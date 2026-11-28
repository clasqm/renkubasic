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
  YYSYMBOL_tTREEBOX = 146,                 /* tTREEBOX  */
  YYSYMBOL_tCOLUMNBOX = 147,               /* tCOLUMNBOX  */
  YYSYMBOL_tCALENDAR = 148,                /* tCALENDAR  */
  YYSYMBOL_tCOLORCONTROL = 149,            /* tCOLORCONTROL  */
  YYSYMBOL_tCOLUMN = 150,                  /* tCOLUMN  */
  YYSYMBOL_tSORT = 151,                    /* tSORT  */
  YYSYMBOL_tEXPAND = 152,                  /* tEXPAND  */
  YYSYMBOL_tCOLLAPSE = 153,                /* tCOLLAPSE  */
  YYSYMBOL_tSELECT = 154,                  /* tSELECT  */
  YYSYMBOL_tGETS = 155,                    /* tGETS  */
  YYSYMBOL_tMENU = 156,                    /* tMENU  */
  YYSYMBOL_tSUBMENU = 157,                 /* tSUBMENU  */
  YYSYMBOL_tSUBSUBMENU = 158,              /* tSUBSUBMENU  */
  YYSYMBOL_tCLIPBOARD = 159,               /* tCLIPBOARD  */
  YYSYMBOL_tCOPY = 160,                    /* tCOPY  */
  YYSYMBOL_tPASTE = 161,                   /* tPASTE  */
  YYSYMBOL_tTRANSLATE = 162,               /* tTRANSLATE  */
  YYSYMBOL_tMESSAGE = 163,                 /* tMESSAGE  */
  YYSYMBOL_tATTRIBUTE = 164,               /* tATTRIBUTE  */
  YYSYMBOL_tBITMAP = 165,                  /* tBITMAP  */
  YYSYMBOL_tALERT = 166,                   /* tALERT  */
  YYSYMBOL_tFILEPANEL = 167,               /* tFILEPANEL  */
  YYSYMBOL_tPOPUPMENU = 168,               /* tPOPUPMENU  */
  YYSYMBOL_tSOUND = 169,                   /* tSOUND  */
  YYSYMBOL_tMEDIASOUND = 170,              /* tMEDIASOUND  */
  YYSYMBOL_tLOUDNESS = 171,                /* tLOUDNESS  */
  YYSYMBOL_tPLAY = 172,                    /* tPLAY  */
  YYSYMBOL_tSTOP = 173,                    /* tSTOP  */
  YYSYMBOL_tSIN = 174,                     /* tSIN  */
  YYSYMBOL_tASIN = 175,                    /* tASIN  */
  YYSYMBOL_tCOS = 176,                     /* tCOS  */
  YYSYMBOL_tACOS = 177,                    /* tACOS  */
  YYSYMBOL_tTAN = 178,                     /* tTAN  */
  YYSYMBOL_tATAN = 179,                    /* tATAN  */
  YYSYMBOL_tEXP = 180,                     /* tEXP  */
  YYSYMBOL_tLOG = 181,                     /* tLOG  */
  YYSYMBOL_tSQRT = 182,                    /* tSQRT  */
  YYSYMBOL_tSQR = 183,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 184,                   /* tMYEOF  */
  YYSYMBOL_tABS = 185,                     /* tABS  */
  YYSYMBOL_tSIG = 186,                     /* tSIG  */
  YYSYMBOL_tINT = 187,                     /* tINT  */
  YYSYMBOL_tCEIL = 188,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 189,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 190,                    /* tFRAC  */
  YYSYMBOL_tROUND = 191,                   /* tROUND  */
  YYSYMBOL_tMOD = 192,                     /* tMOD  */
  YYSYMBOL_tRAN = 193,                     /* tRAN  */
  YYSYMBOL_tVAL = 194,                     /* tVAL  */
  YYSYMBOL_tLEFT = 195,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 196,                   /* tRIGHT  */
  YYSYMBOL_tMID = 197,                     /* tMID  */
  YYSYMBOL_tLEN = 198,                     /* tLEN  */
  YYSYMBOL_tMIN = 199,                     /* tMIN  */
  YYSYMBOL_tMAX = 200,                     /* tMAX  */
  YYSYMBOL_tSTR = 201,                     /* tSTR  */
  YYSYMBOL_tINKEY = 202,                   /* tINKEY  */
  YYSYMBOL_tCHR = 203,                     /* tCHR  */
  YYSYMBOL_tASC = 204,                     /* tASC  */
  YYSYMBOL_tHEX = 205,                     /* tHEX  */
  YYSYMBOL_tDEC = 206,                     /* tDEC  */
  YYSYMBOL_tBIN = 207,                     /* tBIN  */
  YYSYMBOL_tUPPER = 208,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 209,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 210,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 211,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 212,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 213,                /* tMOUSEMOD  */
  YYSYMBOL_tMOUSE = 214,                   /* tMOUSE  */
  YYSYMBOL_tKEYBOARD = 215,                /* tKEYBOARD  */
  YYSYMBOL_tTRIM = 216,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 217,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 218,                   /* tRTRIM  */
  YYSYMBOL_tSTRING2 = 219,                 /* tSTRING2  */
  YYSYMBOL_tREPLACE = 220,                 /* tREPLACE  */
  YYSYMBOL_tINSTR = 221,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 222,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 223,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 224,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 225,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 226,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 227,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 228,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 229,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 230,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 231,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 232,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 233,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 234,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 235,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 236,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 237,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 238,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 239,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 240,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 241,                    /* tDATE  */
  YYSYMBOL_tTIME = 242,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 243,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 244,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 245,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 246,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 247,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 248,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 249,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 250, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 251,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 252, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 253,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 254,                   /* tEVAL2  */
  YYSYMBOL_tARGUMENT = 255,                /* tARGUMENT  */
  YYSYMBOL_256_ = 256,                     /* '-'  */
  YYSYMBOL_257_ = 257,                     /* '+'  */
  YYSYMBOL_258_ = 258,                     /* '*'  */
  YYSYMBOL_259_ = 259,                     /* '/'  */
  YYSYMBOL_UMINUS = 260,                   /* UMINUS  */
  YYSYMBOL_261_ = 261,                     /* ';'  */
  YYSYMBOL_262_ = 262,                     /* ','  */
  YYSYMBOL_263_ = 263,                     /* '('  */
  YYSYMBOL_264_ = 264,                     /* ')'  */
  YYSYMBOL_265_ = 265,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 266,                 /* $accept  */
  YYSYMBOL_program_or_expression = 267,    /* program_or_expression  */
  YYSYMBOL_program = 268,                  /* program  */
  YYSYMBOL_statement_list = 269,           /* statement_list  */
  YYSYMBOL_270_1 = 270,                    /* $@1  */
  YYSYMBOL_271_2 = 271,                    /* $@2  */
  YYSYMBOL_assignment = 272,               /* assignment  */
  YYSYMBOL_statement = 273,                /* statement  */
  YYSYMBOL_274_3 = 274,                    /* $@3  */
  YYSYMBOL_275_4 = 275,                    /* $@4  */
  YYSYMBOL_276_5 = 276,                    /* $@5  */
  YYSYMBOL_277_6 = 277,                    /* $@6  */
  YYSYMBOL_278_7 = 278,                    /* $@7  */
  YYSYMBOL_279_8 = 279,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 280,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 281,        /* string_assignment  */
  YYSYMBOL_to = 282,                       /* to  */
  YYSYMBOL_open_clause = 283,              /* open_clause  */
  YYSYMBOL_seek_clause = 284,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 285,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 286,        /* string_expression  */
  YYSYMBOL_string_function = 287,          /* string_function  */
  YYSYMBOL_number_assignment = 288,        /* number_assignment  */
  YYSYMBOL_expression = 289,               /* expression  */
  YYSYMBOL_290_9 = 290,                    /* $@9  */
  YYSYMBOL_291_10 = 291,                   /* $@10  */
  YYSYMBOL_arrayref = 292,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 293,          /* string_arrayref  */
  YYSYMBOL_coordinates = 294,              /* coordinates  */
  YYSYMBOL_function = 295,                 /* function  */
  YYSYMBOL_const = 296,                    /* const  */
  YYSYMBOL_number = 297,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 298,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 299,                  /* dimlist  */
  YYSYMBOL_function_or_array = 300,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 301,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 302,                /* call_list  */
  YYSYMBOL_303_11 = 303,                   /* $@11  */
  YYSYMBOL_calls = 304,                    /* calls  */
  YYSYMBOL_call_item = 305,                /* call_item  */
  YYSYMBOL_function_definition = 306,      /* function_definition  */
  YYSYMBOL_307_12 = 307,                   /* $@12  */
  YYSYMBOL_308_13 = 308,                   /* $@13  */
  YYSYMBOL_309_14 = 309,                   /* $@14  */
  YYSYMBOL_endsub = 310,                   /* endsub  */
  YYSYMBOL_function_name = 311,            /* function_name  */
  YYSYMBOL_export = 312,                   /* export  */
  YYSYMBOL_local_list = 313,               /* local_list  */
  YYSYMBOL_local_item = 314,               /* local_item  */
  YYSYMBOL_static_list = 315,              /* static_list  */
  YYSYMBOL_static_item = 316,              /* static_item  */
  YYSYMBOL_paramlist = 317,                /* paramlist  */
  YYSYMBOL_paramitem = 318,                /* paramitem  */
  YYSYMBOL_for_loop = 319,                 /* for_loop  */
  YYSYMBOL_320_15 = 320,                   /* $@15  */
  YYSYMBOL_321_16 = 321,                   /* $@16  */
  YYSYMBOL_322_17 = 322,                   /* $@17  */
  YYSYMBOL_323_18 = 323,                   /* $@18  */
  YYSYMBOL_next = 324,                     /* next  */
  YYSYMBOL_step_part = 325,                /* step_part  */
  YYSYMBOL_next_symbol = 326,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 327,  /* switch_number_or_string  */
  YYSYMBOL_328_19 = 328,                   /* $@19  */
  YYSYMBOL_sep_list = 329,                 /* sep_list  */
  YYSYMBOL_number_or_string = 330,         /* number_or_string  */
  YYSYMBOL_case_list = 331,                /* case_list  */
  YYSYMBOL_332_20 = 332,                   /* $@20  */
  YYSYMBOL_default = 333,                  /* default  */
  YYSYMBOL_334_21 = 334,                   /* $@21  */
  YYSYMBOL_do_loop = 335,                  /* do_loop  */
  YYSYMBOL_336_22 = 336,                   /* $@22  */
  YYSYMBOL_loop = 337,                     /* loop  */
  YYSYMBOL_while_loop = 338,               /* while_loop  */
  YYSYMBOL_339_23 = 339,                   /* $@23  */
  YYSYMBOL_340_24 = 340,                   /* $@24  */
  YYSYMBOL_wend = 341,                     /* wend  */
  YYSYMBOL_repeat_loop = 342,              /* repeat_loop  */
  YYSYMBOL_343_25 = 343,                   /* $@25  */
  YYSYMBOL_until = 344,                    /* until  */
  YYSYMBOL_if_clause = 345,                /* if_clause  */
  YYSYMBOL_346_26 = 346,                   /* $@26  */
  YYSYMBOL_347_27 = 347,                   /* $@27  */
  YYSYMBOL_348_28 = 348,                   /* $@28  */
  YYSYMBOL_349_29 = 349,                   /* $@29  */
  YYSYMBOL_endif = 350,                    /* endif  */
  YYSYMBOL_short_if = 351,                 /* short_if  */
  YYSYMBOL_352_30 = 352,                   /* $@30  */
  YYSYMBOL_end_of_if = 353,                /* end_of_if  */
  YYSYMBOL_else_part = 354,                /* else_part  */
  YYSYMBOL_elsif_part = 355,               /* elsif_part  */
  YYSYMBOL_356_31 = 356,                   /* $@31  */
  YYSYMBOL_357_32 = 357,                   /* $@32  */
  YYSYMBOL_maybe_then = 358,               /* maybe_then  */
  YYSYMBOL_inputlist = 359,                /* inputlist  */
  YYSYMBOL_360_33 = 360,                   /* $@33  */
  YYSYMBOL_input = 361,                    /* input  */
  YYSYMBOL_readlist = 362,                 /* readlist  */
  YYSYMBOL_readitem = 363,                 /* readitem  */
  YYSYMBOL_datalist = 364,                 /* datalist  */
  YYSYMBOL_printlist = 365,                /* printlist  */
  YYSYMBOL_using = 366,                    /* using  */
  YYSYMBOL_inputbody = 367,                /* inputbody  */
  YYSYMBOL_368_34 = 368,                   /* $@34  */
  YYSYMBOL_369_35 = 369,                   /* $@35  */
  YYSYMBOL_370_36 = 370,                   /* $@36  */
  YYSYMBOL_371_37 = 371,                   /* $@37  */
  YYSYMBOL_372_38 = 372,                   /* $@38  */
  YYSYMBOL_373_39 = 373,                   /* $@39  */
  YYSYMBOL_374_40 = 374,                   /* $@40  */
  YYSYMBOL_375_41 = 375,                   /* $@41  */
  YYSYMBOL_376_42 = 376,                   /* $@42  */
  YYSYMBOL_377_43 = 377,                   /* $@43  */
  YYSYMBOL_378_44 = 378,                   /* $@44  */
  YYSYMBOL_379_45 = 379,                   /* $@45  */
  YYSYMBOL_380_46 = 380,                   /* $@46  */
  YYSYMBOL_prompt = 381,                   /* prompt  */
  YYSYMBOL_printintro = 382,               /* printintro  */
  YYSYMBOL_hashed_number = 383,            /* hashed_number  */
  YYSYMBOL_goto_list = 384,                /* goto_list  */
  YYSYMBOL_gosub_list = 385                /* gosub_list  */
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
#define YYLAST   16444

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  266
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  661
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2106

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   511


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
       2,     2,     2,     2,     2,   265,     2,     2,     2,     2,
     263,   264,   258,   257,   262,   256,     2,   259,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   261,
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
     255,   260
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
     365,   366,   367,   368,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   507,   508,   509,   510,   511,   515,   516,   517,
     518,   519,   520,   523,   524,   527,   528,   529,   530,   531,
     534,   535,   538,   539,   542,   543,   544,   545,   546,   547,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     582,   583,   586,   594,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,   611,   616,   617,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   634,   635,   638,   638,   639,   639,   640,   641,   642,
     643,   644,   645,   646,   647,   648,   649,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   660,   661,   662,
     663,   664,   665,   666,   667,   668,   669,   670,   671,   674,
     677,   680,   683,   684,   685,   686,   687,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   704,   705,   706,   707,   708,   709,   710,
     711,   712,   713,   714,   715,   716,   717,   718,   719,   720,
     721,   722,   723,   724,   725,   726,   727,   728,   729,   730,
     731,   732,   733,   734,   735,   736,   737,   738,   739,   740,
     741,   742,   743,   744,   745,   746,   747,   748,   749,   750,
     751,   752,   753,   756,   757,   760,   764,   765,   766,   769,
     770,   771,   772,   773,   774,   775,   776,   777,   778,   779,
     780,   781,   782,   783,   784,   787,   788,   789,   792,   793,
     794,   795,   798,   799,   802,   803,   804,   805,   808,   811,
     814,   814,   817,   818,   819,   822,   823,   826,   827,   830,
     826,   835,   836,   839,   840,   843,   844,   845,   846,   849,
     850,   853,   854,   855,   856,   859,   860,   863,   864,   865,
     866,   869,   870,   871,   874,   875,   876,   877,   880,   881,
     886,   901,   880,   906,   907,   908,   909,   910,   911,   914,
     915,   918,   919,   924,   924,   928,   929,   932,   933,   937,
     939,   938,   943,   944,   944,   948,   948,   954,   955,   956,
     957,   958,   959,   963,   964,   963,   970,   971,   975,   975,
     980,   981,   982,   983,   984,   985,   988,   989,   989,   991,
     988,   995,   996,   997,   998,   999,  1000,  1003,  1003,  1008,
    1009,  1012,  1013,  1016,  1018,  1020,  1017,  1024,  1025,  1028,
    1029,  1029,  1032,  1033,  1035,  1036,  1040,  1041,  1044,  1045,
    1047,  1048,  1052,  1053,  1054,  1055,  1058,  1059,  1060,  1061,
    1062,  1065,  1066,  1067,  1070,  1070,  1071,  1071,  1072,  1072,
    1073,  1073,  1074,  1074,  1075,  1075,  1076,  1076,  1077,  1077,
    1078,  1078,  1079,  1079,  1080,  1080,  1081,  1081,  1082,  1082,
    1085,  1086,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,  1098,  1099,  1100,  1101,  1102,  1105,  1106,  1108,  1109,
    1112,  1113
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
  "tLISTBOX", "tDROPBOX", "tTREEBOX", "tCOLUMNBOX", "tCALENDAR",
  "tCOLORCONTROL", "tCOLUMN", "tSORT", "tEXPAND", "tCOLLAPSE", "tSELECT",
  "tGETS", "tMENU", "tSUBMENU", "tSUBSUBMENU", "tCLIPBOARD", "tCOPY",
  "tPASTE", "tTRANSLATE", "tMESSAGE", "tATTRIBUTE", "tBITMAP", "tALERT",
  "tFILEPANEL", "tPOPUPMENU", "tSOUND", "tMEDIASOUND", "tLOUDNESS",
  "tPLAY", "tSTOP", "tSIN", "tASIN", "tCOS", "tACOS", "tTAN", "tATAN",
  "tEXP", "tLOG", "tSQRT", "tSQR", "tMYEOF", "tABS", "tSIG", "tINT",
  "tCEIL", "tFLOOR", "tFRAC", "tROUND", "tMOD", "tRAN", "tVAL", "tLEFT",
  "tRIGHT", "tMID", "tLEN", "tMIN", "tMAX", "tSTR", "tINKEY", "tCHR",
  "tASC", "tHEX", "tDEC", "tBIN", "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY",
  "tMOUSEB", "tMOUSEMOD", "tMOUSE", "tKEYBOARD", "tTRIM", "tLTRIM",
  "tRTRIM", "tSTRING2", "tREPLACE", "tINSTR", "tRINSTR", "tCHOMP",
  "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tFRNFN_CALL",
  "tFRNFN_CALL2", "tFRNFN_SIZE", "tFRNBF_ALLOC", "tFRNBF_FREE",
  "tFRNBF_SIZE", "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET", "tFRNBF_GET2",
  "tFRNBF_GET_BUFFER", "tFRNBF_SET_BUFFER", "tDATE", "tTIME", "tTOKEN",
  "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB", "tSTART_PROGRAM",
  "tSTART_EXPRESSION", "tSTART_STRING_EXPRESSION", "tSTART_ASSIGNMENT",
  "tSTART_FUNCTION_DEFINITION", "tEVAL", "tEVAL2", "tARGUMENT", "'-'",
  "'+'", "'*'", "'/'", "UMINUS", "';'", "','", "'('", "')'", "'#'",
  "$accept", "program_or_expression", "program", "statement_list", "$@1",
  "$@2", "assignment", "statement", "$@3", "$@4", "$@5", "$@6", "$@7",
  "$@8", "clear_fill_clause", "string_assignment", "to", "open_clause",
  "seek_clause", "string_scalar_or_array", "string_expression",
  "string_function", "number_assignment", "expression", "$@9", "$@10",
  "arrayref", "string_arrayref", "coordinates", "function", "const",
  "number", "symbol_or_lineno", "dimlist", "function_or_array",
  "stringfunction_or_array", "call_list", "$@11", "calls", "call_item",
  "function_definition", "$@12", "$@13", "$@14", "endsub", "function_name",
  "export", "local_list", "local_item", "static_list", "static_item",
  "paramlist", "paramitem", "for_loop", "$@15", "$@16", "$@17", "$@18",
  "next", "step_part", "next_symbol", "switch_number_or_string", "$@19",
  "sep_list", "number_or_string", "case_list", "$@20", "default", "$@21",
  "do_loop", "$@22", "loop", "while_loop", "$@23", "$@24", "wend",
  "repeat_loop", "$@25", "until", "if_clause", "$@26", "$@27", "$@28",
  "$@29", "endif", "short_if", "$@30", "end_of_if", "else_part",
  "elsif_part", "$@31", "$@32", "maybe_then", "inputlist", "$@33", "input",
  "readlist", "readitem", "datalist", "printlist", "using", "inputbody",
  "$@34", "$@35", "$@36", "$@37", "$@38", "$@39", "$@40", "$@41", "$@42",
  "$@43", "$@44", "$@45", "$@46", "prompt", "printintro", "hashed_number",
  "goto_list", "gosub_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-1620)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-567)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1623, 13556, 11344, 12961,   148,   222,    62,   -60,   -58, -1620,
   -1620, -1620, -1620, -1620,    29,    29,    29,  8260, -1620, -1620,
   -1620, 12961, -1620, -1620, 12961,    45,   116, -1620, -1620, -1620,
   11344,   -38, -1620, 11344,    77, -1620, 11344, 11344, 11344,   131,
      37,    29,  3735,  2384,  4373,   138, 11344,  7232,  8517,   250,
      60, 11344, -1620,    33, 12961, 12961, 12961,    22, 11344,   947,
   11344, 11344,  8774,  9031,  7489,  6204, 11344,  6718,  9288,  9545,
   11963, 12961, 12961,   -37,  6975,  9802, 10059, 10316, 11344, 11344,
    5947,  6461,  5433,  5690, 10573, 10830, 12089, 12215, 12341,    24,
     -24,  7746, 12961,   -85,    -1,   110,   -29,   -20,    -7,    10,
      20,  4373, 12961, 12961, 12961, -1620,   187, -1620, -1620,   184,
   -1620, -1620, -1620, -1620,   194,   211, -1620,   265, -1620, -1620,
   -1620, -1620, -1620, -1620, -1620, -1620,   101,   121, -1620, -1620,
   -1620, -1620,   123,   127,   135,   137, 11344,   141,   175,   177,
     188,   192,   221,    81,   223,   274,   276,   314,   225,   352,
      96,   104,   266,   290,   320,   -35,   -33,    47,    49,   341,
     345,   140,   159,   387, -1620,   106, 12961, 11344,   216,   350,
     401,   389,   391,   403,   406,   433,   442,   463,   522,   528,
     530,   550,   569,   583,   592,   613,   614,   616,   634,   678,
     687,   690,   703,   727,   728,   738,   747,   748,   749,   758,
     767,   768,   769,   779,   780,   783,   787,   789,   790,   791,
     797,   362,   529,   806,   807,   808,   825,   850,   851,   857,
     860,   870,   878,   894,   896,   907,   916,   991,   992,   993,
     995,  1005,  1017,  1018,  1021,  1033,  1034,  1041,  1062,  1063,
    1073,  1086,  1087, 11344, 11344,   588, -1620,   627, -1620, -1620,
   -1620, -1620,   608,   669,   709,   740,   752, 12961,   -40,   763,
     194,   211,   871, -1620, 11344, -1620, 12961, -1620,   996, 11344,
   13330, -1620, -1620, -1620, -1620, -1620,   282,   563,   478,   506,
     576, -1620, 11344, -1620,   576, -1620, -1620, 11344, 13330,   679,
    1089,   884,  1095,     7, 11344,   -32,   588,   952,  1106,  1108,
     757,   952,   588,  2607,   588, 13698,  1116,  1118,   844, -1620,
   -1620,   585,   585, -1620, -1620,   848, -1620,  8003, 12961, 11344,
      21,   952,   887,    81, -1620, -1620, -1620,   889, 11344, 12961,
   12961, 12961, 13777, -1620, 11344, -1620,     0, 12961,   943, -1620,
   -1620, 11344, 11087, -1620, -1620,   952, -1620, -1620,   576,    -5,
      -5, -1620,     0, 11344, 11344, 11344, 11344, 11344, 11344, 11344,
   12961, 12961, 11344, 11344, 11344, 11344, 11344,     0,     0, 12961,
     963, 12961,   983, 12961, 12961,     0, 12961, 12961, 12961, 12961,
       0,   985, 12961, 12961, 12961,     0, 12961,     0, 12961,  1052,
   12961,    43,   153,   209, 12961, 12961, 12961, 12961, 12961,     0,
   12961,     0, 12961,     0, 12961,     0,     0,     0, 12961, 12961,
   12961, 12961, 12961,     0, 12961, 12961, 12961, 12961,     0, 12961,
   12961, 12961, 12961, 12961, 12961, 12961,     0, 12961, 12961, 12961,
   12465, 12961, 12961,     0, 12961,  1076, 12961,  1121, 12961,   394,
   12961,   465, 12961,   466, 12961, 12961, 12961, 12961, 12961, 13895,
     601, 11344, 11344, 11344, 11344,   924,   924,   924,  4647, 12961,
     115,  1125,   576,   724,   731, -1620,  1240, 11344, 11344, 11344,
   11344, 12961, -1620, -1620, -1620, 11344, 11344,   897, 11344, 11344,
   11344, 11344,  4110,  4373, 12961, -1620,   531,   531, 11344, 11344,
   12961, 12961, 12961, 12961, 12961, 12961, 12961, 12961, 12961, 12961,
   12961, 12961, 12961, 12961, 12961, 12961, 12961, 12961, 12961, 12589,
   12961, 12961, 12961,  1130, -1620, 12961,  1134,  1152,   735,  1151,
   12961, 12961, -1620, 11344, 11344, 11344, 11344, 11344, 11344, 11344,
   11344, 11344, 11344,  4373, 11344, 11344, 11344, 11344, 11344, 11344,
   11344, 11344,  4909, 12961, 12961, 12961, 12961, 12961, 11344, 11344,
   11344,  5171, 11344, 12961, 11344, 12961, 11344, 12961, 12961,  2848,
   11589, 11713, 11837, 12961, 12961, 12961, 12961, 12961, 11344, 12961,
   12961, 12961, 12961, 12961, 12961,  4373, 12961, -1620, -1620, 12961,
   11344, 12961, 12961, 12961, 12961, 12961,  1176,  1178, 12961,   924,
   12961,   924, 12961, 12961, 12961,  1366,   125,  1215, 12961, 12961,
   12961, 12961, 12961, 12961, 12961, 12961, -1620, -1620, -1620, 11344,
   11344, 11344, 11344, 11344, 11344, 11344, 11344, 11344, 11344, 11344,
   11344,   -25, -1620, -1620, -1620,   952,  1198,   576,  1200,  1391,
     952,   436, -1620, -1620, -1620, -1620,  1212,  1213,  1216, -1620,
    1214,  1225,  1235, -1620,   588,   952,  1236, -1620,   588,   952,
    1456,   765,  1455, 13330, 11344,  1268, 12961, -1620, -1620, 11344,
     588,   777,   208,  1277,  1463,  1284,    12, -1620,  1513, -1620,
   -1620,   544, 11344, 11344, -1620, -1620,   131, -1620, -1620,    51,
   13917,   576,   952,   488, 12713, 11344,     0,   576,   576,   737,
   11344, -1620,   -32, -1620, -1620, 11344,   756, 12961, -1620, 11344,
       0, 11344, 11344, 11344,  1263,     0,  1294,     0,  1298,     0,
       0,   799,   576,  1304,  1334,     0,     0, 13953, 11344, 11344,
     811, 12961,   822, 12961,   576,   830, 11344,   833,   576,   840,
     841, 11344, 12961,   843,   847,   865, 11344,   867, 11344,   869,
   12961,   880, 11344, 12961, 12961,   886,   901,   904,   912,   915,
   11344,   919, 11344,   921, 11344,   923, 11344, 11344, 11344,   576,
     925,   938,   576,   940, 11344,   576,   941,   942,   944, 11344,
     576,   956,   958,   576,   962,   964,   970, 11344,   971,   576,
     972, 12961,   974,   978,   980, 11344,   981, 12961,   982, 12961,
     984, 12961,  1010, 12961,  1012, 12961,   576,  1014,  1020,  1036,
     576, 11344, 12961,   952,   952,   952,   952,  1342,  1344,  1354,
    1355, -1620,  1246,    72, 11344, 11344, 11344, 11344, -1620,  1356,
       0,     0,   952,   576,   599,  1361,  1364, 13974, 13989,  1270,
   14004, 14019, 14034,  1373,   103,  1379,  1384,  1037,  1363,  1388,
    1396,  1397,  1402,  1410,     0, 14049,  1038,    91,   576,   576,
     576,   576,   576,  1049,   576,   576,   576,  1050,   576,   576,
    1051,   576,   576,  1067,   576, 12961,   576,  1075,   576,  1091,
   12961,    99, 12961, 12961, 12961, 12961,  1099,   576,  1515,  1559,
    1606,  1816,  1903,    39,  1936,   457,  2013,  2029,  1407,  2044,
    2065,  2580,  2660,  2678,  2886,  3046, 14064, -1620,  3114,   105,
    1103,  1111,  1113,   166, 14092, 14114,   139,   888, -1620,  3129,
    3157,   210,  3243,    -4,  3328,   259,   281, -1620,   368, -1620,
     384, -1620,   425, -1620,   429,   576,   576,   431,   460,   500,
   14129,  1120,  1123,  1132,   501,   502,   503,   538,  1411,    23,
    1420,  1421,   523,  3395,   525,    42,  1138,  1139,  1142, -1620,
   -1620,  1146,  -192,  1148,  -143,  1149,   553,   561, -1620, -1620,
     576,   576,   576,   576,   576,   576,   576, -1620, 11344, 11344,
    1409,    66,   388,   190,   -34,   -12,   -21, -1620,   -52,   -52,
    1366,  1366, -1620, -1620, -1620, 13330, -1620, -1620, 11344, -1620,
   -1620, -1620, -1620,    29,    29, -1620, -1620,   478, -1620, -1620,
     506, 11344, -1620,  1496, -1620, -1620, -1620, -1620, -1620, -1620,
   -1620, -1620,   556, 14150, 11344,    57,  3525, 13085, -1620, -1620,
   11344, 11344,  1423, 12961, -1620, -1620, 11344, -1620,   663,  1433,
    1445,  1448,  1449, 14261, 14289,  1467,  1482, -1620, -1620, -1620,
   11344,  1588,  1609, -1620,  1150, 14326, 11344, 12961,   952, -1620,
   -1620, 12961,  1157, -1620, 11344, 14347, 14362,  1457, 12961, 11344,
   11344, 11344, 12961, 11344, 11344, 11344, 11344, 11344, 11344, 11344,
   11344,  1465,  1487, 11344,  1160, 11344,  1164, 11344,  1499, 12961,
   12961, 12961,  1505,  1167, 12961, 12961, 11344,  1506, 12961,  1528,
   11344,  1171, 12961, 14377,   576,   576, 12961, 12961, 11344, 12961,
   11344,  1536, 12961,  1549, 12961,  1550, 11344,  1569,  1586,  1589,
   11344, 11344, 11344,  1590, 12961, 11344, 11344,  1592, 12961, 11344,
   12961, 12961, 11344,  1593, 12961, 11344,  1173, 11344, 12961, 11344,
    1595, 12961,  1177, 11344,  1179, 11344,  1187, 12961,  1193, 12961,
    1195, 12961, 12961, 12961, 14392,  1197, -1620, 11344, 11344, 11344,
   -1620, -1620,   588,   952,   588,   952, 14407, 14422, 13330, 11344,
   11344, 11344, -1620, -1620, -1620, -1620, -1620, 11344, 11344, -1620,
   11344, 11344, 11344, -1620, 12961, -1620, 12837, -1620, 12961,  1494,
    1594, -1620, -1620, 11344, 11344, 11344, 11344, 12961, -1620, 12961,
   11344, 11344, 11344,   576, 11344, 12961,   570, -1620,  1199,  1201,
    1203,  1230, 11344, -1620, -1620, -1620, -1620, -1620, 11344, -1620,
   -1620, 11344, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620,
   -1620, -1620, -1620, 11344, -1620, -1620, 11344, 11344, 11344, -1620,
   11344, 11344, -1620, 12961, -1620, -1620, -1620, -1620, -1620, 11344,
   -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620,
   -1620, 12961, 12961, 12961, 12961, -1620, -1620, -1620, -1620, -1620,
   12961, -1620, -1620, -1620, -1620, -1620, -1620, 11344, -1620, 11344,
   11344, 11344,  1720, 12961, -1620,  1720, 12961, -1620, 12961, -1620,
   -1620,   897,  1537, 11344,    90,   952, -1620,  1597, -1620,  1598,
    1602,  1603, -1620,  1604,  1605, -1620, -1620, -1620,   644, 13330,
   -1620, -1620, -1620, 11344, 14437, 12961,  1792, -1620, 12961,   576,
     588,   777, 14458, 11344,    85,   663,   663,  3629,  1613,  1614,
   -1620,  1620, -1620, -1620, -1620, -1620, 11344, 11344, -1620, -1620,
   14486,  4373,  4373, 12961, 12961,  1622,  1234,   576, 12961, -1620,
   11344, 11344, 12961,   576,  1632, 14501,     0,  1238,  1633,     0,
     588, 14523, 14634, 14655,     0,  1634, 14698, 12961, 12961,   952,
   12961,   952, 12961,   588,   952, 12961,  1250,   576,   576, 12961,
   12961,  1251,  1252,   546,   952, 12961,  1254, 12961,   952, 12961,
    1258, 12961,  1260,  1262,   952,   576,   952, 12961,  1275, 12961,
    1276, 12961,   952, 12961, 12961, 12961,   588, 14720,   588,   952,
     952, 12961,   576,   952,   952, 12961,  1286,   603,   952,   576,
     576,   952, 12961,  1289, 14735, 11344,   952,  1292,   952, 12961,
     576, 12961, 14750, 12961,   636, 14765, 12961,  1293, 12961,  1296,
   12961,   576,  1300,  1302, 12961, 12961,  1621,  3931,  3946,   932,
   12961, 12961, -1620,   952,     0, -1620,  1635,  3962,  3983,  4004,
    4669,  4931,   572,  1639,    97,   576, -1620, -1620,  5193,  6740,
    1642,    54,  1306,   576,   952,   952,   952, 14780,   576, -1620,
   12961, 12961, 12961, 12961,   952,  6997,  7254,  7768,  8025,  8282,
    1189,  8539,  8796,   262,  9053,   573,  1310,   289,   366,   578,
    9310, 14795, 14810,  9567,  -108,   604,   -82,   609,   624,    74,
   -1620, -1620, -1620,    29,    29, -1620, -1620, -1620, -1620, 11344,
    1854,  1869,  1865,  9824, 11344,   632,  1647,   367, -1620, 11344,
   14831, 12961,  1853, -1620, -1620, -1620, -1620, -1620, -1620,  1648,
    1650,   952,   952, 12961, -1620, -1620,   576,   576, 12961, 12961,
    1312, 14852,   952,  1313, 12961, 12961, 11344, 12961, 12961, 11344,
   11344, 11344, 11344, 11344, 11344, 12961,   576,  1319,  1320,  1336,
    1358, 11344,  1362,  1381, 12961, 11344, 11344,  1382, 12961,  1383,
    1390, 11344,   576, 11344, 11344,  1392, 12961,  1393, 11344,  1400,
    1401,  1430,  1431, 12961,  1441,  1443, 11344, 12961,  1444, 11344,
   11344,   952, 11344,  1451,  1458, 11344,   576, 12961, 12961,  1461,
   11344,  1464, 12961,  1477, 12961, 12961,   576,   576, -1620,  1840,
    1841, 11344,  1845,  1478,   576, 11344,   734, -1620, -1620, -1620,
   -1620, -1620, -1620, -1620, 12961, -1620, -1620, -1620, -1620, 11344,
   12961, 11344,   652,   654,  1490,   576, -1620, -1620, -1620, -1620,
   -1620, 11344, -1620, -1620, -1620, 12961, -1620, -1620, -1620, 12961,
   11344, -1620, 11344, -1620, -1620, -1620, 12961, 11344, -1620, 12961,
   -1620, -1620, 12961, -1620, -1620, -1620, 11344, -1620, -1620, -1620,
   -1620, -1620,  1874,   716, 10081,  1866, 11344, 12961, 10338, 11344,
     662,  1660,  1513,   663,  1663,  1664,   663, -1620, -1620,   576,
    1498,   576, 12961, 12961, 12961,   576,   576,  1667,   576,   576,
       0, 14867, 14895, 15007,     0, 15028,  1500, 12961, 11344, 11344,
   12961, 15064, 11344, 12961,   576, 15092,   952, 12961,  1502, 12961,
   11344, 15107, 15122,   588,   952, 12961,   576, 12961, 15137, 11344,
   11344, 12961, 12961,   576, 11344, 12961,   660,   952,   576, 11344,
   15152, 15167, 15182, 11344, 12961, 15204,  1508,   576, 12961,   829,
   15225, 12961,  1518, 12961,  1519,   576, 12961, 12961, 10595, 12961,
   11344, -1620,  1669,  1670,   -22, -1620,   664, 15240,   576,   952,
   -1620, -1620, 12961, 10852,   666,   667, 11109, 11366,   670, 11592,
     675,   718,    94, 13330, 13782, 11344,  1883, -1620,  1672, -1620,
    1674, 15261,   719,   755, 11607,  1880, 11344,   663, -1620, -1620,
   -1620, -1620, 12961,   576,   576,   576, 12961, 11344, 11344, 12961,
   11344, 11344, 11344, 12961,  1520, 15379, 15401,  1521, 11344, 15437,
    1527, 11344,  1535, 11344,  1543, 15458, 11344, 11344,  1545,  1547,
   11344, 15473, 15488,   576,   576, 15503,  1551, 11344, 15518, 11344,
   11344, 11344, 15533,  1557, 11344, 12961,   576, 12961, 12961,  1564,
   11344,  1565, 12961,   576,   576,  1864,   576,   952,  1676,  1677,
     734, -1620, -1620, 11344,   576, -1620, -1620, -1620, -1620, -1620,
   -1620, -1620, -1620, -1620, 11344, -1620,  1865,  1904,   698, 13330,
   -1620, 12961, 11344, 11344, -1620, -1620,  1683,  1513, -1620,  1686,
    1513, 15548, -1620,   576,   576,  1691, 15576,   576, 15598,  1692,
   15613,  1567, 12961, 12961, 12961, 12961, 15634, 12961, 12961, 15745,
   11344,   952, 12961, 11344,   952, 15773, 12961, 11344,   952, 11344,
   12961, 12961, 12961,   952, 12961, 15810, 15831, 15846, 12961, 12961,
     952,   576,  1568,   576, 12961,   873, 15861, 12961,   576, 12961,
   -1620, -1620, -1620, 13330, 11627,   952, 13330, -1620, -1620,  1865,
     782,   408, 15876, 11829,  1513, 12961,   663,  1513, 11344,   663,
   11344, 12961, 12961, 11344, 12961, 12961, 12961,   576,   576,   576,
    1571, 11344,   576,   576, 11344, 15891,  1575, 15906, 11344,   576,
   15921, 15942,   576,   576,   576,   576, 11344, 12961, 11344,  1577,
     576, 12961,   576, 12961, 12961,  1578,   576,     6, -1620,  1865,
   13330, -1620, -1620, -1620, -1620, -1620, -1620, -1620, 12961, -1620,
   11344, -1620,   663,   423, -1620,   663, 15970, -1620, 11954,   576,
     576, 15985,   576,   576,   576, 12961,   952,   952, 11344, 12961,
   11344,   952, 12961, 12961,   952,   576, 16007, 12961,   576,  1581,
     576, 12961, -1620, -1620, -1620,  1031,  1865,   720, 12080, -1620,
   12961, -1620, -1620, 11344, -1620, 12961,   576, 16118,   576, 16139,
     576,   576, 11344,   576, 12961,   576, -1620, -1620, -1620, -1620,
   -1620, -1620,  1951,  1874, -1620, -1620,   721,  1513, 13472,  1513,
     576, 12961, 12961, 16182,   576, -1620, -1620, -1620, -1620,   663,
   -1620,   663,  1584,   576, 12961,  1513, -1620,  1513, -1620, 12961,
     576,   663,   663,   576, -1620, -1620
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   242,     0,     0,     0,   495,     0,     0,     0,   236,
     518,   553,   558,    18,     0,     0,     0,     0,    31,    33,
     496,     0,   480,   480,     0,   497,    25,    27,   533,   545,
       0,   642,    55,    67,     0,   233,   234,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   243,
     244,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   225,
       0,     0,     0,     0,     0,     2,     9,    17,     8,     0,
      12,    46,    48,    14,    29,    30,    28,     0,    20,    21,
      24,    23,    22,    35,    36,   468,   353,   264,   469,   470,
     471,   267,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   314,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
       0,     0,     0,     0,     0,     0,     0,   413,   416,   419,
     422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   295,   297,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   265,     0,   367,   347,
     352,   266,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,   480,     0,   480,     0,     0,
      16,   473,   472,    37,    38,    45,     0,     0,     0,     0,
      19,    50,   482,    51,    49,   498,    26,     0,    16,   577,
       0,   646,     0,     0,   606,   638,    69,    68,     0,     0,
      70,   235,    60,     0,    62,     0,   598,   600,    63,   596,
     602,     0,     0,   603,   465,    64,    66,     0,   220,     0,
       0,   657,     0,    92,   222,    86,    47,     0,     0,     0,
       0,     0,     0,    74,     0,    57,    79,     0,     0,    94,
      93,     0,     0,   245,   246,   223,    13,    15,   237,     0,
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
       0,     0,   238,     0,     0,     7,     0,     0,     0,     0,
       0,     0,   487,   480,   480,     0,     0,   337,     0,     0,
       0,     0,     0,     0,     0,   443,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   313,     0,     0,     0,     0,     0,
       0,     0,   448,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   480,   480,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   359,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,   335,   333,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     5,     6,   331,     0,   247,     0,     0,
     554,     9,    39,    40,    41,    43,   501,   502,    32,   499,
     507,   508,    34,   505,   485,   486,   481,   483,   538,   537,
       0,     9,     0,    16,     0,     0,     0,   643,   644,     0,
     609,   611,    52,     0,     0,     0,     0,    56,   640,   480,
     480,     0,     0,     0,   480,   480,     0,   467,   466,     0,
       0,   221,   656,     0,     0,     0,     0,    96,    73,     0,
       0,    78,   638,   254,   253,     0,     0,     0,    75,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,     0,     0,     0,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
       0,     0,   174,     0,     0,   179,     0,     0,     0,     0,
     188,     0,     0,   191,     0,     0,     0,     0,     0,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   213,     0,     0,     0,
     218,     0,     0,   117,   116,   118,   119,   262,     0,     0,
       0,   226,     0,     0,     0,     0,     0,     0,    10,     0,
       0,     0,   332,   252,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   300,   304,
     301,   305,   461,     0,   460,   450,   449,     0,   452,   451,
       0,   454,   453,     0,   457,     0,   455,     0,   310,     0,
       0,     0,     0,     0,     0,     0,     0,   447,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   393,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,     0,
       0,     0,     0,     0,     0,     0,     0,   414,     0,   417,
       0,   420,     0,   423,     0,   315,   316,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   296,
     298,     0,     0,     0,     0,     0,     0,     0,   269,   368,
     362,   364,   366,   363,   365,   360,   361,   268,     0,     0,
     340,   342,   344,   341,   343,   338,   339,   358,   355,   354,
     356,   357,   478,   479,   519,    16,   565,   563,     0,   564,
     560,   562,   559,     0,     0,   480,   480,     0,   480,   480,
       0,     0,   535,   539,   552,   550,   551,   548,   547,   549,
     546,   567,     9,     0,     0,     0,     0,     0,   607,    53,
      54,     0,     0,     0,   614,   616,     0,   641,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   597,   604,   605,
       0,     0,     0,   257,   256,   260,     0,     0,   371,    58,
      76,     0,    89,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   153,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   480,     0,     0,     0,
     227,   228,   229,   230,   231,   232,     0,     0,    16,     0,
       0,     0,   493,   494,   488,   435,   327,     0,     0,   426,
       0,     0,     0,   436,     0,   437,     0,   430,     0,     0,
       0,   348,   349,     0,     0,     0,     0,     0,   464,     0,
       0,     0,     0,   456,     0,     0,     0,   311,     0,     0,
       0,     0,     0,   372,   373,   374,   375,   376,     0,   377,
     379,     0,   380,   382,   383,   345,   389,   390,   384,   386,
     387,   388,   385,     0,   392,   397,     0,     0,     0,   396,
       0,     0,   277,     0,   274,   280,   281,   398,   325,     0,
     399,   326,   282,   283,   412,   415,   418,   421,   286,   284,
     285,     0,     0,     0,     0,   289,   405,   290,   411,   410,
       0,   299,   406,   291,   407,   292,   409,     0,   293,     0,
       0,     0,     0,     0,   320,     0,     0,   322,     0,   442,
     330,   336,   334,     0,     9,   561,   658,    42,   660,    44,
       0,     0,   500,     0,     0,   506,   484,   536,   542,    16,
     579,   580,   578,     0,     0,     0,   647,   645,     0,   612,
     610,   611,     0,     0,     0,     0,     0,     0,   592,   594,
     639,   589,   474,   476,   480,   480,     0,     0,   599,   601,
      71,     0,     0,     0,     0,     0,     0,   126,     0,    77,
       0,     0,     0,   102,     0,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,   124,     0,   129,   130,     0,     0,   134,   133,     0,
       0,     0,     0,     0,   142,     0,     0,     0,   149,     0,
       0,     0,     0,     0,   156,   155,   157,     0,     0,     0,
       0,     0,   164,     0,     0,     0,   168,     0,   170,   171,
     172,     0,   176,   178,   177,     0,   181,   184,   185,   189,
     190,   187,     0,     0,     0,     0,   195,     0,   197,     0,
     201,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   215,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,    87,     0,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   444,   369,   370,     0,     0,
       0,     0,   462,   459,   306,   307,   308,     0,   458,   312,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     557,   556,   555,     0,     0,   503,   504,   509,   510,     0,
       0,     0,   568,     0,     0,     0,     0,     0,   608,     0,
       0,     0,   628,   615,   617,   618,   480,   480,   590,     0,
       0,    59,    61,     0,   258,   259,   255,   261,     0,     0,
      90,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196,     0,     0,     0,     0,   202,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   216,   115,   263,     0,
       0,     0,     0,   240,   241,     0,   511,   424,   425,   427,
     428,   429,   438,   439,     0,   440,   350,   351,   323,     0,
       0,     0,     0,     0,     0,   302,   378,   381,   391,   270,
     271,     0,   273,   394,   395,     0,   275,   400,   287,     0,
       0,   401,     0,   403,   318,   294,     0,     0,   329,     0,
     432,   319,     0,   434,   321,   346,     0,   659,   661,   540,
     543,   534,   583,   649,     0,   648,     0,     0,     0,     0,
       0,     0,   640,     0,     0,     0,     0,   475,   477,    72,
       0,    97,     0,     0,     0,   103,   106,     0,   101,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   139,     0,   140,     0,     0,     0,
       0,   144,     0,   150,   151,     0,   159,     0,   161,     0,
       0,     0,     0,   169,     0,     0,     0,   183,   186,     0,
       0,     0,     0,     0,     0,     0,     0,   205,     0,     0,
       0,     0,     0,     0,     0,   217,     0,     0,     0,     0,
       0,    88,   514,   515,     0,   512,     0,     0,   463,   309,
     445,   317,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   529,    16,   242,     0,   581,   653,     0,   650,
       0,     0,     0,   620,     0,   630,     0,     0,   619,   593,
     595,   591,     0,   125,    82,    98,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,   166,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,     0,     0,     0,
       0,     0,     0,   250,   251,     0,   249,   239,     0,     0,
       0,   489,   441,     0,   303,   272,   276,   288,   402,   404,
     408,   328,   431,   433,     0,   520,   541,     9,   587,    16,
     569,     0,     0,     0,   613,   632,     0,   640,   622,     0,
     640,     0,   629,    95,   110,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   147,     0,     0,   145,     0,     0,     0,   162,     0,
       0,     0,     0,   182,     0,     0,     0,     0,     0,     0,
     203,   206,     0,   208,     0,     0,     0,     0,   214,     0,
     516,   517,   513,    16,     0,   530,    16,   588,   584,   582,
       0,     0,     0,     0,   640,     0,     0,   640,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,   121,   123,
       0,     0,   132,   127,     0,     0,     0,     0,     0,   154,
       0,     0,   163,   167,   175,   180,     0,     0,     0,     0,
     200,     0,   207,     0,     0,     0,   248,     9,   324,   521,
      16,   576,   573,   574,   575,   571,   572,   570,     0,   654,
       0,   651,     0,     0,   621,     0,     0,   631,     0,   109,
     100,     0,   111,   105,   219,     0,   136,   141,     0,     0,
       0,   152,     0,     0,   199,   194,     0,     0,   209,     0,
     212,     0,   492,   491,   490,     0,   585,     0,     0,   633,
       0,   634,   623,     0,   624,     0,   128,     0,   146,     0,
     158,   160,     0,   192,     0,   210,   524,   526,   527,   528,
     523,   525,   531,   583,   655,   652,     0,   640,     0,   640,
     108,     0,     0,     0,   211,   532,   522,   586,   636,     0,
     626,     0,   137,   148,     0,   640,   635,   640,   625,     0,
     193,     0,     0,   138,   637,   627
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1620, -1620, -1620,  -180, -1620, -1620,  1952,   802, -1620, -1620,
   -1620, -1620, -1620, -1620, -1620,  1912,   507, -1620, -1620,  -408,
      -3, -1620,  1917,  1700, -1620, -1620,  1470,  -478,  3091, -1620,
    1307,   -30,   -14, -1620,     2,     4,   169, -1620, -1620,   988,
    1966, -1620, -1620, -1620, -1620, -1620, -1620, -1620,   975, -1620,
     997, -1620,   132, -1620, -1620, -1620, -1620, -1620, -1620, -1620,
   -1620, -1620, -1620, -1620,   472, -1620, -1620, -1620, -1620, -1620,
   -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620,
   -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620,   -90,
   -1620, -1620, -1620, -1211, -1620, -1620, -1620,  1309, -1620, -1620,
     682,  1303, -1620, -1620, -1620, -1620, -1620, -1620, -1620, -1620,
   -1620, -1620, -1620, -1620, -1620, -1619, -1620,    32, -1620, -1620
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,   105,   106,   466,  1158,   107,   108,   278,   279,
     993,   994,   295,   692,   109,   110,   695,   111,   112,   808,
     245,   246,   113,   332,   969,   968,   840,   841,   333,   248,
     313,   249,   273,   300,   250,   251,   281,   282,   646,   647,
     116,   824,  1446,  1943,  2044,  1164,   117,   638,   639,   642,
     643,  1764,  1765,   118,   268,  1283,  1946,  2045,  2072,  1875,
    2086,   119,   287,  1003,   650,  1298,  1783,  1511,  1784,   120,
     288,  1010,   121,   269,   985,  1502,   122,   270,   992,   123,
     652,  1299,  1672,  1950,  2007,   124,   653,  1302,  1880,  1786,
    2000,  2073,  1948,  1320,  1686,  1321,   308,   309,   315,   662,
    1018,   667,  1315,  1316,  1683,  1887,  1957,  2079,  2097,  1682,
    1890,  1954,  2077,  2095,   668,  1028,   294,   322,  1287,  1289
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     258,   274,   275,   114,   622,   115,   260,   693,   261,   843,
     314,   657,   693,   451,   658,   264,  1024,   266,   280,  1025,
     290,   284,   291,   292,   394,   616,   663,   316,   664,   665,
     296,  2042,   683,   271,   302,   304,   272,     7,     8,   320,
     125,   614,   615,   616,   128,   129,   130,   310,   809,   810,
    2043,   348,   349,   350,   125,   260,   616,   261,   128,   129,
     130,  1038,   263,  1797,   615,   616,   693,   391,   392,   393,
    1273,   445,  1274,   285,   395,   326,   327,   499,   500,   502,
     503,   298,   299,   439,   441,   443,  1666,   446,   452,   450,
     631,   598,   599,   600,   601,   602,   603,   604,   460,   462,
     463,   464,   607,   608,  1523,  1524,  1500,  1874,   651,   609,
     610,   611,   612,   613,   614,   615,   616,   607,   608,  1276,
     501,  1277,   504,   286,   609,   610,   611,   612,   613,   614,
     615,   616,   351,   461,  1501,   306,   307,   607,   608,   612,
     613,   614,   615,   616,   609,   610,   611,   612,   613,   614,
     615,   616,     7,     8,  1659,   344,  1660,   607,   608,   505,
     506,   508,   509,   518,   609,   610,   611,   612,   613,   614,
     615,   616,   453,   598,   599,   600,   601,   602,   603,   604,
    1662,   952,  1663,   954,   444,   598,   599,   600,   601,   602,
     603,   604,   283,   484,   485,   598,   599,   600,   601,   602,
     603,   604,   507,   265,   510,   267,   619,   620,   492,   598,
     599,   600,   601,   602,   603,   604,   494,   605,   516,   328,
     329,   454,   617,   618,   619,   620,   330,   293,    96,    97,
      98,   465,   605,   666,   455,   617,   618,   619,   620,   958,
    1860,   596,  1861,   456,   617,   618,   619,   620,    53,   331,
      20,   493,   605,   605,   621,    25,   457,   694,  1239,   495,
    1240,   517,   694,   627,   613,   614,   615,   616,  1956,   470,
     659,  1959,   114,   458,   115,  1026,   467,   468,   605,   644,
     605,   677,   678,   459,   648,  1260,   471,  1261,   469,   472,
     114,   660,   115,   311,   312,   617,   618,   619,   620,   605,
     605,  1208,   513,  1209,  1267,   742,  1268,   311,   312,   339,
     617,   618,   619,   620,   605,   681,   694,   632,   633,  1305,
     514,  1306,   617,   618,   619,   620,   687,   688,   689,   605,
     617,   618,   619,   620,   696,  2012,  1151,   490,  2015,   340,
     341,   342,   605,    96,    97,    98,   343,  1521,   605,  1522,
     617,   618,   619,   620,   605,  1188,   605,   711,   712,  1624,
     605,  1625,   605,  1197,   265,  1174,   720,  1175,   722,  1225,
     724,   725,   605,   727,   728,   729,   730,   814,   496,   733,
     734,   735,   605,   737,   267,   739,   473,   741,   520,   958,
     474,   745,   746,   747,   748,   749,   605,   751,   475,   753,
     476,   755,   497,  1232,   478,   759,   760,   761,   762,   763,
     605,   765,   766,   767,   768,   743,   770,   771,   772,   773,
     774,   775,   776,   605,   778,   779,   780,   782,   783,   784,
    1229,   786,   498,   788,   626,   790,   628,   792,   479,   794,
     480,   796,   797,   798,   799,   800,   617,   618,   619,   620,
     986,   481,   987,   511,   988,   482,   813,   512,  2089,   610,
    2091,   612,   613,   614,   615,   616,   605,   605,   823,  1019,
    1020,   744,  1798,  1012,  1237,  1801,  2101,   989,  2102,   834,
     990,   837,   636,   637,   483,   991,   486,   846,   847,   848,
     849,   850,   851,   852,   853,   854,   855,   856,   857,   858,
     859,   860,   861,   862,   863,   864,   866,   867,   868,   869,
     640,   641,   871,   522,   835,   836,   605,   876,   877,   605,
     607,   608,   521,  1242,  1645,   563,  1646,   609,   610,   611,
     612,   613,   614,   615,   616,   838,   839,   487,   605,   488,
     899,   900,   901,   902,   903,  1243,   605,   906,  1031,  1032,
     911,  1650,   913,  1651,   915,   916,   918,   920,   922,   924,
     925,   926,   927,   928,   929,   888,   931,   932,   933,   934,
     935,   936,   937,   939,  1041,  1042,   942,   489,   944,   945,
     946,   947,   948,   634,   635,   951,  1892,   953,   125,   955,
     956,   957,   128,   129,   130,   960,   961,   962,   963,   964,
     965,   966,   967,  1162,  1163,  1300,  1301,   938,   598,   599,
     600,   601,   602,   603,   604,   491,   598,   599,   600,   601,
     602,   603,   604,   605,   605,   605,   607,   608,  1652,  1677,
    1653,   958,  1244,   609,   610,   611,   612,   613,   614,   615,
     616,   605,   825,   826,   617,   618,   619,   620,  1245,   314,
     515,   605,   523,  1015,   524,   114,   791,   115,   598,   599,
     600,   601,   602,   603,   604,   605,   525,  1318,  1319,   526,
    2008,   606,  2009,   598,   599,   600,   601,   602,   603,   604,
     605,  1044,   605,  1509,  1510,  2050,   605,  2051,   605,  1246,
     607,   608,   564,  1247,  1052,  1248,   527,   609,   610,   611,
     612,   613,   614,   615,   616,   528,   598,   599,   600,   601,
     602,   603,   604,   617,   618,   619,   620,   605,  1074,  1211,
    1076,  1212,   605,   605,  1249,  -566,   529,   793,   795,  1083,
     598,   599,   600,   601,   602,   603,   604,  1091,  1762,  1763,
    1094,  1095,   607,   608,  1947,  2014,   940,   941,  2017,   609,
     610,   611,   612,   613,   614,   615,   616,   605,   605,   605,
     605,   607,   608,   501,  1250,  1255,  1256,  1257,   609,   610,
     611,   612,   613,   614,   615,   616,  1787,  1788,  1126,  1004,
     605,  1005,   605,  1006,  1132,   530,  1134,  1264,  1136,  1266,
    1138,   531,  1140,   532,  1494,   605,  2001,  1496,  2002,  1145,
    2003,  2049,  1258,   605,  2052,  1284,  1007,   623,  1566,  1008,
     605,  1152,  1154,   533,  1009,  1885,  1886,  1279,   605,   617,
     618,   619,   620,  2004,   504,  1280,  2005,   605,  1017,   605,
     605,  2006,   534,   605,  1469,   605,  1622,  1648,  1029,  1030,
     607,   608,  1654,  1035,  1036,   605,   535,   609,   610,   611,
     612,   613,   614,   615,   616,   536,   701,   702,   605,   703,
     605,   605,  1193,   802,   507,  1587,   605,  1196,  1661,  1198,
    1199,  1200,  1201,  1664,   718,   719,   537,   538,  2096,   539,
    2098,   605,   726,   617,   618,   619,   620,   731,  1665,   605,
    2104,  2105,   736,   605,   738,   510,  1675,   540,  1597,   598,
     599,   600,   601,   602,   603,   604,   750,   517,   752,   605,
     754,   605,   756,   757,   758,   624,  1770,   605,  1771,   605,
     764,   605,  1837,   605,   605,   769,  1795,   605,  1862,   807,
    1866,  1867,   605,   777,  1870,   617,   618,   619,   620,  1872,
     785,   541,   655,   598,   599,   600,   601,   602,   603,   604,
     542,   607,   608,   543,   617,   618,   619,   620,   609,   610,
     611,   612,   613,   614,   615,   616,   544,   609,   610,   611,
     612,   613,   614,   615,   616,   605,   605,   605,   605,  1286,
    1288,   605,  1873,  1884,  2074,  2088,   816,   114,   605,   115,
     545,   546,   605,   817,   605,   607,   608,   874,   644,  1047,
     629,   547,   609,   610,   611,   612,   613,   614,   615,   616,
     548,   549,   550,   605,  1309,   607,   608,  1310,  1051,   671,
    1314,   551,   609,   610,   611,   612,   613,   614,   615,   616,
     552,   553,   554,   617,   618,   619,   620,   353,   354,   355,
     356,   357,   555,   556,  1336,  2066,   557,  2067,  1337,  2068,
     558,   358,   559,   560,   561,  1343,   605,   359,   360,  1347,
     562,  1065,  1350,   361,   362,   363,   364,   365,   605,   565,
     566,   567,  2069,  1073,  1363,  2070,  1366,  1367,  1368,   605,
    2071,  1371,  1372,  1373,  1075,  1376,   605,   605,   568,  1380,
     605,  1847,  1077,  1382,  1383,  1079,  1385,   605,   605,  1388,
     605,  1390,  1080,  1081,   605,  1084,   676,  1396,  1398,  1085,
     679,  1402,   366,   569,   570,  1406,  1407,  1409,  1410,  1512,
     571,  1413,   605,   572,   605,  1417,   605,  1086,  1420,  1088,
     605,  1090,  1424,   573,  1427,  1993,  1429,   605,  1431,  1432,
    1433,   574,  1092,   605,   617,   618,   619,   620,  1096,   684,
    1233,   685,  1234,   617,   618,   619,   620,   575,   605,   576,
     114,   605,   115,  1097,  1290,  1291,  1098,  1293,  1294,   605,
     577,  1452,   605,  1454,  1099,  1455,   605,  1100,   605,   578,
     605,  1102,   605,  1104,  1462,  1106,  1463,  1110,   617,   618,
     619,   620,  1468,  1046,  1611,   605,  1612,   605,   605,   605,
    1111,   605,  1112,  1114,  1115,   697,  1116,  1054,   617,   618,
     619,   620,  1059,   605,  1061,   605,  1063,  1064,  1118,   605,
    1119,   605,  1068,  1069,  1120,   721,  1121,   605,   605,   605,
    1483,   605,  1122,  1124,  1125,   605,  1127,   605,   605,   605,
    1128,   605,  1129,  1131,  1133,   723,  1135,   732,  1485,  1486,
    1487,  1488,   607,   608,   579,   580,   581,  1489,   582,   609,
     610,   611,   612,   613,   614,   615,   616,   605,   583,   605,
    1495,   605,  1137,  1497,  1139,  1498,  1141,   605,   607,   608,
     584,   585,  1142,   818,   586,   609,   610,   611,   612,   613,
     614,   615,   616,   605,   605,   605,   587,   588,  1143,  1178,
    1187,   114,  1515,   115,   589,  1517,   605,   605,   605,   607,
     608,  1189,  1190,  1191,   740,  1436,   609,   610,   611,   612,
     613,   614,   615,   616,   605,   590,   591,  1160,  1161,  1192,
    1536,  1537,   605,   607,   608,  1540,   592,  1194,   787,  1543,
     609,   610,   611,   612,   613,   614,   615,   616,   605,   593,
     594,  1185,   654,  1195,  1556,  1557,   605,  1558,   656,  1559,
     605,  1202,  1560,  1534,  1535,  1226,  1562,  1563,   605,   669,
     605,   670,  1567,  1227,  1569,  1228,  1570,   605,  1572,   674,
     605,   675,  1252,   789,  1575,  1253,  1577,   815,  1579,   605,
    1580,  1581,  1582,   870,  1254,   605,   605,   872,  1584,   605,
    1269,  1270,  1585,   605,  1271,   605,   605,   605,  1272,  1588,
    1275,  1278,  1333,   875,   605,   873,  1593,   605,  1594,  1338,
    1596,   605,  1360,  1599,   605,  1601,  1362,  1603,   605,  1370,
     605,  1606,  1607,  1379,   605,  1415,   605,  1613,  1614,  1421,
     949,  1423,   950,   616,   605,   617,   618,   619,   620,  1426,
     605,  1641,   605,  1642,   605,  1428,   605,  1430,   605,  1435,
     605,  1470,   982,  1471,   983,  1472,   984,  1632,  1633,  1634,
    1635,   617,   618,   619,   620,   995,   996,   998,   997,   959,
     610,   611,   612,   613,   614,   615,   616,   605,   999,  1667,
    1668,   605,  1473,  1529,  1530,   605,  1539,  1000,  1001,  1002,
    1547,  1011,   617,   618,   619,   620,   648,   605,   605,   605,
    1150,   605,  1561,  1564,  1565,   605,  1568,   605,  1680,   605,
    1571,  1022,  1573,  1027,  1574,  1058,   617,   618,   619,   620,
    1689,  1014,   605,   605,  1169,  1690,  1691,  1576,  1578,  1297,
    1021,  1695,  1696,   605,  1698,  1699,   605,  1023,  1586,   605,
     605,  1589,  1706,   605,  1592,  1600,  1060,   605,  1602,   605,
    1062,  1714,  1604,   605,  1605,  1718,  1066,   605,  1630,   605,
     605,  1723,  1649,  1726,  1692,  1694,   605,   605,   607,   608,
    1733,  1707,  1708,  1736,  1738,   609,   610,   611,   612,   613,
     614,   615,   616,   605,  1746,  1747,  1067,  1749,  1709,  1752,
     607,  1754,  1755,  1876,  1877,  1146,  1147,   609,   610,   611,
     612,   613,   614,   615,   616,   605,  1148,  1149,  1159,   605,
    1710,  1766,   607,   608,  1712,  1165,  1179,  1768,  1166,   609,
     610,   611,   612,   613,   614,   615,   616,  1173,   605,   605,
     605,  1176,  1774,  1713,  1717,  1719,  1775,   605,  1177,   605,
     605,  1180,  1720,  1778,  1725,  1727,  1780,   605,   605,  1781,
    1181,  1182,  1729,  1730,  1183,   617,   618,   619,   620,   607,
     608,  1215,  1184,  1331,  1792,  1259,   609,   610,   611,   612,
     613,   614,   615,   616,  1262,  1263,  1313,   605,   605,  1803,
    1804,  1805,  1731,  1732,  1332,  1684,  1685,  1322,   605,  1949,
     605,   605,   247,  1734,  1814,  1735,  1739,  1817,   605,  1323,
    1820,  1324,  1325,  1743,  1822,   605,  1824,   277,   605,  1342,
    1744,   605,  1828,  1748,  1829,   839,  1751,  1357,  1833,  1834,
     289,  1328,  1836,   297,   605,   605,   301,   303,   305,  1753,
    1760,  1843,   321,   321,   321,  1846,  1329,   605,  1849,  1358,
    1851,   345,  1772,  1853,  1854,   605,  1856,   605,  1456,   605,
    1802,  1365,  1813,  1997,  1823,   605,  1999,  1369,  1375,  1864,
    1845,   617,   618,   619,   620,   605,   605,   605,   605,  1203,
    1850,  1852,  1902,  1905,   605,   114,   114,   115,   115,  1908,
    1377,   449,   605,   617,   618,   619,   620,  1910,  1387,  1893,
     605,   321,   605,  1894,   605,  1912,  1897,  1916,   605,  1917,
    1901,  1389,  1391,  1922,   605,   617,   618,   619,   620,  1929,
    2046,   605,   605,  1204,   605,   605,  1934,  1937,   605,  1966,
    1991,  1393,   605,  2025,   605,   605,   477,  2029,   605,  2037,
    2041,   605,  1931,  2064,  1932,  1933,  2099,  1935,  1394,  1938,
    1516,  1395,  1401,  1546,  1405,  1412,  1549,  1419,  1457,  1503,
    1504,  1553,   617,   618,   619,   620,  1505,  1506,  1507,  1508,
    1205,     1,     2,     3,     4,     5,  1526,  1527,  1951,   607,
     608,   114,  1528,   115,  1538,  1608,   609,   610,   611,   612,
     613,   614,   615,   616,  1544,  1548,  1554,  1670,  1616,  1967,
    1968,  1969,  1970,  1623,  1972,  1973,  1628,  1671,    -9,  1976,
    1676,  1681,  1687,  1979,  1688,  1756,  1757,  1982,  1983,  1984,
    1759,  1985,  1785,  1796,  1790,  1989,  1990,  1799,  1800,  1806,
    1879,  1992,  1858,  1859,  1995,  1881,  1996,  1882,  1889,  1939,
    1940,  1941,  -544,   595,   597,   114,  1955,   115,   114,  1958,
     115,  1615,  2013,  1961,  1964,  2085,   259,   842,  2019,  2020,
    1442,  2022,  2023,  2024,   625,   346,   607,   608,  1629,   630,
     347,   262,  1292,   609,   610,   611,   612,   613,   614,   615,
     616,  1669,   645,  2087,  2035,  1037,  1039,   649,  2038,  1296,
    2039,  2040,  1942,  1518,   661,  1049,     0,  1295,     0,   607,
     608,     0,   114,     0,   115,  2047,   609,   610,   611,   612,
     613,   614,   615,   616,     0,     0,     0,   680,     0,   682,
       0,     0,  2056,     0,     0,     0,  2058,     0,     0,  2060,
    2061,     0,     0,     0,  2063,     0,     0,     0,  2065,     0,
       0,     0,     0,     0,     0,     0,     0,  2076,     0,     0,
       0,     0,  2080,     0,     0,     0,     0,     0,     0,     0,
       0,  2084,     0,     0,     0,     0,   717,     0,     0,     0,
       0,     0,   617,   618,   619,   620,   607,   608,  2092,  2093,
    1206,     0,     0,   609,   610,   611,   612,   613,   614,   615,
     616,  2100,   607,   608,     0,     0,  2103,     0,     0,   609,
     610,   611,   612,   613,   614,   615,   616,   607,   608,     0,
       0,     0,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,     0,     0,     0,     0,     0,     0,   607,   608,
       0,     0,     0,     0,     0,   609,   610,   611,   612,   613,
     614,   615,   616,     0,     0,     0,     0,     0,     0,     0,
       0,   803,   804,   805,   806,     0,     0,     0,   812,   617,
     618,   619,   620,     0,     0,     0,     0,  1207,     0,     0,
     822,     0,     0,     0,     0,   827,   828,     0,   829,   830,
     831,   832,   321,   321,     0,     0,     0,     0,     0,   845,
       0,     0,   617,   618,   619,   620,     0,     0,     0,     0,
    1210,     0,     0,     0,     0,     0,     0,  1807,     0,     0,
       0,  1811,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   878,   879,   880,   881,   882,   883,   884,
     885,   886,   887,   321,   889,   890,   891,   892,   893,   894,
     895,   896,   898,     0,     0,     0,     0,     0,   904,   905,
     907,   909,   910,     0,   912,     0,   914,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   930,   617,
     618,   619,   620,     0,     0,   321,     0,  1213,     0,     0,
     943,     0,     0,     0,     0,   617,   618,   619,   620,     0,
       0,     0,     0,  1214,     0,     0,     0,     0,     0,     0,
     617,   618,   619,   620,     0,     0,     0,     0,  1216,   970,
     971,   972,   973,   974,   975,   976,   977,   978,   979,   980,
     981,   617,   618,   619,   620,     0,     0,     0,     0,  1217,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1013,     0,     0,     0,     0,  1016,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1033,  1034,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1045,     0,   125,   126,   127,
    1048,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,  1055,  1056,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1093,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,     0,
       0,     0,     0,   323,     0,     0,     0,     0,     0,     0,
       0,   324,     0,     0,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,   325,     0,     0,     0,     0,   148,
       0,  1144,     0,     0,     0,     0,   149,     0,     0,     0,
     150,   151,     0,     0,  1153,  1155,  1156,  1157,     0,     0,
     152,     0,   153,   154,     0,     0,     0,     0,   155,   156,
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
     243,     0,     0,   607,   608,     0,     0,   244,     0,   319,
     609,   610,   611,   612,   613,   614,   615,   616,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1281,  1282,
     607,   608,     0,     0,     0,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,     0,     0,     0,  1285,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   645,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1304,     0,     0,     0,     0,     0,
    1311,  1312,     0,   607,   608,     0,  1317,     0,     0,     0,
     609,   610,   611,   612,   613,   614,   615,   616,     0,     0,
    1330,   607,   608,     0,     0,     0,     0,     0,   609,   610,
     611,   612,   613,   614,   615,   616,     0,     0,     0,     0,
    1345,     0,     0,     0,     0,  1351,  1352,  1353,     0,     0,
    1356,     0,     0,  1359,     0,  1361,     0,  1364,     0,     0,
       0,     0,     0,     0,     0,     0,  1374,     0,     0,     0,
    1378,     0,     0,     0,     0,     0,     0,     0,  1384,     0,
    1386,     0,     0,     0,     0,     0,  1392,     0,     0,     0,
    1397,  1399,  1400,     0,     0,  1403,  1404,     0,     0,  1408,
       0,     0,  1411,     0,     0,  1414,     0,  1416,     0,  1418,
       0,     0,     0,  1422,     0,  1425,   617,   618,   619,   620,
       0,     0,     0,     0,  1218,     0,     0,  1437,  1438,  1439,
       0,     0,     0,   127,     0,     0,     0,     0,   131,  1443,
       0,     0,     0,   617,   618,   619,   620,  1447,  1448,   672,
    1449,  1450,  1451,     0,     0,     0,     0,     0,     0,   133,
       0,     0,     0,  1458,  1459,     0,  1461,     0,     0,     0,
    1464,  1465,  1466,     0,  1467,     0,     0,     0,     0,     0,
       0,     0,  1474,     0,     0,     0,     0,     0,  1475,     0,
       0,  1476,     0,     0,     0,     0,   617,   618,   619,   620,
       0,     0,     0,  1477,  1219,     0,  1478,  1479,  1480,     0,
    1481,  1482,     0,     0,   617,   618,   619,   620,     0,  1484,
       0,     0,  1220,     0,     0,     0,     0,     0,     0,   607,
     608,     0,     0,   146,     0,   147,   609,   610,   611,   612,
     613,   614,   615,   616,     0,     0,     0,  1490,     0,  1491,
    1492,  1493,     0,     0,   150,   151,     0,     0,     0,     0,
       0,     0,     0,  1499,     0,     0,     0,     0,     0,     0,
       0,     0,   252,   253,   254,   255,   159,     0,     0,     0,
       0,     0,     0,  1513,   161,     0,     0,   162,     0,     0,
     163,   164,   256,  1520,     0,   166,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1531,  1532,     0,     0,
       0,   321,   321,     0,     0,     0,     0,     0,     0,     0,
    1541,  1542,     0,   192,   193,   194,     0,     0,     0,   198,
     199,   200,     0,   202,     0,   204,   205,   206,     0,     0,
       0,     0,   211,   212,   213,   214,   215,   216,   217,     0,
       0,   220,     0,   222,     0,   224,     0,     0,   226,     0,
     228,     0,     0,   230,     0,     0,   232,   233,     0,   234,
     235,     0,   237,     0,   239,     0,     0,     0,     0,     0,
       0,     0,   242,     0,     0,     0,     0,     0,     0,   607,
     608,   257,   917,     0,     0,  1591,   609,   610,   611,   612,
     613,   614,   615,   616,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   336,   338,
       0,     0,   617,   618,   619,   620,     0,     0,     0,   352,
    1221,   367,   368,   370,   372,   375,   380,   381,   385,   387,
     389,     0,     0,     0,     0,   399,   401,   403,   405,   406,
     407,   413,   418,   426,   433,   435,   437,   607,   608,     0,
       0,     0,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,   607,   608,     0,     0,     0,     0,     0,   609,
     610,   611,   612,   613,   614,   615,   616,     0,     0,   649,
       0,     0,     0,     0,  1674,     0,     0,     0,     0,  1678,
     607,   608,     0,     0,     0,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1701,  1702,  1703,     0,  1705,     0,     0,     0,   519,     0,
       0,  1711,     0,     0,     0,  1715,  1716,     0,     0,     0,
       0,  1721,     0,  1722,  1724,     0,     0,     0,  1728,     0,
       0,     0,     0,     0,     0,     0,  1737,     0,     0,  1740,
    1741,     0,  1742,     0,     0,  1745,     0,     0,     0,     0,
    1750,     0,   617,   618,   619,   620,   607,   608,     0,     0,
    1222,  1758,     0,   609,   610,   611,   612,   613,   614,   615,
     616,     0,     0,     0,     0,     0,     0,     0,     0,  1767,
       0,  1769,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1773,     0,     0,     0,     0,     0,     0,     0,     0,
    1776,     0,  1777,     0,     0,     0,     0,  1779,     0,     0,
       0,     0,     0,     0,     0,     0,  1782,     0,     0,     0,
     617,   618,   619,   620,     0,     0,  1791,     0,  1224,  1794,
       0,     0,     0,     0,     0,   617,   618,   619,   620,     0,
       0,   607,   608,  1235,     0,     0,     0,     0,   609,   610,
     611,   612,   613,   614,   615,   616,     0,     0,  1815,  1816,
       0,     0,  1819,   617,   618,   619,   620,     0,     0,   686,
    1825,  1236,     0,     0,     0,   691,     0,     0,     0,  1831,
    1832,     0,   698,   700,  1835,     0,     0,     0,     0,  1838,
       0,     0,     0,  1842,   704,   705,   706,   707,   708,   709,
     710,     0,     0,   713,   714,   715,   716,     0,   607,   608,
    1857,     0,     0,     0,     0,   609,   610,   611,   612,   613,
     614,   615,   616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1878,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1891,     0,     0,   617,
     618,   619,   620,     0,     0,     0,     0,  1238,  1896,     0,
    1898,     0,  1900,     0,     0,     0,     0,     0,  1906,     0,
       0,  1909,     0,  1911,     0,     0,  1914,  1915,     0,     0,
    1918,     0,     0,     0,     0,     0,     0,  1923,     0,  1925,
    1926,  1927,     0,     0,  1930,     0,     0,     0,     0,     0,
    1936,     0,     0,     0,     0,     0,     0,     0,   819,   820,
     821,     0,     0,  1944,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1945,     0,     0,     0,     0,   844,
       0,     0,  1952,  1953,   617,   618,   619,   620,   607,   608,
       0,     0,  1241,     0,     0,   609,   610,   611,   612,   613,
     614,   615,   616,     0,     0,     0,     0,     0,     0,     0,
    1975,     0,     0,  1977,     0,     0,     0,  1980,     0,  1981,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   617,   618,   619,   620,     0,     0,     0,  2016,  1265,
    2018,     0,     0,  2021,     0,     0,     0,     0,     0,     0,
       0,  2026,     0,     0,  2027,     0,     0,     0,  2031,     0,
       0,     0,     0,     0,     0,     0,  2034,     0,  2036,     0,
       0,     0,   607,   608,     0,     0,     0,     0,     0,   609,
     610,   611,   612,   613,   614,   615,   616,     0,     0,     0,
    2048,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2057,     0,
    2059,     0,     0,     0,     0,     0,     0,     0,   125,   126,
     127,     0,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,  2078,     0,     0,     0,     0,     0,     0,
       0,     0,  2083,     0,     0,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   617,   618,   619,   620,     0,  1050,     0,     0,  1307,
    1053,     0,     0,     0,  1057,     0,     0,     0,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,  1071,
    1072,     0,     0,     0,     0,     0,   141,  1078,     0,   142,
       0,     0,  1082,     0,   317,     0,     0,  1087,     0,  1089,
       0,     0,   318,     0,     0,     0,   144,   145,     0,     0,
     146,  1101,   147,  1103,     0,  1105,     0,  1107,  1108,  1109,
     148,     0,     0,     0,     0,  1113,     0,   149,     0,     0,
    1117,   150,   151,     0,     0,     0,     0,     0,  1123,     0,
       0,   152,     0,   153,   154,     0,  1130,     0,     0,   155,
     156,   157,   158,   159,   160,   617,   618,   619,   620,     0,
       0,   161,     0,  1525,   162,     0,     0,   163,   164,   165,
       0,     0,   166,   167,   168,   169,   170,     0,     0,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,     0,   225,   226,   227,   228,     0,   229,
     230,     0,   231,   232,   233,     0,   234,   235,   236,   237,
     238,   239,   240,     0,     0,     0,     0,     0,   241,   242,
       0,   243,     0,     0,   607,   608,     0,     0,   244,     0,
     319,   609,   610,   611,   612,   613,   614,   615,   616,   607,
     608,     0,     0,     0,     0,     0,   609,   610,   611,   612,
     613,   614,   615,   616,     0,   607,   608,     0,     0,     0,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
       0,     0,     0,     0,     0,     0,   607,   608,     0,     0,
       0,     0,     0,   609,   610,   611,   612,   613,   614,   615,
     616,     0,     0,     0,     0,     0,     0,   607,   608,     0,
       0,     0,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,   126,   127,     0,   128,   129,   130,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1335,     0,     0,
     132,   133,     0,     0,     0,  1339,     0,     0,     0,     0,
    1344,     0,  1346,     0,  1348,  1349,     0,     0,     0,  1354,
    1355,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
       0,     0,     0,     0,     0,     0,     0,   617,   618,   619,
     620,   141,     0,     0,   142,  1609,     0,     0,     0,   143,
       0,     0,   617,   618,   619,   620,     0,   833,     0,     0,
    1610,   144,   145,     0,     0,   146,     0,   147,   617,   618,
     619,   620,     0,     0,     0,   148,  1617,     0,     0,     0,
       0,     0,   149,     0,     0,     0,   150,   151,     0,   617,
     618,   619,   620,     0,     0,     0,   152,  1618,   153,   154,
       0,  1444,  1445,     0,   155,   156,   157,   158,   159,   160,
     617,   618,   619,   620,     0,     0,   161,     0,  1619,   162,
       0,     0,   163,   164,   165,     0,  1460,   166,   167,   168,
     169,   170,     0,     0,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,     0,   225,
     226,   227,   228,     0,   229,   230,     0,   231,   232,   233,
       0,   234,   235,   236,   237,   238,   239,   240,     0,     0,
       0,     0,     0,   241,   242,     0,   243,     0,     0,     0,
       0,     0,     0,   244,     0,   319,   125,   126,   127,     0,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,     0,     0,
       0,     0,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,   153,   154,     0,     0,     0,     0,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,   161,
       0,     0,   162,     0,     0,   163,   164,   165,     0,     0,
     166,   167,   168,   169,   170,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,   226,   227,   228,     0,   229,   230,     0,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,     0,     0,     0,     0,     0,   241,   242,     0,   243,
       0,     0,     0,     0,     0,     0,   244,  1697,   319,     0,
    1700,     0,     0,     0,  1704,     0,     0,     0,     0,     0,
     125,   126,   127,     0,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   132,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1761,     0,     0,     0,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,     0,
       0,   142,   607,   608,     0,     0,   143,     0,     0,   609,
     610,   611,   612,   613,   614,   615,   616,     0,   144,   145,
       0,     0,   146,     0,   147,     0,     0,     0,     0,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,   149,
       0,     0,     0,   150,   151,     0,     0,     0,     0,     0,
       0,     0,     0,   152,     0,   153,   154,     0,     0,     0,
       0,   155,   156,   157,   158,   159,   160,     0,     0,     0,
       0,     0,     0,   161,     0,     0,   162,     0,     0,   163,
     164,   165,     0,     0,   166,   167,   168,   169,   170,     0,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,     0,   225,   226,   227,   228,
       0,   229,   230,     0,   231,   232,   233,     0,   234,   235,
     236,   237,   238,   239,   240,     0,     0,     0,  1895,     0,
     241,   242,  1899,   243,     0,     0,     0,     0,     0,     0,
     244,   811,   125,   126,   127,     0,   128,   129,   130,   131,
       0,     0,     0,     0,     0,   617,   618,   619,   620,     0,
       0,     0,     0,  1620,     0,     0,     0,     0,     0,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   607,   608,     0,     0,   143,     0,
       0,   609,   610,   611,   612,   613,   614,   615,   616,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
       0,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,   149,     0,     0,     0,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,   153,   154,     0,
       0,     0,     0,   155,   156,   157,   158,   159,   160,     0,
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
       0,     0,   244,   897,   125,   126,   127,     0,   128,   129,
     130,   131,     0,     0,     0,     0,     0,   617,   618,   619,
     620,     0,     0,     0,     0,  1621,     0,     0,     0,     0,
       0,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,     0,     0,   142,   607,   608,     0,     0,
     143,     0,     0,   609,   610,   611,   612,   613,   614,   615,
     616,     0,   144,   145,     0,     0,   146,     0,   147,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     0,     0,
       0,     0,     0,   149,     0,     0,     0,   150,   151,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,   153,
     154,     0,     0,     0,     0,   155,   156,   157,   158,   159,
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
       0,     0,     0,     0,   244,   908,   125,   126,   127,     0,
     128,   129,   130,   131,     0,     0,     0,     0,     0,   617,
     618,   619,   620,     0,     0,     0,     0,  1626,     0,     0,
       0,     0,     0,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,     0,     0,
       0,     0,   143,     0,     0,     0,     0,     0,   419,     0,
       0,     0,     0,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,   153,   154,     0,     0,   420,   421,   155,   156,   157,
     158,   159,   160,     0,   422,   423,   424,   425,     0,   161,
       0,     0,   162,     0,     0,   163,   164,   165,     0,     0,
     166,   167,   168,   169,   170,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,   226,   227,   228,     0,   229,   230,     0,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,     0,     0,     0,     0,     0,   241,   242,     0,   243,
       0,     0,     0,   125,   126,   127,   244,   128,   129,   130,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     132,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   427,     0,   134,   135,   136,   137,   138,   139,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,   142,     0,     0,     0,     0,   143,
       0,     0,     0,     0,     0,   428,     0,     0,     0,     0,
       0,   144,   145,     0,     0,   146,     0,   147,     0,     0,
       0,     0,     0,     0,     0,   148,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,   150,   151,     0,     0,
       0,     0,     0,     0,     0,     0,   152,     0,   153,   154,
       0,     0,   429,   430,   155,   156,   157,   158,   159,   160,
     431,     0,     0,     0,   432,     0,   161,     0,     0,   162,
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
       0,   142,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,   408,     0,     0,     0,     0,     0,   144,   145,
       0,     0,   146,     0,   147,     0,     0,     0,     0,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,   149,
       0,     0,     0,   150,   151,     0,     0,     0,     0,     0,
       0,     0,     0,   152,     0,   153,   154,     0,     0,   409,
     410,   155,   156,   157,   158,   159,   160,     0,   411,     0,
       0,   412,     0,   161,     0,     0,   162,     0,     0,   163,
     164,   165,     0,     0,   166,   167,   168,   169,   170,     0,
       0,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,     0,   225,   226,   227,   228,
       0,   229,   230,     0,   231,   232,   233,     0,   234,   235,
     236,   237,   238,   239,   240,     0,     0,     0,     0,     0,
     241,   242,     0,   243,     0,     0,     0,   125,   126,   127,
     244,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   376,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,     0,
       0,     0,     0,   143,     0,     0,     0,     0,     0,   377,
       0,     0,     0,     0,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,     0,   378,     0,     0,     0,   148,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
     150,   151,     0,     0,     0,     0,     0,     0,     0,     0,
     152,     0,   153,   154,     0,     0,   379,     0,   155,   156,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,     0,     0,   142,     0,     0,     0,     0,
     143,     0,     0,     0,     0,     0,   414,     0,     0,     0,
       0,     0,   144,   145,     0,     0,   146,     0,   147,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     0,     0,
       0,     0,     0,   149,     0,     0,     0,   150,   151,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,   153,
     154,     0,     0,   415,   416,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,   417,     0,   161,     0,     0,
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
       0,   125,   126,   127,   244,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     382,     0,     0,     0,     0,     0,     0,     0,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   383,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,   607,   608,     0,     0,   143,     0,     0,
     609,   610,   611,   612,   613,   614,   615,   616,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,   384,
       0,     0,     0,   148,     0,     0,     0,     0,     0,     0,
     149,     0,     0,     0,   150,   151,     0,     0,     0,     0,
       0,     0,     0,     0,   152,     0,   153,   154,     0,     0,
       0,     0,   155,   156,   157,   158,   159,   160,     0,     0,
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
       0,     0,     0,     0,     0,     0,   617,   618,   619,   620,
       0,     0,     0,     0,  1627,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,     0,   142,
     607,   608,     0,     0,   143,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,     0,   144,   145,     0,     0,
     146,     0,   147,     0,     0,     0,   396,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,   150,   151,     0,     0,     0,     0,     0,     0,     0,
       0,   152,     0,   153,   154,     0,     0,   397,   398,   155,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
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
       0,   243,     0,     0,     0,   125,   126,   127,   244,   128,
     129,   130,   131,     0,   334,     0,     0,     0,     0,     0,
       0,     0,     0,   617,   618,   619,   620,     0,     0,     0,
       0,  1636,   132,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   335,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   135,   136,   137,   138,
     139,   140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,     0,     0,   142,   607,   608,     0,
       0,   143,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,     0,   144,   145,     0,     0,   146,     0,   147,
       0,     0,     0,     0,     0,     0,     0,   148,     0,     0,
       0,     0,     0,     0,   149,     0,     0,     0,   150,   151,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
     153,   154,     0,     0,     0,     0,   155,   156,   157,   158,
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
     617,   618,   619,   620,     0,     0,     0,     0,  1637,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,     0,     0,     0,     0,   143,     0,
       0,     0,     0,     0,   373,     0,     0,     0,     0,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
     374,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,   149,     0,     0,     0,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,   153,   154,     0,
       0,     0,     0,   155,   156,   157,   158,   159,   160,     0,
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
       0,     0,   241,   242,     0,   243,     0,     0,     0,   125,
     126,   127,   244,   128,   129,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   132,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   134,
     135,   136,   137,   138,   139,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,     0,     0,
     142,   607,   608,     0,     0,   143,     0,     0,   609,   610,
     611,   612,   613,   614,   615,   616,     0,   144,   145,     0,
       0,   146,     0,   147,     0,     0,     0,     0,   447,     0,
       0,   148,     0,     0,     0,     0,     0,     0,   149,     0,
       0,     0,   150,   151,     0,     0,     0,     0,     0,     0,
       0,     0,   152,     0,   153,   154,     0,     0,     0,   448,
     155,   156,   157,   158,   159,   160,     0,     0,     0,     0,
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
       0,     0,     0,     0,   617,   618,   619,   620,     0,     0,
       0,     0,  1638,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   607,   608,
       0,     0,   143,     0,     0,   609,   610,   611,   612,   613,
     614,   615,   616,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,     0,   484,   485,     0,   148,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,   153,   154,     0,     0,     0,     0,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,   161,
       0,     0,   162,     0,     0,   163,   164,   165,     0,     0,
     166,   167,   168,   169,   170,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,   226,   227,   228,     0,   229,   230,     0,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,     0,     0,     0,     0,     0,   241,   242,     0,   243,
       0,     0,     0,   125,   126,   127,   244,   128,   129,   130,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   617,   618,   619,   620,     0,     0,     0,     0,  1639,
     132,   133,     0,     0,   276,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,   142,   607,   608,     0,     0,   143,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
       0,   144,   145,     0,     0,   146,     0,   147,     0,     0,
       0,     0,     0,     0,     0,   148,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,   150,   151,     0,     0,
       0,     0,     0,     0,     0,     0,   152,     0,   153,   154,
       0,     0,     0,     0,   155,   156,   157,   158,   159,   160,
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
       0,     0,     0,     0,     0,     0,     0,     0,   617,   618,
     619,   620,     0,     0,     0,     0,  1640,   132,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,     0,
       0,   142,   607,   608,     0,     0,   143,     0,     0,   609,
     610,   611,   612,   613,   614,   615,   616,     0,   144,   145,
       0,     0,   146,     0,   147,     0,     0,     0,   337,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,   149,
       0,     0,     0,   150,   151,     0,     0,     0,     0,     0,
       0,     0,     0,   152,     0,   153,   154,     0,     0,     0,
       0,   155,   156,   157,   158,   159,   160,     0,     0,     0,
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
     241,   242,     0,   243,     0,     0,     0,   125,   126,   127,
     244,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   617,   618,   619,   620,     0,
       0,     0,     0,  1643,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   607,
     608,     0,     0,   143,     0,     0,   609,   610,   611,   612,
     613,   614,   615,   616,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,     0,   369,     0,     0,     0,   148,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
     150,   151,     0,     0,     0,     0,     0,     0,     0,     0,
     152,     0,   153,   154,     0,     0,     0,     0,   155,   156,
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
       0,     0,   617,   618,   619,   620,     0,     0,     0,     0,
    1644,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   141,     0,     0,   142,   607,   608,     0,     0,
     143,     0,     0,   609,   610,   611,   612,   613,   614,   615,
     616,     0,   144,   145,     0,     0,   146,     0,   147,     0,
       0,     0,   371,     0,     0,     0,   148,     0,     0,     0,
       0,     0,     0,   149,     0,     0,     0,   150,   151,     0,
       0,     0,     0,     0,     0,     0,     0,   152,     0,   153,
     154,     0,     0,     0,     0,   155,   156,   157,   158,   159,
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
       0,   125,   126,   127,   244,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   617,
     618,   619,   620,     0,     0,     0,     0,  1647,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,   607,   608,     0,     0,   143,     0,     0,
     609,   610,   611,   612,   613,   614,   615,   616,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,   386,
       0,     0,     0,   148,     0,     0,     0,     0,     0,     0,
     149,     0,     0,     0,   150,   151,     0,     0,     0,     0,
       0,     0,     0,     0,   152,     0,   153,   154,     0,     0,
       0,     0,   155,   156,   157,   158,   159,   160,     0,     0,
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
       0,     0,     0,     0,     0,     0,   617,   618,   619,   620,
       0,     0,     0,     0,  1655,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,     0,   142,
     607,   608,     0,     0,   143,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,     0,   144,   145,     0,     0,
     146,     0,   147,     0,     0,     0,   388,     0,     0,     0,
     148,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,   150,   151,     0,     0,     0,     0,     0,     0,     0,
       0,   152,     0,   153,   154,     0,     0,     0,     0,   155,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
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
       0,   243,     0,     0,     0,   125,   126,   127,   244,   128,
     129,   130,   131,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   617,   618,   619,   620,     0,     0,     0,
       0,  1658,   132,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   134,   135,   136,   137,   138,
     139,   140,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,     0,     0,   142,   607,   608,     0,
       0,   143,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,     0,   144,   145,     0,     0,   146,     0,   147,
       0,     0,     0,   400,     0,     0,     0,   148,     0,     0,
       0,     0,     0,     0,   149,     0,     0,     0,   150,   151,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
     153,   154,     0,     0,     0,     0,   155,   156,   157,   158,
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
     617,   618,   619,   620,     0,     0,     0,     0,  1673,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   607,   608,     0,     0,   143,     0,
       0,   609,   610,   611,   612,   613,   614,   615,   616,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
     402,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,   149,     0,     0,     0,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,   153,   154,     0,
       0,     0,     0,   155,   156,   157,   158,   159,   160,     0,
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
       0,     0,   241,   242,     0,   243,     0,     0,     0,   125,
     126,   127,   244,   128,   129,   130,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   617,   618,   619,
     620,     0,     0,     0,     0,  1789,   132,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   134,
     135,   136,   137,   138,   139,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,     0,     0,
     142,   607,   608,     0,     0,   143,     0,     0,   609,   610,
     611,   612,   613,   614,   615,   616,     0,   144,   145,     0,
       0,   146,     0,   147,     0,     0,     0,   404,     0,     0,
       0,   148,     0,     0,     0,     0,     0,     0,   149,     0,
       0,     0,   150,   151,     0,     0,     0,     0,     0,     0,
       0,     0,   152,     0,   153,   154,     0,     0,     0,     0,
     155,   156,   157,   158,   159,   160,     0,     0,     0,     0,
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
       0,     0,     0,     0,   617,   618,   619,   620,     0,     0,
       0,     0,  1793,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   607,   608,
       0,     0,   143,     0,     0,   609,   610,   611,   612,   613,
     614,   615,   616,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,   434,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,   153,   154,     0,     0,     0,     0,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,   161,
       0,     0,   162,     0,     0,   163,   164,   165,     0,     0,
     166,   167,   168,   169,   170,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,     0,   225,   226,   227,   228,     0,   229,   230,     0,
     231,   232,   233,     0,   234,   235,   236,   237,   238,   239,
     240,     0,     0,     0,     0,     0,   241,   242,     0,   243,
       0,     0,     0,   125,   126,   127,   244,   128,   129,   130,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   617,   618,   619,   620,     0,     0,     0,     0,  1855,
     132,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,   135,   136,   137,   138,   139,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,     0,     0,   142,   607,   608,     0,     0,   143,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
       0,   144,   145,     0,     0,   146,     0,   147,     0,     0,
       0,   436,     0,     0,     0,   148,     0,     0,     0,     0,
       0,     0,   149,     0,     0,     0,   150,   151,     0,     0,
       0,     0,     0,     0,     0,     0,   152,     0,   153,   154,
       0,     0,     0,     0,   155,   156,   157,   158,   159,   160,
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
     125,   126,   127,   244,   128,   129,   130,   131,     0,   699,
       0,     0,     0,     0,     0,     0,     0,     0,   617,   618,
     619,   620,     0,     0,     0,     0,  1865,   132,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,   135,   136,   137,   138,   139,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,     0,
       0,   142,   607,   608,     0,     0,   143,     0,     0,   609,
     610,   611,   612,   613,   614,   615,   616,     0,   144,   145,
       0,     0,   146,     0,   147,     0,     0,     0,     0,     0,
       0,     0,   148,     0,     0,     0,     0,     0,     0,   149,
       0,     0,     0,   150,   151,     0,     0,     0,     0,     0,
       0,     0,     0,   152,     0,   153,   154,     0,     0,     0,
       0,   155,   156,   157,   158,   159,   160,     0,     0,     0,
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
     241,   242,     0,   243,     0,     0,     0,   125,   126,   127,
     244,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   617,   618,   619,   620,     0,
       0,     0,     0,  1868,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   607,
     608,     0,     0,   143,     0,     0,   609,   610,   611,   612,
     613,   614,   615,   616,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
     150,   151,     0,     0,     0,     0,     0,     0,     0,     0,
     152,     0,   153,   154,     0,     0,     0,     0,   155,   156,
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
     239,   240,     0,     0,   127,     0,     0,   241,   242,   131,
     243,     0,     0,     0,     0,     0,     0,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,   617,   618,   619,   620,     0,     0,     0,     0,
    1869,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   607,   608,     0,     0,     0,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
     607,   608,     0,     0,     0,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,     0,     0,     0,     0,     0,
     607,   608,     0,     0,   146,     0,   147,   609,   610,   611,
     612,   613,   614,   615,   616,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,   151,     0,   127,     0,
       0,     0,     0,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,   253,   254,   255,   159,     0,     0,
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
     151,     0,   127,   242,     0,     0,     0,   131,   617,   618,
     619,   620,   257,   919,     0,     0,  1871,   252,   253,   254,
     255,   159,     0,   617,   618,   619,   620,     0,   133,   161,
       0,  1888,   162,     0,     0,   163,   164,   256,     0,     0,
     166,   167,     0,   617,   618,   619,   620,     0,     0,     0,
       0,  1998,   607,   608,     0,     0,     0,     0,     0,   609,
     610,   611,   612,   613,   614,   615,   616,     0,   192,   193,
     194,     0,     0,     0,   198,   199,   200,     0,   202,     0,
     204,   205,   206,     0,     0,     0,     0,   211,   212,   213,
     214,   215,   216,   217,     0,     0,   220,     0,   222,     0,
     224,     0,   146,   226,   147,   228,     0,     0,   230,     0,
       0,   232,   233,     0,   234,   235,     0,   237,     0,   239,
       0,     0,     0,   150,   151,     0,     0,   242,   127,     0,
       0,     0,     0,   131,     0,     0,   257,   921,     0,     0,
       0,   252,   253,   254,   255,   159,     0,     0,     0,     0,
       0,     0,     0,   161,   133,     0,   162,     0,     0,   163,
     164,   256,     0,     0,   166,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   607,   608,     0,
       0,     0,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,   192,   193,   194,     0,     0,     0,   198,   199,
     200,     0,   202,     0,   204,   205,   206,     0,     0,     0,
       0,   211,   212,   213,   214,   215,   216,   217,     0,     0,
     220,     0,   222,     0,   224,     0,     0,   226,   146,   228,
     147,     0,   230,     0,   390,   232,   233,     0,   234,   235,
       0,   237,     0,   239,     0,   617,   618,   619,   620,   150,
     151,   242,     0,  2011,   127,     0,     0,     0,     0,   131,
     257,   923,     0,     0,     0,     0,     0,   252,   253,   254,
     255,   159,     0,     0,     0,     0,     0,     0,     0,   161,
     133,     0,   162,     0,     0,   163,   164,   256,     0,     0,
     166,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   607,   608,     0,     0,     0,     0,     0,
     609,   610,   611,   612,   613,   614,   615,   616,   192,   193,
     194,     0,     0,     0,   198,   199,   200,     0,   202,     0,
     204,   205,   206,     0,     0,     0,     0,   211,   212,   213,
     214,   215,   216,   217,     0,     0,   220,     0,   222,     0,
     224,     0,     0,   226,   146,   228,   147,     0,   230,     0,
     438,   232,   233,     0,   234,   235,     0,   237,     0,   239,
     617,   618,   619,   620,     0,   150,   151,   242,  2054,     0,
     127,     0,     0,     0,     0,   131,   257,     0,     0,     0,
       0,     0,     0,   252,   253,   254,   255,   159,     0,     0,
       0,     0,     0,     0,     0,   161,   133,     0,   162,     0,
       0,   163,   164,   256,     0,     0,   166,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,   193,   194,     0,     0,     0,
     198,   199,   200,     0,   202,     0,   204,   205,   206,     0,
       0,     0,     0,   211,   212,   213,   214,   215,   216,   217,
       0,     0,   220,     0,   222,     0,   224,     0,     0,   226,
     146,   228,   147,     0,   230,     0,   440,   232,   233,     0,
     234,   235,     0,   237,     0,   239,   617,   618,   619,   620,
       0,   150,   151,   242,  2075,     0,   127,     0,     0,     0,
       0,   131,   257,     0,     0,     0,     0,     0,     0,   252,
     253,   254,   255,   159,     0,     0,     0,     0,     0,     0,
       0,   161,   133,     0,   162,     0,     0,   163,   164,   256,
       0,     0,   166,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,   194,     0,     0,     0,   198,   199,   200,     0,
     202,     0,   204,   205,   206,     0,     0,     0,     0,   211,
     212,   213,   214,   215,   216,   217,     0,     0,   220,     0,
     222,     0,   224,     0,     0,   226,   146,   228,   147,     0,
     230,     0,   442,   232,   233,     0,   234,   235,     0,   237,
       0,   239,     0,     0,     0,     0,     0,   150,   151,   242,
     127,     0,     0,     0,     0,   131,     0,     0,   257,     0,
       0,     0,     0,     0,     0,   252,   253,   254,   255,   159,
       0,     0,     0,     0,     0,     0,   133,   161,     0,     0,
     162,     0,     0,   163,   164,   256,     0,     0,   166,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,   193,   194,     0,
       0,     0,   198,   199,   200,     0,   202,     0,   204,   205,
     206,     0,     0,     0,     0,   211,   212,   213,   214,   215,
     216,   217,     0,     0,   220,     0,   222,     0,   224,     0,
     146,   226,   147,   228,     0,     0,   230,     0,     0,   232,
     233,     0,   234,   235,     0,   237,     0,   239,     0,     0,
       0,   150,   151,     0,   127,   242,     0,     0,     0,   131,
       0,     0,     0,     0,   257,     0,     0,     0,     0,   252,
     253,   254,   255,   159,     0,   781,     0,     0,     0,     0,
     133,   161,     0,     0,   162,     0,     0,   163,   164,   256,
       0,     0,   166,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,   194,     0,     0,     0,   198,   199,   200,     0,
     202,     0,   204,   205,   206,     0,     0,     0,     0,   211,
     212,   213,   214,   215,   216,   217,     0,     0,   220,     0,
     222,     0,   224,     0,   146,   226,   147,   228,     0,     0,
     230,     0,     0,   232,   233,     0,   234,   235,     0,   237,
       0,   239,     0,     0,     0,   150,   151,     0,   127,   242,
       0,     0,     0,   131,     0,     0,     0,     0,   257,     0,
       0,     0,     0,   252,   253,   254,   255,   159,     0,   865,
       0,     0,     0,     0,   133,   161,     0,     0,   162,     0,
       0,   163,   164,   256,     0,     0,   166,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,   193,   194,     0,     0,     0,
     198,   199,   200,     0,   202,     0,   204,   205,   206,     0,
       0,     0,     0,   211,   212,   213,   214,   215,   216,   217,
    1043,     0,   220,     0,   222,     0,   224,     0,   146,   226,
     147,   228,     0,     0,   230,     0,     0,   232,   233,     0,
     234,   235,     0,   237,     0,   239,     0,     0,     0,   150,
     151,     0,   127,   242,     0,     0,     0,   131,     0,     0,
       0,     0,   257,     0,     0,     0,     0,   252,   253,   254,
     255,   159,     0,     0,     0,     0,     0,     0,   133,   161,
       0,     0,   162,     0,     0,   163,   164,   256,     0,     0,
     166,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,   193,
     194,     0,     0,     0,   198,   199,   200,     0,   202,     0,
     204,   205,   206,     0,     0,     0,     0,   211,   212,   213,
     214,   215,   216,   217,  1453,     0,   220,     0,   222,     0,
     224,     0,   146,   226,   147,   228,     0,     0,   230,     0,
       0,   232,   233,     0,   234,   235,     0,   237,     0,   239,
       0,     0,     0,   150,   151,     0,   127,   242,     0,     0,
       0,   131,     0,     0,     0,     0,   257,     0,     0,     0,
       0,   252,   253,   254,   255,   159,     0,     0,     0,     0,
       0,     0,   133,   161,     0,     0,   162,     0,     0,   163,
     164,   256,     0,     0,   166,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   192,   193,   194,     0,     0,     0,   198,   199,
     200,     0,   202,     0,   204,   205,   206,     0,     0,     0,
       0,   211,   212,   213,   214,   215,   216,   217,     0,     0,
     220,     0,   222,     0,   224,     0,   146,   226,   147,   228,
       0,     0,   230,     0,     0,   232,   233,     0,   234,   235,
       0,   237,     0,   239,     0,     0,     0,   150,   151,     0,
     127,   242,     0,     0,     0,   131,     0,     0,     0,     0,
     257,     0,     0,     0,     0,   252,   253,   254,   255,   159,
       0,     0,     0,     0,     0,     0,   133,   161,     0,     0,
     162,     0,     0,   163,   164,   256,     0,     0,   166,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,   193,   194,     0,
       0,     0,   198,   199,   200,     0,   202,     0,   204,   205,
     206,     0,     0,     0,     0,   211,   212,   213,   214,   215,
     216,   217,     0,     0,   220,     0,   222,     0,   224,     0,
     146,   226,   147,   228,     0,     0,   230,     0,     0,   232,
     233,     0,   234,   235,     0,   237,     0,   239,     0,     0,
       0,   150,   151,     0,     0,   242,     0,     0,     0,     0,
       0,     0,     0,     0,   257,     0,     0,     0,     0,   252,
     253,   254,   255,   159,     0,     0,     0,     0,     0,     0,
       0,   161,     0,     0,   162,     0,     0,   163,   164,   256,
       0,     0,   166,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,   194,     0,     0,     0,   198,   199,   200,     0,
     202,     0,   204,   205,   206,     0,     0,     0,     0,   211,
     212,   213,   214,   215,   216,   217,     0,     0,   220,     0,
     222,     0,   224,     0,     0,   226,     0,   228,     0,     0,
     230,     0,     0,   232,   233,     0,   234,   235,     0,   237,
       0,   239,     0,     0,     7,     8,     9,     0,     0,   242,
       0,    10,     0,     0,     0,    11,     0,    12,  1308,    13,
      14,    15,    16,    17,  -495,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,     0,     0,
       0,     0,    29,     0,     0,    30,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,    45,
      46,    47,  -242,  -242,    48,    49,    50,     0,    51,    52,
      53,     0,     0,    54,  -242,     0,    55,     0,    56,    57,
       0,     0,     0,     0,    58,    59,     0,     0,     0,     0,
       0,    60,     0,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,     0,    80,    81,    82,    83,    84,    85,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,     0,     0,     0,    90,    91,    92,     0,     0,    93,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,     0,
       0,     0,    99,     0,     0,   607,   608,     0,     0,     0,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
       0,     0,     0,     0,   100,     0,     0,     0,   101,     0,
       7,     8,     9,   102,     0,     0,   103,    10,     0,     0,
     104,    11,     0,    12,     0,    13,    14,    15,    16,    17,
    -495,     0,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,     0,     0,     0,     0,    29,   -16,
     -16,    30,     0,     0,     0,     0,     0,     0,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    37,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    40,    41,    42,    43,    44,
       0,     0,     0,     0,     0,    45,    46,    47,     0,     0,
      48,    49,    50,     0,    51,    52,    53,     0,     0,    54,
       0,     0,    55,     0,    56,    57,     0,     0,     0,     0,
      58,    59,     0,     0,     0,     0,     0,    60,     0,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,     0,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,     0,     0,     0,
      90,    91,    92,     0,     0,    93,    94,    95,   617,   618,
     619,   620,     0,     0,     0,     0,  2090,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,     0,     0,     0,    99,     0,
       0,   607,   608,     0,     0,     0,     0,     0,   609,   610,
     611,   612,   613,   614,   615,   616,     0,     0,     0,     0,
     100,     0,     0,     0,   101,     0,     7,     8,     9,   102,
       0,     0,   103,    10,     0,     0,   104,    11,     0,    12,
       0,    13,    14,    15,    16,    17,  -495,     0,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,    28,
     -16,     0,     0,     0,    29,   -16,     0,    30,     0,     0,
       0,     0,     0,     0,    31,    32,    33,    34,    35,    36,
     607,   608,     0,    37,    38,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,     0,     0,     0,     0,     0,
      39,    40,    41,    42,    43,    44,     0,     0,     0,     0,
       0,    45,    46,    47,     0,     0,    48,    49,    50,     0,
      51,    52,    53,     0,     0,    54,     0,     0,    55,     0,
      56,    57,     0,     0,     0,     0,    58,    59,     0,     0,
       0,     0,     0,    60,     0,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,    80,    81,    82,    83,
      84,    85,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,     0,     0,     0,    90,    91,    92,     0,
       0,    93,    94,    95,   617,   618,   619,   620,   607,   608,
     673,     0,     0,     0,     0,   609,   610,   611,   612,   613,
     614,   615,   616,     0,     0,     0,     0,    96,    97,    98,
     607,   608,     0,     0,    99,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
     101,     0,     0,     0,     0,   102,   607,   608,   103,     0,
       0,     0,   104,   609,   610,   611,   612,   613,   614,   615,
     616,     0,     0,   617,   618,   619,   620,   607,   608,   690,
       0,     0,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,   607,   608,     0,     0,     0,     0,     0,   609,
     610,   611,   612,   613,   614,   615,   616,   607,   608,     0,
       0,     0,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,   607,   608,     0,     0,     0,     0,     0,   609,
     610,   611,   612,   613,   614,   615,   616,   607,   608,     0,
       0,     0,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,   607,   608,     0,     0,     0,     0,     0,   609,
     610,   611,   612,   613,   614,   615,   616,   607,   608,     0,
       0,     0,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   617,   618,   619,   620,   607,   608,   801,     0,     0,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
       0,     0,     0,   617,   618,   619,   620,   607,   608,  1040,
       0,     0,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,   607,   608,     0,     0,     0,     0,     0,   609,
     610,   611,   612,   613,   614,   615,   616,     0,     0,   617,
     618,   619,   620,   607,   608,  1070,     0,     0,     0,     0,
     609,   610,   611,   612,   613,   614,   615,   616,     0,     0,
     617,   618,   619,   620,     0,     0,  1167,     0,     0,     0,
       0,     0,     0,     0,     0,   617,   618,   619,   620,     0,
       0,  1168,     0,     0,     0,     0,     0,     0,     0,     0,
     617,   618,   619,   620,     0,     0,  1170,     0,     0,     0,
       0,     0,     0,     0,     0,   617,   618,   619,   620,     0,
       0,  1171,     0,     0,     0,     0,     0,     0,     0,     0,
     617,   618,   619,   620,     0,     0,  1172,     0,     0,     0,
       0,     0,     0,     0,     0,   617,   618,   619,   620,     0,
       0,  1186,     0,     0,     0,     0,     0,     0,     0,     0,
     617,   618,   619,   620,   607,   608,  1223,     0,     0,     0,
       0,   609,   610,   611,   612,   613,   614,   615,   616,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   617,   618,
     619,   620,   607,   608,  1230,     0,     0,     0,     0,   609,
     610,   611,   612,   613,   614,   615,   616,     0,     0,     0,
     617,   618,   619,   620,     0,     0,  1231,     0,     0,     0,
       0,     0,     0,     0,     0,   617,   618,   619,   620,   607,
     608,  1251,     0,     0,     0,     0,   609,   610,   611,   612,
     613,   614,   615,   616,     0,     0,   617,   618,   619,   620,
     607,   608,  1303,     0,     0,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,   607,   608,     0,     0,     0,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
     607,   608,     0,     0,     0,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,   607,   608,     0,     0,     0,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
     607,   608,     0,     0,     0,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,   607,   608,     0,     0,     0,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
     607,   608,     0,     0,     0,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,     0,     0,   617,   618,   619,
     620,   607,   608,  1326,     0,     0,     0,     0,   609,   610,
     611,   612,   613,   614,   615,   616,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   617,   618,   619,   620,   607,
     608,  1327,     0,     0,     0,     0,   609,   610,   611,   612,
     613,   614,   615,   616,   607,   608,     0,     0,     0,     0,
       0,   609,   610,   611,   612,   613,   614,   615,   616,     0,
       0,     0,   617,   618,   619,   620,   607,   608,  1334,     0,
       0,     0,     0,   609,   610,   611,   612,   613,   614,   615,
     616,     0,     0,   617,   618,   619,   620,     0,     0,  1340,
       0,     0,     0,     0,     0,     0,     0,     0,   617,   618,
     619,   620,     0,     0,  1341,     0,     0,     0,     0,     0,
       0,     0,     0,   617,   618,   619,   620,     0,     0,  1381,
       0,     0,     0,     0,     0,     0,     0,     0,   617,   618,
     619,   620,     0,     0,  1434,     0,     0,     0,     0,     0,
       0,     0,     0,   617,   618,   619,   620,     0,     0,  1440,
       0,     0,     0,     0,     0,     0,     0,     0,   617,   618,
     619,   620,     0,     0,  1441,     0,     0,     0,     0,     0,
       0,     0,     0,   617,   618,   619,   620,   607,   608,  1514,
       0,     0,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,     0,     0,   617,   618,   619,   620,   607,   608,
    1519,     0,     0,     0,     0,   609,   610,   611,   612,   613,
     614,   615,   616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   617,   618,   619,   620,     0,     0,  1533,     0,
       0,     0,     0,     0,     0,     0,     0,   617,   618,   619,
     620,   607,   608,  1545,     0,     0,     0,     0,   609,   610,
     611,   612,   613,   614,   615,   616,     0,     0,     0,   617,
     618,   619,   620,   607,   608,  1550,     0,     0,     0,     0,
     609,   610,   611,   612,   613,   614,   615,   616,   607,   608,
       0,     0,     0,     0,     0,   609,   610,   611,   612,   613,
     614,   615,   616,   607,   608,     0,     0,     0,     0,     0,
     609,   610,   611,   612,   613,   614,   615,   616,   607,   608,
       0,     0,     0,     0,     0,   609,   610,   611,   612,   613,
     614,   615,   616,   607,   608,     0,     0,     0,     0,     0,
     609,   610,   611,   612,   613,   614,   615,   616,   607,   608,
       0,     0,     0,     0,     0,   609,   610,   611,   612,   613,
     614,   615,   616,   607,   608,     0,     0,     0,     0,     0,
     609,   610,   611,   612,   613,   614,   615,   616,     0,     0,
     617,   618,   619,   620,   607,   608,  1551,     0,     0,     0,
       0,   609,   610,   611,   612,   613,   614,   615,   616,     0,
       0,   617,   618,   619,   620,   607,   608,  1552,     0,     0,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
     607,   608,     0,     0,     0,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   617,   618,   619,   620,   607,   608,
    1555,     0,     0,     0,     0,   609,   610,   611,   612,   613,
     614,   615,   616,     0,     0,     0,   617,   618,   619,   620,
       0,     0,  1583,     0,     0,     0,     0,     0,     0,     0,
       0,   617,   618,   619,   620,     0,     0,  1590,     0,     0,
       0,     0,     0,     0,     0,     0,   617,   618,   619,   620,
       0,     0,  1595,     0,     0,     0,     0,     0,     0,     0,
       0,   617,   618,   619,   620,     0,     0,  1598,     0,     0,
       0,     0,     0,     0,     0,     0,   617,   618,   619,   620,
       0,     0,  1631,     0,     0,     0,     0,     0,     0,     0,
       0,   617,   618,   619,   620,     0,     0,  1656,     0,     0,
       0,     0,     0,     0,     0,     0,   617,   618,   619,   620,
     607,   608,  1657,     0,     0,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,     0,     0,   617,   618,   619,
     620,   607,   608,  1679,     0,     0,     0,     0,   609,   610,
     611,   612,   613,   614,   615,   616,     0,     0,   617,   618,
     619,   620,     0,     0,  1693,     0,     0,     0,     0,     0,
       0,     0,     0,   617,   618,   619,   620,   607,   608,  1808,
       0,     0,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   617,   618,   619,   620,   607,   608,  1809,     0,     0,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
     607,   608,     0,     0,     0,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,   607,   608,     0,     0,     0,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
     607,   608,     0,     0,     0,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,   607,   608,     0,     0,     0,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
     607,   608,     0,     0,     0,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,   607,   608,     0,     0,     0,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
       0,     0,     0,   617,   618,   619,   620,   607,   608,  1810,
       0,     0,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,     0,     0,   617,   618,   619,   620,   607,   608,
    1812,     0,     0,     0,     0,   609,   610,   611,   612,   613,
     614,   615,   616,   607,   608,     0,     0,     0,     0,     0,
     609,   610,   611,   612,   613,   614,   615,   616,     0,     0,
     617,   618,   619,   620,   607,   608,  1818,     0,     0,     0,
       0,   609,   610,   611,   612,   613,   614,   615,   616,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   617,   618,
     619,   620,     0,     0,  1821,     0,     0,     0,     0,     0,
       0,     0,     0,   617,   618,   619,   620,     0,     0,  1826,
       0,     0,     0,     0,     0,     0,     0,     0,   617,   618,
     619,   620,     0,     0,  1827,     0,     0,     0,     0,     0,
       0,     0,     0,   617,   618,   619,   620,     0,     0,  1830,
       0,     0,     0,     0,     0,     0,     0,     0,   617,   618,
     619,   620,     0,     0,  1839,     0,     0,     0,     0,     0,
       0,     0,     0,   617,   618,   619,   620,     0,     0,  1840,
       0,     0,     0,     0,     0,     0,     0,     0,   617,   618,
     619,   620,   607,   608,  1841,     0,     0,     0,     0,   609,
     610,   611,   612,   613,   614,   615,   616,     0,     0,     0,
     617,   618,   619,   620,   607,   608,  1844,     0,     0,     0,
       0,   609,   610,   611,   612,   613,   614,   615,   616,     0,
       0,   617,   618,   619,   620,     0,     0,  1848,     0,     0,
       0,     0,     0,     0,     0,     0,   617,   618,   619,   620,
     607,   608,  1863,     0,     0,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,     0,     0,   617,   618,   619,
     620,   607,   608,  1883,     0,     0,     0,     0,   609,   610,
     611,   612,   613,   614,   615,   616,   607,   608,     0,     0,
       0,     0,     0,   609,   610,   611,   612,   613,   614,   615,
     616,   607,   608,     0,     0,     0,     0,     0,   609,   610,
     611,   612,   613,   614,   615,   616,   607,   608,     0,     0,
       0,     0,     0,   609,   610,   611,   612,   613,   614,   615,
     616,   607,   608,     0,     0,     0,     0,     0,   609,   610,
     611,   612,   613,   614,   615,   616,   607,   608,     0,     0,
       0,     0,     0,   609,   610,   611,   612,   613,   614,   615,
     616,   607,   608,     0,     0,     0,     0,     0,   609,   610,
     611,   612,   613,   614,   615,   616,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   617,   618,   619,   620,   607,
     608,  1903,     0,     0,     0,     0,   609,   610,   611,   612,
     613,   614,   615,   616,     0,     0,     0,   617,   618,   619,
     620,   607,   608,  1904,     0,     0,     0,     0,   609,   610,
     611,   612,   613,   614,   615,   616,   607,   608,     0,     0,
       0,     0,     0,   609,   610,   611,   612,   613,   614,   615,
     616,     0,     0,   617,   618,   619,   620,   607,   608,  1907,
       0,     0,     0,     0,   609,   610,   611,   612,   613,   614,
     615,   616,     0,     0,   617,   618,   619,   620,     0,     0,
    1913,     0,     0,     0,     0,     0,     0,     0,     0,   617,
     618,   619,   620,     0,     0,  1919,     0,     0,     0,     0,
       0,     0,     0,     0,   617,   618,   619,   620,     0,     0,
    1920,     0,     0,     0,     0,     0,     0,     0,     0,   617,
     618,   619,   620,     0,     0,  1921,     0,     0,     0,     0,
       0,     0,     0,     0,   617,   618,   619,   620,     0,     0,
    1924,     0,     0,     0,     0,     0,     0,     0,     0,   617,
     618,   619,   620,     0,     0,  1928,     0,     0,     0,     0,
       0,     0,     0,     0,   617,   618,   619,   620,   607,   608,
    1960,     0,     0,     0,     0,   609,   610,   611,   612,   613,
     614,   615,   616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   617,   618,   619,   620,   607,   608,  1962,     0,
       0,     0,     0,   609,   610,   611,   612,   613,   614,   615,
     616,     0,     0,     0,   617,   618,   619,   620,     0,     0,
    1963,     0,     0,     0,     0,     0,     0,     0,     0,   617,
     618,   619,   620,   607,   608,  1965,     0,     0,     0,     0,
     609,   610,   611,   612,   613,   614,   615,   616,     0,     0,
     617,   618,   619,   620,   607,   608,  1971,     0,     0,     0,
       0,   609,   610,   611,   612,   613,   614,   615,   616,   607,
     608,     0,     0,     0,     0,     0,   609,   610,   611,   612,
     613,   614,   615,   616,   607,   608,     0,     0,     0,     0,
       0,   609,   610,   611,   612,   613,   614,   615,   616,   607,
     608,     0,     0,     0,     0,     0,   609,   610,   611,   612,
     613,   614,   615,   616,   607,   608,     0,     0,     0,     0,
       0,   609,   610,   611,   612,   613,   614,   615,   616,   607,
     608,     0,     0,     0,     0,     0,   609,   610,   611,   612,
     613,   614,   615,   616,   607,   608,     0,     0,     0,     0,
       0,   609,   610,   611,   612,   613,   614,   615,   616,     0,
       0,   617,   618,   619,   620,   607,   608,  1974,     0,     0,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   617,
     618,   619,   620,   607,   608,  1978,     0,     0,     0,     0,
     609,   610,   611,   612,   613,   614,   615,   616,   607,   608,
       0,     0,     0,     0,     0,   609,   610,   611,   612,   613,
     614,   615,   616,     0,     0,     0,   617,   618,   619,   620,
     607,   608,  1986,     0,     0,     0,     0,   609,   610,   611,
     612,   613,   614,   615,   616,     0,     0,   617,   618,   619,
     620,     0,     0,  1987,     0,     0,     0,     0,     0,     0,
       0,     0,   617,   618,   619,   620,     0,     0,  1988,     0,
       0,     0,     0,     0,     0,     0,     0,   617,   618,   619,
     620,     0,     0,  1994,     0,     0,     0,     0,     0,     0,
       0,     0,   617,   618,   619,   620,     0,     0,  2010,     0,
       0,     0,     0,     0,     0,     0,     0,   617,   618,   619,
     620,     0,     0,  2028,     0,     0,     0,     0,     0,     0,
       0,     0,   617,   618,   619,   620,     0,     0,  2030,     0,
       0,     0,     0,     0,     0,     0,     0,   617,   618,   619,
     620,   607,   608,  2032,     0,     0,     0,     0,   609,   610,
     611,   612,   613,   614,   615,   616,     0,     0,   617,   618,
     619,   620,   607,   608,  2033,     0,     0,     0,     0,   609,
     610,   611,   612,   613,   614,   615,   616,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   617,   618,   619,   620,
       0,     0,  2053,     0,     0,     0,     0,     0,     0,     0,
       0,   617,   618,   619,   620,   607,   608,  2055,     0,     0,
       0,     0,   609,   610,   611,   612,   613,   614,   615,   616,
       0,     0,     0,   617,   618,   619,   620,     0,     0,  2062,
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
       0,     0,     0,     0,   617,   618,   619,   620,     0,     0,
    2081,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   617,   618,   619,   620,     0,
       0,  2082,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   617,   618,
     619,   620,     0,     0,  2094
};

static const yytype_int16 yycheck[] =
{
       3,    15,    16,     1,    44,     1,     4,    12,     4,   487,
      40,     4,    12,    98,     7,    75,     4,    75,    21,     7,
      58,    24,    60,    61,    61,    77,    58,    41,    60,    61,
      33,    25,    11,     4,    37,    38,     7,     4,     5,    42,
       3,    75,    76,    77,     7,     8,     9,    10,   456,   457,
      44,    54,    55,    56,     3,    53,    77,    53,     7,     8,
       9,    10,     0,  1682,    76,    77,    12,    70,    71,    72,
     262,    95,   264,    28,   111,    43,    44,   112,   113,   112,
     113,     4,     5,    86,    87,    88,    12,   111,   173,    92,
     270,    70,    71,    72,    73,    74,    75,    76,   101,   102,
     103,   104,    63,    64,  1315,  1316,    16,    13,   288,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,   262,
     155,   264,   155,     7,    70,    71,    72,    73,    74,    75,
      76,    77,   110,   101,    44,     4,     5,    63,    64,    73,
      74,    75,    76,    77,    70,    71,    72,    73,    74,    75,
      76,    77,     4,     5,   262,    95,   264,    63,    64,   112,
     113,   112,   113,   166,    70,    71,    72,    73,    74,    75,
      76,    77,   173,    70,    71,    72,    73,    74,    75,    76,
     262,   589,   264,   591,   160,    70,    71,    72,    73,    74,
      75,    76,    23,   112,   113,    70,    71,    72,    73,    74,
      75,    76,   155,   263,   155,   263,   258,   259,   112,    70,
      71,    72,    73,    74,    75,    76,   112,   257,   112,    81,
      82,   111,   256,   257,   258,   259,    88,   265,   195,   196,
     197,    44,   257,   265,   263,   256,   257,   258,   259,   264,
     262,   244,   264,   263,   256,   257,   258,   259,   100,   111,
      28,   155,   257,   257,   257,    33,   263,   262,   262,   155,
     264,   155,   262,   266,    74,    75,    76,    77,  1887,    75,
     263,  1890,   270,   263,   270,   263,    92,    93,   257,   282,
     257,   311,   312,   263,   287,   262,    75,   264,   104,    24,
     288,   294,   288,   256,   257,   256,   257,   258,   259,   257,
     257,   262,   162,   264,   262,   262,   264,   256,   257,    59,
     256,   257,   258,   259,   257,   318,   262,    35,    36,   262,
     161,   264,   256,   257,   258,   259,   329,   330,   331,   257,
     256,   257,   258,   259,   337,  1954,   264,   112,  1957,    89,
      90,    91,   257,   195,   196,   197,    96,   262,   257,   264,
     256,   257,   258,   259,   257,   264,   257,   360,   361,   262,
     257,   264,   257,   264,   263,   262,   369,   264,   371,   264,
     373,   374,   257,   376,   377,   378,   379,   262,   112,   382,
     383,   384,   257,   386,   263,   388,   263,   390,   172,   264,
     263,   394,   395,   396,   397,   398,   257,   400,   263,   402,
     263,   404,   112,   264,   263,   408,   409,   410,   411,   412,
     257,   414,   415,   416,   417,   262,   419,   420,   421,   422,
     423,   424,   425,   257,   427,   428,   429,   430,   431,   432,
     264,   434,   112,   436,   265,   438,   267,   440,   263,   442,
     263,   444,   445,   446,   447,   448,   256,   257,   258,   259,
      14,   263,    16,   112,    18,   263,   459,   112,  2077,    71,
    2079,    73,    74,    75,    76,    77,   257,   257,   471,   261,
     262,   262,  1683,   653,   264,  1686,  2095,    41,  2097,   482,
      44,   484,     4,     5,   263,    49,   263,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
       4,     5,   515,   112,   482,   483,   257,   520,   521,   257,
      63,    64,   172,   264,   262,   163,   264,    70,    71,    72,
      73,    74,    75,    76,    77,     4,     5,   263,   257,   263,
     543,   544,   545,   546,   547,   264,   257,   550,     4,     5,
     553,   262,   555,   264,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   533,   569,   570,   571,   572,
     573,   574,   575,   576,    86,    87,   579,   263,   581,   582,
     583,   584,   585,    20,    21,   588,  1797,   590,     3,   592,
     593,   594,     7,     8,     9,   598,   599,   600,   601,   602,
     603,   604,   605,     4,     5,    49,    50,   575,    70,    71,
      72,    73,    74,    75,    76,   263,    70,    71,    72,    73,
      74,    75,    76,   257,   257,   257,    63,    64,   262,   262,
     264,   264,   264,    70,    71,    72,    73,    74,    75,    76,
      77,   257,   473,   474,   256,   257,   258,   259,   264,   679,
     263,   257,   263,   656,   263,   653,   262,   653,    70,    71,
      72,    73,    74,    75,    76,   257,   263,     4,     5,   263,
     262,    44,   264,    70,    71,    72,    73,    74,    75,    76,
     257,   684,   257,    39,    40,   262,   257,   264,   257,   264,
      63,    64,   163,   264,   697,   264,   263,    70,    71,    72,
      73,    74,    75,    76,    77,   263,    70,    71,    72,    73,
      74,    75,    76,   256,   257,   258,   259,   257,   721,   262,
     723,   264,   257,   257,   264,    46,   263,   262,   262,   732,
      70,    71,    72,    73,    74,    75,    76,   740,     4,     5,
     743,   744,    63,    64,    46,  1956,   577,   578,  1959,    70,
      71,    72,    73,    74,    75,    76,    77,   257,   257,   257,
     257,    63,    64,   155,   264,   264,   264,   264,    70,    71,
      72,    73,    74,    75,    76,    77,    60,    61,   781,    14,
     257,    16,   257,    18,   787,   263,   789,   264,   791,   264,
     793,   263,   795,   263,  1272,   257,    14,  1275,    16,   802,
      18,  2012,   264,   257,  2015,   985,    41,    44,   262,    44,
     257,   814,   815,   263,    49,    60,    61,   264,   257,   256,
     257,   258,   259,    41,   155,   264,    44,   257,    51,   257,
     257,    49,   263,   257,   264,   257,   264,   264,   669,   670,
      63,    64,   264,   674,   675,   257,   263,    70,    71,    72,
      73,    74,    75,    76,    77,   263,   349,   350,   257,   352,
     257,   257,   865,   262,   155,   262,   257,   870,   264,   872,
     873,   874,   875,   264,   367,   368,   263,   263,  2089,   263,
    2091,   257,   375,   256,   257,   258,   259,   380,   264,   257,
    2101,  2102,   385,   257,   387,   155,   264,   263,   262,    70,
      71,    72,    73,    74,    75,    76,   399,   155,   401,   257,
     403,   257,   405,   406,   407,    44,   264,   257,   264,   257,
     413,   257,   262,   257,   257,   418,   264,   257,   264,     5,
     264,   264,   257,   426,   264,   256,   257,   258,   259,   264,
     433,   263,    58,    70,    71,    72,    73,    74,    75,    76,
     263,    63,    64,   263,   256,   257,   258,   259,    70,    71,
      72,    73,    74,    75,    76,    77,   263,    70,    71,    72,
      73,    74,    75,    76,    77,   257,   257,   257,   257,   993,
     994,   257,   264,   264,   264,   264,   262,   985,   257,   985,
     263,   263,   257,   262,   257,    63,    64,   262,  1001,   262,
       4,   263,    70,    71,    72,    73,    74,    75,    76,    77,
     263,   263,   263,   257,  1017,    63,    64,  1020,   262,   262,
    1023,   263,    70,    71,    72,    73,    74,    75,    76,    77,
     263,   263,   263,   256,   257,   258,   259,    90,    91,    92,
      93,    94,   263,   263,  1047,    14,   263,    16,  1051,    18,
     263,   104,   263,   263,   263,  1058,   257,   110,   111,  1062,
     263,   262,  1065,   116,   117,   118,   119,   120,   257,   263,
     263,   263,    41,   262,  1077,    44,  1079,  1080,  1081,   257,
      49,  1084,  1085,  1086,   262,  1088,   257,   257,   263,  1092,
     257,   262,   262,  1096,  1097,   262,  1099,   257,   257,  1102,
     257,  1104,   262,   262,   257,   262,   262,  1110,  1111,   262,
     262,  1114,   165,   263,   263,  1118,  1119,  1120,  1121,  1299,
     263,  1124,   257,   263,   257,  1128,   257,   262,  1131,   262,
     257,   262,  1135,   263,  1137,   262,  1139,   257,  1141,  1142,
    1143,   263,   262,   257,   256,   257,   258,   259,   262,   262,
     262,   262,   264,   256,   257,   258,   259,   263,   257,   263,
    1158,   257,  1158,   262,   995,   996,   262,   998,   999,   257,
     263,  1174,   257,  1176,   262,  1178,   257,   262,   257,   263,
     257,   262,   257,   262,  1187,   262,  1189,   262,   256,   257,
     258,   259,  1195,   686,   262,   257,   264,   257,   257,   257,
     262,   257,   262,   262,   262,   262,   262,   700,   256,   257,
     258,   259,   705,   257,   707,   257,   709,   710,   262,   257,
     262,   257,   715,   716,   262,   262,   262,   257,   257,   257,
    1233,   257,   262,   262,   262,   257,   262,   257,   257,   257,
     262,   257,   262,   262,   262,   262,   262,   262,  1251,  1252,
    1253,  1254,    63,    64,   263,   263,   263,  1260,   263,    70,
      71,    72,    73,    74,    75,    76,    77,   257,   263,   257,
    1273,   257,   262,  1276,   262,  1278,   262,   257,    63,    64,
     263,   263,   262,    43,   263,    70,    71,    72,    73,    74,
      75,    76,    77,   257,   257,   257,   263,   263,   262,   262,
     262,  1299,  1305,  1299,   263,  1308,   257,   257,   257,    63,
      64,   262,   262,   262,   262,  1146,    70,    71,    72,    73,
      74,    75,    76,    77,   257,   263,   263,   820,   821,   262,
    1333,  1334,   257,    63,    64,  1338,   263,   262,   262,  1342,
      70,    71,    72,    73,    74,    75,    76,    77,   257,   263,
     263,   844,   263,   262,  1357,  1358,   257,  1360,   263,  1362,
     257,   262,  1365,  1331,  1332,   262,  1369,  1370,   257,   263,
     257,   263,  1375,   262,  1377,   262,  1379,   257,  1381,   263,
     257,   263,   262,   262,  1387,   262,  1389,   262,  1391,   257,
    1393,  1394,  1395,   263,   262,   257,   257,   263,  1401,   257,
     262,   262,  1405,   257,   262,   257,   257,   257,   262,  1412,
     262,   262,   262,   262,   257,   263,  1419,   257,  1421,   262,
    1423,   257,   262,  1426,   257,  1428,   262,  1430,   257,   262,
     257,  1434,  1435,   262,   257,   262,   257,  1440,  1441,   262,
     264,   262,   264,    77,   257,   256,   257,   258,   259,   262,
     257,   262,   257,   264,   257,   262,   257,   262,   257,   262,
     257,   262,   264,   262,   264,   262,    75,  1470,  1471,  1472,
    1473,   256,   257,   258,   259,   263,   263,   263,   262,   264,
      71,    72,    73,    74,    75,    76,    77,   257,   263,  1503,
    1504,   257,   262,  1324,  1325,   257,   262,   262,   262,    43,
     262,    46,   256,   257,   258,   259,  1509,   257,   257,   257,
     264,   257,   262,   262,   262,   257,   262,   257,  1521,   257,
     262,    58,   262,    10,   262,   262,   256,   257,   258,   259,
    1533,   263,   257,   257,   264,  1538,  1539,   262,   262,    43,
     263,  1544,  1545,   257,  1547,  1548,   257,   263,   262,   257,
     257,   262,  1555,   257,   262,   262,   262,   257,   262,   257,
     262,  1564,   262,   257,   262,  1568,   262,   257,   262,   257,
     257,  1574,   262,  1576,   262,   262,   257,   257,    63,    64,
    1583,   262,   262,  1586,  1587,    70,    71,    72,    73,    74,
      75,    76,    77,   257,  1597,  1598,   262,  1600,   262,  1602,
      63,  1604,  1605,  1783,  1784,   263,   262,    70,    71,    72,
      73,    74,    75,    76,    77,   257,   262,   262,   262,   257,
     262,  1624,    63,    64,   262,   264,   263,  1630,   264,    70,
      71,    72,    73,    74,    75,    76,    77,   264,   257,   257,
     257,   262,  1645,   262,   262,   262,  1649,   257,   264,   257,
     257,   263,   262,  1656,   262,   262,  1659,   257,   257,  1662,
     264,   264,   262,   262,   262,   256,   257,   258,   259,    63,
      64,   264,   262,    85,  1677,   264,    70,    71,    72,    73,
      74,    75,    76,    77,   264,   264,   263,   257,   257,  1692,
    1693,  1694,   262,   262,    85,  1526,  1527,   264,   257,  1879,
     257,   257,     2,   262,  1707,   262,   262,  1710,   257,   264,
    1713,   263,   263,   262,  1717,   257,  1719,    17,   257,   262,
     262,   257,  1725,   262,  1727,     5,   262,   262,  1731,  1732,
      30,   264,  1735,    33,   257,   257,    36,    37,    38,   262,
     262,  1744,    42,    43,    44,  1748,   264,   257,  1751,   262,
    1753,    51,   262,  1756,  1757,   257,  1759,   257,   264,   257,
     262,   262,   262,  1943,   262,   257,  1946,   262,   262,  1772,
     262,   256,   257,   258,   259,   257,   257,   257,   257,   264,
     262,   262,   262,   262,   257,  1783,  1784,  1783,  1784,   262,
     262,    91,   257,   256,   257,   258,   259,   262,   262,  1802,
     257,   101,   257,  1806,   257,   262,  1809,   262,   257,   262,
    1813,   262,   262,   262,   257,   256,   257,   258,   259,   262,
    2000,   257,   257,   264,   257,   257,   262,   262,   257,   262,
     262,   262,   257,   262,   257,   257,   136,   262,   257,   262,
     262,   257,  1845,   262,  1847,  1848,   262,  1850,   262,  1852,
      58,   262,   262,  1346,   262,   262,  1349,   262,   264,   262,
     262,  1354,   256,   257,   258,   259,   264,   264,   264,   264,
     264,   248,   249,   250,   251,   252,   263,   263,  1881,    63,
      64,  1879,   262,  1879,   262,   264,    70,    71,    72,    73,
      74,    75,    76,    77,   262,   262,   262,    43,   263,  1902,
    1903,  1904,  1905,   264,  1907,  1908,   264,    38,    43,  1912,
     263,    58,   264,  1916,   264,    75,    75,  1920,  1921,  1922,
      75,  1924,    48,   263,    58,  1928,  1929,   264,   264,   262,
      47,  1934,   263,   263,  1937,   263,  1939,   263,    58,    75,
     264,   264,    38,   243,   244,  1943,   263,  1943,  1946,   263,
    1946,  1444,  1955,   262,   262,     4,     4,   487,  1961,  1962,
    1158,  1964,  1965,  1966,   264,    53,    63,    64,  1461,   269,
      53,     5,   997,    70,    71,    72,    73,    74,    75,    76,
      77,  1509,   282,  2073,  1987,   676,   679,   287,  1991,  1001,
    1993,  1994,  1860,  1311,   294,   692,    -1,  1000,    -1,    63,
      64,    -1,  2000,    -1,  2000,  2008,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,   317,    -1,   319,
      -1,    -1,  2025,    -1,    -1,    -1,  2029,    -1,    -1,  2032,
    2033,    -1,    -1,    -1,  2037,    -1,    -1,    -1,  2041,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2050,    -1,    -1,
      -1,    -1,  2055,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2064,    -1,    -1,    -1,    -1,   366,    -1,    -1,    -1,
      -1,    -1,   256,   257,   258,   259,    63,    64,  2081,  2082,
     264,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,  2094,    63,    64,    -1,    -1,  2099,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   451,   452,   453,   454,    -1,    -1,    -1,   458,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
     470,    -1,    -1,    -1,    -1,   475,   476,    -1,   478,   479,
     480,   481,   482,   483,    -1,    -1,    -1,    -1,    -1,   489,
      -1,    -1,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,  1700,    -1,    -1,
      -1,  1704,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   541,   542,    -1,    -1,    -1,    -1,    -1,   548,   549,
     550,   551,   552,    -1,   554,    -1,   556,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   568,   256,
     257,   258,   259,    -1,    -1,   575,    -1,   264,    -1,    -1,
     580,    -1,    -1,    -1,    -1,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   654,    -1,    -1,    -1,    -1,   659,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   672,   673,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   685,    -1,     3,     4,     5,
     690,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,   701,   702,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   742,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,   110,    -1,    -1,    -1,    -1,   115,
      -1,   801,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,    -1,   814,   815,   816,   817,    -1,    -1,
     136,    -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
      -1,   167,   168,   169,   170,   171,    -1,    -1,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,    -1,   229,   230,   231,   232,    -1,   234,   235,
      -1,   237,   238,   239,    -1,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,    -1,   253,   254,    -1,
     256,    -1,    -1,    63,    64,    -1,    -1,   263,    -1,   265,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   968,   969,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,   988,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1001,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1014,    -1,    -1,    -1,    -1,    -1,
    1020,  1021,    -1,    63,    64,    -1,  1026,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
    1040,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
    1060,    -1,    -1,    -1,    -1,  1065,  1066,  1067,    -1,    -1,
    1070,    -1,    -1,  1073,    -1,  1075,    -1,  1077,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1086,    -1,    -1,    -1,
    1090,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1098,    -1,
    1100,    -1,    -1,    -1,    -1,    -1,  1106,    -1,    -1,    -1,
    1110,  1111,  1112,    -1,    -1,  1115,  1116,    -1,    -1,  1119,
      -1,    -1,  1122,    -1,    -1,  1125,    -1,  1127,    -1,  1129,
      -1,    -1,    -1,  1133,    -1,  1135,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    -1,    -1,  1147,  1148,  1149,
      -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    10,  1159,
      -1,    -1,    -1,   256,   257,   258,   259,  1167,  1168,   262,
    1170,  1171,  1172,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,  1183,  1184,    -1,  1186,    -1,    -1,    -1,
    1190,  1191,  1192,    -1,  1194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1202,    -1,    -1,    -1,    -1,    -1,  1208,    -1,
      -1,  1211,    -1,    -1,    -1,    -1,   256,   257,   258,   259,
      -1,    -1,    -1,  1223,   264,    -1,  1226,  1227,  1228,    -1,
    1230,  1231,    -1,    -1,   256,   257,   258,   259,    -1,  1239,
      -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,   105,    -1,   107,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,  1267,    -1,  1269,
    1270,  1271,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1283,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,  1303,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,  1313,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1326,  1327,    -1,    -1,
      -1,  1331,  1332,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1340,  1341,    -1,   195,   196,   197,    -1,    -1,    -1,   201,
     202,   203,    -1,   205,    -1,   207,   208,   209,    -1,    -1,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,    -1,
      -1,   223,    -1,   225,    -1,   227,    -1,    -1,   230,    -1,
     232,    -1,    -1,   235,    -1,    -1,   238,   239,    -1,   241,
     242,    -1,   244,    -1,   246,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,   263,   264,    -1,    -1,  1415,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,   256,   257,   258,   259,    -1,    -1,    -1,    58,
     264,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,  1509,
      -1,    -1,    -1,    -1,  1514,    -1,    -1,    -1,    -1,  1519,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1550,  1551,  1552,    -1,  1554,    -1,    -1,    -1,   167,    -1,
      -1,  1561,    -1,    -1,    -1,  1565,  1566,    -1,    -1,    -1,
      -1,  1571,    -1,  1573,  1574,    -1,    -1,    -1,  1578,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1586,    -1,    -1,  1589,
    1590,    -1,  1592,    -1,    -1,  1595,    -1,    -1,    -1,    -1,
    1600,    -1,   256,   257,   258,   259,    63,    64,    -1,    -1,
     264,  1611,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1629,
      -1,  1631,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1641,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1650,    -1,  1652,    -1,    -1,    -1,    -1,  1657,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1666,    -1,    -1,    -1,
     256,   257,   258,   259,    -1,    -1,  1676,    -1,   264,  1679,
      -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,    -1,
      -1,    63,    64,   264,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,  1708,  1709,
      -1,    -1,  1712,   256,   257,   258,   259,    -1,    -1,   328,
    1720,   264,    -1,    -1,    -1,   334,    -1,    -1,    -1,  1729,
    1730,    -1,   341,   342,  1734,    -1,    -1,    -1,    -1,  1739,
      -1,    -1,    -1,  1743,   353,   354,   355,   356,   357,   358,
     359,    -1,    -1,   362,   363,   364,   365,    -1,    63,    64,
    1760,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1785,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1796,    -1,    -1,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,  1808,    -1,
    1810,    -1,  1812,    -1,    -1,    -1,    -1,    -1,  1818,    -1,
      -1,  1821,    -1,  1823,    -1,    -1,  1826,  1827,    -1,    -1,
    1830,    -1,    -1,    -1,    -1,    -1,    -1,  1837,    -1,  1839,
    1840,  1841,    -1,    -1,  1844,    -1,    -1,    -1,    -1,    -1,
    1850,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,   468,
     469,    -1,    -1,  1863,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1874,    -1,    -1,    -1,    -1,   488,
      -1,    -1,  1882,  1883,   256,   257,   258,   259,    63,    64,
      -1,    -1,   264,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1910,    -1,    -1,  1913,    -1,    -1,    -1,  1917,    -1,  1919,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,    -1,    -1,    -1,  1958,   264,
    1960,    -1,    -1,  1963,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1971,    -1,    -1,  1974,    -1,    -1,    -1,  1978,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1986,    -1,  1988,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
    2010,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2028,    -1,
    2030,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2053,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2062,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,    -1,   695,    -1,    -1,   264,
     699,    -1,    -1,    -1,   703,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,   718,
     719,    -1,    -1,    -1,    -1,    -1,    81,   726,    -1,    84,
      -1,    -1,   731,    -1,    89,    -1,    -1,   736,    -1,   738,
      -1,    -1,    97,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,   750,   107,   752,    -1,   754,    -1,   756,   757,   758,
     115,    -1,    -1,    -1,    -1,   764,    -1,   122,    -1,    -1,
     769,   126,   127,    -1,    -1,    -1,    -1,    -1,   777,    -1,
      -1,   136,    -1,   138,   139,    -1,   785,    -1,    -1,   144,
     145,   146,   147,   148,   149,   256,   257,   258,   259,    -1,
      -1,   156,    -1,   264,   159,    -1,    -1,   162,   163,   164,
      -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,    -1,   229,   230,   231,   232,    -1,   234,
     235,    -1,   237,   238,   239,    -1,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,    -1,   253,   254,
      -1,   256,    -1,    -1,    63,    64,    -1,    -1,   263,    -1,
     265,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1046,    -1,    -1,
      30,    31,    -1,    -1,    -1,  1054,    -1,    -1,    -1,    -1,
    1059,    -1,  1061,    -1,  1063,  1064,    -1,    -1,    -1,  1068,
    1069,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,
     259,    81,    -1,    -1,    84,   264,    -1,    -1,    -1,    89,
      -1,    -1,   256,   257,   258,   259,    -1,    97,    -1,    -1,
     264,   101,   102,    -1,    -1,   105,    -1,   107,   256,   257,
     258,   259,    -1,    -1,    -1,   115,   264,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,   256,
     257,   258,   259,    -1,    -1,    -1,   136,   264,   138,   139,
      -1,  1160,  1161,    -1,   144,   145,   146,   147,   148,   149,
     256,   257,   258,   259,    -1,    -1,   156,    -1,   264,   159,
      -1,    -1,   162,   163,   164,    -1,  1185,   167,   168,   169,
     170,   171,    -1,    -1,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,    -1,   229,
     230,   231,   232,    -1,   234,   235,    -1,   237,   238,   239,
      -1,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,    -1,   253,   254,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,   263,    -1,   265,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,    -1,   229,   230,   231,   232,    -1,   234,   235,    -1,
     237,   238,   239,    -1,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,    -1,   253,   254,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,   263,  1546,   265,    -1,
    1549,    -1,    -1,    -1,  1553,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1615,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,    -1,   167,   168,   169,   170,   171,    -1,
      -1,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,    -1,   229,   230,   231,   232,
      -1,   234,   235,    -1,   237,   238,   239,    -1,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,  1807,    -1,
     253,   254,  1811,   256,    -1,    -1,    -1,    -1,    -1,    -1,
     263,   264,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,    -1,    30,
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
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,   167,   168,   169,   170,
     171,    -1,    -1,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,    -1,   229,   230,
     231,   232,    -1,   234,   235,    -1,   237,   238,   239,    -1,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,    -1,   253,   254,    -1,   256,    -1,    -1,    -1,    -1,
      -1,    -1,   263,   264,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,
     259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,    -1,
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
     139,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
     169,   170,   171,    -1,    -1,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,    -1,
     229,   230,   231,   232,    -1,   234,   235,    -1,   237,   238,
     239,    -1,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,    -1,   253,   254,    -1,   256,    -1,    -1,
      -1,    -1,    -1,    -1,   263,   264,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,
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
      -1,   138,   139,    -1,    -1,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,   151,   152,   153,   154,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,    -1,   229,   230,   231,   232,    -1,   234,   235,    -1,
     237,   238,   239,    -1,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,    -1,   253,   254,    -1,   256,
      -1,    -1,    -1,     3,     4,     5,   263,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    61,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,
      -1,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,   169,
     170,   171,    -1,    -1,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,    -1,   229,
     230,   231,   232,    -1,   234,   235,    -1,   237,   238,   239,
      -1,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,    -1,   253,   254,    -1,   256,    -1,    -1,    -1,
       3,     4,     5,   263,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
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
     143,   144,   145,   146,   147,   148,   149,    -1,   151,    -1,
      -1,   154,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,    -1,   167,   168,   169,   170,   171,    -1,
      -1,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,    -1,   229,   230,   231,   232,
      -1,   234,   235,    -1,   237,   238,   239,    -1,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,   256,    -1,    -1,    -1,     3,     4,     5,
     263,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,   111,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,    -1,   142,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
      -1,   167,   168,   169,   170,   171,    -1,    -1,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,    -1,   229,   230,   231,   232,    -1,   234,   235,
      -1,   237,   238,   239,    -1,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,    -1,   253,   254,    -1,
     256,    -1,    -1,    -1,     3,     4,     5,   263,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
     169,   170,   171,    -1,    -1,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,    -1,
     229,   230,   231,   232,    -1,   234,   235,    -1,   237,   238,
     239,    -1,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,    -1,   253,   254,    -1,   256,    -1,    -1,
      -1,     3,     4,     5,   263,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,   111,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,    -1,   229,   230,   231,
     232,    -1,   234,   235,    -1,   237,   238,   239,    -1,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
      -1,   253,   254,    -1,   256,    -1,    -1,    -1,     3,     4,
       5,   263,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    30,    31,    -1,    -1,    -1,
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
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,    -1,   229,   230,   231,   232,    -1,   234,
     235,    -1,   237,   238,   239,    -1,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,    -1,   253,   254,
      -1,   256,    -1,    -1,    -1,     3,     4,     5,   263,     7,
       8,     9,    10,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,
      -1,    89,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,
     168,   169,   170,   171,    -1,    -1,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
      -1,   229,   230,   231,   232,    -1,   234,   235,    -1,   237,
     238,   239,    -1,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,    -1,   253,   254,    -1,   256,    -1,
      -1,    -1,     3,     4,     5,   263,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    30,
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
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,   167,   168,   169,   170,
     171,    -1,    -1,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,    -1,   229,   230,
     231,   232,    -1,   234,   235,    -1,   237,   238,   239,    -1,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,    -1,   253,   254,    -1,   256,    -1,    -1,    -1,     3,
       4,     5,   263,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,   112,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,    -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,    -1,   229,   230,   231,   232,    -1,
     234,   235,    -1,   237,   238,   239,    -1,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,    -1,   253,
     254,    -1,   256,    -1,    -1,    -1,     3,     4,     5,   263,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,
      -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,   112,   113,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,    -1,   229,   230,   231,   232,    -1,   234,   235,    -1,
     237,   238,   239,    -1,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,    -1,   253,   254,    -1,   256,
      -1,    -1,    -1,     3,     4,     5,   263,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      30,    31,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,   169,
     170,   171,    -1,    -1,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,    -1,   229,
     230,   231,   232,    -1,   234,   235,    -1,   237,   238,   239,
      -1,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,    -1,   253,   254,    -1,   256,    -1,    -1,    -1,
       3,     4,     5,   263,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    30,    31,    -1,
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
      -1,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,    -1,   167,   168,   169,   170,   171,    -1,
      -1,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,    -1,   229,   230,   231,   232,
      -1,   234,   235,    -1,   237,   238,   239,    -1,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,   256,    -1,    -1,    -1,     3,     4,     5,
     263,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,
      64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,   111,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
      -1,   167,   168,   169,   170,   171,    -1,    -1,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,    -1,   229,   230,   231,   232,    -1,   234,   235,
      -1,   237,   238,   239,    -1,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,    -1,   253,   254,    -1,
     256,    -1,    -1,    -1,     3,     4,     5,   263,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     139,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
     169,   170,   171,    -1,    -1,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,    -1,
     229,   230,   231,   232,    -1,   234,   235,    -1,   237,   238,
     239,    -1,   241,   242,   243,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,    -1,   253,   254,    -1,   256,    -1,    -1,
      -1,     3,     4,     5,   263,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,
     257,   258,   259,    -1,    -1,    -1,    -1,   264,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,   111,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,    -1,   229,   230,   231,
     232,    -1,   234,   235,    -1,   237,   238,   239,    -1,   241,
     242,   243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
      -1,   253,   254,    -1,   256,    -1,    -1,    -1,     3,     4,
       5,   263,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,
      -1,    -1,    -1,    -1,   264,    30,    31,    -1,    -1,    -1,
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
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,    -1,   229,   230,   231,   232,    -1,   234,
     235,    -1,   237,   238,   239,    -1,   241,   242,   243,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,    -1,   253,   254,
      -1,   256,    -1,    -1,    -1,     3,     4,     5,   263,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,
      -1,    89,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,   111,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,
     168,   169,   170,   171,    -1,    -1,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
      -1,   229,   230,   231,   232,    -1,   234,   235,    -1,   237,
     238,   239,    -1,   241,   242,   243,   244,   245,   246,   247,
      -1,    -1,    -1,    -1,    -1,   253,   254,    -1,   256,    -1,
      -1,    -1,     3,     4,     5,   263,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,    30,
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
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,   167,   168,   169,   170,
     171,    -1,    -1,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,    -1,   229,   230,
     231,   232,    -1,   234,   235,    -1,   237,   238,   239,    -1,
     241,   242,   243,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,    -1,   253,   254,    -1,   256,    -1,    -1,    -1,     3,
       4,     5,   263,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,
     259,    -1,    -1,    -1,    -1,   264,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,   111,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,    -1,    -1,   167,   168,   169,   170,   171,    -1,    -1,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,    -1,   229,   230,   231,   232,    -1,
     234,   235,    -1,   237,   238,   239,    -1,   241,   242,   243,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,    -1,   253,
     254,    -1,   256,    -1,    -1,    -1,     3,     4,     5,   263,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   256,   257,   258,   259,    -1,    -1,
      -1,    -1,   264,    30,    31,    -1,    -1,    -1,    -1,    -1,
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
      -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,    -1,   229,   230,   231,   232,    -1,   234,   235,    -1,
     237,   238,   239,    -1,   241,   242,   243,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,    -1,   253,   254,    -1,   256,
      -1,    -1,    -1,     3,     4,     5,   263,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,    -1,    -1,    -1,    -1,   264,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,   111,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,   169,
     170,   171,    -1,    -1,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,    -1,   229,
     230,   231,   232,    -1,   234,   235,    -1,   237,   238,   239,
      -1,   241,   242,   243,   244,   245,   246,   247,    -1,    -1,
      -1,    -1,    -1,   253,   254,    -1,   256,    -1,    -1,    -1,
       3,     4,     5,   263,     7,     8,     9,    10,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,    -1,   167,   168,   169,   170,   171,    -1,
      -1,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,    -1,   229,   230,   231,   232,
      -1,   234,   235,    -1,   237,   238,   239,    -1,   241,   242,
     243,   244,   245,   246,   247,    -1,    -1,    -1,    -1,    -1,
     253,   254,    -1,   256,    -1,    -1,    -1,     3,     4,     5,
     263,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,    -1,
      -1,    -1,    -1,   264,    30,    31,    -1,    -1,    -1,    -1,
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
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
      -1,   167,   168,   169,   170,   171,    -1,    -1,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,    -1,   229,   230,   231,   232,    -1,   234,   235,
      -1,   237,   238,   239,    -1,   241,   242,   243,   244,   245,
     246,   247,    -1,    -1,     5,    -1,    -1,   253,   254,    10,
     256,    -1,    -1,    -1,    -1,    -1,    -1,   263,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,   256,   257,   258,   259,    -1,    -1,    -1,    -1,
     264,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,   105,    -1,   107,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,    -1,     5,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    31,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   196,   197,    -1,    -1,    -1,
     201,   202,   203,    -1,   205,    -1,   207,   208,   209,    -1,
      -1,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,   223,    -1,   225,    -1,   227,    -1,   105,   230,
     107,   232,    -1,    -1,   235,    -1,    -1,   238,   239,    -1,
     241,   242,    -1,   244,    -1,   246,    -1,    -1,    -1,   126,
     127,    -1,     5,   254,    -1,    -1,    -1,    10,   256,   257,
     258,   259,   263,   264,    -1,    -1,   264,   144,   145,   146,
     147,   148,    -1,   256,   257,   258,   259,    -1,    31,   156,
      -1,   264,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,    -1,   256,   257,   258,   259,    -1,    -1,    -1,
      -1,   264,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   195,   196,
     197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,    -1,
     207,   208,   209,    -1,    -1,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,   223,    -1,   225,    -1,
     227,    -1,   105,   230,   107,   232,    -1,    -1,   235,    -1,
      -1,   238,   239,    -1,   241,   242,    -1,   244,    -1,   246,
      -1,    -1,    -1,   126,   127,    -1,    -1,   254,     5,    -1,
      -1,    -1,    -1,    10,    -1,    -1,   263,   264,    -1,    -1,
      -1,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,    31,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,    -1,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   195,   196,   197,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,    -1,   207,   208,   209,    -1,    -1,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
     223,    -1,   225,    -1,   227,    -1,    -1,   230,   105,   232,
     107,    -1,   235,    -1,   111,   238,   239,    -1,   241,   242,
      -1,   244,    -1,   246,    -1,   256,   257,   258,   259,   126,
     127,   254,    -1,   264,     5,    -1,    -1,    -1,    -1,    10,
     263,   264,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      31,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,   195,   196,
     197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,    -1,
     207,   208,   209,    -1,    -1,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,   223,    -1,   225,    -1,
     227,    -1,    -1,   230,   105,   232,   107,    -1,   235,    -1,
     111,   238,   239,    -1,   241,   242,    -1,   244,    -1,   246,
     256,   257,   258,   259,    -1,   126,   127,   254,   264,    -1,
       5,    -1,    -1,    -1,    -1,    10,   263,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    31,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   196,   197,    -1,    -1,    -1,
     201,   202,   203,    -1,   205,    -1,   207,   208,   209,    -1,
      -1,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,   223,    -1,   225,    -1,   227,    -1,    -1,   230,
     105,   232,   107,    -1,   235,    -1,   111,   238,   239,    -1,
     241,   242,    -1,   244,    -1,   246,   256,   257,   258,   259,
      -1,   126,   127,   254,   264,    -1,     5,    -1,    -1,    -1,
      -1,    10,   263,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    31,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,    -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,    -1,   207,   208,   209,    -1,    -1,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,   223,    -1,
     225,    -1,   227,    -1,    -1,   230,   105,   232,   107,    -1,
     235,    -1,   111,   238,   239,    -1,   241,   242,    -1,   244,
      -1,   246,    -1,    -1,    -1,    -1,    -1,   126,   127,   254,
       5,    -1,    -1,    -1,    -1,    10,    -1,    -1,   263,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    31,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   196,   197,    -1,
      -1,    -1,   201,   202,   203,    -1,   205,    -1,   207,   208,
     209,    -1,    -1,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,   223,    -1,   225,    -1,   227,    -1,
     105,   230,   107,   232,    -1,    -1,   235,    -1,    -1,   238,
     239,    -1,   241,   242,    -1,   244,    -1,   246,    -1,    -1,
      -1,   126,   127,    -1,     5,   254,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,    -1,   150,    -1,    -1,    -1,    -1,
      31,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,    -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,    -1,   207,   208,   209,    -1,    -1,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,   223,    -1,
     225,    -1,   227,    -1,   105,   230,   107,   232,    -1,    -1,
     235,    -1,    -1,   238,   239,    -1,   241,   242,    -1,   244,
      -1,   246,    -1,    -1,    -1,   126,   127,    -1,     5,   254,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,   263,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,   150,
      -1,    -1,    -1,    -1,    31,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   196,   197,    -1,    -1,    -1,
     201,   202,   203,    -1,   205,    -1,   207,   208,   209,    -1,
      -1,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
      97,    -1,   223,    -1,   225,    -1,   227,    -1,   105,   230,
     107,   232,    -1,    -1,   235,    -1,    -1,   238,   239,    -1,
     241,   242,    -1,   244,    -1,   246,    -1,    -1,    -1,   126,
     127,    -1,     5,   254,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,   263,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    31,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,
     197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,    -1,
     207,   208,   209,    -1,    -1,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,    97,    -1,   223,    -1,   225,    -1,
     227,    -1,   105,   230,   107,   232,    -1,    -1,   235,    -1,
      -1,   238,   239,    -1,   241,   242,    -1,   244,    -1,   246,
      -1,    -1,    -1,   126,   127,    -1,     5,   254,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    31,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,    -1,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   196,   197,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,    -1,   207,   208,   209,    -1,    -1,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
     223,    -1,   225,    -1,   227,    -1,   105,   230,   107,   232,
      -1,    -1,   235,    -1,    -1,   238,   239,    -1,   241,   242,
      -1,   244,    -1,   246,    -1,    -1,    -1,   126,   127,    -1,
       5,   254,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
     263,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    31,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   196,   197,    -1,
      -1,    -1,   201,   202,   203,    -1,   205,    -1,   207,   208,
     209,    -1,    -1,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,   223,    -1,   225,    -1,   227,    -1,
     105,   230,   107,   232,    -1,    -1,   235,    -1,    -1,   238,
     239,    -1,   241,   242,    -1,   244,    -1,   246,    -1,    -1,
      -1,   126,   127,    -1,    -1,   254,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   263,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,    -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,    -1,   207,   208,   209,    -1,    -1,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,    -1,    -1,   223,    -1,
     225,    -1,   227,    -1,    -1,   230,    -1,   232,    -1,    -1,
     235,    -1,    -1,   238,   239,    -1,   241,   242,    -1,   244,
      -1,   246,    -1,    -1,     4,     5,     6,    -1,    -1,   254,
      -1,    11,    -1,    -1,    -1,    15,    -1,    17,   263,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    98,    99,
     100,    -1,    -1,   103,   104,    -1,   106,    -1,   108,   109,
      -1,    -1,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,
      -1,   121,    -1,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,    -1,    -1,   169,
     170,   171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   196,   197,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,   228,    -1,
       4,     5,     6,   233,    -1,    -1,   236,    11,    -1,    -1,
     240,    15,    -1,    17,    -1,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    -1,    -1,
      94,    95,    96,    -1,    98,    99,   100,    -1,    -1,   103,
      -1,    -1,   106,    -1,   108,   109,    -1,    -1,    -1,    -1,
     114,   115,    -1,    -1,    -1,    -1,    -1,   121,    -1,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,    -1,    -1,   169,   170,   171,   256,   257,
     258,   259,    -1,    -1,    -1,    -1,   264,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   196,   197,    -1,    -1,    -1,    -1,   202,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,   228,    -1,     4,     5,     6,   233,
      -1,    -1,   236,    11,    -1,    -1,   240,    15,    -1,    17,
      -1,    19,    20,    21,    22,    23,    24,    -1,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    36,    37,
      38,    -1,    -1,    -1,    42,    43,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,    57,
      63,    64,    -1,    61,    62,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    89,    90,    91,    -1,    -1,    94,    95,    96,    -1,
      98,    99,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,
     108,   109,    -1,    -1,    -1,    -1,   114,   115,    -1,    -1,
      -1,    -1,    -1,   121,    -1,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,    -1,    -1,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,    -1,
      -1,   169,   170,   171,   256,   257,   258,   259,    63,    64,
     262,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,   195,   196,   197,
      63,    64,    -1,    -1,   202,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,   233,    63,    64,   236,    -1,
      -1,    -1,   240,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   256,   257,   258,   259,    63,    64,   262,
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
      -1,   256,   257,   258,   259,    63,    64,   262,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,   256,   257,   258,   259,    63,    64,   262,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   256,
     257,   258,   259,    63,    64,   262,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     256,   257,   258,   259,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   257,   258,   259,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   257,   258,   259,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   257,   258,   259,    63,    64,   262,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,
     258,   259,    63,    64,   262,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
     256,   257,   258,   259,    -1,    -1,   262,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,    63,
      64,   262,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   256,   257,   258,   259,
      63,    64,   262,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   256,   257,   258,
     259,    63,    64,   262,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,    63,
      64,   262,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,   256,   257,   258,   259,    63,    64,   262,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   256,   257,   258,   259,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,
     258,   259,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,   257,   258,   259,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,
     258,   259,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,   257,   258,   259,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,
     258,   259,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,   257,   258,   259,    63,    64,   262,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   256,   257,   258,   259,    63,    64,
     262,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   256,   257,   258,   259,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,
     259,    63,    64,   262,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,   256,
     257,   258,   259,    63,    64,   262,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     256,   257,   258,   259,    63,    64,   262,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,   256,   257,   258,   259,    63,    64,   262,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   256,   257,   258,   259,    63,    64,
     262,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,   256,   257,   258,   259,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,
      63,    64,   262,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   256,   257,   258,
     259,    63,    64,   262,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   256,   257,
     258,   259,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,   257,   258,   259,    63,    64,   262,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,    63,    64,   262,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,   256,   257,   258,   259,    63,    64,   262,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   256,   257,   258,   259,    63,    64,
     262,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     256,   257,   258,   259,    63,    64,   262,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,
     258,   259,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,   257,   258,   259,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,
     258,   259,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,   257,   258,   259,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,
     258,   259,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,   257,   258,   259,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,
     258,   259,    63,    64,   262,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
     256,   257,   258,   259,    63,    64,   262,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,   256,   257,   258,   259,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,
      63,    64,   262,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   256,   257,   258,
     259,    63,    64,   262,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,    63,
      64,   262,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,   256,   257,   258,
     259,    63,    64,   262,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   256,   257,   258,   259,    63,    64,   262,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   256,   257,   258,   259,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,
     257,   258,   259,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   256,   257,   258,   259,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,
     257,   258,   259,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   256,   257,   258,   259,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,
     257,   258,   259,    -1,    -1,   262,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   256,   257,   258,   259,    63,    64,
     262,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   256,   257,   258,   259,    63,    64,   262,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,   256,   257,   258,   259,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,
     257,   258,   259,    63,    64,   262,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     256,   257,   258,   259,    63,    64,   262,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,   256,   257,   258,   259,    63,    64,   262,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,
     257,   258,   259,    63,    64,   262,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,   256,   257,   258,   259,
      63,    64,   262,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   256,   257,   258,
     259,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   256,   257,   258,   259,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,
     259,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   256,   257,   258,   259,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,
     259,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   256,   257,   258,   259,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,
     259,    63,    64,   262,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   256,   257,
     258,   259,    63,    64,   262,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,   257,   258,   259,    63,    64,   262,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,   256,   257,   258,   259,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   256,   257,   258,   259,    -1,    -1,
     262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   256,   257,   258,   259,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,
     258,   259,    -1,    -1,   262
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   248,   249,   250,   251,   252,   267,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   114,   115,
     121,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     144,   145,   146,   147,   148,   149,   156,   157,   158,   159,
     164,   165,   166,   169,   170,   171,   195,   196,   197,   202,
     224,   228,   233,   236,   240,   268,   269,   272,   273,   280,
     281,   283,   284,   288,   300,   301,   306,   312,   319,   327,
     335,   338,   342,   345,   351,     3,     4,     5,     7,     8,
       9,    10,    30,    31,    63,    64,    65,    66,    67,    68,
      69,    81,    84,    89,   101,   102,   105,   107,   115,   122,
     126,   127,   136,   138,   139,   144,   145,   146,   147,   148,
     149,   156,   159,   162,   163,   164,   167,   168,   169,   170,
     171,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   229,   230,   231,   232,   234,
     235,   237,   238,   239,   241,   242,   243,   244,   245,   246,
     247,   253,   254,   256,   263,   286,   287,   289,   295,   297,
     300,   301,   144,   145,   146,   147,   164,   263,   286,   272,
     300,   301,   306,     0,    75,   263,    75,   263,   320,   339,
     343,     4,     7,   298,   298,   298,    34,   289,   274,   275,
     286,   302,   303,   302,   286,    28,     7,   328,   336,   289,
      58,    60,    61,   265,   382,   278,   286,   289,     4,     5,
     299,   289,   286,   289,   286,   289,     4,     5,   362,   363,
      10,   256,   257,   296,   297,   364,   298,    89,    97,   265,
     286,   289,   383,    89,    97,   110,   383,   383,    81,    82,
      88,   111,   289,   294,    12,    53,   294,   111,   294,    59,
      89,    90,    91,    96,    95,   289,   281,   288,   286,   286,
     286,   110,   294,    90,    91,    92,    93,    94,   104,   110,
     111,   116,   117,   118,   119,   120,   165,   294,   294,   111,
     294,   111,   294,    95,   111,   294,    61,    95,   111,   142,
     294,   294,    22,    61,   111,   294,   111,   294,   111,   294,
     111,   286,   286,   286,    61,   111,   111,   142,   143,   294,
     111,   294,   111,   294,   111,   294,   294,   294,    95,   142,
     143,   151,   154,   294,    95,   142,   143,   154,   294,    95,
     142,   143,   151,   152,   153,   154,   294,    61,    95,   142,
     143,   150,   154,   294,   111,   294,   111,   294,   111,   286,
     111,   286,   111,   286,   160,    95,   111,   112,   143,   289,
     286,    98,   173,   173,   111,   263,   263,   263,   263,   263,
     286,   383,   286,   286,   286,    44,   270,    92,    93,   104,
      75,    75,    24,   263,   263,   263,   263,   289,   263,   263,
     263,   263,   263,   263,   112,   113,   263,   263,   263,   263,
     112,   263,   112,   155,   112,   155,   112,   112,   112,   112,
     113,   155,   112,   113,   155,   112,   113,   155,   112,   113,
     155,   112,   112,   162,   161,   263,   112,   155,   286,   294,
     172,   172,   112,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   163,   163,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   289,   286,   289,    70,    71,
      72,    73,    74,    75,    76,   257,    44,    63,    64,    70,
      71,    72,    73,    74,    75,    76,    77,   256,   257,   258,
     259,   286,    44,    44,    44,   289,   302,   286,   302,     4,
     289,   269,    35,    36,    20,    21,     4,     5,   313,   314,
       4,     5,   315,   316,   286,   289,   304,   305,   286,   289,
     330,   269,   346,   352,   263,    58,   263,     4,     7,   263,
     286,   289,   365,    58,    60,    61,   265,   367,   380,   263,
     263,   262,   262,   262,   263,   263,   262,   297,   297,   262,
     289,   286,   289,    11,   262,   262,   294,   286,   286,   286,
     262,   294,   279,    12,   262,   282,   286,   262,   294,    12,
     294,   282,   282,   282,   294,   294,   294,   294,   294,   294,
     294,   286,   286,   294,   294,   294,   294,   289,   282,   282,
     286,   262,   286,   262,   286,   286,   282,   286,   286,   286,
     286,   282,   262,   286,   286,   286,   282,   286,   282,   286,
     262,   286,   262,   262,   262,   286,   286,   286,   286,   286,
     282,   286,   282,   286,   282,   286,   282,   282,   282,   286,
     286,   286,   286,   286,   282,   286,   286,   286,   286,   282,
     286,   286,   286,   286,   286,   286,   286,   282,   286,   286,
     286,   150,   286,   286,   286,   282,   286,   262,   286,   262,
     286,   262,   286,   262,   286,   262,   286,   286,   286,   286,
     286,   262,   262,   289,   289,   289,   289,     5,   285,   285,
     285,   264,   289,   286,   262,   262,   262,   262,    43,   294,
     294,   294,   289,   286,   307,   302,   302,   289,   289,   289,
     289,   289,   289,    97,   286,   383,   383,   286,     4,     5,
     292,   293,   292,   293,   294,   289,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   150,   286,   286,   286,   286,
     263,   286,   263,   263,   262,   262,   286,   286,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   383,   289,
     289,   289,   289,   289,   289,   289,   289,   264,   289,   286,
     286,   286,   286,   286,   289,   289,   286,   289,   264,   289,
     289,   286,   289,   286,   289,   286,   286,   264,   286,   264,
     286,   264,   286,   264,   286,   286,   286,   286,   286,   286,
     289,   286,   286,   286,   286,   286,   286,   286,   383,   286,
     302,   302,   286,   289,   286,   286,   286,   286,   286,   264,
     264,   286,   285,   286,   285,   286,   286,   286,   264,   264,
     286,   286,   286,   286,   286,   286,   286,   286,   291,   290,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   264,   264,    75,   340,    14,    16,    18,    41,
      44,    49,   344,   276,   277,   263,   263,   262,   263,   263,
     262,   262,    43,   329,    14,    16,    18,    41,    44,    49,
     337,    46,   269,   289,   263,   286,   289,    51,   366,   261,
     262,   263,    58,   263,     4,     7,   263,    10,   381,   302,
     302,     4,     5,   289,   289,   302,   302,   363,    10,   296,
     262,    86,    87,    97,   286,   289,   282,   262,   289,   367,
     294,   262,   286,   294,   282,   289,   289,   294,   262,   282,
     262,   282,   262,   282,   282,   262,   262,   262,   282,   282,
     262,   294,   294,   262,   286,   262,   286,   262,   294,   262,
     262,   262,   294,   286,   262,   262,   262,   294,   262,   294,
     262,   286,   262,   289,   286,   286,   262,   262,   262,   262,
     262,   294,   262,   294,   262,   294,   262,   294,   294,   294,
     262,   262,   262,   294,   262,   262,   262,   294,   262,   262,
     262,   262,   262,   294,   262,   262,   286,   262,   262,   262,
     294,   262,   286,   262,   286,   262,   286,   262,   286,   262,
     286,   262,   262,   262,   289,   286,   263,   262,   262,   262,
     264,   264,   286,   289,   286,   289,   289,   289,   271,   262,
     282,   282,     4,     5,   311,   264,   264,   262,   262,   264,
     262,   262,   262,   264,   262,   264,   262,   264,   262,   263,
     263,   264,   264,   262,   262,   282,   262,   262,   264,   262,
     262,   262,   262,   286,   262,   262,   286,   264,   286,   286,
     286,   286,   262,   264,   264,   264,   264,   264,   262,   264,
     264,   262,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   262,   264,   264,   262,   262,   262,   264,
     262,   262,   264,   262,   264,   264,   264,   264,   264,   262,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   262,   262,   262,   262,   264,   264,   264,   264,   264,
     262,   264,   264,   264,   264,   264,   264,   262,   264,   262,
     262,   262,   262,   262,   264,   262,   262,   264,   262,   264,
     264,   289,   289,   321,   269,   289,   298,   384,   298,   385,
     302,   302,   314,   302,   302,   316,   305,    43,   331,   347,
      49,    50,   353,   262,   289,   262,   264,   264,   263,   286,
     286,   289,   289,   263,   286,   368,   369,   289,     4,     5,
     359,   361,   264,   264,   263,   263,   262,   262,   264,   264,
     289,    85,    85,   262,   262,   294,   286,   286,   262,   294,
     262,   262,   262,   286,   294,   289,   294,   286,   294,   294,
     286,   289,   289,   289,   294,   294,   289,   262,   262,   289,
     262,   289,   262,   286,   289,   262,   286,   286,   286,   262,
     262,   286,   286,   286,   289,   262,   286,   262,   289,   262,
     286,   262,   286,   286,   289,   286,   289,   262,   286,   262,
     286,   262,   289,   262,   262,   262,   286,   289,   286,   289,
     289,   262,   286,   289,   289,   262,   286,   286,   289,   286,
     286,   289,   262,   286,   289,   262,   289,   286,   289,   262,
     286,   262,   289,   262,   286,   289,   262,   286,   262,   286,
     262,   286,   286,   286,   262,   262,   302,   289,   289,   289,
     262,   262,   273,   289,   294,   294,   308,   289,   289,   289,
     289,   289,   286,    97,   286,   286,   264,   264,   289,   289,
     294,   289,   286,   286,   289,   289,   289,   289,   286,   264,
     262,   262,   262,   262,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   286,   289,   286,   286,   286,   286,   286,
     289,   289,   289,   289,   293,   286,   293,   286,   286,   289,
      16,    44,   341,   262,   262,   264,   264,   264,   264,    39,
      40,   333,   269,   289,   262,   286,    58,   286,   366,   262,
     289,   262,   264,   359,   359,   264,   263,   263,   262,   302,
     302,   289,   289,   262,   383,   383,   286,   286,   262,   262,
     286,   289,   289,   286,   262,   262,   282,   262,   262,   282,
     262,   262,   262,   282,   262,   262,   286,   286,   286,   286,
     286,   262,   286,   286,   262,   262,   262,   286,   262,   286,
     286,   262,   286,   262,   262,   286,   262,   286,   262,   286,
     286,   286,   286,   262,   286,   286,   262,   262,   286,   262,
     262,   289,   262,   286,   286,   262,   286,   262,   262,   286,
     262,   286,   262,   286,   262,   262,   286,   286,   264,   264,
     264,   262,   264,   286,   286,   282,   263,   264,   264,   264,
     264,   264,   264,   264,   262,   264,   264,   264,   264,   282,
     262,   262,   286,   286,   286,   286,   264,   264,   264,   264,
     264,   262,   264,   264,   264,   262,   264,   264,   264,   262,
     262,   264,   262,   264,   264,   264,   262,   262,   264,   262,
     264,   264,   262,   264,   264,   264,    12,   298,   298,   330,
      43,    38,   348,   264,   289,   264,   263,   262,   289,   262,
     286,    58,   375,   370,   302,   302,   360,   264,   264,   286,
     286,   286,   262,   262,   262,   286,   286,   294,   286,   286,
     294,   289,   289,   289,   294,   289,   286,   262,   262,   262,
     262,   289,   262,   262,   286,   289,   289,   262,   286,   262,
     262,   289,   289,   286,   289,   262,   286,   262,   289,   262,
     262,   262,   262,   286,   262,   262,   286,   289,   286,   262,
     289,   289,   289,   262,   262,   289,   286,   286,   262,   286,
     289,   262,   286,   262,   286,   286,    75,    75,   289,    75,
     262,   294,     4,     5,   317,   318,   286,   289,   286,   289,
     264,   264,   262,   289,   286,   286,   289,   289,   286,   289,
     286,   286,   289,   332,   334,    48,   355,    60,    61,   264,
      58,   289,   286,   264,   289,   264,   263,   381,   359,   264,
     264,   359,   262,   286,   286,   286,   262,   282,   262,   262,
     262,   282,   262,   262,   286,   289,   289,   286,   262,   289,
     286,   262,   286,   262,   286,   289,   262,   262,   286,   286,
     262,   289,   289,   286,   286,   289,   286,   262,   289,   262,
     262,   262,   289,   286,   262,   262,   286,   262,   262,   286,
     262,   286,   262,   286,   286,   264,   286,   289,   263,   263,
     262,   264,   264,   262,   286,   264,   264,   264,   264,   264,
     264,   264,   264,   264,    13,   325,   269,   269,   289,    47,
     354,   263,   263,   262,   264,    60,    61,   371,   264,    58,
     376,   289,   359,   286,   286,   294,   289,   286,   289,   294,
     289,   286,   262,   262,   262,   262,   289,   262,   262,   289,
     262,   289,   262,   262,   289,   289,   262,   262,   289,   262,
     262,   262,   262,   289,   262,   289,   289,   289,   262,   262,
     289,   286,   286,   286,   262,   286,   289,   262,   286,    75,
     264,   264,   318,   309,   289,   289,   322,    46,   358,   269,
     349,   286,   289,   289,   377,   263,   381,   372,   263,   381,
     262,   262,   262,   262,   262,   262,   262,   286,   286,   286,
     286,   262,   286,   286,   262,   289,   286,   289,   262,   286,
     289,   289,   286,   286,   286,   286,   262,   262,   262,   286,
     286,   262,   286,   262,   262,   286,   286,   269,   264,   269,
     356,    14,    16,    18,    41,    44,    49,   350,   262,   264,
     262,   264,   381,   286,   359,   381,   289,   359,   289,   286,
     286,   289,   286,   286,   286,   262,   289,   289,   262,   262,
     262,   289,   262,   262,   289,   286,   289,   262,   286,   286,
     286,   262,    25,    44,   310,   323,   269,   286,   289,   359,
     262,   264,   359,   262,   264,   262,   286,   289,   286,   289,
     286,   286,   262,   286,   262,   286,    14,    16,    18,    41,
      44,    49,   324,   357,   264,   264,   286,   378,   289,   373,
     286,   262,   262,   289,   286,     4,   326,   355,   264,   381,
     264,   381,   286,   286,   262,   379,   359,   374,   359,   262,
     286,   381,   381,   286,   359,   359
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   266,   267,   267,   267,   267,   267,   268,   269,   270,
     271,   269,   272,   272,   272,   272,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   274,   273,   275,   273,   273,   273,   273,   273,   273,
     273,   276,   273,   277,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   278,   273,   279,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   280,   280,   280,   280,   280,   281,   281,   281,
     281,   281,   281,   282,   282,   283,   283,   283,   283,   283,
     284,   284,   285,   285,   286,   286,   286,   286,   286,   286,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   288,   288,   290,   289,   291,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   289,   292,
     293,   294,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   296,   296,   296,   297,   297,
     297,   297,   298,   298,   299,   299,   299,   299,   300,   301,
     303,   302,   304,   304,   304,   305,   305,   307,   308,   309,
     306,   310,   310,   311,   311,   312,   312,   312,   312,   313,
     313,   314,   314,   314,   314,   315,   315,   316,   316,   316,
     316,   317,   317,   317,   318,   318,   318,   318,   320,   321,
     322,   323,   319,   324,   324,   324,   324,   324,   324,   325,
     325,   326,   326,   328,   327,   329,   329,   330,   330,   331,
     332,   331,   333,   334,   333,   336,   335,   337,   337,   337,
     337,   337,   337,   339,   340,   338,   341,   341,   343,   342,
     344,   344,   344,   344,   344,   344,   346,   347,   348,   349,
     345,   350,   350,   350,   350,   350,   350,   352,   351,   353,
     353,   354,   354,   355,   356,   357,   355,   358,   358,   359,
     360,   359,   361,   361,   361,   361,   362,   362,   363,   363,
     363,   363,   364,   364,   364,   364,   365,   365,   365,   365,
     365,   366,   366,   366,   368,   367,   369,   367,   370,   367,
     371,   367,   372,   367,   373,   367,   374,   367,   375,   367,
     376,   367,   377,   367,   378,   367,   379,   367,   380,   367,
     381,   381,   382,   382,   382,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   382,   382,   383,   383,   384,   384,
     385,   385
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
       6,     5,     2,     2,     2,     9,     3,     7,     8,     5,
      11,     7,     5,     7,     7,    11,     7,     9,    13,    11,
       9,    11,     3,     6,     4,     6,     3,     3,     3,     3,
      10,    10,     5,    10,     5,     8,     5,    10,    12,     5,
       5,     3,    10,     5,     5,     3,    11,    14,    16,     7,
       7,    11,     5,     6,     7,     9,    12,     9,    14,     5,
       7,     7,    11,     4,    10,     5,     5,     5,    12,     7,
      12,     7,     9,    10,     5,     8,     8,    10,     5,     7,
       5,     5,     5,     3,     3,    10,     5,     5,     5,     3,
      10,     5,     9,     7,     5,     5,     7,     5,     3,     5,
       5,     3,    12,    15,    11,     5,     6,     5,     3,    11,
      10,     5,     6,     9,     8,     7,     9,    10,     9,    11,
      12,    13,    11,     3,     9,     5,     6,     7,     3,    11,
       2,     3,     2,     2,     1,     1,     3,     4,     4,     4,
       4,     4,     4,     1,     1,     2,     1,     2,     2,     8,
       6,     6,     0,     1,     1,     2,     2,     3,    10,     8,
       8,     8,     3,     1,     1,     6,     4,     4,     6,     6,
       4,     6,     1,     4,     1,     1,     1,     1,     3,     3,
       6,     6,     8,     6,     4,     6,     8,     4,     1,     3,
       4,     4,     4,     4,     4,     4,     4,     6,     8,     4,
       4,     4,     4,     4,     6,     1,     3,     1,     3,     4,
       3,     3,     6,     8,     3,     3,     5,     5,     5,     7,
       3,     4,     5,     2,     1,     3,     3,     7,     6,     6,
       4,     6,     4,     6,    10,     4,     4,     4,     8,     6,
       4,     3,     3,     0,     4,     0,     4,     2,     3,     3,
       3,     3,     3,     3,     3,     4,     6,     1,     4,     4,
       6,     6,     1,     1,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       3,     3,     4,     4,     4,     4,     4,     4,     6,     4,
       4,     6,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     4,     3,     6,     6,     4,     4,     4,     4,
       6,     6,     8,     6,     8,     4,     4,     4,     8,     4,
       4,     4,     4,     1,     3,     4,     1,     3,     4,     1,
       3,     4,     1,     3,     6,     6,     4,     6,     6,     6,
       4,     8,     6,     8,     6,     4,     4,     4,     6,     6,
       6,     8,     4,     2,     5,     7,     5,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     4,     3,     5,     5,
       3,     3,     5,     7,     4,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     4,     6,     4,     6,     4,     4,
       0,     2,     0,     1,     3,     1,     1,     0,     0,     0,
      11,     1,     1,     1,     1,     0,     1,     1,     2,     1,
       3,     1,     1,     4,     4,     1,     3,     1,     1,     4,
       4,     0,     1,     3,     1,     1,     3,     3,     0,     0,
       0,     0,    14,     1,     1,     1,     1,     1,     1,     0,
       2,     0,     1,     0,     7,     1,     2,     1,     1,     0,
       0,     5,     0,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     1,     0,     0,     6,     1,     1,     0,     4,
       1,     2,     1,     1,     1,     1,     0,     0,     0,     0,
      11,     1,     1,     1,     1,     1,     1,     0,     5,     1,
       1,     0,     2,     0,     0,     0,     7,     0,     1,     1,
       0,     4,     1,     4,     1,     4,     1,     3,     1,     4,
       1,     4,     1,     1,     3,     3,     0,     2,     4,     1,
       3,     0,     2,     6,     0,     4,     0,     4,     0,     6,
       0,     9,     0,    10,     0,    13,     0,    15,     0,     7,
       0,     9,     0,    10,     0,    13,     0,    15,     0,     3,
       0,     1,     0,     2,     2,     4,     1,     4,     6,     6,
       7,    10,    12,     7,    10,    12,     2,     1,     1,     3,
       1,     3
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

  case 99: /* statement: tDRAW tSET string_expression ',' string_expression  */
                                                       {add_command(cYABDRAWSETTEXT);}
    break;

  case 100: /* statement: tDRAW tSET string_expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                    {add_command(cYABDRAWSETCOLOUR);}
    break;

  case 101: /* statement: tDRAW tTEXT coordinates ',' string_expression ',' string_expression  */
                                                                        {add_command(cYABDRAWTEXT);}
    break;

  case 102: /* statement: tDRAW tDOT coordinates ',' string_expression  */
                                                 {add_command(cYABDRAWDOT);}
    break;

  case 103: /* statement: tDRAW tLINE coordinates to coordinates ',' string_expression  */
                                                                 {add_command(cYABDRAWLINE);}
    break;

  case 104: /* statement: tDRAW tRECT coordinates to coordinates ',' string_expression  */
                                                                 {add_command(cYABDRAWRECT);}
    break;

  case 105: /* statement: tDRAW tROUNDRECT coordinates to coordinates ',' expression ',' expression ',' string_expression  */
                                                                                                    {add_command(cYABDRAWROUNDRECT);}
    break;

  case 106: /* statement: tDRAW tCIRCLE coordinates ',' expression ',' string_expression  */
                                                                   {add_command(cYABDRAWCIRCLE);}
    break;

  case 107: /* statement: tDRAW tELLIPSE coordinates ',' expression ',' expression ',' string_expression  */
                                                                                   {add_command(cYABDRAWELLIPSE);}
    break;

  case 108: /* statement: tDRAW tARC coordinates ',' expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                             {add_command(cYABDRAWARC);}
    break;

  case 109: /* statement: tDRAW tCURVE coordinates to coordinates to coordinates to coordinates ',' string_expression  */
                                                                                                {add_command(cYABDRAWCURVE);}
    break;

  case 110: /* statement: tDRAW tTRIANGLE coordinates to coordinates to coordinates ',' string_expression  */
                                                                                    {add_command(cYABDRAWTRIANGLE);}
    break;

  case 111: /* statement: tDRAW tPOLYGON coordinates to coordinates to coordinates to coordinates ',' string_expression  */
                                                                                                  {add_command(cYABDRAWPOLYGON);}
    break;

  case 112: /* statement: tDRAW tFLUSH string_expression  */
                                   {add_command(cYABDRAWFLUSH);}
    break;

  case 113: /* statement: tSCREENSHOT coordinates to coordinates ',' string_expression  */
                                                                 {add_command(cYABSCREENSHOT);}
    break;

  case 114: /* statement: tLAYOUT string_expression ',' string_expression  */
                                                    {add_command(cYABLAYOUT);}
    break;

  case 115: /* statement: tALERT string_expression ',' string_expression ',' string_expression  */
                                                                         {add_command(cYABALERT);}
    break;

  case 116: /* statement: tSOUND tSTOP expression  */
                            {add_command(cYABSOUNDSTOP);}
    break;

  case 117: /* statement: tSOUND tWAIT expression  */
                            {add_command(cYABSOUNDWAIT);}
    break;

  case 118: /* statement: tMEDIASOUND tSTOP expression  */
                                 {add_command(cYABMEDIASOUNDSTOP);}
    break;

  case 119: /* statement: tLOUDNESS tSET expression  */
                              {add_command(cYABLOUDNESSSET);}
    break;

  case 120: /* statement: tBUTTON coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                         {add_command(cYABBUTTON);}
    break;

  case 121: /* statement: tCHECKBOX coordinates ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                           {add_command(cYABCHECKBOX);}
    break;

  case 122: /* statement: tCHECKBOX tSET string_expression ',' expression  */
                                                    {add_command(cYABCHECKBOXSET);}
    break;

  case 123: /* statement: tRADIOBUTTON coordinates ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                              {add_command(cYABRADIOBUTTON);}
    break;

  case 124: /* statement: tRADIOBUTTON tSET string_expression ',' expression  */
                                                       {add_command(cYABRADIOSET);}
    break;

  case 125: /* statement: tTEXT coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                        {add_command(cYABTEXT);}
    break;

  case 126: /* statement: tTEXT tSET string_expression ',' string_expression  */
                                                       {add_command(cYABTEXTALIGN);}
    break;

  case 127: /* statement: tTEXTURL coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                 {add_command(cYABTEXTURL);}
    break;

  case 128: /* statement: tTEXTCONTROL coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                    {add_command(cYABTEXTCONTROL);}
    break;

  case 129: /* statement: tTEXTCONTROL tSET string_expression ',' string_expression  */
                                                              {add_command(cYABTEXTCONTROLSET);}
    break;

  case 130: /* statement: tTEXTCONTROL tSET string_expression ',' expression  */
                                                       {add_command(cYABTEXTCONTROLMASK);}
    break;

  case 131: /* statement: tTEXTCONTROL tCLEAR string_expression  */
                                          {add_command(cYABTEXTCONTROLCLEAR);}
    break;

  case 132: /* statement: tTEXTEDIT coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                    {add_command(cYABTEXTEDIT);}
    break;

  case 133: /* statement: tTEXTEDIT tADD string_expression ',' string_expression  */
                                                           {add_command(cYABTEXTEDITADD);}
    break;

  case 134: /* statement: tTEXTEDIT tSET string_expression ',' string_expression  */
                                                           {add_command(cYABTEXTEDITSET);}
    break;

  case 135: /* statement: tTEXTEDIT tCLEAR string_expression  */
                                       {add_command(cYABTEXTEDITCLEAR);}
    break;

  case 136: /* statement: tTEXTEDIT tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                           {add_command(cYABTEXTEDITCOLOUR);}
    break;

  case 137: /* statement: tSLIDER coordinates to coordinates ',' string_expression ',' string_expression ',' expression ',' expression ',' string_expression  */
                                                                                                                                       {add_command(cYABSLIDER);}
    break;

  case 138: /* statement: tSLIDER coordinates to coordinates ',' string_expression ',' string_expression ',' expression ',' expression ',' string_expression ',' string_expression  */
                                                                                                                                                             {add_command(cYABSLIDEROPT);}
    break;

  case 139: /* statement: tSLIDER tLABEL string_expression ',' string_expression ',' string_expression  */
                                                                                 {add_command(cYABSLIDERLABEL);}
    break;

  case 140: /* statement: tSLIDER tSET string_expression ',' string_expression ',' expression  */
                                                                        {add_command(cYABSLIDERMARKS);}
    break;

  case 141: /* statement: tSLIDER tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                         {add_command(cYABSLIDERCOLOUR);}
    break;

  case 142: /* statement: tSLIDER tSET string_expression ',' expression  */
                                                  {add_command(cYABSLIDERSET);}
    break;

  case 143: /* statement: tSCROLLBAR string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cYABSCROLLBAR);}
    break;

  case 144: /* statement: tSCROLLBAR tSET string_expression ',' string_expression ',' expression  */
                                                                           {add_command(cYABSCROLLBARSET);}
    break;

  case 145: /* statement: tSCROLLBAR tSET string_expression ',' string_expression ',' expression ',' expression  */
                                                                                          {add_command(cYABSCROLLBARRANGE);}
    break;

  case 146: /* statement: tSTATUSBAR coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                  {add_command(cYABSTATUSBAR);}
    break;

  case 147: /* statement: tSTATUSBAR tSET string_expression ',' string_expression ',' string_expression ',' expression  */
                                                                                                 {add_command(cYABSTATUSBARSET);}
    break;

  case 148: /* statement: tSPINCONTROL coordinates ',' string_expression ',' string_expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                                                            {add_command(cYABSPINCONTROL);}
    break;

  case 149: /* statement: tSPINCONTROL tSET string_expression ',' expression  */
                                                       {add_command(cYABSPINCONTROLSET);}
    break;

  case 150: /* statement: tOPTION tSET string_expression ',' string_expression ',' string_expression  */
                                                                               {add_command(cYABOPTIONTEXT);}
    break;

  case 151: /* statement: tOPTION tSET string_expression ',' string_expression ',' expression  */
                                                                        {add_command(cYABOPTIONNUMBER);}
    break;

  case 152: /* statement: tOPTION tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                         {add_command(cYABOPTIONCOLOUR);}
    break;

  case 153: /* statement: tTOOLTIP string_expression ',' string_expression  */
                                                     {add_command(cYABTOOLTIP);}
    break;

  case 154: /* statement: tTABVIEW coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                          {add_command(cYABTABVIEW);}
    break;

  case 155: /* statement: tTABVIEW tADD string_expression ',' string_expression  */
                                                          {add_command(cYABTABADD);}
    break;

  case 156: /* statement: tTABVIEW tSET string_expression ',' expression  */
                                                   {add_command(cYABTABSET);}
    break;

  case 157: /* statement: tTABVIEW tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABTABREMOVE);}
    break;

  case 158: /* statement: tBOXVIEW coordinates to coordinates ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                                         {add_command(cYABBOXVIEW);}
    break;

  case 159: /* statement: tBOXVIEW tSET string_expression ',' string_expression ',' string_expression  */
                                                                                {add_command(cYABBOXVIEWSET);}
    break;

  case 160: /* statement: tSPLITVIEW coordinates to coordinates ',' string_expression ',' expression ',' expression ',' string_expression  */
                                                                                                                    {add_command(cYABSPLITVIEW);}
    break;

  case 161: /* statement: tSPLITVIEW tSET string_expression ',' string_expression ',' expression  */
                                                                           {add_command(cYABSPLITVIEWSET);}
    break;

  case 162: /* statement: tSPLITVIEW tSET string_expression ',' string_expression ',' expression ',' expression  */
                                                                                          {add_command(cYABSPLITVIEWMIN);}
    break;

  case 163: /* statement: tSTACKVIEW coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                     {add_command(cYABSTACKVIEW);}
    break;

  case 164: /* statement: tSTACKVIEW tSET string_expression ',' expression  */
                                                     {add_command(cYABSTACKVIEWSET);}
    break;

  case 165: /* statement: tCANVAS coordinates to coordinates ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABCANVAS);}
    break;

  case 166: /* statement: tREGION coordinates to coordinates ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABREGION);}
    break;

  case 167: /* statement: tLISTBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                   {add_command(cYABLISTBOX);}
    break;

  case 168: /* statement: tLISTBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABLISTBOXADD);}
    break;

  case 169: /* statement: tLISTBOX tADD string_expression ',' expression ',' string_expression  */
                                                                         {add_command(cYABLISTBOXADD2);}
    break;

  case 170: /* statement: tLISTBOX tREMOVE string_expression ',' string_expression  */
                                                             {add_command(cYABLISTBOXREMOVE);}
    break;

  case 171: /* statement: tLISTBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABLISTBOXREMOVE2);}
    break;

  case 172: /* statement: tLISTBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABLISTBOXSELECT);}
    break;

  case 173: /* statement: tLISTBOX tCLEAR string_expression  */
                                      {add_command(cYABLISTBOXCLEAR);}
    break;

  case 174: /* statement: tLISTBOX tSORT string_expression  */
                                     {add_command(cYABLISTSORT);}
    break;

  case 175: /* statement: tDROPBOX coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                          {add_command(cYABDROPBOX);}
    break;

  case 176: /* statement: tDROPBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABDROPBOXADD);}
    break;

  case 177: /* statement: tDROPBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABDROPBOXSELECT);}
    break;

  case 178: /* statement: tDROPBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABDROPBOXREMOVE);}
    break;

  case 179: /* statement: tDROPBOX tCLEAR string_expression  */
                                      {add_command(cYABDROPBOXCLEAR);}
    break;

  case 180: /* statement: tTREEBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                   {add_command(cYABTREEBOX);}
    break;

  case 181: /* statement: tTREEBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABTREEADD);}
    break;

  case 182: /* statement: tTREEBOX tADD string_expression ',' string_expression ',' string_expression ',' expression  */
                                                                                               {add_command(cYABTREEADDCHILD);}
    break;

  case 183: /* statement: tTREEBOX tADD string_expression ',' string_expression ',' expression  */
                                                                         {add_command(cYABTREEADDAT);}
    break;

  case 184: /* statement: tTREEBOX tREMOVE string_expression ',' string_expression  */
                                                             {add_command(cYABTREEREMOVE);}
    break;

  case 185: /* statement: tTREEBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABTREEREMOVE2);}
    break;

  case 186: /* statement: tTREEBOX tREMOVE string_expression ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABTREEREMOVECHILD);}
    break;

  case 187: /* statement: tTREEBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABTREESELECT);}
    break;

  case 188: /* statement: tTREEBOX tCLEAR string_expression  */
                                      {add_command(cYABTREECLEAR);}
    break;

  case 189: /* statement: tTREEBOX tEXPAND string_expression ',' string_expression  */
                                                             {add_command(cYABTREEEXPAND);}
    break;

  case 190: /* statement: tTREEBOX tCOLLAPSE string_expression ',' string_expression  */
                                                               {add_command(cYABTREECOLLAPSE);}
    break;

  case 191: /* statement: tTREEBOX tSORT string_expression  */
                                     {add_command(cYABTREESORT);}
    break;

  case 192: /* statement: tCOLUMNBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression ',' string_expression  */
                                                                                                                           {add_command(cYABCOLUMNBOX);}
    break;

  case 193: /* statement: tCOLUMNBOX tCOLUMN string_expression ',' string_expression ',' expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                                                                 {add_command(cYABCOLUMNBOXCOLUMN);}
    break;

  case 194: /* statement: tCOLUMNBOX tADD string_expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                         {add_command(cYABCOLUMNBOXADD);}
    break;

  case 195: /* statement: tCOLUMNBOX tREMOVE string_expression ',' expression  */
                                                        {add_command(cYABCOLUMNBOXREMOVE);}
    break;

  case 196: /* statement: tCOLUMNBOX tREMOVE tCOLUMN string_expression ',' expression  */
                                                                {add_command(cYABCOLUMNBOXREMOVECOLUMN);}
    break;

  case 197: /* statement: tCOLUMNBOX tSELECT string_expression ',' expression  */
                                                        {add_command(cYABCOLUMNBOXSELECT);}
    break;

  case 198: /* statement: tCOLUMNBOX tCLEAR string_expression  */
                                        {add_command(cYABCOLUMNBOXCLEAR);}
    break;

  case 199: /* statement: tCOLUMNBOX tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                            {add_command(cYABCOLUMNBOXCOLOUR);}
    break;

  case 200: /* statement: tCALENDAR coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                  {add_command(cYABCALENDAR);}
    break;

  case 201: /* statement: tCALENDAR tSET string_expression ',' string_expression  */
                                                           {add_command(cYABCALENDARSET);}
    break;

  case 202: /* statement: tCOLORCONTROL coordinates ',' string_expression ',' string_expression  */
                                                                          {add_command(cYABCOLORCONTROL);}
    break;

  case 203: /* statement: tCOLORCONTROL tSET string_expression ',' expression ',' expression ',' expression  */
                                                                                      {add_command(cYABCOLORCONTROLSET);}
    break;

  case 204: /* statement: tMENU string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                              {add_command(cYABMENU);}
    break;

  case 205: /* statement: tMENU tSET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cYABMENURADIO);}
    break;

  case 206: /* statement: tMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                   {add_command(cYABMENUOPTION);}
    break;

  case 207: /* statement: tSUBMENU string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                       {add_command(cYABSUBMENU);}
    break;

  case 208: /* statement: tSUBMENU tSET string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                               {add_command(cYABSUBMENURADIO);}
    break;

  case 209: /* statement: tSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                            {add_command(cYABSUBMENUOPTION);}
    break;

  case 210: /* statement: tSUBSUBMENU string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                                {add_command(cYABSUBSUBMENU);}
    break;

  case 211: /* statement: tSUBSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                                     {add_command(cYABSUBSUBMENUOPTION);}
    break;

  case 212: /* statement: tSUBSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                                        {add_command(cYABSUBSUBMENURADIO);}
    break;

  case 213: /* statement: tCLIPBOARD tCOPY string_expression  */
                                       {add_command(cYABCLIPBOARDCOPY);}
    break;

  case 214: /* statement: tATTRIBUTE tSET string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                        {add_command(cYABATTRIBUTESET);}
    break;

  case 215: /* statement: tATTRIBUTE tCLEAR string_expression ',' string_expression  */
                                                              {add_command(cYABATTRIBUTECLEAR);}
    break;

  case 216: /* statement: tBITMAP expression ',' expression ',' string_expression  */
                                                            {add_command(cYABBITMAP);}
    break;

  case 217: /* statement: tBITMAP tGET string_expression ',' string_expression ',' string_expression  */
                                                                               {add_command(cYABBITMAPGET);}
    break;

  case 218: /* statement: tBITMAP tREMOVE string_expression  */
                                      {add_command(cYABBITMAPREMOVE);}
    break;

  case 219: /* statement: tDRAW tBITMAP expression ',' expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                              {add_command(cYABBITMAPDRAW);}
    break;

  case 220: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 221: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 222: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 223: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 224: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 225: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 226: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 227: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 228: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 229: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 230: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 231: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 232: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 233: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 234: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 235: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 236: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 237: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 238: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 239: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 240: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 241: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 242: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 243: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 244: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 245: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 246: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 247: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 248: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 249: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 250: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 251: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 252: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 255: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 256: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 257: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 258: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 259: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 260: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 261: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 262: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 263: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 264: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 266: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 267: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 268: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 270: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 271: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 272: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 273: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 274: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 275: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 276: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 277: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 278: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 279: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 280: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 281: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 282: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 283: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 284: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 285: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 286: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 287: /* string_function: tSTRING2 '(' expression ',' string_expression ')'  */
                                                      {create_function(fSTRING);}
    break;

  case 288: /* string_function: tREPLACE '(' string_expression ',' string_expression ',' string_expression ')'  */
                                                                                    {create_function(fREPLACE);}
    break;

  case 289: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 290: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 291: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 292: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 293: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 294: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 295: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 296: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 297: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 298: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 299: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 300: /* string_function: tTEXTCONTROL tGET string_expression  */
                                        {create_function(fYABTEXTCONTROLGET);}
    break;

  case 301: /* string_function: tTEXTEDIT tGET string_expression  */
                                     {create_function(fYABTEXTEDITGET);}
    break;

  case 302: /* string_function: tPOPUPMENU coordinates ',' string_expression ',' string_expression  */
                                                                                       {create_function(fYABPOPUPMENU);}
    break;

  case 303: /* string_function: tFILEPANEL string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                   {create_function(fYABFILEPANEL);}
    break;

  case 304: /* string_function: tTEXTCONTROL tGETS string_expression  */
                                                         {create_function(fYABTEXTCONTROLGET);}
    break;

  case 305: /* string_function: tTEXTEDIT tGETS string_expression  */
                                                      {create_function(fYABTEXTEDITGET);}
    break;

  case 306: /* string_function: tLISTBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABLISTBOXGET);}
    break;

  case 307: /* string_function: tDROPBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABDROPBOXGET);}
    break;

  case 308: /* string_function: tTREEBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABTREEBOXGET);}
    break;

  case 309: /* string_function: tCOLUMNBOX tGETS string_expression ',' expression ',' expression  */
                                                                                     {create_function(fYABCOLUMNBOXGET);}
    break;

  case 310: /* string_function: tCALENDAR tGET string_expression  */
                                                     {create_function(fYABCALENDARGET);}
    break;

  case 311: /* string_function: tTRANSLATE '(' string_expression ')'  */
                                         {create_function(fYABTRANSLATE);}
    break;

  case 312: /* string_function: tMENU tTRANSLATE '(' string_expression ')'  */
                                               {create_function(fYABMENUTRANSLATE);}
    break;

  case 313: /* string_function: tCLIPBOARD tPASTE  */
                      {create_function(fYABCLIPBOARDPASTE);}
    break;

  case 314: /* string_function: tMESSAGE  */
             {create_function(fYABMESSAGE);}
    break;

  case 315: /* string_function: tMOUSE tMESSAGE string_expression  */
                                                      {create_function(fYABMOUSEMESSAGE);}
    break;

  case 316: /* string_function: tKEYBOARD tMESSAGE string_expression  */
                                                         {create_function(fYABKEYBOARDMESSAGE);}
    break;

  case 317: /* string_function: tATTRIBUTE tGETS '(' string_expression ',' string_expression ')'  */
                                                                     {create_function(fYABATTRIBUTEGET);}
    break;

  case 318: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 319: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 320: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 321: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 322: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 323: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 324: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 325: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 326: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 327: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 328: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 329: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 330: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 331: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 332: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 333: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 334: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 335: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 336: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 337: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 338: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 339: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 340: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 341: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 342: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 343: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 344: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 345: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 346: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 347: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 348: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 349: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 350: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 351: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 352: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 353: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 354: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 355: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 356: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 357: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 358: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 359: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 360: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 361: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 362: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 363: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 364: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 365: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 366: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 369: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 370: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 372: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 373: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 374: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 375: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 376: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 377: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 378: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 379: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 380: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 381: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 382: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 383: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 384: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 385: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 386: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 387: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 388: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 389: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 390: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 391: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 392: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 393: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 394: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 395: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 396: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 397: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 398: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 399: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 400: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 401: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 402: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 403: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 404: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 405: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 406: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 407: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 408: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 409: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 410: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 411: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 412: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 413: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 414: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 415: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 416: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 417: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 418: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 419: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 420: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 421: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 422: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 423: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 424: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 425: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 426: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 427: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 428: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 429: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 430: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 431: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 432: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 433: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 434: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 435: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 436: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 437: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 438: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 439: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 440: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 441: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 442: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 443: /* function: tWINDOW tCOUNT  */
                   {create_function(fYABNUMWINDOWS);}
    break;

  case 444: /* function: tWINDOW tGET string_expression ',' string_expression  */
                                                         {create_function(fYABWINDOWGET);}
    break;

  case 445: /* function: tATTRIBUTE tGET '(' string_expression ',' string_expression ')'  */
                                                                    {create_function(fYABATTRIBUTEGETNUM);}
    break;

  case 446: /* function: tSOUND tPLAY string_expression ',' expression  */
                                                                  {create_function(fYABSOUNDPLAY);}
    break;

  case 447: /* function: tMEDIASOUND tPLAY string_expression  */
                                                        {create_function(fYABMEDIASOUNDPLAY);}
    break;

  case 448: /* function: tLOUDNESS tGET  */
                   {create_function(fYABLOUDNESSGET);}
    break;

  case 449: /* function: tLISTBOX tCOUNT string_expression  */
                                                      {create_function(fYABLISTBOXCOUNT);}
    break;

  case 450: /* function: tLISTBOX tGET string_expression  */
                                                    {create_function(fYABLISTBOXSELECTED);}
    break;

  case 451: /* function: tDROPBOX tCOUNT string_expression  */
                                                      {create_function(fYABDROPBOXCOUNT);}
    break;

  case 452: /* function: tDROPBOX tGET string_expression  */
                                                    {create_function(fYABDROPBOXSELECTED);}
    break;

  case 453: /* function: tTREEBOX tCOUNT string_expression  */
                                                      {create_function(fYABTREEBOXCOUNT);}
    break;

  case 454: /* function: tTREEBOX tGET string_expression  */
                                                    {create_function(fYABTREEBOXSELECTED);}
    break;

  case 455: /* function: tCOLUMNBOX tCOUNT string_expression  */
                                                        {create_function(fYABCOLUMNBOXCOUNT);}
    break;

  case 456: /* function: tCOLUMNBOX tCOUNT tCOLUMN string_expression  */
                                                                {create_function(fYABCOLUMNBOXCOUNTCOLUMNS);}
    break;

  case 457: /* function: tCOLUMNBOX tGET string_expression  */
                                                      {create_function(fYABCOLUMNBOXSELECTED);}
    break;

  case 458: /* function: tCOLORCONTROL tGET string_expression ',' string_expression  */
                                                                               {create_function(fYABCOLORCONTROLGET);}
    break;

  case 459: /* function: tSPLITVIEW tGET string_expression ',' string_expression  */
                                                                            {create_function(fYABSPLITVIEWGET);}
    break;

  case 460: /* function: tSTACKVIEW tGET string_expression  */
                                                      {create_function(fYABSTACKVIEWGET);}
    break;

  case 461: /* function: tTABVIEW tGET string_expression  */
                                                    {create_function(fYABTABVIEWGET);}
    break;

  case 462: /* function: tDRAW tGET string_expression ',' string_expression  */
                                                       {create_function(fYABDRAWGET);}
    break;

  case 463: /* function: tDRAW tGET string_expression ',' string_expression ',' string_expression  */
                                                                             {create_function(fYABDRAWGETTEXT);}
    break;

  case 464: /* function: tBFILESIZE '(' string_expression ')'  */
                                         {create_function(fYABBFILESIZE);}
    break;

  case 465: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 466: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 467: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 468: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 469: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 470: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 471: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 472: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 473: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 474: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 475: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 476: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 477: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 478: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 479: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 480: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 487: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 488: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 489: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 490: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 491: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 492: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 493: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 494: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 495: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 496: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 497: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 498: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 501: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 502: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 503: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 504: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 507: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 508: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 509: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 510: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 514: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 515: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 516: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 517: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 518: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 519: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 520: /* $@17: %empty  */
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

  case 521: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 522: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 523: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 524: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 525: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 526: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 527: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 528: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 529: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 531: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 532: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 533: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 534: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 540: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 541: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 543: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 545: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 547: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 548: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 549: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 550: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 551: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 552: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 553: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 554: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 556: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 557: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 558: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 560: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 561: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 562: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 563: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 564: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 565: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 566: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 567: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 568: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 569: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 571: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 572: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 573: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 574: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 575: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 576: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 577: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 579: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 580: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 584: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 585: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 590: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 592: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 593: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 594: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 595: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 598: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 599: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 600: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 601: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 602: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 603: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 604: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 605: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 609: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 610: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 611: /* using: %empty  */
       {create_print('d');}
    break;

  case 612: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 613: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 614: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 615: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 616: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 617: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 618: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 619: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 620: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 621: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 622: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 623: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 624: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 625: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 626: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 627: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 628: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 629: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 630: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 631: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 632: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 633: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 634: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 635: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 636: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 637: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 638: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 639: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 640: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 641: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 642: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 643: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 644: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 645: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 646: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 647: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 648: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 649: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 650: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 651: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 652: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 653: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 654: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 655: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 658: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 659: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 660: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 661: /* gosub_list: gosub_list ',' symbol_or_lineno  */
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

