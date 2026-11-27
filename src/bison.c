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
  YYSYMBOL_tATTRIBUTE = 163,               /* tATTRIBUTE  */
  YYSYMBOL_tBITMAP = 164,                  /* tBITMAP  */
  YYSYMBOL_tSIN = 165,                     /* tSIN  */
  YYSYMBOL_tASIN = 166,                    /* tASIN  */
  YYSYMBOL_tCOS = 167,                     /* tCOS  */
  YYSYMBOL_tACOS = 168,                    /* tACOS  */
  YYSYMBOL_tTAN = 169,                     /* tTAN  */
  YYSYMBOL_tATAN = 170,                    /* tATAN  */
  YYSYMBOL_tEXP = 171,                     /* tEXP  */
  YYSYMBOL_tLOG = 172,                     /* tLOG  */
  YYSYMBOL_tSQRT = 173,                    /* tSQRT  */
  YYSYMBOL_tSQR = 174,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 175,                   /* tMYEOF  */
  YYSYMBOL_tABS = 176,                     /* tABS  */
  YYSYMBOL_tSIG = 177,                     /* tSIG  */
  YYSYMBOL_tINT = 178,                     /* tINT  */
  YYSYMBOL_tCEIL = 179,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 180,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 181,                    /* tFRAC  */
  YYSYMBOL_tROUND = 182,                   /* tROUND  */
  YYSYMBOL_tMOD = 183,                     /* tMOD  */
  YYSYMBOL_tRAN = 184,                     /* tRAN  */
  YYSYMBOL_tVAL = 185,                     /* tVAL  */
  YYSYMBOL_tLEFT = 186,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 187,                   /* tRIGHT  */
  YYSYMBOL_tMID = 188,                     /* tMID  */
  YYSYMBOL_tLEN = 189,                     /* tLEN  */
  YYSYMBOL_tMIN = 190,                     /* tMIN  */
  YYSYMBOL_tMAX = 191,                     /* tMAX  */
  YYSYMBOL_tSTR = 192,                     /* tSTR  */
  YYSYMBOL_tINKEY = 193,                   /* tINKEY  */
  YYSYMBOL_tCHR = 194,                     /* tCHR  */
  YYSYMBOL_tASC = 195,                     /* tASC  */
  YYSYMBOL_tHEX = 196,                     /* tHEX  */
  YYSYMBOL_tDEC = 197,                     /* tDEC  */
  YYSYMBOL_tBIN = 198,                     /* tBIN  */
  YYSYMBOL_tUPPER = 199,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 200,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 201,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 202,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 203,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 204,                /* tMOUSEMOD  */
  YYSYMBOL_tTRIM = 205,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 206,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 207,                   /* tRTRIM  */
  YYSYMBOL_tSTRING2 = 208,                 /* tSTRING2  */
  YYSYMBOL_tREPLACE = 209,                 /* tREPLACE  */
  YYSYMBOL_tINSTR = 210,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 211,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 212,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 213,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 214,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 215,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 216,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 217,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 218,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 219,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 220,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 221,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 222,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 223,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 224,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 225,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 226,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 227,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 228,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 229,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 230,                    /* tDATE  */
  YYSYMBOL_tTIME = 231,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 232,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 233,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 234,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 235,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 236,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 237,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 238,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 239, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 240,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 241, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 242,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 243,                   /* tEVAL2  */
  YYSYMBOL_tARGUMENT = 244,                /* tARGUMENT  */
  YYSYMBOL_245_ = 245,                     /* '-'  */
  YYSYMBOL_246_ = 246,                     /* '+'  */
  YYSYMBOL_247_ = 247,                     /* '*'  */
  YYSYMBOL_248_ = 248,                     /* '/'  */
  YYSYMBOL_UMINUS = 249,                   /* UMINUS  */
  YYSYMBOL_250_ = 250,                     /* ';'  */
  YYSYMBOL_251_ = 251,                     /* ','  */
  YYSYMBOL_252_ = 252,                     /* '('  */
  YYSYMBOL_253_ = 253,                     /* ')'  */
  YYSYMBOL_254_ = 254,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 255,                 /* $accept  */
  YYSYMBOL_program_or_expression = 256,    /* program_or_expression  */
  YYSYMBOL_program = 257,                  /* program  */
  YYSYMBOL_statement_list = 258,           /* statement_list  */
  YYSYMBOL_259_1 = 259,                    /* $@1  */
  YYSYMBOL_260_2 = 260,                    /* $@2  */
  YYSYMBOL_assignment = 261,               /* assignment  */
  YYSYMBOL_statement = 262,                /* statement  */
  YYSYMBOL_263_3 = 263,                    /* $@3  */
  YYSYMBOL_264_4 = 264,                    /* $@4  */
  YYSYMBOL_265_5 = 265,                    /* $@5  */
  YYSYMBOL_266_6 = 266,                    /* $@6  */
  YYSYMBOL_267_7 = 267,                    /* $@7  */
  YYSYMBOL_268_8 = 268,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 269,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 270,        /* string_assignment  */
  YYSYMBOL_to = 271,                       /* to  */
  YYSYMBOL_open_clause = 272,              /* open_clause  */
  YYSYMBOL_seek_clause = 273,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 274,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 275,        /* string_expression  */
  YYSYMBOL_string_function = 276,          /* string_function  */
  YYSYMBOL_number_assignment = 277,        /* number_assignment  */
  YYSYMBOL_expression = 278,               /* expression  */
  YYSYMBOL_279_9 = 279,                    /* $@9  */
  YYSYMBOL_280_10 = 280,                   /* $@10  */
  YYSYMBOL_arrayref = 281,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 282,          /* string_arrayref  */
  YYSYMBOL_coordinates = 283,              /* coordinates  */
  YYSYMBOL_function = 284,                 /* function  */
  YYSYMBOL_const = 285,                    /* const  */
  YYSYMBOL_number = 286,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 287,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 288,                  /* dimlist  */
  YYSYMBOL_function_or_array = 289,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 290,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 291,                /* call_list  */
  YYSYMBOL_292_11 = 292,                   /* $@11  */
  YYSYMBOL_calls = 293,                    /* calls  */
  YYSYMBOL_call_item = 294,                /* call_item  */
  YYSYMBOL_function_definition = 295,      /* function_definition  */
  YYSYMBOL_296_12 = 296,                   /* $@12  */
  YYSYMBOL_297_13 = 297,                   /* $@13  */
  YYSYMBOL_298_14 = 298,                   /* $@14  */
  YYSYMBOL_endsub = 299,                   /* endsub  */
  YYSYMBOL_function_name = 300,            /* function_name  */
  YYSYMBOL_export = 301,                   /* export  */
  YYSYMBOL_local_list = 302,               /* local_list  */
  YYSYMBOL_local_item = 303,               /* local_item  */
  YYSYMBOL_static_list = 304,              /* static_list  */
  YYSYMBOL_static_item = 305,              /* static_item  */
  YYSYMBOL_paramlist = 306,                /* paramlist  */
  YYSYMBOL_paramitem = 307,                /* paramitem  */
  YYSYMBOL_for_loop = 308,                 /* for_loop  */
  YYSYMBOL_309_15 = 309,                   /* $@15  */
  YYSYMBOL_310_16 = 310,                   /* $@16  */
  YYSYMBOL_311_17 = 311,                   /* $@17  */
  YYSYMBOL_312_18 = 312,                   /* $@18  */
  YYSYMBOL_next = 313,                     /* next  */
  YYSYMBOL_step_part = 314,                /* step_part  */
  YYSYMBOL_next_symbol = 315,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 316,  /* switch_number_or_string  */
  YYSYMBOL_317_19 = 317,                   /* $@19  */
  YYSYMBOL_sep_list = 318,                 /* sep_list  */
  YYSYMBOL_number_or_string = 319,         /* number_or_string  */
  YYSYMBOL_case_list = 320,                /* case_list  */
  YYSYMBOL_321_20 = 321,                   /* $@20  */
  YYSYMBOL_default = 322,                  /* default  */
  YYSYMBOL_323_21 = 323,                   /* $@21  */
  YYSYMBOL_do_loop = 324,                  /* do_loop  */
  YYSYMBOL_325_22 = 325,                   /* $@22  */
  YYSYMBOL_loop = 326,                     /* loop  */
  YYSYMBOL_while_loop = 327,               /* while_loop  */
  YYSYMBOL_328_23 = 328,                   /* $@23  */
  YYSYMBOL_329_24 = 329,                   /* $@24  */
  YYSYMBOL_wend = 330,                     /* wend  */
  YYSYMBOL_repeat_loop = 331,              /* repeat_loop  */
  YYSYMBOL_332_25 = 332,                   /* $@25  */
  YYSYMBOL_until = 333,                    /* until  */
  YYSYMBOL_if_clause = 334,                /* if_clause  */
  YYSYMBOL_335_26 = 335,                   /* $@26  */
  YYSYMBOL_336_27 = 336,                   /* $@27  */
  YYSYMBOL_337_28 = 337,                   /* $@28  */
  YYSYMBOL_338_29 = 338,                   /* $@29  */
  YYSYMBOL_endif = 339,                    /* endif  */
  YYSYMBOL_short_if = 340,                 /* short_if  */
  YYSYMBOL_341_30 = 341,                   /* $@30  */
  YYSYMBOL_end_of_if = 342,                /* end_of_if  */
  YYSYMBOL_else_part = 343,                /* else_part  */
  YYSYMBOL_elsif_part = 344,               /* elsif_part  */
  YYSYMBOL_345_31 = 345,                   /* $@31  */
  YYSYMBOL_346_32 = 346,                   /* $@32  */
  YYSYMBOL_maybe_then = 347,               /* maybe_then  */
  YYSYMBOL_inputlist = 348,                /* inputlist  */
  YYSYMBOL_349_33 = 349,                   /* $@33  */
  YYSYMBOL_input = 350,                    /* input  */
  YYSYMBOL_readlist = 351,                 /* readlist  */
  YYSYMBOL_readitem = 352,                 /* readitem  */
  YYSYMBOL_datalist = 353,                 /* datalist  */
  YYSYMBOL_printlist = 354,                /* printlist  */
  YYSYMBOL_using = 355,                    /* using  */
  YYSYMBOL_inputbody = 356,                /* inputbody  */
  YYSYMBOL_357_34 = 357,                   /* $@34  */
  YYSYMBOL_358_35 = 358,                   /* $@35  */
  YYSYMBOL_359_36 = 359,                   /* $@36  */
  YYSYMBOL_360_37 = 360,                   /* $@37  */
  YYSYMBOL_361_38 = 361,                   /* $@38  */
  YYSYMBOL_362_39 = 362,                   /* $@39  */
  YYSYMBOL_363_40 = 363,                   /* $@40  */
  YYSYMBOL_364_41 = 364,                   /* $@41  */
  YYSYMBOL_365_42 = 365,                   /* $@42  */
  YYSYMBOL_366_43 = 366,                   /* $@43  */
  YYSYMBOL_367_44 = 367,                   /* $@44  */
  YYSYMBOL_368_45 = 368,                   /* $@45  */
  YYSYMBOL_369_46 = 369,                   /* $@46  */
  YYSYMBOL_prompt = 370,                   /* prompt  */
  YYSYMBOL_printintro = 371,               /* printintro  */
  YYSYMBOL_hashed_number = 372,            /* hashed_number  */
  YYSYMBOL_goto_list = 373,                /* goto_list  */
  YYSYMBOL_gosub_list = 374                /* gosub_list  */
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
#define YYFINAL  248
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   15174

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  255
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  643
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2039

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   500


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
       2,     2,     2,     2,     2,   254,     2,     2,     2,     2,
     252,   253,   247,   246,   251,   245,     2,   248,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   250,
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
     249
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
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   599,
     600,   603,   603,   604,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   635,   636,   639,   642,   645,
     648,   649,   650,   651,   652,   653,   654,   655,   656,   657,
     658,   659,   660,   661,   662,   663,   664,   665,   666,   667,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,   682,   683,   684,   685,   686,   687,
     688,   689,   690,   691,   692,   693,   694,   695,   696,   697,
     698,   699,   700,   701,   702,   703,   704,   705,   706,   707,
     708,   709,   710,   711,   712,   713,   714,   715,   716,   717,
     718,   721,   722,   725,   728,   729,   730,   731,   732,   733,
     734,   735,   736,   737,   738,   739,   740,   743,   744,   745,
     748,   749,   750,   751,   754,   755,   758,   759,   760,   761,
     764,   767,   770,   770,   773,   774,   775,   778,   779,   782,
     783,   786,   782,   791,   792,   795,   796,   799,   800,   801,
     802,   805,   806,   809,   810,   811,   812,   815,   816,   819,
     820,   821,   822,   825,   826,   827,   830,   831,   832,   833,
     836,   837,   842,   857,   836,   862,   863,   864,   865,   866,
     867,   870,   871,   874,   875,   880,   880,   884,   885,   888,
     889,   893,   895,   894,   899,   900,   900,   904,   904,   910,
     911,   912,   913,   914,   915,   919,   920,   919,   926,   927,
     931,   931,   936,   937,   938,   939,   940,   941,   944,   945,
     945,   947,   944,   951,   952,   953,   954,   955,   956,   959,
     959,   964,   965,   968,   969,   972,   974,   976,   973,   980,
     981,   984,   985,   985,   988,   989,   991,   992,   996,   997,
    1000,  1001,  1003,  1004,  1008,  1009,  1010,  1011,  1014,  1015,
    1016,  1017,  1018,  1021,  1022,  1023,  1026,  1026,  1027,  1027,
    1028,  1028,  1029,  1029,  1030,  1030,  1031,  1031,  1032,  1032,
    1033,  1033,  1034,  1034,  1035,  1035,  1036,  1036,  1037,  1037,
    1038,  1038,  1041,  1042,  1045,  1046,  1047,  1048,  1049,  1050,
    1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,  1061,  1062,
    1064,  1065,  1068,  1069
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
  "tPASTE", "tTRANSLATE", "tATTRIBUTE", "tBITMAP", "tSIN", "tASIN", "tCOS",
  "tACOS", "tTAN", "tATAN", "tEXP", "tLOG", "tSQRT", "tSQR", "tMYEOF",
  "tABS", "tSIG", "tINT", "tCEIL", "tFLOOR", "tFRAC", "tROUND", "tMOD",
  "tRAN", "tVAL", "tLEFT", "tRIGHT", "tMID", "tLEN", "tMIN", "tMAX",
  "tSTR", "tINKEY", "tCHR", "tASC", "tHEX", "tDEC", "tBIN", "tUPPER",
  "tLOWER", "tMOUSEX", "tMOUSEY", "tMOUSEB", "tMOUSEMOD", "tTRIM",
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

#define YYPACT_NINF (-1589)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-549)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -97, 12709, 10578, 12142,    68,     5,    74,   -53,   -49, -1589,
   -1589, -1589, -1589, -1589,   119,   119,   119,  7872, -1589, -1589,
   -1589, 12142, -1589, -1589, 12142,    76,   117, -1589, -1589, -1589,
   10578,   -33, -1589, 10578,   246, -1589, 10578, 10578, 10578,   500,
      33,   119,  3644,  2303,  4161,   205, 10578,  6888,  8118,    12,
      32, 10578, -1589,    85, 12142, 12142, 12142,    46, 10578,  2459,
   10578, 10578,  8364,  8610,  7134,  5904, 10578,  6396,  8856,  9102,
   11189, 12142, 12142,   -13,  6642,  9348, 10578,  9594, 10578, 10578,
    5658,  6150,  5166,  5412,  9840, 10086, 11316, 11434, 11552,    -1,
      14,  7380,   -72,   -54,   -29,   -14,    -8,  4161, 12142, 12142,
   12142, -1589,   222, -1589, -1589,   127, -1589, -1589, -1589, -1589,
     135,   178, -1589,   308, -1589, -1589, -1589, -1589, -1589, -1589,
   -1589, -1589,    92,   102, -1589, -1589, -1589, -1589,   123,   131,
     134,   147, 10578,   168,   213,   234,   237,   255,   282,   326,
     301,   334,   344,   392,   183,   395,   -93,   -68,    24,    45,
     112,   115,   251,   567,   520,   542,   483,     0,   493,   495,
     497,   515,   529,   533,   546,   597,   608,   612,   618,   622,
     648,   654,   668,   669,   679,   690,   698,   699,   711,   712,
     723,   735,   756,   762,   763,   773,   775,   790,   799,   800,
     811,   813,   814,   821,   824,   830,   834,   842,   870,   872,
     886,   929,   930,   931,   957,   970,   972,   973,   984,   986,
     987,   988,  1000,  1013,  1024,  1025,  1032,  1045,  1057,  1067,
    1075,  1077,  1088,  1092,  1099,  1102,  1127,  1137, 10578, 10578,
     142, -1589,   254, -1589, -1589, -1589, -1589,   562,   616,   628,
     652,   703, 12142,   -35,   802,   135,   178,   874, -1589, 10578,
   -1589, 12142, -1589,  1144, 10578, 12494, -1589, -1589, -1589, -1589,
   -1589,   484,    90,   539,   571,   864, -1589, 10578, -1589,   864,
   -1589, -1589, 10578, 12494,   531,  1138,  1083,  1139,     8, 10578,
     -11,   142,  1946,  1155,  1162,   913,  1946,   142,  1425,   142,
    9616,  1170,  1184,   921, -1589, -1589,   997,   997, -1589, -1589,
    1004, -1589,  7626, 12142, 10578,     6,  1946,  1011,   326, -1589,
   -1589, -1589,  1035, 10578, 12142, 12142, 12142,  9862, -1589, 10578,
   -1589,    -2, 12142,  1141, -1589, -1589, 10578, 10332, -1589, -1589,
    1946, -1589, -1589,   864,    -6,    -6, -1589,    -2, 10578, 10578,
   10578, 10578, 10578, 10578, 10578, 12142, 12142, 10578, 10578, 10578,
   10578, 10578,    -2,    -2, 12142,  1157, 12142,  1172, 12142, 12142,
      -2, 12142, 12142, 12142, 12142,    -2,  1186, 12142, 12142, 12142,
      -2, 12142,    -2, 12142,  1204, 12142,  -146,   -42,    -5, 12142,
   12142, 12142, 12142, 12142,    -2, 12142,    -2,    -2, 12142,    -2,
      -2,    -2, 12142, 12142, 12142, 12142, 12142,    -2, 12142, 12142,
   12142, 12142,    -2, 12142, 12142, 12142, 12142, 12142, 12142, 12142,
      -2, 12142, 12142, 12142, 11670, 12142, 12142,    -2, 12142,  1222,
   12142,  1230, 12142,    -4, 12142,    63, 12142,   190, 12142, 12142,
   12142, 12142, 12142, 10108,  1175,  1175,  1175,  4413, 12142,   111,
    1231,   864,   210,   306, -1589,  1165, 10578, 10578, 10578, 10578,
   12142, -1589, -1589, -1589, 10578, 10578,  1355, 10578, 10578, 10578,
   10578,  3909,  4161, 12142, -1589,   593,   593, 10578, 10578, 12142,
   12142, 12142, 12142, 12142, 12142, 12142, 12142, 12142, 12142, 12142,
   12142, 12142, 12142, 12142, 12142, 11788, 12142, 12142, 12142,  1240,
   -1589, 12142,  1241,  1256, 10578, 10578, 10578, 10578, 10578, 10578,
   10578, 10578, 10578, 10578,  4161, 10578, 10578, 10578, 10578, 10578,
   10578, 10578, 10578,  4664, 12142, 12142, 12142, 12142, 12142, 10578,
   10578, 10578,  4915, 10578, 12142, 10578, 12142, 10578, 12142, 12142,
   10711, 10821, 10950, 11060, 12142, 12142, 12142, 10578, 12142, 12142,
   12142, 12142, 12142, 12142,  4161, 12142, -1589, -1589, 12142, 10578,
   12142, 12142, 12142, 12142, 12142,  1168,  1238, 12142,  1175, 12142,
    1175, 12142, 12142, 12142,  1439,   121,   906, 12142, 12142, 12142,
   12142, 12142, 12142, 12142, 12142, -1589, -1589, -1589, 10578, 10578,
   10578, 10578, 10578, 10578, 10578, 10578, 10578, 10578, 10578, 10578,
     -24, -1589, -1589, -1589,  1946,  1261,   864,  1269,  1462,  1946,
     266, -1589, -1589, -1589, -1589,  1303,  1340,  1313, -1589,  1343,
    1344,  1338, -1589,   142,  1946,  1358, -1589,   142,  1946,  1194,
     607,  1567, 12494, 10578,  1370, 12142, -1589, -1589, 10578,   142,
     594,   349,  1372,  1582,  1391,     9, -1589,  1637, -1589, -1589,
     697, 10578, 10578, -1589, -1589,   500, -1589, -1589,    51, 10354,
     864,  1946,   524, 11906, 10578,    -2,   864,   864,   327, 10578,
   -1589,   -11, -1589, -1589, 10578,   434, 12142, -1589, 10578,    -2,
   10578, 10578, 10578,  1398,    -2,  1406,    -2,  1410,    -2,    -2,
     453,   864,  1416,  1423,    -2,    -2, 10600, 10578, 10578,   502,
   12142,   551, 12142,   864,   643, 10578,   644,   864,   694,   738,
   10578, 12142,   787,   794,   795, 10578,   798, 10578,   808, 12142,
     816, 10578, 12142, 12142,   826,   829,   833,   837,   844, 10578,
     850, 10578, 10578,   856, 10578, 10578, 10578,   864,   858,   860,
     864,   862, 10578,   864,   866,   875,   882, 10578,   864,   888,
     894,   864,   896,   898,   904, 10578,   910,   864,   911, 12142,
     912,   920,   922, 10578,   928, 12142,   955, 12142,   956, 12142,
    1003, 12142,  1010, 12142,   864,  1012,  1034,  1049,   864, 10578,
    1444,  1424,  1426,  1447, -1589,   947,    22, 10578, 10578, 10578,
   10578, -1589,  1448,    -2,    -2,  1946,   864,   715,  1452,  1455,
   10638, 12365,  1140, 12629, 12844, 12919,  1463,    99,  1467,  1472,
    1050,  1482,  1491,  1500,  1501,  1493,  1505,    -2, 13030,  1053,
      28,   864,   864,   864,   864,   864,   864,  1060,   864,   864,
    1062,   864,   864,  1066,   864, 12142,   864,  1070,   864,  1072,
   12142,    39, 12142, 12142,  1156,  1171,  1196,  1456,  1502,   620,
    1544,   651,  1688,  1755,  1504,  1802,  1837,  1962,  1988,  2023,
    2045,  2077, 13050, -1589,  2092,    55,  1079,  1082,  1085,    87,
   13084, 13105,   378,   666, -1589,  2174,  2368,   141,  2521,  -160,
    2563,   161,   184, -1589,   209, -1589,   263, -1589,   309, -1589,
     367,   381,   400,   435, 13120,  1095,  1096,  1097,   454,   498,
     504,   509,  1516,   -16,  1533,  1534,   513,  2592,   519,    88,
    1104,  1106,  1107, -1589, -1589,  1118,   -19,  1120,   120,  1122,
     527,   547, -1589, -1589,   864,   864,   864,   864,   864,   864,
     864, -1589, 10578, 10578,  1323,   810,  1727,   369,   101,   186,
     -40, -1589,   -46,   -46,  1439,  1439, -1589, -1589, -1589, 12494,
   -1589, -1589, 10578, -1589, -1589, -1589, -1589,   119,   119, -1589,
   -1589,   539, -1589, -1589,   571, 10578, -1589,  1740, -1589, -1589,
   -1589, -1589, -1589, -1589, -1589, -1589,   682, 13135, 10578,   241,
    2612, 12260, -1589, -1589, 10578, 10578,  1543, 12142, -1589, -1589,
   10578, -1589,   729,  1554,  1561,  1572,  1604, 13150, 13165,  1608,
    1610, -1589, -1589, -1589, 10578,  1711,  1737, -1589,  1129, 13180,
   10578, 12142,  1946, -1589, -1589, 12142,  1130, -1589, 10578, 13195,
   13216,  1606, 12142, 10578, 10578, 10578, 12142, 10578, 10578, 10578,
   10578, 10578, 10578, 10578, 10578,  1611,  1617, 10578,  1131, 10578,
    1159, 10578,  1619, 12142, 12142, 12142,  1620,  1160, 12142, 12142,
   10578,  1631, 12142,  1633, 10578,  1169, 12142, 13236,   864,   864,
   12142, 12142, 10578, 12142, 10578,  1636, 12142,  1639,  1642, 10578,
    1646,  1648,  1651, 10578, 10578, 10578,  1652, 12142, 10578, 10578,
    1653, 12142, 10578, 12142, 12142, 10578,  1664, 12142, 10578,  1189,
   10578, 12142, 10578,  1665, 12142,  1199, 10578,  1200, 10578,  1201,
   12142,  1207, 12142,  1208, 12142, 12142, 12142, 13251, -1589, 10578,
   10578, 10578, -1589, -1589,   142,  1946,   142,  1946, 13270, 13381,
   12494, 10578, 10578, 10578, -1589, -1589, -1589, -1589, -1589, 10578,
   10578, -1589, 10578, 10578, 10578, -1589, 12142, -1589, 12024, -1589,
   12142,  1635,  1666, -1589, -1589, 10578, 10578, 10578, 10578, 12142,
   -1589, 10578, 10578, 10578,   864, 10578, 12142,   550, -1589,  1210,
    1211, -1589, -1589, -1589, -1589, -1589, 10578, -1589, -1589, 10578,
   -1589, -1589, -1589, -1589, -1589, -1589, -1589, -1589, -1589, -1589,
   -1589, 10578, -1589, -1589, 10578, 10578, 10578, -1589, 10578, 10578,
   -1589, 12142, -1589, -1589, -1589, -1589, -1589, 10578, -1589, -1589,
   -1589, -1589, -1589, -1589, -1589, -1589, -1589, -1589, -1589, 12142,
   12142, 12142, 12142, -1589, -1589, -1589, -1589, -1589, 12142, -1589,
   -1589, -1589, -1589, -1589, -1589, 10578, -1589, 10578, 10578, 10578,
    1913, 12142, -1589,  1913, 12142, -1589, 12142, -1589, -1589,  1355,
    1114, 10578,    48,  1946, -1589,  1669, -1589,  1671,  1672,  1674,
   -1589,  1675,  1676, -1589, -1589, -1589,   730, 12494, -1589, -1589,
   -1589, 10578, 13402, 12142,  1872, -1589, 12142,   864,   142,   594,
   13437, 10578,   244,   729,   729,  2798,  1680,  1687, -1589,  1689,
   -1589, -1589, -1589, -1589, 10578, 10578, -1589, -1589, 13456,  4161,
    4161, 12142, 12142,  1691,  1217,   864, 12142, -1589, 10578, 10578,
   12142,   864,  1694, 13471,    -2,  1219,  1695,    -2,   142, 13486,
   13501, 13516,    -2,  1696, 13531, 12142, 12142,  1946, 12142,  1946,
   12142,   142,  1946, 12142,  1225,   864,   864, 12142, 12142,  1228,
    1229,   517,  1946, 12142,  1239, 12142,  1946, 12142,  1258, 12142,
    1259,  1260,  1946,   864,  1946, 12142,  1266, 12142, 12142,  1946,
   12142, 12142, 12142,   142, 13546,   142,  1946,  1946, 12142,   864,
    1946,  1946, 12142,  1272,   602,  1946,   864,   864,  1946, 12142,
    1288, 13567, 10578,  1946,  1295,  1946, 12142,   864, 12142, 13588,
   12142,   716, 13603, 12142,  1298, 12142,  1299, 12142,   864,  1301,
    1302, 12142,  1697,  2813,  2839,   852, 12142, 12142, -1589,  1946,
      -2, -1589,  1699,  2859,  2897,  2915,  3005,  3050,   553,  1700,
     245,   864, -1589, -1589,  3124,  3159,  1701,    43,  1305,  1946,
    1946,  1946, 13623,   864, -1589, 12142, 12142,  3236,  3288,  3316,
    3432,  3474,   884,  3969,  4221,   257,  4473,   555,  1308,   271,
     382,   592,  4686, 13732, 13753,  4724,   206,   601,   310,   604,
     606,    58, -1589, -1589, -1589,   119,   119, -1589, -1589, -1589,
   -1589, 10578,  1905,  1914,  1915,  4937, 10578,   609,  1705,   408,
   -1589, 10578, 13789, 12142,  1902, -1589, -1589, -1589, -1589, -1589,
   -1589,  1708,  1712,  1946,  1946, 12142, -1589, -1589,   864,   864,
   12142, 12142,  1311, 13809,  1946,  1312, 12142, 12142, 10578, 12142,
   12142, 10578, 10578, 10578, 10578, 10578, 10578, 12142,   864,  1335,
    1336,  1337,  1339, 10578,  1347,  1353, 12142, 10578, 10578,  1359,
   12142,  1360,  1379, 10578,   864, 10578, 10578,  1385, 12142,  1386,
    1387,  1393,  1395,  1404, 12142,  1405,  1407, 10578, 12142,  1413,
   10578, 10578,  1946, 10578,  1417,  1435, 10578,   864, 12142, 12142,
    1437, 10578,  1438, 12142,  1446, 12142, 12142,   864, -1589,  1889,
    1891, 10578,  1893,  1449,   864, 10578,   819, -1589, -1589, -1589,
   -1589, -1589, -1589, -1589, 12142, -1589, -1589, -1589, -1589, 10578,
   12142, 10578,   623,   626, -1589, -1589, -1589, -1589, -1589, 10578,
   -1589, -1589, -1589, 12142, -1589, -1589, -1589, 12142, 10578, -1589,
   10578, -1589, -1589, -1589, 12142, 10578, -1589, 12142, -1589, -1589,
   12142, -1589, -1589, -1589, 10578, -1589, -1589, -1589, -1589, -1589,
    1921,   831,  4975,  1912, 10578, 12142,  6418, 10578,   686,  1724,
    1637,   729,  1725,  1729,   729, -1589, -1589,   864,  1460,   864,
   12142, 12142, 12142,   864,   864,  1726,   864,   864,    -2, 13824,
   13839, 13854,    -2, 13869,  1466, 12142, 10578, 10578, 12142, 13884,
   10578, 12142,   864, 13899,  1946, 12142,  1476, 12142, 10578, 13918,
   13939,   142,  1946, 12142,   864, 12142, 10578, 10578, 12142, 12142,
     864, 10578, 12142,   745,  1946,   864, 10578, 13954, 13975, 14085,
   10578, 12142, 14104,  1480,   864, 12142,   761, 14140, 12142,  1486,
   12142,  1487,   864, 12142, 12142,  6664, 12142, 10578, -1589,  1731,
    1732,   321, -1589,   688, 14161,   864,  1946, -1589, -1589,  6910,
     691,   700,  7402,  7648,   719,  7894,   720,   739,    75, 12494,
   12924, 10578,  1939, -1589,  1735, -1589,  1736, 14176,   740,   849,
    8140,  1931, 10578,   729, -1589, -1589, -1589, -1589, 12142,   864,
     864,   864, 12142, 10578, 10578, 12142, 10578, 10578, 10578, 12142,
    1490, 14191, 14206,  1494, 10578, 14221,  1520, 10578,  1521, 10578,
    1524, 14236, 10578, 10578,  1527,  1530, 14251, 14271,   864,   864,
   14290,  1548, 10578, 14305, 10578, 10578, 10578, 14326,  1559, 10578,
   12142,   864, 12142, 12142,  1560, 10578,  1562, 12142,   864,   864,
    1916,   864,  1946,  1739,  1742,   819, -1589, -1589, 10578, -1589,
   -1589, -1589, -1589, -1589, -1589, -1589, -1589, -1589, 10578, -1589,
    1915,  1952,   566, 12494, -1589, 12142, 10578, 10578, -1589, -1589,
    1741,  1637, -1589,  1744,  1637, 14437, -1589,   864,   864,  1746,
   14457,   864, 14491,  1747, 14512,  1569, 12142, 12142, 12142, 12142,
   14527, 12142, 12142, 14542, 10578,  1946, 12142, 10578,  1946, 14557,
   12142, 10578, 10578, 12142, 12142, 12142,  1946, 12142, 14572, 14587,
   14602, 12142, 12142,  1946,   864,  1570,   864, 12142,  1218, 14623,
   12142,   864, 12142, -1589, -1589, -1589, 12494,  8386,  1946, 12494,
   -1589, -1589,  1915,   889,   409, 14643,  8632,  1637, 12142,   729,
    1637, 10578,   729, 10578, 12142, 12142, 10578, 12142, 12142, 12142,
     864,   864,   864,  1591, 10578,   864,   864, 10578, 14658,  1594,
   14677, 10578,   864, 14788, 14809,   864,   864,   864,   864, 10578,
   12142, 10578,  1595,   864, 12142,   864, 12142, 12142,  1598,   864,
      31, -1589,  1915, 12494, -1589, -1589, -1589, -1589, -1589, -1589,
   -1589, 12142, -1589, 10578, -1589,   729,   465, -1589,   729, 14844,
   -1589,  8878,   864,   864, 14863,   864,   864,   864, 12142,  1946,
    1946, 10578, 12142, 10578,  1946, 12142, 12142,  1946,   864, 14878,
   12142,   864,  1602,   864, 12142, -1589, -1589, -1589,   985,  1915,
     742,  9124, -1589, 12142, -1589, -1589, 10578, -1589, 12142,   864,
   14893,   864, 14908,   864,   864, 10578,   864, 12142,   864, -1589,
   -1589, -1589, -1589, -1589, -1589,  1995,  1921, -1589, -1589,   744,
    1637,  9370,  1637,   864, 12142, 12142, 14923,   864, -1589, -1589,
   -1589, -1589,   729, -1589,   729,  1609,   864, 12142,  1637, -1589,
    1637, -1589, 12142,   864,   729,   729,   864, -1589, -1589
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   235,     0,     0,     0,   477,     0,     0,     0,   229,
     500,   535,   540,    18,     0,     0,     0,     0,    31,    33,
     478,     0,   462,   462,     0,   479,    25,    27,   515,   527,
       0,   624,    55,    67,     0,   226,   227,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   236,
     237,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,     0,     0,     0,     0,
       0,     2,     9,    17,     8,     0,    12,    46,    48,    14,
      29,    30,    28,     0,    20,    21,    24,    23,    22,    35,
      36,   450,   341,   257,   451,   452,   453,   260,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,     0,     0,     0,
       0,     0,     0,     0,   401,   404,   407,   410,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   288,
     290,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   258,     0,   355,   335,   340,   259,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
     462,     0,   462,     0,     0,    16,   455,   454,    37,    38,
      45,     0,     0,     0,     0,    19,    50,   464,    51,    49,
     480,    26,     0,    16,   559,     0,   628,     0,     0,   588,
     620,    69,    68,     0,     0,    70,   228,    60,     0,    62,
       0,   580,   582,    63,   578,   584,     0,     0,   585,   447,
      64,    66,     0,   213,     0,     0,   639,     0,    92,   215,
      86,    47,     0,     0,     0,     0,     0,     0,    74,     0,
      57,    79,     0,     0,    94,    93,     0,     0,   238,   239,
     216,    13,    15,   230,     0,     0,    85,     0,     0,     0,
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
       0,   231,     0,     0,     7,     0,     0,     0,     0,     0,
       0,   469,   462,   462,     0,     0,   325,     0,     0,     0,
       0,     0,     0,     0,   431,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     304,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   462,   462,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   347,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,   323,   321,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     5,     6,   319,     0,   240,     0,     0,   536,
       9,    39,    40,    41,    43,   483,   484,    32,   481,   489,
     490,    34,   487,   467,   468,   463,   465,   520,   519,     0,
       9,     0,    16,     0,     0,     0,   625,   626,     0,   591,
     593,    52,     0,     0,     0,     0,    56,   622,   462,   462,
       0,     0,     0,   462,   462,     0,   449,   448,     0,     0,
     214,   638,     0,     0,     0,     0,    96,    73,     0,     0,
      78,   620,   247,   246,     0,     0,     0,    75,     0,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,     0,     0,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   166,     0,     0,
     167,     0,     0,   172,     0,     0,     0,     0,   181,     0,
       0,   184,     0,     0,     0,     0,     0,   191,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   206,     0,     0,     0,   211,     0,
     255,     0,     0,     0,   219,     0,     0,     0,     0,     0,
       0,    10,     0,     0,     0,   320,   245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   293,   295,   294,   296,   435,   434,     0,   437,   436,
       0,   439,   438,     0,   442,     0,   440,     0,   301,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   381,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   272,     0,     0,     0,     0,     0,
       0,     0,     0,   402,     0,   405,     0,   408,     0,   411,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   289,   291,     0,     0,     0,     0,     0,
       0,     0,   262,   356,   350,   352,   354,   351,   353,   348,
     349,   261,     0,     0,   328,   330,   332,   329,   331,   326,
     327,   346,   343,   342,   344,   345,   460,   461,   501,    16,
     547,   545,     0,   546,   542,   544,   541,     0,     0,   462,
     462,     0,   462,   462,     0,     0,   517,   521,   534,   532,
     533,   530,   529,   531,   528,   549,     9,     0,     0,     0,
       0,     0,   589,    53,    54,     0,     0,     0,   596,   598,
       0,   623,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   579,   586,   587,     0,     0,     0,   250,   249,   253,
       0,     0,   359,    58,    76,     0,    89,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   148,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   462,     0,
       0,     0,   220,   221,   222,   223,   224,   225,     0,     0,
      16,     0,     0,     0,   475,   476,   470,   423,   315,     0,
       0,   414,     0,     0,     0,   424,     0,   425,     0,   418,
       0,     0,     0,   336,   337,     0,     0,     0,     0,     0,
     446,     0,     0,     0,   441,     0,     0,     0,   302,     0,
       0,   360,   361,   362,   363,   364,     0,   365,   367,     0,
     368,   370,   371,   333,   377,   378,   372,   374,   375,   376,
     373,     0,   380,   385,     0,     0,     0,   384,     0,     0,
     270,     0,   267,   273,   274,   386,   313,     0,   387,   314,
     275,   276,   400,   403,   406,   409,   279,   277,   278,     0,
       0,     0,     0,   282,   393,   283,   399,   398,     0,   292,
     394,   284,   395,   285,   397,     0,   286,     0,     0,     0,
       0,     0,   308,     0,     0,   310,     0,   430,   318,   324,
     322,     0,     9,   543,   640,    42,   642,    44,     0,     0,
     482,     0,     0,   488,   466,   518,   524,    16,   561,   562,
     560,     0,     0,     0,   629,   627,     0,   594,   592,   593,
       0,     0,     0,     0,     0,     0,   574,   576,   621,   571,
     456,   458,   462,   462,     0,     0,   581,   583,    71,     0,
       0,     0,     0,     0,     0,   121,     0,    77,     0,     0,
       0,   102,     0,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,   117,     0,   119,
       0,   124,   125,     0,     0,   129,   128,     0,     0,     0,
       0,     0,   137,     0,     0,     0,   144,     0,     0,     0,
       0,     0,   151,   150,   152,     0,     0,     0,     0,   157,
       0,     0,     0,   161,     0,   163,   164,   165,     0,   169,
     171,   170,     0,   174,   177,   178,   182,   183,   180,     0,
       0,     0,     0,   188,     0,   190,     0,   194,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   208,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    87,
       0,    91,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   432,   357,   358,     0,     0,     0,     0,   444,   297,
     298,   299,     0,   443,   303,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   539,   538,   537,     0,     0,   485,   486,   491,
     492,     0,     0,     0,   550,     0,     0,     0,     0,     0,
     590,     0,     0,     0,   610,   597,   599,   600,   462,   462,
     572,     0,     0,    59,    61,     0,   251,   252,   248,   254,
       0,     0,    90,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   189,     0,     0,     0,     0,   195,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   209,   256,     0,
       0,     0,     0,   233,   234,     0,   493,   412,   413,   415,
     416,   417,   426,   427,     0,   428,   338,   339,   311,     0,
       0,     0,     0,     0,   366,   369,   379,   263,   264,     0,
     266,   382,   383,     0,   268,   388,   280,     0,     0,   389,
       0,   391,   306,   287,     0,     0,   317,     0,   420,   307,
       0,   422,   309,   334,     0,   641,   643,   522,   525,   516,
     565,   631,     0,   630,     0,     0,     0,     0,     0,     0,
     622,     0,     0,     0,     0,   457,   459,    72,     0,    97,
       0,     0,     0,   103,   106,     0,   101,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,     0,   135,     0,     0,     0,     0,   139,
       0,   145,   146,     0,   154,     0,     0,     0,     0,     0,
     162,     0,     0,     0,   176,   179,     0,     0,     0,     0,
       0,     0,     0,     0,   198,     0,     0,     0,     0,     0,
       0,     0,   210,     0,     0,     0,     0,     0,    88,   496,
     497,     0,   494,     0,     0,   445,   300,   433,   305,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   511,    16,
     235,     0,   563,   635,     0,   632,     0,     0,     0,   602,
       0,   612,     0,     0,   601,   575,   577,   573,     0,   120,
      82,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   158,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   197,     0,     0,     0,     0,     0,     0,   243,   244,
       0,   242,   232,     0,     0,     0,   471,   429,     0,   265,
     269,   281,   390,   392,   396,   316,   419,   421,     0,   502,
     523,     9,   569,    16,   551,     0,     0,     0,   595,   614,
       0,   622,   604,     0,   622,     0,   611,    95,   110,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,     0,     0,   140,     0,
       0,     0,     0,     0,     0,     0,   175,     0,     0,     0,
       0,     0,     0,   196,   199,     0,   201,     0,     0,     0,
       0,   207,     0,   498,   499,   495,    16,     0,   512,    16,
     570,   566,   564,     0,     0,     0,     0,   622,     0,     0,
     622,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   118,     0,     0,   127,   122,     0,     0,     0,
       0,     0,   149,     0,     0,   156,   160,   168,   173,     0,
       0,     0,     0,   193,     0,   200,     0,     0,     0,   241,
       9,   312,   503,    16,   558,   555,   556,   557,   553,   554,
     552,     0,   636,     0,   633,     0,     0,   603,     0,     0,
     613,     0,   109,   100,     0,   111,   105,   212,     0,   131,
     136,     0,     0,     0,   147,     0,     0,   192,   187,     0,
       0,   202,     0,   205,     0,   474,   473,   472,     0,   567,
       0,     0,   615,     0,   616,   605,     0,   606,     0,   123,
       0,   141,     0,   153,   155,     0,   185,     0,   203,   506,
     508,   509,   510,   505,   507,   513,   565,   637,   634,     0,
     622,     0,   622,   108,     0,     0,     0,   204,   514,   504,
     568,   618,     0,   608,     0,   132,   143,     0,   622,   617,
     622,   607,     0,   186,     0,     0,   133,   619,   609
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1589, -1589, -1589,  -253, -1589, -1589,  2000,   895, -1589, -1589,
   -1589, -1589, -1589, -1589, -1589,  1953,   491, -1589, -1589,  -370,
      -3, -1589,  1954,  1677, -1589, -1589,  1547,  -459,  2936, -1589,
    1366,   -39,   -12, -1589,     4,    10,   166, -1589, -1589,  1076,
    2010, -1589, -1589, -1589, -1589, -1589, -1589, -1589,  1089, -1589,
    1073, -1589,   235, -1589, -1589, -1589, -1589, -1589, -1589, -1589,
   -1589, -1589, -1589, -1589,   590, -1589, -1589, -1589, -1589, -1589,
   -1589, -1589, -1589, -1589, -1589, -1589, -1589, -1589, -1589, -1589,
   -1589, -1589, -1589, -1589, -1589, -1589, -1589, -1589, -1589,    36,
   -1589, -1589, -1589, -1240, -1589, -1589, -1589,  1399, -1589, -1589,
     784,  1384, -1589, -1589, -1589, -1589, -1589, -1589, -1589, -1589,
   -1589, -1589, -1589, -1589, -1589, -1588, -1589,     2, -1589, -1589
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,   101,   102,   445,  1110,   103,   104,   263,   264,
     947,   948,   280,   661,   105,   106,   664,   107,   108,   771,
     230,   231,   109,   317,   923,   922,   803,   804,   318,   233,
     298,   234,   258,   285,   235,   236,   266,   267,   615,   616,
     112,   787,  1392,  1876,  1977,  1116,   113,   607,   608,   611,
     612,  1701,  1702,   114,   253,  1231,  1879,  1978,  2005,  1809,
    2019,   115,   272,   957,   619,  1246,  1719,  1453,  1720,   116,
     273,   964,   117,   254,   939,  1444,   118,   255,   946,   119,
     621,  1247,  1610,  1883,  1940,   120,   622,  1250,  1814,  1722,
    1933,  2006,  1881,  1268,  1624,  1269,   293,   294,   300,   631,
     972,   636,  1263,  1264,  1621,  1821,  1890,  2012,  2030,  1620,
    1824,  1887,  2010,  2028,   637,   982,   279,   307,  1235,  1237
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     243,   299,   600,   259,   260,   110,   662,   806,   245,   591,
     662,   111,   626,   978,   246,   627,   979,   652,   265,   471,
     620,   269,   249,  1465,  1466,   275,   251,   276,   277,   301,
     281,   585,  1733,    20,   287,   289,   121,   585,    25,   305,
     124,   125,   126,   295,   473,   311,   312,   632,   379,   633,
     634,   333,   334,   335,   121,   662,  1975,   245,   124,   125,
     126,   992,   472,   246,  1442,   772,   773,   376,   377,   378,
    1604,   324,     7,     8,   248,  1976,   567,   568,   569,   570,
     571,   572,   573,   423,   425,   427,   574,   474,  1808,     7,
       8,  1187,  1443,  1188,   439,   441,   442,   443,   380,   440,
     574,   325,   326,   327,   270,   711,   576,   577,   328,   429,
     603,   604,   492,   578,   579,   580,   581,   582,   583,   584,
     585,   576,   577,   256,   271,   430,   257,   329,   578,   579,
     580,   581,   582,   583,   584,   585,   475,   476,   576,   577,
       1,     2,     3,     4,     5,   578,   579,   580,   581,   582,
     583,   584,   585,   576,   577,   493,   336,   478,   479,   428,
     578,   579,   580,   581,   582,   583,   584,   585,    53,   567,
     568,   569,   570,   571,   572,   573,   583,   584,   585,   477,
     434,   567,   568,   569,   570,   571,   572,   573,   906,   268,
     908,   567,   568,   569,   570,   571,   572,   573,   435,   250,
     480,   588,   589,   252,   574,   586,   587,   588,   589,   712,
     449,   574,   567,   568,   569,   570,   571,   572,   573,   446,
     447,   278,   574,   436,   481,   482,   565,   484,   485,   912,
     574,   448,  1221,  1889,  1222,  1208,  1892,  1209,   437,   590,
     574,   574,   574,   635,   438,   663,   713,   759,   596,   663,
     283,   284,   574,   450,    92,    93,    94,   646,   647,   110,
     628,   980,   584,   585,   613,   111,   444,   483,   574,   617,
     486,    92,    93,    94,   574,  1103,   629,   110,   296,   297,
     940,  1140,   941,   111,   942,   574,   313,   314,   586,   587,
     588,   589,  1148,   315,   663,   469,   296,   297,   575,  1945,
     650,   574,  1948,   586,   587,   588,   589,   943,  1173,   574,
     944,   656,   657,   658,   761,   945,   316,   576,   577,   665,
     586,   587,   588,   589,   578,   579,   580,   581,   582,   583,
     584,   585,   451,   574,   574,   586,   587,   588,   589,  1215,
    1177,  1216,   680,   681,   250,   574,   586,   587,   588,   589,
    1126,   689,  1127,   691,   252,   693,   694,   574,   696,   697,
     698,   699,   777,   487,   702,   703,   704,   574,   706,   966,
     708,  1224,   710,  1225,   912,   452,   714,   715,   716,   717,
     718,  1734,   720,   453,  1737,   723,   454,   574,   574,   727,
     728,   729,   730,   731,  1185,   733,   734,   735,   736,   455,
     738,   739,   740,   741,   742,   743,   744,   574,   746,   747,
     748,   750,   751,   752,  1190,   754,   595,   756,   597,   758,
     457,   760,  2022,   762,  2024,   764,   765,   766,   767,   768,
     574,   586,   587,   588,   589,   776,   574,  1191,   463,   464,
    2034,   763,  2035,   582,   583,   584,   585,   786,   567,   568,
     569,   570,   571,   572,   573,   574,   574,  1597,   797,  1598,
     800,   779,  1192,   798,   799,   458,   809,   810,   811,   812,
     813,   814,   815,   816,   817,   818,   819,   820,   821,   822,
     823,   824,   826,   827,   828,   829,   459,   574,   831,   460,
     574,   574,  1253,  1826,  1254,  1463,  1564,  1464,  1565,   586,
     587,   588,   589,   574,   291,   292,   844,   461,  1583,   574,
    1584,   855,   856,   857,   858,   859,  1193,   574,   862,   601,
     602,   867,  1588,   869,  1589,   871,   872,   874,   876,   878,
     880,   881,   882,   883,   462,   885,   886,   887,   888,   889,
     890,   891,   893,   605,   606,   896,   892,   898,   899,   900,
     901,   902,   574,   465,   905,   574,   907,   780,   909,   910,
     911,  1600,  1194,  1601,   914,   915,   916,   917,   918,   919,
     920,   921,  1795,   574,  1796,   609,   610,  -548,  1001,   567,
     568,   569,   570,   571,   572,   573,   466,   567,   568,   569,
     570,   571,   572,   573,   576,   577,   467,   801,   802,   973,
     974,   578,   579,   580,   581,   582,   583,   584,   585,   299,
     995,   996,  1880,   574,   586,   587,   588,   589,   788,   789,
    1195,   958,   969,   959,   574,   960,   110,   574,   574,   576,
     577,  1180,   111,  1590,  1196,  1591,   578,   579,   580,   581,
     582,   583,   584,   585,   468,   971,   574,   470,   961,  1947,
     998,   962,  1950,  1197,   574,   574,   963,   576,   577,  1615,
    1941,   912,  1942,  1006,   578,   579,   580,   581,   582,   583,
     584,   585,   567,   568,   569,   570,   571,   572,   573,   488,
     574,   574,   489,   576,   577,  1005,  1232,  1028,  1198,  1030,
     578,   579,   580,   581,   582,   583,   584,   585,  1037,   574,
     574,   985,   986,   490,  1019,  1982,  1045,  1203,  1985,  1048,
    1049,   574,   894,   895,   576,   577,  1983,   477,  1984,  1114,
    1115,   578,   579,   580,   581,   582,   583,   584,   585,   576,
     577,  1248,  1249,  1266,  1267,   491,   578,   579,   580,   581,
     582,   583,   584,   585,   574,   494,  1079,   495,   574,   496,
     574,  1204,  1085,  1027,  1087,   574,  1089,  1205,  1091,   574,
    1093,  1436,  1206,   574,  1438,   574,  1212,   497,  1508,  1451,
    1452,   480,  1214,   574,  1104,  1106,   586,   587,   588,   589,
    1227,   498,  2029,   483,  2031,   499,   567,   568,   569,   570,
     571,   572,   573,   574,  2037,  2038,   574,   574,   500,   574,
    1228,   574,  1029,  1414,   983,   984,  1562,   486,  1586,   989,
     990,   586,   587,   588,   589,   567,   568,   569,   570,   571,
     572,   573,  1144,  1699,  1700,   670,   671,  1147,   672,  1149,
    1150,   567,   568,   569,   570,   571,   572,   573,   574,   586,
     587,   588,   589,   687,   688,  1592,   592,   574,   574,   501,
     574,   695,   574,  1528,  1599,   574,   700,  1602,   493,  1603,
     502,   705,  1613,   707,   503,   586,   587,   588,   589,   574,
     504,  1156,   574,  1157,   505,   719,  1707,   721,   722,  1708,
     724,   725,   726,   581,   582,   583,   584,   585,   732,   574,
     574,  1723,  1724,   737,  1031,  1033,   586,   587,   588,   589,
     506,   745,  1159,  1934,  1160,  1935,   507,  1936,   753,  1819,
    1820,   586,   587,   588,   589,   576,   577,  1181,   593,  1182,
     508,   509,   578,   579,   580,   581,   582,   583,   584,   585,
    1937,   510,   574,  1938,   574,  1234,  1236,   574,  1939,  1731,
     574,  1797,   511,   110,  1800,  1034,   574,   576,   577,   111,
     512,   513,   613,  1801,   578,   579,   580,   581,   582,   583,
     584,   585,   574,   514,   515,   574,   574,  1538,  1257,   576,
     577,  1258,  1804,  1806,  1262,   516,   578,   579,   580,   581,
     582,   583,   584,   585,   574,   574,   574,   517,   574,  1035,
     574,   574,  1807,  1818,  1454,  2007,  1772,  2021,  1284,  1999,
     121,  2000,  1285,  2001,   124,   125,   126,   574,   518,  1291,
     576,   577,  1782,  1295,   519,   520,  1298,   578,   579,   580,
     581,   582,   583,   584,   585,   521,  2002,   522,  1311,  2003,
    1314,  1315,  1316,   574,  2004,  1319,  1320,  1321,  1038,  1324,
     574,   574,   523,  1328,   574,  1039,  1040,  1330,  1331,  1042,
    1333,   524,   525,  1336,   574,   586,   587,   588,   589,  1044,
    1343,  1345,   574,   526,  1349,   527,   528,  1046,  1353,  1354,
    1356,  1357,   574,   529,  1360,   574,   530,  1050,  1364,   574,
    1051,  1367,   531,   574,  1052,  1371,   532,  1374,  1053,  1376,
     574,  1378,  1379,  1380,   533,  1054,   574,   586,   587,   588,
     589,  1056,   574,  1551,   574,  1552,   574,  1059,   574,  1063,
     574,  1064,   574,  1065,   110,  1238,  1239,  1067,  1241,  1242,
     111,   574,   534,  1398,   535,  1400,  1068,  1401,   574,   586,
     587,   588,   589,  1069,   574,  1579,  1408,  1580,   536,  1071,
     574,   624,   574,  1413,   574,  1072,  1000,  1073,   598,  1074,
     574,   586,   587,   588,   589,  1075,   574,   574,   574,   913,
    1008,  1077,  1078,  1080,   640,  1013,   574,  1015,   574,  1017,
    1018,  1081,   645,  1082,   574,  1022,  1023,   576,  1425,  1084,
     770,   537,   538,   539,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,  1427,  1428,  1429,  1430,
    1102,   574,   574,   576,   577,  1431,  1086,  1088,   781,   540,
     578,   579,   580,   581,   582,   583,   584,   585,  1437,   576,
     577,  1439,   541,  1440,   542,   543,   578,   579,   580,   581,
     582,   583,   584,   585,   576,   577,   544,   956,   545,   546,
     547,   578,   579,   580,   581,   582,   583,   584,   585,   574,
    1457,   110,   548,  1459,  1090,   648,   574,   111,   574,   576,
     577,  1092,   653,  1094,  1382,   549,   578,   579,   580,   581,
     582,   583,   584,   585,  1112,  1113,   550,   551,  1478,  1479,
     574,  1476,  1477,  1482,   552,  1095,   654,  1485,   567,   568,
     569,   570,   571,   572,   573,   574,   574,   553,  1137,   574,
    1096,  1130,  1498,  1499,  1139,  1500,   574,  1501,   574,   554,
    1502,  1141,   574,  1142,  1504,  1505,   574,  1143,   574,   555,
    1509,  1145,  1511,  1146,  1512,   574,  1514,   556,   574,   557,
    1174,   574,  1517,  1175,  1519,  1520,  1176,  1521,  1522,  1523,
     558,   574,   574,   574,   559,  1525,  1200,  1201,  1202,  1526,
     574,   560,   574,   574,   561,  1217,  1529,  1218,  1219,   586,
     587,   588,   589,  1534,   574,  1535,   574,  1537,   574,  1220,
    1540,  1223,  1542,  1226,  1544,   574,   574,   574,  1547,   562,
    1281,  1286,  1308,  1553,  1554,   586,   587,   588,   589,   563,
     623,   625,   666,  1121,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   574,   574,   638,   690,  1151,
    1310,  1318,  1572,  1573,   639,   574,   586,   587,   588,   589,
    1327,   903,   643,   692,  1152,   578,   579,   580,   581,   582,
     583,   584,   585,  1605,  1606,   574,   644,   701,  1471,  1472,
    1362,   586,   587,   588,   589,   574,   574,   574,   617,  1153,
    1368,  1370,  1373,   574,   574,   709,   574,   574,  1375,  1377,
    1618,  1415,  1416,   574,   574,   574,  1810,  1811,  1481,  1926,
    1489,   574,  1627,   755,   574,   574,  1503,  1628,  1629,  1506,
    1507,   757,   778,  1633,  1634,   574,  1636,  1637,   576,   577,
    1510,   904,   830,   832,  1644,   578,   579,   580,   581,   582,
     583,   584,   585,  1652,   574,   574,   574,  1656,   833,  1513,
    1515,  1516,   574,  1661,   936,  1664,   585,  1518,   574,   576,
     577,  1670,   937,  1527,  1673,  1675,   578,   579,   580,   581,
     582,   583,   584,   585,   574,  1683,  1684,   938,  1686,  1530,
    1689,   574,  1691,  1692,   574,   574,  1533,   574,   574,  1541,
    1543,   574,  1545,  1546,   574,   949,  1570,   574,   574,  1587,
    1882,  1703,  1630,  1632,   951,   576,   577,  1705,   586,   587,
     588,   589,   578,   579,   580,   581,   582,   583,   584,   585,
    1710,   574,   574,   574,  1711,   574,  1645,  1646,  1647,   954,
    1648,  1714,   950,   574,  1716,   952,   953,  1717,  1650,   574,
     586,   587,   588,   589,  1651,   574,   574,   576,   577,   955,
    1655,  1657,  1728,   965,   578,   579,   580,   581,   582,   583,
     584,   585,   968,  1930,   975,   574,  1932,  1739,  1740,  1741,
    1658,   574,   574,   574,  1622,  1623,  1663,  1665,  1666,   574,
     976,   574,  1750,   977,  1667,  1753,  1668,   981,  1756,  1012,
     574,   574,  1758,   574,  1760,  1669,  1671,  1014,  1672,   574,
    1764,  1016,  1765,   574,  1676,  1768,  1769,  1020,  1680,  1771,
     586,   587,   588,   589,  1021,  1099,   641,  1100,  1778,   232,
    1979,   574,  1781,   574,   574,  1784,  1681,  1786,  1685,  1688,
    1788,  1789,   574,  1791,   262,   574,  1098,  1690,  1101,  1111,
    1697,   586,   587,   588,   589,  1117,   574,   274,  1118,  1154,
     282,  1738,   574,   286,   288,   290,  1125,  1749,  1128,   306,
     306,   306,   574,   110,   110,  1129,   574,  1759,   330,   111,
     111,  1780,   574,   574,  1131,  1827,   574,  1785,  1787,  1828,
     574,  1836,  1831,  1132,  1135,  1839,  1835,   586,   587,   588,
     589,   576,   577,  1133,  1134,  1155,  1136,  1163,   578,   579,
     580,   581,   582,   583,   584,   585,   574,   574,   433,  1207,
     574,  1842,  1844,   574,   306,  1846,   574,  1864,  1850,  1865,
    1866,  1851,  1868,  1245,  1871,  1488,  1210,  1211,  1491,   586,
     587,   588,   589,  1495,   574,  1261,  1279,  1158,   579,  1855,
     581,   582,   583,   584,   585,   574,   574,  1270,   574,   456,
    1862,  1867,  1884,  1870,  1271,   574,   574,   110,   576,   577,
    1899,  1924,  1280,   111,  1272,   578,   579,   580,   581,   582,
     583,   584,   585,  1900,  1901,  1902,  1903,   574,  1905,  1906,
     574,   574,  1958,  1909,   574,  1962,  1970,  1912,   574,  1974,
    1915,  1916,  1917,  1997,  1918,   574,  1273,  1290,  1922,  1923,
    2032,  1276,  1305,  1277,  1925,   576,   577,  1928,  1306,  1929,
    1313,  1317,   578,   579,   580,   581,   582,   583,   584,   585,
     110,  1555,  1323,   110,  1325,  1946,   111,  1335,  1402,   111,
    1337,  1952,  1953,  1338,  1955,  1956,  1957,  1340,  1569,  1341,
     576,   577,  1342,  1348,  1352,   564,   566,   578,   579,   580,
     581,   582,   583,   584,   585,  1359,  1366,  1968,   802,  1403,
    1445,  1971,  1446,  1972,  1973,  1447,   594,  1448,  1449,  1450,
    1458,   599,  1468,   586,   587,   588,   589,   110,  1980,  1469,
    1470,  1161,  1480,   111,   614,  1486,  1490,  1496,  1608,   618,
    1548,  1556,  1609,  1563,  1568,  1989,   630,  1614,    -9,  1991,
    1619,  1625,  1993,  1994,  1693,  1626,  1694,  1996,  1696,  1721,
    1726,  1998,   586,   587,   588,   589,  1732,  1742,  1735,   649,
    2009,   651,  1736,  1793,  1794,  2013,  1813,  1815,  1816,  1823,
    -526,  1872,  1873,  1888,  2017,  1874,  1891,  1894,  1897,  2018,
     586,   587,   588,   589,   244,  1388,   331,   332,  1162,   576,
     577,  2025,  2026,   805,   993,   247,   578,   579,   580,   581,
     582,   583,   584,   585,  2033,   576,   577,  1243,   686,  2036,
    1875,  1244,   578,   579,   580,   581,   582,   583,   584,   585,
    1240,  1607,  2020,  1460,   991,  1003,     0,   586,   587,   588,
     589,   576,   577,     0,     0,  1164,     0,     0,   578,   579,
     580,   581,   582,   583,   584,   585,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   586,   587,   588,   589,   576,   577,     0,     0,
    1165,     0,     0,   578,   579,   580,   581,   582,   583,   584,
     585,     0,     0,     0,     0,     0,     0,     0,   576,   577,
       0,     0,     0,     0,   775,   578,   579,   580,   581,   582,
     583,   584,   585,     0,     0,     0,   785,     0,     0,  1743,
       0,   790,   791,  1747,   792,   793,   794,   795,   306,   306,
     576,   577,     0,     0,     0,   808,     0,   578,   579,   580,
     581,   582,   583,   584,   585,   576,   577,     0,     0,     0,
       0,     0,   578,   579,   580,   581,   582,   583,   584,   585,
       0,   834,   835,   836,   837,   838,   839,   840,   841,   842,
     843,   306,   845,   846,   847,   848,   849,   850,   851,   852,
     854,   586,   587,   588,   589,     0,   860,   861,   863,   865,
     866,     0,   868,     0,   870,     0,     0,   586,   587,   588,
     589,     0,     0,     0,   884,  1166,     0,     0,     0,     0,
       0,   306,     0,     0,     0,     0,   897,     0,     0,     0,
       0,     0,     0,   586,   587,   588,   589,   576,   577,     0,
       0,  1167,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,     0,     0,     0,   924,   925,   926,   927,   928,
     929,   930,   931,   932,   933,   934,   935,     0,   586,   587,
     588,   589,     0,     0,     0,     0,  1168,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   587,   588,   589,     0,     0,     0,     0,  1169,     0,
     967,     0,     0,     0,     0,   970,   121,   122,   123,     0,
     124,   125,   126,   127,     0,     0,     0,     0,   987,   988,
       0,     0,   586,   587,   588,   589,     0,     0,     0,     0,
    1170,   999,     0,   128,   129,     0,  1002,   586,   587,   588,
     589,     0,     0,     0,     0,  1172,     0,  1009,  1010,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   131,   132,   133,
     134,   135,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,     0,     0,   138,  1047,     0,
       0,     0,   308,     0,     0,     0,     0,     0,     0,     0,
     309,     0,     0,     0,   140,   141,     0,     0,   142,     0,
     143,     0,     0,   310,     0,     0,     0,     0,   144,   586,
     587,   588,   589,     0,     0,   145,     0,  1183,     0,   146,
     147,   576,   577,     0,     0,     0,     0,     0,   578,   579,
     580,   581,   582,   583,   584,   585,  1097,   148,   149,   150,
     151,   152,   153,     0,  1105,  1107,  1108,  1109,     0,   154,
       0,     0,   155,     0,     0,   156,   157,     0,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
       0,   210,   211,   212,   213,     0,   214,   215,     0,   216,
     217,   218,     0,   219,   220,   221,   222,   223,   224,   225,
       0,     0,     0,     0,     0,   226,   227,     0,   228,   338,
     339,   340,   341,   342,     0,   229,     0,   304,     0,     0,
       0,     0,     0,   343,     0,     0,     0,     0,     0,   344,
     345,     0,     0,     0,     0,   346,   347,   348,   349,   350,
       0,     0,     0,     0,   576,   577,     0,     0,     0,     0,
       0,   578,   579,   580,   581,   582,   583,   584,   585,  1229,
    1230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   586,   587,   588,   589,     0,     0,  1233,
       0,  1184,     0,   351,     0,     0,   576,   577,     0,     0,
       0,     0,   614,   578,   579,   580,   581,   582,   583,   584,
     585,     0,     0,     0,     0,  1252,     0,     0,     0,     0,
       0,  1259,  1260,     0,     0,   576,   577,  1265,     0,     0,
       0,     0,   578,   579,   580,   581,   582,   583,   584,   585,
       0,  1278,     0,     0,     0,   576,   577,     0,     0,     0,
       0,     0,   578,   579,   580,   581,   582,   583,   584,   585,
       0,  1293,     0,     0,     0,     0,  1299,  1300,  1301,     0,
       0,  1304,     0,     0,  1307,     0,  1309,     0,  1312,     0,
       0,     0,     0,     0,     0,     0,     0,  1322,     0,     0,
       0,  1326,     0,     0,     0,     0,     0,     0,     0,  1332,
       0,  1334,     0,     0,     0,     0,  1339,     0,     0,     0,
    1344,  1346,  1347,     0,     0,  1350,  1351,     0,     0,  1355,
       0,     0,  1358,     0,     0,  1361,     0,  1363,     0,  1365,
       0,     0,     0,  1369,     0,  1372,   586,   587,   588,   589,
       0,     0,     0,     0,  1186,     0,  1383,  1384,  1385,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1389,     0,
       0,     0,     0,     0,     0,     0,  1393,  1394,     0,  1395,
    1396,  1397,     0,     0,     0,     0,     0,     0,   586,   587,
     588,   589,  1404,  1405,     0,  1407,  1189,     0,  1409,  1410,
    1411,     0,  1412,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1417,     0,     0,  1418,   586,   587,   588,
     589,     0,     0,     0,     0,  1213,     0,     0,  1419,     0,
       0,  1420,  1421,  1422,     0,  1423,  1424,   586,   587,   588,
     589,   576,   577,     0,  1426,  1255,     0,     0,   578,   579,
     580,   581,   582,   583,   584,   585,   576,   577,     0,     0,
       0,     0,     0,   578,   579,   580,   581,   582,   583,   584,
     585,     0,  1432,     0,  1433,  1434,  1435,     0,     0,     0,
       0,     0,   576,   577,     0,     0,     0,     0,  1441,   578,
     579,   580,   581,   582,   583,   584,   585,     0,     0,     0,
       0,     0,   576,   577,     0,     0,     0,     0,  1455,   578,
     579,   580,   581,   582,   583,   584,   585,     0,  1462,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1473,  1474,     0,     0,     0,   306,   306,     0,     0,
     576,   577,     0,     0,     0,  1483,  1484,   578,   579,   580,
     581,   582,   583,   584,   585,     0,     0,     0,   576,   577,
       0,     0,     0,   321,   323,   578,   579,   580,   581,   582,
     583,   584,   585,     0,   337,     0,   352,   353,   355,   357,
     360,   365,   366,   370,   372,   374,     0,     0,     0,     0,
     384,   386,   387,   389,   390,   391,   397,   402,   410,   417,
     419,   421,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1532,
       0,     0,     0,   586,   587,   588,   589,     0,     0,     0,
       0,  1467,     0,     0,     0,     0,     0,     0,   586,   587,
     588,   589,     0,     0,     0,     0,  1549,     0,   576,   577,
       0,     0,     0,     0,     0,   578,   579,   580,   581,   582,
     583,   584,   585,     0,   586,   587,   588,   589,     0,     0,
       0,     0,  1550,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   586,   587,   588,   589,     0,     0,
       0,     0,  1557,   576,   577,     0,     0,     0,     0,     0,
     578,   579,   580,   581,   582,   583,   584,   585,   618,     0,
       0,     0,     0,  1612,     0,     0,     0,     0,  1616,     0,
       0,     0,   586,   587,   588,   589,     0,     0,     0,     0,
    1558,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   587,   588,   589,     0,     0,     0,     0,  1559,  1639,
    1640,  1641,     0,  1643,     0,     0,     0,     0,     0,     0,
    1649,     0,     0,     0,  1653,  1654,     0,   576,   577,     0,
    1659,     0,  1660,  1662,   578,   579,   580,   581,   582,   583,
     584,   585,     0,     0,  1674,     0,     0,  1677,  1678,     0,
    1679,     0,     0,  1682,     0,     0,     0,     0,  1687,     0,
       0,     0,   576,   577,     0,     0,     0,     0,  1695,   578,
     579,   580,   581,   582,   583,   584,   585,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1704,     0,  1706,   655,
     586,   587,   588,   589,     0,   660,  1709,     0,  1560,     0,
       0,     0,   667,   669,     0,  1712,     0,  1713,     0,     0,
       0,     0,  1715,     0,   673,   674,   675,   676,   677,   678,
     679,  1718,     0,   682,   683,   684,   685,     0,     0,     0,
       0,  1727,     0,     0,  1730,   586,   587,   588,   589,   576,
     577,     0,     0,  1561,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1751,  1752,     0,     0,  1755,     0,     0,
       0,     0,     0,     0,     0,  1761,     0,     0,     0,     0,
       0,     0,     0,  1766,  1767,     0,     0,     0,  1770,     0,
       0,   576,   577,  1773,     0,     0,     0,  1777,   578,   579,
     580,   581,   582,   583,   584,   585,     0,     0,     0,   586,
     587,   588,   589,     0,  1792,     0,     0,  1566,     0,   576,
     577,     0,   782,   783,   784,     0,   578,   579,   580,   581,
     582,   583,   584,   585,     0,     0,     0,     0,  1812,     0,
       0,     0,     0,   807,   586,   587,   588,   589,     0,  1825,
       0,     0,  1567,     0,     0,     0,     0,     0,     0,     0,
       0,  1830,     0,  1832,     0,  1834,     0,     0,     0,     0,
       0,  1840,     0,     0,  1843,     0,  1845,     0,     0,  1848,
    1849,     0,     0,     0,     0,     0,     0,     0,     0,  1856,
       0,  1858,  1859,  1860,     0,     0,  1863,     0,     0,     0,
       0,     0,  1869,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1877,     0,     0,     0,     0,
       0,   586,   587,   588,   589,  1878,     0,     0,     0,  1574,
       0,     0,     0,  1885,  1886,   576,   577,     0,     0,     0,
       0,     0,   578,   579,   580,   581,   582,   583,   584,   585,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1908,     0,     0,  1910,     0,     0,     0,  1913,  1914,
       0,     0,     0,   586,   587,   588,   589,   576,   577,     0,
       0,  1575,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   586,   587,   588,   589,     0,     0,     0,  1949,  1576,
    1951,     0,     0,  1954,     0,     0,     0,     0,     0,     0,
       0,  1959,     0,     0,  1960,     0,     0,     0,  1964,     0,
       0,     0,     0,     0,     0,     0,  1967,     0,  1969,     0,
    1004,     0,     0,     0,  1007,     0,     0,     0,  1011,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1981,     0,     0,  1025,  1026,     0,     0,     0,     0,     0,
       0,  1032,     0,     0,     0,     0,  1036,     0,  1990,     0,
    1992,  1041,     0,  1043,     0,     0,     0,   121,   122,   123,
       0,   124,   125,   126,   127,  1055,     0,  1057,  1058,     0,
    1060,  1061,  1062,  2011,     0,     0,     0,     0,  1066,     0,
       0,     0,  2016,  1070,   128,   129,     0,   586,   587,   588,
     589,  1076,     0,     0,     0,  1577,     0,     0,     0,  1083,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,   586,
     587,   588,   589,     0,     0,   137,     0,  1578,   138,     0,
       0,     0,     0,   302,     0,     0,     0,     0,     0,     0,
       0,   303,     0,     0,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   155,     0,     0,   156,   157,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,   211,   212,   213,     0,   214,   215,     0,
     216,   217,   218,     0,   219,   220,   221,   222,   223,   224,
     225,     0,     0,     0,     0,     0,   226,   227,     0,   228,
       0,     0,     0,     0,     0,     0,   229,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,   122,   123,     0,   124,   125,   126,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1283,     0,     0,   128,
     129,     0,     0,     0,  1287,     0,     0,     0,     0,  1292,
       0,  1294,     0,  1296,  1297,     0,     0,     0,  1302,  1303,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   130,   131,   132,   133,   134,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,     0,     0,   138,     0,     0,     0,     0,   139,     0,
       0,     0,     0,     0,     0,     0,   796,     0,     0,     0,
     140,   141,     0,     0,   142,     0,   143,     0,     0,     0,
       0,     0,     0,     0,   144,     0,     0,     0,     0,     0,
       0,   145,   576,   577,     0,   146,   147,     0,     0,   578,
     579,   580,   581,   582,   583,   584,   585,     0,  1390,  1391,
       0,     0,     0,   148,   149,   150,   151,   152,   153,     0,
       0,     0,     0,     0,     0,   154,     0,     0,   155,     0,
       0,   156,   157,  1406,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,     0,   210,   211,   212,
     213,     0,   214,   215,     0,   216,   217,   218,     0,   219,
     220,   221,   222,   223,   224,   225,     0,     0,     0,     0,
       0,   226,   227,     0,   228,     0,     0,     0,     0,     0,
       0,   229,     0,   304,   121,   122,   123,     0,   124,   125,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   586,   587,   588,   589,     0,     0,
       0,     0,  1581,     0,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   137,     0,     0,   138,     0,     0,     0,     0,
     139,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   140,   141,     0,     0,   142,     0,   143,     0,
       0,     0,     0,     0,     0,     0,   144,     0,     0,     0,
       0,     0,     0,   145,   576,   577,     0,   146,   147,     0,
       0,   578,   579,   580,   581,   582,   583,   584,   585,     0,
       0,     0,     0,     0,     0,   148,   149,   150,   151,   152,
     153,     0,     0,     0,     0,     0,     0,   154,     0,     0,
     155,     0,     0,   156,   157,     0,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,     0,   210,
     211,   212,   213,     0,   214,   215,     0,   216,   217,   218,
       0,   219,   220,   221,   222,   223,   224,   225,     0,     0,
       0,     0,     0,   226,   227,     0,   228,     0,     0,     0,
       0,     0,     0,   229,     0,   304,   121,   122,   123,     0,
     124,   125,   126,   127,  1635,     0,     0,  1638,     0,     0,
       0,  1642,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   586,   587,   588,   589,
       0,     0,     0,     0,  1582,     0,   130,   131,   132,   133,
     134,   135,   136,     0,     0,     0,     0,     0,     0,     0,
       0,  1698,     0,     0,   137,     0,     0,   138,     0,     0,
       0,     0,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   140,   141,     0,     0,   142,     0,
     143,     0,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,     0,     0,     0,   145,   576,   577,     0,   146,
     147,     0,     0,   578,   579,   580,   581,   582,   583,   584,
     585,     0,     0,     0,     0,     0,     0,   148,   149,   150,
     151,   152,   153,     0,     0,     0,     0,     0,     0,   154,
       0,     0,   155,     0,     0,   156,   157,     0,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
       0,   210,   211,   212,   213,     0,   214,   215,     0,   216,
     217,   218,     0,   219,   220,   221,   222,   223,   224,   225,
       0,     0,     0,     0,     0,   226,   227,     0,   228,     0,
       0,     0,     0,     0,     0,   229,   774,   121,   122,   123,
       0,   124,   125,   126,   127,     0,     0,     0,     0,  1829,
       0,     0,     0,  1833,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   586,   587,
     588,   589,     0,     0,     0,     0,  1585,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,   576,
     577,     0,     0,   139,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,   576,   577,     0,
     146,   147,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,     0,     0,     0,     0,     0,     0,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   155,     0,     0,   156,   157,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,   211,   212,   213,     0,   214,   215,     0,
     216,   217,   218,     0,   219,   220,   221,   222,   223,   224,
     225,     0,     0,     0,     0,     0,   226,   227,     0,   228,
       0,     0,     0,     0,     0,     0,   229,   853,   121,   122,
     123,     0,   124,   125,   126,   127,     0,     0,     0,     0,
       0,   586,   587,   588,   589,     0,     0,     0,     0,  1593,
       0,     0,     0,     0,     0,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   586,
     587,   588,   589,     0,     0,     0,     0,  1596,   130,   131,
     132,   133,   134,   135,   136,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,   138,
     576,   577,     0,     0,   139,     0,     0,   578,   579,   580,
     581,   582,   583,   584,   585,     0,   140,   141,     0,     0,
     142,     0,   143,     0,     0,     0,     0,     0,     0,     0,
     144,     0,     0,     0,     0,     0,     0,   145,   576,   577,
       0,   146,   147,     0,     0,   578,   579,   580,   581,   582,
     583,   584,   585,     0,     0,     0,     0,     0,     0,   148,
     149,   150,   151,   152,   153,     0,     0,     0,     0,     0,
       0,   154,     0,     0,   155,     0,     0,   156,   157,     0,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,     0,   210,   211,   212,   213,     0,   214,   215,
       0,   216,   217,   218,     0,   219,   220,   221,   222,   223,
     224,   225,     0,     0,     0,     0,     0,   226,   227,     0,
     228,     0,     0,     0,     0,     0,     0,   229,   864,   121,
     122,   123,     0,   124,   125,   126,   127,     0,     0,     0,
       0,     0,   586,   587,   588,   589,     0,     0,     0,     0,
    1611,     0,     0,     0,     0,     0,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   587,   588,   589,     0,     0,     0,     0,  1725,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     138,     0,     0,     0,     0,   139,     0,     0,     0,     0,
       0,   403,     0,     0,     0,     0,     0,   140,   141,     0,
       0,   142,     0,   143,     0,     0,     0,     0,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   404,   405,
     148,   149,   150,   151,   152,   153,     0,   406,   407,   408,
     409,     0,   154,     0,     0,   155,     0,     0,   156,   157,
       0,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   210,   211,   212,   213,     0,   214,
     215,     0,   216,   217,   218,     0,   219,   220,   221,   222,
     223,   224,   225,     0,     0,     0,     0,     0,   226,   227,
       0,   228,     0,     0,     0,   121,   122,   123,   229,   124,
     125,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   411,     0,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,     0,   138,     0,     0,     0,
       0,   139,     0,     0,     0,     0,     0,   412,     0,     0,
       0,     0,     0,   140,   141,     0,     0,   142,     0,   143,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   413,   414,   148,   149,   150,   151,
     152,   153,   415,     0,     0,     0,   416,     0,   154,     0,
       0,   155,     0,     0,   156,   157,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     210,   211,   212,   213,     0,   214,   215,     0,   216,   217,
     218,     0,   219,   220,   221,   222,   223,   224,   225,     0,
       0,     0,     0,     0,   226,   227,     0,   228,     0,     0,
       0,   121,   122,   123,   229,   124,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,   138,     0,     0,     0,     0,   139,     0,     0,
       0,     0,     0,   392,     0,     0,     0,     0,     0,   140,
     141,     0,     0,   142,     0,   143,     0,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     393,   394,   148,   149,   150,   151,   152,   153,     0,   395,
       0,     0,   396,     0,   154,     0,     0,   155,     0,     0,
     156,   157,     0,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   210,   211,   212,   213,
       0,   214,   215,     0,   216,   217,   218,     0,   219,   220,
     221,   222,   223,   224,   225,     0,     0,     0,     0,     0,
     226,   227,     0,   228,     0,     0,     0,   121,   122,   123,
     229,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   361,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     0,   362,
       0,     0,     0,     0,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,   363,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   364,     0,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   155,     0,     0,   156,   157,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,   211,   212,   213,     0,   214,   215,     0,
     216,   217,   218,     0,   219,   220,   221,   222,   223,   224,
     225,     0,     0,     0,     0,     0,   226,   227,     0,   228,
       0,     0,     0,   121,   122,   123,   229,   124,   125,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,   138,     0,     0,     0,     0,   139,
       0,     0,     0,     0,     0,   398,     0,     0,     0,     0,
       0,   140,   141,     0,     0,   142,     0,   143,     0,     0,
       0,     0,     0,     0,     0,   144,     0,     0,     0,     0,
       0,     0,   145,     0,     0,     0,   146,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   399,   400,   148,   149,   150,   151,   152,   153,
       0,     0,     0,     0,   401,     0,   154,     0,     0,   155,
       0,     0,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,     0,   210,   211,
     212,   213,     0,   214,   215,     0,   216,   217,   218,     0,
     219,   220,   221,   222,   223,   224,   225,     0,     0,     0,
       0,     0,   226,   227,     0,   228,     0,     0,     0,   121,
     122,   123,   229,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   367,     0,
       0,     0,     0,     0,     0,     0,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   368,     0,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     138,   576,   577,     0,     0,   139,     0,     0,   578,   579,
     580,   581,   582,   583,   584,   585,     0,   140,   141,     0,
       0,   142,     0,   143,     0,     0,     0,   369,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,   150,   151,   152,   153,     0,     0,     0,     0,
       0,     0,   154,     0,     0,   155,     0,     0,   156,   157,
       0,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   210,   211,   212,   213,     0,   214,
     215,     0,   216,   217,   218,     0,   219,   220,   221,   222,
     223,   224,   225,     0,     0,     0,     0,     0,   226,   227,
       0,   228,     0,     0,     0,   121,   122,   123,   229,   124,
     125,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   586,   587,   588,   589,     0,     0,     0,
       0,  1729,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,     0,   138,   576,   577,     0,
       0,   139,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,     0,   140,   141,     0,     0,   142,     0,   143,
       0,     0,     0,   381,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   382,   383,   148,   149,   150,   151,
     152,   153,     0,     0,     0,     0,     0,     0,   154,     0,
       0,   155,     0,     0,   156,   157,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     210,   211,   212,   213,     0,   214,   215,     0,   216,   217,
     218,     0,   219,   220,   221,   222,   223,   224,   225,     0,
       0,     0,     0,     0,   226,   227,     0,   228,     0,     0,
       0,   121,   122,   123,   229,   124,   125,   126,   127,     0,
     319,     0,     0,     0,     0,     0,     0,     0,     0,   586,
     587,   588,   589,     0,     0,     0,     0,  1790,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,   138,   576,   577,     0,     0,   139,     0,     0,
     578,   579,   580,   581,   582,   583,   584,   585,     0,   140,
     141,     0,     0,   142,     0,   143,     0,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,   149,   150,   151,   152,   153,     0,     0,
       0,     0,     0,     0,   154,     0,     0,   155,     0,     0,
     156,   157,     0,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   210,   211,   212,   213,
       0,   214,   215,     0,   216,   217,   218,     0,   219,   220,
     221,   222,   223,   224,   225,     0,     0,     0,     0,     0,
     226,   227,     0,   228,     0,     0,     0,   121,   122,   123,
     229,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   586,   587,   588,   589,     0,
       0,     0,     0,  1799,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,     0,
       0,     0,     0,   139,     0,     0,     0,     0,     0,   358,
       0,     0,     0,     0,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,   359,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   155,     0,     0,   156,   157,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,   211,   212,   213,     0,   214,   215,     0,
     216,   217,   218,     0,   219,   220,   221,   222,   223,   224,
     225,     0,     0,     0,     0,     0,   226,   227,     0,   228,
       0,     0,     0,   121,   122,   123,   229,   124,   125,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,   138,   576,   577,     0,     0,   139,
       0,     0,   578,   579,   580,   581,   582,   583,   584,   585,
       0,   140,   141,     0,     0,   142,     0,   143,     0,     0,
       0,     0,   431,     0,     0,   144,     0,     0,     0,     0,
       0,     0,   145,     0,     0,     0,   146,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   432,   148,   149,   150,   151,   152,   153,
       0,     0,     0,     0,     0,     0,   154,     0,     0,   155,
       0,     0,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,     0,   210,   211,
     212,   213,     0,   214,   215,     0,   216,   217,   218,     0,
     219,   220,   221,   222,   223,   224,   225,     0,     0,     0,
       0,     0,   226,   227,     0,   228,     0,     0,     0,   121,
     122,   123,   229,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   586,   587,   588,
     589,     0,     0,     0,     0,  1802,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     138,   576,   577,     0,     0,   139,     0,     0,   578,   579,
     580,   581,   582,   583,   584,   585,     0,   140,   141,     0,
       0,   142,     0,   143,     0,     0,     0,     0,   463,   464,
       0,   144,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,   150,   151,   152,   153,     0,     0,     0,     0,
       0,     0,   154,     0,     0,   155,     0,     0,   156,   157,
       0,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   210,   211,   212,   213,     0,   214,
     215,     0,   216,   217,   218,     0,   219,   220,   221,   222,
     223,   224,   225,     0,     0,     0,     0,     0,   226,   227,
       0,   228,     0,     0,     0,   121,   122,   123,   229,   124,
     125,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   586,   587,   588,   589,     0,     0,     0,
       0,  1803,   128,   129,     0,     0,   261,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,     0,   138,   576,   577,     0,
       0,   139,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,     0,   140,   141,     0,     0,   142,     0,   143,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,   150,   151,
     152,   153,     0,     0,     0,     0,     0,     0,   154,     0,
       0,   155,     0,     0,   156,   157,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     210,   211,   212,   213,     0,   214,   215,     0,   216,   217,
     218,     0,   219,   220,   221,   222,   223,   224,   225,     0,
       0,     0,     0,     0,   226,   227,     0,   228,     0,     0,
       0,   121,   122,   123,   229,   124,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   586,
     587,   588,   589,     0,     0,     0,     0,  1805,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,   138,   576,   577,     0,     0,   139,     0,     0,
     578,   579,   580,   581,   582,   583,   584,   585,     0,   140,
     141,     0,     0,   142,     0,   143,     0,     0,     0,   322,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,   149,   150,   151,   152,   153,     0,     0,
       0,     0,     0,     0,   154,     0,     0,   155,     0,     0,
     156,   157,     0,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   210,   211,   212,   213,
       0,   214,   215,     0,   216,   217,   218,     0,   219,   220,
     221,   222,   223,   224,   225,     0,     0,     0,     0,     0,
     226,   227,     0,   228,     0,     0,     0,   121,   122,   123,
     229,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   586,   587,   588,   589,     0,
       0,     0,     0,  1822,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,   576,
     577,     0,     0,   139,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,   354,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   155,     0,     0,   156,   157,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,   211,   212,   213,     0,   214,   215,     0,
     216,   217,   218,     0,   219,   220,   221,   222,   223,   224,
     225,     0,     0,     0,     0,     0,   226,   227,     0,   228,
       0,     0,     0,   121,   122,   123,   229,   124,   125,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   586,   587,   588,   589,     0,     0,     0,     0,  1931,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,   138,   576,   577,     0,     0,   139,
       0,     0,   578,   579,   580,   581,   582,   583,   584,   585,
       0,   140,   141,     0,     0,   142,     0,   143,     0,     0,
       0,   356,     0,     0,     0,   144,     0,     0,     0,     0,
       0,     0,   145,     0,     0,     0,   146,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   149,   150,   151,   152,   153,
       0,     0,     0,     0,     0,     0,   154,     0,     0,   155,
       0,     0,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,     0,   210,   211,
     212,   213,     0,   214,   215,     0,   216,   217,   218,     0,
     219,   220,   221,   222,   223,   224,   225,     0,     0,     0,
       0,     0,   226,   227,     0,   228,     0,     0,     0,   121,
     122,   123,   229,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   586,   587,   588,
     589,     0,     0,     0,     0,  1944,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     138,   576,   577,     0,     0,   139,     0,     0,   578,   579,
     580,   581,   582,   583,   584,   585,     0,   140,   141,     0,
       0,   142,     0,   143,     0,     0,     0,   371,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,   150,   151,   152,   153,     0,     0,     0,     0,
       0,     0,   154,     0,     0,   155,     0,     0,   156,   157,
       0,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   210,   211,   212,   213,     0,   214,
     215,     0,   216,   217,   218,     0,   219,   220,   221,   222,
     223,   224,   225,     0,     0,     0,     0,     0,   226,   227,
       0,   228,     0,     0,     0,   121,   122,   123,   229,   124,
     125,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   586,   587,   588,   589,     0,     0,     0,
       0,  1987,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,     0,   138,   576,   577,     0,
       0,   139,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,     0,   140,   141,     0,     0,   142,     0,   143,
       0,     0,     0,   373,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,   150,   151,
     152,   153,     0,     0,     0,     0,     0,     0,   154,     0,
       0,   155,     0,     0,   156,   157,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     210,   211,   212,   213,     0,   214,   215,     0,   216,   217,
     218,     0,   219,   220,   221,   222,   223,   224,   225,     0,
       0,     0,     0,     0,   226,   227,     0,   228,     0,     0,
       0,   121,   122,   123,   229,   124,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   586,
     587,   588,   589,     0,     0,     0,     0,  2008,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,   138,   576,   577,     0,     0,   139,     0,     0,
     578,   579,   580,   581,   582,   583,   584,   585,     0,   140,
     141,     0,     0,   142,     0,   143,     0,     0,     0,   385,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
     145,     0,     0,     0,   146,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   148,   149,   150,   151,   152,   153,     0,     0,
       0,     0,     0,     0,   154,     0,     0,   155,     0,     0,
     156,   157,     0,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   210,   211,   212,   213,
       0,   214,   215,     0,   216,   217,   218,     0,   219,   220,
     221,   222,   223,   224,   225,     0,     0,     0,     0,     0,
     226,   227,     0,   228,     0,     0,     0,   121,   122,   123,
     229,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   586,   587,   588,   589,     0,
       0,     0,     0,  2023,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,     0,     0,   138,   576,
     577,     0,     0,   139,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,     0,   140,   141,     0,     0,   142,
       0,   143,     0,     0,     0,   388,     0,     0,     0,   144,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
     146,   147,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,   149,
     150,   151,   152,   153,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   155,     0,     0,   156,   157,     0,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,   211,   212,   213,     0,   214,   215,     0,
     216,   217,   218,     0,   219,   220,   221,   222,   223,   224,
     225,     0,     0,     0,     0,     0,   226,   227,     0,   228,
       0,     0,     0,   121,   122,   123,   229,   124,   125,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   586,   587,   588,   589,     0,     0,   642,     0,     0,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,     0,     0,   138,   576,   577,     0,     0,   139,
       0,     0,   578,   579,   580,   581,   582,   583,   584,   585,
       0,   140,   141,     0,     0,   142,     0,   143,     0,     0,
       0,   418,     0,     0,     0,   144,     0,     0,     0,     0,
       0,     0,   145,     0,     0,     0,   146,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   148,   149,   150,   151,   152,   153,
       0,     0,     0,     0,     0,     0,   154,     0,     0,   155,
       0,     0,   156,   157,     0,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,     0,   210,   211,
     212,   213,     0,   214,   215,     0,   216,   217,   218,     0,
     219,   220,   221,   222,   223,   224,   225,     0,     0,     0,
       0,     0,   226,   227,     0,   228,     0,     0,     0,   121,
     122,   123,   229,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   586,   587,   588,
     589,     0,     0,   659,     0,     0,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,     0,     0,
     138,   576,   577,     0,     0,   139,     0,     0,   578,   579,
     580,   581,   582,   583,   584,   585,     0,   140,   141,     0,
       0,   142,     0,   143,     0,     0,     0,   420,     0,     0,
       0,   144,     0,     0,     0,     0,     0,     0,   145,     0,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,   149,   150,   151,   152,   153,     0,     0,     0,     0,
       0,     0,   154,     0,     0,   155,     0,     0,   156,   157,
       0,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   210,   211,   212,   213,     0,   214,
     215,     0,   216,   217,   218,     0,   219,   220,   221,   222,
     223,   224,   225,     0,     0,     0,     0,     0,   226,   227,
       0,   228,     0,     0,     0,   121,   122,   123,   229,   124,
     125,   126,   127,     0,   668,     0,     0,     0,     0,     0,
       0,     0,     0,   586,   587,   588,   589,     0,     0,   769,
       0,     0,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,     0,     0,   138,   576,   577,     0,
       0,   139,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,     0,   140,   141,     0,     0,   142,     0,   143,
       0,     0,     0,     0,     0,     0,     0,   144,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,   146,   147,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,   149,   150,   151,
     152,   153,     0,     0,     0,     0,     0,     0,   154,     0,
       0,   155,     0,     0,   156,   157,     0,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     210,   211,   212,   213,     0,   214,   215,     0,   216,   217,
     218,     0,   219,   220,   221,   222,   223,   224,   225,     0,
       0,     0,     0,     0,   226,   227,     0,   228,     0,     0,
       0,   121,   122,   123,   229,   124,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   586,
     587,   588,   589,     0,     0,   994,     0,     0,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
       0,     0,   138,   576,   577,     0,     0,   139,     0,     0,
     578,   579,   580,   581,   582,   583,   584,   585,     0,   140,
     141,     0,     0,   142,     0,   143,     0,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
     145,   576,   577,     0,   146,   147,     0,     0,   578,   579,
     580,   581,   582,   583,   584,   585,   123,     0,     0,     0,
       0,   127,   148,   149,   150,   151,   152,   153,     0,     0,
       0,     0,     0,     0,   154,     0,     0,   155,     0,     0,
     156,   157,   129,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,     0,   210,   211,   212,   213,
       0,   214,   215,     0,   216,   217,   218,     0,   219,   220,
     221,   222,   223,   224,   225,     0,   142,     0,   143,     0,
     226,   227,     0,   228,     0,     0,   123,     0,     0,     0,
     229,   127,     0,     0,     0,     0,     0,   146,   147,     0,
       0,     0,     0,     0,     0,   586,   587,   588,   589,     0,
       0,  1024,   129,     0,     0,   237,   238,   239,   240,   152,
       0,     0,     0,     0,     0,     0,     0,   154,     0,     0,
     155,     0,     0,   156,   241,     0,     0,     0,     0,     0,
       0,     0,     0,   586,   587,   588,   589,     0,     0,  1119,
       0,     0,     0,     0,     0,     0,     0,   179,   180,   181,
       0,     0,     0,   185,   186,   187,     0,   189,     0,   191,
     192,   193,     0,     0,     0,     0,   198,   199,   200,   201,
     202,     0,     0,   205,     0,   207,   142,   209,   143,     0,
     211,     0,   213,     0,     0,   215,     0,     0,   217,   218,
       0,   219,   220,     0,   222,     0,   224,   146,   147,     0,
       0,     0,     0,     0,   227,   123,     0,     0,     0,     0,
     127,     0,     0,   242,   873,   237,   238,   239,   240,   152,
       0,     0,     0,     0,     0,     0,     0,   154,     0,     0,
     155,   129,     0,   156,   241,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   179,   180,   181,
       0,     0,     0,   185,   186,   187,     0,   189,     0,   191,
     192,   193,     0,     0,     0,     0,   198,   199,   200,   201,
     202,     0,     0,   205,     0,   207,     0,   209,     0,     0,
     211,     0,   213,     0,     0,   215,     0,     0,   217,   218,
       0,   219,   220,     0,   222,   142,   224,   143,     0,     0,
       0,     0,     0,     0,   227,   123,     0,     0,     0,     0,
     127,     0,     0,   242,   875,     0,   146,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,     0,     0,   237,   238,   239,   240,   152,     0,
       0,     0,     0,     0,     0,     0,   154,     0,     0,   155,
       0,     0,   156,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   179,   180,   181,     0,
       0,     0,   185,   186,   187,     0,   189,     0,   191,   192,
     193,     0,     0,     0,     0,   198,   199,   200,   201,   202,
       0,     0,   205,     0,   207,   142,   209,   143,     0,   211,
       0,   213,     0,     0,   215,     0,     0,   217,   218,     0,
     219,   220,     0,   222,     0,   224,   146,   147,     0,     0,
       0,     0,     0,   227,   123,     0,     0,     0,     0,   127,
       0,     0,   242,   877,   237,   238,   239,   240,   152,     0,
       0,     0,     0,     0,     0,     0,   154,     0,     0,   155,
     129,     0,   156,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   179,   180,   181,     0,
       0,     0,   185,   186,   187,     0,   189,     0,   191,   192,
     193,     0,     0,     0,     0,   198,   199,   200,   201,   202,
       0,     0,   205,     0,   207,     0,   209,     0,     0,   211,
       0,   213,     0,     0,   215,     0,     0,   217,   218,     0,
     219,   220,     0,   222,   142,   224,   143,     0,     0,     0,
     375,     0,     0,   227,     0,     0,     0,     0,     0,     0,
       0,     0,   242,   879,     0,   146,   147,     0,     0,     0,
       0,   123,     0,     0,     0,     0,   127,     0,     0,     0,
       0,     0,     0,   237,   238,   239,   240,   152,     0,     0,
       0,     0,     0,     0,     0,   154,     0,   129,   155,     0,
       0,   156,   241,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   179,   180,   181,     0,     0,
       0,   185,   186,   187,     0,   189,     0,   191,   192,   193,
       0,     0,     0,     0,   198,   199,   200,   201,   202,     0,
       0,   205,     0,   207,     0,   209,     0,     0,   211,     0,
     213,     0,     0,   215,     0,     0,   217,   218,     0,   219,
     220,   142,   222,   143,   224,     0,     0,   422,     0,     0,
       0,     0,   227,     0,     0,     0,     0,     0,     0,   123,
       0,   242,   146,   147,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,   240,   152,   129,     0,     0,     0,     0,
       0,     0,   154,     0,     0,   155,     0,     0,   156,   241,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   179,   180,   181,     0,     0,     0,   185,   186,
     187,     0,   189,     0,   191,   192,   193,     0,     0,     0,
       0,   198,   199,   200,   201,   202,     0,     0,   205,     0,
     207,     0,   209,     0,     0,   211,     0,   213,     0,   142,
     215,   143,     0,   217,   218,   424,   219,   220,     0,   222,
       0,   224,     0,     0,     0,     0,     0,   123,     0,   227,
     146,   147,   127,     0,     0,     0,     0,     0,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,   238,
     239,   240,   152,   129,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   155,     0,     0,   156,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     179,   180,   181,     0,     0,     0,   185,   186,   187,     0,
     189,     0,   191,   192,   193,     0,     0,     0,     0,   198,
     199,   200,   201,   202,     0,     0,   205,     0,   207,     0,
     209,     0,     0,   211,     0,   213,     0,   142,   215,   143,
       0,   217,   218,   426,   219,   220,     0,   222,     0,   224,
       0,     0,     0,     0,     0,   123,     0,   227,   146,   147,
     127,     0,     0,     0,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,   240,
     152,   129,     0,     0,     0,     0,     0,     0,   154,     0,
       0,   155,     0,     0,   156,   241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,   180,
     181,     0,     0,     0,   185,   186,   187,     0,   189,     0,
     191,   192,   193,     0,     0,     0,     0,   198,   199,   200,
     201,   202,     0,     0,   205,     0,   207,     0,   209,     0,
       0,   211,     0,   213,     0,   142,   215,   143,     0,   217,
     218,     0,   219,   220,     0,   222,     0,   224,     0,     0,
       0,     0,     0,   123,     0,   227,   146,   147,   127,     0,
       0,     0,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   239,   240,   152,   129,
     749,     0,     0,     0,     0,     0,   154,     0,     0,   155,
       0,     0,   156,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   179,   180,   181,     0,
       0,     0,   185,   186,   187,     0,   189,     0,   191,   192,
     193,     0,     0,     0,     0,   198,   199,   200,   201,   202,
       0,     0,   205,     0,   207,     0,   209,     0,     0,   211,
       0,   213,     0,   142,   215,   143,     0,   217,   218,     0,
     219,   220,     0,   222,     0,   224,     0,     0,     0,     0,
       0,   123,     0,   227,   146,   147,   127,     0,     0,     0,
       0,     0,   242,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,   239,   240,   152,   129,   825,     0,
       0,     0,     0,     0,   154,     0,     0,   155,     0,     0,
     156,   241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   179,   180,   181,     0,     0,     0,
     185,   186,   187,     0,   189,     0,   191,   192,   193,     0,
       0,     0,     0,   198,   199,   200,   201,   202,     0,     0,
     205,     0,   207,   997,   209,     0,     0,   211,     0,   213,
       0,   142,   215,   143,     0,   217,   218,     0,   219,   220,
       0,   222,     0,   224,     0,     0,     0,     0,     0,   123,
       0,   227,   146,   147,   127,     0,     0,     0,     0,     0,
     242,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     237,   238,   239,   240,   152,   129,     0,     0,     0,     0,
       0,     0,   154,     0,     0,   155,     0,     0,   156,   241,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   179,   180,   181,     0,     0,     0,   185,   186,
     187,     0,   189,     0,   191,   192,   193,     0,     0,     0,
       0,   198,   199,   200,   201,   202,     0,     0,   205,     0,
     207,  1399,   209,     0,     0,   211,     0,   213,     0,   142,
     215,   143,     0,   217,   218,     0,   219,   220,     0,   222,
       0,   224,     0,     0,     0,     0,     0,   123,     0,   227,
     146,   147,   127,     0,     0,     0,     0,     0,   242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,   238,
     239,   240,   152,   129,     0,     0,     0,     0,     0,     0,
     154,     0,     0,   155,     0,     0,   156,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     179,   180,   181,     0,     0,     0,   185,   186,   187,     0,
     189,     0,   191,   192,   193,     0,     0,     0,     0,   198,
     199,   200,   201,   202,     0,     0,   205,     0,   207,     0,
     209,     0,     0,   211,     0,   213,     0,   142,   215,   143,
       0,   217,   218,     0,   219,   220,     0,   222,     0,   224,
       0,     0,     0,     0,     0,   123,     0,   227,   146,   147,
     127,     0,     0,     0,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   237,   238,   239,   240,
     152,   129,     0,     0,     0,     0,     0,     0,   154,     0,
       0,   155,     0,     0,   156,   241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,   180,
     181,     0,     0,     0,   185,   186,   187,     0,   189,     0,
     191,   192,   193,     0,     0,     0,     0,   198,   199,   200,
     201,   202,     0,     0,   205,     0,   207,     0,   209,     0,
       0,   211,     0,   213,     0,   142,   215,   143,     0,   217,
     218,     0,   219,   220,     0,   222,     0,   224,     0,     0,
       0,     0,     0,     0,     0,   227,   146,   147,     0,     0,
       0,     0,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   238,   239,   240,   152,     0,
       0,     0,     0,     0,     0,     0,   154,     0,     0,   155,
       0,     0,   156,   241,     0,     0,     0,     0,   576,   577,
       0,     0,     0,     0,     0,   578,   579,   580,   581,   582,
     583,   584,   585,     0,     0,     0,   179,   180,   181,     0,
       0,     0,   185,   186,   187,     0,   189,     0,   191,   192,
     193,     0,     0,     0,     0,   198,   199,   200,   201,   202,
       0,     0,   205,     0,   207,     0,   209,     0,     0,   211,
       0,   213,     0,     0,   215,     0,     0,   217,   218,     0,
     219,   220,     0,   222,     0,   224,     0,     0,     7,     8,
       9,     0,     0,   227,     0,    10,     0,     0,     0,    11,
       0,    12,  1256,    13,    14,    15,    16,    17,  -477,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,     0,     0,     0,     0,    29,     0,     0,    30,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    37,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,    45,    46,    47,  -235,  -235,    48,    49,
      50,     0,    51,    52,    53,     0,     0,    54,  -235,     0,
      55,     0,    56,    57,     0,     0,     0,     0,    58,    59,
     586,   587,   588,   589,     0,    60,  1120,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,     0,     0,    90,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,    93,    94,     0,     0,     0,     0,    95,     0,     0,
       0,     0,   576,   577,     0,     0,     0,     0,     0,   578,
     579,   580,   581,   582,   583,   584,   585,    96,     0,     0,
       0,    97,     0,     7,     8,     9,    98,     0,     0,    99,
      10,     0,     0,   100,    11,     0,    12,     0,    13,    14,
      15,    16,    17,  -477,     0,    18,    19,    20,    21,    22,
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
       0,     0,    90,    91,   586,   587,   588,   589,     0,     0,
    1122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    93,    94,     0,     0,
       0,     0,    95,     0,     0,     0,     0,   576,   577,     0,
       0,     0,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,    96,     0,     0,     0,    97,     0,     7,     8,
       9,    98,     0,     0,    99,    10,     0,     0,   100,    11,
       0,    12,     0,    13,    14,    15,    16,    17,  -477,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,   -16,     0,     0,     0,    29,   -16,     0,    30,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,   576,   577,     0,    37,    38,     0,     0,   578,
     579,   580,   581,   582,   583,   584,   585,     0,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,    45,    46,    47,     0,     0,    48,    49,
      50,     0,    51,    52,    53,     0,     0,    54,     0,     0,
      55,     0,    56,    57,     0,     0,     0,     0,    58,    59,
       0,     0,     0,     0,     0,    60,     0,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,     0,     0,    90,    91,   586,
     587,   588,   589,   576,   577,  1123,     0,     0,     0,     0,
     578,   579,   580,   581,   582,   583,   584,   585,     0,     0,
      92,    93,    94,   576,   577,     0,     0,    95,     0,     0,
     578,   579,   580,   581,   582,   583,   584,   585,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,     0,     0,
       0,    97,     0,     0,     0,     0,    98,   576,   577,    99,
       0,     0,     0,   100,   578,   579,   580,   581,   582,   583,
     584,   585,     0,     0,   586,   587,   588,   589,   576,   577,
    1124,     0,     0,     0,     0,   578,   579,   580,   581,   582,
     583,   584,   585,   576,   577,     0,     0,     0,     0,     0,
     578,   579,   580,   581,   582,   583,   584,   585,   576,   577,
       0,     0,     0,     0,     0,   578,   579,   580,   581,   582,
     583,   584,   585,   576,   577,     0,     0,     0,     0,     0,
     578,   579,   580,   581,   582,   583,   584,   585,   576,   577,
       0,     0,     0,     0,     0,   578,   579,   580,   581,   582,
     583,   584,   585,   576,   577,     0,     0,     0,     0,     0,
     578,   579,   580,   581,   582,   583,   584,   585,   576,   577,
       0,     0,     0,     0,     0,   578,   579,   580,   581,   582,
     583,   584,   585,     0,     0,   586,   587,   588,   589,   576,
     577,  1138,     0,     0,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,     0,   586,   587,   588,   589,   576,
     577,  1171,     0,     0,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,   576,   577,     0,     0,     0,     0,
       0,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   576,   577,  1178,     0,     0,     0,     0,
     578,   579,   580,   581,   582,   583,   584,   585,     0,     0,
     586,   587,   588,   589,     0,     0,  1179,     0,     0,     0,
       0,     0,     0,     0,     0,   586,   587,   588,   589,     0,
       0,  1199,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   587,   588,   589,     0,     0,  1251,     0,     0,     0,
       0,     0,     0,     0,     0,   586,   587,   588,   589,     0,
       0,  1274,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   587,   588,   589,     0,     0,  1275,     0,     0,     0,
       0,     0,     0,     0,     0,   586,   587,   588,   589,     0,
       0,  1282,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   587,   588,   589,   576,   577,  1288,     0,     0,     0,
       0,   578,   579,   580,   581,   582,   583,   584,   585,     0,
       0,   586,   587,   588,   589,   576,   577,  1289,     0,     0,
       0,     0,   578,   579,   580,   581,   582,   583,   584,   585,
       0,   586,   587,   588,   589,     0,     0,  1329,     0,     0,
       0,     0,     0,     0,     0,     0,   586,   587,   588,   589,
     576,   577,  1381,     0,     0,     0,     0,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,   576,
     577,  1386,     0,     0,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,   576,   577,     0,     0,     0,     0,
       0,   578,   579,   580,   581,   582,   583,   584,   585,   576,
     577,     0,     0,     0,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,   576,   577,     0,     0,     0,     0,
       0,   578,   579,   580,   581,   582,   583,   584,   585,   576,
     577,     0,     0,     0,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,   576,   577,     0,     0,     0,     0,
       0,   578,   579,   580,   581,   582,   583,   584,   585,   576,
     577,     0,     0,     0,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,     0,     0,   586,   587,   588,   589,
     576,   577,  1387,     0,     0,     0,     0,   578,   579,   580,
     581,   582,   583,   584,   585,     0,     0,   586,   587,   588,
     589,   576,   577,  1456,     0,     0,     0,     0,   578,   579,
     580,   581,   582,   583,   584,   585,   576,   577,     0,     0,
       0,     0,     0,   578,   579,   580,   581,   582,   583,   584,
     585,     0,   586,   587,   588,   589,   576,   577,  1461,     0,
       0,     0,     0,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,     0,     0,  1475,     0,     0,
       0,     0,     0,     0,     0,     0,   586,   587,   588,   589,
       0,     0,  1487,     0,     0,     0,     0,     0,     0,     0,
       0,   586,   587,   588,   589,     0,     0,  1492,     0,     0,
       0,     0,     0,     0,     0,     0,   586,   587,   588,   589,
       0,     0,  1493,     0,     0,     0,     0,     0,     0,     0,
       0,   586,   587,   588,   589,     0,     0,  1494,     0,     0,
       0,     0,     0,     0,     0,     0,   586,   587,   588,   589,
       0,     0,  1497,     0,     0,     0,     0,     0,     0,     0,
       0,   586,   587,   588,   589,   576,   577,  1524,     0,     0,
       0,     0,   578,   579,   580,   581,   582,   583,   584,   585,
       0,     0,   586,   587,   588,   589,   576,   577,  1531,     0,
       0,     0,     0,   578,   579,   580,   581,   582,   583,   584,
     585,     0,     0,   586,   587,   588,   589,     0,     0,  1536,
       0,     0,     0,     0,     0,     0,     0,     0,   586,   587,
     588,   589,   576,   577,  1539,     0,     0,     0,     0,   578,
     579,   580,   581,   582,   583,   584,   585,     0,   586,   587,
     588,   589,   576,   577,  1571,     0,     0,     0,     0,   578,
     579,   580,   581,   582,   583,   584,   585,   576,   577,     0,
       0,     0,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,   576,   577,     0,     0,     0,     0,     0,   578,
     579,   580,   581,   582,   583,   584,   585,   576,   577,     0,
       0,     0,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,   576,   577,     0,     0,     0,     0,     0,   578,
     579,   580,   581,   582,   583,   584,   585,   576,   577,     0,
       0,     0,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,   576,   577,     0,     0,     0,     0,     0,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   576,   577,  1594,     0,     0,     0,     0,   578,   579,
     580,   581,   582,   583,   584,   585,     0,     0,   586,   587,
     588,   589,   576,   577,  1595,     0,     0,     0,     0,   578,
     579,   580,   581,   582,   583,   584,   585,   576,   577,     0,
       0,     0,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,     0,     0,   586,   587,   588,   589,   576,   577,
    1617,     0,     0,     0,     0,   578,   579,   580,   581,   582,
     583,   584,   585,     0,   586,   587,   588,   589,     0,     0,
    1631,     0,     0,     0,     0,     0,     0,     0,     0,   586,
     587,   588,   589,     0,     0,  1744,     0,     0,     0,     0,
       0,     0,     0,     0,   586,   587,   588,   589,     0,     0,
    1745,     0,     0,     0,     0,     0,     0,     0,     0,   586,
     587,   588,   589,     0,     0,  1746,     0,     0,     0,     0,
       0,     0,     0,     0,   586,   587,   588,   589,     0,     0,
    1748,     0,     0,     0,     0,     0,     0,     0,     0,   586,
     587,   588,   589,     0,     0,  1754,     0,     0,     0,     0,
       0,     0,     0,     0,   586,   587,   588,   589,   576,   577,
    1757,     0,     0,     0,     0,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   576,   577,  1762,
       0,     0,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,     0,     0,   586,   587,   588,   589,     0,     0,
    1763,     0,     0,     0,     0,     0,     0,     0,     0,   586,
     587,   588,   589,   576,   577,  1774,     0,     0,     0,     0,
     578,   579,   580,   581,   582,   583,   584,   585,     0,     0,
     586,   587,   588,   589,   576,   577,  1775,     0,     0,     0,
       0,   578,   579,   580,   581,   582,   583,   584,   585,   576,
     577,     0,     0,     0,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,   576,   577,     0,     0,     0,     0,
       0,   578,   579,   580,   581,   582,   583,   584,   585,   576,
     577,     0,     0,     0,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,   576,   577,     0,     0,     0,     0,
       0,   578,   579,   580,   581,   582,   583,   584,   585,   576,
     577,     0,     0,     0,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,   576,   577,     0,     0,     0,     0,
       0,   578,   579,   580,   581,   582,   583,   584,   585,     0,
     586,   587,   588,   589,   576,   577,  1776,     0,     0,     0,
       0,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   576,   577,  1779,     0,     0,     0,     0,
     578,   579,   580,   581,   582,   583,   584,   585,   576,   577,
       0,     0,     0,     0,     0,   578,   579,   580,   581,   582,
     583,   584,   585,     0,     0,   586,   587,   588,   589,   576,
     577,  1783,     0,     0,     0,     0,   578,   579,   580,   581,
     582,   583,   584,   585,     0,     0,   586,   587,   588,   589,
       0,     0,  1798,     0,     0,     0,     0,     0,     0,     0,
       0,   586,   587,   588,   589,     0,     0,  1817,     0,     0,
       0,     0,     0,     0,     0,     0,   586,   587,   588,   589,
       0,     0,  1837,     0,     0,     0,     0,     0,     0,     0,
       0,   586,   587,   588,   589,     0,     0,  1838,     0,     0,
       0,     0,     0,     0,     0,     0,   586,   587,   588,   589,
       0,     0,  1841,     0,     0,     0,     0,     0,     0,     0,
       0,   586,   587,   588,   589,     0,     0,  1847,     0,     0,
       0,     0,     0,     0,     0,     0,   586,   587,   588,   589,
     576,   577,  1852,     0,     0,     0,     0,   578,   579,   580,
     581,   582,   583,   584,   585,     0,   586,   587,   588,   589,
     576,   577,  1853,     0,     0,     0,     0,   578,   579,   580,
     581,   582,   583,   584,   585,   586,   587,   588,   589,     0,
       0,  1854,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   587,   588,   589,   576,   577,  1857,     0,     0,     0,
       0,   578,   579,   580,   581,   582,   583,   584,   585,     0,
       0,   586,   587,   588,   589,   576,   577,  1861,     0,     0,
       0,     0,   578,   579,   580,   581,   582,   583,   584,   585,
     576,   577,     0,     0,     0,     0,     0,   578,   579,   580,
     581,   582,   583,   584,   585,   576,   577,     0,     0,     0,
       0,     0,   578,   579,   580,   581,   582,   583,   584,   585,
     576,   577,     0,     0,     0,     0,     0,   578,   579,   580,
     581,   582,   583,   584,   585,   576,   577,     0,     0,     0,
       0,     0,   578,   579,   580,   581,   582,   583,   584,   585,
     576,   577,     0,     0,     0,     0,     0,   578,   579,   580,
     581,   582,   583,   584,   585,   576,   577,     0,     0,     0,
       0,     0,   578,   579,   580,   581,   582,   583,   584,   585,
       0,     0,   586,   587,   588,   589,   576,   577,  1893,     0,
       0,     0,     0,   578,   579,   580,   581,   582,   583,   584,
     585,     0,   586,   587,   588,   589,   576,   577,  1895,     0,
       0,     0,     0,   578,   579,   580,   581,   582,   583,   584,
     585,   576,   577,     0,     0,     0,     0,     0,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     576,   577,  1896,     0,     0,     0,     0,   578,   579,   580,
     581,   582,   583,   584,   585,     0,     0,   586,   587,   588,
     589,     0,     0,  1898,     0,     0,     0,     0,     0,     0,
       0,     0,   586,   587,   588,   589,     0,     0,  1904,     0,
       0,     0,     0,     0,     0,     0,     0,   586,   587,   588,
     589,     0,     0,  1907,     0,     0,     0,     0,     0,     0,
       0,     0,   586,   587,   588,   589,     0,     0,  1911,     0,
       0,     0,     0,     0,     0,     0,     0,   586,   587,   588,
     589,     0,     0,  1919,     0,     0,     0,     0,     0,     0,
       0,     0,   586,   587,   588,   589,     0,     0,  1920,     0,
       0,     0,     0,     0,     0,     0,     0,   586,   587,   588,
     589,   576,   577,  1921,     0,     0,     0,     0,   578,   579,
     580,   581,   582,   583,   584,   585,     0,     0,   586,   587,
     588,   589,   576,   577,  1927,     0,     0,     0,     0,   578,
     579,   580,   581,   582,   583,   584,   585,     0,   586,   587,
     588,   589,     0,     0,  1943,     0,     0,     0,     0,     0,
       0,     0,     0,   586,   587,   588,   589,   576,   577,  1961,
       0,     0,     0,     0,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   587,   588,   589,   576,   577,  1963,     0,
       0,     0,     0,   578,   579,   580,   581,   582,   583,   584,
     585,   576,   577,     0,     0,     0,     0,     0,   578,   579,
     580,   581,   582,   583,   584,   585,   576,   577,     0,     0,
       0,     0,     0,   578,   579,   580,   581,   582,   583,   584,
     585,   576,   577,     0,     0,     0,     0,     0,   578,   579,
     580,   581,   582,   583,   584,   585,   576,   577,     0,     0,
       0,     0,     0,   578,   579,   580,   581,   582,   583,   584,
     585,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   586,   587,   588,   589,     0,     0,  1965,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   586,   587,   588,   589,     0,     0,
    1966,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   586,
     587,   588,   589,     0,     0,  1986,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   586,   587,
     588,   589,     0,     0,  1988,     0,     0,     0,     0,     0,
       0,     0,     0,   586,   587,   588,   589,     0,     0,  1995,
       0,     0,     0,     0,     0,     0,     0,     0,   586,   587,
     588,   589,     0,     0,  2014,     0,     0,     0,     0,     0,
       0,     0,     0,   586,   587,   588,   589,     0,     0,  2015,
       0,     0,     0,     0,     0,     0,     0,     0,   586,   587,
     588,   589,     0,     0,  2027
};

static const yytype_int16 yycheck[] =
{
       3,    40,   255,    15,    16,     1,    12,   466,     4,    44,
      12,     1,     4,     4,     4,     7,     7,    11,    21,   112,
     273,    24,    75,  1263,  1264,    58,    75,    60,    61,    41,
      33,    77,  1620,    28,    37,    38,     3,    77,    33,    42,
       7,     8,     9,    10,   112,    43,    44,    58,    61,    60,
      61,    54,    55,    56,     3,    12,    25,    53,     7,     8,
       9,    10,   155,    53,    16,   435,   436,    70,    71,    72,
      12,    59,     4,     5,     0,    44,    70,    71,    72,    73,
      74,    75,    76,    86,    87,    88,   246,   155,    13,     4,
       5,   251,    44,   253,    97,    98,    99,   100,   111,    97,
     246,    89,    90,    91,    28,   251,    63,    64,    96,    95,
      20,    21,   112,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,     4,     7,   111,     7,    95,    70,    71,
      72,    73,    74,    75,    76,    77,   112,   113,    63,    64,
     237,   238,   239,   240,   241,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,   155,   110,   112,   113,   160,
      70,    71,    72,    73,    74,    75,    76,    77,   100,    70,
      71,    72,    73,    74,    75,    76,    75,    76,    77,   155,
     252,    70,    71,    72,    73,    74,    75,    76,   558,    23,
     560,    70,    71,    72,    73,    74,    75,    76,   252,   252,
     155,   247,   248,   252,   246,   245,   246,   247,   248,   251,
      75,   246,    70,    71,    72,    73,    74,    75,    76,    92,
      93,   254,   246,   252,   112,   113,   229,   112,   113,   253,
     246,   104,   251,  1821,   253,   251,  1824,   253,   252,   242,
     246,   246,   246,   254,   252,   251,   251,   251,   251,   251,
       4,     5,   246,    75,   186,   187,   188,   296,   297,   255,
     252,   252,    76,    77,   267,   255,    44,   155,   246,   272,
     155,   186,   187,   188,   246,   253,   279,   273,   245,   246,
      14,   253,    16,   273,    18,   246,    81,    82,   245,   246,
     247,   248,   253,    88,   251,   112,   245,   246,    44,  1887,
     303,   246,  1890,   245,   246,   247,   248,    41,   253,   246,
      44,   314,   315,   316,   251,    49,   111,    63,    64,   322,
     245,   246,   247,   248,    70,    71,    72,    73,    74,    75,
      76,    77,    24,   246,   246,   245,   246,   247,   248,   251,
     253,   253,   345,   346,   252,   246,   245,   246,   247,   248,
     251,   354,   253,   356,   252,   358,   359,   246,   361,   362,
     363,   364,   251,   112,   367,   368,   369,   246,   371,   622,
     373,   251,   375,   253,   253,   252,   379,   380,   381,   382,
     383,  1621,   385,   252,  1624,   388,   252,   246,   246,   392,
     393,   394,   395,   396,   253,   398,   399,   400,   401,   252,
     403,   404,   405,   406,   407,   408,   409,   246,   411,   412,
     413,   414,   415,   416,   253,   418,   250,   420,   252,   422,
     252,   424,  2010,   426,  2012,   428,   429,   430,   431,   432,
     246,   245,   246,   247,   248,   438,   246,   253,   112,   113,
    2028,   251,  2030,    74,    75,    76,    77,   450,    70,    71,
      72,    73,    74,    75,    76,   246,   246,   251,   461,   253,
     463,   251,   253,   461,   462,   252,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   252,   246,   491,   252,
     246,   246,   251,  1733,   253,   251,   251,   253,   253,   245,
     246,   247,   248,   246,     4,     5,   504,   252,   251,   246,
     253,   514,   515,   516,   517,   518,   253,   246,   521,    35,
      36,   524,   251,   526,   253,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   252,   538,   539,   540,   541,   542,
     543,   544,   545,     4,     5,   548,   544,   550,   551,   552,
     553,   554,   246,   252,   557,   246,   559,   251,   561,   562,
     563,   251,   253,   253,   567,   568,   569,   570,   571,   572,
     573,   574,   251,   246,   253,     4,     5,    46,   251,    70,
      71,    72,    73,    74,    75,    76,   252,    70,    71,    72,
      73,    74,    75,    76,    63,    64,   252,     4,     5,   250,
     251,    70,    71,    72,    73,    74,    75,    76,    77,   648,
      86,    87,    46,   246,   245,   246,   247,   248,   452,   453,
     253,    14,   625,    16,   246,    18,   622,   246,   246,    63,
      64,   253,   622,   251,   253,   253,    70,    71,    72,    73,
      74,    75,    76,    77,   252,    51,   246,   252,    41,  1889,
     653,    44,  1892,   253,   246,   246,    49,    63,    64,   251,
     251,   253,   253,   666,    70,    71,    72,    73,    74,    75,
      76,    77,    70,    71,    72,    73,    74,    75,    76,   112,
     246,   246,   162,    63,    64,   251,   939,   690,   253,   692,
      70,    71,    72,    73,    74,    75,    76,    77,   701,   246,
     246,     4,     5,   161,   251,  1945,   709,   253,  1948,   712,
     713,   246,   546,   547,    63,    64,   251,   155,   253,     4,
       5,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    49,    50,     4,     5,   252,    70,    71,    72,    73,
      74,    75,    76,    77,   246,   252,   749,   252,   246,   252,
     246,   253,   755,   251,   757,   246,   759,   253,   761,   246,
     763,  1220,   253,   246,  1223,   246,   253,   252,   251,    39,
      40,   155,   253,   246,   777,   778,   245,   246,   247,   248,
     253,   252,  2022,   155,  2024,   252,    70,    71,    72,    73,
      74,    75,    76,   246,  2034,  2035,   246,   246,   252,   246,
     253,   246,   251,   253,   638,   639,   253,   155,   253,   643,
     644,   245,   246,   247,   248,    70,    71,    72,    73,    74,
      75,    76,   825,     4,     5,   334,   335,   830,   337,   832,
     833,    70,    71,    72,    73,    74,    75,    76,   246,   245,
     246,   247,   248,   352,   353,   253,    44,   246,   246,   252,
     246,   360,   246,   251,   253,   246,   365,   253,   155,   253,
     252,   370,   253,   372,   252,   245,   246,   247,   248,   246,
     252,   251,   246,   253,   252,   384,   253,   386,   387,   253,
     389,   390,   391,    73,    74,    75,    76,    77,   397,   246,
     246,    60,    61,   402,   251,   251,   245,   246,   247,   248,
     252,   410,   251,    14,   253,    16,   252,    18,   417,    60,
      61,   245,   246,   247,   248,    63,    64,   251,    44,   253,
     252,   252,    70,    71,    72,    73,    74,    75,    76,    77,
      41,   252,   246,    44,   246,   947,   948,   246,    49,   253,
     246,   253,   252,   939,   253,   251,   246,    63,    64,   939,
     252,   252,   955,   253,    70,    71,    72,    73,    74,    75,
      76,    77,   246,   252,   252,   246,   246,   251,   971,    63,
      64,   974,   253,   253,   977,   252,    70,    71,    72,    73,
      74,    75,    76,    77,   246,   246,   246,   252,   246,   251,
     246,   246,   253,   253,  1247,   253,   251,   253,  1001,    14,
       3,    16,  1005,    18,     7,     8,     9,   246,   252,  1012,
      63,    64,   251,  1016,   252,   252,  1019,    70,    71,    72,
      73,    74,    75,    76,    77,   252,    41,   252,  1031,    44,
    1033,  1034,  1035,   246,    49,  1038,  1039,  1040,   251,  1042,
     246,   246,   252,  1046,   246,   251,   251,  1050,  1051,   251,
    1053,   252,   252,  1056,   246,   245,   246,   247,   248,   251,
    1063,  1064,   246,   252,  1067,   252,   252,   251,  1071,  1072,
    1073,  1074,   246,   252,  1077,   246,   252,   251,  1081,   246,
     251,  1084,   252,   246,   251,  1088,   252,  1090,   251,  1092,
     246,  1094,  1095,  1096,   252,   251,   246,   245,   246,   247,
     248,   251,   246,   251,   246,   253,   246,   251,   246,   251,
     246,   251,   246,   251,  1110,   949,   950,   251,   952,   953,
    1110,   246,   252,  1126,   252,  1128,   251,  1130,   246,   245,
     246,   247,   248,   251,   246,   251,  1139,   253,   252,   251,
     246,    58,   246,  1146,   246,   251,   655,   251,     4,   251,
     246,   245,   246,   247,   248,   251,   246,   246,   246,   253,
     669,   251,   251,   251,   251,   674,   246,   676,   246,   678,
     679,   251,   251,   251,   246,   684,   685,    63,  1181,   251,
       5,   252,   252,   252,    70,    71,    72,    73,    74,    75,
      76,    77,   245,   246,   247,   248,  1199,  1200,  1201,  1202,
     253,   246,   246,    63,    64,  1208,   251,   251,    43,   252,
      70,    71,    72,    73,    74,    75,    76,    77,  1221,    63,
      64,  1224,   252,  1226,   252,   252,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,   252,    43,   252,   252,
     252,    70,    71,    72,    73,    74,    75,    76,    77,   246,
    1253,  1247,   252,  1256,   251,   251,   246,  1247,   246,    63,
      64,   251,   251,   251,  1098,   252,    70,    71,    72,    73,
      74,    75,    76,    77,   783,   784,   252,   252,  1281,  1282,
     246,  1279,  1280,  1286,   252,   251,   251,  1290,    70,    71,
      72,    73,    74,    75,    76,   246,   246,   252,   807,   246,
     251,   251,  1305,  1306,   251,  1308,   246,  1310,   246,   252,
    1313,   251,   246,   251,  1317,  1318,   246,   251,   246,   252,
    1323,   251,  1325,   251,  1327,   246,  1329,   252,   246,   252,
     251,   246,  1335,   251,  1337,  1338,   251,  1340,  1341,  1342,
     252,   246,   246,   246,   252,  1348,   251,   251,   251,  1352,
     246,   252,   246,   246,   252,   251,  1359,   251,   251,   245,
     246,   247,   248,  1366,   246,  1368,   246,  1370,   246,   251,
    1373,   251,  1375,   251,  1377,   246,   246,   246,  1381,   252,
     251,   251,   251,  1386,  1387,   245,   246,   247,   248,   252,
     252,   252,   251,   253,    71,    72,    73,    74,    75,    76,
      77,   245,   246,   247,   248,   246,   246,   252,   251,   253,
     251,   251,  1415,  1416,   252,   246,   245,   246,   247,   248,
     251,   253,   252,   251,   253,    70,    71,    72,    73,    74,
      75,    76,    77,  1445,  1446,   246,   252,   251,  1272,  1273,
     251,   245,   246,   247,   248,   246,   246,   246,  1451,   253,
     251,   251,   251,   246,   246,   251,   246,   246,   251,   251,
    1463,   251,   251,   246,   246,   246,  1719,  1720,   251,   251,
     251,   246,  1475,   251,   246,   246,   251,  1480,  1481,   251,
     251,   251,   251,  1486,  1487,   246,  1489,  1490,    63,    64,
     251,   253,   252,   252,  1497,    70,    71,    72,    73,    74,
      75,    76,    77,  1506,   246,   246,   246,  1510,   252,   251,
     251,   251,   246,  1516,   253,  1518,    77,   251,   246,    63,
      64,  1524,   253,   251,  1527,  1528,    70,    71,    72,    73,
      74,    75,    76,    77,   246,  1538,  1539,    75,  1541,   251,
    1543,   246,  1545,  1546,   246,   246,   251,   246,   246,   251,
     251,   246,   251,   251,   246,   252,   251,   246,   246,   251,
    1813,  1564,   251,   251,   251,    63,    64,  1570,   245,   246,
     247,   248,    70,    71,    72,    73,    74,    75,    76,    77,
    1583,   246,   246,   246,  1587,   246,   251,   251,   251,   251,
     251,  1594,   252,   246,  1597,   252,   252,  1600,   251,   246,
     245,   246,   247,   248,   251,   246,   246,    63,    64,   251,
     251,   251,  1615,    46,    70,    71,    72,    73,    74,    75,
      76,    77,   252,  1876,   252,   246,  1879,  1630,  1631,  1632,
     251,   246,   246,   246,  1468,  1469,   251,   251,   251,   246,
      58,   246,  1645,   252,   251,  1648,   251,    10,  1651,   251,
     246,   246,  1655,   246,  1657,   251,   251,   251,   251,   246,
    1663,   251,  1665,   246,   251,  1668,  1669,   251,   251,  1672,
     245,   246,   247,   248,   251,   251,   251,   251,  1681,     2,
    1933,   246,  1685,   246,   246,  1688,   251,  1690,   251,   251,
    1693,  1694,   246,  1696,    17,   246,   252,   251,   251,   251,
     251,   245,   246,   247,   248,   253,   246,    30,   253,   253,
      33,   251,   246,    36,    37,    38,   253,   251,   251,    42,
      43,    44,   246,  1719,  1720,   253,   246,   251,    51,  1719,
    1720,   251,   246,   246,   252,  1738,   246,   251,   251,  1742,
     246,   251,  1745,   252,   251,   251,  1749,   245,   246,   247,
     248,    63,    64,   253,   253,   253,   251,   253,    70,    71,
      72,    73,    74,    75,    76,    77,   246,   246,    91,   253,
     246,   251,   251,   246,    97,   251,   246,  1780,   251,  1782,
    1783,   251,  1785,    43,  1787,  1294,   253,   253,  1297,   245,
     246,   247,   248,  1302,   246,   252,    85,   253,    71,   251,
      73,    74,    75,    76,    77,   246,   246,   253,   246,   132,
     251,   251,  1815,   251,   253,   246,   246,  1813,    63,    64,
     251,   251,    85,  1813,   252,    70,    71,    72,    73,    74,
      75,    76,    77,  1836,  1837,  1838,  1839,   246,  1841,  1842,
     246,   246,   251,  1846,   246,   251,   251,  1850,   246,   251,
    1853,  1854,  1855,   251,  1857,   246,   252,   251,  1861,  1862,
     251,   253,   251,   253,  1867,    63,    64,  1870,   251,  1872,
     251,   251,    70,    71,    72,    73,    74,    75,    76,    77,
    1876,  1390,   251,  1879,   251,  1888,  1876,   251,   253,  1879,
     251,  1894,  1895,   251,  1897,  1898,  1899,   251,  1407,   251,
      63,    64,   251,   251,   251,   228,   229,    70,    71,    72,
      73,    74,    75,    76,    77,   251,   251,  1920,     5,   253,
     251,  1924,   251,  1926,  1927,   253,   249,   253,   253,   253,
      58,   254,   252,   245,   246,   247,   248,  1933,  1941,   252,
     251,   253,   251,  1933,   267,   251,   251,   251,    43,   272,
     253,   252,    38,   253,   253,  1958,   279,   252,    43,  1962,
      58,   253,  1965,  1966,    75,   253,    75,  1970,    75,    48,
      58,  1974,   245,   246,   247,   248,   252,   251,   253,   302,
    1983,   304,   253,   252,   252,  1988,    47,   252,   252,    58,
      38,    75,   253,   252,  1997,   253,   252,   251,   251,     4,
     245,   246,   247,   248,     4,  1110,    53,    53,   253,    63,
      64,  2014,  2015,   466,   648,     5,    70,    71,    72,    73,
      74,    75,    76,    77,  2027,    63,    64,   954,   351,  2032,
    1795,   955,    70,    71,    72,    73,    74,    75,    76,    77,
     951,  1451,  2006,  1259,   645,   661,    -1,   245,   246,   247,
     248,    63,    64,    -1,    -1,   253,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,   247,   248,    63,    64,    -1,    -1,
     253,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,   437,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,   449,    -1,    -1,  1638,
      -1,   454,   455,  1642,   457,   458,   459,   460,   461,   462,
      63,    64,    -1,    -1,    -1,   468,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   245,   246,   247,   248,    -1,   519,   520,   521,   522,
     523,    -1,   525,    -1,   527,    -1,    -1,   245,   246,   247,
     248,    -1,    -1,    -1,   537,   253,    -1,    -1,    -1,    -1,
      -1,   544,    -1,    -1,    -1,    -1,   549,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   246,   247,   248,    63,    64,    -1,
      -1,   253,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,    -1,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,   253,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    -1,
     623,    -1,    -1,    -1,    -1,   628,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,   641,   642,
      -1,    -1,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
     253,   654,    -1,    30,    31,    -1,   659,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,   253,    -1,   670,   671,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,   711,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,   110,    -1,    -1,    -1,    -1,   115,   245,
     246,   247,   248,    -1,    -1,   122,    -1,   253,    -1,   126,
     127,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   769,   144,   145,   146,
     147,   148,   149,    -1,   777,   778,   779,   780,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,   218,   219,   220,   221,    -1,   223,   224,    -1,   226,
     227,   228,    -1,   230,   231,   232,   233,   234,   235,   236,
      -1,    -1,    -1,    -1,    -1,   242,   243,    -1,   245,    90,
      91,    92,    93,    94,    -1,   252,    -1,   254,    -1,    -1,
      -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,   110,
     111,    -1,    -1,    -1,    -1,   116,   117,   118,   119,   120,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   922,
     923,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,   942,
      -1,   253,    -1,   164,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,   955,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,   968,    -1,    -1,    -1,    -1,
      -1,   974,   975,    -1,    -1,    63,    64,   980,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   994,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,  1014,    -1,    -1,    -1,    -1,  1019,  1020,  1021,    -1,
      -1,  1024,    -1,    -1,  1027,    -1,  1029,    -1,  1031,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1040,    -1,    -1,
      -1,  1044,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1052,
      -1,  1054,    -1,    -1,    -1,    -1,  1059,    -1,    -1,    -1,
    1063,  1064,  1065,    -1,    -1,  1068,  1069,    -1,    -1,  1072,
      -1,    -1,  1075,    -1,    -1,  1078,    -1,  1080,    -1,  1082,
      -1,    -1,    -1,  1086,    -1,  1088,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,   253,    -1,  1099,  1100,  1101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1119,  1120,    -1,  1122,
    1123,  1124,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,
     247,   248,  1135,  1136,    -1,  1138,   253,    -1,  1141,  1142,
    1143,    -1,  1145,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1156,    -1,    -1,  1159,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,   253,    -1,    -1,  1171,    -1,
      -1,  1174,  1175,  1176,    -1,  1178,  1179,   245,   246,   247,
     248,    63,    64,    -1,  1187,   253,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,  1215,    -1,  1217,  1218,  1219,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,  1231,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,  1251,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,  1261,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1274,  1275,    -1,    -1,    -1,  1279,  1280,    -1,    -1,
      63,    64,    -1,    -1,    -1,  1288,  1289,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    47,    48,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    58,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1362,
      -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,   253,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,  1451,    -1,
      -1,    -1,    -1,  1456,    -1,    -1,    -1,    -1,  1461,    -1,
      -1,    -1,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,  1492,
    1493,  1494,    -1,  1496,    -1,    -1,    -1,    -1,    -1,    -1,
    1503,    -1,    -1,    -1,  1507,  1508,    -1,    63,    64,    -1,
    1513,    -1,  1515,  1516,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,  1527,    -1,    -1,  1530,  1531,    -1,
    1533,    -1,    -1,  1536,    -1,    -1,    -1,    -1,  1541,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,  1551,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1569,    -1,  1571,   313,
     245,   246,   247,   248,    -1,   319,  1579,    -1,   253,    -1,
      -1,    -1,   326,   327,    -1,  1588,    -1,  1590,    -1,    -1,
      -1,    -1,  1595,    -1,   338,   339,   340,   341,   342,   343,
     344,  1604,    -1,   347,   348,   349,   350,    -1,    -1,    -1,
      -1,  1614,    -1,    -1,  1617,   245,   246,   247,   248,    63,
      64,    -1,    -1,   253,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1646,  1647,    -1,    -1,  1650,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1658,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1666,  1667,    -1,    -1,    -1,  1671,    -1,
      -1,    63,    64,  1676,    -1,    -1,    -1,  1680,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,   245,
     246,   247,   248,    -1,  1697,    -1,    -1,   253,    -1,    63,
      64,    -1,   446,   447,   448,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,  1721,    -1,
      -1,    -1,    -1,   467,   245,   246,   247,   248,    -1,  1732,
      -1,    -1,   253,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1744,    -1,  1746,    -1,  1748,    -1,    -1,    -1,    -1,
      -1,  1754,    -1,    -1,  1757,    -1,  1759,    -1,    -1,  1762,
    1763,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1772,
      -1,  1774,  1775,  1776,    -1,    -1,  1779,    -1,    -1,    -1,
      -1,    -1,  1785,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1798,    -1,    -1,    -1,    -1,
      -1,   245,   246,   247,   248,  1808,    -1,    -1,    -1,   253,
      -1,    -1,    -1,  1816,  1817,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1844,    -1,    -1,  1847,    -1,    -1,    -1,  1851,  1852,
      -1,    -1,    -1,   245,   246,   247,   248,    63,    64,    -1,
      -1,   253,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,   246,   247,   248,    -1,    -1,    -1,  1891,   253,
    1893,    -1,    -1,  1896,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1904,    -1,    -1,  1907,    -1,    -1,    -1,  1911,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1919,    -1,  1921,    -1,
     664,    -1,    -1,    -1,   668,    -1,    -1,    -1,   672,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1943,    -1,    -1,   687,   688,    -1,    -1,    -1,    -1,    -1,
      -1,   695,    -1,    -1,    -1,    -1,   700,    -1,  1961,    -1,
    1963,   705,    -1,   707,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,   719,    -1,   721,   722,    -1,
     724,   725,   726,  1986,    -1,    -1,    -1,    -1,   732,    -1,
      -1,    -1,  1995,   737,    30,    31,    -1,   245,   246,   247,
     248,   745,    -1,    -1,    -1,   253,    -1,    -1,    -1,   753,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,   245,
     246,   247,   248,    -1,    -1,    81,    -1,   253,    84,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,   218,   219,   220,   221,    -1,   223,   224,    -1,
     226,   227,   228,    -1,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,    -1,   242,   243,    -1,   245,
      -1,    -1,    -1,    -1,    -1,    -1,   252,    -1,   254,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1000,    -1,    -1,    30,
      31,    -1,    -1,    -1,  1008,    -1,    -1,    -1,    -1,  1013,
      -1,  1015,    -1,  1017,  1018,    -1,    -1,    -1,  1022,  1023,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    63,    64,    -1,   126,   127,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,  1112,  1113,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,  1137,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,    -1,   218,   219,   220,
     221,    -1,   223,   224,    -1,   226,   227,   228,    -1,   230,
     231,   232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,
      -1,   242,   243,    -1,   245,    -1,    -1,    -1,    -1,    -1,
      -1,   252,    -1,   254,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,
      -1,    -1,   253,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    63,    64,    -1,   126,   127,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,    -1,   218,
     219,   220,   221,    -1,   223,   224,    -1,   226,   227,   228,
      -1,   230,   231,   232,   233,   234,   235,   236,    -1,    -1,
      -1,    -1,    -1,   242,   243,    -1,   245,    -1,    -1,    -1,
      -1,    -1,    -1,   252,    -1,   254,     3,     4,     5,    -1,
       7,     8,     9,    10,  1488,    -1,    -1,  1491,    -1,    -1,
      -1,  1495,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
      -1,    -1,    -1,    -1,   253,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1555,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    63,    64,    -1,   126,
     127,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
      -1,   218,   219,   220,   221,    -1,   223,   224,    -1,   226,
     227,   228,    -1,   230,   231,   232,   233,   234,   235,   236,
      -1,    -1,    -1,    -1,    -1,   242,   243,    -1,   245,    -1,
      -1,    -1,    -1,    -1,    -1,   252,   253,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,  1743,
      -1,    -1,    -1,  1747,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,
     247,   248,    -1,    -1,    -1,    -1,   253,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,
      64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    63,    64,    -1,
     126,   127,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,   218,   219,   220,   221,    -1,   223,   224,    -1,
     226,   227,   228,    -1,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,    -1,   242,   243,    -1,   245,
      -1,    -1,    -1,    -1,    -1,    -1,   252,   253,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,   245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,   253,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,
      63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    63,    64,
      -1,   126,   127,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,    -1,   218,   219,   220,   221,    -1,   223,   224,
      -1,   226,   227,   228,    -1,   230,   231,   232,   233,   234,
     235,   236,    -1,    -1,    -1,    -1,    -1,   242,   243,    -1,
     245,    -1,    -1,    -1,    -1,    -1,    -1,   252,   253,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,   245,   246,   247,   248,    -1,    -1,    -1,    -1,
     253,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,   151,   152,   153,
     154,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,   218,   219,   220,   221,    -1,   223,
     224,    -1,   226,   227,   228,    -1,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,    -1,   242,   243,
      -1,   245,    -1,    -1,    -1,     3,     4,     5,   252,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,   147,
     148,   149,   150,    -1,    -1,    -1,   154,    -1,   156,    -1,
      -1,   159,    -1,    -1,   162,   163,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
     218,   219,   220,   221,    -1,   223,   224,    -1,   226,   227,
     228,    -1,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,    -1,   242,   243,    -1,   245,    -1,    -1,
      -1,     3,     4,     5,   252,     7,     8,     9,    10,    -1,
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
     142,   143,   144,   145,   146,   147,   148,   149,    -1,   151,
      -1,    -1,   154,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,   218,   219,   220,   221,
      -1,   223,   224,    -1,   226,   227,   228,    -1,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,    -1,
     242,   243,    -1,   245,    -1,    -1,    -1,     3,     4,     5,
     252,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,   218,   219,   220,   221,    -1,   223,   224,    -1,
     226,   227,   228,    -1,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,    -1,   242,   243,    -1,   245,
      -1,    -1,    -1,     3,     4,     5,   252,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,   218,   219,
     220,   221,    -1,   223,   224,    -1,   226,   227,   228,    -1,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,    -1,   242,   243,    -1,   245,    -1,    -1,    -1,     3,
       4,     5,   252,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,
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
      -1,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,   218,   219,   220,   221,    -1,   223,
     224,    -1,   226,   227,   228,    -1,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,    -1,   242,   243,
      -1,   245,    -1,    -1,    -1,     3,     4,     5,   252,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,   253,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   159,    -1,    -1,   162,   163,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
     218,   219,   220,   221,    -1,   223,   224,    -1,   226,   227,
     228,    -1,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,    -1,   242,   243,    -1,   245,    -1,    -1,
      -1,     3,     4,     5,   252,     7,     8,     9,    10,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,   253,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,   218,   219,   220,   221,
      -1,   223,   224,    -1,   226,   227,   228,    -1,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,    -1,
     242,   243,    -1,   245,    -1,    -1,    -1,     3,     4,     5,
     252,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,   111,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,   218,   219,   220,   221,    -1,   223,   224,    -1,
     226,   227,   228,    -1,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,    -1,   242,   243,    -1,   245,
      -1,    -1,    -1,     3,     4,     5,   252,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   143,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,   218,   219,
     220,   221,    -1,   223,   224,    -1,   226,   227,   228,    -1,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,    -1,   242,   243,    -1,   245,    -1,    -1,    -1,     3,
       4,     5,   252,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,   253,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,   112,   113,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,   218,   219,   220,   221,    -1,   223,
     224,    -1,   226,   227,   228,    -1,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,    -1,   242,   243,
      -1,   245,    -1,    -1,    -1,     3,     4,     5,   252,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,   253,    30,    31,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,
      -1,    89,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,   159,    -1,    -1,   162,   163,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
     218,   219,   220,   221,    -1,   223,   224,    -1,   226,   227,
     228,    -1,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,    -1,   242,   243,    -1,   245,    -1,    -1,
      -1,     3,     4,     5,   252,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,   253,    30,    31,
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
     162,   163,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,   218,   219,   220,   221,
      -1,   223,   224,    -1,   226,   227,   228,    -1,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,    -1,
     242,   243,    -1,   245,    -1,    -1,    -1,     3,     4,     5,
     252,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    30,    31,    -1,    -1,    -1,    -1,
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
     156,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,   218,   219,   220,   221,    -1,   223,   224,    -1,
     226,   227,   228,    -1,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,    -1,   242,   243,    -1,   245,
      -1,    -1,    -1,     3,     4,     5,   252,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,   246,   247,   248,    -1,    -1,    -1,    -1,   253,
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
      -1,    -1,   162,   163,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,   218,   219,
     220,   221,    -1,   223,   224,    -1,   226,   227,   228,    -1,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,    -1,   242,   243,    -1,   245,    -1,    -1,    -1,     3,
       4,     5,   252,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,
     248,    -1,    -1,    -1,    -1,   253,    30,    31,    -1,    -1,
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
      -1,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,   218,   219,   220,   221,    -1,   223,
     224,    -1,   226,   227,   228,    -1,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,    -1,   242,   243,
      -1,   245,    -1,    -1,    -1,     3,     4,     5,   252,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,    -1,
      -1,   253,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   159,    -1,    -1,   162,   163,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
     218,   219,   220,   221,    -1,   223,   224,    -1,   226,   227,
     228,    -1,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,    -1,   242,   243,    -1,   245,    -1,    -1,
      -1,     3,     4,     5,   252,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,   247,   248,    -1,    -1,    -1,    -1,   253,    30,    31,
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
     162,   163,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,   218,   219,   220,   221,
      -1,   223,   224,    -1,   226,   227,   228,    -1,   230,   231,
     232,   233,   234,   235,   236,    -1,    -1,    -1,    -1,    -1,
     242,   243,    -1,   245,    -1,    -1,    -1,     3,     4,     5,
     252,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,    -1,
      -1,    -1,    -1,   253,    30,    31,    -1,    -1,    -1,    -1,
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
     156,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,    -1,   218,   219,   220,   221,    -1,   223,   224,    -1,
     226,   227,   228,    -1,   230,   231,   232,   233,   234,   235,
     236,    -1,    -1,    -1,    -1,    -1,   242,   243,    -1,   245,
      -1,    -1,    -1,     3,     4,     5,   252,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,   246,   247,   248,    -1,    -1,   251,    -1,    -1,
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
      -1,    -1,   162,   163,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,    -1,   218,   219,
     220,   221,    -1,   223,   224,    -1,   226,   227,   228,    -1,
     230,   231,   232,   233,   234,   235,   236,    -1,    -1,    -1,
      -1,    -1,   242,   243,    -1,   245,    -1,    -1,    -1,     3,
       4,     5,   252,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,
     248,    -1,    -1,   251,    -1,    -1,    30,    31,    -1,    -1,
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
      -1,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,    -1,   218,   219,   220,   221,    -1,   223,
     224,    -1,   226,   227,   228,    -1,   230,   231,   232,   233,
     234,   235,   236,    -1,    -1,    -1,    -1,    -1,   242,   243,
      -1,   245,    -1,    -1,    -1,     3,     4,     5,   252,     7,
       8,     9,    10,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,   251,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,
      -1,    89,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,   159,    -1,    -1,   162,   163,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,    -1,
     218,   219,   220,   221,    -1,   223,   224,    -1,   226,   227,
     228,    -1,   230,   231,   232,   233,   234,   235,   236,    -1,
      -1,    -1,    -1,    -1,   242,   243,    -1,   245,    -1,    -1,
      -1,     3,     4,     5,   252,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,   247,   248,    -1,    -1,   251,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    63,    64,    -1,   126,   127,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,     5,    -1,    -1,    -1,
      -1,    10,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,    31,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,    -1,   218,   219,   220,   221,
      -1,   223,   224,    -1,   226,   227,   228,    -1,   230,   231,
     232,   233,   234,   235,   236,    -1,   105,    -1,   107,    -1,
     242,   243,    -1,   245,    -1,    -1,     5,    -1,    -1,    -1,
     252,    10,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,    -1,
      -1,   251,    31,    -1,    -1,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,
      -1,    -1,    -1,   192,   193,   194,    -1,   196,    -1,   198,
     199,   200,    -1,    -1,    -1,    -1,   205,   206,   207,   208,
     209,    -1,    -1,   212,    -1,   214,   105,   216,   107,    -1,
     219,    -1,   221,    -1,    -1,   224,    -1,    -1,   227,   228,
      -1,   230,   231,    -1,   233,    -1,   235,   126,   127,    -1,
      -1,    -1,    -1,    -1,   243,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,   252,   253,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    31,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,
      -1,    -1,    -1,   192,   193,   194,    -1,   196,    -1,   198,
     199,   200,    -1,    -1,    -1,    -1,   205,   206,   207,   208,
     209,    -1,    -1,   212,    -1,   214,    -1,   216,    -1,    -1,
     219,    -1,   221,    -1,    -1,   224,    -1,    -1,   227,   228,
      -1,   230,   231,    -1,   233,   105,   235,   107,    -1,    -1,
      -1,    -1,    -1,    -1,   243,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,   252,   253,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,    -1,
      -1,    -1,   192,   193,   194,    -1,   196,    -1,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
      -1,    -1,   212,    -1,   214,   105,   216,   107,    -1,   219,
      -1,   221,    -1,    -1,   224,    -1,    -1,   227,   228,    -1,
     230,   231,    -1,   233,    -1,   235,   126,   127,    -1,    -1,
      -1,    -1,    -1,   243,     5,    -1,    -1,    -1,    -1,    10,
      -1,    -1,   252,   253,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      31,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,    -1,
      -1,    -1,   192,   193,   194,    -1,   196,    -1,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
      -1,    -1,   212,    -1,   214,    -1,   216,    -1,    -1,   219,
      -1,   221,    -1,    -1,   224,    -1,    -1,   227,   228,    -1,
     230,   231,    -1,   233,   105,   235,   107,    -1,    -1,    -1,
     111,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   252,   253,    -1,   126,   127,    -1,    -1,    -1,
      -1,     5,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    31,   159,    -1,
      -1,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   187,   188,    -1,    -1,
      -1,   192,   193,   194,    -1,   196,    -1,   198,   199,   200,
      -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,    -1,
      -1,   212,    -1,   214,    -1,   216,    -1,    -1,   219,    -1,
     221,    -1,    -1,   224,    -1,    -1,   227,   228,    -1,   230,
     231,   105,   233,   107,   235,    -1,    -1,   111,    -1,    -1,
      -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,     5,
      -1,   252,   126,   127,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,    31,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,    -1,    -1,    -1,   192,   193,
     194,    -1,   196,    -1,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,   206,   207,   208,   209,    -1,    -1,   212,    -1,
     214,    -1,   216,    -1,    -1,   219,    -1,   221,    -1,   105,
     224,   107,    -1,   227,   228,   111,   230,   231,    -1,   233,
      -1,   235,    -1,    -1,    -1,    -1,    -1,     5,    -1,   243,
     126,   127,    10,    -1,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,    31,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,    -1,    -1,    -1,   192,   193,   194,    -1,
     196,    -1,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
     206,   207,   208,   209,    -1,    -1,   212,    -1,   214,    -1,
     216,    -1,    -1,   219,    -1,   221,    -1,   105,   224,   107,
      -1,   227,   228,   111,   230,   231,    -1,   233,    -1,   235,
      -1,    -1,    -1,    -1,    -1,     5,    -1,   243,   126,   127,
      10,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,    31,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,   159,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,    -1,    -1,    -1,   192,   193,   194,    -1,   196,    -1,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,   206,   207,
     208,   209,    -1,    -1,   212,    -1,   214,    -1,   216,    -1,
      -1,   219,    -1,   221,    -1,   105,   224,   107,    -1,   227,
     228,    -1,   230,   231,    -1,   233,    -1,   235,    -1,    -1,
      -1,    -1,    -1,     5,    -1,   243,   126,   127,    10,    -1,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,    31,
     150,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,    -1,
      -1,    -1,   192,   193,   194,    -1,   196,    -1,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
      -1,    -1,   212,    -1,   214,    -1,   216,    -1,    -1,   219,
      -1,   221,    -1,   105,   224,   107,    -1,   227,   228,    -1,
     230,   231,    -1,   233,    -1,   235,    -1,    -1,    -1,    -1,
      -1,     5,    -1,   243,   126,   127,    10,    -1,    -1,    -1,
      -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,    31,   150,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,   163,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   186,   187,   188,    -1,    -1,    -1,
     192,   193,   194,    -1,   196,    -1,   198,   199,   200,    -1,
      -1,    -1,    -1,   205,   206,   207,   208,   209,    -1,    -1,
     212,    -1,   214,    97,   216,    -1,    -1,   219,    -1,   221,
      -1,   105,   224,   107,    -1,   227,   228,    -1,   230,   231,
      -1,   233,    -1,   235,    -1,    -1,    -1,    -1,    -1,     5,
      -1,   243,   126,   127,    10,    -1,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,    31,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   186,   187,   188,    -1,    -1,    -1,   192,   193,
     194,    -1,   196,    -1,   198,   199,   200,    -1,    -1,    -1,
      -1,   205,   206,   207,   208,   209,    -1,    -1,   212,    -1,
     214,    97,   216,    -1,    -1,   219,    -1,   221,    -1,   105,
     224,   107,    -1,   227,   228,    -1,   230,   231,    -1,   233,
      -1,   235,    -1,    -1,    -1,    -1,    -1,     5,    -1,   243,
     126,   127,    10,    -1,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,    31,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,    -1,    -1,    -1,   192,   193,   194,    -1,
     196,    -1,   198,   199,   200,    -1,    -1,    -1,    -1,   205,
     206,   207,   208,   209,    -1,    -1,   212,    -1,   214,    -1,
     216,    -1,    -1,   219,    -1,   221,    -1,   105,   224,   107,
      -1,   227,   228,    -1,   230,   231,    -1,   233,    -1,   235,
      -1,    -1,    -1,    -1,    -1,     5,    -1,   243,   126,   127,
      10,    -1,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,    31,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,   159,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,    -1,    -1,    -1,   192,   193,   194,    -1,   196,    -1,
     198,   199,   200,    -1,    -1,    -1,    -1,   205,   206,   207,
     208,   209,    -1,    -1,   212,    -1,   214,    -1,   216,    -1,
      -1,   219,    -1,   221,    -1,   105,   224,   107,    -1,   227,
     228,    -1,   230,   231,    -1,   233,    -1,   235,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,   186,   187,   188,    -1,
      -1,    -1,   192,   193,   194,    -1,   196,    -1,   198,   199,
     200,    -1,    -1,    -1,    -1,   205,   206,   207,   208,   209,
      -1,    -1,   212,    -1,   214,    -1,   216,    -1,    -1,   219,
      -1,   221,    -1,    -1,   224,    -1,    -1,   227,   228,    -1,
     230,   231,    -1,   233,    -1,   235,    -1,    -1,     4,     5,
       6,    -1,    -1,   243,    -1,    11,    -1,    -1,    -1,    15,
      -1,    17,   252,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,
     106,    -1,   108,   109,    -1,    -1,    -1,    -1,   114,   115,
     245,   246,   247,   248,    -1,   121,   251,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,   157,   158,   159,    -1,    -1,    -1,   163,   164,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     186,   187,   188,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   213,    -1,    -1,
      -1,   217,    -1,     4,     5,     6,   222,    -1,    -1,   225,
      11,    -1,    -1,   229,    15,    -1,    17,    -1,    19,    20,
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
      -1,    -1,   163,   164,   245,   246,   247,   248,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,   187,   188,    -1,    -1,
      -1,    -1,   193,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   213,    -1,    -1,    -1,   217,    -1,     4,     5,
       6,   222,    -1,    -1,   225,    11,    -1,    -1,   229,    15,
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
     156,   157,   158,   159,    -1,    -1,    -1,   163,   164,   245,
     246,   247,   248,    63,    64,   251,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     186,   187,   188,    63,    64,    -1,    -1,   193,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   213,    -1,    -1,
      -1,   217,    -1,    -1,    -1,    -1,   222,    63,    64,   225,
      -1,    -1,    -1,   229,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   245,   246,   247,   248,    63,    64,
     251,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   245,   246,   247,   248,    63,
      64,   251,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   245,   246,   247,   248,    63,
      64,   251,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   245,
     246,   247,   248,    63,    64,   251,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     245,   246,   247,   248,    -1,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,   246,   247,   248,    -1,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,   246,   247,   248,    -1,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,   246,   247,   248,    63,    64,   251,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,   245,   246,   247,   248,    63,    64,   251,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   245,   246,   247,   248,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
      63,    64,   251,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,   245,   246,   247,   248,    63,
      64,   251,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   245,   246,   247,   248,
      63,    64,   251,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   245,   246,   247,
     248,    63,    64,   251,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   245,   246,   247,   248,    63,    64,   251,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,   245,   246,   247,   248,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
      -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,   246,   247,   248,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
      -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,   246,   247,   248,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
      -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,   246,   247,   248,    63,    64,   251,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,   245,   246,   247,   248,    63,    64,   251,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   245,   246,   247,   248,    -1,    -1,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,
     247,   248,    63,    64,   251,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   245,   246,
     247,   248,    63,    64,   251,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   245,   246,   247,
     248,    63,    64,   251,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   245,   246,
     247,   248,    63,    64,   251,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   245,   246,   247,   248,    63,    64,
     251,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   245,   246,   247,   248,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,   247,   248,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,   247,   248,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,   247,   248,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   245,   246,   247,   248,    63,    64,
     251,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,   245,   246,   247,   248,    63,    64,   251,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   245,   246,   247,   248,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,   247,   248,    63,    64,   251,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     245,   246,   247,   248,    63,    64,   251,    -1,    -1,    -1,
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
     245,   246,   247,   248,    63,    64,   251,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   245,
     246,   247,   248,    63,    64,   251,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   245,   246,   247,   248,    63,
      64,   251,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   245,   246,   247,   248,
      -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,   246,   247,   248,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
      -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,   246,   247,   248,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
      -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   245,   246,   247,   248,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,   248,
      63,    64,   251,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   245,   246,   247,   248,
      63,    64,   251,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,   245,   246,   247,   248,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     245,   246,   247,   248,    63,    64,   251,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,   245,   246,   247,   248,    63,    64,   251,    -1,    -1,
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
      -1,    -1,   245,   246,   247,   248,    63,    64,   251,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   245,   246,   247,   248,    63,    64,   251,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   245,   246,   247,   248,
      63,    64,   251,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   245,   246,   247,
     248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,   247,   248,    -1,    -1,   251,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,
     248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,   247,   248,    -1,    -1,   251,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,
     248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   245,   246,   247,   248,    -1,    -1,   251,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,   247,
     248,    63,    64,   251,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   245,   246,
     247,   248,    63,    64,   251,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   245,   246,
     247,   248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   246,   247,   248,    63,    64,   251,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   245,   246,   247,   248,    63,    64,   251,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,
     251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,
     246,   247,   248,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,
     247,   248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,
     247,   248,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   246,   247,   248,    -1,    -1,   251,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   245,   246,
     247,   248,    -1,    -1,   251
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   237,   238,   239,   240,   241,   256,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   114,   115,
     121,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     144,   145,   146,   147,   148,   149,   156,   157,   158,   159,
     163,   164,   186,   187,   188,   193,   213,   217,   222,   225,
     229,   257,   258,   261,   262,   269,   270,   272,   273,   277,
     289,   290,   295,   301,   308,   316,   324,   327,   331,   334,
     340,     3,     4,     5,     7,     8,     9,    10,    30,    31,
      63,    64,    65,    66,    67,    68,    69,    81,    84,    89,
     101,   102,   105,   107,   115,   122,   126,   127,   144,   145,
     146,   147,   148,   149,   156,   159,   162,   163,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     218,   219,   220,   221,   223,   224,   226,   227,   228,   230,
     231,   232,   233,   234,   235,   236,   242,   243,   245,   252,
     275,   276,   278,   284,   286,   289,   290,   144,   145,   146,
     147,   163,   252,   275,   261,   289,   290,   295,     0,    75,
     252,    75,   252,   309,   328,   332,     4,     7,   287,   287,
     287,    34,   278,   263,   264,   275,   291,   292,   291,   275,
      28,     7,   317,   325,   278,    58,    60,    61,   254,   371,
     267,   275,   278,     4,     5,   288,   278,   275,   278,   275,
     278,     4,     5,   351,   352,    10,   245,   246,   285,   286,
     353,   287,    89,    97,   254,   275,   278,   372,    89,    97,
     110,   372,   372,    81,    82,    88,   111,   278,   283,    12,
      53,   283,   111,   283,    59,    89,    90,    91,    96,    95,
     278,   270,   277,   275,   275,   275,   110,   283,    90,    91,
      92,    93,    94,   104,   110,   111,   116,   117,   118,   119,
     120,   164,   283,   283,   111,   283,   111,   283,    95,   111,
     283,    61,    95,   111,   142,   283,   283,    22,    61,   111,
     283,   111,   283,   111,   283,   111,   275,   275,   275,    61,
     111,   111,   142,   143,   283,   111,   283,   283,   111,   283,
     283,   283,    95,   142,   143,   151,   154,   283,    95,   142,
     143,   154,   283,    95,   142,   143,   151,   152,   153,   154,
     283,    61,    95,   142,   143,   150,   154,   283,   111,   283,
     111,   283,   111,   275,   111,   275,   111,   275,   160,    95,
     111,   112,   143,   278,   252,   252,   252,   252,   252,   275,
     372,   275,   275,   275,    44,   259,    92,    93,   104,    75,
      75,    24,   252,   252,   252,   252,   278,   252,   252,   252,
     252,   252,   252,   112,   113,   252,   252,   252,   252,   112,
     252,   112,   155,   112,   155,   112,   113,   155,   112,   113,
     155,   112,   113,   155,   112,   113,   155,   112,   112,   162,
     161,   252,   112,   155,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   278,   275,   278,    70,    71,    72,
      73,    74,    75,    76,   246,    44,    63,    64,    70,    71,
      72,    73,    74,    75,    76,    77,   245,   246,   247,   248,
     275,    44,    44,    44,   278,   291,   275,   291,     4,   278,
     258,    35,    36,    20,    21,     4,     5,   302,   303,     4,
       5,   304,   305,   275,   278,   293,   294,   275,   278,   319,
     258,   335,   341,   252,    58,   252,     4,     7,   252,   275,
     278,   354,    58,    60,    61,   254,   356,   369,   252,   252,
     251,   251,   251,   252,   252,   251,   286,   286,   251,   278,
     275,   278,    11,   251,   251,   283,   275,   275,   275,   251,
     283,   268,    12,   251,   271,   275,   251,   283,    12,   283,
     271,   271,   271,   283,   283,   283,   283,   283,   283,   283,
     275,   275,   283,   283,   283,   283,   278,   271,   271,   275,
     251,   275,   251,   275,   275,   271,   275,   275,   275,   275,
     271,   251,   275,   275,   275,   271,   275,   271,   275,   251,
     275,   251,   251,   251,   275,   275,   275,   275,   275,   271,
     275,   271,   271,   275,   271,   271,   271,   275,   275,   275,
     275,   275,   271,   275,   275,   275,   275,   271,   275,   275,
     275,   275,   275,   275,   275,   271,   275,   275,   275,   150,
     275,   275,   275,   271,   275,   251,   275,   251,   275,   251,
     275,   251,   275,   251,   275,   275,   275,   275,   275,   251,
       5,   274,   274,   274,   253,   278,   275,   251,   251,   251,
     251,    43,   283,   283,   283,   278,   275,   296,   291,   291,
     278,   278,   278,   278,   278,   278,    97,   275,   372,   372,
     275,     4,     5,   281,   282,   281,   282,   283,   278,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   150,   275,   275,   275,   275,
     252,   275,   252,   252,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   372,   278,   278,   278,   278,   278,
     278,   278,   278,   253,   278,   275,   275,   275,   275,   275,
     278,   278,   275,   278,   253,   278,   278,   275,   278,   275,
     278,   275,   275,   253,   275,   253,   275,   253,   275,   253,
     275,   275,   275,   275,   278,   275,   275,   275,   275,   275,
     275,   275,   372,   275,   291,   291,   275,   278,   275,   275,
     275,   275,   275,   253,   253,   275,   274,   275,   274,   275,
     275,   275,   253,   253,   275,   275,   275,   275,   275,   275,
     275,   275,   280,   279,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   253,   253,    75,   329,
      14,    16,    18,    41,    44,    49,   333,   265,   266,   252,
     252,   251,   252,   252,   251,   251,    43,   318,    14,    16,
      18,    41,    44,    49,   326,    46,   258,   278,   252,   275,
     278,    51,   355,   250,   251,   252,    58,   252,     4,     7,
     252,    10,   370,   291,   291,     4,     5,   278,   278,   291,
     291,   352,    10,   285,   251,    86,    87,    97,   275,   278,
     271,   251,   278,   356,   283,   251,   275,   283,   271,   278,
     278,   283,   251,   271,   251,   271,   251,   271,   271,   251,
     251,   251,   271,   271,   251,   283,   283,   251,   275,   251,
     275,   251,   283,   251,   251,   251,   283,   275,   251,   251,
     251,   283,   251,   283,   251,   275,   251,   278,   275,   275,
     251,   251,   251,   251,   251,   283,   251,   283,   283,   251,
     283,   283,   283,   251,   251,   251,   283,   251,   251,   251,
     283,   251,   251,   251,   251,   251,   283,   251,   251,   275,
     251,   251,   251,   283,   251,   275,   251,   275,   251,   275,
     251,   275,   251,   275,   251,   251,   251,   278,   252,   251,
     251,   251,   253,   253,   275,   278,   275,   278,   278,   278,
     260,   251,   271,   271,     4,     5,   300,   253,   253,   251,
     251,   253,   251,   251,   251,   253,   251,   253,   251,   253,
     251,   252,   252,   253,   253,   251,   251,   271,   251,   251,
     253,   251,   251,   251,   275,   251,   251,   275,   253,   275,
     275,   253,   253,   253,   253,   253,   251,   253,   253,   251,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   251,   253,   253,   251,   251,   251,   253,   251,   251,
     253,   251,   253,   253,   253,   253,   253,   251,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   251,
     251,   251,   251,   253,   253,   253,   253,   253,   251,   253,
     253,   253,   253,   253,   253,   251,   253,   251,   251,   251,
     251,   251,   253,   251,   251,   253,   251,   253,   253,   278,
     278,   310,   258,   278,   287,   373,   287,   374,   291,   291,
     303,   291,   291,   305,   294,    43,   320,   336,    49,    50,
     342,   251,   278,   251,   253,   253,   252,   275,   275,   278,
     278,   252,   275,   357,   358,   278,     4,     5,   348,   350,
     253,   253,   252,   252,   251,   251,   253,   253,   278,    85,
      85,   251,   251,   283,   275,   275,   251,   283,   251,   251,
     251,   275,   283,   278,   283,   275,   283,   283,   275,   278,
     278,   278,   283,   283,   278,   251,   251,   278,   251,   278,
     251,   275,   278,   251,   275,   275,   275,   251,   251,   275,
     275,   275,   278,   251,   275,   251,   278,   251,   275,   251,
     275,   275,   278,   275,   278,   251,   275,   251,   251,   278,
     251,   251,   251,   275,   278,   275,   278,   278,   251,   275,
     278,   278,   251,   275,   275,   278,   275,   275,   278,   251,
     275,   278,   251,   278,   275,   278,   251,   275,   251,   278,
     251,   275,   278,   251,   275,   251,   275,   251,   275,   275,
     275,   251,   291,   278,   278,   278,   251,   251,   262,   278,
     283,   283,   297,   278,   278,   278,   278,   278,   275,    97,
     275,   275,   253,   253,   278,   278,   283,   278,   275,   278,
     278,   278,   278,   275,   253,   251,   251,   278,   278,   278,
     278,   278,   278,   278,   278,   275,   278,   275,   275,   275,
     275,   275,   278,   278,   278,   278,   282,   275,   282,   275,
     275,   278,    16,    44,   330,   251,   251,   253,   253,   253,
     253,    39,    40,   322,   258,   278,   251,   275,    58,   275,
     355,   251,   278,   251,   253,   348,   348,   253,   252,   252,
     251,   291,   291,   278,   278,   251,   372,   372,   275,   275,
     251,   251,   275,   278,   278,   275,   251,   251,   271,   251,
     251,   271,   251,   251,   251,   271,   251,   251,   275,   275,
     275,   275,   275,   251,   275,   275,   251,   251,   251,   275,
     251,   275,   275,   251,   275,   251,   251,   275,   251,   275,
     275,   275,   275,   275,   251,   275,   275,   251,   251,   275,
     251,   251,   278,   251,   275,   275,   251,   275,   251,   251,
     275,   251,   275,   251,   275,   251,   251,   275,   253,   253,
     253,   251,   253,   275,   275,   271,   252,   253,   253,   253,
     253,   253,   253,   253,   251,   253,   253,   253,   253,   271,
     251,   251,   275,   275,   253,   253,   253,   253,   253,   251,
     253,   253,   253,   251,   253,   253,   253,   251,   251,   253,
     251,   253,   253,   253,   251,   251,   253,   251,   253,   253,
     251,   253,   253,   253,    12,   287,   287,   319,    43,    38,
     337,   253,   278,   253,   252,   251,   278,   251,   275,    58,
     364,   359,   291,   291,   349,   253,   253,   275,   275,   275,
     251,   251,   251,   275,   275,   283,   275,   275,   283,   278,
     278,   278,   283,   278,   275,   251,   251,   251,   251,   278,
     251,   251,   275,   278,   278,   251,   275,   251,   251,   278,
     278,   275,   278,   251,   275,   251,   251,   251,   251,   251,
     275,   251,   251,   275,   278,   275,   251,   278,   278,   278,
     251,   251,   278,   275,   275,   251,   275,   278,   251,   275,
     251,   275,   275,    75,    75,   278,    75,   251,   283,     4,
       5,   306,   307,   275,   278,   275,   278,   253,   253,   278,
     275,   275,   278,   278,   275,   278,   275,   275,   278,   321,
     323,    48,   344,    60,    61,   253,    58,   278,   275,   253,
     278,   253,   252,   370,   348,   253,   253,   348,   251,   275,
     275,   275,   251,   271,   251,   251,   251,   271,   251,   251,
     275,   278,   278,   275,   251,   278,   275,   251,   275,   251,
     275,   278,   251,   251,   275,   275,   278,   278,   275,   275,
     278,   275,   251,   278,   251,   251,   251,   278,   275,   251,
     251,   275,   251,   251,   275,   251,   275,   251,   275,   275,
     253,   275,   278,   252,   252,   251,   253,   253,   251,   253,
     253,   253,   253,   253,   253,   253,   253,   253,    13,   314,
     258,   258,   278,    47,   343,   252,   252,   251,   253,    60,
      61,   360,   253,    58,   365,   278,   348,   275,   275,   283,
     278,   275,   278,   283,   278,   275,   251,   251,   251,   251,
     278,   251,   251,   278,   251,   278,   251,   251,   278,   278,
     251,   251,   251,   251,   251,   251,   278,   251,   278,   278,
     278,   251,   251,   278,   275,   275,   275,   251,   275,   278,
     251,   275,    75,   253,   253,   307,   298,   278,   278,   311,
      46,   347,   258,   338,   275,   278,   278,   366,   252,   370,
     361,   252,   370,   251,   251,   251,   251,   251,   251,   251,
     275,   275,   275,   275,   251,   275,   275,   251,   278,   275,
     278,   251,   275,   278,   278,   275,   275,   275,   275,   251,
     251,   251,   275,   275,   251,   275,   251,   251,   275,   275,
     258,   253,   258,   345,    14,    16,    18,    41,    44,    49,
     339,   251,   253,   251,   253,   370,   275,   348,   370,   278,
     348,   278,   275,   275,   278,   275,   275,   275,   251,   278,
     278,   251,   251,   251,   278,   251,   251,   278,   275,   278,
     251,   275,   275,   275,   251,    25,    44,   299,   312,   258,
     275,   278,   348,   251,   253,   348,   251,   253,   251,   275,
     278,   275,   278,   275,   275,   251,   275,   251,   275,    14,
      16,    18,    41,    44,    49,   313,   346,   253,   253,   275,
     367,   278,   362,   275,   251,   251,   278,   275,     4,   315,
     344,   253,   370,   253,   370,   275,   275,   251,   368,   348,
     363,   348,   251,   275,   370,   370,   275,   348,   348
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   255,   256,   256,   256,   256,   256,   257,   258,   259,
     260,   258,   261,   261,   261,   261,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   263,   262,   264,   262,   262,   262,   262,   262,   262,
     262,   265,   262,   266,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   267,   262,   268,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   269,   269,   269,   269,   269,
     270,   270,   270,   270,   270,   270,   271,   271,   272,   272,
     272,   272,   272,   273,   273,   274,   274,   275,   275,   275,
     275,   275,   275,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   277,
     277,   279,   278,   280,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   281,   282,   283,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   285,   285,   285,
     286,   286,   286,   286,   287,   287,   288,   288,   288,   288,
     289,   290,   292,   291,   293,   293,   293,   294,   294,   296,
     297,   298,   295,   299,   299,   300,   300,   301,   301,   301,
     301,   302,   302,   303,   303,   303,   303,   304,   304,   305,
     305,   305,   305,   306,   306,   306,   307,   307,   307,   307,
     309,   310,   311,   312,   308,   313,   313,   313,   313,   313,
     313,   314,   314,   315,   315,   317,   316,   318,   318,   319,
     319,   320,   321,   320,   322,   323,   322,   325,   324,   326,
     326,   326,   326,   326,   326,   328,   329,   327,   330,   330,
     332,   331,   333,   333,   333,   333,   333,   333,   335,   336,
     337,   338,   334,   339,   339,   339,   339,   339,   339,   341,
     340,   342,   342,   343,   343,   344,   345,   346,   344,   347,
     347,   348,   349,   348,   350,   350,   350,   350,   351,   351,
     352,   352,   352,   352,   353,   353,   353,   353,   354,   354,
     354,   354,   354,   355,   355,   355,   357,   356,   358,   356,
     359,   356,   360,   356,   361,   356,   362,   356,   363,   356,
     364,   356,   365,   356,   366,   356,   367,   356,   368,   356,
     369,   356,   370,   370,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   372,   372,
     373,   373,   374,   374
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
       7,     3,     4,     5,     2,     7,     6,     6,     4,     6,
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
       4,     2,     5,     7,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     5,     5,     7,     4,     1,     2,     2,
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

  case 305: /* string_function: tATTRIBUTE tGETS '(' string_expression ',' string_expression ')'  */
                                                                     {create_function(fYABATTRIBUTEGET);}
    break;

  case 306: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 307: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 308: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 309: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 310: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 311: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 312: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 313: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 314: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 315: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 316: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 317: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 318: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 319: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 320: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 321: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 322: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 323: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 324: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 325: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 326: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 327: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 328: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 329: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 330: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 331: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 332: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 333: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 334: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 335: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 336: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 337: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 338: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 339: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 340: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 341: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 342: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 343: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 344: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 345: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 346: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 347: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 348: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 349: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 350: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 351: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 352: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 353: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 354: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 357: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 358: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 360: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 361: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 362: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 363: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 364: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 365: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 366: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 367: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 368: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 369: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 370: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 371: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 372: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 373: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 374: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 375: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 376: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 377: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 378: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 379: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 380: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 381: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 382: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 383: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 384: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 385: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 386: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 387: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 388: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 389: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 390: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 391: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 392: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 393: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 394: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 395: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 396: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 397: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 398: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 399: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 400: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 401: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 402: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 403: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 404: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 405: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 406: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 407: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 408: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 409: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 410: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 411: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 412: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 413: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 414: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 415: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 416: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 417: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 418: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 419: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 420: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 421: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 422: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 423: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 424: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 425: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 426: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 427: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 428: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 429: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 430: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 431: /* function: tWINDOW tCOUNT  */
                   {create_function(fYABNUMWINDOWS);}
    break;

  case 432: /* function: tWINDOW tGET string_expression ',' string_expression  */
                                                         {create_function(fYABWINDOWGET);}
    break;

  case 433: /* function: tATTRIBUTE tGET '(' string_expression ',' string_expression ')'  */
                                                                    {create_function(fYABATTRIBUTEGETNUM);}
    break;

  case 434: /* function: tLISTBOX tCOUNT string_expression  */
                                                      {create_function(fYABLISTBOXCOUNT);}
    break;

  case 435: /* function: tLISTBOX tGET string_expression  */
                                                    {create_function(fYABLISTBOXSELECTED);}
    break;

  case 436: /* function: tDROPBOX tCOUNT string_expression  */
                                                      {create_function(fYABDROPBOXCOUNT);}
    break;

  case 437: /* function: tDROPBOX tGET string_expression  */
                                                    {create_function(fYABDROPBOXSELECTED);}
    break;

  case 438: /* function: tTREEBOX tCOUNT string_expression  */
                                                      {create_function(fYABTREEBOXCOUNT);}
    break;

  case 439: /* function: tTREEBOX tGET string_expression  */
                                                    {create_function(fYABTREEBOXSELECTED);}
    break;

  case 440: /* function: tCOLUMNBOX tCOUNT string_expression  */
                                                        {create_function(fYABCOLUMNBOXCOUNT);}
    break;

  case 441: /* function: tCOLUMNBOX tCOUNT tCOLUMN string_expression  */
                                                                {create_function(fYABCOLUMNBOXCOUNTCOLUMNS);}
    break;

  case 442: /* function: tCOLUMNBOX tGET string_expression  */
                                                      {create_function(fYABCOLUMNBOXSELECTED);}
    break;

  case 443: /* function: tCOLORCONTROL tGET string_expression ',' string_expression  */
                                                                               {create_function(fYABCOLORCONTROLGET);}
    break;

  case 444: /* function: tDRAW tGET string_expression ',' string_expression  */
                                                       {create_function(fYABDRAWGET);}
    break;

  case 445: /* function: tDRAW tGET string_expression ',' string_expression ',' string_expression  */
                                                                             {create_function(fYABDRAWGETTEXT);}
    break;

  case 446: /* function: tBFILESIZE '(' string_expression ')'  */
                                         {create_function(fYABBFILESIZE);}
    break;

  case 447: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 448: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 449: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 450: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 451: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 452: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 453: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 454: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 455: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 456: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 457: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 458: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 459: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 460: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 461: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 462: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 469: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 470: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 471: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 472: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 473: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 474: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 475: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 476: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 477: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 478: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 479: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 480: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 483: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 484: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 485: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 486: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 489: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 490: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 491: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 492: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 496: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 497: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 498: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 499: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 500: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 501: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 502: /* $@17: %empty  */
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

  case 503: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 504: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 505: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 506: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 507: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 508: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 509: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 510: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 511: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 513: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 514: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 515: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 516: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 522: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 523: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 525: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 527: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 529: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 530: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 531: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 532: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 533: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 534: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 535: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 536: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 538: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 539: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 540: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 542: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 543: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 544: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 545: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 546: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 547: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 548: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 549: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 550: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 551: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 553: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 554: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 555: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 556: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 557: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 558: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 559: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 561: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 562: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 566: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 567: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 572: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 574: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 575: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 576: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 577: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 580: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 581: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 582: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 583: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 584: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 585: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 586: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 587: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 591: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 592: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 593: /* using: %empty  */
       {create_print('d');}
    break;

  case 594: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 595: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 596: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 597: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 598: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 599: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 600: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 601: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 602: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 603: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 604: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 605: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 606: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 607: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 608: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 609: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 610: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 611: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 612: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 613: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 614: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 615: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 616: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 617: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 618: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 619: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 620: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 621: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 622: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 623: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 624: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 625: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 626: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 627: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 628: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 629: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 630: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 631: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 632: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 633: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 634: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 635: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 636: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 637: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 640: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 641: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 642: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 643: /* gosub_list: gosub_list ',' symbol_or_lineno  */
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

