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
#define YYFINAL  252
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   15666

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  256
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  649
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2059

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
     411,   412,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   495,   496,   497,
     498,   499,   503,   504,   505,   506,   507,   508,   511,   512,
     515,   516,   517,   518,   519,   522,   523,   526,   527,   530,
     531,   532,   533,   534,   535,   538,   539,   540,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   570,   571,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   588,   589,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   605,   606,   609,   609,   610,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   640,   641,   642,
     645,   648,   651,   654,   655,   656,   657,   658,   659,   660,
     661,   662,   663,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   704,   705,   706,   707,   708,   709,   710,
     711,   712,   713,   714,   715,   716,   717,   718,   719,   720,
     721,   722,   723,   724,   727,   728,   731,   734,   735,   736,
     737,   738,   739,   740,   741,   742,   743,   744,   745,   746,
     747,   748,   749,   752,   753,   754,   757,   758,   759,   760,
     763,   764,   767,   768,   769,   770,   773,   776,   779,   779,
     782,   783,   784,   787,   788,   791,   792,   795,   791,   800,
     801,   804,   805,   808,   809,   810,   811,   814,   815,   818,
     819,   820,   821,   824,   825,   828,   829,   830,   831,   834,
     835,   836,   839,   840,   841,   842,   845,   846,   851,   866,
     845,   871,   872,   873,   874,   875,   876,   879,   880,   883,
     884,   889,   889,   893,   894,   897,   898,   902,   904,   903,
     908,   909,   909,   913,   913,   919,   920,   921,   922,   923,
     924,   928,   929,   928,   935,   936,   940,   940,   945,   946,
     947,   948,   949,   950,   953,   954,   954,   956,   953,   960,
     961,   962,   963,   964,   965,   968,   968,   973,   974,   977,
     978,   981,   983,   985,   982,   989,   990,   993,   994,   994,
     997,   998,  1000,  1001,  1005,  1006,  1009,  1010,  1012,  1013,
    1017,  1018,  1019,  1020,  1023,  1024,  1025,  1026,  1027,  1030,
    1031,  1032,  1035,  1035,  1036,  1036,  1037,  1037,  1038,  1038,
    1039,  1039,  1040,  1040,  1041,  1041,  1042,  1042,  1043,  1043,
    1044,  1044,  1045,  1045,  1046,  1046,  1047,  1047,  1050,  1051,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1062,  1063,
    1064,  1065,  1066,  1067,  1070,  1071,  1073,  1074,  1077,  1078
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

#define YYPACT_NINF (-1610)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-555)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     366, 13174, 11181, 12604,    12,   110,    33,   -56,   -38, -1610,
   -1610, -1610, -1610, -1610,    86,    86,    86,  8217, -1610, -1610,
   -1610, 12604, -1610, -1610, 12604,    14,    82, -1610, -1610, -1610,
   11181,   -20, -1610, 11181,   295, -1610, 11181, 11181, 11181,   332,
      17,    86,  3984,  3655,  4491,    -1, 11181,  7229,  8464,   160,
     -40, 11181, -1610,    18, 12604, 12604, 12604,    19, 11181,  3035,
   11181, 11181,  8711,  8958,  7476,  6241, 11181,  6735,  9205,  9452,
   11646, 12604, 12604,   -29,  6982,  9699,  9946, 10193, 11181, 11181,
    5994,  6488,  5500,  5747, 10440, 10687, 11765, 11884, 12003,    -4,
     -33,  7723,   -68,   -65,   -55,   -49,   -35,  4491, 12604, 12604,
   12604, -1610,   177, -1610, -1610,    79, -1610, -1610, -1610, -1610,
     167,   170, -1610,   224, -1610, -1610, -1610, -1610, -1610, -1610,
   -1610, -1610,    13,    26, -1610, -1610, -1610, -1610,    31,    42,
      66,    95, 11181,   108,   114,   134,   136,   140,   159,   -48,
     172,   174,   176,   185,   141,   201,   -76,   -41,   190,   209,
     246,   -69,    15,    32,    61,   279,   350,   302,   305,   244,
   -1610,    84,   263,   265,   289,   308,   318,   329,   341,   384,
     440,   454,   484,   497,   500,   509,   513,   515,   540,   553,
     561,   564,   577,   655,   680,   692,   704,   720,   726,   754,
     786,   799,   803,   813,   819,   826,   839,   873,   884,   886,
     893,   903,   921,   922,   934,   943,   952,   970,   983,   985,
     986,  1034,  1035,  1061,  1070,  1077,  1080,  1088,  1090,  1092,
    1098,  1106,  1115,  1116,  1124,  1141,  1161,  1181,  1182,  1185,
    1195,  1198, 11181, 11181,   268, -1610,   539, -1610, -1610, -1610,
   -1610,   414,   502,   621,   623,   691, 12604,   -30,   837,   167,
     170,   858, -1610, 11181, -1610, 12604, -1610,   859, 11181, 12958,
   -1610, -1610, -1610, -1610, -1610,   343,   105,   490,   523,   663,
   -1610, 11181, -1610,   663, -1610, -1610, 11181, 12958,   572,  1206,
     902,  1225,     4, 11181,   -11,   268, 11518,  1226,  1252,   673,
   11518,   268,  1746,   268,  2641,  1265,  1271,   735, -1610, -1610,
    1100,  1100, -1610, -1610,   834, -1610,  7970, 12604, 11181,    87,
   11518,   865,   -48, -1610, -1610, -1610,   881, 11181, 12604, 12604,
   12604, 11415, -1610, 11181, -1610,     3, 12604,  1006, -1610, -1610,
   11181, 10934, -1610, -1610, 11518, -1610, -1610,   663,    -6,    -6,
   -1610,     3, 11181, 11181, 11181, 11181, 11181, 11181, 11181, 12604,
   12604, 11181, 11181, 11181, 11181, 11181,     3,     3, 12604,  1014,
   12604,  1023, 12604, 12604,     3, 12604, 12604, 12604, 12604,     3,
    1039, 12604, 12604, 12604,     3, 12604,     3, 12604,  1060, 12604,
     -15,    98,   313, 12604, 12604, 12604, 12604, 12604,     3, 12604,
       3, 12604,     3, 12604,     3,     3,     3, 12604, 12604, 12604,
   12604, 12604,     3, 12604, 12604, 12604, 12604,     3, 12604, 12604,
   12604, 12604, 12604, 12604, 12604,     3, 12604, 12604, 12604, 12114,
   12604, 12604,     3, 12604,  1144, 12604,  1171, 12604,   334, 12604,
     376, 12604,   377, 12604, 12604, 12604, 12604, 12604, 11432,  1012,
    1012,  1012,  4744, 12604,   152,  1237,   663,   404,   487, -1610,
    1111, 11181, 11181, 11181, 11181, 12604, -1610, -1610, -1610, 11181,
   11181,   920, 11181, 11181, 11181, 11181,  4237,  4491, 12604, -1610,
     547,   547, 11181, 11181, 12604, 12604, 12604, 12604, 12604, 12604,
   12604, 12604, 12604, 12604, 12604, 12604, 12604, 12604, 12604, 12604,
   12604, 12604, 12604, 12244, 12604, 12604, 12604,  1279, -1610, 12604,
    1301,  1319, 11181, 11181, 11181, 11181, 11181, 11181, 11181, 11181,
   11181, 11181,  4491, 11181, 11181, 11181, 11181, 11181, 11181, 11181,
   11181,  4996, 12604, 12604, 12604, 12604, 12604, 11181, 11181, 11181,
    5248, 11181, 12604, 11181, 12604, 11181, 12604, 12604,  2220,  2370,
   11416, 11527, 12604, 12604, 12604, 11181, 12604, 12604, 12604, 12604,
   12604, 12604,  4491, 12604, -1610, -1610, 12604, 11181, 12604, 12604,
   12604, 12604, 12604,  1078,  1183, 12604,  1012, 12604,  1012, 12604,
   12604, 12604,  1058,   138,   728, 12604, 12604, 12604, 12604, 12604,
   12604, 12604, 12604, -1610, -1610, -1610, 11181, 11181, 11181, 11181,
   11181, 11181, 11181, 11181, 11181, 11181, 11181, 11181,  -191, -1610,
   -1610, -1610, 11518,  1267,   663,  1325,  1147, 11518,  1081, -1610,
   -1610, -1610, -1610,  1320,  1353,  1246, -1610,  1356,  1360,  1262,
   -1610,   268, 11518,  1316, -1610,   268, 11518,  1152,  1245,  1367,
   12958, 11181,  1366, 12604, -1610, -1610, 11181,   268,   589,   333,
    1380,  1599,  1407,     6, -1610,  1487, -1610, -1610,   665, 11181,
   11181, -1610, -1610,   332, -1610, -1610,    67, 11454,   663, 11518,
     586, 12374, 11181,     3,   663,   663,   543, 11181, -1610,   -11,
   -1610, -1610, 11181,   806, 12604, -1610, 11181,     3, 11181, 11181,
   11181,  1412,     3,  1414,     3,  1422,     3,     3,   823,   663,
    1424,  1428,     3,     3, 12107, 11181, 11181,   833, 12604,   849,
   12604,   663,   867, 11181,   868,   663,   869,   876, 11181, 12604,
     880,   882,   898, 11181,   900, 11181,   901, 12604,   908, 11181,
   12604, 12604,   918,   924,   941,   942,   968, 11181,   969, 11181,
    1001, 11181,  1002, 11181, 11181, 11181,   663,  1003,  1004,   663,
    1005, 11181,   663,  1013,  1021,  1038, 11181,   663,  1051,  1053,
     663,  1057,  1059,  1063, 11181,  1066,   663,  1073, 12604,  1075,
    1079,  1095, 11181,  1097, 12604,  1114, 12604,  1120, 12604,  1132,
   12604,  1136, 12604,   663,  1139,  1143,  1145,   663, 11181,  1437,
    1462,  1463,  1464, -1610,   752,  -108, 11181, 11181, 11181, 11181,
   -1610,  1472,     3,     3, 11518,   663,   706,  1471,  1478, 12419,
   12828,   864, 13094, 13310, 13385,  1480,   119,  1488,  1505,  1157,
    1516,  1526,  1517,  1537,  1489,  1541,     3, 13497,  1158,  -107,
     663,   663,   663,   663,   663,  1159,   663,   663,   663,  1160,
     663,   663,  1168,   663,   663,  1174,   663, 12604,   663,  1175,
     663,  1178, 12604,   -18, 12604, 12604,   960,  1109,  1127,  1154,
    1170,   373,  1207,   436,  1369,  1473,  1550,  1771,  1987,  2006,
    2021,  2045,  2066,  2104, 13517, -1610,  2428,     0,  1184,  1200,
    1210,    11, 13551, 13572,   385,   628, -1610,  2562,  2591,    36,
    2667,   -14,  2726,    49,    64, -1610,   102, -1610,   188, -1610,
     251, -1610,   270,   316,   379,   387, 13587,  1211,  1213,  1219,
     461,   462,   542,   517,  1551,    34,  1558,  1560,   607,  2783,
     625,    35,  1220,  1221,  1222, -1610, -1610,  1223,  -141,  1230,
     -88,  1233,   631,   652, -1610, -1610,   663,   663,   663,   663,
     663,   663,   663, -1610, 11181, 11181,  1701,    28,   683,   255,
     756,   610,    23, -1610,   -46,   -46,  1058,  1058, -1610, -1610,
   -1610, 12958, -1610, -1610, 11181, -1610, -1610, -1610, -1610,    86,
      86, -1610, -1610,   490, -1610, -1610,   523, 11181, -1610,  1725,
   -1610, -1610, -1610, -1610, -1610, -1610, -1610, -1610,   844, 13602,
   11181,    58,  2869, 12723, -1610, -1610, 11181, 11181,  1562, 12604,
   -1610, -1610, 11181, -1610,  1022,  1572,  1574,  1583,  1584, 13617,
   13632,  1576,  1585, -1610, -1610, -1610, 11181,  1753,  1764, -1610,
    1234, 13647, 11181, 12604, 11518, -1610, -1610, 12604,  1240, -1610,
   11181, 13662, 13684,  1598, 12604, 11181, 11181, 11181, 12604, 11181,
   11181, 11181, 11181, 11181, 11181, 11181, 11181,  1609,  1615, 11181,
    1243, 11181,  1244, 11181,  1617, 12604, 12604, 12604,  1621,  1254,
   12604, 12604, 11181,  1631, 12604,  1633, 11181,  1257, 12604, 13704,
     663,   663, 12604, 12604, 11181, 12604, 11181,  1634, 12604,  1636,
   12604,  1638, 11181,  1639,  1640,  1641, 11181, 11181, 11181,  1642,
   12604, 11181, 11181,  1643, 12604, 11181, 12604, 12604, 11181,  1644,
   12604, 11181,  1260, 11181, 12604, 11181,  1646, 12604,  1261, 11181,
    1264, 11181,  1268, 12604,  1270, 12604,  1278, 12604, 12604, 12604,
   13719, -1610, 11181, 11181, 11181, -1610, -1610,   268, 11518,   268,
   11518, 13738, 13849, 12958, 11181, 11181, 11181, -1610, -1610, -1610,
   -1610, -1610, 11181, 11181, -1610, 11181, 11181, 11181, -1610, 12604,
   -1610, 12493, -1610, 12604,  1647,  1648, -1610, -1610, 11181, 11181,
   11181, 11181, 12604, -1610, 12604, 11181, 11181, 11181,   663, 11181,
   12604,   695, -1610,  1281,  1287, -1610, -1610, -1610, -1610, -1610,
   11181, -1610, -1610, 11181, -1610, -1610, -1610, -1610, -1610, -1610,
   -1610, -1610, -1610, -1610, -1610, 11181, -1610, -1610, 11181, 11181,
   11181, -1610, 11181, 11181, -1610, 12604, -1610, -1610, -1610, -1610,
   -1610, 11181, -1610, -1610, -1610, -1610, -1610, -1610, -1610, -1610,
   -1610, -1610, -1610, 12604, 12604, 12604, 12604, -1610, -1610, -1610,
   -1610, -1610, 12604, -1610, -1610, -1610, -1610, -1610, -1610, 11181,
   -1610, 11181, 11181, 11181,  1898, 12604, -1610,  1898, 12604, -1610,
   12604, -1610, -1610,   920,   895, 11181,    44, 11518, -1610,  1654,
   -1610,  1656,  1655,  1663, -1610,  1665,  1667, -1610, -1610, -1610,
     883, 12958, -1610, -1610, -1610, 11181, 13871, 12604,  1852, -1610,
   12604,   663,   268,   589, 13906, 11181,    81,  1022,  1022,  2889,
    1671,  1674, -1610,  1678, -1610, -1610, -1610, -1610, 11181, 11181,
   -1610, -1610, 13925,  4491,  4491, 12604, 12604,  1679,  1288,   663,
   12604, -1610, 11181, 11181, 12604,   663,  1680, 13940,     3,  1304,
    1681,     3,   268, 13955, 13970, 13985,     3,  1682, 14000, 12604,
   12604, 11518, 12604, 11518, 12604,   268, 11518, 12604,  1311,   663,
     663, 12604, 12604,  1314,  1315,   525, 11518, 12604,  1317, 12604,
   11518, 12604,  1318, 12604,  1324,  1333, 11518,   663, 11518, 12604,
    1334, 12604,  1335, 12604, 11518, 12604, 12604, 12604,   268, 14015,
     268, 11518, 11518, 12604,   663, 11518, 11518, 12604,  1336,   657,
   11518,   663,   663, 11518, 12604,  1342, 14036, 11181, 11518,  1343,
   11518, 12604,   663, 12604, 14058, 12604,   737, 14073, 12604,  1344,
   12604,  1351, 12604,   663,  1352,  1355, 12604,  1684,  2927,  2942,
     649, 12604, 12604, -1610, 11518,     3, -1610,  1683,  3022,  3037,
    3299,  3322,  3339,   696,  1685,   278,   663, -1610, -1610,  3354,
    3442,  1686,    45,  1373,   663, 11518, 11518, 11518, 14093,   663,
   -1610, 12604, 12604,  3848,  3867,  3888,  4766,  5018,   672,  5270,
    6757,   442,  7004,   697,  1375,   527,   528,   699,  7251, 14202,
   14223,  7745,   -87,   707,    68,   708,   709,    60, -1610, -1610,
   -1610,    86,    86, -1610, -1610, -1610, -1610, 11181,  1892,  1904,
    1902,  7992, 11181,   731,  1699,   593, -1610, 11181, 14260, 12604,
    1895, -1610, -1610, -1610, -1610, -1610, -1610,  1702,  1703, 11518,
   11518, 12604, -1610, -1610,   663,   663, 12604, 12604,  1387, 14280,
   11518,  1388, 12604, 12604, 11181, 12604, 12604, 11181, 11181, 11181,
   11181, 11181, 11181, 12604,   663,  1389,  1390,  1400,  1401, 11181,
    1402,  1403, 12604, 11181, 11181,  1409, 12604,  1416,  1420, 11181,
     663, 11181, 11181,  1423, 12604,  1426, 11181,  1439,  1442,  1445,
    1446, 12604,  1452,  1454, 11181, 12604,  1455, 11181, 11181, 11518,
   11181,  1465,  1466, 11181,   663, 12604, 12604,  1481, 11181,  1496,
   12604,  1500, 12604, 12604,   663, -1610,  1880,  1884, 11181,  1885,
    1502,   663, 11181,  1085, -1610, -1610, -1610, -1610, -1610, -1610,
   -1610, 12604, -1610, -1610, -1610, -1610, 11181, 12604, 11181,   734,
     761, -1610, -1610, -1610, -1610, -1610, 11181, -1610, -1610, -1610,
   12604, -1610, -1610, -1610, 12604, 11181, -1610, 11181, -1610, -1610,
   -1610, 12604, 11181, -1610, 12604, -1610, -1610, 12604, -1610, -1610,
   -1610, 11181, -1610, -1610, -1610, -1610, -1610,  1914,  1103,  8239,
    1905, 11181, 12604,  8486, 11181,   762,  1712,  1487,  1022,  1713,
    1714,  1022, -1610, -1610,   663,  1503,   663, 12604, 12604, 12604,
     663,   663,  1718,   663,   663,     3, 14295, 14310, 14325,     3,
   14340,  1504, 12604, 11181, 11181, 12604, 14355, 11181, 12604,   663,
   14370, 11518, 12604,  1511, 12604, 11181, 14389, 14410,   268, 11518,
   12604,   663, 12604, 14425, 11181, 11181, 12604, 12604,   663, 11181,
   12604,   794, 11518,   663, 11181, 14447, 14557, 14576, 11181, 12604,
   14612,  1514,   663, 12604,   816, 14634, 12604,  1515, 12604,  1518,
     663, 12604, 12604,  8733, 12604, 11181, -1610,  1719,  1720,   123,
   -1610,   764, 14649,   663, 11518, -1610, -1610,  8980,   765,   766,
    9227,  9474,   775,  9721,   791,   807,    78, 12958, 13390, 11181,
    1919, -1610,  1721, -1610,  1724, 14664,   810,  1117,  9968,  1913,
   11181,  1022, -1610, -1610, -1610, -1610, 12604,   663,   663,   663,
   12604, 11181, 11181, 12604, 11181, 11181, 11181, 12604,  1533, 14679,
   14694,  1534, 11181, 14709,  1535, 11181,  1536, 11181,  1542, 14724,
   11181, 11181,  1545,  1548, 11181, 14744, 14763,   663,   663, 14778,
    1555, 11181, 14799, 11181, 11181, 11181, 14911,  1559, 11181, 12604,
     663, 12604, 12604,  1561, 11181,  1577, 12604,   663,   663,  1903,
     663, 11518,  1726,  1727,  1085, -1610, -1610, 11181, -1610, -1610,
   -1610, -1610, -1610, -1610, -1610, -1610, -1610, 11181, -1610,  1902,
    1946,   604, 12958, -1610, 12604, 11181, 11181, -1610, -1610,  1732,
    1487, -1610,  1733,  1487, 14931, -1610,   663,   663,  1736, 14965,
     663, 14986,  1737, 15001,  1580, 12604, 12604, 12604, 12604, 15016,
   12604, 12604, 15031, 11181, 11518, 12604, 11181, 11518, 15046, 12604,
   11181, 11518, 11181, 12604, 12604, 12604, 11518, 12604, 15061, 15076,
   15098, 12604, 12604, 11518,   663,  1604,   663, 12604,   841, 15118,
   12604,   663, 12604, -1610, -1610, -1610, 12958, 10215, 11518, 12958,
   -1610, -1610,  1902,  1258,   608, 15133, 10462,  1487, 12604,  1022,
    1487, 11181,  1022, 11181, 12604, 12604, 11181, 12604, 12604, 12604,
     663,   663,   663,  1612, 11181,   663,   663, 11181, 15152,  1613,
   15263, 11181,   663, 15285, 15320,   663,   663,   663,   663, 11181,
   12604, 11181,  1616,   663, 12604,   663, 12604, 12604,  1628,   663,
      48, -1610,  1902, 12958, -1610, -1610, -1610, -1610, -1610, -1610,
   -1610, 12604, -1610, 11181, -1610,  1022,   653, -1610,  1022, 15339,
   -1610, 10709,   663,   663, 15354,   663,   663,   663, 12604, 11518,
   11518, 11181, 12604, 11181, 11518, 12604, 12604, 11518,   663, 15369,
   12604,   663,  1629,   663, 12604, -1610, -1610, -1610,  1321,  1902,
     822, 10956, -1610, 12604, -1610, -1610, 11181, -1610, 12604,   663,
   15384,   663, 15399,   663,   663, 11181,   663, 12604,   663, -1610,
   -1610, -1610, -1610, -1610, -1610,  1986,  1914, -1610, -1610,   824,
    1487, 11203,  1487,   663, 12604, 12604, 15414,   663, -1610, -1610,
   -1610, -1610,  1022, -1610,  1022,  1630,   663, 12604,  1487, -1610,
    1487, -1610, 12604,   663,  1022,  1022,   663, -1610, -1610
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   237,     0,     0,     0,   483,     0,     0,     0,   231,
     506,   541,   546,    18,     0,     0,     0,     0,    31,    33,
     484,     0,   468,   468,     0,   485,    25,    27,   521,   533,
       0,   630,    55,    67,     0,   228,   229,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   238,
     239,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,     0,     0,     0,     0,
       0,     2,     9,    17,     8,     0,    12,    46,    48,    14,
      29,    30,    28,     0,    20,    21,    24,    23,    22,    35,
      36,   456,   344,   259,   457,   458,   459,   262,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     307,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,     0,     0,     0,     0,     0,     0,     0,   404,   407,
     410,   413,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   290,   292,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   260,     0,   358,   338,   343,
     261,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,   468,     0,   468,     0,     0,    16,
     461,   460,    37,    38,    45,     0,     0,     0,     0,    19,
      50,   470,    51,    49,   486,    26,     0,    16,   565,     0,
     634,     0,     0,   594,   626,    69,    68,     0,     0,    70,
     230,    60,     0,    62,     0,   586,   588,    63,   584,   590,
       0,     0,   591,   453,    64,    66,     0,   215,     0,     0,
     645,     0,    92,   217,    86,    47,     0,     0,     0,     0,
       0,     0,    74,     0,    57,    79,     0,     0,    94,    93,
       0,     0,   240,   241,   218,    13,    15,   232,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,     0,     0,     7,
       0,     0,     0,     0,     0,     0,   475,   468,   468,     0,
       0,   328,     0,     0,     0,     0,     0,     0,     0,   434,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   306,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   468,   468,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   350,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,   326,   324,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     6,   322,     0,   242,     0,     0,   542,     9,    39,
      40,    41,    43,   489,   490,    32,   487,   495,   496,    34,
     493,   473,   474,   469,   471,   526,   525,     0,     9,     0,
      16,     0,     0,     0,   631,   632,     0,   597,   599,    52,
       0,     0,     0,     0,    56,   628,   468,   468,     0,     0,
       0,   468,   468,     0,   455,   454,     0,     0,   216,   644,
       0,     0,     0,     0,    96,    73,     0,     0,    78,   626,
     249,   248,     0,     0,     0,    75,     0,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,     0,     0,     0,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   168,     0,     0,   169,
       0,     0,   174,     0,     0,     0,     0,   183,     0,     0,
     186,     0,     0,     0,     0,     0,   193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   208,     0,     0,     0,   213,     0,   257,
       0,     0,     0,   221,     0,     0,     0,     0,     0,     0,
      10,     0,     0,     0,   323,   247,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     295,   297,   296,   298,   449,     0,   448,   438,   437,     0,
     440,   439,     0,   442,   441,     0,   445,     0,   443,     0,
     303,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   384,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   274,     0,     0,     0,
       0,     0,     0,     0,     0,   405,     0,   408,     0,   411,
       0,   414,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   291,   293,     0,     0,     0,
       0,     0,     0,     0,   264,   359,   353,   355,   357,   354,
     356,   351,   352,   263,     0,     0,   331,   333,   335,   332,
     334,   329,   330,   349,   346,   345,   347,   348,   466,   467,
     507,    16,   553,   551,     0,   552,   548,   550,   547,     0,
       0,   468,   468,     0,   468,   468,     0,     0,   523,   527,
     540,   538,   539,   536,   535,   537,   534,   555,     9,     0,
       0,     0,     0,     0,   595,    53,    54,     0,     0,     0,
     602,   604,     0,   629,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   585,   592,   593,     0,     0,     0,   252,
     251,   255,     0,     0,   362,    58,    76,     0,    89,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   148,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   468,     0,     0,     0,   222,   223,   224,   225,   226,
     227,     0,     0,    16,     0,     0,     0,   481,   482,   476,
     426,   318,     0,     0,   417,     0,     0,     0,   427,     0,
     428,     0,   421,     0,     0,     0,   339,   340,     0,     0,
       0,     0,     0,   452,     0,     0,     0,     0,   444,     0,
       0,     0,   304,     0,     0,   363,   364,   365,   366,   367,
       0,   368,   370,     0,   371,   373,   374,   336,   380,   381,
     375,   377,   378,   379,   376,     0,   383,   388,     0,     0,
       0,   387,     0,     0,   272,     0,   269,   275,   276,   389,
     316,     0,   390,   317,   277,   278,   403,   406,   409,   412,
     281,   279,   280,     0,     0,     0,     0,   284,   396,   285,
     402,   401,     0,   294,   397,   286,   398,   287,   400,     0,
     288,     0,     0,     0,     0,     0,   311,     0,     0,   313,
       0,   433,   321,   327,   325,     0,     9,   549,   646,    42,
     648,    44,     0,     0,   488,     0,     0,   494,   472,   524,
     530,    16,   567,   568,   566,     0,     0,     0,   635,   633,
       0,   600,   598,   599,     0,     0,     0,     0,     0,     0,
     580,   582,   627,   577,   462,   464,   468,   468,     0,     0,
     587,   589,    71,     0,     0,     0,     0,     0,     0,   121,
       0,    77,     0,     0,     0,   102,     0,     0,     0,     0,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,   117,     0,   119,     0,   124,   125,     0,     0,   129,
     128,     0,     0,     0,     0,     0,   137,     0,     0,     0,
     144,     0,     0,     0,     0,     0,   151,   150,   152,     0,
       0,     0,     0,     0,   159,     0,     0,     0,   163,     0,
     165,   166,   167,     0,   171,   173,   172,     0,   176,   179,
     180,   184,   185,   182,     0,     0,     0,     0,   190,     0,
     192,     0,   196,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   210,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    87,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   435,   360,   361,     0,
       0,     0,     0,   450,   447,   299,   300,   301,     0,   446,
     305,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   545,   544,
     543,     0,     0,   491,   492,   497,   498,     0,     0,     0,
     556,     0,     0,     0,     0,     0,   596,     0,     0,     0,
     616,   603,   605,   606,   468,   468,   578,     0,     0,    59,
      61,     0,   253,   254,   250,   256,     0,     0,    90,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   191,
       0,     0,     0,     0,   197,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   211,   258,     0,     0,     0,     0,
     235,   236,     0,   499,   415,   416,   418,   419,   420,   429,
     430,     0,   431,   341,   342,   314,     0,     0,     0,     0,
       0,   369,   372,   382,   265,   266,     0,   268,   385,   386,
       0,   270,   391,   282,     0,     0,   392,     0,   394,   309,
     289,     0,     0,   320,     0,   423,   310,     0,   425,   312,
     337,     0,   647,   649,   528,   531,   522,   571,   637,     0,
     636,     0,     0,     0,     0,     0,     0,   628,     0,     0,
       0,     0,   463,   465,    72,     0,    97,     0,     0,     0,
     103,   106,     0,   101,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   134,
       0,   135,     0,     0,     0,     0,   139,     0,   145,   146,
       0,   154,     0,   156,     0,     0,     0,     0,   164,     0,
       0,     0,   178,   181,     0,     0,     0,     0,     0,     0,
       0,     0,   200,     0,     0,     0,     0,     0,     0,     0,
     212,     0,     0,     0,     0,     0,    88,   502,   503,     0,
     500,     0,     0,   451,   302,   436,   308,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   517,    16,   237,     0,
     569,   641,     0,   638,     0,     0,     0,   608,     0,   618,
       0,     0,   607,   581,   583,   579,     0,   120,    82,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   160,   161,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     199,     0,     0,     0,     0,     0,     0,   245,   246,     0,
     244,   234,     0,     0,     0,   477,   432,     0,   267,   271,
     283,   393,   395,   399,   319,   422,   424,     0,   508,   529,
       9,   575,    16,   557,     0,     0,     0,   601,   620,     0,
     628,   610,     0,   628,     0,   617,    95,   110,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,     0,     0,   140,     0,     0,
       0,   157,     0,     0,     0,     0,   177,     0,     0,     0,
       0,     0,     0,   198,   201,     0,   203,     0,     0,     0,
       0,   209,     0,   504,   505,   501,    16,     0,   518,    16,
     576,   572,   570,     0,     0,     0,     0,   628,     0,     0,
     628,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   118,     0,     0,   127,   122,     0,     0,     0,
       0,     0,   149,     0,     0,   158,   162,   170,   175,     0,
       0,     0,     0,   195,     0,   202,     0,     0,     0,   243,
       9,   315,   509,    16,   564,   561,   562,   563,   559,   560,
     558,     0,   642,     0,   639,     0,     0,   609,     0,     0,
     619,     0,   109,   100,     0,   111,   105,   214,     0,   131,
     136,     0,     0,     0,   147,     0,     0,   194,   189,     0,
       0,   204,     0,   207,     0,   480,   479,   478,     0,   573,
       0,     0,   621,     0,   622,   611,     0,   612,     0,   123,
       0,   141,     0,   153,   155,     0,   187,     0,   205,   512,
     514,   515,   516,   511,   513,   519,   571,   643,   640,     0,
     628,     0,   628,   108,     0,     0,     0,   206,   520,   510,
     574,   624,     0,   614,     0,   132,   143,     0,   628,   623,
     628,   613,     0,   188,     0,     0,   133,   625,   615
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1610, -1610, -1610,  -211, -1610, -1610,  1992,   874, -1610, -1610,
   -1610, -1610, -1610, -1610, -1610,  1949,  1236, -1610, -1610,  -382,
      -3, -1610,  1950,  1693, -1610, -1610,  1538,  -464,  2999, -1610,
    1348,   -39,   -12, -1610,     1,     8,   197, -1610, -1610,  1040,
    2001, -1610, -1610, -1610, -1610, -1610, -1610, -1610,  1045, -1610,
    1044, -1610,   198, -1610, -1610, -1610, -1610, -1610, -1610, -1610,
   -1610, -1610, -1610, -1610,   544, -1610, -1610, -1610, -1610, -1610,
   -1610, -1610, -1610, -1610, -1610, -1610, -1610, -1610, -1610, -1610,
   -1610, -1610, -1610, -1610, -1610, -1610, -1610, -1610, -1610,   -13,
   -1610, -1610, -1610, -1171, -1610, -1610, -1610,  1362, -1610, -1610,
     743,  1354, -1610, -1610, -1610, -1610, -1610, -1610, -1610, -1610,
   -1610, -1610, -1610, -1610, -1610, -1609, -1610,     2, -1610, -1610
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,   101,   102,   450,  1123,   103,   104,   267,   268,
     959,   960,   284,   669,   105,   106,   672,   107,   108,   780,
     234,   235,   109,   321,   935,   934,   812,   813,   322,   237,
     302,   238,   262,   289,   239,   240,   270,   271,   623,   624,
     112,   796,  1407,  1896,  1997,  1129,   113,   615,   616,   619,
     620,  1719,  1720,   114,   257,  1245,  1899,  1998,  2025,  1828,
    2039,   115,   276,   969,   627,  1260,  1737,  1469,  1738,   116,
     277,   976,   117,   258,   951,  1460,   118,   259,   958,   119,
     629,  1261,  1627,  1903,  1960,   120,   630,  1264,  1833,  1740,
    1953,  2026,  1901,  1282,  1641,  1283,   297,   298,   304,   639,
     984,   644,  1277,  1278,  1638,  1840,  1910,  2032,  2050,  1637,
    1843,  1907,  2030,  2048,   645,   994,   283,   311,  1249,  1251
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     247,   303,   110,   263,   264,   249,   670,   815,   634,   111,
     990,   635,   250,   991,   599,   670,     7,     8,   269,   253,
     121,   273,     7,     8,   124,   125,   126,   299,  1751,   305,
     285,   593,   383,   252,   291,   293,   476,   255,   279,   309,
     280,   281,   274,   483,   484,   315,   316,   640,   608,   641,
     642,   337,   338,   339,   249,   333,   582,   670,   781,   782,
    1458,   250,   434,   924,   468,   469,   628,   380,   381,   382,
     121,   478,  1621,  1995,   124,   125,   126,  1004,   435,   477,
     317,   318,   384,   428,   430,   432,   485,   319,  1459,   275,
     260,  1827,  1996,   261,   444,   446,   447,   448,   660,   445,
     593,   589,   590,   591,   592,   593,  1481,  1482,   584,   585,
     320,  1235,    53,  1236,   479,   586,   587,   588,   589,   590,
     591,   592,   593,   584,   585,   611,   612,   486,   487,   340,
     586,   587,   588,   589,   590,   591,   592,   593,    20,   582,
     582,   584,   585,    25,   489,   490,  1116,  1153,   586,   587,
     588,   589,   590,   591,   592,   593,   433,   575,   576,   577,
     578,   579,   580,   581,  1238,  1614,  1239,  1615,   584,   585,
     488,   451,   452,   492,   493,   586,   587,   588,   589,   590,
     591,   592,   593,   453,   918,   439,   920,   491,   440,   575,
     576,   577,   578,   579,   580,   581,   500,   254,   441,    92,
      93,    94,   596,   597,   442,    92,    93,    94,   575,   576,
     577,   578,   579,   580,   581,   256,   494,   582,   443,   328,
     272,   449,   575,   576,   577,   578,   579,   580,   581,   582,
     573,  1909,   582,   582,  1912,   282,  1162,   719,  1201,   501,
    1202,   582,   454,   598,   643,   455,   671,   582,   456,   329,
     330,   331,   604,   474,  1187,   671,   332,   636,   582,   992,
     110,   654,   655,   300,   301,  1191,   254,   111,   621,   594,
     595,   596,   597,   625,   594,   595,   596,   597,   110,   256,
     637,   582,   582,   582,   457,   111,  1222,  1229,  1223,  1230,
    1199,   594,   595,   596,   597,   458,   582,   671,  1965,   287,
     288,  1968,   480,  1204,   658,   582,   594,   595,   596,   597,
    1267,   582,  1268,   300,   301,   664,   665,   666,  1205,   459,
    1617,   481,  1618,   673,   594,   595,   596,   597,   582,   590,
     591,   592,   593,  1479,   582,  1480,   295,   296,   575,   576,
     577,   578,   579,   580,   581,   582,   688,   689,   460,   582,
     720,   594,   595,   596,   597,   697,  1206,   699,   482,   701,
     702,   462,   704,   705,   706,   707,   582,   463,   710,   711,
     712,  1139,   714,  1140,   716,  1814,   718,  1815,   609,   610,
     722,   723,   724,   725,   726,   582,   728,   464,   730,   465,
     732,   495,   924,   466,   736,   737,   738,   739,   740,   582,
     742,   743,   744,   745,   786,   747,   748,   749,   750,   751,
     752,   753,   467,   755,   756,   757,   759,   760,   761,   978,
     763,  2042,   765,  2044,   767,   470,   769,   471,   771,   472,
     773,   774,   775,   776,   777,   582,   584,   585,   473,  2054,
     785,  2055,  1207,   586,   587,   588,   589,   590,   591,   592,
     593,   603,   795,   605,   475,   575,   576,   577,   578,   579,
     580,   581,   496,   806,   497,   809,   498,  1752,   807,   808,
    1755,   818,   819,   820,   821,   822,   823,   824,   825,   826,
     827,   828,   829,   830,   831,   832,   833,   834,   835,   836,
     838,   839,   840,   841,   613,   614,   843,   499,   582,   584,
     585,   594,   595,   596,   597,  1208,   586,   587,   588,   589,
     590,   591,   592,   593,   856,   582,   502,   582,   503,   867,
     868,   869,   870,   871,  1209,   582,   874,   617,   618,   879,
    1581,   881,  1582,   883,   884,   886,   888,   890,   892,   893,
     894,   895,   504,   897,   898,   899,   900,   901,   902,   903,
     905,   810,   811,   908,   904,   910,   911,   912,   913,   914,
     582,   505,   917,   582,   919,   721,   921,   922,   923,   485,
    1210,   506,   926,   927,   928,   929,   930,   931,   932,   933,
    1845,   582,   507,   583,   985,   986,   768,   575,   576,   577,
     578,   579,   580,   581,   508,   575,   576,   577,   578,   579,
     580,   581,   584,   585,     1,     2,     3,     4,     5,   586,
     587,   588,   589,   590,   591,   592,   593,   303,  -554,   594,
     595,   596,   597,   582,   582,  1170,   582,  1171,   770,   772,
     981,   110,   582,  1211,   582,   584,   585,   509,   111,  1194,
     983,  1212,   586,   587,   588,   589,   590,   591,   592,   593,
    1900,   582,   584,   585,   797,   798,   788,   488,  1010,   586,
     587,   588,   589,   590,   591,   592,   593,   584,   585,   997,
     998,  1018,  1007,  1008,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   592,   593,  1173,   582,
    1174,   584,   585,   510,  1600,  1040,  1601,  1042,   586,   587,
     588,   589,   590,   591,   592,   593,  1049,   511,   582,   582,
    1127,  1128,   584,   585,  1057,  1217,  1218,  1060,  1061,   586,
     587,   588,   589,   590,   591,   592,   593,   575,   576,   577,
     578,   579,   580,   581,   582,   584,   585,   512,  1967,   789,
    1246,  1970,   586,   587,   588,   589,   590,   591,   592,   593,
     513,   906,   907,   514,   587,  1092,   589,   590,   591,   592,
     593,  1098,   515,  1100,   582,  1102,   516,  1104,   517,  1106,
    1452,  1220,   582,  1454,   582,   582,   491,  1524,   494,  1605,
    1607,  1606,  1608,  1117,  1119,   594,   595,   596,   597,   582,
     582,   584,   585,   518,  2002,  1013,  1219,  2005,   586,   587,
     588,   589,   590,   591,   592,   593,   519,   575,   576,   577,
     578,   579,   580,   581,   520,   584,   585,   521,   594,   595,
     596,   597,   586,   587,   588,   589,   590,   591,   592,   593,
     522,   591,   592,   593,  1158,   594,   595,   596,   597,  1161,
     582,  1163,  1164,   995,   996,  1632,   501,   924,  1001,  1002,
     594,   595,   596,   597,   582,   582,   594,   595,   596,   597,
    1961,  1226,  1962,   606,   575,   576,   577,   578,   579,   580,
     581,  2049,   582,  2051,   594,   595,   596,   597,   582,  1228,
    1195,   600,  1196,  2057,  2058,  1241,   575,   576,   577,   578,
     579,   580,   581,  1262,  1263,   594,   595,   596,   597,   582,
     582,  1568,   601,  1569,   582,  2003,  1242,  2004,   523,  1545,
     582,   575,   576,   577,   578,   579,   580,   581,   594,   595,
     596,   597,  1467,  1468,  1596,   648,  1597,   584,   585,   594,
     595,   596,   597,   524,   586,   587,   588,   589,   590,   591,
     592,   593,   582,   582,   582,   525,   582,  1248,  1250,  1430,
    1579,  1603,   110,  1609,   582,   582,   582,   526,   584,   111,
     632,  1616,  1619,  1620,   621,   586,   587,   588,   589,   590,
     591,   592,   593,   527,   594,   595,   596,   597,   582,   528,
    1271,   582,   925,  1272,   582,  1630,  1276,   653,  1725,  1555,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   594,   595,   596,   597,  1115,   529,   582,   582,
    1298,   582,   582,   582,  1299,  1726,  1749,   779,  1816,  1819,
    1820,  1305,   582,   584,   585,  1309,  1280,  1281,  1312,  1823,
     586,   587,   588,   589,   590,   591,   592,   593,   582,   530,
    1325,   582,  1328,  1329,  1330,  1825,  1791,  1333,  1334,  1335,
    1470,  1338,   531,   582,   582,  1342,   532,   582,  1017,  1344,
    1345,  1826,  1347,   582,  1837,  1350,   533,  1352,  1801,   582,
     582,   582,   534,  1358,  1360,  1031,  2027,  1364,  2041,   535,
     582,  1368,  1369,  1371,  1372,  1039,   656,  1375,   582,  1717,
    1718,  1379,   536,  1946,  1382,   952,   582,   953,  1386,   954,
    1389,  1041,  1391,   121,  1393,  1394,  1395,   124,   125,   126,
     594,   595,   596,   597,   582,   582,   582,   661,  1134,  1043,
    1045,  1046,   955,   582,   110,   956,   537,   582,  1047,   582,
     957,   111,  1050,   662,  1051,   593,  1413,   538,  1415,   539,
    1416,   594,   595,   596,   597,   582,   540,   582,   582,  1423,
    1052,  1424,  1054,  1056,   790,   582,   541,  1429,  1252,  1253,
    1058,  1255,  1256,  1741,  1742,   582,   594,   595,   596,   597,
    1062,   582,   584,   585,   542,   543,  1063,  1838,  1839,   586,
     587,   588,   589,   590,   591,   592,   593,   544,   582,   582,
     584,   585,  1441,  1064,  1065,   968,   545,   586,   587,   588,
     589,   590,   591,   592,   593,   546,   594,   595,   596,   597,
    1443,  1444,  1445,  1446,  1165,   582,   582,   584,   585,  1447,
    1066,  1068,   950,   547,   586,   587,   588,   589,   590,   591,
     592,   593,  1453,   584,   585,  1455,   548,  1456,   549,   550,
     586,   587,   588,   589,   590,   591,   592,   593,   582,   582,
     582,   582,   582,  1070,  1072,  1076,  1077,  1078,   674,   970,
     582,   971,   110,   972,  1473,  1080,   698,  1475,   582,   111,
     584,   585,  1954,  1081,  1955,   700,  1956,   586,   587,   588,
     589,   590,   591,   592,   593,   582,   973,   551,   552,   974,
    1082,   709,  1494,  1495,   975,  1492,  1493,  1498,   582,  1957,
     582,  1501,  1958,  1084,   582,  1085,   582,  1959,  1397,  1086,
     582,  1087,   717,   582,   553,  1088,  1514,  1515,  1090,  1516,
     582,  1517,   582,   554,  1518,  1091,   582,  1093,  1520,  1521,
     555,  1094,   915,   556,  1525,  2019,  1527,  2020,  1528,  2021,
    1530,   557,   582,   558,   582,   559,  1533,  1095,  1535,  1097,
    1537,   560,  1538,  1539,  1540,   594,   595,   596,   597,   561,
    1542,   582,  2022,  1166,  1543,  2023,  1099,   582,   562,   563,
    2024,  1546,  1101,   594,   595,   596,   597,   564,  1551,   582,
    1552,  1167,  1554,   582,  1103,  1557,   582,  1559,  1105,  1561,
     582,  1107,   582,  1564,   565,  1108,   764,  1109,  1570,  1571,
     594,   595,   596,   597,   582,   582,   582,   582,  1168,  1143,
    1152,  1154,  1155,   977,   566,   582,   594,   595,   596,   597,
    1156,   582,   582,   766,  1169,   582,  1157,  1159,  1589,  1590,
    1160,   582,   584,   585,   567,   568,  1188,   916,   569,   586,
     587,   588,   589,   590,   591,   592,   593,   582,   570,  1622,
    1623,   571,  1189,   594,   595,   596,   597,   582,   582,   631,
     582,  1172,  1190,  1214,   625,  1215,   582,   582,   582,   582,
     582,  1216,  1231,  1232,  1233,  1234,  1635,   582,   633,   646,
     582,   582,  1237,  1487,  1488,  1240,  1295,   582,  1644,   787,
     582,   582,  1300,  1645,  1646,  1322,  1324,   993,   963,  1650,
    1651,   582,  1653,  1654,   582,   647,  1332,   582,   582,  1341,
    1661,   582,  1377,  1383,   966,   582,  1385,   582,   651,  1669,
    1388,   948,  1390,  1673,   652,   582,  1829,  1830,   582,  1678,
    1392,  1681,   842,  1431,   582,   582,   584,   585,  1688,  1432,
    1497,  1691,  1693,   586,   587,   588,   589,   590,   591,   592,
     593,   582,  1701,  1702,   844,  1704,  1505,  1707,   582,  1709,
    1710,   582,   582,  1519,   582,   582,  1522,  1523,   967,  1526,
    1529,   582,   845,   961,   678,   679,  1531,   680,  1721,   949,
     582,   582,   582,   582,  1723,  1532,  1534,  1536,  1544,   582,
     582,   582,   695,   696,  1547,  1550,  1558,  1728,   582,   582,
     703,  1729,   582,  1560,  1562,   708,   962,  1563,  1732,   964,
     713,  1734,   715,   965,  1735,   594,   595,   596,   597,   980,
     582,  1902,   582,  1175,   727,  1587,   729,  1604,   731,  1746,
     733,   734,   735,   987,   582,   582,   582,   582,   741,  1647,
    1649,  1662,  1663,   746,  1757,  1758,  1759,   582,   582,   582,
     582,   754,  1664,  1665,  1667,  1668,   582,   988,   762,  1768,
     989,  1672,  1771,   582,  1024,  1774,  1026,   582,  1674,  1776,
     582,  1778,  1675,   582,  1028,  1680,  1032,  1782,  1682,  1783,
    1033,  1639,  1640,  1787,  1788,  1950,   582,  1790,  1952,   582,
    1111,  1684,   582,   582,  1685,   236,  1797,  1686,  1687,   582,
    1800,   582,   582,  1803,  1689,  1805,  1690,  1694,  1807,  1808,
     266,  1810,   582,   582,  1112,  1113,  1114,  1698,  1699,   594,
     595,   596,   597,   278,  1124,  1130,   286,  1176,   582,   290,
     292,   294,  1131,  1703,  1138,   310,   310,   310,   110,   110,
    1141,  1148,  1999,   582,   334,   111,   111,   582,  1706,   582,
     582,   582,  1708,  1846,  1715,  1756,  1767,  1847,   582,  1142,
    1850,   582,   582,  1777,  1854,   582,  1799,  1804,  1259,  1144,
    1806,  1146,   587,   588,   589,   590,   591,   592,   593,  1145,
     582,   582,   582,   582,   438,  1855,  1858,  1861,  1863,   582,
     310,  1147,   582,  1149,  1865,   582,  1884,  1869,  1885,  1886,
    1870,  1888,   582,  1891,  1177,  1221,   582,  1875,   582,   584,
     585,  1882,  1224,  1887,  1225,  1275,   586,   587,   588,   589,
     590,   591,   592,   593,   582,   461,  1284,   582,  1285,  1890,
    1290,  1904,  1919,   110,   584,   585,  1286,  1287,  1293,  1291,
     111,   586,   587,   588,   589,   590,   591,   592,   593,  1294,
    1304,   582,  1920,  1921,  1922,  1923,  1944,  1925,  1926,   582,
     582,  1319,  1929,   582,  1978,  1982,  1932,  1320,  1990,  1327,
    1935,  1936,  1937,  1331,  1938,   582,   582,   582,  1942,  1943,
    1994,  2017,  2052,  1337,  1945,  1339,  1349,  1948,  1351,  1949,
    1353,  1355,  1356,  1357,  1363,  1367,  1374,   110,  1381,  1012,
     110,  1417,  1418,   811,   111,  1966,  1461,   111,  1462,  1463,
    1474,  1972,  1973,  1020,  1975,  1976,  1977,  1464,  1025,  1465,
    1027,  1466,  1029,  1030,  1484,   572,   574,  1485,  1034,  1035,
    1486,  1496,  1502,  1506,  1512,  1625,  1573,  1988,  1565,  1580,
    1585,  1991,  1626,  1992,  1993,    -9,   602,   594,   595,   596,
     597,   607,  1631,  1636,   110,  1711,  1642,  1643,  2000,  1712,
    1714,   111,  1739,  1744,   622,  1750,  1832,  1753,  1754,   626,
    1760,  1842,  1812,  1813,  1834,  2009,   638,  1835,  1892,  2011,
    1893,  1894,  2013,  2014,  -532,  1908,  1911,  2016,  1914,  1917,
    2038,  2018,   594,   595,   596,   597,   248,  1403,   649,   657,
    2029,   659,   335,   336,  1005,  2033,   251,  1258,  1254,   814,
    1257,  1624,  1895,  2040,  2037,  1003,  1476,   594,   595,   596,
     597,     0,     0,  1015,     0,  1178,     0,     0,  1125,  1126,
       0,  2045,  2046,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2053,     0,     0,     0,   694,  2056,
     584,   585,  1150,     0,     0,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,     0,     0,     0,     0,   584,
     585,     0,     0,     0,     0,     0,   586,   587,   588,   589,
     590,   591,   592,   593,   584,   585,     0,     0,     0,     0,
       0,   586,   587,   588,   589,   590,   591,   592,   593,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   584,   585,
       0,     0,     0,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,     0,     0,     0,     0,     0,     0,   584,
     585,     0,     0,     0,     0,   784,   586,   587,   588,   589,
     590,   591,   592,   593,     0,     0,     0,   794,     0,     0,
       0,     0,   799,   800,     0,   801,   802,   803,   804,   310,
     310,     0,     0,     0,     0,     0,   817,   584,   585,     0,
       0,     0,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   846,   847,   848,   849,   850,
     851,   852,   853,   854,   855,   310,   857,   858,   859,   860,
     861,   862,   863,   864,   866,     0,     0,     0,     0,     0,
     872,   873,   875,   877,   878,   123,   880,     0,   882,     0,
     127,     0,     0,   594,   595,   596,   597,     0,   896,     0,
       0,  1179,     0,     0,     0,   310,     0,     0,     0,     0,
     909,   129,   594,   595,   596,   597,     0,     0,     0,     0,
    1180,     0,     0,     0,     0,     0,     0,   594,   595,   596,
     597,     0,     0,     0,     0,  1181,     0,     0,     0,   936,
     937,   938,   939,   940,   941,   942,   943,   944,   945,   946,
     947,   594,   595,   596,   597,     0,     0,     0,     0,  1182,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   594,   595,   596,   597,     0,     0,     0,     0,
    1183,     0,     0,     0,   979,   142,     0,   143,     0,   982,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   999,  1000,     0,     0,   146,   147,     0,     0,
     594,   595,   596,   597,     0,  1011,     0,     0,  1184,     0,
    1014,     0,     0,     0,   241,   242,   243,   244,   155,     0,
       0,  1021,  1022,     0,     0,   123,   157,     0,     0,   158,
     127,     0,   159,   160,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,     0,     0,     0,     0,     0,   183,   184,   185,
       0,     0,  1059,   189,   190,   191,     0,   193,     0,   195,
     196,   197,     0,     0,     0,     0,   202,   203,   204,   205,
     206,     0,     0,   209,     0,   211,     0,   213,     0,     0,
     215,     0,   217,     0,     0,   219,     0,     0,   221,   222,
       0,   223,   224,     0,   226,     0,   228,     0,     0,     0,
       0,     0,     0,     0,   231,     0,     0,     0,     0,     0,
       0,  1110,     0,   246,   885,   142,     0,   143,     0,  1118,
    1120,  1121,  1122,     0,     0,     0,     0,     0,     0,     0,
       0,   584,   585,     0,     0,     0,   146,   147,   586,   587,
     588,   589,   590,   591,   592,   593,     0,     0,     0,     0,
       0,     0,     0,     0,   241,   242,   243,   244,   155,     0,
       0,     0,     0,     0,     0,     0,   157,     0,     0,   158,
       0,     0,   159,   160,   245,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1504,     0,     0,  1507,     0,     0,
       0,     0,  1511,     0,     0,     0,     0,   183,   184,   185,
       0,     0,     0,   189,   190,   191,     0,   193,     0,   195,
     196,   197,     0,     0,     0,     0,   202,   203,   204,   205,
     206,     0,     0,   209,     0,   211,     0,   213,     0,     0,
     215,     0,   217,     0,     0,   219,     0,     0,   221,   222,
       0,   223,   224,     0,   226,     0,   228,     0,     0,     0,
       0,     0,     0,     0,   231,     0,     0,     0,     0,     0,
       0,     0,     0,   246,   887,   584,   585,  1243,  1244,     0,
       0,     0,   586,   587,   588,   589,   590,   591,   592,   593,
       0,  1572,     0,     0,     0,     0,     0,  1247,     0,     0,
       0,     0,     0,     0,   584,   585,     0,     0,  1586,     0,
     622,   586,   587,   588,   589,   590,   591,   592,   593,     0,
       0,     0,     0,  1266,   594,   595,   596,   597,     0,  1273,
    1274,     0,  1186,     0,     0,  1279,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1292,
       0,     0,     0,     0,   584,   585,     0,     0,     0,     0,
       0,   586,   587,   588,   589,   590,   591,   592,   593,  1307,
       0,     0,     0,     0,  1313,  1314,  1315,     0,     0,  1318,
     584,   585,  1321,     0,  1323,     0,  1326,   586,   587,   588,
     589,   590,   591,   592,   593,  1336,     0,     0,     0,  1340,
       0,     0,     0,     0,     0,     0,     0,  1346,     0,  1348,
       0,     0,     0,     0,     0,  1354,     0,     0,     0,  1359,
    1361,  1362,     0,     0,  1365,  1366,     0,     0,  1370,     0,
       0,  1373,     0,     0,  1376,     0,  1378,     0,  1380,   584,
     585,     0,  1384,     0,  1387,     0,   586,   587,   588,   589,
     590,   591,   592,   593,     0,  1398,  1399,  1400,   594,   595,
     596,   597,     0,     0,     0,     0,  1197,  1404,     0,     0,
       0,     0,     0,     0,     0,  1408,  1409,     0,  1410,  1411,
    1412,     0,     0,     0,     0,     0,     0,   594,   595,   596,
     597,  1419,  1420,     0,  1422,  1198,   584,   585,  1425,  1426,
    1427,     0,  1428,   586,   587,   588,   589,   590,   591,   592,
     593,     0,     0,  1433,     0,     0,  1434,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1435,     0,
       0,  1436,  1437,  1438,     0,  1439,  1440,   594,   595,   596,
     597,  1761,     0,   650,  1442,  1765,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,   595,   596,   597,     0,     0,     0,
       0,  1200,  1448,     0,  1449,  1450,  1451,     0,     0,     0,
       0,     0,   584,   585,     0,     0,     0,     0,  1457,   586,
     587,   588,   589,   590,   591,   592,   593,     0,     0,     0,
       0,     0,   584,   585,     0,     0,     0,     0,  1471,   586,
     587,   588,   589,   590,   591,   592,   593,     0,  1478,     0,
       0,     0,   594,   595,   596,   597,     0,     0,     0,     0,
    1203,  1489,  1490,     0,     0,     0,   310,   310,     0,     0,
     584,   585,     0,     0,     0,  1499,  1500,   586,   587,   588,
     589,   590,   591,   592,   593,   584,   585,     0,     0,     0,
       0,     0,   586,   587,   588,   589,   590,   591,   592,   593,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   594,
     595,   596,   597,     0,     0,     0,     0,  1227,     0,     0,
       0,     0,     0,     0,     0,     0,   325,   327,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   341,     0,   356,
     357,   359,   361,   364,   369,   370,   374,   376,   378,     0,
    1549,     0,     0,   388,   390,   392,   394,   395,   396,   402,
     407,   415,   422,   424,   426,   584,   585,     0,     0,     0,
       0,     0,   586,   587,   588,   589,   590,   591,   592,   593,
     584,   585,     0,     0,     0,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,     0,
       0,     0,     0,  1269,     0,   342,   343,   344,   345,   346,
       0,     0,     0,     0,     0,   594,   595,   596,   597,   347,
       0,     0,     0,  1483,     0,   348,   349,     0,     0,     0,
       0,   350,   351,   352,   353,   354,     0,     0,     0,     0,
     626,     0,     0,     0,     0,  1629,     0,     0,     0,     0,
    1633,     0,     0,   594,   595,   596,   597,     0,     0,     0,
       0,  1566,     0,     0,     0,     0,     0,     0,   594,   595,
     596,   597,     0,     0,     0,     0,  1567,     0,     0,     0,
     355,  1656,  1657,  1658,     0,  1660,     0,     0,     0,     0,
       0,     0,  1666,     0,     0,     0,  1670,  1671,     0,     0,
       0,     0,  1676,     0,  1677,  1679,     0,     0,     0,  1683,
       0,     0,     0,     0,     0,     0,     0,  1692,     0,     0,
    1695,  1696,     0,  1697,     0,     0,  1700,     0,     0,     0,
       0,  1705,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1713,     0,     0,     0,     0,     0,     0,   594,   595,
     596,   597,     0,     0,     0,     0,  1574,     0,     0,  1722,
       0,  1724,     0,   594,   595,   596,   597,     0,     0,  1727,
       0,  1575,     0,     0,     0,     0,     0,     0,  1730,     0,
    1731,     0,     0,     0,     0,  1733,     0,     0,     0,     0,
       0,     0,     0,     0,  1736,     0,   663,     0,     0,     0,
       0,     0,   668,     0,  1745,     0,     0,  1748,     0,   675,
     677,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   681,   682,   683,   684,   685,   686,   687,     0,     0,
     690,   691,   692,   693,     0,     0,  1769,  1770,     0,     0,
    1773,     0,   584,   585,     0,     0,     0,     0,  1779,   586,
     587,   588,   589,   590,   591,   592,   593,  1785,  1786,     0,
       0,     0,  1789,     0,     0,   584,   585,  1792,     0,     0,
       0,  1796,   586,   587,   588,   589,   590,   591,   592,   593,
       0,     0,   584,   585,     0,     0,     0,     0,  1811,   586,
     587,   588,   589,   590,   591,   592,   593,   584,   585,     0,
       0,     0,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,  1831,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1844,     0,     0,     0,     0,     0,     0,
     791,   792,   793,     0,     0,  1849,     0,  1851,     0,  1853,
       0,     0,     0,     0,     0,  1859,     0,     0,  1862,     0,
    1864,   816,     0,  1867,  1868,     0,     0,  1871,     0,     0,
       0,     0,     0,     0,  1876,     0,  1878,  1879,  1880,     0,
       0,  1883,     0,     0,     0,     0,     0,  1889,     0,     0,
       0,     0,     0,     0,     0,   584,   585,     0,     0,     0,
    1897,     0,   586,   587,   588,   589,   590,   591,   592,   593,
    1898,     0,     0,     0,     0,     0,     0,     0,  1905,  1906,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,     0,
       0,     0,     0,  1576,     0,     0,  1928,     0,     0,  1930,
       0,     0,     0,  1933,     0,  1934,     0,     0,   594,   595,
     596,   597,     0,     0,     0,     0,  1577,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,     0,
       0,     0,     0,  1578,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,  1969,     0,  1971,     0,  1583,  1974,
       0,     0,     0,     0,     0,     0,     0,  1979,     0,     0,
    1980,     0,     0,     0,  1984,     0,     0,     0,     0,     0,
       0,     0,  1987,     0,  1989,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2001,     0,   121,   122,
     123,     0,   124,   125,   126,   127,     0,     0,     0,     0,
       0,  1016,     0,     0,  2010,  1019,  2012,     0,     0,  1023,
       0,     0,     0,     0,     0,   128,   129,     0,   594,   595,
     596,   597,     0,     0,  1037,  1038,  1584,     0,     0,  2031,
       0,     0,  1044,     0,     0,     0,     0,  1048,  2036,     0,
       0,     0,  1053,     0,  1055,     0,     0,     0,   130,   131,
     132,   133,   134,   135,   136,     0,  1067,     0,  1069,     0,
    1071,     0,  1073,  1074,  1075,     0,   137,     0,     0,   138,
    1079,     0,     0,     0,   312,  1083,     0,     0,     0,     0,
       0,     0,   313,  1089,     0,     0,   140,   141,     0,     0,
     142,  1096,   143,     0,     0,   314,     0,     0,     0,     0,
     144,     0,     0,     0,     0,     0,     0,   145,     0,     0,
       0,   146,   147,     0,     0,     0,     0,     0,     0,     0,
       0,   148,     0,   149,   150,     0,     0,     0,     0,   151,
     152,   153,   154,   155,   156,     0,     0,     0,     0,     0,
       0,   157,     0,     0,   158,     0,     0,   159,   160,   161,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,     0,   214,   215,   216,   217,     0,   218,
     219,     0,   220,   221,   222,     0,   223,   224,   225,   226,
     227,   228,   229,     0,     0,     0,     0,     0,   230,   231,
       0,   232,     0,     0,     0,     0,     0,     0,   233,     0,
     308,   584,   585,     0,     0,     0,     0,     0,   586,   587,
     588,   589,   590,   591,   592,   593,     0,     0,     0,     0,
     584,   585,     0,     0,     0,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,     0,     0,     0,     0,     0,
       0,   584,   585,     0,     0,     0,     0,     0,   586,   587,
     588,   589,   590,   591,   592,   593,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   121,   122,   123,
       0,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1297,     0,     0,   128,   129,     0,     0,     0,  1301,
       0,     0,     0,     0,  1306,     0,  1308,     0,  1310,  1311,
       0,     0,     0,  1316,  1317,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,   306,     0,     0,     0,     0,     0,     0,
       0,   307,     0,     0,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,   594,   595,   596,   597,     0,   144,
       0,     0,  1591,     0,     0,     0,   145,     0,     0,     0,
     146,   147,     0,   594,   595,   596,   597,     0,     0,     0,
     148,  1592,   149,   150,  1405,  1406,     0,     0,   151,   152,
     153,   154,   155,   156,   594,   595,   596,   597,     0,     0,
     157,     0,  1593,   158,     0,     0,   159,   160,   161,  1421,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,   214,   215,   216,   217,     0,   218,   219,
       0,   220,   221,   222,     0,   223,   224,   225,   226,   227,
     228,   229,     0,     0,     0,     0,     0,   230,   231,     0,
     232,     0,     0,     0,     0,     0,     0,   233,     0,   308,
     121,   122,   123,     0,   124,   125,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,   138,     0,     0,     0,     0,   139,     0,     0,     0,
       0,     0,     0,     0,   805,     0,     0,     0,   140,   141,
       0,     0,   142,     0,   143,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,   146,   147,     0,     0,     0,     0,     0,
       0,     0,     0,   148,     0,   149,   150,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   156,     0,     0,     0,
       0,     0,     0,   157,     0,     0,   158,     0,     0,   159,
     160,   161,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,     0,   214,   215,   216,   217,
       0,   218,   219,     0,   220,   221,   222,     0,   223,   224,
     225,   226,   227,   228,   229,     0,     0,     0,     0,     0,
     230,   231,     0,   232,     0,     0,     0,     0,     0,     0,
     233,     0,   308,     0,   121,   122,   123,     0,   124,   125,
     126,   127,     0,  1652,     0,     0,  1655,     0,     0,     0,
    1659,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1716,   137,     0,     0,   138,     0,     0,     0,     0,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   141,     0,     0,   142,     0,   143,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,   145,     0,     0,     0,   146,   147,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,   149,
     150,     0,     0,     0,     0,   151,   152,   153,   154,   155,
     156,     0,     0,     0,     0,     0,     0,   157,     0,     0,
     158,     0,     0,   159,   160,   161,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,     0,
     214,   215,   216,   217,     0,   218,   219,     0,   220,   221,
     222,     0,   223,   224,   225,   226,   227,   228,   229,     0,
       0,     0,     0,     0,   230,   231,     0,   232,     0,     0,
       0,     0,     0,     0,   233,     0,   308,   121,   122,   123,
       0,   124,   125,   126,   127,     0,     0,     0,     0,     0,
    1848,     0,     0,     0,  1852,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,   584,
     585,     0,     0,   139,     0,     0,   586,   587,   588,   589,
     590,   591,   592,   593,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
     148,     0,   149,   150,     0,     0,     0,     0,   151,   152,
     153,   154,   155,   156,     0,     0,     0,     0,     0,     0,
     157,     0,     0,   158,     0,     0,   159,   160,   161,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,   214,   215,   216,   217,     0,   218,   219,
       0,   220,   221,   222,     0,   223,   224,   225,   226,   227,
     228,   229,     0,     0,     0,     0,     0,   230,   231,     0,
     232,     0,     0,     0,     0,     0,     0,   233,   783,   121,
     122,   123,     0,   124,   125,   126,   127,     0,     0,     0,
       0,     0,   594,   595,   596,   597,     0,     0,     0,     0,
    1594,     0,     0,     0,     0,     0,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     138,   584,   585,     0,     0,   139,     0,     0,   586,   587,
     588,   589,   590,   591,   592,   593,     0,   140,   141,     0,
       0,   142,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,   148,     0,   149,   150,     0,     0,     0,     0,
     151,   152,   153,   154,   155,   156,     0,     0,     0,     0,
       0,     0,   157,     0,     0,   158,     0,     0,   159,   160,
     161,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,   214,   215,   216,   217,     0,
     218,   219,     0,   220,   221,   222,     0,   223,   224,   225,
     226,   227,   228,   229,     0,     0,     0,     0,     0,   230,
     231,     0,   232,     0,     0,     0,     0,     0,     0,   233,
     865,   121,   122,   123,     0,   124,   125,   126,   127,     0,
       0,     0,     0,     0,   594,   595,   596,   597,     0,     0,
       0,     0,  1595,     0,     0,     0,     0,     0,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,   138,   584,   585,     0,     0,   139,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,     0,   140,
     141,     0,     0,   142,     0,   143,     0,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,   148,     0,   149,   150,     0,     0,
       0,     0,   151,   152,   153,   154,   155,   156,     0,     0,
       0,     0,     0,     0,   157,     0,     0,   158,     0,     0,
     159,   160,   161,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,   214,   215,   216,
     217,     0,   218,   219,     0,   220,   221,   222,     0,   223,
     224,   225,   226,   227,   228,   229,     0,     0,     0,     0,
       0,   230,   231,     0,   232,     0,     0,     0,     0,     0,
       0,   233,   876,   121,   122,   123,     0,   124,   125,   126,
     127,     0,     0,     0,     0,     0,   594,   595,   596,   597,
       0,     0,     0,     0,  1598,     0,     0,     0,     0,     0,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,   138,     0,     0,     0,     0,   139,
       0,     0,     0,     0,     0,   408,     0,     0,     0,     0,
       0,   140,   141,     0,     0,   142,     0,   143,     0,     0,
       0,     0,     0,     0,     0,   144,     0,     0,     0,     0,
       0,     0,   145,     0,     0,     0,   146,   147,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,   149,   150,
       0,     0,   409,   410,   151,   152,   153,   154,   155,   156,
       0,   411,   412,   413,   414,     0,   157,     0,     0,   158,
       0,     0,   159,   160,   161,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,     0,   214,
     215,   216,   217,     0,   218,   219,     0,   220,   221,   222,
       0,   223,   224,   225,   226,   227,   228,   229,     0,     0,
       0,     0,     0,   230,   231,     0,   232,     0,     0,     0,
     121,   122,   123,   233,   124,   125,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   416,     0,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,   138,     0,     0,     0,     0,   139,     0,     0,     0,
       0,     0,   417,     0,     0,     0,     0,     0,   140,   141,
       0,     0,   142,     0,   143,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,   146,   147,     0,     0,     0,     0,     0,
       0,     0,     0,   148,     0,   149,   150,     0,     0,   418,
     419,   151,   152,   153,   154,   155,   156,   420,     0,     0,
       0,   421,     0,   157,     0,     0,   158,     0,     0,   159,
     160,   161,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,     0,   214,   215,   216,   217,
       0,   218,   219,     0,   220,   221,   222,     0,   223,   224,
     225,   226,   227,   228,   229,     0,     0,     0,     0,     0,
     230,   231,     0,   232,     0,     0,     0,   121,   122,   123,
     233,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     0,   397,
       0,     0,     0,     0,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
     148,     0,   149,   150,     0,     0,   398,   399,   151,   152,
     153,   154,   155,   156,     0,   400,     0,     0,   401,     0,
     157,     0,     0,   158,     0,     0,   159,   160,   161,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,   214,   215,   216,   217,     0,   218,   219,
       0,   220,   221,   222,     0,   223,   224,   225,   226,   227,
     228,   229,     0,     0,     0,     0,     0,   230,   231,     0,
     232,     0,     0,     0,   121,   122,   123,   233,   124,   125,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   365,     0,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,     0,     0,   138,     0,     0,     0,     0,
     139,     0,     0,     0,     0,     0,   366,     0,     0,     0,
       0,     0,   140,   141,     0,     0,   142,     0,   143,     0,
       0,     0,   367,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,   145,     0,     0,     0,   146,   147,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,   149,
     150,     0,     0,   368,     0,   151,   152,   153,   154,   155,
     156,     0,     0,     0,     0,     0,     0,   157,     0,     0,
     158,     0,     0,   159,   160,   161,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,     0,
     214,   215,   216,   217,     0,   218,   219,     0,   220,   221,
     222,     0,   223,   224,   225,   226,   227,   228,   229,     0,
       0,     0,     0,     0,   230,   231,     0,   232,     0,     0,
       0,   121,   122,   123,   233,   124,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,   138,     0,     0,     0,     0,   139,     0,     0,
       0,     0,     0,   403,     0,     0,     0,     0,     0,   140,
     141,     0,     0,   142,     0,   143,     0,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,   148,     0,   149,   150,     0,     0,
     404,   405,   151,   152,   153,   154,   155,   156,     0,     0,
       0,     0,   406,     0,   157,     0,     0,   158,     0,     0,
     159,   160,   161,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,   214,   215,   216,
     217,     0,   218,   219,     0,   220,   221,   222,     0,   223,
     224,   225,   226,   227,   228,   229,     0,     0,     0,     0,
       0,   230,   231,     0,   232,     0,     0,     0,   121,   122,
     123,   233,   124,   125,   126,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   371,     0,     0,
       0,     0,     0,     0,     0,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   372,     0,   130,   131,
     132,   133,   134,   135,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,   138,
     584,   585,     0,     0,   139,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,     0,   140,   141,     0,     0,
     142,     0,   143,     0,     0,     0,   373,     0,     0,     0,
     144,     0,     0,     0,     0,     0,     0,   145,     0,     0,
       0,   146,   147,     0,     0,     0,     0,     0,     0,     0,
       0,   148,     0,   149,   150,     0,     0,     0,     0,   151,
     152,   153,   154,   155,   156,     0,     0,     0,     0,     0,
       0,   157,     0,     0,   158,     0,     0,   159,   160,   161,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,     0,   214,   215,   216,   217,     0,   218,
     219,     0,   220,   221,   222,     0,   223,   224,   225,   226,
     227,   228,   229,     0,     0,     0,     0,     0,   230,   231,
       0,   232,     0,     0,     0,   121,   122,   123,   233,   124,
     125,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,   595,   596,   597,     0,     0,     0,
       0,  1599,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,     0,   138,   584,   585,     0,
       0,   139,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,     0,   140,   141,     0,     0,   142,     0,   143,
       0,     0,     0,   385,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,   148,     0,
     149,   150,     0,     0,   386,   387,   151,   152,   153,   154,
     155,   156,     0,     0,     0,     0,     0,     0,   157,     0,
       0,   158,     0,     0,   159,   160,   161,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,   214,   215,   216,   217,     0,   218,   219,     0,   220,
     221,   222,     0,   223,   224,   225,   226,   227,   228,   229,
       0,     0,     0,     0,     0,   230,   231,     0,   232,     0,
       0,     0,   121,   122,   123,   233,   124,   125,   126,   127,
       0,   323,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,     0,     0,     0,     0,  1602,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   324,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,   132,   133,   134,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,     0,     0,   138,   584,   585,     0,     0,   139,     0,
       0,   586,   587,   588,   589,   590,   591,   592,   593,     0,
     140,   141,     0,     0,   142,     0,   143,     0,     0,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,     0,
       0,   145,     0,     0,     0,   146,   147,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,   149,   150,     0,
       0,     0,     0,   151,   152,   153,   154,   155,   156,     0,
       0,     0,     0,     0,     0,   157,     0,     0,   158,     0,
       0,   159,   160,   161,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,     0,   214,   215,
     216,   217,     0,   218,   219,     0,   220,   221,   222,     0,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,   230,   231,     0,   232,     0,     0,     0,   121,
     122,   123,   233,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   594,   595,   596,
     597,     0,     0,     0,     0,  1610,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     138,     0,     0,     0,     0,   139,     0,     0,     0,     0,
       0,   362,     0,     0,     0,     0,     0,   140,   141,     0,
       0,   142,     0,   143,     0,     0,     0,   363,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,   148,     0,   149,   150,     0,     0,     0,     0,
     151,   152,   153,   154,   155,   156,     0,     0,     0,     0,
       0,     0,   157,     0,     0,   158,     0,     0,   159,   160,
     161,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,   214,   215,   216,   217,     0,
     218,   219,     0,   220,   221,   222,     0,   223,   224,   225,
     226,   227,   228,   229,     0,     0,     0,     0,     0,   230,
     231,     0,   232,     0,     0,     0,   121,   122,   123,   233,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   131,   132,   133,
     134,   135,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,     0,     0,   138,   584,   585,
       0,     0,   139,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,     0,   140,   141,     0,     0,   142,     0,
     143,     0,     0,     0,     0,   436,     0,     0,   144,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,   146,
     147,     0,     0,     0,     0,     0,     0,     0,     0,   148,
       0,   149,   150,     0,     0,     0,   437,   151,   152,   153,
     154,   155,   156,     0,     0,     0,     0,     0,     0,   157,
       0,     0,   158,     0,     0,   159,   160,   161,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,     0,   214,   215,   216,   217,     0,   218,   219,     0,
     220,   221,   222,     0,   223,   224,   225,   226,   227,   228,
     229,     0,     0,     0,     0,     0,   230,   231,     0,   232,
       0,     0,     0,   121,   122,   123,   233,   124,   125,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   594,   595,   596,   597,     0,     0,     0,     0,  1613,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,   138,   584,   585,     0,     0,   139,
       0,     0,   586,   587,   588,   589,   590,   591,   592,   593,
       0,   140,   141,     0,     0,   142,     0,   143,     0,     0,
       0,     0,   468,   469,     0,   144,     0,     0,     0,     0,
       0,     0,   145,     0,     0,     0,   146,   147,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,   149,   150,
       0,     0,     0,     0,   151,   152,   153,   154,   155,   156,
       0,     0,     0,     0,     0,     0,   157,     0,     0,   158,
       0,     0,   159,   160,   161,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,     0,   214,
     215,   216,   217,     0,   218,   219,     0,   220,   221,   222,
       0,   223,   224,   225,   226,   227,   228,   229,     0,     0,
       0,     0,     0,   230,   231,     0,   232,     0,     0,     0,
     121,   122,   123,   233,   124,   125,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   594,   595,
     596,   597,     0,     0,     0,     0,  1628,   128,   129,     0,
       0,   265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,   138,   584,   585,     0,     0,   139,     0,     0,   586,
     587,   588,   589,   590,   591,   592,   593,     0,   140,   141,
       0,     0,   142,     0,   143,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,   146,   147,     0,     0,     0,     0,     0,
       0,     0,     0,   148,     0,   149,   150,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   156,     0,     0,     0,
       0,     0,     0,   157,     0,     0,   158,     0,     0,   159,
     160,   161,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,     0,   214,   215,   216,   217,
       0,   218,   219,     0,   220,   221,   222,     0,   223,   224,
     225,   226,   227,   228,   229,     0,     0,     0,     0,     0,
     230,   231,     0,   232,     0,     0,     0,   121,   122,   123,
     233,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,     0,
       0,     0,     0,  1743,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,   584,
     585,     0,     0,   139,     0,     0,   586,   587,   588,   589,
     590,   591,   592,   593,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,   326,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
     148,     0,   149,   150,     0,     0,     0,     0,   151,   152,
     153,   154,   155,   156,     0,     0,     0,     0,     0,     0,
     157,     0,     0,   158,     0,     0,   159,   160,   161,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,   214,   215,   216,   217,     0,   218,   219,
       0,   220,   221,   222,     0,   223,   224,   225,   226,   227,
     228,   229,     0,     0,     0,     0,     0,   230,   231,     0,
     232,     0,     0,     0,   121,   122,   123,   233,   124,   125,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   594,   595,   596,   597,     0,     0,     0,     0,
    1747,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,     0,     0,   138,   584,   585,     0,     0,
     139,     0,     0,   586,   587,   588,   589,   590,   591,   592,
     593,     0,   140,   141,     0,     0,   142,     0,   143,     0,
       0,     0,   358,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,   145,     0,     0,     0,   146,   147,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,   149,
     150,     0,     0,     0,     0,   151,   152,   153,   154,   155,
     156,     0,     0,     0,     0,     0,     0,   157,     0,     0,
     158,     0,     0,   159,   160,   161,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,     0,
     214,   215,   216,   217,     0,   218,   219,     0,   220,   221,
     222,     0,   223,   224,   225,   226,   227,   228,   229,     0,
       0,     0,     0,     0,   230,   231,     0,   232,     0,     0,
       0,   121,   122,   123,   233,   124,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   594,
     595,   596,   597,     0,     0,     0,     0,  1809,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,   138,   584,   585,     0,     0,   139,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,     0,   140,
     141,     0,     0,   142,     0,   143,     0,     0,     0,   360,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,   148,     0,   149,   150,     0,     0,
       0,     0,   151,   152,   153,   154,   155,   156,     0,     0,
       0,     0,     0,     0,   157,     0,     0,   158,     0,     0,
     159,   160,   161,     0,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,     0,   214,   215,   216,
     217,     0,   218,   219,     0,   220,   221,   222,     0,   223,
     224,   225,   226,   227,   228,   229,     0,     0,     0,     0,
       0,   230,   231,     0,   232,     0,     0,     0,   121,   122,
     123,   233,   124,   125,   126,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   595,   596,   597,
       0,     0,     0,     0,  1818,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,   131,
     132,   133,   134,   135,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,   138,
     584,   585,     0,     0,   139,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,     0,   140,   141,     0,     0,
     142,     0,   143,     0,     0,     0,   375,     0,     0,     0,
     144,     0,     0,     0,     0,     0,     0,   145,     0,     0,
       0,   146,   147,     0,     0,     0,     0,     0,     0,     0,
       0,   148,     0,   149,   150,     0,     0,     0,     0,   151,
     152,   153,   154,   155,   156,     0,     0,     0,     0,     0,
       0,   157,     0,     0,   158,     0,     0,   159,   160,   161,
       0,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,     0,   214,   215,   216,   217,     0,   218,
     219,     0,   220,   221,   222,     0,   223,   224,   225,   226,
     227,   228,   229,     0,     0,     0,     0,     0,   230,   231,
       0,   232,     0,     0,     0,   121,   122,   123,   233,   124,
     125,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   594,   595,   596,   597,     0,     0,     0,
       0,  1821,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,     0,   138,   584,   585,     0,
       0,   139,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,     0,   140,   141,     0,     0,   142,     0,   143,
       0,     0,     0,   377,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,   148,     0,
     149,   150,     0,     0,     0,     0,   151,   152,   153,   154,
     155,   156,     0,     0,     0,     0,     0,     0,   157,     0,
       0,   158,     0,     0,   159,   160,   161,     0,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
       0,   214,   215,   216,   217,     0,   218,   219,     0,   220,
     221,   222,     0,   223,   224,   225,   226,   227,   228,   229,
       0,     0,     0,     0,     0,   230,   231,     0,   232,     0,
       0,     0,   121,   122,   123,   233,   124,   125,   126,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,     0,     0,     0,     0,  1822,   128,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,   132,   133,   134,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,     0,     0,   138,   584,   585,     0,     0,   139,     0,
       0,   586,   587,   588,   589,   590,   591,   592,   593,     0,
     140,   141,     0,     0,   142,     0,   143,     0,     0,     0,
     389,     0,     0,     0,   144,     0,     0,     0,     0,     0,
       0,   145,     0,     0,     0,   146,   147,     0,     0,     0,
       0,     0,     0,     0,     0,   148,     0,   149,   150,     0,
       0,     0,     0,   151,   152,   153,   154,   155,   156,     0,
       0,     0,     0,     0,     0,   157,     0,     0,   158,     0,
       0,   159,   160,   161,     0,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,     0,   214,   215,
     216,   217,     0,   218,   219,     0,   220,   221,   222,     0,
     223,   224,   225,   226,   227,   228,   229,     0,     0,     0,
       0,     0,   230,   231,     0,   232,     0,     0,     0,   121,
     122,   123,   233,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   594,   595,   596,
     597,     0,     0,     0,     0,  1824,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     138,   584,   585,     0,     0,   139,     0,     0,   586,   587,
     588,   589,   590,   591,   592,   593,     0,   140,   141,     0,
       0,   142,     0,   143,     0,     0,     0,   391,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,   148,     0,   149,   150,     0,     0,     0,     0,
     151,   152,   153,   154,   155,   156,     0,     0,     0,     0,
       0,     0,   157,     0,     0,   158,     0,     0,   159,   160,
     161,     0,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,     0,   214,   215,   216,   217,     0,
     218,   219,     0,   220,   221,   222,     0,   223,   224,   225,
     226,   227,   228,   229,     0,     0,     0,     0,     0,   230,
     231,     0,   232,     0,     0,     0,   121,   122,   123,   233,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   594,   595,   596,   597,     0,     0,
       0,     0,  1841,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   131,   132,   133,
     134,   135,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,     0,     0,   138,   584,   585,
       0,     0,   139,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,     0,   140,   141,     0,     0,   142,     0,
     143,     0,     0,     0,   393,     0,     0,     0,   144,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,   146,
     147,     0,     0,     0,     0,     0,     0,     0,     0,   148,
       0,   149,   150,     0,     0,     0,     0,   151,   152,   153,
     154,   155,   156,     0,     0,     0,     0,     0,     0,   157,
       0,     0,   158,     0,     0,   159,   160,   161,     0,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,     0,   214,   215,   216,   217,     0,   218,   219,     0,
     220,   221,   222,     0,   223,   224,   225,   226,   227,   228,
     229,     0,     0,     0,     0,     0,   230,   231,     0,   232,
       0,     0,     0,   121,   122,   123,   233,   124,   125,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   594,   595,   596,   597,     0,     0,     0,     0,  1951,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,   138,   584,   585,     0,     0,   139,
       0,     0,   586,   587,   588,   589,   590,   591,   592,   593,
       0,   140,   141,     0,     0,   142,     0,   143,     0,     0,
       0,   423,     0,     0,     0,   144,     0,     0,     0,     0,
       0,     0,   145,     0,     0,     0,   146,   147,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,   149,   150,
       0,     0,     0,     0,   151,   152,   153,   154,   155,   156,
       0,     0,     0,     0,     0,     0,   157,     0,     0,   158,
       0,     0,   159,   160,   161,     0,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,     0,   214,
     215,   216,   217,     0,   218,   219,     0,   220,   221,   222,
       0,   223,   224,   225,   226,   227,   228,   229,     0,     0,
       0,     0,     0,   230,   231,     0,   232,     0,     0,     0,
     121,   122,   123,   233,   124,   125,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   594,   595,
     596,   597,     0,     0,     0,     0,  1964,   128,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,     0,
       0,   138,   584,   585,     0,     0,   139,     0,     0,   586,
     587,   588,   589,   590,   591,   592,   593,     0,   140,   141,
       0,     0,   142,     0,   143,     0,     0,     0,   425,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,   146,   147,     0,     0,     0,     0,     0,
       0,     0,     0,   148,     0,   149,   150,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   156,     0,     0,     0,
       0,     0,     0,   157,     0,     0,   158,     0,     0,   159,
     160,   161,     0,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,     0,   214,   215,   216,   217,
       0,   218,   219,     0,   220,   221,   222,     0,   223,   224,
     225,   226,   227,   228,   229,     0,     0,     0,     0,     0,
     230,   231,     0,   232,     0,     0,     0,   121,   122,   123,
     233,   124,   125,   126,   127,     0,   676,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,     0,
       0,     0,     0,  2007,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,   584,
     585,     0,     0,   139,     0,     0,   586,   587,   588,   589,
     590,   591,   592,   593,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
     148,     0,   149,   150,     0,     0,     0,     0,   151,   152,
     153,   154,   155,   156,     0,     0,     0,     0,     0,     0,
     157,     0,     0,   158,     0,     0,   159,   160,   161,     0,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,     0,   214,   215,   216,   217,     0,   218,   219,
       0,   220,   221,   222,     0,   223,   224,   225,   226,   227,
     228,   229,     0,     0,     0,     0,     0,   230,   231,     0,
     232,     0,     0,     0,   121,   122,   123,   233,   124,   125,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   594,   595,   596,   597,     0,     0,     0,     0,
    2028,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,     0,     0,   138,   584,   585,     0,     0,
     139,     0,     0,   586,   587,   588,   589,   590,   591,   592,
     593,     0,   140,   141,     0,     0,   142,     0,   143,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,   145,     0,     0,     0,   146,   147,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,   149,
     150,     0,     0,     0,     0,   151,   152,   153,   154,   155,
     156,     0,     0,     0,     0,     0,     0,   157,     0,     0,
     158,     0,     0,   159,   160,   161,     0,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,     0,
     214,   215,   216,   217,     0,   218,   219,     0,   220,   221,
     222,     0,   223,   224,   225,   226,   227,   228,   229,     0,
       0,   123,     0,     0,   230,   231,   127,   232,     0,     0,
       0,     0,     0,     0,   233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,     0,   594,
     595,   596,   597,     0,     0,     0,     0,  2043,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   584,   585,
       0,     0,     0,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,     0,     0,   584,   585,     0,     0,     0,
       0,     0,   586,   587,   588,   589,   590,   591,   592,   593,
       0,     0,     0,     0,     0,     0,     0,   584,   585,     0,
       0,   142,     0,   143,   586,   587,   588,   589,   590,   591,
     592,   593,   123,     0,     0,     0,     0,   127,     0,     0,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,     0,
     241,   242,   243,   244,   155,     0,     0,     0,     0,     0,
       0,     0,   157,     0,     0,   158,     0,     0,   159,   160,
     245,   584,   585,     0,     0,     0,     0,     0,   586,   587,
     588,   589,   590,   591,   592,   593,     0,     0,     0,     0,
       0,     0,     0,   183,   184,   185,     0,     0,     0,   189,
     190,   191,     0,   193,     0,   195,   196,   197,     0,     0,
       0,     0,   202,   203,   204,   205,   206,     0,     0,   209,
       0,   211,   142,   213,   143,     0,   215,     0,   217,     0,
       0,   219,     0,     0,   221,   222,     0,   223,   224,     0,
     226,   123,   228,   146,   147,     0,   127,     0,     0,     0,
     231,   594,   595,   596,   597,     0,     0,   667,     0,   246,
     889,   241,   242,   243,   244,   155,     0,   129,   594,   595,
     596,   597,     0,   157,   778,     0,   158,     0,     0,   159,
     160,   245,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,     0,     0,  1006,     0,     0,     0,
       0,     0,     0,     0,   183,   184,   185,     0,     0,     0,
     189,   190,   191,     0,   193,     0,   195,   196,   197,     0,
       0,     0,     0,   202,   203,   204,   205,   206,     0,     0,
     209,     0,   211,     0,   213,     0,     0,   215,     0,   217,
       0,   142,   219,   143,     0,   221,   222,   379,   223,   224,
       0,   226,     0,   228,   594,   595,   596,   597,     0,     0,
     123,   231,   146,   147,     0,   127,     0,     0,     0,     0,
     246,   891,     0,     0,     0,     0,     0,     0,     0,     0,
     241,   242,   243,   244,   155,     0,   129,     0,     0,     0,
       0,     0,   157,     0,     0,   158,     0,     0,   159,   160,
     245,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   183,   184,   185,     0,     0,     0,   189,
     190,   191,     0,   193,     0,   195,   196,   197,     0,     0,
       0,     0,   202,   203,   204,   205,   206,     0,     0,   209,
       0,   211,     0,   213,     0,     0,   215,     0,   217,     0,
     142,   219,   143,     0,   221,   222,   427,   223,   224,     0,
     226,     0,   228,     0,     0,     0,     0,     0,     0,   123,
     231,   146,   147,     0,   127,     0,     0,     0,     0,   246,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
     242,   243,   244,   155,     0,   129,     0,     0,     0,     0,
       0,   157,     0,     0,   158,     0,     0,   159,   160,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   183,   184,   185,     0,     0,     0,   189,   190,
     191,     0,   193,     0,   195,   196,   197,     0,     0,     0,
       0,   202,   203,   204,   205,   206,     0,     0,   209,     0,
     211,     0,   213,     0,     0,   215,     0,   217,     0,   142,
     219,   143,     0,   221,   222,   429,   223,   224,     0,   226,
       0,   228,     0,     0,     0,     0,     0,     0,   123,   231,
     146,   147,     0,   127,     0,     0,     0,     0,   246,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   241,   242,
     243,   244,   155,     0,   129,     0,     0,     0,     0,     0,
     157,     0,     0,   158,     0,     0,   159,   160,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,     0,     0,     0,   189,   190,   191,
       0,   193,     0,   195,   196,   197,     0,     0,     0,     0,
     202,   203,   204,   205,   206,     0,     0,   209,     0,   211,
       0,   213,     0,     0,   215,     0,   217,     0,   142,   219,
     143,     0,   221,   222,   431,   223,   224,     0,   226,   123,
     228,     0,     0,     0,   127,     0,     0,     0,   231,   146,
     147,     0,     0,     0,     0,     0,     0,   246,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   241,   242,   243,
     244,   155,     0,     0,     0,     0,     0,     0,     0,   157,
       0,     0,   158,     0,     0,   159,   160,   245,     0,     0,
     584,   585,     0,     0,     0,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,     0,     0,     0,     0,     0,
     183,   184,   185,     0,     0,     0,   189,   190,   191,     0,
     193,     0,   195,   196,   197,     0,     0,     0,     0,   202,
     203,   204,   205,   206,     0,     0,   209,     0,   211,   142,
     213,   143,     0,   215,     0,   217,     0,     0,   219,     0,
       0,   221,   222,     0,   223,   224,     0,   226,     0,   228,
     146,   147,     0,     0,     0,     0,     0,   231,     0,   123,
       0,     0,     0,     0,   127,     0,   246,     0,   241,   242,
     243,   244,   155,     0,   758,     0,     0,     0,     0,     0,
     157,     0,     0,   158,     0,   129,   159,   160,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,     0,     0,     0,   189,   190,   191,
       0,   193,     0,   195,   196,   197,     0,     0,     0,     0,
     202,   203,   204,   205,   206,     0,     0,   209,     0,   211,
       0,   213,     0,     0,   215,     0,   217,     0,     0,   219,
       0,     0,   221,   222,     0,   223,   224,     0,   226,   142,
     228,   143,     0,   594,   595,   596,   597,     0,   231,  1036,
       0,     0,     0,     0,     0,     0,     0,   246,     0,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,   123,
       0,     0,     0,     0,   127,     0,     0,     0,   241,   242,
     243,   244,   155,     0,   837,     0,     0,     0,     0,     0,
     157,     0,     0,   158,     0,   129,   159,   160,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,     0,     0,     0,   189,   190,   191,
       0,   193,     0,   195,   196,   197,     0,     0,     0,     0,
     202,   203,   204,   205,   206,     0,     0,   209,     0,   211,
       0,   213,     0,     0,   215,     0,   217,     0,     0,   219,
       0,  1009,   221,   222,     0,   223,   224,     0,   226,   142,
     228,   143,   584,   585,     0,     0,     0,     0,   231,   586,
     587,   588,   589,   590,   591,   592,   593,   246,   123,     0,
     146,   147,     0,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   241,   242,
     243,   244,   155,     0,   129,     0,     0,     0,     0,     0,
     157,     0,     0,   158,     0,     0,   159,   160,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,     0,     0,     0,   189,   190,   191,
       0,   193,     0,   195,   196,   197,     0,     0,     0,     0,
     202,   203,   204,   205,   206,     0,     0,   209,     0,   211,
    1414,   213,     0,     0,   215,     0,   217,     0,   142,   219,
     143,     0,   221,   222,     0,   223,   224,     0,   226,   123,
     228,     0,     0,     0,   127,     0,     0,     0,   231,   146,
     147,     0,     0,     0,     0,     0,     0,   246,     0,     0,
       0,     0,     0,     0,     0,   129,     0,   241,   242,   243,
     244,   155,     0,     0,     0,     0,     0,     0,     0,   157,
       0,     0,   158,     0,     0,   159,   160,   245,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,     0,
       0,  1132,     0,     0,     0,     0,     0,     0,     0,     0,
     183,   184,   185,     0,     0,     0,   189,   190,   191,     0,
     193,     0,   195,   196,   197,     0,     0,     0,     0,   202,
     203,   204,   205,   206,     0,     0,   209,     0,   211,   142,
     213,   143,     0,   215,     0,   217,     0,     0,   219,     0,
       0,   221,   222,     0,   223,   224,     0,   226,   123,   228,
     146,   147,     0,   127,     0,     0,     0,   231,     0,     0,
       0,     0,     0,     0,     0,     0,   246,     0,   241,   242,
     243,   244,   155,     0,   129,     0,     0,     0,     0,     0,
     157,     0,     0,   158,     0,     0,   159,   160,   245,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   183,   184,   185,     0,     0,     0,   189,   190,   191,
       0,   193,     0,   195,   196,   197,     0,     0,     0,     0,
     202,   203,   204,   205,   206,     0,     0,   209,     0,   211,
       0,   213,     0,     0,   215,     0,   217,     0,   142,   219,
     143,     0,   221,   222,     0,   223,   224,     0,   226,     0,
     228,     0,     0,     0,     0,     0,     0,     0,   231,   146,
     147,     0,     0,     0,     0,     0,     0,   246,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,   242,   243,
     244,   155,     0,     0,     0,     0,     0,     0,     0,   157,
       0,     0,   158,     0,     0,   159,   160,   245,     0,     0,
       0,   584,   585,     0,     0,     0,     0,     0,   586,   587,
     588,   589,   590,   591,   592,   593,     0,     0,     0,     0,
     183,   184,   185,     0,     0,     0,   189,   190,   191,     0,
     193,     0,   195,   196,   197,     0,     0,     0,     0,   202,
     203,   204,   205,   206,     0,     0,   209,     0,   211,     0,
     213,     0,     0,   215,     0,   217,     0,     0,   219,     0,
       0,   221,   222,     0,   223,   224,     0,   226,     0,   228,
       0,     0,     7,     8,     9,     0,     0,   231,     0,    10,
       0,     0,     0,    11,     0,    12,  1270,    13,    14,    15,
      16,    17,  -483,     0,    18,    19,    20,    21,    22,    23,
      24,    25,     0,    26,    27,    28,     0,     0,     0,     0,
      29,     0,     0,    30,     0,     0,     0,     0,     0,     0,
      31,    32,    33,    34,    35,    36,     0,     0,     0,    37,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    40,    41,    42,
      43,    44,     0,     0,     0,     0,     0,    45,    46,    47,
    -237,  -237,    48,    49,    50,     0,    51,    52,    53,     0,
       0,    54,  -237,     0,    55,     0,    56,    57,     0,     0,
       0,     0,    58,    59,   594,   595,   596,   597,     0,    60,
    1133,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,     0,    80,    81,    82,    83,    84,    85,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,     0,     0,
       0,     0,    90,    91,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,     0,     0,
       0,     0,    95,     0,     0,     0,     0,   584,   585,     0,
       0,     0,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,    96,     0,     0,     0,    97,     0,     7,     8,
       9,    98,     0,     0,    99,    10,     0,     0,   100,    11,
       0,    12,     0,    13,    14,    15,    16,    17,  -483,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,     0,     0,     0,     0,    29,   -16,   -16,    30,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    37,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,    45,    46,    47,     0,     0,    48,    49,
      50,     0,    51,    52,    53,     0,     0,    54,     0,     0,
      55,     0,    56,    57,     0,     0,     0,     0,    58,    59,
       0,     0,     0,     0,     0,    60,     0,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,     0,     0,     0,    90,    91,
     594,   595,   596,   597,     0,     0,  1135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    93,    94,     0,     0,     0,     0,    95,     0,
       0,     0,     0,   584,   585,     0,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,    96,     0,
       0,     0,    97,     0,     7,     8,     9,    98,     0,     0,
      99,    10,     0,     0,   100,    11,     0,    12,     0,    13,
      14,    15,    16,    17,  -483,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,   -16,     0,
       0,     0,    29,   -16,     0,    30,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,   584,   585,
       0,    37,    38,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,    48,    49,    50,     0,    51,    52,
      53,     0,     0,    54,     0,     0,    55,     0,    56,    57,
       0,     0,     0,     0,    58,    59,     0,     0,     0,     0,
       0,    60,     0,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,     0,    80,    81,    82,    83,    84,    85,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
       0,     0,     0,     0,    90,    91,   594,   595,   596,   597,
     584,   585,  1136,     0,     0,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,     0,     0,    92,    93,    94,
     584,   585,     0,     0,    95,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    96,     0,     0,     0,    97,     0,
       0,     0,     0,    98,   584,   585,    99,     0,     0,     0,
     100,   586,   587,   588,   589,   590,   591,   592,   593,     0,
       0,   594,   595,   596,   597,   584,   585,  1137,     0,     0,
       0,     0,   586,   587,   588,   589,   590,   591,   592,   593,
     584,   585,     0,     0,     0,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,   584,   585,     0,     0,     0,
       0,     0,   586,   587,   588,   589,   590,   591,   592,   593,
     584,   585,     0,     0,     0,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,   584,   585,     0,     0,     0,
       0,     0,   586,   587,   588,   589,   590,   591,   592,   593,
     584,   585,     0,     0,     0,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,   584,   585,     0,     0,     0,
       0,     0,   586,   587,   588,   589,   590,   591,   592,   593,
       0,     0,     0,   594,   595,   596,   597,   584,   585,  1151,
       0,     0,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,     0,   594,   595,   596,   597,   584,   585,  1185,
       0,     0,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,   584,   585,     0,     0,     0,     0,     0,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   584,   585,  1192,     0,     0,     0,     0,   586,   587,
     588,   589,   590,   591,   592,   593,     0,     0,   594,   595,
     596,   597,     0,     0,  1193,     0,     0,     0,     0,     0,
       0,     0,     0,   594,   595,   596,   597,     0,     0,  1213,
       0,     0,     0,     0,     0,     0,     0,     0,   594,   595,
     596,   597,     0,     0,  1265,     0,     0,     0,     0,     0,
       0,     0,     0,   594,   595,   596,   597,     0,     0,  1288,
       0,     0,     0,     0,     0,     0,     0,     0,   594,   595,
     596,   597,     0,     0,  1289,     0,     0,     0,     0,     0,
       0,     0,     0,   594,   595,   596,   597,     0,     0,  1296,
       0,     0,     0,     0,     0,     0,     0,     0,   594,   595,
     596,   597,   584,   585,  1302,     0,     0,     0,     0,   586,
     587,   588,   589,   590,   591,   592,   593,     0,     0,     0,
     594,   595,   596,   597,   584,   585,  1303,     0,     0,     0,
       0,   586,   587,   588,   589,   590,   591,   592,   593,     0,
     594,   595,   596,   597,     0,     0,  1343,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,   584,
     585,  1396,     0,     0,     0,     0,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   584,   585,
    1401,     0,     0,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,   584,   585,     0,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,   584,   585,
       0,     0,     0,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,   584,   585,     0,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,   584,   585,
       0,     0,     0,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,   584,   585,     0,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,   584,   585,
       0,     0,     0,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,     0,     0,   594,   595,   596,   597,   584,
     585,  1402,     0,     0,     0,     0,   586,   587,   588,   589,
     590,   591,   592,   593,     0,     0,     0,   594,   595,   596,
     597,   584,   585,  1472,     0,     0,     0,     0,   586,   587,
     588,   589,   590,   591,   592,   593,   584,   585,     0,     0,
       0,     0,     0,   586,   587,   588,   589,   590,   591,   592,
     593,     0,   594,   595,   596,   597,   584,   585,  1477,     0,
       0,     0,     0,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,     0,     0,  1491,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   595,   596,   597,
       0,     0,  1503,     0,     0,     0,     0,     0,     0,     0,
       0,   594,   595,   596,   597,     0,     0,  1508,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   595,   596,   597,
       0,     0,  1509,     0,     0,     0,     0,     0,     0,     0,
       0,   594,   595,   596,   597,     0,     0,  1510,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   595,   596,   597,
       0,     0,  1513,     0,     0,     0,     0,     0,     0,     0,
       0,   594,   595,   596,   597,   584,   585,  1541,     0,     0,
       0,     0,   586,   587,   588,   589,   590,   591,   592,   593,
       0,     0,   594,   595,   596,   597,   584,   585,  1548,     0,
       0,     0,     0,   586,   587,   588,   589,   590,   591,   592,
     593,     0,     0,     0,   594,   595,   596,   597,     0,     0,
    1553,     0,     0,     0,     0,     0,     0,     0,     0,   594,
     595,   596,   597,   584,   585,  1556,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,     0,   594,
     595,   596,   597,   584,   585,  1588,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,   584,   585,
       0,     0,     0,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,   584,   585,     0,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,   584,   585,
       0,     0,     0,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,   584,   585,     0,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,   584,   585,
       0,     0,     0,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,   584,   585,     0,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   584,   585,  1611,     0,     0,     0,     0,   586,
     587,   588,   589,   590,   591,   592,   593,     0,     0,   594,
     595,   596,   597,   584,   585,  1612,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,   584,   585,
       0,     0,     0,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,     0,     0,     0,   594,   595,   596,   597,
     584,   585,  1634,     0,     0,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,     0,   594,   595,   596,   597,
       0,     0,  1648,     0,     0,     0,     0,     0,     0,     0,
       0,   594,   595,   596,   597,     0,     0,  1762,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   595,   596,   597,
       0,     0,  1763,     0,     0,     0,     0,     0,     0,     0,
       0,   594,   595,   596,   597,     0,     0,  1764,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   595,   596,   597,
       0,     0,  1766,     0,     0,     0,     0,     0,     0,     0,
       0,   594,   595,   596,   597,     0,     0,  1772,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   595,   596,   597,
     584,   585,  1775,     0,     0,     0,     0,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   584,
     585,  1780,     0,     0,     0,     0,   586,   587,   588,   589,
     590,   591,   592,   593,     0,     0,   594,   595,   596,   597,
       0,     0,  1781,     0,     0,     0,     0,     0,     0,     0,
       0,   594,   595,   596,   597,   584,   585,  1784,     0,     0,
       0,     0,   586,   587,   588,   589,   590,   591,   592,   593,
       0,     0,     0,   594,   595,   596,   597,   584,   585,  1793,
       0,     0,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,   584,   585,     0,     0,     0,     0,     0,   586,
     587,   588,   589,   590,   591,   592,   593,   584,   585,     0,
       0,     0,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,   584,   585,     0,     0,     0,     0,     0,   586,
     587,   588,   589,   590,   591,   592,   593,   584,   585,     0,
       0,     0,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,   584,   585,     0,     0,     0,     0,     0,   586,
     587,   588,   589,   590,   591,   592,   593,   584,   585,     0,
       0,     0,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,     0,   594,   595,   596,   597,   584,   585,  1794,
       0,     0,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   584,   585,  1795,     0,
       0,     0,     0,   586,   587,   588,   589,   590,   591,   592,
     593,   584,   585,     0,     0,     0,     0,     0,   586,   587,
     588,   589,   590,   591,   592,   593,     0,     0,   594,   595,
     596,   597,   584,   585,  1798,     0,     0,     0,     0,   586,
     587,   588,   589,   590,   591,   592,   593,     0,     0,     0,
     594,   595,   596,   597,     0,     0,  1802,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,     0,
       0,  1817,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,     0,     0,  1836,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,     0,
       0,  1856,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,     0,     0,  1857,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,     0,
       0,  1860,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,   584,   585,  1866,     0,     0,     0,
       0,   586,   587,   588,   589,   590,   591,   592,   593,     0,
     594,   595,   596,   597,   584,   585,  1872,     0,     0,     0,
       0,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,     0,     0,  1873,     0,     0,     0,     0,
       0,     0,     0,     0,   594,   595,   596,   597,   584,   585,
    1874,     0,     0,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,     0,     0,   594,   595,   596,   597,   584,
     585,  1877,     0,     0,     0,     0,   586,   587,   588,   589,
     590,   591,   592,   593,   584,   585,     0,     0,     0,     0,
       0,   586,   587,   588,   589,   590,   591,   592,   593,   584,
     585,     0,     0,     0,     0,     0,   586,   587,   588,   589,
     590,   591,   592,   593,   584,   585,     0,     0,     0,     0,
       0,   586,   587,   588,   589,   590,   591,   592,   593,   584,
     585,     0,     0,     0,     0,     0,   586,   587,   588,   589,
     590,   591,   592,   593,   584,   585,     0,     0,     0,     0,
       0,   586,   587,   588,   589,   590,   591,   592,   593,   584,
     585,     0,     0,     0,     0,     0,   586,   587,   588,   589,
     590,   591,   592,   593,     0,     0,     0,   594,   595,   596,
     597,   584,   585,  1881,     0,     0,     0,     0,   586,   587,
     588,   589,   590,   591,   592,   593,     0,   594,   595,   596,
     597,   584,   585,  1913,     0,     0,     0,     0,   586,   587,
     588,   589,   590,   591,   592,   593,   584,   585,     0,     0,
       0,     0,     0,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   584,   585,  1915,     0,     0,
       0,     0,   586,   587,   588,   589,   590,   591,   592,   593,
       0,     0,   594,   595,   596,   597,     0,     0,  1916,     0,
       0,     0,     0,     0,     0,     0,     0,   594,   595,   596,
     597,     0,     0,  1918,     0,     0,     0,     0,     0,     0,
       0,     0,   594,   595,   596,   597,     0,     0,  1924,     0,
       0,     0,     0,     0,     0,     0,     0,   594,   595,   596,
     597,     0,     0,  1927,     0,     0,     0,     0,     0,     0,
       0,     0,   594,   595,   596,   597,     0,     0,  1931,     0,
       0,     0,     0,     0,     0,     0,     0,   594,   595,   596,
     597,     0,     0,  1939,     0,     0,     0,     0,     0,     0,
       0,     0,   594,   595,   596,   597,   584,   585,  1940,     0,
       0,     0,     0,   586,   587,   588,   589,   590,   591,   592,
     593,     0,     0,     0,   594,   595,   596,   597,   584,   585,
    1941,     0,     0,     0,     0,   586,   587,   588,   589,   590,
     591,   592,   593,     0,   594,   595,   596,   597,     0,     0,
    1947,     0,     0,     0,     0,     0,     0,     0,     0,   594,
     595,   596,   597,   584,   585,  1963,     0,     0,     0,     0,
     586,   587,   588,   589,   590,   591,   592,   593,   594,   595,
     596,   597,   584,   585,  1981,     0,     0,     0,     0,   586,
     587,   588,   589,   590,   591,   592,   593,   584,   585,     0,
       0,     0,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,   584,   585,     0,     0,     0,     0,     0,   586,
     587,   588,   589,   590,   591,   592,   593,   584,   585,     0,
       0,     0,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,   584,   585,     0,     0,     0,     0,     0,   586,
     587,   588,   589,   590,   591,   592,   593,   584,   585,     0,
       0,     0,     0,     0,   586,   587,   588,   589,   590,   591,
     592,   593,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   594,
     595,   596,   597,     0,     0,  1983,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   594,   595,   596,   597,     0,     0,  1985,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   594,   595,   596,   597,
       0,     0,  1986,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,     0,
       0,  2006,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,     0,     0,  2008,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,     0,
       0,  2015,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,     0,     0,  2034,     0,     0,     0,
       0,     0,     0,     0,     0,   594,   595,   596,   597,     0,
       0,  2035,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   595,   596,   597,     0,     0,  2047
};

static const yytype_int16 yycheck[] =
{
       3,    40,     1,    15,    16,     4,    12,   471,     4,     1,
       4,     7,     4,     7,    44,    12,     4,     5,    21,    75,
       3,    24,     4,     5,     7,     8,     9,    10,  1637,    41,
      33,    77,    61,     0,    37,    38,   112,    75,    58,    42,
      60,    61,    28,   112,   113,    43,    44,    58,   259,    60,
      61,    54,    55,    56,    53,    95,   247,    12,   440,   441,
      16,    53,    95,   254,   112,   113,   277,    70,    71,    72,
       3,   112,    12,    25,     7,     8,     9,    10,   111,   155,
      81,    82,   111,    86,    87,    88,   155,    88,    44,     7,
       4,    13,    44,     7,    97,    98,    99,   100,    11,    97,
      77,    73,    74,    75,    76,    77,  1277,  1278,    63,    64,
     111,   252,   100,   254,   155,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    20,    21,   112,   113,   110,
      70,    71,    72,    73,    74,    75,    76,    77,    28,   247,
     247,    63,    64,    33,   112,   113,   254,   254,    70,    71,
      72,    73,    74,    75,    76,    77,   160,    70,    71,    72,
      73,    74,    75,    76,   252,   252,   254,   254,    63,    64,
     155,    92,    93,   112,   113,    70,    71,    72,    73,    74,
      75,    76,    77,   104,   566,   253,   568,   155,   253,    70,
      71,    72,    73,    74,    75,    76,   112,   253,   253,   187,
     188,   189,   248,   249,   253,   187,   188,   189,    70,    71,
      72,    73,    74,    75,    76,   253,   155,   247,   253,    59,
      23,    44,    70,    71,    72,    73,    74,    75,    76,   247,
     233,  1840,   247,   247,  1843,   255,   254,   252,   252,   155,
     254,   247,    75,   246,   255,    75,   252,   247,    24,    89,
      90,    91,   255,   112,   254,   252,    96,   253,   247,   253,
     259,   300,   301,   246,   247,   254,   253,   259,   271,   246,
     247,   248,   249,   276,   246,   247,   248,   249,   277,   253,
     283,   247,   247,   247,   253,   277,   252,   252,   254,   254,
     254,   246,   247,   248,   249,   253,   247,   252,  1907,     4,
       5,  1910,   112,   254,   307,   247,   246,   247,   248,   249,
     252,   247,   254,   246,   247,   318,   319,   320,   254,   253,
     252,   112,   254,   326,   246,   247,   248,   249,   247,    74,
      75,    76,    77,   252,   247,   254,     4,     5,    70,    71,
      72,    73,    74,    75,    76,   247,   349,   350,   253,   247,
     252,   246,   247,   248,   249,   358,   254,   360,   112,   362,
     363,   253,   365,   366,   367,   368,   247,   253,   371,   372,
     373,   252,   375,   254,   377,   252,   379,   254,    35,    36,
     383,   384,   385,   386,   387,   247,   389,   253,   391,   253,
     393,   112,   254,   253,   397,   398,   399,   400,   401,   247,
     403,   404,   405,   406,   252,   408,   409,   410,   411,   412,
     413,   414,   253,   416,   417,   418,   419,   420,   421,   630,
     423,  2030,   425,  2032,   427,   253,   429,   253,   431,   253,
     433,   434,   435,   436,   437,   247,    63,    64,   253,  2048,
     443,  2050,   254,    70,    71,    72,    73,    74,    75,    76,
      77,   254,   455,   256,   253,    70,    71,    72,    73,    74,
      75,    76,   112,   466,   162,   468,   161,  1638,   466,   467,
    1641,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,     4,     5,   499,   253,   247,    63,
      64,   246,   247,   248,   249,   254,    70,    71,    72,    73,
      74,    75,    76,    77,   512,   247,   253,   247,   253,   522,
     523,   524,   525,   526,   254,   247,   529,     4,     5,   532,
     252,   534,   254,   536,   537,   538,   539,   540,   541,   542,
     543,   544,   253,   546,   547,   548,   549,   550,   551,   552,
     553,     4,     5,   556,   552,   558,   559,   560,   561,   562,
     247,   253,   565,   247,   567,   252,   569,   570,   571,   155,
     254,   253,   575,   576,   577,   578,   579,   580,   581,   582,
    1751,   247,   253,    44,   251,   252,   252,    70,    71,    72,
      73,    74,    75,    76,   253,    70,    71,    72,    73,    74,
      75,    76,    63,    64,   238,   239,   240,   241,   242,    70,
      71,    72,    73,    74,    75,    76,    77,   656,    46,   246,
     247,   248,   249,   247,   247,   252,   247,   254,   252,   252,
     633,   630,   247,   254,   247,    63,    64,   253,   630,   254,
      51,   254,    70,    71,    72,    73,    74,    75,    76,    77,
      46,   247,    63,    64,   457,   458,   252,   155,   661,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,     4,
       5,   674,    86,    87,    70,    71,    72,    73,    74,    75,
      76,    77,   246,   247,   248,   249,    76,    77,   252,   247,
     254,    63,    64,   253,   252,   698,   254,   700,    70,    71,
      72,    73,    74,    75,    76,    77,   709,   253,   247,   247,
       4,     5,    63,    64,   717,   254,   254,   720,   721,    70,
      71,    72,    73,    74,    75,    76,    77,    70,    71,    72,
      73,    74,    75,    76,   247,    63,    64,   253,  1909,   252,
     951,  1912,    70,    71,    72,    73,    74,    75,    76,    77,
     253,   554,   555,   253,    71,   758,    73,    74,    75,    76,
      77,   764,   253,   766,   247,   768,   253,   770,   253,   772,
    1234,   254,   247,  1237,   247,   247,   155,   252,   155,   252,
     252,   254,   254,   786,   787,   246,   247,   248,   249,   247,
     247,    63,    64,   253,  1965,   252,   254,  1968,    70,    71,
      72,    73,    74,    75,    76,    77,   253,    70,    71,    72,
      73,    74,    75,    76,   253,    63,    64,   253,   246,   247,
     248,   249,    70,    71,    72,    73,    74,    75,    76,    77,
     253,    75,    76,    77,   837,   246,   247,   248,   249,   842,
     247,   844,   845,   646,   647,   252,   155,   254,   651,   652,
     246,   247,   248,   249,   247,   247,   246,   247,   248,   249,
     252,   254,   254,     4,    70,    71,    72,    73,    74,    75,
      76,  2042,   247,  2044,   246,   247,   248,   249,   247,   254,
     252,    44,   254,  2054,  2055,   254,    70,    71,    72,    73,
      74,    75,    76,    49,    50,   246,   247,   248,   249,   247,
     247,   252,    44,   254,   247,   252,   254,   254,   253,   252,
     247,    70,    71,    72,    73,    74,    75,    76,   246,   247,
     248,   249,    39,    40,   252,   252,   254,    63,    64,   246,
     247,   248,   249,   253,    70,    71,    72,    73,    74,    75,
      76,    77,   247,   247,   247,   253,   247,   959,   960,   254,
     254,   254,   951,   254,   247,   247,   247,   253,    63,   951,
      58,   254,   254,   254,   967,    70,    71,    72,    73,    74,
      75,    76,    77,   253,   246,   247,   248,   249,   247,   253,
     983,   247,   254,   986,   247,   254,   989,   252,   254,   252,
      70,    71,    72,    73,    74,    75,    76,    77,   246,   247,
     248,   249,   246,   247,   248,   249,   254,   253,   247,   247,
    1013,   247,   247,   247,  1017,   254,   254,     5,   254,   254,
     254,  1024,   247,    63,    64,  1028,     4,     5,  1031,   254,
      70,    71,    72,    73,    74,    75,    76,    77,   247,   253,
    1043,   247,  1045,  1046,  1047,   254,   252,  1050,  1051,  1052,
    1261,  1054,   253,   247,   247,  1058,   253,   247,   252,  1062,
    1063,   254,  1065,   247,   254,  1068,   253,  1070,   252,   247,
     247,   247,   253,  1076,  1077,   252,   254,  1080,   254,   253,
     247,  1084,  1085,  1086,  1087,   252,   252,  1090,   247,     4,
       5,  1094,   253,   252,  1097,    14,   247,    16,  1101,    18,
    1103,   252,  1105,     3,  1107,  1108,  1109,     7,     8,     9,
     246,   247,   248,   249,   247,   247,   247,   252,   254,   252,
     252,   252,    41,   247,  1123,    44,   253,   247,   252,   247,
      49,  1123,   252,   252,   252,    77,  1139,   253,  1141,   253,
    1143,   246,   247,   248,   249,   247,   253,   247,   247,  1152,
     252,  1154,   252,   252,    43,   247,   253,  1160,   961,   962,
     252,   964,   965,    60,    61,   247,   246,   247,   248,   249,
     252,   247,    63,    64,   253,   253,   252,    60,    61,    70,
      71,    72,    73,    74,    75,    76,    77,   253,   247,   247,
      63,    64,  1195,   252,   252,    43,   253,    70,    71,    72,
      73,    74,    75,    76,    77,   253,   246,   247,   248,   249,
    1213,  1214,  1215,  1216,   254,   247,   247,    63,    64,  1222,
     252,   252,    75,   253,    70,    71,    72,    73,    74,    75,
      76,    77,  1235,    63,    64,  1238,   253,  1240,   253,   253,
      70,    71,    72,    73,    74,    75,    76,    77,   247,   247,
     247,   247,   247,   252,   252,   252,   252,   252,   252,    14,
     247,    16,  1261,    18,  1267,   252,   252,  1270,   247,  1261,
      63,    64,    14,   252,    16,   252,    18,    70,    71,    72,
      73,    74,    75,    76,    77,   247,    41,   253,   253,    44,
     252,   252,  1295,  1296,    49,  1293,  1294,  1300,   247,    41,
     247,  1304,    44,   252,   247,   252,   247,    49,  1111,   252,
     247,   252,   252,   247,   253,   252,  1319,  1320,   252,  1322,
     247,  1324,   247,   253,  1327,   252,   247,   252,  1331,  1332,
     253,   252,   254,   253,  1337,    14,  1339,    16,  1341,    18,
    1343,   253,   247,   253,   247,   253,  1349,   252,  1351,   252,
    1353,   253,  1355,  1356,  1357,   246,   247,   248,   249,   253,
    1363,   247,    41,   254,  1367,    44,   252,   247,   253,   253,
      49,  1374,   252,   246,   247,   248,   249,   253,  1381,   247,
    1383,   254,  1385,   247,   252,  1388,   247,  1390,   252,  1392,
     247,   252,   247,  1396,   253,   252,   252,   252,  1401,  1402,
     246,   247,   248,   249,   247,   247,   247,   247,   254,   252,
     252,   252,   252,    46,   253,   247,   246,   247,   248,   249,
     252,   247,   247,   252,   254,   247,   252,   252,  1431,  1432,
     252,   247,    63,    64,   253,   253,   252,   254,   253,    70,
      71,    72,    73,    74,    75,    76,    77,   247,   253,  1461,
    1462,   253,   252,   246,   247,   248,   249,   247,   247,   253,
     247,   254,   252,   252,  1467,   252,   247,   247,   247,   247,
     247,   252,   252,   252,   252,   252,  1479,   247,   253,   253,
     247,   247,   252,  1286,  1287,   252,   252,   247,  1491,   252,
     247,   247,   252,  1496,  1497,   252,   252,    10,   252,  1502,
    1503,   247,  1505,  1506,   247,   253,   252,   247,   247,   252,
    1513,   247,   252,   252,   252,   247,   252,   247,   253,  1522,
     252,   254,   252,  1526,   253,   247,  1737,  1738,   247,  1532,
     252,  1534,   253,   252,   247,   247,    63,    64,  1541,   252,
     252,  1544,  1545,    70,    71,    72,    73,    74,    75,    76,
      77,   247,  1555,  1556,   253,  1558,   252,  1560,   247,  1562,
    1563,   247,   247,   252,   247,   247,   252,   252,   252,   252,
     252,   247,   253,   253,   338,   339,   252,   341,  1581,   254,
     247,   247,   247,   247,  1587,   252,   252,   252,   252,   247,
     247,   247,   356,   357,   252,   252,   252,  1600,   247,   247,
     364,  1604,   247,   252,   252,   369,   253,   252,  1611,   253,
     374,  1614,   376,   253,  1617,   246,   247,   248,   249,   253,
     247,  1832,   247,   254,   388,   252,   390,   252,   392,  1632,
     394,   395,   396,   253,   247,   247,   247,   247,   402,   252,
     252,   252,   252,   407,  1647,  1648,  1649,   247,   247,   247,
     247,   415,   252,   252,   252,   252,   247,    58,   422,  1662,
     253,   252,  1665,   247,   252,  1668,   252,   247,   252,  1672,
     247,  1674,   252,   247,   252,   252,   252,  1680,   252,  1682,
     252,  1484,  1485,  1686,  1687,  1896,   247,  1690,  1899,   247,
     253,   252,   247,   247,   252,     2,  1699,   252,   252,   247,
    1703,   247,   247,  1706,   252,  1708,   252,   252,  1711,  1712,
      17,  1714,   247,   247,   252,   252,   252,   252,   252,   246,
     247,   248,   249,    30,   252,   254,    33,   254,   247,    36,
      37,    38,   254,   252,   254,    42,    43,    44,  1737,  1738,
     252,   252,  1953,   247,    51,  1737,  1738,   247,   252,   247,
     247,   247,   252,  1756,   252,   252,   252,  1760,   247,   254,
    1763,   247,   247,   252,  1767,   247,   252,   252,    43,   253,
     252,   254,    71,    72,    73,    74,    75,    76,    77,   253,
     247,   247,   247,   247,    91,   252,   252,   252,   252,   247,
      97,   254,   247,   252,   252,   247,  1799,   252,  1801,  1802,
     252,  1804,   247,  1806,   254,   254,   247,   252,   247,    63,
      64,   252,   254,   252,   254,   253,    70,    71,    72,    73,
      74,    75,    76,    77,   247,   132,   254,   247,   254,   252,
     254,  1834,   252,  1832,    63,    64,   253,   253,    85,   254,
    1832,    70,    71,    72,    73,    74,    75,    76,    77,    85,
     252,   247,  1855,  1856,  1857,  1858,   252,  1860,  1861,   247,
     247,   252,  1865,   247,   252,   252,  1869,   252,   252,   252,
    1873,  1874,  1875,   252,  1877,   247,   247,   247,  1881,  1882,
     252,   252,   252,   252,  1887,   252,   252,  1890,   252,  1892,
     252,   252,   252,   252,   252,   252,   252,  1896,   252,   663,
    1899,   254,   254,     5,  1896,  1908,   252,  1899,   252,   254,
      58,  1914,  1915,   677,  1917,  1918,  1919,   254,   682,   254,
     684,   254,   686,   687,   253,   232,   233,   253,   692,   693,
     252,   252,   252,   252,   252,    43,   253,  1940,   254,   254,
     254,  1944,    38,  1946,  1947,    43,   253,   246,   247,   248,
     249,   258,   253,    58,  1953,    75,   254,   254,  1961,    75,
      75,  1953,    48,    58,   271,   253,    47,   254,   254,   276,
     252,    58,   253,   253,   253,  1978,   283,   253,    75,  1982,
     254,   254,  1985,  1986,    38,   253,   253,  1990,   252,   252,
       4,  1994,   246,   247,   248,   249,     4,  1123,   252,   306,
    2003,   308,    53,    53,   656,  2008,     5,   967,   963,   471,
     966,  1467,  1814,  2026,  2017,   653,  1273,   246,   247,   248,
     249,    -1,    -1,   669,    -1,   254,    -1,    -1,   792,   793,
      -1,  2034,  2035,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2047,    -1,    -1,    -1,   355,  2052,
      63,    64,   816,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,   442,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,   454,    -1,    -1,
      -1,    -1,   459,   460,    -1,   462,   463,   464,   465,   466,
     467,    -1,    -1,    -1,    -1,    -1,   473,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,    -1,    -1,    -1,    -1,    -1,
     527,   528,   529,   530,   531,     5,   533,    -1,   535,    -1,
      10,    -1,    -1,   246,   247,   248,   249,    -1,   545,    -1,
      -1,   254,    -1,    -1,    -1,   552,    -1,    -1,    -1,    -1,
     557,    31,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   595,   596,
     597,   246,   247,   248,   249,    -1,    -1,    -1,    -1,   254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,   631,   105,    -1,   107,    -1,   636,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   649,   650,    -1,    -1,   126,   127,    -1,    -1,
     246,   247,   248,   249,    -1,   662,    -1,    -1,   254,    -1,
     667,    -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,
      -1,   678,   679,    -1,    -1,     5,   156,    -1,    -1,   159,
      10,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,   187,   188,   189,
      -1,    -1,   719,   193,   194,   195,    -1,   197,    -1,   199,
     200,   201,    -1,    -1,    -1,    -1,   206,   207,   208,   209,
     210,    -1,    -1,   213,    -1,   215,    -1,   217,    -1,    -1,
     220,    -1,   222,    -1,    -1,   225,    -1,    -1,   228,   229,
      -1,   231,   232,    -1,   234,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,
      -1,   778,    -1,   253,   254,   105,    -1,   107,    -1,   786,
     787,   788,   789,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,   126,   127,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,   164,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1308,    -1,    -1,  1311,    -1,    -1,
      -1,    -1,  1316,    -1,    -1,    -1,    -1,   187,   188,   189,
      -1,    -1,    -1,   193,   194,   195,    -1,   197,    -1,   199,
     200,   201,    -1,    -1,    -1,    -1,   206,   207,   208,   209,
     210,    -1,    -1,   213,    -1,   215,    -1,   217,    -1,    -1,
     220,    -1,   222,    -1,    -1,   225,    -1,    -1,   228,   229,
      -1,   231,   232,    -1,   234,    -1,   236,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   253,   254,    63,    64,   934,   935,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,  1405,    -1,    -1,    -1,    -1,    -1,   954,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,  1422,    -1,
     967,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,   980,   246,   247,   248,   249,    -1,   986,
     987,    -1,   254,    -1,    -1,   992,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1006,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,  1026,
      -1,    -1,    -1,    -1,  1031,  1032,  1033,    -1,    -1,  1036,
      63,    64,  1039,    -1,  1041,    -1,  1043,    70,    71,    72,
      73,    74,    75,    76,    77,  1052,    -1,    -1,    -1,  1056,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1064,    -1,  1066,
      -1,    -1,    -1,    -1,    -1,  1072,    -1,    -1,    -1,  1076,
    1077,  1078,    -1,    -1,  1081,  1082,    -1,    -1,  1085,    -1,
      -1,  1088,    -1,    -1,  1091,    -1,  1093,    -1,  1095,    63,
      64,    -1,  1099,    -1,  1101,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,  1112,  1113,  1114,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,  1124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1132,  1133,    -1,  1135,  1136,
    1137,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,
     249,  1148,  1149,    -1,  1151,   254,    63,    64,  1155,  1156,
    1157,    -1,  1159,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,  1170,    -1,    -1,  1173,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1185,    -1,
      -1,  1188,  1189,  1190,    -1,  1192,  1193,   246,   247,   248,
     249,  1655,    -1,   252,  1201,  1659,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,  1229,    -1,  1231,  1232,  1233,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,  1245,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,  1265,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,  1275,    -1,
      -1,    -1,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,  1288,  1289,    -1,    -1,    -1,  1293,  1294,    -1,    -1,
      63,    64,    -1,    -1,    -1,  1302,  1303,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    -1,
    1377,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    90,    91,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,   104,
      -1,    -1,    -1,   254,    -1,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,
    1467,    -1,    -1,    -1,    -1,  1472,    -1,    -1,    -1,    -1,
    1477,    -1,    -1,   246,   247,   248,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
     165,  1508,  1509,  1510,    -1,  1512,    -1,    -1,    -1,    -1,
      -1,    -1,  1519,    -1,    -1,    -1,  1523,  1524,    -1,    -1,
      -1,    -1,  1529,    -1,  1531,  1532,    -1,    -1,    -1,  1536,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1544,    -1,    -1,
    1547,  1548,    -1,  1550,    -1,    -1,  1553,    -1,    -1,    -1,
      -1,  1558,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1568,    -1,    -1,    -1,    -1,    -1,    -1,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,  1586,
      -1,  1588,    -1,   246,   247,   248,   249,    -1,    -1,  1596,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,  1605,    -1,
    1607,    -1,    -1,    -1,    -1,  1612,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1621,    -1,   317,    -1,    -1,    -1,
      -1,    -1,   323,    -1,  1631,    -1,    -1,  1634,    -1,   330,
     331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   342,   343,   344,   345,   346,   347,   348,    -1,    -1,
     351,   352,   353,   354,    -1,    -1,  1663,  1664,    -1,    -1,
    1667,    -1,    63,    64,    -1,    -1,    -1,    -1,  1675,    70,
      71,    72,    73,    74,    75,    76,    77,  1684,  1685,    -1,
      -1,    -1,  1689,    -1,    -1,    63,    64,  1694,    -1,    -1,
      -1,  1698,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,  1715,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,  1739,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1750,    -1,    -1,    -1,    -1,    -1,    -1,
     451,   452,   453,    -1,    -1,  1762,    -1,  1764,    -1,  1766,
      -1,    -1,    -1,    -1,    -1,  1772,    -1,    -1,  1775,    -1,
    1777,   472,    -1,  1780,  1781,    -1,    -1,  1784,    -1,    -1,
      -1,    -1,    -1,    -1,  1791,    -1,  1793,  1794,  1795,    -1,
      -1,  1798,    -1,    -1,    -1,    -1,    -1,  1804,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
    1817,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
    1827,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1835,  1836,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,  1863,    -1,    -1,  1866,
      -1,    -1,    -1,  1870,    -1,  1872,    -1,    -1,   246,   247,
     248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,  1911,    -1,  1913,    -1,   254,  1916,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1924,    -1,    -1,
    1927,    -1,    -1,    -1,  1931,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1939,    -1,  1941,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1963,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,   672,    -1,    -1,  1981,   676,  1983,    -1,    -1,   680,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,   246,   247,
     248,   249,    -1,    -1,   695,   696,   254,    -1,    -1,  2006,
      -1,    -1,   703,    -1,    -1,    -1,    -1,   708,  2015,    -1,
      -1,    -1,   713,    -1,   715,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,   727,    -1,   729,    -1,
     731,    -1,   733,   734,   735,    -1,    81,    -1,    -1,    84,
     741,    -1,    -1,    -1,    89,   746,    -1,    -1,    -1,    -1,
      -1,    -1,    97,   754,    -1,    -1,   101,   102,    -1,    -1,
     105,   762,   107,    -1,    -1,   110,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   136,    -1,   138,   139,    -1,    -1,    -1,    -1,   144,
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
      -1,   246,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,
     255,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1012,    -1,    -1,    30,    31,    -1,    -1,    -1,  1020,
      -1,    -1,    -1,    -1,  1025,    -1,  1027,    -1,  1029,  1030,
      -1,    -1,    -1,  1034,  1035,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,   246,   247,   248,   249,    -1,   115,
      -1,    -1,   254,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,   246,   247,   248,   249,    -1,    -1,    -1,
     136,   254,   138,   139,  1125,  1126,    -1,    -1,   144,   145,
     146,   147,   148,   149,   246,   247,   248,   249,    -1,    -1,
     156,    -1,   254,   159,    -1,    -1,   162,   163,   164,  1150,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,   219,   220,   221,   222,    -1,   224,   225,
      -1,   227,   228,   229,    -1,   231,   232,   233,   234,   235,
     236,   237,    -1,    -1,    -1,    -1,    -1,   243,   244,    -1,
     246,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,   255,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,
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
     253,    -1,   255,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,  1504,    -1,    -1,  1507,    -1,    -1,    -1,
    1511,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1572,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
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
      -1,    -1,    -1,    -1,   253,    -1,   255,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
    1761,    -1,    -1,    -1,  1765,    -1,    -1,    -1,    -1,    -1,
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
     246,    -1,    -1,    -1,    -1,    -1,    -1,   253,   254,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,   246,   247,   248,   249,    -1,    -1,    -1,    -1,
     254,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,
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
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,   142,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,    -1,   142,   143,   144,   145,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,   142,    -1,   144,   145,   146,   147,   148,
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
      -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,
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
      -1,   136,    -1,   138,   139,    -1,    -1,    -1,    -1,   144,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,   139,    -1,    -1,   142,   143,   144,   145,   146,   147,
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
      -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,
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
      -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,    -1,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,    -1,   143,   144,   145,   146,
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
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,
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
      -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,
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
     136,    -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
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
      -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,    -1,
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
      -1,   136,    -1,   138,   139,    -1,    -1,    -1,    -1,   144,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,
     138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
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
      -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,
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
      -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,    -1,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,
      -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,   146,
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
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,
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
     163,   164,    -1,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,    -1,   219,   220,   221,   222,
      -1,   224,   225,    -1,   227,   228,   229,    -1,   231,   232,
     233,   234,   235,   236,   237,    -1,    -1,    -1,    -1,    -1,
     243,   244,    -1,   246,    -1,    -1,    -1,     3,     4,     5,
     253,     7,     8,     9,    10,    -1,    12,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     136,    -1,   138,   139,    -1,    -1,    -1,    -1,   144,   145,
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
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
     219,   220,   221,   222,    -1,   224,   225,    -1,   227,   228,
     229,    -1,   231,   232,   233,   234,   235,   236,   237,    -1,
      -1,     5,    -1,    -1,   243,   244,    10,   246,    -1,    -1,
      -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,   246,
     247,   248,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,   105,    -1,   107,    70,    71,    72,    73,    74,    75,
      76,    77,     5,    -1,    -1,    -1,    -1,    10,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,    -1,    -1,    -1,   193,
     194,   195,    -1,   197,    -1,   199,   200,   201,    -1,    -1,
      -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,   213,
      -1,   215,   105,   217,   107,    -1,   220,    -1,   222,    -1,
      -1,   225,    -1,    -1,   228,   229,    -1,   231,   232,    -1,
     234,     5,   236,   126,   127,    -1,    10,    -1,    -1,    -1,
     244,   246,   247,   248,   249,    -1,    -1,   252,    -1,   253,
     254,   144,   145,   146,   147,   148,    -1,    31,   246,   247,
     248,   249,    -1,   156,   252,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   187,   188,   189,    -1,    -1,    -1,
     193,   194,   195,    -1,   197,    -1,   199,   200,   201,    -1,
      -1,    -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,
     213,    -1,   215,    -1,   217,    -1,    -1,   220,    -1,   222,
      -1,   105,   225,   107,    -1,   228,   229,   111,   231,   232,
      -1,   234,    -1,   236,   246,   247,   248,   249,    -1,    -1,
       5,   244,   126,   127,    -1,    10,    -1,    -1,    -1,    -1,
     253,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,    -1,    31,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   187,   188,   189,    -1,    -1,    -1,   193,
     194,   195,    -1,   197,    -1,   199,   200,   201,    -1,    -1,
      -1,    -1,   206,   207,   208,   209,   210,    -1,    -1,   213,
      -1,   215,    -1,   217,    -1,    -1,   220,    -1,   222,    -1,
     105,   225,   107,    -1,   228,   229,   111,   231,   232,    -1,
     234,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,     5,
     244,   126,   127,    -1,    10,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,    -1,    31,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   187,   188,   189,    -1,    -1,    -1,   193,   194,
     195,    -1,   197,    -1,   199,   200,   201,    -1,    -1,    -1,
      -1,   206,   207,   208,   209,   210,    -1,    -1,   213,    -1,
     215,    -1,   217,    -1,    -1,   220,    -1,   222,    -1,   105,
     225,   107,    -1,   228,   229,   111,   231,   232,    -1,   234,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,     5,   244,
     126,   127,    -1,    10,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,    -1,    31,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,    -1,    -1,    -1,   193,   194,   195,
      -1,   197,    -1,   199,   200,   201,    -1,    -1,    -1,    -1,
     206,   207,   208,   209,   210,    -1,    -1,   213,    -1,   215,
      -1,   217,    -1,    -1,   220,    -1,   222,    -1,   105,   225,
     107,    -1,   228,   229,   111,   231,   232,    -1,   234,     5,
     236,    -1,    -1,    -1,    10,    -1,    -1,    -1,   244,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,    -1,    -1,    -1,   193,   194,   195,    -1,
     197,    -1,   199,   200,   201,    -1,    -1,    -1,    -1,   206,
     207,   208,   209,   210,    -1,    -1,   213,    -1,   215,   105,
     217,   107,    -1,   220,    -1,   222,    -1,    -1,   225,    -1,
      -1,   228,   229,    -1,   231,   232,    -1,   234,    -1,   236,
     126,   127,    -1,    -1,    -1,    -1,    -1,   244,    -1,     5,
      -1,    -1,    -1,    -1,    10,    -1,   253,    -1,   144,   145,
     146,   147,   148,    -1,   150,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    31,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,    -1,    -1,    -1,   193,   194,   195,
      -1,   197,    -1,   199,   200,   201,    -1,    -1,    -1,    -1,
     206,   207,   208,   209,   210,    -1,    -1,   213,    -1,   215,
      -1,   217,    -1,    -1,   220,    -1,   222,    -1,    -1,   225,
      -1,    -1,   228,   229,    -1,   231,   232,    -1,   234,   105,
     236,   107,    -1,   246,   247,   248,   249,    -1,   244,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,   144,   145,
     146,   147,   148,    -1,   150,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    31,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,    -1,    -1,    -1,   193,   194,   195,
      -1,   197,    -1,   199,   200,   201,    -1,    -1,    -1,    -1,
     206,   207,   208,   209,   210,    -1,    -1,   213,    -1,   215,
      -1,   217,    -1,    -1,   220,    -1,   222,    -1,    -1,   225,
      -1,    97,   228,   229,    -1,   231,   232,    -1,   234,   105,
     236,   107,    63,    64,    -1,    -1,    -1,    -1,   244,    70,
      71,    72,    73,    74,    75,    76,    77,   253,     5,    -1,
     126,   127,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,    -1,    31,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,    -1,    -1,    -1,   193,   194,   195,
      -1,   197,    -1,   199,   200,   201,    -1,    -1,    -1,    -1,
     206,   207,   208,   209,   210,    -1,    -1,   213,    -1,   215,
      97,   217,    -1,    -1,   220,    -1,   222,    -1,   105,   225,
     107,    -1,   228,   229,    -1,   231,   232,    -1,   234,     5,
     236,    -1,    -1,    -1,    10,    -1,    -1,    -1,   244,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     187,   188,   189,    -1,    -1,    -1,   193,   194,   195,    -1,
     197,    -1,   199,   200,   201,    -1,    -1,    -1,    -1,   206,
     207,   208,   209,   210,    -1,    -1,   213,    -1,   215,   105,
     217,   107,    -1,   220,    -1,   222,    -1,    -1,   225,    -1,
      -1,   228,   229,    -1,   231,   232,    -1,   234,     5,   236,
     126,   127,    -1,    10,    -1,    -1,    -1,   244,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,   144,   145,
     146,   147,   148,    -1,    31,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,    -1,    -1,    -1,   193,   194,   195,
      -1,   197,    -1,   199,   200,   201,    -1,    -1,    -1,    -1,
     206,   207,   208,   209,   210,    -1,    -1,   213,    -1,   215,
      -1,   217,    -1,    -1,   220,    -1,   222,    -1,   105,   225,
     107,    -1,   228,   229,    -1,   231,   232,    -1,   234,    -1,
     236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
     187,   188,   189,    -1,    -1,    -1,   193,   194,   195,    -1,
     197,    -1,   199,   200,   201,    -1,    -1,    -1,    -1,   206,
     207,   208,   209,   210,    -1,    -1,   213,    -1,   215,    -1,
     217,    -1,    -1,   220,    -1,   222,    -1,    -1,   225,    -1,
      -1,   228,   229,    -1,   231,   232,    -1,   234,    -1,   236,
      -1,    -1,     4,     5,     6,    -1,    -1,   244,    -1,    11,
      -1,    -1,    -1,    15,    -1,    17,   253,    19,    20,    21,
      22,    23,    24,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    -1,    -1,    -1,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,
      92,    93,    94,    95,    96,    -1,    98,    99,   100,    -1,
      -1,   103,   104,    -1,   106,    -1,   108,   109,    -1,    -1,
      -1,    -1,   114,   115,   246,   247,   248,   249,    -1,   121,
     252,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,   157,   158,   159,    -1,    -1,
      -1,    -1,   164,   165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   187,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   214,    -1,    -1,    -1,   218,    -1,     4,     5,
       6,   223,    -1,    -1,   226,    11,    -1,    -1,   230,    15,
      -1,    17,    -1,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    -1,    -1,    94,    95,
      96,    -1,    98,    99,   100,    -1,    -1,   103,    -1,    -1,
     106,    -1,   108,   109,    -1,    -1,    -1,    -1,   114,   115,
      -1,    -1,    -1,    -1,    -1,   121,    -1,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,   164,   165,
     246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   187,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,   214,    -1,
      -1,    -1,   218,    -1,     4,     5,     6,   223,    -1,    -1,
     226,    11,    -1,    -1,   230,    15,    -1,    17,    -1,    19,
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
     140,   141,    -1,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,   159,
      -1,    -1,    -1,    -1,   164,   165,   246,   247,   248,   249,
      63,    64,   252,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   187,   188,   189,
      63,    64,    -1,    -1,   194,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   214,    -1,    -1,    -1,   218,    -1,
      -1,    -1,    -1,   223,    63,    64,   226,    -1,    -1,    -1,
     230,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
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
      -1,    -1,    -1,   246,   247,   248,   249,    63,    64,   252,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   246,   247,   248,   249,    63,    64,   252,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   246,   247,   248,
     249,    63,    64,   252,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   246,   247,
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
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
     246,   247,   248,   249,    63,    64,   252,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,    63,
      64,   252,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   246,   247,   248,   249,    63,    64,
     252,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   246,   247,   248,   249,    63,
      64,   252,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,   246,   247,   248,
     249,    63,    64,   252,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   246,   247,   248,   249,    63,    64,   252,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,   246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,    63,    64,   252,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,   246,   247,   248,   249,    63,    64,   252,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,   246,   247,   248,   249,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
     247,   248,   249,    63,    64,   252,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   246,
     247,   248,   249,    63,    64,   252,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,   246,   247,
     248,   249,    63,    64,   252,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   246,
     247,   248,   249,    63,    64,   252,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,   246,   247,   248,   249,
      63,    64,   252,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   246,   247,   248,   249,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
      63,    64,   252,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,   246,   247,   248,   249,    63,
      64,   252,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   246,   247,   248,   249,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,    63,    64,   252,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,   246,   247,   248,   249,    63,    64,   252,
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
      76,    77,    -1,   246,   247,   248,   249,    63,    64,   252,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   246,   247,   248,   249,    63,    64,   252,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   246,   247,
     248,   249,    63,    64,   252,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
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
     246,   247,   248,   249,    63,    64,   252,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   246,
     247,   248,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   246,   247,   248,   249,    63,    64,
     252,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   246,   247,   248,   249,    63,
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
      74,    75,    76,    77,    -1,    -1,    -1,   246,   247,   248,
     249,    63,    64,   252,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   246,   247,   248,
     249,    63,    64,   252,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,   246,   247,   248,   249,    63,    64,   252,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
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
      77,    -1,    -1,    -1,   246,   247,   248,   249,    63,    64,
     252,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   246,   247,   248,   249,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
     247,   248,   249,    63,    64,   252,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,   246,   247,
     248,   249,    63,    64,   252,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   246,
     247,   248,   249,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     246,   247,   248,   249,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   246,   247,   248,   249,    -1,
      -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     101,   102,   105,   107,   115,   122,   126,   127,   136,   138,
     139,   144,   145,   146,   147,   148,   149,   156,   159,   162,
     163,   164,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   219,   220,   221,   222,   224,   225,
     227,   228,   229,   231,   232,   233,   234,   235,   236,   237,
     243,   244,   246,   253,   276,   277,   279,   285,   287,   290,
     291,   144,   145,   146,   147,   164,   253,   276,   262,   290,
     291,   296,     0,    75,   253,    75,   253,   310,   329,   333,
       4,     7,   288,   288,   288,    34,   279,   264,   265,   276,
     292,   293,   292,   276,    28,     7,   318,   326,   279,    58,
      60,    61,   255,   372,   268,   276,   279,     4,     5,   289,
     279,   276,   279,   276,   279,     4,     5,   352,   353,    10,
     246,   247,   286,   287,   354,   288,    89,    97,   255,   276,
     279,   373,    89,    97,   110,   373,   373,    81,    82,    88,
     111,   279,   284,    12,    53,   284,   111,   284,    59,    89,
      90,    91,    96,    95,   279,   271,   278,   276,   276,   276,
     110,   284,    90,    91,    92,    93,    94,   104,   110,   111,
     116,   117,   118,   119,   120,   165,   284,   284,   111,   284,
     111,   284,    95,   111,   284,    61,    95,   111,   142,   284,
     284,    22,    61,   111,   284,   111,   284,   111,   284,   111,
     276,   276,   276,    61,   111,   111,   142,   143,   284,   111,
     284,   111,   284,   111,   284,   284,   284,    95,   142,   143,
     151,   154,   284,    95,   142,   143,   154,   284,    95,   142,
     143,   151,   152,   153,   154,   284,    61,    95,   142,   143,
     150,   154,   284,   111,   284,   111,   284,   111,   276,   111,
     276,   111,   276,   160,    95,   111,   112,   143,   279,   253,
     253,   253,   253,   253,   276,   373,   276,   276,   276,    44,
     260,    92,    93,   104,    75,    75,    24,   253,   253,   253,
     253,   279,   253,   253,   253,   253,   253,   253,   112,   113,
     253,   253,   253,   253,   112,   253,   112,   155,   112,   155,
     112,   112,   112,   112,   113,   155,   112,   113,   155,   112,
     113,   155,   112,   113,   155,   112,   112,   162,   161,   253,
     112,   155,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   279,   276,   279,    70,    71,    72,    73,    74,
      75,    76,   247,    44,    63,    64,    70,    71,    72,    73,
      74,    75,    76,    77,   246,   247,   248,   249,   276,    44,
      44,    44,   279,   292,   276,   292,     4,   279,   259,    35,
      36,    20,    21,     4,     5,   303,   304,     4,     5,   305,
     306,   276,   279,   294,   295,   276,   279,   320,   259,   336,
     342,   253,    58,   253,     4,     7,   253,   276,   279,   355,
      58,    60,    61,   255,   357,   370,   253,   253,   252,   252,
     252,   253,   253,   252,   287,   287,   252,   279,   276,   279,
      11,   252,   252,   284,   276,   276,   276,   252,   284,   269,
      12,   252,   272,   276,   252,   284,    12,   284,   272,   272,
     272,   284,   284,   284,   284,   284,   284,   284,   276,   276,
     284,   284,   284,   284,   279,   272,   272,   276,   252,   276,
     252,   276,   276,   272,   276,   276,   276,   276,   272,   252,
     276,   276,   276,   272,   276,   272,   276,   252,   276,   252,
     252,   252,   276,   276,   276,   276,   276,   272,   276,   272,
     276,   272,   276,   272,   272,   272,   276,   276,   276,   276,
     276,   272,   276,   276,   276,   276,   272,   276,   276,   276,
     276,   276,   276,   276,   272,   276,   276,   276,   150,   276,
     276,   276,   272,   276,   252,   276,   252,   276,   252,   276,
     252,   276,   252,   276,   276,   276,   276,   276,   252,     5,
     275,   275,   275,   254,   279,   276,   252,   252,   252,   252,
      43,   284,   284,   284,   279,   276,   297,   292,   292,   279,
     279,   279,   279,   279,   279,    97,   276,   373,   373,   276,
       4,     5,   282,   283,   282,   283,   284,   279,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   150,   276,   276,
     276,   276,   253,   276,   253,   253,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   373,   279,   279,   279,
     279,   279,   279,   279,   279,   254,   279,   276,   276,   276,
     276,   276,   279,   279,   276,   279,   254,   279,   279,   276,
     279,   276,   279,   276,   276,   254,   276,   254,   276,   254,
     276,   254,   276,   276,   276,   276,   279,   276,   276,   276,
     276,   276,   276,   276,   373,   276,   292,   292,   276,   279,
     276,   276,   276,   276,   276,   254,   254,   276,   275,   276,
     275,   276,   276,   276,   254,   254,   276,   276,   276,   276,
     276,   276,   276,   276,   281,   280,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   254,   254,
      75,   330,    14,    16,    18,    41,    44,    49,   334,   266,
     267,   253,   253,   252,   253,   253,   252,   252,    43,   319,
      14,    16,    18,    41,    44,    49,   327,    46,   259,   279,
     253,   276,   279,    51,   356,   251,   252,   253,    58,   253,
       4,     7,   253,    10,   371,   292,   292,     4,     5,   279,
     279,   292,   292,   353,    10,   286,   252,    86,    87,    97,
     276,   279,   272,   252,   279,   357,   284,   252,   276,   284,
     272,   279,   279,   284,   252,   272,   252,   272,   252,   272,
     272,   252,   252,   252,   272,   272,   252,   284,   284,   252,
     276,   252,   276,   252,   284,   252,   252,   252,   284,   276,
     252,   252,   252,   284,   252,   284,   252,   276,   252,   279,
     276,   276,   252,   252,   252,   252,   252,   284,   252,   284,
     252,   284,   252,   284,   284,   284,   252,   252,   252,   284,
     252,   252,   252,   284,   252,   252,   252,   252,   252,   284,
     252,   252,   276,   252,   252,   252,   284,   252,   276,   252,
     276,   252,   276,   252,   276,   252,   276,   252,   252,   252,
     279,   253,   252,   252,   252,   254,   254,   276,   279,   276,
     279,   279,   279,   261,   252,   272,   272,     4,     5,   301,
     254,   254,   252,   252,   254,   252,   252,   252,   254,   252,
     254,   252,   254,   252,   253,   253,   254,   254,   252,   252,
     272,   252,   252,   254,   252,   252,   252,   252,   276,   252,
     252,   276,   254,   276,   276,   254,   254,   254,   254,   254,
     252,   254,   254,   252,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   252,   254,   254,   252,   252,
     252,   254,   252,   252,   254,   252,   254,   254,   254,   254,
     254,   252,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   252,   252,   252,   252,   254,   254,   254,
     254,   254,   252,   254,   254,   254,   254,   254,   254,   252,
     254,   252,   252,   252,   252,   252,   254,   252,   252,   254,
     252,   254,   254,   279,   279,   311,   259,   279,   288,   374,
     288,   375,   292,   292,   304,   292,   292,   306,   295,    43,
     321,   337,    49,    50,   343,   252,   279,   252,   254,   254,
     253,   276,   276,   279,   279,   253,   276,   358,   359,   279,
       4,     5,   349,   351,   254,   254,   253,   253,   252,   252,
     254,   254,   279,    85,    85,   252,   252,   284,   276,   276,
     252,   284,   252,   252,   252,   276,   284,   279,   284,   276,
     284,   284,   276,   279,   279,   279,   284,   284,   279,   252,
     252,   279,   252,   279,   252,   276,   279,   252,   276,   276,
     276,   252,   252,   276,   276,   276,   279,   252,   276,   252,
     279,   252,   276,   252,   276,   276,   279,   276,   279,   252,
     276,   252,   276,   252,   279,   252,   252,   252,   276,   279,
     276,   279,   279,   252,   276,   279,   279,   252,   276,   276,
     279,   276,   276,   279,   252,   276,   279,   252,   279,   276,
     279,   252,   276,   252,   279,   252,   276,   279,   252,   276,
     252,   276,   252,   276,   276,   276,   252,   292,   279,   279,
     279,   252,   252,   263,   279,   284,   284,   298,   279,   279,
     279,   279,   279,   276,    97,   276,   276,   254,   254,   279,
     279,   284,   279,   276,   276,   279,   279,   279,   279,   276,
     254,   252,   252,   279,   279,   279,   279,   279,   279,   279,
     279,   276,   279,   276,   276,   276,   276,   276,   279,   279,
     279,   279,   283,   276,   283,   276,   276,   279,    16,    44,
     331,   252,   252,   254,   254,   254,   254,    39,    40,   323,
     259,   279,   252,   276,    58,   276,   356,   252,   279,   252,
     254,   349,   349,   254,   253,   253,   252,   292,   292,   279,
     279,   252,   373,   373,   276,   276,   252,   252,   276,   279,
     279,   276,   252,   252,   272,   252,   252,   272,   252,   252,
     252,   272,   252,   252,   276,   276,   276,   276,   276,   252,
     276,   276,   252,   252,   252,   276,   252,   276,   276,   252,
     276,   252,   252,   276,   252,   276,   252,   276,   276,   276,
     276,   252,   276,   276,   252,   252,   276,   252,   252,   279,
     252,   276,   276,   252,   276,   252,   252,   276,   252,   276,
     252,   276,   252,   252,   276,   254,   254,   254,   252,   254,
     276,   276,   272,   253,   254,   254,   254,   254,   254,   254,
     254,   252,   254,   254,   254,   254,   272,   252,   252,   276,
     276,   254,   254,   254,   254,   254,   252,   254,   254,   254,
     252,   254,   254,   254,   252,   252,   254,   252,   254,   254,
     254,   252,   252,   254,   252,   254,   254,   252,   254,   254,
     254,    12,   288,   288,   320,    43,    38,   338,   254,   279,
     254,   253,   252,   279,   252,   276,    58,   365,   360,   292,
     292,   350,   254,   254,   276,   276,   276,   252,   252,   252,
     276,   276,   284,   276,   276,   284,   279,   279,   279,   284,
     279,   276,   252,   252,   252,   252,   279,   252,   252,   276,
     279,   279,   252,   276,   252,   252,   279,   279,   276,   279,
     252,   276,   252,   279,   252,   252,   252,   252,   276,   252,
     252,   276,   279,   276,   252,   279,   279,   279,   252,   252,
     279,   276,   276,   252,   276,   279,   252,   276,   252,   276,
     276,    75,    75,   279,    75,   252,   284,     4,     5,   307,
     308,   276,   279,   276,   279,   254,   254,   279,   276,   276,
     279,   279,   276,   279,   276,   276,   279,   322,   324,    48,
     345,    60,    61,   254,    58,   279,   276,   254,   279,   254,
     253,   371,   349,   254,   254,   349,   252,   276,   276,   276,
     252,   272,   252,   252,   252,   272,   252,   252,   276,   279,
     279,   276,   252,   279,   276,   252,   276,   252,   276,   279,
     252,   252,   276,   276,   252,   279,   279,   276,   276,   279,
     276,   252,   279,   252,   252,   252,   279,   276,   252,   252,
     276,   252,   252,   276,   252,   276,   252,   276,   276,   254,
     276,   279,   253,   253,   252,   254,   254,   252,   254,   254,
     254,   254,   254,   254,   254,   254,   254,    13,   315,   259,
     259,   279,    47,   344,   253,   253,   252,   254,    60,    61,
     361,   254,    58,   366,   279,   349,   276,   276,   284,   279,
     276,   279,   284,   279,   276,   252,   252,   252,   252,   279,
     252,   252,   279,   252,   279,   252,   252,   279,   279,   252,
     252,   279,   252,   252,   252,   252,   279,   252,   279,   279,
     279,   252,   252,   279,   276,   276,   276,   252,   276,   279,
     252,   276,    75,   254,   254,   308,   299,   279,   279,   312,
      46,   348,   259,   339,   276,   279,   279,   367,   253,   371,
     362,   253,   371,   252,   252,   252,   252,   252,   252,   252,
     276,   276,   276,   276,   252,   276,   276,   252,   279,   276,
     279,   252,   276,   279,   279,   276,   276,   276,   276,   252,
     252,   252,   276,   276,   252,   276,   252,   252,   276,   276,
     259,   254,   259,   346,    14,    16,    18,    41,    44,    49,
     340,   252,   254,   252,   254,   371,   276,   349,   371,   279,
     349,   279,   276,   276,   279,   276,   276,   276,   252,   279,
     279,   252,   252,   252,   279,   252,   252,   279,   276,   279,
     252,   276,   276,   276,   252,    25,    44,   300,   313,   259,
     276,   279,   349,   252,   254,   349,   252,   254,   252,   276,
     279,   276,   279,   276,   276,   252,   276,   252,   276,    14,
      16,    18,    41,    44,    49,   314,   347,   254,   254,   276,
     368,   279,   363,   276,   252,   252,   279,   276,     4,   316,
     345,   254,   371,   254,   371,   276,   276,   252,   369,   349,
     364,   349,   252,   276,   371,   371,   276,   349,   349
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
     263,   263,   263,   263,   263,   263,   263,   270,   270,   270,
     270,   270,   271,   271,   271,   271,   271,   271,   272,   272,
     273,   273,   273,   273,   273,   274,   274,   275,   275,   276,
     276,   276,   276,   276,   276,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   278,   278,   280,   279,   281,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     282,   283,   284,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   286,   286,   286,   287,   287,   287,   287,
     288,   288,   289,   289,   289,   289,   290,   291,   293,   292,
     294,   294,   294,   295,   295,   297,   298,   299,   296,   300,
     300,   301,   301,   302,   302,   302,   302,   303,   303,   304,
     304,   304,   304,   305,   305,   306,   306,   306,   306,   307,
     307,   307,   308,   308,   308,   308,   310,   311,   312,   313,
     309,   314,   314,   314,   314,   314,   314,   315,   315,   316,
     316,   318,   317,   319,   319,   320,   320,   321,   322,   321,
     323,   324,   323,   326,   325,   327,   327,   327,   327,   327,
     327,   329,   330,   328,   331,   331,   333,   332,   334,   334,
     334,   334,   334,   334,   336,   337,   338,   339,   335,   340,
     340,   340,   340,   340,   340,   342,   341,   343,   343,   344,
     344,   345,   346,   347,   345,   348,   348,   349,   350,   349,
     351,   351,   351,   351,   352,   352,   353,   353,   353,   353,
     354,   354,   354,   354,   355,   355,   355,   355,   355,   356,
     356,   356,   358,   357,   359,   357,   360,   357,   361,   357,
     362,   357,   363,   357,   364,   357,   365,   357,   366,   357,
     367,   357,   368,   357,   369,   357,   370,   357,   371,   371,
     372,   372,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   373,   373,   374,   374,   375,   375
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
       5,     5,     5,    12,     7,    12,     7,     9,    10,     5,
       8,     8,    10,     5,     7,     5,     5,     5,     3,     3,
      10,     5,     5,     5,     3,    10,     5,     9,     7,     5,
       5,     7,     5,     3,     5,     5,     3,    12,    15,    11,
       5,     6,     5,     3,    11,    10,     5,     6,     9,     8,
       7,     9,    10,     9,    11,    12,    13,    11,     3,     9,
       5,     6,     7,     3,    11,     2,     3,     2,     2,     1,
       1,     3,     4,     4,     4,     4,     4,     4,     1,     1,
       2,     1,     2,     2,     8,     6,     6,     0,     1,     1,
       2,     2,     3,    10,     8,     8,     8,     3,     1,     1,
       6,     4,     4,     6,     6,     4,     6,     1,     4,     1,
       1,     1,     1,     3,     3,     6,     6,     8,     6,     4,
       6,     8,     4,     1,     3,     4,     4,     4,     4,     4,
       4,     4,     6,     8,     4,     4,     4,     4,     4,     6,
       1,     3,     1,     3,     4,     3,     3,     3,     3,     5,
       5,     5,     7,     3,     4,     5,     2,     1,     7,     6,
       6,     4,     6,     4,     6,    10,     4,     4,     4,     8,
       6,     4,     3,     3,     0,     4,     0,     4,     2,     3,
       3,     3,     3,     3,     3,     3,     4,     6,     1,     4,
       4,     6,     6,     1,     1,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     4,     4,     4,     4,     4,     4,     6,
       4,     4,     6,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     4,     3,     6,     6,     4,     4,     4,
       4,     6,     6,     8,     6,     8,     4,     4,     4,     8,
       4,     4,     4,     4,     1,     3,     4,     1,     3,     4,
       1,     3,     4,     1,     3,     6,     6,     4,     6,     6,
       6,     4,     8,     6,     8,     6,     4,     4,     4,     6,
       6,     6,     8,     4,     2,     5,     7,     3,     3,     3,
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

  case 156: /* statement: tSPLITVIEW tSET string_expression ',' string_expression ',' expression  */
                                                                           {add_command(cYABSPLITVIEWSET);}
    break;

  case 157: /* statement: tSPLITVIEW tSET string_expression ',' string_expression ',' expression ',' expression  */
                                                                                          {add_command(cYABSPLITVIEWMIN);}
    break;

  case 158: /* statement: tSTACKVIEW coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                     {add_command(cYABSTACKVIEW);}
    break;

  case 159: /* statement: tSTACKVIEW tSET string_expression ',' expression  */
                                                     {add_command(cYABSTACKVIEWSET);}
    break;

  case 160: /* statement: tCANVAS coordinates to coordinates ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABCANVAS);}
    break;

  case 161: /* statement: tREGION coordinates to coordinates ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABREGION);}
    break;

  case 162: /* statement: tLISTBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                   {add_command(cYABLISTBOX);}
    break;

  case 163: /* statement: tLISTBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABLISTBOXADD);}
    break;

  case 164: /* statement: tLISTBOX tADD string_expression ',' expression ',' string_expression  */
                                                                         {add_command(cYABLISTBOXADD2);}
    break;

  case 165: /* statement: tLISTBOX tREMOVE string_expression ',' string_expression  */
                                                             {add_command(cYABLISTBOXREMOVE);}
    break;

  case 166: /* statement: tLISTBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABLISTBOXREMOVE2);}
    break;

  case 167: /* statement: tLISTBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABLISTBOXSELECT);}
    break;

  case 168: /* statement: tLISTBOX tCLEAR string_expression  */
                                      {add_command(cYABLISTBOXCLEAR);}
    break;

  case 169: /* statement: tLISTBOX tSORT string_expression  */
                                     {add_command(cYABLISTSORT);}
    break;

  case 170: /* statement: tDROPBOX coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                          {add_command(cYABDROPBOX);}
    break;

  case 171: /* statement: tDROPBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABDROPBOXADD);}
    break;

  case 172: /* statement: tDROPBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABDROPBOXSELECT);}
    break;

  case 173: /* statement: tDROPBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABDROPBOXREMOVE);}
    break;

  case 174: /* statement: tDROPBOX tCLEAR string_expression  */
                                      {add_command(cYABDROPBOXCLEAR);}
    break;

  case 175: /* statement: tTREEBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                   {add_command(cYABTREEBOX);}
    break;

  case 176: /* statement: tTREEBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABTREEADD);}
    break;

  case 177: /* statement: tTREEBOX tADD string_expression ',' string_expression ',' string_expression ',' expression  */
                                                                                               {add_command(cYABTREEADDCHILD);}
    break;

  case 178: /* statement: tTREEBOX tADD string_expression ',' string_expression ',' expression  */
                                                                         {add_command(cYABTREEADDAT);}
    break;

  case 179: /* statement: tTREEBOX tREMOVE string_expression ',' string_expression  */
                                                             {add_command(cYABTREEREMOVE);}
    break;

  case 180: /* statement: tTREEBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABTREEREMOVE2);}
    break;

  case 181: /* statement: tTREEBOX tREMOVE string_expression ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABTREEREMOVECHILD);}
    break;

  case 182: /* statement: tTREEBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABTREESELECT);}
    break;

  case 183: /* statement: tTREEBOX tCLEAR string_expression  */
                                      {add_command(cYABTREECLEAR);}
    break;

  case 184: /* statement: tTREEBOX tEXPAND string_expression ',' string_expression  */
                                                             {add_command(cYABTREEEXPAND);}
    break;

  case 185: /* statement: tTREEBOX tCOLLAPSE string_expression ',' string_expression  */
                                                               {add_command(cYABTREECOLLAPSE);}
    break;

  case 186: /* statement: tTREEBOX tSORT string_expression  */
                                     {add_command(cYABTREESORT);}
    break;

  case 187: /* statement: tCOLUMNBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression ',' string_expression  */
                                                                                                                           {add_command(cYABCOLUMNBOX);}
    break;

  case 188: /* statement: tCOLUMNBOX tCOLUMN string_expression ',' string_expression ',' expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                                                                 {add_command(cYABCOLUMNBOXCOLUMN);}
    break;

  case 189: /* statement: tCOLUMNBOX tADD string_expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                         {add_command(cYABCOLUMNBOXADD);}
    break;

  case 190: /* statement: tCOLUMNBOX tREMOVE string_expression ',' expression  */
                                                        {add_command(cYABCOLUMNBOXREMOVE);}
    break;

  case 191: /* statement: tCOLUMNBOX tREMOVE tCOLUMN string_expression ',' expression  */
                                                                {add_command(cYABCOLUMNBOXREMOVECOLUMN);}
    break;

  case 192: /* statement: tCOLUMNBOX tSELECT string_expression ',' expression  */
                                                        {add_command(cYABCOLUMNBOXSELECT);}
    break;

  case 193: /* statement: tCOLUMNBOX tCLEAR string_expression  */
                                        {add_command(cYABCOLUMNBOXCLEAR);}
    break;

  case 194: /* statement: tCOLUMNBOX tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                            {add_command(cYABCOLUMNBOXCOLOUR);}
    break;

  case 195: /* statement: tCALENDAR coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                  {add_command(cYABCALENDAR);}
    break;

  case 196: /* statement: tCALENDAR tSET string_expression ',' string_expression  */
                                                           {add_command(cYABCALENDARSET);}
    break;

  case 197: /* statement: tCOLORCONTROL coordinates ',' string_expression ',' string_expression  */
                                                                          {add_command(cYABCOLORCONTROL);}
    break;

  case 198: /* statement: tCOLORCONTROL tSET string_expression ',' expression ',' expression ',' expression  */
                                                                                      {add_command(cYABCOLORCONTROLSET);}
    break;

  case 199: /* statement: tMENU string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                              {add_command(cYABMENU);}
    break;

  case 200: /* statement: tMENU tSET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cYABMENURADIO);}
    break;

  case 201: /* statement: tMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                   {add_command(cYABMENUOPTION);}
    break;

  case 202: /* statement: tSUBMENU string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                       {add_command(cYABSUBMENU);}
    break;

  case 203: /* statement: tSUBMENU tSET string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                               {add_command(cYABSUBMENURADIO);}
    break;

  case 204: /* statement: tSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                            {add_command(cYABSUBMENUOPTION);}
    break;

  case 205: /* statement: tSUBSUBMENU string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                                {add_command(cYABSUBSUBMENU);}
    break;

  case 206: /* statement: tSUBSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                                     {add_command(cYABSUBSUBMENUOPTION);}
    break;

  case 207: /* statement: tSUBSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                                        {add_command(cYABSUBSUBMENURADIO);}
    break;

  case 208: /* statement: tCLIPBOARD tCOPY string_expression  */
                                       {add_command(cYABCLIPBOARDCOPY);}
    break;

  case 209: /* statement: tATTRIBUTE tSET string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                        {add_command(cYABATTRIBUTESET);}
    break;

  case 210: /* statement: tATTRIBUTE tCLEAR string_expression ',' string_expression  */
                                                              {add_command(cYABATTRIBUTECLEAR);}
    break;

  case 211: /* statement: tBITMAP expression ',' expression ',' string_expression  */
                                                            {add_command(cYABBITMAP);}
    break;

  case 212: /* statement: tBITMAP tGET string_expression ',' string_expression ',' string_expression  */
                                                                               {add_command(cYABBITMAPGET);}
    break;

  case 213: /* statement: tBITMAP tREMOVE string_expression  */
                                      {add_command(cYABBITMAPREMOVE);}
    break;

  case 214: /* statement: tDRAW tBITMAP expression ',' expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                              {add_command(cYABBITMAPDRAW);}
    break;

  case 215: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 216: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 217: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 218: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 219: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 220: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 221: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 222: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 223: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 224: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 225: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 226: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 227: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 228: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 229: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 230: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 231: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 232: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 233: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 234: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 235: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 236: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 237: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 238: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 239: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 240: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 241: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 242: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 243: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 244: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 245: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 246: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 247: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 250: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 251: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 252: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 253: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 254: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 255: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 256: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 257: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 258: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 259: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 261: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 262: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 263: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 265: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 266: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 267: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 268: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 269: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 270: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 271: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 272: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 273: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 274: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 275: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 276: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 277: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 278: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 279: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 280: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 281: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 282: /* string_function: tSTRING2 '(' expression ',' string_expression ')'  */
                                                      {create_function(fSTRING);}
    break;

  case 283: /* string_function: tREPLACE '(' string_expression ',' string_expression ',' string_expression ')'  */
                                                                                    {create_function(fREPLACE);}
    break;

  case 284: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 285: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 286: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 287: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 288: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 289: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 290: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 291: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 292: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 293: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 294: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 295: /* string_function: tTEXTCONTROL tGET string_expression  */
                                        {create_function(fYABTEXTCONTROLGET);}
    break;

  case 296: /* string_function: tTEXTEDIT tGET string_expression  */
                                     {create_function(fYABTEXTEDITGET);}
    break;

  case 297: /* string_function: tTEXTCONTROL tGETS string_expression  */
                                                         {create_function(fYABTEXTCONTROLGET);}
    break;

  case 298: /* string_function: tTEXTEDIT tGETS string_expression  */
                                                      {create_function(fYABTEXTEDITGET);}
    break;

  case 299: /* string_function: tLISTBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABLISTBOXGET);}
    break;

  case 300: /* string_function: tDROPBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABDROPBOXGET);}
    break;

  case 301: /* string_function: tTREEBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABTREEBOXGET);}
    break;

  case 302: /* string_function: tCOLUMNBOX tGETS string_expression ',' expression ',' expression  */
                                                                                     {create_function(fYABCOLUMNBOXGET);}
    break;

  case 303: /* string_function: tCALENDAR tGET string_expression  */
                                                     {create_function(fYABCALENDARGET);}
    break;

  case 304: /* string_function: tTRANSLATE '(' string_expression ')'  */
                                         {create_function(fYABTRANSLATE);}
    break;

  case 305: /* string_function: tMENU tTRANSLATE '(' string_expression ')'  */
                                               {create_function(fYABMENUTRANSLATE);}
    break;

  case 306: /* string_function: tCLIPBOARD tPASTE  */
                      {create_function(fYABCLIPBOARDPASTE);}
    break;

  case 307: /* string_function: tMESSAGE  */
             {create_function(fYABMESSAGE);}
    break;

  case 308: /* string_function: tATTRIBUTE tGETS '(' string_expression ',' string_expression ')'  */
                                                                     {create_function(fYABATTRIBUTEGET);}
    break;

  case 309: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 310: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 311: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 312: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 313: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 314: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 315: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 316: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 317: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 318: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 319: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 320: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 321: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 322: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 323: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 324: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 325: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 326: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 327: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 328: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 329: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 330: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 331: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 332: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 333: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 334: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 335: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 336: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 337: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 338: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 339: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 340: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 341: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 342: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 343: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 344: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 345: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 346: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 347: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 348: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 349: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 350: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 351: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 352: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 353: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 354: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 355: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 356: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 357: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 360: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 361: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 363: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 364: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 365: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 366: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 367: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 368: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 369: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 370: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 371: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 372: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 373: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 374: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 375: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 376: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 377: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 378: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 379: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 380: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 381: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 382: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 383: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 384: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 385: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 386: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 387: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 388: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 389: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 390: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 391: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 392: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 393: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 394: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 395: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 396: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 397: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 398: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 399: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 400: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 401: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 402: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 403: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 404: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 405: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 406: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 407: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 408: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 409: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 410: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 411: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 412: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 413: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 414: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 415: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 416: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 417: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 418: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 419: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 420: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 421: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 422: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 423: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 424: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 425: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 426: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 427: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 428: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 429: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 430: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 431: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 432: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 433: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 434: /* function: tWINDOW tCOUNT  */
                   {create_function(fYABNUMWINDOWS);}
    break;

  case 435: /* function: tWINDOW tGET string_expression ',' string_expression  */
                                                         {create_function(fYABWINDOWGET);}
    break;

  case 436: /* function: tATTRIBUTE tGET '(' string_expression ',' string_expression ')'  */
                                                                    {create_function(fYABATTRIBUTEGETNUM);}
    break;

  case 437: /* function: tLISTBOX tCOUNT string_expression  */
                                                      {create_function(fYABLISTBOXCOUNT);}
    break;

  case 438: /* function: tLISTBOX tGET string_expression  */
                                                    {create_function(fYABLISTBOXSELECTED);}
    break;

  case 439: /* function: tDROPBOX tCOUNT string_expression  */
                                                      {create_function(fYABDROPBOXCOUNT);}
    break;

  case 440: /* function: tDROPBOX tGET string_expression  */
                                                    {create_function(fYABDROPBOXSELECTED);}
    break;

  case 441: /* function: tTREEBOX tCOUNT string_expression  */
                                                      {create_function(fYABTREEBOXCOUNT);}
    break;

  case 442: /* function: tTREEBOX tGET string_expression  */
                                                    {create_function(fYABTREEBOXSELECTED);}
    break;

  case 443: /* function: tCOLUMNBOX tCOUNT string_expression  */
                                                        {create_function(fYABCOLUMNBOXCOUNT);}
    break;

  case 444: /* function: tCOLUMNBOX tCOUNT tCOLUMN string_expression  */
                                                                {create_function(fYABCOLUMNBOXCOUNTCOLUMNS);}
    break;

  case 445: /* function: tCOLUMNBOX tGET string_expression  */
                                                      {create_function(fYABCOLUMNBOXSELECTED);}
    break;

  case 446: /* function: tCOLORCONTROL tGET string_expression ',' string_expression  */
                                                                               {create_function(fYABCOLORCONTROLGET);}
    break;

  case 447: /* function: tSPLITVIEW tGET string_expression ',' string_expression  */
                                                                            {create_function(fYABSPLITVIEWGET);}
    break;

  case 448: /* function: tSTACKVIEW tGET string_expression  */
                                                      {create_function(fYABSTACKVIEWGET);}
    break;

  case 449: /* function: tTABVIEW tGET string_expression  */
                                                    {create_function(fYABTABVIEWGET);}
    break;

  case 450: /* function: tDRAW tGET string_expression ',' string_expression  */
                                                       {create_function(fYABDRAWGET);}
    break;

  case 451: /* function: tDRAW tGET string_expression ',' string_expression ',' string_expression  */
                                                                             {create_function(fYABDRAWGETTEXT);}
    break;

  case 452: /* function: tBFILESIZE '(' string_expression ')'  */
                                         {create_function(fYABBFILESIZE);}
    break;

  case 453: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 454: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 455: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 456: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 457: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 458: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 459: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 460: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 461: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 462: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 463: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 464: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 465: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 466: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 467: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 468: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 475: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 476: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 477: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 478: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 479: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 480: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 481: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 482: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 483: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 484: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 485: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 486: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 489: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 490: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 491: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 492: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 495: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 496: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 497: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 498: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 502: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 503: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 504: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 505: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 506: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 507: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 508: /* $@17: %empty  */
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

  case 509: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 510: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 511: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 512: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 513: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 514: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 515: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 516: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 517: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 519: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 520: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 521: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 522: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 528: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 529: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 531: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 533: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 535: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 536: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 537: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 538: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 539: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 540: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 541: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 542: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 544: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 545: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 546: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 548: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 549: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 550: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 551: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 552: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 553: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 554: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 555: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 556: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 557: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 559: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 560: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 561: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 562: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 563: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 564: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 565: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 567: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 568: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 572: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 573: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 578: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 580: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 581: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 582: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 583: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 586: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 587: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 588: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 589: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 590: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 591: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 592: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 593: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 597: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 598: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 599: /* using: %empty  */
       {create_print('d');}
    break;

  case 600: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 601: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 602: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 603: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 604: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 605: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 606: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 607: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 608: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 609: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 610: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 611: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 612: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 613: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 614: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 615: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 616: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 617: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 618: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 619: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 620: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 621: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 622: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 623: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 624: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 625: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 626: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 627: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 628: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 629: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 630: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 631: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 632: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 633: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 634: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 635: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 636: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 637: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 638: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 639: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 640: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 641: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 642: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 643: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 646: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 647: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 648: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 649: /* gosub_list: gosub_list ',' symbol_or_lineno  */
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

