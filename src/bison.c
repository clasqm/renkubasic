/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */

/*

    YABASIC  ---  a simple Basic Interpreter
    written by Marc Ihm 1995-2026
    more info at www.yabasic.de

    BISON part
     
    This file is part of yabasic and may be copied under the terms of
    MIT License which can be found in the file LICENSE.

*/


#ifndef YABASIC_INCLUDED
#include "yabasic.h"     /* definitions of yabasic */
#endif

#ifdef WINDOWS
#include <malloc.h>
#else
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#else
#include <stdlib.h>
#endif
#endif

#if HAVE_ALLOCA_H
#ifndef WINDOWS
#include <alloca.h>
#endif
#endif

void __yy_bcopy(char *,char *,int); /* prototype missing */

int tileol; /* true, read should go to eon of line */
int function_type=ftNONE; /* contains function type while parsing function */
char *current_function=NULL; /* name of currently parsed function */
int exported=FALSE; /* true, if function is exported */
int yylex(void);
extern struct library *current_library; /* defined in main.c: name of currently parsed library */
extern int yylineno; /* defined in flex */
int missing_endif=0;
int missing_endif_line=0;
int missing_endsub=0;
int missing_endsub_line=0;
int missing_next=0;
int missing_next_line=0;
int missing_wend=0;
int missing_wend_line=0;
int missing_until=0;
int missing_until_line=0;
int missing_loop=0;
int missing_loop_line=0;
int loop_nesting=0;
int switch_nesting=0;

void report_if_missing(char *text,int eof) {
  if (missing_loop || missing_endif || missing_next || missing_until || missing_wend) {
    if (eof) {
       error_without_position(sERROR,text);
    } else {
       error(sERROR,text);
    }
    collect_missing_clauses(string,-1);
    if (string[0]) {
      error_without_position(sERROR,string);
    }
  }
}

void report_conflicting_close(char *text,int missing) {
  error(sERROR,text);
  collect_missing_clauses(string,missing);
  error(sERROR,string);
}

void collect_missing_clauses(char *string, char exclude) {
  char buff[INBUFFLEN];
  
  string[0]='\0';
  if (missing_endif && exclude!='e') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"if-statement starting at line %d has seen no 'endif' yet",missing_endif_line);
    strcat(string, buff);
  }

  if (missing_next && exclude!='n') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"for-loop starting at line %d has seen no 'next' yet",missing_next_line);
    strcat(string, buff);
  }

  if (missing_wend && exclude!='w') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"while-loop starting at line %d has seen no 'wend' yet",missing_wend_line);
    strcat(string, buff);
  }

  if (missing_until && exclude!='u') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"repeat-loop starting at line %d has seen no 'until' yet",missing_until_line);
    strcat(string, buff);
  }
  
  if (missing_loop && exclude!='l') {
    if (string[0]) strcat(string,"; ");
    sprintf(buff,"do-loop starting at line %d has seen no 'loop' yet",missing_loop_line);
    strcat(string, buff);
  }
}


# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "bison.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tFNUM = 3,                      /* tFNUM  */
  YYSYMBOL_tSYMBOL = 4,                    /* tSYMBOL  */
  YYSYMBOL_tSTRSYM = 5,                    /* tSTRSYM  */
  YYSYMBOL_tDOCU = 6,                      /* tDOCU  */
  YYSYMBOL_tDIGITS = 7,                    /* tDIGITS  */
  YYSYMBOL_tHEXDIGITS = 8,                 /* tHEXDIGITS  */
  YYSYMBOL_tBINDIGITS = 9,                 /* tBINDIGITS  */
  YYSYMBOL_tSTRING = 10,                   /* tSTRING  */
  YYSYMBOL_tFOR = 11,                      /* tFOR  */
  YYSYMBOL_tTO = 12,                       /* tTO  */
  YYSYMBOL_tSTEP = 13,                     /* tSTEP  */
  YYSYMBOL_tNEXT = 14,                     /* tNEXT  */
  YYSYMBOL_tWHILE = 15,                    /* tWHILE  */
  YYSYMBOL_tWEND = 16,                     /* tWEND  */
  YYSYMBOL_tREPEAT = 17,                   /* tREPEAT  */
  YYSYMBOL_tUNTIL = 18,                    /* tUNTIL  */
  YYSYMBOL_tIMPORT = 19,                   /* tIMPORT  */
  YYSYMBOL_tGOTO = 20,                     /* tGOTO  */
  YYSYMBOL_tGOSUB = 21,                    /* tGOSUB  */
  YYSYMBOL_tLABEL = 22,                    /* tLABEL  */
  YYSYMBOL_tON = 23,                       /* tON  */
  YYSYMBOL_tSUB = 24,                      /* tSUB  */
  YYSYMBOL_tENDSUB = 25,                   /* tENDSUB  */
  YYSYMBOL_tLOCAL = 26,                    /* tLOCAL  */
  YYSYMBOL_tSTATIC = 27,                   /* tSTATIC  */
  YYSYMBOL_tEXPORT = 28,                   /* tEXPORT  */
  YYSYMBOL_tERROR = 29,                    /* tERROR  */
  YYSYMBOL_tEXECUTE = 30,                  /* tEXECUTE  */
  YYSYMBOL_tEXECUTE2 = 31,                 /* tEXECUTE2  */
  YYSYMBOL_tCOMPILE = 32,                  /* tCOMPILE  */
  YYSYMBOL_tRUNTIME_CREATED_SUB = 33,      /* tRUNTIME_CREATED_SUB  */
  YYSYMBOL_tINTERRUPT = 34,                /* tINTERRUPT  */
  YYSYMBOL_tBREAK = 35,                    /* tBREAK  */
  YYSYMBOL_tCONTINUE = 36,                 /* tCONTINUE  */
  YYSYMBOL_tSWITCH = 37,                   /* tSWITCH  */
  YYSYMBOL_tSEND = 38,                     /* tSEND  */
  YYSYMBOL_tCASE = 39,                     /* tCASE  */
  YYSYMBOL_tDEFAULT = 40,                  /* tDEFAULT  */
  YYSYMBOL_tLOOP = 41,                     /* tLOOP  */
  YYSYMBOL_tDO = 42,                       /* tDO  */
  YYSYMBOL_tSEP = 43,                      /* tSEP  */
  YYSYMBOL_tEOPROG = 44,                   /* tEOPROG  */
  YYSYMBOL_tIF = 45,                       /* tIF  */
  YYSYMBOL_tTHEN = 46,                     /* tTHEN  */
  YYSYMBOL_tELSE = 47,                     /* tELSE  */
  YYSYMBOL_tELSIF = 48,                    /* tELSIF  */
  YYSYMBOL_tENDIF = 49,                    /* tENDIF  */
  YYSYMBOL_tIMPLICITENDIF = 50,            /* tIMPLICITENDIF  */
  YYSYMBOL_tUSING = 51,                    /* tUSING  */
  YYSYMBOL_tPRINT = 52,                    /* tPRINT  */
  YYSYMBOL_tINPUT = 53,                    /* tINPUT  */
  YYSYMBOL_tRETURN = 54,                   /* tRETURN  */
  YYSYMBOL_tDIM = 55,                      /* tDIM  */
  YYSYMBOL_tEND = 56,                      /* tEND  */
  YYSYMBOL_tEXIT = 57,                     /* tEXIT  */
  YYSYMBOL_tAT = 58,                       /* tAT  */
  YYSYMBOL_tSCREEN = 59,                   /* tSCREEN  */
  YYSYMBOL_tREVERSE = 60,                  /* tREVERSE  */
  YYSYMBOL_tCOLOUR = 61,                   /* tCOLOUR  */
  YYSYMBOL_tBACKCOLOUR = 62,               /* tBACKCOLOUR  */
  YYSYMBOL_tAND = 63,                      /* tAND  */
  YYSYMBOL_tOR = 64,                       /* tOR  */
  YYSYMBOL_tNOT = 65,                      /* tNOT  */
  YYSYMBOL_tBITNOT = 66,                   /* tBITNOT  */
  YYSYMBOL_tEOR = 67,                      /* tEOR  */
  YYSYMBOL_tSHL = 68,                      /* tSHL  */
  YYSYMBOL_tSHR = 69,                      /* tSHR  */
  YYSYMBOL_tNEQ = 70,                      /* tNEQ  */
  YYSYMBOL_tLEQ = 71,                      /* tLEQ  */
  YYSYMBOL_tGEQ = 72,                      /* tGEQ  */
  YYSYMBOL_tLTN = 73,                      /* tLTN  */
  YYSYMBOL_tGTN = 74,                      /* tGTN  */
  YYSYMBOL_tEQU = 75,                      /* tEQU  */
  YYSYMBOL_tEQU2 = 76,                     /* tEQU2  */
  YYSYMBOL_tPOW = 77,                      /* tPOW  */
  YYSYMBOL_tREAD = 78,                     /* tREAD  */
  YYSYMBOL_tDATA = 79,                     /* tDATA  */
  YYSYMBOL_tRESTORE = 80,                  /* tRESTORE  */
  YYSYMBOL_tOPEN = 81,                     /* tOPEN  */
  YYSYMBOL_tCLOSE = 82,                    /* tCLOSE  */
  YYSYMBOL_tSEEK = 83,                     /* tSEEK  */
  YYSYMBOL_tTELL = 84,                     /* tTELL  */
  YYSYMBOL_tAS = 85,                       /* tAS  */
  YYSYMBOL_tREADING = 86,                  /* tREADING  */
  YYSYMBOL_tWRITING = 87,                  /* tWRITING  */
  YYSYMBOL_tORIGIN = 88,                   /* tORIGIN  */
  YYSYMBOL_tWINDOW = 89,                   /* tWINDOW  */
  YYSYMBOL_tDOT = 90,                      /* tDOT  */
  YYSYMBOL_tLINE = 91,                     /* tLINE  */
  YYSYMBOL_tCIRCLE = 92,                   /* tCIRCLE  */
  YYSYMBOL_tTRIANGLE = 93,                 /* tTRIANGLE  */
  YYSYMBOL_tTEXT = 94,                     /* tTEXT  */
  YYSYMBOL_tCLEAR = 95,                    /* tCLEAR  */
  YYSYMBOL_tFILL = 96,                     /* tFILL  */
  YYSYMBOL_tPRINTER = 97,                  /* tPRINTER  */
  YYSYMBOL_tWAIT = 98,                     /* tWAIT  */
  YYSYMBOL_tBELL = 99,                     /* tBELL  */
  YYSYMBOL_tLET = 100,                     /* tLET  */
  YYSYMBOL_tARDIM = 101,                   /* tARDIM  */
  YYSYMBOL_tARSIZE = 102,                  /* tARSIZE  */
  YYSYMBOL_tBIND = 103,                    /* tBIND  */
  YYSYMBOL_tRECT = 104,                    /* tRECT  */
  YYSYMBOL_tGETBIT = 105,                  /* tGETBIT  */
  YYSYMBOL_tPUTBIT = 106,                  /* tPUTBIT  */
  YYSYMBOL_tGETCHAR = 107,                 /* tGETCHAR  */
  YYSYMBOL_tPUTCHAR = 108,                 /* tPUTCHAR  */
  YYSYMBOL_tNEW = 109,                     /* tNEW  */
  YYSYMBOL_tCURVE = 110,                   /* tCURVE  */
  YYSYMBOL_tSET = 111,                     /* tSET  */
  YYSYMBOL_tGET = 112,                     /* tGET  */
  YYSYMBOL_tCOUNT = 113,                   /* tCOUNT  */
  YYSYMBOL_tVIEW = 114,                    /* tVIEW  */
  YYSYMBOL_tDRAW = 115,                    /* tDRAW  */
  YYSYMBOL_tFLUSH = 116,                   /* tFLUSH  */
  YYSYMBOL_tELLIPSE = 117,                 /* tELLIPSE  */
  YYSYMBOL_tARC = 118,                     /* tARC  */
  YYSYMBOL_tPOLYGON = 119,                 /* tPOLYGON  */
  YYSYMBOL_tROUNDRECT = 120,               /* tROUNDRECT  */
  YYSYMBOL_tSCREENSHOT = 121,              /* tSCREENSHOT  */
  YYSYMBOL_tBFILESIZE = 122,               /* tBFILESIZE  */
  YYSYMBOL_tBUTTON = 123,                  /* tBUTTON  */
  YYSYMBOL_tCHECKBOX = 124,                /* tCHECKBOX  */
  YYSYMBOL_tRADIOBUTTON = 125,             /* tRADIOBUTTON  */
  YYSYMBOL_tTEXTCONTROL = 126,             /* tTEXTCONTROL  */
  YYSYMBOL_tTEXTEDIT = 127,                /* tTEXTEDIT  */
  YYSYMBOL_tTEXTURL = 128,                 /* tTEXTURL  */
  YYSYMBOL_tSLIDER = 129,                  /* tSLIDER  */
  YYSYMBOL_tSTATUSBAR = 130,               /* tSTATUSBAR  */
  YYSYMBOL_tSPINCONTROL = 131,             /* tSPINCONTROL  */
  YYSYMBOL_tSCROLLBAR = 132,               /* tSCROLLBAR  */
  YYSYMBOL_tLAYOUT = 133,                  /* tLAYOUT  */
  YYSYMBOL_tTOOLTIP = 134,                 /* tTOOLTIP  */
  YYSYMBOL_tOPTION = 135,                  /* tOPTION  */
  YYSYMBOL_tTABVIEW = 136,                 /* tTABVIEW  */
  YYSYMBOL_tBOXVIEW = 137,                 /* tBOXVIEW  */
  YYSYMBOL_tSPLITVIEW = 138,               /* tSPLITVIEW  */
  YYSYMBOL_tSTACKVIEW = 139,               /* tSTACKVIEW  */
  YYSYMBOL_tCANVAS = 140,                  /* tCANVAS  */
  YYSYMBOL_tREGION = 141,                  /* tREGION  */
  YYSYMBOL_tADD = 142,                     /* tADD  */
  YYSYMBOL_tREMOVE = 143,                  /* tREMOVE  */
  YYSYMBOL_tLISTBOX = 144,                 /* tLISTBOX  */
  YYSYMBOL_tDROPBOX = 145,                 /* tDROPBOX  */
  YYSYMBOL_tDROPZONE = 146,                /* tDROPZONE  */
  YYSYMBOL_tTREEBOX = 147,                 /* tTREEBOX  */
  YYSYMBOL_tCOLUMNBOX = 148,               /* tCOLUMNBOX  */
  YYSYMBOL_tCALENDAR = 149,                /* tCALENDAR  */
  YYSYMBOL_tCOLORCONTROL = 150,            /* tCOLORCONTROL  */
  YYSYMBOL_tCOLUMN = 151,                  /* tCOLUMN  */
  YYSYMBOL_tSORT = 152,                    /* tSORT  */
  YYSYMBOL_tEXPAND = 153,                  /* tEXPAND  */
  YYSYMBOL_tCOLLAPSE = 154,                /* tCOLLAPSE  */
  YYSYMBOL_tSELECT = 155,                  /* tSELECT  */
  YYSYMBOL_tGETS = 156,                    /* tGETS  */
  YYSYMBOL_tMENU = 157,                    /* tMENU  */
  YYSYMBOL_tSUBMENU = 158,                 /* tSUBMENU  */
  YYSYMBOL_tSUBSUBMENU = 159,              /* tSUBSUBMENU  */
  YYSYMBOL_tCLIPBOARD = 160,               /* tCLIPBOARD  */
  YYSYMBOL_tCOPY = 161,                    /* tCOPY  */
  YYSYMBOL_tPASTE = 162,                   /* tPASTE  */
  YYSYMBOL_tTRANSLATE = 163,               /* tTRANSLATE  */
  YYSYMBOL_tMESSAGE = 164,                 /* tMESSAGE  */
  YYSYMBOL_tATTRIBUTE = 165,               /* tATTRIBUTE  */
  YYSYMBOL_tBITMAP = 166,                  /* tBITMAP  */
  YYSYMBOL_tALERT = 167,                   /* tALERT  */
  YYSYMBOL_tFILEPANEL = 168,               /* tFILEPANEL  */
  YYSYMBOL_tPOPUPMENU = 169,               /* tPOPUPMENU  */
  YYSYMBOL_tSOUND = 170,                   /* tSOUND  */
  YYSYMBOL_tMEDIASOUND = 171,              /* tMEDIASOUND  */
  YYSYMBOL_tLOUDNESS = 172,                /* tLOUDNESS  */
  YYSYMBOL_tPLAY = 173,                    /* tPLAY  */
  YYSYMBOL_tSTOP = 174,                    /* tSTOP  */
  YYSYMBOL_tSIN = 175,                     /* tSIN  */
  YYSYMBOL_tASIN = 176,                    /* tASIN  */
  YYSYMBOL_tCOS = 177,                     /* tCOS  */
  YYSYMBOL_tACOS = 178,                    /* tACOS  */
  YYSYMBOL_tTAN = 179,                     /* tTAN  */
  YYSYMBOL_tATAN = 180,                    /* tATAN  */
  YYSYMBOL_tEXP = 181,                     /* tEXP  */
  YYSYMBOL_tLOG = 182,                     /* tLOG  */
  YYSYMBOL_tSQRT = 183,                    /* tSQRT  */
  YYSYMBOL_tSQR = 184,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 185,                   /* tMYEOF  */
  YYSYMBOL_tABS = 186,                     /* tABS  */
  YYSYMBOL_tSIG = 187,                     /* tSIG  */
  YYSYMBOL_tINT = 188,                     /* tINT  */
  YYSYMBOL_tCEIL = 189,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 190,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 191,                    /* tFRAC  */
  YYSYMBOL_tROUND = 192,                   /* tROUND  */
  YYSYMBOL_tMOD = 193,                     /* tMOD  */
  YYSYMBOL_tRAN = 194,                     /* tRAN  */
  YYSYMBOL_tVAL = 195,                     /* tVAL  */
  YYSYMBOL_tLEFT = 196,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 197,                   /* tRIGHT  */
  YYSYMBOL_tMID = 198,                     /* tMID  */
  YYSYMBOL_tLEN = 199,                     /* tLEN  */
  YYSYMBOL_tMIN = 200,                     /* tMIN  */
  YYSYMBOL_tMAX = 201,                     /* tMAX  */
  YYSYMBOL_tSTR = 202,                     /* tSTR  */
  YYSYMBOL_tINKEY = 203,                   /* tINKEY  */
  YYSYMBOL_tCHR = 204,                     /* tCHR  */
  YYSYMBOL_tASC = 205,                     /* tASC  */
  YYSYMBOL_tHEX = 206,                     /* tHEX  */
  YYSYMBOL_tDEC = 207,                     /* tDEC  */
  YYSYMBOL_tBIN = 208,                     /* tBIN  */
  YYSYMBOL_tUPPER = 209,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 210,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 211,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 212,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 213,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 214,                /* tMOUSEMOD  */
  YYSYMBOL_tMOUSE = 215,                   /* tMOUSE  */
  YYSYMBOL_tKEYBOARD = 216,                /* tKEYBOARD  */
  YYSYMBOL_tTRIM = 217,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 218,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 219,                   /* tRTRIM  */
  YYSYMBOL_tSTRING2 = 220,                 /* tSTRING2  */
  YYSYMBOL_tREPLACE = 221,                 /* tREPLACE  */
  YYSYMBOL_tINSTR = 222,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 223,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 224,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 225,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 226,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 227,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 228,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 229,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 230,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 231,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 232,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 233,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 234,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 235,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 236,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 237,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 238,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 239,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 240,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 241,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 242,                    /* tDATE  */
  YYSYMBOL_tTIME = 243,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 244,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 245,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 246,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 247,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 248,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 249,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 250,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 251, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 252,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 253, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 254,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 255,                   /* tEVAL2  */
  YYSYMBOL_tARGUMENT = 256,                /* tARGUMENT  */
  YYSYMBOL_257_ = 257,                     /* '-'  */
  YYSYMBOL_258_ = 258,                     /* '+'  */
  YYSYMBOL_259_ = 259,                     /* '*'  */
  YYSYMBOL_260_ = 260,                     /* '/'  */
  YYSYMBOL_UMINUS = 261,                   /* UMINUS  */
  YYSYMBOL_262_ = 262,                     /* ';'  */
  YYSYMBOL_263_ = 263,                     /* ','  */
  YYSYMBOL_264_ = 264,                     /* '('  */
  YYSYMBOL_265_ = 265,                     /* ')'  */
  YYSYMBOL_266_ = 266,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 267,                 /* $accept  */
  YYSYMBOL_program_or_expression = 268,    /* program_or_expression  */
  YYSYMBOL_program = 269,                  /* program  */
  YYSYMBOL_statement_list = 270,           /* statement_list  */
  YYSYMBOL_271_1 = 271,                    /* $@1  */
  YYSYMBOL_272_2 = 272,                    /* $@2  */
  YYSYMBOL_assignment = 273,               /* assignment  */
  YYSYMBOL_statement = 274,                /* statement  */
  YYSYMBOL_275_3 = 275,                    /* $@3  */
  YYSYMBOL_276_4 = 276,                    /* $@4  */
  YYSYMBOL_277_5 = 277,                    /* $@5  */
  YYSYMBOL_278_6 = 278,                    /* $@6  */
  YYSYMBOL_279_7 = 279,                    /* $@7  */
  YYSYMBOL_280_8 = 280,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 281,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 282,        /* string_assignment  */
  YYSYMBOL_to = 283,                       /* to  */
  YYSYMBOL_open_clause = 284,              /* open_clause  */
  YYSYMBOL_seek_clause = 285,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 286,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 287,        /* string_expression  */
  YYSYMBOL_string_function = 288,          /* string_function  */
  YYSYMBOL_number_assignment = 289,        /* number_assignment  */
  YYSYMBOL_expression = 290,               /* expression  */
  YYSYMBOL_291_9 = 291,                    /* $@9  */
  YYSYMBOL_292_10 = 292,                   /* $@10  */
  YYSYMBOL_arrayref = 293,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 294,          /* string_arrayref  */
  YYSYMBOL_coordinates = 295,              /* coordinates  */
  YYSYMBOL_function = 296,                 /* function  */
  YYSYMBOL_const = 297,                    /* const  */
  YYSYMBOL_number = 298,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 299,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 300,                  /* dimlist  */
  YYSYMBOL_function_or_array = 301,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 302,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 303,                /* call_list  */
  YYSYMBOL_304_11 = 304,                   /* $@11  */
  YYSYMBOL_calls = 305,                    /* calls  */
  YYSYMBOL_call_item = 306,                /* call_item  */
  YYSYMBOL_function_definition = 307,      /* function_definition  */
  YYSYMBOL_308_12 = 308,                   /* $@12  */
  YYSYMBOL_309_13 = 309,                   /* $@13  */
  YYSYMBOL_310_14 = 310,                   /* $@14  */
  YYSYMBOL_endsub = 311,                   /* endsub  */
  YYSYMBOL_function_name = 312,            /* function_name  */
  YYSYMBOL_export = 313,                   /* export  */
  YYSYMBOL_local_list = 314,               /* local_list  */
  YYSYMBOL_local_item = 315,               /* local_item  */
  YYSYMBOL_static_list = 316,              /* static_list  */
  YYSYMBOL_static_item = 317,              /* static_item  */
  YYSYMBOL_paramlist = 318,                /* paramlist  */
  YYSYMBOL_paramitem = 319,                /* paramitem  */
  YYSYMBOL_for_loop = 320,                 /* for_loop  */
  YYSYMBOL_321_15 = 321,                   /* $@15  */
  YYSYMBOL_322_16 = 322,                   /* $@16  */
  YYSYMBOL_323_17 = 323,                   /* $@17  */
  YYSYMBOL_324_18 = 324,                   /* $@18  */
  YYSYMBOL_next = 325,                     /* next  */
  YYSYMBOL_step_part = 326,                /* step_part  */
  YYSYMBOL_next_symbol = 327,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 328,  /* switch_number_or_string  */
  YYSYMBOL_329_19 = 329,                   /* $@19  */
  YYSYMBOL_sep_list = 330,                 /* sep_list  */
  YYSYMBOL_number_or_string = 331,         /* number_or_string  */
  YYSYMBOL_case_list = 332,                /* case_list  */
  YYSYMBOL_333_20 = 333,                   /* $@20  */
  YYSYMBOL_default = 334,                  /* default  */
  YYSYMBOL_335_21 = 335,                   /* $@21  */
  YYSYMBOL_do_loop = 336,                  /* do_loop  */
  YYSYMBOL_337_22 = 337,                   /* $@22  */
  YYSYMBOL_loop = 338,                     /* loop  */
  YYSYMBOL_while_loop = 339,               /* while_loop  */
  YYSYMBOL_340_23 = 340,                   /* $@23  */
  YYSYMBOL_341_24 = 341,                   /* $@24  */
  YYSYMBOL_wend = 342,                     /* wend  */
  YYSYMBOL_repeat_loop = 343,              /* repeat_loop  */
  YYSYMBOL_344_25 = 344,                   /* $@25  */
  YYSYMBOL_until = 345,                    /* until  */
  YYSYMBOL_if_clause = 346,                /* if_clause  */
  YYSYMBOL_347_26 = 347,                   /* $@26  */
  YYSYMBOL_348_27 = 348,                   /* $@27  */
  YYSYMBOL_349_28 = 349,                   /* $@28  */
  YYSYMBOL_350_29 = 350,                   /* $@29  */
  YYSYMBOL_endif = 351,                    /* endif  */
  YYSYMBOL_short_if = 352,                 /* short_if  */
  YYSYMBOL_353_30 = 353,                   /* $@30  */
  YYSYMBOL_end_of_if = 354,                /* end_of_if  */
  YYSYMBOL_else_part = 355,                /* else_part  */
  YYSYMBOL_elsif_part = 356,               /* elsif_part  */
  YYSYMBOL_357_31 = 357,                   /* $@31  */
  YYSYMBOL_358_32 = 358,                   /* $@32  */
  YYSYMBOL_maybe_then = 359,               /* maybe_then  */
  YYSYMBOL_inputlist = 360,                /* inputlist  */
  YYSYMBOL_361_33 = 361,                   /* $@33  */
  YYSYMBOL_input = 362,                    /* input  */
  YYSYMBOL_readlist = 363,                 /* readlist  */
  YYSYMBOL_readitem = 364,                 /* readitem  */
  YYSYMBOL_datalist = 365,                 /* datalist  */
  YYSYMBOL_printlist = 366,                /* printlist  */
  YYSYMBOL_using = 367,                    /* using  */
  YYSYMBOL_inputbody = 368,                /* inputbody  */
  YYSYMBOL_369_34 = 369,                   /* $@34  */
  YYSYMBOL_370_35 = 370,                   /* $@35  */
  YYSYMBOL_371_36 = 371,                   /* $@36  */
  YYSYMBOL_372_37 = 372,                   /* $@37  */
  YYSYMBOL_373_38 = 373,                   /* $@38  */
  YYSYMBOL_374_39 = 374,                   /* $@39  */
  YYSYMBOL_375_40 = 375,                   /* $@40  */
  YYSYMBOL_376_41 = 376,                   /* $@41  */
  YYSYMBOL_377_42 = 377,                   /* $@42  */
  YYSYMBOL_378_43 = 378,                   /* $@43  */
  YYSYMBOL_379_44 = 379,                   /* $@44  */
  YYSYMBOL_380_45 = 380,                   /* $@45  */
  YYSYMBOL_381_46 = 381,                   /* $@46  */
  YYSYMBOL_prompt = 382,                   /* prompt  */
  YYSYMBOL_printintro = 383,               /* printintro  */
  YYSYMBOL_hashed_number = 384,            /* hashed_number  */
  YYSYMBOL_goto_list = 385,                /* goto_list  */
  YYSYMBOL_gosub_list = 386                /* gosub_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */

void
yyerror(char *message) {
  error(sERROR,message);
}

void
lyyerror(int severity, char *message) {
  error(severity,message);
}


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  263
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   16612

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  267
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  663
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   512


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   266,     2,     2,     2,     2,
     264,   265,   259,   258,   263,   257,     2,   260,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   262,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   261
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   243,   243,   244,   245,   246,   247,   250,   253,   254,
     254,   254,   257,   258,   259,   260,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   278,   279,   279,   280,   281,   282,   283,   284,
     285,   286,   286,   288,   288,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   300,   301,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   318,   319,
     320,   321,   322,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   509,   510,   511,   512,   513,   517,
     518,   519,   520,   521,   522,   525,   526,   529,   530,   531,
     532,   533,   536,   537,   540,   541,   544,   545,   546,   547,
     548,   549,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   584,   585,   588,   596,   600,   601,   602,   603,
     604,   605,   606,   607,   608,   609,   613,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   636,   637,   640,   640,   641,   641,   642,
     643,   644,   645,   646,   647,   648,   649,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   660,   661,   662,
     663,   664,   665,   666,   667,   668,   669,   670,   671,   672,
     673,   676,   679,   682,   685,   686,   687,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   704,   705,   706,   707,   708,   709,   710,
     711,   712,   713,   714,   715,   716,   717,   718,   719,   720,
     721,   722,   723,   724,   725,   726,   727,   728,   729,   730,
     731,   732,   733,   734,   735,   736,   737,   738,   739,   740,
     741,   742,   743,   744,   745,   746,   747,   748,   749,   750,
     751,   752,   753,   754,   755,   758,   759,   762,   766,   767,
     768,   771,   772,   773,   774,   775,   776,   777,   778,   779,
     780,   781,   782,   783,   784,   785,   786,   789,   790,   791,
     794,   795,   796,   797,   800,   801,   804,   805,   806,   807,
     810,   813,   816,   816,   819,   820,   821,   824,   825,   828,
     829,   832,   828,   837,   838,   841,   842,   845,   846,   847,
     848,   851,   852,   855,   856,   857,   858,   861,   862,   865,
     866,   867,   868,   871,   872,   873,   876,   877,   878,   879,
     882,   883,   888,   903,   882,   908,   909,   910,   911,   912,
     913,   916,   917,   920,   921,   926,   926,   930,   931,   934,
     935,   939,   941,   940,   945,   946,   946,   950,   950,   956,
     957,   958,   959,   960,   961,   965,   966,   965,   972,   973,
     977,   977,   982,   983,   984,   985,   986,   987,   990,   991,
     991,   993,   990,   997,   998,   999,  1000,  1001,  1002,  1005,
    1005,  1010,  1011,  1014,  1015,  1018,  1020,  1022,  1019,  1026,
    1027,  1030,  1031,  1031,  1034,  1035,  1037,  1038,  1042,  1043,
    1046,  1047,  1049,  1050,  1054,  1055,  1056,  1057,  1060,  1061,
    1062,  1063,  1064,  1067,  1068,  1069,  1072,  1072,  1073,  1073,
    1074,  1074,  1075,  1075,  1076,  1076,  1077,  1077,  1078,  1078,
    1079,  1079,  1080,  1080,  1081,  1081,  1082,  1082,  1083,  1083,
    1084,  1084,  1087,  1088,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1107,  1108,
    1110,  1111,  1114,  1115
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tFNUM", "tSYMBOL",
  "tSTRSYM", "tDOCU", "tDIGITS", "tHEXDIGITS", "tBINDIGITS", "tSTRING",
  "tFOR", "tTO", "tSTEP", "tNEXT", "tWHILE", "tWEND", "tREPEAT", "tUNTIL",
  "tIMPORT", "tGOTO", "tGOSUB", "tLABEL", "tON", "tSUB", "tENDSUB",
  "tLOCAL", "tSTATIC", "tEXPORT", "tERROR", "tEXECUTE", "tEXECUTE2",
  "tCOMPILE", "tRUNTIME_CREATED_SUB", "tINTERRUPT", "tBREAK", "tCONTINUE",
  "tSWITCH", "tSEND", "tCASE", "tDEFAULT", "tLOOP", "tDO", "tSEP",
  "tEOPROG", "tIF", "tTHEN", "tELSE", "tELSIF", "tENDIF", "tIMPLICITENDIF",
  "tUSING", "tPRINT", "tINPUT", "tRETURN", "tDIM", "tEND", "tEXIT", "tAT",
  "tSCREEN", "tREVERSE", "tCOLOUR", "tBACKCOLOUR", "tAND", "tOR", "tNOT",
  "tBITNOT", "tEOR", "tSHL", "tSHR", "tNEQ", "tLEQ", "tGEQ", "tLTN",
  "tGTN", "tEQU", "tEQU2", "tPOW", "tREAD", "tDATA", "tRESTORE", "tOPEN",
  "tCLOSE", "tSEEK", "tTELL", "tAS", "tREADING", "tWRITING", "tORIGIN",
  "tWINDOW", "tDOT", "tLINE", "tCIRCLE", "tTRIANGLE", "tTEXT", "tCLEAR",
  "tFILL", "tPRINTER", "tWAIT", "tBELL", "tLET", "tARDIM", "tARSIZE",
  "tBIND", "tRECT", "tGETBIT", "tPUTBIT", "tGETCHAR", "tPUTCHAR", "tNEW",
  "tCURVE", "tSET", "tGET", "tCOUNT", "tVIEW", "tDRAW", "tFLUSH",
  "tELLIPSE", "tARC", "tPOLYGON", "tROUNDRECT", "tSCREENSHOT",
  "tBFILESIZE", "tBUTTON", "tCHECKBOX", "tRADIOBUTTON", "tTEXTCONTROL",
  "tTEXTEDIT", "tTEXTURL", "tSLIDER", "tSTATUSBAR", "tSPINCONTROL",
  "tSCROLLBAR", "tLAYOUT", "tTOOLTIP", "tOPTION", "tTABVIEW", "tBOXVIEW",
  "tSPLITVIEW", "tSTACKVIEW", "tCANVAS", "tREGION", "tADD", "tREMOVE",
  "tLISTBOX", "tDROPBOX", "tDROPZONE", "tTREEBOX", "tCOLUMNBOX",
  "tCALENDAR", "tCOLORCONTROL", "tCOLUMN", "tSORT", "tEXPAND", "tCOLLAPSE",
  "tSELECT", "tGETS", "tMENU", "tSUBMENU", "tSUBSUBMENU", "tCLIPBOARD",
  "tCOPY", "tPASTE", "tTRANSLATE", "tMESSAGE", "tATTRIBUTE", "tBITMAP",
  "tALERT", "tFILEPANEL", "tPOPUPMENU", "tSOUND", "tMEDIASOUND",
  "tLOUDNESS", "tPLAY", "tSTOP", "tSIN", "tASIN", "tCOS", "tACOS", "tTAN",
  "tATAN", "tEXP", "tLOG", "tSQRT", "tSQR", "tMYEOF", "tABS", "tSIG",
  "tINT", "tCEIL", "tFLOOR", "tFRAC", "tROUND", "tMOD", "tRAN", "tVAL",
  "tLEFT", "tRIGHT", "tMID", "tLEN", "tMIN", "tMAX", "tSTR", "tINKEY",
  "tCHR", "tASC", "tHEX", "tDEC", "tBIN", "tUPPER", "tLOWER", "tMOUSEX",
  "tMOUSEY", "tMOUSEB", "tMOUSEMOD", "tMOUSE", "tKEYBOARD", "tTRIM",
  "tLTRIM", "tRTRIM", "tSTRING2", "tREPLACE", "tINSTR", "tRINSTR",
  "tCHOMP", "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE",
  "tFRNFN_CALL", "tFRNFN_CALL2", "tFRNFN_SIZE", "tFRNBF_ALLOC",
  "tFRNBF_FREE", "tFRNBF_SIZE", "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET",
  "tFRNBF_GET2", "tFRNBF_GET_BUFFER", "tFRNBF_SET_BUFFER", "tDATE",
  "tTIME", "tTOKEN", "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB",
  "tSTART_PROGRAM", "tSTART_EXPRESSION", "tSTART_STRING_EXPRESSION",
  "tSTART_ASSIGNMENT", "tSTART_FUNCTION_DEFINITION", "tEVAL", "tEVAL2",
  "tARGUMENT", "'-'", "'+'", "'*'", "'/'", "UMINUS", "';'", "','", "'('",
  "')'", "'#'", "$accept", "program_or_expression", "program",
  "statement_list", "$@1", "$@2", "assignment", "statement", "$@3", "$@4",
  "$@5", "$@6", "$@7", "$@8", "clear_fill_clause", "string_assignment",
  "to", "open_clause", "seek_clause", "string_scalar_or_array",
  "string_expression", "string_function", "number_assignment",
  "expression", "$@9", "$@10", "arrayref", "string_arrayref",
  "coordinates", "function", "const", "number", "symbol_or_lineno",
  "dimlist", "function_or_array", "stringfunction_or_array", "call_list",
  "$@11", "calls", "call_item", "function_definition", "$@12", "$@13",
  "$@14", "endsub", "function_name", "export", "local_list", "local_item",
  "static_list", "static_item", "paramlist", "paramitem", "for_loop",
  "$@15", "$@16", "$@17", "$@18", "next", "step_part", "next_symbol",
  "switch_number_or_string", "$@19", "sep_list", "number_or_string",
  "case_list", "$@20", "default", "$@21", "do_loop", "$@22", "loop",
  "while_loop", "$@23", "$@24", "wend", "repeat_loop", "$@25", "until",
  "if_clause", "$@26", "$@27", "$@28", "$@29", "endif", "short_if", "$@30",
  "end_of_if", "else_part", "elsif_part", "$@31", "$@32", "maybe_then",
  "inputlist", "$@33", "input", "readlist", "readitem", "datalist",
  "printlist", "using", "inputbody", "$@34", "$@35", "$@36", "$@37",
  "$@38", "$@39", "$@40", "$@41", "$@42", "$@43", "$@44", "$@45", "$@46",
  "prompt", "printintro", "hashed_number", "goto_list", "gosub_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-1650)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-569)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1049, 13923, 11679, 13323,    90,   223,    70,   -59,   -53, -1650,
   -1650, -1650, -1650, -1650,    34,    34,    34,  8583, -1650, -1650,
   -1650, 13323, -1650, -1650, 13323,    45,    25, -1650, -1650, -1650,
   11679,   -41, -1650, 11679,   177, -1650, 11679, 11679, 11679,   276,
      37,    34,  3906,  3642,  4434,   162, 11679,  7293,  8841,   171,
     -16, 11679, -1650,    24, 13323, 13323, 13323,   -13,  7551,  1372,
   11679, 11679,  9099,  9357,  7809,  6261, 11679,  6777,  9615,  9873,
   12307, 13323, 13323,   -37,  7035, 10131, 10389, 10647, 11679, 11679,
    6003,  6519,  5487,  5745, 10905, 11163, 12434, 12564, 12691,   -17,
     -15,  8067, 13323,   -62,   -69,    23,  -102,   -91,   -54,    -9,
      18,  4434, 13323, 13323, 13323, -1650,   155, -1650, -1650,    68,
   -1650, -1650, -1650, -1650,   148,   164, -1650,   241, -1650, -1650,
   -1650, -1650, -1650, -1650, -1650, -1650,    29,    43, -1650, -1650,
   -1650, -1650,    52,    91,   101,   116, 11679,   124,   128,   134,
     138,   140,   161,   115,   174,   176,   187,   193,   217,   210,
     -79,    -8,   220,   278,   294,   -70,   -64,   -31,   -10,   336,
     376,   349,   127,   257, -1650,    47, 13323, 11679,   366,   368,
     476,   364,   380,   384,   394,   408,   410,   428,   455,   470,
     490,   519,   525,   529,   558,   582,   597,   608,   625,   643,
     655,   664,   665,   674,   678,   694,   698,   712,   728,   736,
     737,   739,   740,   749,   755,   772,   783,   785,   789,   796,
     797,   621,   654,   828,   840,   852,   853,   854,   863,   867,
     869,   873,   885,   891,   892,   901,   942,   945,   954,   955,
     956,   958,   965,   983,   985,  1002,  1008,  1014,  1023,  1024,
    1025,  1044,  1056, 11679, 11679,   226, -1650,   392, -1650, -1650,
   -1650, -1650,   651,   748,   784,   830,   877, 13323,   -29,   908,
     148,   164,   916, -1650, 11679, -1650, 13323, -1650,   990, 11679,
   13696, -1650, -1650, -1650, -1650, -1650,   308,   590,   482,   546,
     777, -1650, 11679, -1650,   777, -1650, -1650, 11679, 13696,   566,
    1057,  1010,  1058,     5, 11679,   -35,   226, 12041,  1059,  1060,
     780, 12041,   226,   850,   226, 12168,  1073,  1076,   839, -1650,
   -1650,   624,   624, -1650, -1650,   851, -1650,  8325, 13323, 11679,
     113, 12041,  1006,   115, -1650, -1650, -1650,  1086, 11679, 13323,
   13323, 13323, 12425, -1650, 11679, -1650,     1, 13323,  1087, -1650,
   -1650, 11679, 11421, -1650, -1650, 12041, -1650, -1650,   777,    -5,
      -5, -1650, 13323, 13323,     1, 11679, 11679, 11679, 11679, 11679,
   11679, 11679, 13323, 13323, 11679, 11679, 11679, 11679, 11679,     1,
       1, 13323,  1088, 13323,  1089, 13323, 13323,     1, 13323, 13323,
   13323, 13323,     1,  1090, 13323, 13323, 13323,     1, 13323,     1,
   13323,  1102, 13323,  -170,    50,   154, 13323, 13323, 13323, 13323,
   13323,     1, 13323,     1, 13323,     1, 13323,     1,     1,     1,
   13323, 13323, 13323, 13323, 13323,     1, 13323, 13323, 13323, 13323,
       1, 13323, 13323, 13323, 13323, 13323, 13323, 13323,     1, 13323,
   13323, 13323, 12816, 13323, 13323,     1, 13323,  1112, 13323,  1118,
   13323,   255, 13323,   327, 13323,   431, 13323, 13323, 13323, 13323,
   13323, 13059,   480, 11679, 11679, 11679, 11679,  1203,  1203,  1203,
    4698, 13323,   142,  1122,   777,   541,   767, -1650,  1243, 11679,
   11679, 11679, 11679, 13323, -1650, -1650, -1650, 11679, 11679,  1384,
   11679, 11679, 11679, 11679,  4170,  4434, 13323, -1650,   572,   572,
   11679, 11679, 13323, 13323, 13323, 13323, 13323, 13323, 13323, 13323,
   13323, 13323, 13323, 13323, 13323, 13323, 13323, 13323, 13323, 13323,
   13323, 12943, 13323, 13323, 13323,  1109, -1650, 13323,  1125,  1127,
     768,  1130, 13323, 13323, -1650, 11679, 11679, 11679, 11679, 11679,
   11679, 11679, 11679, 11679, 11679,  4434, 11679, 11679, 11679, 11679,
   11679, 11679, 11679, 11679,  4961, 13323, 13323, 13323, 13323, 13323,
   11679, 11679, 11679,  5224, 11679, 13323, 11679, 13323, 11679, 13323,
   13323,  2384, 11925, 12050, 12177, 13323, 13323, 13323, 13323, 13323,
   11679, 13323, 13323, 13323, 13323, 13323, 13323,  4434, 13323, -1650,
   -1650, 13323, 11679, 13323, 13323, 13323, 13323, 13323,  1136,  1150,
   13323,  1203, 13323,  1203, 13323, 13323, 13323,  1169,    65,   676,
   13323, 13323, 13323, 13323, 13323, 13323, 13323, 13323, -1650, -1650,
   -1650, 11679, 11679, 11679, 11679, 11679, 11679, 11679, 11679, 11679,
   11679, 11679, 11679,   -57, -1650, -1650, -1650, 12041,  1152,   777,
    1175,  1359, 12041,   317, -1650, -1650, -1650, -1650,  1179,  1180,
    1190, -1650,  1204,  1205,  1221, -1650,   226, 12041,  1224, -1650,
     226, 12041,  1424,  1110,  1449, 13696, 11679,  1253, 13323, -1650,
   -1650, 11679,   226,   605,   343,  1262,  1475,  1280,     7, -1650,
    1515, -1650, -1650,   603, 11679, 11679, -1650, -1650,   276, -1650,
   -1650,    53, 13509,   777, 12041,   560, 13068, 11679,     1,   777,
     777,   769, 11679, -1650,   -35, -1650, -1650, 11679,   771, 13323,
   -1650, 11679,     1, 11679, 11679,   777,   777, 11679,  1272,     1,
    1288,     1,  1297,     1,     1,   779,   777,  1301,  1307,     1,
       1, 13839, 11679, 11679,   787, 13323,   793, 13323,   777,   804,
   11679,   806,   777,   825,   832, 11679, 13323,   833,   836,   843,
   11679,   872, 11679,   876, 13323,   883, 11679, 13323, 13323,   887,
     889,   890,   899,   900, 11679,   918, 11679,   920, 11679,   922,
   11679, 11679, 11679,   777,   924,   926,   777,   928, 11679,   777,
     944,   968,   970, 11679,   777,   972,   978,   777,   979,   980,
     981, 11679,   982,   777,  1004, 13323,  1005,  1007,  1022, 11679,
    1075, 13323,  1078, 13323,  1106, 13323,  1114, 13323,  1116, 13323,
     777,  1145,  1146,  1149,   777, 11679, 13323, 12041, 12041, 12041,
   12041,  1317,  1337,  1357,  1367, -1650,  1140,    12, 11679, 11679,
   11679, 11679, -1650,  1373,     1,     1, 12041,   777,   666,  1374,
    1380, 14066, 14145,  1220, 14264, 14286, 14322,  1400,    56,  1392,
    1402,  1153,  1394,  1415,  1416,  1417,  1403,  1435,     1, 14343,
    1156,    59,   777,   777,   777,   777,   777,  1160,   777,   777,
     777,  1163,   777,   777,  1167,   777,   777,  1170,   777, 13323,
     777,  1174,   777,  1212, 13323,    60, 13323, 13323, 13323, 13323,
    1223,   777,  1240,  1255,  1375,  1519,  1598,   696,  1613,   757,
    1755,  1820,  1436,  1908,  2033,  2048,  2070,  2127,  2144,  2277,
   14358, -1650,  2298,    98,  1238,  1244,  1245,    99, 14373, 14388,
     104,   781, -1650,  2422,  2442,   109,  2587,   -56,  2850,   126,
     184, -1650,   195, -1650,   215, -1650,   282, -1650,   321,   777,
     777,   449,   458,   463, 14403,  1246,  1248,  1258,   471,   472,
     477,   121,  1448,   -39,  1451,  1458,   516,  2878,   521,    -6,
    1260,  1261,  1269, -1650, -1650,  1278,  -152,  1279,  -118,  1289,
     522,   526, -1650, -1650,   777,   777,   777,   777,   777,   777,
     777, -1650, 11679, 11679,  1000,   688,  1271,   610,   -11,   518,
     -23, -1650,   -27,   -27,  1169,  1169, -1650, -1650, -1650, 13696,
   -1650, -1650, 11679, -1650, -1650, -1650, -1650,    34,    34, -1650,
   -1650,   482, -1650, -1650,   546, 11679, -1650,  1500, -1650, -1650,
   -1650, -1650, -1650, -1650, -1650, -1650,   656, 14418, 11679,    20,
    2924, 13450, -1650, -1650, 11679, 11679,  1445, 13323, -1650, -1650,
   11679, -1650,   713,  1466,  1470,  1465,  1486, 14433, 14462,  1488,
    1497, -1650, -1650, -1650, 11679,  1495,  1552, -1650,  1292, 14484,
   11679, 13323, 12041, -1650, -1650, 13323,  1295, -1650, 11679, 14499,
   14520,  1502, 13323, 11679, 11679, 11679, 13323, 11679, 11679, 11679,
   11679, 11679, 11679, 11679, 11679,  1508,  1509, 11679,  1296, 11679,
    1299, 11679,  1522, 13323, 13323, 13323,  1537,  1303, 13323, 13323,
   11679,  1559, 13323,  1560, 11679,  1305, 13323, 14631,   777,   777,
   13323, 13323, 11679, 13323, 11679,  1572, 13323,  1580, 13323,  1581,
   11679,  1605,  1614,  1623, 11679, 11679, 11679,  1625, 13323, 11679,
   11679,  1626, 13323, 11679, 13323, 13323, 11679,  1635, 13323, 11679,
    1309, 11679, 13323, 11679,  1636, 13323,  1313, 11679,  1315, 11679,
    1316, 13323,  1339, 13323,  1346, 13323, 13323, 13323, 14660,  1352,
   -1650, 11679, 11679, 11679, -1650, -1650,   226, 12041,   226, 12041,
   14697, 14718, 13696, 11679, 11679, 11679, -1650, -1650, -1650, -1650,
   -1650, 11679, 11679, -1650, 11679, 11679, 11679, -1650, 13323, -1650,
   13198, -1650, 13323,  1645,  1659, -1650, -1650, 11679, 11679, 11679,
   11679, 13323, -1650, 13323, 11679, 11679, 11679,   777, 11679, 13323,
     537, -1650,  1353,  1354,  1355,  1356, 11679, -1650, -1650, -1650,
   -1650, -1650, 11679, -1650, -1650, 11679, -1650, -1650, -1650, -1650,
   -1650, -1650, -1650, -1650, -1650, -1650, -1650, 11679, -1650, -1650,
   11679, 11679, 11679, -1650, 11679, 11679, -1650, 13323, -1650, -1650,
   -1650, -1650, -1650, 11679, -1650, -1650, -1650, -1650, -1650, -1650,
   -1650, -1650, -1650, -1650, -1650, 13323, 13323, 13323, 13323, -1650,
   -1650, -1650, -1650, -1650, 13323, -1650, -1650, -1650, -1650, -1650,
   -1650, 11679, -1650, 11679, 11679, 11679,  1633, 13323, -1650,  1633,
   13323, -1650, 13323, -1650, -1650,  1384,   452, 11679,    15, 12041,
   -1650,  1637, -1650,  1638,  1681,  1692, -1650,  1696,  1722, -1650,
   -1650, -1650,   717, 13696, -1650, -1650, -1650, 11679, 14733, 13323,
    1622, -1650, 13323,   777,   226,   605, 14748, 11679,    82,   713,
     713,  2942,  1654,  1680, -1650,  1713, -1650, -1650, -1650, -1650,
   11679, 11679, -1650, -1650, 14763,  4434,  4434, 13323, 13323,  1714,
    1363,   777, 13323, -1650, 11679, 11679, 13323,   777,  1726, 14778,
       1,  1364,  1727,     1,   226, 14793, 14808, 14829,     1,  1730,
   14858, 13323, 13323, 12041, 13323, 12041, 13323,   226, 12041, 13323,
    1365,   777,   777, 13323, 13323,  1366,  1389,   462, 12041, 13323,
    1390, 13323, 12041, 13323,  1391, 13323,  1393,  1401, 12041,   777,
   12041, 13323,  1433, 13323,  1434, 13323, 12041, 13323, 13323, 13323,
     226, 14873,   226, 12041, 12041, 13323,   777, 12041, 12041, 13323,
    1441,   543, 12041,   777,   777, 12041, 13323,  1442, 14895, 11679,
   12041,  1444, 12041, 13323,   777, 13323, 15006, 13323,   550, 15027,
   13323,  1452, 13323,  1454, 13323,   777,  1461,  1464, 13323, 13323,
    1735,  2980,  2996,   935, 13323, 13323, -1650, 12041,     1, -1650,
    1743,  3018,  3241,  3318,  3335,  3538,   540,  1740,    83,   777,
   -1650, -1650,  4456,  4720,  1746,    79,  1467,   777, 12041, 12041,
   12041, 15071,   777, -1650, 13323, 13323, 13323, 13323, 12041,  4983,
    5246,  6799,  7057,  7315,  1097,  7573,  8089,   196,  8347,   552,
    1480,   213,   214,   554,  8605, 15093, 15108,  8863,   -65,   640,
     -25,   641,   644,    46, -1650, -1650, -1650,    34,    34, -1650,
   -1650, -1650, -1650, 11679,  1900,  1965,  1973,  9121, 11679,   645,
    1753,   290, -1650, 11679, 15123, 13323,  1960, -1650, -1650, -1650,
   -1650, -1650, -1650,  1754,  1757, 12041, 12041, 13323, -1650, -1650,
     777,   777, 13323, 13323,  1481, 15138, 12041,  1493, 13323, 13323,
   11679, 13323, 13323, 11679, 11679, 11679, 11679, 11679, 11679, 13323,
     777,  1501,  1503,  1505,  1511, 11679,  1517,  1523, 13323, 11679,
   11679,  1524, 13323,  1525,  1535, 11679,   777, 11679, 11679,  1536,
   13323,  1538, 11679,  1539,  1546,  1548,  1550, 13323,  1554,  1557,
   11679, 13323,  1558, 11679, 11679, 12041, 11679,  1575,  1576, 11679,
     777, 13323, 13323,  1578, 11679,  1579, 13323,  1587, 13323, 13323,
     777,   777, -1650,  1949,  1950, 11679,  1953,  1589,   777, 11679,
     838, -1650, -1650, -1650, -1650, -1650, -1650, -1650, 13323, -1650,
   -1650, -1650, -1650, 11679, 13323, 11679,   650,   672,  1596,   777,
   -1650, -1650, -1650, -1650, -1650, 11679, -1650, -1650, -1650, 13323,
   -1650, -1650, -1650, 13323, 11679, -1650, 11679, -1650, -1650, -1650,
   13323, 11679, -1650, 13323, -1650, -1650, 13323, -1650, -1650, -1650,
   11679, -1650, -1650, -1650, -1650, -1650,  1981,   799,  9379,  1974,
   11679, 13323,  9637, 11679,   685,  1767,  1515,   713,  1770,  1771,
     713, -1650, -1650,   777,  1602,   777, 13323, 13323, 13323,   777,
     777,  1774,   777,   777,     1, 15153, 15168, 15183,     1, 15204,
    1603, 13323, 11679, 11679, 13323, 15225, 11679, 13323,   777, 15240,
   12041, 13323,  1604, 13323, 11679, 15269, 15381,   226, 12041, 13323,
     777, 13323, 15402, 11679, 11679, 13323, 13323,   777, 11679, 13323,
     765, 12041,   777, 11679, 15438, 15467, 15482, 11679, 13323, 15497,
    1606,   777, 13323,   807, 15512, 13323,  1616, 13323,  1617,   777,
   13323, 13323,  9895, 13323, 11679, -1650,  1775,  1776,     3, -1650,
     699, 15527,   777, 12041, -1650, -1650, 13323, 10153,   708,   710,
   10411, 10669,   714, 10927,   716,   720,    94, 13696, 14150, 11679,
    1994, -1650,  1779, -1650,  1780, 15542,   722,   857, 11185,  1987,
   11679,   713, -1650, -1650, -1650, -1650, 13323,   777,   777,   777,
   13323, 11679, 11679, 13323, 11679, 11679, 11679, 13323,  1618, 15557,
   15579,  1644, 11679, 15600,  1653, 11679,  1656, 11679,  1668, 15615,
   11679, 11679,  1669,  1670, 11679, 15636, 15755,   777,   777, 15777,
    1676, 11679, 15813, 11679, 11679, 11679, 15834,  1678, 11679, 13323,
     777, 13323, 13323,  1679, 11679,  1687, 13323,   777,   777,  1971,
     777, 12041,  1782,  1783,   838, -1650, -1650, 11679,   777, -1650,
   -1650, -1650, -1650, -1650, -1650, -1650, -1650, -1650, 11679, -1650,
    1973,  2011,   627, 13696, -1650, 13323, 11679, 11679, -1650, -1650,
    1786,  1515, -1650,  1788,  1515, 15849, -1650,   777,   777,  1790,
   15864,   777, 15879,  1791, 15894,  1695, 13323, 13323, 13323, 13323,
   15909, 13323, 13323, 15924, 11679, 12041, 13323, 11679, 12041, 15953,
   13323, 11679, 12041, 11679, 13323, 13323, 13323, 12041, 13323, 15975,
   15990, 16011, 13323, 13323, 12041,   777,  1697,   777, 13323,   821,
   16122, 13323,   777, 13323, -1650, -1650, -1650, 13696, 11443, 12041,
   13696, -1650, -1650,  1973,  1183,   430, 16151, 11701,  1515, 13323,
     713,  1515, 11679,   713, 11679, 13323, 13323, 11679, 13323, 13323,
   13323,   777,   777,   777,  1701, 11679,   777,   777, 11679, 16188,
    1711, 16209, 11679,   777, 16224, 16239,   777,   777,   777,   777,
   11679, 13323, 11679,  1712,   777, 13323,   777, 13323, 13323,  1738,
     777,    62, -1650,  1973, 13696, -1650, -1650, -1650, -1650, -1650,
   -1650, -1650, 13323, -1650, 11679, -1650,   713,   450, -1650,   713,
   16254, -1650, 11926,   777,   777, 16269,   777,   777,   777, 13323,
   12041, 12041, 11679, 13323, 11679, 12041, 13323, 13323, 12041,   777,
   16284, 13323,   777,  1739,   777, 13323, -1650, -1650, -1650,  1207,
    1973,   730, 11944, -1650, 13323, -1650, -1650, 11679, -1650, 13323,
     777, 16299,   777, 16320,   777,   777, 11679,   777, 13323,   777,
   -1650, -1650, -1650, -1650, -1650, -1650,  2051,  1981, -1650, -1650,
     731,  1515, 11963,  1515,   777, 13323, 13323, 16349,   777, -1650,
   -1650, -1650, -1650,   713, -1650,   713,  1741,   777, 13323,  1515,
   -1650,  1515, -1650, 13323,   777,   713,   713,   777, -1650, -1650
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   244,     0,     0,     0,   497,     0,     0,     0,   238,
     520,   555,   560,    18,     0,     0,     0,     0,    31,    33,
     498,     0,   482,   482,     0,   499,    25,    27,   535,   547,
       0,   644,    55,    67,     0,   235,   236,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   245,
     246,     0,   226,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   227,
       0,     0,     0,     0,     0,     2,     9,    17,     8,     0,
      12,    46,    48,    14,    29,    30,    28,     0,    20,    21,
      24,    23,    22,    35,    36,   470,   355,   266,   471,   472,
     473,   269,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   316,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   280,
       0,     0,     0,     0,     0,     0,     0,   415,   418,   421,
     424,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   297,   299,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   267,     0,   369,   349,
     354,   268,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,   482,     0,   482,     0,     0,
      16,   475,   474,    37,    38,    45,     0,     0,     0,     0,
      19,    50,   484,    51,    49,   500,    26,     0,    16,   579,
       0,   648,     0,     0,   608,   640,    69,    68,     0,     0,
      70,   237,    60,     0,    62,     0,   600,   602,    63,   598,
     604,     0,     0,   605,   467,    64,    66,     0,   222,     0,
       0,   659,     0,    92,   224,    86,    47,     0,     0,     0,
       0,     0,     0,    74,     0,    57,    79,     0,     0,    94,
      93,     0,     0,   247,   248,   225,    13,    15,   239,     0,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   240,     0,     0,     7,     0,     0,
       0,     0,     0,     0,   489,   482,   482,     0,     0,   339,
       0,     0,     0,     0,     0,     0,     0,   445,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   315,     0,     0,     0,
       0,     0,     0,     0,   450,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   482,
     482,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,   337,
     335,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     6,   333,     0,   249,
       0,     0,   556,     9,    39,    40,    41,    43,   503,   504,
      32,   501,   509,   510,    34,   507,   487,   488,   483,   485,
     540,   539,     0,     9,     0,    16,     0,     0,     0,   645,
     646,     0,   611,   613,    52,     0,     0,     0,     0,    56,
     642,   482,   482,     0,     0,     0,   482,   482,     0,   469,
     468,     0,     0,   223,   658,     0,     0,     0,     0,    96,
      73,     0,     0,    78,   640,   256,   255,     0,     0,     0,
      75,     0,    81,     0,     0,    99,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
       0,     0,   137,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,   176,     0,     0,   181,
       0,     0,     0,     0,   190,     0,     0,   193,     0,     0,
       0,     0,     0,   200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,     0,     0,     0,   220,     0,     0,   119,   118,   120,
     121,   264,     0,     0,     0,   228,     0,     0,     0,     0,
       0,     0,    10,     0,     0,     0,   334,   254,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   302,   306,   303,   307,   463,     0,   462,   452,
     451,     0,   454,   453,     0,   456,   455,     0,   459,     0,
     457,     0,   312,     0,     0,     0,     0,     0,     0,     0,
       0,   449,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   395,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   281,     0,     0,     0,     0,     0,     0,     0,
       0,   416,     0,   419,     0,   422,     0,   425,     0,   317,
     318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   298,   300,     0,     0,     0,     0,     0,
       0,     0,   271,   370,   364,   366,   368,   365,   367,   362,
     363,   270,     0,     0,   342,   344,   346,   343,   345,   340,
     341,   360,   357,   356,   358,   359,   480,   481,   521,    16,
     567,   565,     0,   566,   562,   564,   561,     0,     0,   482,
     482,     0,   482,   482,     0,     0,   537,   541,   554,   552,
     553,   550,   549,   551,   548,   569,     9,     0,     0,     0,
       0,     0,   609,    53,    54,     0,     0,     0,   616,   618,
       0,   643,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   599,   606,   607,     0,     0,     0,   259,   258,   262,
       0,     0,   373,    58,    76,     0,    89,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     482,     0,     0,     0,   229,   230,   231,   232,   233,   234,
       0,     0,    16,     0,     0,     0,   495,   496,   490,   437,
     329,     0,     0,   428,     0,     0,     0,   438,     0,   439,
       0,   432,     0,     0,     0,   350,   351,     0,     0,     0,
       0,     0,   466,     0,     0,     0,     0,   458,     0,     0,
       0,   313,     0,     0,     0,     0,     0,   374,   375,   376,
     377,   378,     0,   379,   381,     0,   382,   384,   385,   347,
     391,   392,   386,   388,   389,   390,   387,     0,   394,   399,
       0,     0,     0,   398,     0,     0,   279,     0,   276,   282,
     283,   400,   327,     0,   401,   328,   284,   285,   414,   417,
     420,   423,   288,   286,   287,     0,     0,     0,     0,   291,
     407,   292,   413,   412,     0,   301,   408,   293,   409,   294,
     411,     0,   295,     0,     0,     0,     0,     0,   322,     0,
       0,   324,     0,   444,   332,   338,   336,     0,     9,   563,
     660,    42,   662,    44,     0,     0,   502,     0,     0,   508,
     486,   538,   544,    16,   581,   582,   580,     0,     0,     0,
     649,   647,     0,   614,   612,   613,     0,     0,     0,     0,
       0,     0,   594,   596,   641,   591,   476,   478,   482,   482,
       0,     0,   601,   603,    71,     0,     0,     0,     0,     0,
       0,   128,     0,    77,     0,     0,     0,   104,     0,     0,
       0,     0,     0,     0,   101,     0,     0,     0,     0,     0,
       0,     0,     0,   124,     0,   126,     0,   131,   132,     0,
       0,   136,   135,     0,     0,     0,     0,     0,   144,     0,
       0,     0,   151,     0,     0,     0,     0,     0,   158,   157,
     159,     0,     0,     0,     0,     0,   166,     0,     0,     0,
     170,     0,   172,   173,   174,     0,   178,   180,   179,     0,
     183,   186,   187,   191,   192,   189,     0,     0,     0,     0,
     197,     0,   199,     0,   203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   217,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    87,     0,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   446,
     371,   372,     0,     0,     0,     0,   464,   461,   308,   309,
     310,     0,   460,   314,     0,     0,     0,     0,   448,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   559,   558,   557,     0,     0,   505,
     506,   511,   512,     0,     0,     0,   570,     0,     0,     0,
       0,     0,   610,     0,     0,     0,   630,   617,   619,   620,
     482,   482,   592,     0,     0,    59,    61,     0,   260,   261,
     257,   263,     0,     0,    90,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   198,     0,     0,     0,     0,
     204,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     218,   117,   265,     0,     0,     0,     0,   242,   243,     0,
     513,   426,   427,   429,   430,   431,   440,   441,     0,   442,
     352,   353,   325,     0,     0,     0,     0,     0,     0,   304,
     380,   383,   393,   272,   273,     0,   275,   396,   397,     0,
     277,   402,   289,     0,     0,   403,     0,   405,   320,   296,
       0,     0,   331,     0,   434,   321,     0,   436,   323,   348,
       0,   661,   663,   542,   545,   536,   585,   651,     0,   650,
       0,     0,     0,     0,     0,     0,   642,     0,     0,     0,
       0,   477,   479,    72,     0,    97,     0,     0,     0,   105,
     108,     0,   103,   106,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,     0,
     142,     0,     0,     0,     0,   146,     0,   152,   153,     0,
     161,     0,   163,     0,     0,     0,     0,   171,     0,     0,
       0,   185,   188,     0,     0,     0,     0,     0,     0,     0,
       0,   207,     0,     0,     0,     0,     0,     0,     0,   219,
       0,     0,     0,     0,     0,    88,   516,   517,     0,   514,
       0,     0,   465,   311,   447,   319,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   531,    16,   244,     0,
     583,   655,     0,   652,     0,     0,     0,   622,     0,   632,
       0,     0,   621,   595,   597,   593,     0,   127,    82,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     206,     0,     0,     0,     0,     0,     0,   252,   253,     0,
     251,   241,     0,     0,     0,   491,   443,     0,   305,   274,
     278,   290,   404,   406,   410,   330,   433,   435,     0,   522,
     543,     9,   589,    16,   571,     0,     0,     0,   615,   634,
       0,   642,   624,     0,   642,     0,   631,    95,   112,     0,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,     0,     0,   147,     0,
       0,     0,   164,     0,     0,     0,     0,   184,     0,     0,
       0,     0,     0,     0,   205,   208,     0,   210,     0,     0,
       0,     0,   216,     0,   518,   519,   515,    16,     0,   532,
      16,   590,   586,   584,     0,     0,     0,     0,   642,     0,
       0,   642,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   123,   125,     0,     0,   134,   129,     0,     0,
       0,     0,     0,   156,     0,     0,   165,   169,   177,   182,
       0,     0,     0,     0,   202,     0,   209,     0,     0,     0,
     250,     9,   326,   523,    16,   578,   575,   576,   577,   573,
     574,   572,     0,   656,     0,   653,     0,     0,   623,     0,
       0,   633,     0,   111,   102,     0,   113,   107,   221,     0,
     138,   143,     0,     0,     0,   154,     0,     0,   201,   196,
       0,     0,   211,     0,   214,     0,   494,   493,   492,     0,
     587,     0,     0,   635,     0,   636,   625,     0,   626,     0,
     130,     0,   148,     0,   160,   162,     0,   194,     0,   212,
     526,   528,   529,   530,   525,   527,   533,   585,   657,   654,
       0,   642,     0,   642,   110,     0,     0,     0,   213,   534,
     524,   588,   638,     0,   628,     0,   139,   150,     0,   642,
     637,   642,   627,     0,   195,     0,     0,   140,   639,   629
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1650, -1650, -1650,  -180, -1650, -1650,  2053,   896, -1650, -1650,
   -1650, -1650, -1650, -1650, -1650,  2006,   562, -1650, -1650,  -387,
      -3, -1650,  2007,  1704, -1650, -1650,  1573,  -479,  2399, -1650,
    1382,   -36,   -14, -1650,     2,     4,    55, -1650, -1650,  1061,
    2056, -1650, -1650, -1650, -1650, -1650, -1650, -1650,  1063, -1650,
    1064, -1650,   203, -1650, -1650, -1650, -1650, -1650, -1650, -1650,
   -1650, -1650, -1650, -1650,   556, -1650, -1650, -1650, -1650, -1650,
   -1650, -1650, -1650, -1650, -1650, -1650, -1650, -1650, -1650, -1650,
   -1650, -1650, -1650, -1650, -1650, -1650, -1650, -1650, -1650,    -7,
   -1650, -1650, -1650, -1205, -1650, -1650, -1650,  1395, -1650, -1650,
     756,  1381, -1650, -1650, -1650, -1650, -1650, -1650, -1650, -1650,
   -1650, -1650, -1650, -1650, -1650, -1649, -1650,    32, -1650, -1650
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,   105,   106,   468,  1162,   107,   108,   278,   279,
     997,   998,   295,   694,   109,   110,   697,   111,   112,   812,
     245,   246,   113,   332,   973,   972,   844,   845,   333,   248,
     313,   249,   273,   300,   250,   251,   281,   282,   648,   649,
     116,   828,  1450,  1947,  2048,  1168,   117,   640,   641,   644,
     645,  1768,  1769,   118,   268,  1287,  1950,  2049,  2076,  1879,
    2090,   119,   287,  1007,   652,  1302,  1787,  1515,  1788,   120,
     288,  1014,   121,   269,   989,  1506,   122,   270,   996,   123,
     654,  1303,  1676,  1954,  2011,   124,   655,  1306,  1884,  1790,
    2004,  2077,  1952,  1324,  1690,  1325,   308,   309,   315,   664,
    1022,   669,  1319,  1320,  1687,  1891,  1961,  2083,  2101,  1686,
    1894,  1958,  2081,  2099,   670,  1032,   294,   322,  1291,  1293
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     258,   274,   275,   114,   314,   115,   260,   695,   261,   659,
     847,  1028,   660,   695,  1029,   624,   264,   290,   280,   291,
     292,   284,   266,   665,   396,   666,   667,   316,     7,     8,
     296,  1504,   286,   494,   302,   304,   453,  1801,   271,   320,
     125,   272,   501,   502,   128,   129,   130,   310,   504,   505,
     618,   348,   349,   350,   618,   260,   125,   261,  1670,  1505,
     128,   129,   130,  1042,   616,   617,   618,   393,   394,   395,
     263,   813,   814,   285,   397,   326,   327,   495,   283,   344,
     447,   507,   508,   441,   443,   445,   503,  2046,   607,   452,
     633,   695,   506,   746,     7,     8,   448,   351,   462,   464,
     465,   466,   510,   511,   496,   455,  2047,  1878,   653,   609,
     610,  1277,   454,  1278,  1527,  1528,   611,   612,   613,   614,
     615,   616,   617,   618,   685,   509,   600,   601,   602,   603,
     604,   605,   606,   463,   456,   600,   601,   602,   603,   604,
     605,   606,   609,   610,   446,  1280,   512,  1281,   497,   611,
     612,   613,   614,   615,   616,   617,   618,   609,   610,   518,
     469,   470,   457,   520,   611,   612,   613,   614,   615,   616,
     617,   618,   471,   458,   600,   601,   602,   603,   604,   605,
     606,   298,   299,   600,   601,   602,   603,   604,   605,   606,
      53,   600,   601,   602,   603,   604,   605,   606,  1663,   467,
    1664,   607,   607,   519,   956,   265,   958,  1243,   962,  1244,
     459,   267,   600,   601,   602,   603,   604,   605,   606,   607,
      96,    97,    98,   472,  1264,   293,  1265,   486,   487,   607,
     339,   668,   621,   622,   619,   620,   621,   622,  1666,   473,
    1667,   598,  1960,   328,   329,  1963,   619,   620,   621,   622,
     330,    20,   607,   607,   623,   460,    25,  1271,   696,  1272,
     340,   341,   342,   629,   696,   474,  1864,   343,  1865,   661,
     607,  1030,   114,   331,   115,   679,   680,  1155,   607,   646,
     306,   307,   461,  1309,   650,  1310,    96,    97,    98,   516,
     114,   662,   115,   265,   311,   312,   600,   601,   602,   603,
     604,   605,   606,   619,   620,   621,   622,   267,   607,  2016,
     311,   312,  2019,   747,   607,   683,   475,   607,   607,  1178,
     628,  1179,   630,   607,  1192,  1201,   689,   690,   691,   492,
     962,   990,   498,   991,   698,   992,   619,   620,   621,   622,
     607,   607,   696,   634,   635,  1525,  1628,  1526,  1629,   705,
     706,   619,   620,   621,   622,   476,   607,   607,   993,   715,
     716,   994,   607,  1229,  1233,   477,   995,   607,   724,  1236,
     726,   607,   728,   729,  1241,   731,   732,   733,   734,   607,
     478,   737,   738,   739,   607,   741,  1262,   743,   480,   745,
     499,  1246,   481,   749,   750,   751,   752,   753,   482,   755,
     607,   757,   483,   759,   484,   818,   500,   763,   764,   765,
     766,   767,   607,   769,   770,   771,   772,   748,   774,   775,
     776,   777,   778,   779,   780,   485,   782,   783,   784,   786,
     787,   788,  2093,   790,  2095,   792,   608,   794,   488,   796,
     489,   798,   607,   800,   801,   802,   803,   804,   513,  1247,
    2105,   490,  2106,   607,   607,   609,   610,   491,   817,  1649,
    1248,  1650,   611,   612,   613,   614,   615,   616,   617,   618,
     827,   607,   607,   607,   493,  1016,  1654,  1656,  1655,  1657,
    1249,   838,  1802,   841,   607,  1805,   638,   639,   514,   850,
     851,   852,   853,   854,   855,   856,   857,   858,   859,   860,
     861,   862,   863,   864,   865,   866,   867,   868,   870,   871,
     872,   873,   515,   607,   875,   609,   839,   840,   795,   880,
     881,   517,   611,   612,   613,   614,   615,   616,   617,   618,
     829,   830,   600,   601,   602,   603,   604,   605,   606,   522,
     607,   523,   903,   904,   905,   906,   907,  1250,   607,   910,
     642,   643,   915,  1681,   917,   962,   919,   920,   922,   924,
     926,   928,   929,   930,   931,   932,   933,   892,   935,   936,
     937,   938,   939,   940,   941,   943,   842,   843,   946,   607,
     948,   949,   950,   951,   952,   607,  1251,   955,   524,   957,
     797,   959,   960,   961,   617,   618,  1896,   964,   965,   966,
     967,   968,   969,   970,   971,  1023,  1024,  1035,  1036,   942,
     636,   637,  -568,   600,   601,   602,   603,   604,   605,   606,
     600,   601,   602,   603,   604,   605,   606,   125,   525,   609,
     610,   128,   129,   130,   944,   945,   611,   612,   613,   614,
     615,   616,   617,   618,   526,   314,  1045,  1046,   527,   619,
     620,   621,   622,   609,   610,  1019,  1021,   114,   528,   115,
     611,   612,   613,   614,   615,   616,   617,   618,   609,   610,
    1166,  1167,   529,  1951,   530,   611,   612,   613,   614,   615,
     616,   617,   618,  1048,   615,   616,   617,   618,   607,   607,
     609,   610,   531,  2012,   799,  2013,  1056,   611,   612,   613,
     614,   615,   616,   617,   618,  1304,  1305,   607,   607,   619,
     620,   621,   622,  2054,  1252,  2055,   607,  1322,  1323,   532,
     607,   607,  1078,  1253,  1080,  1570,  1033,  1034,  1254,   607,
     607,  1039,  1040,  1087,   533,   607,  1259,  1260,   607,   609,
     610,  1095,  1261,   806,  1098,  1099,   611,   612,   613,   614,
     615,   616,   617,   618,   534,  2018,  1513,  1514,  2021,   609,
     610,   614,   615,   616,   617,   618,   611,   612,   613,   614,
     615,   616,   617,   618,   607,   619,   620,   621,   622,   607,
     607,  1268,  1130,   535,   607,   565,  1270,  1283,  1136,   536,
    1138,  1284,  1140,   537,  1142,   607,  1144,  1498,   607,   607,
    1500,   607,  1473,  1149,   820,  1626,  1591,   503,   607,  1288,
     607,  2053,   607,  1601,  2056,  1156,  1158,  1652,   566,  1658,
     609,   610,   538,   619,   620,   621,   622,   611,   612,   613,
     614,   615,   616,   617,   618,   600,   601,   602,   603,   604,
     605,   606,  1766,  1767,   609,   610,   539,   619,   620,   621,
     622,   611,   612,   613,   614,   615,   616,   617,   618,  1791,
    1792,   540,   619,   620,   621,   622,  1197,   619,   620,   621,
     622,  1200,   541,  1202,  1203,  1204,  1205,   600,   601,   602,
     603,   604,   605,   606,   619,   620,   621,   622,  2100,   542,
    2102,   600,   601,   602,   603,   604,   605,   606,   607,   607,
    2108,  2109,   607,   607,   506,  1665,  1668,   543,   607,  1669,
    1679,   703,   704,   609,   610,  1774,   707,  1889,  1890,   544,
     611,   612,   613,   614,   615,   616,   617,   618,   545,   546,
     607,   722,   723,   619,   620,   621,   622,  1775,   547,   730,
     509,   963,   548,   607,   735,   619,   620,   621,   622,   740,
    1799,   742,   625,   619,   620,   621,   622,   607,   549,  1212,
     626,  1213,   550,   754,  1866,   756,   607,   758,   607,   760,
     761,   762,   607,  1870,   607,  1871,   551,   768,   607,  1874,
     607,  1876,   773,  1290,  1292,  1877,   512,  1888,   607,   607,
     781,   114,   552,   115,   631,  2078,  2092,   789,   609,   610,
     553,   554,   646,   555,   556,   611,   612,   613,   614,   615,
     616,   617,   618,   557,   619,   620,   621,   622,  1313,   558,
    1215,  1314,  1216,   607,  1318,   607,   607,   607,  1841,   607,
     821,   878,  1051,   519,  1055,   607,   559,   607,   619,   620,
     621,   622,  1069,   673,  1237,   607,  1238,   560,  1340,   561,
    1077,   607,  1341,   562,  1294,  1295,  1079,  1297,  1298,  1347,
     563,   564,   607,  1351,   607,   607,  1354,  1081,   657,  1083,
    1851,   612,   613,   614,   615,   616,   617,   618,  1367,   607,
    1370,  1371,  1372,   607,  1997,  1375,  1376,  1377,  1084,  1380,
     607,   607,   567,  1384,   607,  1085,  1088,  1386,  1387,  1089,
    1389,   607,   678,  1392,   568,  1394,  1090,   619,   620,   621,
     622,  1400,  1402,   674,   681,  1406,   569,   570,   571,  1410,
    1411,  1413,  1414,  1516,  1008,  1417,  1009,   572,  1010,  1421,
     607,   573,  1424,   574,   607,  1092,  1428,   575,  1431,  1094,
    1433,   607,  1435,  1436,  1437,   607,  1096,   607,   607,   576,
    1100,  1011,  1101,  1102,  1012,   577,   578,   607,   607,  1013,
     609,   610,  1103,  1104,   114,   579,   115,   611,   612,   613,
     614,   615,   616,   617,   618,  1456,   607,  1458,   607,  1459,
     607,  1106,   607,  1108,   607,  1110,   607,  1114,  1466,  1115,
    1467,  1116,   619,   620,   621,   622,  1472,  2005,  1615,  2006,
    1616,  2007,   607,   609,   610,  1440,   580,  1118,   811,   581,
     611,   612,   613,   614,   615,   616,   617,   618,   582,   583,
     584,  2070,   585,  2071,  2008,  2072,   607,  2009,   607,   586,
     607,  1119,  2010,  1120,  1487,  1122,   607,   607,   607,   607,
     607,  1123,  1124,  1125,  1126,  1128,   618,   587,  2073,   588,
    1050,  2074,  1489,  1490,  1491,  1492,  2075,   619,   620,   621,
     622,  1493,   607,   607,  1058,   607,   589,  1129,  1131,   686,
    1132,  1063,   590,  1065,  1499,  1067,  1068,  1501,   591,  1502,
     607,  1072,  1073,   609,   610,  1133,   822,   592,   593,   594,
     611,   612,   613,   614,   615,   616,   617,   618,     1,     2,
       3,     4,     5,   609,   610,   114,  1519,   115,   595,  1521,
     611,   612,   613,   614,   615,   616,   617,   618,   609,   610,
     596,   656,   658,   671,   672,   611,   612,   613,   614,   615,
     616,   617,   618,   607,  1540,  1541,   607,   676,  1135,  1544,
     677,  1137,   612,  1547,   614,   615,   616,   617,   618,   687,
     699,   725,   727,   736,   619,   620,   621,   622,  1560,  1561,
    1645,  1562,  1646,  1563,   607,   744,  1564,  1538,  1539,  1139,
    1566,  1567,   607,   874,   607,   791,  1571,  1141,  1573,  1143,
    1574,   793,  1576,  1533,  1534,   819,  1164,  1165,  1579,   876,
    1581,   877,  1583,   879,  1584,  1585,  1586,   619,   620,   621,
     622,   953,  1588,   607,   607,  1154,  1589,   607,  1145,  1146,
    1189,   607,  1147,  1592,   607,   954,  1182,   986,   607,  1191,
    1597,   607,  1598,  1193,  1600,   607,  1194,  1603,   607,  1605,
    1195,  1607,   607,  1196,   988,  1610,  1611,  1198,   609,   610,
     987,  1617,  1618,   999,  1000,   611,   612,   613,   614,   615,
     616,   617,   618,  1001,   611,   612,   613,   614,   615,   616,
     617,   618,   355,   356,   357,   358,   359,  1006,  1002,  1003,
     607,  1636,  1637,  1638,  1639,  1199,   360,   619,   620,   621,
     622,   607,   361,   362,  1004,  1173,  1206,  1005,   363,   364,
     365,   366,   367,  1671,  1672,  1015,   607,   619,   620,   621,
     622,  1230,   607,   607,   607,  1207,   607,  1231,  1232,  1256,
     650,  1257,   619,   620,   621,   622,   607,  1018,   607,   607,
    1208,  1258,  1684,  1273,  1274,  1031,  1025,   607,   619,   620,
     621,   622,  1275,  1026,  1693,  1062,   607,   607,   368,  1694,
    1695,  1276,  1279,  1301,  1027,  1699,  1700,   607,  1702,  1703,
     607,  1064,  1282,   607,   607,  1337,  1710,   607,  1342,  1364,
    1066,   607,  1366,   607,  1070,  1718,  1374,   607,  1383,  1722,
    1071,   607,  1419,   607,   607,  1727,  1425,  1730,  1427,  1430,
    1335,  1150,   609,   610,  1737,  1688,  1689,  1740,  1742,   611,
     612,   613,   614,   615,   616,   617,   618,   607,  1750,  1751,
    1151,  1753,  1432,  1756,   607,  1758,  1759,  1880,  1881,  1434,
     607,   607,   607,   607,   607,  1439,  1474,  1475,  1476,  1477,
    1152,   607,   607,   607,   607,  1770,  1543,  1551,  1565,  1568,
    1153,  1772,   619,   620,   621,   622,  1163,  1336,   843,  1169,
    1209,   619,   620,   621,   622,  1170,  1778,   607,   607,   607,
    1779,   607,  1569,  1572,  1575,  1180,  1577,  1782,  1183,   607,
    1784,   609,   610,  1785,  1578,  1177,  1187,  1181,   611,   612,
     613,   614,   615,   616,   617,   618,   609,   610,  1796,  1184,
    1520,  1185,  1186,   611,   612,   613,   614,   615,   616,   617,
     618,   607,   607,  1807,  1808,  1809,  1580,  1582,  1188,   607,
     607,  1219,   607,  1953,  1590,  1593,   247,  1596,  1818,  1317,
     607,  1821,   607,  1263,  1824,  1604,  1266,  1606,  1826,   607,
    1828,   277,   607,  1267,  1608,   607,  1832,  1609,  1833,  1328,
    1634,  1326,  1837,  1838,   289,  1327,  1840,   297,   607,   607,
     301,   303,   305,  1653,  1696,  1847,   321,   321,   321,  1850,
    1329,   607,  1853,  1332,  1855,   345,  1698,  1857,  1858,   607,
    1860,   607,  1333,   607,  1711,  1346,  1712,  2001,  1713,   607,
    2003,  1361,  1362,  1868,  1714,   607,   619,   620,   621,   622,
    1716,   607,   607,   607,  1210,  1369,  1717,  1721,  1723,   114,
     114,   115,   115,   607,   607,   451,   607,   607,  1724,  1729,
    1373,  1731,  1733,  1897,   607,   321,   607,  1898,   607,  1734,
    1901,  1735,   607,  1736,  1905,   607,   607,  1738,   609,   610,
    1739,  1743,  1379,  1381,  2050,   611,   612,   613,   614,   615,
     616,   617,   618,   607,   607,  1391,   607,   607,  1747,  1748,
     479,  1752,  1755,  1393,  1395,   607,  1935,   607,  1936,  1937,
    1757,  1939,  1764,  1942,   607,   619,   620,   621,   622,  1776,
     607,   607,   607,  1211,   607,  1806,  1817,  1827,  1397,  1849,
     619,   620,   621,   622,   607,   607,   607,  1398,  1214,  1854,
    1856,  1906,  1955,   609,   610,   114,  1399,   115,  1405,  1409,
     611,   612,   613,   614,   615,   616,   617,   618,  1416,  1423,
    1507,  1508,   607,  1971,  1972,  1973,  1974,  1909,  1976,  1977,
    1460,   607,  1550,  1980,   607,  1553,  1912,  1983,  1530,  1914,
    1557,  1986,  1987,  1988,  1461,  1989,   607,   607,   607,  1993,
    1994,  1916,  1920,  1921,   607,  1996,   607,   607,  1999,  1926,
    2000,  1933,  1938,  1674,  1531,   607,  1509,   597,   599,   114,
    1941,   115,   114,   607,   115,   607,  2017,  1510,  1970,   607,
    1995,  1511,  2023,  2024,  2029,  2026,  2027,  2028,   627,   607,
     607,   609,   610,   632,  2033,  2041,  1532,  1542,   611,   612,
     613,   614,   615,   616,   617,   618,   647,  1512,  2039,  1548,
    1552,   651,  2042,  1558,  2043,  2044,   607,   607,   663,   607,
    1612,  2045,  2068,  1675,  2103,  1627,   114,  1620,   115,  2051,
    1619,  1632,   619,   620,   621,   622,    -9,  1680,  1685,  1691,
    1217,   682,  1692,   684,  1760,  1761,  2060,  1633,  1763,  1789,
    2062,  1800,  1794,  2064,  2065,  1803,  1804,  1810,  2067,  1862,
    1863,  1883,  2069,  1885,  1886,  1893,  1943,  1944,  1945,  -546,
    1959,  2080,  1962,  1965,  1968,  2089,  2084,   259,  1446,   346,
     347,   262,   846,  1043,  1296,  2088,  1300,  1946,  1299,  1673,
    2091,  1522,   721,  1041,     0,  1053,     0,   619,   620,   621,
     622,     0,  2096,  2097,     0,  1218,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2104,   609,   610,     0,     0,
    2107,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,   609,   610,     0,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,     0,     0,     0,     0,
       0,     0,     0,   609,   610,     0,     0,     0,     0,     0,
     611,   612,   613,   614,   615,   616,   617,   618,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   807,   808,   809,
     810,     0,     0,     0,   816,   619,   620,   621,   622,     0,
       0,     0,     0,  1220,     0,     0,   826,     0,     0,     0,
       0,   831,   832,     0,   833,   834,   835,   836,   321,   321,
     609,   610,     0,     0,     0,   849,     0,   611,   612,   613,
     614,   615,   616,   617,   618,     0,     0,   609,   610,     0,
       0,     0,     0,     0,   611,   612,   613,   614,   615,   616,
     617,   618,     0,     0,     0,     0,     0,     0,     0,   882,
     883,   884,   885,   886,   887,   888,   889,   890,   891,   321,
     893,   894,   895,   896,   897,   898,   899,   900,   902,     0,
       0,     0,     0,     0,   908,   909,   911,   913,   914,     0,
     916,     0,   918,     0,     0,     0,  1811,     0,     0,     0,
    1815,     0,     0,     0,   934,     0,     0,     0,     0,     0,
       0,   321,     0,     0,     0,     0,   947,     0,     0,     0,
     619,   620,   621,   622,     0,     0,     0,     0,  1221,     0,
       0,     0,     0,     0,     0,   619,   620,   621,   622,     0,
       0,     0,     0,  1222,     0,   974,   975,   976,   977,   978,
     979,   980,   981,   982,   983,   984,   985,   619,   620,   621,
     622,     0,     0,     0,     0,  1223,     0,     0,     0,     0,
     609,   610,     0,     0,     0,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,     0,     0,     0,     0,     0,
    1017,   609,   610,     0,     0,  1020,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,     0,     0,  1037,  1038,
       0,     0,     0,     0,   619,   620,   621,   622,     0,   127,
       0,  1049,  1224,     0,   131,     0,  1052,     0,     0,     0,
       0,   619,   620,   621,   622,     0,     0,  1059,  1060,  1225,
       0,     0,     0,     0,     0,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   336,   338,     0,     0,
    1097,     0,     0,     0,     0,     0,     0,   354,     0,   369,
     370,   372,   374,   377,   382,   383,   387,   389,   391,     0,
       0,     0,     0,   401,   403,   405,   407,   408,   409,   415,
     420,   428,   435,   437,   439,   609,   610,     0,     0,   146,
       0,   147,   611,   612,   613,   614,   615,   616,   617,   618,
       0,     0,     0,     0,     0,   609,   610,     0,     0,  1148,
     150,   151,   611,   612,   613,   614,   615,   616,   617,   618,
       0,     0,  1157,  1159,  1160,  1161,     0,     0,   252,   253,
       0,   254,   255,   159,   619,   620,   621,   622,     0,     0,
       0,   161,  1226,     0,   162,     0,     0,   163,   164,   256,
       0,     0,   166,   167,     0,   619,   620,   621,   622,     0,
       0,     0,     0,  1228,     0,     0,   521,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,   194,     0,     0,     0,   198,   199,   200,     0,
     202,     0,   204,   205,   206,     0,     0,     0,     0,   211,
     212,   213,   214,   215,   216,   217,     0,     0,   220,     0,
     222,     0,   224,     0,     0,   226,     0,   228,     0,     0,
     230,     0,     0,   232,   233,     0,   234,   235,     0,   237,
       0,   239,     0,     0,     0,     0,     0,     0,     0,   242,
       0,     0,     0,     0,     0,     0,     0,     0,   257,   921,
     609,   610,     0,     0,     0,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1285,  1286,     0,   619,
     620,   621,   622,     0,     0,     0,     0,  1239,     0,     0,
       0,     0,     0,     0,     0,     0,  1289,     0,     0,   619,
     620,   621,   622,     0,     0,     0,     0,  1240,     0,   647,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1308,     0,     0,     0,     0,   688,  1315,  1316,
       0,     0,     0,   693,  1321,     0,     0,     0,     0,     0,
     700,   702,     0,     0,     0,     0,     0,     0,  1334,     0,
       0,     0,     0,     0,   708,   709,   710,   711,   712,   713,
     714,     0,     0,   717,   718,   719,   720,     0,  1349,     0,
       0,     0,     0,  1355,  1356,  1357,     0,     0,  1360,     0,
       0,  1363,     0,  1365,     0,  1368,     0,     0,     0,     0,
       0,     0,     0,     0,  1378,     0,     0,     0,  1382,     0,
       0,     0,     0,     0,     0,     0,  1388,     0,  1390,     0,
       0,     0,     0,     0,  1396,     0,     0,     0,  1401,  1403,
    1404,     0,     0,  1407,  1408,     0,     0,  1412,     0,     0,
    1415,     0,     0,  1418,     0,  1420,     0,  1422,     0,     0,
       0,  1426,     0,  1429,   619,   620,   621,   622,     0,     0,
       0,     0,  1242,     0,     0,  1441,  1442,  1443,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1447,   823,   824,
     825,     0,     0,     0,     0,  1451,  1452,     0,  1453,  1454,
    1455,     0,     0,     0,     0,     0,     0,     0,     0,   848,
       0,  1462,  1463,     0,  1465,     0,     0,     0,  1468,  1469,
    1470,     0,  1471,     0,     0,     0,     0,     0,     0,     0,
    1478,     0,     0,   609,   610,     0,  1479,     0,     0,  1480,
     611,   612,   613,   614,   615,   616,   617,   618,     0,     0,
       0,  1481,     0,     0,  1482,  1483,  1484,     0,  1485,  1486,
       0,   609,   610,     0,     0,     0,     0,  1488,   611,   612,
     613,   614,   615,   616,   617,   618,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1494,     0,  1495,  1496,  1497,
       0,     0,     0,     0,     0,     0,     0,   609,   610,     0,
       0,  1503,     0,     0,   611,   612,   613,   614,   615,   616,
     617,   618,     0,     0,     0,   609,   610,     0,     0,     0,
       0,  1517,   611,   612,   613,   614,   615,   616,   617,   618,
       0,  1524,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1535,  1536,     0,     0,     0,   321,
     321,     0,     0,   609,   610,     0,     0,     0,  1545,  1546,
     611,   612,   613,   614,   615,   616,   617,   618,     0,   609,
     610,     0,     0,     0,     0,     0,   611,   612,   613,   614,
     615,   616,   617,   618,     0,     0,     0,     0,     0,     0,
       0,   609,   610,     0,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,  1054,     0,     0,     0,
    1057,     0,     0,     0,     0,     0,  1061,   619,   620,   621,
     622,     0,     0,     0,     0,  1245,     0,     0,     0,     0,
       0,  1075,  1076,  1595,     0,     0,     0,     0,     0,  1082,
       0,     0,     0,     0,  1086,   619,   620,   621,   622,  1091,
       0,  1093,     0,  1269,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1105,     0,  1107,     0,  1109,     0,  1111,
    1112,  1113,     0,     0,     0,     0,     0,  1117,     0,     0,
       0,     0,  1121,     0,     0,     0,     0,     0,     0,     0,
    1127,   619,   620,   621,   622,     0,     0,     0,  1134,  1311,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   619,
     620,   621,   622,     0,     0,     0,     0,  1529,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   651,     0,     0,
       0,     0,  1678,     0,     0,     0,     0,  1682,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   619,   620,   621,
     622,     0,     0,     0,     0,  1613,     0,     0,     0,     0,
       0,     0,     0,   619,   620,   621,   622,     0,  1705,  1706,
    1707,  1614,  1709,     0,     0,     0,     0,     0,     0,  1715,
       0,     0,     0,  1719,  1720,   619,   620,   621,   622,  1725,
       0,  1726,  1728,  1621,     0,     0,  1732,     0,     0,     0,
       0,     0,     0,     0,  1741,     0,     0,  1744,  1745,     0,
    1746,     0,     0,  1749,   609,   610,     0,     0,  1754,     0,
       0,   611,   612,   613,   614,   615,   616,   617,   618,  1762,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1771,     0,  1773,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1777,
       0,     0,     0,     0,     0,     0,     0,     0,  1780,     0,
    1781,     0,     0,     0,     0,  1783,     0,     0,     0,     0,
       0,     0,     0,     0,  1786,     0,     0,     0,     0,     0,
       0,   609,   610,     0,  1795,     0,     0,  1798,   611,   612,
     613,   614,   615,   616,   617,   618,     0,     0,   609,   610,
       0,     0,     0,     0,     0,   611,   612,   613,   614,   615,
     616,   617,   618,     0,     0,     0,  1819,  1820,     0,     0,
    1823,     0,     0,     0,     0,     0,     0,     0,  1829,     0,
       0,     0,     0,     0,     0,     0,     0,  1835,  1836,     0,
       0,     0,  1839,     0,     0,     0,     0,  1842,     0,  1339,
       0,  1846,     0,     0,     0,     0,     0,  1343,     0,     0,
       0,     0,  1348,     0,  1350,     0,  1352,  1353,  1861,     0,
       0,  1358,  1359,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1882,     0,     0,     0,     0,   619,   620,
     621,   622,     0,     0,  1895,     0,  1622,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1900,     0,  1902,     0,
    1904,     0,     0,     0,     0,     0,  1910,     0,     0,  1913,
       0,  1915,     0,     0,  1918,  1919,     0,     0,  1922,     0,
       0,     0,     0,     0,     0,  1927,     0,  1929,  1930,  1931,
       0,     0,  1934,     0,     0,     0,     0,     0,  1940,     0,
       0,     0,     0,  1448,  1449,     0,     0,     0,     0,     0,
       0,  1948,     0,     0,     0,   619,   620,   621,   622,     0,
       0,     0,  1949,  1623,     0,     0,     0,     0,  1464,     0,
    1956,  1957,   619,   620,   621,   622,     0,     0,     0,     0,
    1624,   609,   610,     0,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,     0,     0,  1979,     0,
       0,  1981,     0,     0,     0,  1984,     0,  1985,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,   126,   127,     0,   128,
     129,   130,   131,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2020,     0,  2022,     0,
       0,  2025,   132,   133,     0,     0,     0,     0,     0,  2030,
       0,     0,  2031,     0,     0,     0,  2035,     0,     0,     0,
       0,     0,     0,     0,  2038,     0,  2040,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   135,   136,   137,   138,
     139,   140,     0,     0,     0,     0,     0,     0,  2052,     0,
       0,     0,     0,   141,     0,     0,   142,     0,     0,     0,
       0,   323,     0,     0,     0,     0,  2061,     0,  2063,   324,
       0,     0,     0,   144,   145,     0,     0,   146,     0,   147,
       0,     0,   325,     0,     0,     0,     0,   148,     0,     0,
       0,  2082,     0,     0,   149,     0,     0,     0,   150,   151,
    2087,     0,     0,     0,     0,     0,     0,     0,   152,     0,
     153,   154,     0,     0,     0,     0,   155,   156,     0,   157,
     158,   159,   160,     0,     0,   619,   620,   621,   622,   161,
       0,     0,   162,  1625,     0,   163,   164,   165,     0,     0,
     166,   167,   168,   169,   170,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,   226,   227,   228,     0,   229,   230,     0,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,     0,     0,     0,     0,     0,   241,   242,     0,   243,
       0,     0,     0,     0,     0,     0,   244,     0,   319,   125,
     126,   127,     0,   128,   129,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   132,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1701,
       0,     0,  1704,     0,     0,     0,  1708,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   134,
     135,   136,   137,   138,   139,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,     0,     0,
     142,     0,     0,     0,     0,   317,     0,     0,     0,     0,
       0,     0,     0,   318,     0,     0,     0,   144,   145,     0,
       0,   146,     0,   147,     0,     0,     0,     0,  1765,     0,
       0,   148,     0,     0,     0,     0,     0,     0,   149,     0,
       0,     0,   150,   151,     0,     0,     0,     0,     0,     0,
       0,     0,   152,     0,   153,   154,     0,     0,     0,     0,
     155,   156,     0,   157,   158,   159,   160,     0,     0,     0,
       0,     0,     0,   161,     0,     0,   162,     0,     0,   163,
     164,   165,     0,     0,   166,   167,   168,   169,   170,     0,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,     0,   225,   226,   227,   228,
       0,   229,   230,     0,   231,   232,   233,     0,   234,   235,
     236,   237,   238,   239,   240,     0,     0,     0,     0,     0,
     241,   242,     0,   243,     0,     0,     0,     0,     0,     0,
     244,     0,   319,   125,   126,   127,     0,   128,   129,   130,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     132,   133,     0,     0,     0,     0,     0,     0,     0,     0,
    1899,     0,     0,     0,  1903,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,   142,     0,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,   837,     0,     0,
       0,   144,   145,     0,     0,   146,     0,   147,     0,     0,
       0,     0,     0,     0,     0,   148,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,   150,   151,     0,     0,
       0,     0,     0,     0,     0,     0,   152,     0,   153,   154,
       0,     0,     0,     0,   155,   156,     0,   157,   158,   159,
     160,     0,     0,     0,     0,     0,     0,   161,     0,     0,
     162,     0,     0,   163,   164,   165,     0,     0,   166,   167,
     168,   169,   170,     0,     0,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,     0,
     225,   226,   227,   228,     0,   229,   230,     0,   231,   232,
     233,     0,   234,   235,   236,   237,   238,   239,   240,     0,
       0,     0,     0,     0,   241,   242,     0,   243,     0,     0,
       0,     0,     0,     0,   244,     0,   319,   125,   126,   127,
       0,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   609,
     610,     0,     0,   143,     0,     0,   611,   612,   613,   614,
     615,   616,   617,   618,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
     150,   151,     0,     0,     0,     0,     0,     0,     0,     0,
     152,     0,   153,   154,     0,     0,     0,     0,   155,   156,
       0,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,   161,     0,     0,   162,     0,     0,   163,   164,   165,
       0,     0,   166,   167,   168,   169,   170,     0,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,     0,   225,   226,   227,   228,     0,   229,
     230,     0,   231,   232,   233,     0,   234,   235,   236,   237,
     238,   239,   240,     0,     0,     0,     0,     0,   241,   242,
       0,   243,     0,     0,     0,     0,     0,     0,   244,     0,
     319,   125,   126,   127,     0,   128,   129,   130,   131,     0,
       0,     0,     0,   619,   620,   621,   622,     0,     0,     0,
       0,  1630,     0,     0,     0,     0,     0,     0,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,   609,   610,     0,     0,   143,     0,     0,
     611,   612,   613,   614,   615,   616,   617,   618,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,     0,
       0,     0,     0,   148,     0,     0,     0,     0,     0,     0,
     149,     0,     0,     0,   150,   151,     0,     0,     0,     0,
       0,     0,     0,     0,   152,     0,   153,   154,     0,     0,
       0,     0,   155,   156,     0,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,   161,     0,     0,   162,     0,
       0,   163,   164,   165,     0,     0,   166,   167,   168,   169,
     170,     0,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,     0,   225,   226,
     227,   228,     0,   229,   230,     0,   231,   232,   233,     0,
     234,   235,   236,   237,   238,   239,   240,     0,     0,     0,
       0,     0,   241,   242,     0,   243,     0,     0,     0,     0,
       0,     0,   244,   815,   125,   126,   127,     0,   128,   129,
     130,   131,     0,     0,     0,     0,     0,   619,   620,   621,
     622,     0,     0,     0,     0,  1631,     0,     0,     0,     0,
       0,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,     0,     0,   142,   609,   610,     0,     0,
     143,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,     0,   144,   145,     0,     0,   146,     0,   147,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     0,     0,
       0,     0,     0,   149,     0,     0,     0,   150,   151,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,   153,
     154,     0,     0,     0,     0,   155,   156,     0,   157,   158,
     159,   160,     0,     0,     0,     0,     0,     0,   161,     0,
       0,   162,     0,     0,   163,   164,   165,     0,     0,   166,
     167,   168,   169,   170,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
       0,   225,   226,   227,   228,     0,   229,   230,     0,   231,
     232,   233,     0,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     0,     0,     0,   241,   242,     0,   243,     0,
       0,     0,     0,     0,     0,   244,   901,   125,   126,   127,
       0,   128,   129,   130,   131,     0,     0,     0,     0,     0,
     619,   620,   621,   622,     0,     0,     0,     0,  1640,     0,
       0,     0,     0,     0,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   609,
     610,     0,     0,   143,     0,     0,   611,   612,   613,   614,
     615,   616,   617,   618,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
     150,   151,     0,     0,     0,     0,     0,     0,     0,     0,
     152,     0,   153,   154,     0,     0,     0,     0,   155,   156,
       0,   157,   158,   159,   160,     0,     0,     0,     0,     0,
       0,   161,     0,     0,   162,     0,     0,   163,   164,   165,
       0,     0,   166,   167,   168,   169,   170,     0,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,     0,   225,   226,   227,   228,     0,   229,
     230,     0,   231,   232,   233,     0,   234,   235,   236,   237,
     238,   239,   240,     0,     0,     0,     0,     0,   241,   242,
       0,   243,     0,     0,     0,     0,     0,     0,   244,   912,
     125,   126,   127,     0,   128,   129,   130,   131,     0,     0,
       0,     0,     0,   619,   620,   621,   622,     0,     0,     0,
       0,  1641,     0,     0,     0,     0,     0,   132,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,     0,
       0,   142,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,   421,     0,     0,     0,     0,     0,   144,   145,
       0,     0,   146,     0,   147,     0,     0,     0,     0,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,   149,
       0,     0,     0,   150,   151,     0,     0,     0,     0,     0,
       0,     0,     0,   152,     0,   153,   154,     0,     0,   422,
     423,   155,   156,     0,   157,   158,   159,   160,     0,   424,
     425,   426,   427,     0,   161,     0,     0,   162,     0,     0,
     163,   164,   165,     0,     0,   166,   167,   168,   169,   170,
       0,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,     0,   225,   226,   227,
     228,     0,   229,   230,     0,   231,   232,   233,     0,   234,
     235,   236,   237,   238,   239,   240,     0,     0,     0,     0,
       0,   241,   242,     0,   243,     0,     0,     0,   125,   126,
     127,   244,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   429,     0,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,     0,   142,
       0,     0,     0,     0,   143,     0,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,   144,   145,     0,     0,
     146,     0,   147,     0,     0,     0,     0,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,   150,   151,     0,     0,     0,     0,     0,     0,     0,
       0,   152,     0,   153,   154,     0,     0,   431,   432,   155,
     156,     0,   157,   158,   159,   160,   433,     0,     0,     0,
     434,     0,   161,     0,     0,   162,     0,     0,   163,   164,
     165,     0,     0,   166,   167,   168,   169,   170,     0,     0,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,     0,   225,   226,   227,   228,     0,
     229,   230,     0,   231,   232,   233,     0,   234,   235,   236,
     237,   238,   239,   240,     0,     0,     0,     0,     0,   241,
     242,     0,   243,     0,     0,     0,   125,   126,   127,   244,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,     0,     0,
       0,     0,   143,     0,     0,     0,     0,     0,   410,     0,
       0,     0,     0,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,   153,   154,     0,     0,   411,   412,   155,   156,     0,
     157,   158,   159,   160,     0,   413,     0,     0,   414,     0,
     161,     0,     0,   162,     0,     0,   163,   164,   165,     0,
       0,   166,   167,   168,   169,   170,     0,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,     0,   225,   226,   227,   228,     0,   229,   230,
       0,   231,   232,   233,     0,   234,   235,   236,   237,   238,
     239,   240,     0,     0,     0,     0,     0,   241,   242,     0,
     243,     0,     0,     0,   125,   126,   127,   244,   128,   129,
     130,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   378,     0,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,     0,     0,   142,     0,     0,     0,     0,
     143,     0,     0,     0,     0,     0,   379,     0,     0,     0,
       0,     0,   144,   145,     0,     0,   146,     0,   147,     0,
       0,     0,   380,     0,     0,     0,   148,     0,     0,     0,
       0,     0,     0,   149,     0,     0,     0,   150,   151,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,   153,
     154,     0,     0,   381,     0,   155,   156,     0,   157,   158,
     159,   160,     0,     0,     0,     0,     0,     0,   161,     0,
       0,   162,     0,     0,   163,   164,   165,     0,     0,   166,
     167,   168,   169,   170,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
       0,   225,   226,   227,   228,     0,   229,   230,     0,   231,
     232,   233,     0,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     0,     0,     0,   241,   242,     0,   243,     0,
       0,     0,   125,   126,   127,   244,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,     0,     0,     0,     0,   143,     0,
       0,     0,     0,     0,   416,     0,     0,     0,     0,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
       0,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,   149,     0,     0,     0,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,   153,   154,     0,
       0,   417,   418,   155,   156,     0,   157,   158,   159,   160,
       0,     0,     0,     0,   419,     0,   161,     0,     0,   162,
       0,     0,   163,   164,   165,     0,     0,   166,   167,   168,
     169,   170,     0,     0,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,     0,   225,
     226,   227,   228,     0,   229,   230,     0,   231,   232,   233,
       0,   234,   235,   236,   237,   238,   239,   240,     0,     0,
       0,     0,     0,   241,   242,     0,   243,     0,     0,     0,
     125,   126,   127,   244,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   384,
       0,     0,     0,     0,     0,     0,     0,   132,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   385,     0,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,     0,
       0,   142,   609,   610,     0,     0,   143,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,     0,   144,   145,
       0,     0,   146,     0,   147,     0,     0,     0,   386,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,   149,
       0,     0,     0,   150,   151,     0,     0,     0,     0,     0,
       0,     0,     0,   152,     0,   153,   154,     0,     0,     0,
       0,   155,   156,     0,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,   161,     0,     0,   162,     0,     0,
     163,   164,   165,     0,     0,   166,   167,   168,   169,   170,
       0,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,     0,   225,   226,   227,
     228,     0,   229,   230,     0,   231,   232,   233,     0,   234,
     235,   236,   237,   238,   239,   240,     0,     0,     0,     0,
       0,   241,   242,     0,   243,     0,     0,     0,   125,   126,
     127,   244,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
       0,     0,     0,     0,  1642,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,     0,   142,
     609,   610,     0,     0,   143,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,     0,   144,   145,     0,     0,
     146,     0,   147,     0,     0,     0,   398,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,   150,   151,     0,     0,     0,     0,     0,     0,     0,
       0,   152,     0,   153,   154,     0,     0,   399,   400,   155,
     156,     0,   157,   158,   159,   160,     0,     0,     0,     0,
       0,     0,   161,     0,     0,   162,     0,     0,   163,   164,
     165,     0,     0,   166,   167,   168,   169,   170,     0,     0,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,     0,   225,   226,   227,   228,     0,
     229,   230,     0,   231,   232,   233,     0,   234,   235,   236,
     237,   238,   239,   240,     0,     0,     0,     0,     0,   241,
     242,     0,   243,     0,     0,     0,   125,   126,   127,   244,
     128,   129,   130,   131,     0,   334,     0,     0,     0,     0,
       0,     0,     0,     0,   619,   620,   621,   622,     0,     0,
       0,     0,  1643,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   335,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   609,   610,
       0,     0,   143,     0,     0,   611,   612,   613,   614,   615,
     616,   617,   618,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,   153,   154,     0,     0,     0,     0,   155,   156,     0,
     157,   158,   159,   160,     0,     0,     0,     0,     0,     0,
     161,     0,     0,   162,     0,     0,   163,   164,   165,     0,
       0,   166,   167,   168,   169,   170,     0,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,     0,   225,   226,   227,   228,     0,   229,   230,
       0,   231,   232,   233,     0,   234,   235,   236,   237,   238,
     239,   240,     0,     0,     0,     0,     0,   241,   242,     0,
     243,     0,     0,     0,   125,   126,   127,   244,   128,   129,
     130,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   619,   620,   621,   622,     0,     0,     0,     0,
    1644,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,     0,     0,   142,   609,   610,     0,     0,
     143,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,     0,   144,   145,     0,     0,   146,     0,   147,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     0,     0,
       0,     0,     0,   149,     0,     0,     0,   150,   151,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,   153,
     154,     0,     0,     0,   352,   155,   156,   353,   157,   158,
     159,   160,     0,     0,     0,     0,     0,     0,   161,     0,
       0,   162,     0,     0,   163,   164,   165,     0,     0,   166,
     167,   168,   169,   170,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
       0,   225,   226,   227,   228,     0,   229,   230,     0,   231,
     232,   233,     0,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     0,     0,     0,   241,   242,     0,   243,     0,
       0,     0,   125,   126,   127,   244,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,     0,     0,     0,     0,  1647,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,     0,     0,     0,     0,   143,     0,
       0,     0,     0,     0,   375,     0,     0,     0,     0,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
     376,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,   149,     0,     0,     0,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,   153,   154,     0,
       0,     0,     0,   155,   156,     0,   157,   158,   159,   160,
       0,     0,     0,     0,     0,     0,   161,     0,     0,   162,
       0,     0,   163,   164,   165,     0,     0,   166,   167,   168,
     169,   170,     0,     0,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,     0,   225,
     226,   227,   228,     0,   229,   230,     0,   231,   232,   233,
       0,   234,   235,   236,   237,   238,   239,   240,     0,     0,
       0,     0,     0,   241,   242,     0,   243,     0,     0,     0,
     125,   126,   127,   244,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   132,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,     0,
       0,   142,   609,   610,     0,     0,   143,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,     0,   144,   145,
       0,     0,   146,     0,   147,     0,     0,     0,     0,   449,
       0,     0,   148,     0,     0,     0,     0,     0,     0,   149,
       0,     0,     0,   150,   151,     0,     0,     0,     0,     0,
       0,     0,     0,   152,     0,   153,   154,     0,     0,     0,
     450,   155,   156,     0,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,   161,     0,     0,   162,     0,     0,
     163,   164,   165,     0,     0,   166,   167,   168,   169,   170,
       0,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,     0,   225,   226,   227,
     228,     0,   229,   230,     0,   231,   232,   233,     0,   234,
     235,   236,   237,   238,   239,   240,     0,     0,     0,     0,
       0,   241,   242,     0,   243,     0,     0,     0,   125,   126,
     127,   244,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
       0,     0,     0,     0,  1648,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,     0,   142,
     609,   610,     0,     0,   143,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,     0,   144,   145,     0,     0,
     146,     0,   147,     0,     0,     0,     0,   486,   487,     0,
     148,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,   150,   151,     0,     0,     0,     0,     0,     0,     0,
       0,   152,     0,   153,   154,     0,     0,     0,     0,   155,
     156,     0,   157,   158,   159,   160,     0,     0,     0,     0,
       0,     0,   161,     0,     0,   162,     0,     0,   163,   164,
     165,     0,     0,   166,   167,   168,   169,   170,     0,     0,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,     0,   225,   226,   227,   228,     0,
     229,   230,     0,   231,   232,   233,     0,   234,   235,   236,
     237,   238,   239,   240,     0,     0,     0,     0,     0,   241,
     242,     0,   243,     0,     0,     0,   125,   126,   127,   244,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   619,   620,   621,   622,     0,     0,
       0,     0,  1651,   132,   133,     0,     0,   276,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   609,   610,
       0,     0,   143,     0,     0,   611,   612,   613,   614,   615,
     616,   617,   618,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,   153,   154,     0,     0,     0,     0,   155,   156,     0,
     157,   158,   159,   160,     0,     0,     0,     0,     0,     0,
     161,     0,     0,   162,     0,     0,   163,   164,   165,     0,
       0,   166,   167,   168,   169,   170,     0,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,     0,   225,   226,   227,   228,     0,   229,   230,
       0,   231,   232,   233,     0,   234,   235,   236,   237,   238,
     239,   240,     0,     0,     0,     0,     0,   241,   242,     0,
     243,     0,     0,     0,   125,   126,   127,   244,   128,   129,
     130,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   619,   620,   621,   622,     0,     0,     0,     0,
    1659,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,     0,     0,   142,   609,   610,     0,     0,
     143,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,     0,   144,   145,     0,     0,   146,     0,   147,     0,
       0,     0,   337,     0,     0,     0,   148,     0,     0,     0,
       0,     0,     0,   149,     0,     0,     0,   150,   151,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,   153,
     154,     0,     0,     0,     0,   155,   156,     0,   157,   158,
     159,   160,     0,     0,     0,     0,     0,     0,   161,     0,
       0,   162,     0,     0,   163,   164,   165,     0,     0,   166,
     167,   168,   169,   170,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
       0,   225,   226,   227,   228,     0,   229,   230,     0,   231,
     232,   233,     0,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     0,     0,     0,   241,   242,     0,   243,     0,
       0,     0,   125,   126,   127,   244,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,     0,     0,     0,     0,  1662,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   609,   610,     0,     0,   143,     0,
       0,   611,   612,   613,   614,   615,   616,   617,   618,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
     371,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,   149,     0,     0,     0,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,   153,   154,     0,
       0,     0,     0,   155,   156,     0,   157,   158,   159,   160,
       0,     0,     0,     0,     0,     0,   161,     0,     0,   162,
       0,     0,   163,   164,   165,     0,     0,   166,   167,   168,
     169,   170,     0,     0,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,     0,   225,
     226,   227,   228,     0,   229,   230,     0,   231,   232,   233,
       0,   234,   235,   236,   237,   238,   239,   240,     0,     0,
       0,     0,     0,   241,   242,     0,   243,     0,     0,     0,
     125,   126,   127,   244,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   619,   620,
     621,   622,     0,     0,     0,     0,  1677,   132,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,     0,
       0,   142,   609,   610,     0,     0,   143,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,     0,   144,   145,
       0,     0,   146,     0,   147,     0,     0,     0,   373,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,   149,
       0,     0,     0,   150,   151,     0,     0,     0,     0,     0,
       0,     0,     0,   152,     0,   153,   154,     0,     0,     0,
       0,   155,   156,     0,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,   161,     0,     0,   162,     0,     0,
     163,   164,   165,     0,     0,   166,   167,   168,   169,   170,
       0,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,     0,   225,   226,   227,
     228,     0,   229,   230,     0,   231,   232,   233,     0,   234,
     235,   236,   237,   238,   239,   240,     0,     0,     0,     0,
       0,   241,   242,     0,   243,     0,     0,     0,   125,   126,
     127,   244,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
       0,     0,     0,     0,  1793,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,     0,   142,
     609,   610,     0,     0,   143,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,     0,   144,   145,     0,     0,
     146,     0,   147,     0,     0,     0,   388,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,   150,   151,     0,     0,     0,     0,     0,     0,     0,
       0,   152,     0,   153,   154,     0,     0,     0,     0,   155,
     156,     0,   157,   158,   159,   160,     0,     0,     0,     0,
       0,     0,   161,     0,     0,   162,     0,     0,   163,   164,
     165,     0,     0,   166,   167,   168,   169,   170,     0,     0,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,     0,   225,   226,   227,   228,     0,
     229,   230,     0,   231,   232,   233,     0,   234,   235,   236,
     237,   238,   239,   240,     0,     0,     0,     0,     0,   241,
     242,     0,   243,     0,     0,     0,   125,   126,   127,   244,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   619,   620,   621,   622,     0,     0,
       0,     0,  1797,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   609,   610,
       0,     0,   143,     0,     0,   611,   612,   613,   614,   615,
     616,   617,   618,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,   390,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,   153,   154,     0,     0,     0,     0,   155,   156,     0,
     157,   158,   159,   160,     0,     0,     0,     0,     0,     0,
     161,     0,     0,   162,     0,     0,   163,   164,   165,     0,
       0,   166,   167,   168,   169,   170,     0,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,     0,   225,   226,   227,   228,     0,   229,   230,
       0,   231,   232,   233,     0,   234,   235,   236,   237,   238,
     239,   240,     0,     0,     0,     0,     0,   241,   242,     0,
     243,     0,     0,     0,   125,   126,   127,   244,   128,   129,
     130,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   619,   620,   621,   622,     0,     0,     0,     0,
    1859,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,     0,     0,   142,   609,   610,     0,     0,
     143,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,     0,   144,   145,     0,     0,   146,     0,   147,     0,
       0,     0,   402,     0,     0,     0,   148,     0,     0,     0,
       0,     0,     0,   149,     0,     0,     0,   150,   151,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,   153,
     154,     0,     0,     0,     0,   155,   156,     0,   157,   158,
     159,   160,     0,     0,     0,     0,     0,     0,   161,     0,
       0,   162,     0,     0,   163,   164,   165,     0,     0,   166,
     167,   168,   169,   170,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
       0,   225,   226,   227,   228,     0,   229,   230,     0,   231,
     232,   233,     0,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     0,     0,     0,   241,   242,     0,   243,     0,
       0,     0,   125,   126,   127,   244,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,     0,     0,     0,     0,  1869,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   609,   610,     0,     0,   143,     0,
       0,   611,   612,   613,   614,   615,   616,   617,   618,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
     404,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,   149,     0,     0,     0,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,   153,   154,     0,
       0,     0,     0,   155,   156,     0,   157,   158,   159,   160,
       0,     0,     0,     0,     0,     0,   161,     0,     0,   162,
       0,     0,   163,   164,   165,     0,     0,   166,   167,   168,
     169,   170,     0,     0,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,     0,   225,
     226,   227,   228,     0,   229,   230,     0,   231,   232,   233,
       0,   234,   235,   236,   237,   238,   239,   240,     0,     0,
       0,     0,     0,   241,   242,     0,   243,     0,     0,     0,
     125,   126,   127,   244,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   619,   620,
     621,   622,     0,     0,     0,     0,  1872,   132,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,     0,
       0,   142,   609,   610,     0,     0,   143,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,     0,   144,   145,
       0,     0,   146,     0,   147,     0,     0,     0,   406,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,   149,
       0,     0,     0,   150,   151,     0,     0,     0,     0,     0,
       0,     0,     0,   152,     0,   153,   154,     0,     0,     0,
       0,   155,   156,     0,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,   161,     0,     0,   162,     0,     0,
     163,   164,   165,     0,     0,   166,   167,   168,   169,   170,
       0,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,     0,   225,   226,   227,
     228,     0,   229,   230,     0,   231,   232,   233,     0,   234,
     235,   236,   237,   238,   239,   240,     0,     0,     0,     0,
       0,   241,   242,     0,   243,     0,     0,     0,   125,   126,
     127,   244,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
       0,     0,     0,     0,  1873,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,     0,   142,
     609,   610,     0,     0,   143,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,     0,   144,   145,     0,     0,
     146,     0,   147,     0,     0,     0,   436,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,   150,   151,     0,     0,     0,     0,     0,     0,     0,
       0,   152,     0,   153,   154,     0,     0,     0,     0,   155,
     156,     0,   157,   158,   159,   160,     0,     0,     0,     0,
       0,     0,   161,     0,     0,   162,     0,     0,   163,   164,
     165,     0,     0,   166,   167,   168,   169,   170,     0,     0,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,     0,   225,   226,   227,   228,     0,
     229,   230,     0,   231,   232,   233,     0,   234,   235,   236,
     237,   238,   239,   240,     0,     0,     0,     0,     0,   241,
     242,     0,   243,     0,     0,     0,   125,   126,   127,   244,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   619,   620,   621,   622,     0,     0,
       0,     0,  1875,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   609,   610,
       0,     0,   143,     0,     0,   611,   612,   613,   614,   615,
     616,   617,   618,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,   438,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,   153,   154,     0,     0,     0,     0,   155,   156,     0,
     157,   158,   159,   160,     0,     0,     0,     0,     0,     0,
     161,     0,     0,   162,     0,     0,   163,   164,   165,     0,
       0,   166,   167,   168,   169,   170,     0,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,     0,   225,   226,   227,   228,     0,   229,   230,
       0,   231,   232,   233,     0,   234,   235,   236,   237,   238,
     239,   240,     0,     0,     0,     0,     0,   241,   242,     0,
     243,     0,     0,     0,   125,   126,   127,   244,   128,   129,
     130,   131,     0,   701,     0,     0,     0,     0,     0,     0,
       0,     0,   619,   620,   621,   622,     0,     0,     0,     0,
    1892,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,     0,     0,   142,   609,   610,     0,     0,
     143,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,     0,   144,   145,     0,     0,   146,     0,   147,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     0,     0,
       0,     0,     0,   149,     0,     0,     0,   150,   151,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,   153,
     154,     0,     0,     0,     0,   155,   156,     0,   157,   158,
     159,   160,     0,     0,     0,     0,     0,     0,   161,     0,
       0,   162,     0,     0,   163,   164,   165,     0,     0,   166,
     167,   168,   169,   170,     0,     0,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
       0,   225,   226,   227,   228,     0,   229,   230,     0,   231,
     232,   233,     0,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     0,     0,     0,   241,   242,     0,   243,     0,
       0,     0,   125,   126,   127,   244,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,     0,     0,     0,     0,  2002,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   609,   610,     0,     0,   143,     0,
       0,   611,   612,   613,   614,   615,   616,   617,   618,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
       0,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,   149,     0,     0,     0,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,   153,   154,     0,
       0,     0,     0,   155,   156,     0,   157,   158,   159,   160,
       0,     0,     0,     0,     0,     0,   161,     0,     0,   162,
       0,     0,   163,   164,   165,     0,     0,   166,   167,   168,
     169,   170,     0,     0,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,     0,   225,
     226,   227,   228,     0,   229,   230,     0,   231,   232,   233,
       0,   234,   235,   236,   237,   238,   239,   240,     0,     0,
     127,     0,     0,   241,   242,   131,   243,     0,     0,     0,
       0,     0,     0,   244,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   133,     0,   619,   620,
     621,   622,     0,     0,     0,     0,  2015,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   609,
     610,     0,     0,     0,     0,     0,   611,   612,   613,   614,
     615,   616,   617,   618,     0,     0,     0,   609,   610,     0,
       0,     0,     0,     0,   611,   612,   613,   614,   615,   616,
     617,   618,     0,     0,     0,     0,   609,   610,     0,     0,
     146,     0,   147,   611,   612,   613,   614,   615,   616,   617,
     618,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,   151,     0,     0,   127,     0,     0,     0,     0,
     131,     0,     0,     0,     0,     0,     0,     0,     0,   252,
     253,     0,   254,   255,   159,     0,     0,     0,     0,     0,
       0,   133,   161,     0,     0,   162,     0,     0,   163,   164,
     256,     0,     0,   166,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   609,   610,     0,     0,     0,     0,
       0,   611,   612,   613,   614,   615,   616,   617,   618,     0,
       0,   192,   193,   194,     0,     0,     0,   198,   199,   200,
       0,   202,     0,   204,   205,   206,     0,     0,     0,     0,
     211,   212,   213,   214,   215,   216,   217,     0,     0,   220,
       0,   222,     0,   224,     0,   146,   226,   147,   228,     0,
       0,   230,     0,     0,   232,   233,     0,   234,   235,     0,
     237,     0,   239,     0,     0,     0,   150,   151,     0,     0,
     242,     0,   127,   619,   620,   621,   622,   131,     0,   257,
     923,  2058,     0,     0,   252,   253,     0,   254,   255,   159,
       0,   619,   620,   621,   622,     0,     0,   161,   133,  2079,
     162,     0,     0,   163,   164,   256,     0,     0,   166,   167,
     619,   620,   621,   622,     0,     0,     0,     0,  2094,     0,
       0,   609,   610,     0,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,   192,   193,   194,     0,
       0,     0,   198,   199,   200,     0,   202,     0,   204,   205,
     206,     0,     0,     0,     0,   211,   212,   213,   214,   215,
     216,   217,     0,     0,   220,     0,   222,     0,   224,     0,
       0,   226,   146,   228,   147,     0,   230,     0,     0,   232,
     233,     0,   234,   235,     0,   237,     0,   239,   619,   620,
     621,   622,     0,   150,   151,   242,     0,     0,     0,     0,
       0,     0,   127,     0,   257,   925,     0,   131,     0,     0,
       0,   252,   253,     0,   254,   255,   159,     0,     0,     0,
       0,     0,     0,     0,   161,     0,     0,   162,   133,     0,
     163,   164,   256,     0,     0,   166,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   192,   193,   194,     0,     0,     0,   198,
     199,   200,     0,   202,     0,   204,   205,   206,     0,     0,
       0,     0,   211,   212,   213,   214,   215,   216,   217,     0,
       0,   220,     0,   222,     0,   224,     0,     0,   226,     0,
     228,     0,   146,   230,   147,     0,   232,   233,   392,   234,
     235,     0,   237,     0,   239,   619,   620,   621,   622,     0,
       0,   675,   242,   150,   151,     0,     0,     0,     0,   127,
       0,   257,   927,     0,   131,     0,     0,     0,     0,     0,
       0,   252,   253,     0,   254,   255,   159,     0,     0,     0,
       0,     0,     0,     0,   161,   133,     0,   162,     0,     0,
     163,   164,   256,     0,     0,   166,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   609,   610,
       0,     0,     0,     0,     0,   611,   612,   613,   614,   615,
     616,   617,   618,   192,   193,   194,     0,     0,     0,   198,
     199,   200,     0,   202,     0,   204,   205,   206,     0,     0,
       0,     0,   211,   212,   213,   214,   215,   216,   217,     0,
       0,   220,     0,   222,     0,   224,     0,     0,   226,   146,
     228,   147,     0,   230,     0,   440,   232,   233,     0,   234,
     235,     0,   237,     0,   239,     0,     0,     0,     0,     0,
     150,   151,   242,     0,     0,     0,     0,     0,     0,   127,
       0,   257,     0,     0,   131,     0,     0,     0,   252,   253,
       0,   254,   255,   159,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,   162,   133,     0,   163,   164,   256,
       0,     0,   166,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,   194,     0,     0,     0,   198,   199,   200,     0,
     202,     0,   204,   205,   206,     0,     0,     0,     0,   211,
     212,   213,   214,   215,   216,   217,     0,     0,   220,     0,
     222,     0,   224,     0,     0,   226,     0,   228,     0,   146,
     230,   147,     0,   232,   233,   442,   234,   235,     0,   237,
       0,   239,   619,   620,   621,   622,     0,     0,   692,   242,
     150,   151,     0,     0,     0,     0,   127,     0,   257,     0,
       0,   131,     0,     0,     0,     0,     0,     0,   252,   253,
       0,   254,   255,   159,     0,     0,     0,     0,     0,     0,
       0,   161,   133,     0,   162,     0,     0,   163,   164,   256,
       0,     0,   166,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,   194,     0,     0,     0,   198,   199,   200,     0,
     202,     0,   204,   205,   206,     0,     0,     0,     0,   211,
     212,   213,   214,   215,   216,   217,     0,     0,   220,     0,
     222,     0,   224,     0,     0,   226,   146,   228,   147,     0,
     230,     0,   444,   232,   233,     0,   234,   235,     0,   237,
       0,   239,     0,     0,     0,     0,     0,   150,   151,   242,
       0,   127,     0,     0,     0,     0,   131,     0,   257,     0,
       0,     0,     0,     0,     0,   252,   253,     0,   254,   255,
     159,     0,     0,     0,     0,     0,     0,   133,   161,     0,
       0,   162,     0,     0,   163,   164,   256,     0,     0,   166,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,   193,   194,
       0,     0,     0,   198,   199,   200,     0,   202,     0,   204,
     205,   206,     0,     0,     0,     0,   211,   212,   213,   214,
     215,   216,   217,     0,     0,   220,     0,   222,     0,   224,
       0,   146,   226,   147,   228,     0,     0,   230,     0,     0,
     232,   233,     0,   234,   235,     0,   237,     0,   239,     0,
       0,     0,   150,   151,     0,     0,   242,     0,   127,     0,
       0,     0,     0,   131,     0,   257,     0,     0,     0,     0,
     252,   253,     0,   254,   255,   159,     0,   785,     0,     0,
       0,     0,     0,   161,   133,     0,   162,     0,     0,   163,
     164,   256,     0,     0,   166,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   192,   193,   194,     0,     0,     0,   198,   199,
     200,     0,   202,     0,   204,   205,   206,     0,     0,     0,
       0,   211,   212,   213,   214,   215,   216,   217,     0,     0,
     220,     0,   222,     0,   224,     0,     0,   226,   146,   228,
     147,     0,   230,     0,     0,   232,   233,     0,   234,   235,
       0,   237,     0,   239,     0,     0,     0,     0,     0,   150,
     151,   242,     0,   127,     0,     0,     0,     0,   131,     0,
     257,     0,     0,     0,     0,     0,     0,   252,   253,     0,
     254,   255,   159,     0,   869,     0,     0,     0,     0,   133,
     161,     0,     0,   162,     0,     0,   163,   164,   256,     0,
       0,   166,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   609,   610,     0,     0,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,     0,     0,   192,
     193,   194,     0,     0,     0,   198,   199,   200,     0,   202,
       0,   204,   205,   206,     0,     0,     0,     0,   211,   212,
     213,   214,   215,   216,   217,  1047,     0,   220,     0,   222,
       0,   224,     0,   146,   226,   147,   228,     0,     0,   230,
       0,     0,   232,   233,     0,   234,   235,     0,   237,     0,
     239,     0,     0,     0,   150,   151,     0,     0,   242,     0,
       0,     0,     0,   127,     0,     0,     0,   257,   131,     0,
       0,     0,   252,   253,     0,   254,   255,   159,     0,     0,
       0,     0,     0,     0,     0,   161,     0,     0,   162,   133,
       0,   163,   164,   256,     0,     0,   166,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,   193,   194,     0,     0,     0,
     198,   199,   200,     0,   202,     0,   204,   205,   206,     0,
       0,     0,     0,   211,   212,   213,   214,   215,   216,   217,
       0,     0,   220,     0,   222,  1457,   224,     0,     0,   226,
       0,   228,     0,   146,   230,   147,     0,   232,   233,     0,
     234,   235,     0,   237,     0,   239,   619,   620,   621,   622,
       0,     0,   805,   242,   150,   151,     0,     0,   127,     0,
       0,     0,   257,   131,     0,     0,     0,     0,     0,     0,
       0,     0,   252,   253,     0,   254,   255,   159,     0,     0,
       0,     0,     0,     0,   133,   161,     0,     0,   162,     0,
       0,   163,   164,   256,     0,     0,   166,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,   193,   194,     0,     0,     0,
     198,   199,   200,     0,   202,     0,   204,   205,   206,     0,
       0,     0,     0,   211,   212,   213,   214,   215,   216,   217,
       0,     0,   220,     0,   222,     0,   224,     0,   146,   226,
     147,   228,     0,     0,   230,     0,     0,   232,   233,     0,
     234,   235,     0,   237,     0,   239,     0,     0,     0,   150,
     151,     0,     0,   242,     0,   127,     0,     0,     0,     0,
     131,     0,   257,     0,     0,     0,     0,   252,   253,     0,
     254,   255,   159,     0,     0,     0,     0,     0,     0,     0,
     161,   133,     0,   162,     0,     0,   163,   164,   256,     0,
       0,   166,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   192,
     193,   194,     0,     0,     0,   198,   199,   200,     0,   202,
       0,   204,   205,   206,     0,     0,     0,     0,   211,   212,
     213,   214,   215,   216,   217,     0,     0,   220,     0,   222,
       0,   224,     0,     0,   226,   146,   228,   147,     0,   230,
       0,     0,   232,   233,     0,   234,   235,     0,   237,     0,
     239,     0,   609,   610,     0,     0,   150,   151,   242,   611,
     612,   613,   614,   615,   616,   617,   618,   257,     0,     0,
       0,     0,     0,     0,   252,   253,     0,   254,   255,   159,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
     162,     0,     0,   163,   164,   256,     0,     0,   166,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,   193,   194,     0,
       0,     0,   198,   199,   200,     0,   202,     0,   204,   205,
     206,     0,     0,     0,     0,   211,   212,   213,   214,   215,
     216,   217,     0,     0,   220,     0,   222,     0,   224,     0,
       0,   226,     0,   228,     0,     0,   230,     0,     0,   232,
     233,     0,   234,   235,     0,   237,     0,   239,     0,     0,
       7,     8,     9,     0,     0,   242,     0,    10,     0,     0,
       0,    11,     0,    12,  1312,    13,    14,    15,    16,    17,
    -497,     0,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,     0,     0,     0,     0,    29,     0,
       0,    30,     0,     0,     0,     0,     0,     0,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    37,    38,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
       0,     0,  1044,     0,    39,    40,    41,    42,    43,    44,
       0,     0,     0,     0,     0,    45,    46,    47,  -244,  -244,
      48,    49,    50,     0,    51,    52,    53,     0,     0,    54,
    -244,     0,    55,     0,    56,    57,     0,     0,     0,     0,
      58,    59,     0,     0,     0,     0,     0,    60,     0,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,     0,
      80,    81,     0,    82,    83,    84,    85,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,     0,     0,
       0,    90,    91,    92,     0,     0,    93,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    98,     0,     0,     0,     0,    99,
       0,     0,   609,   610,     0,     0,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,     0,     0,     0,
       0,   100,     0,     0,     0,   101,     0,     7,     8,     9,
     102,     0,     0,   103,    10,     0,     0,   104,    11,     0,
      12,     0,    13,    14,    15,    16,    17,  -497,     0,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,     0,     0,     0,     0,    29,   -16,   -16,    30,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,    45,    46,    47,     0,     0,    48,    49,    50,
       0,    51,    52,    53,     0,     0,    54,     0,     0,    55,
       0,    56,    57,     0,     0,     0,     0,    58,    59,     0,
       0,     0,     0,     0,    60,     0,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,     0,    80,    81,     0,
      82,    83,    84,    85,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,     0,     0,     0,    90,    91,
      92,     0,     0,    93,    94,    95,   619,   620,   621,   622,
       0,     0,  1074,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,     0,     0,     0,     0,    99,     0,     0,   609,
     610,     0,     0,     0,     0,     0,   611,   612,   613,   614,
     615,   616,   617,   618,     0,     0,     0,     0,   100,     0,
       0,     0,   101,     0,     7,     8,     9,   102,     0,     0,
     103,    10,     0,     0,   104,    11,     0,    12,     0,    13,
      14,    15,    16,    17,  -497,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,   -16,     0,
       0,     0,    29,   -16,     0,    30,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,   609,   610,
       0,    37,    38,     0,     0,   611,   612,   613,   614,   615,
     616,   617,   618,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,    48,    49,    50,     0,    51,    52,
      53,     0,     0,    54,     0,     0,    55,     0,    56,    57,
       0,     0,     0,     0,    58,    59,     0,     0,     0,     0,
       0,    60,     0,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,     0,    80,    81,     0,    82,    83,    84,
      85,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,     0,     0,     0,    90,    91,    92,     0,     0,
      93,    94,    95,   619,   620,   621,   622,   609,   610,  1171,
       0,     0,     0,     0,   611,   612,   613,   614,   615,   616,
     617,   618,     0,     0,     0,     0,    96,    97,    98,   609,
     610,     0,     0,    99,     0,     0,   611,   612,   613,   614,
     615,   616,   617,   618,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,     0,     0,   101,
       0,     0,     0,     0,   102,   609,   610,   103,     0,     0,
       0,   104,   611,   612,   613,   614,   615,   616,   617,   618,
       0,     0,   619,   620,   621,   622,   609,   610,  1172,     0,
       0,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,   609,   610,     0,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,   609,   610,     0,     0,
       0,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,   609,   610,     0,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,   609,   610,     0,     0,
       0,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,   609,   610,     0,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,   609,   610,     0,     0,
       0,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   619,   620,   621,   622,   609,   610,  1174,     0,     0,
       0,     0,   611,   612,   613,   614,   615,   616,   617,   618,
       0,     0,     0,   619,   620,   621,   622,   609,   610,  1175,
       0,     0,     0,     0,   611,   612,   613,   614,   615,   616,
     617,   618,   609,   610,     0,     0,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,     0,     0,   619,
     620,   621,   622,   609,   610,  1176,     0,     0,     0,     0,
     611,   612,   613,   614,   615,   616,   617,   618,     0,     0,
     619,   620,   621,   622,     0,     0,  1190,     0,     0,     0,
       0,     0,     0,     0,     0,   619,   620,   621,   622,     0,
       0,  1227,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,     0,     0,  1234,     0,     0,     0,
       0,     0,     0,     0,     0,   619,   620,   621,   622,     0,
       0,  1235,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,     0,     0,  1255,     0,     0,     0,
       0,     0,     0,     0,     0,   619,   620,   621,   622,     0,
       0,  1307,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,   609,   610,  1330,     0,     0,     0,
       0,   611,   612,   613,   614,   615,   616,   617,   618,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   619,
     620,   621,   622,   609,   610,  1331,     0,     0,     0,     0,
     611,   612,   613,   614,   615,   616,   617,   618,     0,     0,
       0,   619,   620,   621,   622,     0,     0,  1338,     0,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
     609,   610,  1344,     0,     0,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,     0,     0,   619,   620,   621,
     622,   609,   610,  1345,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,   609,   610,     0,     0,
       0,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,   609,   610,     0,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,   609,   610,     0,     0,
       0,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,   609,   610,     0,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,   609,   610,     0,     0,
       0,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,   609,   610,     0,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,     0,     0,   619,   620,
     621,   622,   609,   610,  1385,     0,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   619,   620,   621,
     622,   609,   610,  1438,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,   609,   610,     0,     0,
       0,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,     0,     0,     0,   619,   620,   621,   622,   609,   610,
    1444,     0,     0,     0,     0,   611,   612,   613,   614,   615,
     616,   617,   618,     0,     0,   619,   620,   621,   622,     0,
       0,  1445,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,     0,     0,  1518,     0,     0,     0,
       0,     0,     0,     0,     0,   619,   620,   621,   622,     0,
       0,  1523,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,     0,     0,  1537,     0,     0,     0,
       0,     0,     0,     0,     0,   619,   620,   621,   622,     0,
       0,  1549,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,     0,     0,  1554,     0,     0,     0,
       0,     0,     0,     0,     0,   619,   620,   621,   622,   609,
     610,  1555,     0,     0,     0,     0,   611,   612,   613,   614,
     615,   616,   617,   618,     0,     0,   619,   620,   621,   622,
     609,   610,  1556,     0,     0,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   619,   620,   621,   622,     0,
       0,  1559,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,   609,   610,  1587,     0,     0,     0,
       0,   611,   612,   613,   614,   615,   616,   617,   618,     0,
       0,     0,   619,   620,   621,   622,   609,   610,  1594,     0,
       0,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,   609,   610,     0,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,   609,   610,     0,     0,
       0,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,   609,   610,     0,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,   609,   610,     0,     0,
       0,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,   609,   610,     0,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,   609,   610,     0,     0,
       0,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,     0,     0,   619,   620,   621,   622,   609,   610,  1599,
       0,     0,     0,     0,   611,   612,   613,   614,   615,   616,
     617,   618,     0,     0,   619,   620,   621,   622,   609,   610,
    1602,     0,     0,     0,     0,   611,   612,   613,   614,   615,
     616,   617,   618,   609,   610,     0,     0,     0,     0,     0,
     611,   612,   613,   614,   615,   616,   617,   618,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   619,   620,
     621,   622,   609,   610,  1635,     0,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,     0,     0,     0,
     619,   620,   621,   622,     0,     0,  1660,     0,     0,     0,
       0,     0,     0,     0,     0,   619,   620,   621,   622,     0,
       0,  1661,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,     0,     0,  1683,     0,     0,     0,
       0,     0,     0,     0,     0,   619,   620,   621,   622,     0,
       0,  1697,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,     0,     0,  1812,     0,     0,     0,
       0,     0,     0,     0,     0,   619,   620,   621,   622,     0,
       0,  1813,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,   609,   610,  1814,     0,     0,     0,
       0,   611,   612,   613,   614,   615,   616,   617,   618,     0,
       0,   619,   620,   621,   622,   609,   610,  1816,     0,     0,
       0,     0,   611,   612,   613,   614,   615,   616,   617,   618,
       0,     0,   619,   620,   621,   622,     0,     0,  1822,     0,
       0,     0,     0,     0,     0,     0,     0,   619,   620,   621,
     622,   609,   610,  1825,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
     609,   610,  1830,     0,     0,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,   609,   610,     0,     0,     0,
       0,     0,   611,   612,   613,   614,   615,   616,   617,   618,
     609,   610,     0,     0,     0,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,   609,   610,     0,     0,     0,
       0,     0,   611,   612,   613,   614,   615,   616,   617,   618,
     609,   610,     0,     0,     0,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,   609,   610,     0,     0,     0,
       0,     0,   611,   612,   613,   614,   615,   616,   617,   618,
     609,   610,     0,     0,     0,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,     0,     0,     0,   619,   620,
     621,   622,   609,   610,  1831,     0,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,     0,     0,   619,
     620,   621,   622,   609,   610,  1834,     0,     0,     0,     0,
     611,   612,   613,   614,   615,   616,   617,   618,   609,   610,
       0,     0,     0,     0,     0,   611,   612,   613,   614,   615,
     616,   617,   618,     0,     0,   619,   620,   621,   622,   609,
     610,  1843,     0,     0,     0,     0,   611,   612,   613,   614,
     615,   616,   617,   618,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   619,   620,   621,   622,     0,     0,
    1844,     0,     0,     0,     0,     0,     0,     0,     0,   619,
     620,   621,   622,     0,     0,  1845,     0,     0,     0,     0,
       0,     0,     0,     0,   619,   620,   621,   622,     0,     0,
    1848,     0,     0,     0,     0,     0,     0,     0,     0,   619,
     620,   621,   622,     0,     0,  1852,     0,     0,     0,     0,
       0,     0,     0,     0,   619,   620,   621,   622,     0,     0,
    1867,     0,     0,     0,     0,     0,     0,     0,     0,   619,
     620,   621,   622,     0,     0,  1887,     0,     0,     0,     0,
       0,     0,     0,     0,   619,   620,   621,   622,   609,   610,
    1907,     0,     0,     0,     0,   611,   612,   613,   614,   615,
     616,   617,   618,     0,     0,     0,   619,   620,   621,   622,
     609,   610,  1908,     0,     0,     0,     0,   611,   612,   613,
     614,   615,   616,   617,   618,     0,     0,   619,   620,   621,
     622,     0,     0,  1911,     0,     0,     0,     0,     0,     0,
       0,     0,   619,   620,   621,   622,   609,   610,  1917,     0,
       0,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,     0,     0,   619,   620,   621,   622,   609,   610,  1923,
       0,     0,     0,     0,   611,   612,   613,   614,   615,   616,
     617,   618,   609,   610,     0,     0,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,   609,   610,     0,
       0,     0,     0,     0,   611,   612,   613,   614,   615,   616,
     617,   618,   609,   610,     0,     0,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,   609,   610,     0,
       0,     0,     0,     0,   611,   612,   613,   614,   615,   616,
     617,   618,   609,   610,     0,     0,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,   609,   610,     0,
       0,     0,     0,     0,   611,   612,   613,   614,   615,   616,
     617,   618,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   619,   620,   621,   622,   609,   610,  1924,     0,
       0,     0,     0,   611,   612,   613,   614,   615,   616,   617,
     618,     0,     0,     0,   619,   620,   621,   622,   609,   610,
    1925,     0,     0,     0,     0,   611,   612,   613,   614,   615,
     616,   617,   618,   609,   610,     0,     0,     0,     0,     0,
     611,   612,   613,   614,   615,   616,   617,   618,     0,     0,
     619,   620,   621,   622,   609,   610,  1928,     0,     0,     0,
       0,   611,   612,   613,   614,   615,   616,   617,   618,     0,
       0,   619,   620,   621,   622,     0,     0,  1932,     0,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
       0,     0,  1964,     0,     0,     0,     0,     0,     0,     0,
       0,   619,   620,   621,   622,     0,     0,  1966,     0,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
       0,     0,  1967,     0,     0,     0,     0,     0,     0,     0,
       0,   619,   620,   621,   622,     0,     0,  1969,     0,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
       0,     0,  1975,     0,     0,     0,     0,     0,     0,     0,
       0,   619,   620,   621,   622,   609,   610,  1978,     0,     0,
       0,     0,   611,   612,   613,   614,   615,   616,   617,   618,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     619,   620,   621,   622,   609,   610,  1982,     0,     0,     0,
       0,   611,   612,   613,   614,   615,   616,   617,   618,     0,
       0,     0,   619,   620,   621,   622,     0,     0,  1990,     0,
       0,     0,     0,     0,     0,     0,     0,   619,   620,   621,
     622,   609,   610,  1991,     0,     0,     0,     0,   611,   612,
     613,   614,   615,   616,   617,   618,     0,     0,   619,   620,
     621,   622,   609,   610,  1992,     0,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,   609,   610,     0,
       0,     0,     0,     0,   611,   612,   613,   614,   615,   616,
     617,   618,   609,   610,     0,     0,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,   609,   610,     0,
       0,     0,     0,     0,   611,   612,   613,   614,   615,   616,
     617,   618,   609,   610,     0,     0,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,   609,   610,     0,
       0,     0,     0,     0,   611,   612,   613,   614,   615,   616,
     617,   618,   609,   610,     0,     0,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,     0,     0,   619,
     620,   621,   622,   609,   610,  1998,     0,     0,     0,     0,
     611,   612,   613,   614,   615,   616,   617,   618,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   619,   620,
     621,   622,   609,   610,  2014,     0,     0,     0,     0,   611,
     612,   613,   614,   615,   616,   617,   618,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   619,   620,   621,   622,     0,
       0,  2032,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
       0,     0,  2034,     0,     0,     0,     0,     0,     0,     0,
       0,   619,   620,   621,   622,     0,     0,  2036,     0,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
       0,     0,  2037,     0,     0,     0,     0,     0,     0,     0,
       0,   619,   620,   621,   622,     0,     0,  2057,     0,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
       0,     0,  2059,     0,     0,     0,     0,     0,     0,     0,
       0,   619,   620,   621,   622,     0,     0,  2066,     0,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
       0,     0,  2085,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   619,   620,   621,
     622,     0,     0,  2086,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   619,   620,   621,   622,
       0,     0,  2098
};

static const yytype_int16 yycheck[] =
{
       3,    15,    16,     1,    40,     1,     4,    12,     4,     4,
     489,     4,     7,    12,     7,    44,    75,    58,    21,    60,
      61,    24,    75,    58,    61,    60,    61,    41,     4,     5,
      33,    16,     7,   112,    37,    38,    98,  1686,     4,    42,
       3,     7,   112,   113,     7,     8,     9,    10,   112,   113,
      77,    54,    55,    56,    77,    53,     3,    53,    12,    44,
       7,     8,     9,    10,    75,    76,    77,    70,    71,    72,
       0,   458,   459,    28,   111,    43,    44,   156,    23,    95,
      95,   112,   113,    86,    87,    88,   156,    25,   258,    92,
     270,    12,   156,   263,     4,     5,   111,   110,   101,   102,
     103,   104,   112,   113,   112,   174,    44,    13,   288,    63,
      64,   263,   174,   265,  1319,  1320,    70,    71,    72,    73,
      74,    75,    76,    77,    11,   156,    70,    71,    72,    73,
      74,    75,    76,   101,   111,    70,    71,    72,    73,    74,
      75,    76,    63,    64,   161,   263,   156,   265,   156,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,   112,
      92,    93,   264,   166,    70,    71,    72,    73,    74,    75,
      76,    77,   104,   264,    70,    71,    72,    73,    74,    75,
      76,     4,     5,    70,    71,    72,    73,    74,    75,    76,
     100,    70,    71,    72,    73,    74,    75,    76,   263,    44,
     265,   258,   258,   156,   591,   264,   593,   263,   265,   265,
     264,   264,    70,    71,    72,    73,    74,    75,    76,   258,
     196,   197,   198,    75,   263,   266,   265,   112,   113,   258,
      59,   266,   259,   260,   257,   258,   259,   260,   263,    75,
     265,   244,  1891,    81,    82,  1894,   257,   258,   259,   260,
      88,    28,   258,   258,   257,   264,    33,   263,   263,   265,
      89,    90,    91,   266,   263,    24,   263,    96,   265,   264,
     258,   264,   270,   111,   270,   311,   312,   265,   258,   282,
       4,     5,   264,   263,   287,   265,   196,   197,   198,   162,
     288,   294,   288,   264,   257,   258,    70,    71,    72,    73,
      74,    75,    76,   257,   258,   259,   260,   264,   258,  1958,
     257,   258,  1961,   263,   258,   318,   264,   258,   258,   263,
     265,   265,   267,   258,   265,   265,   329,   330,   331,   112,
     265,    14,   112,    16,   337,    18,   257,   258,   259,   260,
     258,   258,   263,    35,    36,   263,   263,   265,   265,   352,
     353,   257,   258,   259,   260,   264,   258,   258,    41,   362,
     363,    44,   258,   265,   265,   264,    49,   258,   371,   265,
     373,   258,   375,   376,   265,   378,   379,   380,   381,   258,
     264,   384,   385,   386,   258,   388,   265,   390,   264,   392,
     112,   265,   264,   396,   397,   398,   399,   400,   264,   402,
     258,   404,   264,   406,   264,   263,   112,   410,   411,   412,
     413,   414,   258,   416,   417,   418,   419,   263,   421,   422,
     423,   424,   425,   426,   427,   264,   429,   430,   431,   432,
     433,   434,  2081,   436,  2083,   438,    44,   440,   264,   442,
     264,   444,   258,   446,   447,   448,   449,   450,   112,   265,
    2099,   264,  2101,   258,   258,    63,    64,   264,   461,   263,
     265,   265,    70,    71,    72,    73,    74,    75,    76,    77,
     473,   258,   258,   258,   264,   655,   263,   263,   265,   265,
     265,   484,  1687,   486,   258,  1690,     4,     5,   112,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   163,   258,   517,    63,   484,   485,   263,   522,
     523,   264,    70,    71,    72,    73,    74,    75,    76,    77,
     475,   476,    70,    71,    72,    73,    74,    75,    76,   173,
     258,   173,   545,   546,   547,   548,   549,   265,   258,   552,
       4,     5,   555,   263,   557,   265,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   535,   571,   572,
     573,   574,   575,   576,   577,   578,     4,     5,   581,   258,
     583,   584,   585,   586,   587,   258,   265,   590,   112,   592,
     263,   594,   595,   596,    76,    77,  1801,   600,   601,   602,
     603,   604,   605,   606,   607,   262,   263,     4,     5,   577,
      20,    21,    46,    70,    71,    72,    73,    74,    75,    76,
      70,    71,    72,    73,    74,    75,    76,     3,   264,    63,
      64,     7,     8,     9,   579,   580,    70,    71,    72,    73,
      74,    75,    76,    77,   264,   681,    86,    87,   264,   257,
     258,   259,   260,    63,    64,   658,    51,   655,   264,   655,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
       4,     5,   264,    46,   264,    70,    71,    72,    73,    74,
      75,    76,    77,   686,    74,    75,    76,    77,   258,   258,
      63,    64,   264,   263,   263,   265,   699,    70,    71,    72,
      73,    74,    75,    76,    77,    49,    50,   258,   258,   257,
     258,   259,   260,   263,   265,   265,   258,     4,     5,   264,
     258,   258,   725,   265,   727,   263,   671,   672,   265,   258,
     258,   676,   677,   736,   264,   258,   265,   265,   258,    63,
      64,   744,   265,   263,   747,   748,    70,    71,    72,    73,
      74,    75,    76,    77,   264,  1960,    39,    40,  1963,    63,
      64,    73,    74,    75,    76,    77,    70,    71,    72,    73,
      74,    75,    76,    77,   258,   257,   258,   259,   260,   258,
     258,   265,   785,   264,   258,   164,   265,   265,   791,   264,
     793,   265,   795,   264,   797,   258,   799,  1276,   258,   258,
    1279,   258,   265,   806,   263,   265,   263,   156,   258,   989,
     258,  2016,   258,   263,  2019,   818,   819,   265,   164,   265,
      63,    64,   264,   257,   258,   259,   260,    70,    71,    72,
      73,    74,    75,    76,    77,    70,    71,    72,    73,    74,
      75,    76,     4,     5,    63,    64,   264,   257,   258,   259,
     260,    70,    71,    72,    73,    74,    75,    76,    77,    60,
      61,   264,   257,   258,   259,   260,   869,   257,   258,   259,
     260,   874,   264,   876,   877,   878,   879,    70,    71,    72,
      73,    74,    75,    76,   257,   258,   259,   260,  2093,   264,
    2095,    70,    71,    72,    73,    74,    75,    76,   258,   258,
    2105,  2106,   258,   258,   156,   265,   265,   264,   258,   265,
     265,   349,   350,    63,    64,   265,   354,    60,    61,   264,
      70,    71,    72,    73,    74,    75,    76,    77,   264,   264,
     258,   369,   370,   257,   258,   259,   260,   265,   264,   377,
     156,   265,   264,   258,   382,   257,   258,   259,   260,   387,
     265,   389,    44,   257,   258,   259,   260,   258,   264,   263,
      44,   265,   264,   401,   265,   403,   258,   405,   258,   407,
     408,   409,   258,   265,   258,   265,   264,   415,   258,   265,
     258,   265,   420,   997,   998,   265,   156,   265,   258,   258,
     428,   989,   264,   989,     4,   265,   265,   435,    63,    64,
     264,   264,  1005,   264,   264,    70,    71,    72,    73,    74,
      75,    76,    77,   264,   257,   258,   259,   260,  1021,   264,
     263,  1024,   265,   258,  1027,   258,   258,   258,   263,   258,
     263,   263,   263,   156,   263,   258,   264,   258,   257,   258,
     259,   260,   263,   263,   263,   258,   265,   264,  1051,   264,
     263,   258,  1055,   264,   999,  1000,   263,  1002,  1003,  1062,
     264,   264,   258,  1066,   258,   258,  1069,   263,    58,   263,
     263,    71,    72,    73,    74,    75,    76,    77,  1081,   258,
    1083,  1084,  1085,   258,   263,  1088,  1089,  1090,   263,  1092,
     258,   258,   264,  1096,   258,   263,   263,  1100,  1101,   263,
    1103,   258,   263,  1106,   264,  1108,   263,   257,   258,   259,
     260,  1114,  1115,   263,   263,  1118,   264,   264,   264,  1122,
    1123,  1124,  1125,  1303,    14,  1128,    16,   264,    18,  1132,
     258,   264,  1135,   264,   258,   263,  1139,   264,  1141,   263,
    1143,   258,  1145,  1146,  1147,   258,   263,   258,   258,   264,
     263,    41,   263,   263,    44,   264,   264,   258,   258,    49,
      63,    64,   263,   263,  1162,   264,  1162,    70,    71,    72,
      73,    74,    75,    76,    77,  1178,   258,  1180,   258,  1182,
     258,   263,   258,   263,   258,   263,   258,   263,  1191,   263,
    1193,   263,   257,   258,   259,   260,  1199,    14,   263,    16,
     265,    18,   258,    63,    64,  1150,   264,   263,     5,   264,
      70,    71,    72,    73,    74,    75,    76,    77,   264,   264,
     264,    14,   264,    16,    41,    18,   258,    44,   258,   264,
     258,   263,    49,   263,  1237,   263,   258,   258,   258,   258,
     258,   263,   263,   263,   263,   263,    77,   264,    41,   264,
     688,    44,  1255,  1256,  1257,  1258,    49,   257,   258,   259,
     260,  1264,   258,   258,   702,   258,   264,   263,   263,   263,
     263,   709,   264,   711,  1277,   713,   714,  1280,   264,  1282,
     258,   719,   720,    63,    64,   263,    43,   264,   264,   264,
      70,    71,    72,    73,    74,    75,    76,    77,   249,   250,
     251,   252,   253,    63,    64,  1303,  1309,  1303,   264,  1312,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
     264,   264,   264,   264,   264,    70,    71,    72,    73,    74,
      75,    76,    77,   258,  1337,  1338,   258,   264,   263,  1342,
     264,   263,    71,  1346,    73,    74,    75,    76,    77,   263,
     263,   263,   263,   263,   257,   258,   259,   260,  1361,  1362,
     263,  1364,   265,  1366,   258,   263,  1369,  1335,  1336,   263,
    1373,  1374,   258,   264,   258,   263,  1379,   263,  1381,   263,
    1383,   263,  1385,  1328,  1329,   263,   824,   825,  1391,   264,
    1393,   264,  1395,   263,  1397,  1398,  1399,   257,   258,   259,
     260,   265,  1405,   258,   258,   265,  1409,   258,   263,   263,
     848,   258,   263,  1416,   258,   265,   263,   265,   258,   263,
    1423,   258,  1425,   263,  1427,   258,   263,  1430,   258,  1432,
     263,  1434,   258,   263,    75,  1438,  1439,   263,    63,    64,
     265,  1444,  1445,   264,   264,    70,    71,    72,    73,    74,
      75,    76,    77,   263,    70,    71,    72,    73,    74,    75,
      76,    77,    90,    91,    92,    93,    94,    43,   264,   264,
     258,  1474,  1475,  1476,  1477,   263,   104,   257,   258,   259,
     260,   258,   110,   111,   263,   265,   263,   263,   116,   117,
     118,   119,   120,  1507,  1508,    46,   258,   257,   258,   259,
     260,   263,   258,   258,   258,   265,   258,   263,   263,   263,
    1513,   263,   257,   258,   259,   260,   258,   264,   258,   258,
     265,   263,  1525,   263,   263,    10,   264,   258,   257,   258,
     259,   260,   263,    58,  1537,   263,   258,   258,   166,  1542,
    1543,   263,   263,    43,   264,  1548,  1549,   258,  1551,  1552,
     258,   263,   263,   258,   258,   263,  1559,   258,   263,   263,
     263,   258,   263,   258,   263,  1568,   263,   258,   263,  1572,
     263,   258,   263,   258,   258,  1578,   263,  1580,   263,   263,
      85,   264,    63,    64,  1587,  1530,  1531,  1590,  1591,    70,
      71,    72,    73,    74,    75,    76,    77,   258,  1601,  1602,
     263,  1604,   263,  1606,   258,  1608,  1609,  1787,  1788,   263,
     258,   258,   258,   258,   258,   263,   263,   263,   263,   263,
     263,   258,   258,   258,   258,  1628,   263,   263,   263,   263,
     263,  1634,   257,   258,   259,   260,   263,    85,     5,   265,
     265,   257,   258,   259,   260,   265,  1649,   258,   258,   258,
    1653,   258,   263,   263,   263,   263,   263,  1660,   264,   258,
    1663,    63,    64,  1666,   263,   265,   263,   265,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,  1681,   264,
      58,   265,   265,    70,    71,    72,    73,    74,    75,    76,
      77,   258,   258,  1696,  1697,  1698,   263,   263,   263,   258,
     258,   265,   258,  1883,   263,   263,     2,   263,  1711,   264,
     258,  1714,   258,   265,  1717,   263,   265,   263,  1721,   258,
    1723,    17,   258,   265,   263,   258,  1729,   263,  1731,   264,
     263,   265,  1735,  1736,    30,   265,  1739,    33,   258,   258,
      36,    37,    38,   263,   263,  1748,    42,    43,    44,  1752,
     264,   258,  1755,   265,  1757,    51,   263,  1760,  1761,   258,
    1763,   258,   265,   258,   263,   263,   263,  1947,   263,   258,
    1950,   263,   263,  1776,   263,   258,   257,   258,   259,   260,
     263,   258,   258,   258,   265,   263,   263,   263,   263,  1787,
    1788,  1787,  1788,   258,   258,    91,   258,   258,   263,   263,
     263,   263,   263,  1806,   258,   101,   258,  1810,   258,   263,
    1813,   263,   258,   263,  1817,   258,   258,   263,    63,    64,
     263,   263,   263,   263,  2004,    70,    71,    72,    73,    74,
      75,    76,    77,   258,   258,   263,   258,   258,   263,   263,
     136,   263,   263,   263,   263,   258,  1849,   258,  1851,  1852,
     263,  1854,   263,  1856,   258,   257,   258,   259,   260,   263,
     258,   258,   258,   265,   258,   263,   263,   263,   263,   263,
     257,   258,   259,   260,   258,   258,   258,   263,   265,   263,
     263,   263,  1885,    63,    64,  1883,   263,  1883,   263,   263,
      70,    71,    72,    73,    74,    75,    76,    77,   263,   263,
     263,   263,   258,  1906,  1907,  1908,  1909,   263,  1911,  1912,
     265,   258,  1350,  1916,   258,  1353,   263,  1920,   264,   263,
    1358,  1924,  1925,  1926,   265,  1928,   258,   258,   258,  1932,
    1933,   263,   263,   263,   258,  1938,   258,   258,  1941,   263,
    1943,   263,   263,    43,   264,   258,   265,   243,   244,  1947,
     263,  1947,  1950,   258,  1950,   258,  1959,   265,   263,   258,
     263,   265,  1965,  1966,   263,  1968,  1969,  1970,   264,   258,
     258,    63,    64,   269,   263,   263,   263,   263,    70,    71,
      72,    73,    74,    75,    76,    77,   282,   265,  1991,   263,
     263,   287,  1995,   263,  1997,  1998,   258,   258,   294,   258,
     265,   263,   263,    38,   263,   265,  2004,   264,  2004,  2012,
    1448,   265,   257,   258,   259,   260,    43,   264,    58,   265,
     265,   317,   265,   319,    75,    75,  2029,  1465,    75,    48,
    2033,   264,    58,  2036,  2037,   265,   265,   263,  2041,   264,
     264,    47,  2045,   264,   264,    58,    75,   265,   265,    38,
     264,  2054,   264,   263,   263,     4,  2059,     4,  1162,    53,
      53,     5,   489,   681,  1001,  2068,  1005,  1864,  1004,  1513,
    2077,  1315,   368,   678,    -1,   694,    -1,   257,   258,   259,
     260,    -1,  2085,  2086,    -1,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2098,    63,    64,    -1,    -1,
    2103,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   453,   454,   455,
     456,    -1,    -1,    -1,   460,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,   472,    -1,    -1,    -1,
      -1,   477,   478,    -1,   480,   481,   482,   483,   484,   485,
      63,    64,    -1,    -1,    -1,   491,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,    -1,
      -1,    -1,    -1,    -1,   550,   551,   552,   553,   554,    -1,
     556,    -1,   558,    -1,    -1,    -1,  1704,    -1,    -1,    -1,
    1708,    -1,    -1,    -1,   570,    -1,    -1,    -1,    -1,    -1,
      -1,   577,    -1,    -1,    -1,    -1,   582,    -1,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
     656,    63,    64,    -1,    -1,   661,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   674,   675,
      -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,     5,
      -1,   687,   265,    -1,    10,    -1,   692,    -1,    -1,    -1,
      -1,   257,   258,   259,   260,    -1,    -1,   703,   704,   265,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
     746,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    63,    64,    -1,    -1,   105,
      -1,   107,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,   805,
     126,   127,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,   818,   819,   820,   821,    -1,    -1,   144,   145,
      -1,   147,   148,   149,   257,   258,   259,   260,    -1,    -1,
      -1,   157,   265,    -1,   160,    -1,    -1,   163,   164,   165,
      -1,    -1,   168,   169,    -1,   257,   258,   259,   260,    -1,
      -1,    -1,    -1,   265,    -1,    -1,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   197,   198,    -1,    -1,    -1,   202,   203,   204,    -1,
     206,    -1,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,   224,    -1,
     226,    -1,   228,    -1,    -1,   231,    -1,   233,    -1,    -1,
     236,    -1,    -1,   239,   240,    -1,   242,   243,    -1,   245,
      -1,   247,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   264,   265,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   972,   973,    -1,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   992,    -1,    -1,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,  1005,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1018,    -1,    -1,    -1,    -1,   328,  1024,  1025,
      -1,    -1,    -1,   334,  1030,    -1,    -1,    -1,    -1,    -1,
     341,   342,    -1,    -1,    -1,    -1,    -1,    -1,  1044,    -1,
      -1,    -1,    -1,    -1,   355,   356,   357,   358,   359,   360,
     361,    -1,    -1,   364,   365,   366,   367,    -1,  1064,    -1,
      -1,    -1,    -1,  1069,  1070,  1071,    -1,    -1,  1074,    -1,
      -1,  1077,    -1,  1079,    -1,  1081,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1090,    -1,    -1,    -1,  1094,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1102,    -1,  1104,    -1,
      -1,    -1,    -1,    -1,  1110,    -1,    -1,    -1,  1114,  1115,
    1116,    -1,    -1,  1119,  1120,    -1,    -1,  1123,    -1,    -1,
    1126,    -1,    -1,  1129,    -1,  1131,    -1,  1133,    -1,    -1,
      -1,  1137,    -1,  1139,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    -1,    -1,  1151,  1152,  1153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1163,   469,   470,
     471,    -1,    -1,    -1,    -1,  1171,  1172,    -1,  1174,  1175,
    1176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   490,
      -1,  1187,  1188,    -1,  1190,    -1,    -1,    -1,  1194,  1195,
    1196,    -1,  1198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1206,    -1,    -1,    63,    64,    -1,  1212,    -1,    -1,  1215,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,  1227,    -1,    -1,  1230,  1231,  1232,    -1,  1234,  1235,
      -1,    63,    64,    -1,    -1,    -1,    -1,  1243,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1271,    -1,  1273,  1274,  1275,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,  1287,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,  1307,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,  1317,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1330,  1331,    -1,    -1,    -1,  1335,
    1336,    -1,    -1,    63,    64,    -1,    -1,    -1,  1344,  1345,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   697,    -1,    -1,    -1,
     701,    -1,    -1,    -1,    -1,    -1,   707,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,   722,   723,  1419,    -1,    -1,    -1,    -1,    -1,   730,
      -1,    -1,    -1,    -1,   735,   257,   258,   259,   260,   740,
      -1,   742,    -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   754,    -1,   756,    -1,   758,    -1,   760,
     761,   762,    -1,    -1,    -1,    -1,    -1,   768,    -1,    -1,
      -1,    -1,   773,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     781,   257,   258,   259,   260,    -1,    -1,    -1,   789,   265,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,
     258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1513,    -1,    -1,
      -1,    -1,  1518,    -1,    -1,    -1,    -1,  1523,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   257,   258,   259,   260,    -1,  1554,  1555,
    1556,   265,  1558,    -1,    -1,    -1,    -1,    -1,    -1,  1565,
      -1,    -1,    -1,  1569,  1570,   257,   258,   259,   260,  1575,
      -1,  1577,  1578,   265,    -1,    -1,  1582,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1590,    -1,    -1,  1593,  1594,    -1,
    1596,    -1,    -1,  1599,    63,    64,    -1,    -1,  1604,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,  1615,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1633,    -1,  1635,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1645,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1654,    -1,
    1656,    -1,    -1,    -1,    -1,  1661,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1670,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,  1680,    -1,    -1,  1683,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,  1712,  1713,    -1,    -1,
    1716,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1724,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1733,  1734,    -1,
      -1,    -1,  1738,    -1,    -1,    -1,    -1,  1743,    -1,  1050,
      -1,  1747,    -1,    -1,    -1,    -1,    -1,  1058,    -1,    -1,
      -1,    -1,  1063,    -1,  1065,    -1,  1067,  1068,  1764,    -1,
      -1,  1072,  1073,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1789,    -1,    -1,    -1,    -1,   257,   258,
     259,   260,    -1,    -1,  1800,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1812,    -1,  1814,    -1,
    1816,    -1,    -1,    -1,    -1,    -1,  1822,    -1,    -1,  1825,
      -1,  1827,    -1,    -1,  1830,  1831,    -1,    -1,  1834,    -1,
      -1,    -1,    -1,    -1,    -1,  1841,    -1,  1843,  1844,  1845,
      -1,    -1,  1848,    -1,    -1,    -1,    -1,    -1,  1854,    -1,
      -1,    -1,    -1,  1164,  1165,    -1,    -1,    -1,    -1,    -1,
      -1,  1867,    -1,    -1,    -1,   257,   258,   259,   260,    -1,
      -1,    -1,  1878,   265,    -1,    -1,    -1,    -1,  1189,    -1,
    1886,  1887,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,  1914,    -1,
      -1,  1917,    -1,    -1,    -1,  1921,    -1,  1923,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1962,    -1,  1964,    -1,
      -1,  1967,    30,    31,    -1,    -1,    -1,    -1,    -1,  1975,
      -1,    -1,  1978,    -1,    -1,    -1,  1982,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1990,    -1,  1992,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,  2014,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    -1,  2032,    -1,  2034,    97,
      -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,   110,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,  2057,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,
    2066,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,   139,    -1,    -1,    -1,    -1,   144,   145,    -1,   147,
     148,   149,   150,    -1,    -1,   257,   258,   259,   260,   157,
      -1,    -1,   160,   265,    -1,   163,   164,   165,    -1,    -1,
     168,   169,   170,   171,   172,    -1,    -1,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,    -1,   230,   231,   232,   233,    -1,   235,   236,    -1,
     238,   239,   240,    -1,   242,   243,   244,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,   257,
      -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,   266,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1550,
      -1,    -1,  1553,    -1,    -1,    -1,  1557,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,  1619,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,    -1,
     144,   145,    -1,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,    -1,   160,    -1,    -1,   163,
     164,   165,    -1,    -1,   168,   169,   170,   171,   172,    -1,
      -1,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,    -1,   230,   231,   232,   233,
      -1,   235,   236,    -1,   238,   239,   240,    -1,   242,   243,
     244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,    -1,
     254,   255,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,
     264,    -1,   266,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1811,    -1,    -1,    -1,  1815,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,
      -1,    -1,    -1,    -1,   144,   145,    -1,   147,   148,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,
     160,    -1,    -1,   163,   164,   165,    -1,    -1,   168,   169,
     170,   171,   172,    -1,    -1,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,    -1,
     230,   231,   232,   233,    -1,   235,   236,    -1,   238,   239,
     240,    -1,   242,   243,   244,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,    -1,   254,   255,    -1,   257,    -1,    -1,
      -1,    -1,    -1,    -1,   264,    -1,   266,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,
      64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,
      -1,   147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,   160,    -1,    -1,   163,   164,   165,
      -1,    -1,   168,   169,   170,   171,   172,    -1,    -1,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,    -1,   230,   231,   232,   233,    -1,   235,
     236,    -1,   238,   239,   240,    -1,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,   264,    -1,
     266,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,
      -1,    -1,   144,   145,    -1,   147,   148,   149,   150,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,   160,    -1,
      -1,   163,   164,   165,    -1,    -1,   168,   169,   170,   171,
     172,    -1,    -1,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,    -1,   230,   231,
     232,   233,    -1,   235,   236,    -1,   238,   239,   240,    -1,
     242,   243,   244,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,    -1,   254,   255,    -1,   257,    -1,    -1,    -1,    -1,
      -1,    -1,   264,   265,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,
     260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,
      89,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,    -1,    -1,   144,   145,    -1,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,   160,    -1,    -1,   163,   164,   165,    -1,    -1,   168,
     169,   170,   171,   172,    -1,    -1,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
      -1,   230,   231,   232,   233,    -1,   235,   236,    -1,   238,
     239,   240,    -1,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,    -1,   254,   255,    -1,   257,    -1,
      -1,    -1,    -1,    -1,    -1,   264,   265,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,
      64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,
      -1,   147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,   160,    -1,    -1,   163,   164,   165,
      -1,    -1,   168,   169,   170,   171,   172,    -1,    -1,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,    -1,   230,   231,   232,   233,    -1,   235,
     236,    -1,   238,   239,   240,    -1,   242,   243,   244,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,   255,
      -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,   264,   265,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,   257,   258,   259,   260,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,   142,
     143,   144,   145,    -1,   147,   148,   149,   150,    -1,   152,
     153,   154,   155,    -1,   157,    -1,    -1,   160,    -1,    -1,
     163,   164,   165,    -1,    -1,   168,   169,   170,   171,   172,
      -1,    -1,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,    -1,   230,   231,   232,
     233,    -1,   235,   236,    -1,   238,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
      -1,   254,   255,    -1,   257,    -1,    -1,    -1,     3,     4,
       5,   264,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,   138,   139,    -1,    -1,   142,   143,   144,
     145,    -1,   147,   148,   149,   150,   151,    -1,    -1,    -1,
     155,    -1,   157,    -1,    -1,   160,    -1,    -1,   163,   164,
     165,    -1,    -1,   168,   169,   170,   171,   172,    -1,    -1,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,    -1,   230,   231,   232,   233,    -1,
     235,   236,    -1,   238,   239,   240,    -1,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,
     255,    -1,   257,    -1,    -1,    -1,     3,     4,     5,   264,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,   142,   143,   144,   145,    -1,
     147,   148,   149,   150,    -1,   152,    -1,    -1,   155,    -1,
     157,    -1,    -1,   160,    -1,    -1,   163,   164,   165,    -1,
      -1,   168,   169,   170,   171,   172,    -1,    -1,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,    -1,   230,   231,   232,   233,    -1,   235,   236,
      -1,   238,   239,   240,    -1,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
     257,    -1,    -1,    -1,     3,     4,     5,   264,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,   111,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,   142,    -1,   144,   145,    -1,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,   160,    -1,    -1,   163,   164,   165,    -1,    -1,   168,
     169,   170,   171,   172,    -1,    -1,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
      -1,   230,   231,   232,   233,    -1,   235,   236,    -1,   238,
     239,   240,    -1,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,    -1,   254,   255,    -1,   257,    -1,
      -1,    -1,     3,     4,     5,   264,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,
      -1,   142,   143,   144,   145,    -1,   147,   148,   149,   150,
      -1,    -1,    -1,    -1,   155,    -1,   157,    -1,    -1,   160,
      -1,    -1,   163,   164,   165,    -1,    -1,   168,   169,   170,
     171,   172,    -1,    -1,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,    -1,   230,
     231,   232,   233,    -1,   235,   236,    -1,   238,   239,   240,
      -1,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,   257,    -1,    -1,    -1,
       3,     4,     5,   264,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,   111,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,
      -1,   144,   145,    -1,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,    -1,   160,    -1,    -1,
     163,   164,   165,    -1,    -1,   168,   169,   170,   171,   172,
      -1,    -1,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,    -1,   230,   231,   232,
     233,    -1,   235,   236,    -1,   238,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
      -1,   254,   255,    -1,   257,    -1,    -1,    -1,     3,     4,
       5,   264,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,
      63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,   111,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,   138,   139,    -1,    -1,   142,   143,   144,
     145,    -1,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,    -1,   160,    -1,    -1,   163,   164,
     165,    -1,    -1,   168,   169,   170,   171,   172,    -1,    -1,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,    -1,   230,   231,   232,   233,    -1,
     235,   236,    -1,   238,   239,   240,    -1,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,
     255,    -1,   257,    -1,    -1,    -1,     3,     4,     5,   264,
       7,     8,     9,    10,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,
      -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,    -1,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,   160,    -1,    -1,   163,   164,   165,    -1,
      -1,   168,   169,   170,   171,   172,    -1,    -1,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,    -1,   230,   231,   232,   233,    -1,   235,   236,
      -1,   238,   239,   240,    -1,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
     257,    -1,    -1,    -1,     3,     4,     5,   264,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,
      89,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,   160,    -1,    -1,   163,   164,   165,    -1,    -1,   168,
     169,   170,   171,   172,    -1,    -1,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
      -1,   230,   231,   232,   233,    -1,   235,   236,    -1,   238,
     239,   240,    -1,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,    -1,   254,   255,    -1,   257,    -1,
      -1,    -1,     3,     4,     5,   264,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
     111,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,
      -1,    -1,    -1,   144,   145,    -1,   147,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,   160,
      -1,    -1,   163,   164,   165,    -1,    -1,   168,   169,   170,
     171,   172,    -1,    -1,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,    -1,   230,
     231,   232,   233,    -1,   235,   236,    -1,   238,   239,   240,
      -1,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,   257,    -1,    -1,    -1,
       3,     4,     5,   264,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,   112,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,
     143,   144,   145,    -1,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,    -1,   160,    -1,    -1,
     163,   164,   165,    -1,    -1,   168,   169,   170,   171,   172,
      -1,    -1,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,    -1,   230,   231,   232,
     233,    -1,   235,   236,    -1,   238,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
      -1,   254,   255,    -1,   257,    -1,    -1,    -1,     3,     4,
       5,   264,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,
      63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,    -1,   112,   113,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,   138,   139,    -1,    -1,    -1,    -1,   144,
     145,    -1,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,    -1,   160,    -1,    -1,   163,   164,
     165,    -1,    -1,   168,   169,   170,   171,   172,    -1,    -1,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,    -1,   230,   231,   232,   233,    -1,
     235,   236,    -1,   238,   239,   240,    -1,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,
     255,    -1,   257,    -1,    -1,    -1,     3,     4,     5,   264,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    30,    31,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,
      -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,    -1,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,   160,    -1,    -1,   163,   164,   165,    -1,
      -1,   168,   169,   170,   171,   172,    -1,    -1,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,    -1,   230,   231,   232,   233,    -1,   235,   236,
      -1,   238,   239,   240,    -1,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
     257,    -1,    -1,    -1,     3,     4,     5,   264,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,
      89,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,   111,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,    -1,    -1,   144,   145,    -1,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,   160,    -1,    -1,   163,   164,   165,    -1,    -1,   168,
     169,   170,   171,   172,    -1,    -1,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
      -1,   230,   231,   232,   233,    -1,   235,   236,    -1,   238,
     239,   240,    -1,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,    -1,   254,   255,    -1,   257,    -1,
      -1,    -1,     3,     4,     5,   264,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
     111,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,
      -1,    -1,    -1,   144,   145,    -1,   147,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,   160,
      -1,    -1,   163,   164,   165,    -1,    -1,   168,   169,   170,
     171,   172,    -1,    -1,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,    -1,   230,
     231,   232,   233,    -1,   235,   236,    -1,   238,   239,   240,
      -1,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,   257,    -1,    -1,    -1,
       3,     4,     5,   264,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,   111,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,
      -1,   144,   145,    -1,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,    -1,   160,    -1,    -1,
     163,   164,   165,    -1,    -1,   168,   169,   170,   171,   172,
      -1,    -1,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,    -1,   230,   231,   232,
     233,    -1,   235,   236,    -1,   238,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
      -1,   254,   255,    -1,   257,    -1,    -1,    -1,     3,     4,
       5,   264,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,
      63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,   111,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,   138,   139,    -1,    -1,    -1,    -1,   144,
     145,    -1,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,    -1,   160,    -1,    -1,   163,   164,
     165,    -1,    -1,   168,   169,   170,   171,   172,    -1,    -1,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,    -1,   230,   231,   232,   233,    -1,
     235,   236,    -1,   238,   239,   240,    -1,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,
     255,    -1,   257,    -1,    -1,    -1,     3,     4,     5,   264,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,
      -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,    -1,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,   160,    -1,    -1,   163,   164,   165,    -1,
      -1,   168,   169,   170,   171,   172,    -1,    -1,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,    -1,   230,   231,   232,   233,    -1,   235,   236,
      -1,   238,   239,   240,    -1,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
     257,    -1,    -1,    -1,     3,     4,     5,   264,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,
      89,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,   111,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,    -1,    -1,   144,   145,    -1,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,   160,    -1,    -1,   163,   164,   165,    -1,    -1,   168,
     169,   170,   171,   172,    -1,    -1,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
      -1,   230,   231,   232,   233,    -1,   235,   236,    -1,   238,
     239,   240,    -1,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,    -1,   254,   255,    -1,   257,    -1,
      -1,    -1,     3,     4,     5,   264,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
     111,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,
      -1,    -1,    -1,   144,   145,    -1,   147,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,   160,
      -1,    -1,   163,   164,   165,    -1,    -1,   168,   169,   170,
     171,   172,    -1,    -1,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,    -1,   230,
     231,   232,   233,    -1,   235,   236,    -1,   238,   239,   240,
      -1,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,    -1,   254,   255,    -1,   257,    -1,    -1,    -1,
       3,     4,     5,   264,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,   111,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,
      -1,   144,   145,    -1,   147,   148,   149,   150,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,    -1,   160,    -1,    -1,
     163,   164,   165,    -1,    -1,   168,   169,   170,   171,   172,
      -1,    -1,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,    -1,   230,   231,   232,
     233,    -1,   235,   236,    -1,   238,   239,   240,    -1,   242,
     243,   244,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
      -1,   254,   255,    -1,   257,    -1,    -1,    -1,     3,     4,
       5,   264,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      -1,    -1,    -1,    -1,   265,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,
      63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,   111,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,   138,   139,    -1,    -1,    -1,    -1,   144,
     145,    -1,   147,   148,   149,   150,    -1,    -1,    -1,    -1,
      -1,    -1,   157,    -1,    -1,   160,    -1,    -1,   163,   164,
     165,    -1,    -1,   168,   169,   170,   171,   172,    -1,    -1,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,    -1,   230,   231,   232,   233,    -1,
     235,   236,    -1,   238,   239,   240,    -1,   242,   243,   244,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,    -1,   254,
     255,    -1,   257,    -1,    -1,    -1,     3,     4,     5,   264,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,    -1,
      -1,    -1,   265,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,
      -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,    -1,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,   160,    -1,    -1,   163,   164,   165,    -1,
      -1,   168,   169,   170,   171,   172,    -1,    -1,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,    -1,   230,   231,   232,   233,    -1,   235,   236,
      -1,   238,   239,   240,    -1,   242,   243,   244,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,    -1,   254,   255,    -1,
     257,    -1,    -1,    -1,     3,     4,     5,   264,     7,     8,
       9,    10,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,   258,   259,   260,    -1,    -1,    -1,    -1,
     265,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,
      89,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,    -1,    -1,   144,   145,    -1,   147,   148,
     149,   150,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,   160,    -1,    -1,   163,   164,   165,    -1,    -1,   168,
     169,   170,   171,   172,    -1,    -1,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
      -1,   230,   231,   232,   233,    -1,   235,   236,    -1,   238,
     239,   240,    -1,   242,   243,   244,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,    -1,   254,   255,    -1,   257,    -1,
      -1,    -1,     3,     4,     5,   264,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,
      -1,    -1,    -1,   144,   145,    -1,   147,   148,   149,   150,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,   160,
      -1,    -1,   163,   164,   165,    -1,    -1,   168,   169,   170,
     171,   172,    -1,    -1,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,    -1,   230,
     231,   232,   233,    -1,   235,   236,    -1,   238,   239,   240,
      -1,   242,   243,   244,   245,   246,   247,   248,    -1,    -1,
       5,    -1,    -1,   254,   255,    10,   257,    -1,    -1,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,   257,   258,
     259,   260,    -1,    -1,    -1,    -1,   265,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
     105,    -1,   107,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,    -1,    -1,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,    -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    31,   157,    -1,    -1,   160,    -1,    -1,   163,   164,
     165,    -1,    -1,   168,   169,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,   196,   197,   198,    -1,    -1,    -1,   202,   203,   204,
      -1,   206,    -1,   208,   209,   210,    -1,    -1,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,   224,
      -1,   226,    -1,   228,    -1,   105,   231,   107,   233,    -1,
      -1,   236,    -1,    -1,   239,   240,    -1,   242,   243,    -1,
     245,    -1,   247,    -1,    -1,    -1,   126,   127,    -1,    -1,
     255,    -1,     5,   257,   258,   259,   260,    10,    -1,   264,
     265,   265,    -1,    -1,   144,   145,    -1,   147,   148,   149,
      -1,   257,   258,   259,   260,    -1,    -1,   157,    31,   265,
     160,    -1,    -1,   163,   164,   165,    -1,    -1,   168,   169,
     257,   258,   259,   260,    -1,    -1,    -1,    -1,   265,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   196,   197,   198,    -1,
      -1,    -1,   202,   203,   204,    -1,   206,    -1,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,   224,    -1,   226,    -1,   228,    -1,
      -1,   231,   105,   233,   107,    -1,   236,    -1,    -1,   239,
     240,    -1,   242,   243,    -1,   245,    -1,   247,   257,   258,
     259,   260,    -1,   126,   127,   255,    -1,    -1,    -1,    -1,
      -1,    -1,     5,    -1,   264,   265,    -1,    10,    -1,    -1,
      -1,   144,   145,    -1,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    -1,    -1,   160,    31,    -1,
     163,   164,   165,    -1,    -1,   168,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   196,   197,   198,    -1,    -1,    -1,   202,
     203,   204,    -1,   206,    -1,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,   224,    -1,   226,    -1,   228,    -1,    -1,   231,    -1,
     233,    -1,   105,   236,   107,    -1,   239,   240,   111,   242,
     243,    -1,   245,    -1,   247,   257,   258,   259,   260,    -1,
      -1,   263,   255,   126,   127,    -1,    -1,    -1,    -1,     5,
      -1,   264,   265,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,    -1,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   157,    31,    -1,   160,    -1,    -1,
     163,   164,   165,    -1,    -1,   168,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,   196,   197,   198,    -1,    -1,    -1,   202,
     203,   204,    -1,   206,    -1,   208,   209,   210,    -1,    -1,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,   224,    -1,   226,    -1,   228,    -1,    -1,   231,   105,
     233,   107,    -1,   236,    -1,   111,   239,   240,    -1,   242,
     243,    -1,   245,    -1,   247,    -1,    -1,    -1,    -1,    -1,
     126,   127,   255,    -1,    -1,    -1,    -1,    -1,    -1,     5,
      -1,   264,    -1,    -1,    10,    -1,    -1,    -1,   144,   145,
      -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    -1,    -1,   160,    31,    -1,   163,   164,   165,
      -1,    -1,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   197,   198,    -1,    -1,    -1,   202,   203,   204,    -1,
     206,    -1,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,   224,    -1,
     226,    -1,   228,    -1,    -1,   231,    -1,   233,    -1,   105,
     236,   107,    -1,   239,   240,   111,   242,   243,    -1,   245,
      -1,   247,   257,   258,   259,   260,    -1,    -1,   263,   255,
     126,   127,    -1,    -1,    -1,    -1,     5,    -1,   264,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
      -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   157,    31,    -1,   160,    -1,    -1,   163,   164,   165,
      -1,    -1,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     196,   197,   198,    -1,    -1,    -1,   202,   203,   204,    -1,
     206,    -1,   208,   209,   210,    -1,    -1,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,   224,    -1,
     226,    -1,   228,    -1,    -1,   231,   105,   233,   107,    -1,
     236,    -1,   111,   239,   240,    -1,   242,   243,    -1,   245,
      -1,   247,    -1,    -1,    -1,    -1,    -1,   126,   127,   255,
      -1,     5,    -1,    -1,    -1,    -1,    10,    -1,   264,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,    -1,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,    31,   157,    -1,
      -1,   160,    -1,    -1,   163,   164,   165,    -1,    -1,   168,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,   197,   198,
      -1,    -1,    -1,   202,   203,   204,    -1,   206,    -1,   208,
     209,   210,    -1,    -1,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,   224,    -1,   226,    -1,   228,
      -1,   105,   231,   107,   233,    -1,    -1,   236,    -1,    -1,
     239,   240,    -1,   242,   243,    -1,   245,    -1,   247,    -1,
      -1,    -1,   126,   127,    -1,    -1,   255,    -1,     5,    -1,
      -1,    -1,    -1,    10,    -1,   264,    -1,    -1,    -1,    -1,
     144,   145,    -1,   147,   148,   149,    -1,   151,    -1,    -1,
      -1,    -1,    -1,   157,    31,    -1,   160,    -1,    -1,   163,
     164,   165,    -1,    -1,   168,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,   198,    -1,    -1,    -1,   202,   203,
     204,    -1,   206,    -1,   208,   209,   210,    -1,    -1,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
     224,    -1,   226,    -1,   228,    -1,    -1,   231,   105,   233,
     107,    -1,   236,    -1,    -1,   239,   240,    -1,   242,   243,
      -1,   245,    -1,   247,    -1,    -1,    -1,    -1,    -1,   126,
     127,   255,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,    -1,
     147,   148,   149,    -1,   151,    -1,    -1,    -1,    -1,    31,
     157,    -1,    -1,   160,    -1,    -1,   163,   164,   165,    -1,
      -1,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   196,
     197,   198,    -1,    -1,    -1,   202,   203,   204,    -1,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,    97,    -1,   224,    -1,   226,
      -1,   228,    -1,   105,   231,   107,   233,    -1,    -1,   236,
      -1,    -1,   239,   240,    -1,   242,   243,    -1,   245,    -1,
     247,    -1,    -1,    -1,   126,   127,    -1,    -1,   255,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    -1,   264,    10,    -1,
      -1,    -1,   144,   145,    -1,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,   160,    31,
      -1,   163,   164,   165,    -1,    -1,   168,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   197,   198,    -1,    -1,    -1,
     202,   203,   204,    -1,   206,    -1,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,   224,    -1,   226,    97,   228,    -1,    -1,   231,
      -1,   233,    -1,   105,   236,   107,    -1,   239,   240,    -1,
     242,   243,    -1,   245,    -1,   247,   257,   258,   259,   260,
      -1,    -1,   263,   255,   126,   127,    -1,    -1,     5,    -1,
      -1,    -1,   264,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,    -1,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,    31,   157,    -1,    -1,   160,    -1,
      -1,   163,   164,   165,    -1,    -1,   168,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   196,   197,   198,    -1,    -1,    -1,
     202,   203,   204,    -1,   206,    -1,   208,   209,   210,    -1,
      -1,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
      -1,    -1,   224,    -1,   226,    -1,   228,    -1,   105,   231,
     107,   233,    -1,    -1,   236,    -1,    -1,   239,   240,    -1,
     242,   243,    -1,   245,    -1,   247,    -1,    -1,    -1,   126,
     127,    -1,    -1,   255,    -1,     5,    -1,    -1,    -1,    -1,
      10,    -1,   264,    -1,    -1,    -1,    -1,   144,   145,    -1,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    31,    -1,   160,    -1,    -1,   163,   164,   165,    -1,
      -1,   168,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
     197,   198,    -1,    -1,    -1,   202,   203,   204,    -1,   206,
      -1,   208,   209,   210,    -1,    -1,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,    -1,    -1,   224,    -1,   226,
      -1,   228,    -1,    -1,   231,   105,   233,   107,    -1,   236,
      -1,    -1,   239,   240,    -1,   242,   243,    -1,   245,    -1,
     247,    -1,    63,    64,    -1,    -1,   126,   127,   255,    70,
      71,    72,    73,    74,    75,    76,    77,   264,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,    -1,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,
     160,    -1,    -1,   163,   164,   165,    -1,    -1,   168,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   196,   197,   198,    -1,
      -1,    -1,   202,   203,   204,    -1,   206,    -1,   208,   209,
     210,    -1,    -1,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,    -1,    -1,   224,    -1,   226,    -1,   228,    -1,
      -1,   231,    -1,   233,    -1,    -1,   236,    -1,    -1,   239,
     240,    -1,   242,   243,    -1,   245,    -1,   247,    -1,    -1,
       4,     5,     6,    -1,    -1,   255,    -1,    11,    -1,    -1,
      -1,    15,    -1,    17,   264,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      -1,    -1,   263,    -1,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    98,    99,   100,    -1,    -1,   103,
     104,    -1,   106,    -1,   108,   109,    -1,    -1,    -1,    -1,
     114,   115,    -1,    -1,    -1,    -1,    -1,   121,    -1,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,    -1,
     144,   145,    -1,   147,   148,   149,   150,    -1,    -1,    -1,
      -1,    -1,    -1,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,    -1,    -1,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   196,   197,   198,    -1,    -1,    -1,    -1,   203,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,   225,    -1,    -1,    -1,   229,    -1,     4,     5,     6,
     234,    -1,    -1,   237,    11,    -1,    -1,   241,    15,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    -1,    -1,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,   108,   109,    -1,    -1,    -1,    -1,   114,   115,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    -1,    -1,   144,   145,    -1,
     147,   148,   149,   150,    -1,    -1,    -1,    -1,    -1,    -1,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,    -1,    -1,   170,   171,   172,   257,   258,   259,   260,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   196,
     197,   198,    -1,    -1,    -1,    -1,   203,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,   225,    -1,
      -1,    -1,   229,    -1,     4,     5,     6,   234,    -1,    -1,
     237,    11,    -1,    -1,   241,    15,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    38,    -1,
      -1,    -1,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    63,    64,
      -1,    61,    62,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    -1,    -1,    94,    95,    96,    -1,    98,    99,
     100,    -1,    -1,   103,    -1,    -1,   106,    -1,   108,   109,
      -1,    -1,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,
      -1,   121,    -1,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,    -1,   144,   145,    -1,   147,   148,   149,
     150,    -1,    -1,    -1,    -1,    -1,    -1,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,
     170,   171,   172,   257,   258,   259,   260,    63,    64,   263,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,   196,   197,   198,    63,
      64,    -1,    -1,   203,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,    -1,    -1,    -1,   229,
      -1,    -1,    -1,    -1,   234,    63,    64,   237,    -1,    -1,
      -1,   241,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,   257,   258,   259,   260,    63,    64,   263,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   257,   258,   259,   260,    63,    64,   263,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,   257,   258,   259,   260,    63,    64,   263,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   257,
     258,   259,   260,    63,    64,   263,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    63,    64,   263,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,
     258,   259,   260,    63,    64,   263,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,   257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      63,    64,   263,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   257,   258,   259,
     260,    63,    64,   263,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   257,   258,
     259,   260,    63,    64,   263,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,
     260,    63,    64,   263,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,   257,   258,   259,   260,    63,    64,
     263,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   257,   258,   259,   260,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,    63,
      64,   263,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   257,   258,   259,   260,
      63,    64,   263,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    63,    64,   263,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,   257,   258,   259,   260,    63,    64,   263,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   257,   258,   259,   260,    63,    64,   263,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   257,   258,   259,   260,    63,    64,
     263,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   258,
     259,   260,    63,    64,   263,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    63,    64,   263,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,   257,   258,   259,   260,    63,    64,   263,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,   257,   258,   259,   260,    -1,    -1,   263,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,
     260,    63,    64,   263,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      63,    64,   263,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,   257,   258,
     259,   260,    63,    64,   263,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   257,
     258,   259,   260,    63,    64,   263,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   257,   258,   259,   260,    63,
      64,   263,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,
     258,   259,   260,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,
     258,   259,   260,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,    -1,
     263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,
     258,   259,   260,    -1,    -1,   263,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   257,   258,   259,   260,    63,    64,
     263,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,   257,   258,   259,   260,
      63,    64,   263,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   257,   258,   259,
     260,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,   258,   259,   260,    63,    64,   263,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   257,   258,   259,   260,    63,    64,   263,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   257,   258,   259,   260,    63,    64,   263,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,   257,   258,   259,   260,    63,    64,
     263,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     257,   258,   259,   260,    63,    64,   263,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,   257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   257,   258,   259,   260,    63,    64,   263,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     257,   258,   259,   260,    63,    64,   263,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,   257,   258,   259,   260,    -1,    -1,   263,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,
     260,    63,    64,   263,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   257,   258,
     259,   260,    63,    64,   263,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   257,
     258,   259,   260,    63,    64,   263,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   258,
     259,   260,    63,    64,   263,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,    -1,
      -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   257,   258,   259,   260,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,
     260,    -1,    -1,   263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   257,   258,   259,   260,
      -1,    -1,   263
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   249,   250,   251,   252,   253,   268,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   114,   115,
     121,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     144,   145,   147,   148,   149,   150,   157,   158,   159,   160,
     165,   166,   167,   170,   171,   172,   196,   197,   198,   203,
     225,   229,   234,   237,   241,   269,   270,   273,   274,   281,
     282,   284,   285,   289,   301,   302,   307,   313,   320,   328,
     336,   339,   343,   346,   352,     3,     4,     5,     7,     8,
       9,    10,    30,    31,    63,    64,    65,    66,    67,    68,
      69,    81,    84,    89,   101,   102,   105,   107,   115,   122,
     126,   127,   136,   138,   139,   144,   145,   147,   148,   149,
     150,   157,   160,   163,   164,   165,   168,   169,   170,   171,
     172,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   230,   231,   232,   233,   235,
     236,   238,   239,   240,   242,   243,   244,   245,   246,   247,
     248,   254,   255,   257,   264,   287,   288,   290,   296,   298,
     301,   302,   144,   145,   147,   148,   165,   264,   287,   273,
     301,   302,   307,     0,    75,   264,    75,   264,   321,   340,
     344,     4,     7,   299,   299,   299,    34,   290,   275,   276,
     287,   303,   304,   303,   287,    28,     7,   329,   337,   290,
      58,    60,    61,   266,   383,   279,   287,   290,     4,     5,
     300,   290,   287,   290,   287,   290,     4,     5,   363,   364,
      10,   257,   258,   297,   298,   365,   299,    89,    97,   266,
     287,   290,   384,    89,    97,   110,   384,   384,    81,    82,
      88,   111,   290,   295,    12,    53,   295,   111,   295,    59,
      89,    90,    91,    96,    95,   290,   282,   289,   287,   287,
     287,   110,   143,   146,   295,    90,    91,    92,    93,    94,
     104,   110,   111,   116,   117,   118,   119,   120,   166,   295,
     295,   111,   295,   111,   295,    95,   111,   295,    61,    95,
     111,   142,   295,   295,    22,    61,   111,   295,   111,   295,
     111,   295,   111,   287,   287,   287,    61,   111,   111,   142,
     143,   295,   111,   295,   111,   295,   111,   295,   295,   295,
      95,   142,   143,   152,   155,   295,    95,   142,   143,   155,
     295,    95,   142,   143,   152,   153,   154,   155,   295,    61,
      95,   142,   143,   151,   155,   295,   111,   295,   111,   295,
     111,   287,   111,   287,   111,   287,   161,    95,   111,   112,
     143,   290,   287,    98,   174,   174,   111,   264,   264,   264,
     264,   264,   287,   384,   287,   287,   287,    44,   271,    92,
      93,   104,    75,    75,    24,   264,   264,   264,   264,   290,
     264,   264,   264,   264,   264,   264,   112,   113,   264,   264,
     264,   264,   112,   264,   112,   156,   112,   156,   112,   112,
     112,   112,   113,   156,   112,   113,   156,   112,   113,   156,
     112,   113,   156,   112,   112,   163,   162,   264,   112,   156,
     287,   295,   173,   173,   112,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   164,   164,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   290,   287,   290,
      70,    71,    72,    73,    74,    75,    76,   258,    44,    63,
      64,    70,    71,    72,    73,    74,    75,    76,    77,   257,
     258,   259,   260,   287,    44,    44,    44,   290,   303,   287,
     303,     4,   290,   270,    35,    36,    20,    21,     4,     5,
     314,   315,     4,     5,   316,   317,   287,   290,   305,   306,
     287,   290,   331,   270,   347,   353,   264,    58,   264,     4,
       7,   264,   287,   290,   366,    58,    60,    61,   266,   368,
     381,   264,   264,   263,   263,   263,   264,   264,   263,   298,
     298,   263,   290,   287,   290,    11,   263,   263,   295,   287,
     287,   287,   263,   295,   280,    12,   263,   283,   287,   263,
     295,    12,   295,   283,   283,   287,   287,   283,   295,   295,
     295,   295,   295,   295,   295,   287,   287,   295,   295,   295,
     295,   290,   283,   283,   287,   263,   287,   263,   287,   287,
     283,   287,   287,   287,   287,   283,   263,   287,   287,   287,
     283,   287,   283,   287,   263,   287,   263,   263,   263,   287,
     287,   287,   287,   287,   283,   287,   283,   287,   283,   287,
     283,   283,   283,   287,   287,   287,   287,   287,   283,   287,
     287,   287,   287,   283,   287,   287,   287,   287,   287,   287,
     287,   283,   287,   287,   287,   151,   287,   287,   287,   283,
     287,   263,   287,   263,   287,   263,   287,   263,   287,   263,
     287,   287,   287,   287,   287,   263,   263,   290,   290,   290,
     290,     5,   286,   286,   286,   265,   290,   287,   263,   263,
     263,   263,    43,   295,   295,   295,   290,   287,   308,   303,
     303,   290,   290,   290,   290,   290,   290,    97,   287,   384,
     384,   287,     4,     5,   293,   294,   293,   294,   295,   290,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   151,
     287,   287,   287,   287,   264,   287,   264,   264,   263,   263,
     287,   287,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   384,   290,   290,   290,   290,   290,   290,   290,
     290,   265,   290,   287,   287,   287,   287,   287,   290,   290,
     287,   290,   265,   290,   290,   287,   290,   287,   290,   287,
     287,   265,   287,   265,   287,   265,   287,   265,   287,   287,
     287,   287,   287,   287,   290,   287,   287,   287,   287,   287,
     287,   287,   384,   287,   303,   303,   287,   290,   287,   287,
     287,   287,   287,   265,   265,   287,   286,   287,   286,   287,
     287,   287,   265,   265,   287,   287,   287,   287,   287,   287,
     287,   287,   292,   291,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   265,   265,    75,   341,
      14,    16,    18,    41,    44,    49,   345,   277,   278,   264,
     264,   263,   264,   264,   263,   263,    43,   330,    14,    16,
      18,    41,    44,    49,   338,    46,   270,   290,   264,   287,
     290,    51,   367,   262,   263,   264,    58,   264,     4,     7,
     264,    10,   382,   303,   303,     4,     5,   290,   290,   303,
     303,   364,    10,   297,   263,    86,    87,    97,   287,   290,
     283,   263,   290,   368,   295,   263,   287,   295,   283,   290,
     290,   295,   263,   283,   263,   283,   263,   283,   283,   263,
     263,   263,   283,   283,   263,   295,   295,   263,   287,   263,
     287,   263,   295,   263,   263,   263,   295,   287,   263,   263,
     263,   295,   263,   295,   263,   287,   263,   290,   287,   287,
     263,   263,   263,   263,   263,   295,   263,   295,   263,   295,
     263,   295,   295,   295,   263,   263,   263,   295,   263,   263,
     263,   295,   263,   263,   263,   263,   263,   295,   263,   263,
     287,   263,   263,   263,   295,   263,   287,   263,   287,   263,
     287,   263,   287,   263,   287,   263,   263,   263,   290,   287,
     264,   263,   263,   263,   265,   265,   287,   290,   287,   290,
     290,   290,   272,   263,   283,   283,     4,     5,   312,   265,
     265,   263,   263,   265,   263,   263,   263,   265,   263,   265,
     263,   265,   263,   264,   264,   265,   265,   263,   263,   283,
     263,   263,   265,   263,   263,   263,   263,   287,   263,   263,
     287,   265,   287,   287,   287,   287,   263,   265,   265,   265,
     265,   265,   263,   265,   265,   263,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   263,   265,   265,
     263,   263,   263,   265,   263,   263,   265,   263,   265,   265,
     265,   265,   265,   263,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   263,   263,   263,   263,   265,
     265,   265,   265,   265,   263,   265,   265,   265,   265,   265,
     265,   263,   265,   263,   263,   263,   263,   263,   265,   263,
     263,   265,   263,   265,   265,   290,   290,   322,   270,   290,
     299,   385,   299,   386,   303,   303,   315,   303,   303,   317,
     306,    43,   332,   348,    49,    50,   354,   263,   290,   263,
     265,   265,   264,   287,   287,   290,   290,   264,   287,   369,
     370,   290,     4,     5,   360,   362,   265,   265,   264,   264,
     263,   263,   265,   265,   290,    85,    85,   263,   263,   295,
     287,   287,   263,   295,   263,   263,   263,   287,   295,   290,
     295,   287,   295,   295,   287,   290,   290,   290,   295,   295,
     290,   263,   263,   290,   263,   290,   263,   287,   290,   263,
     287,   287,   287,   263,   263,   287,   287,   287,   290,   263,
     287,   263,   290,   263,   287,   263,   287,   287,   290,   287,
     290,   263,   287,   263,   287,   263,   290,   263,   263,   263,
     287,   290,   287,   290,   290,   263,   287,   290,   290,   263,
     287,   287,   290,   287,   287,   290,   263,   287,   290,   263,
     290,   287,   290,   263,   287,   263,   290,   263,   287,   290,
     263,   287,   263,   287,   263,   287,   287,   287,   263,   263,
     303,   290,   290,   290,   263,   263,   274,   290,   295,   295,
     309,   290,   290,   290,   290,   290,   287,    97,   287,   287,
     265,   265,   290,   290,   295,   290,   287,   287,   290,   290,
     290,   290,   287,   265,   263,   263,   263,   263,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   287,   290,   287,
     287,   287,   287,   287,   290,   290,   290,   290,   294,   287,
     294,   287,   287,   290,    16,    44,   342,   263,   263,   265,
     265,   265,   265,    39,    40,   334,   270,   290,   263,   287,
      58,   287,   367,   263,   290,   263,   265,   360,   360,   265,
     264,   264,   263,   303,   303,   290,   290,   263,   384,   384,
     287,   287,   263,   263,   287,   290,   290,   287,   263,   263,
     283,   263,   263,   283,   263,   263,   263,   283,   263,   263,
     287,   287,   287,   287,   287,   263,   287,   287,   263,   263,
     263,   287,   263,   287,   287,   263,   287,   263,   263,   287,
     263,   287,   263,   287,   287,   287,   287,   263,   287,   287,
     263,   263,   287,   263,   263,   290,   263,   287,   287,   263,
     287,   263,   263,   287,   263,   287,   263,   287,   263,   263,
     287,   287,   265,   265,   265,   263,   265,   287,   287,   283,
     264,   265,   265,   265,   265,   265,   265,   265,   263,   265,
     265,   265,   265,   283,   263,   263,   287,   287,   287,   287,
     265,   265,   265,   265,   265,   263,   265,   265,   265,   263,
     265,   265,   265,   263,   263,   265,   263,   265,   265,   265,
     263,   263,   265,   263,   265,   265,   263,   265,   265,   265,
      12,   299,   299,   331,    43,    38,   349,   265,   290,   265,
     264,   263,   290,   263,   287,    58,   376,   371,   303,   303,
     361,   265,   265,   287,   287,   287,   263,   263,   263,   287,
     287,   295,   287,   287,   295,   290,   290,   290,   295,   290,
     287,   263,   263,   263,   263,   290,   263,   263,   287,   290,
     290,   263,   287,   263,   263,   290,   290,   287,   290,   263,
     287,   263,   290,   263,   263,   263,   263,   287,   263,   263,
     287,   290,   287,   263,   290,   290,   290,   263,   263,   290,
     287,   287,   263,   287,   290,   263,   287,   263,   287,   287,
      75,    75,   290,    75,   263,   295,     4,     5,   318,   319,
     287,   290,   287,   290,   265,   265,   263,   290,   287,   287,
     290,   290,   287,   290,   287,   287,   290,   333,   335,    48,
     356,    60,    61,   265,    58,   290,   287,   265,   290,   265,
     264,   382,   360,   265,   265,   360,   263,   287,   287,   287,
     263,   283,   263,   263,   263,   283,   263,   263,   287,   290,
     290,   287,   263,   290,   287,   263,   287,   263,   287,   290,
     263,   263,   287,   287,   263,   290,   290,   287,   287,   290,
     287,   263,   290,   263,   263,   263,   290,   287,   263,   263,
     287,   263,   263,   287,   263,   287,   263,   287,   287,   265,
     287,   290,   264,   264,   263,   265,   265,   263,   287,   265,
     265,   265,   265,   265,   265,   265,   265,   265,    13,   326,
     270,   270,   290,    47,   355,   264,   264,   263,   265,    60,
      61,   372,   265,    58,   377,   290,   360,   287,   287,   295,
     290,   287,   290,   295,   290,   287,   263,   263,   263,   263,
     290,   263,   263,   290,   263,   290,   263,   263,   290,   290,
     263,   263,   290,   263,   263,   263,   263,   290,   263,   290,
     290,   290,   263,   263,   290,   287,   287,   287,   263,   287,
     290,   263,   287,    75,   265,   265,   319,   310,   290,   290,
     323,    46,   359,   270,   350,   287,   290,   290,   378,   264,
     382,   373,   264,   382,   263,   263,   263,   263,   263,   263,
     263,   287,   287,   287,   287,   263,   287,   287,   263,   290,
     287,   290,   263,   287,   290,   290,   287,   287,   287,   287,
     263,   263,   263,   287,   287,   263,   287,   263,   263,   287,
     287,   270,   265,   270,   357,    14,    16,    18,    41,    44,
      49,   351,   263,   265,   263,   265,   382,   287,   360,   382,
     290,   360,   290,   287,   287,   290,   287,   287,   287,   263,
     290,   290,   263,   263,   263,   290,   263,   263,   290,   287,
     290,   263,   287,   287,   287,   263,    25,    44,   311,   324,
     270,   287,   290,   360,   263,   265,   360,   263,   265,   263,
     287,   290,   287,   290,   287,   287,   263,   287,   263,   287,
      14,    16,    18,    41,    44,    49,   325,   358,   265,   265,
     287,   379,   290,   374,   287,   263,   263,   290,   287,     4,
     327,   356,   265,   382,   265,   382,   287,   287,   263,   380,
     360,   375,   360,   263,   287,   382,   382,   287,   360,   360
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   267,   268,   268,   268,   268,   268,   269,   270,   271,
     272,   270,   273,   273,   273,   273,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   275,   274,   276,   274,   274,   274,   274,   274,   274,
     274,   277,   274,   278,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   279,   274,   280,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   281,   281,   281,   281,   281,   282,
     282,   282,   282,   282,   282,   283,   283,   284,   284,   284,
     284,   284,   285,   285,   286,   286,   287,   287,   287,   287,
     287,   287,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   289,   289,   291,   290,   292,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   293,   294,   295,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   297,   297,   297,
     298,   298,   298,   298,   299,   299,   300,   300,   300,   300,
     301,   302,   304,   303,   305,   305,   305,   306,   306,   308,
     309,   310,   307,   311,   311,   312,   312,   313,   313,   313,
     313,   314,   314,   315,   315,   315,   315,   316,   316,   317,
     317,   317,   317,   318,   318,   318,   319,   319,   319,   319,
     321,   322,   323,   324,   320,   325,   325,   325,   325,   325,
     325,   326,   326,   327,   327,   329,   328,   330,   330,   331,
     331,   332,   333,   332,   334,   335,   334,   337,   336,   338,
     338,   338,   338,   338,   338,   340,   341,   339,   342,   342,
     344,   343,   345,   345,   345,   345,   345,   345,   347,   348,
     349,   350,   346,   351,   351,   351,   351,   351,   351,   353,
     352,   354,   354,   355,   355,   356,   357,   358,   356,   359,
     359,   360,   361,   360,   362,   362,   362,   362,   363,   363,
     364,   364,   364,   364,   365,   365,   365,   365,   366,   366,
     366,   366,   366,   367,   367,   367,   369,   368,   370,   368,
     371,   368,   372,   368,   373,   368,   374,   368,   375,   368,
     376,   368,   377,   368,   378,   368,   379,   368,   380,   368,
     381,   368,   382,   382,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   384,   384,
     385,   385,   386,   386
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     3,     3,     3,     2,     1,     0,
       0,     5,     1,     2,     1,     2,     0,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     0,     3,     0,     3,     1,     1,     2,     2,     3,
       3,     0,     5,     0,     5,     2,     1,     2,     1,     2,
       2,     2,     3,     4,     4,     0,     3,     0,     4,     6,
       2,     6,     2,     2,     2,     1,     2,     1,     2,     2,
       2,     5,     7,     3,     2,     3,     4,     5,     3,     2,
       4,     3,     8,     6,     6,     2,     2,     5,     7,     4,
       6,     5,     2,     2,     2,     9,     3,     7,     8,     3,
       3,     5,    11,     7,     5,     7,     7,    11,     7,     9,
      13,    11,     9,    11,     3,     6,     4,     6,     3,     3,
       3,     3,    10,    10,     5,    10,     5,     8,     5,    10,
      12,     5,     5,     3,    10,     5,     5,     3,    11,    14,
      16,     7,     7,    11,     5,     6,     7,     9,    12,     9,
      14,     5,     7,     7,    11,     4,    10,     5,     5,     5,
      12,     7,    12,     7,     9,    10,     5,     8,     8,    10,
       5,     7,     5,     5,     5,     3,     3,    10,     5,     5,
       5,     3,    10,     5,     9,     7,     5,     5,     7,     5,
       3,     5,     5,     3,    12,    15,    11,     5,     6,     5,
       3,    11,    10,     5,     6,     9,     8,     7,     9,    10,
       9,    11,    12,    13,    11,     3,     9,     5,     6,     7,
       3,    11,     2,     3,     2,     2,     1,     1,     3,     4,
       4,     4,     4,     4,     4,     1,     1,     2,     1,     2,
       2,     8,     6,     6,     0,     1,     1,     2,     2,     3,
      10,     8,     8,     8,     3,     1,     1,     6,     4,     4,
       6,     6,     4,     6,     1,     4,     1,     1,     1,     1,
       3,     3,     6,     6,     8,     6,     4,     6,     8,     4,
       1,     3,     4,     4,     4,     4,     4,     4,     4,     6,
       8,     4,     4,     4,     4,     4,     6,     1,     3,     1,
       3,     4,     3,     3,     6,     8,     3,     3,     5,     5,
       5,     7,     3,     4,     5,     2,     1,     3,     3,     7,
       6,     6,     4,     6,     4,     6,    10,     4,     4,     4,
       8,     6,     4,     3,     3,     0,     4,     0,     4,     2,
       3,     3,     3,     3,     3,     3,     3,     4,     6,     1,
       4,     4,     6,     6,     1,     1,     3,     3,     3,     3,
       3,     2,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     4,     4,     4,     4,     4,     4,
       6,     4,     4,     6,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     4,     3,     6,     6,     4,     4,
       4,     4,     6,     6,     8,     6,     8,     4,     4,     4,
       8,     4,     4,     4,     4,     1,     3,     4,     1,     3,
       4,     1,     3,     4,     1,     3,     6,     6,     4,     6,
       6,     6,     4,     8,     6,     8,     6,     4,     4,     4,
       6,     6,     6,     8,     4,     2,     5,     7,     5,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     4,     3,
       5,     5,     3,     3,     5,     7,     4,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     4,     6,     4,     6,
       4,     4,     0,     2,     0,     1,     3,     1,     1,     0,
       0,     0,    11,     1,     1,     1,     1,     0,     1,     1,
       2,     1,     3,     1,     1,     4,     4,     1,     3,     1,
       1,     4,     4,     0,     1,     3,     1,     1,     3,     3,
       0,     0,     0,     0,    14,     1,     1,     1,     1,     1,
       1,     0,     2,     0,     1,     0,     7,     1,     2,     1,
       1,     0,     0,     5,     0,     0,     4,     0,     4,     1,
       1,     1,     1,     1,     1,     0,     0,     6,     1,     1,
       0,     4,     1,     2,     1,     1,     1,     1,     0,     0,
       0,     0,    11,     1,     1,     1,     1,     1,     1,     0,
       5,     1,     1,     0,     2,     0,     0,     0,     7,     0,
       1,     1,     0,     4,     1,     4,     1,     4,     1,     3,
       1,     4,     1,     4,     1,     1,     3,     3,     0,     2,
       4,     1,     3,     0,     2,     6,     0,     4,     0,     4,
       0,     6,     0,     9,     0,    10,     0,    13,     0,    15,
       0,     7,     0,     9,     0,    10,     0,    13,     0,    15,
       0,     3,     0,     1,     0,     2,     2,     4,     1,     4,
       6,     6,     7,    10,    12,     7,    10,    12,     2,     1,
       1,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* program_or_expression: tSTART_EXPRESSION expression tEOPROG  */
                                         {YYACCEPT;}
    break;

  case 4: /* program_or_expression: tSTART_STRING_EXPRESSION string_expression tEOPROG  */
                                                       {YYACCEPT;}
    break;

  case 5: /* program_or_expression: tSTART_ASSIGNMENT assignment tEOPROG  */
                                         {YYACCEPT;}
    break;

  case 6: /* program_or_expression: tSTART_FUNCTION_DEFINITION function_definition tEOPROG  */
                                                           {YYACCEPT;}
    break;

  case 7: /* program: statement_list tEOPROG  */
                                {YYACCEPT;}
    break;

  case 9: /* $@1: %empty  */
                   {if (severity_so_far >= sERROR) {YYABORT;}}
    break;

  case 10: /* $@2: %empty  */
                                                                    {if (in_short_if > 0 && (yyvsp[0].nnl) > 0) lyyerror(sERROR,"short if-statement (i.e. without 'then' and ended by newline) does not contain any statements");}
    break;

  case 18: /* statement: tIMPORT  */
            {report_if_missing("can not import a library in a loop or an if-statement",FALSE);}
    break;

  case 19: /* statement: tERROR string_expression  */
                             {add_command(cERROR);}
    break;

  case 25: /* statement: tBREAK  */
           {add_command(cPOP_MULTI);create_mybreak(1);if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}
    break;

  case 26: /* statement: tBREAK tDIGITS  */
                   {add_command(cPOP_MULTI);create_mybreak(atoi((yyvsp[0].digits)));if (!loop_nesting && !switch_nesting) lyyerror(sERROR,"break outside loop or switch");}
    break;

  case 27: /* statement: tCONTINUE  */
              {add_command(cPOP_MULTI);add_command_with_switch_state(cCONTINUE);if (!loop_nesting) lyyerror(sERROR,"continue outside loop");}
    break;

  case 29: /* statement: function_or_array  */
                      {create_call((yyvsp[0].symbol));add_command(cPOP);}
    break;

  case 30: /* statement: stringfunction_or_array  */
                            {create_call((yyvsp[0].symbol));add_command(cPOP);}
    break;

  case 31: /* $@3: %empty  */
           {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'local' outside functions");}
    break;

  case 33: /* $@4: %empty  */
            {if (function_type==ftNONE) lyyerror(sERROR,"no use for 'static' outside functions");}
    break;

  case 37: /* statement: tGOTO symbol_or_lineno  */
                           {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 38: /* statement: tGOSUB symbol_or_lineno  */
                            {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 39: /* statement: tON tINTERRUPT tBREAK  */
                          {create_exception(TRUE);}
    break;

  case 40: /* statement: tON tINTERRUPT tCONTINUE  */
                             {create_exception(FALSE);}
    break;

  case 41: /* $@5: %empty  */
                         {add_command(cSKIPPER);}
    break;

  case 42: /* statement: tON expression tGOTO $@5 goto_list  */
              {add_command(cNOP);}
    break;

  case 43: /* $@6: %empty  */
                          {add_command(cSKIPPER);}
    break;

  case 44: /* statement: tON expression tGOSUB $@6 gosub_list  */
               {add_command(cNOP);}
    break;

  case 45: /* statement: tLABEL symbol_or_lineno  */
                            {create_label((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol),cLABEL);}
    break;

  case 46: /* statement: open_clause  */
                {add_command(cCHECKOPEN);}
    break;

  case 47: /* statement: tCLOSE hashed_number  */
                         {add_command(cCLOSE);}
    break;

  case 48: /* statement: seek_clause  */
                {add_command(cCHECKSEEK);}
    break;

  case 49: /* statement: tCOMPILE string_expression  */
                               {add_command(cCOMPILE);}
    break;

  case 50: /* statement: tEXECUTE call_list  */
                       {create_execute(0);add_command(cPOP);add_command(cPOP);}
    break;

  case 51: /* statement: tEXECUTE2 call_list  */
                        {create_execute(1);add_command(cPOP);add_command(cPOP);}
    break;

  case 52: /* statement: tPRINT printintro printlist  */
                                {create_colour(0);create_print('n');create_pps(cPOPSTREAM,0);}
    break;

  case 53: /* statement: tPRINT printintro printlist ';'  */
                                    {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 54: /* statement: tPRINT printintro printlist ','  */
                                    {create_colour(0);create_print('t');create_pps(cPOPSTREAM,0);}
    break;

  case 55: /* $@7: %empty  */
           {tileol=FALSE;}
    break;

  case 57: /* $@8: %empty  */
                 {tileol=TRUE;}
    break;

  case 59: /* statement: tCOLOUR expression ',' expression ',' expression  */
                                                     {add_command(cGCOLOUR);}
    break;

  case 60: /* statement: tCOLOUR string_expression  */
                              {add_command(cGCOLOUR2);}
    break;

  case 61: /* statement: tBACKCOLOUR expression ',' expression ',' expression  */
                                                         {add_command(cGBACKCOLOUR);}
    break;

  case 62: /* statement: tBACKCOLOUR string_expression  */
                                  {add_command(cGBACKCOLOUR2);}
    break;

  case 65: /* statement: tRESTORE  */
             {create_restore("");}
    break;

  case 66: /* statement: tRESTORE symbol_or_lineno  */
                              {create_restore((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));}
    break;

  case 67: /* statement: tRETURN  */
            {if (function_type!=ftNONE) {
	       add_command(cCLEARSYMREFS);end_symref_chain();
	       add_command(cPOPSYMLIST);
               create_check_return_value(ftNONE,function_type);
               add_command(cRETURN_FROM_CALL);
             } else {
               add_command(cRETURN_FROM_GOSUB);
            }}
    break;

  case 68: /* statement: tRETURN expression  */
                       {if (function_type==ftNONE) {lyyerror(sERROR,"a value can only be returned from a subroutine"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNUMBER,function_type);add_command(cRETURN_FROM_CALL);}
    break;

  case 69: /* statement: tRETURN string_expression  */
                              {if (function_type==ftNONE) {lyyerror(sERROR,"can not return value"); YYABORT;} add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftSTRING,function_type);add_command(cRETURN_FROM_CALL);}
    break;

  case 71: /* statement: tOPEN tWINDOW expression ',' expression  */
                                            {create_openwin(FALSE);}
    break;

  case 72: /* statement: tOPEN tWINDOW expression ',' expression ',' string_expression  */
         {create_openwin(TRUE);}
    break;

  case 73: /* statement: tWINDOW tORIGIN string_expression  */
                                      {add_command(cMOVEORIGIN);}
    break;

  case 74: /* statement: tDOT coordinates  */
                     {add_command(cDOT);}
    break;

  case 75: /* statement: tCLEAR tDOT coordinates  */
                            {add_command(cDOT);putindrawmode(dmCLEAR);}
    break;

  case 76: /* statement: tLINE coordinates to coordinates  */
                                     {create_line(2);}
    break;

  case 77: /* statement: tCLEAR tLINE coordinates to coordinates  */
                                            {create_line(2);putindrawmode(dmCLEAR);}
    break;

  case 78: /* statement: tLINE tTO coordinates  */
                          {create_line(1);}
    break;

  case 79: /* statement: tLINE coordinates  */
                      {create_line(1);}
    break;

  case 80: /* statement: tCLEAR tLINE tTO coordinates  */
                                 {create_line(1);putindrawmode(dmCLEAR);}
    break;

  case 81: /* statement: tCLEAR tLINE coordinates  */
                             {create_line(1);putindrawmode(dmCLEAR);}
    break;

  case 82: /* statement: tPUTBIT string_expression to expression ',' expression ',' string_expression  */
                                                                                 {add_command(cPUTBIT);}
    break;

  case 83: /* statement: tPUTBIT string_expression to expression ',' expression  */
                                                           {create_pushstr("solid"); add_command(cPUTBIT);}
    break;

  case 84: /* statement: tPUTCHAR string_expression to expression ',' expression  */
                                                            {add_command(cPUTCHAR);}
    break;

  case 85: /* statement: tNEW tCURVE  */
                {create_line(-1);}
    break;

  case 86: /* statement: tCLOSE tCURVE  */
                  {create_line(0);}
    break;

  case 87: /* statement: clear_fill_clause tCIRCLE coordinates ',' expression  */
                                                         {add_command(cCIRCLE);putindrawmode(0);}
    break;

  case 88: /* statement: clear_fill_clause tTRIANGLE coordinates to coordinates to coordinates  */
                                                                          {add_command(cTRIANGLE);putindrawmode(0);}
    break;

  case 89: /* statement: tTEXT coordinates ',' string_expression  */
                                            {add_command(cTEXT1);}
    break;

  case 90: /* statement: tTEXT coordinates ',' string_expression ',' string_expression  */
                                                                  {add_command(cTEXT2);}
    break;

  case 91: /* statement: clear_fill_clause tRECT coordinates to coordinates  */
                                                       {add_command(cRECT);putindrawmode(0);}
    break;

  case 92: /* statement: tCLOSE tWINDOW  */
                   {add_command(cCLOSEWIN);}
    break;

  case 93: /* statement: tCLEAR tWINDOW  */
                   {add_command(cCLEARWIN);}
    break;

  case 94: /* statement: tCLEAR tSCREEN  */
                   {add_command(cCLEARSCR);}
    break;

  case 95: /* statement: tWINDOW tOPEN coordinates to coordinates ',' string_expression ',' string_expression  */
                                                                                         {add_command(cYABOPENWIN);}
    break;

  case 96: /* statement: tWINDOW tCLOSE string_expression  */
                                     {add_command(cYABCLOSEWIN);}
    break;

  case 97: /* statement: tWINDOW tSET string_expression ',' string_expression ',' string_expression  */
                                                                               {add_command(cYABWINSET);}
    break;

  case 98: /* statement: tVIEW coordinates to coordinates ',' string_expression ',' string_expression  */
                                                                                 {add_command(cYABVIEW);}
    break;

  case 99: /* statement: tVIEW tREMOVE string_expression  */
                                    {add_command(cYABVIEWREMOVE);}
    break;

  case 100: /* statement: tVIEW tDROPZONE string_expression  */
                                      {add_command(cYABVIEWDROPZONE);}
    break;

  case 101: /* statement: tDRAW tSET string_expression ',' string_expression  */
                                                       {add_command(cYABDRAWSETTEXT);}
    break;

  case 102: /* statement: tDRAW tSET string_expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                    {add_command(cYABDRAWSETCOLOUR);}
    break;

  case 103: /* statement: tDRAW tTEXT coordinates ',' string_expression ',' string_expression  */
                                                                        {add_command(cYABDRAWTEXT);}
    break;

  case 104: /* statement: tDRAW tDOT coordinates ',' string_expression  */
                                                 {add_command(cYABDRAWDOT);}
    break;

  case 105: /* statement: tDRAW tLINE coordinates to coordinates ',' string_expression  */
                                                                 {add_command(cYABDRAWLINE);}
    break;

  case 106: /* statement: tDRAW tRECT coordinates to coordinates ',' string_expression  */
                                                                 {add_command(cYABDRAWRECT);}
    break;

  case 107: /* statement: tDRAW tROUNDRECT coordinates to coordinates ',' expression ',' expression ',' string_expression  */
                                                                                                    {add_command(cYABDRAWROUNDRECT);}
    break;

  case 108: /* statement: tDRAW tCIRCLE coordinates ',' expression ',' string_expression  */
                                                                   {add_command(cYABDRAWCIRCLE);}
    break;

  case 109: /* statement: tDRAW tELLIPSE coordinates ',' expression ',' expression ',' string_expression  */
                                                                                   {add_command(cYABDRAWELLIPSE);}
    break;

  case 110: /* statement: tDRAW tARC coordinates ',' expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                             {add_command(cYABDRAWARC);}
    break;

  case 111: /* statement: tDRAW tCURVE coordinates to coordinates to coordinates to coordinates ',' string_expression  */
                                                                                                {add_command(cYABDRAWCURVE);}
    break;

  case 112: /* statement: tDRAW tTRIANGLE coordinates to coordinates to coordinates ',' string_expression  */
                                                                                    {add_command(cYABDRAWTRIANGLE);}
    break;

  case 113: /* statement: tDRAW tPOLYGON coordinates to coordinates to coordinates to coordinates ',' string_expression  */
                                                                                                  {add_command(cYABDRAWPOLYGON);}
    break;

  case 114: /* statement: tDRAW tFLUSH string_expression  */
                                   {add_command(cYABDRAWFLUSH);}
    break;

  case 115: /* statement: tSCREENSHOT coordinates to coordinates ',' string_expression  */
                                                                 {add_command(cYABSCREENSHOT);}
    break;

  case 116: /* statement: tLAYOUT string_expression ',' string_expression  */
                                                    {add_command(cYABLAYOUT);}
    break;

  case 117: /* statement: tALERT string_expression ',' string_expression ',' string_expression  */
                                                                         {add_command(cYABALERT);}
    break;

  case 118: /* statement: tSOUND tSTOP expression  */
                            {add_command(cYABSOUNDSTOP);}
    break;

  case 119: /* statement: tSOUND tWAIT expression  */
                            {add_command(cYABSOUNDWAIT);}
    break;

  case 120: /* statement: tMEDIASOUND tSTOP expression  */
                                 {add_command(cYABMEDIASOUNDSTOP);}
    break;

  case 121: /* statement: tLOUDNESS tSET expression  */
                              {add_command(cYABLOUDNESSSET);}
    break;

  case 122: /* statement: tBUTTON coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                         {add_command(cYABBUTTON);}
    break;

  case 123: /* statement: tCHECKBOX coordinates ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                           {add_command(cYABCHECKBOX);}
    break;

  case 124: /* statement: tCHECKBOX tSET string_expression ',' expression  */
                                                    {add_command(cYABCHECKBOXSET);}
    break;

  case 125: /* statement: tRADIOBUTTON coordinates ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                              {add_command(cYABRADIOBUTTON);}
    break;

  case 126: /* statement: tRADIOBUTTON tSET string_expression ',' expression  */
                                                       {add_command(cYABRADIOSET);}
    break;

  case 127: /* statement: tTEXT coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                        {add_command(cYABTEXT);}
    break;

  case 128: /* statement: tTEXT tSET string_expression ',' string_expression  */
                                                       {add_command(cYABTEXTALIGN);}
    break;

  case 129: /* statement: tTEXTURL coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                 {add_command(cYABTEXTURL);}
    break;

  case 130: /* statement: tTEXTCONTROL coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                    {add_command(cYABTEXTCONTROL);}
    break;

  case 131: /* statement: tTEXTCONTROL tSET string_expression ',' string_expression  */
                                                              {add_command(cYABTEXTCONTROLSET);}
    break;

  case 132: /* statement: tTEXTCONTROL tSET string_expression ',' expression  */
                                                       {add_command(cYABTEXTCONTROLMASK);}
    break;

  case 133: /* statement: tTEXTCONTROL tCLEAR string_expression  */
                                          {add_command(cYABTEXTCONTROLCLEAR);}
    break;

  case 134: /* statement: tTEXTEDIT coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                    {add_command(cYABTEXTEDIT);}
    break;

  case 135: /* statement: tTEXTEDIT tADD string_expression ',' string_expression  */
                                                           {add_command(cYABTEXTEDITADD);}
    break;

  case 136: /* statement: tTEXTEDIT tSET string_expression ',' string_expression  */
                                                           {add_command(cYABTEXTEDITSET);}
    break;

  case 137: /* statement: tTEXTEDIT tCLEAR string_expression  */
                                       {add_command(cYABTEXTEDITCLEAR);}
    break;

  case 138: /* statement: tTEXTEDIT tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                           {add_command(cYABTEXTEDITCOLOUR);}
    break;

  case 139: /* statement: tSLIDER coordinates to coordinates ',' string_expression ',' string_expression ',' expression ',' expression ',' string_expression  */
                                                                                                                                       {add_command(cYABSLIDER);}
    break;

  case 140: /* statement: tSLIDER coordinates to coordinates ',' string_expression ',' string_expression ',' expression ',' expression ',' string_expression ',' string_expression  */
                                                                                                                                                             {add_command(cYABSLIDEROPT);}
    break;

  case 141: /* statement: tSLIDER tLABEL string_expression ',' string_expression ',' string_expression  */
                                                                                 {add_command(cYABSLIDERLABEL);}
    break;

  case 142: /* statement: tSLIDER tSET string_expression ',' string_expression ',' expression  */
                                                                        {add_command(cYABSLIDERMARKS);}
    break;

  case 143: /* statement: tSLIDER tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                         {add_command(cYABSLIDERCOLOUR);}
    break;

  case 144: /* statement: tSLIDER tSET string_expression ',' expression  */
                                                  {add_command(cYABSLIDERSET);}
    break;

  case 145: /* statement: tSCROLLBAR string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cYABSCROLLBAR);}
    break;

  case 146: /* statement: tSCROLLBAR tSET string_expression ',' string_expression ',' expression  */
                                                                           {add_command(cYABSCROLLBARSET);}
    break;

  case 147: /* statement: tSCROLLBAR tSET string_expression ',' string_expression ',' expression ',' expression  */
                                                                                          {add_command(cYABSCROLLBARRANGE);}
    break;

  case 148: /* statement: tSTATUSBAR coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                  {add_command(cYABSTATUSBAR);}
    break;

  case 149: /* statement: tSTATUSBAR tSET string_expression ',' string_expression ',' string_expression ',' expression  */
                                                                                                 {add_command(cYABSTATUSBARSET);}
    break;

  case 150: /* statement: tSPINCONTROL coordinates ',' string_expression ',' string_expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                                                            {add_command(cYABSPINCONTROL);}
    break;

  case 151: /* statement: tSPINCONTROL tSET string_expression ',' expression  */
                                                       {add_command(cYABSPINCONTROLSET);}
    break;

  case 152: /* statement: tOPTION tSET string_expression ',' string_expression ',' string_expression  */
                                                                               {add_command(cYABOPTIONTEXT);}
    break;

  case 153: /* statement: tOPTION tSET string_expression ',' string_expression ',' expression  */
                                                                        {add_command(cYABOPTIONNUMBER);}
    break;

  case 154: /* statement: tOPTION tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                         {add_command(cYABOPTIONCOLOUR);}
    break;

  case 155: /* statement: tTOOLTIP string_expression ',' string_expression  */
                                                     {add_command(cYABTOOLTIP);}
    break;

  case 156: /* statement: tTABVIEW coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                          {add_command(cYABTABVIEW);}
    break;

  case 157: /* statement: tTABVIEW tADD string_expression ',' string_expression  */
                                                          {add_command(cYABTABADD);}
    break;

  case 158: /* statement: tTABVIEW tSET string_expression ',' expression  */
                                                   {add_command(cYABTABSET);}
    break;

  case 159: /* statement: tTABVIEW tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABTABREMOVE);}
    break;

  case 160: /* statement: tBOXVIEW coordinates to coordinates ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                                         {add_command(cYABBOXVIEW);}
    break;

  case 161: /* statement: tBOXVIEW tSET string_expression ',' string_expression ',' string_expression  */
                                                                                {add_command(cYABBOXVIEWSET);}
    break;

  case 162: /* statement: tSPLITVIEW coordinates to coordinates ',' string_expression ',' expression ',' expression ',' string_expression  */
                                                                                                                    {add_command(cYABSPLITVIEW);}
    break;

  case 163: /* statement: tSPLITVIEW tSET string_expression ',' string_expression ',' expression  */
                                                                           {add_command(cYABSPLITVIEWSET);}
    break;

  case 164: /* statement: tSPLITVIEW tSET string_expression ',' string_expression ',' expression ',' expression  */
                                                                                          {add_command(cYABSPLITVIEWMIN);}
    break;

  case 165: /* statement: tSTACKVIEW coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                     {add_command(cYABSTACKVIEW);}
    break;

  case 166: /* statement: tSTACKVIEW tSET string_expression ',' expression  */
                                                     {add_command(cYABSTACKVIEWSET);}
    break;

  case 167: /* statement: tCANVAS coordinates to coordinates ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABCANVAS);}
    break;

  case 168: /* statement: tREGION coordinates to coordinates ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABREGION);}
    break;

  case 169: /* statement: tLISTBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                   {add_command(cYABLISTBOX);}
    break;

  case 170: /* statement: tLISTBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABLISTBOXADD);}
    break;

  case 171: /* statement: tLISTBOX tADD string_expression ',' expression ',' string_expression  */
                                                                         {add_command(cYABLISTBOXADD2);}
    break;

  case 172: /* statement: tLISTBOX tREMOVE string_expression ',' string_expression  */
                                                             {add_command(cYABLISTBOXREMOVE);}
    break;

  case 173: /* statement: tLISTBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABLISTBOXREMOVE2);}
    break;

  case 174: /* statement: tLISTBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABLISTBOXSELECT);}
    break;

  case 175: /* statement: tLISTBOX tCLEAR string_expression  */
                                      {add_command(cYABLISTBOXCLEAR);}
    break;

  case 176: /* statement: tLISTBOX tSORT string_expression  */
                                     {add_command(cYABLISTSORT);}
    break;

  case 177: /* statement: tDROPBOX coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                          {add_command(cYABDROPBOX);}
    break;

  case 178: /* statement: tDROPBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABDROPBOXADD);}
    break;

  case 179: /* statement: tDROPBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABDROPBOXSELECT);}
    break;

  case 180: /* statement: tDROPBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABDROPBOXREMOVE);}
    break;

  case 181: /* statement: tDROPBOX tCLEAR string_expression  */
                                      {add_command(cYABDROPBOXCLEAR);}
    break;

  case 182: /* statement: tTREEBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                   {add_command(cYABTREEBOX);}
    break;

  case 183: /* statement: tTREEBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABTREEADD);}
    break;

  case 184: /* statement: tTREEBOX tADD string_expression ',' string_expression ',' string_expression ',' expression  */
                                                                                               {add_command(cYABTREEADDCHILD);}
    break;

  case 185: /* statement: tTREEBOX tADD string_expression ',' string_expression ',' expression  */
                                                                         {add_command(cYABTREEADDAT);}
    break;

  case 186: /* statement: tTREEBOX tREMOVE string_expression ',' string_expression  */
                                                             {add_command(cYABTREEREMOVE);}
    break;

  case 187: /* statement: tTREEBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABTREEREMOVE2);}
    break;

  case 188: /* statement: tTREEBOX tREMOVE string_expression ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABTREEREMOVECHILD);}
    break;

  case 189: /* statement: tTREEBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABTREESELECT);}
    break;

  case 190: /* statement: tTREEBOX tCLEAR string_expression  */
                                      {add_command(cYABTREECLEAR);}
    break;

  case 191: /* statement: tTREEBOX tEXPAND string_expression ',' string_expression  */
                                                             {add_command(cYABTREEEXPAND);}
    break;

  case 192: /* statement: tTREEBOX tCOLLAPSE string_expression ',' string_expression  */
                                                               {add_command(cYABTREECOLLAPSE);}
    break;

  case 193: /* statement: tTREEBOX tSORT string_expression  */
                                     {add_command(cYABTREESORT);}
    break;

  case 194: /* statement: tCOLUMNBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression ',' string_expression  */
                                                                                                                           {add_command(cYABCOLUMNBOX);}
    break;

  case 195: /* statement: tCOLUMNBOX tCOLUMN string_expression ',' string_expression ',' expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                                                                 {add_command(cYABCOLUMNBOXCOLUMN);}
    break;

  case 196: /* statement: tCOLUMNBOX tADD string_expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                         {add_command(cYABCOLUMNBOXADD);}
    break;

  case 197: /* statement: tCOLUMNBOX tREMOVE string_expression ',' expression  */
                                                        {add_command(cYABCOLUMNBOXREMOVE);}
    break;

  case 198: /* statement: tCOLUMNBOX tREMOVE tCOLUMN string_expression ',' expression  */
                                                                {add_command(cYABCOLUMNBOXREMOVECOLUMN);}
    break;

  case 199: /* statement: tCOLUMNBOX tSELECT string_expression ',' expression  */
                                                        {add_command(cYABCOLUMNBOXSELECT);}
    break;

  case 200: /* statement: tCOLUMNBOX tCLEAR string_expression  */
                                        {add_command(cYABCOLUMNBOXCLEAR);}
    break;

  case 201: /* statement: tCOLUMNBOX tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                            {add_command(cYABCOLUMNBOXCOLOUR);}
    break;

  case 202: /* statement: tCALENDAR coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                  {add_command(cYABCALENDAR);}
    break;

  case 203: /* statement: tCALENDAR tSET string_expression ',' string_expression  */
                                                           {add_command(cYABCALENDARSET);}
    break;

  case 204: /* statement: tCOLORCONTROL coordinates ',' string_expression ',' string_expression  */
                                                                          {add_command(cYABCOLORCONTROL);}
    break;

  case 205: /* statement: tCOLORCONTROL tSET string_expression ',' expression ',' expression ',' expression  */
                                                                                      {add_command(cYABCOLORCONTROLSET);}
    break;

  case 206: /* statement: tMENU string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                              {add_command(cYABMENU);}
    break;

  case 207: /* statement: tMENU tSET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cYABMENURADIO);}
    break;

  case 208: /* statement: tMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                   {add_command(cYABMENUOPTION);}
    break;

  case 209: /* statement: tSUBMENU string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                       {add_command(cYABSUBMENU);}
    break;

  case 210: /* statement: tSUBMENU tSET string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                               {add_command(cYABSUBMENURADIO);}
    break;

  case 211: /* statement: tSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                            {add_command(cYABSUBMENUOPTION);}
    break;

  case 212: /* statement: tSUBSUBMENU string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                                {add_command(cYABSUBSUBMENU);}
    break;

  case 213: /* statement: tSUBSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                                     {add_command(cYABSUBSUBMENUOPTION);}
    break;

  case 214: /* statement: tSUBSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                                        {add_command(cYABSUBSUBMENURADIO);}
    break;

  case 215: /* statement: tCLIPBOARD tCOPY string_expression  */
                                       {add_command(cYABCLIPBOARDCOPY);}
    break;

  case 216: /* statement: tATTRIBUTE tSET string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                        {add_command(cYABATTRIBUTESET);}
    break;

  case 217: /* statement: tATTRIBUTE tCLEAR string_expression ',' string_expression  */
                                                              {add_command(cYABATTRIBUTECLEAR);}
    break;

  case 218: /* statement: tBITMAP expression ',' expression ',' string_expression  */
                                                            {add_command(cYABBITMAP);}
    break;

  case 219: /* statement: tBITMAP tGET string_expression ',' string_expression ',' string_expression  */
                                                                               {add_command(cYABBITMAPGET);}
    break;

  case 220: /* statement: tBITMAP tREMOVE string_expression  */
                                      {add_command(cYABBITMAPREMOVE);}
    break;

  case 221: /* statement: tDRAW tBITMAP expression ',' expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                              {add_command(cYABBITMAPDRAW);}
    break;

  case 222: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 223: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 224: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 225: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 226: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 227: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 228: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 229: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 230: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 231: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 232: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 233: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 234: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 235: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 236: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 237: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 238: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 239: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 240: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 241: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 242: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 243: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 244: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 245: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 246: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 247: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 248: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 249: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 250: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 251: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 252: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 253: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 254: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 257: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 258: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 259: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 260: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 261: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 262: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 263: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 264: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 265: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 266: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 268: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 269: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 270: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 272: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 273: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 274: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 275: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 276: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 277: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 278: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 279: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 280: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 281: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 282: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 283: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 284: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 285: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 286: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 287: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 288: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 289: /* string_function: tSTRING2 '(' expression ',' string_expression ')'  */
                                                      {create_function(fSTRING);}
    break;

  case 290: /* string_function: tREPLACE '(' string_expression ',' string_expression ',' string_expression ')'  */
                                                                                    {create_function(fREPLACE);}
    break;

  case 291: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 292: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 293: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 294: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 295: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 296: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 297: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 298: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 299: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 300: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 301: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 302: /* string_function: tTEXTCONTROL tGET string_expression  */
                                        {create_function(fYABTEXTCONTROLGET);}
    break;

  case 303: /* string_function: tTEXTEDIT tGET string_expression  */
                                     {create_function(fYABTEXTEDITGET);}
    break;

  case 304: /* string_function: tPOPUPMENU coordinates ',' string_expression ',' string_expression  */
                                                                                       {create_function(fYABPOPUPMENU);}
    break;

  case 305: /* string_function: tFILEPANEL string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                   {create_function(fYABFILEPANEL);}
    break;

  case 306: /* string_function: tTEXTCONTROL tGETS string_expression  */
                                                         {create_function(fYABTEXTCONTROLGET);}
    break;

  case 307: /* string_function: tTEXTEDIT tGETS string_expression  */
                                                      {create_function(fYABTEXTEDITGET);}
    break;

  case 308: /* string_function: tLISTBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABLISTBOXGET);}
    break;

  case 309: /* string_function: tDROPBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABDROPBOXGET);}
    break;

  case 310: /* string_function: tTREEBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABTREEBOXGET);}
    break;

  case 311: /* string_function: tCOLUMNBOX tGETS string_expression ',' expression ',' expression  */
                                                                                     {create_function(fYABCOLUMNBOXGET);}
    break;

  case 312: /* string_function: tCALENDAR tGET string_expression  */
                                                     {create_function(fYABCALENDARGET);}
    break;

  case 313: /* string_function: tTRANSLATE '(' string_expression ')'  */
                                         {create_function(fYABTRANSLATE);}
    break;

  case 314: /* string_function: tMENU tTRANSLATE '(' string_expression ')'  */
                                               {create_function(fYABMENUTRANSLATE);}
    break;

  case 315: /* string_function: tCLIPBOARD tPASTE  */
                      {create_function(fYABCLIPBOARDPASTE);}
    break;

  case 316: /* string_function: tMESSAGE  */
             {create_function(fYABMESSAGE);}
    break;

  case 317: /* string_function: tMOUSE tMESSAGE string_expression  */
                                                      {create_function(fYABMOUSEMESSAGE);}
    break;

  case 318: /* string_function: tKEYBOARD tMESSAGE string_expression  */
                                                         {create_function(fYABKEYBOARDMESSAGE);}
    break;

  case 319: /* string_function: tATTRIBUTE tGETS '(' string_expression ',' string_expression ')'  */
                                                                     {create_function(fYABATTRIBUTEGET);}
    break;

  case 320: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 321: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 322: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 323: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 324: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 325: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 326: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 327: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 328: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 329: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 330: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 331: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 332: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 333: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 334: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 335: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 336: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 337: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 338: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 339: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 340: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 341: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 342: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 343: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 344: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 345: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 346: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 347: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 348: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 349: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 350: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 351: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 352: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 353: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 354: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 355: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 356: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 357: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 358: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 359: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 360: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 361: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 362: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 363: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 364: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 365: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 366: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 367: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 368: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 371: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 372: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 374: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 375: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 376: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 377: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 378: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 379: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 380: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 381: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 382: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 383: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 384: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 385: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 386: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 387: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 388: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 389: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 390: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 391: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 392: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 393: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 394: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 395: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 396: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 397: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 398: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 399: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 400: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 401: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 402: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 403: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 404: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 405: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 406: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 407: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 408: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 409: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 410: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 411: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 412: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 413: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 414: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 415: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 416: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 417: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 418: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 419: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 420: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 421: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 422: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 423: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 424: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 425: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 426: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 427: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 428: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 429: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 430: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 431: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 432: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 433: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 434: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 435: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 436: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 437: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 438: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 439: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 440: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 441: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 442: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 443: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 444: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 445: /* function: tWINDOW tCOUNT  */
                   {create_function(fYABNUMWINDOWS);}
    break;

  case 446: /* function: tWINDOW tGET string_expression ',' string_expression  */
                                                         {create_function(fYABWINDOWGET);}
    break;

  case 447: /* function: tATTRIBUTE tGET '(' string_expression ',' string_expression ')'  */
                                                                    {create_function(fYABATTRIBUTEGETNUM);}
    break;

  case 448: /* function: tSOUND tPLAY string_expression ',' expression  */
                                                                  {create_function(fYABSOUNDPLAY);}
    break;

  case 449: /* function: tMEDIASOUND tPLAY string_expression  */
                                                        {create_function(fYABMEDIASOUNDPLAY);}
    break;

  case 450: /* function: tLOUDNESS tGET  */
                   {create_function(fYABLOUDNESSGET);}
    break;

  case 451: /* function: tLISTBOX tCOUNT string_expression  */
                                                      {create_function(fYABLISTBOXCOUNT);}
    break;

  case 452: /* function: tLISTBOX tGET string_expression  */
                                                    {create_function(fYABLISTBOXSELECTED);}
    break;

  case 453: /* function: tDROPBOX tCOUNT string_expression  */
                                                      {create_function(fYABDROPBOXCOUNT);}
    break;

  case 454: /* function: tDROPBOX tGET string_expression  */
                                                    {create_function(fYABDROPBOXSELECTED);}
    break;

  case 455: /* function: tTREEBOX tCOUNT string_expression  */
                                                      {create_function(fYABTREEBOXCOUNT);}
    break;

  case 456: /* function: tTREEBOX tGET string_expression  */
                                                    {create_function(fYABTREEBOXSELECTED);}
    break;

  case 457: /* function: tCOLUMNBOX tCOUNT string_expression  */
                                                        {create_function(fYABCOLUMNBOXCOUNT);}
    break;

  case 458: /* function: tCOLUMNBOX tCOUNT tCOLUMN string_expression  */
                                                                {create_function(fYABCOLUMNBOXCOUNTCOLUMNS);}
    break;

  case 459: /* function: tCOLUMNBOX tGET string_expression  */
                                                      {create_function(fYABCOLUMNBOXSELECTED);}
    break;

  case 460: /* function: tCOLORCONTROL tGET string_expression ',' string_expression  */
                                                                               {create_function(fYABCOLORCONTROLGET);}
    break;

  case 461: /* function: tSPLITVIEW tGET string_expression ',' string_expression  */
                                                                            {create_function(fYABSPLITVIEWGET);}
    break;

  case 462: /* function: tSTACKVIEW tGET string_expression  */
                                                      {create_function(fYABSTACKVIEWGET);}
    break;

  case 463: /* function: tTABVIEW tGET string_expression  */
                                                    {create_function(fYABTABVIEWGET);}
    break;

  case 464: /* function: tDRAW tGET string_expression ',' string_expression  */
                                                       {create_function(fYABDRAWGET);}
    break;

  case 465: /* function: tDRAW tGET string_expression ',' string_expression ',' string_expression  */
                                                                             {create_function(fYABDRAWGETTEXT);}
    break;

  case 466: /* function: tBFILESIZE '(' string_expression ')'  */
                                         {create_function(fYABBFILESIZE);}
    break;

  case 467: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 468: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 469: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 470: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 471: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 472: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 473: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 474: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 475: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 476: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 477: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 478: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 479: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 480: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 481: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 482: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 489: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 490: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 491: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 492: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 493: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 494: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 495: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 496: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 497: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 498: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 499: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 500: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 503: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 504: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 505: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 506: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 509: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 510: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 511: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 512: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 516: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 517: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 518: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 519: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 520: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 521: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 522: /* $@17: %empty  */
                    { /* pushes another expression */
	     add_command(cSKIPONCE);
	     pushlabel();
	     add_command(cSTARTFOR);
	     add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     poplabel();

	     add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cSKIPONCE);
	     add_command(cFORINCREMENT);
	     add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[-6].symbol),FALSE),NULL);
	     add_command(cFORCHECK);
	     add_command(cDECIDE);
             pushlabel();}
    break;

  case 523: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 524: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 525: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 526: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 527: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 528: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 529: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 530: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 531: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 533: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 534: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 535: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 536: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 542: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 543: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 545: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 547: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 549: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 550: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 551: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 552: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 553: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 554: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 555: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 556: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 558: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 559: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 560: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 562: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 563: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 564: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 565: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 566: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 567: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 568: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 569: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 570: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 571: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 573: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 574: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 575: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 576: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 577: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 578: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 579: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 581: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 582: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 586: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 587: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 592: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 594: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 595: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 596: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 597: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 600: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 601: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 602: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 603: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 604: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 605: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 606: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 607: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 611: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 612: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 613: /* using: %empty  */
       {create_print('d');}
    break;

  case 614: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 615: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 616: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 617: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 618: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 619: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 620: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 621: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 622: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 623: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 624: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 625: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 626: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 627: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 628: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 629: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 630: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 631: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 632: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 633: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 634: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 635: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 636: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 637: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 638: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 639: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 640: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 641: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 642: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 643: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 644: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 645: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 646: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 647: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 648: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 649: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 650: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 651: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 652: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 653: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 654: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 655: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 656: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 657: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 660: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 661: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 662: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 663: /* gosub_list: gosub_list ',' symbol_or_lineno  */
                                    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

