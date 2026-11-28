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
  YYSYMBOL_tTRIM = 214,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 215,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 216,                   /* tRTRIM  */
  YYSYMBOL_tSTRING2 = 217,                 /* tSTRING2  */
  YYSYMBOL_tREPLACE = 218,                 /* tREPLACE  */
  YYSYMBOL_tINSTR = 219,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 220,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 221,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 222,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 223,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 224,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 225,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 226,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 227,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 228,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 229,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 230,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 231,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 232,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 233,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 234,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 235,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 236,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 237,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 238,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 239,                    /* tDATE  */
  YYSYMBOL_tTIME = 240,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 241,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 242,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 243,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 244,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 245,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 246,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 247,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 248, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 249,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 250, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 251,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 252,                   /* tEVAL2  */
  YYSYMBOL_tARGUMENT = 253,                /* tARGUMENT  */
  YYSYMBOL_254_ = 254,                     /* '-'  */
  YYSYMBOL_255_ = 255,                     /* '+'  */
  YYSYMBOL_256_ = 256,                     /* '*'  */
  YYSYMBOL_257_ = 257,                     /* '/'  */
  YYSYMBOL_UMINUS = 258,                   /* UMINUS  */
  YYSYMBOL_259_ = 259,                     /* ';'  */
  YYSYMBOL_260_ = 260,                     /* ','  */
  YYSYMBOL_261_ = 261,                     /* '('  */
  YYSYMBOL_262_ = 262,                     /* ')'  */
  YYSYMBOL_263_ = 263,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 264,                 /* $accept  */
  YYSYMBOL_program_or_expression = 265,    /* program_or_expression  */
  YYSYMBOL_program = 266,                  /* program  */
  YYSYMBOL_statement_list = 267,           /* statement_list  */
  YYSYMBOL_268_1 = 268,                    /* $@1  */
  YYSYMBOL_269_2 = 269,                    /* $@2  */
  YYSYMBOL_assignment = 270,               /* assignment  */
  YYSYMBOL_statement = 271,                /* statement  */
  YYSYMBOL_272_3 = 272,                    /* $@3  */
  YYSYMBOL_273_4 = 273,                    /* $@4  */
  YYSYMBOL_274_5 = 274,                    /* $@5  */
  YYSYMBOL_275_6 = 275,                    /* $@6  */
  YYSYMBOL_276_7 = 276,                    /* $@7  */
  YYSYMBOL_277_8 = 277,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 278,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 279,        /* string_assignment  */
  YYSYMBOL_to = 280,                       /* to  */
  YYSYMBOL_open_clause = 281,              /* open_clause  */
  YYSYMBOL_seek_clause = 282,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 283,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 284,        /* string_expression  */
  YYSYMBOL_string_function = 285,          /* string_function  */
  YYSYMBOL_number_assignment = 286,        /* number_assignment  */
  YYSYMBOL_expression = 287,               /* expression  */
  YYSYMBOL_288_9 = 288,                    /* $@9  */
  YYSYMBOL_289_10 = 289,                   /* $@10  */
  YYSYMBOL_arrayref = 290,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 291,          /* string_arrayref  */
  YYSYMBOL_coordinates = 292,              /* coordinates  */
  YYSYMBOL_function = 293,                 /* function  */
  YYSYMBOL_const = 294,                    /* const  */
  YYSYMBOL_number = 295,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 296,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 297,                  /* dimlist  */
  YYSYMBOL_function_or_array = 298,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 299,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 300,                /* call_list  */
  YYSYMBOL_301_11 = 301,                   /* $@11  */
  YYSYMBOL_calls = 302,                    /* calls  */
  YYSYMBOL_call_item = 303,                /* call_item  */
  YYSYMBOL_function_definition = 304,      /* function_definition  */
  YYSYMBOL_305_12 = 305,                   /* $@12  */
  YYSYMBOL_306_13 = 306,                   /* $@13  */
  YYSYMBOL_307_14 = 307,                   /* $@14  */
  YYSYMBOL_endsub = 308,                   /* endsub  */
  YYSYMBOL_function_name = 309,            /* function_name  */
  YYSYMBOL_export = 310,                   /* export  */
  YYSYMBOL_local_list = 311,               /* local_list  */
  YYSYMBOL_local_item = 312,               /* local_item  */
  YYSYMBOL_static_list = 313,              /* static_list  */
  YYSYMBOL_static_item = 314,              /* static_item  */
  YYSYMBOL_paramlist = 315,                /* paramlist  */
  YYSYMBOL_paramitem = 316,                /* paramitem  */
  YYSYMBOL_for_loop = 317,                 /* for_loop  */
  YYSYMBOL_318_15 = 318,                   /* $@15  */
  YYSYMBOL_319_16 = 319,                   /* $@16  */
  YYSYMBOL_320_17 = 320,                   /* $@17  */
  YYSYMBOL_321_18 = 321,                   /* $@18  */
  YYSYMBOL_next = 322,                     /* next  */
  YYSYMBOL_step_part = 323,                /* step_part  */
  YYSYMBOL_next_symbol = 324,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 325,  /* switch_number_or_string  */
  YYSYMBOL_326_19 = 326,                   /* $@19  */
  YYSYMBOL_sep_list = 327,                 /* sep_list  */
  YYSYMBOL_number_or_string = 328,         /* number_or_string  */
  YYSYMBOL_case_list = 329,                /* case_list  */
  YYSYMBOL_330_20 = 330,                   /* $@20  */
  YYSYMBOL_default = 331,                  /* default  */
  YYSYMBOL_332_21 = 332,                   /* $@21  */
  YYSYMBOL_do_loop = 333,                  /* do_loop  */
  YYSYMBOL_334_22 = 334,                   /* $@22  */
  YYSYMBOL_loop = 335,                     /* loop  */
  YYSYMBOL_while_loop = 336,               /* while_loop  */
  YYSYMBOL_337_23 = 337,                   /* $@23  */
  YYSYMBOL_338_24 = 338,                   /* $@24  */
  YYSYMBOL_wend = 339,                     /* wend  */
  YYSYMBOL_repeat_loop = 340,              /* repeat_loop  */
  YYSYMBOL_341_25 = 341,                   /* $@25  */
  YYSYMBOL_until = 342,                    /* until  */
  YYSYMBOL_if_clause = 343,                /* if_clause  */
  YYSYMBOL_344_26 = 344,                   /* $@26  */
  YYSYMBOL_345_27 = 345,                   /* $@27  */
  YYSYMBOL_346_28 = 346,                   /* $@28  */
  YYSYMBOL_347_29 = 347,                   /* $@29  */
  YYSYMBOL_endif = 348,                    /* endif  */
  YYSYMBOL_short_if = 349,                 /* short_if  */
  YYSYMBOL_350_30 = 350,                   /* $@30  */
  YYSYMBOL_end_of_if = 351,                /* end_of_if  */
  YYSYMBOL_else_part = 352,                /* else_part  */
  YYSYMBOL_elsif_part = 353,               /* elsif_part  */
  YYSYMBOL_354_31 = 354,                   /* $@31  */
  YYSYMBOL_355_32 = 355,                   /* $@32  */
  YYSYMBOL_maybe_then = 356,               /* maybe_then  */
  YYSYMBOL_inputlist = 357,                /* inputlist  */
  YYSYMBOL_358_33 = 358,                   /* $@33  */
  YYSYMBOL_input = 359,                    /* input  */
  YYSYMBOL_readlist = 360,                 /* readlist  */
  YYSYMBOL_readitem = 361,                 /* readitem  */
  YYSYMBOL_datalist = 362,                 /* datalist  */
  YYSYMBOL_printlist = 363,                /* printlist  */
  YYSYMBOL_using = 364,                    /* using  */
  YYSYMBOL_inputbody = 365,                /* inputbody  */
  YYSYMBOL_366_34 = 366,                   /* $@34  */
  YYSYMBOL_367_35 = 367,                   /* $@35  */
  YYSYMBOL_368_36 = 368,                   /* $@36  */
  YYSYMBOL_369_37 = 369,                   /* $@37  */
  YYSYMBOL_370_38 = 370,                   /* $@38  */
  YYSYMBOL_371_39 = 371,                   /* $@39  */
  YYSYMBOL_372_40 = 372,                   /* $@40  */
  YYSYMBOL_373_41 = 373,                   /* $@41  */
  YYSYMBOL_374_42 = 374,                   /* $@42  */
  YYSYMBOL_375_43 = 375,                   /* $@43  */
  YYSYMBOL_376_44 = 376,                   /* $@44  */
  YYSYMBOL_377_45 = 377,                   /* $@45  */
  YYSYMBOL_378_46 = 378,                   /* $@46  */
  YYSYMBOL_prompt = 379,                   /* prompt  */
  YYSYMBOL_printintro = 380,               /* printintro  */
  YYSYMBOL_hashed_number = 381,            /* hashed_number  */
  YYSYMBOL_goto_list = 382,                /* goto_list  */
  YYSYMBOL_gosub_list = 383                /* gosub_list  */
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
#define YYFINAL  261
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   16072

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  264
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  659
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2098

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   509


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
       2,     2,     2,     2,     2,   263,     2,     2,     2,     2,
     261,   262,   256,   255,   260,   254,     2,   257,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   259,
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
     245,   246,   247,   248,   249,   250,   251,   252,   253,   258
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   242,   242,   243,   244,   245,   246,   249,   252,   253,
     253,   253,   256,   257,   258,   259,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   277,   278,   278,   279,   280,   281,   282,   283,
     284,   285,   285,   287,   287,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   299,   300,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   317,   318,
     319,   320,   321,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   506,   507,   508,   509,   510,   514,   515,   516,
     517,   518,   519,   522,   523,   526,   527,   528,   529,   530,
     533,   534,   537,   538,   541,   542,   543,   544,   545,   546,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     581,   582,   585,   586,   590,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   620,
     621,   624,   624,   625,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   660,   663,   666,
     669,   670,   671,   672,   673,   674,   675,   676,   677,   678,
     679,   680,   681,   682,   683,   684,   685,   686,   687,   688,
     689,   690,   691,   692,   693,   694,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   705,   706,   707,   708,
     709,   710,   711,   712,   713,   714,   715,   716,   717,   718,
     719,   720,   721,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   731,   732,   733,   734,   735,   736,   737,   738,
     739,   742,   743,   746,   750,   751,   752,   755,   756,   757,
     758,   759,   760,   761,   762,   763,   764,   765,   766,   767,
     768,   769,   770,   773,   774,   775,   778,   779,   780,   781,
     784,   785,   788,   789,   790,   791,   794,   797,   800,   800,
     803,   804,   805,   808,   809,   812,   813,   816,   812,   821,
     822,   825,   826,   829,   830,   831,   832,   835,   836,   839,
     840,   841,   842,   845,   846,   849,   850,   851,   852,   855,
     856,   857,   860,   861,   862,   863,   866,   867,   872,   887,
     866,   892,   893,   894,   895,   896,   897,   900,   901,   904,
     905,   910,   910,   914,   915,   918,   919,   923,   925,   924,
     929,   930,   930,   934,   934,   940,   941,   942,   943,   944,
     945,   949,   950,   949,   956,   957,   961,   961,   966,   967,
     968,   969,   970,   971,   974,   975,   975,   977,   974,   981,
     982,   983,   984,   985,   986,   989,   989,   994,   995,   998,
     999,  1002,  1004,  1006,  1003,  1010,  1011,  1014,  1015,  1015,
    1018,  1019,  1021,  1022,  1026,  1027,  1030,  1031,  1033,  1034,
    1038,  1039,  1040,  1041,  1044,  1045,  1046,  1047,  1048,  1051,
    1052,  1053,  1056,  1056,  1057,  1057,  1058,  1058,  1059,  1059,
    1060,  1060,  1061,  1061,  1062,  1062,  1063,  1063,  1064,  1064,
    1065,  1065,  1066,  1066,  1067,  1067,  1068,  1068,  1071,  1072,
    1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1091,  1092,  1094,  1095,  1098,  1099
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
  "tMOUSEB", "tMOUSEMOD", "tTRIM", "tLTRIM", "tRTRIM", "tSTRING2",
  "tREPLACE", "tINSTR", "tRINSTR", "tCHOMP", "tSYSTEM", "tSYSTEM2",
  "tPEEK", "tPEEK2", "tPOKE", "tFRNFN_CALL", "tFRNFN_CALL2", "tFRNFN_SIZE",
  "tFRNBF_ALLOC", "tFRNBF_FREE", "tFRNBF_SIZE", "tFRNBF_DUMP",
  "tFRNBF_SET", "tFRNBF_GET", "tFRNBF_GET2", "tFRNBF_GET_BUFFER",
  "tFRNBF_SET_BUFFER", "tDATE", "tTIME", "tTOKEN", "tTOKENALT", "tSPLIT",
  "tSPLITALT", "tGLOB", "tSTART_PROGRAM", "tSTART_EXPRESSION",
  "tSTART_STRING_EXPRESSION", "tSTART_ASSIGNMENT",
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

#define YYPACT_NINF (-1482)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-565)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     581, 13469, 11273, 12883,    28,    93,    97,   -55,   -53, -1482,
   -1482, -1482, -1482, -1482,   269,   269,   269,  8213, -1482, -1482,
   -1482, 12883, -1482, -1482, 12883,    95,   134, -1482, -1482, -1482,
   11273,   -32, -1482, 11273,   188, -1482, 11273, 11273, 11273,   294,
      37,   269,  3721,  2374,  4355,   176, 11273,  7193,  8468,   121,
      86, 11273, -1482,    38, 12883, 12883, 12883,    43, 11273,  2304,
   11273, 11273,  8723,  8978,  7448,  6173, 11273,  6683,  9233,  9488,
   11878, 12883, 12883,   -45,  6938,  9743,  9998, 10253, 11273, 11273,
    5918,  6428,  5408,  5663, 10508, 10763, 12002, 12126, 12250,    47,
     -24,  7703, 12883,   -85,    49,   182,   -48,    59,    98,   100,
     119,  4355, 12883, 12883, 12883, -1482,   264, -1482, -1482,   149,
   -1482, -1482, -1482, -1482,   237,   301, -1482,   360, -1482, -1482,
   -1482, -1482, -1482, -1482, -1482, -1482,   125,   141, -1482, -1482,
   -1482, -1482,   160,   169,   177,   194, 11273,   217,   219,   248,
     256,   288,   300,   198,   338,   340,   344,   369,   276,   377,
     -50,   -47,   351,   528,   534,     6,    17,    27,    71,   540,
     548,   482,   493,   442, -1482,   -35, 12883, 11273,   503,   556,
     577,   479,   490,   512,   514,   520,   522,   524,   609,   610,
     630,   631,   632,   633,   659,   660,   672,   685,   705,   706,
     719,   721,   723,   736,   751,   752,   764,   765,   774,   776,
     793,   797,   803,   806,   820,   821,   823,   830,   831,   839,
     845,   846,   853,   855,   856,   870,   878,   920,   931,   941,
     978,   987,   988,   989,   991,  1001,  1013,  1014,  1021,  1022,
    1024,  1025,  1041,  1058,  1069,  1082,  1083,  1085,  1094,  1104,
    1112, 11273, 11273,   173, -1482,   671, -1482, -1482, -1482, -1482,
     654,   701,   727,   753,   754, 12883,   -40,   956,   237,   301,
     979, -1482, 11273, -1482, 12883, -1482,   933, 11273, 13245, -1482,
   -1482, -1482, -1482, -1482,   417,   595,   530,   542,   796, -1482,
   11273, -1482,   796, -1482, -1482, 11273, 13245,    40,  1114,  1092,
    1118,     7, 11273,    18,   173,  1808,  1120,  1122,  1044,  1808,
     173,  1534,   173, 11295,  1195,  1205,  1072, -1482, -1482,   505,
     505, -1482, -1482,  1117, -1482,  7958, 12883, 11273,    20,  1808,
    1147,   198, -1482, -1482, -1482,  1174, 11273, 12883, 12883, 12883,
   11515, -1482, 11273, -1482,     5, 12883,  1184, -1482, -1482, 11273,
   11018, -1482, -1482,  1808, -1482, -1482,   796,    -5,    -5, -1482,
       5, 11273, 11273, 11273, 11273, 11273, 11273, 11273, 12883, 12883,
   11273, 11273, 11273, 11273, 11273,     5,     5, 12883,  1207, 12883,
    1208, 12883, 12883,     5, 12883, 12883, 12883, 12883,     5,  1209,
   12883, 12883, 12883,     5, 12883,     5, 12883,  1218, 12883,  -133,
     -23,    -4, 12883, 12883, 12883, 12883, 12883,     5, 12883,     5,
   12883,     5, 12883,     5,     5,     5, 12883, 12883, 12883, 12883,
   12883,     5, 12883, 12883, 12883, 12883,     5, 12883, 12883, 12883,
   12883, 12883, 12883, 12883,     5, 12883, 12883, 12883, 12369, 12883,
   12883,     5, 12883,  1226, 12883,  1227, 12883,    -1, 12883,   102,
   12883,   153, 12883, 12883, 12883, 12883, 12883, 11532,   324, 11273,
   11273, 11273, 11273,  1186,  1186,  1186,  4628, 12883,   115,  1228,
     796,   428,   614, -1482,  1023, 11273, 11273, 11273, 11273, 12883,
   -1482, -1482, -1482, 11273, 11273,  1792, 11273, 11273, 11273, 11273,
    4094,  4355, 12883, -1482,   566,   566, 11273, 11273, 12883, 12883,
   12883, 12883, 12883, 12883, 12883, 12883, 12883, 12883, 12883, 12883,
   12883, 12883, 12883, 12883, 12883, 12883, 12883, 12493, 12883, 12883,
   12883,  1234, -1482, 12883,  1246,  1254,   755,  1229, 12883, 12883,
   -1482, 11273, 11273, 11273, 11273, 11273, 11273, 11273, 11273, 11273,
   11273,  4355, 11273, 11273, 11273, 11273, 11273, 11273, 11273, 11273,
    4888, 12883, 12883, 12883, 12883, 12883, 11273, 11273, 11273,  5148,
   11273, 12883, 11273, 12883, 11273, 12883, 12883,  2836, 11516, 11635,
   11754, 12883, 12883, 12883, 11273, 12883, 12883, 12883, 12883, 12883,
   12883,  4355, 12883, -1482, -1482, 12883, 11273, 12883, 12883, 12883,
   12883, 12883,   976,  1252, 12883,  1186, 12883,  1186, 12883, 12883,
   12883,  1124,    72,   842, 12883, 12883, 12883, 12883, 12883, 12883,
   12883, 12883, -1482, -1482, -1482, 11273, 11273, 11273, 11273, 11273,
   11273, 11273, 11273, 11273, 11273, 11273, 11273,  -106, -1482, -1482,
   -1482,  1808,  1261,   796,  1263,  1441,  1808,   222, -1482, -1482,
   -1482, -1482,  1270,  1272,  1274, -1482,  1280,  1293,  1290, -1482,
     173,  1808,  1300, -1482,   173,  1808,  1519,   418,  1544, 13245,
   11273,  1340, 12883, -1482, -1482, 11273,   173,   549,   414,  1341,
    1558,  1342,     8, -1482,  1590, -1482, -1482,   682, 11273, 11273,
   -1482, -1482,   294, -1482, -1482,    51, 11554,   796,  1808,   613,
   12637, 11273,     5,   796,   796,   795, 11273, -1482,    18, -1482,
   -1482, 11273,   802, 12883, -1482, 11273,     5, 11273, 11273, 11273,
    1375,     5,  1385,     5,  1397,     5,     5,   805,   796,  1398,
    1405,     5,     5, 12552, 11273, 11273,   818, 12883,   848, 12883,
     796,   858, 11273,   885,   796,   887,   891, 11273, 12883,   893,
     902,   903, 11273,   904, 11273,   906, 12883,   913, 11273, 12883,
   12883,   916,   917,   919,   927,   928, 11273,   929, 11273,   930,
   11273,   938, 11273, 11273, 11273,   796,   939,   940,   796,   960,
   11273,   796,   961,   963,   967, 11273,   796,   970,   971,   796,
     973,   974,   977, 11273,   980,   796,   981, 12883,  1006,  1008,
    1010, 11273,  1017, 12883,  1018, 12883,  1043, 12883,  1060, 12883,
    1061, 12883,   796,  1062,  1063,  1071,   796, 11273, 12883,  1808,
    1808,  1808,  1808,  1406,  1418,  1419,  1420, -1482,  1133,  -103,
   11273, 11273, 11273, 11273, -1482,  1421,     5,     5,  1808,   796,
     722,  1429,  1444, 12685, 13387,  1183, 13611, 13688, 13806,  1451,
     103,  1443,  1455,  1087,  1458,  1464,  1459,  1478,  1499,  1501,
       5, 13828,  1090,    12,   796,   796,   796,   796,   796,  1097,
     796,   796,   796,  1099,   796,   796,  1103,   796,   796,  1107,
     796, 12883,   796,  1109,   796,  1116, 12883,    23, 12883, 12883,
   12883, 12883,  1138,   796,  1217,  1237,  1264,  1509,  1599,   621,
    1744,   747,  2005,  2021,  1521,  2036,  2057,  2084,  2114,  2131,
    2570,  2588, 13862, -1482,  2607,    45,  1139,  1142,  1145,    67,
   13883, 13898,   374,   762, -1482,  2647,  2666,    91,  2861,  -100,
    2876,   202,   281, -1482,   282, -1482,   318, -1482,   327, -1482,
     352,   355,   372,   388, 13913,  1146,  1149,  1153,   402,   516,
     532,   400,  1522,   -46,  1524,  1548,   536,  3036,   585,    68,
    1156,  1160,  1163, -1482, -1482,  1167,  -224,  1169,  -190,  1173,
     591,   602, -1482, -1482,   796,   796,   796,   796,   796,   796,
     796, -1482, 11273, 11273,   693,   739,   605,   268,   -27,   227,
     -36, -1482,   -52,   -52,  1124,  1124, -1482, -1482, -1482, 13245,
   -1482, -1482, 11273, -1482, -1482, -1482, -1482,   269,   269, -1482,
   -1482,   530, -1482, -1482,   542, 11273, -1482,  1623, -1482, -1482,
   -1482, -1482, -1482, -1482, -1482, -1482,   689, 13928, 11273,    76,
    3104, 13002, -1482, -1482, 11273, 11273,  1550, 12883, -1482, -1482,
   11273, -1482,   750,  1551,  1563,  1572,  1575, 13943, 13958,  1570,
    1581, -1482, -1482, -1482, 11273,  1691,  1727, -1482,  1175, 13973,
   11273, 12883,  1808, -1482, -1482, 12883,  1181, -1482, 11273, 14001,
   14023,  1584, 12883, 11273, 11273, 11273, 12883, 11273, 11273, 11273,
   11273, 11273, 11273, 11273, 11273,  1585,  1586, 11273,  1187, 11273,
    1188, 11273,  1587, 12883, 12883, 12883,  1588,  1191, 12883, 12883,
   11273,  1589, 12883,  1591, 11273,  1197, 12883, 14038,   796,   796,
   12883, 12883, 11273, 12883, 11273,  1592, 12883,  1597, 12883,  1598,
   11273,  1600,  1614,  1616, 11273, 11273, 11273,  1617, 12883, 11273,
   11273,  1626, 12883, 11273, 12883, 12883, 11273,  1627, 12883, 11273,
    1198, 11273, 12883, 11273,  1628, 12883,  1199, 11273,  1200, 11273,
    1210, 12883,  1220, 12883,  1221, 12883, 12883, 12883, 14057,  1222,
   -1482, 11273, 11273, 11273, -1482, -1482,   173,  1808,   173,  1808,
   14168, 14196, 13245, 11273, 11273, 11273, -1482, -1482, -1482, -1482,
   -1482, 11273, 11273, -1482, 11273, 11273, 11273, -1482, 12883, -1482,
   12764, -1482, 12883,  1633,  1636, -1482, -1482, 11273, 11273, 11273,
   11273, 12883, -1482, 12883, 11273, 11273, 11273,   796, 11273, 12883,
     617, -1482,  1230,  1241,  1242,  1243, 11273, -1482, -1482, -1482,
   -1482, -1482, 11273, -1482, -1482, 11273, -1482, -1482, -1482, -1482,
   -1482, -1482, -1482, -1482, -1482, -1482, -1482, 11273, -1482, -1482,
   11273, 11273, 11273, -1482, 11273, 11273, -1482, 12883, -1482, -1482,
   -1482, -1482, -1482, 11273, -1482, -1482, -1482, -1482, -1482, -1482,
   -1482, -1482, -1482, -1482, -1482, 12883, 12883, 12883, 12883, -1482,
   -1482, -1482, -1482, -1482, 12883, -1482, -1482, -1482, -1482, -1482,
   -1482, 11273, -1482, 11273, 11273, 11273,  1836, 12883, -1482,  1836,
   12883, -1482, 12883, -1482, -1482,  1792,  2260, 11273,    58,  1808,
   -1482,  1629, -1482,  1630,  1637,  1638, -1482,  1640,  1641, -1482,
   -1482, -1482,   760, 13245, -1482, -1482, -1482, 11273, 14233, 12883,
    1801, -1482, 12883,   796,   173,   549, 14252, 11273,   196,   750,
     750,  3119,  1643,  1645, -1482,  1647, -1482, -1482, -1482, -1482,
   11273, 11273, -1482, -1482, 14267,  4355,  4355, 12883, 12883,  1648,
    1249,   796, 12883, -1482, 11273, 11273, 12883,   796,  1652, 14282,
       5,  1250,  1654,     5,   173, 14297, 14312, 14327,     5,  1655,
   14342, 12883, 12883,  1808, 12883,  1808, 12883,   173,  1808, 12883,
    1251,   796,   796, 12883, 12883,  1253,  1262,   127,  1808, 12883,
    1277, 12883,  1808, 12883,  1285, 12883,  1287,  1288,  1808,   796,
    1808, 12883,  1289, 12883,  1296, 12883,  1808, 12883, 12883, 12883,
     173, 14363,   173,  1808,  1808, 12883,   796,  1808,  1808, 12883,
    1297,   647,  1808,   796,   796,  1808, 12883,  1298, 14391, 11273,
    1808,  1306,  1808, 12883,   796, 12883, 14406, 12883,   814, 14428,
   12883,  1308, 12883,  1309, 12883,   796,  1315,  1316, 12883, 12883,
    1657,  3147,  3231,   881, 12883, 12883, -1482,  1808,     5, -1482,
    1659,  3316,  3383,  3481,  3511,  3537,   618,  1660,   349,   796,
   -1482, -1482,  3617,  3915,  1662,    94,  1332,   796,  1808,  1808,
    1808, 14537,   796, -1482, 12883, 12883, 12883, 12883,  1808,  3930,
    3948,  3969,  3990,  4650,   957,  4910,  5170,   373,  6705,   648,
    1339,   401,   446,   649,  6960, 14558, 14601,  7215,  -180,   668,
    -153,   674,   676,    61, -1482, -1482, -1482,   269,   269, -1482,
   -1482, -1482, -1482, 11273,  1807,  1878,  1882,  7725, 11273,   677,
    1666,   447, -1482, 11273, 14623, 12883,  1863, -1482, -1482, -1482,
   -1482, -1482, -1482,  1667,  1668,  1808,  1808, 12883, -1482, -1482,
     796,   796, 12883, 12883,  1357, 14638,  1808,  1358, 12883, 12883,
   11273, 12883, 12883, 11273, 11273, 11273, 11273, 11273, 11273, 12883,
     796,  1359,  1365,  1368,  1369, 11273,  1371,  1372, 12883, 11273,
   11273,  1378, 12883,  1382,  1384, 11273,   796, 11273, 11273,  1386,
   12883,  1388, 11273,  1394,  1400,  1401,  1404, 12883,  1422,  1432,
   11273, 12883,  1433, 11273, 11273,  1808, 11273,  1435,  1439, 11273,
     796, 12883, 12883,  1442, 11273,  1445, 12883,  1452, 12883, 12883,
     796,   796, -1482,  1856,  1857, 11273,  1858,  1454,   796, 11273,
     837, -1482, -1482, -1482, -1482, -1482, -1482, -1482, 12883, -1482,
   -1482, -1482, -1482, 11273, 12883, 11273,   713,   714,   796,   796,
   -1482, -1482, -1482, -1482, -1482, 11273, -1482, -1482, -1482, 12883,
   -1482, -1482, -1482, 12883, 11273, -1482, 11273, -1482, -1482, -1482,
   12883, 11273, -1482, 12883, -1482, -1482, 12883, -1482, -1482, -1482,
   11273, -1482, -1482, -1482, -1482, -1482,  1886,   783,  7980,  1880,
   11273, 12883,  8235, 11273,   715,  1680,  1590,   750,  1681,  1683,
     750, -1482, -1482,   796,  1460,   796, 12883, 12883, 12883,   796,
     796,  1686,   796,   796,     5, 14653, 14668, 14683,     5, 14698,
    1473, 12883, 11273, 11273, 12883, 14713, 11273, 12883,   796, 14732,
    1808, 12883,  1474, 12883, 11273, 14753, 14768,   173,  1808, 12883,
     796, 12883, 14796, 11273, 11273, 12883, 12883,   796, 11273, 12883,
     825,  1808,   796, 11273, 14908, 14927, 14963, 11273, 12883, 14991,
    1486,   796, 12883,   889, 15006, 12883,  1494, 12883,  1496,   796,
   12883, 12883,  8490, 12883, 11273, -1482,  1687,  1688,     0, -1482,
     716, 15021,   796,  1808, -1482, -1482,  8745,   717,   743,  9000,
    9255,   744,  9510,   781,   784,   456, 13245, 13693, 11273,  1900,
   -1482,  1696, -1482,  1697, 15036,   785,   794,  9765,  1894, 11273,
     750, -1482, -1482, -1482, -1482, 12883,   796,   796,   796, 12883,
   11273, 11273, 12883, 11273, 11273, 11273, 12883,  1497, 15051, 15066,
    1498, 11273, 15081,  1500, 11273,  1507, 11273,  1513, 15103, 11273,
   11273,  1514,  1515, 11273, 15122, 15137,   796,   796, 15158,  1517,
   11273, 15276, 11273, 11273, 11273, 15298,  1527, 11273, 12883,   796,
   12883, 12883,  1538, 11273,  1542, 12883,   796,   796,  1884,   796,
    1808,  1698,  1700,   837, -1482, -1482, 11273, -1482, -1482, -1482,
   -1482, -1482, -1482, -1482, -1482, -1482, 11273, -1482,  1882,  1925,
     686, 13245, -1482, 12883, 11273, 11273, -1482, -1482,  1703,  1590,
   -1482,  1704,  1590, 15332, -1482,   796,   796,  1706, 15353,   796,
   15368,  1707, 15383,  1545, 12883, 12883, 12883, 12883, 15398, 12883,
   12883, 15413, 11273,  1808, 12883, 11273,  1808, 15428, 12883, 11273,
    1808, 11273, 12883, 12883, 12883,  1808, 12883, 15443, 15471, 15493,
   12883, 12883,  1808,   796,  1546,   796, 12883,   915, 15508, 12883,
     796, 12883, -1482, -1482, -1482, 13245, 10020,  1808, 13245, -1482,
   -1482,  1882,  1045,   469, 15527, 10275,  1590, 12883,   750,  1590,
   11273,   750, 11273, 12883, 12883, 11273, 12883, 12883, 12883,   796,
     796,   796,  1549, 11273,   796,   796, 11273, 15638,  1567, 15666,
   11273,   796, 15703, 15722,   796,   796,   796,   796, 11273, 12883,
   11273,  1568,   796, 12883,   796, 12883, 12883,  1569,   796,    31,
   -1482,  1882, 13245, -1482, -1482, -1482, -1482, -1482, -1482, -1482,
   12883, -1482, 11273, -1482,   750,   517, -1482,   750, 15737, -1482,
   10530,   796,   796, 15752,   796,   796,   796, 12883,  1808,  1808,
   11273, 12883, 11273,  1808, 12883, 12883,  1808,   796, 15767, 12883,
     796,  1571,   796, 12883, -1482, -1482, -1482,  1111,  1882,   786,
   10785, -1482, 12883, -1482, -1482, 11273, -1482, 12883,   796, 15782,
     796, 15797,   796,   796, 11273,   796, 12883,   796, -1482, -1482,
   -1482, -1482, -1482, -1482,  1964,  1886, -1482, -1482,   790,  1590,
   11040,  1590,   796, 12883, 12883, 15812,   796, -1482, -1482, -1482,
   -1482,   750, -1482,   750,  1579,   796, 12883,  1590, -1482,  1590,
   -1482, 12883,   796,   750,   750,   796, -1482, -1482
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   242,     0,     0,     0,   493,     0,     0,     0,   236,
     516,   551,   556,    18,     0,     0,     0,     0,    31,    33,
     494,     0,   478,   478,     0,   495,    25,    27,   531,   543,
       0,   640,    55,    67,     0,   233,   234,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   243,
     244,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   225,
       0,     0,     0,     0,     0,     2,     9,    17,     8,     0,
      12,    46,    48,    14,    29,    30,    28,     0,    20,    21,
      24,    23,    22,    35,    36,   466,   351,   264,   467,   468,
     469,   267,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   314,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   278,
       0,     0,     0,     0,     0,     0,     0,   411,   414,   417,
     420,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   295,   297,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,     0,   365,   345,   350,   266,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,   478,     0,   478,     0,     0,    16,   471,
     470,    37,    38,    45,     0,     0,     0,     0,    19,    50,
     480,    51,    49,   496,    26,     0,    16,   575,     0,   644,
       0,     0,   604,   636,    69,    68,     0,     0,    70,   235,
      60,     0,    62,     0,   596,   598,    63,   594,   600,     0,
       0,   601,   463,    64,    66,     0,   220,     0,     0,   655,
       0,    92,   222,    86,    47,     0,     0,     0,     0,     0,
       0,    74,     0,    57,    79,     0,     0,    94,    93,     0,
       0,   245,   246,   223,    13,    15,   237,     0,     0,    85,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,     0,     7,     0,     0,     0,     0,     0,     0,
     485,   478,   478,     0,     0,   335,     0,     0,     0,     0,
       0,     0,     0,   441,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   313,     0,     0,     0,     0,     0,     0,     0,
     446,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   478,   478,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   357,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,   333,   331,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
       6,   329,     0,   247,     0,     0,   552,     9,    39,    40,
      41,    43,   499,   500,    32,   497,   505,   506,    34,   503,
     483,   484,   479,   481,   536,   535,     0,     9,     0,    16,
       0,     0,     0,   641,   642,     0,   607,   609,    52,     0,
       0,     0,     0,    56,   638,   478,   478,     0,     0,     0,
     478,   478,     0,   465,   464,     0,     0,   221,   654,     0,
       0,     0,     0,    96,    73,     0,     0,    78,   636,   254,
     253,     0,     0,     0,    75,     0,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,     0,     0,     0,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,     0,     0,   174,     0,
       0,   179,     0,     0,     0,     0,   188,     0,     0,   191,
       0,     0,     0,     0,     0,   198,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   213,     0,     0,     0,   218,     0,     0,   117,
     116,   118,   119,   262,     0,     0,     0,   226,     0,     0,
       0,     0,     0,     0,    10,     0,     0,     0,   330,   252,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   300,   304,   301,   305,   459,     0,
     458,   448,   447,     0,   450,   449,     0,   452,   451,     0,
     455,     0,   453,     0,   310,     0,     0,     0,     0,     0,
       0,     0,     0,   445,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   391,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   279,     0,     0,     0,     0,     0,
       0,     0,     0,   412,     0,   415,     0,   418,     0,   421,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   296,   298,     0,     0,     0,     0,     0,
       0,     0,   269,   366,   360,   362,   364,   361,   363,   358,
     359,   268,     0,     0,   338,   340,   342,   339,   341,   336,
     337,   356,   353,   352,   354,   355,   476,   477,   517,    16,
     563,   561,     0,   562,   558,   560,   557,     0,     0,   478,
     478,     0,   478,   478,     0,     0,   533,   537,   550,   548,
     549,   546,   545,   547,   544,   565,     9,     0,     0,     0,
       0,     0,   605,    53,    54,     0,     0,     0,   612,   614,
       0,   639,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   595,   602,   603,     0,     0,     0,   257,   256,   260,
       0,     0,   369,    58,    76,     0,    89,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   153,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     478,     0,     0,     0,   227,   228,   229,   230,   231,   232,
       0,     0,    16,     0,     0,     0,   491,   492,   486,   433,
     325,     0,     0,   424,     0,     0,     0,   434,     0,   435,
       0,   428,     0,     0,     0,   346,   347,     0,     0,     0,
       0,     0,   462,     0,     0,     0,     0,   454,     0,     0,
       0,   311,     0,     0,     0,     0,     0,   370,   371,   372,
     373,   374,     0,   375,   377,     0,   378,   380,   381,   343,
     387,   388,   382,   384,   385,   386,   383,     0,   390,   395,
       0,     0,     0,   394,     0,     0,   277,     0,   274,   280,
     281,   396,   323,     0,   397,   324,   282,   283,   410,   413,
     416,   419,   286,   284,   285,     0,     0,     0,     0,   289,
     403,   290,   409,   408,     0,   299,   404,   291,   405,   292,
     407,     0,   293,     0,     0,     0,     0,     0,   318,     0,
       0,   320,     0,   440,   328,   334,   332,     0,     9,   559,
     656,    42,   658,    44,     0,     0,   498,     0,     0,   504,
     482,   534,   540,    16,   577,   578,   576,     0,     0,     0,
     645,   643,     0,   610,   608,   609,     0,     0,     0,     0,
       0,     0,   590,   592,   637,   587,   472,   474,   478,   478,
       0,     0,   597,   599,    71,     0,     0,     0,     0,     0,
       0,   126,     0,    77,     0,     0,     0,   102,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,   122,     0,   124,     0,   129,   130,     0,
       0,   134,   133,     0,     0,     0,     0,     0,   142,     0,
       0,     0,   149,     0,     0,     0,     0,     0,   156,   155,
     157,     0,     0,     0,     0,     0,   164,     0,     0,     0,
     168,     0,   170,   171,   172,     0,   176,   178,   177,     0,
     181,   184,   185,   189,   190,   187,     0,     0,     0,     0,
     195,     0,   197,     0,   201,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    87,     0,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   442,
     367,   368,     0,     0,     0,     0,   460,   457,   306,   307,
     308,     0,   456,   312,     0,     0,     0,     0,   444,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   555,   554,   553,     0,     0,   501,
     502,   507,   508,     0,     0,     0,   566,     0,     0,     0,
       0,     0,   606,     0,     0,     0,   626,   613,   615,   616,
     478,   478,   588,     0,     0,    59,    61,     0,   258,   259,
     255,   261,     0,     0,    90,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   196,     0,     0,     0,     0,
     202,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     216,   115,   263,     0,     0,     0,     0,   240,   241,     0,
     509,   422,   423,   425,   426,   427,   436,   437,     0,   438,
     348,   349,   321,     0,     0,     0,     0,     0,   303,   302,
     376,   379,   389,   270,   271,     0,   273,   392,   393,     0,
     275,   398,   287,     0,     0,   399,     0,   401,   316,   294,
       0,     0,   327,     0,   430,   317,     0,   432,   319,   344,
       0,   657,   659,   538,   541,   532,   581,   647,     0,   646,
       0,     0,     0,     0,     0,     0,   638,     0,     0,     0,
       0,   473,   475,    72,     0,    97,     0,     0,     0,   103,
     106,     0,   101,   104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   139,     0,
     140,     0,     0,     0,     0,   144,     0,   150,   151,     0,
     159,     0,   161,     0,     0,     0,     0,   169,     0,     0,
       0,   183,   186,     0,     0,     0,     0,     0,     0,     0,
       0,   205,     0,     0,     0,     0,     0,     0,     0,   217,
       0,     0,     0,     0,     0,    88,   512,   513,     0,   510,
       0,     0,   461,   309,   443,   315,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,    16,   242,     0,   579,
     651,     0,   648,     0,     0,     0,   618,     0,   628,     0,
       0,   617,   591,   593,   589,     0,   125,    82,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   165,   166,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
       0,     0,     0,     0,     0,     0,   250,   251,     0,   249,
     239,     0,     0,     0,   487,   439,     0,   272,   276,   288,
     400,   402,   406,   326,   429,   431,     0,   518,   539,     9,
     585,    16,   567,     0,     0,     0,   611,   630,     0,   638,
     620,     0,   638,     0,   627,    95,   110,     0,     0,   107,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   147,     0,     0,   145,     0,     0,     0,
     162,     0,     0,     0,     0,   182,     0,     0,     0,     0,
       0,     0,   203,   206,     0,   208,     0,     0,     0,     0,
     214,     0,   514,   515,   511,    16,     0,   528,    16,   586,
     582,   580,     0,     0,     0,     0,   638,     0,     0,   638,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
     121,   123,     0,     0,   132,   127,     0,     0,     0,     0,
       0,   154,     0,     0,   163,   167,   175,   180,     0,     0,
       0,     0,   200,     0,   207,     0,     0,     0,   248,     9,
     322,   519,    16,   574,   571,   572,   573,   569,   570,   568,
       0,   652,     0,   649,     0,     0,   619,     0,     0,   629,
       0,   109,   100,     0,   111,   105,   219,     0,   136,   141,
       0,     0,     0,   152,     0,     0,   199,   194,     0,     0,
     209,     0,   212,     0,   490,   489,   488,     0,   583,     0,
       0,   631,     0,   632,   621,     0,   622,     0,   128,     0,
     146,     0,   158,   160,     0,   192,     0,   210,   522,   524,
     525,   526,   521,   523,   529,   581,   653,   650,     0,   638,
       0,   638,   108,     0,     0,     0,   211,   530,   520,   584,
     634,     0,   624,     0,   137,   148,     0,   638,   633,   638,
     623,     0,   193,     0,     0,   138,   635,   625
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1482, -1482, -1482,  -249, -1482, -1482,  1965,   819, -1482, -1482,
   -1482, -1482, -1482, -1482, -1482,  1917,   -64, -1482, -1482,  -391,
      -3, -1482,  1919,  1694, -1482, -1482,  1488,  -476,  3081, -1482,
    1302,   -30,   -14, -1482,     2,     4,   131, -1482, -1482,   983,
    1970, -1482, -1482, -1482, -1482, -1482, -1482, -1482,   990, -1482,
     993, -1482,   132, -1482, -1482, -1482, -1482, -1482, -1482, -1482,
   -1482, -1482, -1482, -1482,   481, -1482, -1482, -1482, -1482, -1482,
   -1482, -1482, -1482, -1482, -1482, -1482, -1482, -1482, -1482, -1482,
   -1482, -1482, -1482, -1482, -1482, -1482, -1482, -1482, -1482,   -77,
   -1482, -1482, -1482, -1159, -1482, -1482, -1482,  1317, -1482, -1482,
     687,  1303, -1482, -1482, -1482, -1482, -1482, -1482, -1482, -1482,
   -1482, -1482, -1482, -1482, -1482, -1481, -1482,   -20, -1482, -1482
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,   105,   106,   464,  1152,   107,   108,   276,   277,
     987,   988,   293,   688,   109,   110,   691,   111,   112,   804,
     243,   244,   113,   330,   963,   962,   836,   837,   331,   246,
     311,   247,   271,   298,   248,   249,   279,   280,   642,   643,
     116,   820,  1440,  1935,  2036,  1158,   117,   634,   635,   638,
     639,  1758,  1759,   118,   266,  1277,  1938,  2037,  2064,  1867,
    2078,   119,   285,   997,   646,  1292,  1776,  1505,  1777,   120,
     286,  1004,   121,   267,   979,  1496,   122,   268,   986,   123,
     648,  1293,  1666,  1942,  1999,   124,   649,  1296,  1872,  1779,
    1992,  2065,  1940,  1314,  1680,  1315,   306,   307,   313,   658,
    1012,   663,  1309,  1310,  1677,  1879,  1949,  2071,  2089,  1676,
    1882,  1946,  2069,  2087,   664,  1022,   292,   320,  1281,  1283
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     256,   272,   273,   114,   618,   115,   258,   689,   259,   839,
     312,   653,  1018,   449,   654,  1019,   392,   689,   278,   627,
     262,   282,   264,   324,   325,   612,   288,   314,   289,   290,
     294,   679,     7,     8,   300,   302,  1267,   647,  1268,   318,
     125,   612,     7,     8,   128,   129,   130,   308,   610,   611,
     612,   346,   347,   348,   125,   258,  2034,   259,   128,   129,
     130,  1032,   490,   805,   806,   492,   393,   389,   390,   391,
    1270,   443,  1271,  1660,  1494,  2035,   659,   514,   660,   661,
    1653,   459,  1654,   437,   439,   441,  -564,   444,   450,   448,
     594,   595,   596,   597,   598,   599,   600,   261,   458,   460,
     461,   462,  1495,   603,   604,   491,   689,  1656,   493,  1657,
     605,   606,   607,   608,   609,   610,   611,   612,   497,   498,
     515,    20,   601,   283,   603,   604,    25,   738,    53,   500,
     501,   605,   606,   607,   608,   609,   610,   611,   612,   503,
     504,   284,   594,   595,   596,   597,   598,   599,   600,   601,
    1517,  1518,   601,   349,   281,   601,   952,   603,   604,  1145,
    1233,   499,  1234,   516,   605,   606,   607,   608,   609,   610,
     611,   612,   502,   594,   595,   596,   597,   598,   599,   600,
     337,   342,   505,   506,   507,   594,   595,   596,   597,   598,
     599,   600,   296,   297,   946,  1790,   948,   594,   595,   596,
     597,   598,   599,   600,   615,   616,   263,   442,   265,   601,
     338,   339,   340,   453,  1254,   601,  1255,   341,   613,   614,
     615,   616,   451,    96,    97,    98,   508,   613,   614,   615,
     616,   291,   601,    96,    97,    98,   980,   739,   981,   592,
     982,   465,   466,   594,   595,   596,   597,   598,   599,   600,
     601,   601,   617,   467,   601,   690,   740,   326,   327,   787,
    1853,   623,  1854,   983,   328,   690,   984,   601,   655,  1020,
     114,   985,   115,   269,  1182,   601,   270,   640,   601,   673,
     674,   662,   644,   697,   698,  1191,   699,   329,   114,   656,
     115,   309,   310,   452,   613,   614,   615,   616,   304,   305,
     601,   714,   715,   611,   612,   309,   310,  1219,   463,   722,
     482,   483,   468,   677,   727,   613,   614,   615,   616,   732,
     454,   734,   601,   601,   683,   684,   685,   601,  1261,  1223,
    1262,   601,   692,   746,   952,   748,  1299,   750,  1300,   752,
     753,   754,   609,   610,   611,   612,   601,   760,   613,   614,
     615,   616,   765,  1231,   690,   707,   708,   601,   601,   455,
     773,   456,   789,  1168,   716,  1169,   718,   781,   720,   721,
     601,   723,   724,   725,   726,   810,   469,   729,   730,   731,
     457,   733,   601,   735,   470,   737,   263,  1560,   488,   741,
     742,   743,   744,   745,   622,   747,   624,   749,  1948,   751,
    1006,  1951,   265,   755,   756,   757,   758,   759,   601,   761,
     762,   763,   764,   791,   766,   767,   768,   769,   770,   771,
     772,   471,   774,   775,   776,   778,   779,   780,   601,   782,
     472,   784,   998,   786,   999,   788,  1000,   790,   473,   792,
     793,   794,   795,   796,   594,   595,   596,   597,   598,   599,
     600,   601,   628,   629,   809,   474,  1515,   601,  1516,  1001,
     831,   832,  1002,   494,  1236,  2004,   819,  1003,  2007,  1866,
     594,   595,   596,   597,   598,   599,   600,   830,   476,   833,
     477,   613,   614,   615,   616,   842,   843,   844,   845,   846,
     847,   848,   849,   850,   851,   852,   853,   854,   855,   856,
     857,   858,   859,   860,   862,   863,   864,   865,   125,   478,
     867,   884,   128,   129,   130,   872,   873,   479,  1791,   603,
     604,  1794,   613,   614,   615,   616,   605,   606,   607,   608,
     609,   610,   611,   612,   632,   633,   601,   601,   895,   896,
     897,   898,   899,  1237,  1238,   902,   636,   637,   907,   480,
     909,   932,   911,   912,   914,   916,   918,   920,   921,   922,
     923,   481,   925,   926,   927,   928,   929,   930,   931,   933,
     834,   835,   936,   601,   938,   939,   940,   941,   942,   601,
    1239,   945,   601,   947,   798,   949,   950,   951,  2081,  1240,
    2083,   954,   955,   956,   957,   958,   959,   960,   961,   484,
    1011,   485,   821,   822,   601,   486,  2093,   601,  2094,  1618,
     601,  1619,   603,   604,  1241,   630,   631,  1242,  1040,   605,
     606,   607,   608,   609,   610,   611,   612,   601,   601,   601,
     487,  1884,  1048,  1639,  1243,  1640,  1226,  1053,   489,  1055,
     495,  1057,  1058,   601,   511,   312,   496,  1062,  1063,  1009,
    1244,   114,   509,   115,   512,   601,   601,   601,   603,   604,
     510,  1644,  1252,  1645,  1249,   605,   606,   607,   608,   609,
     610,   611,   612,  1013,  1014,   518,   606,  1038,   608,   609,
     610,   611,   612,   601,   603,   604,  1025,  1026,   812,   520,
    1046,   605,   606,   607,   608,   609,   610,   611,   612,  1035,
    1036,   601,   601,   513,   934,   935,  1646,  1671,  1647,   952,
     613,   614,   615,   616,  1068,   602,  1070,   594,   595,   596,
     597,   598,   599,   600,   601,  1077,  1156,  1157,   519,  2000,
    1278,  2001,  1939,  1085,   603,   604,  1088,  1089,  1294,  1295,
     521,   605,   606,   607,   608,   609,   610,   611,   612,   603,
     604,   522,  1154,  1155,  1312,  1313,   605,   606,   607,   608,
     609,   610,   611,   612,   606,   607,   608,   609,   610,   611,
     612,   601,   601,   523,  1120,   524,  1179,  2042,  1250,  2043,
    1126,   525,  1128,   526,  1130,   527,  1132,   601,  1134,  2006,
    1488,   601,  2009,  1490,  1251,  1139,  1023,  1024,  1258,  1503,
    1504,  1029,  1030,   613,   614,   615,   616,  1146,  1148,   499,
     603,   604,   608,   609,   610,   611,   612,   605,   606,   607,
     608,   609,   610,   611,   612,   603,   604,     1,     2,     3,
       4,     5,   605,   606,   607,   608,   609,   610,   611,   612,
     601,  1756,  1757,  1780,  1781,  2041,   601,  1260,  2044,   613,
     614,   615,   616,  1273,  1877,  1878,   502,   601,  1187,   613,
     614,   615,   616,  1190,  1274,  1192,  1193,  1194,  1195,   601,
     528,   529,   601,   601,   813,   613,   614,   615,   616,  1463,
    1616,  1202,   505,  1203,   594,   595,   596,   597,   598,   599,
     600,   530,   531,   532,   533,   594,   595,   596,   597,   598,
     599,   600,   601,   601,   601,   603,   604,  1581,   508,   515,
    1642,  1648,   605,   606,   607,   608,   609,   610,   611,   612,
     534,   535,  2088,   601,  2090,   613,   614,   615,   616,   601,
    1655,   601,   601,   536,  2096,  2097,  1658,   625,  1659,  1669,
     613,   614,   615,   616,   603,   604,   537,   613,   614,   615,
     616,   605,   606,   607,   608,   609,   610,   611,   612,   594,
     595,   596,   597,   598,   599,   600,   538,   539,   601,   601,
     601,   601,   601,  1280,  1282,  1764,  1765,  1788,  1855,  1858,
     540,   114,   541,   115,   542,   594,   595,   596,   597,   598,
     599,   600,   640,   613,   614,   615,   616,   543,   601,   601,
     619,   613,   614,   615,   616,  1859,  1862,  1205,  1303,  1206,
     601,  1304,   544,   545,  1308,   870,   613,   614,   615,   616,
     603,   604,  1227,   620,  1228,   546,   547,   605,   606,   607,
     608,   609,   610,   611,   612,   548,   601,   549,  1330,   601,
     601,   601,  1331,  1864,  1506,   601,  1865,  1876,  2066,  1337,
     601,   601,  2080,  1341,   550,  1041,  1344,   601,   551,  1993,
     601,  1994,  1045,  1995,   552,  1059,   814,   553,  1357,   601,
    1360,  1361,  1362,   601,  1591,  1365,  1366,  1367,  1067,  1370,
     601,   554,   555,  1374,   556,  1830,  1996,  1376,  1377,  1997,
    1379,   557,   558,  1382,  1998,  1384,   613,   614,   615,   616,
     559,  1390,  1392,   601,   953,  1396,   560,   561,  1069,  1400,
    1401,  1403,  1404,   601,   562,  1407,   563,   564,  1071,  1411,
    1284,  1285,  1414,  1287,  1288,  2058,  1418,  2059,  1421,  2060,
    1423,   565,  1425,  1426,  1427,   613,   614,   615,   616,   566,
     601,  1605,   601,  1606,   601,  1073,   601,  1074,   601,  1840,
     651,  1075,  2061,  1078,   114,  2062,   115,   601,   601,   601,
    2063,   601,  1079,  1080,  1082,  1446,  1084,  1448,   601,  1449,
     601,   601,   601,  1086,   601,  1985,  1090,  1091,  1456,  1092,
    1457,   567,   601,   601,   601,   601,  1462,  1093,  1094,  1096,
    1098,   803,   568,   601,   601,   601,   603,   604,  1100,  1104,
    1105,   612,   569,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   601,   601,  1635,   601,  1636,
    1106,  1108,   601,  1109,  1477,   601,   601,  1110,   601,   601,
    1112,  1113,   601,  1114,  1115,   601,   601,  1116,   943,   570,
    1118,  1119,  1479,  1480,  1481,  1482,   603,   604,   571,   572,
     573,  1483,   574,   605,   606,   607,   608,   609,   610,   611,
     612,   601,   575,   601,  1489,   601,  1121,  1491,  1122,  1492,
    1123,  1430,   601,   601,   576,   577,  1540,  1125,  1127,  1543,
     603,   604,   578,   579,  1547,   580,   581,   605,   606,   607,
     608,   609,   610,   611,   612,   114,  1509,   115,   601,  1511,
     603,   604,   582,  1129,   667,  1528,  1529,   605,   606,   607,
     608,   609,   610,   611,   612,   601,   601,   601,   601,   583,
    1131,  1133,  1135,  1136,  1530,  1531,   601,   603,   604,  1534,
     584,  1137,   672,  1537,   605,   606,   607,   608,   609,   610,
     611,   612,   601,   585,   586,   601,   587,  1172,  1550,  1551,
    1181,  1552,   601,  1553,   601,   588,  1554,  1183,   601,  1184,
    1556,  1557,   601,  1185,   601,   589,  1561,  1186,  1563,  1188,
    1564,   601,  1566,   590,  1609,   650,  1189,   675,  1569,   652,
    1571,   665,  1573,   666,  1574,  1575,  1576,   613,   614,   615,
     616,  1623,  1578,   601,   601,  1144,  1579,   601,  1196,  1220,
     601,   601,  1221,  1582,   601,  1222,  1246,   680,   601,  1247,
    1587,   601,  1588,  1248,  1590,   601,  1263,  1593,   601,  1595,
    1264,  1597,   601,  1265,   601,  1600,  1601,  1266,   601,  1269,
     601,  1607,  1608,  1272,   681,  1327,   601,   613,   614,   615,
     616,  1332,   601,   601,   693,  1163,   601,  1354,  1356,  1523,
    1524,  1364,   601,   601,   601,   601,   670,  1373,  1409,  1415,
    1417,  1626,  1627,  1628,  1629,   601,   671,   717,   719,   728,
    1420,   613,   614,   615,   616,   601,   601,   601,   736,  1197,
    1422,  1424,  1429,  1661,  1662,   601,   783,   785,   811,   871,
    1464,   613,   614,   615,   616,   866,   601,   601,   601,  1198,
     644,  1465,  1466,  1467,   601,   601,   601,   868,   601,  1533,
    1541,  1555,  1674,  1558,   944,   869,   978,   601,   613,   614,
     615,   616,  1559,   976,  1683,   977,  1199,  1868,  1869,  1684,
    1685,   989,   601,   990,   991,  1689,  1690,  1562,  1692,  1693,
     601,   992,   601,   601,   601,  1565,  1700,  1567,  1568,  1570,
     994,   601,   601,   601,   993,  1708,  1572,  1580,  1583,  1712,
     995,   601,   996,   601,   601,  1717,  1586,  1720,  1594,  1596,
     601,   601,   603,   604,  1727,  1598,  1599,  1730,  1732,   605,
     606,   607,   608,   609,   610,   611,   612,   601,  1740,  1741,
    1005,  1743,  1624,  1746,   601,  1748,  1749,   603,   604,  1643,
    1021,  1008,  1015,  1017,   605,   606,   607,   608,   609,   610,
     611,   612,   601,   601,   601,  1760,  1016,  1686,  1688,  1701,
     601,  1762,  1941,   601,   601,  1702,   601,   601,  1703,  1704,
    1800,  1706,  1707,   601,  1804,  1052,  1767,   601,  1711,   601,
    1768,   601,  1713,   601,  1714,  1054,  1719,  1771,  1721,   601,
    1773,  1678,  1679,  1774,  1723,   601,   601,  1056,  1060,   601,
    1724,  1725,   603,   604,  1726,  1061,  1291,  1140,  1785,   605,
     606,   607,   608,   609,   610,   611,   612,   601,  1141,  1142,
    1143,  1153,  1728,  1796,  1797,  1798,  1989,   601,   601,  1991,
     601,  1159,  1729,  1733,   601,  1737,   245,   601,  1807,  1738,
     601,  1810,  1742,  1170,  1813,  1745,  1160,   601,  1815,   601,
    1817,   275,  1747,  1167,  1754,   601,  1821,  1171,  1822,  1173,
    1795,  1175,  1826,  1827,   287,  1174,  1829,   295,   601,   601,
     299,   301,   303,  1806,  1816,  1836,   319,   319,   319,  1839,
    1176,   601,  1842,  2038,  1844,   343,  1838,  1846,  1847,   601,
    1849,   601,   601,   601,  1843,   601,  1845,  1894,  1897,  1177,
    1900,  1178,   601,   613,   614,   615,   616,  1902,   601,   601,
     601,  1200,   601,  1904,  1908,  1909,  1325,  1914,   114,   114,
     115,   115,   601,  1209,  1253,   447,  1256,  1921,   613,   614,
     615,   616,  1885,   601,   668,   319,  1886,   601,  1926,  1889,
     601,   601,  1929,  1893,   601,  1958,  1983,   603,   604,  2017,
    1257,  1307,  1326,  1316,   605,   606,   607,   608,   609,   610,
     611,   612,   601,   601,   601,  1317,   601,  2021,  2029,  2033,
     475,  2056,  1322,  1318,   601,  1923,  1319,  1924,  1925,  2091,
    1927,   835,  1930,  1323,  1336,  1351,  1352,  1359,  1363,  1369,
    1664,  1371,  1381,   613,   614,   615,   616,  1383,  1385,  1510,
    1387,  1201,   605,   606,   607,   608,   609,   610,   611,   612,
    1943,   603,   604,   114,  1388,   115,  1389,  1395,   605,   606,
     607,   608,   609,   610,   611,   612,  1399,  1406,  1413,  1497,
    1498,  1959,  1960,  1961,  1962,  1450,  1964,  1965,  1451,  1499,
    1500,  1968,  1501,  1502,  1520,  1971,  1521,  1522,  1532,  1974,
    1975,  1976,  1538,  1977,  1542,  1548,  1665,  1981,  1982,  1602,
    1610,  1675,  1617,  1984,  1622,    -9,  1987,  1670,  1988,  1681,
    1682,  1750,  1751,  1753,  1778,   591,   593,   114,  1783,   115,
     114,  1789,   115,  1792,  2005,  1793,  1799,  1871,  1851,  1852,
    2011,  2012,  1881,  2014,  2015,  2016,   621,  1873,  1874,  1931,
    1932,   626,  1933,  -542,  1947,  1950,  1953,  1956,  2077,   257,
     344,  1436,   345,   838,   641,   260,  2027,  1033,  1290,   645,
    2030,  1286,  2031,  2032,  1663,  1934,   657,  1289,  2079,  1031,
       0,  1043,  1512,     0,   114,     0,   115,  2039,   613,   614,
     615,   616,     0,     0,     0,     0,  1204,     0,     0,   676,
       0,   678,     0,     0,  2048,     0,     0,     0,  2050,     0,
       0,  2052,  2053,     0,     0,     0,  2055,     0,     0,     0,
    2057,     0,     0,     0,     0,     0,     0,     0,     0,  2068,
       0,     0,     0,     0,  2072,     0,   613,   614,   615,   616,
       0,     0,     0,  2076,     0,     0,     0,     0,   713,     0,
       0,     0,   613,   614,   615,   616,     0,     0,   603,   604,
    2084,  2085,     0,     0,     0,   605,   606,   607,   608,   609,
     610,   611,   612,  2092,   603,   604,     0,     0,  2095,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,   603,
     604,     0,     0,     0,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,     0,     0,     0,     0,     0,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,     0,     0,
       0,     0,     0,   799,   800,   801,   802,   603,   604,     0,
     808,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   818,     0,     0,     0,     0,   823,   824,     0,
     825,   826,   827,   828,   319,   319,     0,   603,   604,     0,
       0,   841,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,     0,     0,   603,   604,     0,     0,     0,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
       0,     0,     0,     0,     0,   874,   875,   876,   877,   878,
     879,   880,   881,   882,   883,   319,   885,   886,   887,   888,
     889,   890,   891,   892,   894,     0,     0,     0,     0,     0,
     900,   901,   903,   905,   906,     0,   908,     0,   910,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   924,   613,
     614,   615,   616,     0,     0,   319,     0,  1207,     0,     0,
     937,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,     0,     0,  1208,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,     0,     0,  1210,   964,
     965,   966,   967,   968,   969,   970,   971,   972,   973,   974,
     975,   613,   614,   615,   616,     0,     0,     0,     0,  1211,
       0,     0,     0,   603,     0,     0,     0,     0,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,     0,     0,  1007,     0,  1212,     0,     0,  1010,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1027,  1028,     0,     0,     0,     0,   613,   614,
     615,   616,     0,     0,     0,  1039,  1213,   125,   126,   127,
    1042,   128,   129,   130,   131,   613,   614,   615,   616,     0,
       0,  1049,  1050,  1214,   351,   352,   353,   354,   355,     0,
       0,     0,     0,     0,   132,   133,     0,     0,   356,     0,
       0,     0,     0,     0,   357,   358,     0,     0,     0,     0,
     359,   360,   361,   362,   363,     0,     0,     0,     0,     0,
       0,     0,  1087,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,     0,
       0,     0,     0,   321,     0,     0,     0,     0,     0,   364,
       0,   322,     0,     0,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,   323,     0,     0,     0,     0,   148,
       0,  1138,     0,     0,     0,     0,   149,     0,     0,     0,
     150,   151,     0,     0,  1147,  1149,  1150,  1151,     0,     0,
     152,     0,   153,   154,   613,   614,   615,   616,   155,   156,
     157,   158,   159,   160,     0,     0,     0,     0,     0,     0,
     161,     0,     0,   162,     0,     0,   163,   164,   165,     0,
       0,   166,   167,   168,   169,   170,     0,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
       0,   223,   224,   225,   226,     0,   227,   228,     0,   229,
     230,   231,     0,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,   239,   240,     0,   241,     0,
       0,     0,     0,   603,   604,   242,     0,   317,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,     0,     0,
       0,   603,   604,     0,     0,     0,  1275,  1276,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,     0,     0,
     603,   604,     0,     0,     0,     0,  1279,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,     0,   641,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1298,     0,     0,     0,     0,     0,  1305,  1306,
     603,   604,     0,     0,  1311,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,  1324,   603,
     604,     0,     0,     0,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,     0,     0,     0,  1339,     0,
       0,     0,     0,  1345,  1346,  1347,     0,     0,  1350,     0,
       0,  1353,     0,  1355,     0,  1358,     0,     0,     0,     0,
       0,     0,     0,     0,  1368,     0,     0,     0,  1372,     0,
       0,     0,     0,     0,     0,     0,  1378,     0,  1380,     0,
       0,     0,     0,     0,  1386,     0,     0,     0,  1391,  1393,
    1394,     0,     0,  1397,  1398,     0,     0,  1402,     0,     0,
    1405,     0,     0,  1408,     0,  1410,     0,  1412,     0,     0,
       0,  1416,     0,  1419,   613,   614,   615,   616,     0,     0,
       0,     0,  1215,     0,     0,  1431,  1432,  1433,     0,     0,
       0,   127,   613,   614,   615,   616,   131,  1437,     0,     0,
    1216,     0,     0,     0,     0,  1441,  1442,     0,  1443,  1444,
    1445,   613,   614,   615,   616,     0,     0,   133,     0,  1218,
       0,  1452,  1453,     0,  1455,     0,     0,     0,  1458,  1459,
    1460,     0,  1461,     0,     0,     0,     0,     0,     0,     0,
    1468,     0,     0,     0,     0,     0,  1469,     0,     0,  1470,
       0,   613,   614,   615,   616,     0,     0,     0,     0,  1229,
       0,  1471,     0,     0,  1472,  1473,  1474,     0,  1475,  1476,
     613,   614,   615,   616,   603,   604,     0,  1478,  1230,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,   603,
     604,   146,     0,   147,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,  1484,     0,  1485,  1486,  1487,
       0,     0,   150,   151,     0,     0,     0,     0,     0,     0,
       0,  1493,     0,     0,     0,     0,     0,     0,     0,     0,
     250,   251,   252,   253,   159,     0,     0,     0,     0,     0,
       0,  1507,   161,     0,     0,   162,     0,     0,   163,   164,
     254,  1514,     0,   166,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1525,  1526,     0,     0,     0,   319,
     319,     0,     0,     0,     0,     0,     0,     0,  1535,  1536,
       0,   192,   193,   194,     0,     0,     0,   198,   199,   200,
       0,   202,     0,   204,   205,   206,     0,     0,     0,     0,
     211,   212,   213,   214,   215,     0,     0,   218,     0,   220,
       0,   222,     0,     0,   224,     0,   226,     0,     0,   228,
       0,     0,   230,   231,     0,   232,   233,     0,   235,     0,
     237,     0,     0,     0,     0,     0,     0,     0,   240,     0,
       0,     0,     0,     0,     0,     0,     0,   255,   913,   603,
     604,     0,     0,  1585,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,   613,   614,   615,   616,     0,
       0,     0,     0,  1232,     0,     0,     0,     0,   334,   336,
     613,   614,   615,   616,     0,     0,     0,     0,  1235,   350,
       0,   365,   366,   368,   370,   373,   378,   379,   383,   385,
     387,     0,     0,     0,     0,   397,   399,   401,   403,   404,
     405,   411,   416,   424,   431,   433,   435,   603,   604,     0,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   603,   604,     0,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   645,     0,     0,
       0,     0,  1668,     0,     0,     0,     0,  1672,     0,     0,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1695,  1696,
    1697,     0,  1699,     0,     0,     0,     0,     0,   517,  1705,
       0,     0,     0,  1709,  1710,     0,     0,     0,     0,  1715,
       0,  1716,  1718,     0,     0,     0,  1722,     0,     0,     0,
       0,     0,     0,     0,  1731,     0,     0,  1734,  1735,     0,
    1736,     0,     0,  1739,     0,     0,     0,     0,  1744,     0,
     613,   614,   615,   616,   603,   604,     0,     0,  1259,  1752,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
       0,     0,     0,     0,     0,     0,     0,  1761,     0,  1763,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1766,
       0,     0,     0,     0,     0,     0,     0,     0,  1769,     0,
    1770,     0,     0,     0,     0,  1772,     0,     0,     0,     0,
       0,     0,     0,     0,  1775,     0,     0,     0,   613,   614,
     615,   616,     0,     0,  1784,     0,  1301,  1787,     0,     0,
       0,     0,     0,   613,   614,   615,   616,     0,     0,   603,
     604,  1519,     0,     0,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,     0,  1808,  1809,     0,     0,
    1812,   613,   614,   615,   616,     0,     0,   682,  1818,  1603,
       0,     0,     0,   687,     0,     0,     0,  1824,  1825,     0,
     694,   696,  1828,     0,     0,     0,     0,  1831,     0,     0,
       0,  1835,   700,   701,   702,   703,   704,   705,   706,     0,
       0,   709,   710,   711,   712,     0,   603,   604,  1850,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1870,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1883,     0,   613,   614,   615,   616,     0,
       0,     0,     0,  1604,     0,  1888,     0,  1890,     0,  1892,
       0,     0,     0,     0,     0,  1898,     0,     0,  1901,     0,
    1903,     0,     0,  1906,  1907,     0,     0,  1910,     0,     0,
       0,     0,     0,     0,  1915,     0,  1917,  1918,  1919,     0,
       0,  1922,     0,     0,     0,     0,     0,  1928,     0,     0,
       0,     0,     0,     0,   603,   604,   815,   816,   817,     0,
    1936,   605,   606,   607,   608,   609,   610,   611,   612,     0,
    1937,     0,     0,     0,     0,     0,     0,   840,  1944,  1945,
     613,   614,   615,   616,   603,   604,     0,     0,  1611,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
       0,     0,     0,     0,     0,     0,  1967,     0,     0,  1969,
     603,   604,     0,  1972,     0,  1973,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,     0,  2008,  1612,  2010,     0,     0,  2013,
       0,     0,     0,     0,     0,     0,     0,  2018,     0,     0,
    2019,     0,     0,     0,  2023,     0,     0,     0,     0,     0,
       0,     0,  2026,     0,  2028,     0,     0,     0,     0,     0,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,  2040,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2049,     0,  2051,     0,     0,     0,
       0,     0,     0,     0,   125,   126,   127,     0,   128,   129,
     130,   131,     0,     0,     0,   613,   614,   615,   616,  2070,
       0,     0,     0,  1613,     0,     0,     0,     0,  2075,     0,
       0,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,     0,  1044,  1614,     0,     0,  1047,     0,     0,     0,
    1051,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,   613,   614,   615,   616,  1065,  1066,     0,     0,  1615,
       0,     0,   141,  1072,     0,   142,     0,     0,  1076,     0,
     315,     0,     0,  1081,     0,  1083,     0,     0,   316,     0,
       0,     0,   144,   145,     0,     0,   146,  1095,   147,  1097,
       0,  1099,     0,  1101,  1102,  1103,   148,     0,     0,     0,
       0,  1107,     0,   149,     0,     0,  1111,   150,   151,     0,
       0,     0,     0,     0,  1117,     0,     0,   152,     0,   153,
     154,     0,  1124,     0,     0,   155,   156,   157,   158,   159,
     160,   613,   614,   615,   616,     0,     0,   161,     0,  1620,
     162,     0,     0,   163,   164,   165,     0,     0,   166,   167,
     168,   169,   170,     0,     0,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,     0,   223,   224,
     225,   226,     0,   227,   228,     0,   229,   230,   231,     0,
     232,   233,   234,   235,   236,   237,   238,     0,     0,     0,
       0,     0,   239,   240,     0,   241,     0,     0,   603,   604,
       0,     0,   242,     0,   317,   605,   606,   607,   608,   609,
     610,   611,   612,   603,   604,     0,     0,     0,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,     0,     0,
       0,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,     0,     0,
       0,     0,   603,   604,     0,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,     0,     0,     0,
       0,     0,     0,   603,   604,     0,     0,     0,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,   126,   127,
       0,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1329,     0,     0,   132,   133,     0,     0,     0,  1333,
       0,     0,     0,     0,  1338,     0,  1340,     0,  1342,  1343,
       0,     0,     0,  1348,  1349,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,   613,
     614,   615,   616,     0,     0,   141,     0,  1621,   142,     0,
       0,     0,     0,   143,   613,   614,   615,   616,     0,     0,
       0,   829,  1630,     0,     0,   144,   145,     0,     0,   146,
       0,   147,   613,   614,   615,   616,     0,     0,     0,   148,
    1631,     0,     0,     0,     0,     0,   149,     0,     0,     0,
     150,   151,     0,   613,   614,   615,   616,     0,     0,     0,
     152,  1632,   153,   154,     0,  1438,  1439,     0,   155,   156,
     157,   158,   159,   160,   613,   614,   615,   616,     0,     0,
     161,     0,  1633,   162,     0,     0,   163,   164,   165,     0,
    1454,   166,   167,   168,   169,   170,     0,     0,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
       0,   223,   224,   225,   226,     0,   227,   228,     0,   229,
     230,   231,     0,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,   239,   240,     0,   241,     0,
       0,     0,     0,     0,     0,   242,     0,   317,   125,   126,
     127,     0,   128,   129,   130,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   134,   135,
     136,   137,   138,   139,   140,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   141,     0,     0,   142,
       0,     0,     0,     0,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   144,   145,     0,     0,
     146,     0,   147,     0,     0,     0,     0,     0,     0,     0,
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
     222,     0,   223,   224,   225,   226,     0,   227,   228,     0,
     229,   230,   231,     0,   232,   233,   234,   235,   236,   237,
     238,     0,     0,     0,     0,     0,   239,   240,     0,   241,
       0,     0,     0,     0,     0,     0,   242,     0,   317,     0,
       0,  1691,     0,     0,  1694,     0,     0,     0,  1698,     0,
       0,   125,   126,   127,     0,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1755,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,   603,   604,     0,     0,   143,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,     0,
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
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,  1887,   241,     0,     0,  1891,     0,     0,     0,   242,
     807,   125,   126,   127,     0,   128,   129,   130,   131,     0,
       0,     0,     0,     0,   613,   614,   615,   616,     0,     0,
       0,     0,  1634,     0,     0,     0,     0,     0,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,   603,   604,     0,     0,   143,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,     0,
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
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,     0,   241,     0,     0,     0,     0,     0,     0,   242,
     893,   125,   126,   127,     0,   128,   129,   130,   131,     0,
       0,     0,     0,     0,   613,   614,   615,   616,     0,     0,
       0,     0,  1637,     0,     0,     0,     0,     0,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,   603,   604,     0,     0,   143,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,     0,
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
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,     0,   241,     0,     0,     0,     0,     0,     0,   242,
     904,   125,   126,   127,     0,   128,   129,   130,   131,     0,
       0,     0,     0,     0,   613,   614,   615,   616,     0,     0,
       0,     0,  1638,     0,     0,     0,     0,     0,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,     0,     0,     0,     0,   143,     0,     0,
       0,     0,     0,   417,     0,     0,     0,     0,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,     0,
       0,     0,     0,   148,     0,     0,     0,     0,     0,     0,
     149,     0,     0,     0,   150,   151,     0,     0,     0,     0,
       0,     0,     0,     0,   152,     0,   153,   154,     0,     0,
     418,   419,   155,   156,   157,   158,   159,   160,     0,   420,
     421,   422,   423,     0,   161,     0,     0,   162,     0,     0,
     163,   164,   165,     0,     0,   166,   167,   168,   169,   170,
       0,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,     0,   241,     0,     0,     0,   125,   126,   127,   242,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   425,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,     0,     0,
       0,     0,   143,     0,     0,     0,     0,     0,   426,     0,
       0,     0,     0,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,     0,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,   153,   154,     0,     0,   427,   428,   155,   156,   157,
     158,   159,   160,   429,     0,     0,     0,   430,     0,   161,
       0,     0,   162,     0,     0,   163,   164,   165,     0,     0,
     166,   167,   168,   169,   170,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
     223,   224,   225,   226,     0,   227,   228,     0,   229,   230,
     231,     0,   232,   233,   234,   235,   236,   237,   238,     0,
       0,     0,     0,     0,   239,   240,     0,   241,     0,     0,
       0,   125,   126,   127,   242,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,     0,     0,     0,     0,   143,     0,     0,
       0,     0,     0,   406,     0,     0,     0,     0,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,     0,
       0,     0,     0,   148,     0,     0,     0,     0,     0,     0,
     149,     0,     0,     0,   150,   151,     0,     0,     0,     0,
       0,     0,     0,     0,   152,     0,   153,   154,     0,     0,
     407,   408,   155,   156,   157,   158,   159,   160,     0,   409,
       0,     0,   410,     0,   161,     0,     0,   162,     0,     0,
     163,   164,   165,     0,     0,   166,   167,   168,   169,   170,
       0,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,     0,   241,     0,     0,     0,   125,   126,   127,   242,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   374,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,     0,     0,
       0,     0,   143,     0,     0,     0,     0,     0,   375,     0,
       0,     0,     0,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,   376,     0,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,   153,   154,     0,     0,   377,     0,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,   161,
       0,     0,   162,     0,     0,   163,   164,   165,     0,     0,
     166,   167,   168,   169,   170,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
     223,   224,   225,   226,     0,   227,   228,     0,   229,   230,
     231,     0,   232,   233,   234,   235,   236,   237,   238,     0,
       0,     0,     0,     0,   239,   240,     0,   241,     0,     0,
       0,   125,   126,   127,   242,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,     0,     0,     0,     0,   143,     0,     0,
       0,     0,     0,   412,     0,     0,     0,     0,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,     0,
       0,     0,     0,   148,     0,     0,     0,     0,     0,     0,
     149,     0,     0,     0,   150,   151,     0,     0,     0,     0,
       0,     0,     0,     0,   152,     0,   153,   154,     0,     0,
     413,   414,   155,   156,   157,   158,   159,   160,     0,     0,
       0,     0,   415,     0,   161,     0,     0,   162,     0,     0,
     163,   164,   165,     0,     0,   166,   167,   168,   169,   170,
       0,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,     0,   241,     0,     0,     0,   125,   126,   127,   242,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   380,     0,     0,     0,     0,
       0,     0,     0,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   381,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   603,   604,
       0,     0,   143,     0,     0,   605,   606,   607,   608,   609,
     610,   611,   612,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,   382,     0,     0,     0,   148,     0,
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
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
     223,   224,   225,   226,     0,   227,   228,     0,   229,   230,
     231,     0,   232,   233,   234,   235,   236,   237,   238,     0,
       0,     0,     0,     0,   239,   240,     0,   241,     0,     0,
       0,   125,   126,   127,   242,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     614,   615,   616,     0,     0,     0,     0,  1641,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,   603,   604,     0,     0,   143,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,   394,
       0,     0,     0,   148,     0,     0,     0,     0,     0,     0,
     149,     0,     0,     0,   150,   151,     0,     0,     0,     0,
       0,     0,     0,     0,   152,     0,   153,   154,     0,     0,
     395,   396,   155,   156,   157,   158,   159,   160,     0,     0,
       0,     0,     0,     0,   161,     0,     0,   162,     0,     0,
     163,   164,   165,     0,     0,   166,   167,   168,   169,   170,
       0,     0,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,     0,   241,     0,     0,     0,   125,   126,   127,   242,
     128,   129,   130,   131,     0,   332,     0,     0,     0,     0,
       0,     0,     0,     0,   613,   614,   615,   616,     0,     0,
       0,     0,  1649,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   333,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   603,   604,
       0,     0,   143,     0,     0,   605,   606,   607,   608,   609,
     610,   611,   612,     0,   144,   145,     0,     0,   146,     0,
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
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
     223,   224,   225,   226,     0,   227,   228,     0,   229,   230,
     231,     0,   232,   233,   234,   235,   236,   237,   238,     0,
       0,     0,     0,     0,   239,   240,     0,   241,     0,     0,
       0,   125,   126,   127,   242,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     614,   615,   616,     0,     0,     0,     0,  1652,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,     0,     0,     0,     0,   143,     0,     0,
       0,     0,     0,   371,     0,     0,     0,     0,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,   372,
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
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,     0,   241,     0,     0,     0,   125,   126,   127,   242,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   603,   604,
       0,     0,   143,     0,     0,   605,   606,   607,   608,   609,
     610,   611,   612,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,     0,   445,     0,     0,   148,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   150,
     151,     0,     0,     0,     0,     0,     0,     0,     0,   152,
       0,   153,   154,     0,     0,     0,   446,   155,   156,   157,
     158,   159,   160,     0,     0,     0,     0,     0,     0,   161,
       0,     0,   162,     0,     0,   163,   164,   165,     0,     0,
     166,   167,   168,   169,   170,     0,     0,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
     223,   224,   225,   226,     0,   227,   228,     0,   229,   230,
     231,     0,   232,   233,   234,   235,   236,   237,   238,     0,
       0,     0,     0,     0,   239,   240,     0,   241,     0,     0,
       0,   125,   126,   127,   242,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     614,   615,   616,     0,     0,     0,     0,  1667,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,   603,   604,     0,     0,   143,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,     0,
     482,   483,     0,   148,     0,     0,     0,     0,     0,     0,
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
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,     0,   241,     0,     0,     0,   125,   126,   127,   242,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   613,   614,   615,   616,     0,     0,
       0,     0,  1782,   132,   133,     0,     0,   274,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   603,   604,
       0,     0,   143,     0,     0,   605,   606,   607,   608,   609,
     610,   611,   612,     0,   144,   145,     0,     0,   146,     0,
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
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
     223,   224,   225,   226,     0,   227,   228,     0,   229,   230,
     231,     0,   232,   233,   234,   235,   236,   237,   238,     0,
       0,     0,     0,     0,   239,   240,     0,   241,     0,     0,
       0,   125,   126,   127,   242,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     614,   615,   616,     0,     0,     0,     0,  1786,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,   603,   604,     0,     0,   143,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,   335,
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
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,     0,   241,     0,     0,     0,   125,   126,   127,   242,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   613,   614,   615,   616,     0,     0,
       0,     0,  1848,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   603,   604,
       0,     0,   143,     0,     0,   605,   606,   607,   608,   609,
     610,   611,   612,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,   367,     0,     0,     0,   148,     0,
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
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
     223,   224,   225,   226,     0,   227,   228,     0,   229,   230,
     231,     0,   232,   233,   234,   235,   236,   237,   238,     0,
       0,     0,     0,     0,   239,   240,     0,   241,     0,     0,
       0,   125,   126,   127,   242,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     614,   615,   616,     0,     0,     0,     0,  1857,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,   603,   604,     0,     0,   143,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,   369,
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
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,     0,   241,     0,     0,     0,   125,   126,   127,   242,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   613,   614,   615,   616,     0,     0,
       0,     0,  1860,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   603,   604,
       0,     0,   143,     0,     0,   605,   606,   607,   608,   609,
     610,   611,   612,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,   384,     0,     0,     0,   148,     0,
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
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
     223,   224,   225,   226,     0,   227,   228,     0,   229,   230,
     231,     0,   232,   233,   234,   235,   236,   237,   238,     0,
       0,     0,     0,     0,   239,   240,     0,   241,     0,     0,
       0,   125,   126,   127,   242,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     614,   615,   616,     0,     0,     0,     0,  1861,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,   603,   604,     0,     0,   143,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,     0,   144,
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
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,     0,   241,     0,     0,     0,   125,   126,   127,   242,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   613,   614,   615,   616,     0,     0,
       0,     0,  1863,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   603,   604,
       0,     0,   143,     0,     0,   605,   606,   607,   608,   609,
     610,   611,   612,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,   398,     0,     0,     0,   148,     0,
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
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
     223,   224,   225,   226,     0,   227,   228,     0,   229,   230,
     231,     0,   232,   233,   234,   235,   236,   237,   238,     0,
       0,     0,     0,     0,   239,   240,     0,   241,     0,     0,
       0,   125,   126,   127,   242,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     614,   615,   616,     0,     0,     0,     0,  1880,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,   603,   604,     0,     0,   143,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,   400,
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
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,     0,   241,     0,     0,     0,   125,   126,   127,   242,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   613,   614,   615,   616,     0,     0,
       0,     0,  1990,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   603,   604,
       0,     0,   143,     0,     0,   605,   606,   607,   608,   609,
     610,   611,   612,     0,   144,   145,     0,     0,   146,     0,
     147,     0,     0,     0,   402,     0,     0,     0,   148,     0,
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
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
     223,   224,   225,   226,     0,   227,   228,     0,   229,   230,
     231,     0,   232,   233,   234,   235,   236,   237,   238,     0,
       0,     0,     0,     0,   239,   240,     0,   241,     0,     0,
       0,   125,   126,   127,   242,   128,   129,   130,   131,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     614,   615,   616,     0,     0,     0,     0,  2003,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,   603,   604,     0,     0,   143,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,   432,
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
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,     0,   241,     0,     0,     0,   125,   126,   127,   242,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   613,   614,   615,   616,     0,     0,
       0,     0,  2046,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   603,   604,
       0,     0,   143,     0,     0,   605,   606,   607,   608,   609,
     610,   611,   612,     0,   144,   145,     0,     0,   146,     0,
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
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
     223,   224,   225,   226,     0,   227,   228,     0,   229,   230,
     231,     0,   232,   233,   234,   235,   236,   237,   238,     0,
       0,     0,     0,     0,   239,   240,     0,   241,     0,     0,
       0,   125,   126,   127,   242,   128,   129,   130,   131,     0,
     695,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     614,   615,   616,     0,     0,     0,     0,  2067,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,   142,   603,   604,     0,     0,   143,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,     0,   144,
     145,     0,     0,   146,     0,   147,     0,     0,     0,     0,
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
     219,   220,   221,   222,     0,   223,   224,   225,   226,     0,
     227,   228,     0,   229,   230,   231,     0,   232,   233,   234,
     235,   236,   237,   238,     0,     0,     0,     0,     0,   239,
     240,     0,   241,     0,     0,     0,   125,   126,   127,   242,
     128,   129,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   613,   614,   615,   616,     0,     0,
       0,     0,  2082,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   134,   135,   136,   137,
     138,   139,   140,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,   142,   603,   604,
       0,     0,   143,     0,     0,   605,   606,   607,   608,   609,
     610,   611,   612,     0,   144,   145,     0,     0,   146,     0,
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
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
     223,   224,   225,   226,     0,   227,   228,     0,   229,   230,
     231,     0,   232,   233,   234,   235,   236,   237,   238,     0,
       0,   127,     0,     0,   239,   240,   131,   241,     0,     0,
       0,     0,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   133,     0,   613,
     614,   615,   616,     0,     0,   669,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   603,   604,
       0,     0,     0,     0,     0,   605,   606,   607,   608,   609,
     610,   611,   612,     0,     0,   603,   604,     0,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,     0,     0,     0,     0,     0,   603,   604,     0,
       0,   146,     0,   147,   605,   606,   607,   608,   609,   610,
     611,   612,     0,     0,     0,     0,     0,     0,     0,     0,
     127,     0,   150,   151,     0,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     250,   251,   252,   253,   159,     0,   133,     0,     0,     0,
       0,     0,   161,     0,     0,   162,     0,     0,   163,   164,
     254,     0,     0,   166,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   192,   193,   194,     0,     0,     0,   198,   199,   200,
       0,   202,     0,   204,   205,   206,     0,     0,     0,     0,
     211,   212,   213,   214,   215,     0,     0,   218,     0,   220,
     146,   222,   147,     0,   224,     0,   226,     0,     0,   228,
       0,     0,   230,   231,     0,   232,   233,     0,   235,   127,
     237,   150,   151,     0,   131,     0,     0,     0,   240,   613,
     614,   615,   616,     0,     0,   686,     0,   255,   915,   250,
     251,   252,   253,   159,     0,   133,   613,   614,   615,   616,
       0,   161,   797,     0,   162,     0,     0,   163,   164,   254,
       0,     0,   166,   167,     0,     0,     0,     0,   613,   614,
     615,   616,     0,     0,  1034,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,   194,     0,     0,     0,   198,   199,   200,     0,
     202,     0,   204,   205,   206,     0,     0,     0,     0,   211,
     212,   213,   214,   215,     0,     0,   218,     0,   220,   146,
     222,   147,     0,   224,     0,   226,     0,     0,   228,     0,
       0,   230,   231,     0,   232,   233,     0,   235,     0,   237,
     150,   151,     0,   127,     0,     0,     0,   240,   131,     0,
       0,     0,     0,     0,     0,     0,   255,   917,   250,   251,
     252,   253,   159,     0,     0,     0,     0,     0,     0,   133,
     161,     0,     0,   162,     0,     0,   163,   164,   254,     0,
       0,   166,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   192,
     193,   194,     0,     0,     0,   198,   199,   200,     0,   202,
       0,   204,   205,   206,     0,     0,     0,     0,   211,   212,
     213,   214,   215,     0,     0,   218,     0,   220,     0,   222,
       0,     0,   224,   146,   226,   147,     0,   228,     0,   388,
     230,   231,     0,   232,   233,     0,   235,     0,   237,     0,
       0,     0,     0,     0,   150,   151,   240,   127,     0,     0,
       0,     0,   131,     0,     0,   255,   919,     0,     0,     0,
       0,     0,   250,   251,   252,   253,   159,     0,     0,     0,
       0,     0,     0,   133,   161,     0,     0,   162,     0,     0,
     163,   164,   254,     0,     0,   166,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   192,   193,   194,     0,     0,     0,   198,
     199,   200,     0,   202,     0,   204,   205,   206,     0,     0,
       0,     0,   211,   212,   213,   214,   215,     0,     0,   218,
       0,   220,     0,   222,     0,     0,   224,   146,   226,   147,
       0,   228,     0,   436,   230,   231,     0,   232,   233,     0,
     235,     0,   237,     0,     0,     0,     0,     0,   150,   151,
     240,   127,     0,     0,     0,     0,   131,     0,     0,   255,
       0,     0,     0,     0,     0,     0,   250,   251,   252,   253,
     159,     0,     0,     0,     0,     0,     0,   133,   161,     0,
       0,   162,     0,     0,   163,   164,   254,     0,     0,   166,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,   193,   194,
       0,     0,     0,   198,   199,   200,     0,   202,     0,   204,
     205,   206,     0,     0,     0,     0,   211,   212,   213,   214,
     215,     0,     0,   218,     0,   220,     0,   222,     0,     0,
     224,   146,   226,   147,     0,   228,     0,   438,   230,   231,
       0,   232,   233,     0,   235,     0,   237,     0,     0,     0,
       0,     0,   150,   151,   240,   127,     0,     0,     0,     0,
     131,     0,     0,   255,     0,     0,     0,     0,     0,     0,
     250,   251,   252,   253,   159,     0,     0,     0,     0,     0,
       0,   133,   161,     0,     0,   162,     0,     0,   163,   164,
     254,     0,     0,   166,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   192,   193,   194,     0,     0,     0,   198,   199,   200,
       0,   202,     0,   204,   205,   206,     0,     0,     0,     0,
     211,   212,   213,   214,   215,     0,     0,   218,     0,   220,
       0,   222,     0,     0,   224,   146,   226,   147,     0,   228,
       0,   440,   230,   231,     0,   232,   233,     0,   235,     0,
     237,     0,     0,     0,   127,     0,   150,   151,   240,   131,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,     0,     0,     0,   250,   251,   252,   253,   159,     0,
     133,     0,     0,     0,     0,     0,   161,     0,     0,   162,
       0,     0,   163,   164,   254,     0,     0,   166,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   192,   193,   194,     0,     0,
       0,   198,   199,   200,     0,   202,     0,   204,   205,   206,
       0,     0,     0,     0,   211,   212,   213,   214,   215,     0,
       0,   218,     0,   220,   146,   222,   147,     0,   224,     0,
     226,     0,     0,   228,     0,     0,   230,   231,     0,   232,
     233,     0,   235,     0,   237,   150,   151,     0,   127,     0,
       0,     0,   240,   131,     0,     0,     0,     0,     0,     0,
       0,   255,     0,   250,   251,   252,   253,   159,     0,   777,
       0,     0,     0,     0,   133,   161,     0,     0,   162,     0,
       0,   163,   164,   254,     0,     0,   166,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,   193,   194,     0,     0,     0,
     198,   199,   200,     0,   202,     0,   204,   205,   206,     0,
       0,     0,     0,   211,   212,   213,   214,   215,     0,     0,
     218,     0,   220,     0,   222,     0,     0,   224,   146,   226,
     147,     0,   228,     0,     0,   230,   231,     0,   232,   233,
       0,   235,     0,   237,     0,   603,   604,     0,     0,   150,
     151,   240,   605,   606,   607,   608,   609,   610,   611,   612,
     255,     0,     0,     0,     0,     0,     0,   250,   251,   252,
     253,   159,   127,   861,     0,     0,     0,   131,     0,   161,
       0,     0,   162,     0,     0,   163,   164,   254,     0,     0,
     166,   167,     0,     0,     0,     0,     0,     0,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,   193,
     194,     0,     0,     0,   198,   199,   200,     0,   202,     0,
     204,   205,   206,     0,     0,     0,     0,   211,   212,   213,
     214,   215,     0,     0,   218,     0,   220,     0,   222,     0,
       0,   224,     0,   226,     0,     0,   228,     0,     0,   230,
     231,     0,   232,   233,  1037,   235,     0,   237,     0,     0,
       0,     0,   146,     0,   147,   240,     0,     0,   603,   604,
       0,     0,     0,     0,   255,   605,   606,   607,   608,   609,
     610,   611,   612,   150,   151,     0,     0,     0,     0,   127,
       0,     0,     0,     0,   131,     0,     0,     0,     0,     0,
       0,   250,   251,   252,   253,   159,     0,     0,     0,     0,
       0,     0,     0,   161,     0,   133,   162,     0,     0,   163,
     164,   254,     0,     0,   166,   167,   613,   614,   615,   616,
       0,     0,  1064,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   192,   193,   194,     0,     0,     0,   198,   199,
     200,     0,   202,     0,   204,   205,   206,     0,     0,     0,
       0,   211,   212,   213,   214,   215,     0,     0,   218,     0,
     220,  1447,   222,     0,     0,   224,     0,   226,     0,   146,
     228,   147,     0,   230,   231,     0,   232,   233,     0,   235,
       0,   237,     0,     0,     0,     0,     0,     0,   127,   240,
     150,   151,     0,   131,     0,     0,     0,     0,   255,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   250,   251,
     252,   253,   159,     0,   133,     0,     0,     0,     0,     0,
     161,     0,     0,   162,     0,     0,   163,   164,   254,     0,
       0,   166,   167,     0,     0,     0,     0,     0,     0,   613,
     614,   615,   616,     0,     0,  1161,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   192,
     193,   194,     0,     0,     0,   198,   199,   200,     0,   202,
       0,   204,   205,   206,     0,     0,     0,     0,   211,   212,
     213,   214,   215,     0,     0,   218,     0,   220,   146,   222,
     147,     0,   224,     0,   226,     0,     0,   228,     0,     0,
     230,   231,     0,   232,   233,     0,   235,   127,   237,   150,
     151,     0,   131,     0,     0,     0,   240,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,   250,   251,   252,
     253,   159,     0,   133,     0,     0,     0,     0,     0,   161,
       0,     0,   162,     0,     0,   163,   164,   254,     0,     0,
     166,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,   193,
     194,     0,     0,     0,   198,   199,   200,     0,   202,     0,
     204,   205,   206,     0,     0,     0,     0,   211,   212,   213,
     214,   215,     0,     0,   218,     0,   220,   146,   222,   147,
       0,   224,     0,   226,     0,     0,   228,     0,     0,   230,
     231,     0,   232,   233,     0,   235,     0,   237,   150,   151,
       0,     0,     0,     0,     0,   240,     0,     0,     0,     0,
       0,     0,     0,     0,   255,     0,   250,   251,   252,   253,
     159,     0,     0,     0,     0,     0,     0,     0,   161,     0,
       0,   162,     0,     0,   163,   164,   254,     0,     0,   166,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   192,   193,   194,
       0,     0,     0,   198,   199,   200,     0,   202,     0,   204,
     205,   206,     0,     0,     0,     0,   211,   212,   213,   214,
     215,     0,     0,   218,     0,   220,     0,   222,     0,     0,
     224,     0,   226,     0,     0,   228,     0,     0,   230,   231,
       0,   232,   233,     0,   235,     0,   237,     0,     0,     7,
       8,     9,     0,     0,   240,     0,    10,     0,     0,     0,
      11,     0,    12,  1302,    13,    14,    15,    16,    17,  -493,
       0,    18,    19,    20,    21,    22,    23,    24,    25,     0,
      26,    27,    28,     0,     0,     0,     0,    29,     0,     0,
      30,     0,     0,     0,     0,     0,     0,    31,    32,    33,
      34,    35,    36,     0,     0,     0,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    40,    41,    42,    43,    44,     0,
       0,     0,     0,     0,    45,    46,    47,  -242,  -242,    48,
      49,    50,     0,    51,    52,    53,     0,     0,    54,  -242,
       0,    55,     0,    56,    57,     0,     0,     0,     0,    58,
      59,     0,     0,     0,     0,     0,    60,     0,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,     0,     0,    80,
      81,    82,    83,    84,    85,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,     0,     0,     0,     0,    90,
      91,    92,     0,     0,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      96,    97,    98,     0,     0,     0,     0,    99,     0,     0,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,   100,     0,     0,
       0,   101,     0,     7,     8,     9,   102,     0,     0,   103,
      10,     0,     0,   104,    11,     0,    12,     0,    13,    14,
      15,    16,    17,  -493,     0,    18,    19,    20,    21,    22,
      23,    24,    25,     0,    26,    27,    28,     0,     0,     0,
       0,    29,   -16,   -16,    30,     0,     0,     0,     0,     0,
       0,    31,    32,    33,    34,    35,    36,     0,     0,     0,
      37,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,    44,     0,     0,     0,     0,     0,    45,    46,
      47,     0,     0,    48,    49,    50,     0,    51,    52,    53,
       0,     0,    54,     0,     0,    55,     0,    56,    57,     0,
       0,     0,     0,    58,    59,     0,     0,     0,     0,     0,
      60,     0,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,     0,
       0,     0,     0,    90,    91,    92,     0,     0,    93,    94,
      95,   613,   614,   615,   616,     0,     0,  1162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,    97,    98,     0,     0,     0,
       0,    99,     0,     0,   603,   604,     0,     0,     0,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
       0,   100,     0,     0,     0,   101,     0,     7,     8,     9,
     102,     0,     0,   103,    10,     0,     0,   104,    11,     0,
      12,     0,    13,    14,    15,    16,    17,  -493,     0,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,   -16,     0,     0,     0,    29,   -16,     0,    30,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,   603,   604,     0,    37,    38,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,    45,    46,    47,     0,     0,    48,    49,    50,
       0,    51,    52,    53,     0,     0,    54,     0,     0,    55,
       0,    56,    57,     0,     0,     0,     0,    58,    59,     0,
       0,     0,     0,     0,    60,     0,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,     0,    80,    81,    82,
      83,    84,    85,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,     0,     0,     0,    90,    91,    92,
       0,     0,    93,    94,    95,   613,   614,   615,   616,   603,
     604,  1164,     0,     0,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,     0,     0,     0,    96,    97,
      98,   603,   604,     0,     0,    99,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,     0,     0,   101,
       0,     0,     0,     0,   102,   603,   604,   103,     0,     0,
       0,   104,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,   613,   614,   615,   616,   603,   604,  1165,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   603,   604,     0,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   603,   604,     0,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   603,   604,     0,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,   603,   604,  1166,     0,     0,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
       0,     0,   613,   614,   615,   616,   603,   604,  1180,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     603,   604,  1217,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,   613,   614,   615,
     616,     0,     0,  1224,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  1225,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  1245,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  1297,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  1320,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  1321,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,   603,   604,  1328,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,   603,
     604,  1334,     0,     0,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  1335,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,   603,   604,  1375,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   603,   604,  1428,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,   603,   604,     0,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,   603,   604,     0,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,   603,   604,     0,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,   613,   614,   615,   616,   603,   604,  1434,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,   603,   604,  1435,     0,     0,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,   603,
     604,     0,     0,     0,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,     0,     0,   613,   614,   615,
     616,   603,   604,  1508,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
       0,     0,  1513,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,  1527,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
       0,     0,  1539,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,  1544,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
       0,     0,  1545,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,  1546,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
     603,   604,  1549,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,   613,   614,   615,
     616,   603,   604,  1577,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,  1584,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,   603,   604,  1589,     0,     0,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
       0,     0,   613,   614,   615,   616,   603,   604,  1592,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   603,   604,     0,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   603,   604,     0,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   603,   604,     0,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   603,   604,  1625,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,   613,   614,   615,   616,   603,   604,  1650,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,   603,
     604,  1651,     0,     0,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  1673,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  1687,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  1801,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  1802,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  1803,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  1805,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,   603,   604,  1811,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     603,   604,  1814,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,   613,   614,   615,
     616,     0,     0,  1819,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,   603,   604,  1820,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,   603,   604,  1823,     0,     0,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,   603,
     604,     0,     0,     0,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,   603,   604,     0,     0,     0,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,   603,
     604,     0,     0,     0,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,   603,   604,     0,     0,     0,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,   603,
     604,     0,     0,     0,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,   603,   604,     0,     0,     0,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
       0,     0,   613,   614,   615,   616,   603,   604,  1832,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   603,   604,  1833,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,   613,   614,   615,
     616,   603,   604,  1834,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,  1837,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,  1841,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,  1856,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,  1875,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,  1895,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,  1896,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,   603,
     604,  1899,     0,     0,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,     0,     0,   613,   614,   615,
     616,   603,   604,  1905,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
       0,     0,  1911,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,   603,   604,  1912,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,   613,   614,   615,   616,   603,   604,  1913,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   603,   604,     0,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   603,   604,     0,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   603,   604,     0,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,   603,   604,  1916,     0,     0,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
       0,     0,   613,   614,   615,   616,   603,   604,  1920,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,   613,   614,   615,   616,
     603,   604,  1952,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,   613,   614,   615,
     616,     0,     0,  1954,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  1955,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  1957,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  1963,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  1966,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  1970,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,   603,   604,  1978,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,   603,
     604,  1979,     0,     0,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  1980,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,   603,   604,  1986,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   603,   604,  2002,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,   603,   604,     0,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,   603,   604,     0,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,   603,   604,     0,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,   613,   614,   615,   616,     0,     0,  2020,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,  2022,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  2024,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
       0,     0,  2025,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,  2045,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
       0,     0,  2047,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,  2054,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
       0,     0,  2073,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,  2074,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
       0,     0,  2086
};

static const yytype_int16 yycheck[] =
{
       3,    15,    16,     1,    44,     1,     4,    12,     4,   485,
      40,     4,     4,    98,     7,     7,    61,    12,    21,   268,
      75,    24,    75,    43,    44,    77,    58,    41,    60,    61,
      33,    11,     4,     5,    37,    38,   260,   286,   262,    42,
       3,    77,     4,     5,     7,     8,     9,    10,    75,    76,
      77,    54,    55,    56,     3,    53,    25,    53,     7,     8,
       9,    10,   112,   454,   455,   112,   111,    70,    71,    72,
     260,    95,   262,    12,    16,    44,    58,   112,    60,    61,
     260,   101,   262,    86,    87,    88,    46,   111,   173,    92,
      70,    71,    72,    73,    74,    75,    76,     0,   101,   102,
     103,   104,    44,    63,    64,   155,    12,   260,   155,   262,
      70,    71,    72,    73,    74,    75,    76,    77,   112,   113,
     155,    28,   255,    28,    63,    64,    33,   260,   100,   112,
     113,    70,    71,    72,    73,    74,    75,    76,    77,   112,
     113,     7,    70,    71,    72,    73,    74,    75,    76,   255,
    1309,  1310,   255,   110,    23,   255,   262,    63,    64,   262,
     260,   155,   262,   166,    70,    71,    72,    73,    74,    75,
      76,    77,   155,    70,    71,    72,    73,    74,    75,    76,
      59,    95,   155,   112,   113,    70,    71,    72,    73,    74,
      75,    76,     4,     5,   585,  1676,   587,    70,    71,    72,
      73,    74,    75,    76,   256,   257,   261,   160,   261,   255,
      89,    90,    91,   261,   260,   255,   262,    96,   254,   255,
     256,   257,   173,   195,   196,   197,   155,   254,   255,   256,
     257,   263,   255,   195,   196,   197,    14,   260,    16,   242,
      18,    92,    93,    70,    71,    72,    73,    74,    75,    76,
     255,   255,   255,   104,   255,   260,   260,    81,    82,   260,
     260,   264,   262,    41,    88,   260,    44,   255,   261,   261,
     268,    49,   268,     4,   262,   255,     7,   280,   255,   309,
     310,   263,   285,   347,   348,   262,   350,   111,   286,   292,
     286,   254,   255,   111,   254,   255,   256,   257,     4,     5,
     255,   365,   366,    76,    77,   254,   255,   262,    44,   373,
     112,   113,    75,   316,   378,   254,   255,   256,   257,   383,
     261,   385,   255,   255,   327,   328,   329,   255,   260,   262,
     262,   255,   335,   397,   262,   399,   260,   401,   262,   403,
     404,   405,    74,    75,    76,    77,   255,   411,   254,   255,
     256,   257,   416,   262,   260,   358,   359,   255,   255,   261,
     424,   261,   260,   260,   367,   262,   369,   431,   371,   372,
     255,   374,   375,   376,   377,   260,    75,   380,   381,   382,
     261,   384,   255,   386,    24,   388,   261,   260,   112,   392,
     393,   394,   395,   396,   263,   398,   265,   400,  1879,   402,
     649,  1882,   261,   406,   407,   408,   409,   410,   255,   412,
     413,   414,   415,   260,   417,   418,   419,   420,   421,   422,
     423,   261,   425,   426,   427,   428,   429,   430,   255,   432,
     261,   434,    14,   436,    16,   438,    18,   440,   261,   442,
     443,   444,   445,   446,    70,    71,    72,    73,    74,    75,
      76,   255,    35,    36,   457,   261,   260,   255,   262,    41,
     480,   481,    44,   112,   262,  1946,   469,    49,  1949,    13,
      70,    71,    72,    73,    74,    75,    76,   480,   261,   482,
     261,   254,   255,   256,   257,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,     3,   261,
     513,   531,     7,     8,     9,   518,   519,   261,  1677,    63,
      64,  1680,   254,   255,   256,   257,    70,    71,    72,    73,
      74,    75,    76,    77,     4,     5,   255,   255,   541,   542,
     543,   544,   545,   262,   262,   548,     4,     5,   551,   261,
     553,   571,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   261,   565,   566,   567,   568,   569,   570,   571,   572,
       4,     5,   575,   255,   577,   578,   579,   580,   581,   255,
     262,   584,   255,   586,   260,   588,   589,   590,  2069,   262,
    2071,   594,   595,   596,   597,   598,   599,   600,   601,   261,
      51,   261,   471,   472,   255,   261,  2087,   255,  2089,   260,
     255,   262,    63,    64,   262,    20,    21,   262,   682,    70,
      71,    72,    73,    74,    75,    76,    77,   255,   255,   255,
     261,  1790,   696,   260,   262,   262,   262,   701,   261,   703,
     112,   705,   706,   255,   162,   675,   112,   711,   712,   652,
     262,   649,   112,   649,   161,   255,   255,   255,    63,    64,
     112,   260,   262,   262,   262,    70,    71,    72,    73,    74,
      75,    76,    77,   259,   260,   172,    71,   680,    73,    74,
      75,    76,    77,   255,    63,    64,     4,     5,   260,   112,
     693,    70,    71,    72,    73,    74,    75,    76,    77,    86,
      87,   255,   255,   261,   573,   574,   260,   260,   262,   262,
     254,   255,   256,   257,   717,    44,   719,    70,    71,    72,
      73,    74,    75,    76,   255,   728,     4,     5,   172,   260,
     979,   262,    46,   736,    63,    64,   739,   740,    49,    50,
     261,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,   261,   816,   817,     4,     5,    70,    71,    72,    73,
      74,    75,    76,    77,    71,    72,    73,    74,    75,    76,
      77,   255,   255,   261,   777,   261,   840,   260,   262,   262,
     783,   261,   785,   261,   787,   261,   789,   255,   791,  1948,
    1266,   255,  1951,  1269,   262,   798,   665,   666,   262,    39,
      40,   670,   671,   254,   255,   256,   257,   810,   811,   155,
      63,    64,    73,    74,    75,    76,    77,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,   246,   247,   248,
     249,   250,    70,    71,    72,    73,    74,    75,    76,    77,
     255,     4,     5,    60,    61,  2004,   255,   262,  2007,   254,
     255,   256,   257,   262,    60,    61,   155,   255,   861,   254,
     255,   256,   257,   866,   262,   868,   869,   870,   871,   255,
     261,   261,   255,   255,   260,   254,   255,   256,   257,   262,
     262,   260,   155,   262,    70,    71,    72,    73,    74,    75,
      76,   261,   261,   261,   261,    70,    71,    72,    73,    74,
      75,    76,   255,   255,   255,    63,    64,   260,   155,   155,
     262,   262,    70,    71,    72,    73,    74,    75,    76,    77,
     261,   261,  2081,   255,  2083,   254,   255,   256,   257,   255,
     262,   255,   255,   261,  2093,  2094,   262,     4,   262,   262,
     254,   255,   256,   257,    63,    64,   261,   254,   255,   256,
     257,    70,    71,    72,    73,    74,    75,    76,    77,    70,
      71,    72,    73,    74,    75,    76,   261,   261,   255,   255,
     255,   255,   255,   987,   988,   262,   262,   262,   262,   262,
     261,   979,   261,   979,   261,    70,    71,    72,    73,    74,
      75,    76,   995,   254,   255,   256,   257,   261,   255,   255,
      44,   254,   255,   256,   257,   262,   262,   260,  1011,   262,
     255,  1014,   261,   261,  1017,   260,   254,   255,   256,   257,
      63,    64,   260,    44,   262,   261,   261,    70,    71,    72,
      73,    74,    75,    76,    77,   261,   255,   261,  1041,   255,
     255,   255,  1045,   262,  1293,   255,   262,   262,   262,  1052,
     255,   255,   262,  1056,   261,   260,  1059,   255,   261,    14,
     255,    16,   260,    18,   261,   260,    43,   261,  1071,   255,
    1073,  1074,  1075,   255,   260,  1078,  1079,  1080,   260,  1082,
     255,   261,   261,  1086,   261,   260,    41,  1090,  1091,    44,
    1093,   261,   261,  1096,    49,  1098,   254,   255,   256,   257,
     261,  1104,  1105,   255,   262,  1108,   261,   261,   260,  1112,
    1113,  1114,  1115,   255,   261,  1118,   261,   261,   260,  1122,
     989,   990,  1125,   992,   993,    14,  1129,    16,  1131,    18,
    1133,   261,  1135,  1136,  1137,   254,   255,   256,   257,   261,
     255,   260,   255,   262,   255,   260,   255,   260,   255,   260,
      58,   260,    41,   260,  1152,    44,  1152,   255,   255,   255,
      49,   255,   260,   260,   260,  1168,   260,  1170,   255,  1172,
     255,   255,   255,   260,   255,   260,   260,   260,  1181,   260,
    1183,   261,   255,   255,   255,   255,  1189,   260,   260,   260,
     260,     5,   261,   255,   255,   255,    63,    64,   260,   260,
     260,    77,   261,    70,    71,    72,    73,    74,    75,    76,
      77,   254,   255,   256,   257,   255,   255,   260,   255,   262,
     260,   260,   255,   260,  1227,   255,   255,   260,   255,   255,
     260,   260,   255,   260,   260,   255,   255,   260,   262,   261,
     260,   260,  1245,  1246,  1247,  1248,    63,    64,   261,   261,
     261,  1254,   261,    70,    71,    72,    73,    74,    75,    76,
      77,   255,   261,   255,  1267,   255,   260,  1270,   260,  1272,
     260,  1140,   255,   255,   261,   261,  1340,   260,   260,  1343,
      63,    64,   261,   261,  1348,   261,   261,    70,    71,    72,
      73,    74,    75,    76,    77,  1293,  1299,  1293,   255,  1302,
      63,    64,   261,   260,   260,  1325,  1326,    70,    71,    72,
      73,    74,    75,    76,    77,   255,   255,   255,   255,   261,
     260,   260,   260,   260,  1327,  1328,   255,    63,    64,  1332,
     261,   260,   260,  1336,    70,    71,    72,    73,    74,    75,
      76,    77,   255,   261,   261,   255,   261,   260,  1351,  1352,
     260,  1354,   255,  1356,   255,   261,  1359,   260,   255,   260,
    1363,  1364,   255,   260,   255,   261,  1369,   260,  1371,   260,
    1373,   255,  1375,   261,  1438,   261,   260,   260,  1381,   261,
    1383,   261,  1385,   261,  1387,  1388,  1389,   254,   255,   256,
     257,  1455,  1395,   255,   255,   262,  1399,   255,   260,   260,
     255,   255,   260,  1406,   255,   260,   260,   260,   255,   260,
    1413,   255,  1415,   260,  1417,   255,   260,  1420,   255,  1422,
     260,  1424,   255,   260,   255,  1428,  1429,   260,   255,   260,
     255,  1434,  1435,   260,   260,   260,   255,   254,   255,   256,
     257,   260,   255,   255,   260,   262,   255,   260,   260,  1318,
    1319,   260,   255,   255,   255,   255,   261,   260,   260,   260,
     260,  1464,  1465,  1466,  1467,   255,   261,   260,   260,   260,
     260,   254,   255,   256,   257,   255,   255,   255,   260,   262,
     260,   260,   260,  1497,  1498,   255,   260,   260,   260,   260,
     260,   254,   255,   256,   257,   261,   255,   255,   255,   262,
    1503,   260,   260,   260,   255,   255,   255,   261,   255,   260,
     260,   260,  1515,   260,   262,   261,    75,   255,   254,   255,
     256,   257,   260,   262,  1527,   262,   262,  1776,  1777,  1532,
    1533,   261,   255,   261,   260,  1538,  1539,   260,  1541,  1542,
     255,   261,   255,   255,   255,   260,  1549,   260,   260,   260,
     260,   255,   255,   255,   261,  1558,   260,   260,   260,  1562,
     260,   255,    43,   255,   255,  1568,   260,  1570,   260,   260,
     255,   255,    63,    64,  1577,   260,   260,  1580,  1581,    70,
      71,    72,    73,    74,    75,    76,    77,   255,  1591,  1592,
      46,  1594,   260,  1596,   255,  1598,  1599,    63,    64,   260,
      10,   261,   261,   261,    70,    71,    72,    73,    74,    75,
      76,    77,   255,   255,   255,  1618,    58,   260,   260,   260,
     255,  1624,  1871,   255,   255,   260,   255,   255,   260,   260,
    1694,   260,   260,   255,  1698,   260,  1639,   255,   260,   255,
    1643,   255,   260,   255,   260,   260,   260,  1650,   260,   255,
    1653,  1520,  1521,  1656,   260,   255,   255,   260,   260,   255,
     260,   260,    63,    64,   260,   260,    43,   261,  1671,    70,
      71,    72,    73,    74,    75,    76,    77,   255,   260,   260,
     260,   260,   260,  1686,  1687,  1688,  1935,   255,   255,  1938,
     255,   262,   260,   260,   255,   260,     2,   255,  1701,   260,
     255,  1704,   260,   260,  1707,   260,   262,   255,  1711,   255,
    1713,    17,   260,   262,   260,   255,  1719,   262,  1721,   261,
     260,   262,  1725,  1726,    30,   261,  1729,    33,   255,   255,
      36,    37,    38,   260,   260,  1738,    42,    43,    44,  1742,
     262,   255,  1745,  1992,  1747,    51,   260,  1750,  1751,   255,
    1753,   255,   255,   255,   260,   255,   260,   260,   260,   260,
     260,   260,   255,   254,   255,   256,   257,   260,   255,   255,
     255,   262,   255,   260,   260,   260,    85,   260,  1776,  1777,
    1776,  1777,   255,   262,   262,    91,   262,   260,   254,   255,
     256,   257,  1795,   255,   260,   101,  1799,   255,   260,  1802,
     255,   255,   260,  1806,   255,   260,   260,    63,    64,   260,
     262,   261,    85,   262,    70,    71,    72,    73,    74,    75,
      76,    77,   255,   255,   255,   262,   255,   260,   260,   260,
     136,   260,   262,   261,   255,  1838,   261,  1840,  1841,   260,
    1843,     5,  1845,   262,   260,   260,   260,   260,   260,   260,
      43,   260,   260,   254,   255,   256,   257,   260,   260,    58,
     260,   262,    70,    71,    72,    73,    74,    75,    76,    77,
    1873,    63,    64,  1871,   260,  1871,   260,   260,    70,    71,
      72,    73,    74,    75,    76,    77,   260,   260,   260,   260,
     260,  1894,  1895,  1896,  1897,   262,  1899,  1900,   262,   262,
     262,  1904,   262,   262,   261,  1908,   261,   260,   260,  1912,
    1913,  1914,   260,  1916,   260,   260,    38,  1920,  1921,   262,
     261,    58,   262,  1926,   262,    43,  1929,   261,  1931,   262,
     262,    75,    75,    75,    48,   241,   242,  1935,    58,  1935,
    1938,   261,  1938,   262,  1947,   262,   260,    47,   261,   261,
    1953,  1954,    58,  1956,  1957,  1958,   262,   261,   261,    75,
     262,   267,   262,    38,   261,   261,   260,   260,     4,     4,
      53,  1152,    53,   485,   280,     5,  1979,   675,   995,   285,
    1983,   991,  1985,  1986,  1503,  1853,   292,   994,  2065,   672,
      -1,   688,  1305,    -1,  1992,    -1,  1992,  2000,   254,   255,
     256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,   315,
      -1,   317,    -1,    -1,  2017,    -1,    -1,    -1,  2021,    -1,
      -1,  2024,  2025,    -1,    -1,    -1,  2029,    -1,    -1,    -1,
    2033,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2042,
      -1,    -1,    -1,    -1,  2047,    -1,   254,   255,   256,   257,
      -1,    -1,    -1,  2056,    -1,    -1,    -1,    -1,   364,    -1,
      -1,    -1,   254,   255,   256,   257,    -1,    -1,    63,    64,
    2073,  2074,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,  2086,    63,    64,    -1,    -1,  2091,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   449,   450,   451,   452,    63,    64,    -1,
     456,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   468,    -1,    -1,    -1,    -1,   473,   474,    -1,
     476,   477,   478,   479,   480,   481,    -1,    63,    64,    -1,
      -1,   487,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,    -1,    -1,    -1,    -1,    -1,
     546,   547,   548,   549,   550,    -1,   552,    -1,   554,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   564,   254,
     255,   256,   257,    -1,    -1,   571,    -1,   262,    -1,    -1,
     576,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,   254,   255,
     256,   257,    -1,    -1,   650,    -1,   262,    -1,    -1,   655,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   668,   669,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,    -1,   681,   262,     3,     4,     5,
     686,     7,     8,     9,    10,   254,   255,   256,   257,    -1,
      -1,   697,   698,   262,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,   104,    -1,
      -1,    -1,    -1,    -1,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   738,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,   165,
      -1,    97,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,   110,    -1,    -1,    -1,    -1,   115,
      -1,   797,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,    -1,   810,   811,   812,   813,    -1,    -1,
     136,    -1,   138,   139,   254,   255,   256,   257,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
      -1,   167,   168,   169,   170,   171,    -1,    -1,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,   227,   228,   229,   230,    -1,   232,   233,    -1,   235,
     236,   237,    -1,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,
      -1,    -1,    -1,    63,    64,   261,    -1,   263,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,   962,   963,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,   982,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,   995,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1008,    -1,    -1,    -1,    -1,    -1,  1014,  1015,
      63,    64,    -1,    -1,  1020,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,  1034,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,  1054,    -1,
      -1,    -1,    -1,  1059,  1060,  1061,    -1,    -1,  1064,    -1,
      -1,  1067,    -1,  1069,    -1,  1071,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1080,    -1,    -1,    -1,  1084,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1092,    -1,  1094,    -1,
      -1,    -1,    -1,    -1,  1100,    -1,    -1,    -1,  1104,  1105,
    1106,    -1,    -1,  1109,  1110,    -1,    -1,  1113,    -1,    -1,
    1116,    -1,    -1,  1119,    -1,  1121,    -1,  1123,    -1,    -1,
      -1,  1127,    -1,  1129,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    -1,    -1,  1141,  1142,  1143,    -1,    -1,
      -1,     5,   254,   255,   256,   257,    10,  1153,    -1,    -1,
     262,    -1,    -1,    -1,    -1,  1161,  1162,    -1,  1164,  1165,
    1166,   254,   255,   256,   257,    -1,    -1,    31,    -1,   262,
      -1,  1177,  1178,    -1,  1180,    -1,    -1,    -1,  1184,  1185,
    1186,    -1,  1188,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1196,    -1,    -1,    -1,    -1,    -1,  1202,    -1,    -1,  1205,
      -1,   254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,
      -1,  1217,    -1,    -1,  1220,  1221,  1222,    -1,  1224,  1225,
     254,   255,   256,   257,    63,    64,    -1,  1233,   262,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,   105,    -1,   107,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,  1261,    -1,  1263,  1264,  1265,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,
      -1,  1297,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,  1307,    -1,   167,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1320,  1321,    -1,    -1,    -1,  1325,
    1326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1334,  1335,
      -1,   195,   196,   197,    -1,    -1,    -1,   201,   202,   203,
      -1,   205,    -1,   207,   208,   209,    -1,    -1,    -1,    -1,
     214,   215,   216,   217,   218,    -1,    -1,   221,    -1,   223,
      -1,   225,    -1,    -1,   228,    -1,   230,    -1,    -1,   233,
      -1,    -1,   236,   237,    -1,   239,   240,    -1,   242,    -1,
     244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,   262,    63,
      64,    -1,    -1,  1409,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    47,    48,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    58,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,  1503,    -1,    -1,
      -1,    -1,  1508,    -1,    -1,    -1,    -1,  1513,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1544,  1545,
    1546,    -1,  1548,    -1,    -1,    -1,    -1,    -1,   167,  1555,
      -1,    -1,    -1,  1559,  1560,    -1,    -1,    -1,    -1,  1565,
      -1,  1567,  1568,    -1,    -1,    -1,  1572,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1580,    -1,    -1,  1583,  1584,    -1,
    1586,    -1,    -1,  1589,    -1,    -1,    -1,    -1,  1594,    -1,
     254,   255,   256,   257,    63,    64,    -1,    -1,   262,  1605,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1623,    -1,  1625,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1635,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1644,    -1,
    1646,    -1,    -1,    -1,    -1,  1651,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1660,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,  1670,    -1,   262,  1673,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,    63,
      64,   262,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,  1702,  1703,    -1,    -1,
    1706,   254,   255,   256,   257,    -1,    -1,   326,  1714,   262,
      -1,    -1,    -1,   332,    -1,    -1,    -1,  1723,  1724,    -1,
     339,   340,  1728,    -1,    -1,    -1,    -1,  1733,    -1,    -1,
      -1,  1737,   351,   352,   353,   354,   355,   356,   357,    -1,
      -1,   360,   361,   362,   363,    -1,    63,    64,  1754,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1778,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1789,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,  1801,    -1,  1803,    -1,  1805,
      -1,    -1,    -1,    -1,    -1,  1811,    -1,    -1,  1814,    -1,
    1816,    -1,    -1,  1819,  1820,    -1,    -1,  1823,    -1,    -1,
      -1,    -1,    -1,    -1,  1830,    -1,  1832,  1833,  1834,    -1,
      -1,  1837,    -1,    -1,    -1,    -1,    -1,  1843,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,   465,   466,   467,    -1,
    1856,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
    1866,    -1,    -1,    -1,    -1,    -1,    -1,   486,  1874,  1875,
     254,   255,   256,   257,    63,    64,    -1,    -1,   262,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1902,    -1,    -1,  1905,
      63,    64,    -1,  1909,    -1,  1911,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,    -1,  1950,   262,  1952,    -1,    -1,  1955,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1963,    -1,    -1,
    1966,    -1,    -1,    -1,  1970,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1978,    -1,  1980,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,  2002,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2020,    -1,  2022,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,   254,   255,   256,   257,  2045,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,  2054,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,   691,   262,    -1,    -1,   695,    -1,    -1,    -1,
     699,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,   254,   255,   256,   257,   714,   715,    -1,    -1,   262,
      -1,    -1,    81,   722,    -1,    84,    -1,    -1,   727,    -1,
      89,    -1,    -1,   732,    -1,   734,    -1,    -1,    97,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,   746,   107,   748,
      -1,   750,    -1,   752,   753,   754,   115,    -1,    -1,    -1,
      -1,   760,    -1,   122,    -1,    -1,   765,   126,   127,    -1,
      -1,    -1,    -1,    -1,   773,    -1,    -1,   136,    -1,   138,
     139,    -1,   781,    -1,    -1,   144,   145,   146,   147,   148,
     149,   254,   255,   256,   257,    -1,    -1,   156,    -1,   262,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
     169,   170,   171,    -1,    -1,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,    -1,   227,   228,
     229,   230,    -1,   232,   233,    -1,   235,   236,   237,    -1,
     239,   240,   241,   242,   243,   244,   245,    -1,    -1,    -1,
      -1,    -1,   251,   252,    -1,   254,    -1,    -1,    63,    64,
      -1,    -1,   261,    -1,   263,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1040,    -1,    -1,    30,    31,    -1,    -1,    -1,  1048,
      -1,    -1,    -1,    -1,  1053,    -1,  1055,    -1,  1057,  1058,
      -1,    -1,    -1,  1062,  1063,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,    -1,    -1,    81,    -1,   262,    84,    -1,
      -1,    -1,    -1,    89,   254,   255,   256,   257,    -1,    -1,
      -1,    97,   262,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,   254,   255,   256,   257,    -1,    -1,    -1,   115,
     262,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,   254,   255,   256,   257,    -1,    -1,    -1,
     136,   262,   138,   139,    -1,  1154,  1155,    -1,   144,   145,
     146,   147,   148,   149,   254,   255,   256,   257,    -1,    -1,
     156,    -1,   262,   159,    -1,    -1,   162,   163,   164,    -1,
    1179,   167,   168,   169,   170,   171,    -1,    -1,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
      -1,   227,   228,   229,   230,    -1,   232,   233,    -1,   235,
     236,   237,    -1,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,   261,    -1,   263,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     225,    -1,   227,   228,   229,   230,    -1,   232,   233,    -1,
     235,   236,   237,    -1,   239,   240,   241,   242,   243,   244,
     245,    -1,    -1,    -1,    -1,    -1,   251,   252,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,   263,    -1,
      -1,  1540,    -1,    -1,  1543,    -1,    -1,    -1,  1547,    -1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1609,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
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
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,  1800,   254,    -1,    -1,  1804,    -1,    -1,    -1,   261,
     262,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    30,    31,
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
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,   261,
     262,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    30,    31,
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
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,   261,
     262,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,   151,
     152,   153,   154,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,   261,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,    -1,   154,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,   229,   230,    -1,   232,   233,    -1,   235,   236,
     237,    -1,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,    -1,
      -1,     3,     4,     5,   261,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,   151,
      -1,    -1,   154,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,   261,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,   142,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,   229,   230,    -1,   232,   233,    -1,   235,   236,
     237,    -1,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,    -1,
      -1,     3,     4,     5,   261,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,   261,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,
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
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,   229,   230,    -1,   232,   233,    -1,   235,   236,
     237,    -1,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,    -1,
      -1,     3,     4,     5,   261,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,    31,
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
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,   261,
       7,     8,     9,    10,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    30,    31,    -1,    -1,    -1,    -1,    -1,
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
      -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,   229,   230,    -1,   232,   233,    -1,   235,   236,
     237,    -1,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,    -1,
      -1,     3,     4,     5,   261,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,   101,
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
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,   261,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,
      -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,   229,   230,    -1,   232,   233,    -1,   235,   236,
     237,    -1,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,    -1,
      -1,     3,     4,     5,   261,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
     112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
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
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,   261,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    30,    31,    -1,    -1,    34,    -1,    -1,
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
      -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,   229,   230,    -1,   232,   233,    -1,   235,   236,
     237,    -1,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,    -1,
      -1,     3,     4,     5,   261,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,    31,
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
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,   261,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    30,    31,    -1,    -1,    -1,    -1,    -1,
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
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,   229,   230,    -1,   232,   233,    -1,   235,   236,
     237,    -1,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,    -1,
      -1,     3,     4,     5,   261,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,    31,
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
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,   261,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    30,    31,    -1,    -1,    -1,    -1,    -1,
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
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,   229,   230,    -1,   232,   233,    -1,   235,   236,
     237,    -1,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,    -1,
      -1,     3,     4,     5,   261,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,    31,
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
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,   261,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    30,    31,    -1,    -1,    -1,    -1,    -1,
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
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,   229,   230,    -1,   232,   233,    -1,   235,   236,
     237,    -1,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,    -1,
      -1,     3,     4,     5,   261,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,    31,
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
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,   261,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    30,    31,    -1,    -1,    -1,    -1,    -1,
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
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,   229,   230,    -1,   232,   233,    -1,   235,   236,
     237,    -1,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,    -1,
      -1,     3,     4,     5,   261,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,    31,
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
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,   261,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    30,    31,    -1,    -1,    -1,    -1,    -1,
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
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,   229,   230,    -1,   232,   233,    -1,   235,   236,
     237,    -1,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,    -1,
      -1,     3,     4,     5,   261,     7,     8,     9,    10,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,    31,
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
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,    -1,    -1,   167,   168,   169,   170,   171,
      -1,    -1,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,    -1,   227,   228,   229,   230,    -1,
     232,   233,    -1,   235,   236,   237,    -1,   239,   240,   241,
     242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,   251,
     252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,   261,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,
      -1,    -1,   262,    30,    31,    -1,    -1,    -1,    -1,    -1,
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
      -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,   169,   170,   171,    -1,    -1,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,    -1,
     227,   228,   229,   230,    -1,   232,   233,    -1,   235,   236,
     237,    -1,   239,   240,   241,   242,   243,   244,   245,    -1,
      -1,     5,    -1,    -1,   251,   252,    10,   254,    -1,    -1,
      -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,   254,
     255,   256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,   105,    -1,   107,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,    -1,   126,   127,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,    -1,    31,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,    -1,    -1,   167,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   196,   197,    -1,    -1,    -1,   201,   202,   203,
      -1,   205,    -1,   207,   208,   209,    -1,    -1,    -1,    -1,
     214,   215,   216,   217,   218,    -1,    -1,   221,    -1,   223,
     105,   225,   107,    -1,   228,    -1,   230,    -1,    -1,   233,
      -1,    -1,   236,   237,    -1,   239,   240,    -1,   242,     5,
     244,   126,   127,    -1,    10,    -1,    -1,    -1,   252,   254,
     255,   256,   257,    -1,    -1,   260,    -1,   261,   262,   144,
     145,   146,   147,   148,    -1,    31,   254,   255,   256,   257,
      -1,   156,   260,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,    -1,   167,   168,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,    -1,   207,   208,   209,    -1,    -1,    -1,    -1,   214,
     215,   216,   217,   218,    -1,    -1,   221,    -1,   223,   105,
     225,   107,    -1,   228,    -1,   230,    -1,    -1,   233,    -1,
      -1,   236,   237,    -1,   239,   240,    -1,   242,    -1,   244,
     126,   127,    -1,     5,    -1,    -1,    -1,   252,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   261,   262,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    31,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
      -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,
      -1,   207,   208,   209,    -1,    -1,    -1,    -1,   214,   215,
     216,   217,   218,    -1,    -1,   221,    -1,   223,    -1,   225,
      -1,    -1,   228,   105,   230,   107,    -1,   233,    -1,   111,
     236,   237,    -1,   239,   240,    -1,   242,    -1,   244,    -1,
      -1,    -1,    -1,    -1,   126,   127,   252,     5,    -1,    -1,
      -1,    -1,    10,    -1,    -1,   261,   262,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    31,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,    -1,    -1,   167,   168,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   196,   197,    -1,    -1,    -1,   201,
     202,   203,    -1,   205,    -1,   207,   208,   209,    -1,    -1,
      -1,    -1,   214,   215,   216,   217,   218,    -1,    -1,   221,
      -1,   223,    -1,   225,    -1,    -1,   228,   105,   230,   107,
      -1,   233,    -1,   111,   236,   237,    -1,   239,   240,    -1,
     242,    -1,   244,    -1,    -1,    -1,    -1,    -1,   126,   127,
     252,     5,    -1,    -1,    -1,    -1,    10,    -1,    -1,   261,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    31,   156,    -1,
      -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,   197,
      -1,    -1,    -1,   201,   202,   203,    -1,   205,    -1,   207,
     208,   209,    -1,    -1,    -1,    -1,   214,   215,   216,   217,
     218,    -1,    -1,   221,    -1,   223,    -1,   225,    -1,    -1,
     228,   105,   230,   107,    -1,   233,    -1,   111,   236,   237,
      -1,   239,   240,    -1,   242,    -1,   244,    -1,    -1,    -1,
      -1,    -1,   126,   127,   252,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    31,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,    -1,    -1,   167,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   196,   197,    -1,    -1,    -1,   201,   202,   203,
      -1,   205,    -1,   207,   208,   209,    -1,    -1,    -1,    -1,
     214,   215,   216,   217,   218,    -1,    -1,   221,    -1,   223,
      -1,   225,    -1,    -1,   228,   105,   230,   107,    -1,   233,
      -1,   111,   236,   237,    -1,   239,   240,    -1,   242,    -1,
     244,    -1,    -1,    -1,     5,    -1,   126,   127,   252,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,
      31,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   196,   197,    -1,    -1,
      -1,   201,   202,   203,    -1,   205,    -1,   207,   208,   209,
      -1,    -1,    -1,    -1,   214,   215,   216,   217,   218,    -1,
      -1,   221,    -1,   223,   105,   225,   107,    -1,   228,    -1,
     230,    -1,    -1,   233,    -1,    -1,   236,   237,    -1,   239,
     240,    -1,   242,    -1,   244,   126,   127,    -1,     5,    -1,
      -1,    -1,   252,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   261,    -1,   144,   145,   146,   147,   148,    -1,   150,
      -1,    -1,    -1,    -1,    31,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   196,   197,    -1,    -1,    -1,
     201,   202,   203,    -1,   205,    -1,   207,   208,   209,    -1,
      -1,    -1,    -1,   214,   215,   216,   217,   218,    -1,    -1,
     221,    -1,   223,    -1,   225,    -1,    -1,   228,   105,   230,
     107,    -1,   233,    -1,    -1,   236,   237,    -1,   239,   240,
      -1,   242,    -1,   244,    -1,    63,    64,    -1,    -1,   126,
     127,   252,    70,    71,    72,    73,    74,    75,    76,    77,
     261,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,     5,   150,    -1,    -1,    -1,    10,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,
     197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,    -1,
     207,   208,   209,    -1,    -1,    -1,    -1,   214,   215,   216,
     217,   218,    -1,    -1,   221,    -1,   223,    -1,   225,    -1,
      -1,   228,    -1,   230,    -1,    -1,   233,    -1,    -1,   236,
     237,    -1,   239,   240,    97,   242,    -1,   244,    -1,    -1,
      -1,    -1,   105,    -1,   107,   252,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,   261,    70,    71,    72,    73,    74,
      75,    76,    77,   126,   127,    -1,    -1,    -1,    -1,     5,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    31,   159,    -1,    -1,   162,
     163,   164,    -1,    -1,   167,   168,   254,   255,   256,   257,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   196,   197,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,    -1,   207,   208,   209,    -1,    -1,    -1,
      -1,   214,   215,   216,   217,   218,    -1,    -1,   221,    -1,
     223,    97,   225,    -1,    -1,   228,    -1,   230,    -1,   105,
     233,   107,    -1,   236,   237,    -1,   239,   240,    -1,   242,
      -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,     5,   252,
     126,   127,    -1,    10,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,    -1,    31,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
      -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,
      -1,   207,   208,   209,    -1,    -1,    -1,    -1,   214,   215,
     216,   217,   218,    -1,    -1,   221,    -1,   223,   105,   225,
     107,    -1,   228,    -1,   230,    -1,    -1,   233,    -1,    -1,
     236,   237,    -1,   239,   240,    -1,   242,     5,   244,   126,
     127,    -1,    10,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   261,    -1,   144,   145,   146,
     147,   148,    -1,    31,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,
     197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,    -1,
     207,   208,   209,    -1,    -1,    -1,    -1,   214,   215,   216,
     217,   218,    -1,    -1,   221,    -1,   223,   105,   225,   107,
      -1,   228,    -1,   230,    -1,    -1,   233,    -1,    -1,   236,
     237,    -1,   239,   240,    -1,   242,    -1,   244,   126,   127,
      -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   261,    -1,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,
     168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,   197,
      -1,    -1,    -1,   201,   202,   203,    -1,   205,    -1,   207,
     208,   209,    -1,    -1,    -1,    -1,   214,   215,   216,   217,
     218,    -1,    -1,   221,    -1,   223,    -1,   225,    -1,    -1,
     228,    -1,   230,    -1,    -1,   233,    -1,    -1,   236,   237,
      -1,   239,   240,    -1,   242,    -1,   244,    -1,    -1,     4,
       5,     6,    -1,    -1,   252,    -1,    11,    -1,    -1,    -1,
      15,    -1,    17,   261,    19,    20,    21,    22,    23,    24,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,    94,
      95,    96,    -1,    98,    99,   100,    -1,    -1,   103,   104,
      -1,   106,    -1,   108,   109,    -1,    -1,    -1,    -1,   114,
     115,    -1,    -1,    -1,    -1,    -1,   121,    -1,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    -1,    -1,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,
     165,   166,    -1,    -1,   169,   170,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,   197,    -1,    -1,    -1,    -1,   202,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   222,    -1,    -1,
      -1,   226,    -1,     4,     5,     6,   231,    -1,    -1,   234,
      11,    -1,    -1,   238,    15,    -1,    17,    -1,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    -1,    -1,    94,    95,    96,    -1,    98,    99,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,   108,   109,    -1,
      -1,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,
     121,    -1,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    -1,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   157,   158,   159,    -1,
      -1,    -1,    -1,   164,   165,   166,    -1,    -1,   169,   170,
     171,   254,   255,   256,   257,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   196,   197,    -1,    -1,    -1,
      -1,   202,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,   222,    -1,    -1,    -1,   226,    -1,     4,     5,     6,
     231,    -1,    -1,   234,    11,    -1,    -1,   238,    15,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    38,    -1,    -1,    -1,    42,    43,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    63,    64,    -1,    61,    62,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    -1,    -1,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,   108,   109,    -1,    -1,    -1,    -1,   114,   115,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,   166,
      -1,    -1,   169,   170,   171,   254,   255,   256,   257,    63,
      64,   260,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,   195,   196,
     197,    63,    64,    -1,    -1,   202,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,   226,
      -1,    -1,    -1,    -1,   231,    63,    64,   234,    -1,    -1,
      -1,   238,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,   254,   255,   256,   257,    63,    64,   260,    -1,
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
     254,   255,   256,   257,    63,    64,   260,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,   254,   255,   256,   257,    63,    64,   260,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   254,   255,   256,   257,
      63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    63,
      64,   260,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    63,    64,   260,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,   254,   255,   256,   257,    63,    64,   260,    -1,    -1,
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
      -1,    -1,   254,   255,   256,   257,    63,    64,   260,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    63,    64,   260,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,   254,   255,   256,
     257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   254,   255,   256,   257,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
      63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   254,   255,   256,
     257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    63,    64,   260,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,   254,   255,   256,   257,    63,    64,   260,    -1,
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
      77,   254,   255,   256,   257,    63,    64,   260,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,   254,   255,   256,   257,    63,    64,   260,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    63,
      64,   260,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   254,   255,   256,   257,
      63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    63,    64,   260,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    63,    64,   260,    -1,    -1,    -1,
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
      -1,    -1,   254,   255,   256,   257,    63,    64,   260,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,   254,   255,   256,   257,    63,    64,   260,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   254,   255,   256,
     257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    63,
      64,   260,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,   254,   255,   256,
     257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   254,   255,   256,   257,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,   256,   257,    63,    64,   260,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,   254,   255,   256,   257,    63,    64,   260,    -1,
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
     254,   255,   256,   257,    63,    64,   260,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,   254,   255,   256,   257,    63,    64,   260,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   254,   255,   256,   257,
      63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    63,
      64,   260,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    63,    64,   260,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,   254,   255,   256,   257,    63,    64,   260,    -1,    -1,
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
      -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
      -1,    -1,   260
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   246,   247,   248,   249,   250,   265,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   114,   115,
     121,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     144,   145,   146,   147,   148,   149,   156,   157,   158,   159,
     164,   165,   166,   169,   170,   171,   195,   196,   197,   202,
     222,   226,   231,   234,   238,   266,   267,   270,   271,   278,
     279,   281,   282,   286,   298,   299,   304,   310,   317,   325,
     333,   336,   340,   343,   349,     3,     4,     5,     7,     8,
       9,    10,    30,    31,    63,    64,    65,    66,    67,    68,
      69,    81,    84,    89,   101,   102,   105,   107,   115,   122,
     126,   127,   136,   138,   139,   144,   145,   146,   147,   148,
     149,   156,   159,   162,   163,   164,   167,   168,   169,   170,
     171,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   227,   228,   229,   230,   232,   233,   235,
     236,   237,   239,   240,   241,   242,   243,   244,   245,   251,
     252,   254,   261,   284,   285,   287,   293,   295,   298,   299,
     144,   145,   146,   147,   164,   261,   284,   270,   298,   299,
     304,     0,    75,   261,    75,   261,   318,   337,   341,     4,
       7,   296,   296,   296,    34,   287,   272,   273,   284,   300,
     301,   300,   284,    28,     7,   326,   334,   287,    58,    60,
      61,   263,   380,   276,   284,   287,     4,     5,   297,   287,
     284,   287,   284,   287,     4,     5,   360,   361,    10,   254,
     255,   294,   295,   362,   296,    89,    97,   263,   284,   287,
     381,    89,    97,   110,   381,   381,    81,    82,    88,   111,
     287,   292,    12,    53,   292,   111,   292,    59,    89,    90,
      91,    96,    95,   287,   279,   286,   284,   284,   284,   110,
     292,    90,    91,    92,    93,    94,   104,   110,   111,   116,
     117,   118,   119,   120,   165,   292,   292,   111,   292,   111,
     292,    95,   111,   292,    61,    95,   111,   142,   292,   292,
      22,    61,   111,   292,   111,   292,   111,   292,   111,   284,
     284,   284,    61,   111,   111,   142,   143,   292,   111,   292,
     111,   292,   111,   292,   292,   292,    95,   142,   143,   151,
     154,   292,    95,   142,   143,   154,   292,    95,   142,   143,
     151,   152,   153,   154,   292,    61,    95,   142,   143,   150,
     154,   292,   111,   292,   111,   292,   111,   284,   111,   284,
     111,   284,   160,    95,   111,   112,   143,   287,   284,    98,
     173,   173,   111,   261,   261,   261,   261,   261,   284,   381,
     284,   284,   284,    44,   268,    92,    93,   104,    75,    75,
      24,   261,   261,   261,   261,   287,   261,   261,   261,   261,
     261,   261,   112,   113,   261,   261,   261,   261,   112,   261,
     112,   155,   112,   155,   112,   112,   112,   112,   113,   155,
     112,   113,   155,   112,   113,   155,   112,   113,   155,   112,
     112,   162,   161,   261,   112,   155,   284,   292,   172,   172,
     112,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   287,   284,   287,    70,    71,    72,    73,    74,    75,
      76,   255,    44,    63,    64,    70,    71,    72,    73,    74,
      75,    76,    77,   254,   255,   256,   257,   284,    44,    44,
      44,   287,   300,   284,   300,     4,   287,   267,    35,    36,
      20,    21,     4,     5,   311,   312,     4,     5,   313,   314,
     284,   287,   302,   303,   284,   287,   328,   267,   344,   350,
     261,    58,   261,     4,     7,   261,   284,   287,   363,    58,
      60,    61,   263,   365,   378,   261,   261,   260,   260,   260,
     261,   261,   260,   295,   295,   260,   287,   284,   287,    11,
     260,   260,   292,   284,   284,   284,   260,   292,   277,    12,
     260,   280,   284,   260,   292,    12,   292,   280,   280,   280,
     292,   292,   292,   292,   292,   292,   292,   284,   284,   292,
     292,   292,   292,   287,   280,   280,   284,   260,   284,   260,
     284,   284,   280,   284,   284,   284,   284,   280,   260,   284,
     284,   284,   280,   284,   280,   284,   260,   284,   260,   260,
     260,   284,   284,   284,   284,   284,   280,   284,   280,   284,
     280,   284,   280,   280,   280,   284,   284,   284,   284,   284,
     280,   284,   284,   284,   284,   280,   284,   284,   284,   284,
     284,   284,   284,   280,   284,   284,   284,   150,   284,   284,
     284,   280,   284,   260,   284,   260,   284,   260,   284,   260,
     284,   260,   284,   284,   284,   284,   284,   260,   260,   287,
     287,   287,   287,     5,   283,   283,   283,   262,   287,   284,
     260,   260,   260,   260,    43,   292,   292,   292,   287,   284,
     305,   300,   300,   287,   287,   287,   287,   287,   287,    97,
     284,   381,   381,   284,     4,     5,   290,   291,   290,   291,
     292,   287,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   150,   284,   284,   284,   284,   261,   284,   261,   261,
     260,   260,   284,   284,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   381,   287,   287,   287,   287,   287,
     287,   287,   287,   262,   287,   284,   284,   284,   284,   284,
     287,   287,   284,   287,   262,   287,   287,   284,   287,   284,
     287,   284,   284,   262,   284,   262,   284,   262,   284,   262,
     284,   284,   284,   284,   287,   284,   284,   284,   284,   284,
     284,   284,   381,   284,   300,   300,   284,   287,   284,   284,
     284,   284,   284,   262,   262,   284,   283,   284,   283,   284,
     284,   284,   262,   262,   284,   284,   284,   284,   284,   284,
     284,   284,   289,   288,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   262,   262,    75,   338,
      14,    16,    18,    41,    44,    49,   342,   274,   275,   261,
     261,   260,   261,   261,   260,   260,    43,   327,    14,    16,
      18,    41,    44,    49,   335,    46,   267,   287,   261,   284,
     287,    51,   364,   259,   260,   261,    58,   261,     4,     7,
     261,    10,   379,   300,   300,     4,     5,   287,   287,   300,
     300,   361,    10,   294,   260,    86,    87,    97,   284,   287,
     280,   260,   287,   365,   292,   260,   284,   292,   280,   287,
     287,   292,   260,   280,   260,   280,   260,   280,   280,   260,
     260,   260,   280,   280,   260,   292,   292,   260,   284,   260,
     284,   260,   292,   260,   260,   260,   292,   284,   260,   260,
     260,   292,   260,   292,   260,   284,   260,   287,   284,   284,
     260,   260,   260,   260,   260,   292,   260,   292,   260,   292,
     260,   292,   292,   292,   260,   260,   260,   292,   260,   260,
     260,   292,   260,   260,   260,   260,   260,   292,   260,   260,
     284,   260,   260,   260,   292,   260,   284,   260,   284,   260,
     284,   260,   284,   260,   284,   260,   260,   260,   287,   284,
     261,   260,   260,   260,   262,   262,   284,   287,   284,   287,
     287,   287,   269,   260,   280,   280,     4,     5,   309,   262,
     262,   260,   260,   262,   260,   260,   260,   262,   260,   262,
     260,   262,   260,   261,   261,   262,   262,   260,   260,   280,
     260,   260,   262,   260,   260,   260,   260,   284,   260,   260,
     284,   262,   284,   284,   284,   284,   260,   262,   262,   262,
     262,   262,   260,   262,   262,   260,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   260,   262,   262,
     260,   260,   260,   262,   260,   260,   262,   260,   262,   262,
     262,   262,   262,   260,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   260,   260,   260,   260,   262,
     262,   262,   262,   262,   260,   262,   262,   262,   262,   262,
     262,   260,   262,   260,   260,   260,   260,   260,   262,   260,
     260,   262,   260,   262,   262,   287,   287,   319,   267,   287,
     296,   382,   296,   383,   300,   300,   312,   300,   300,   314,
     303,    43,   329,   345,    49,    50,   351,   260,   287,   260,
     262,   262,   261,   284,   284,   287,   287,   261,   284,   366,
     367,   287,     4,     5,   357,   359,   262,   262,   261,   261,
     260,   260,   262,   262,   287,    85,    85,   260,   260,   292,
     284,   284,   260,   292,   260,   260,   260,   284,   292,   287,
     292,   284,   292,   292,   284,   287,   287,   287,   292,   292,
     287,   260,   260,   287,   260,   287,   260,   284,   287,   260,
     284,   284,   284,   260,   260,   284,   284,   284,   287,   260,
     284,   260,   287,   260,   284,   260,   284,   284,   287,   284,
     287,   260,   284,   260,   284,   260,   287,   260,   260,   260,
     284,   287,   284,   287,   287,   260,   284,   287,   287,   260,
     284,   284,   287,   284,   284,   287,   260,   284,   287,   260,
     287,   284,   287,   260,   284,   260,   287,   260,   284,   287,
     260,   284,   260,   284,   260,   284,   284,   284,   260,   260,
     300,   287,   287,   287,   260,   260,   271,   287,   292,   292,
     306,   287,   287,   287,   287,   287,   284,    97,   284,   284,
     262,   262,   287,   287,   292,   287,   284,   284,   287,   287,
     287,   287,   284,   262,   260,   260,   260,   260,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   284,   287,   284,
     284,   284,   284,   284,   287,   287,   287,   287,   291,   284,
     291,   284,   284,   287,    16,    44,   339,   260,   260,   262,
     262,   262,   262,    39,    40,   331,   267,   287,   260,   284,
      58,   284,   364,   260,   287,   260,   262,   357,   357,   262,
     261,   261,   260,   300,   300,   287,   287,   260,   381,   381,
     284,   284,   260,   260,   284,   287,   287,   284,   260,   260,
     280,   260,   260,   280,   260,   260,   260,   280,   260,   260,
     284,   284,   284,   284,   284,   260,   284,   284,   260,   260,
     260,   284,   260,   284,   284,   260,   284,   260,   260,   284,
     260,   284,   260,   284,   284,   284,   284,   260,   284,   284,
     260,   260,   284,   260,   260,   287,   260,   284,   284,   260,
     284,   260,   260,   284,   260,   284,   260,   284,   260,   260,
     284,   284,   262,   262,   262,   260,   262,   284,   284,   280,
     261,   262,   262,   262,   262,   262,   262,   262,   260,   262,
     262,   262,   262,   280,   260,   260,   284,   284,   284,   284,
     262,   262,   262,   262,   262,   260,   262,   262,   262,   260,
     262,   262,   262,   260,   260,   262,   260,   262,   262,   262,
     260,   260,   262,   260,   262,   262,   260,   262,   262,   262,
      12,   296,   296,   328,    43,    38,   346,   262,   287,   262,
     261,   260,   287,   260,   284,    58,   373,   368,   300,   300,
     358,   262,   262,   284,   284,   284,   260,   260,   260,   284,
     284,   292,   284,   284,   292,   287,   287,   287,   292,   287,
     284,   260,   260,   260,   260,   287,   260,   260,   284,   287,
     287,   260,   284,   260,   260,   287,   287,   284,   287,   260,
     284,   260,   287,   260,   260,   260,   260,   284,   260,   260,
     284,   287,   284,   260,   287,   287,   287,   260,   260,   287,
     284,   284,   260,   284,   287,   260,   284,   260,   284,   284,
      75,    75,   287,    75,   260,   292,     4,     5,   315,   316,
     284,   287,   284,   287,   262,   262,   287,   284,   284,   287,
     287,   284,   287,   284,   284,   287,   330,   332,    48,   353,
      60,    61,   262,    58,   287,   284,   262,   287,   262,   261,
     379,   357,   262,   262,   357,   260,   284,   284,   284,   260,
     280,   260,   260,   260,   280,   260,   260,   284,   287,   287,
     284,   260,   287,   284,   260,   284,   260,   284,   287,   260,
     260,   284,   284,   260,   287,   287,   284,   284,   287,   284,
     260,   287,   260,   260,   260,   287,   284,   260,   260,   284,
     260,   260,   284,   260,   284,   260,   284,   284,   262,   284,
     287,   261,   261,   260,   262,   262,   260,   262,   262,   262,
     262,   262,   262,   262,   262,   262,    13,   323,   267,   267,
     287,    47,   352,   261,   261,   260,   262,    60,    61,   369,
     262,    58,   374,   287,   357,   284,   284,   292,   287,   284,
     287,   292,   287,   284,   260,   260,   260,   260,   287,   260,
     260,   287,   260,   287,   260,   260,   287,   287,   260,   260,
     287,   260,   260,   260,   260,   287,   260,   287,   287,   287,
     260,   260,   287,   284,   284,   284,   260,   284,   287,   260,
     284,    75,   262,   262,   316,   307,   287,   287,   320,    46,
     356,   267,   347,   284,   287,   287,   375,   261,   379,   370,
     261,   379,   260,   260,   260,   260,   260,   260,   260,   284,
     284,   284,   284,   260,   284,   284,   260,   287,   284,   287,
     260,   284,   287,   287,   284,   284,   284,   284,   260,   260,
     260,   284,   284,   260,   284,   260,   260,   284,   284,   267,
     262,   267,   354,    14,    16,    18,    41,    44,    49,   348,
     260,   262,   260,   262,   379,   284,   357,   379,   287,   357,
     287,   284,   284,   287,   284,   284,   284,   260,   287,   287,
     260,   260,   260,   287,   260,   260,   287,   284,   287,   260,
     284,   284,   284,   260,    25,    44,   308,   321,   267,   284,
     287,   357,   260,   262,   357,   260,   262,   260,   284,   287,
     284,   287,   284,   284,   260,   284,   260,   284,    14,    16,
      18,    41,    44,    49,   322,   355,   262,   262,   284,   376,
     287,   371,   284,   260,   260,   287,   284,     4,   324,   353,
     262,   379,   262,   379,   284,   284,   260,   377,   357,   372,
     357,   260,   284,   379,   379,   284,   357,   357
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   264,   265,   265,   265,   265,   265,   266,   267,   268,
     269,   267,   270,   270,   270,   270,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   272,   271,   273,   271,   271,   271,   271,   271,   271,
     271,   274,   271,   275,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   276,   271,   277,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   278,   278,   278,   278,   278,   279,   279,   279,
     279,   279,   279,   280,   280,   281,   281,   281,   281,   281,
     282,   282,   283,   283,   284,   284,   284,   284,   284,   284,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   286,
     286,   288,   287,   289,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   290,   291,   292,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   294,   294,   294,   295,   295,   295,   295,
     296,   296,   297,   297,   297,   297,   298,   299,   301,   300,
     302,   302,   302,   303,   303,   305,   306,   307,   304,   308,
     308,   309,   309,   310,   310,   310,   310,   311,   311,   312,
     312,   312,   312,   313,   313,   314,   314,   314,   314,   315,
     315,   315,   316,   316,   316,   316,   318,   319,   320,   321,
     317,   322,   322,   322,   322,   322,   322,   323,   323,   324,
     324,   326,   325,   327,   327,   328,   328,   329,   330,   329,
     331,   332,   331,   334,   333,   335,   335,   335,   335,   335,
     335,   337,   338,   336,   339,   339,   341,   340,   342,   342,
     342,   342,   342,   342,   344,   345,   346,   347,   343,   348,
     348,   348,   348,   348,   348,   350,   349,   351,   351,   352,
     352,   353,   354,   355,   353,   356,   356,   357,   358,   357,
     359,   359,   359,   359,   360,   360,   361,   361,   361,   361,
     362,   362,   362,   362,   363,   363,   363,   363,   363,   364,
     364,   364,   366,   365,   367,   365,   368,   365,   369,   365,
     370,   365,   371,   365,   372,   365,   373,   365,   374,   365,
     375,   365,   376,   365,   377,   365,   378,   365,   379,   379,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   381,   381,   382,   382,   383,   383
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
       3,     3,     6,     6,     3,     3,     5,     5,     5,     7,
       3,     4,     5,     2,     1,     7,     6,     6,     4,     6,
       4,     6,    10,     4,     4,     4,     8,     6,     4,     3,
       3,     0,     4,     0,     4,     2,     3,     3,     3,     3,
       3,     3,     3,     4,     6,     1,     4,     4,     6,     6,
       1,     1,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       4,     4,     4,     4,     4,     4,     6,     4,     4,     6,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       4,     3,     6,     6,     4,     4,     4,     4,     6,     6,
       8,     6,     8,     4,     4,     4,     8,     4,     4,     4,
       4,     1,     3,     4,     1,     3,     4,     1,     3,     4,
       1,     3,     6,     6,     4,     6,     6,     6,     4,     8,
       6,     8,     6,     4,     4,     4,     6,     6,     6,     8,
       4,     2,     5,     7,     5,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     5,     5,     3,     3,
       5,     7,     4,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     4,     6,     4,     6,     4,     4,     0,     2,
       0,     1,     3,     1,     1,     0,     0,     0,    11,     1,
       1,     1,     1,     0,     1,     1,     2,     1,     3,     1,
       1,     4,     4,     1,     3,     1,     1,     4,     4,     0,
       1,     3,     1,     1,     3,     3,     0,     0,     0,     0,
      14,     1,     1,     1,     1,     1,     1,     0,     2,     0,
       1,     0,     7,     1,     2,     1,     1,     0,     0,     5,
       0,     0,     4,     0,     4,     1,     1,     1,     1,     1,
       1,     0,     0,     6,     1,     1,     0,     4,     1,     2,
       1,     1,     1,     1,     0,     0,     0,     0,    11,     1,
       1,     1,     1,     1,     1,     0,     5,     1,     1,     0,
       2,     0,     0,     0,     7,     0,     1,     1,     0,     4,
       1,     4,     1,     4,     1,     3,     1,     4,     1,     4,
       1,     1,     3,     3,     0,     2,     4,     1,     3,     0,
       2,     6,     0,     4,     0,     4,     0,     6,     0,     9,
       0,    10,     0,    13,     0,    15,     0,     7,     0,     9,
       0,    10,     0,    13,     0,    15,     0,     3,     0,     1,
       0,     2,     2,     4,     1,     4,     6,     6,     7,    10,
      12,     7,    10,    12,     2,     1,     1,     3,     1,     3
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

  case 303: /* string_function: tFILEPANEL string_expression ',' string_expression ',' string_expression  */
                                                                                             {create_function(fYABFILEPANELLOAD);}
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

  case 315: /* string_function: tATTRIBUTE tGETS '(' string_expression ',' string_expression ')'  */
                                                                     {create_function(fYABATTRIBUTEGET);}
    break;

  case 316: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 317: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 318: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 319: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 320: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 321: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 322: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 323: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 324: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 325: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 326: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 327: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 328: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 329: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 330: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 331: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 332: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 333: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 334: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 335: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 336: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 337: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 338: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 339: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 340: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 341: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 342: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 343: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 344: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 345: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 346: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 347: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 348: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 349: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 350: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 351: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 352: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 353: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 354: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 355: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 356: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 357: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 358: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 359: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 360: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 361: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 362: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 363: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 364: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 367: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 368: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 370: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 371: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 372: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 373: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 374: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 375: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 376: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 377: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 378: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 379: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 380: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 381: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 382: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 383: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 384: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 385: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 386: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 387: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 388: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 389: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 390: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 391: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 392: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 393: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 394: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 395: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 396: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 397: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 398: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 399: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 400: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 401: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 402: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 403: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 404: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 405: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 406: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 407: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 408: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 409: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 410: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 411: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 412: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 413: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 414: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 415: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 416: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 417: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 418: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 419: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 420: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 421: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 422: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 423: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 424: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 425: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 426: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 427: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 428: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 429: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 430: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 431: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 432: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 433: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 434: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 435: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 436: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 437: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 438: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 439: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 440: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 441: /* function: tWINDOW tCOUNT  */
                   {create_function(fYABNUMWINDOWS);}
    break;

  case 442: /* function: tWINDOW tGET string_expression ',' string_expression  */
                                                         {create_function(fYABWINDOWGET);}
    break;

  case 443: /* function: tATTRIBUTE tGET '(' string_expression ',' string_expression ')'  */
                                                                    {create_function(fYABATTRIBUTEGETNUM);}
    break;

  case 444: /* function: tSOUND tPLAY string_expression ',' expression  */
                                                                  {create_function(fYABSOUNDPLAY);}
    break;

  case 445: /* function: tMEDIASOUND tPLAY string_expression  */
                                                        {create_function(fYABMEDIASOUNDPLAY);}
    break;

  case 446: /* function: tLOUDNESS tGET  */
                   {create_function(fYABLOUDNESSGET);}
    break;

  case 447: /* function: tLISTBOX tCOUNT string_expression  */
                                                      {create_function(fYABLISTBOXCOUNT);}
    break;

  case 448: /* function: tLISTBOX tGET string_expression  */
                                                    {create_function(fYABLISTBOXSELECTED);}
    break;

  case 449: /* function: tDROPBOX tCOUNT string_expression  */
                                                      {create_function(fYABDROPBOXCOUNT);}
    break;

  case 450: /* function: tDROPBOX tGET string_expression  */
                                                    {create_function(fYABDROPBOXSELECTED);}
    break;

  case 451: /* function: tTREEBOX tCOUNT string_expression  */
                                                      {create_function(fYABTREEBOXCOUNT);}
    break;

  case 452: /* function: tTREEBOX tGET string_expression  */
                                                    {create_function(fYABTREEBOXSELECTED);}
    break;

  case 453: /* function: tCOLUMNBOX tCOUNT string_expression  */
                                                        {create_function(fYABCOLUMNBOXCOUNT);}
    break;

  case 454: /* function: tCOLUMNBOX tCOUNT tCOLUMN string_expression  */
                                                                {create_function(fYABCOLUMNBOXCOUNTCOLUMNS);}
    break;

  case 455: /* function: tCOLUMNBOX tGET string_expression  */
                                                      {create_function(fYABCOLUMNBOXSELECTED);}
    break;

  case 456: /* function: tCOLORCONTROL tGET string_expression ',' string_expression  */
                                                                               {create_function(fYABCOLORCONTROLGET);}
    break;

  case 457: /* function: tSPLITVIEW tGET string_expression ',' string_expression  */
                                                                            {create_function(fYABSPLITVIEWGET);}
    break;

  case 458: /* function: tSTACKVIEW tGET string_expression  */
                                                      {create_function(fYABSTACKVIEWGET);}
    break;

  case 459: /* function: tTABVIEW tGET string_expression  */
                                                    {create_function(fYABTABVIEWGET);}
    break;

  case 460: /* function: tDRAW tGET string_expression ',' string_expression  */
                                                       {create_function(fYABDRAWGET);}
    break;

  case 461: /* function: tDRAW tGET string_expression ',' string_expression ',' string_expression  */
                                                                             {create_function(fYABDRAWGETTEXT);}
    break;

  case 462: /* function: tBFILESIZE '(' string_expression ')'  */
                                         {create_function(fYABBFILESIZE);}
    break;

  case 463: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 464: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 465: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 466: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 467: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 468: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 469: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 470: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 471: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 472: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 473: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 474: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 475: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 476: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 477: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 478: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 485: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 486: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 487: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 488: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 489: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 490: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 491: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 492: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 493: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 494: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 495: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 496: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 499: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 500: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 501: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 502: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 505: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 506: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 507: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 508: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 512: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 513: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 514: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 515: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 516: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 517: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 518: /* $@17: %empty  */
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

  case 519: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 520: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 521: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 522: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 523: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 524: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 525: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 526: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 527: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 529: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 530: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 531: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 532: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 538: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 539: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 541: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 543: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 545: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 546: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 547: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 548: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 549: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 550: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 551: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 552: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 554: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 555: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 556: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 558: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 559: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 560: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 561: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 562: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 563: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 564: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 565: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 566: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 567: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 569: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 570: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 571: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 572: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 573: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 574: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 575: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 577: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 578: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 582: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 583: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 588: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 590: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 591: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 592: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 593: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 596: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 597: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 598: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 599: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 600: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 601: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 602: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 603: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 607: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 608: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 609: /* using: %empty  */
       {create_print('d');}
    break;

  case 610: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 611: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 612: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 613: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 614: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 615: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 616: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 617: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 618: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 619: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 620: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 621: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 622: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 623: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 624: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 625: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 626: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 627: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 628: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 629: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 630: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 631: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 632: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 633: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 634: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 635: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 636: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 637: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 638: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 639: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 640: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 641: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 642: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 643: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 644: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 645: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 646: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 647: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 648: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 649: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 650: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 651: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 652: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 653: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 656: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 657: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 658: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 659: /* gosub_list: gosub_list ',' symbol_or_lineno  */
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

