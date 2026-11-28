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
#define YYLAST   16162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  264
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  659
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2100

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
     581,   582,   585,   592,   596,   597,   598,   599,   600,   601,
     602,   603,   604,   605,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   626,
     627,   630,   630,   631,   631,   632,   633,   634,   635,   636,
     637,   638,   639,   640,   641,   642,   643,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   666,   669,   672,
     675,   676,   677,   678,   679,   680,   681,   682,   683,   684,
     685,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   731,   732,   733,   734,
     735,   736,   737,   738,   739,   740,   741,   742,   743,   744,
     745,   748,   749,   752,   756,   757,   758,   761,   762,   763,
     764,   765,   766,   767,   768,   769,   770,   771,   772,   773,
     774,   775,   776,   779,   780,   781,   784,   785,   786,   787,
     790,   791,   794,   795,   796,   797,   800,   803,   806,   806,
     809,   810,   811,   814,   815,   818,   819,   822,   818,   827,
     828,   831,   832,   835,   836,   837,   838,   841,   842,   845,
     846,   847,   848,   851,   852,   855,   856,   857,   858,   861,
     862,   863,   866,   867,   868,   869,   872,   873,   878,   893,
     872,   898,   899,   900,   901,   902,   903,   906,   907,   910,
     911,   916,   916,   920,   921,   924,   925,   929,   931,   930,
     935,   936,   936,   940,   940,   946,   947,   948,   949,   950,
     951,   955,   956,   955,   962,   963,   967,   967,   972,   973,
     974,   975,   976,   977,   980,   981,   981,   983,   980,   987,
     988,   989,   990,   991,   992,   995,   995,  1000,  1001,  1004,
    1005,  1008,  1010,  1012,  1009,  1016,  1017,  1020,  1021,  1021,
    1024,  1025,  1027,  1028,  1032,  1033,  1036,  1037,  1039,  1040,
    1044,  1045,  1046,  1047,  1050,  1051,  1052,  1053,  1054,  1057,
    1058,  1059,  1062,  1062,  1063,  1063,  1064,  1064,  1065,  1065,
    1066,  1066,  1067,  1067,  1068,  1068,  1069,  1069,  1070,  1070,
    1071,  1071,  1072,  1072,  1073,  1073,  1074,  1074,  1077,  1078,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,  1097,  1098,  1100,  1101,  1104,  1105
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

#define YYPACT_NINF (-1644)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-565)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     565, 13510, 11314, 12924,    21,    95,    27,   -59,   -55, -1644,
   -1644, -1644, -1644, -1644,   101,   101,   101,  8254, -1644, -1644,
   -1644, 12924, -1644, -1644, 12924,    30,    41, -1644, -1644, -1644,
   11314,   -14, -1644, 11314,   138, -1644, 11314, 11314, 11314,   217,
      33,   101,  3761,  2414,  4395,   192, 11314,  7234,  8509,   146,
      64, 11314, -1644,    98, 12924, 12924, 12924,   -28, 11314,  1493,
   11314, 11314,  8764,  9019,  7489,  6214, 11314,  6724,  9274,  9529,
   11919, 12924, 12924,   -24,  6979,  9784, 10039, 10294, 11314, 11314,
    5959,  6469,  5449,  5704, 10549, 10804, 12043, 12167, 12291,   -38,
     -25,  7744, 12924,   -85,   -17,    15,   -80,   -77,    24,    73,
      75,  4395, 12924, 12924, 12924, -1644,   149, -1644, -1644,   127,
   -1644, -1644, -1644, -1644,   179,   195, -1644,   252, -1644, -1644,
   -1644, -1644, -1644, -1644, -1644, -1644,    81,   100, -1644, -1644,
   -1644, -1644,   123,   137,   141,   160, 11314,   177,   186,   219,
     248,   251,   274,   210,   288,   300,   329,   350,   169,   356,
     -83,    48,   187,   199,   232,    -2,     7,    17,    28,   247,
     264,   224,   227,   366, -1644,    49, 12924, 11314,   312,   355,
     341,   370,   385,   393,   417,   431,   454,   465,   468,   490,
     512,   520,   522,   524,   528,   567,   568,   569,   598,   599,
     620,   621,   622,   633,   634,   635,   670,   700,   701,   702,
     703,   704,   723,   725,   726,   727,   763,   764,   776,   778,
     791,   793,   803,   804,   819,   820,   821,   831,   853,   855,
     856,   864,   866,   868,   870,   899,   903,   909,   910,   911,
     912,   930,   941,   958,   979,   980,   987,   988,   989,   991,
    1001, 11314, 11314,   458, -1644,   647, -1644, -1644, -1644, -1644,
     433,   450,   452,   460,   690, 12924,   -40,   883,   179,   195,
     966, -1644, 11314, -1644, 12924, -1644,   904, 11314, 13286, -1644,
   -1644, -1644, -1644, -1644,   365,   623,   451,   464,   642, -1644,
   11314, -1644,   642, -1644, -1644, 11314, 13286,   684,  1013,   852,
    1014,     2, 11314,    16,   458,  2300,  1021,  1022,   747,  2300,
     458,  1477,   458,  2253,  1024,  1025,   846, -1644, -1644,   259,
     259, -1644, -1644,   886, -1644,  7999, 12924, 11314,    20,  2300,
     888,   210, -1644, -1644, -1644,   921, 11314, 12924, 12924, 12924,
   11556, -1644, 11314, -1644,     5, 12924,   939, -1644, -1644, 11314,
   11059, -1644, -1644,  2300, -1644, -1644,   642,    -5,    -5, -1644,
       5, 11314, 11314, 11314, 11314, 11314, 11314, 11314, 12924, 12924,
   11314, 11314, 11314, 11314, 11314,     5,     5, 12924,  1035, 12924,
    1038, 12924, 12924,     5, 12924, 12924, 12924, 12924,     5,  1042,
   12924, 12924, 12924,     5, 12924,     5, 12924,  1044, 12924,  -116,
     -47,    -7, 12924, 12924, 12924, 12924, 12924,     5, 12924,     5,
   12924,     5, 12924,     5,     5,     5, 12924, 12924, 12924, 12924,
   12924,     5, 12924, 12924, 12924, 12924,     5, 12924, 12924, 12924,
   12924, 12924, 12924, 12924,     5, 12924, 12924, 12924, 12410, 12924,
   12924,     5, 12924,  1059, 12924,  1070, 12924,    -4, 12924,   102,
   12924,   223, 12924, 12924, 12924, 12924, 12924, 12593,   253, 11314,
   11314, 11314, 11314,  1036,  1036,  1036,  4669, 12924,   115,  1072,
     642,   324,   375, -1644,  1158, 11314, 11314, 11314, 11314, 12924,
   -1644, -1644, -1644, 11314, 11314,   692, 11314, 11314, 11314, 11314,
    4134,  4395, 12924, -1644,   477,   477, 11314, 11314, 12924, 12924,
   12924, 12924, 12924, 12924, 12924, 12924, 12924, 12924, 12924, 12924,
   12924, 12924, 12924, 12924, 12924, 12924, 12924, 12534, 12924, 12924,
   12924,  1082, -1644, 12924,  1083,  1085,   446,  1095, 12924, 12924,
   -1644, 11314, 11314, 11314, 11314, 11314, 11314, 11314, 11314, 11314,
   11314,  4395, 11314, 11314, 11314, 11314, 11314, 11314, 11314, 11314,
    4929, 12924, 12924, 12924, 12924, 12924, 11314, 11314, 11314,  5189,
   11314, 12924, 11314, 12924, 11314, 12924, 12924,  2876, 11557, 11676,
   11795, 12924, 12924, 12924, 11314, 12924, 12924, 12924, 12924, 12924,
   12924,  4395, 12924, -1644, -1644, 12924, 11314, 12924, 12924, 12924,
   12924, 12924,  1111,  1113, 12924,  1036, 12924,  1036, 12924, 12924,
   12924,  1162,    42,   842, 12924, 12924, 12924, 12924, 12924, 12924,
   12924, 12924, -1644, -1644, -1644, 11314, 11314, 11314, 11314, 11314,
   11314, 11314, 11314, 11314, 11314, 11314, 11314,  -217, -1644, -1644,
   -1644,  2300,  1115,   642,  1117,  1290,  2300,   418, -1644, -1644,
   -1644, -1644,  1120,  1122,  1138, -1644,  1195,  1205,  1147, -1644,
     458,  2300,  1174, -1644,   458,  2300,  1415,   893,  1398, 13286,
   11314,  1206, 12924, -1644, -1644, 11314,   458,   549,   266,  1207,
    1428,  1208,     8, -1644,  1478, -1644, -1644,   542, 11314, 11314,
   -1644, -1644,   217, -1644, -1644,    52, 12726,   642,  2300,   484,
   12678, 11314,     5,   642,   642,   584, 11314, -1644,    16, -1644,
   -1644, 11314,   601, 12924, -1644, 11314,     5, 11314, 11314, 11314,
    1229,     5,  1230,     5,  1238,     5,     5,   675,   642,  1241,
    1253,     5,     5, 13428, 11314, 11314,   730, 12924,   749, 12924,
     642,   767, 11314,   780,   642,   807,   848, 11314, 12924,   858,
     884,   885, 11314,   887, 11314,   894, 12924,   908, 11314, 12924,
   12924,   924,   928,   932,   934,   938, 11314,   940, 11314,   960,
   11314,   961, 11314, 11314, 11314,   642,   962,   963,   642,   974,
   11314,   642,   975,   976,   977, 11314,   642,   978,  1006,   642,
    1008,  1010,  1017, 11314,  1018,   642,  1060, 12924,  1061,  1062,
    1063, 11314,  1071, 12924,  1087, 12924,  1090, 12924,  1097, 12924,
    1099, 12924,   642,  1103,  1107,  1109,   642, 11314, 12924,  2300,
    2300,  2300,  2300,  1236,  1254,  1255,  1256, -1644,   896,  -184,
   11314, 11314, 11314, 11314, -1644,  1265,     5,     5,  2300,   642,
     659,  1269,  1271, 13652, 13729,  1237, 13847, 13869, 13903,  1281,
     103,  1274,  1283,  1116,  1299,  1318,  1310,  1320,  1284,  1330,
       5, 13924,  1139,  -158,   642,   642,   642,   642,   642,  1142,
     642,   642,   642,  1145,   642,   642,  1146,   642,   642,  1149,
     642, 12924,   642,  1153,   642,  1156, 12924,  -110, 12924, 12924,
   12924, 12924,  1160,   642,  1264,  1432,  1735,  1756,  1781,   761,
    1863,   881,  1895,  1989,  1336,  2037,  2058,  2097,  2124,  2154,
    2610,  2628, 13939, -1644,  2647,   -48,  1163,  1167,  1169,   -15,
   13954, 13969,   125,  1133, -1644,  2687,  2706,     9,  2901,    83,
    2916,    65,    91, -1644,   202, -1644,   281, -1644,   282, -1644,
     318,   327,   346,   472, 13984,  1173,  1175,  1181,   473,   476,
     516,   400,  1346,   189,  1354,  1403,   517,  3076,   538,   190,
    1187,  1191,  1193, -1644, -1644,  1197,  -153,  1199,   -68,  1200,
     585,   586, -1644, -1644,   642,   642,   642,   642,   642,   642,
     642, -1644, 11314, 11314,   957,   971,   920,    74,   -11,     3,
     -45, -1644,   -23,   -23,  1162,  1162, -1644, -1644, -1644, 13286,
   -1644, -1644, 11314, -1644, -1644, -1644, -1644,   101,   101, -1644,
   -1644,   451, -1644, -1644,   464, 11314, -1644,  1537, -1644, -1644,
   -1644, -1644, -1644, -1644, -1644, -1644,   616, 13999, 11314,   203,
    3144, 13043, -1644, -1644, 11314, 11314,  1331, 12924, -1644, -1644,
   11314, -1644,   671,  1416,  1417,  1340,  1374, 14014, 14042,  1431,
    1441, -1644, -1644, -1644, 11314,  1560,  1563, -1644,  1210, 14064,
   11314, 12924,  2300, -1644, -1644, 12924,  1220, -1644, 11314, 14079,
   14098,  1439, 12924, 11314, 11314, 11314, 12924, 11314, 11314, 11314,
   11314, 11314, 11314, 11314, 11314,  1453,  1461, 11314,  1221, 11314,
    1223, 11314,  1468, 12924, 12924, 12924,  1469,  1227, 12924, 12924,
   11314,  1499, 12924,  1502, 11314,  1262, 12924, 14209,   642,   642,
   12924, 12924, 11314, 12924, 11314,  1505, 12924,  1506, 12924,  1523,
   11314,  1532,  1542,  1543, 11314, 11314, 11314,  1554, 12924, 11314,
   11314,  1555, 12924, 11314, 12924, 12924, 11314,  1564, 12924, 11314,
    1268, 11314, 12924, 11314,  1574, 12924,  1272, 11314,  1282, 11314,
    1301, 12924,  1302, 12924,  1303, 12924, 12924, 12924, 14237,  1309,
   -1644, 11314, 11314, 11314, -1644, -1644,   458,  2300,   458,  2300,
   14274, 14293, 13286, 11314, 11314, 11314, -1644, -1644, -1644, -1644,
   -1644, 11314, 11314, -1644, 11314, 11314, 11314, -1644, 12924, -1644,
   12805, -1644, 12924,  1578,  1584, -1644, -1644, 11314, 11314, 11314,
   11314, 12924, -1644, 12924, 11314, 11314, 11314,   642, 11314, 12924,
     587, -1644,  1311,  1313,  1315,  1321, 11314, -1644, -1644, -1644,
   -1644, -1644, 11314, -1644, -1644, 11314, -1644, -1644, -1644, -1644,
   -1644, -1644, -1644, -1644, -1644, -1644, -1644, 11314, -1644, -1644,
   11314, 11314, 11314, -1644, 11314, 11314, -1644, 12924, -1644, -1644,
   -1644, -1644, -1644, 11314, -1644, -1644, -1644, -1644, -1644, -1644,
   -1644, -1644, -1644, -1644, -1644, 12924, 12924, 12924, 12924, -1644,
   -1644, -1644, -1644, -1644, 12924, -1644, -1644, -1644, -1644, -1644,
   -1644, 11314, -1644, 11314, 11314, 11314,  1658, 12924, -1644,  1658,
   12924, -1644, 12924, -1644, -1644,   692,   669, 11314,   111,  2300,
   -1644,  1587, -1644,  1588,  1629,  1639, -1644,  1640,  1642, -1644,
   -1644, -1644,   649, 13286, -1644, -1644, -1644, 11314, 14308, 12924,
    1765, -1644, 12924,   642,   458,   549, 14323, 11314,   344,   671,
     671,  3159,  1589,  1628, -1644,  1646, -1644, -1644, -1644, -1644,
   11314, 11314, -1644, -1644, 14338,  4395,  4395, 12924, 12924,  1648,
    1339,   642, 12924, -1644, 11314, 11314, 12924,   642,  1649, 14353,
       5,  1345,  1650,     5,   458, 14368, 14383, 14404,     5,  1654,
   14432, 12924, 12924,  2300, 12924,  2300, 12924,   458,  2300, 12924,
    1347,   642,   642, 12924, 12924,  1359,  1362,   153,  2300, 12924,
    1363, 12924,  2300, 12924,  1365, 12924,  1369,  1371,  2300,   642,
    2300, 12924,  1372, 12924,  1373, 12924,  2300, 12924, 12924, 12924,
     458, 14447,   458,  2300,  2300, 12924,   642,  2300,  2300, 12924,
    1382,   448,  2300,   642,   642,  2300, 12924,  1383, 14469, 11314,
    2300,  1384,  2300, 12924,   642, 12924, 14578, 12924,   609, 14599,
   12924,  1386, 12924,  1394, 12924,   642,  1400,  1401, 12924, 12924,
    1655,  3187,  3271,  1183, 12924, 12924, -1644,  2300,     5, -1644,
    1657,  3422,  3542,  3657,  3955,  3970,   595,  1659,   354,   642,
   -1644, -1644,  3988,  4009,  1660,    94,  1402,   642,  2300,  2300,
    2300, 14642,   642, -1644, 12924, 12924, 12924, 12924,  2300,  4030,
    4691,  4951,  5211,  6746,  1217,  7001,  7256,   374,  7766,   600,
    1404,   378,   390,   636,  8021, 14664, 14679,  8276,   -30,   637,
      38,   638,   666,    61, -1644, -1644, -1644,   101,   101, -1644,
   -1644, -1644, -1644, 11314,  1806,  1850,  1873,  8531, 11314,   674,
    1662,   396, -1644, 11314, 14694, 12924,  1866, -1644, -1644, -1644,
   -1644, -1644, -1644,  1667,  1669,  2300,  2300, 12924, -1644, -1644,
     642,   642, 12924, 12924,  1411, 14709,  2300,  1412, 12924, 12924,
   11314, 12924, 12924, 11314, 11314, 11314, 11314, 11314, 11314, 12924,
     642,  1414,  1420,  1421,  1422, 11314,  1435,  1436, 12924, 11314,
   11314,  1437, 12924,  1445,  1447, 11314,   642, 11314, 11314,  1451,
   12924,  1454, 11314,  1457,  1460,  1464,  1470, 12924,  1483,  1485,
   11314, 12924,  1486, 11314, 11314,  2300, 11314,  1494,  1497, 11314,
     642, 12924, 12924,  1498, 11314,  1500, 12924,  1501, 12924, 12924,
     642,   642, -1644,  1857,  1867, 11314,  1868,  1513,   642, 11314,
     745, -1644, -1644, -1644, -1644, -1644, -1644, -1644, 12924, -1644,
   -1644, -1644, -1644, 11314, 12924, 11314,   688,   743,  1514,   642,
   -1644, -1644, -1644, -1644, -1644, 11314, -1644, -1644, -1644, 12924,
   -1644, -1644, -1644, 12924, 11314, -1644, 11314, -1644, -1644, -1644,
   12924, 11314, -1644, 12924, -1644, -1644, 12924, -1644, -1644, -1644,
   11314, -1644, -1644, -1644, -1644, -1644,  1897,   738,  8786,  1890,
   11314, 12924,  9041, 11314,   744,  1688,  1478,   671,  1689,  1692,
     671, -1644, -1644,   642,  1520,   642, 12924, 12924, 12924,   642,
     642,  1700,   642,   642,     5, 14724, 14739, 14754,     5, 14773,
    1524, 12924, 11314, 11314, 12924, 14794, 11314, 12924,   642, 14809,
    2300, 12924,  1531, 12924, 11314, 14837, 14949,   458,  2300, 12924,
     642, 12924, 14968, 11314, 11314, 12924, 12924,   642, 11314, 12924,
     800,  2300,   642, 11314, 15004, 15032, 15047, 11314, 12924, 15062,
    1534,   642, 12924,   814, 15077, 12924,  1535, 12924,  1541,   642,
   12924, 12924,  9296, 12924, 11314, -1644,  1701,  1702,    50, -1644,
     757, 15092,   642,  2300, -1644, -1644, 12924,  9551,   758,   781,
    9806, 10061,   795, 10316,   796,   811,   597, 13286, 13734, 11314,
    1914, -1644,  1703, -1644,  1712, 15107,   823,   766, 10571,  1916,
   11314,   671, -1644, -1644, -1644, -1644, 12924,   642,   642,   642,
   12924, 11314, 11314, 12924, 11314, 11314, 11314, 12924,  1558, 15122,
   15144,  1561, 11314, 15163,  1562, 11314,  1582, 11314,  1604, 15178,
   11314, 11314,  1605,  1606, 11314, 15199, 15317,   642,   642, 15339,
    1607, 11314, 15373, 11314, 11314, 11314, 15394,  1608, 11314, 12924,
     642, 12924, 12924,  1614, 11314,  1616, 12924,   642,   642,  1902,
     642,  2300,  1717,  1718,   745, -1644, -1644, 11314,   642, -1644,
   -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644, 11314, -1644,
    1873,  1943,   746, 13286, -1644, 12924, 11314, 11314, -1644, -1644,
    1722,  1478, -1644,  1725,  1478, 15409, -1644,   642,   642,  1727,
   15424,   642, 15439,  1728, 15454,  1618, 12924, 12924, 12924, 12924,
   15469, 12924, 12924, 15484, 11314,  2300, 12924, 11314,  2300, 15512,
   12924, 11314,  2300, 11314, 12924, 12924, 12924,  2300, 12924, 15534,
   15549, 15568, 12924, 12924,  2300,   642,  1620,   642, 12924,   906,
   15679, 12924,   642, 12924, -1644, -1644, -1644, 13286, 10826,  2300,
   13286, -1644, -1644,  1873,  1045,   447, 15707, 11081,  1478, 12924,
     671,  1478, 11314,   671, 11314, 12924, 12924, 11314, 12924, 12924,
   12924,   642,   642,   642,  1624, 11314,   642,   642, 11314, 15744,
    1626, 15763, 11314,   642, 15778, 15793,   642,   642,   642,   642,
   11314, 12924, 11314,  1627,   642, 12924,   642, 12924, 12924,  1630,
     642,    31, -1644,  1873, 13286, -1644, -1644, -1644, -1644, -1644,
   -1644, -1644, 12924, -1644, 11314, -1644,   671,   515, -1644,   671,
   15808, -1644, 11336,   642,   642, 15823,   642,   642,   642, 12924,
    2300,  2300, 11314, 12924, 11314,  2300, 12924, 12924,  2300,   642,
   15838, 12924,   642,  1637,   642, 12924, -1644, -1644, -1644,  1141,
    1873,   829, 11574, -1644, 12924, -1644, -1644, 11314, -1644, 12924,
     642, 15853,   642, 15874,   642,   642, 11314,   642, 12924,   642,
   -1644, -1644, -1644, -1644, -1644, -1644,  1990,  1897, -1644, -1644,
     845,  1478, 11595,  1478,   642, 12924, 12924, 15902,   642, -1644,
   -1644, -1644, -1644,   671, -1644,   671,  1645,   642, 12924,  1478,
   -1644,  1478, -1644, 12924,   642,   671,   671,   642, -1644, -1644
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
     348,   349,   321,     0,     0,     0,     0,     0,     0,   302,
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
       0,     0,     0,     0,     0,     0,   527,    16,   242,     0,
     579,   651,     0,   648,     0,     0,     0,   618,     0,   628,
       0,     0,   617,   591,   593,   589,     0,   125,    82,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   165,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     204,     0,     0,     0,     0,     0,     0,   250,   251,     0,
     249,   239,     0,     0,     0,   487,   439,     0,   303,   272,
     276,   288,   400,   402,   406,   326,   429,   431,     0,   518,
     539,     9,   585,    16,   567,     0,     0,     0,   611,   630,
       0,   638,   620,     0,   638,     0,   627,    95,   110,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,     0,     0,   145,     0,
       0,     0,   162,     0,     0,     0,     0,   182,     0,     0,
       0,     0,     0,     0,   203,   206,     0,   208,     0,     0,
       0,     0,   214,     0,   514,   515,   511,    16,     0,   528,
      16,   586,   582,   580,     0,     0,     0,     0,   638,     0,
       0,   638,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,   121,   123,     0,     0,   132,   127,     0,     0,
       0,     0,     0,   154,     0,     0,   163,   167,   175,   180,
       0,     0,     0,     0,   200,     0,   207,     0,     0,     0,
     248,     9,   322,   519,    16,   574,   571,   572,   573,   569,
     570,   568,     0,   652,     0,   649,     0,     0,   619,     0,
       0,   629,     0,   109,   100,     0,   111,   105,   219,     0,
     136,   141,     0,     0,     0,   152,     0,     0,   199,   194,
       0,     0,   209,     0,   212,     0,   490,   489,   488,     0,
     583,     0,     0,   631,     0,   632,   621,     0,   622,     0,
     128,     0,   146,     0,   158,   160,     0,   192,     0,   210,
     522,   524,   525,   526,   521,   523,   529,   581,   653,   650,
       0,   638,     0,   638,   108,     0,     0,     0,   211,   530,
     520,   584,   634,     0,   624,     0,   137,   148,     0,   638,
     633,   638,   623,     0,   193,     0,     0,   138,   635,   625
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1644, -1644, -1644,  -267, -1644, -1644,  1991,   841, -1644, -1644,
   -1644, -1644, -1644, -1644, -1644,  1947,   -64, -1644, -1644,  -405,
      -3, -1644,  1949,  1734, -1644, -1644,  1518,  -475,  3121, -1644,
    1332,   -18,   -13, -1644,     4,    10,   131, -1644, -1644,  1011,
    2000, -1644, -1644, -1644, -1644, -1644, -1644, -1644,  1026, -1644,
    1015, -1644,   154, -1644, -1644, -1644, -1644, -1644, -1644, -1644,
   -1644, -1644, -1644, -1644,   518, -1644, -1644, -1644, -1644, -1644,
   -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644,
   -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644,   -52,
   -1644, -1644, -1644, -1163, -1644, -1644, -1644,  1350, -1644, -1644,
     720,  1341, -1644, -1644, -1644, -1644, -1644, -1644, -1644, -1644,
   -1644, -1644, -1644, -1644, -1644, -1643, -1644,   -20, -1644, -1644
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,   105,   106,   464,  1152,   107,   108,   276,   277,
     987,   988,   293,   688,   109,   110,   691,   111,   112,   804,
     243,   244,   113,   330,   963,   962,   836,   837,   331,   246,
     311,   247,   271,   298,   248,   249,   279,   280,   642,   643,
     116,   820,  1440,  1937,  2038,  1158,   117,   634,   635,   638,
     639,  1758,  1759,   118,   266,  1277,  1940,  2039,  2066,  1869,
    2080,   119,   285,   997,   646,  1292,  1777,  1505,  1778,   120,
     286,  1004,   121,   267,   979,  1496,   122,   268,   986,   123,
     648,  1293,  1666,  1944,  2001,   124,   649,  1296,  1874,  1780,
    1994,  2067,  1942,  1314,  1680,  1315,   306,   307,   313,   658,
    1012,   663,  1309,  1310,  1677,  1881,  1951,  2073,  2091,  1676,
    1884,  1948,  2071,  2089,   664,  1022,   292,   320,  1281,  1283
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     256,   627,   272,   273,   618,   114,   653,   689,   258,   654,
     839,   115,  1018,   449,   259,  1019,   262,   689,   278,   647,
     264,   282,   312,   324,   325,     7,     8,   261,   314,   490,
     294,   679,   612,  1791,   300,   302,   125,   392,   601,   318,
     128,   129,   130,   308,   288,   952,   289,   290,   284,   805,
     806,   346,   347,   348,   612,   125,  2036,   258,   283,   128,
     129,   130,  1032,   259,   610,   611,   612,   389,   390,   391,
     443,   601,   491,  1660,   659,  2037,   660,   661,  1145,   611,
     612,   459,   349,   437,   439,   441,   444,   393,   450,   448,
     594,   595,   596,   597,   598,   599,   600,   601,   458,   460,
     461,   462,     7,     8,  1182,   269,   689,  1267,   270,  1268,
     497,   498,   594,   595,   596,   597,   598,   599,   600,   500,
     501,    53,   442,    20,   603,   604,   452,  1494,    25,   503,
     504,   605,   606,   607,   608,   609,   610,   611,   612,   601,
     506,   507,   296,   297,   738,   601,  1517,  1518,   609,   610,
     611,   612,  1191,   499,   281,  1495,   451,   603,   604,   342,
     492,   514,   502,   516,   605,   606,   607,   608,   609,   610,
     611,   612,   505,   594,   595,   596,   597,   598,   599,   600,
     946,   453,   948,   508,   454,   594,   595,   596,   597,   598,
     599,   600,  1270,   463,  1271,   594,   595,   596,   597,   598,
     599,   600,   263,   493,   515,   337,   265,   601,   601,   613,
     614,   615,   616,   739,  1219,   601,    96,    97,    98,   465,
     466,   304,   305,   594,   595,   596,   597,   598,   599,   600,
    1653,   467,  1654,   615,   616,   338,   339,   340,  1950,   592,
     601,  1953,   341,   613,   614,   615,   616,  1223,   601,   291,
     601,   601,   617,   740,   468,   690,   787,   613,   614,   615,
     616,   623,   125,   655,   601,   690,   128,   129,   130,  1020,
     469,  1231,   114,   326,   327,   601,   470,   640,   115,   662,
     328,   488,   644,   697,   698,   455,   699,   309,   310,   656,
     114,   673,   674,    96,    97,    98,   115,   601,  1656,   494,
    1657,   714,   715,   329,   952,  2006,   309,   310,  2009,   722,
    1854,   495,  1855,   677,   727,   613,   614,   615,   616,   732,
     601,   734,   482,   483,   683,   684,   685,  1236,   613,   614,
     615,   616,   692,   746,   456,   748,   457,   750,   601,   752,
     753,   754,   263,  1233,   496,  1234,   601,   760,   613,   614,
     615,   616,   765,  1237,   690,   707,   708,   601,   601,   509,
     773,   265,   789,  1168,   716,  1169,   718,   781,   720,   721,
     601,   723,   724,   725,   726,   810,   510,   729,   730,   731,
     601,   733,  1006,   735,   471,   737,   511,  1226,   512,   741,
     742,   743,   744,   745,   622,   747,   624,   749,   472,   751,
     628,   629,   473,   755,   756,   757,   758,   759,   601,   761,
     762,   763,   764,  1560,   766,   767,   768,   769,   770,   771,
     772,   474,   774,   775,   776,   778,   779,   780,  2083,   782,
    2085,   784,   980,   786,   981,   788,   982,   790,   476,   792,
     793,   794,   795,   796,   601,   601,  2095,   477,  2096,  1254,
    1261,  1255,  1262,   520,   809,   632,   633,   601,   601,   983,
     831,   832,   984,  1299,  1238,  1300,   819,   985,   636,   637,
     594,   595,   596,   597,   598,   599,   600,   830,   601,   833,
     478,   834,   835,   791,   518,   842,   843,   844,   845,   846,
     847,   848,   849,   850,   851,   852,   853,   854,   855,   856,
     857,   858,   859,   860,   862,   863,   864,   865,   601,   479,
     867,   884,   480,   798,  1792,   872,   873,  1795,   594,   595,
     596,   597,   598,   599,   600,  1013,  1014,   519,   594,   595,
     596,   597,   598,   599,   600,   481,   601,   601,   895,   896,
     897,   898,   899,  1239,  1240,   902,  1025,  1026,   907,   484,
     909,   932,   911,   912,   914,   916,   918,   920,   921,   922,
     923,   485,   925,   926,   927,   928,   929,   930,   931,   933,
    1035,  1036,   936,   601,   938,   939,   940,   941,   942,   601,
    1241,   945,   601,   947,   812,   949,   950,   951,   499,  1242,
     486,   954,   955,   956,   957,   958,   959,   960,   961,   601,
    1011,   601,   821,   822,  1515,   502,  1516,   505,  1243,   601,
    1868,   487,   603,   604,  1618,   508,  1619,   489,  1040,   605,
     606,   607,   608,   609,   610,   611,   612,   513,  1886,   601,
     601,   521,  1048,   601,  1639,   813,  1640,  1053,  1644,  1055,
    1645,  1057,  1058,   630,   631,   601,   522,  1062,  1063,  1009,
    1646,   601,  1647,   114,   523,   601,  1671,   312,   952,   115,
     603,   604,  1252,  1156,  1157,  1294,  1295,   605,   606,   607,
     608,   609,   610,   611,   612,  1312,  1313,  1038,   524,   594,
     595,   596,   597,   598,   599,   600,   603,   604,  1503,  1504,
    1046,   602,   525,   605,   606,   607,   608,   609,   610,   611,
     612,   601,   601,   601,   934,   935,   870,  2002,  1581,  2003,
     603,   604,  1278,   601,  1068,   526,  1070,   605,   606,   607,
     608,   609,   610,   611,   612,  1077,   527,   601,   601,   528,
    -564,   601,   603,  1085,  1244,  1249,  1088,  1089,  1250,   605,
     606,   607,   608,   609,   610,   611,   612,   603,   604,  1756,
    1757,   529,  1154,  1155,   605,   606,   607,   608,   609,   610,
     611,   612,   605,   606,   607,   608,   609,   610,   611,   612,
     601,   601,   601,   530,  1120,  2044,  1179,  2045,  1251,  1258,
    1126,   531,  1128,   532,  1130,   533,  1132,  2008,  1134,   534,
    2011,  1488,  1941,   601,  1490,  1139,  1023,  1024,  1781,  1782,
    1260,  1029,  1030,   613,   614,   615,   616,  1146,  1148,   603,
     604,     1,     2,     3,     4,     5,   605,   606,   607,   608,
     609,   610,   611,   612,   603,   604,  1879,  1880,   535,   536,
     537,   605,   606,   607,   608,   609,   610,   611,   612,   601,
     601,   601,   601,  2043,  1041,   515,  2046,  1273,  1274,  1463,
     601,   613,   614,   615,   616,   601,   601,  1616,  1187,   538,
     539,  1045,  1642,  1190,   601,  1192,  1193,  1194,  1195,  1591,
     594,   595,   596,   597,   598,   599,   600,   613,   614,   615,
     616,   540,   541,   542,   594,   595,   596,   597,   598,   599,
     600,   601,   601,   601,   543,   544,   545,   601,  1648,  1655,
    1658,   613,   614,   615,   616,   603,   604,   998,   625,   999,
     651,  1000,   605,   606,   607,   608,   609,   610,   611,   612,
    2090,   601,  2092,   613,   614,   615,   616,   619,  1659,   601,
     601,   546,  2098,  2099,  1001,  1059,  1669,  1002,   613,   614,
     615,   616,  1003,   601,   603,   604,   613,   614,   615,   616,
    1764,   605,   606,   607,   608,   609,   610,   611,   612,   603,
     604,   547,   548,   549,   550,   551,   605,   606,   607,   608,
     609,   610,   611,   612,  1280,  1282,   594,   595,   596,   597,
     598,   599,   600,   114,   552,   601,   553,   554,   555,   115,
    1067,   606,   640,   608,   609,   610,   611,   612,   601,   601,
     613,   614,   615,   616,   601,  1765,  1789,   667,  1303,  1069,
     620,  1304,   601,   601,  1308,   613,   614,   615,   616,  1856,
    1860,  1202,   601,  1203,   556,   557,  1506,  1071,   606,   607,
     608,   609,   610,   611,   612,   601,   601,   558,  1330,   559,
    1073,   803,  1331,  1861,   608,   609,   610,   611,   612,  1337,
     601,   601,   560,  1341,   561,   601,  1344,  1864,  1866,  1995,
    1831,  1996,   601,  1997,   562,   563,   601,  1074,  1357,   601,
    1360,  1361,  1362,  1867,  1841,  1365,  1366,  1367,   601,  1370,
     564,   565,   566,  1374,   601,  1878,  1998,  1376,  1377,  1999,
    1379,  2068,   567,  1382,  2000,  1384,   613,   614,   615,   616,
     601,  1390,  1392,   601,   953,  1396,   672,  2082,  1075,  1400,
    1401,  1403,  1404,   601,   568,  1407,   569,   570,  1078,  1411,
    1284,  1285,  1414,  1287,  1288,   571,  1418,   572,  1421,   573,
    1423,   574,  1425,  1426,  1427,   613,   614,   615,   616,   601,
     601,  1205,   601,  1206,  1079,  1080,   675,  1082,   680,   601,
     613,   614,   615,   616,  1084,  2060,   114,  2061,  1144,  2062,
     575,   601,   115,   601,   576,  1446,  1987,  1448,  1086,  1449,
     577,   578,   579,   580,   613,   614,   615,   616,  1456,   601,
    1457,   681,  2063,   601,  1090,  2064,  1462,   601,  1091,   601,
    2065,   581,  1092,   601,  1093,   601,   603,   604,  1094,   693,
    1096,   814,   582,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   601,   601,   601,   601,   583,
    1098,  1100,  1104,  1105,  1477,   613,   614,   615,   616,   601,
     601,   601,   601,   601,  1106,  1108,  1109,  1110,  1112,   612,
     584,   585,  1479,  1480,  1481,  1482,   603,   604,   586,   587,
     588,  1483,   589,   605,   606,   607,   608,   609,   610,   611,
     612,   601,   590,   601,  1489,   601,  1113,  1491,  1114,  1492,
    1115,  1430,   601,   601,   650,   652,  1540,  1116,  1118,  1543,
     603,   604,   665,   666,  1547,   670,   671,   605,   606,   607,
     608,   609,   610,   611,   612,   717,  1509,   114,   719,  1511,
     603,   604,   728,   115,   736,  1528,  1529,   605,   606,   607,
     608,   609,   610,   611,   612,   601,   601,   601,   601,   783,
    1119,  1121,  1122,  1123,  1530,  1531,   601,   603,   604,  1534,
     785,  1125,   811,  1537,   605,   606,   607,   608,   609,   610,
     611,   612,   601,   866,   868,   601,   869,  1127,  1550,  1551,
    1129,  1552,   601,  1553,   601,   871,  1554,  1131,   601,  1133,
    1556,  1557,   601,  1135,   601,   978,  1561,  1136,  1563,  1137,
    1564,   601,  1566,   943,  1609,   944,  1172,   976,  1569,   977,
    1571,   989,  1573,   990,  1574,  1575,  1576,   613,   614,   615,
     616,  1623,  1578,  1227,   601,  1228,  1579,   601,   991,  1181,
     601,   601,  1183,  1582,   601,  1184,  1185,   994,   601,  1186,
    1587,   601,  1588,  1188,  1590,   601,  1189,  1593,   601,  1595,
    1196,  1597,   601,  1220,   601,  1600,  1601,  1221,   601,  1222,
     601,  1607,  1608,  1246,   995,  1247,   601,   613,   614,   615,
     616,  1248,   601,  1605,  1005,  1606,   601,  1263,   601,  1523,
    1524,  1264,   601,  1265,   601,   601,   992,  1266,   996,  1269,
    1272,  1626,  1627,  1628,  1629,   601,   993,  1008,  1015,  1017,
    1327,   613,   614,   615,   616,   601,   601,  1635,   601,  1636,
    1332,  1354,   601,  1356,  1661,  1662,  1016,  1364,  1021,  1052,
    1054,   613,   614,   615,   616,   603,   604,  1140,  1056,  1163,
     644,  1060,   605,   606,   607,   608,   609,   610,   611,   612,
    1870,  1871,  1674,  1061,  1141,  1142,  1143,   601,   613,   614,
     615,   616,  1373,   601,  1683,  1153,  1197,   601,  1409,  1684,
    1685,  1159,  1415,  1160,  1170,  1689,  1690,   601,  1692,  1693,
     603,   604,  1417,  1167,  1177,  1171,  1700,   605,   606,   607,
     608,   609,   610,   611,   612,  1708,   601,   601,   601,  1712,
    1173,  1420,  1422,  1424,   601,  1717,   601,  1720,   601,  1429,
     601,  1464,  1175,  1465,  1727,  1466,   601,  1730,  1732,  1174,
    1291,  1467,  1176,   351,   352,   353,   354,   355,  1740,  1741,
    1178,  1743,  1307,  1746,   601,  1748,  1749,   356,  1209,  1533,
     601,  1318,   601,   357,   358,  1541,  1943,  1555,  1253,   359,
     360,   361,   362,   363,   601,  1760,  1256,   601,   601,  1558,
     601,  1762,  1559,  1562,   601,  1565,   601,   601,   601,  1567,
    1801,  1568,  1570,  1572,  1805,  1319,  1768,   601,   601,   601,
    1769,   601,  1580,  1583,  1586,  1325,  1594,  1772,  1326,   601,
    1774,  1678,  1679,  1775,  1596,   601,   601,   601,   364,   601,
    1598,  1599,  1624,   835,  1643,  1257,   601,   601,  1786,   601,
    1991,  1686,  1688,  1993,  1701,   601,   601,   601,  1316,  1317,
    1702,  1703,  1704,  1797,  1798,  1799,   613,   614,   615,   616,
     601,   601,   601,  1322,  1198,  1706,  1707,  1711,  1808,  1336,
     601,  1811,   601,  1323,  1814,  1713,   601,  1714,  1816,   601,
    1818,  1719,   601,  1351,  1721,   601,  1822,  1723,  1823,   601,
    1724,  1352,  1827,  1828,  1725,   601,  1830,  2040,  1359,  1363,
    1726,   613,   614,   615,   616,  1837,   245,   668,   601,  1840,
     601,   601,  1843,  1728,  1845,  1729,  1733,  1847,  1848,   601,
    1850,   275,   601,   601,  1737,   601,   601,  1738,  1742,  1369,
    1745,  1747,  1371,  1858,   287,  1381,  1383,   295,   601,   601,
     299,   301,   303,  1754,  1766,   601,   319,   319,   319,   601,
    1796,   114,   114,  1385,  1807,   343,   601,   115,   115,   601,
     601,  1817,  1387,  1887,  1839,  1844,   601,  1888,   603,   604,
    1891,  1846,  1388,  1389,  1895,   605,   606,   607,   608,   609,
     610,   611,   612,   601,  1395,  1399,   601,   601,  1896,   603,
     604,  1899,  1902,  1510,  1406,   447,   605,   606,   607,   608,
     609,   610,   611,   612,  1413,   319,  1925,   601,  1926,  1927,
    1450,  1929,  1904,  1932,   603,   604,  1451,  1497,  1498,  1664,
    1520,   605,   606,   607,   608,   609,   610,   611,   612,   601,
     601,   601,   601,   601,  1906,  1910,  1911,  1916,  1923,   601,
     475,   601,  1945,   601,  1928,   601,  1931,   114,  1960,   601,
    1985,   601,   601,   115,  2019,   601,  2023,  2031,  1665,  1521,
    2035,  1499,   601,  1961,  1962,  1963,  1964,  2058,  1966,  1967,
     601,  1500,  1501,  1970,  1502,  2093,  1522,  1973,  1532,  1538,
    1542,  1976,  1977,  1978,  1548,  1979,    -9,  1602,  1610,  1983,
    1984,  1617,  1622,  1670,  1675,  1986,   603,   604,  1989,  1681,
    1990,  1682,  1750,   605,   606,   607,   608,   609,   610,   611,
     612,   114,  1751,  1753,   114,  1779,  2007,   115,  1784,  1790,
     115,  1793,  2013,  2014,  1794,  2016,  2017,  2018,   603,   604,
    1800,  1873,  1852,  1853,  1875,   605,   606,   607,   608,   609,
     610,   611,   612,  1876,  1883,   591,   593,  1933,  2029,  1934,
    1935,  -542,  2032,  1949,  2033,  2034,  1952,  1955,  1958,   613,
     614,   615,   616,  1436,  2079,   257,   621,  1199,   114,  2041,
     344,   626,   345,   838,   115,   260,  1290,  1033,  1936,  1289,
     613,   614,   615,   616,   641,  2081,  2050,  1286,  1200,   645,
    2052,  1663,  1031,  2054,  2055,  1512,   657,     0,  2057,  1043,
       0,     0,  2059,     0,     0,   613,   614,   615,   616,     0,
       0,  2070,     0,  1201,     0,     0,  2074,     0,     0,   676,
       0,   678,   603,   604,     0,  2078,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,     0,     0,     0,
       0,     0,  2086,  2087,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2094,     0,     0,     0,     0,
    2097,     0,     0,     0,     0,     0,     0,     0,   713,     0,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,   613,   614,   615,
     616,   603,   604,     0,     0,  1204,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     614,   615,   616,     0,     0,     0,     0,  1207,     0,     0,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,     0,     0,
       0,     0,     0,   799,   800,   801,   802,   603,   604,     0,
     808,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   818,     0,     0,     0,     0,   823,   824,     0,
     825,   826,   827,   828,   319,   319,     0,   603,   604,     0,
       0,   841,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   615,   616,     0,     0,     0,
       0,  1208,     0,     0,     0,   874,   875,   876,   877,   878,
     879,   880,   881,   882,   883,   319,   885,   886,   887,   888,
     889,   890,   891,   892,   894,     0,     0,     0,     0,     0,
     900,   901,   903,   905,   906,     0,   908,     0,   910,     0,
       0,   613,   614,   615,   616,     0,     0,     0,   924,  1210,
       0,     0,     0,     0,     0,   319,     0,     0,     0,     0,
     937,     0,   613,   614,   615,   616,   603,   604,     0,     0,
    1211,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,     0,     0,     0,     0,     0,     0,     0,     0,   964,
     965,   966,   967,   968,   969,   970,   971,   972,   973,   974,
     975,   613,   614,   615,   616,     0,     0,     0,     0,  1212,
       0,     0,     0,   603,   604,     0,     0,     0,     0,     0,
     605,   606,   607,   608,   609,   610,   611,   612,   613,   614,
     615,   616,     0,     0,  1007,     0,  1213,     0,     0,  1010,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1027,  1028,     0,     0,     0,     0,   613,   614,
     615,   616,     0,     0,     0,  1039,  1214,   125,   126,   127,
    1042,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,  1049,  1050,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1087,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,     0,
       0,     0,     0,   321,     0,     0,     0,   613,   614,   615,
     616,   322,     0,   669,     0,   144,   145,     0,     0,   146,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1767,
       0,     0,     0,     0,     0,     0,     0,     0,  1770,     0,
    1771,     0,     0,     0,     0,  1773,     0,     0,     0,     0,
       0,     0,     0,     0,  1776,     0,     0,     0,   613,   614,
     615,   616,     0,     0,  1785,     0,  1301,  1788,     0,     0,
       0,     0,     0,   613,   614,   615,   616,     0,     0,     0,
       0,  1519,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1809,  1810,     0,     0,
    1813,   613,   614,   615,   616,     0,     0,   682,  1819,  1603,
       0,     0,     0,   687,     0,     0,     0,  1825,  1826,     0,
     694,   696,  1829,     0,     0,     0,     0,  1832,     0,     0,
       0,  1836,   700,   701,   702,   703,   704,   705,   706,     0,
       0,   709,   710,   711,   712,   603,   604,     0,  1851,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1872,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1885,   613,   614,   615,   616,     0,
       0,     0,     0,  1604,     0,     0,  1890,     0,  1892,     0,
    1894,     0,     0,     0,     0,     0,  1900,     0,     0,  1903,
       0,  1905,     0,     0,  1908,  1909,     0,     0,  1912,     0,
       0,     0,     0,     0,     0,  1917,     0,  1919,  1920,  1921,
       0,     0,  1924,     0,     0,     0,     0,     0,  1930,     0,
       0,     0,     0,     0,     0,     0,   815,   816,   817,     0,
       0,  1938,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1939,     0,     0,   603,   604,   840,     0,     0,
    1946,  1947,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1969,     0,
       0,  1971,     0,     0,     0,  1974,     0,  1975,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
       0,     0,     0,     0,  1611,     0,  2010,     0,  2012,     0,
       0,  2015,     0,     0,     0,     0,     0,     0,     0,  2020,
       0,     0,  2021,     0,     0,     0,  2025,     0,     0,     0,
       0,     0,     0,     0,  2028,     0,  2030,     0,     0,     0,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,  2042,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2051,     0,  2053,     0,
       0,     0,     0,     0,   125,   126,   127,     0,   128,   129,
     130,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2072,     0,     0,     0,     0,     0,     0,     0,     0,
    2077,   132,   133,     0,     0,     0,   613,   614,   615,   616,
       0,     0,     0,     0,  1612,     0,     0,     0,     0,     0,
       0,     0,  1044,     0,     0,     0,  1047,     0,     0,     0,
    1051,     0,     0,     0,   134,   135,   136,   137,   138,   139,
     140,     0,     0,     0,     0,  1065,  1066,     0,     0,     0,
       0,     0,   141,  1072,     0,   142,     0,     0,  1076,     0,
     315,     0,     0,  1081,     0,  1083,     0,     0,   316,     0,
       0,     0,   144,   145,     0,     0,   146,  1095,   147,  1097,
       0,  1099,     0,  1101,  1102,  1103,   148,     0,     0,     0,
       0,  1107,     0,   149,     0,     0,  1111,   150,   151,     0,
       0,     0,     0,     0,  1117,     0,     0,   152,     0,   153,
     154,     0,  1124,     0,     0,   155,   156,   157,   158,   159,
     160,   613,   614,   615,   616,     0,     0,   161,     0,  1613,
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
     614,   615,   616,     0,     0,   141,     0,  1614,   142,     0,
       0,     0,     0,   143,   613,   614,   615,   616,     0,     0,
       0,   829,  1615,     0,     0,   144,   145,     0,     0,   146,
       0,   147,   613,   614,   615,   616,     0,     0,     0,   148,
    1620,     0,     0,     0,     0,     0,   149,     0,     0,     0,
     150,   151,     0,   613,   614,   615,   616,     0,     0,     0,
     152,  1621,   153,   154,     0,  1438,  1439,     0,   155,   156,
     157,   158,   159,   160,   613,   614,   615,   616,     0,     0,
     161,     0,  1630,   162,     0,     0,   163,   164,   165,     0,
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
       0,     0,   125,   126,   127,     0,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1755,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   603,   604,     0,     0,   143,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
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
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,  1889,   241,     0,     0,  1893,     0,     0,     0,
     242,   807,   125,   126,   127,     0,   128,   129,   130,   131,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,     0,     0,  1631,     0,     0,     0,     0,     0,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   603,   604,     0,     0,   143,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
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
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,     0,   241,     0,     0,     0,     0,     0,     0,
     242,   893,   125,   126,   127,     0,   128,   129,   130,   131,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,     0,     0,  1632,     0,     0,     0,     0,     0,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   603,   604,     0,     0,   143,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
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
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,     0,   241,     0,     0,     0,     0,     0,     0,
     242,   904,   125,   126,   127,     0,   128,   129,   130,   131,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,     0,     0,  1633,     0,     0,     0,     0,     0,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,     0,     0,     0,     0,   143,     0,
       0,     0,     0,     0,   417,     0,     0,     0,     0,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
       0,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,   149,     0,     0,     0,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,   153,   154,     0,
       0,   418,   419,   155,   156,   157,   158,   159,   160,     0,
     420,   421,   422,   423,     0,   161,     0,     0,   162,     0,
       0,   163,   164,   165,     0,     0,   166,   167,   168,   169,
     170,     0,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,     0,   241,     0,     0,     0,   125,   126,   127,
     242,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   425,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,     0,
       0,     0,     0,   143,     0,     0,     0,     0,     0,   426,
       0,     0,     0,     0,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,     0,     0,     0,     0,     0,   148,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
     150,   151,     0,     0,     0,     0,     0,     0,     0,     0,
     152,     0,   153,   154,     0,     0,   427,   428,   155,   156,
     157,   158,   159,   160,   429,     0,     0,     0,   430,     0,
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
       0,     0,   125,   126,   127,   242,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,     0,     0,     0,     0,   143,     0,
       0,     0,     0,     0,   406,     0,     0,     0,     0,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
       0,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,   149,     0,     0,     0,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,   153,   154,     0,
       0,   407,   408,   155,   156,   157,   158,   159,   160,     0,
     409,     0,     0,   410,     0,   161,     0,     0,   162,     0,
       0,   163,   164,   165,     0,     0,   166,   167,   168,   169,
     170,     0,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,     0,   241,     0,     0,     0,   125,   126,   127,
     242,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   374,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,     0,
       0,     0,     0,   143,     0,     0,     0,     0,     0,   375,
       0,     0,     0,     0,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,     0,   376,     0,     0,     0,   148,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
     150,   151,     0,     0,     0,     0,     0,     0,     0,     0,
     152,     0,   153,   154,     0,     0,   377,     0,   155,   156,
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
       0,     0,   125,   126,   127,   242,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,     0,     0,     0,     0,   143,     0,
       0,     0,     0,     0,   412,     0,     0,     0,     0,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
       0,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,   149,     0,     0,     0,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,   153,   154,     0,
       0,   413,   414,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,   415,     0,   161,     0,     0,   162,     0,
       0,   163,   164,   165,     0,     0,   166,   167,   168,   169,
     170,     0,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,     0,   241,     0,     0,     0,   125,   126,   127,
     242,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   380,     0,     0,     0,
       0,     0,     0,     0,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   381,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   603,
     604,     0,     0,   143,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,     0,   382,     0,     0,     0,   148,
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
       0,   223,   224,   225,   226,     0,   227,   228,     0,   229,
     230,   231,     0,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,   239,   240,     0,   241,     0,
       0,     0,   125,   126,   127,   242,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,     0,     0,  1634,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   603,   604,     0,     0,   143,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
     394,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,   149,     0,     0,     0,   150,   151,     0,     0,     0,
       0,     0,     0,     0,     0,   152,     0,   153,   154,     0,
       0,   395,   396,   155,   156,   157,   158,   159,   160,     0,
       0,     0,     0,     0,     0,   161,     0,     0,   162,     0,
       0,   163,   164,   165,     0,     0,   166,   167,   168,   169,
     170,     0,     0,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,     0,   241,     0,     0,     0,   125,   126,   127,
     242,   128,   129,   130,   131,     0,   332,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,     0,     0,  1637,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   333,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   603,
     604,     0,     0,   143,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,   144,   145,     0,     0,   146,
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
       0,   223,   224,   225,   226,     0,   227,   228,     0,   229,
     230,   231,     0,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,   239,   240,     0,   241,     0,
       0,     0,   125,   126,   127,   242,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,     0,     0,  1638,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,     0,     0,     0,     0,   143,     0,
       0,     0,     0,     0,   371,     0,     0,     0,     0,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
     372,     0,     0,     0,   148,     0,     0,     0,     0,     0,
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
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,     0,   241,     0,     0,     0,   125,   126,   127,
     242,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   603,
     604,     0,     0,   143,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,     0,     0,   445,     0,     0,   148,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
     150,   151,     0,     0,     0,     0,     0,     0,     0,     0,
     152,     0,   153,   154,     0,     0,     0,   446,   155,   156,
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
       0,     0,   125,   126,   127,   242,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,     0,     0,  1641,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   603,   604,     0,     0,   143,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
       0,   482,   483,     0,   148,     0,     0,     0,     0,     0,
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
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,     0,   241,     0,     0,     0,   125,   126,   127,
     242,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,     0,     0,  1649,   132,   133,     0,     0,   274,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   603,
     604,     0,     0,   143,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,   144,   145,     0,     0,   146,
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
       0,   223,   224,   225,   226,     0,   227,   228,     0,   229,
     230,   231,     0,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,   239,   240,     0,   241,     0,
       0,     0,   125,   126,   127,   242,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,     0,     0,  1652,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   603,   604,     0,     0,   143,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
     335,     0,     0,     0,   148,     0,     0,     0,     0,     0,
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
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,     0,   241,     0,     0,     0,   125,   126,   127,
     242,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,     0,     0,  1667,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   603,
     604,     0,     0,   143,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,     0,   367,     0,     0,     0,   148,
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
       0,   223,   224,   225,   226,     0,   227,   228,     0,   229,
     230,   231,     0,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,   239,   240,     0,   241,     0,
       0,     0,   125,   126,   127,   242,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,     0,     0,  1783,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   603,   604,     0,     0,   143,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
     369,     0,     0,     0,   148,     0,     0,     0,     0,     0,
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
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,     0,   241,     0,     0,     0,   125,   126,   127,
     242,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,     0,     0,  1787,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   603,
     604,     0,     0,   143,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,     0,   384,     0,     0,     0,   148,
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
       0,   223,   224,   225,   226,     0,   227,   228,     0,   229,
     230,   231,     0,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,   239,   240,     0,   241,     0,
       0,     0,   125,   126,   127,   242,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,     0,     0,  1849,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   603,   604,     0,     0,   143,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
     386,     0,     0,     0,   148,     0,     0,     0,     0,     0,
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
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,     0,   241,     0,     0,     0,   125,   126,   127,
     242,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,     0,     0,  1859,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   603,
     604,     0,     0,   143,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,     0,   398,     0,     0,     0,   148,
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
       0,   223,   224,   225,   226,     0,   227,   228,     0,   229,
     230,   231,     0,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,   239,   240,     0,   241,     0,
       0,     0,   125,   126,   127,   242,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,     0,     0,  1862,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   603,   604,     0,     0,   143,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
     400,     0,     0,     0,   148,     0,     0,     0,     0,     0,
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
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,     0,   241,     0,     0,     0,   125,   126,   127,
     242,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,     0,     0,  1863,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   603,
     604,     0,     0,   143,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,     0,   402,     0,     0,     0,   148,
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
       0,   223,   224,   225,   226,     0,   227,   228,     0,   229,
     230,   231,     0,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,   239,   240,     0,   241,     0,
       0,     0,   125,   126,   127,   242,   128,   129,   130,   131,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,     0,     0,  1865,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   603,   604,     0,     0,   143,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
     144,   145,     0,     0,   146,     0,   147,     0,     0,     0,
     432,     0,     0,     0,   148,     0,     0,     0,     0,     0,
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
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,     0,   241,     0,     0,     0,   125,   126,   127,
     242,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,     0,     0,  1882,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   603,
     604,     0,     0,   143,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,   144,   145,     0,     0,   146,
       0,   147,     0,     0,     0,   434,     0,     0,     0,   148,
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
       0,   223,   224,   225,   226,     0,   227,   228,     0,   229,
     230,   231,     0,   232,   233,   234,   235,   236,   237,   238,
       0,     0,     0,     0,     0,   239,   240,     0,   241,     0,
       0,     0,   125,   126,   127,   242,   128,   129,   130,   131,
       0,   695,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,     0,     0,  1992,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,   135,   136,   137,   138,   139,   140,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,   142,   603,   604,     0,     0,   143,     0,
       0,   605,   606,   607,   608,   609,   610,   611,   612,     0,
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
     218,   219,   220,   221,   222,     0,   223,   224,   225,   226,
       0,   227,   228,     0,   229,   230,   231,     0,   232,   233,
     234,   235,   236,   237,   238,     0,     0,     0,     0,     0,
     239,   240,     0,   241,     0,     0,     0,   125,   126,   127,
     242,   128,   129,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   615,   616,     0,
       0,     0,     0,  2005,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,   142,   603,
     604,     0,     0,   143,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,   144,   145,     0,     0,   146,
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
       0,   223,   224,   225,   226,     0,   227,   228,     0,   229,
     230,   231,     0,   232,   233,   234,   235,   236,   237,   238,
       0,     0,   127,     0,     0,   239,   240,   131,   241,     0,
       0,     0,     0,     0,     0,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
     613,   614,   615,   616,     0,     0,     0,     0,  2048,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   603,
     604,     0,     0,     0,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,     0,     0,   603,   604,     0,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,     0,     0,     0,     0,     0,     0,   603,   604,
       0,     0,   146,     0,   147,   605,   606,   607,   608,   609,
     610,   611,   612,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,   150,   151,     0,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   250,   251,   252,   253,   159,     0,   133,     0,     0,
       0,     0,     0,   161,     0,     0,   162,     0,     0,   163,
     164,   254,     0,     0,   166,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   192,   193,   194,     0,     0,     0,   198,   199,
     200,     0,   202,     0,   204,   205,   206,     0,     0,     0,
       0,   211,   212,   213,   214,   215,     0,     0,   218,     0,
     220,   146,   222,   147,     0,   224,     0,   226,     0,     0,
     228,     0,     0,   230,   231,     0,   232,   233,     0,   235,
     127,   237,   150,   151,     0,   131,     0,     0,     0,   240,
     613,   614,   615,   616,     0,     0,   686,     0,   255,   915,
     250,   251,   252,   253,   159,     0,   133,     0,   613,   614,
     615,   616,   161,     0,     0,   162,  2069,     0,   163,   164,
     254,     0,     0,   166,   167,     0,     0,     0,     0,   613,
     614,   615,   616,     0,     0,     0,     0,  2084,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   192,   193,   194,     0,     0,     0,   198,   199,   200,
       0,   202,     0,   204,   205,   206,     0,     0,     0,     0,
     211,   212,   213,   214,   215,     0,     0,   218,     0,   220,
     146,   222,   147,     0,   224,     0,   226,     0,     0,   228,
       0,     0,   230,   231,     0,   232,   233,     0,   235,     0,
     237,   150,   151,     0,   127,     0,     0,     0,   240,   131,
       0,     0,     0,     0,     0,     0,     0,   255,   917,   250,
     251,   252,   253,   159,     0,     0,     0,     0,     0,     0,
     133,   161,     0,     0,   162,     0,     0,   163,   164,   254,
       0,     0,   166,   167,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,   194,     0,     0,     0,   198,   199,   200,     0,
     202,     0,   204,   205,   206,     0,     0,     0,     0,   211,
     212,   213,   214,   215,     0,     0,   218,     0,   220,     0,
     222,     0,     0,   224,   146,   226,   147,     0,   228,     0,
     388,   230,   231,     0,   232,   233,     0,   235,     0,   237,
       0,     0,     0,     0,     0,   150,   151,   240,   127,     0,
       0,     0,     0,   131,     0,     0,   255,   919,     0,     0,
       0,     0,     0,   250,   251,   252,   253,   159,     0,     0,
       0,     0,     0,     0,   133,   161,     0,     0,   162,     0,
       0,   163,   164,   254,     0,     0,   166,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,   193,   194,     0,     0,     0,
     198,   199,   200,     0,   202,     0,   204,   205,   206,     0,
       0,     0,     0,   211,   212,   213,   214,   215,     0,     0,
     218,     0,   220,     0,   222,     0,     0,   224,   146,   226,
     147,     0,   228,     0,   436,   230,   231,     0,   232,   233,
       0,   235,     0,   237,     0,     0,     0,     0,     0,   150,
     151,   240,   127,     0,     0,     0,     0,   131,     0,     0,
     255,     0,     0,     0,     0,     0,     0,   250,   251,   252,
     253,   159,     0,     0,     0,     0,     0,     0,   133,   161,
       0,     0,   162,     0,     0,   163,   164,   254,     0,     0,
     166,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,   193,
     194,     0,     0,     0,   198,   199,   200,     0,   202,     0,
     204,   205,   206,     0,     0,     0,     0,   211,   212,   213,
     214,   215,     0,     0,   218,     0,   220,     0,   222,     0,
       0,   224,   146,   226,   147,     0,   228,     0,   438,   230,
     231,     0,   232,   233,     0,   235,     0,   237,     0,     0,
       0,     0,     0,   150,   151,   240,   127,     0,     0,     0,
       0,   131,     0,     0,   255,     0,     0,     0,     0,     0,
       0,   250,   251,   252,   253,   159,     0,     0,     0,     0,
       0,     0,   133,   161,     0,     0,   162,     0,     0,   163,
     164,   254,     0,     0,   166,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   192,   193,   194,     0,     0,     0,   198,   199,
     200,     0,   202,     0,   204,   205,   206,     0,     0,     0,
       0,   211,   212,   213,   214,   215,     0,     0,   218,     0,
     220,     0,   222,     0,     0,   224,   146,   226,   147,     0,
     228,     0,   440,   230,   231,     0,   232,   233,     0,   235,
       0,   237,     0,     0,     0,   127,     0,   150,   151,   240,
     131,     0,     0,     0,     0,     0,     0,     0,   255,     0,
       0,     0,     0,     0,     0,   250,   251,   252,   253,   159,
       0,   133,     0,     0,     0,     0,     0,   161,     0,     0,
     162,     0,     0,   163,   164,   254,     0,     0,   166,   167,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   192,   193,   194,     0,
       0,     0,   198,   199,   200,     0,   202,     0,   204,   205,
     206,     0,     0,     0,     0,   211,   212,   213,   214,   215,
       0,     0,   218,     0,   220,   146,   222,   147,     0,   224,
       0,   226,     0,     0,   228,     0,     0,   230,   231,     0,
     232,   233,     0,   235,     0,   237,   150,   151,     0,   127,
       0,     0,     0,   240,   131,     0,     0,     0,     0,     0,
       0,     0,   255,     0,   250,   251,   252,   253,   159,     0,
     777,     0,     0,     0,     0,   133,   161,     0,     0,   162,
       0,     0,   163,   164,   254,     0,     0,   166,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   192,   193,   194,     0,     0,
       0,   198,   199,   200,     0,   202,     0,   204,   205,   206,
       0,     0,     0,     0,   211,   212,   213,   214,   215,     0,
       0,   218,     0,   220,     0,   222,     0,     0,   224,   146,
     226,   147,     0,   228,     0,     0,   230,   231,     0,   232,
     233,     0,   235,     0,   237,     0,   603,   604,     0,     0,
     150,   151,   240,   605,   606,   607,   608,   609,   610,   611,
     612,   255,     0,     0,     0,     0,     0,     0,   250,   251,
     252,   253,   159,   127,   861,     0,     0,     0,   131,     0,
     161,     0,     0,   162,     0,     0,   163,   164,   254,     0,
       0,   166,   167,     0,     0,     0,     0,     0,     0,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   192,
     193,   194,     0,     0,     0,   198,   199,   200,     0,   202,
       0,   204,   205,   206,     0,     0,     0,     0,   211,   212,
     213,   214,   215,     0,     0,   218,     0,   220,     0,   222,
       0,     0,   224,     0,   226,     0,     0,   228,     0,     0,
     230,   231,     0,   232,   233,  1037,   235,     0,   237,     0,
       0,     0,     0,   146,     0,   147,   240,     0,     0,   603,
     604,     0,     0,     0,     0,   255,   605,   606,   607,   608,
     609,   610,   611,   612,   150,   151,     0,     0,     0,     0,
     127,     0,     0,     0,     0,   131,     0,     0,     0,     0,
       0,     0,   250,   251,   252,   253,   159,     0,     0,     0,
       0,     0,     0,     0,   161,     0,   133,   162,     0,     0,
     163,   164,   254,     0,     0,   166,   167,   613,   614,   615,
     616,     0,     0,   797,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   192,   193,   194,     0,     0,     0,   198,
     199,   200,     0,   202,     0,   204,   205,   206,     0,     0,
       0,     0,   211,   212,   213,   214,   215,     0,     0,   218,
       0,   220,  1447,   222,     0,     0,   224,     0,   226,     0,
     146,   228,   147,     0,   230,   231,     0,   232,   233,     0,
     235,     0,   237,     0,     0,     0,     0,     0,     0,   127,
     240,   150,   151,     0,   131,     0,     0,     0,     0,   255,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
     251,   252,   253,   159,     0,   133,     0,     0,     0,     0,
       0,   161,     0,     0,   162,     0,     0,   163,   164,   254,
       0,     0,   166,   167,     0,     0,     0,     0,     0,     0,
     613,   614,   615,   616,     0,     0,  1034,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,   194,     0,     0,     0,   198,   199,   200,     0,
     202,     0,   204,   205,   206,     0,     0,     0,     0,   211,
     212,   213,   214,   215,     0,     0,   218,     0,   220,   146,
     222,   147,     0,   224,     0,   226,     0,     0,   228,     0,
       0,   230,   231,     0,   232,   233,     0,   235,   127,   237,
     150,   151,     0,   131,     0,     0,     0,   240,     0,     0,
       0,     0,     0,     0,     0,     0,   255,     0,   250,   251,
     252,   253,   159,     0,   133,     0,     0,     0,     0,     0,
     161,     0,     0,   162,     0,     0,   163,   164,   254,     0,
       0,   166,   167,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   192,
     193,   194,     0,     0,     0,   198,   199,   200,     0,   202,
       0,   204,   205,   206,     0,     0,     0,     0,   211,   212,
     213,   214,   215,     0,     0,   218,     0,   220,   146,   222,
     147,     0,   224,     0,   226,     0,     0,   228,     0,     0,
     230,   231,     0,   232,   233,     0,   235,     0,   237,   150,
     151,     0,     0,     0,     0,     0,   240,     0,     0,     0,
       0,     0,     0,     0,     0,   255,     0,   250,   251,   252,
     253,   159,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,   162,     0,     0,   163,   164,   254,     0,     0,
     166,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   192,   193,
     194,     0,     0,     0,   198,   199,   200,     0,   202,     0,
     204,   205,   206,     0,     0,     0,     0,   211,   212,   213,
     214,   215,     0,     0,   218,     0,   220,     0,   222,     0,
       0,   224,     0,   226,     0,     0,   228,     0,     0,   230,
     231,     0,   232,   233,     0,   235,     0,   237,     0,     0,
       7,     8,     9,     0,     0,   240,     0,    10,     0,     0,
       0,    11,     0,    12,  1302,    13,    14,    15,    16,    17,
    -493,     0,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,     0,     0,     0,     0,    29,     0,
       0,    30,     0,     0,     0,     0,     0,     0,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    37,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    40,    41,    42,    43,    44,
       0,     0,     0,     0,     0,    45,    46,    47,  -242,  -242,
      48,    49,    50,     0,    51,    52,    53,     0,     0,    54,
    -242,     0,    55,     0,    56,    57,     0,     0,     0,     0,
      58,    59,     0,     0,     0,     0,     0,    60,     0,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,     0,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,     0,     0,     0,     0,
      90,    91,    92,     0,     0,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,    97,    98,     0,     0,     0,     0,    99,     0,
       0,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,   100,     0,
       0,     0,   101,     0,     7,     8,     9,   102,     0,     0,
     103,    10,     0,     0,   104,    11,     0,    12,     0,    13,
      14,    15,    16,    17,  -493,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,     0,     0,
       0,     0,    29,   -16,   -16,    30,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,    48,    49,    50,     0,    51,    52,
      53,     0,     0,    54,     0,     0,    55,     0,    56,    57,
       0,     0,     0,     0,    58,    59,     0,     0,     0,     0,
       0,    60,     0,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,     0,    80,    81,    82,    83,    84,    85,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,     0,     0,     0,    90,    91,    92,     0,     0,    93,
      94,    95,   613,   614,   615,   616,     0,     0,  1064,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,     0,     0,
       0,     0,    99,     0,     0,   603,   604,     0,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,   100,     0,     0,     0,   101,     0,     7,     8,
       9,   102,     0,     0,   103,    10,     0,     0,   104,    11,
       0,    12,     0,    13,    14,    15,    16,    17,  -493,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,   -16,     0,     0,     0,    29,   -16,     0,    30,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,   603,   604,     0,    37,    38,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,     0,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,    45,    46,    47,     0,     0,    48,    49,
      50,     0,    51,    52,    53,     0,     0,    54,     0,     0,
      55,     0,    56,    57,     0,     0,     0,     0,    58,    59,
       0,     0,     0,     0,     0,    60,     0,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,     0,     0,     0,    90,    91,
      92,     0,     0,    93,    94,    95,   613,   614,   615,   616,
     603,   604,  1161,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,     0,    96,
      97,    98,   603,   604,     0,     0,    99,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
     101,     0,     0,     0,     0,   102,   603,   604,   103,     0,
       0,     0,   104,   605,   606,   607,   608,   609,   610,   611,
     612,     0,     0,   613,   614,   615,   616,   603,   604,  1162,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   603,   604,     0,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   603,   604,     0,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   603,   604,     0,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   603,   604,     0,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   603,   604,     0,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   603,   604,     0,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,   603,   604,  1164,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,     0,   613,   614,   615,   616,   603,   604,  1165,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   603,   604,     0,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   603,   604,  1166,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,   613,   614,
     615,   616,     0,     0,  1180,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   615,   616,     0,     0,  1217,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   614,
     615,   616,     0,     0,  1224,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   615,   616,     0,     0,  1225,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   614,
     615,   616,     0,     0,  1245,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   615,   616,     0,     0,  1297,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   614,
     615,   616,   603,   604,  1320,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
     603,   604,  1321,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,   613,   614,
     615,   616,     0,     0,  1328,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   615,   616,   603,   604,  1334,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   603,   604,  1335,     0,
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
     612,     0,     0,   613,   614,   615,   616,   603,   604,  1375,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,   603,   604,  1428,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
     603,   604,     0,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,   613,   614,
     615,   616,   603,   604,  1434,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,     0,     0,  1435,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  1508,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  1513,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  1527,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  1539,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  1544,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,   603,   604,  1545,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,   613,   614,
     615,   616,   603,   604,  1546,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
       0,     0,  1549,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,   603,   604,  1577,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,     0,   613,   614,   615,   616,   603,   604,  1584,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   603,   604,     0,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   603,   604,     0,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   603,   604,     0,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   603,   604,     0,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   603,   604,     0,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   603,   604,     0,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   603,   604,  1589,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,     0,     0,   613,   614,   615,   616,   603,   604,  1592,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   603,   604,     0,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
     603,   604,  1625,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,   613,   614,
     615,   616,     0,     0,  1650,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   615,   616,     0,     0,  1651,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   614,
     615,   616,     0,     0,  1673,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   615,   616,     0,     0,  1687,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   614,
     615,   616,     0,     0,  1802,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   615,   616,     0,     0,  1803,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   614,
     615,   616,   603,   604,  1804,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   603,   604,  1806,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,   613,   614,
     615,   616,     0,     0,  1812,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   615,   616,   603,   604,  1815,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,   603,   604,  1820,     0,     0,
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
       0,     0,     0,   613,   614,   615,   616,   603,   604,  1821,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   603,   604,  1824,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,   603,   604,     0,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,   613,   614,
     615,   616,   603,   604,  1833,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
       0,     0,  1834,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,  1835,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
       0,     0,  1838,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,  1842,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
       0,     0,  1857,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,     0,     0,  1877,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
     603,   604,  1897,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,   613,   614,
     615,   616,   603,   604,  1898,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,     0,     0,  1901,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,   603,   604,  1907,     0,
       0,     0,     0,   605,   606,   607,   608,   609,   610,   611,
     612,     0,     0,   613,   614,   615,   616,   603,   604,  1913,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   603,   604,     0,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   603,   604,     0,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   603,   604,     0,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   603,   604,     0,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   603,   604,     0,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   603,   604,     0,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,   603,   604,  1914,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,     0,   613,   614,   615,   616,   603,   604,  1915,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   603,   604,     0,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   603,   604,  1918,     0,     0,     0,     0,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,   613,   614,
     615,   616,     0,     0,  1922,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   615,   616,     0,     0,  1954,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   614,
     615,   616,     0,     0,  1956,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   615,   616,     0,     0,  1957,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   614,
     615,   616,     0,     0,  1959,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   615,   616,     0,     0,  1965,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   614,
     615,   616,   603,   604,  1968,     0,     0,     0,     0,   605,
     606,   607,   608,   609,   610,   611,   612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
     603,   604,  1972,     0,     0,     0,     0,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,   613,   614,
     615,   616,     0,     0,  1980,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   615,   616,   603,   604,  1981,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   603,   604,  1982,     0,
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
     612,     0,     0,   613,   614,   615,   616,   603,   604,  1988,
       0,     0,     0,     0,   605,   606,   607,   608,   609,   610,
     611,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   613,   614,   615,   616,   603,   604,  2004,     0,     0,
       0,     0,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   614,
     615,   616,     0,     0,  2022,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  2024,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  2026,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  2027,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  2047,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  2049,     0,     0,     0,     0,     0,     0,
       0,     0,   613,   614,   615,   616,     0,     0,  2056,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   614,   615,
     616,     0,     0,  2075,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   614,
     615,   616,     0,     0,  2076,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   613,   614,   615,   616,
       0,     0,  2088
};

static const yytype_int16 yycheck[] =
{
       3,   268,    15,    16,    44,     1,     4,    12,     4,     7,
     485,     1,     4,    98,     4,     7,    75,    12,    21,   286,
      75,    24,    40,    43,    44,     4,     5,     0,    41,   112,
      33,    11,    77,  1676,    37,    38,     3,    61,   255,    42,
       7,     8,     9,    10,    58,   262,    60,    61,     7,   454,
     455,    54,    55,    56,    77,     3,    25,    53,    28,     7,
       8,     9,    10,    53,    75,    76,    77,    70,    71,    72,
      95,   255,   155,    12,    58,    44,    60,    61,   262,    76,
      77,   101,   110,    86,    87,    88,   111,   111,   173,    92,
      70,    71,    72,    73,    74,    75,    76,   255,   101,   102,
     103,   104,     4,     5,   262,     4,    12,   260,     7,   262,
     112,   113,    70,    71,    72,    73,    74,    75,    76,   112,
     113,   100,   160,    28,    63,    64,   111,    16,    33,   112,
     113,    70,    71,    72,    73,    74,    75,    76,    77,   255,
     112,   113,     4,     5,   260,   255,  1309,  1310,    74,    75,
      76,    77,   262,   155,    23,    44,   173,    63,    64,    95,
     112,   112,   155,   166,    70,    71,    72,    73,    74,    75,
      76,    77,   155,    70,    71,    72,    73,    74,    75,    76,
     585,   261,   587,   155,   261,    70,    71,    72,    73,    74,
      75,    76,   260,    44,   262,    70,    71,    72,    73,    74,
      75,    76,   261,   155,   155,    59,   261,   255,   255,   254,
     255,   256,   257,   260,   262,   255,   195,   196,   197,    92,
      93,     4,     5,    70,    71,    72,    73,    74,    75,    76,
     260,   104,   262,   256,   257,    89,    90,    91,  1881,   242,
     255,  1884,    96,   254,   255,   256,   257,   262,   255,   263,
     255,   255,   255,   260,    75,   260,   260,   254,   255,   256,
     257,   264,     3,   261,   255,   260,     7,     8,     9,   261,
      75,   262,   268,    81,    82,   255,    24,   280,   268,   263,
      88,   112,   285,   347,   348,   261,   350,   254,   255,   292,
     286,   309,   310,   195,   196,   197,   286,   255,   260,   112,
     262,   365,   366,   111,   262,  1948,   254,   255,  1951,   373,
     260,   112,   262,   316,   378,   254,   255,   256,   257,   383,
     255,   385,   112,   113,   327,   328,   329,   262,   254,   255,
     256,   257,   335,   397,   261,   399,   261,   401,   255,   403,
     404,   405,   261,   260,   112,   262,   255,   411,   254,   255,
     256,   257,   416,   262,   260,   358,   359,   255,   255,   112,
     424,   261,   260,   260,   367,   262,   369,   431,   371,   372,
     255,   374,   375,   376,   377,   260,   112,   380,   381,   382,
     255,   384,   649,   386,   261,   388,   162,   262,   161,   392,
     393,   394,   395,   396,   263,   398,   265,   400,   261,   402,
      35,    36,   261,   406,   407,   408,   409,   410,   255,   412,
     413,   414,   415,   260,   417,   418,   419,   420,   421,   422,
     423,   261,   425,   426,   427,   428,   429,   430,  2071,   432,
    2073,   434,    14,   436,    16,   438,    18,   440,   261,   442,
     443,   444,   445,   446,   255,   255,  2089,   261,  2091,   260,
     260,   262,   262,   112,   457,     4,     5,   255,   255,    41,
     480,   481,    44,   260,   262,   262,   469,    49,     4,     5,
      70,    71,    72,    73,    74,    75,    76,   480,   255,   482,
     261,     4,     5,   260,   172,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   255,   261,
     513,   531,   261,   260,  1677,   518,   519,  1680,    70,    71,
      72,    73,    74,    75,    76,   259,   260,   172,    70,    71,
      72,    73,    74,    75,    76,   261,   255,   255,   541,   542,
     543,   544,   545,   262,   262,   548,     4,     5,   551,   261,
     553,   571,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   261,   565,   566,   567,   568,   569,   570,   571,   572,
      86,    87,   575,   255,   577,   578,   579,   580,   581,   255,
     262,   584,   255,   586,   260,   588,   589,   590,   155,   262,
     261,   594,   595,   596,   597,   598,   599,   600,   601,   255,
      51,   255,   471,   472,   260,   155,   262,   155,   262,   255,
      13,   261,    63,    64,   260,   155,   262,   261,   682,    70,
      71,    72,    73,    74,    75,    76,    77,   261,  1791,   255,
     255,   261,   696,   255,   260,   260,   262,   701,   260,   703,
     262,   705,   706,    20,    21,   255,   261,   711,   712,   652,
     260,   255,   262,   649,   261,   255,   260,   675,   262,   649,
      63,    64,   262,     4,     5,    49,    50,    70,    71,    72,
      73,    74,    75,    76,    77,     4,     5,   680,   261,    70,
      71,    72,    73,    74,    75,    76,    63,    64,    39,    40,
     693,    44,   261,    70,    71,    72,    73,    74,    75,    76,
      77,   255,   255,   255,   573,   574,   260,   260,   260,   262,
      63,    64,   979,   255,   717,   261,   719,    70,    71,    72,
      73,    74,    75,    76,    77,   728,   261,   255,   255,   261,
      46,   255,    63,   736,   262,   262,   739,   740,   262,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,     4,
       5,   261,   816,   817,    70,    71,    72,    73,    74,    75,
      76,    77,    70,    71,    72,    73,    74,    75,    76,    77,
     255,   255,   255,   261,   777,   260,   840,   262,   262,   262,
     783,   261,   785,   261,   787,   261,   789,  1950,   791,   261,
    1953,  1266,    46,   255,  1269,   798,   665,   666,    60,    61,
     262,   670,   671,   254,   255,   256,   257,   810,   811,    63,
      64,   246,   247,   248,   249,   250,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    60,    61,   261,   261,
     261,    70,    71,    72,    73,    74,    75,    76,    77,   255,
     255,   255,   255,  2006,   260,   155,  2009,   262,   262,   262,
     255,   254,   255,   256,   257,   255,   255,   262,   861,   261,
     261,   260,   262,   866,   255,   868,   869,   870,   871,   260,
      70,    71,    72,    73,    74,    75,    76,   254,   255,   256,
     257,   261,   261,   261,    70,    71,    72,    73,    74,    75,
      76,   255,   255,   255,   261,   261,   261,   255,   262,   262,
     262,   254,   255,   256,   257,    63,    64,    14,     4,    16,
      58,    18,    70,    71,    72,    73,    74,    75,    76,    77,
    2083,   255,  2085,   254,   255,   256,   257,    44,   262,   255,
     255,   261,  2095,  2096,    41,   260,   262,    44,   254,   255,
     256,   257,    49,   255,    63,    64,   254,   255,   256,   257,
     262,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,   261,   261,   261,   261,   261,    70,    71,    72,    73,
      74,    75,    76,    77,   987,   988,    70,    71,    72,    73,
      74,    75,    76,   979,   261,   255,   261,   261,   261,   979,
     260,    71,   995,    73,    74,    75,    76,    77,   255,   255,
     254,   255,   256,   257,   255,   262,   262,   260,  1011,   260,
      44,  1014,   255,   255,  1017,   254,   255,   256,   257,   262,
     262,   260,   255,   262,   261,   261,  1293,   260,    71,    72,
      73,    74,    75,    76,    77,   255,   255,   261,  1041,   261,
     260,     5,  1045,   262,    73,    74,    75,    76,    77,  1052,
     255,   255,   261,  1056,   261,   255,  1059,   262,   262,    14,
     260,    16,   255,    18,   261,   261,   255,   260,  1071,   255,
    1073,  1074,  1075,   262,   260,  1078,  1079,  1080,   255,  1082,
     261,   261,   261,  1086,   255,   262,    41,  1090,  1091,    44,
    1093,   262,   261,  1096,    49,  1098,   254,   255,   256,   257,
     255,  1104,  1105,   255,   262,  1108,   260,   262,   260,  1112,
    1113,  1114,  1115,   255,   261,  1118,   261,   261,   260,  1122,
     989,   990,  1125,   992,   993,   261,  1129,   261,  1131,   261,
    1133,   261,  1135,  1136,  1137,   254,   255,   256,   257,   255,
     255,   260,   255,   262,   260,   260,   260,   260,   260,   255,
     254,   255,   256,   257,   260,    14,  1152,    16,   262,    18,
     261,   255,  1152,   255,   261,  1168,   260,  1170,   260,  1172,
     261,   261,   261,   261,   254,   255,   256,   257,  1181,   255,
    1183,   260,    41,   255,   260,    44,  1189,   255,   260,   255,
      49,   261,   260,   255,   260,   255,    63,    64,   260,   260,
     260,    43,   261,    70,    71,    72,    73,    74,    75,    76,
      77,   254,   255,   256,   257,   255,   255,   255,   255,   261,
     260,   260,   260,   260,  1227,   254,   255,   256,   257,   255,
     255,   255,   255,   255,   260,   260,   260,   260,   260,    77,
     261,   261,  1245,  1246,  1247,  1248,    63,    64,   261,   261,
     261,  1254,   261,    70,    71,    72,    73,    74,    75,    76,
      77,   255,   261,   255,  1267,   255,   260,  1270,   260,  1272,
     260,  1140,   255,   255,   261,   261,  1340,   260,   260,  1343,
      63,    64,   261,   261,  1348,   261,   261,    70,    71,    72,
      73,    74,    75,    76,    77,   260,  1299,  1293,   260,  1302,
      63,    64,   260,  1293,   260,  1325,  1326,    70,    71,    72,
      73,    74,    75,    76,    77,   255,   255,   255,   255,   260,
     260,   260,   260,   260,  1327,  1328,   255,    63,    64,  1332,
     260,   260,   260,  1336,    70,    71,    72,    73,    74,    75,
      76,    77,   255,   261,   261,   255,   261,   260,  1351,  1352,
     260,  1354,   255,  1356,   255,   260,  1359,   260,   255,   260,
    1363,  1364,   255,   260,   255,    75,  1369,   260,  1371,   260,
    1373,   255,  1375,   262,  1438,   262,   260,   262,  1381,   262,
    1383,   261,  1385,   261,  1387,  1388,  1389,   254,   255,   256,
     257,  1455,  1395,   260,   255,   262,  1399,   255,   260,   260,
     255,   255,   260,  1406,   255,   260,   260,   260,   255,   260,
    1413,   255,  1415,   260,  1417,   255,   260,  1420,   255,  1422,
     260,  1424,   255,   260,   255,  1428,  1429,   260,   255,   260,
     255,  1434,  1435,   260,   260,   260,   255,   254,   255,   256,
     257,   260,   255,   260,    46,   262,   255,   260,   255,  1318,
    1319,   260,   255,   260,   255,   255,   261,   260,    43,   260,
     260,  1464,  1465,  1466,  1467,   255,   261,   261,   261,   261,
     260,   254,   255,   256,   257,   255,   255,   260,   255,   262,
     260,   260,   255,   260,  1497,  1498,    58,   260,    10,   260,
     260,   254,   255,   256,   257,    63,    64,   261,   260,   262,
    1503,   260,    70,    71,    72,    73,    74,    75,    76,    77,
    1777,  1778,  1515,   260,   260,   260,   260,   255,   254,   255,
     256,   257,   260,   255,  1527,   260,   262,   255,   260,  1532,
    1533,   262,   260,   262,   260,  1538,  1539,   255,  1541,  1542,
      63,    64,   260,   262,   260,   262,  1549,    70,    71,    72,
      73,    74,    75,    76,    77,  1558,   255,   255,   255,  1562,
     261,   260,   260,   260,   255,  1568,   255,  1570,   255,   260,
     255,   260,   262,   260,  1577,   260,   255,  1580,  1581,   261,
      43,   260,   262,    90,    91,    92,    93,    94,  1591,  1592,
     260,  1594,   261,  1596,   255,  1598,  1599,   104,   262,   260,
     255,   261,   255,   110,   111,   260,  1873,   260,   262,   116,
     117,   118,   119,   120,   255,  1618,   262,   255,   255,   260,
     255,  1624,   260,   260,   255,   260,   255,   255,   255,   260,
    1694,   260,   260,   260,  1698,   261,  1639,   255,   255,   255,
    1643,   255,   260,   260,   260,    85,   260,  1650,    85,   255,
    1653,  1520,  1521,  1656,   260,   255,   255,   255,   165,   255,
     260,   260,   260,     5,   260,   262,   255,   255,  1671,   255,
    1937,   260,   260,  1940,   260,   255,   255,   255,   262,   262,
     260,   260,   260,  1686,  1687,  1688,   254,   255,   256,   257,
     255,   255,   255,   262,   262,   260,   260,   260,  1701,   260,
     255,  1704,   255,   262,  1707,   260,   255,   260,  1711,   255,
    1713,   260,   255,   260,   260,   255,  1719,   260,  1721,   255,
     260,   260,  1725,  1726,   260,   255,  1729,  1994,   260,   260,
     260,   254,   255,   256,   257,  1738,     2,   260,   255,  1742,
     255,   255,  1745,   260,  1747,   260,   260,  1750,  1751,   255,
    1753,    17,   255,   255,   260,   255,   255,   260,   260,   260,
     260,   260,   260,  1766,    30,   260,   260,    33,   255,   255,
      36,    37,    38,   260,   260,   255,    42,    43,    44,   255,
     260,  1777,  1778,   260,   260,    51,   255,  1777,  1778,   255,
     255,   260,   260,  1796,   260,   260,   255,  1800,    63,    64,
    1803,   260,   260,   260,  1807,    70,    71,    72,    73,    74,
      75,    76,    77,   255,   260,   260,   255,   255,   260,    63,
      64,   260,   260,    58,   260,    91,    70,    71,    72,    73,
      74,    75,    76,    77,   260,   101,  1839,   255,  1841,  1842,
     262,  1844,   260,  1846,    63,    64,   262,   260,   260,    43,
     261,    70,    71,    72,    73,    74,    75,    76,    77,   255,
     255,   255,   255,   255,   260,   260,   260,   260,   260,   255,
     136,   255,  1875,   255,   260,   255,   260,  1873,   260,   255,
     260,   255,   255,  1873,   260,   255,   260,   260,    38,   261,
     260,   262,   255,  1896,  1897,  1898,  1899,   260,  1901,  1902,
     255,   262,   262,  1906,   262,   260,   260,  1910,   260,   260,
     260,  1914,  1915,  1916,   260,  1918,    43,   262,   261,  1922,
    1923,   262,   262,   261,    58,  1928,    63,    64,  1931,   262,
    1933,   262,    75,    70,    71,    72,    73,    74,    75,    76,
      77,  1937,    75,    75,  1940,    48,  1949,  1937,    58,   261,
    1940,   262,  1955,  1956,   262,  1958,  1959,  1960,    63,    64,
     260,    47,   261,   261,   261,    70,    71,    72,    73,    74,
      75,    76,    77,   261,    58,   241,   242,    75,  1981,   262,
     262,    38,  1985,   261,  1987,  1988,   261,   260,   260,   254,
     255,   256,   257,  1152,     4,     4,   262,   262,  1994,  2002,
      53,   267,    53,   485,  1994,     5,   995,   675,  1854,   994,
     254,   255,   256,   257,   280,  2067,  2019,   991,   262,   285,
    2023,  1503,   672,  2026,  2027,  1305,   292,    -1,  2031,   688,
      -1,    -1,  2035,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,  2044,    -1,   262,    -1,    -1,  2049,    -1,    -1,   315,
      -1,   317,    63,    64,    -1,  2058,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,  2075,  2076,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2088,    -1,    -1,    -1,    -1,
    2093,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   364,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   254,   255,   256,
     257,    63,    64,    -1,    -1,   262,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   449,   450,   451,   452,    63,    64,    -1,
     456,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   468,    -1,    -1,    -1,    -1,   473,   474,    -1,
     476,   477,   478,   479,   480,   481,    -1,    63,    64,    -1,
      -1,   487,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,    -1,    -1,    -1,    -1,    -1,
     546,   547,   548,   549,   550,    -1,   552,    -1,   554,    -1,
      -1,   254,   255,   256,   257,    -1,    -1,    -1,   564,   262,
      -1,    -1,    -1,    -1,    -1,   571,    -1,    -1,    -1,    -1,
     576,    -1,   254,   255,   256,   257,    63,    64,    -1,    -1,
     262,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,   254,   255,
     256,   257,    -1,    -1,   650,    -1,   262,    -1,    -1,   655,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   668,   669,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,    -1,   681,   262,     3,     4,     5,
     686,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,   697,   698,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   738,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,   254,   255,   256,
     257,    97,    -1,   260,    -1,   101,   102,    -1,    -1,   105,
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
      -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1702,  1703,    -1,    -1,
    1706,   254,   255,   256,   257,    -1,    -1,   326,  1714,   262,
      -1,    -1,    -1,   332,    -1,    -1,    -1,  1723,  1724,    -1,
     339,   340,  1728,    -1,    -1,    -1,    -1,  1733,    -1,    -1,
      -1,  1737,   351,   352,   353,   354,   355,   356,   357,    -1,
      -1,   360,   361,   362,   363,    63,    64,    -1,  1754,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1779,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1790,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,  1802,    -1,  1804,    -1,
    1806,    -1,    -1,    -1,    -1,    -1,  1812,    -1,    -1,  1815,
      -1,  1817,    -1,    -1,  1820,  1821,    -1,    -1,  1824,    -1,
      -1,    -1,    -1,    -1,    -1,  1831,    -1,  1833,  1834,  1835,
      -1,    -1,  1838,    -1,    -1,    -1,    -1,    -1,  1844,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   465,   466,   467,    -1,
      -1,  1857,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1868,    -1,    -1,    63,    64,   486,    -1,    -1,
    1876,  1877,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1904,    -1,
      -1,  1907,    -1,    -1,    -1,  1911,    -1,  1913,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,    -1,  1952,    -1,  1954,    -1,
      -1,  1957,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1965,
      -1,    -1,  1968,    -1,    -1,    -1,  1972,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1980,    -1,  1982,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,  2004,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2022,    -1,  2024,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2047,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2056,    30,    31,    -1,    -1,    -1,   254,   255,   256,   257,
      -1,    -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   691,    -1,    -1,    -1,   695,    -1,    -1,    -1,
     699,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,   714,   715,    -1,    -1,    -1,
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
      -1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1609,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
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
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,  1801,   254,    -1,    -1,  1805,    -1,    -1,    -1,
     261,   262,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    30,
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
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
     261,   262,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    30,
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
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
     261,   262,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    30,
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
      -1,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
     151,   152,   153,   154,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,   167,   168,   169,   170,
     171,    -1,    -1,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,
     261,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,   150,    -1,    -1,    -1,   154,    -1,
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
      -1,    -1,     3,     4,     5,   261,     7,     8,     9,    10,
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
      -1,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
     151,    -1,    -1,   154,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,   167,   168,   169,   170,
     171,    -1,    -1,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,
     261,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
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
      -1,   227,   228,   229,   230,    -1,   232,   233,    -1,   235,
     236,   237,    -1,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,
      -1,    -1,     3,     4,     5,   261,     7,     8,     9,    10,
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
      -1,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,   154,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,   167,   168,   169,   170,
     171,    -1,    -1,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,
     261,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    -1,    63,    64,    65,
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
      -1,   227,   228,   229,   230,    -1,   232,   233,    -1,   235,
     236,   237,    -1,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,
      -1,    -1,     3,     4,     5,   261,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,
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
      -1,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,   167,   168,   169,   170,
     171,    -1,    -1,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,
     261,     7,     8,     9,    10,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,
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
      -1,   227,   228,   229,   230,    -1,   232,   233,    -1,   235,
     236,   237,    -1,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,
      -1,    -1,     3,     4,     5,   261,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,
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
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,
     261,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,
      64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,    -1,    -1,   143,   144,   145,
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
      -1,    -1,     3,     4,     5,   261,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
      -1,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,
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
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,
     261,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    30,    31,    -1,    -1,    34,    -1,
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
      -1,   227,   228,   229,   230,    -1,   232,   233,    -1,   235,
     236,   237,    -1,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,
      -1,    -1,     3,     4,     5,   261,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,
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
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,
     261,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    30,    31,    -1,    -1,    -1,    -1,
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
      -1,   227,   228,   229,   230,    -1,   232,   233,    -1,   235,
     236,   237,    -1,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,
      -1,    -1,     3,     4,     5,   261,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,
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
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,
     261,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    30,    31,    -1,    -1,    -1,    -1,
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
      -1,   227,   228,   229,   230,    -1,   232,   233,    -1,   235,
     236,   237,    -1,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,
      -1,    -1,     3,     4,     5,   261,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,
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
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,
     261,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    30,    31,    -1,    -1,    -1,    -1,
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
      -1,   227,   228,   229,   230,    -1,   232,   233,    -1,   235,
     236,   237,    -1,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,
      -1,    -1,     3,     4,     5,   261,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,
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
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,
     261,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    30,    31,    -1,    -1,    -1,    -1,
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
      -1,   227,   228,   229,   230,    -1,   232,   233,    -1,   235,
     236,   237,    -1,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,
      -1,    -1,     3,     4,     5,   261,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,
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
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,
     261,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    30,    31,    -1,    -1,    -1,    -1,
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
      -1,   227,   228,   229,   230,    -1,   232,   233,    -1,   235,
     236,   237,    -1,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,    -1,    -1,    -1,   251,   252,    -1,   254,    -1,
      -1,    -1,     3,     4,     5,   261,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    30,
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
     221,   222,   223,   224,   225,    -1,   227,   228,   229,   230,
      -1,   232,   233,    -1,   235,   236,   237,    -1,   239,   240,
     241,   242,   243,   244,   245,    -1,    -1,    -1,    -1,    -1,
     251,   252,    -1,   254,    -1,    -1,    -1,     3,     4,     5,
     261,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,    -1,
      -1,    -1,    -1,   262,    30,    31,    -1,    -1,    -1,    -1,
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
      -1,   227,   228,   229,   230,    -1,   232,   233,    -1,   235,
     236,   237,    -1,   239,   240,   241,   242,   243,   244,   245,
      -1,    -1,     5,    -1,    -1,   251,   252,    10,   254,    -1,
      -1,    -1,    -1,    -1,    -1,   261,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
     254,   255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,   105,    -1,   107,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,    -1,   126,   127,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,    -1,    31,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,    -1,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   196,   197,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,    -1,   207,   208,   209,    -1,    -1,    -1,
      -1,   214,   215,   216,   217,   218,    -1,    -1,   221,    -1,
     223,   105,   225,   107,    -1,   228,    -1,   230,    -1,    -1,
     233,    -1,    -1,   236,   237,    -1,   239,   240,    -1,   242,
       5,   244,   126,   127,    -1,    10,    -1,    -1,    -1,   252,
     254,   255,   256,   257,    -1,    -1,   260,    -1,   261,   262,
     144,   145,   146,   147,   148,    -1,    31,    -1,   254,   255,
     256,   257,   156,    -1,    -1,   159,   262,    -1,   162,   163,
     164,    -1,    -1,   167,   168,    -1,    -1,    -1,    -1,   254,
     255,   256,   257,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   196,   197,    -1,    -1,    -1,   201,   202,   203,
      -1,   205,    -1,   207,   208,   209,    -1,    -1,    -1,    -1,
     214,   215,   216,   217,   218,    -1,    -1,   221,    -1,   223,
     105,   225,   107,    -1,   228,    -1,   230,    -1,    -1,   233,
      -1,    -1,   236,   237,    -1,   239,   240,    -1,   242,    -1,
     244,   126,   127,    -1,     5,    -1,    -1,    -1,   252,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,   262,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      31,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,    -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,    -1,   207,   208,   209,    -1,    -1,    -1,    -1,   214,
     215,   216,   217,   218,    -1,    -1,   221,    -1,   223,    -1,
     225,    -1,    -1,   228,   105,   230,   107,    -1,   233,    -1,
     111,   236,   237,    -1,   239,   240,    -1,   242,    -1,   244,
      -1,    -1,    -1,    -1,    -1,   126,   127,   252,     5,    -1,
      -1,    -1,    -1,    10,    -1,    -1,   261,   262,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    31,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   196,   197,    -1,    -1,    -1,
     201,   202,   203,    -1,   205,    -1,   207,   208,   209,    -1,
      -1,    -1,    -1,   214,   215,   216,   217,   218,    -1,    -1,
     221,    -1,   223,    -1,   225,    -1,    -1,   228,   105,   230,
     107,    -1,   233,    -1,   111,   236,   237,    -1,   239,   240,
      -1,   242,    -1,   244,    -1,    -1,    -1,    -1,    -1,   126,
     127,   252,     5,    -1,    -1,    -1,    -1,    10,    -1,    -1,
     261,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    31,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,
     197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,    -1,
     207,   208,   209,    -1,    -1,    -1,    -1,   214,   215,   216,
     217,   218,    -1,    -1,   221,    -1,   223,    -1,   225,    -1,
      -1,   228,   105,   230,   107,    -1,   233,    -1,   111,   236,
     237,    -1,   239,   240,    -1,   242,    -1,   244,    -1,    -1,
      -1,    -1,    -1,   126,   127,   252,     5,    -1,    -1,    -1,
      -1,    10,    -1,    -1,   261,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    31,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,    -1,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   196,   197,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,    -1,   207,   208,   209,    -1,    -1,    -1,
      -1,   214,   215,   216,   217,   218,    -1,    -1,   221,    -1,
     223,    -1,   225,    -1,    -1,   228,   105,   230,   107,    -1,
     233,    -1,   111,   236,   237,    -1,   239,   240,    -1,   242,
      -1,   244,    -1,    -1,    -1,     5,    -1,   126,   127,   252,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
      -1,    31,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   196,   197,    -1,
      -1,    -1,   201,   202,   203,    -1,   205,    -1,   207,   208,
     209,    -1,    -1,    -1,    -1,   214,   215,   216,   217,   218,
      -1,    -1,   221,    -1,   223,   105,   225,   107,    -1,   228,
      -1,   230,    -1,    -1,   233,    -1,    -1,   236,   237,    -1,
     239,   240,    -1,   242,    -1,   244,   126,   127,    -1,     5,
      -1,    -1,    -1,   252,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   261,    -1,   144,   145,   146,   147,   148,    -1,
     150,    -1,    -1,    -1,    -1,    31,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   196,   197,    -1,    -1,
      -1,   201,   202,   203,    -1,   205,    -1,   207,   208,   209,
      -1,    -1,    -1,    -1,   214,   215,   216,   217,   218,    -1,
      -1,   221,    -1,   223,    -1,   225,    -1,    -1,   228,   105,
     230,   107,    -1,   233,    -1,    -1,   236,   237,    -1,   239,
     240,    -1,   242,    -1,   244,    -1,    63,    64,    -1,    -1,
     126,   127,   252,    70,    71,    72,    73,    74,    75,    76,
      77,   261,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,     5,   150,    -1,    -1,    -1,    10,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
      -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,
      -1,   207,   208,   209,    -1,    -1,    -1,    -1,   214,   215,
     216,   217,   218,    -1,    -1,   221,    -1,   223,    -1,   225,
      -1,    -1,   228,    -1,   230,    -1,    -1,   233,    -1,    -1,
     236,   237,    -1,   239,   240,    97,   242,    -1,   244,    -1,
      -1,    -1,    -1,   105,    -1,   107,   252,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,   261,    70,    71,    72,    73,
      74,    75,    76,    77,   126,   127,    -1,    -1,    -1,    -1,
       5,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    31,   159,    -1,    -1,
     162,   163,   164,    -1,    -1,   167,   168,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   196,   197,    -1,    -1,    -1,   201,
     202,   203,    -1,   205,    -1,   207,   208,   209,    -1,    -1,
      -1,    -1,   214,   215,   216,   217,   218,    -1,    -1,   221,
      -1,   223,    97,   225,    -1,    -1,   228,    -1,   230,    -1,
     105,   233,   107,    -1,   236,   237,    -1,   239,   240,    -1,
     242,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,     5,
     252,   126,   127,    -1,    10,    -1,    -1,    -1,    -1,   261,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,    -1,    31,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,    -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,
     254,   255,   256,   257,    -1,    -1,   260,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,
     205,    -1,   207,   208,   209,    -1,    -1,    -1,    -1,   214,
     215,   216,   217,   218,    -1,    -1,   221,    -1,   223,   105,
     225,   107,    -1,   228,    -1,   230,    -1,    -1,   233,    -1,
      -1,   236,   237,    -1,   239,   240,    -1,   242,     5,   244,
     126,   127,    -1,    10,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   261,    -1,   144,   145,
     146,   147,   148,    -1,    31,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
      -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,
     196,   197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,
      -1,   207,   208,   209,    -1,    -1,    -1,    -1,   214,   215,
     216,   217,   218,    -1,    -1,   221,    -1,   223,   105,   225,
     107,    -1,   228,    -1,   230,    -1,    -1,   233,    -1,    -1,
     236,   237,    -1,   239,   240,    -1,   242,    -1,   244,   126,
     127,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   261,    -1,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   195,   196,
     197,    -1,    -1,    -1,   201,   202,   203,    -1,   205,    -1,
     207,   208,   209,    -1,    -1,    -1,    -1,   214,   215,   216,
     217,   218,    -1,    -1,   221,    -1,   223,    -1,   225,    -1,
      -1,   228,    -1,   230,    -1,    -1,   233,    -1,    -1,   236,
     237,    -1,   239,   240,    -1,   242,    -1,   244,    -1,    -1,
       4,     5,     6,    -1,    -1,   252,    -1,    11,    -1,    -1,
      -1,    15,    -1,    17,   261,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,
      94,    95,    96,    -1,    98,    99,   100,    -1,    -1,   103,
     104,    -1,   106,    -1,   108,   109,    -1,    -1,    -1,    -1,
     114,   115,    -1,    -1,    -1,    -1,    -1,   121,    -1,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   157,   158,   159,    -1,    -1,    -1,    -1,
     164,   165,   166,    -1,    -1,   169,   170,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   196,   197,    -1,    -1,    -1,    -1,   202,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   222,    -1,
      -1,    -1,   226,    -1,     4,     5,     6,   231,    -1,    -1,
     234,    11,    -1,    -1,   238,    15,    -1,    17,    -1,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    -1,    -1,    94,    95,    96,    -1,    98,    99,
     100,    -1,    -1,   103,    -1,    -1,   106,    -1,   108,   109,
      -1,    -1,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,
      -1,   121,    -1,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   166,    -1,    -1,   169,
     170,   171,   254,   255,   256,   257,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   195,   196,   197,    -1,    -1,
      -1,    -1,   202,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,   222,    -1,    -1,    -1,   226,    -1,     4,     5,
       6,   231,    -1,    -1,   234,    11,    -1,    -1,   238,    15,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    38,    -1,    -1,    -1,    42,    43,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    63,    64,    -1,    61,    62,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    -1,    -1,    94,    95,
      96,    -1,    98,    99,   100,    -1,    -1,   103,    -1,    -1,
     106,    -1,   108,   109,    -1,    -1,    -1,    -1,   114,   115,
      -1,    -1,    -1,    -1,    -1,   121,    -1,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     166,    -1,    -1,   169,   170,   171,   254,   255,   256,   257,
      63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,   195,
     196,   197,    63,    64,    -1,    -1,   202,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
     226,    -1,    -1,    -1,    -1,   231,    63,    64,   234,    -1,
      -1,    -1,   238,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   254,   255,   256,   257,    63,    64,   260,
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
      -1,   254,   255,   256,   257,    63,    64,   260,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,   254,   255,   256,   257,    63,    64,   260,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   254,   255,   256,
     257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
      63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    63,    64,   260,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   254,   255,   256,   257,    63,    64,   260,    -1,
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
      77,    -1,    -1,   254,   255,   256,   257,    63,    64,   260,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,   256,   257,    63,    64,   260,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,   254,   255,
     256,   257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   254,   255,   256,
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
      72,    73,    74,    75,    76,    77,    -1,    -1,   254,   255,
     256,   257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
      -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,   256,   257,    63,    64,   260,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,   254,   255,   256,   257,    63,    64,   260,
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
      76,    77,   254,   255,   256,   257,    63,    64,   260,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   254,   255,   256,   257,    63,    64,   260,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
      63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   254,   255,   256,
     257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    63,    64,   260,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,   256,   257,    63,    64,   260,    -1,    -1,
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
      -1,    -1,    -1,   254,   255,   256,   257,    63,    64,   260,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   254,   255,   256,   257,    63,    64,   260,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   254,   255,
     256,   257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
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
      63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,   254,   255,
     256,   257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    63,    64,   260,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   254,   255,   256,   257,    63,    64,   260,
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
      -1,   254,   255,   256,   257,    63,    64,   260,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,   254,   255,   256,   257,    63,    64,   260,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   254,   255,   256,
     257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    63,    64,   260,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,   257,
      63,    64,   260,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   254,   255,   256,   257,    63,    64,   260,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   254,   255,   256,   257,    63,    64,   260,    -1,
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
      77,    -1,    -1,   254,   255,   256,   257,    63,    64,   260,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   254,   255,   256,   257,    63,    64,   260,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   254,   255,   256,   257,    -1,    -1,   260,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,   256,
     257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   254,   255,
     256,   257,    -1,    -1,   260,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     284,   287,   284,   287,   262,   262,   260,   287,   284,   284,
     287,   287,   284,   287,   284,   284,   287,   330,   332,    48,
     353,    60,    61,   262,    58,   287,   284,   262,   287,   262,
     261,   379,   357,   262,   262,   357,   260,   284,   284,   284,
     260,   280,   260,   260,   260,   280,   260,   260,   284,   287,
     287,   284,   260,   287,   284,   260,   284,   260,   284,   287,
     260,   260,   284,   284,   260,   287,   287,   284,   284,   287,
     284,   260,   287,   260,   260,   260,   287,   284,   260,   260,
     284,   260,   260,   284,   260,   284,   260,   284,   284,   262,
     284,   287,   261,   261,   260,   262,   262,   260,   284,   262,
     262,   262,   262,   262,   262,   262,   262,   262,    13,   323,
     267,   267,   287,    47,   352,   261,   261,   260,   262,    60,
      61,   369,   262,    58,   374,   287,   357,   284,   284,   292,
     287,   284,   287,   292,   287,   284,   260,   260,   260,   260,
     287,   260,   260,   287,   260,   287,   260,   260,   287,   287,
     260,   260,   287,   260,   260,   260,   260,   287,   260,   287,
     287,   287,   260,   260,   287,   284,   284,   284,   260,   284,
     287,   260,   284,    75,   262,   262,   316,   307,   287,   287,
     320,    46,   356,   267,   347,   284,   287,   287,   375,   261,
     379,   370,   261,   379,   260,   260,   260,   260,   260,   260,
     260,   284,   284,   284,   284,   260,   284,   284,   260,   287,
     284,   287,   260,   284,   287,   287,   284,   284,   284,   284,
     260,   260,   260,   284,   284,   260,   284,   260,   260,   284,
     284,   267,   262,   267,   354,    14,    16,    18,    41,    44,
      49,   348,   260,   262,   260,   262,   379,   284,   357,   379,
     287,   357,   287,   284,   284,   287,   284,   284,   284,   260,
     287,   287,   260,   260,   260,   287,   260,   260,   287,   284,
     287,   260,   284,   284,   284,   260,    25,    44,   308,   321,
     267,   284,   287,   357,   260,   262,   357,   260,   262,   260,
     284,   287,   284,   287,   284,   284,   260,   284,   260,   284,
      14,    16,    18,    41,    44,    49,   322,   355,   262,   262,
     284,   376,   287,   371,   284,   260,   260,   287,   284,     4,
     324,   353,   262,   379,   262,   379,   284,   284,   260,   377,
     357,   372,   357,   260,   284,   379,   379,   284,   357,   357
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
       3,     3,     6,     8,     3,     3,     5,     5,     5,     7,
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

