%{
/*

    YABASIC  ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2026
    more info at www.yabasic.de

    FLEX part
     
    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wmisleading-indentation"  
#endif

#include <string.h>

#include "bison.h"       /* get tokens from BISON */
#ifndef YABASIC_INCLUDED
#include "yabasic.h"     /* definitions of yabasic */
#endif
int import_lib(char *); /* import library */

#define MAX_INCLUDE_DEPTH 5
#define MAX_INCLUDE_NUMBER 100
static YY_BUFFER_STATE include_stack[MAX_INCLUDE_DEPTH]; /* stack for included libraries */
int include_depth; /* current position in library_stack */
struct library *library_stack[MAX_INCLUDE_DEPTH]; /* stack for library file names */
int library_chain_length=0; /* length of library_chain */
struct library *library_chain[MAX_INCLUDE_NUMBER]; /* list of all library file names in order of appearance */
struct library *currlib; /* current library as relevant to bison */
int inlib; /* true, while in library */
int in_short_if=0; /* greater than zero, if within a short if */
int len_of_lineno=0; /* length of last line number */
YY_BUFFER_STATE from_string_buffer; /* to read from string */

/*
    Remark on yycolumn and yylineno:

    We only need to track yycolumn, yylineno is taken care for us
    entirely by flex (even during yyless).  To handle yycolumn we need
    the YY_USER_ACTION which advances yycolumn by the length of each
    token; additionally we reset it to 1 every time we see a newline.

    The newline normally will be returned as token tSEP; only if the
    newline terminates a short if-statement (which has no endif), the
    token tIMPLICITENDIF will be returned. In any case we reset
    yycolumn appropriately.

    Bison, which consumes the tokens returned by this lexer, often
    needs to look ahead a few (two ?) tokens to parse correctly, this
    might trigger the lexer to read into the next line, which will in
    turn reset yycolumn.

    This needs to be handled correctly in effective_lineno(), which
    returns the current line number. There are also quite a lot of
    tests now, which make sure, that the linenumber for error messages
    is updated correctly.
	 
*/

int yycolumn=1;
int yydoublenl;
#define YY_USER_ACTION yydoublenl=FALSE;yylloc.first_line=yylloc.last_line=yylineno; yylloc.first_column=yycolumn; yylloc.last_column=yycolumn+yyleng-1;yycolumn+=yyleng;
#define YY_NO_UNISTD_H
#define YY_NO_INPUT

int start_token;
%}

WS [ \t\f\r\v]
NAME ([a-z_][a-z0-9_]*\.[a-z_][a-z0-9_]*)|([a-z_][a-z0-9_]*)

%option noyywrap
%option yylineno
%x PRELNO
%x PASTLNO
%x PASTIMPORT
%x EVAL_DIGITS
/* YABKEY is entered right after window, view and draw. Only there are set,
   get and count keywords: a plain yabasic program may use them as ordinary
   variable names (the CLI test c020 does), while a yab program writes
   `window count` or `draw set`. The state ends with the first other token, so
   the keyword reading never leaks into the next statement. */
%x YABKEY

%%
%{
  if (start_token != evNONE)
      {
        int t = start_token;
        start_token = evNONE;
        return t;
      }
%}

<<EOF>> {
  if (severity_threshold <= sDEBUG) {
    sprintf(string,"Closing file '%s'",currlib->short_name);
    error(sDEBUG,string);
  }
  if (--include_depth<0) {
    return tEOPROG;
  } else {
    if (!is_bound) {
      yy_delete_buffer(YY_CURRENT_BUFFER);
      yy_switch_to_buffer(include_stack[include_depth]);
    }
    report_if_missing("Premature end of file",TRUE);
    leave_lib();
    yylval.nnl=0;
    return tSEP;
  }
}

{WS}+ {BEGIN(INITIAL);}     /* ignore whitespace */

^{WS}*/[0-9]+ {if (program_state<=spCOMPILING) {BEGIN(PRELNO);return tLABEL;} else {BEGIN(EVAL_DIGITS);}} /* for functions eval() and compile(), when program state has advanced to spRUNNING, we do not accept line numbers */
<PRELNO>[0-9]+ {
  BEGIN(PASTLNO);
  yylval.symbol=(char *)my_strdup(yytext);
  len_of_lineno=strlen(yytext);		 
  return tSYMBOL;
}
<PASTLNO>.* {yycolumn=len_of_lineno+1;BEGIN(INITIAL);yyless(0);yylval.nnl=0;return tSEP;}
<PASTLNO>\n {yycolumn=1;BEGIN(INITIAL);yylval.nnl=1;return tSEP;}

\n\n {yycolumn=1;yydoublenl=TRUE;yylval.nnl=2; if (in_short_if) {in_short_if--;yyless(0);return tIMPLICITENDIF;} if (interactive && !inlib) {return tEOPROG;} else {return tSEP;}}
\n {yycolumn=1;yylval.nnl=1; if (in_short_if) {in_short_if--;yyless(0);return tIMPLICITENDIF;};return tSEP;}
: {yylval.nnl=0;if (in_short_if && check_compat) error(sWARNING,"Short if has changed in version 2.71");return tSEP;}

REM{WS}+.* {yylval.nnl=0;return tSEP;}  /* comments span 'til end of line */
\/\/.* {yylval.nnl=0;return tSEP;}  /* comments span 'til end of line */
REM\n {yycolumn=1;yylval.nnl=1; if (in_short_if) {in_short_if--;yyless(0);return tIMPLICITENDIF;};return tSEP;}
REM {yymore();}

IMPORT{WS}+{NAME} {BEGIN(PASTIMPORT);import_lib(my_strdup(yytext+7));return tIMPORT;}
<PASTIMPORT>.* {yycolumn=1;BEGIN(INITIAL);yyless(0);unput('\n');yylval.nnl=0;return tSEP;}
<PASTIMPORT>\n {yycolumn=1;BEGIN(INITIAL);yylval.nnl=1;return tSEP;}

((DOCU|DOC|DOCUMENTATION)({WS}+.*)?) {
  char *where=strpbrk(yytext," \t\r\f\v");
  yylval.docu=(char *)my_strdup(where ? where+1 : NULL);
  return tDOCU;
}

^#.*\n {yycolumn=1;yylval.nnl=1;return tSEP;} /* hash (#) as first character of a line may introduce comments too */
^'.*\n {yycolumn=1;yylval.nnl=1;return tSEP;} /* apostrophe (') as first character may introduce comments too */

EXECUTE return tEXECUTE;
"EXECUTE$" return tEXECUTE2;
COMPILE return tCOMPILE;
EVAL return tEVAL;
"EVAL$" return tEVAL2;
RUNTIME_CREATED_SUB return tRUNTIME_CREATED_SUB;
END{WS}+SUB return tENDSUB;
END{WS}+IF return tENDIF;
END-IF return tENDIF;
END{WS}+WHILE return tWEND;
END-WHILE return tWEND;
END{WS}+SWITCH return tSEND;
END-SWITCH return tSEND;
END{WS}+"SWITCH$" return tSEND;
END-"SWITCH$" return tSEND;
EXPORT return tEXPORT;
ERROR return tERROR;
FOR return tFOR;
BREAK return tBREAK;
SWITCH return tSWITCH;
CASE return tCASE;
DEFAULT return tDEFAULT;
LOOP return tLOOP;
DO return tDO;
TO return tTO;
AS return tAS;
READING return tREADING;
WRITING return tWRITING;
STEP return tSTEP;
NEXT return tNEXT;
WHILE return tWHILE;
WEND return tWEND;
REPEAT return tREPEAT;
UNTIL return tUNTIL;
GOTO return tGOTO;
GOSUB return tGOSUB;
SUB return tSUB;
SUBROUTINE return tSUB;
LOCAL return tLOCAL;
STATIC return tSTATIC;
ON return tON;
INTERRUPT return tINTERRUPT;
CONTINUE return tCONTINUE;
LABEL return tLABEL;
IF return tIF;
THEN return tTHEN;
ELSE return tELSE;
ELSIF return tELSIF;
ELSEIF return tELSIF;
ENDIF return tENDIF;
FI return tENDIF;
OPEN return tOPEN;
CLOSE return tCLOSE;
SEEK return tSEEK;
TELL return tTELL;
PRINT return tPRINT;
USING return tUSING;
REVERSE return tREVERSE;
COLOR return tCOLOUR;
COLOUR return tCOLOUR;
BACKCOLOR return tBACKCOLOUR;
BACKCOLOUR return tBACKCOLOUR;
\? return tPRINT;
INPUT return tINPUT;
RETURN return tRETURN;
DIM return tDIM;
REDIM return tDIM;
END return tEND;
EXIT return tEXIT;
READ return tREAD;
DATA return tDATA;
RESTORE return tRESTORE;
AND return tAND;
OR return tOR;
NOT return tNOT;
BITNOT return tBITNOT;
ALERT return tALERT;
SOUND {BEGIN(YABKEY);return tSOUND;}
MEDIASOUND {BEGIN(YABKEY);return tMEDIASOUND;}
LOUDNESS {BEGIN(YABKEY);return tLOUDNESS;}
FILEPANEL return tFILEPANEL;
POPUPMENU return tPOPUPMENU;
EOR return tEOR;
XOR return tEOR;
SHL return tSHL;
SHR return tSHR;
WINDOW {BEGIN(YABKEY);return tWINDOW;}
ORIGIN return tORIGIN;
PRINTER return tPRINTER;
DOT return tDOT;
LINE return tLINE;
CURVE return tCURVE;
CIRCLE return tCIRCLE;
TRIANGLE return tTRIANGLE;
CLEAR return tCLEAR;
FILL return tFILL;
FILLED return tFILL;
TEXT {BEGIN(YABKEY);return tTEXT;}
RECTANGLE return tRECT;
RECT return tRECT;
BOX return tRECT;
BUTTON {BEGIN(YABKEY);return tBUTTON;}
CHECKBOX {BEGIN(YABKEY);return tCHECKBOX;}
RADIOBUTTON {BEGIN(YABKEY);return tRADIOBUTTON;}
TEXTCONTROL {BEGIN(YABKEY);return tTEXTCONTROL;}
TEXTEDIT {BEGIN(YABKEY);return tTEXTEDIT;}
TEXTURL {BEGIN(YABKEY);return tTEXTURL;}
SLIDER {BEGIN(YABKEY);return tSLIDER;}
STATUSBAR {BEGIN(YABKEY);return tSTATUSBAR;}
SPINCONTROL {BEGIN(YABKEY);return tSPINCONTROL;}
SCROLLBAR {BEGIN(YABKEY);return tSCROLLBAR;}
LAYOUT {BEGIN(YABKEY);return tLAYOUT;}
TOOLTIP {BEGIN(YABKEY);return tTOOLTIP;}
OPTION {BEGIN(YABKEY);return tOPTION;}
TABVIEW {BEGIN(YABKEY);return tTABVIEW;}
BOXVIEW {BEGIN(YABKEY);return tBOXVIEW;}
SPLITVIEW {BEGIN(YABKEY);return tSPLITVIEW;}
STACKVIEW {BEGIN(YABKEY);return tSTACKVIEW;}
CANVAS {BEGIN(YABKEY);return tCANVAS;}
REGION {BEGIN(YABKEY);return tREGION;}
BITMAP {BEGIN(YABKEY);return tBITMAP;}
MENU {BEGIN(YABKEY);return tMENU;}
SUBMENU {BEGIN(YABKEY);return tSUBMENU;}
SUBSUBMENU {BEGIN(YABKEY);return tSUBSUBMENU;}
CLIPBOARD {BEGIN(YABKEY);return tCLIPBOARD;}
ATTRIBUTE {BEGIN(YABKEY);return tATTRIBUTE;}
"MESSAGE$" return tMESSAGE;
"TRANSLATE$" return tTRANSLATE;
LISTBOX {BEGIN(YABKEY);return tLISTBOX;}
DROPBOX {BEGIN(YABKEY);return tDROPBOX;}
TREEBOX {BEGIN(YABKEY);return tTREEBOX;}
COLUMNBOX {BEGIN(YABKEY);return tCOLUMNBOX;}
CALENDAR {BEGIN(YABKEY);return tCALENDAR;}
COLORCONTROL {BEGIN(YABKEY);return tCOLORCONTROL;}
  /* The command words are keywords only directly after a command keyword, and
     only when the whole word was written: `text 1, 2, set$` still scans set$
     as a string variable, while `text set "id", "centre"` gets tSET. */
<YABKEY>SET/[ \t] {BEGIN(INITIAL);return tSET;}
  /* The newline is part of the class because `loudness get` is a getter with
     no argument at all, so the word can end the line. */
<YABKEY>GET/[ \t\n] {BEGIN(INITIAL);return tGET;}
<YABKEY>ADD/[ \t] {BEGIN(INITIAL);return tADD;}
<YABKEY>REMOVE/[ \t] {BEGIN(INITIAL);return tREMOVE;}
<YABKEY>SELECT/[ \t] {BEGIN(INITIAL);return tSELECT;}
<YABKEY>SORT/[ \t] {BEGIN(INITIAL);return tSORT;}
<YABKEY>EXPAND/[ \t] {BEGIN(INITIAL);return tEXPAND;}
<YABKEY>COLLAPSE/[ \t] {BEGIN(INITIAL);return tCOLLAPSE;}
<YABKEY>COLUMN/[ \t] {BEGIN(INITIAL);return tCOLUMN;}
  /* `sound play`, `sound stop`, `sound wait` and `mediasound stop`; the words
     are keywords only there, and the trailing context keeps a variable such as
     `stopwatch` out of them. A parenthesis counts as the end of the word, so
     `sound stop(1)` scans like yab's combined form. */
<YABKEY>PLAY/[ \t(] {BEGIN(INITIAL);return tPLAY;}
<YABKEY>STOP/[ \t(] {BEGIN(INITIAL);return tSTOP;}
  /* `clipboard copy` and `clipboard paste$`; yab spells the getter with the
     dollar, and both words are only keywords after `clipboard`. */
<YABKEY>BITMAP {BEGIN(INITIAL);return tBITMAP;} /* `draw bitmap` */
<YABKEY>COPY {BEGIN(INITIAL);return tCOPY;}
<YABKEY>"PASTE$" {BEGIN(INITIAL);return tPASTE;}
<YABKEY>"TRANSLATE$" {BEGIN(INITIAL);return tTRANSLATE;}
  /* yab's get$ returns text, get a number. Both stay available: the text
     getters use get$, the numeric ones (item counts, the selected position,
     colour components) use get, and `textcontrol get`/`textedit get` keep the
     plain spelling they were introduced with. */
<YABKEY>"GET$" {BEGIN(INITIAL);return tGETS;}
  /* `attribute get(...)` puts the parenthesis straight after the word, with
     no space for the rule above to take; yab spells the numeric getter
     `get` there too. The parenthesis is pushed back for the parser. */
<YABKEY>"GET(" {BEGIN(INITIAL);yyless(yyleng-1);return tGET;}
  /* count stays in the command state, because `columnbox count column` is the
     one form where a second command word follows; the state's fallback rule
     rescans anything else normally. */
<YABKEY>COUNT {return tCOUNT;}
<YABKEY>{WS}+ ; /* skip blanks between the command words */
<YABKEY>\n {yycolumn=1;BEGIN(INITIAL);yylval.nnl=1;return tSEP;}
<YABKEY>. {BEGIN(INITIAL);yyless(0);} /* not a command word: scan it normally */
VIEW {BEGIN(YABKEY);return tVIEW;}
DRAW {BEGIN(YABKEY);return tDRAW;}
FLUSH return tFLUSH;
ELLIPSE return tELLIPSE;
ARC return tARC;
POLYGON return tPOLYGON;
ROUNDRECT return tROUNDRECT;
SCREENSHOT return tSCREENSHOT;
BFILESIZE return tBFILESIZE;
BITBLIT return tPUTBIT;
BITBLT return tPUTBIT;
PUTBIT return tPUTBIT;
"BITBLT$" return tGETBIT;
"BITBLIT$" return tGETBIT;
"GETBIT$" return tGETBIT;
PUTSCREEN return tPUTCHAR;
"GETSCREEN$" return tGETCHAR;
NEW return tNEW;
WAIT return tWAIT;
PAUSE return tWAIT;
SLEEP return tWAIT;
BELL return tBELL;
BEEP return tBELL;
LET return tLET;
ARRAYDIM return tARDIM;
ARRAYDIMENSION return tARDIM;
ARRAYSIZE return tARSIZE;
NUMPARAM(S)?({WS}*\({WS}*\))? {yylval.symbol=(char *)my_strdup("numparams"); return tSYMBOL;}
BIND return tBIND;

SIN return tSIN;
ASIN return tASIN;
COS return tCOS;
ACOS return tACOS;
TAN return tTAN;
ATAN return tATAN;
EXP return tEXP;
LOG return tLOG;
SQRT return tSQRT;
SQR return tSQR;
INT return tINT;
CEIL return tCEIL;
FLOOR return tFLOOR;
ROUND return tROUND;
FRAC return tFRAC;
ABS return tABS;
SIG return tSIG;
MOD return tMOD;
RAN return tRAN;
MIN return tMIN;
MAX return tMAX;
"LEFT$" return tLEFT;
"RIGHT$" return tRIGHT;
"MID$" return tMID;
"LOWER$" return tLOWER;
"UPPER$" return tUPPER;
"LTRIM$" return tLTRIM;
"RTRIM$" return tRTRIM;
"TRIM$" return tTRIM;
"STRING$" return tSTRING2;
"REPLACE$" return tREPLACE;
INSTR return tINSTR;
RINSTR return tRINSTR;
"CHOMP$" return tCHOMP;
LEN return tLEN;
VAL return tVAL;
EOF return tMYEOF;
"STR$" return tSTR;
"INKEY$" return tINKEY;
"MOUSEX" return tMOUSEX;
"MOUSEY" return tMOUSEY;
"MOUSEB" return tMOUSEB;
"MOUSEBUTTON" return tMOUSEB;
"MOUSEMOD" return tMOUSEMOD;
"MOUSEMODIFIER" return tMOUSEMOD;
"CHR$" return tCHR;
ASC return tASC;
"HEX$" return tHEX;
"BIN$" return tBIN;
DEC return tDEC;
AT return tAT;
@ return tAT;
SCREEN return tSCREEN;
SYSTEM return tSYSTEM;
"SYSTEM$" return tSYSTEM2;
"DATE$" return tDATE;
"TIME$" return tTIME;
PEEK return tPEEK;
"PEEK$" return tPEEK2;
POKE return tPOKE;
FOREIGN_FUNCTION_CALL return tFRNFN_CALL;
FRNFN_CALL return tFRNFN_CALL;
"FOREIGN_FUNCTION_CALL$" return tFRNFN_CALL2;
"FRNFN_CALL$" return tFRNFN_CALL2;
FOREIGN_FUNCTION_SIZE return tFRNFN_SIZE;
FRNFN_SIZE return tFRNFN_SIZE;
FOREIGN_BUFFER_GET return tFRNBF_GET;
FRNBF_GET return tFRNBF_GET;
"FOREIGN_BUFFER_GET$" return tFRNBF_GET2;
"FRNBF_GET$" return tFRNBF_GET2;
"FOREIGN_BUFFER_GET_BUFFER$" return tFRNBF_GET_BUFFER;
"FRNBF_GET_BUFFER$" return tFRNBF_GET_BUFFER;
FOREIGN_BUFFER_SET return tFRNBF_SET;
FRNBF_SET return tFRNBF_SET;
FOREIGN_BUFFER_SET_BUFFER return tFRNBF_SET_BUFFER;
FRNBF_SET_BUFFER return tFRNBF_SET_BUFFER;
"FOREIGN_BUFFER_ALLOCATE$" return tFRNBF_ALLOC;
"FOREIGN_BUFFER_ALLOC$" return tFRNBF_ALLOC;
"FRNBF_ALLOC$" return tFRNBF_ALLOC;
"FOREIGN_BUFFER_DUMP$" return tFRNBF_DUMP;
"FRNBF_DUMP$" return tFRNBF_DUMP;
"FOREIGN_BUFFER_SIZE" return tFRNBF_SIZE;
"FRNBF_SIZE" return tFRNBF_SIZE;
"FOREIGN_BUFFER_FREE" return tFRNBF_FREE;
"FRNBF_FREE" return tFRNBF_FREE;
TOKEN return tTOKEN;
"TOKEN$" return tTOKENALT;
SPLIT return tSPLIT;
"SPLIT$" return tSPLITALT;
GLOB return tGLOB;
"^" return tPOW;
"**" return tPOW;

"<>" return tNEQ;
"!=" return tNEQ;
"<=" return tLEQ;
">=" return tGEQ;
"=" return tEQU;
"==" return tEQU2;
"<" return tLTN;
">" return tGTN;
"!" return tNOT;

[-+*/:(),.;] {return yytext[0];}

<INITIAL,EVAL_DIGITS>0x[0-9a-zA-Z]+ {
  yylval.digits=(char *)my_strdup(yytext+2);
  BEGIN(INITIAL);  		    
  return tHEXDIGITS;
}

<INITIAL,EVAL_DIGITS>0b[0-1]+ {
  yylval.digits=(char *)my_strdup(yytext+2);
  BEGIN(INITIAL);  		    
  return tBINDIGITS;
}

<INITIAL,EVAL_DIGITS>[0-9]+ {
  yylval.digits=(char *)my_strdup(yytext);
  BEGIN(INITIAL);  		    
  return tDIGITS;
}

<INITIAL,EVAL_DIGITS>(([0-9]+|([0-9]*\.[0-9]*))([eE][-+]?[0-9]+)?) {
  { double d;
    sscanf(yytext,"%lg",&d);
    yylval.fnum=d;
    BEGIN(INITIAL);  		    
    return tFNUM;
  }
}

pi {yylval.fnum=3.1415926535897932;return tFNUM;}
euler {yylval.fnum=2.7182818284590452;return tFNUM;}
TRUE {yylval.fnum=1; return tFNUM;}
FALSE {yylval.fnum=0; return tFNUM;}

{NAME} {
  yylval.symbol=(char *)my_strdup(yytext);
  return tSYMBOL;
}

{NAME}\$ {
  yylval.symbol=(char *)my_strdup(yytext);
  return tSTRSYM;
}

\"[^"]*(\"|\n) {
  if (yyleng<2 || yytext[yyleng-1]=='\n') { /* unterminated string has reached end of line, report qualified error in bison */
        yyless(1);
  	yylval.string=NULL;
  	return tSTRING;
  } else if (yytext[yyleng-1]=='\"' && count_backslashes(yytext+yyleng-2)%2==1) { /* final quote was escaped, so put all text back and read more */
  	yyless(yyleng-1);
	yymore();
  } else { /* properly quoted string; remove quotes and return it */
	yylval.string=(char *)my_strdup(yytext+1);
	*(yylval.string+strlen(yylval.string)-1)='\0';
	replace_escapes(yylval.string);
	return tSTRING;
  }
}


. {if (isprint(yytext[0])) return yytext[0]; else return ' ';}

%%
void open_main(FILE *file,char *explicit,char *main_file_name) /* open main file */
{
  include_depth=0;
  
  if (explicit) {
    include_stack[include_depth]=yy_scan_string(explicit);
  } else {
    include_stack[include_depth]=yy_create_buffer(file,YY_BUF_SIZE);
  }
  library_stack[include_depth]=new_library(main_file_name,"main");
  library_chain[library_chain_length++]=library_stack[include_depth];
  if (!explicit) yy_switch_to_buffer(include_stack[include_depth]);
  currlib=library_stack[0];
  inlib=FALSE;
  
  return;
}


void start_flex_from_string(char *text) /* open string with commands */
{
  from_string_buffer = yy_scan_string(text);
/*  yy_switch_to_buffer(from_string_buffer); */
}


void end_flex_from_string(void) /* free structure used to read string */
{
  yy_delete_buffer(from_string_buffer);
}


int import_lib(char *name) /* import library */
{
  char *full;
  static int end_of_all_imports=FALSE;
  static int ignore_nested_imports=FALSE;
  FILE *lib_file;

  while(isspace(*name)) name++;
  name[strcspn(name, "\n")] = '\0';

  /* This can only occur in bound programs; void all further import-statements */
  if (!strcmp(name,"__END_OF_ALL_IMPORTS")) {
    error(sDEBUG,"Encountered special import __END_OF_ALL_IMPORTS");
    end_of_all_imports=TRUE;
  }

  if (end_of_all_imports) return TRUE;

  /* This can only occur in bound programs, close currently imported library */
  if (!strcmp(name,"__END_OF_CURRENT_IMPORT")) {
    error(sDEBUG,"Encountered special import __END_OF_CURRENT_IMPORT");
    include_depth--;
    leave_lib();
    ignore_nested_imports=FALSE; 
    return TRUE;
  }

  /* This can only occur in bound programs, ignore nested import-statement */
  if (!strcmp(name,"__IGNORE_NESTED_IMPORTS")) {
    error(sDEBUG,"Encountered special import __IGNORE_NESTED_IMPORTS");
    ignore_nested_imports=TRUE; 
  }

  if (ignore_nested_imports) return TRUE;

  include_depth++;
  inlib=TRUE;
  if (include_depth>=MAX_INCLUDE_DEPTH) {
    sprintf(string,"Could not import '%s': nested too deep (%d)",name,include_depth);
    error(sERROR,string);
    return FALSE;
  }

  if (is_bound) {
    full=name;
  } else {
    lib_file=open_library(name,&full);
    if (!lib_file) return FALSE;
    yy_switch_to_buffer(yy_create_buffer(lib_file,YY_BUF_SIZE));
    include_stack[include_depth]=YY_CURRENT_BUFFER;
  }
  library_stack[include_depth]=new_library(full,NULL);
  library_chain[library_chain_length++]=library_stack[include_depth];
  if (library_chain_length>=MAX_INCLUDE_NUMBER) {
    sprintf(string,"Cannot import more than %d libraries",MAX_INCLUDE_NUMBER);
    error(sERROR,string);
    return FALSE;
  }
  if (!library_stack[include_depth]) {
    sprintf(string,"library '%s' has already been imported",full);
    error(sERROR,string);
    return FALSE;
  } 

  if (severity_threshold <= sNOTE) {
    if (is_bound) {      
      sprintf(string,"importing library '%s'",name);
    } else {
      sprintf(string,"importing from file '%s'",full);
    }
    error(sNOTE,string);
  }
  currlib=library_stack[include_depth]; /* switch late because error() uses currlib */
  return TRUE;
}


FILE *open_library(char *name,char **fullreturn) /* search and open a library */
{
  static char full_wdir[NAMEBUFFLEN];
  static char full_main[NAMEBUFFLEN];
  static char full_global[NAMEBUFFLEN];
  char unquoted[NAMEBUFFLEN];
  char *p;
  FILE *lib;
  int i;

  for(p=name;strchr(" \"'`",*p);p++) if (!*p) break;
  strncpy(unquoted,p,NAMEBUFFLEN);
  unquoted[NAMEBUFFLEN - 1] = '\0';
  for(;!strchr(" \"'`",*p);p++) if (!*p) break;
  if (*p) unquoted[p-name-2]='\0';
  name=unquoted;
  if (strchr(name,'.')) {
    sprintf(string,"library name '%s' contains '.'",name);
    error(sERROR,string);
    return NULL;
  }
  if (!strcmp(name,"main")) {
    if (is_bound) return NULL;
    error(sERROR,"invalid library name 'main'");
    return NULL;
  }

  /* search in current working dir */
  if (fullreturn) *fullreturn=full_wdir;
  strncpy(full_wdir,name,NAMEBUFFLEN);
  full_wdir[NAMEBUFFLEN - 1] = '\0';  
  strcat(full_wdir,".yab");
  lib=fopen(full_wdir,"r");
  if (lib) return lib;
  
  /* search in dir of main file */
  if (fullreturn) *fullreturn=full_main;
  if (strchr(main_file_name,'/') || strchr(main_file_name,'\\')) {
    strncpy(full_main,main_file_name,NAMEBUFFLEN - 1);
  } else {
    full_main[0]='\0';
  }
  for(i=0;i<2;i++) {
    p=strrchr(full_main,"\\/"[i]);
    if (p) *p='\0';
  }
  if (full_main[0] && !strchr("\\/",full_main[strlen(full_main)-1])) {
#ifdef UNIX
    strcat(full_main,"/");
#else
    strcat(full_main,"\\");
#endif
  }     
  strcat(full_main,name);
  strcat(full_main,".yab");
  lib=fopen(full_main,"r");
  if (lib) return lib;
  
  /* search in global directory */
  if (fullreturn) *fullreturn=full_global;
  strncpy(full_global,library_path,NAMEBUFFLEN - 1);
  if (full_global[0] && !strchr("\\/",full_global[strlen(full_global)-1])) {
#ifdef UNIX
    strcat(full_global,"/");
#else
    strcat(full_global,"\\");
#endif
  }     
  strcat(full_global,name);
  strcat(full_global,".yab");
  lib=fopen(full_global,"r");
  if (lib) return lib;
    
  sprintf(string,"could not open library '%s': not in current workingdir as '%s', not in directory of main file as '%s', not in library path as '%s'",name,full_wdir,full_main,full_global);
  error(sERROR,string);
  return NULL;
}


void leave_lib(void) /* processing, when end of library is found */
{
  if (include_depth<0) return;
  if (severity_threshold <= sDEBUG) {
    sprintf(string,"End of library '%s', continue with '%s', include depth is now %d",currlib->short_name,library_stack[include_depth]->short_name,include_depth);
    error(sDEBUG,string);
  }
  yylineno=currlib->yylineno_at_start;
  currlib=library_stack[include_depth];
  inlib=(include_depth>0);
}
