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
  YYSYMBOL_tSIN = 166,                     /* tSIN  */
  YYSYMBOL_tASIN = 167,                    /* tASIN  */
  YYSYMBOL_tCOS = 168,                     /* tCOS  */
  YYSYMBOL_tACOS = 169,                    /* tACOS  */
  YYSYMBOL_tTAN = 170,                     /* tTAN  */
  YYSYMBOL_tATAN = 171,                    /* tATAN  */
  YYSYMBOL_tEXP = 172,                     /* tEXP  */
  YYSYMBOL_tLOG = 173,                     /* tLOG  */
  YYSYMBOL_tSQRT = 174,                    /* tSQRT  */
  YYSYMBOL_tSQR = 175,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 176,                   /* tMYEOF  */
  YYSYMBOL_tABS = 177,                     /* tABS  */
  YYSYMBOL_tSIG = 178,                     /* tSIG  */
  YYSYMBOL_tINT = 179,                     /* tINT  */
  YYSYMBOL_tCEIL = 180,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 181,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 182,                    /* tFRAC  */
  YYSYMBOL_tROUND = 183,                   /* tROUND  */
  YYSYMBOL_tMOD = 184,                     /* tMOD  */
  YYSYMBOL_tRAN = 185,                     /* tRAN  */
  YYSYMBOL_tVAL = 186,                     /* tVAL  */
  YYSYMBOL_tLEFT = 187,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 188,                   /* tRIGHT  */
  YYSYMBOL_tMID = 189,                     /* tMID  */
  YYSYMBOL_tLEN = 190,                     /* tLEN  */
  YYSYMBOL_tMIN = 191,                     /* tMIN  */
  YYSYMBOL_tMAX = 192,                     /* tMAX  */
  YYSYMBOL_tSTR = 193,                     /* tSTR  */
  YYSYMBOL_tINKEY = 194,                   /* tINKEY  */
  YYSYMBOL_tCHR = 195,                     /* tCHR  */
  YYSYMBOL_tASC = 196,                     /* tASC  */
  YYSYMBOL_tHEX = 197,                     /* tHEX  */
  YYSYMBOL_tDEC = 198,                     /* tDEC  */
  YYSYMBOL_tBIN = 199,                     /* tBIN  */
  YYSYMBOL_tUPPER = 200,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 201,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 202,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 203,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 204,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 205,                /* tMOUSEMOD  */
  YYSYMBOL_tTRIM = 206,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 207,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 208,                   /* tRTRIM  */
  YYSYMBOL_tSTRING2 = 209,                 /* tSTRING2  */
  YYSYMBOL_tREPLACE = 210,                 /* tREPLACE  */
  YYSYMBOL_tINSTR = 211,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 212,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 213,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 214,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 215,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 216,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 217,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 218,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 219,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 220,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 221,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 222,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 223,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 224,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 225,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 226,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 227,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 228,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 229,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 230,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 231,                    /* tDATE  */
  YYSYMBOL_tTIME = 232,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 233,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 234,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 235,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 236,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 237,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 238,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 239,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 240, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 241,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 242, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 243,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 244,                   /* tEVAL2  */
  YYSYMBOL_tARGUMENT = 245,                /* tARGUMENT  */
  YYSYMBOL_246_ = 246,                     /* '-'  */
  YYSYMBOL_247_ = 247,                     /* '+'  */
  YYSYMBOL_248_ = 248,                     /* '*'  */
  YYSYMBOL_249_ = 249,                     /* '/'  */
  YYSYMBOL_UMINUS = 250,                   /* UMINUS  */
  YYSYMBOL_251_ = 251,                     /* ';'  */
  YYSYMBOL_252_ = 252,                     /* ','  */
  YYSYMBOL_253_ = 253,                     /* '('  */
  YYSYMBOL_254_ = 254,                     /* ')'  */
  YYSYMBOL_255_ = 255,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 256,                 /* $accept  */
  YYSYMBOL_program_or_expression = 257,    /* program_or_expression  */
  YYSYMBOL_program = 258,                  /* program  */
  YYSYMBOL_statement_list = 259,           /* statement_list  */
  YYSYMBOL_260_1 = 260,                    /* $@1  */
  YYSYMBOL_261_2 = 261,                    /* $@2  */
  YYSYMBOL_assignment = 262,               /* assignment  */
  YYSYMBOL_statement = 263,                /* statement  */
  YYSYMBOL_264_3 = 264,                    /* $@3  */
  YYSYMBOL_265_4 = 265,                    /* $@4  */
  YYSYMBOL_266_5 = 266,                    /* $@5  */
  YYSYMBOL_267_6 = 267,                    /* $@6  */
  YYSYMBOL_268_7 = 268,                    /* $@7  */
  YYSYMBOL_269_8 = 269,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 270,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 271,        /* string_assignment  */
  YYSYMBOL_to = 272,                       /* to  */
  YYSYMBOL_open_clause = 273,              /* open_clause  */
  YYSYMBOL_seek_clause = 274,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 275,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 276,        /* string_expression  */
  YYSYMBOL_string_function = 277,          /* string_function  */
  YYSYMBOL_number_assignment = 278,        /* number_assignment  */
  YYSYMBOL_expression = 279,               /* expression  */
  YYSYMBOL_280_9 = 280,                    /* $@9  */
  YYSYMBOL_281_10 = 281,                   /* $@10  */
  YYSYMBOL_arrayref = 282,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 283,          /* string_arrayref  */
  YYSYMBOL_coordinates = 284,              /* coordinates  */
  YYSYMBOL_function = 285,                 /* function  */
  YYSYMBOL_const = 286,                    /* const  */
  YYSYMBOL_number = 287,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 288,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 289,                  /* dimlist  */
  YYSYMBOL_function_or_array = 290,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 291,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 292,                /* call_list  */
  YYSYMBOL_293_11 = 293,                   /* $@11  */
  YYSYMBOL_calls = 294,                    /* calls  */
  YYSYMBOL_call_item = 295,                /* call_item  */
  YYSYMBOL_function_definition = 296,      /* function_definition  */
  YYSYMBOL_297_12 = 297,                   /* $@12  */
  YYSYMBOL_298_13 = 298,                   /* $@13  */
  YYSYMBOL_299_14 = 299,                   /* $@14  */
  YYSYMBOL_endsub = 300,                   /* endsub  */
  YYSYMBOL_function_name = 301,            /* function_name  */
  YYSYMBOL_export = 302,                   /* export  */
  YYSYMBOL_local_list = 303,               /* local_list  */
  YYSYMBOL_local_item = 304,               /* local_item  */
  YYSYMBOL_static_list = 305,              /* static_list  */
  YYSYMBOL_static_item = 306,              /* static_item  */
  YYSYMBOL_paramlist = 307,                /* paramlist  */
  YYSYMBOL_paramitem = 308,                /* paramitem  */
  YYSYMBOL_for_loop = 309,                 /* for_loop  */
  YYSYMBOL_310_15 = 310,                   /* $@15  */
  YYSYMBOL_311_16 = 311,                   /* $@16  */
  YYSYMBOL_312_17 = 312,                   /* $@17  */
  YYSYMBOL_313_18 = 313,                   /* $@18  */
  YYSYMBOL_next = 314,                     /* next  */
  YYSYMBOL_step_part = 315,                /* step_part  */
  YYSYMBOL_next_symbol = 316,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 317,  /* switch_number_or_string  */
  YYSYMBOL_318_19 = 318,                   /* $@19  */
  YYSYMBOL_sep_list = 319,                 /* sep_list  */
  YYSYMBOL_number_or_string = 320,         /* number_or_string  */
  YYSYMBOL_case_list = 321,                /* case_list  */
  YYSYMBOL_322_20 = 322,                   /* $@20  */
  YYSYMBOL_default = 323,                  /* default  */
  YYSYMBOL_324_21 = 324,                   /* $@21  */
  YYSYMBOL_do_loop = 325,                  /* do_loop  */
  YYSYMBOL_326_22 = 326,                   /* $@22  */
  YYSYMBOL_loop = 327,                     /* loop  */
  YYSYMBOL_while_loop = 328,               /* while_loop  */
  YYSYMBOL_329_23 = 329,                   /* $@23  */
  YYSYMBOL_330_24 = 330,                   /* $@24  */
  YYSYMBOL_wend = 331,                     /* wend  */
  YYSYMBOL_repeat_loop = 332,              /* repeat_loop  */
  YYSYMBOL_333_25 = 333,                   /* $@25  */
  YYSYMBOL_until = 334,                    /* until  */
  YYSYMBOL_if_clause = 335,                /* if_clause  */
  YYSYMBOL_336_26 = 336,                   /* $@26  */
  YYSYMBOL_337_27 = 337,                   /* $@27  */
  YYSYMBOL_338_28 = 338,                   /* $@28  */
  YYSYMBOL_339_29 = 339,                   /* $@29  */
  YYSYMBOL_endif = 340,                    /* endif  */
  YYSYMBOL_short_if = 341,                 /* short_if  */
  YYSYMBOL_342_30 = 342,                   /* $@30  */
  YYSYMBOL_end_of_if = 343,                /* end_of_if  */
  YYSYMBOL_else_part = 344,                /* else_part  */
  YYSYMBOL_elsif_part = 345,               /* elsif_part  */
  YYSYMBOL_346_31 = 346,                   /* $@31  */
  YYSYMBOL_347_32 = 347,                   /* $@32  */
  YYSYMBOL_maybe_then = 348,               /* maybe_then  */
  YYSYMBOL_inputlist = 349,                /* inputlist  */
  YYSYMBOL_350_33 = 350,                   /* $@33  */
  YYSYMBOL_input = 351,                    /* input  */
  YYSYMBOL_readlist = 352,                 /* readlist  */
  YYSYMBOL_readitem = 353,                 /* readitem  */
  YYSYMBOL_datalist = 354,                 /* datalist  */
  YYSYMBOL_printlist = 355,                /* printlist  */
  YYSYMBOL_using = 356,                    /* using  */
  YYSYMBOL_inputbody = 357,                /* inputbody  */
  YYSYMBOL_358_34 = 358,                   /* $@34  */
  YYSYMBOL_359_35 = 359,                   /* $@35  */
  YYSYMBOL_360_36 = 360,                   /* $@36  */
  YYSYMBOL_361_37 = 361,                   /* $@37  */
  YYSYMBOL_362_38 = 362,                   /* $@38  */
  YYSYMBOL_363_39 = 363,                   /* $@39  */
  YYSYMBOL_364_40 = 364,                   /* $@40  */
  YYSYMBOL_365_41 = 365,                   /* $@41  */
  YYSYMBOL_366_42 = 366,                   /* $@42  */
  YYSYMBOL_367_43 = 367,                   /* $@43  */
  YYSYMBOL_368_44 = 368,                   /* $@44  */
  YYSYMBOL_369_45 = 369,                   /* $@45  */
  YYSYMBOL_370_46 = 370,                   /* $@46  */
  YYSYMBOL_prompt = 371,                   /* prompt  */
  YYSYMBOL_printintro = 372,               /* printintro  */
  YYSYMBOL_hashed_number = 373,            /* hashed_number  */
  YYSYMBOL_goto_list = 374,                /* goto_list  */
  YYSYMBOL_gosub_list = 375                /* gosub_list  */
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
#define YYFINAL  249
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   15286

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  256
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  644
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2040

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   501


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   255,     2,     2,     2,     2,
     253,   254,   248,   247,   252,   246,     2,   249,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   251,
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
     245,   250
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   236,   236,   237,   238,   239,   240,   243,   246,   247,
     247,   247,   250,   251,   252,   253,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   271,   272,   272,   273,   274,   275,   276,   277,
     278,   279,   279,   281,   281,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   293,   294,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   311,   312,
     313,   314,   315,   317,   318,   319,   320,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   380,
     381,   382,   383,   384,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   493,   494,   495,   496,   497,
     501,   502,   503,   504,   505,   506,   509,   510,   513,   514,
     515,   516,   517,   520,   521,   524,   525,   528,   529,   530,
     531,   532,   533,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   568,   569,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   586,   587,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     603,   604,   607,   607,   608,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   640,   643,   646,
     649,   652,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   662,   663,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   704,   705,   706,   707,   708,   709,   710,
     711,   712,   713,   714,   715,   716,   717,   718,   719,   720,
     721,   722,   725,   726,   729,   732,   733,   734,   735,   736,
     737,   738,   739,   740,   741,   742,   743,   744,   747,   748,
     749,   752,   753,   754,   755,   758,   759,   762,   763,   764,
     765,   768,   771,   774,   774,   777,   778,   779,   782,   783,
     786,   787,   790,   786,   795,   796,   799,   800,   803,   804,
     805,   806,   809,   810,   813,   814,   815,   816,   819,   820,
     823,   824,   825,   826,   829,   830,   831,   834,   835,   836,
     837,   840,   841,   846,   861,   840,   866,   867,   868,   869,
     870,   871,   874,   875,   878,   879,   884,   884,   888,   889,
     892,   893,   897,   899,   898,   903,   904,   904,   908,   908,
     914,   915,   916,   917,   918,   919,   923,   924,   923,   930,
     931,   935,   935,   940,   941,   942,   943,   944,   945,   948,
     949,   949,   951,   948,   955,   956,   957,   958,   959,   960,
     963,   963,   968,   969,   972,   973,   976,   978,   980,   977,
     984,   985,   988,   989,   989,   992,   993,   995,   996,  1000,
    1001,  1004,  1005,  1007,  1008,  1012,  1013,  1014,  1015,  1018,
    1019,  1020,  1021,  1022,  1025,  1026,  1027,  1030,  1030,  1031,
    1031,  1032,  1032,  1033,  1033,  1034,  1034,  1035,  1035,  1036,
    1036,  1037,  1037,  1038,  1038,  1039,  1039,  1040,  1040,  1041,
    1041,  1042,  1042,  1045,  1046,  1049,  1050,  1051,  1052,  1053,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1065,
    1066,  1068,  1069,  1072,  1073
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
  "tPASTE", "tTRANSLATE", "tMESSAGE", "tATTRIBUTE", "tBITMAP", "tSIN",
  "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP", "tLOG", "tSQRT",
  "tSQR", "tMYEOF", "tABS", "tSIG", "tINT", "tCEIL", "tFLOOR", "tFRAC",
  "tROUND", "tMOD", "tRAN", "tVAL", "tLEFT", "tRIGHT", "tMID", "tLEN",
  "tMIN", "tMAX", "tSTR", "tINKEY", "tCHR", "tASC", "tHEX", "tDEC", "tBIN",
  "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY", "tMOUSEB", "tMOUSEMOD",
  "tTRIM", "tLTRIM", "tRTRIM", "tSTRING2", "tREPLACE", "tINSTR", "tRINSTR",
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

#define YYPACT_NINF (-1597)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-550)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     999, 12736, 10624, 12166,    43,   152,    44,   -56,   -51, -1597,
   -1597, -1597, -1597, -1597,   164,   164,   164,  7907, -1597, -1597,
   -1597, 12166, -1597, -1597, 12166,     5,    67, -1597, -1597, -1597,
   10624,   -38, -1597, 10624,   210, -1597, 10624, 10624, 10624,   264,
      33,   164,  3647,  2306,  4164,   160, 10624,  6919,  8154,   105,
      21, 10624, -1597,    11, 12166, 12166, 12166,   -18, 10624,  2454,
   10624, 10624,  8401,  8648,  7166,  5931, 10624,  6425,  8895,  9142,
   11208, 12166, 12166,   -30,  6672,  9389, 10624,  9636, 10624, 10624,
    5684,  6178,  5190,  5437,  9883, 10130, 11327, 11446, 11565,   -20,
     -40,  7413,   -86,   -71,   -60,   -25,    34,  4164, 12166, 12166,
   12166, -1597,   111, -1597, -1597,    -2, -1597, -1597, -1597, -1597,
     158,   170, -1597,   226, -1597, -1597, -1597, -1597, -1597, -1597,
   -1597, -1597,    41,    47, -1597, -1597, -1597, -1597,    62,   134,
     147,   155, 10624,   166,   181,   193,   196,   207,   209,   229,
     213,   282,   301,   347,   143,   366,   -52,   -50,   -37,    29,
      57,   112,   199,   246,   110,   194,   391, -1597,   -19,   423,
     452,   461,   484,   493,   495,   497,   501,   511,   517,   540,
     585,   587,   602,   612,   653,   657,   660,   672,   679,   690,
     692,   701,   702,   711,   714,   723,   733,   762,   773,   775,
     782,   788,   790,   803,   813,   814,   821,   824,   830,   834,
     838,   861,   870,   876,   877,   889,   890,   892,   901,   911,
     921,   929,   938,   939,   948,   956,   972,   973,  1000,  1006,
    1007,  1008,  1009,  1010,  1021,  1022,  1034,  1036,  1037, 10624,
   10624,   381, -1597,   535, -1597, -1597, -1597, -1597,   268,   276,
     351,   362,   505, 12166,   -31,   320,   158,   170,   708, -1597,
   10624, -1597, 12166, -1597,   874, 10624, 12520, -1597, -1597, -1597,
   -1597, -1597,   340,   255,   380,   483,   569, -1597, 10624, -1597,
     569, -1597, -1597, 10624, 12520,   595,  1038,   801,  1048,     3,
   10624,   -32,   381,  5497,  1056,  1057,   623,  5497,   381, 10897,
     381, 11669,  1066,  1067,   648, -1597, -1597,   250,   250, -1597,
   -1597,   722, -1597,  7660, 12166, 10624,    87,  5497,   736,   229,
   -1597, -1597, -1597,   746, 10624, 12166, 12166, 12166, 11981, -1597,
   10624, -1597,    -1, 12166,   953, -1597, -1597, 10624, 10377, -1597,
   -1597,  5497, -1597, -1597,   569,    -9,    -9, -1597,    -1, 10624,
   10624, 10624, 10624, 10624, 10624, 10624, 12166, 12166, 10624, 10624,
   10624, 10624, 10624,    -1,    -1, 12166,  1070, 12166,  1076, 12166,
   12166,    -1, 12166, 12166, 12166, 12166,    -1,  1078, 12166, 12166,
   12166,    -1, 12166,    -1, 12166,  1082, 12166,  -132,   -34,   198,
   12166, 12166, 12166, 12166, 12166,    -1, 12166,    -1,    -1, 12166,
      -1,    -1,    -1, 12166, 12166, 12166, 12166, 12166,    -1, 12166,
   12166, 12166, 12166,    -1, 12166, 12166, 12166, 12166, 12166, 12166,
   12166,    -1, 12166, 12166, 12166, 11676, 12166, 12166,    -1, 12166,
    1093, 12166,  1100, 12166,   211, 12166,   253, 12166,   306, 12166,
   12166, 12166, 12166, 12166, 12390,  1158,  1158,  1158,  4434, 12166,
     647,  1102,   569,   396,   410, -1597,   984, 10624, 10624, 10624,
   10624, 12166, -1597, -1597, -1597, 10624, 10624,  1917, 10624, 10624,
   10624, 10624,  3911,  4164, 12166, -1597,   516,   516, 10624, 10624,
   12166, 12166, 12166, 12166, 12166, 12166, 12166, 12166, 12166, 12166,
   12166, 12166, 12166, 12166, 12166, 12166, 11806, 12166, 12166, 12166,
    1117, -1597, 12166,  1127,  1147, 10624, 10624, 10624, 10624, 10624,
   10624, 10624, 10624, 10624, 10624,  4164, 10624, 10624, 10624, 10624,
   10624, 10624, 10624, 10624,  4686, 12166, 12166, 12166, 12166, 12166,
   10624, 10624, 10624,  4938, 10624, 12166, 10624, 12166, 10624, 12166,
   12166,   673, 10859, 10970, 11089, 12166, 12166, 12166, 10624, 12166,
   12166, 12166, 12166, 12166, 12166,  4164, 12166, -1597, -1597, 12166,
   10624, 12166, 12166, 12166, 12166, 12166,   927,   954, 12166,  1158,
   12166,  1158, 12166, 12166, 12166,  1241,   135,  1172, 12166, 12166,
   12166, 12166, 12166, 12166, 12166, 12166, -1597, -1597, -1597, 10624,
   10624, 10624, 10624, 10624, 10624, 10624, 10624, 10624, 10624, 10624,
   10624,  -165, -1597, -1597, -1597,  5497,  1128,   569,  1145,  1280,
    5497,   606, -1597, -1597, -1597, -1597,  1148,  1155,  1164, -1597,
    1174,  1182,  1185, -1597,   381,  5497,  1186, -1597,   381,  5497,
    1401,   659,  1410, 12520, 10624,  1211, 12166, -1597, -1597, 10624,
     381,   102,   293,  1212,  1408,  1221,    10, -1597,  1453, -1597,
   -1597,   570, 10624, 10624, -1597, -1597,   264, -1597, -1597,    70,
   12656,   569,  5497,   499, 11936, 10624,    -1,   569,   569,   445,
   10624, -1597,   -32, -1597, -1597, 10624,   449, 12166, -1597, 10624,
      -1, 10624, 10624, 10624,  1231,    -1,  1238,    -1,  1247,    -1,
      -1,   644,   569,  1251,  1259,    -1,    -1, 12872, 10624, 10624,
     645, 12166,   667, 12166,   569,   681, 10624,   699,   569,   700,
     718, 10624, 12166,   719,   721,   735, 10624,   737, 10624,   745,
   12166,   748, 10624, 12166, 12166,   749,   755,   757,   787,   795,
   10624,   798, 10624, 10624,   805, 10624, 10624, 10624,   569,   806,
     808,   569,   812, 10624,   569,   816,   826,   829, 10624,   569,
     833,   837,   569,   855,   856,   857, 10624,   858,   569,   859,
   12166,   865,   869,   873, 10624,   875, 12166,   884, 12166,   894,
   12166,   908, 12166,   909, 12166,   569,   910,   926,   928,   569,
   10624,  1260,  1263,  1271,  1272, -1597,  1194,  -110, 10624, 10624,
   10624, 10624, -1597,  1286,    -1,    -1,  5497,   569,   625,  1313,
    1315, 12947, 13059,  1222, 13079, 13113, 13134,  1316,   116,  1319,
    1326,   955,  1340,  1370,  1356,  1372,  1338,  1351,    -1, 13149,
     971,    19,   569,   569,   569,   569,   569,   569,  1003,   569,
     569,  1026,   569,   569,  1029,   569, 12166,   569,  1053,   569,
    1055, 12166,    27, 12166, 12166,  1457,  1502,  1544,  1561,  1756,
     886,  1840,  1095,  1903,  2027,  1387,  2048,  2171,  2366,  2523,
    2594,  2614,  2642, 13164, -1597,  2801,    55,  1065,  1079,  1085,
      99, 13179, 13194,   367,  1113, -1597,  2830,  2845,   141,  2862,
      -8,  2900,   178,   245, -1597,   378, -1597,   395, -1597,   398,
   -1597,   399,   407,   409,   427, 13209,  1101,  1104,  1111,   435,
     439,   440,   519,  1394,     0,  1396,  1420,   444,  2917,   448,
      56,  1122,  1125,  1129, -1597, -1597,  1131,  -148,  1143,  -135,
    1144,   459,   462, -1597, -1597,   569,   569,   569,   569,   569,
     569,   569, -1597, 10624, 10624,   947,    50,   262,   541,   487,
     -12,   -27, -1597,   -45,   -45,  1241,  1241, -1597, -1597, -1597,
   12520, -1597, -1597, 10624, -1597, -1597, -1597, -1597,   164,   164,
   -1597, -1597,   380, -1597, -1597,   483, 10624, -1597,  1615, -1597,
   -1597, -1597, -1597, -1597, -1597, -1597, -1597,   747, 13224, 10624,
      93,  2988, 12285, -1597, -1597, 10624, 10624,  1409, 12166, -1597,
   -1597, 10624, -1597,   720,  1445,  1447,  1454,  1465, 13246, 13266,
    1456,  1466, -1597, -1597, -1597, 10624,  1642,  1650, -1597,  1146,
   13281, 10624, 12166,  5497, -1597, -1597, 12166,  1150, -1597, 10624,
   13300, 13411,  1448, 12166, 10624, 10624, 10624, 12166, 10624, 10624,
   10624, 10624, 10624, 10624, 10624, 10624,  1492,  1493, 10624,  1160,
   10624,  1163, 10624,  1513, 12166, 12166, 12166,  1519,  1170, 12166,
   12166, 10624,  1521, 12166,  1522, 10624,  1176, 12166, 13433,   569,
     569, 12166, 12166, 10624, 12166, 10624,  1523, 12166,  1527,  1530,
   10624,  1532,  1534,  1535, 10624, 10624, 10624,  1536, 12166, 10624,
   10624,  1537, 12166, 10624, 12166, 12166, 10624,  1542, 12166, 10624,
    1177, 10624, 12166, 10624,  1543, 12166,  1178, 10624,  1184, 10624,
    1187, 12166,  1198, 12166,  1199, 12166, 12166, 12166, 13468, -1597,
   10624, 10624, 10624, -1597, -1597,   381,  5497,   381,  5497, 13487,
   13502, 12520, 10624, 10624, 10624, -1597, -1597, -1597, -1597, -1597,
   10624, 10624, -1597, 10624, 10624, 10624, -1597, 12166, -1597, 12055,
   -1597, 12166,  1545,  1546, -1597, -1597, 10624, 10624, 10624, 10624,
   12166, -1597, 10624, 10624, 10624,   569, 10624, 12166,   502, -1597,
    1200,  1206, -1597, -1597, -1597, -1597, -1597, 10624, -1597, -1597,
   10624, -1597, -1597, -1597, -1597, -1597, -1597, -1597, -1597, -1597,
   -1597, -1597, 10624, -1597, -1597, 10624, 10624, 10624, -1597, 10624,
   10624, -1597, 12166, -1597, -1597, -1597, -1597, -1597, 10624, -1597,
   -1597, -1597, -1597, -1597, -1597, -1597, -1597, -1597, -1597, -1597,
   12166, 12166, 12166, 12166, -1597, -1597, -1597, -1597, -1597, 12166,
   -1597, -1597, -1597, -1597, -1597, -1597, 10624, -1597, 10624, 10624,
   10624,  1791, 12166, -1597,  1791, 12166, -1597, 12166, -1597, -1597,
    1917,   563, 10624,    22,  5497, -1597,  1549, -1597,  1550,  1551,
    1552, -1597,  1558,  1560, -1597, -1597, -1597,   774, 12520, -1597,
   -1597, -1597, 10624, 13517, 12166,  1739, -1597, 12166,   569,   381,
     102, 13532, 10624,   243,   720,   720,  3127,  1563,  1564, -1597,
    1569, -1597, -1597, -1597, -1597, 10624, 10624, -1597, -1597, 13547,
    4164,  4164, 12166, 12166,  1571,  1207,   569, 12166, -1597, 10624,
   10624, 12166,   569,  1572, 13562,    -1,  1208,  1573,    -1,   381,
   13577, 13598, 13620,    -1,  1586, 13635, 12166, 12166,  5497, 12166,
    5497, 12166,   381,  5497, 12166,  1210,   569,   569, 12166, 12166,
    1220,  1228,   656,  5497, 12166,  1230, 12166,  5497, 12166,  1234,
   12166,  1242,  1244,  5497,   569,  5497, 12166,  1245, 12166, 12166,
    5497, 12166, 12166, 12166,   381, 13655,   381,  5497,  5497, 12166,
     569,  5497,  5497, 12166,  1246,   669,  5497,   569,   569,  5497,
   12166,  1253, 13764, 10624,  5497,  1254,  5497, 12166,   569, 12166,
   13785, 12166,   778, 13822, 12166,  1255, 12166,  1265, 12166,   569,
    1288,  1295, 12166,  1587,  3237,  3291,  1140, 12166, 12166, -1597,
    5497,    -1, -1597,  1589,  3320,  3346,  3439,  3478,  3971,   504,
    1591,   244,   569, -1597, -1597,  4224,  4456,  1592,    37,  1298,
    5497,  5497,  5497, 13842,   569, -1597, 12166, 12166,  4494,  4708,
    4746,  4960,  4998,  1157,  6447,  6694,   271,  6941,   515,  1299,
     326,   329,   518,  7435, 13857, 13872,  7682,   -98,   520,    36,
     532,   538,    58, -1597, -1597, -1597,   164,   164, -1597, -1597,
   -1597, -1597, 10624,  1760,  1766,  1800,  7929, 10624,   544,  1594,
     330, -1597, 10624, 13887, 12166,  1792, -1597, -1597, -1597, -1597,
   -1597, -1597,  1595,  1600,  5497,  5497, 12166, -1597, -1597,   569,
     569, 12166, 12166,  1301, 13902,  5497,  1302, 12166, 12166, 10624,
   12166, 12166, 10624, 10624, 10624, 10624, 10624, 10624, 12166,   569,
    1305,  1308,  1309,  1311, 10624,  1312,  1335, 12166, 10624, 10624,
    1336, 12166,  1337,  1339, 10624,   569, 10624, 10624,  1347, 12166,
    1349,  1350,  1353,  1357,  1359, 12166,  1375,  1392, 10624, 12166,
    1393, 10624, 10624,  5497, 10624,  1395,  1404, 10624,   569, 12166,
   12166,  1405, 10624,  1407, 12166,  1413, 12166, 12166,   569, -1597,
    1781,  1782, 10624,  1783,  1417,   569, 10624,   820, -1597, -1597,
   -1597, -1597, -1597, -1597, -1597, 12166, -1597, -1597, -1597, -1597,
   10624, 12166, 10624,   568,   579, -1597, -1597, -1597, -1597, -1597,
   10624, -1597, -1597, -1597, 12166, -1597, -1597, -1597, 12166, 10624,
   -1597, 10624, -1597, -1597, -1597, 12166, 10624, -1597, 12166, -1597,
   -1597, 12166, -1597, -1597, -1597, 10624, -1597, -1597, -1597, -1597,
   -1597,  1813,   945,  8176,  1804, 10624, 12166,  8423, 10624,   580,
    1610,  1453,   720,  1612,  1613,   720, -1597, -1597,   569,  1421,
     569, 12166, 12166, 12166,   569,   569,  1617,   569,   569,    -1,
   13917, 13932, 13951,    -1, 13972,  1424, 12166, 10624, 10624, 12166,
   13987, 10624, 12166,   569, 14009,  5497, 12166,  1425, 12166, 10624,
   14119, 14138,   381,  5497, 12166,   569, 12166, 10624, 10624, 12166,
   12166,   569, 10624, 12166,   866,  5497,   569, 10624, 14174, 14196,
   14211, 10624, 12166, 14226,  1433,   569, 12166,  1025, 14241, 12166,
    1435, 12166,  1437,   569, 12166, 12166,  8670, 12166, 10624, -1597,
    1611,  1618,   120, -1597,   592, 14256,   569,  5497, -1597, -1597,
    8917,   609,   617,  9164,  9411,   622,  9658,   630,   664,    75,
   12520, 12952, 10624,  1825, -1597,  1620, -1597,  1621, 14271,   675,
     952,  9905,  1817, 10624,   720, -1597, -1597, -1597, -1597, 12166,
     569,   569,   569, 12166, 10624, 10624, 12166, 10624, 10624, 10624,
   12166,  1443, 14286, 14306,  1446, 10624, 14325,  1450, 10624,  1461,
   10624,  1467, 14340, 10624, 10624,  1479,  1486, 14361, 14473,   569,
     569, 14493,  1487, 10624, 14527, 10624, 10624, 10624, 14548,  1490,
   10624, 12166,   569, 12166, 12166,  1494, 10624,  1505, 12166,   569,
     569,  1801,   569,  5497,  1623,  1624,   820, -1597, -1597, 10624,
   -1597, -1597, -1597, -1597, -1597, -1597, -1597, -1597, -1597, 10624,
   -1597,  1800,  1841,   731, 12520, -1597, 12166, 10624, 10624, -1597,
   -1597,  1627,  1453, -1597,  1629,  1453, 14563, -1597,   569,   569,
    1631, 14578,   569, 14593,  1635, 14608,  1506, 12166, 12166, 12166,
   12166, 14623, 12166, 12166, 14638, 10624,  5497, 12166, 10624,  5497,
   14660, 12166, 10624, 10624, 12166, 12166, 12166,  5497, 12166, 14680,
   14695, 14714, 12166, 12166,  5497,   569,  1507,   569, 12166,  1077,
   14825, 12166,   569, 12166, -1597, -1597, -1597, 12520, 10152,  5497,
   12520, -1597, -1597,  1800,   871,   349, 14847, 10399,  1453, 12166,
     720,  1453, 10624,   720, 10624, 12166, 12166, 10624, 12166, 12166,
   12166,   569,   569,   569,  1508, 10624,   569,   569, 10624, 14882,
    1514, 14901, 10624,   569, 14916, 14931,   569,   569,   569,   569,
   10624, 12166, 10624,  1515,   569, 12166,   569, 12166, 12166,  1516,
     569,    12, -1597,  1800, 12520, -1597, -1597, -1597, -1597, -1597,
   -1597, -1597, 12166, -1597, 10624, -1597,   720,   350, -1597,   720,
   14946, -1597, 10646,   569,   569, 14961,   569,   569,   569, 12166,
    5497,  5497, 10624, 12166, 10624,  5497, 12166, 12166,  5497,   569,
   14976, 12166,   569,  1517,   569, 12166, -1597, -1597, -1597,   967,
    1800,   676, 10684, -1597, 12166, -1597, -1597, 10624, -1597, 12166,
     569, 14991,   569, 15012,   569,   569, 10624,   569, 12166,   569,
   -1597, -1597, -1597, -1597, -1597, -1597,  1885,  1813, -1597, -1597,
     677,  1453, 10876,  1453,   569, 12166, 12166, 15034,   569, -1597,
   -1597, -1597, -1597,   720, -1597,   720,  1525,   569, 12166,  1453,
   -1597,  1453, -1597, 12166,   569,   720,   720,   569, -1597, -1597
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   235,     0,     0,     0,   478,     0,     0,     0,   229,
     501,   536,   541,    18,     0,     0,     0,     0,    31,    33,
     479,     0,   463,   463,     0,   480,    25,    27,   516,   528,
       0,   625,    55,    67,     0,   226,   227,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   236,
     237,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,     0,     0,     0,     0,
       0,     2,     9,    17,     8,     0,    12,    46,    48,    14,
      29,    30,    28,     0,    20,    21,    24,    23,    22,    35,
      36,   451,   342,   257,   452,   453,   454,   260,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   305,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   271,     0,     0,
       0,     0,     0,     0,     0,   402,   405,   408,   411,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,   290,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   258,     0,   356,   336,   341,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,   463,     0,   463,     0,     0,    16,   456,   455,    37,
      38,    45,     0,     0,     0,     0,    19,    50,   465,    51,
      49,   481,    26,     0,    16,   560,     0,   629,     0,     0,
     589,   621,    69,    68,     0,     0,    70,   228,    60,     0,
      62,     0,   581,   583,    63,   579,   585,     0,     0,   586,
     448,    64,    66,     0,   213,     0,     0,   640,     0,    92,
     215,    86,    47,     0,     0,     0,     0,     0,     0,    74,
       0,    57,    79,     0,     0,    94,    93,     0,     0,   238,
     239,   216,    13,    15,   230,     0,     0,    85,     0,     0,
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
       0,     0,   231,     0,     0,     7,     0,     0,     0,     0,
       0,     0,   470,   463,   463,     0,     0,   326,     0,     0,
       0,     0,     0,     0,     0,   432,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   304,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   463,   463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   348,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,   324,   322,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     5,     6,   320,     0,   240,     0,     0,
     537,     9,    39,    40,    41,    43,   484,   485,    32,   482,
     490,   491,    34,   488,   468,   469,   464,   466,   521,   520,
       0,     9,     0,    16,     0,     0,     0,   626,   627,     0,
     592,   594,    52,     0,     0,     0,     0,    56,   623,   463,
     463,     0,     0,     0,   463,   463,     0,   450,   449,     0,
       0,   214,   639,     0,     0,     0,     0,    96,    73,     0,
       0,    78,   621,   247,   246,     0,     0,     0,    75,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,     0,     0,     0,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   166,     0,
       0,   167,     0,     0,   172,     0,     0,     0,     0,   181,
       0,     0,   184,     0,     0,     0,     0,     0,   191,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   206,     0,     0,     0,   211,
       0,   255,     0,     0,     0,   219,     0,     0,     0,     0,
       0,     0,    10,     0,     0,     0,   321,   245,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   293,   295,   294,   296,   436,   435,     0,   438,
     437,     0,   440,   439,     0,   443,     0,   441,     0,   301,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   382,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   272,     0,     0,     0,     0,
       0,     0,     0,     0,   403,     0,   406,     0,   409,     0,
     412,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   289,   291,     0,     0,     0,     0,
       0,     0,     0,   262,   357,   351,   353,   355,   352,   354,
     349,   350,   261,     0,     0,   329,   331,   333,   330,   332,
     327,   328,   347,   344,   343,   345,   346,   461,   462,   502,
      16,   548,   546,     0,   547,   543,   545,   542,     0,     0,
     463,   463,     0,   463,   463,     0,     0,   518,   522,   535,
     533,   534,   531,   530,   532,   529,   550,     9,     0,     0,
       0,     0,     0,   590,    53,    54,     0,     0,     0,   597,
     599,     0,   624,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   580,   587,   588,     0,     0,     0,   250,   249,
     253,     0,     0,   360,    58,    76,     0,    89,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     148,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   463,
       0,     0,     0,   220,   221,   222,   223,   224,   225,     0,
       0,    16,     0,     0,     0,   476,   477,   471,   424,   316,
       0,     0,   415,     0,     0,     0,   425,     0,   426,     0,
     419,     0,     0,     0,   337,   338,     0,     0,     0,     0,
       0,   447,     0,     0,     0,   442,     0,     0,     0,   302,
       0,     0,   361,   362,   363,   364,   365,     0,   366,   368,
       0,   369,   371,   372,   334,   378,   379,   373,   375,   376,
     377,   374,     0,   381,   386,     0,     0,     0,   385,     0,
       0,   270,     0,   267,   273,   274,   387,   314,     0,   388,
     315,   275,   276,   401,   404,   407,   410,   279,   277,   278,
       0,     0,     0,     0,   282,   394,   283,   400,   399,     0,
     292,   395,   284,   396,   285,   398,     0,   286,     0,     0,
       0,     0,     0,   309,     0,     0,   311,     0,   431,   319,
     325,   323,     0,     9,   544,   641,    42,   643,    44,     0,
       0,   483,     0,     0,   489,   467,   519,   525,    16,   562,
     563,   561,     0,     0,     0,   630,   628,     0,   595,   593,
     594,     0,     0,     0,     0,     0,     0,   575,   577,   622,
     572,   457,   459,   463,   463,     0,     0,   582,   584,    71,
       0,     0,     0,     0,     0,     0,   121,     0,    77,     0,
       0,     0,   102,     0,     0,     0,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,   117,     0,
     119,     0,   124,   125,     0,     0,   129,   128,     0,     0,
       0,     0,     0,   137,     0,     0,     0,   144,     0,     0,
       0,     0,     0,   151,   150,   152,     0,     0,     0,     0,
     157,     0,     0,     0,   161,     0,   163,   164,   165,     0,
     169,   171,   170,     0,   174,   177,   178,   182,   183,   180,
       0,     0,     0,     0,   188,     0,   190,     0,   194,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   208,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      87,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   433,   358,   359,     0,     0,     0,     0,   445,
     297,   298,   299,     0,   444,   303,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   540,   539,   538,     0,     0,   486,   487,
     492,   493,     0,     0,     0,   551,     0,     0,     0,     0,
       0,   591,     0,     0,     0,   611,   598,   600,   601,   463,
     463,   573,     0,     0,    59,    61,     0,   251,   252,   248,
     254,     0,     0,    90,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,     0,     0,     0,     0,   195,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   209,   256,
       0,     0,     0,     0,   233,   234,     0,   494,   413,   414,
     416,   417,   418,   427,   428,     0,   429,   339,   340,   312,
       0,     0,     0,     0,     0,   367,   370,   380,   263,   264,
       0,   266,   383,   384,     0,   268,   389,   280,     0,     0,
     390,     0,   392,   307,   287,     0,     0,   318,     0,   421,
     308,     0,   423,   310,   335,     0,   642,   644,   523,   526,
     517,   566,   632,     0,   631,     0,     0,     0,     0,     0,
       0,   623,     0,     0,     0,     0,   458,   460,    72,     0,
      97,     0,     0,     0,   103,   106,     0,   101,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,     0,   135,     0,     0,     0,     0,
     139,     0,   145,   146,     0,   154,     0,     0,     0,     0,
       0,   162,     0,     0,     0,   176,   179,     0,     0,     0,
       0,     0,     0,     0,     0,   198,     0,     0,     0,     0,
       0,     0,     0,   210,     0,     0,     0,     0,     0,    88,
     497,   498,     0,   495,     0,     0,   446,   300,   434,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   512,
      16,   235,     0,   564,   636,     0,   633,     0,     0,     0,
     603,     0,   613,     0,     0,   602,   576,   578,   574,     0,
     120,    82,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   158,
     159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   197,     0,     0,     0,     0,     0,     0,   243,
     244,     0,   242,   232,     0,     0,     0,   472,   430,     0,
     265,   269,   281,   391,   393,   397,   317,   420,   422,     0,
     503,   524,     9,   570,    16,   552,     0,     0,     0,   596,
     615,     0,   623,   605,     0,   623,     0,   612,    95,   110,
       0,     0,   107,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,     0,     0,   140,
       0,     0,     0,     0,     0,     0,     0,   175,     0,     0,
       0,     0,     0,     0,   196,   199,     0,   201,     0,     0,
       0,     0,   207,     0,   499,   500,   496,    16,     0,   513,
      16,   571,   567,   565,     0,     0,     0,     0,   623,     0,
       0,   623,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,   116,   118,     0,     0,   127,   122,     0,     0,
       0,     0,     0,   149,     0,     0,   156,   160,   168,   173,
       0,     0,     0,     0,   193,     0,   200,     0,     0,     0,
     241,     9,   313,   504,    16,   559,   556,   557,   558,   554,
     555,   553,     0,   637,     0,   634,     0,     0,   604,     0,
       0,   614,     0,   109,   100,     0,   111,   105,   212,     0,
     131,   136,     0,     0,     0,   147,     0,     0,   192,   187,
       0,     0,   202,     0,   205,     0,   475,   474,   473,     0,
     568,     0,     0,   616,     0,   617,   606,     0,   607,     0,
     123,     0,   141,     0,   153,   155,     0,   185,     0,   203,
     507,   509,   510,   511,   506,   508,   514,   566,   638,   635,
       0,   623,     0,   623,   108,     0,     0,     0,   204,   515,
     505,   569,   619,     0,   609,     0,   132,   143,     0,   623,
     618,   623,   608,     0,   186,     0,     0,   133,   620,   610
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1597, -1597, -1597,  -202, -1597, -1597,  1886,   780, -1597, -1597,
   -1597, -1597, -1597, -1597, -1597,  1845,  1663, -1597, -1597,  -378,
      -3, -1597,  1846,  1679, -1597, -1597,  1427,  -461,  2938, -1597,
    1252,   -36,   -14, -1597,     4,     8,    40, -1597, -1597,   944,
    1897, -1597, -1597, -1597, -1597, -1597, -1597, -1597,   968, -1597,
     950, -1597,   123, -1597, -1597, -1597, -1597, -1597, -1597, -1597,
   -1597, -1597, -1597, -1597,   454, -1597, -1597, -1597, -1597, -1597,
   -1597, -1597, -1597, -1597, -1597, -1597, -1597, -1597, -1597, -1597,
   -1597, -1597, -1597, -1597, -1597, -1597, -1597, -1597, -1597,  -100,
   -1597, -1597, -1597, -1178, -1597, -1597, -1597,  1275, -1597, -1597,
     663,  1264, -1597, -1597, -1597, -1597, -1597, -1597, -1597, -1597,
   -1597, -1597, -1597, -1597, -1597, -1596, -1597,     2, -1597, -1597
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,   101,   102,   446,  1111,   103,   104,   264,   265,
     948,   949,   281,   662,   105,   106,   665,   107,   108,   772,
     231,   232,   109,   318,   924,   923,   804,   805,   319,   234,
     299,   235,   259,   286,   236,   237,   267,   268,   616,   617,
     112,   788,  1393,  1877,  1978,  1117,   113,   608,   609,   612,
     613,  1702,  1703,   114,   254,  1232,  1880,  1979,  2006,  1810,
    2020,   115,   273,   958,   620,  1247,  1720,  1454,  1721,   116,
     274,   965,   117,   255,   940,  1445,   118,   256,   947,   119,
     622,  1248,  1611,  1884,  1941,   120,   623,  1251,  1815,  1723,
    1934,  2007,  1882,  1269,  1625,  1270,   294,   295,   301,   632,
     973,   637,  1264,  1265,  1622,  1822,  1891,  2013,  2031,  1621,
    1825,  1888,  2011,  2029,   638,   983,   280,   308,  1236,  1238
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     244,   260,   261,   663,   300,   110,   807,   627,   246,   111,
     628,   663,   247,   592,   979,     7,     8,   980,   266,   250,
     276,   270,   277,   278,   252,  1734,   633,   302,   634,   635,
     282,   380,   586,   271,   288,   290,   121,  1976,  1443,   306,
     124,   125,   126,   296,   249,   312,   313,     7,     8,   663,
     586,   334,   335,   336,   601,   430,  1977,   246,   773,   774,
     472,   247,   474,   269,   585,   586,  1444,   377,   378,   379,
    1605,   431,   621,   121,   272,   476,   477,   124,   125,   126,
     993,   381,   575,   424,   426,   428,  1466,  1467,  1809,   913,
     447,   448,   337,   493,   440,   442,   443,   444,   653,   441,
     577,   578,   449,   473,  1222,   475,  1223,   579,   580,   581,
     582,   583,   584,   585,   586,   575,   330,  1225,   478,  1226,
     712,   577,   578,   582,   583,   584,   585,   586,   579,   580,
     581,   582,   583,   584,   585,   586,   494,   575,   577,   578,
     429,   479,   480,    53,  1104,   579,   580,   581,   582,   583,
     584,   585,   586,   972,  1598,   445,  1599,   568,   569,   570,
     571,   572,   573,   574,   325,   577,   578,   435,   257,   482,
     483,   258,   579,   580,   581,   582,   583,   584,   585,   586,
      20,   907,   436,   909,   481,    25,   568,   569,   570,   571,
     572,   573,   574,   437,   326,   327,   328,   251,    92,    93,
      94,   329,   253,   589,   590,   568,   569,   570,   571,   572,
     573,   574,   484,   575,   284,   285,   575,   279,   713,   587,
     588,   589,   590,   636,   485,   486,  1890,   566,   438,  1893,
      92,    93,    94,   450,   587,   588,   589,   590,   575,   575,
     591,   314,   315,   664,  1188,   451,  1189,   575,   316,   597,
     452,   664,  1209,   121,  1210,   470,   629,   124,   125,   126,
     110,   647,   648,   981,   111,   614,   575,   487,   292,   293,
     618,   317,   490,  1141,   575,   604,   605,   630,   110,   297,
     298,  1149,   111,   587,   588,   589,   590,   439,  1601,   664,
    1602,   596,  1946,   598,   251,  1949,   587,   588,   589,   590,
     253,   651,   575,   575,   587,   588,   589,   590,  1216,  1174,
    1217,   488,   657,   658,   659,   453,   297,   298,   577,   578,
     666,   587,   588,   589,   590,   579,   580,   581,   582,   583,
     584,   585,   586,   580,   575,   582,   583,   584,   585,   586,
     575,   464,   465,   681,   682,  1254,   575,  1255,   587,   588,
     589,   590,   690,  1178,   692,   491,   694,   695,   489,   697,
     698,   699,   700,   575,   593,   703,   704,   705,  1127,   707,
    1128,   709,  1796,   711,  1797,   602,   603,   715,   716,   717,
     718,   719,   575,   721,   606,   607,   724,   454,   575,   913,
     728,   729,   730,   731,   732,  1186,   734,   735,   736,   737,
     455,   739,   740,   741,   742,   743,   744,   745,   456,   747,
     748,   749,   751,   752,   753,  2023,   755,  2025,   757,   458,
     759,   967,   761,   478,   763,   575,   765,   766,   767,   768,
     769,   481,  1191,  2035,   459,  2036,   777,   568,   569,   570,
     571,   572,   573,   574,  1735,   575,   460,  1738,   787,   461,
     714,   568,   569,   570,   571,   572,   573,   574,   575,   798,
     462,   801,   463,   760,   799,   800,   466,   810,   811,   812,
     813,   814,   815,   816,   817,   818,   819,   820,   821,   822,
     823,   824,   825,   827,   828,   829,   830,   610,   611,   832,
     575,   575,   575,   789,   790,  1464,  1565,  1465,  1566,  1192,
     575,   587,   588,   589,   590,   762,   484,   845,   587,   588,
     589,   590,   856,   857,   858,   859,   860,   487,   575,   863,
     802,   803,   868,  1584,   870,  1585,   872,   873,   875,   877,
     879,   881,   882,   883,   884,   467,   886,   887,   888,   889,
     890,   891,   892,   894,   974,   975,   897,   893,   899,   900,
     901,   902,   903,   575,   468,   906,  1827,   908,   764,   910,
     911,   912,   584,   585,   586,   915,   916,   917,   918,   919,
     920,   921,   922,   575,   986,   987,   575,   575,  1589,   576,
    1590,  1591,  1616,  1592,   913,   996,   997,   895,   896,   568,
     569,   570,   571,   572,   573,   574,   575,   575,   577,   578,
     469,  1942,  1984,  1943,  1985,   579,   580,   581,   582,   583,
     584,   585,   586,   300,   575,   583,   584,   585,   586,   471,
     941,  1181,   942,   970,   943,   575,   577,   110,   575,  1115,
    1116,   111,  1193,   579,   580,   581,   582,   583,   584,   585,
     586,  -549,   575,   575,   492,   575,   575,   944,   780,  1194,
     945,   999,  1195,  1196,   575,   946,   575,   575,   577,   578,
     494,  1197,   781,  1198,  1007,   579,   580,   581,   582,   583,
     584,   585,   586,   959,   575,   960,   495,   961,   123,   984,
     985,  1199,   575,   127,   990,   991,   575,   575,  1029,  1204,
    1031,   575,   575,  1205,  1206,   575,   575,  1002,  1213,  1038,
     962,  1006,  1215,   963,   129,   496,   575,  1046,   964,   575,
    1049,  1050,  1948,  1228,   497,  1951,  1229,   568,   569,   570,
     571,   572,   573,   574,  1267,  1268,   568,   569,   570,   571,
     572,   573,   574,   587,   588,   589,   590,   498,  1233,   568,
     569,   570,   571,   572,   573,   574,   499,  1080,   500,   575,
     501,   575,   594,  1086,   502,  1088,  1415,  1090,  1563,  1092,
    1437,  1094,   575,  1439,   503,   575,   575,   575,  1983,  1587,
     504,  1986,  1593,  1207,  1600,  1105,  1107,  1881,   142,   575,
     143,   587,   588,   589,   590,   575,  1603,   587,   588,   589,
     590,   575,  1604,   505,   577,   578,  1249,  1250,  1614,   146,
     147,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,  1452,  1453,   575,   575,   238,   239,   240,
     241,   152,  1708,  1145,  1700,  1701,   575,   575,  1148,   154,
    1150,  1151,   155,  1709,  1732,   156,   157,   242,   506,   575,
     507,   587,   588,   589,   590,  2030,  1798,  2032,   568,   569,
     570,   571,   572,   573,   574,   508,   575,  2038,  2039,   625,
     180,   181,   182,  1801,   575,   509,   186,   187,   188,   575,
     190,  1802,   192,   193,   194,   641,  1805,   575,   599,   199,
     200,   201,   202,   203,  1807,  1935,   206,  1936,   208,  1937,
     210,   575,   575,   212,   575,   214,  1020,  1028,   216,   778,
     646,   218,   219,   575,   220,   221,   510,   223,  1509,   225,
     511,   575,  1938,   512,   575,  1939,   575,   228,  1808,  1030,
    1940,  1529,   575,   575,   575,   513,   243,   874,   575,  1819,
    2008,  2022,   514,  1032,  1235,  1237,   568,   569,   570,   571,
     572,   573,   574,   515,   110,   516,   575,   575,   111,   577,
     578,  1034,  1035,   614,   517,   518,   579,   580,   581,   582,
     583,   584,   585,   586,   519,   575,   575,   520,   575,  1258,
    1036,  1039,  1259,  1040,   649,  1263,   521,   587,   588,   589,
     590,  2000,   575,  2001,   575,  2002,   522,  1041,   654,  1043,
    1239,  1240,   575,  1242,  1243,   575,   575,  1045,   655,  1285,
    1047,  1051,   575,  1286,   575,  1724,  1725,  1052,  2003,  1053,
    1292,  2004,  1820,  1821,  1296,   523,  2005,  1299,   580,   581,
     582,   583,   584,   585,   586,   575,   524,   782,   525,  1312,
    1539,  1315,  1316,  1317,   575,   526,  1320,  1321,  1322,  1054,
    1325,   527,   575,   528,  1329,   575,  1455,  1055,  1331,  1332,
    1057,  1334,   575,   575,  1337,   575,   529,  1060,  1064,   575,
    1065,  1344,  1346,   575,  1066,  1350,   530,   531,  1068,  1354,
    1355,  1357,  1358,   575,   532,  1361,   575,   533,  1069,  1365,
     575,  1070,  1368,   534,   575,  1072,  1372,   535,  1375,  1073,
    1377,   536,  1379,  1380,  1381,   568,   569,   570,   571,   572,
     573,   574,   575,   575,   575,   575,   575,  1074,  1075,  1076,
    1078,  1079,   575,   575,   537,   110,   575,  1081,  1773,   111,
     575,  1082,   575,   538,  1399,  1083,  1401,  1085,  1402,   539,
     540,   575,   587,   588,   589,   590,  1087,  1409,  1157,  1383,
    1158,   575,   541,   542,  1414,   543,  1089,   568,   569,   570,
     571,   572,   573,   574,   544,   575,   575,   575,   577,   578,
    1091,  1093,  1095,   771,   545,   579,   580,   581,   582,   583,
     584,   585,   586,   575,   546,   575,   577,   578,  1096,  1426,
    1097,   904,   547,   579,   580,   581,   582,   583,   584,   585,
     586,   548,   549,   587,   588,   589,   590,  1428,  1429,  1430,
    1431,   550,   575,   577,   578,   667,  1432,  1131,   905,   551,
     579,   580,   581,   582,   583,   584,   585,   586,   575,  1438,
     577,   578,  1440,  1140,  1441,   552,   553,   579,   580,   581,
     582,   583,   584,   585,   586,   577,   578,     1,     2,     3,
       4,     5,   579,   580,   581,   582,   583,   584,   585,   586,
     575,  1458,   110,   554,  1460,  1142,   111,   577,   578,   555,
     556,   557,   558,   559,   579,   580,   581,   582,   583,   584,
     585,   586,   575,   575,   560,   561,   575,  1783,  1143,  1479,
    1480,  1144,  1477,  1478,  1483,   577,   578,   562,  1486,   563,
     564,   624,   579,   580,   581,   582,   583,   584,   585,   586,
     575,   626,   575,  1499,  1500,  1146,  1501,  1147,  1502,   639,
     640,  1503,   575,  1472,  1473,  1505,  1506,  1175,   586,   644,
     645,  1510,   691,  1512,   575,  1513,   575,  1515,   693,  1927,
     702,  1176,   575,  1518,   710,  1520,  1521,  1177,  1522,  1523,
    1524,   587,   588,   589,   590,   756,  1526,  1160,   575,  1161,
    1527,   575,   758,  1201,   779,   939,  1202,  1530,   575,   587,
     588,   589,   590,  1203,  1535,  1182,  1536,  1183,  1538,   575,
     831,  1541,   575,  1543,  1218,  1545,   575,  1219,   575,  1548,
     833,  1220,   937,  1221,  1554,  1555,   587,   588,   589,   590,
     575,   575,  1552,   575,  1553,  1224,  1227,   575,  1282,   938,
     834,   950,  1287,   587,   588,   589,   590,   575,   951,  1580,
     575,  1581,  1309,  1573,  1574,  1311,   952,   575,   587,   588,
     589,   590,  1319,   575,   575,   575,   914,   953,  1328,  1363,
    1369,   575,  1606,  1607,   575,   954,  1371,   955,   956,  1374,
     587,   588,   589,   590,   957,   575,   575,   575,  1103,   618,
    1376,  1378,  1416,   575,   575,   575,   966,   575,  1417,  1482,
    1490,  1619,  1504,   982,   969,   976,   977,   575,   587,   588,
     589,   590,  1507,  1628,   978,   575,  1122,   575,  1629,  1630,
    1508,   575,  1511,  1013,  1634,  1635,  1514,  1637,  1638,   575,
    1015,   575,   575,   575,  1516,  1645,  1517,  1519,  1528,  1017,
     575,   575,   575,  1021,  1653,  1531,  1534,  1542,  1657,  1623,
    1624,  1022,   575,  1099,  1662,  1100,  1665,  1544,  1811,  1812,
     577,   578,  1671,  1101,  1102,  1674,  1676,   579,   580,   581,
     582,   583,   584,   585,   586,   575,  1684,  1685,  1112,  1687,
    1546,  1690,   575,  1692,  1693,   575,   575,  1547,   575,   575,
    1571,  1588,   575,  1631,  1633,   575,   575,  1646,   575,   575,
    1647,  1648,  1704,  1649,  1651,   577,   578,  1118,  1706,  1119,
    1126,  1129,   579,   580,   581,   582,   583,   584,   585,   586,
    1130,  1711,   575,   575,   575,  1712,   575,  1652,  1656,  1658,
    1136,  1659,  1715,  1132,   575,  1717,   575,   575,  1718,  1664,
     575,  1666,  1667,  1137,   575,  1668,   575,   577,   578,  1669,
    1134,  1670,  1883,  1729,   579,   580,   581,   582,   583,   584,
     585,   586,   575,  1133,   577,   578,  1135,  1672,  1740,  1741,
    1742,   579,   580,   581,   582,   583,   584,   585,   586,   575,
     575,  1164,   575,  1751,  1673,  1677,  1754,  1681,  1208,  1757,
    1211,   575,   575,  1759,   575,  1761,  1682,  1686,  1246,  1689,
     575,  1765,  1262,  1766,   575,  1691,  1769,  1770,   575,  1698,
    1772,   575,   575,  1739,  1212,  1931,  1750,  1760,  1933,  1779,
     575,   233,   575,  1782,   575,  1781,  1785,  1786,  1787,  1788,
     575,  1789,  1790,   575,  1792,  1837,   263,   575,  1840,  1271,
    1291,  1272,  1843,   587,   588,   589,   590,  1273,   575,   275,
    1277,  1152,   283,  1845,   575,   287,   289,   291,  1274,  1847,
    1278,   307,   307,   307,   110,   110,   575,  1280,   111,   111,
     331,  1851,  1980,   575,   575,  1281,  1828,   575,  1852,  1856,
    1829,   575,  1863,  1832,  1306,  1307,  1868,  1836,   587,   588,
     589,   590,   575,   575,   575,   575,  1153,  1871,  1900,  1925,
    1959,   575,   575,   575,   575,  1314,  1963,  1971,  1975,  1998,
     434,  1318,   575,  1324,  1326,  1336,   307,  2033,  1865,  1338,
    1866,  1867,  1339,  1869,  1341,  1872,  1342,  1343,  1349,  1353,
     587,   588,   589,   590,  1360,  1367,   803,  1459,  1154,  1403,
    1404,  1446,  1447,  1609,  1610,  1448,  1449,   587,   588,   589,
     590,   457,  1450,  1885,  1451,  1155,  1469,  1470,   110,   577,
     578,  1471,   111,  1481,  1487,  1491,   579,   580,   581,   582,
     583,   584,   585,   586,  1901,  1902,  1903,  1904,  1497,  1906,
    1907,  1549,  1557,    -9,  1910,  1564,  1569,  1615,  1913,  1626,
    1620,  1916,  1917,  1918,  1627,  1919,  1694,  1695,  1697,  1923,
    1924,  1722,  1727,  1733,  1794,  1926,  1736,  1737,  1929,  1743,
    1930,  1795,  1814,  1816,  1817,  1824,  1873,  1874,  1875,  -527,
    1889,   110,  1892,  1895,   110,   111,  1947,  1898,   111,  2019,
     245,  1389,  1953,  1954,   806,  1956,  1957,  1958,   332,   333,
    1245,   994,   248,   577,   578,  1244,  1608,  2021,   565,   567,
     579,   580,   581,   582,   583,   584,   585,   586,  1969,  1876,
    1241,   992,  1972,  1461,  1973,  1974,  1004,     0,     0,   595,
       0,     0,     0,     0,   600,     0,     0,     0,   110,  1981,
       0,     0,   111,     0,     0,     0,     0,   615,     0,     0,
       0,     0,   619,     0,     0,     0,  1990,     0,     0,   631,
    1992,     0,     0,  1994,  1995,     0,   577,   578,  1997,     0,
       0,     0,  1999,   579,   580,   581,   582,   583,   584,   585,
     586,  2010,   650,     0,   652,     0,  2014,   579,   580,   581,
     582,   583,   584,   585,   586,  2018,     0,     0,   671,   672,
       0,   673,   587,   588,   589,   590,     0,     0,     0,     0,
    1156,     0,  2026,  2027,     0,     0,   688,   689,     0,     0,
       0,     0,     0,     0,   696,  2034,     0,     0,     0,   701,
    2037,   687,     0,     0,   706,     0,   708,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   720,     0,
     722,   723,     0,   725,   726,   727,     0,     0,     0,     0,
       0,   733,     0,     0,     0,     0,   738,     0,     0,     0,
       0,     0,     0,     0,   746,     0,     0,     0,     0,     0,
       0,   754,     0,     0,     0,     0,   587,   588,   589,   590,
     577,   578,     0,     0,  1159,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,     0,     0,     0,     0,     0,
       0,   577,   578,     0,     0,     0,     0,   776,   579,   580,
     581,   582,   583,   584,   585,   586,     0,     0,     0,   786,
       0,     0,     0,     0,   791,   792,     0,   793,   794,   795,
     796,   307,   307,     0,     0,     0,     0,     0,   809,   587,
     588,   589,   590,     0,     0,     0,     0,  1162,     0,     0,
       0,     0,     0,   587,   588,   589,   590,     0,     0,     0,
       0,     0,     0,     0,   835,   836,   837,   838,   839,   840,
     841,   842,   843,   844,   307,   846,   847,   848,   849,   850,
     851,   852,   853,   855,     0,     0,     0,     0,     0,   861,
     862,   864,   866,   867,     0,   869,     0,   871,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   885,     0,     0,
       0,     0,     0,     0,   307,     0,     0,     0,     0,   898,
       0,     0,     0,     0,   577,   578,     0,     0,     0,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   925,   926,
     927,   928,   929,   930,   931,   932,   933,   934,   935,   936,
       0,     0,     0,   587,   588,   589,   590,     0,     0,     0,
       0,  1163,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   587,   588,   589,   590,     0,     0,
       0,     0,  1165,   968,     0,     0,     0,     0,   971,   121,
     122,   123,     0,   124,   125,   126,   127,     0,     0,  1001,
       0,   988,   989,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1009,  1000,     0,   128,   129,  1014,  1003,
    1016,     0,  1018,  1019,     0,     0,     0,     0,  1023,  1024,
    1010,  1011,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     138,  1048,     0,     0,     0,   309,     0,     0,     0,     0,
       0,     0,     0,   310,     0,     0,     0,   140,   141,     0,
       0,   142,     0,   143,     0,     0,   311,   587,   588,   589,
     590,   144,     0,     0,     0,  1166,     0,     0,   145,   577,
     578,     0,   146,   147,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,     0,     0,     0,  1113,  1114,  1098,
     148,   149,   150,   151,   152,   153,     0,  1106,  1108,  1109,
    1110,     0,   154,     0,     0,   155,     0,     0,   156,   157,
     158,  1138,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,     0,   211,   212,   213,   214,     0,
     215,   216,     0,   217,   218,   219,     0,   220,   221,   222,
     223,   224,   225,   226,   339,   340,   341,   342,   343,   227,
     228,     0,   229,     0,     0,     0,     0,     0,   344,   230,
       0,   305,     0,     0,   345,   346,     0,     0,     0,     0,
     347,   348,   349,   350,   351,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   577,   578,     0,     0,
       0,     0,     0,   579,   580,   581,   582,   583,   584,   585,
     586,     0,  1230,  1231,     0,     0,     0,     0,     0,     0,
       0,     0,   587,   588,   589,   590,     0,     0,     0,   352,
    1167,     0,  1234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   615,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1253,     0,
       0,     0,     0,     0,  1260,  1261,     0,   577,   578,     0,
    1266,     0,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,     0,     0,  1279,     0,     0,   577,   578,     0,
       0,     0,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,     0,     0,  1294,     0,     0,     0,     0,  1300,
    1301,  1302,     0,     0,  1305,   577,   578,  1308,     0,  1310,
       0,  1313,   579,   580,   581,   582,   583,   584,   585,   586,
    1323,     0,     0,     0,  1327,     0,     0,     0,     0,     0,
       0,     0,  1333,     0,  1335,     0,     0,     0,     0,  1340,
       0,     0,     0,  1345,  1347,  1348,     0,     0,  1351,  1352,
       0,     0,  1356,     0,     0,  1359,     0,     0,  1362,     0,
    1364,     0,  1366,     0,     0,     0,  1370,     0,  1373,   587,
     588,   589,   590,     0,     0,     0,     0,  1168,     0,  1384,
    1385,  1386,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1390,     0,     0,     0,     0,     0,     0,     0,  1394,
    1395,     0,  1396,  1397,  1398,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1405,  1406,     0,  1408,     0,
       0,  1410,  1411,  1412,     0,  1413,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1418,     0,     0,  1419,
     587,   588,   589,   590,     0,     0,     0,     0,  1169,     0,
       0,  1420,     0,     0,  1421,  1422,  1423,     0,  1424,  1425,
     587,   588,   589,   590,   577,   578,     0,  1427,  1170,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,     0,   577,   578,  1433,  1171,  1434,  1435,  1436,
     579,   580,   581,   582,   583,   584,   585,   586,   577,   578,
       0,  1442,     0,     0,     0,   579,   580,   581,   582,   583,
     584,   585,   586,     0,     0,   577,   578,     0,     0,     0,
       0,  1456,   579,   580,   581,   582,   583,   584,   585,   586,
       0,  1463,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1474,  1475,     0,     0,  1489,   307,
     307,  1492,     0,   577,   578,     0,  1496,     0,  1484,  1485,
     579,   580,   581,   582,   583,   584,   585,   586,     0,     0,
     577,   578,     0,     0,     0,   322,   324,   579,   580,   581,
     582,   583,   584,   585,   586,     0,   338,     0,   353,   354,
     356,   358,   361,   366,   367,   371,   373,   375,     0,     0,
       0,     0,   385,   387,   388,   390,   391,   392,   398,   403,
     411,   418,   420,   422,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1533,     0,     0,     0,     0,   587,   588,   589,
     590,   577,   578,     0,  1556,  1173,     0,     0,   579,   580,
     581,   582,   583,   584,   585,   586,     0,     0,     0,     0,
       0,  1570,     0,     0,     0,     0,   587,   588,   589,   590,
       0,     0,     0,     0,  1184,     0,     0,     0,     0,     0,
       0,   587,   588,   589,   590,     0,     0,     0,     0,  1185,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,     0,     0,     0,     0,  1187,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   619,     0,     0,     0,     0,  1613,     0,     0,     0,
       0,  1617,     0,     0,     0,     0,   587,   588,   589,   590,
       0,     0,     0,     0,  1190,     0,     0,     0,     0,     0,
       0,     0,     0,   587,   588,   589,   590,     0,     0,     0,
       0,  1214,  1640,  1641,  1642,     0,  1644,     0,     0,     0,
       0,     0,     0,  1650,     0,     0,     0,  1654,  1655,     0,
     577,   578,     0,  1660,     0,  1661,  1663,   579,   580,   581,
     582,   583,   584,   585,   586,     0,     0,  1675,     0,     0,
    1678,  1679,     0,  1680,     0,     0,  1683,     0,     0,     0,
       0,  1688,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1696,     0,     0,   587,   588,   589,   590,     0,     0,
       0,     0,  1256,     0,     0,     0,     0,     0,     0,  1705,
       0,  1707,   656,     0,     0,     0,     0,     0,   661,  1710,
       0,     0,     0,     0,     0,   668,   670,     0,  1713,     0,
    1714,     0,     0,     0,     0,  1716,     0,   674,   675,   676,
     677,   678,   679,   680,  1719,     0,   683,   684,   685,   686,
       0,     0,     0,     0,  1728,     0,     0,  1731,     0,     0,
     577,   578,  1744,     0,     0,     0,  1748,   579,   580,   581,
     582,   583,   584,   585,   586,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1752,  1753,     0,     0,
    1756,     0,     0,     0,     0,     0,     0,     0,  1762,     0,
       0,     0,     0,     0,     0,     0,  1767,  1768,     0,     0,
       0,  1771,     0,     0,   577,   578,  1774,     0,     0,     0,
    1778,   579,   580,   581,   582,   583,   584,   585,   586,     0,
       0,     0,     0,   587,   588,   589,   590,  1793,     0,     0,
       0,  1468,     0,   577,   578,   783,   784,   785,     0,     0,
     579,   580,   581,   582,   583,   584,   585,   586,     0,     0,
       0,  1813,     0,     0,     0,     0,   808,     0,     0,   577,
     578,     0,  1826,     0,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,  1831,     0,  1833,     0,  1835,     0,
       0,     0,     0,     0,  1841,     0,     0,  1844,     0,  1846,
       0,     0,  1849,  1850,     0,     0,     0,     0,     0,     0,
       0,     0,  1857,     0,  1859,  1860,  1861,     0,     0,  1864,
       0,     0,     0,     0,     0,  1870,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1878,     0,
       0,     0,     0,   587,   588,   589,   590,     0,  1879,     0,
       0,  1550,     0,     0,     0,     0,  1886,  1887,     0,     0,
       0,     0,   577,   578,     0,     0,     0,     0,     0,   579,
     580,   581,   582,   583,   584,   585,   586,     0,     0,     0,
       0,     0,     0,     0,  1909,     0,     0,  1911,     0,     0,
       0,  1914,  1915,     0,     0,     0,     0,   587,   588,   589,
     590,   577,   578,     0,     0,  1551,     0,     0,   579,   580,
     581,   582,   583,   584,   585,   586,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
       0,  1950,     0,  1952,  1558,     0,  1955,     0,     0,     0,
       0,     0,     0,     0,  1960,     0,     0,  1961,     0,     0,
       0,  1965,   587,   588,   589,   590,     0,     0,     0,  1968,
    1559,  1970,     0,  1005,     0,     0,     0,  1008,     0,     0,
       0,  1012,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1982,     0,     0,  1026,  1027,     0,     0,
       0,     0,     0,     0,  1033,     0,     0,     0,     0,  1037,
       0,  1991,     0,  1993,  1042,     0,  1044,     0,     0,     0,
     121,   122,   123,     0,   124,   125,   126,   127,  1056,     0,
    1058,  1059,     0,  1061,  1062,  1063,  2012,     0,     0,     0,
       0,  1067,     0,     0,     0,  2017,  1071,   128,   129,     0,
       0,     0,     0,     0,  1077,   587,   588,   589,   590,     0,
       0,     0,  1084,  1560,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,   587,   588,   589,   590,   137,     0,
       0,   138,  1561,     0,     0,     0,   303,     0,     0,     0,
       0,     0,     0,     0,   304,     0,     0,     0,   140,   141,
       0,     0,   142,     0,   143,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,   146,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,   149,   150,   151,   152,   153,     0,     0,     0,
       0,     0,     0,   154,     0,     0,   155,     0,     0,   156,
     157,   158,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,     0,   211,   212,   213,   214,
       0,   215,   216,     0,   217,   218,   219,     0,   220,   221,
     222,   223,   224,   225,   226,     0,     0,     0,     0,     0,
     227,   228,     0,   229,     0,     0,     0,     0,     0,     0,
     230,     0,   305,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   122,   123,     0,   124,   125,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1284,
       0,   128,   129,     0,     0,     0,     0,  1288,     0,     0,
       0,     0,  1293,     0,  1295,     0,  1297,  1298,     0,     0,
       0,  1303,  1304,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,     0,     0,   138,     0,     0,     0,     0,
     139,     0,     0,     0,     0,     0,     0,     0,   797,     0,
       0,     0,   140,   141,     0,     0,   142,     0,   143,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,   145,   577,   578,     0,   146,   147,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,     0,
       0,  1391,  1392,     0,     0,   148,   149,   150,   151,   152,
     153,     0,     0,     0,     0,     0,     0,   154,     0,     0,
     155,     0,     0,   156,   157,   158,  1407,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,     0,
     211,   212,   213,   214,     0,   215,   216,     0,   217,   218,
     219,     0,   220,   221,   222,   223,   224,   225,   226,     0,
       0,     0,     0,     0,   227,   228,     0,   229,     0,     0,
       0,     0,     0,     0,   230,     0,   305,   121,   122,   123,
       0,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   587,   588,   589,
     590,     0,     0,     0,     0,  1562,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,   577,   578,     0,
     146,   147,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,     0,     0,     0,     0,     0,     0,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   155,     0,     0,   156,   157,   158,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,     0,   211,   212,   213,   214,     0,   215,   216,
       0,   217,   218,   219,     0,   220,   221,   222,   223,   224,
     225,   226,     0,     0,     0,     0,     0,   227,   228,     0,
     229,     0,     0,     0,     0,     0,     0,   230,     0,   305,
       0,     0,     0,     0,     0,     0,     0,  1636,     0,     0,
    1639,     0,     0,     0,  1643,     0,     0,   121,   122,   123,
       0,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,   129,     0,     0,     0,     0,
     587,   588,   589,   590,     0,     0,     0,     0,  1567,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1699,     0,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,   577,
     578,     0,     0,   139,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,   577,   578,     0,
     146,   147,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,     0,     0,     0,     0,     0,     0,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   155,     0,     0,   156,   157,   158,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,     0,   211,   212,   213,   214,     0,   215,   216,
       0,   217,   218,   219,     0,   220,   221,   222,   223,   224,
     225,   226,     0,     0,     0,     0,     0,   227,   228,     0,
     229,     0,  1830,     0,     0,     0,  1834,   230,   775,   121,
     122,   123,     0,   124,   125,   126,   127,     0,     0,     0,
       0,     0,   587,   588,   589,   590,     0,     0,     0,     0,
    1568,     0,     0,     0,     0,     0,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     587,   588,   589,   590,     0,     0,     0,     0,  1575,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     138,   577,   578,     0,     0,   139,     0,     0,   579,   580,
     581,   582,   583,   584,   585,   586,     0,   140,   141,     0,
       0,   142,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,   145,   577,
     578,     0,   146,   147,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,     0,     0,     0,     0,     0,     0,
     148,   149,   150,   151,   152,   153,     0,     0,     0,     0,
       0,     0,   154,     0,     0,   155,     0,     0,   156,   157,
     158,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,     0,   211,   212,   213,   214,     0,
     215,   216,     0,   217,   218,   219,     0,   220,   221,   222,
     223,   224,   225,   226,     0,     0,     0,     0,     0,   227,
     228,     0,   229,     0,     0,     0,     0,     0,     0,   230,
     854,   121,   122,   123,     0,   124,   125,   126,   127,     0,
       0,     0,     0,     0,   587,   588,   589,   590,     0,     0,
       0,     0,  1576,     0,     0,     0,     0,     0,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   587,   588,   589,   590,     0,     0,     0,     0,
    1577,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,   138,   577,   578,     0,     0,   139,     0,     0,
     579,   580,   581,   582,   583,   584,   585,   586,     0,   140,
     141,     0,     0,   142,     0,   143,     0,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
     145,   577,   578,     0,   146,   147,     0,     0,   579,   580,
     581,   582,   583,   584,   585,   586,     0,     0,     0,     0,
       0,     0,   148,   149,   150,   151,   152,   153,     0,     0,
       0,     0,     0,     0,   154,     0,     0,   155,     0,     0,
     156,   157,   158,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,     0,   211,   212,   213,
     214,     0,   215,   216,     0,   217,   218,   219,     0,   220,
     221,   222,   223,   224,   225,   226,     0,     0,     0,     0,
       0,   227,   228,     0,   229,     0,     0,     0,     0,     0,
       0,   230,   865,   121,   122,   123,     0,   124,   125,   126,
     127,     0,     0,     0,     0,     0,   587,   588,   589,   590,
       0,     0,     0,     0,  1578,     0,     0,     0,     0,     0,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   587,   588,   589,   590,     0,     0,
       0,     0,  1579,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,   138,     0,     0,     0,     0,   139,
       0,     0,     0,     0,     0,   404,     0,     0,     0,     0,
       0,   140,   141,     0,     0,   142,     0,   143,     0,     0,
       0,     0,     0,     0,     0,   144,     0,     0,     0,     0,
       0,     0,   145,     0,     0,     0,   146,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   405,   406,   148,   149,   150,   151,   152,   153,
       0,   407,   408,   409,   410,     0,   154,     0,     0,   155,
       0,     0,   156,   157,   158,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,     0,   211,
     212,   213,   214,     0,   215,   216,     0,   217,   218,   219,
       0,   220,   221,   222,   223,   224,   225,   226,     0,     0,
       0,     0,     0,   227,   228,     0,   229,     0,     0,     0,
     121,   122,   123,   230,   124,   125,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   412,     0,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,   138,     0,     0,     0,     0,   139,     0,     0,     0,
       0,     0,   413,     0,     0,     0,     0,     0,   140,   141,
       0,     0,   142,     0,   143,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,   145,
     577,   578,     0,   146,   147,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,     0,     0,     0,     0,   414,
     415,   148,   149,   150,   151,   152,   153,   416,     0,     0,
       0,   417,     0,   154,     0,     0,   155,     0,     0,   156,
     157,   158,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,     0,   211,   212,   213,   214,
       0,   215,   216,     0,   217,   218,   219,     0,   220,   221,
     222,   223,   224,   225,   226,     0,     0,     0,     0,     0,
     227,   228,     0,   229,     0,     0,     0,   121,   122,   123,
     230,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   587,   588,   589,   590,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   394,   395,   148,   149,
     150,   151,   152,   153,     0,   396,     0,     0,   397,     0,
     154,     0,     0,   155,     0,     0,   156,   157,   158,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,     0,   211,   212,   213,   214,     0,   215,   216,
       0,   217,   218,   219,     0,   220,   221,   222,   223,   224,
     225,   226,     0,     0,     0,     0,     0,   227,   228,     0,
     229,     0,     0,     0,   121,   122,   123,   230,   124,   125,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   362,     0,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,     0,     0,   138,     0,     0,     0,     0,
     139,     0,     0,     0,     0,     0,   363,     0,     0,     0,
       0,     0,   140,   141,     0,     0,   142,     0,   143,     0,
       0,     0,   364,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,   145,     0,     0,     0,   146,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   365,     0,   148,   149,   150,   151,   152,
     153,     0,     0,     0,     0,     0,     0,   154,     0,     0,
     155,     0,     0,   156,   157,   158,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,     0,
     211,   212,   213,   214,     0,   215,   216,     0,   217,   218,
     219,     0,   220,   221,   222,   223,   224,   225,   226,     0,
       0,     0,     0,     0,   227,   228,     0,   229,     0,     0,
       0,   121,   122,   123,   230,   124,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,   138,     0,     0,     0,     0,   139,     0,     0,
       0,     0,     0,   399,     0,     0,     0,     0,     0,   140,
     141,     0,     0,   142,     0,   143,     0,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     400,   401,   148,   149,   150,   151,   152,   153,     0,     0,
       0,     0,   402,     0,   154,     0,     0,   155,     0,     0,
     156,   157,   158,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,     0,   211,   212,   213,
     214,     0,   215,   216,     0,   217,   218,   219,     0,   220,
     221,   222,   223,   224,   225,   226,     0,     0,     0,     0,
       0,   227,   228,     0,   229,     0,     0,     0,   121,   122,
     123,   230,   124,   125,   126,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   368,     0,     0,
       0,     0,     0,     0,     0,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   369,     0,   130,   131,
     132,   133,   134,   135,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,   138,
     577,   578,     0,     0,   139,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,     0,   140,   141,     0,     0,
     142,     0,   143,     0,     0,     0,   370,     0,     0,     0,
     144,     0,     0,     0,     0,     0,     0,   145,     0,     0,
       0,   146,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
     149,   150,   151,   152,   153,     0,     0,     0,     0,     0,
       0,   154,     0,     0,   155,     0,     0,   156,   157,   158,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     0,   211,   212,   213,   214,     0,   215,
     216,     0,   217,   218,   219,     0,   220,   221,   222,   223,
     224,   225,   226,     0,     0,     0,     0,     0,   227,   228,
       0,   229,     0,     0,     0,   121,   122,   123,   230,   124,
     125,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   587,   588,   589,   590,     0,     0,     0,
       0,  1582,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,     0,   138,   577,   578,     0,
       0,   139,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,     0,   140,   141,     0,     0,   142,     0,   143,
       0,     0,     0,   382,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   383,   384,   148,   149,   150,   151,
     152,   153,     0,     0,     0,     0,     0,     0,   154,     0,
       0,   155,     0,     0,   156,   157,   158,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
       0,   211,   212,   213,   214,     0,   215,   216,     0,   217,
     218,   219,     0,   220,   221,   222,   223,   224,   225,   226,
       0,     0,     0,     0,     0,   227,   228,     0,   229,     0,
       0,     0,   121,   122,   123,   230,   124,   125,   126,   127,
       0,   320,     0,     0,     0,     0,     0,     0,     0,     0,
     587,   588,   589,   590,     0,     0,     0,     0,  1583,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   321,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,   132,   133,   134,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,     0,     0,   138,   577,   578,     0,     0,   139,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,     0,
     140,   141,     0,     0,   142,     0,   143,     0,     0,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,     0,
       0,   145,     0,     0,     0,   146,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,   149,   150,   151,   152,   153,     0,
       0,     0,     0,     0,     0,   154,     0,     0,   155,     0,
       0,   156,   157,   158,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,     0,   211,   212,
     213,   214,     0,   215,   216,     0,   217,   218,   219,     0,
     220,   221,   222,   223,   224,   225,   226,     0,     0,     0,
       0,     0,   227,   228,     0,   229,     0,     0,     0,   121,
     122,   123,   230,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   587,   588,   589,
     590,     0,     0,     0,     0,  1586,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     138,     0,     0,     0,     0,   139,     0,     0,     0,     0,
       0,   359,     0,     0,     0,     0,     0,   140,   141,     0,
       0,   142,     0,   143,     0,     0,     0,   360,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,   150,   151,   152,   153,     0,     0,     0,     0,
       0,     0,   154,     0,     0,   155,     0,     0,   156,   157,
     158,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,     0,   211,   212,   213,   214,     0,
     215,   216,     0,   217,   218,   219,     0,   220,   221,   222,
     223,   224,   225,   226,     0,     0,     0,     0,     0,   227,
     228,     0,   229,     0,     0,     0,   121,   122,   123,   230,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   131,   132,   133,
     134,   135,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,     0,     0,   138,   577,   578,
       0,     0,   139,     0,     0,   579,   580,   581,   582,   583,
     584,   585,   586,     0,   140,   141,     0,     0,   142,     0,
     143,     0,     0,     0,     0,   432,     0,     0,   144,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,   146,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   433,   148,   149,   150,
     151,   152,   153,     0,     0,     0,     0,     0,     0,   154,
       0,     0,   155,     0,     0,   156,   157,   158,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,     0,   211,   212,   213,   214,     0,   215,   216,     0,
     217,   218,   219,     0,   220,   221,   222,   223,   224,   225,
     226,     0,     0,     0,     0,     0,   227,   228,     0,   229,
       0,     0,     0,   121,   122,   123,   230,   124,   125,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   587,   588,   589,   590,     0,     0,     0,     0,  1594,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,   138,   577,   578,     0,     0,   139,
       0,     0,   579,   580,   581,   582,   583,   584,   585,   586,
       0,   140,   141,     0,     0,   142,     0,   143,     0,     0,
       0,     0,   464,   465,     0,   144,     0,     0,     0,     0,
       0,     0,   145,     0,     0,     0,   146,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   149,   150,   151,   152,   153,
       0,     0,     0,     0,     0,     0,   154,     0,     0,   155,
       0,     0,   156,   157,   158,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,     0,   211,
     212,   213,   214,     0,   215,   216,     0,   217,   218,   219,
       0,   220,   221,   222,   223,   224,   225,   226,     0,     0,
       0,     0,     0,   227,   228,     0,   229,     0,     0,     0,
     121,   122,   123,   230,   124,   125,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,     0,     0,     0,     0,  1597,   128,   129,     0,
       0,   262,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,   138,   577,   578,     0,     0,   139,     0,     0,   579,
     580,   581,   582,   583,   584,   585,   586,     0,   140,   141,
       0,     0,   142,     0,   143,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,   146,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,   149,   150,   151,   152,   153,     0,     0,     0,
       0,     0,     0,   154,     0,     0,   155,     0,     0,   156,
     157,   158,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,     0,   211,   212,   213,   214,
       0,   215,   216,     0,   217,   218,   219,     0,   220,   221,
     222,   223,   224,   225,   226,     0,     0,     0,     0,     0,
     227,   228,     0,   229,     0,     0,     0,   121,   122,   123,
     230,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   587,   588,   589,   590,     0,
       0,     0,     0,  1612,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,   577,
     578,     0,     0,   139,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,   323,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   155,     0,     0,   156,   157,   158,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,     0,   211,   212,   213,   214,     0,   215,   216,
       0,   217,   218,   219,     0,   220,   221,   222,   223,   224,
     225,   226,     0,     0,     0,     0,     0,   227,   228,     0,
     229,     0,     0,     0,   121,   122,   123,   230,   124,   125,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   587,   588,   589,   590,     0,     0,     0,     0,
    1726,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,     0,     0,   138,   577,   578,     0,     0,
     139,     0,     0,   579,   580,   581,   582,   583,   584,   585,
     586,     0,   140,   141,     0,     0,   142,     0,   143,     0,
       0,     0,   355,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,   145,     0,     0,     0,   146,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   148,   149,   150,   151,   152,
     153,     0,     0,     0,     0,     0,     0,   154,     0,     0,
     155,     0,     0,   156,   157,   158,     0,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,     0,
     211,   212,   213,   214,     0,   215,   216,     0,   217,   218,
     219,     0,   220,   221,   222,   223,   224,   225,   226,     0,
       0,     0,     0,     0,   227,   228,     0,   229,     0,     0,
       0,   121,   122,   123,   230,   124,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   587,
     588,   589,   590,     0,     0,     0,     0,  1730,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,   138,   577,   578,     0,     0,   139,     0,     0,
     579,   580,   581,   582,   583,   584,   585,   586,     0,   140,
     141,     0,     0,   142,     0,   143,     0,     0,     0,   357,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,   149,   150,   151,   152,   153,     0,     0,
       0,     0,     0,     0,   154,     0,     0,   155,     0,     0,
     156,   157,   158,     0,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,     0,   211,   212,   213,
     214,     0,   215,   216,     0,   217,   218,   219,     0,   220,
     221,   222,   223,   224,   225,   226,     0,     0,     0,     0,
       0,   227,   228,     0,   229,     0,     0,     0,   121,   122,
     123,   230,   124,   125,   126,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
       0,     0,     0,     0,  1791,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,   131,
     132,   133,   134,   135,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,   138,
     577,   578,     0,     0,   139,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,     0,   140,   141,     0,     0,
     142,     0,   143,     0,     0,     0,   372,     0,     0,     0,
     144,     0,     0,     0,     0,     0,     0,   145,     0,     0,
       0,   146,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   148,
     149,   150,   151,   152,   153,     0,     0,     0,     0,     0,
       0,   154,     0,     0,   155,     0,     0,   156,   157,   158,
       0,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     0,   211,   212,   213,   214,     0,   215,
     216,     0,   217,   218,   219,     0,   220,   221,   222,   223,
     224,   225,   226,     0,     0,     0,     0,     0,   227,   228,
       0,   229,     0,     0,     0,   121,   122,   123,   230,   124,
     125,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   587,   588,   589,   590,     0,     0,     0,
       0,  1800,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,     0,   138,   577,   578,     0,
       0,   139,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,     0,   140,   141,     0,     0,   142,     0,   143,
       0,     0,     0,   374,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,   150,   151,
     152,   153,     0,     0,     0,     0,     0,     0,   154,     0,
       0,   155,     0,     0,   156,   157,   158,     0,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
       0,   211,   212,   213,   214,     0,   215,   216,     0,   217,
     218,   219,     0,   220,   221,   222,   223,   224,   225,   226,
       0,     0,     0,     0,     0,   227,   228,     0,   229,     0,
       0,     0,   121,   122,   123,   230,   124,   125,   126,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     587,   588,   589,   590,     0,     0,     0,     0,  1803,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,   132,   133,   134,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,     0,     0,   138,   577,   578,     0,     0,   139,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,     0,
     140,   141,     0,     0,   142,     0,   143,     0,     0,     0,
     386,     0,     0,     0,   144,     0,     0,     0,     0,     0,
       0,   145,     0,     0,     0,   146,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,   149,   150,   151,   152,   153,     0,
       0,     0,     0,     0,     0,   154,     0,     0,   155,     0,
       0,   156,   157,   158,     0,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,     0,   211,   212,
     213,   214,     0,   215,   216,     0,   217,   218,   219,     0,
     220,   221,   222,   223,   224,   225,   226,     0,     0,     0,
       0,     0,   227,   228,     0,   229,     0,     0,     0,   121,
     122,   123,   230,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   587,   588,   589,
     590,     0,     0,     0,     0,  1804,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     138,   577,   578,     0,     0,   139,     0,     0,   579,   580,
     581,   582,   583,   584,   585,   586,     0,   140,   141,     0,
       0,   142,     0,   143,     0,     0,     0,   389,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,   150,   151,   152,   153,     0,     0,     0,     0,
       0,     0,   154,     0,     0,   155,     0,     0,   156,   157,
     158,     0,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,     0,   211,   212,   213,   214,     0,
     215,   216,     0,   217,   218,   219,     0,   220,   221,   222,
     223,   224,   225,   226,     0,     0,     0,     0,     0,   227,
     228,     0,   229,     0,     0,     0,   121,   122,   123,   230,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   587,   588,   589,   590,     0,     0,
       0,     0,  1806,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   131,   132,   133,
     134,   135,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,     0,     0,   138,   577,   578,
       0,     0,   139,     0,     0,   579,   580,   581,   582,   583,
     584,   585,   586,     0,   140,   141,     0,     0,   142,     0,
     143,     0,     0,     0,   419,     0,     0,     0,   144,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,   146,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,   149,   150,
     151,   152,   153,     0,     0,     0,     0,     0,     0,   154,
       0,     0,   155,     0,     0,   156,   157,   158,     0,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,     0,   211,   212,   213,   214,     0,   215,   216,     0,
     217,   218,   219,     0,   220,   221,   222,   223,   224,   225,
     226,     0,     0,     0,     0,     0,   227,   228,     0,   229,
       0,     0,     0,   121,   122,   123,   230,   124,   125,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   587,   588,   589,   590,     0,     0,     0,     0,  1823,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,   138,   577,   578,     0,     0,   139,
       0,     0,   579,   580,   581,   582,   583,   584,   585,   586,
       0,   140,   141,     0,     0,   142,     0,   143,     0,     0,
       0,   421,     0,     0,     0,   144,     0,     0,     0,     0,
       0,     0,   145,     0,     0,     0,   146,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   149,   150,   151,   152,   153,
       0,     0,     0,     0,     0,     0,   154,     0,     0,   155,
       0,     0,   156,   157,   158,     0,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,     0,   211,
     212,   213,   214,     0,   215,   216,     0,   217,   218,   219,
       0,   220,   221,   222,   223,   224,   225,   226,     0,     0,
       0,     0,     0,   227,   228,     0,   229,     0,     0,     0,
     121,   122,   123,   230,   124,   125,   126,   127,     0,   669,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,     0,     0,     0,     0,  1932,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,   138,   577,   578,     0,     0,   139,     0,     0,   579,
     580,   581,   582,   583,   584,   585,   586,     0,   140,   141,
       0,     0,   142,     0,   143,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,   146,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   148,   149,   150,   151,   152,   153,     0,     0,     0,
       0,     0,     0,   154,     0,     0,   155,     0,     0,   156,
     157,   158,     0,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,     0,   211,   212,   213,   214,
       0,   215,   216,     0,   217,   218,   219,     0,   220,   221,
     222,   223,   224,   225,   226,     0,     0,     0,     0,     0,
     227,   228,     0,   229,     0,     0,     0,   121,   122,   123,
     230,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   587,   588,   589,   590,     0,
       0,     0,     0,  1945,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,   577,
     578,     0,     0,   139,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,   577,   578,     0,
     146,   147,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,     0,     0,     0,     0,     0,     0,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   155,     0,     0,   156,   157,   158,     0,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,     0,   211,   212,   213,   214,     0,   215,   216,
       0,   217,   218,   219,     0,   220,   221,   222,   223,   224,
     225,   226,     0,     0,   123,     0,     0,   227,   228,   127,
     229,     0,     0,     0,     0,     0,     0,   230,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   587,   588,   589,   590,     0,     0,     0,     0,
    1988,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     587,   588,   589,   590,     0,     0,     0,     0,  2009,   577,
     578,     0,     0,     0,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,     0,     0,     0,     0,     0,     0,
     577,   578,     0,     0,   142,     0,   143,   579,   580,   581,
     582,   583,   584,   585,   586,   123,     0,     0,     0,     0,
     127,     0,     0,     0,     0,   146,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,     0,   238,   239,   240,   241,   152,     0,     0,
       0,     0,     0,     0,     0,   154,     0,     0,   155,     0,
       0,   156,   157,   242,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,   181,   182,     0,
       0,     0,   186,   187,   188,     0,   190,     0,   192,   193,
     194,     0,     0,     0,     0,   199,   200,   201,   202,   203,
       0,     0,   206,     0,   208,   142,   210,   143,     0,   212,
       0,   214,     0,     0,   216,     0,     0,   218,   219,     0,
     220,   221,     0,   223,   123,   225,   146,   147,     0,   127,
       0,     0,     0,   228,     0,     0,     0,     0,     0,     0,
       0,     0,   243,   876,   238,   239,   240,   241,   152,     0,
     129,     0,   587,   588,   589,   590,   154,     0,     0,   155,
    2024,     0,   156,   157,   242,     0,     0,     0,     0,     0,
       0,     0,     0,   587,   588,   589,   590,     0,     0,   642,
       0,     0,     0,     0,     0,     0,     0,   180,   181,   182,
       0,     0,     0,   186,   187,   188,     0,   190,     0,   192,
     193,   194,     0,     0,     0,     0,   199,   200,   201,   202,
     203,     0,     0,   206,     0,   208,     0,   210,     0,     0,
     212,     0,   214,     0,   142,   216,   143,     0,   218,   219,
       0,   220,   221,     0,   223,     0,   225,     0,     0,     0,
       0,     0,     0,   123,   228,   146,   147,     0,   127,     0,
       0,     0,     0,   243,   878,     0,     0,     0,     0,     0,
       0,     0,     0,   238,   239,   240,   241,   152,     0,   129,
       0,     0,     0,     0,     0,   154,     0,     0,   155,     0,
       0,   156,   157,   242,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,   181,   182,     0,
       0,     0,   186,   187,   188,     0,   190,     0,   192,   193,
     194,     0,     0,     0,     0,   199,   200,   201,   202,   203,
       0,     0,   206,     0,   208,     0,   210,     0,     0,   212,
       0,   214,     0,   142,   216,   143,     0,   218,   219,   376,
     220,   221,     0,   223,     0,   225,     0,     0,     0,     0,
       0,     0,   123,   228,   146,   147,     0,   127,     0,     0,
       0,     0,   243,   880,     0,     0,     0,     0,     0,     0,
       0,     0,   238,   239,   240,   241,   152,     0,   129,     0,
       0,     0,     0,     0,   154,     0,     0,   155,     0,     0,
     156,   157,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   180,   181,   182,     0,     0,
       0,   186,   187,   188,     0,   190,     0,   192,   193,   194,
       0,     0,     0,     0,   199,   200,   201,   202,   203,     0,
       0,   206,     0,   208,     0,   210,     0,     0,   212,     0,
     214,     0,   142,   216,   143,     0,   218,   219,   423,   220,
     221,     0,   223,     0,   225,     0,     0,     0,     0,     0,
       0,   123,   228,   146,   147,     0,   127,     0,     0,     0,
       0,   243,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,   239,   240,   241,   152,     0,   129,     0,     0,
       0,     0,     0,   154,     0,     0,   155,     0,     0,   156,
     157,   242,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   180,   181,   182,     0,     0,     0,
     186,   187,   188,     0,   190,     0,   192,   193,   194,     0,
       0,     0,     0,   199,   200,   201,   202,   203,     0,     0,
     206,     0,   208,     0,   210,     0,     0,   212,     0,   214,
       0,   142,   216,   143,     0,   218,   219,   425,   220,   221,
       0,   223,     0,   225,     0,     0,     0,     0,     0,     0,
     123,   228,   146,   147,     0,   127,     0,     0,     0,     0,
     243,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,   239,   240,   241,   152,     0,   129,     0,     0,     0,
       0,     0,   154,     0,     0,   155,     0,     0,   156,   157,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,   182,     0,     0,     0,   186,
     187,   188,     0,   190,     0,   192,   193,   194,     0,     0,
       0,     0,   199,   200,   201,   202,   203,     0,     0,   206,
       0,   208,     0,   210,     0,     0,   212,     0,   214,     0,
     142,   216,   143,     0,   218,   219,   427,   220,   221,     0,
     223,   123,   225,     0,     0,     0,   127,     0,     0,     0,
     228,   146,   147,     0,     0,     0,     0,     0,     0,   243,
       0,     0,     0,     0,     0,     0,     0,   129,     0,   238,
     239,   240,   241,   152,     0,     0,     0,     0,     0,     0,
       0,   154,     0,     0,   155,     0,     0,   156,   157,   242,
       0,     0,   577,   578,     0,     0,     0,     0,     0,   579,
     580,   581,   582,   583,   584,   585,   586,     0,     0,     0,
       0,     0,   180,   181,   182,     0,     0,     0,   186,   187,
     188,     0,   190,     0,   192,   193,   194,     0,     0,     0,
       0,   199,   200,   201,   202,   203,     0,     0,   206,     0,
     208,   142,   210,   143,     0,   212,     0,   214,     0,     0,
     216,     0,     0,   218,   219,     0,   220,   221,     0,   223,
       0,   225,   146,   147,     0,     0,     0,     0,     0,   228,
       0,   123,     0,     0,     0,     0,   127,     0,   243,     0,
     238,   239,   240,   241,   152,     0,   750,     0,     0,     0,
       0,     0,   154,     0,     0,   155,     0,   129,   156,   157,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,   182,     0,     0,     0,   186,
     187,   188,     0,   190,     0,   192,   193,   194,     0,     0,
       0,     0,   199,   200,   201,   202,   203,     0,     0,   206,
       0,   208,     0,   210,     0,     0,   212,     0,   214,     0,
       0,   216,     0,     0,   218,   219,     0,   220,   221,     0,
     223,   142,   225,   143,     0,   587,   588,   589,   590,     0,
     228,   643,     0,     0,     0,     0,     0,     0,     0,   243,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,   127,     0,     0,     0,
     238,   239,   240,   241,   152,     0,   826,     0,     0,     0,
       0,     0,   154,     0,     0,   155,     0,   129,   156,   157,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,   182,     0,     0,     0,   186,
     187,   188,     0,   190,     0,   192,   193,   194,     0,     0,
       0,     0,   199,   200,   201,   202,   203,     0,     0,   206,
       0,   208,     0,   210,     0,     0,   212,     0,   214,     0,
       0,   216,     0,   998,   218,   219,     0,   220,   221,     0,
     223,   142,   225,   143,   577,   578,     0,     0,     0,     0,
     228,   579,   580,   581,   582,   583,   584,   585,   586,   243,
     123,     0,   146,   147,     0,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,   239,   240,   241,   152,     0,   129,     0,     0,     0,
       0,     0,   154,     0,     0,   155,     0,     0,   156,   157,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,   182,     0,     0,     0,   186,
     187,   188,     0,   190,     0,   192,   193,   194,     0,     0,
       0,     0,   199,   200,   201,   202,   203,     0,     0,   206,
       0,   208,  1400,   210,     0,     0,   212,     0,   214,     0,
     142,   216,   143,     0,   218,   219,     0,   220,   221,     0,
     223,   123,   225,     0,     0,     0,   127,     0,     0,     0,
     228,   146,   147,     0,     0,     0,     0,     0,     0,   243,
       0,     0,     0,     0,     0,     0,     0,   129,     0,   238,
     239,   240,   241,   152,     0,     0,     0,     0,     0,     0,
       0,   154,     0,     0,   155,     0,     0,   156,   157,   242,
       0,     0,     0,     0,     0,     0,     0,   587,   588,   589,
     590,     0,     0,   660,     0,     0,     0,     0,     0,     0,
       0,     0,   180,   181,   182,     0,     0,     0,   186,   187,
     188,     0,   190,     0,   192,   193,   194,     0,     0,     0,
       0,   199,   200,   201,   202,   203,     0,     0,   206,     0,
     208,   142,   210,   143,     0,   212,     0,   214,     0,     0,
     216,     0,     0,   218,   219,     0,   220,   221,     0,   223,
     123,   225,   146,   147,     0,   127,     0,     0,     0,   228,
       0,     0,     0,     0,     0,     0,     0,     0,   243,     0,
     238,   239,   240,   241,   152,     0,   129,     0,     0,     0,
       0,     0,   154,     0,     0,   155,     0,     0,   156,   157,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   180,   181,   182,     0,     0,     0,   186,
     187,   188,     0,   190,     0,   192,   193,   194,     0,     0,
       0,     0,   199,   200,   201,   202,   203,     0,     0,   206,
       0,   208,     0,   210,     0,     0,   212,     0,   214,     0,
     142,   216,   143,     0,   218,   219,     0,   220,   221,     0,
     223,     0,   225,     0,     0,     0,     0,     0,     0,     0,
     228,   146,   147,     0,     0,     0,     0,     0,     0,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
     239,   240,   241,   152,     0,     0,     0,     0,     0,     0,
       0,   154,     0,     0,   155,     0,     0,   156,   157,   242,
       0,     0,     0,   577,   578,     0,     0,     0,     0,     0,
     579,   580,   581,   582,   583,   584,   585,   586,     0,     0,
       0,     0,   180,   181,   182,     0,     0,     0,   186,   187,
     188,     0,   190,     0,   192,   193,   194,     0,     0,     0,
       0,   199,   200,   201,   202,   203,     0,     0,   206,     0,
     208,     0,   210,     0,     0,   212,     0,   214,     0,     0,
     216,     0,     0,   218,   219,     0,   220,   221,     0,   223,
       0,   225,     0,     0,     7,     8,     9,     0,     0,   228,
       0,    10,     0,     0,     0,    11,     0,    12,  1257,    13,
      14,    15,    16,    17,  -478,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,     0,     0,
       0,     0,    29,     0,     0,    30,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,     0,     0,
       0,    37,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,    45,
      46,    47,  -235,  -235,    48,    49,    50,     0,    51,    52,
      53,     0,     0,    54,  -235,     0,    55,     0,    56,    57,
       0,     0,     0,     0,    58,    59,   587,   588,   589,   590,
       0,    60,   770,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,     0,    80,    81,    82,    83,    84,    85,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,     0,     0,     0,    90,    91,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    93,    94,
       0,     0,     0,     0,    95,     0,     0,     0,     0,   577,
     578,     0,     0,     0,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,    96,     0,     0,     0,    97,     0,
       7,     8,     9,    98,     0,     0,    99,    10,     0,     0,
     100,    11,     0,    12,     0,    13,    14,    15,    16,    17,
    -478,     0,    18,    19,    20,    21,    22,    23,    24,    25,
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
      90,    91,   587,   588,   589,   590,     0,     0,   995,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,    93,    94,     0,     0,     0,     0,
      95,     0,     0,     0,     0,   577,   578,     0,     0,     0,
       0,     0,   579,   580,   581,   582,   583,   584,   585,   586,
      96,     0,     0,     0,    97,     0,     7,     8,     9,    98,
       0,     0,    99,    10,     0,     0,   100,    11,     0,    12,
       0,    13,    14,    15,    16,    17,  -478,     0,    18,    19,
      20,    21,    22,    23,    24,    25,     0,    26,    27,    28,
     -16,     0,     0,     0,    29,   -16,     0,    30,     0,     0,
       0,     0,     0,     0,    31,    32,    33,    34,    35,    36,
     577,   578,     0,    37,    38,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,     0,     0,     0,     0,     0,
      39,    40,    41,    42,    43,    44,     0,     0,     0,     0,
       0,    45,    46,    47,     0,     0,    48,    49,    50,     0,
      51,    52,    53,     0,     0,    54,     0,     0,    55,     0,
      56,    57,     0,     0,     0,     0,    58,    59,     0,     0,
       0,     0,     0,    60,     0,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,    80,    81,    82,    83,
      84,    85,     0,     0,     0,     0,     0,     0,    86,    87,
      88,    89,     0,     0,     0,     0,    90,    91,   587,   588,
     589,   590,   577,   578,  1025,     0,     0,     0,     0,   579,
     580,   581,   582,   583,   584,   585,   586,     0,     0,    92,
      93,    94,   577,   578,     0,     0,    95,     0,     0,   579,
     580,   581,   582,   583,   584,   585,   586,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,     0,     0,     0,
      97,     0,     0,     0,     0,    98,   577,   578,    99,     0,
       0,     0,   100,   579,   580,   581,   582,   583,   584,   585,
     586,     0,     0,   587,   588,   589,   590,   577,   578,  1120,
       0,     0,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,   577,   578,     0,     0,     0,     0,     0,   579,
     580,   581,   582,   583,   584,   585,   586,   577,   578,     0,
       0,     0,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,   577,   578,     0,     0,     0,     0,     0,   579,
     580,   581,   582,   583,   584,   585,   586,   577,   578,     0,
       0,     0,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,   577,   578,     0,     0,     0,     0,     0,   579,
     580,   581,   582,   583,   584,   585,   586,   577,   578,     0,
       0,     0,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,     0,     0,     0,   587,   588,   589,   590,   577,
     578,  1121,     0,     0,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,     0,   587,   588,   589,   590,   577,
     578,  1123,     0,     0,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,   577,   578,     0,     0,     0,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   577,   578,  1124,     0,     0,     0,     0,
     579,   580,   581,   582,   583,   584,   585,   586,     0,     0,
     587,   588,   589,   590,     0,     0,  1125,     0,     0,     0,
       0,     0,     0,     0,     0,   587,   588,   589,   590,     0,
       0,  1139,     0,     0,     0,     0,     0,     0,     0,     0,
     587,   588,   589,   590,     0,     0,  1172,     0,     0,     0,
       0,     0,     0,     0,     0,   587,   588,   589,   590,     0,
       0,  1179,     0,     0,     0,     0,     0,     0,     0,     0,
     587,   588,   589,   590,     0,     0,  1180,     0,     0,     0,
       0,     0,     0,     0,     0,   587,   588,   589,   590,     0,
       0,  1200,     0,     0,     0,     0,     0,     0,     0,     0,
     587,   588,   589,   590,   577,   578,  1252,     0,     0,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,     0,
       0,     0,   587,   588,   589,   590,   577,   578,  1275,     0,
       0,     0,     0,   579,   580,   581,   582,   583,   584,   585,
     586,     0,   587,   588,   589,   590,     0,     0,  1276,     0,
       0,     0,     0,     0,     0,     0,     0,   587,   588,   589,
     590,   577,   578,  1283,     0,     0,     0,     0,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
     577,   578,  1289,     0,     0,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,   577,   578,     0,     0,     0,
       0,     0,   579,   580,   581,   582,   583,   584,   585,   586,
     577,   578,     0,     0,     0,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,   577,   578,     0,     0,     0,
       0,     0,   579,   580,   581,   582,   583,   584,   585,   586,
     577,   578,     0,     0,     0,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,   577,   578,     0,     0,     0,
       0,     0,   579,   580,   581,   582,   583,   584,   585,   586,
     577,   578,     0,     0,     0,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,     0,     0,   587,   588,   589,
     590,   577,   578,  1290,     0,     0,     0,     0,   579,   580,
     581,   582,   583,   584,   585,   586,     0,     0,     0,   587,
     588,   589,   590,   577,   578,  1330,     0,     0,     0,     0,
     579,   580,   581,   582,   583,   584,   585,   586,   577,   578,
       0,     0,     0,     0,     0,   579,   580,   581,   582,   583,
     584,   585,   586,     0,   587,   588,   589,   590,   577,   578,
    1382,     0,     0,     0,     0,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,     0,     0,  1387,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,     0,     0,  1388,     0,     0,     0,     0,     0,
       0,     0,     0,   587,   588,   589,   590,     0,     0,  1457,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,     0,     0,  1462,     0,     0,     0,     0,     0,
       0,     0,     0,   587,   588,   589,   590,     0,     0,  1476,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,     0,     0,  1488,     0,     0,     0,     0,     0,
       0,     0,     0,   587,   588,   589,   590,   577,   578,  1493,
       0,     0,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,     0,     0,   587,   588,   589,   590,   577,   578,
    1494,     0,     0,     0,     0,   579,   580,   581,   582,   583,
     584,   585,   586,     0,     0,     0,   587,   588,   589,   590,
       0,     0,  1495,     0,     0,     0,     0,     0,     0,     0,
       0,   587,   588,   589,   590,   577,   578,  1498,     0,     0,
       0,     0,   579,   580,   581,   582,   583,   584,   585,   586,
       0,   587,   588,   589,   590,   577,   578,  1525,     0,     0,
       0,     0,   579,   580,   581,   582,   583,   584,   585,   586,
     577,   578,     0,     0,     0,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,   577,   578,     0,     0,     0,
       0,     0,   579,   580,   581,   582,   583,   584,   585,   586,
     577,   578,     0,     0,     0,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,   577,   578,     0,     0,     0,
       0,     0,   579,   580,   581,   582,   583,   584,   585,   586,
     577,   578,     0,     0,     0,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,   577,   578,     0,     0,     0,
       0,     0,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   577,   578,  1532,     0,     0,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,     0,
       0,   587,   588,   589,   590,   577,   578,  1537,     0,     0,
       0,     0,   579,   580,   581,   582,   583,   584,   585,   586,
     577,   578,     0,     0,     0,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,     0,     0,     0,   587,   588,
     589,   590,   577,   578,  1540,     0,     0,     0,     0,   579,
     580,   581,   582,   583,   584,   585,   586,     0,   587,   588,
     589,   590,     0,     0,  1572,     0,     0,     0,     0,     0,
       0,     0,     0,   587,   588,   589,   590,     0,     0,  1595,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,     0,     0,  1596,     0,     0,     0,     0,     0,
       0,     0,     0,   587,   588,   589,   590,     0,     0,  1618,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,     0,     0,  1632,     0,     0,     0,     0,     0,
       0,     0,     0,   587,   588,   589,   590,     0,     0,  1745,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,   577,   578,  1746,     0,     0,     0,     0,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   577,   578,  1747,     0,     0,     0,     0,   579,   580,
     581,   582,   583,   584,   585,   586,     0,     0,   587,   588,
     589,   590,     0,     0,  1749,     0,     0,     0,     0,     0,
       0,     0,     0,   587,   588,   589,   590,   577,   578,  1755,
       0,     0,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,     0,     0,     0,   587,   588,   589,   590,   577,
     578,  1758,     0,     0,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,   577,   578,     0,     0,     0,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,   577,
     578,     0,     0,     0,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,   577,   578,     0,     0,     0,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,   577,
     578,     0,     0,     0,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,   577,   578,     0,     0,     0,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,   577,
     578,     0,     0,     0,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,     0,   587,   588,   589,   590,   577,
     578,  1763,     0,     0,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   577,   578,
    1764,     0,     0,     0,     0,   579,   580,   581,   582,   583,
     584,   585,   586,   577,   578,     0,     0,     0,     0,     0,
     579,   580,   581,   582,   583,   584,   585,   586,     0,     0,
     587,   588,   589,   590,   577,   578,  1775,     0,     0,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,     0,
       0,     0,   587,   588,   589,   590,     0,     0,  1776,     0,
       0,     0,     0,     0,     0,     0,     0,   587,   588,   589,
     590,     0,     0,  1777,     0,     0,     0,     0,     0,     0,
       0,     0,   587,   588,   589,   590,     0,     0,  1780,     0,
       0,     0,     0,     0,     0,     0,     0,   587,   588,   589,
     590,     0,     0,  1784,     0,     0,     0,     0,     0,     0,
       0,     0,   587,   588,   589,   590,     0,     0,  1799,     0,
       0,     0,     0,     0,     0,     0,     0,   587,   588,   589,
     590,     0,     0,  1818,     0,     0,     0,     0,     0,     0,
       0,     0,   587,   588,   589,   590,   577,   578,  1838,     0,
       0,     0,     0,   579,   580,   581,   582,   583,   584,   585,
     586,     0,   587,   588,   589,   590,   577,   578,  1839,     0,
       0,     0,     0,   579,   580,   581,   582,   583,   584,   585,
     586,   587,   588,   589,   590,     0,     0,  1842,     0,     0,
       0,     0,     0,     0,     0,     0,   587,   588,   589,   590,
     577,   578,  1848,     0,     0,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,     0,     0,   587,   588,   589,
     590,   577,   578,  1853,     0,     0,     0,     0,   579,   580,
     581,   582,   583,   584,   585,   586,   577,   578,     0,     0,
       0,     0,     0,   579,   580,   581,   582,   583,   584,   585,
     586,   577,   578,     0,     0,     0,     0,     0,   579,   580,
     581,   582,   583,   584,   585,   586,   577,   578,     0,     0,
       0,     0,     0,   579,   580,   581,   582,   583,   584,   585,
     586,   577,   578,     0,     0,     0,     0,     0,   579,   580,
     581,   582,   583,   584,   585,   586,   577,   578,     0,     0,
       0,     0,     0,   579,   580,   581,   582,   583,   584,   585,
     586,   577,   578,     0,     0,     0,     0,     0,   579,   580,
     581,   582,   583,   584,   585,   586,     0,     0,     0,   587,
     588,   589,   590,   577,   578,  1854,     0,     0,     0,     0,
     579,   580,   581,   582,   583,   584,   585,   586,     0,   587,
     588,   589,   590,   577,   578,  1855,     0,     0,     0,     0,
     579,   580,   581,   582,   583,   584,   585,   586,   577,   578,
       0,     0,     0,     0,     0,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   590,   577,   578,  1858,
       0,     0,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,     0,     0,   587,   588,   589,   590,     0,     0,
    1862,     0,     0,     0,     0,     0,     0,     0,     0,   587,
     588,   589,   590,     0,     0,  1894,     0,     0,     0,     0,
       0,     0,     0,     0,   587,   588,   589,   590,     0,     0,
    1896,     0,     0,     0,     0,     0,     0,     0,     0,   587,
     588,   589,   590,     0,     0,  1897,     0,     0,     0,     0,
       0,     0,     0,     0,   587,   588,   589,   590,     0,     0,
    1899,     0,     0,     0,     0,     0,     0,     0,     0,   587,
     588,   589,   590,     0,     0,  1905,     0,     0,     0,     0,
       0,     0,     0,     0,   587,   588,   589,   590,   577,   578,
    1908,     0,     0,     0,     0,   579,   580,   581,   582,   583,
     584,   585,   586,     0,     0,     0,   587,   588,   589,   590,
     577,   578,  1912,     0,     0,     0,     0,   579,   580,   581,
     582,   583,   584,   585,   586,     0,   587,   588,   589,   590,
       0,     0,  1920,     0,     0,     0,     0,     0,     0,     0,
       0,   587,   588,   589,   590,   577,   578,  1921,     0,     0,
       0,     0,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   577,   578,  1922,     0,     0,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,   577,
     578,     0,     0,     0,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,   577,   578,     0,     0,     0,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,   577,
     578,     0,     0,     0,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,   577,   578,     0,     0,     0,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,   577,
     578,     0,     0,     0,     0,     0,   579,   580,   581,   582,
     583,   584,   585,   586,   577,   578,     0,     0,     0,     0,
       0,   579,   580,   581,   582,   583,   584,   585,   586,     0,
       0,   587,   588,   589,   590,   577,   578,  1928,     0,     0,
       0,     0,   579,   580,   581,   582,   583,   584,   585,   586,
       0,     0,     0,   587,   588,   589,   590,   577,   578,  1944,
       0,     0,     0,     0,   579,   580,   581,   582,   583,   584,
     585,   586,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,     0,     0,  1962,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   587,   588,   589,
     590,     0,     0,  1964,     0,     0,     0,     0,     0,     0,
       0,     0,   587,   588,   589,   590,     0,     0,  1966,     0,
       0,     0,     0,     0,     0,     0,     0,   587,   588,   589,
     590,     0,     0,  1967,     0,     0,     0,     0,     0,     0,
       0,     0,   587,   588,   589,   590,     0,     0,  1987,     0,
       0,     0,     0,     0,     0,     0,     0,   587,   588,   589,
     590,     0,     0,  1989,     0,     0,     0,     0,     0,     0,
       0,     0,   587,   588,   589,   590,     0,     0,  1996,     0,
       0,     0,     0,     0,     0,     0,     0,   587,   588,   589,
     590,     0,     0,  2015,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   587,   588,
     589,   590,     0,     0,  2016,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     587,   588,   589,   590,     0,     0,  2028
};

static const yytype_int16 yycheck[] =
{
       3,    15,    16,    12,    40,     1,   467,     4,     4,     1,
       7,    12,     4,    44,     4,     4,     5,     7,    21,    75,
      58,    24,    60,    61,    75,  1621,    58,    41,    60,    61,
      33,    61,    77,    28,    37,    38,     3,    25,    16,    42,
       7,     8,     9,    10,     0,    43,    44,     4,     5,    12,
      77,    54,    55,    56,   256,    95,    44,    53,   436,   437,
     112,    53,   112,    23,    76,    77,    44,    70,    71,    72,
      12,   111,   274,     3,     7,   112,   113,     7,     8,     9,
      10,   111,   247,    86,    87,    88,  1264,  1265,    13,   254,
      92,    93,   110,   112,    97,    98,    99,   100,    11,    97,
      63,    64,   104,   155,   252,   155,   254,    70,    71,    72,
      73,    74,    75,    76,    77,   247,    95,   252,   155,   254,
     252,    63,    64,    73,    74,    75,    76,    77,    70,    71,
      72,    73,    74,    75,    76,    77,   155,   247,    63,    64,
     160,   112,   113,   100,   254,    70,    71,    72,    73,    74,
      75,    76,    77,    51,   252,    44,   254,    70,    71,    72,
      73,    74,    75,    76,    59,    63,    64,   253,     4,   112,
     113,     7,    70,    71,    72,    73,    74,    75,    76,    77,
      28,   559,   253,   561,   155,    33,    70,    71,    72,    73,
      74,    75,    76,   253,    89,    90,    91,   253,   187,   188,
     189,    96,   253,   248,   249,    70,    71,    72,    73,    74,
      75,    76,   155,   247,     4,     5,   247,   255,   252,   246,
     247,   248,   249,   255,   112,   113,  1822,   230,   253,  1825,
     187,   188,   189,    75,   246,   247,   248,   249,   247,   247,
     243,    81,    82,   252,   252,    75,   254,   247,    88,   252,
      24,   252,   252,     3,   254,   112,   253,     7,     8,     9,
     256,   297,   298,   253,   256,   268,   247,   155,     4,     5,
     273,   111,   162,   254,   247,    20,    21,   280,   274,   246,
     247,   254,   274,   246,   247,   248,   249,   253,   252,   252,
     254,   251,  1888,   253,   253,  1891,   246,   247,   248,   249,
     253,   304,   247,   247,   246,   247,   248,   249,   252,   254,
     254,   112,   315,   316,   317,   253,   246,   247,    63,    64,
     323,   246,   247,   248,   249,    70,    71,    72,    73,    74,
      75,    76,    77,    71,   247,    73,    74,    75,    76,    77,
     247,   112,   113,   346,   347,   252,   247,   254,   246,   247,
     248,   249,   355,   254,   357,   161,   359,   360,   112,   362,
     363,   364,   365,   247,    44,   368,   369,   370,   252,   372,
     254,   374,   252,   376,   254,    35,    36,   380,   381,   382,
     383,   384,   247,   386,     4,     5,   389,   253,   247,   254,
     393,   394,   395,   396,   397,   254,   399,   400,   401,   402,
     253,   404,   405,   406,   407,   408,   409,   410,   253,   412,
     413,   414,   415,   416,   417,  2011,   419,  2013,   421,   253,
     423,   623,   425,   155,   427,   247,   429,   430,   431,   432,
     433,   155,   254,  2029,   253,  2031,   439,    70,    71,    72,
      73,    74,    75,    76,  1622,   247,   253,  1625,   451,   253,
     252,    70,    71,    72,    73,    74,    75,    76,   247,   462,
     253,   464,   253,   252,   462,   463,   253,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,     4,     5,   492,
     247,   247,   247,   453,   454,   252,   252,   254,   254,   254,
     247,   246,   247,   248,   249,   252,   155,   505,   246,   247,
     248,   249,   515,   516,   517,   518,   519,   155,   247,   522,
       4,     5,   525,   252,   527,   254,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   253,   539,   540,   541,   542,
     543,   544,   545,   546,   251,   252,   549,   545,   551,   552,
     553,   554,   555,   247,   253,   558,  1734,   560,   252,   562,
     563,   564,    75,    76,    77,   568,   569,   570,   571,   572,
     573,   574,   575,   247,     4,     5,   247,   247,   252,    44,
     254,   252,   252,   254,   254,    86,    87,   547,   548,    70,
      71,    72,    73,    74,    75,    76,   247,   247,    63,    64,
     253,   252,   252,   254,   254,    70,    71,    72,    73,    74,
      75,    76,    77,   649,   247,    74,    75,    76,    77,   253,
      14,   254,    16,   626,    18,   247,    63,   623,   247,     4,
       5,   623,   254,    70,    71,    72,    73,    74,    75,    76,
      77,    46,   247,   247,   253,   247,   247,    41,   252,   254,
      44,   654,   254,   254,   247,    49,   247,   247,    63,    64,
     155,   254,   252,   254,   667,    70,    71,    72,    73,    74,
      75,    76,    77,    14,   247,    16,   253,    18,     5,   639,
     640,   254,   247,    10,   644,   645,   247,   247,   691,   254,
     693,   247,   247,   254,   254,   247,   247,   252,   254,   702,
      41,   252,   254,    44,    31,   253,   247,   710,    49,   247,
     713,   714,  1890,   254,   253,  1893,   254,    70,    71,    72,
      73,    74,    75,    76,     4,     5,    70,    71,    72,    73,
      74,    75,    76,   246,   247,   248,   249,   253,   940,    70,
      71,    72,    73,    74,    75,    76,   253,   750,   253,   247,
     253,   247,    44,   756,   253,   758,   254,   760,   254,   762,
    1221,   764,   247,  1224,   253,   247,   247,   247,  1946,   254,
     253,  1949,   254,   254,   254,   778,   779,    46,   105,   247,
     107,   246,   247,   248,   249,   247,   254,   246,   247,   248,
     249,   247,   254,   253,    63,    64,    49,    50,   254,   126,
     127,    70,    71,    72,    73,    74,    75,    76,    77,   246,
     247,   248,   249,    39,    40,   247,   247,   144,   145,   146,
     147,   148,   254,   826,     4,     5,   247,   247,   831,   156,
     833,   834,   159,   254,   254,   162,   163,   164,   253,   247,
     253,   246,   247,   248,   249,  2023,   254,  2025,    70,    71,
      72,    73,    74,    75,    76,   253,   247,  2035,  2036,    58,
     187,   188,   189,   254,   247,   253,   193,   194,   195,   247,
     197,   254,   199,   200,   201,   252,   254,   247,     4,   206,
     207,   208,   209,   210,   254,    14,   213,    16,   215,    18,
     217,   247,   247,   220,   247,   222,   252,   252,   225,   252,
     252,   228,   229,   247,   231,   232,   253,   234,   252,   236,
     253,   247,    41,   253,   247,    44,   247,   244,   254,   252,
      49,   252,   247,   247,   247,   253,   253,   254,   247,   254,
     254,   254,   253,   252,   948,   949,    70,    71,    72,    73,
      74,    75,    76,   253,   940,   253,   247,   247,   940,    63,
      64,   252,   252,   956,   253,   253,    70,    71,    72,    73,
      74,    75,    76,    77,   253,   247,   247,   253,   247,   972,
     252,   252,   975,   252,   252,   978,   253,   246,   247,   248,
     249,    14,   247,    16,   247,    18,   253,   252,   252,   252,
     950,   951,   247,   953,   954,   247,   247,   252,   252,  1002,
     252,   252,   247,  1006,   247,    60,    61,   252,    41,   252,
    1013,    44,    60,    61,  1017,   253,    49,  1020,    71,    72,
      73,    74,    75,    76,    77,   247,   253,    43,   253,  1032,
     252,  1034,  1035,  1036,   247,   253,  1039,  1040,  1041,   252,
    1043,   253,   247,   253,  1047,   247,  1248,   252,  1051,  1052,
     252,  1054,   247,   247,  1057,   247,   253,   252,   252,   247,
     252,  1064,  1065,   247,   252,  1068,   253,   253,   252,  1072,
    1073,  1074,  1075,   247,   253,  1078,   247,   253,   252,  1082,
     247,   252,  1085,   253,   247,   252,  1089,   253,  1091,   252,
    1093,   253,  1095,  1096,  1097,    70,    71,    72,    73,    74,
      75,    76,   247,   247,   247,   247,   247,   252,   252,   252,
     252,   252,   247,   247,   253,  1111,   247,   252,   252,  1111,
     247,   252,   247,   253,  1127,   252,  1129,   252,  1131,   253,
     253,   247,   246,   247,   248,   249,   252,  1140,   252,  1099,
     254,   247,   253,   253,  1147,   253,   252,    70,    71,    72,
      73,    74,    75,    76,   253,   247,   247,   247,    63,    64,
     252,   252,   252,     5,   253,    70,    71,    72,    73,    74,
      75,    76,    77,   247,   253,   247,    63,    64,   252,  1182,
     252,   254,   253,    70,    71,    72,    73,    74,    75,    76,
      77,   253,   253,   246,   247,   248,   249,  1200,  1201,  1202,
    1203,   253,   247,    63,    64,   252,  1209,   252,   254,   253,
      70,    71,    72,    73,    74,    75,    76,    77,   247,  1222,
      63,    64,  1225,   252,  1227,   253,   253,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,   238,   239,   240,
     241,   242,    70,    71,    72,    73,    74,    75,    76,    77,
     247,  1254,  1248,   253,  1257,   252,  1248,    63,    64,   253,
     253,   253,   253,   253,    70,    71,    72,    73,    74,    75,
      76,    77,   247,   247,   253,   253,   247,   252,   252,  1282,
    1283,   252,  1280,  1281,  1287,    63,    64,   253,  1291,   253,
     253,   253,    70,    71,    72,    73,    74,    75,    76,    77,
     247,   253,   247,  1306,  1307,   252,  1309,   252,  1311,   253,
     253,  1314,   247,  1273,  1274,  1318,  1319,   252,    77,   253,
     253,  1324,   252,  1326,   247,  1328,   247,  1330,   252,   252,
     252,   252,   247,  1336,   252,  1338,  1339,   252,  1341,  1342,
    1343,   246,   247,   248,   249,   252,  1349,   252,   247,   254,
    1353,   247,   252,   252,   252,    75,   252,  1360,   247,   246,
     247,   248,   249,   252,  1367,   252,  1369,   254,  1371,   247,
     253,  1374,   247,  1376,   252,  1378,   247,   252,   247,  1382,
     253,   252,   254,   252,  1387,  1388,   246,   247,   248,   249,
     247,   247,   252,   247,   254,   252,   252,   247,   252,   254,
     253,   253,   252,   246,   247,   248,   249,   247,   253,   252,
     247,   254,   252,  1416,  1417,   252,   252,   247,   246,   247,
     248,   249,   252,   247,   247,   247,   254,   253,   252,   252,
     252,   247,  1446,  1447,   247,   253,   252,   252,   252,   252,
     246,   247,   248,   249,    43,   247,   247,   247,   254,  1452,
     252,   252,   252,   247,   247,   247,    46,   247,   252,   252,
     252,  1464,   252,    10,   253,   253,    58,   247,   246,   247,
     248,   249,   252,  1476,   253,   247,   254,   247,  1481,  1482,
     252,   247,   252,   252,  1487,  1488,   252,  1490,  1491,   247,
     252,   247,   247,   247,   252,  1498,   252,   252,   252,   252,
     247,   247,   247,   252,  1507,   252,   252,   252,  1511,  1469,
    1470,   252,   247,   253,  1517,   252,  1519,   252,  1720,  1721,
      63,    64,  1525,   252,   252,  1528,  1529,    70,    71,    72,
      73,    74,    75,    76,    77,   247,  1539,  1540,   252,  1542,
     252,  1544,   247,  1546,  1547,   247,   247,   252,   247,   247,
     252,   252,   247,   252,   252,   247,   247,   252,   247,   247,
     252,   252,  1565,   252,   252,    63,    64,   254,  1571,   254,
     254,   252,    70,    71,    72,    73,    74,    75,    76,    77,
     254,  1584,   247,   247,   247,  1588,   247,   252,   252,   252,
     252,   252,  1595,   253,   247,  1598,   247,   247,  1601,   252,
     247,   252,   252,   252,   247,   252,   247,    63,    64,   252,
     254,   252,  1814,  1616,    70,    71,    72,    73,    74,    75,
      76,    77,   247,   253,    63,    64,   254,   252,  1631,  1632,
    1633,    70,    71,    72,    73,    74,    75,    76,    77,   247,
     247,   254,   247,  1646,   252,   252,  1649,   252,   254,  1652,
     254,   247,   247,  1656,   247,  1658,   252,   252,    43,   252,
     247,  1664,   253,  1666,   247,   252,  1669,  1670,   247,   252,
    1673,   247,   247,   252,   254,  1877,   252,   252,  1880,  1682,
     247,     2,   247,  1686,   247,   252,  1689,   252,  1691,   252,
     247,  1694,  1695,   247,  1697,   252,    17,   247,   252,   254,
     252,   254,   252,   246,   247,   248,   249,   253,   247,    30,
     254,   254,    33,   252,   247,    36,    37,    38,   253,   252,
     254,    42,    43,    44,  1720,  1721,   247,    85,  1720,  1721,
      51,   252,  1934,   247,   247,    85,  1739,   247,   252,   252,
    1743,   247,   252,  1746,   252,   252,   252,  1750,   246,   247,
     248,   249,   247,   247,   247,   247,   254,   252,   252,   252,
     252,   247,   247,   247,   247,   252,   252,   252,   252,   252,
      91,   252,   247,   252,   252,   252,    97,   252,  1781,   252,
    1783,  1784,   252,  1786,   252,  1788,   252,   252,   252,   252,
     246,   247,   248,   249,   252,   252,     5,    58,   254,   254,
     254,   252,   252,    43,    38,   254,   254,   246,   247,   248,
     249,   132,   254,  1816,   254,   254,   253,   253,  1814,    63,
      64,   252,  1814,   252,   252,   252,    70,    71,    72,    73,
      74,    75,    76,    77,  1837,  1838,  1839,  1840,   252,  1842,
    1843,   254,   253,    43,  1847,   254,   254,   253,  1851,   254,
      58,  1854,  1855,  1856,   254,  1858,    75,    75,    75,  1862,
    1863,    48,    58,   253,   253,  1868,   254,   254,  1871,   252,
    1873,   253,    47,   253,   253,    58,    75,   254,   254,    38,
     253,  1877,   253,   252,  1880,  1877,  1889,   252,  1880,     4,
       4,  1111,  1895,  1896,   467,  1898,  1899,  1900,    53,    53,
     956,   649,     5,    63,    64,   955,  1452,  2007,   229,   230,
      70,    71,    72,    73,    74,    75,    76,    77,  1921,  1796,
     952,   646,  1925,  1260,  1927,  1928,   662,    -1,    -1,   250,
      -1,    -1,    -1,    -1,   255,    -1,    -1,    -1,  1934,  1942,
      -1,    -1,  1934,    -1,    -1,    -1,    -1,   268,    -1,    -1,
      -1,    -1,   273,    -1,    -1,    -1,  1959,    -1,    -1,   280,
    1963,    -1,    -1,  1966,  1967,    -1,    63,    64,  1971,    -1,
      -1,    -1,  1975,    70,    71,    72,    73,    74,    75,    76,
      77,  1984,   303,    -1,   305,    -1,  1989,    70,    71,    72,
      73,    74,    75,    76,    77,  1998,    -1,    -1,   335,   336,
      -1,   338,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,  2015,  2016,    -1,    -1,   353,   354,    -1,    -1,
      -1,    -1,    -1,    -1,   361,  2028,    -1,    -1,    -1,   366,
    2033,   352,    -1,    -1,   371,    -1,   373,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   385,    -1,
     387,   388,    -1,   390,   391,   392,    -1,    -1,    -1,    -1,
      -1,   398,    -1,    -1,    -1,    -1,   403,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   411,    -1,    -1,    -1,    -1,    -1,
      -1,   418,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
      63,    64,    -1,    -1,   254,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,   438,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,   450,
      -1,    -1,    -1,    -1,   455,   456,    -1,   458,   459,   460,
     461,   462,   463,    -1,    -1,    -1,    -1,    -1,   469,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,    -1,    -1,    -1,    -1,    -1,   520,
     521,   522,   523,   524,    -1,   526,    -1,   528,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   538,    -1,    -1,
      -1,    -1,    -1,    -1,   545,    -1,    -1,    -1,    -1,   550,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   590,
      -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,   624,    -1,    -1,    -1,    -1,   629,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,   656,
      -1,   642,   643,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   670,   655,    -1,    30,    31,   675,   660,
     677,    -1,   679,   680,    -1,    -1,    -1,    -1,   685,   686,
     671,   672,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,   712,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,   110,   246,   247,   248,
     249,   115,    -1,    -1,    -1,   254,    -1,    -1,   122,    63,
      64,    -1,   126,   127,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,   784,   785,   770,
     144,   145,   146,   147,   148,   149,    -1,   778,   779,   780,
     781,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,   808,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,   219,   220,   221,   222,    -1,
     224,   225,    -1,   227,   228,   229,    -1,   231,   232,   233,
     234,   235,   236,   237,    90,    91,    92,    93,    94,   243,
     244,    -1,   246,    -1,    -1,    -1,    -1,    -1,   104,   253,
      -1,   255,    -1,    -1,   110,   111,    -1,    -1,    -1,    -1,
     116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   923,   924,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,    -1,    -1,    -1,   165,
     254,    -1,   943,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   956,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   969,    -1,
      -1,    -1,    -1,    -1,   975,   976,    -1,    63,    64,    -1,
     981,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   995,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,  1015,    -1,    -1,    -1,    -1,  1020,
    1021,  1022,    -1,    -1,  1025,    63,    64,  1028,    -1,  1030,
      -1,  1032,    70,    71,    72,    73,    74,    75,    76,    77,
    1041,    -1,    -1,    -1,  1045,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1053,    -1,  1055,    -1,    -1,    -1,    -1,  1060,
      -1,    -1,    -1,  1064,  1065,  1066,    -1,    -1,  1069,  1070,
      -1,    -1,  1073,    -1,    -1,  1076,    -1,    -1,  1079,    -1,
    1081,    -1,  1083,    -1,    -1,    -1,  1087,    -1,  1089,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,  1100,
    1101,  1102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1120,
    1121,    -1,  1123,  1124,  1125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1136,  1137,    -1,  1139,    -1,
      -1,  1142,  1143,  1144,    -1,  1146,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1157,    -1,    -1,  1160,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,  1172,    -1,    -1,  1175,  1176,  1177,    -1,  1179,  1180,
     246,   247,   248,   249,    63,    64,    -1,  1188,   254,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,    -1,    63,    64,  1216,   254,  1218,  1219,  1220,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,  1232,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,  1252,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,  1262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1275,  1276,    -1,    -1,  1295,  1280,
    1281,  1298,    -1,    63,    64,    -1,  1303,    -1,  1289,  1290,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      63,    64,    -1,    -1,    -1,    47,    48,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    58,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1363,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    63,    64,    -1,  1391,   254,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,  1408,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1452,    -1,    -1,    -1,    -1,  1457,    -1,    -1,    -1,
      -1,  1462,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,  1493,  1494,  1495,    -1,  1497,    -1,    -1,    -1,
      -1,    -1,    -1,  1504,    -1,    -1,    -1,  1508,  1509,    -1,
      63,    64,    -1,  1514,    -1,  1516,  1517,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,  1528,    -1,    -1,
    1531,  1532,    -1,  1534,    -1,    -1,  1537,    -1,    -1,    -1,
      -1,  1542,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1552,    -1,    -1,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,  1570,
      -1,  1572,   314,    -1,    -1,    -1,    -1,    -1,   320,  1580,
      -1,    -1,    -1,    -1,    -1,   327,   328,    -1,  1589,    -1,
    1591,    -1,    -1,    -1,    -1,  1596,    -1,   339,   340,   341,
     342,   343,   344,   345,  1605,    -1,   348,   349,   350,   351,
      -1,    -1,    -1,    -1,  1615,    -1,    -1,  1618,    -1,    -1,
      63,    64,  1639,    -1,    -1,    -1,  1643,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1647,  1648,    -1,    -1,
    1651,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1659,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1667,  1668,    -1,    -1,
      -1,  1672,    -1,    -1,    63,    64,  1677,    -1,    -1,    -1,
    1681,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,  1698,    -1,    -1,
      -1,   254,    -1,    63,    64,   447,   448,   449,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,  1722,    -1,    -1,    -1,    -1,   468,    -1,    -1,    63,
      64,    -1,  1733,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,  1745,    -1,  1747,    -1,  1749,    -1,
      -1,    -1,    -1,    -1,  1755,    -1,    -1,  1758,    -1,  1760,
      -1,    -1,  1763,  1764,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1773,    -1,  1775,  1776,  1777,    -1,    -1,  1780,
      -1,    -1,    -1,    -1,    -1,  1786,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1799,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    -1,  1809,    -1,
      -1,   254,    -1,    -1,    -1,    -1,  1817,  1818,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1845,    -1,    -1,  1848,    -1,    -1,
      -1,  1852,  1853,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    63,    64,    -1,    -1,   254,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
      -1,  1892,    -1,  1894,   254,    -1,  1897,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1905,    -1,    -1,  1908,    -1,    -1,
      -1,  1912,   246,   247,   248,   249,    -1,    -1,    -1,  1920,
     254,  1922,    -1,   665,    -1,    -1,    -1,   669,    -1,    -1,
      -1,   673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1944,    -1,    -1,   688,   689,    -1,    -1,
      -1,    -1,    -1,    -1,   696,    -1,    -1,    -1,    -1,   701,
      -1,  1962,    -1,  1964,   706,    -1,   708,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,   720,    -1,
     722,   723,    -1,   725,   726,   727,  1987,    -1,    -1,    -1,
      -1,   733,    -1,    -1,    -1,  1996,   738,    30,    31,    -1,
      -1,    -1,    -1,    -1,   746,   246,   247,   248,   249,    -1,
      -1,    -1,   754,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   247,   248,   249,    81,    -1,
      -1,    84,   254,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,   219,   220,   221,   222,
      -1,   224,   225,    -1,   227,   228,   229,    -1,   231,   232,
     233,   234,   235,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,
     253,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1001,
      -1,    30,    31,    -1,    -1,    -1,    -1,  1009,    -1,    -1,
      -1,    -1,  1014,    -1,  1016,    -1,  1018,  1019,    -1,    -1,
      -1,  1023,  1024,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    63,    64,    -1,   126,   127,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,  1113,  1114,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,  1138,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
     219,   220,   221,   222,    -1,   224,   225,    -1,   227,   228,
     229,    -1,   231,   232,   233,   234,   235,   236,   237,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,   246,    -1,    -1,
      -1,    -1,    -1,    -1,   253,    -1,   255,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    63,    64,    -1,
     126,   127,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,   219,   220,   221,   222,    -1,   224,   225,
      -1,   227,   228,   229,    -1,   231,   232,   233,   234,   235,
     236,   237,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1489,    -1,    -1,
    1492,    -1,    -1,    -1,  1496,    -1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1556,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,
      64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    63,    64,    -1,
     126,   127,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,   219,   220,   221,   222,    -1,   224,   225,
      -1,   227,   228,   229,    -1,   231,   232,   233,   234,   235,
     236,   237,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,
     246,    -1,  1744,    -1,    -1,    -1,  1748,   253,   254,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    63,
      64,    -1,   126,   127,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,   219,   220,   221,   222,    -1,
     224,   225,    -1,   227,   228,   229,    -1,   231,   232,   233,
     234,   235,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,
     244,    -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,   253,
     254,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    63,    64,    -1,   126,   127,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,   219,   220,   221,
     222,    -1,   224,   225,    -1,   227,   228,   229,    -1,   231,
     232,   233,   234,   235,   236,   237,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,   246,    -1,    -1,    -1,    -1,    -1,
      -1,   253,   254,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,   152,   153,   154,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,   164,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,   219,
     220,   221,   222,    -1,   224,   225,    -1,   227,   228,   229,
      -1,   231,   232,   233,   234,   235,   236,   237,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,   246,    -1,    -1,    -1,
       3,     4,     5,   253,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      63,    64,    -1,   126,   127,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,    -1,
      -1,   154,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,   219,   220,   221,   222,
      -1,   224,   225,    -1,   227,   228,   229,    -1,   231,   232,
     233,   234,   235,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,   246,    -1,    -1,    -1,     3,     4,     5,
     253,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,   151,    -1,    -1,   154,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,   219,   220,   221,   222,    -1,   224,   225,
      -1,   227,   228,   229,    -1,   231,   232,   233,   234,   235,
     236,   237,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,
     246,    -1,    -1,    -1,     3,     4,     5,   253,     7,     8,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
     219,   220,   221,   222,    -1,   224,   225,    -1,   227,   228,
     229,    -1,   231,   232,   233,   234,   235,   236,   237,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,   246,    -1,    -1,
      -1,     3,     4,     5,   253,     7,     8,     9,    10,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,   154,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,   219,   220,   221,
     222,    -1,   224,   225,    -1,   227,   228,   229,    -1,   231,
     232,   233,   234,   235,   236,   237,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,   246,    -1,    -1,    -1,     3,     4,
       5,   253,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,
      63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,   111,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,   219,   220,   221,   222,    -1,   224,
     225,    -1,   227,   228,   229,    -1,   231,   232,   233,   234,
     235,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,   244,
      -1,   246,    -1,    -1,    -1,     3,     4,     5,   253,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,
      -1,    89,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,   111,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,   159,    -1,    -1,   162,   163,   164,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,   219,   220,   221,   222,    -1,   224,   225,    -1,   227,
     228,   229,    -1,   231,   232,   233,   234,   235,   236,   237,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,   246,    -1,
      -1,    -1,     3,     4,     5,   253,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,   219,   220,
     221,   222,    -1,   224,   225,    -1,   227,   228,   229,    -1,
     231,   232,   233,   234,   235,   236,   237,    -1,    -1,    -1,
      -1,    -1,   243,   244,    -1,   246,    -1,    -1,    -1,     3,
       4,     5,   253,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,   111,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,   219,   220,   221,   222,    -1,
     224,   225,    -1,   227,   228,   229,    -1,   231,   232,   233,
     234,   235,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,
     244,    -1,   246,    -1,    -1,    -1,     3,     4,     5,   253,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,   219,   220,   221,   222,    -1,   224,   225,    -1,
     227,   228,   229,    -1,   231,   232,   233,   234,   235,   236,
     237,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,   246,
      -1,    -1,    -1,     3,     4,     5,   253,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,   164,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,   219,
     220,   221,   222,    -1,   224,   225,    -1,   227,   228,   229,
      -1,   231,   232,   233,   234,   235,   236,   237,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,   246,    -1,    -1,    -1,
       3,     4,     5,   253,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    30,    31,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,   219,   220,   221,   222,
      -1,   224,   225,    -1,   227,   228,   229,    -1,   231,   232,
     233,   234,   235,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,   246,    -1,    -1,    -1,     3,     4,     5,
     253,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    30,    31,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,   219,   220,   221,   222,    -1,   224,   225,
      -1,   227,   228,   229,    -1,   231,   232,   233,   234,   235,
     236,   237,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,
     246,    -1,    -1,    -1,     3,     4,     5,   253,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,
      89,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,   111,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
     219,   220,   221,   222,    -1,   224,   225,    -1,   227,   228,
     229,    -1,   231,   232,   233,   234,   235,   236,   237,    -1,
      -1,    -1,    -1,    -1,   243,   244,    -1,   246,    -1,    -1,
      -1,     3,     4,     5,   253,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    30,    31,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,    -1,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,    -1,   219,   220,   221,
     222,    -1,   224,   225,    -1,   227,   228,   229,    -1,   231,
     232,   233,   234,   235,   236,   237,    -1,    -1,    -1,    -1,
      -1,   243,   244,    -1,   246,    -1,    -1,    -1,     3,     4,
       5,   253,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
      -1,    -1,    -1,    -1,   254,    30,    31,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,   219,   220,   221,   222,    -1,   224,
     225,    -1,   227,   228,   229,    -1,   231,   232,   233,   234,
     235,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,   244,
      -1,   246,    -1,    -1,    -1,     3,     4,     5,   253,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,
      -1,    89,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,   111,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,   159,    -1,    -1,   162,   163,   164,    -1,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,   219,   220,   221,   222,    -1,   224,   225,    -1,   227,
     228,   229,    -1,   231,   232,   233,   234,   235,   236,   237,
      -1,    -1,    -1,    -1,    -1,   243,   244,    -1,   246,    -1,
      -1,    -1,     3,     4,     5,   253,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    30,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,   219,   220,
     221,   222,    -1,   224,   225,    -1,   227,   228,   229,    -1,
     231,   232,   233,   234,   235,   236,   237,    -1,    -1,    -1,
      -1,    -1,   243,   244,    -1,   246,    -1,    -1,    -1,     3,
       4,     5,   253,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    30,    31,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,    -1,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,   219,   220,   221,   222,    -1,
     224,   225,    -1,   227,   228,   229,    -1,   231,   232,   233,
     234,   235,   236,   237,    -1,    -1,    -1,    -1,    -1,   243,
     244,    -1,   246,    -1,    -1,    -1,     3,     4,     5,   253,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,
      -1,    -1,   254,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,
      -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,   111,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,   219,   220,   221,   222,    -1,   224,   225,    -1,
     227,   228,   229,    -1,   231,   232,   233,   234,   235,   236,
     237,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,   246,
      -1,    -1,    -1,     3,     4,     5,   253,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,   164,    -1,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,    -1,   219,
     220,   221,   222,    -1,   224,   225,    -1,   227,   228,   229,
      -1,   231,   232,   233,   234,   235,   236,   237,    -1,    -1,
      -1,    -1,    -1,   243,   244,    -1,   246,    -1,    -1,    -1,
       3,     4,     5,   253,     7,     8,     9,    10,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    30,    31,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,   219,   220,   221,   222,
      -1,   224,   225,    -1,   227,   228,   229,    -1,   231,   232,
     233,   234,   235,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,   246,    -1,    -1,    -1,     3,     4,     5,
     253,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,
      64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    63,    64,    -1,
     126,   127,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,   219,   220,   221,   222,    -1,   224,   225,
      -1,   227,   228,   229,    -1,   231,   232,   233,   234,   235,
     236,   237,    -1,    -1,     5,    -1,    -1,   243,   244,    10,
     246,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,   105,    -1,   107,    70,    71,    72,
      73,    74,    75,    76,    77,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,    -1,
      -1,    -1,   193,   194,   195,    -1,   197,    -1,   199,   200,
     201,    -1,    -1,    -1,    -1,   206,   207,   208,   209,   210,
      -1,    -1,   213,    -1,   215,   105,   217,   107,    -1,   220,
      -1,   222,    -1,    -1,   225,    -1,    -1,   228,   229,    -1,
     231,   232,    -1,   234,     5,   236,   126,   127,    -1,    10,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   253,   254,   144,   145,   146,   147,   148,    -1,
      31,    -1,   246,   247,   248,   249,   156,    -1,    -1,   159,
     254,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
      -1,    -1,    -1,   193,   194,   195,    -1,   197,    -1,   199,
     200,   201,    -1,    -1,    -1,    -1,   206,   207,   208,   209,
     210,    -1,    -1,   213,    -1,   215,    -1,   217,    -1,    -1,
     220,    -1,   222,    -1,   105,   225,   107,    -1,   228,   229,
      -1,   231,   232,    -1,   234,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,     5,   244,   126,   127,    -1,    10,    -1,
      -1,    -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,    31,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,    -1,
      -1,    -1,   193,   194,   195,    -1,   197,    -1,   199,   200,
     201,    -1,    -1,    -1,    -1,   206,   207,   208,   209,   210,
      -1,    -1,   213,    -1,   215,    -1,   217,    -1,    -1,   220,
      -1,   222,    -1,   105,   225,   107,    -1,   228,   229,   111,
     231,   232,    -1,   234,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,     5,   244,   126,   127,    -1,    10,    -1,    -1,
      -1,    -1,   253,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,    -1,    31,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,    -1,    -1,
      -1,   193,   194,   195,    -1,   197,    -1,   199,   200,   201,
      -1,    -1,    -1,    -1,   206,   207,   208,   209,   210,    -1,
      -1,   213,    -1,   215,    -1,   217,    -1,    -1,   220,    -1,
     222,    -1,   105,   225,   107,    -1,   228,   229,   111,   231,
     232,    -1,   234,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,     5,   244,   126,   127,    -1,    10,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,    -1,    31,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,    -1,    -1,    -1,
     193,   194,   195,    -1,   197,    -1,   199,   200,   201,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,
     213,    -1,   215,    -1,   217,    -1,    -1,   220,    -1,   222,
      -1,   105,   225,   107,    -1,   228,   229,   111,   231,   232,
      -1,   234,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
       5,   244,   126,   127,    -1,    10,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,    -1,    31,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,    -1,    -1,    -1,   193,
     194,   195,    -1,   197,    -1,   199,   200,   201,    -1,    -1,
      -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,   213,
      -1,   215,    -1,   217,    -1,    -1,   220,    -1,   222,    -1,
     105,   225,   107,    -1,   228,   229,   111,   231,   232,    -1,
     234,     5,   236,    -1,    -1,    -1,    10,    -1,    -1,    -1,
     244,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,    -1,    -1,    -1,   193,   194,
     195,    -1,   197,    -1,   199,   200,   201,    -1,    -1,    -1,
      -1,   206,   207,   208,   209,   210,    -1,    -1,   213,    -1,
     215,   105,   217,   107,    -1,   220,    -1,   222,    -1,    -1,
     225,    -1,    -1,   228,   229,    -1,   231,   232,    -1,   234,
      -1,   236,   126,   127,    -1,    -1,    -1,    -1,    -1,   244,
      -1,     5,    -1,    -1,    -1,    -1,    10,    -1,   253,    -1,
     144,   145,   146,   147,   148,    -1,   150,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    31,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,    -1,    -1,    -1,   193,
     194,   195,    -1,   197,    -1,   199,   200,   201,    -1,    -1,
      -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,   213,
      -1,   215,    -1,   217,    -1,    -1,   220,    -1,   222,    -1,
      -1,   225,    -1,    -1,   228,   229,    -1,   231,   232,    -1,
     234,   105,   236,   107,    -1,   246,   247,   248,   249,    -1,
     244,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
     144,   145,   146,   147,   148,    -1,   150,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    31,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,    -1,    -1,    -1,   193,
     194,   195,    -1,   197,    -1,   199,   200,   201,    -1,    -1,
      -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,   213,
      -1,   215,    -1,   217,    -1,    -1,   220,    -1,   222,    -1,
      -1,   225,    -1,    97,   228,   229,    -1,   231,   232,    -1,
     234,   105,   236,   107,    63,    64,    -1,    -1,    -1,    -1,
     244,    70,    71,    72,    73,    74,    75,    76,    77,   253,
       5,    -1,   126,   127,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,    -1,    31,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,    -1,    -1,    -1,   193,
     194,   195,    -1,   197,    -1,   199,   200,   201,    -1,    -1,
      -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,   213,
      -1,   215,    97,   217,    -1,    -1,   220,    -1,   222,    -1,
     105,   225,   107,    -1,   228,   229,    -1,   231,   232,    -1,
     234,     5,   236,    -1,    -1,    -1,    10,    -1,    -1,    -1,
     244,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,    -1,    -1,    -1,   193,   194,
     195,    -1,   197,    -1,   199,   200,   201,    -1,    -1,    -1,
      -1,   206,   207,   208,   209,   210,    -1,    -1,   213,    -1,
     215,   105,   217,   107,    -1,   220,    -1,   222,    -1,    -1,
     225,    -1,    -1,   228,   229,    -1,   231,   232,    -1,   234,
       5,   236,   126,   127,    -1,    10,    -1,    -1,    -1,   244,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,
     144,   145,   146,   147,   148,    -1,    31,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,    -1,    -1,    -1,   193,
     194,   195,    -1,   197,    -1,   199,   200,   201,    -1,    -1,
      -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,   213,
      -1,   215,    -1,   217,    -1,    -1,   220,    -1,   222,    -1,
     105,   225,   107,    -1,   228,   229,    -1,   231,   232,    -1,
     234,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,   187,   188,   189,    -1,    -1,    -1,   193,   194,
     195,    -1,   197,    -1,   199,   200,   201,    -1,    -1,    -1,
      -1,   206,   207,   208,   209,   210,    -1,    -1,   213,    -1,
     215,    -1,   217,    -1,    -1,   220,    -1,   222,    -1,    -1,
     225,    -1,    -1,   228,   229,    -1,   231,   232,    -1,   234,
      -1,   236,    -1,    -1,     4,     5,     6,    -1,    -1,   244,
      -1,    11,    -1,    -1,    -1,    15,    -1,    17,   253,    19,
      20,    21,    22,    23,    24,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,
      90,    91,    92,    93,    94,    95,    96,    -1,    98,    99,
     100,    -1,    -1,   103,   104,    -1,   106,    -1,   108,   109,
      -1,    -1,    -1,    -1,   114,   115,   246,   247,   248,   249,
      -1,   121,   252,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,    -1,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
      -1,    -1,    -1,    -1,   194,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   214,    -1,    -1,    -1,   218,    -1,
       4,     5,     6,   223,    -1,    -1,   226,    11,    -1,    -1,
     230,    15,    -1,    17,    -1,    19,    20,    21,    22,    23,
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
     164,   165,   246,   247,   248,   249,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,    -1,    -1,    -1,    -1,
     194,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
     214,    -1,    -1,    -1,   218,    -1,     4,     5,     6,   223,
      -1,    -1,   226,    11,    -1,    -1,   230,    15,    -1,    17,
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
     158,   159,    -1,    -1,    -1,    -1,   164,   165,   246,   247,
     248,   249,    63,    64,   252,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   187,
     188,   189,    63,    64,    -1,    -1,   194,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,
     218,    -1,    -1,    -1,    -1,   223,    63,    64,   226,    -1,
      -1,    -1,   230,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   246,   247,   248,   249,    63,    64,   252,
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
      76,    77,    -1,    -1,    -1,   246,   247,   248,   249,    63,
      64,   252,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   246,   247,   248,   249,    63,
      64,   252,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   246,
     247,   248,   249,    63,    64,   252,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,    63,    64,   252,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,   246,   247,   248,   249,    63,    64,   252,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   246,   247,   248,   249,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    63,    64,   252,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   246,   247,   248,   249,
      63,    64,   252,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   246,   247,   248,
     249,    63,    64,   252,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,   246,
     247,   248,   249,    63,    64,   252,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   246,   247,   248,   249,    63,    64,
     252,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,   246,   247,   248,   249,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    63,    64,   252,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   246,   247,   248,   249,    63,    64,
     252,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,   246,   247,   248,   249,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,    63,    64,   252,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   246,   247,   248,   249,    63,    64,   252,    -1,    -1,
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
     246,   247,   248,   249,    63,    64,   252,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,   246,   247,   248,   249,    63,    64,   252,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,   246,   247,
     248,   249,    63,    64,   252,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   246,   247,
     248,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,    63,    64,   252,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   246,   247,   248,
     249,    63,    64,   252,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   246,   247,
     248,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    63,    64,   252,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,   246,   247,   248,   249,    63,
      64,   252,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   246,   247,   248,   249,    63,
      64,   252,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   246,   247,   248,   249,    63,    64,
     252,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     246,   247,   248,   249,    63,    64,   252,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,   246,   247,   248,   249,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,    63,    64,   252,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   246,   247,   248,   249,    63,    64,   252,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,   246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
      63,    64,   252,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   246,   247,   248,
     249,    63,    64,   252,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,   246,
     247,   248,   249,    63,    64,   252,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   246,
     247,   248,   249,    63,    64,   252,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,   246,   247,   248,   249,    63,    64,   252,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   246,   247,   248,   249,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
     247,   248,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
     247,   248,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
     247,   248,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   247,   248,   249,    63,    64,
     252,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,   246,   247,   248,   249,
      63,    64,   252,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   246,   247,   248,   249,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,    63,    64,   252,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
     246,   247,   248,   249,    63,    64,   252,    -1,    -1,    -1,
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
      -1,   246,   247,   248,   249,    63,    64,   252,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,   246,   247,   248,   249,    63,    64,   252,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,    -1,    -1,   252
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   238,   239,   240,   241,   242,   257,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   114,   115,
     121,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     144,   145,   146,   147,   148,   149,   156,   157,   158,   159,
     164,   165,   187,   188,   189,   194,   214,   218,   223,   226,
     230,   258,   259,   262,   263,   270,   271,   273,   274,   278,
     290,   291,   296,   302,   309,   317,   325,   328,   332,   335,
     341,     3,     4,     5,     7,     8,     9,    10,    30,    31,
      63,    64,    65,    66,    67,    68,    69,    81,    84,    89,
     101,   102,   105,   107,   115,   122,   126,   127,   144,   145,
     146,   147,   148,   149,   156,   159,   162,   163,   164,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   219,   220,   221,   222,   224,   225,   227,   228,   229,
     231,   232,   233,   234,   235,   236,   237,   243,   244,   246,
     253,   276,   277,   279,   285,   287,   290,   291,   144,   145,
     146,   147,   164,   253,   276,   262,   290,   291,   296,     0,
      75,   253,    75,   253,   310,   329,   333,     4,     7,   288,
     288,   288,    34,   279,   264,   265,   276,   292,   293,   292,
     276,    28,     7,   318,   326,   279,    58,    60,    61,   255,
     372,   268,   276,   279,     4,     5,   289,   279,   276,   279,
     276,   279,     4,     5,   352,   353,    10,   246,   247,   286,
     287,   354,   288,    89,    97,   255,   276,   279,   373,    89,
      97,   110,   373,   373,    81,    82,    88,   111,   279,   284,
      12,    53,   284,   111,   284,    59,    89,    90,    91,    96,
      95,   279,   271,   278,   276,   276,   276,   110,   284,    90,
      91,    92,    93,    94,   104,   110,   111,   116,   117,   118,
     119,   120,   165,   284,   284,   111,   284,   111,   284,    95,
     111,   284,    61,    95,   111,   142,   284,   284,    22,    61,
     111,   284,   111,   284,   111,   284,   111,   276,   276,   276,
      61,   111,   111,   142,   143,   284,   111,   284,   284,   111,
     284,   284,   284,    95,   142,   143,   151,   154,   284,    95,
     142,   143,   154,   284,    95,   142,   143,   151,   152,   153,
     154,   284,    61,    95,   142,   143,   150,   154,   284,   111,
     284,   111,   284,   111,   276,   111,   276,   111,   276,   160,
      95,   111,   112,   143,   279,   253,   253,   253,   253,   253,
     276,   373,   276,   276,   276,    44,   260,    92,    93,   104,
      75,    75,    24,   253,   253,   253,   253,   279,   253,   253,
     253,   253,   253,   253,   112,   113,   253,   253,   253,   253,
     112,   253,   112,   155,   112,   155,   112,   113,   155,   112,
     113,   155,   112,   113,   155,   112,   113,   155,   112,   112,
     162,   161,   253,   112,   155,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   279,   276,   279,    70,    71,
      72,    73,    74,    75,    76,   247,    44,    63,    64,    70,
      71,    72,    73,    74,    75,    76,    77,   246,   247,   248,
     249,   276,    44,    44,    44,   279,   292,   276,   292,     4,
     279,   259,    35,    36,    20,    21,     4,     5,   303,   304,
       4,     5,   305,   306,   276,   279,   294,   295,   276,   279,
     320,   259,   336,   342,   253,    58,   253,     4,     7,   253,
     276,   279,   355,    58,    60,    61,   255,   357,   370,   253,
     253,   252,   252,   252,   253,   253,   252,   287,   287,   252,
     279,   276,   279,    11,   252,   252,   284,   276,   276,   276,
     252,   284,   269,    12,   252,   272,   276,   252,   284,    12,
     284,   272,   272,   272,   284,   284,   284,   284,   284,   284,
     284,   276,   276,   284,   284,   284,   284,   279,   272,   272,
     276,   252,   276,   252,   276,   276,   272,   276,   276,   276,
     276,   272,   252,   276,   276,   276,   272,   276,   272,   276,
     252,   276,   252,   252,   252,   276,   276,   276,   276,   276,
     272,   276,   272,   272,   276,   272,   272,   272,   276,   276,
     276,   276,   276,   272,   276,   276,   276,   276,   272,   276,
     276,   276,   276,   276,   276,   276,   272,   276,   276,   276,
     150,   276,   276,   276,   272,   276,   252,   276,   252,   276,
     252,   276,   252,   276,   252,   276,   276,   276,   276,   276,
     252,     5,   275,   275,   275,   254,   279,   276,   252,   252,
     252,   252,    43,   284,   284,   284,   279,   276,   297,   292,
     292,   279,   279,   279,   279,   279,   279,    97,   276,   373,
     373,   276,     4,     5,   282,   283,   282,   283,   284,   279,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   150,   276,   276,   276,
     276,   253,   276,   253,   253,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   373,   279,   279,   279,   279,
     279,   279,   279,   279,   254,   279,   276,   276,   276,   276,
     276,   279,   279,   276,   279,   254,   279,   279,   276,   279,
     276,   279,   276,   276,   254,   276,   254,   276,   254,   276,
     254,   276,   276,   276,   276,   279,   276,   276,   276,   276,
     276,   276,   276,   373,   276,   292,   292,   276,   279,   276,
     276,   276,   276,   276,   254,   254,   276,   275,   276,   275,
     276,   276,   276,   254,   254,   276,   276,   276,   276,   276,
     276,   276,   276,   281,   280,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   254,   254,    75,
     330,    14,    16,    18,    41,    44,    49,   334,   266,   267,
     253,   253,   252,   253,   253,   252,   252,    43,   319,    14,
      16,    18,    41,    44,    49,   327,    46,   259,   279,   253,
     276,   279,    51,   356,   251,   252,   253,    58,   253,     4,
       7,   253,    10,   371,   292,   292,     4,     5,   279,   279,
     292,   292,   353,    10,   286,   252,    86,    87,    97,   276,
     279,   272,   252,   279,   357,   284,   252,   276,   284,   272,
     279,   279,   284,   252,   272,   252,   272,   252,   272,   272,
     252,   252,   252,   272,   272,   252,   284,   284,   252,   276,
     252,   276,   252,   284,   252,   252,   252,   284,   276,   252,
     252,   252,   284,   252,   284,   252,   276,   252,   279,   276,
     276,   252,   252,   252,   252,   252,   284,   252,   284,   284,
     252,   284,   284,   284,   252,   252,   252,   284,   252,   252,
     252,   284,   252,   252,   252,   252,   252,   284,   252,   252,
     276,   252,   252,   252,   284,   252,   276,   252,   276,   252,
     276,   252,   276,   252,   276,   252,   252,   252,   279,   253,
     252,   252,   252,   254,   254,   276,   279,   276,   279,   279,
     279,   261,   252,   272,   272,     4,     5,   301,   254,   254,
     252,   252,   254,   252,   252,   252,   254,   252,   254,   252,
     254,   252,   253,   253,   254,   254,   252,   252,   272,   252,
     252,   254,   252,   252,   252,   276,   252,   252,   276,   254,
     276,   276,   254,   254,   254,   254,   254,   252,   254,   254,
     252,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   252,   254,   254,   252,   252,   252,   254,   252,
     252,   254,   252,   254,   254,   254,   254,   254,   252,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     252,   252,   252,   252,   254,   254,   254,   254,   254,   252,
     254,   254,   254,   254,   254,   254,   252,   254,   252,   252,
     252,   252,   252,   254,   252,   252,   254,   252,   254,   254,
     279,   279,   311,   259,   279,   288,   374,   288,   375,   292,
     292,   304,   292,   292,   306,   295,    43,   321,   337,    49,
      50,   343,   252,   279,   252,   254,   254,   253,   276,   276,
     279,   279,   253,   276,   358,   359,   279,     4,     5,   349,
     351,   254,   254,   253,   253,   252,   252,   254,   254,   279,
      85,    85,   252,   252,   284,   276,   276,   252,   284,   252,
     252,   252,   276,   284,   279,   284,   276,   284,   284,   276,
     279,   279,   279,   284,   284,   279,   252,   252,   279,   252,
     279,   252,   276,   279,   252,   276,   276,   276,   252,   252,
     276,   276,   276,   279,   252,   276,   252,   279,   252,   276,
     252,   276,   276,   279,   276,   279,   252,   276,   252,   252,
     279,   252,   252,   252,   276,   279,   276,   279,   279,   252,
     276,   279,   279,   252,   276,   276,   279,   276,   276,   279,
     252,   276,   279,   252,   279,   276,   279,   252,   276,   252,
     279,   252,   276,   279,   252,   276,   252,   276,   252,   276,
     276,   276,   252,   292,   279,   279,   279,   252,   252,   263,
     279,   284,   284,   298,   279,   279,   279,   279,   279,   276,
      97,   276,   276,   254,   254,   279,   279,   284,   279,   276,
     279,   279,   279,   279,   276,   254,   252,   252,   279,   279,
     279,   279,   279,   279,   279,   279,   276,   279,   276,   276,
     276,   276,   276,   279,   279,   279,   279,   283,   276,   283,
     276,   276,   279,    16,    44,   331,   252,   252,   254,   254,
     254,   254,    39,    40,   323,   259,   279,   252,   276,    58,
     276,   356,   252,   279,   252,   254,   349,   349,   254,   253,
     253,   252,   292,   292,   279,   279,   252,   373,   373,   276,
     276,   252,   252,   276,   279,   279,   276,   252,   252,   272,
     252,   252,   272,   252,   252,   252,   272,   252,   252,   276,
     276,   276,   276,   276,   252,   276,   276,   252,   252,   252,
     276,   252,   276,   276,   252,   276,   252,   252,   276,   252,
     276,   276,   276,   276,   276,   252,   276,   276,   252,   252,
     276,   252,   252,   279,   252,   276,   276,   252,   276,   252,
     252,   276,   252,   276,   252,   276,   252,   252,   276,   254,
     254,   254,   252,   254,   276,   276,   272,   253,   254,   254,
     254,   254,   254,   254,   254,   252,   254,   254,   254,   254,
     272,   252,   252,   276,   276,   254,   254,   254,   254,   254,
     252,   254,   254,   254,   252,   254,   254,   254,   252,   252,
     254,   252,   254,   254,   254,   252,   252,   254,   252,   254,
     254,   252,   254,   254,   254,    12,   288,   288,   320,    43,
      38,   338,   254,   279,   254,   253,   252,   279,   252,   276,
      58,   365,   360,   292,   292,   350,   254,   254,   276,   276,
     276,   252,   252,   252,   276,   276,   284,   276,   276,   284,
     279,   279,   279,   284,   279,   276,   252,   252,   252,   252,
     279,   252,   252,   276,   279,   279,   252,   276,   252,   252,
     279,   279,   276,   279,   252,   276,   252,   252,   252,   252,
     252,   276,   252,   252,   276,   279,   276,   252,   279,   279,
     279,   252,   252,   279,   276,   276,   252,   276,   279,   252,
     276,   252,   276,   276,    75,    75,   279,    75,   252,   284,
       4,     5,   307,   308,   276,   279,   276,   279,   254,   254,
     279,   276,   276,   279,   279,   276,   279,   276,   276,   279,
     322,   324,    48,   345,    60,    61,   254,    58,   279,   276,
     254,   279,   254,   253,   371,   349,   254,   254,   349,   252,
     276,   276,   276,   252,   272,   252,   252,   252,   272,   252,
     252,   276,   279,   279,   276,   252,   279,   276,   252,   276,
     252,   276,   279,   252,   252,   276,   276,   279,   279,   276,
     276,   279,   276,   252,   279,   252,   252,   252,   279,   276,
     252,   252,   276,   252,   252,   276,   252,   276,   252,   276,
     276,   254,   276,   279,   253,   253,   252,   254,   254,   252,
     254,   254,   254,   254,   254,   254,   254,   254,   254,    13,
     315,   259,   259,   279,    47,   344,   253,   253,   252,   254,
      60,    61,   361,   254,    58,   366,   279,   349,   276,   276,
     284,   279,   276,   279,   284,   279,   276,   252,   252,   252,
     252,   279,   252,   252,   279,   252,   279,   252,   252,   279,
     279,   252,   252,   252,   252,   252,   252,   279,   252,   279,
     279,   279,   252,   252,   279,   276,   276,   276,   252,   276,
     279,   252,   276,    75,   254,   254,   308,   299,   279,   279,
     312,    46,   348,   259,   339,   276,   279,   279,   367,   253,
     371,   362,   253,   371,   252,   252,   252,   252,   252,   252,
     252,   276,   276,   276,   276,   252,   276,   276,   252,   279,
     276,   279,   252,   276,   279,   279,   276,   276,   276,   276,
     252,   252,   252,   276,   276,   252,   276,   252,   252,   276,
     276,   259,   254,   259,   346,    14,    16,    18,    41,    44,
      49,   340,   252,   254,   252,   254,   371,   276,   349,   371,
     279,   349,   279,   276,   276,   279,   276,   276,   276,   252,
     279,   279,   252,   252,   252,   279,   252,   252,   279,   276,
     279,   252,   276,   276,   276,   252,    25,    44,   300,   313,
     259,   276,   279,   349,   252,   254,   349,   252,   254,   252,
     276,   279,   276,   279,   276,   276,   252,   276,   252,   276,
      14,    16,    18,    41,    44,    49,   314,   347,   254,   254,
     276,   368,   279,   363,   276,   252,   252,   279,   276,     4,
     316,   345,   254,   371,   254,   371,   276,   276,   252,   369,
     349,   364,   349,   252,   276,   371,   371,   276,   349,   349
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   256,   257,   257,   257,   257,   257,   258,   259,   260,
     261,   259,   262,   262,   262,   262,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   264,   263,   265,   263,   263,   263,   263,   263,   263,
     263,   266,   263,   267,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   268,   263,   269,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   270,   270,   270,   270,   270,
     271,   271,   271,   271,   271,   271,   272,   272,   273,   273,
     273,   273,   273,   274,   274,   275,   275,   276,   276,   276,
     276,   276,   276,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     278,   278,   280,   279,   281,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   282,   283,
     284,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   286,   286,
     286,   287,   287,   287,   287,   288,   288,   289,   289,   289,
     289,   290,   291,   293,   292,   294,   294,   294,   295,   295,
     297,   298,   299,   296,   300,   300,   301,   301,   302,   302,
     302,   302,   303,   303,   304,   304,   304,   304,   305,   305,
     306,   306,   306,   306,   307,   307,   307,   308,   308,   308,
     308,   310,   311,   312,   313,   309,   314,   314,   314,   314,
     314,   314,   315,   315,   316,   316,   318,   317,   319,   319,
     320,   320,   321,   322,   321,   323,   324,   323,   326,   325,
     327,   327,   327,   327,   327,   327,   329,   330,   328,   331,
     331,   333,   332,   334,   334,   334,   334,   334,   334,   336,
     337,   338,   339,   335,   340,   340,   340,   340,   340,   340,
     342,   341,   343,   343,   344,   344,   345,   346,   347,   345,
     348,   348,   349,   350,   349,   351,   351,   351,   351,   352,
     352,   353,   353,   353,   353,   354,   354,   354,   354,   355,
     355,   355,   355,   355,   356,   356,   356,   358,   357,   359,
     357,   360,   357,   361,   357,   362,   357,   363,   357,   364,
     357,   365,   357,   366,   357,   367,   357,   368,   357,   369,
     357,   370,   357,   371,   371,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   373,
     373,   374,   374,   375,   375
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
       9,    11,     3,     6,     4,    10,    10,     5,    10,     5,
       8,     5,    10,    12,     5,     5,     3,    10,     5,     5,
       3,    11,    14,    16,     7,     7,    11,     5,     6,     7,
       9,    12,     9,    14,     5,     7,     7,    11,     4,    10,
       5,     5,     5,    12,     7,    12,    10,     5,     8,     8,
      10,     5,     7,     5,     5,     5,     3,     3,    10,     5,
       5,     5,     3,    10,     5,     9,     7,     5,     5,     7,
       5,     3,     5,     5,     3,    12,    15,    11,     5,     6,
       5,     3,    11,    10,     5,     6,     9,     8,     7,     9,
      10,     9,    11,    12,    13,    11,     3,     9,     5,     6,
       7,     3,    11,     2,     3,     2,     2,     1,     1,     3,
       4,     4,     4,     4,     4,     4,     1,     1,     2,     1,
       2,     2,     8,     6,     6,     0,     1,     1,     2,     2,
       3,    10,     8,     8,     8,     3,     1,     1,     6,     4,
       4,     6,     6,     4,     6,     1,     4,     1,     1,     1,
       1,     3,     3,     6,     6,     8,     6,     4,     6,     8,
       4,     1,     3,     4,     4,     4,     4,     4,     4,     4,
       6,     8,     4,     4,     4,     4,     4,     6,     1,     3,
       1,     3,     4,     3,     3,     3,     3,     5,     5,     5,
       7,     3,     4,     5,     2,     1,     7,     6,     6,     4,
       6,     4,     6,    10,     4,     4,     4,     8,     6,     4,
       3,     3,     0,     4,     0,     4,     2,     3,     3,     3,
       3,     3,     3,     3,     4,     6,     1,     4,     4,     6,
       6,     1,     1,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     4,     4,     4,     4,     4,     4,     6,     4,     4,
       6,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       6,     4,     3,     6,     6,     4,     4,     4,     4,     6,
       6,     8,     6,     8,     4,     4,     4,     8,     4,     4,
       4,     4,     1,     3,     4,     1,     3,     4,     1,     3,
       4,     1,     3,     6,     6,     4,     6,     6,     6,     4,
       8,     6,     8,     6,     4,     4,     4,     6,     6,     6,
       8,     4,     2,     5,     7,     3,     3,     3,     3,     3,
       3,     3,     4,     3,     5,     5,     7,     4,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     4,     6,     4,
       6,     4,     4,     0,     2,     0,     1,     3,     1,     1,
       0,     0,     0,    11,     1,     1,     1,     1,     0,     1,
       1,     2,     1,     3,     1,     1,     4,     4,     1,     3,
       1,     1,     4,     4,     0,     1,     3,     1,     1,     3,
       3,     0,     0,     0,     0,    14,     1,     1,     1,     1,
       1,     1,     0,     2,     0,     1,     0,     7,     1,     2,
       1,     1,     0,     0,     5,     0,     0,     4,     0,     4,
       1,     1,     1,     1,     1,     1,     0,     0,     6,     1,
       1,     0,     4,     1,     2,     1,     1,     1,     1,     0,
       0,     0,     0,    11,     1,     1,     1,     1,     1,     1,
       0,     5,     1,     1,     0,     2,     0,     0,     0,     7,
       0,     1,     1,     0,     4,     1,     4,     1,     4,     1,
       3,     1,     4,     1,     4,     1,     1,     3,     3,     0,
       2,     4,     1,     3,     0,     2,     6,     0,     4,     0,
       4,     0,     6,     0,     9,     0,    10,     0,    13,     0,
      15,     0,     7,     0,     9,     0,    10,     0,    13,     0,
      15,     0,     3,     0,     1,     0,     2,     2,     4,     1,
       4,     6,     6,     7,    10,    12,     7,    10,    12,     2,
       1,     1,     3,     1,     3
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

  case 115: /* statement: tBUTTON coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                         {add_command(cYABBUTTON);}
    break;

  case 116: /* statement: tCHECKBOX coordinates ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                           {add_command(cYABCHECKBOX);}
    break;

  case 117: /* statement: tCHECKBOX tSET string_expression ',' expression  */
                                                    {add_command(cYABCHECKBOXSET);}
    break;

  case 118: /* statement: tRADIOBUTTON coordinates ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                              {add_command(cYABRADIOBUTTON);}
    break;

  case 119: /* statement: tRADIOBUTTON tSET string_expression ',' expression  */
                                                       {add_command(cYABRADIOSET);}
    break;

  case 120: /* statement: tTEXT coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                        {add_command(cYABTEXT);}
    break;

  case 121: /* statement: tTEXT tSET string_expression ',' string_expression  */
                                                       {add_command(cYABTEXTALIGN);}
    break;

  case 122: /* statement: tTEXTURL coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                 {add_command(cYABTEXTURL);}
    break;

  case 123: /* statement: tTEXTCONTROL coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                    {add_command(cYABTEXTCONTROL);}
    break;

  case 124: /* statement: tTEXTCONTROL tSET string_expression ',' string_expression  */
                                                              {add_command(cYABTEXTCONTROLSET);}
    break;

  case 125: /* statement: tTEXTCONTROL tSET string_expression ',' expression  */
                                                       {add_command(cYABTEXTCONTROLMASK);}
    break;

  case 126: /* statement: tTEXTCONTROL tCLEAR string_expression  */
                                          {add_command(cYABTEXTCONTROLCLEAR);}
    break;

  case 127: /* statement: tTEXTEDIT coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                    {add_command(cYABTEXTEDIT);}
    break;

  case 128: /* statement: tTEXTEDIT tADD string_expression ',' string_expression  */
                                                           {add_command(cYABTEXTEDITADD);}
    break;

  case 129: /* statement: tTEXTEDIT tSET string_expression ',' string_expression  */
                                                           {add_command(cYABTEXTEDITSET);}
    break;

  case 130: /* statement: tTEXTEDIT tCLEAR string_expression  */
                                       {add_command(cYABTEXTEDITCLEAR);}
    break;

  case 131: /* statement: tTEXTEDIT tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                           {add_command(cYABTEXTEDITCOLOUR);}
    break;

  case 132: /* statement: tSLIDER coordinates to coordinates ',' string_expression ',' string_expression ',' expression ',' expression ',' string_expression  */
                                                                                                                                       {add_command(cYABSLIDER);}
    break;

  case 133: /* statement: tSLIDER coordinates to coordinates ',' string_expression ',' string_expression ',' expression ',' expression ',' string_expression ',' string_expression  */
                                                                                                                                                             {add_command(cYABSLIDEROPT);}
    break;

  case 134: /* statement: tSLIDER tLABEL string_expression ',' string_expression ',' string_expression  */
                                                                                 {add_command(cYABSLIDERLABEL);}
    break;

  case 135: /* statement: tSLIDER tSET string_expression ',' string_expression ',' expression  */
                                                                        {add_command(cYABSLIDERMARKS);}
    break;

  case 136: /* statement: tSLIDER tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                         {add_command(cYABSLIDERCOLOUR);}
    break;

  case 137: /* statement: tSLIDER tSET string_expression ',' expression  */
                                                  {add_command(cYABSLIDERSET);}
    break;

  case 138: /* statement: tSCROLLBAR string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cYABSCROLLBAR);}
    break;

  case 139: /* statement: tSCROLLBAR tSET string_expression ',' string_expression ',' expression  */
                                                                           {add_command(cYABSCROLLBARSET);}
    break;

  case 140: /* statement: tSCROLLBAR tSET string_expression ',' string_expression ',' expression ',' expression  */
                                                                                          {add_command(cYABSCROLLBARRANGE);}
    break;

  case 141: /* statement: tSTATUSBAR coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                  {add_command(cYABSTATUSBAR);}
    break;

  case 142: /* statement: tSTATUSBAR tSET string_expression ',' string_expression ',' string_expression ',' expression  */
                                                                                                 {add_command(cYABSTATUSBARSET);}
    break;

  case 143: /* statement: tSPINCONTROL coordinates ',' string_expression ',' string_expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                                                            {add_command(cYABSPINCONTROL);}
    break;

  case 144: /* statement: tSPINCONTROL tSET string_expression ',' expression  */
                                                       {add_command(cYABSPINCONTROLSET);}
    break;

  case 145: /* statement: tOPTION tSET string_expression ',' string_expression ',' string_expression  */
                                                                               {add_command(cYABOPTIONTEXT);}
    break;

  case 146: /* statement: tOPTION tSET string_expression ',' string_expression ',' expression  */
                                                                        {add_command(cYABOPTIONNUMBER);}
    break;

  case 147: /* statement: tOPTION tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                         {add_command(cYABOPTIONCOLOUR);}
    break;

  case 148: /* statement: tTOOLTIP string_expression ',' string_expression  */
                                                     {add_command(cYABTOOLTIP);}
    break;

  case 149: /* statement: tTABVIEW coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                          {add_command(cYABTABVIEW);}
    break;

  case 150: /* statement: tTABVIEW tADD string_expression ',' string_expression  */
                                                          {add_command(cYABTABADD);}
    break;

  case 151: /* statement: tTABVIEW tSET string_expression ',' expression  */
                                                   {add_command(cYABTABSET);}
    break;

  case 152: /* statement: tTABVIEW tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABTABREMOVE);}
    break;

  case 153: /* statement: tBOXVIEW coordinates to coordinates ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                                         {add_command(cYABBOXVIEW);}
    break;

  case 154: /* statement: tBOXVIEW tSET string_expression ',' string_expression ',' string_expression  */
                                                                                {add_command(cYABBOXVIEWSET);}
    break;

  case 155: /* statement: tSPLITVIEW coordinates to coordinates ',' string_expression ',' expression ',' expression ',' string_expression  */
                                                                                                                    {add_command(cYABSPLITVIEW);}
    break;

  case 156: /* statement: tSTACKVIEW coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                     {add_command(cYABSTACKVIEW);}
    break;

  case 157: /* statement: tSTACKVIEW tSET string_expression ',' expression  */
                                                     {add_command(cYABSTACKVIEWSET);}
    break;

  case 158: /* statement: tCANVAS coordinates to coordinates ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABCANVAS);}
    break;

  case 159: /* statement: tREGION coordinates to coordinates ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABREGION);}
    break;

  case 160: /* statement: tLISTBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                   {add_command(cYABLISTBOX);}
    break;

  case 161: /* statement: tLISTBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABLISTBOXADD);}
    break;

  case 162: /* statement: tLISTBOX tADD string_expression ',' expression ',' string_expression  */
                                                                         {add_command(cYABLISTBOXADD2);}
    break;

  case 163: /* statement: tLISTBOX tREMOVE string_expression ',' string_expression  */
                                                             {add_command(cYABLISTBOXREMOVE);}
    break;

  case 164: /* statement: tLISTBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABLISTBOXREMOVE2);}
    break;

  case 165: /* statement: tLISTBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABLISTBOXSELECT);}
    break;

  case 166: /* statement: tLISTBOX tCLEAR string_expression  */
                                      {add_command(cYABLISTBOXCLEAR);}
    break;

  case 167: /* statement: tLISTBOX tSORT string_expression  */
                                     {add_command(cYABLISTSORT);}
    break;

  case 168: /* statement: tDROPBOX coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                          {add_command(cYABDROPBOX);}
    break;

  case 169: /* statement: tDROPBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABDROPBOXADD);}
    break;

  case 170: /* statement: tDROPBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABDROPBOXSELECT);}
    break;

  case 171: /* statement: tDROPBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABDROPBOXREMOVE);}
    break;

  case 172: /* statement: tDROPBOX tCLEAR string_expression  */
                                      {add_command(cYABDROPBOXCLEAR);}
    break;

  case 173: /* statement: tTREEBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                   {add_command(cYABTREEBOX);}
    break;

  case 174: /* statement: tTREEBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABTREEADD);}
    break;

  case 175: /* statement: tTREEBOX tADD string_expression ',' string_expression ',' string_expression ',' expression  */
                                                                                               {add_command(cYABTREEADDCHILD);}
    break;

  case 176: /* statement: tTREEBOX tADD string_expression ',' string_expression ',' expression  */
                                                                         {add_command(cYABTREEADDAT);}
    break;

  case 177: /* statement: tTREEBOX tREMOVE string_expression ',' string_expression  */
                                                             {add_command(cYABTREEREMOVE);}
    break;

  case 178: /* statement: tTREEBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABTREEREMOVE2);}
    break;

  case 179: /* statement: tTREEBOX tREMOVE string_expression ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABTREEREMOVECHILD);}
    break;

  case 180: /* statement: tTREEBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABTREESELECT);}
    break;

  case 181: /* statement: tTREEBOX tCLEAR string_expression  */
                                      {add_command(cYABTREECLEAR);}
    break;

  case 182: /* statement: tTREEBOX tEXPAND string_expression ',' string_expression  */
                                                             {add_command(cYABTREEEXPAND);}
    break;

  case 183: /* statement: tTREEBOX tCOLLAPSE string_expression ',' string_expression  */
                                                               {add_command(cYABTREECOLLAPSE);}
    break;

  case 184: /* statement: tTREEBOX tSORT string_expression  */
                                     {add_command(cYABTREESORT);}
    break;

  case 185: /* statement: tCOLUMNBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression ',' string_expression  */
                                                                                                                           {add_command(cYABCOLUMNBOX);}
    break;

  case 186: /* statement: tCOLUMNBOX tCOLUMN string_expression ',' string_expression ',' expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                                                                 {add_command(cYABCOLUMNBOXCOLUMN);}
    break;

  case 187: /* statement: tCOLUMNBOX tADD string_expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                         {add_command(cYABCOLUMNBOXADD);}
    break;

  case 188: /* statement: tCOLUMNBOX tREMOVE string_expression ',' expression  */
                                                        {add_command(cYABCOLUMNBOXREMOVE);}
    break;

  case 189: /* statement: tCOLUMNBOX tREMOVE tCOLUMN string_expression ',' expression  */
                                                                {add_command(cYABCOLUMNBOXREMOVECOLUMN);}
    break;

  case 190: /* statement: tCOLUMNBOX tSELECT string_expression ',' expression  */
                                                        {add_command(cYABCOLUMNBOXSELECT);}
    break;

  case 191: /* statement: tCOLUMNBOX tCLEAR string_expression  */
                                        {add_command(cYABCOLUMNBOXCLEAR);}
    break;

  case 192: /* statement: tCOLUMNBOX tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                            {add_command(cYABCOLUMNBOXCOLOUR);}
    break;

  case 193: /* statement: tCALENDAR coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                  {add_command(cYABCALENDAR);}
    break;

  case 194: /* statement: tCALENDAR tSET string_expression ',' string_expression  */
                                                           {add_command(cYABCALENDARSET);}
    break;

  case 195: /* statement: tCOLORCONTROL coordinates ',' string_expression ',' string_expression  */
                                                                          {add_command(cYABCOLORCONTROL);}
    break;

  case 196: /* statement: tCOLORCONTROL tSET string_expression ',' expression ',' expression ',' expression  */
                                                                                      {add_command(cYABCOLORCONTROLSET);}
    break;

  case 197: /* statement: tMENU string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                              {add_command(cYABMENU);}
    break;

  case 198: /* statement: tMENU tSET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cYABMENURADIO);}
    break;

  case 199: /* statement: tMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                   {add_command(cYABMENUOPTION);}
    break;

  case 200: /* statement: tSUBMENU string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                       {add_command(cYABSUBMENU);}
    break;

  case 201: /* statement: tSUBMENU tSET string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                               {add_command(cYABSUBMENURADIO);}
    break;

  case 202: /* statement: tSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                            {add_command(cYABSUBMENUOPTION);}
    break;

  case 203: /* statement: tSUBSUBMENU string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                                {add_command(cYABSUBSUBMENU);}
    break;

  case 204: /* statement: tSUBSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                                     {add_command(cYABSUBSUBMENUOPTION);}
    break;

  case 205: /* statement: tSUBSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                                        {add_command(cYABSUBSUBMENURADIO);}
    break;

  case 206: /* statement: tCLIPBOARD tCOPY string_expression  */
                                       {add_command(cYABCLIPBOARDCOPY);}
    break;

  case 207: /* statement: tATTRIBUTE tSET string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                        {add_command(cYABATTRIBUTESET);}
    break;

  case 208: /* statement: tATTRIBUTE tCLEAR string_expression ',' string_expression  */
                                                              {add_command(cYABATTRIBUTECLEAR);}
    break;

  case 209: /* statement: tBITMAP expression ',' expression ',' string_expression  */
                                                            {add_command(cYABBITMAP);}
    break;

  case 210: /* statement: tBITMAP tGET string_expression ',' string_expression ',' string_expression  */
                                                                               {add_command(cYABBITMAPGET);}
    break;

  case 211: /* statement: tBITMAP tREMOVE string_expression  */
                                      {add_command(cYABBITMAPREMOVE);}
    break;

  case 212: /* statement: tDRAW tBITMAP expression ',' expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                              {add_command(cYABBITMAPDRAW);}
    break;

  case 213: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 214: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 215: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 216: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 217: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 218: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 219: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 220: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 221: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 222: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 223: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 224: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 225: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 226: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 227: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 228: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 229: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 230: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 231: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 232: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 233: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 234: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 235: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 236: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 237: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 238: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 239: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 240: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 241: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 242: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 243: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 244: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 245: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 248: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 249: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 250: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 251: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 252: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 253: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 254: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 255: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 256: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 257: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 259: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 260: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 261: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 263: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 264: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 265: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 266: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 267: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 268: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 269: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 270: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 271: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 272: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 273: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 274: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 275: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 276: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 277: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 278: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 279: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 280: /* string_function: tSTRING2 '(' expression ',' string_expression ')'  */
                                                      {create_function(fSTRING);}
    break;

  case 281: /* string_function: tREPLACE '(' string_expression ',' string_expression ',' string_expression ')'  */
                                                                                    {create_function(fREPLACE);}
    break;

  case 282: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 283: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 284: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 285: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 286: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 287: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 288: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 289: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 290: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 291: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 292: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 293: /* string_function: tTEXTCONTROL tGET string_expression  */
                                        {create_function(fYABTEXTCONTROLGET);}
    break;

  case 294: /* string_function: tTEXTEDIT tGET string_expression  */
                                     {create_function(fYABTEXTEDITGET);}
    break;

  case 295: /* string_function: tTEXTCONTROL tGETS string_expression  */
                                                         {create_function(fYABTEXTCONTROLGET);}
    break;

  case 296: /* string_function: tTEXTEDIT tGETS string_expression  */
                                                      {create_function(fYABTEXTEDITGET);}
    break;

  case 297: /* string_function: tLISTBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABLISTBOXGET);}
    break;

  case 298: /* string_function: tDROPBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABDROPBOXGET);}
    break;

  case 299: /* string_function: tTREEBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABTREEBOXGET);}
    break;

  case 300: /* string_function: tCOLUMNBOX tGETS string_expression ',' expression ',' expression  */
                                                                                     {create_function(fYABCOLUMNBOXGET);}
    break;

  case 301: /* string_function: tCALENDAR tGET string_expression  */
                                                     {create_function(fYABCALENDARGET);}
    break;

  case 302: /* string_function: tTRANSLATE '(' string_expression ')'  */
                                         {create_function(fYABTRANSLATE);}
    break;

  case 303: /* string_function: tMENU tTRANSLATE '(' string_expression ')'  */
                                               {create_function(fYABMENUTRANSLATE);}
    break;

  case 304: /* string_function: tCLIPBOARD tPASTE  */
                      {create_function(fYABCLIPBOARDPASTE);}
    break;

  case 305: /* string_function: tMESSAGE  */
             {create_function(fYABMESSAGE);}
    break;

  case 306: /* string_function: tATTRIBUTE tGETS '(' string_expression ',' string_expression ')'  */
                                                                     {create_function(fYABATTRIBUTEGET);}
    break;

  case 307: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 308: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 309: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 310: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 311: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 312: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 313: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 314: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 315: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 316: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 317: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 318: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 319: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 320: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 321: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 322: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 323: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 324: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 325: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 326: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 327: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 328: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 329: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 330: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 331: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 332: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 333: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 334: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 335: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 336: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 337: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 338: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 339: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 340: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 341: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 342: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 343: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 344: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 345: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 346: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 347: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 348: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 349: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 350: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 351: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 352: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 353: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 354: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 355: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 358: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 359: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 361: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 362: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 363: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 364: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 365: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 366: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 367: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 368: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 369: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 370: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 371: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 372: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 373: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 374: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 375: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 376: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 377: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 378: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 379: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 380: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 381: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 382: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 383: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 384: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 385: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 386: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 387: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 388: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 389: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 390: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 391: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 392: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 393: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 394: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 395: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 396: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 397: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 398: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 399: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 400: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 401: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 402: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 403: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 404: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 405: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 406: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 407: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 408: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 409: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 410: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 411: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 412: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 413: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 414: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 415: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 416: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 417: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 418: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 419: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 420: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 421: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 422: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 423: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 424: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 425: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 426: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 427: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 428: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 429: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 430: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 431: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 432: /* function: tWINDOW tCOUNT  */
                   {create_function(fYABNUMWINDOWS);}
    break;

  case 433: /* function: tWINDOW tGET string_expression ',' string_expression  */
                                                         {create_function(fYABWINDOWGET);}
    break;

  case 434: /* function: tATTRIBUTE tGET '(' string_expression ',' string_expression ')'  */
                                                                    {create_function(fYABATTRIBUTEGETNUM);}
    break;

  case 435: /* function: tLISTBOX tCOUNT string_expression  */
                                                      {create_function(fYABLISTBOXCOUNT);}
    break;

  case 436: /* function: tLISTBOX tGET string_expression  */
                                                    {create_function(fYABLISTBOXSELECTED);}
    break;

  case 437: /* function: tDROPBOX tCOUNT string_expression  */
                                                      {create_function(fYABDROPBOXCOUNT);}
    break;

  case 438: /* function: tDROPBOX tGET string_expression  */
                                                    {create_function(fYABDROPBOXSELECTED);}
    break;

  case 439: /* function: tTREEBOX tCOUNT string_expression  */
                                                      {create_function(fYABTREEBOXCOUNT);}
    break;

  case 440: /* function: tTREEBOX tGET string_expression  */
                                                    {create_function(fYABTREEBOXSELECTED);}
    break;

  case 441: /* function: tCOLUMNBOX tCOUNT string_expression  */
                                                        {create_function(fYABCOLUMNBOXCOUNT);}
    break;

  case 442: /* function: tCOLUMNBOX tCOUNT tCOLUMN string_expression  */
                                                                {create_function(fYABCOLUMNBOXCOUNTCOLUMNS);}
    break;

  case 443: /* function: tCOLUMNBOX tGET string_expression  */
                                                      {create_function(fYABCOLUMNBOXSELECTED);}
    break;

  case 444: /* function: tCOLORCONTROL tGET string_expression ',' string_expression  */
                                                                               {create_function(fYABCOLORCONTROLGET);}
    break;

  case 445: /* function: tDRAW tGET string_expression ',' string_expression  */
                                                       {create_function(fYABDRAWGET);}
    break;

  case 446: /* function: tDRAW tGET string_expression ',' string_expression ',' string_expression  */
                                                                             {create_function(fYABDRAWGETTEXT);}
    break;

  case 447: /* function: tBFILESIZE '(' string_expression ')'  */
                                         {create_function(fYABBFILESIZE);}
    break;

  case 448: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 449: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 450: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 451: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 452: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 453: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 454: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 455: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 456: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 457: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 458: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 459: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 460: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 461: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 462: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 463: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 470: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 471: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 472: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 473: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 474: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 475: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 476: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 477: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 478: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 479: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 480: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 481: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 484: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 485: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 486: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 487: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 490: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 491: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 492: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 493: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 497: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 498: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 499: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 500: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 501: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 502: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 503: /* $@17: %empty  */
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

  case 504: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 505: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 506: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 507: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 508: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 509: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 510: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 511: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 512: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 514: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 515: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 516: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 517: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 523: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 524: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 526: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 528: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 530: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 531: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 532: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 533: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 534: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 535: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 536: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 537: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 539: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 540: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 541: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 543: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 544: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 545: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 546: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 547: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 548: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 549: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 550: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 551: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 552: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 554: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 555: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 556: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 557: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 558: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 559: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 560: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 562: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 563: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 567: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 568: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 573: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 575: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 576: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 577: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 578: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 581: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 582: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 583: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 584: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 585: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 586: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 587: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 588: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 592: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 593: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 594: /* using: %empty  */
       {create_print('d');}
    break;

  case 595: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 596: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 597: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 598: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 599: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 600: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 601: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 602: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 603: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 604: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 605: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 606: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 607: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 608: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 609: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 610: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 611: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 612: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 613: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 614: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 615: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 616: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 617: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 618: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 619: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 620: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 621: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 622: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 623: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 624: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 625: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 626: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 627: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 628: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 629: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 630: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 631: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 632: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 633: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 634: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 635: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 636: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 637: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 638: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 641: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 642: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 643: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 644: /* gosub_list: gosub_list ',' symbol_or_lineno  */
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

