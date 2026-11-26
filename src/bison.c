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
  YYSYMBOL_tSIN = 144,                     /* tSIN  */
  YYSYMBOL_tASIN = 145,                    /* tASIN  */
  YYSYMBOL_tCOS = 146,                     /* tCOS  */
  YYSYMBOL_tACOS = 147,                    /* tACOS  */
  YYSYMBOL_tTAN = 148,                     /* tTAN  */
  YYSYMBOL_tATAN = 149,                    /* tATAN  */
  YYSYMBOL_tEXP = 150,                     /* tEXP  */
  YYSYMBOL_tLOG = 151,                     /* tLOG  */
  YYSYMBOL_tSQRT = 152,                    /* tSQRT  */
  YYSYMBOL_tSQR = 153,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 154,                   /* tMYEOF  */
  YYSYMBOL_tABS = 155,                     /* tABS  */
  YYSYMBOL_tSIG = 156,                     /* tSIG  */
  YYSYMBOL_tINT = 157,                     /* tINT  */
  YYSYMBOL_tCEIL = 158,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 159,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 160,                    /* tFRAC  */
  YYSYMBOL_tROUND = 161,                   /* tROUND  */
  YYSYMBOL_tMOD = 162,                     /* tMOD  */
  YYSYMBOL_tRAN = 163,                     /* tRAN  */
  YYSYMBOL_tVAL = 164,                     /* tVAL  */
  YYSYMBOL_tLEFT = 165,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 166,                   /* tRIGHT  */
  YYSYMBOL_tMID = 167,                     /* tMID  */
  YYSYMBOL_tLEN = 168,                     /* tLEN  */
  YYSYMBOL_tMIN = 169,                     /* tMIN  */
  YYSYMBOL_tMAX = 170,                     /* tMAX  */
  YYSYMBOL_tSTR = 171,                     /* tSTR  */
  YYSYMBOL_tINKEY = 172,                   /* tINKEY  */
  YYSYMBOL_tCHR = 173,                     /* tCHR  */
  YYSYMBOL_tASC = 174,                     /* tASC  */
  YYSYMBOL_tHEX = 175,                     /* tHEX  */
  YYSYMBOL_tDEC = 176,                     /* tDEC  */
  YYSYMBOL_tBIN = 177,                     /* tBIN  */
  YYSYMBOL_tUPPER = 178,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 179,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 180,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 181,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 182,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 183,                /* tMOUSEMOD  */
  YYSYMBOL_tTRIM = 184,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 185,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 186,                   /* tRTRIM  */
  YYSYMBOL_tSTRING2 = 187,                 /* tSTRING2  */
  YYSYMBOL_tREPLACE = 188,                 /* tREPLACE  */
  YYSYMBOL_tINSTR = 189,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 190,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 191,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 192,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 193,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 194,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 195,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 196,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 197,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 198,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 199,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 200,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 201,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 202,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 203,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 204,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 205,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 206,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 207,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 208,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 209,                    /* tDATE  */
  YYSYMBOL_tTIME = 210,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 211,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 212,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 213,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 214,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 215,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 216,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 217,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 218, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 219,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 220, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 221,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 222,                   /* tEVAL2  */
  YYSYMBOL_223_ = 223,                     /* '-'  */
  YYSYMBOL_224_ = 224,                     /* '+'  */
  YYSYMBOL_225_ = 225,                     /* '*'  */
  YYSYMBOL_226_ = 226,                     /* '/'  */
  YYSYMBOL_UMINUS = 227,                   /* UMINUS  */
  YYSYMBOL_228_ = 228,                     /* ';'  */
  YYSYMBOL_229_ = 229,                     /* ','  */
  YYSYMBOL_230_ = 230,                     /* '('  */
  YYSYMBOL_231_ = 231,                     /* ')'  */
  YYSYMBOL_232_ = 232,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 233,                 /* $accept  */
  YYSYMBOL_program_or_expression = 234,    /* program_or_expression  */
  YYSYMBOL_program = 235,                  /* program  */
  YYSYMBOL_statement_list = 236,           /* statement_list  */
  YYSYMBOL_237_1 = 237,                    /* $@1  */
  YYSYMBOL_238_2 = 238,                    /* $@2  */
  YYSYMBOL_assignment = 239,               /* assignment  */
  YYSYMBOL_statement = 240,                /* statement  */
  YYSYMBOL_241_3 = 241,                    /* $@3  */
  YYSYMBOL_242_4 = 242,                    /* $@4  */
  YYSYMBOL_243_5 = 243,                    /* $@5  */
  YYSYMBOL_244_6 = 244,                    /* $@6  */
  YYSYMBOL_245_7 = 245,                    /* $@7  */
  YYSYMBOL_246_8 = 246,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 247,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 248,        /* string_assignment  */
  YYSYMBOL_to = 249,                       /* to  */
  YYSYMBOL_open_clause = 250,              /* open_clause  */
  YYSYMBOL_seek_clause = 251,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 252,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 253,        /* string_expression  */
  YYSYMBOL_string_function = 254,          /* string_function  */
  YYSYMBOL_number_assignment = 255,        /* number_assignment  */
  YYSYMBOL_expression = 256,               /* expression  */
  YYSYMBOL_257_9 = 257,                    /* $@9  */
  YYSYMBOL_258_10 = 258,                   /* $@10  */
  YYSYMBOL_arrayref = 259,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 260,          /* string_arrayref  */
  YYSYMBOL_coordinates = 261,              /* coordinates  */
  YYSYMBOL_function = 262,                 /* function  */
  YYSYMBOL_const = 263,                    /* const  */
  YYSYMBOL_number = 264,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 265,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 266,                  /* dimlist  */
  YYSYMBOL_function_or_array = 267,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 268,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 269,                /* call_list  */
  YYSYMBOL_270_11 = 270,                   /* $@11  */
  YYSYMBOL_calls = 271,                    /* calls  */
  YYSYMBOL_call_item = 272,                /* call_item  */
  YYSYMBOL_function_definition = 273,      /* function_definition  */
  YYSYMBOL_274_12 = 274,                   /* $@12  */
  YYSYMBOL_275_13 = 275,                   /* $@13  */
  YYSYMBOL_276_14 = 276,                   /* $@14  */
  YYSYMBOL_endsub = 277,                   /* endsub  */
  YYSYMBOL_function_name = 278,            /* function_name  */
  YYSYMBOL_export = 279,                   /* export  */
  YYSYMBOL_local_list = 280,               /* local_list  */
  YYSYMBOL_local_item = 281,               /* local_item  */
  YYSYMBOL_static_list = 282,              /* static_list  */
  YYSYMBOL_static_item = 283,              /* static_item  */
  YYSYMBOL_paramlist = 284,                /* paramlist  */
  YYSYMBOL_paramitem = 285,                /* paramitem  */
  YYSYMBOL_for_loop = 286,                 /* for_loop  */
  YYSYMBOL_287_15 = 287,                   /* $@15  */
  YYSYMBOL_288_16 = 288,                   /* $@16  */
  YYSYMBOL_289_17 = 289,                   /* $@17  */
  YYSYMBOL_290_18 = 290,                   /* $@18  */
  YYSYMBOL_next = 291,                     /* next  */
  YYSYMBOL_step_part = 292,                /* step_part  */
  YYSYMBOL_next_symbol = 293,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 294,  /* switch_number_or_string  */
  YYSYMBOL_295_19 = 295,                   /* $@19  */
  YYSYMBOL_sep_list = 296,                 /* sep_list  */
  YYSYMBOL_number_or_string = 297,         /* number_or_string  */
  YYSYMBOL_case_list = 298,                /* case_list  */
  YYSYMBOL_299_20 = 299,                   /* $@20  */
  YYSYMBOL_default = 300,                  /* default  */
  YYSYMBOL_301_21 = 301,                   /* $@21  */
  YYSYMBOL_do_loop = 302,                  /* do_loop  */
  YYSYMBOL_303_22 = 303,                   /* $@22  */
  YYSYMBOL_loop = 304,                     /* loop  */
  YYSYMBOL_while_loop = 305,               /* while_loop  */
  YYSYMBOL_306_23 = 306,                   /* $@23  */
  YYSYMBOL_307_24 = 307,                   /* $@24  */
  YYSYMBOL_wend = 308,                     /* wend  */
  YYSYMBOL_repeat_loop = 309,              /* repeat_loop  */
  YYSYMBOL_310_25 = 310,                   /* $@25  */
  YYSYMBOL_until = 311,                    /* until  */
  YYSYMBOL_if_clause = 312,                /* if_clause  */
  YYSYMBOL_313_26 = 313,                   /* $@26  */
  YYSYMBOL_314_27 = 314,                   /* $@27  */
  YYSYMBOL_315_28 = 315,                   /* $@28  */
  YYSYMBOL_316_29 = 316,                   /* $@29  */
  YYSYMBOL_endif = 317,                    /* endif  */
  YYSYMBOL_short_if = 318,                 /* short_if  */
  YYSYMBOL_319_30 = 319,                   /* $@30  */
  YYSYMBOL_end_of_if = 320,                /* end_of_if  */
  YYSYMBOL_else_part = 321,                /* else_part  */
  YYSYMBOL_elsif_part = 322,               /* elsif_part  */
  YYSYMBOL_323_31 = 323,                   /* $@31  */
  YYSYMBOL_324_32 = 324,                   /* $@32  */
  YYSYMBOL_maybe_then = 325,               /* maybe_then  */
  YYSYMBOL_inputlist = 326,                /* inputlist  */
  YYSYMBOL_327_33 = 327,                   /* $@33  */
  YYSYMBOL_input = 328,                    /* input  */
  YYSYMBOL_readlist = 329,                 /* readlist  */
  YYSYMBOL_readitem = 330,                 /* readitem  */
  YYSYMBOL_datalist = 331,                 /* datalist  */
  YYSYMBOL_printlist = 332,                /* printlist  */
  YYSYMBOL_using = 333,                    /* using  */
  YYSYMBOL_inputbody = 334,                /* inputbody  */
  YYSYMBOL_335_34 = 335,                   /* $@34  */
  YYSYMBOL_336_35 = 336,                   /* $@35  */
  YYSYMBOL_337_36 = 337,                   /* $@36  */
  YYSYMBOL_338_37 = 338,                   /* $@37  */
  YYSYMBOL_339_38 = 339,                   /* $@38  */
  YYSYMBOL_340_39 = 340,                   /* $@39  */
  YYSYMBOL_341_40 = 341,                   /* $@40  */
  YYSYMBOL_342_41 = 342,                   /* $@41  */
  YYSYMBOL_343_42 = 343,                   /* $@42  */
  YYSYMBOL_344_43 = 344,                   /* $@43  */
  YYSYMBOL_345_44 = 345,                   /* $@44  */
  YYSYMBOL_346_45 = 346,                   /* $@45  */
  YYSYMBOL_347_46 = 347,                   /* $@46  */
  YYSYMBOL_prompt = 348,                   /* prompt  */
  YYSYMBOL_printintro = 349,               /* printintro  */
  YYSYMBOL_hashed_number = 350,            /* hashed_number  */
  YYSYMBOL_goto_list = 351,                /* goto_list  */
  YYSYMBOL_gosub_list = 352                /* gosub_list  */
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
#define YYFINAL  221
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   11334

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  233
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  568
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1665

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   478


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
       2,     2,     2,     2,     2,   232,     2,     2,     2,     2,
     230,   231,   225,   224,   229,   223,     2,   226,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   228,
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
     215,   216,   217,   218,   219,   220,   221,   222,   227
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   214,   214,   215,   216,   217,   218,   221,   224,   225,
     225,   225,   228,   229,   230,   231,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   249,   250,   250,   251,   252,   253,   254,   255,
     256,   257,   257,   259,   259,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   271,   272,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   289,   290,
     291,   292,   293,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   415,   416,   417,   418,   419,   423,   424,   425,
     426,   427,   428,   431,   432,   435,   436,   437,   438,   439,
     442,   443,   446,   447,   450,   451,   452,   453,   454,   455,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   507,   508,   511,   511,   512,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   547,   550,   553,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,   624,   625,   626,   629,   630,   631,
     632,   633,   636,   637,   638,   641,   642,   643,   644,   647,
     648,   651,   652,   653,   654,   657,   660,   663,   663,   666,
     667,   668,   671,   672,   675,   676,   679,   675,   684,   685,
     688,   689,   692,   693,   694,   695,   698,   699,   702,   703,
     704,   705,   708,   709,   712,   713,   714,   715,   718,   719,
     720,   723,   724,   725,   726,   729,   730,   735,   750,   729,
     755,   756,   757,   758,   759,   760,   763,   764,   767,   768,
     773,   773,   777,   778,   781,   782,   786,   788,   787,   792,
     793,   793,   797,   797,   803,   804,   805,   806,   807,   808,
     812,   813,   812,   819,   820,   824,   824,   829,   830,   831,
     832,   833,   834,   837,   838,   838,   840,   837,   844,   845,
     846,   847,   848,   849,   852,   852,   857,   858,   861,   862,
     865,   867,   869,   866,   873,   874,   877,   878,   878,   881,
     882,   884,   885,   889,   890,   893,   894,   896,   897,   901,
     902,   903,   904,   907,   908,   909,   910,   911,   914,   915,
     916,   919,   919,   920,   920,   921,   921,   922,   922,   923,
     923,   924,   924,   925,   925,   926,   926,   927,   927,   928,
     928,   929,   929,   930,   930,   931,   931,   934,   935,   938,
     939,   940,   941,   942,   943,   944,   945,   946,   947,   948,
     949,   950,   951,   954,   955,   957,   958,   961,   962
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
  "tSIN", "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP", "tLOG",
  "tSQRT", "tSQR", "tMYEOF", "tABS", "tSIG", "tINT", "tCEIL", "tFLOOR",
  "tFRAC", "tROUND", "tMOD", "tRAN", "tVAL", "tLEFT", "tRIGHT", "tMID",
  "tLEN", "tMIN", "tMAX", "tSTR", "tINKEY", "tCHR", "tASC", "tHEX", "tDEC",
  "tBIN", "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY", "tMOUSEB", "tMOUSEMOD",
  "tTRIM", "tLTRIM", "tRTRIM", "tSTRING2", "tREPLACE", "tINSTR", "tRINSTR",
  "tCHOMP", "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE",
  "tFRNFN_CALL", "tFRNFN_CALL2", "tFRNFN_SIZE", "tFRNBF_ALLOC",
  "tFRNBF_FREE", "tFRNBF_SIZE", "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET",
  "tFRNBF_GET2", "tFRNBF_GET_BUFFER", "tFRNBF_SET_BUFFER", "tDATE",
  "tTIME", "tTOKEN", "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB",
  "tSTART_PROGRAM", "tSTART_EXPRESSION", "tSTART_STRING_EXPRESSION",
  "tSTART_ASSIGNMENT", "tSTART_FUNCTION_DEFINITION", "tEVAL", "tEVAL2",
  "'-'", "'+'", "'*'", "'/'", "UMINUS", "';'", "','", "'('", "')'", "'#'",
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

#define YYPACT_NINF (-1300)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-474)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1064,  8833,  7672,  8319,    57,     4,    36,   -48,   -44, -1300,
   -1300, -1300, -1300, -1300,   227,   227,   227,  5656, -1300, -1300,
   -1300,  8319, -1300, -1300,  8319,    52,    49, -1300, -1300, -1300,
    7672,   -38, -1300,  7672,   104, -1300,  7672,  7672,  7672,   192,
      38,   227,  2880,  1801,  3363,    13,  7672,  4984,  5880,    53,
      30,  7672, -1300,    98,  8319,  8319,  8319,    11,  7672,   745,
    7672,  7672,  6104,  6328,  5208,  4312,  7672,  4536,  6552,  6776,
    7997,  8319,  8319,   -36,  4760,  7000,  7672,  7224,  7672,  7672,
     -97,   -82,   -43,     0,     6,  3363,  8319,  8319,  8319, -1300,
     117, -1300, -1300,    18, -1300, -1300, -1300, -1300,   157,   220,
   -1300,   275, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
      81,    84, -1300, -1300, -1300, -1300,    92,   123,   129,   145,
    7672,   148,   164,   173,   201,   213,   234,   170,   242,   251,
     263,   289,   249,   305,   442,   448,   351,   360,   377,   383,
     427,   459,   465,   468,   484,   514,   525,   526,   552,   555,
     567,   568,   579,   597,   600,   603,   604,   611,   614,   620,
     621,   628,   636,   638,   639,   640,   647,   655,   664,   667,
     696,   698,   708,   729,   739,   741,   752,   761,   762,   770,
     771,   772,   774,   784,   794,   804,   813,   814,   815,   817,
     829,   841,   842,   852,   864,   871,   880,   888,   894,   900,
     909,   910,   913,   923,   924,   925,  7672,  7672,   437, -1300,
     578, -1300, -1300, -1300, -1300,  8319,   -25,   629,   157,   220,
     666, -1300,  7672, -1300,  8319, -1300,   822,  7672,  8639, -1300,
   -1300, -1300, -1300, -1300,   299,   494,   388,   409,   550, -1300,
    7672, -1300,   550, -1300, -1300,  7672,  8639,   675,   926,   718,
     955,     3,  7672,    12,   437,  4596,   957,   969,   701,  4596,
     437,  2581,   437,  8487,   981,  1018,   711, -1300, -1300,   577,
     577, -1300, -1300,   746, -1300,  5432,  8319,  7672,    17,  4596,
     855,   170, -1300, -1300, -1300,   897,  7672,  8319,  8319,  8319,
    9524, -1300,  7672, -1300,    14,  8319,   972, -1300, -1300,  7672,
    7448, -1300, -1300,  4596, -1300, -1300,   550,    26,    26, -1300,
      14,  7672,  7672,  7672,  7672,  7672,  7672,  7672,  8319,  8319,
    7672,  7672,  7672,  7672,    14,    14,  8319,  1003,  8319,  1028,
    8319,  8319,    14,  8319,  8319,  8319,  8319,    14,  1030,  8319,
    8319,  8319,    14,  8319,    14,  8319,  1031,  8319,   -29,   -21,
      22,  8319,  8319,  8319,  8319,  8319,    14,  8319,    14,    14,
    8319,    14,    14,    14,   953,   953,   953,  3625,  8319,    97,
    1032,   550,   100,   237, -1300,   947,  7672,  7672,  7672,  7672,
    8319, -1300, -1300, -1300,  7672,  7672,   687,  7672,  7672,  7672,
    7672,  3133,  3363,  8319, -1300,   424,   424,  7672,  7672,  8319,
    8319,  8319,  8319,  7672,  7672,  7672,  7672,  7672,  7672,  7672,
    7672,  7672,  7672,  3363,  7672,  7672,  7672,  7672,  7672,  7672,
    7672,  7672,  3854,  8319,  8319,  8319,  8319,  8319,  7672,  7672,
    7672,  4083,  7672,  8319,  7672,  8319,  7672,  8319,  8319,   493,
    2241,  7783,  7891,  8319,  8319,  8319,  7672,  8319,  8319,  8319,
    8319,  8319,  8319,  3363,  8319, -1300, -1300,  8319,  7672,  8319,
    8319,  8319,  8319,  8319,   576,   792,  8319,   953,  8319,   953,
    8319,  8319,  8319,   956,   231,  1330,  8319,  8319,  8319,  8319,
    8319,  8319,  8319,  8319, -1300, -1300, -1300,  7672,  7672,  7672,
    7672,  7672,  7672,  7672,  7672,  7672,  7672,  7672,  7672,  -191,
   -1300, -1300, -1300,  4596,   878,   550,  1037,   906,  4596,    82,
   -1300, -1300, -1300, -1300,  1039,  1040,  1042, -1300,  1055,  1057,
    1059, -1300,   437,  4596,  1060, -1300,   437,  4596,  1247,   161,
    1245,  8639,  7672,  1063,  8319, -1300, -1300,  7672,   437,   935,
     224,  1066,  1236,  1071,    10, -1300,  1294, -1300, -1300,   500,
    7672,  7672, -1300, -1300,   192, -1300, -1300,    56,  9539,   550,
    4596,   430,  8105,  7672,    14,   550,   550,   277,  7672, -1300,
      12, -1300, -1300,  7672,   375,  8319, -1300,  7672,    14,  7672,
    7672,  7672,  1078,    14,  1079,    14,  1080,    14,    14,   381,
     550,  1083,  1086,    14,    14,  7672,  7672,   392,  8319,   502,
    8319,   550,   504,  7672,   506,   550,   542,   544,  7672,  8319,
     546,   548,   554,  7672,   564,  7672,   570,  8319,   581,  7672,
    8319,  8319,   582,   584,   592,   595,   596,  7672,   616,  7672,
    7672,   619,  7672,  7672,  7672,  1087,  1089,  1091,  1092, -1300,
    1384,  -150,  7672,  7672,  7672,  7672, -1300,  1093,    14,    14,
    4596,   550,   541,  1094,  1096,  9554,  9574,  1399,  9602,  9617,
    9639,  1097,   477,  1095,  1101,   623,  1103,  1108,  1109,  1110,
    1113,  1114,    14,  9718,   630,  -127,   550,   550,  1576,  1591,
    1694,  1973,  1991,   965,  2050,   990,  2065,  2253,  1115,  2286,
    2451,  2490,  2791,  3043,  3385,  3423,  9738, -1300,  3647,    50,
     643,   652,   659,    69,  9781,  9803,   412,  1016, -1300,  3685,
    3876,   115,  3914,   -79,  4105,   152,   160, -1300,   171, -1300,
     180, -1300,   188, -1300,   202,   265,   268,   271,  9818,   660,
     663,   691,   294,   309,   310,   503,  1116,   -69,  1117,  1121,
     312,  4143,   313,   -66,   692,   694,   700, -1300, -1300,   703,
     -55,   710,   -20,   713,   331,   332, -1300, -1300,   550,   550,
     550,   550,   550,   550,   550, -1300,  7672,  7672,  1132,   297,
     872,   517,     2,   304,   -35, -1300,   -33,   -33,   956,   956,
   -1300, -1300, -1300,  8639, -1300, -1300,  7672, -1300, -1300, -1300,
   -1300,   227,   227, -1300, -1300,   388, -1300, -1300,   409,  7672,
   -1300,  1296, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
     575,  9833,  7672,    28,  4558,  8427, -1300, -1300,  7672,  7672,
    1123,  8319, -1300, -1300,  7672, -1300,   642,  1128,  1129,  1131,
    1134,  9848,  9863,  1136,  1137, -1300, -1300, -1300,  7672,  1260,
    1277, -1300,   726,  9882,  7672,  8319,  4596, -1300, -1300,  8319,
     727, -1300,  7672,  9902,  9917,  1141,  8319,  7672,  7672,  7672,
    8319,  7672,  7672,  7672,  7672,  7672,  7672,  7672,  1142,  1143,
    7672,   728,  7672,   744,  7672,  1145,  8319,  8319,  8319,  1147,
     748,  8319,  8319,  7672,  1148,  8319,  1150,  7672,   750,  8319,
    9945,   550,   550,  8319,  8319,  7672,  8319,  7672,  1151,  8319,
    1153,  1155,  7672,  1156,  1161,  1163, -1300,  7672,  7672,  7672,
   -1300, -1300,   437,  4596,   437,  4596, 10027, 10046,  8639,  7672,
    7672,  7672, -1300, -1300, -1300, -1300, -1300,  7672,  7672, -1300,
    7672,  7672,  7672, -1300,  8319, -1300,  8213, -1300,  8319,  1164,
    1165, -1300, -1300,  7672,  7672,  7672,  7672,  8319, -1300, -1300,
   -1300, -1300, -1300, -1300,  7672, -1300, -1300,  7672, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,  7672,
   -1300, -1300,  7672,  7672,  7672, -1300,  7672,  7672, -1300,  8319,
   -1300, -1300, -1300, -1300, -1300,  7672, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300,  8319,  8319,  8319,
    8319, -1300, -1300, -1300, -1300, -1300,  8319, -1300, -1300, -1300,
   -1300, -1300, -1300,  7672, -1300,  7672,  7672,  7672,  1360,  8319,
   -1300,  1360,  8319, -1300,  8319, -1300, -1300,   687,   832,  7672,
      55,  4596, -1300,  1168, -1300,  1169,  1177,  1178, -1300,  1179,
    1180, -1300, -1300, -1300,   673,  8639, -1300, -1300, -1300,  7672,
   10081,  8319,  1341, -1300,  8319,   550,   437,   935, 10109,  7672,
      46,   642,   642,  4782,  1182,  1184, -1300,  1188, -1300, -1300,
   -1300, -1300,  7672,  7672, -1300, -1300, 10124,  3363,  3363,  8319,
    8319,  1189,   754,   550,  8319, -1300,  7672,  7672,  8319,   550,
    1190, 10139,    14,   756,  1191,    14,   437, 10154, 10169, 10191,
      14,  1194,  8319,  8319,  4596,  8319,  4596,  8319,   437,  4596,
    8319,   760,   550,   550,  8319,  8319,   764,   789,   557,  4596,
    8319,   791,  8319,  4596,  8319,   793,  8319,   801,   802,  4596,
     550,  4596,  8319,   803,  8319,  8319,  4596,  8319,  8319,  8319,
    1193,  5006,  5454,  1074,  8319,  8319, -1300,  4596,    14, -1300,
    1199,  5678,  5902,  6126,  6350,  6574,   365,  1201,    47,   550,
   -1300, -1300,  6798,  7022,  1204,    43,   844,  7246,  7470,  7694,
    8720,  8752,  1202,  8946,  9022,    67,  9110,   378,   845,    88,
      89,   384,  9132, 10210, 10225,  9166,    25,   413,    79,   414,
     432,    64, -1300, -1300, -1300,   227,   227, -1300, -1300, -1300,
   -1300,  7672,  1393,  1400,  1396,  9186,  7672,   438,  1210,   131,
   -1300,  7672, 10245,  8319,  1383, -1300, -1300, -1300, -1300, -1300,
   -1300,  1211,  1212,  4596,  4596,  8319, -1300, -1300,   550,   550,
    8319,  8319,   846, 10333,  4596,   854,  8319,  8319,  7672,  8319,
    8319,  7672,  7672,  7672,  7672,  7672,  7672,   550,   879,   896,
     898,   904,  7672,   928,   938,  8319,  7672,  7672,   939,  8319,
     940,   941,  7672,   550,  7672,  7672,   942,  8319,   948,   949,
     950,   951,   952, -1300,  1369,  1370,  7672,  1371,   971,   550,
    7672,   732, -1300, -1300, -1300, -1300, -1300, -1300, -1300,  8319,
   -1300, -1300, -1300, -1300,  7672,  8319, -1300, -1300, -1300, -1300,
   -1300,  7672, -1300, -1300, -1300,  8319, -1300, -1300, -1300,  8319,
    7672, -1300,  7672, -1300, -1300, -1300,  8319,  7672, -1300,  8319,
   -1300, -1300,  8319, -1300, -1300, -1300,  7672, -1300, -1300, -1300,
   -1300, -1300,  1401,   574,  9201,  1392,  7672,  8319,  9216,  7672,
     443,  1221,  1294,   642,  1222,  1233,   642, -1300, -1300,   550,
     973,   550,  8319,  8319,  8319,   550,   550,  1223,   550,   550,
      14, 10355, 10389, 10409,    14, 10424,  8319,  7672,  7672,  8319,
   10439,  7672,  8319,   550, 10454,  4596,  8319,   988,  8319,  7672,
   10469, 10497,   437,  4596,  8319,   550,  8319,  7672,  7672,  8319,
    8319,  8319,  8319,  9231,  8319,  7672, -1300,  1235,  1237,   116,
   -1300,   451, 10519,   550,  9246,   452,   461,  9274,  9296,   463,
    9311,   466,   480,   143,  8639,  9027,  7672,  1419, -1300,  1238,
   -1300,  1248, 10534,   485,   693,  9330,  1421,  7672,   642, -1300,
   -1300, -1300, -1300,  8319,   550,   550,   550,  8319,  7672,  7672,
    8319,  7672,  7672,  7672,   994, 10553, 10633,   996,  7672, 10661,
    1000,  7672,  1002,  7672,  1006, 10698,  7672,  7672,  1014,  1020,
   10717, 10732,   550,   550,   550,   550,  1402,   550,  4596,  1249,
    1250,   732, -1300, -1300,  7672, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300,  7672, -1300,  1396,  1444,   890,  8639,
   -1300,  8319,  7672,  7672, -1300, -1300,  1253,  1294, -1300,  1254,
    1294, 10747, -1300,   550,   550,  1256, 10762,   550, 10777,  1257,
   10797,  8319,  8319,  8319,  8319, 10825,  8319,  8319, 10840,  7672,
    4596,  8319,  7672,  4596, 10862,  8319,  7672,  7672,  8319,  8319,
   -1300, -1300, -1300,  8639,  9410,  4596,  8639, -1300, -1300,  1396,
     751,   158, 10941,  9438,  1294,  8319,   642,  1294,  7672,   642,
    7672,  8319,  8319,  7672,  8319,  8319,   550,   550,   550,  1022,
    7672,   550,   550,  7672, 10961,  1026, 11004,  7672,   550, 11026,
   11041,   550,   550,    61, -1300,  1396,  8639, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300,  8319, -1300,  7672, -1300,   642,   177,
   -1300,   642, 11056, -1300,  9475,   550,   550, 11071,   550,   550,
    8319,  4596,  4596,  7672,  8319,  7672,  4596,  8319,  8319, -1300,
   -1300, -1300,   773,  1396,   498,  9494, -1300,  8319, -1300, -1300,
    7672, -1300,  8319,   550, 11086,   550, 11105,   550,   550, -1300,
   -1300, -1300, -1300, -1300, -1300,  1483,  1401, -1300, -1300,   501,
    1294,  9509,  1294,   550,  8319,  8319, -1300, -1300, -1300, -1300,
     642, -1300,   642,  1034,   550,  1294, -1300,  1294, -1300,  8319,
     642,   642,   550, -1300, -1300
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   182,     0,     0,     0,   402,     0,     0,     0,   176,
     425,   460,   465,    18,     0,     0,     0,     0,    31,    33,
     403,     0,   387,   387,     0,   404,    25,    27,   440,   452,
       0,   549,    55,    67,     0,   173,   174,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   183,
     184,     0,   164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   165,     0,     0,     0,     0,     0,     2,
       9,    17,     8,     0,    12,    46,    48,    14,    29,    30,
      28,     0,    20,    21,    24,    23,    22,    35,    36,   375,
     277,   204,   376,   377,   378,   207,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   218,     0,     0,     0,     0,     0,
       0,     0,   337,   340,   343,   346,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   235,   237,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   205,
       0,   291,   271,   276,   206,     0,     0,     0,     0,     0,
       0,     1,     0,   387,     0,   387,     0,     0,    16,   380,
     379,    37,    38,    45,     0,     0,     0,     0,    19,    50,
     389,    51,    49,   405,    26,     0,    16,   484,     0,   553,
       0,     0,   513,   545,    69,    68,     0,     0,    70,   175,
      60,     0,    62,     0,   505,   507,    63,   503,   509,     0,
       0,   510,   372,    64,    66,     0,   160,     0,     0,   564,
       0,    92,   162,    86,    47,     0,     0,     0,     0,     0,
       0,    74,     0,    57,    79,     0,     0,    94,    93,     0,
       0,   185,   186,   163,    13,    15,   177,     0,     0,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   178,     0,     0,     7,     0,     0,     0,     0,     0,
       0,   394,   387,   387,     0,     0,   261,     0,     0,     0,
       0,     0,     0,     0,   367,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   387,   387,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   283,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,   259,   257,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     5,     6,   255,     0,   187,     0,     0,   461,     9,
      39,    40,    41,    43,   408,   409,    32,   406,   414,   415,
      34,   412,   392,   393,   388,   390,   445,   444,     0,     9,
       0,    16,     0,     0,     0,   550,   551,     0,   516,   518,
      52,     0,     0,     0,     0,    56,   547,   387,   387,     0,
       0,     0,   387,   387,     0,   374,   373,     0,     0,   161,
     563,     0,     0,     0,     0,    96,    73,     0,     0,    78,
     545,   194,   193,     0,     0,     0,    75,     0,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,     0,     0,     0,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,     0,     0,     0,   166,
       0,     0,     0,     0,     0,     0,    10,     0,     0,     0,
     256,   192,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,   241,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   317,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   219,     0,
       0,     0,     0,     0,     0,     0,     0,   338,     0,   341,
       0,   344,     0,   347,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   238,     0,
       0,     0,     0,     0,     0,     0,   209,   292,   286,   288,
     290,   287,   289,   284,   285,   208,     0,     0,   264,   266,
     268,   265,   267,   262,   263,   282,   279,   278,   280,   281,
     385,   386,   426,    16,   472,   470,     0,   471,   467,   469,
     466,     0,     0,   387,   387,     0,   387,   387,     0,     0,
     442,   446,   459,   457,   458,   455,   454,   456,   453,   474,
       9,     0,     0,     0,     0,     0,   514,    53,    54,     0,
       0,     0,   521,   523,     0,   548,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,   511,   512,     0,     0,
       0,   197,   196,   200,     0,     0,   295,    58,    76,     0,
      89,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   148,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   387,     0,     0,     0,
     167,   168,   169,   170,   171,   172,     0,     0,    16,     0,
       0,     0,   400,   401,   395,   359,   251,     0,     0,   350,
       0,     0,     0,   360,     0,   361,     0,   354,     0,     0,
       0,   272,   273,     0,     0,     0,     0,     0,   371,   296,
     297,   298,   299,   300,     0,   301,   303,     0,   304,   306,
     307,   269,   313,   314,   308,   310,   311,   312,   309,     0,
     316,   321,     0,     0,     0,   320,     0,     0,   217,     0,
     214,   220,   221,   322,   249,     0,   323,   250,   222,   223,
     336,   339,   342,   345,   226,   224,   225,     0,     0,     0,
       0,   229,   329,   230,   335,   334,     0,   239,   330,   231,
     331,   232,   333,     0,   233,     0,     0,     0,     0,     0,
     244,     0,     0,   246,     0,   366,   254,   260,   258,     0,
       9,   468,   565,    42,   567,    44,     0,     0,   407,     0,
       0,   413,   391,   443,   449,    16,   486,   487,   485,     0,
       0,     0,   554,   552,     0,   519,   517,   518,     0,     0,
       0,     0,     0,     0,   499,   501,   546,   496,   381,   383,
     387,   387,     0,     0,   506,   508,    71,     0,     0,     0,
       0,     0,     0,   121,     0,    77,     0,     0,     0,   102,
       0,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,     0,   117,     0,   119,     0,   124,   125,
       0,     0,   129,   128,     0,     0,     0,     0,     0,   137,
       0,     0,     0,   144,     0,     0,     0,     0,     0,   151,
     150,   152,     0,     0,     0,     0,   157,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    87,     0,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   368,
     293,   294,     0,     0,     0,     0,   369,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   464,   463,   462,     0,     0,   410,   411,   416,
     417,     0,     0,     0,   475,     0,     0,     0,     0,     0,
     515,     0,     0,     0,   535,   522,   524,   525,   387,   387,
     497,     0,     0,    59,    61,     0,   198,   199,   195,   201,
       0,     0,    90,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   203,     0,     0,     0,     0,   180,   181,
       0,   418,   348,   349,   351,   352,   353,   362,   363,     0,
     364,   274,   275,   247,     0,     0,   302,   305,   315,   210,
     211,     0,   213,   318,   319,     0,   215,   324,   227,     0,
       0,   325,     0,   327,   242,   234,     0,     0,   253,     0,
     356,   243,     0,   358,   245,   270,     0,   566,   568,   447,
     450,   441,   490,   556,     0,   555,     0,     0,     0,     0,
       0,     0,   547,     0,     0,     0,     0,   382,   384,    72,
       0,    97,     0,     0,     0,   103,   106,     0,   101,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   134,     0,   135,     0,     0,     0,     0,
     139,     0,   145,   146,     0,   154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,   421,   422,     0,
     419,     0,     0,   370,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   436,    16,   182,     0,   488,   560,     0,
     557,     0,     0,     0,   527,     0,   537,     0,     0,   526,
     500,   502,   498,     0,   120,    82,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   158,   159,   190,   191,     0,   189,   179,     0,
       0,     0,   396,   365,     0,   212,   216,   228,   326,   328,
     332,   252,   355,   357,     0,   427,   448,     9,   494,    16,
     476,     0,     0,     0,   520,   539,     0,   547,   529,     0,
     547,     0,   536,    95,   110,     0,     0,   107,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,     0,     0,   140,     0,     0,     0,     0,     0,     0,
     423,   424,   420,    16,     0,   437,    16,   495,   491,   489,
       0,     0,     0,     0,   547,     0,     0,   547,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   116,   118,     0,
       0,   127,   122,     0,     0,     0,     0,     0,   149,     0,
       0,   156,   188,     9,   248,   428,    16,   483,   480,   481,
     482,   478,   479,   477,     0,   561,     0,   558,     0,     0,
     528,     0,     0,   538,     0,   109,   100,     0,   111,   105,
       0,   131,   136,     0,     0,     0,   147,     0,     0,   399,
     398,   397,     0,   492,     0,     0,   540,     0,   541,   530,
       0,   531,     0,   123,     0,   141,     0,   153,   155,   431,
     433,   434,   435,   430,   432,   438,   490,   562,   559,     0,
     547,     0,   547,   108,     0,     0,   439,   429,   493,   543,
       0,   533,     0,   132,   143,   547,   542,   547,   532,     0,
       0,     0,   133,   544,   534
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1300, -1300, -1300,  -222, -1300, -1300,  1485,   573, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300,  1439,  -178, -1300, -1300,  -316,
      -3, -1300,  1440,  1293, -1300, -1300,  1098,  -395,  2326, -1300,
     944,   -31,   -12, -1300,     1,     7,    35, -1300, -1300,   699,
    1490, -1300, -1300, -1300, -1300, -1300, -1300, -1300,   702, -1300,
     704, -1300,    32, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300,   303, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,  -131,
   -1300, -1300, -1300, -1049, -1300, -1300, -1300,   958, -1300, -1300,
     449,   937, -1300, -1300, -1300, -1300, -1300, -1300, -1300, -1300,
   -1300, -1300, -1300, -1300, -1300, -1299, -1300,   -28, -1300, -1300
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,    89,    90,   375,   918,    91,    92,   236,   237,
     791,   792,   253,   570,    93,    94,   573,    95,    96,   636,
     208,   209,    97,   290,   767,   766,   668,   669,   291,   211,
     271,   212,   231,   258,   213,   214,   239,   240,   524,   525,
     100,   652,  1150,  1533,  1611,   924,   101,   516,   517,   520,
     521,  1399,  1400,   102,   226,  1029,  1536,  1612,  1635,  1485,
    1647,   103,   245,   801,   528,  1044,  1414,  1203,  1415,   104,
     246,   808,   105,   227,   783,  1194,   106,   228,   790,   107,
     530,  1045,  1332,  1540,  1583,   108,   531,  1048,  1490,  1417,
    1576,  1636,  1538,  1066,  1346,  1067,   266,   267,   273,   540,
     816,   545,  1061,  1062,  1343,  1497,  1547,  1642,  1657,  1342,
    1500,  1544,  1640,  1655,   546,   826,   252,   280,  1033,  1035
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     216,   671,    98,   232,   233,   218,   509,   535,    99,   272,
     536,   219,  1215,  1216,   822,   284,   285,   823,   238,   500,
     248,   242,   249,   250,   529,   351,   571,   222,   561,   274,
     254,   224,    20,   483,   260,   262,   221,    25,   571,   278,
     756,   109,   494,  1428,   494,   112,   113,   114,   268,   637,
     638,   306,   307,   308,   218,   571,   244,   370,   241,   109,
     219,     7,     8,   112,   113,   114,   836,   348,   349,   350,
     541,  1192,   542,   543,   483,   352,  1326,   492,   493,   494,
     243,   911,   369,   371,   372,   373,  1609,   476,   477,   478,
     479,   480,   481,   482,   286,   287,   784,   483,   785,  1193,
     786,   288,     7,     8,   948,  1610,   485,   486,   256,   257,
     376,   377,   297,   487,   488,   489,   490,   491,   492,   493,
     494,   309,   378,   787,   289,   302,   788,   485,   486,   579,
     580,   789,   581,   364,   487,   488,   489,   490,   491,   492,
     493,   494,   298,   299,   300,   483,   595,   596,   365,   301,
     985,   750,   986,   752,   603,   483,  1484,    53,   483,   608,
    1006,   374,  1007,  1013,   613,  1014,   615,   476,   477,   478,
     479,   480,   481,   482,  1019,   802,  1020,   803,   627,   804,
     629,   630,   223,   632,   633,   634,   225,   366,   495,   496,
     497,   498,   497,   498,   251,   483,   264,   265,  1546,   483,
     619,  1549,   805,   483,   474,   806,   485,   486,   620,  1022,
     807,  1023,   499,   487,   488,   489,   490,   491,   492,   493,
     494,   505,    80,    81,    82,   495,   496,   497,   498,    98,
     367,   229,   379,   537,   230,    99,   368,   522,   555,   556,
     824,   483,   526,   572,   544,  1588,   483,    98,  1591,   538,
     483,   621,   483,    99,  1319,   572,  1320,  1051,   504,  1052,
     506,   269,   270,    80,    81,    82,   495,   496,   497,   498,
     483,   483,   572,   559,   483,  1213,  1289,  1214,  1290,   269,
     270,   971,   393,   394,   565,   566,   567,   495,   496,   497,
     498,   483,   574,   483,  1429,   380,  1305,  1432,  1306,   381,
     975,   476,   477,   478,   479,   480,   481,   482,  1322,   810,
    1323,   223,   483,   483,   225,   589,   590,  1310,  1312,  1311,
    1313,   483,   382,   597,   483,   599,   642,   601,   602,   644,
     604,   605,   606,   607,   510,   511,   610,   611,   612,   483,
     614,  1650,   616,  1652,   618,  1471,   983,  1472,   622,   623,
     624,   625,   626,   383,   628,   483,  1660,   631,  1661,   384,
    1337,   399,   756,   663,   664,   641,   495,   496,   497,   498,
     490,   491,   492,   493,   494,   385,   483,   651,   387,  1502,
     493,   494,   483,   988,   483,   688,   844,  1584,   662,  1585,
     665,   989,   514,   515,   388,   483,   674,   675,   676,   677,
     852,   483,   990,   389,   483,   857,  1617,   859,  1618,   861,
     862,   991,   483,   518,   519,   866,   867,   653,   654,   992,
     699,   700,   701,   702,   703,   736,   483,   706,   666,   667,
     711,   390,   713,   993,   715,   716,   718,   720,   722,   724,
     725,   726,   727,   391,   729,   730,   731,   732,   733,   734,
     735,   737,   817,   818,   740,   483,   742,   743,   744,   745,
     746,   483,   756,   749,   392,   751,   645,   753,   754,   755,
     920,   921,   395,   758,   759,   760,   761,   762,   763,   764,
     765,   396,   476,   477,   478,   479,   480,   481,   482,   483,
     738,   739,   483,   397,   945,   483,   994,  1590,   111,   995,
    1593,   483,   996,   115,   829,   830,   845,   476,   477,   478,
     479,   480,   481,   482,   512,   513,   839,   840,   483,   398,
     495,   496,   497,   498,   117,  1001,   272,   495,   496,   497,
     498,   813,    98,   483,   483,   400,   483,   483,    99,  1616,
    1002,  1003,  1619,  1010,  1012,   922,   923,   476,   477,   478,
     479,   480,   481,   482,   401,   483,   483,   485,   486,   842,
     402,  1030,  1025,  1026,   487,   488,   489,   490,   491,   492,
     493,   494,   850,   476,   477,   478,   479,   480,   481,   482,
     109,   403,   827,   828,   112,   113,   114,   833,   834,   483,
     404,   491,   492,   493,   494,   871,  1287,   873,   130,   483,
     131,  1656,   483,  1658,   849,   483,   880,   405,   483,  1308,
     863,  1663,  1664,   406,   888,  1314,   483,   891,   892,   134,
     135,   870,   484,  1186,  1046,  1047,  1188,   476,   477,   478,
     479,   480,   481,   482,  1418,  1419,   483,   483,   483,   912,
     914,   485,   486,   978,  1321,  1324,  1064,  1065,   487,   488,
     489,   490,   491,   492,   493,   494,   483,   407,   157,   158,
     159,   483,   483,  1325,   163,   164,   165,   483,   167,  1335,
     169,   170,   171,   501,  1426,   483,   483,   176,   177,   178,
     179,   180,  1473,  1476,   183,   483,   185,   483,   187,   408,
     483,   189,  1477,   191,  1480,   409,   193,  1482,   410,   195,
     196,   483,   197,   198,   483,   200,   934,   202,   935,   483,
     502,  1483,  1201,  1202,   411,   205,  1494,   495,   496,   497,
     498,  -473,   483,   215,   717,   483,   483,   483,   483,  1637,
     483,   872,  1649,   874,  1004,   876,  1397,  1398,   485,   486,
     495,   496,   497,   498,   412,   487,   488,   489,   490,   491,
     492,   493,   494,  1495,  1496,   413,   414,   487,   488,   489,
     490,   491,   492,   493,   494,  1577,   483,  1578,   483,  1579,
     483,   877,   483,   878,   483,   881,   533,   882,   483,  1032,
    1034,   483,   415,   883,    98,   416,  1257,  1629,   483,  1630,
      99,  1631,  1580,   885,   483,  1581,   522,   417,   418,   887,
    1582,   495,   496,   497,   498,   483,   483,   747,   483,   419,
     889,   893,  1055,   894,  1632,  1056,   483,  1633,  1060,   483,
     483,   895,  1634,  1204,   896,   897,   507,   420,  1036,  1037,
     421,  1039,  1040,   422,   423,   311,   312,   313,   314,   315,
     483,   424,  1082,   483,   425,   899,  1083,   483,   902,   316,
     426,   427,   938,  1089,   483,   317,   318,  1093,   428,   947,
    1096,   319,   320,   321,   322,   323,   429,   483,   430,   431,
     432,  1108,   972,  1111,  1112,  1113,   483,   433,  1116,  1117,
    1118,   973,  1121,   483,   483,   434,  1125,   483,   974,   998,
    1127,  1128,   999,  1130,   435,   485,  1133,   436,   495,   496,
     497,   498,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,  1238,   483,   483,  1241,   483,    98,
    1000,  1015,  1245,  1016,   483,    99,   437,   483,   438,  1017,
     549,  1156,  1018,  1158,   483,  1159,  1537,   483,   439,  1021,
     554,  1140,  1024,   488,  1166,   490,   491,   492,   493,   494,
     483,   483,   483,   485,   486,  1079,  1084,  1105,   635,   440,
     487,   488,   489,   490,   491,   492,   493,   494,   483,   441,
    1280,   442,   483,  1107,   483,   557,  1175,  1115,   483,  1124,
     483,   782,   443,  1231,   483,  1239,   815,  1294,   483,  1252,
     646,   444,   445,  1255,  1177,  1178,  1179,  1180,   485,   486,
     446,   447,   448,  1181,   449,   487,   488,   489,   490,   491,
     492,   493,   494,   483,   450,   483,  1187,   483,  1256,  1189,
    1259,  1190,  1262,   748,   451,   483,   483,   483,   485,   486,
    1264,  1265,  1267,   494,   452,   487,   488,   489,   490,   491,
     492,   493,   494,   453,   454,   455,    98,   456,  1207,  1226,
    1227,  1209,    99,   485,   486,   495,   496,   497,   498,   457,
     487,   488,   489,   490,   491,   492,   493,   494,   483,   483,
     483,   458,   459,  1295,  1309,  1352,  1228,  1229,   483,   485,
     486,  1232,   460,  1354,   562,  1235,   487,   488,   489,   490,
     491,   492,   493,   494,   461,   495,   496,   497,   498,  1247,
    1248,   462,  1249,   483,  1250,  1221,  1222,  1251,  1366,   780,
     463,  1253,  1254,   495,   496,   497,   498,  1258,   464,  1260,
     483,  1261,   483,  1263,   465,  1367,   563,  1368,   483,  1266,
     466,  1268,  1269,  1369,  1270,  1271,  1272,   485,   486,   467,
     468,  1278,  1279,   469,   487,   488,   489,   490,   491,   492,
     493,   494,   483,   470,   471,   472,   532,  1371,   495,   496,
     497,   498,   483,   483,   483,   483,   483,  1372,  1376,  1378,
    1379,  1384,   483,   483,   483,   483,   483,  1386,  1387,  1388,
    1389,  1390,  1438,  1327,  1328,   534,  1442,   547,   495,   496,
     497,   498,  1486,  1487,   954,   483,   955,   483,   526,   548,
    1395,   575,  1433,   488,   489,   490,   491,   492,   493,   494,
    1340,   552,   483,   495,   496,   497,   498,  1453,   483,   957,
     483,   958,  1349,  1511,   483,  1514,   483,  1350,  1351,  1517,
     483,  1519,   598,  1355,  1356,  1521,  1358,  1359,   483,   495,
     496,   497,   498,  1525,   483,   979,   483,   980,   553,  1526,
     483,  1600,  1373,  1344,  1345,  1604,  1377,   600,   483,   609,
     617,   643,  1382,  1659,  1385,   485,   486,  1539,   781,   793,
     794,   795,   487,   488,   489,   490,   491,   492,   493,   494,
       1,     2,     3,     4,     5,   796,  1401,   797,   798,   799,
     800,   809,  1403,   812,   820,   210,   819,   495,   496,   497,
     498,   821,  1405,  1276,   825,  1277,  1406,   856,   858,   860,
     235,  1573,   864,  1409,  1575,   865,  1411,   906,   907,  1412,
     908,   909,   919,   247,   936,   925,   255,   926,   933,   259,
     261,   263,   937,   939,  1423,   279,   279,   279,   940,  1043,
     941,   942,   943,   944,   303,  1077,   961,  1005,  1008,  1434,
    1435,  1436,  1009,  1059,  1613,   495,   496,   497,   498,  1068,
    1069,  1070,  1078,  1444,  1071,   667,  1447,  1074,  1075,  1450,
    1088,  1102,  1103,  1452,  1110,  1454,  1114,  1120,   279,  1122,
    1132,  1458,  1134,  1459,  1135,  1137,  1462,  1463,  1464,  1465,
    1138,  1467,  1139,   485,   486,  1160,  1161,  1195,  1196,  1208,
     487,   488,   489,   490,   491,   492,   493,   494,  1197,  1198,
    1199,  1200,  1218,   386,  1219,    98,    98,  1220,  1230,  1236,
    1240,    99,    99,  1246,  1273,   495,   496,   497,   498,  1281,
    1503,  1301,  1288,  1302,  1504,  1293,  1330,  1507,  1331,    -9,
    1336,  1341,  1347,  1348,  1391,  1392,  1394,   485,   486,  1416,
    1421,  1427,  1437,  1430,   487,   488,   489,   490,   491,   492,
     493,   494,   485,   486,  1431,  1469,  1489,  1470,  1491,   487,
     488,   489,   490,   491,   492,   493,   494,  1529,  1492,  1499,
    1530,  1531,  -451,  1545,  1548,  1551,  1554,  1646,  1541,   217,
      98,  1146,   304,   305,   670,   220,    99,  1038,  1042,   473,
     475,   837,  1041,  1532,  1329,  1648,  1210,   847,  1556,  1557,
    1558,  1559,   835,  1561,  1562,   503,     0,     0,  1565,     0,
     508,     0,  1568,     0,     0,  1571,  1572,     0,     0,     0,
       0,     0,     0,   523,    98,     0,     0,    98,   527,     0,
      99,     0,  1589,    99,     0,   539,     0,     0,  1595,  1596,
       0,  1598,  1599,   495,   496,   497,   498,     0,     0,     0,
       0,   757,     0,     0,     0,     0,     0,     0,   558,     0,
     560,     0,     0,     0,     0,     0,     0,    98,     0,     0,
       0,  1614,     0,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1623,     0,     0,
       0,  1625,     0,     0,  1627,  1628,     0,   495,   496,   497,
     498,     0,     0,     0,  1639,   910,     0,     0,     0,  1643,
       0,     0,   495,   496,   497,   498,     0,     0,     0,     0,
     929,     0,     0,     0,     0,     0,     0,     0,     0,   485,
     486,  1653,  1654,     0,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,   485,   486,  1662,     0,     0,     0,
     640,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,   650,     0,     0,     0,     0,   655,   656,     0,
     657,   658,   659,   660,   279,   279,     0,     0,     0,     0,
       0,   673,     0,     0,     0,     0,   678,   679,   680,   681,
     682,   683,   684,   685,   686,   687,   279,   689,   690,   691,
     692,   693,   694,   695,   696,   698,     0,     0,     0,     0,
       0,   704,   705,   707,   709,   710,     0,   712,     0,   714,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   728,
       0,     0,     0,     0,     0,     0,   279,     0,     0,     0,
       0,   741,     0,     0,     0,     0,     0,   485,   486,     0,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,     0,     0,     0,     0,
     768,   769,   770,   771,   772,   773,   774,   775,   776,   777,
     778,   779,     0,     0,     0,     0,     0,     0,     0,   495,
     496,   497,   498,     0,   109,   110,   111,   949,   112,   113,
     114,   115,     0,     0,   495,   496,   497,   498,     0,     0,
       0,     0,   950,     0,     0,   811,     0,     0,     0,     0,
     814,   116,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   831,   832,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   843,     0,     0,     0,
       0,   846,     0,     0,   118,   119,   120,   121,   122,   123,
     124,     0,   853,   854,     0,     0,     0,     0,     0,     0,
       0,     0,   125,     0,     0,   126,     0,     0,     0,     0,
     281,     0,     0,     0,     0,     0,     0,     0,   282,     0,
       0,     0,   128,   129,     0,     0,   130,     0,   131,     0,
       0,   283,   890,     0,     0,     0,   132,   495,   496,   497,
     498,     0,     0,   133,     0,   951,     0,   134,   135,     0,
       0,     0,     0,     0,     0,   913,   915,   916,   917,     0,
       0,     0,     0,     0,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,     0,   188,   189,
     190,   191,     0,   192,   193,     0,   194,   195,   196,     0,
     197,   198,   199,   200,   201,   202,   203,     0,     0,     0,
       0,     0,   204,   205,   206,     0,     0,     0,     0,     0,
       0,   207,     0,   277,     0,     0,   485,   486,     0,     0,
       0,     0,     0,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,   485,   486,     0,     0,     0,  1027,
    1028,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1031,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   523,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1050,     0,     0,     0,     0,
       0,  1057,  1058,   485,   486,     0,     0,  1063,     0,     0,
     487,   488,   489,   490,   491,   492,   493,   494,   485,   486,
       0,  1076,     0,     0,     0,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,     0,     0,     0,
       0,  1091,     0,     0,     0,     0,  1097,  1098,  1099,     0,
       0,     0,     0,  1104,     0,  1106,     0,  1109,     0,     0,
       0,     0,     0,     0,     0,     0,  1119,     0,     0,     0,
    1123,     0,     0,     0,     0,     0,     0,     0,  1129,     0,
    1131,     0,     0,     0,     0,  1136,   495,   496,   497,   498,
    1141,  1142,  1143,     0,   952,     0,     0,     0,     0,     0,
       0,     0,  1147,     0,   495,   496,   497,   498,     0,     0,
    1151,  1152,   953,  1153,  1154,  1155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1162,  1163,     0,  1165,
       0,     0,     0,     0,     0,     0,   111,  1167,     0,     0,
    1168,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1169,     0,     0,  1170,  1171,  1172,     0,  1173,
    1174,     0,   117,   495,   496,   497,   498,     0,  1176,     0,
       0,   956,     0,     0,     0,     0,     0,     0,   495,   496,
     497,   498,     0,     0,     0,     0,   959,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1182,     0,  1183,  1184,
    1185,     0,     0,     0,     0,     0,   485,   486,     0,     0,
       0,     0,  1191,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1205,     0,     0,     0,   130,     0,   131,   485,
     486,     0,  1212,     0,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,     0,  1223,  1224,   134,   135,     0,
     279,   279,     0,   294,   296,     0,     0,     0,     0,  1233,
    1234,     0,     0,     0,   310,     0,   324,   325,   327,   329,
     332,   337,   338,   342,   344,   346,     0,     0,     0,     0,
     356,   358,   359,   361,   362,   363,   157,   158,   159,     0,
       0,     0,   163,   164,   165,     0,   167,     0,   169,   170,
     171,     0,     0,     0,     0,   176,   177,   178,   179,   180,
       0,     0,   183,     0,   185,     0,   187,     0,     0,   189,
       0,   191,     0,     0,   193,     0,     0,   195,   196,     0,
     197,   198,     0,   200,     0,   202,     0,     0,     0,     0,
       0,     0,     0,   205,     0,     0,     0,     0,     0,     0,
       0,   215,   719,     0,     0,     0,   495,   496,   497,   498,
       0,     0,     0,     0,   960,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   527,     0,     0,     0,     0,  1334,
       0,     0,     0,     0,  1338,     0,     0,     0,     0,   495,
     496,   497,   498,     0,   485,   486,     0,   962,     0,     0,
       0,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,     0,     0,  1361,  1362,  1363,     0,  1365,
       0,     0,     0,     0,     0,  1370,     0,     0,     0,  1374,
    1375,     0,     0,   485,   486,  1380,     0,  1381,  1383,     0,
     487,   488,   489,   490,   491,   492,   493,   494,     0,  1393,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1402,     0,     0,
       0,     0,     0,     0,  1404,     0,     0,     0,     0,     0,
       0,     0,     0,  1407,     0,  1408,     0,     0,     0,     0,
    1410,     0,   564,     0,     0,     0,     0,     0,   569,  1413,
       0,     0,     0,     0,     0,   576,   578,     0,     0,  1422,
       0,     0,  1425,     0,     0,     0,     0,   582,   583,   584,
     585,   586,   587,   588,   485,   486,   591,   592,   593,   594,
       0,   487,   488,   489,   490,   491,   492,   493,   494,     0,
    1445,  1446,     0,     0,  1449,     0,     0,     0,     0,     0,
       0,     0,  1455,     0,   495,   496,   497,   498,     0,     0,
    1460,  1461,   963,     0,     0,     0,     0,     0,  1468,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   647,   648,   649,     0,     0,     0,     0,  1488,
       0,     0,     0,   495,   496,   497,   498,     0,     0,     0,
    1501,   964,     0,   672,     0,     0,     0,     0,     0,     0,
       0,     0,  1506,     0,  1508,     0,  1510,     0,     0,     0,
       0,  1515,     0,     0,  1518,     0,  1520,     0,     0,  1523,
    1524,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1534,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1535,     0,     0,
       0,     0,     0,     0,     0,  1542,  1543,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   495,   496,   497,   498,     0,     0,
     550,     0,  1564,     0,     0,  1566,     0,     0,     0,  1569,
    1570,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1592,     0,  1594,     0,     0,  1597,     0,     0,     0,
       0,     0,     0,  1601,   485,   486,  1602,     0,     0,     0,
    1606,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1615,
       0,     0,     0,   109,   110,   111,     0,   112,   113,   114,
     115,     0,     0,     0,     0,     0,  1624,     0,  1626,   848,
       0,     0,     0,   851,     0,     0,     0,   855,     0,     0,
     116,   117,     0,  1641,     0,     0,     0,     0,     0,     0,
       0,   868,   869,     0,     0,     0,     0,     0,     0,   875,
       0,     0,     0,     0,   879,     0,     0,     0,     0,   884,
       0,   886,     0,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,   898,     0,   900,   901,     0,   903,   904,
     905,   125,     0,     0,   126,     0,     0,     0,     0,   275,
       0,     0,     0,     0,     0,     0,     0,   276,     0,     0,
       0,   128,   129,     0,     0,   130,     0,   131,     0,     0,
       0,     0,     0,     0,     0,   132,     0,     0,     0,     0,
       0,     0,   133,     0,     0,     0,   134,   135,     0,     0,
       0,     0,     0,     0,   495,   496,   497,   498,     0,     0,
       0,     0,   965,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,   188,   189,   190,
     191,     0,   192,   193,     0,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,     0,     0,     0,     0,
       0,   204,   205,   206,     0,     0,   485,   486,     0,     0,
     207,     0,   277,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,   111,     0,
     112,   113,   114,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,   117,     0,     0,     0,     0,     0,
    1081,     0,     0,     0,     0,     0,     0,     0,  1085,     0,
       0,     0,     0,  1090,     0,  1092,     0,  1094,  1095,     0,
       0,     0,  1100,  1101,     0,     0,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,     0,   126,     0,     0,
       0,     0,   127,     0,     0,     0,     0,     0,     0,     0,
     661,     0,     0,     0,   128,   129,     0,     0,   130,     0,
     131,     0,     0,     0,     0,     0,  1148,  1149,   132,     0,
       0,     0,     0,     0,     0,   133,     0,     0,     0,   134,
     135,     0,     0,     0,     0,     0,   495,   496,   497,   498,
       0,  1164,     0,     0,   966,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,   191,     0,   192,   193,     0,   194,   195,
     196,     0,   197,   198,   199,   200,   201,   202,   203,     0,
       0,     0,     0,     0,   204,   205,   206,     0,     0,     0,
       0,     0,     0,   207,     0,   277,   109,   110,   111,     0,
     112,   113,   114,   115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,     0,   126,   485,   486,
       0,     0,   127,     0,     0,   487,   488,   489,   490,   491,
     492,   493,   494,     0,   128,   129,     0,     0,   130,     0,
     131,     0,     0,     0,     0,     0,     0,     0,   132,     0,
       0,     0,     0,     0,     0,   133,   485,   486,     0,   134,
     135,     0,     0,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,   191,  1357,   192,   193,  1360,   194,   195,
     196,  1364,   197,   198,   199,   200,   201,   202,   203,     0,
       0,     0,     0,     0,   204,   205,   206,     0,     0,     0,
       0,     0,     0,   207,     0,   277,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1396,     0,   495,   496,
     497,   498,     0,     0,     0,     0,   967,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,   110,
     111,     0,   112,   113,   114,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   495,   496,   497,   498,
       0,     0,     0,     0,   968,   116,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,   119,
     120,   121,   122,   123,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,     0,     0,   126,
     485,   486,     0,     0,   127,     0,     0,   487,   488,   489,
     490,   491,   492,   493,   494,     0,   128,   129,     0,     0,
     130,     0,   131,     0,     0,     0,     0,     0,     0,     0,
     132,     0,     0,     0,     0,     0,     0,   133,   485,   486,
       0,   134,   135,     0,     0,   487,   488,   489,   490,   491,
     492,   493,   494,     0,  1505,     0,     0,     0,  1509,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,     0,   188,   189,   190,   191,     0,   192,   193,     0,
     194,   195,   196,     0,   197,   198,   199,   200,   201,   202,
     203,     0,     0,     0,     0,     0,   204,   205,   206,     0,
       0,     0,     0,     0,     0,   207,   639,   109,   110,   111,
       0,   112,   113,   114,   115,     0,     0,     0,     0,     0,
     495,   496,   497,   498,     0,     0,     0,     0,   970,     0,
       0,     0,     0,     0,   116,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   496,
     497,   498,     0,     0,     0,     0,   981,   118,   119,   120,
     121,   122,   123,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,     0,     0,   126,   485,
     486,     0,     0,   127,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,     0,   128,   129,     0,     0,   130,
       0,   131,     0,     0,     0,     0,     0,     0,     0,   132,
       0,     0,     0,     0,     0,     0,   133,   485,   486,     0,
     134,   135,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
       0,   188,   189,   190,   191,     0,   192,   193,     0,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
       0,     0,     0,     0,     0,   204,   205,   206,     0,     0,
       0,     0,     0,     0,   207,   697,   109,   110,   111,     0,
     112,   113,   114,   115,     0,     0,     0,     0,     0,   495,
     496,   497,   498,     0,     0,     0,     0,   982,     0,     0,
       0,     0,     0,   116,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,     0,     0,     0,     0,   984,   118,   119,   120,   121,
     122,   123,   124,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   125,     0,     0,   126,   485,   486,
       0,     0,   127,     0,     0,   487,   488,   489,   490,   491,
     492,   493,   494,     0,   128,   129,     0,     0,   130,     0,
     131,     0,     0,     0,     0,     0,     0,     0,   132,     0,
       0,     0,     0,     0,     0,   133,   485,   486,     0,   134,
     135,     0,     0,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,     0,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,     0,
     188,   189,   190,   191,     0,   192,   193,     0,   194,   195,
     196,     0,   197,   198,   199,   200,   201,   202,   203,     0,
       0,     0,     0,     0,   204,   205,   206,     0,     0,     0,
       0,     0,     0,   207,   708,   109,   110,   111,     0,   112,
     113,   114,   115,     0,     0,     0,     0,     0,   495,   496,
     497,   498,     0,     0,     0,     0,   987,     0,     0,     0,
       0,     0,   116,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   495,   496,   497,   498,
       0,     0,     0,   333,  1011,   118,   119,   120,   121,   122,
     123,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,   126,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,   334,     0,     0,
       0,     0,     0,   128,   129,     0,     0,   130,     0,   131,
       0,     0,     0,   335,     0,     0,     0,   132,     0,     0,
       0,     0,     0,     0,   133,     0,     0,     0,   134,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   336,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     0,   188,
     189,   190,   191,     0,   192,   193,     0,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,     0,     0,
       0,     0,     0,   204,   205,   206,     0,     0,     0,   109,
     110,   111,   207,   112,   113,   114,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   339,     0,
       0,     0,     0,     0,     0,     0,   116,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   340,     0,   118,
     119,   120,   121,   122,   123,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,     0,     0,
     126,   485,   486,     0,     0,   127,     0,     0,   487,   488,
     489,   490,   491,   492,   493,   494,     0,   128,   129,     0,
       0,   130,     0,   131,     0,     0,     0,   341,     0,     0,
       0,   132,     0,     0,     0,     0,     0,     0,   133,   485,
     486,     0,   134,   135,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,   190,   191,     0,   192,   193,
       0,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,     0,     0,     0,     0,     0,   204,   205,   206,
       0,     0,     0,   109,   110,   111,   207,   112,   113,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   495,   496,   497,   498,     0,     0,     0,     0,  1053,
     116,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   495,
     496,   497,   498,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,     0,     0,   126,   485,   486,     0,     0,   127,
       0,     0,   487,   488,   489,   490,   491,   492,   493,   494,
       0,   128,   129,     0,     0,   130,     0,   131,     0,     0,
       0,   353,     0,     0,     0,   132,     0,     0,     0,     0,
       0,     0,   133,     0,     0,     0,   134,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   354,   355,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,   188,   189,   190,
     191,     0,   192,   193,     0,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,     0,     0,     0,     0,
       0,   204,   205,   206,     0,     0,     0,   109,   110,   111,
     207,   112,   113,   114,   115,     0,   292,     0,     0,     0,
       0,     0,     0,     0,     0,   495,   496,   497,   498,     0,
       0,     0,     0,  1217,   116,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,     0,     0,   126,   485,
     486,     0,     0,   127,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,     0,   128,   129,     0,     0,   130,
       0,   131,     0,     0,     0,     0,     0,     0,     0,   132,
       0,     0,     0,     0,     0,     0,   133,     0,     0,     0,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
       0,   188,   189,   190,   191,     0,   192,   193,     0,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
       0,     0,     0,     0,     0,   204,   205,   206,     0,     0,
       0,   109,   110,   111,   207,   112,   113,   114,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   495,
     496,   497,   498,     0,     0,     0,     0,  1274,   116,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
       0,     0,   126,     0,     0,     0,     0,   127,     0,     0,
       0,     0,     0,   330,     0,     0,     0,     0,     0,   128,
     129,     0,     0,   130,     0,   131,     0,     0,     0,   331,
       0,     0,     0,   132,     0,     0,     0,     0,     0,     0,
     133,     0,     0,     0,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,   188,   189,   190,   191,     0,
     192,   193,     0,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,     0,     0,     0,     0,     0,   204,
     205,   206,     0,     0,     0,   109,   110,   111,   207,   112,
     113,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   116,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,   126,   485,   486,     0,
       0,   127,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,     0,   128,   129,     0,     0,   130,     0,   131,
       0,     0,     0,     0,   393,   394,     0,   132,     0,     0,
       0,     0,     0,     0,   133,     0,     0,     0,   134,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     0,   188,
     189,   190,   191,     0,   192,   193,     0,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,     0,     0,
       0,     0,     0,   204,   205,   206,     0,     0,     0,   109,
     110,   111,   207,   112,   113,   114,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,     0,     0,     0,     0,  1275,   116,   117,     0,     0,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,     0,     0,
     126,   485,   486,     0,     0,   127,     0,     0,   487,   488,
     489,   490,   491,   492,   493,   494,     0,   128,   129,     0,
       0,   130,     0,   131,     0,     0,     0,     0,     0,     0,
       0,   132,     0,     0,     0,     0,     0,     0,   133,     0,
       0,     0,   134,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,   190,   191,     0,   192,   193,
       0,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,     0,     0,     0,     0,     0,   204,   205,   206,
       0,     0,     0,   109,   110,   111,   207,   112,   113,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   495,   496,   497,   498,     0,     0,     0,     0,  1282,
     116,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,     0,     0,   126,   485,   486,     0,     0,   127,
       0,     0,   487,   488,   489,   490,   491,   492,   493,   494,
       0,   128,   129,     0,     0,   130,     0,   131,     0,     0,
       0,   295,     0,     0,     0,   132,     0,     0,     0,     0,
       0,     0,   133,     0,     0,     0,   134,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,   188,   189,   190,
     191,     0,   192,   193,     0,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,     0,     0,     0,     0,
       0,   204,   205,   206,     0,     0,     0,   109,   110,   111,
     207,   112,   113,   114,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   495,   496,   497,   498,     0,
       0,     0,     0,  1283,   116,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,     0,     0,   126,   485,
     486,     0,     0,   127,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,     0,   128,   129,     0,     0,   130,
       0,   131,     0,     0,     0,   326,     0,     0,     0,   132,
       0,     0,     0,     0,     0,     0,   133,     0,     0,     0,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
       0,   188,   189,   190,   191,     0,   192,   193,     0,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
       0,     0,     0,     0,     0,   204,   205,   206,     0,     0,
       0,   109,   110,   111,   207,   112,   113,   114,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   495,
     496,   497,   498,     0,     0,     0,     0,  1284,   116,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
       0,     0,   126,   485,   486,     0,     0,   127,     0,     0,
     487,   488,   489,   490,   491,   492,   493,   494,     0,   128,
     129,     0,     0,   130,     0,   131,     0,     0,     0,   328,
       0,     0,     0,   132,     0,     0,     0,     0,     0,     0,
     133,     0,     0,     0,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,   188,   189,   190,   191,     0,
     192,   193,     0,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,     0,     0,     0,     0,     0,   204,
     205,   206,     0,     0,     0,   109,   110,   111,   207,   112,
     113,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,   496,   497,   498,     0,     0,     0,
       0,  1285,   116,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,   126,   485,   486,     0,
       0,   127,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,     0,   128,   129,     0,     0,   130,     0,   131,
       0,     0,     0,   343,     0,     0,     0,   132,     0,     0,
       0,     0,     0,     0,   133,     0,     0,     0,   134,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     0,   188,
     189,   190,   191,     0,   192,   193,     0,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,     0,     0,
       0,     0,     0,   204,   205,   206,     0,     0,     0,   109,
     110,   111,   207,   112,   113,   114,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,     0,     0,     0,     0,  1286,   116,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,   120,   121,   122,   123,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   125,     0,     0,
     126,   485,   486,     0,     0,   127,     0,     0,   487,   488,
     489,   490,   491,   492,   493,   494,     0,   128,   129,     0,
       0,   130,     0,   131,     0,     0,     0,   345,     0,     0,
       0,   132,     0,     0,     0,     0,     0,     0,   133,     0,
       0,     0,   134,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,     0,   188,   189,   190,   191,     0,   192,   193,
       0,   194,   195,   196,     0,   197,   198,   199,   200,   201,
     202,   203,     0,     0,     0,     0,     0,   204,   205,   206,
       0,     0,     0,   109,   110,   111,   207,   112,   113,   114,
     115,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   495,   496,   497,   498,     0,     0,     0,     0,  1291,
     116,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   118,   119,   120,   121,   122,   123,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,     0,     0,   126,   485,   486,     0,     0,   127,
       0,     0,   487,   488,   489,   490,   491,   492,   493,   494,
       0,   128,   129,     0,     0,   130,     0,   131,     0,     0,
       0,   357,     0,     0,     0,   132,     0,     0,     0,     0,
       0,     0,   133,     0,     0,     0,   134,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,     0,   188,   189,   190,
     191,     0,   192,   193,     0,   194,   195,   196,     0,   197,
     198,   199,   200,   201,   202,   203,     0,     0,     0,     0,
       0,   204,   205,   206,     0,     0,     0,   109,   110,   111,
     207,   112,   113,   114,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   495,   496,   497,   498,     0,
       0,     0,     0,  1292,   116,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   118,   119,   120,
     121,   122,   123,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,     0,     0,   126,   485,
     486,     0,     0,   127,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,     0,   128,   129,     0,     0,   130,
       0,   131,     0,     0,     0,   360,     0,     0,     0,   132,
       0,     0,     0,     0,     0,     0,   133,     0,     0,     0,
     134,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
       0,   188,   189,   190,   191,     0,   192,   193,     0,   194,
     195,   196,     0,   197,   198,   199,   200,   201,   202,   203,
       0,     0,     0,     0,     0,   204,   205,   206,     0,     0,
       0,   109,   110,   111,   207,   112,   113,   114,   115,     0,
     577,     0,     0,     0,     0,     0,     0,     0,     0,   495,
     496,   497,   498,     0,     0,     0,     0,  1296,   116,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   118,   119,   120,   121,   122,   123,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
       0,     0,   126,   485,   486,     0,     0,   127,     0,     0,
     487,   488,   489,   490,   491,   492,   493,   494,     0,   128,
     129,     0,     0,   130,     0,   131,     0,     0,     0,     0,
       0,     0,     0,   132,     0,     0,     0,     0,     0,     0,
     133,     0,     0,     0,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,     0,   188,   189,   190,   191,     0,
     192,   193,     0,   194,   195,   196,     0,   197,   198,   199,
     200,   201,   202,   203,     0,     0,     0,     0,     0,   204,
     205,   206,     0,     0,     0,   109,   110,   111,   207,   112,
     113,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,   496,   497,   498,     0,     0,     0,
       0,  1297,   116,   117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,   126,   485,   486,     0,
       0,   127,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,     0,   128,   129,     0,     0,   130,     0,   131,
       0,     0,     0,     0,     0,     0,     0,   132,   111,     0,
       0,     0,     0,   115,   133,     0,     0,     0,   134,   135,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,     0,   188,
     189,   190,   191,     0,   192,   193,     0,   194,   195,   196,
       0,   197,   198,   199,   200,   201,   202,   203,   130,     0,
     131,     0,     0,   204,   205,   206,   111,     0,     0,     0,
       0,   115,   207,     0,     0,     0,     0,     0,     0,   134,
     135,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,     0,   117,     0,     0,  1298,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   158,
     159,     0,     0,     0,   163,   164,   165,     0,   167,     0,
     169,   170,   171,     0,     0,     0,     0,   176,   177,   178,
     179,   180,     0,     0,   183,     0,   185,     0,   187,     0,
       0,   189,     0,   191,     0,     0,   193,     0,     0,   195,
     196,     0,   197,   198,     0,   200,   130,   202,   131,     0,
       0,     0,   111,     0,     0,   205,     0,   115,     0,     0,
       0,     0,     0,   215,   721,     0,     0,   134,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   159,     0,
       0,     0,   163,   164,   165,     0,   167,     0,   169,   170,
     171,     0,     0,     0,     0,   176,   177,   178,   179,   180,
       0,     0,   183,     0,   185,     0,   187,     0,     0,   189,
       0,   191,     0,     0,   193,     0,     0,   195,   196,     0,
     197,   198,   130,   200,   131,   202,     0,     0,   347,     0,
     111,     0,     0,   205,     0,   115,     0,     0,     0,     0,
       0,   215,   723,   134,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,     0,     0,     0,   163,   164,
     165,     0,   167,     0,   169,   170,   171,     0,     0,     0,
       0,   176,   177,   178,   179,   180,     0,     0,   183,     0,
     185,     0,   187,     0,     0,   189,     0,   191,     0,     0,
     193,     0,   841,   195,   196,     0,   197,   198,     0,   200,
     130,   202,   131,     0,     0,     0,     0,     0,   111,   205,
       0,     0,     0,   115,     0,     0,     0,   215,     0,     0,
       0,   134,   135,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     157,   158,   159,     0,     0,     0,   163,   164,   165,     0,
     167,     0,   169,   170,   171,     0,     0,     0,     0,   176,
     177,   178,   179,   180,     0,     0,   183,     0,   185,     0,
     187,     0,     0,   189,     0,   191,     0,     0,   193,     0,
    1157,   195,   196,     0,   197,   198,     0,   200,   130,   202,
     131,     0,     0,     0,   111,     0,     0,   205,     0,   115,
       0,     0,     0,     0,     0,   215,     0,     0,     0,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   157,   158,
     159,     0,     0,     0,   163,   164,   165,     0,   167,     0,
     169,   170,   171,     0,     0,     0,     0,   176,   177,   178,
     179,   180,     0,     0,   183,     0,   185,     0,   187,     0,
       0,   189,     0,   191,     0,     0,   193,     0,     0,   195,
     196,     0,   197,   198,   130,   200,   131,   202,     0,     0,
       0,     0,   111,     0,     0,   205,     0,   115,     0,     0,
       0,     0,     0,   215,     0,   134,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   158,   159,     0,     0,     0,
     163,   164,   165,     0,   167,     0,   169,   170,   171,     0,
       0,     0,     0,   176,   177,   178,   179,   180,     0,     0,
     183,     0,   185,     0,   187,     0,     0,   189,     0,   191,
       0,     0,   193,     0,     0,   195,   196,     0,   197,   198,
       0,   200,   130,   202,   131,     0,     0,     0,     0,     0,
       0,   205,     0,     0,     0,     0,     0,     0,     0,   215,
     485,   486,     0,   134,   135,     0,     0,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   157,   158,   159,     0,     0,     0,   163,   164,
     165,     0,   167,     0,   169,   170,   171,     0,     0,     0,
       0,   176,   177,   178,   179,   180,     0,     0,   183,     0,
     185,     0,   187,     0,     0,   189,     0,   191,     0,     0,
     193,     0,     0,   195,   196,     0,   197,   198,     0,   200,
       0,   202,     0,     7,     8,     9,     0,     0,     0,   205,
      10,     0,     0,     0,    11,     0,    12,  1054,    13,    14,
      15,    16,    17,  -402,     0,    18,    19,    20,    21,    22,
      23,    24,    25,     0,    26,    27,    28,     0,     0,     0,
       0,    29,     0,     0,    30,     0,     0,     0,     0,     0,
       0,    31,    32,    33,    34,    35,    36,     0,     0,     0,
      37,    38,     0,     0,     0,     0,     0,     0,     0,     0,
     495,   496,   497,   498,     0,     0,   551,    39,    40,    41,
      42,    43,    44,     0,     0,     0,     0,     0,    45,    46,
      47,  -182,  -182,    48,    49,    50,     0,    51,    52,    53,
       0,     0,    54,  -182,     0,    55,     0,    56,    57,     0,
       0,     0,     0,    58,    59,     0,     0,     0,     0,     0,
      60,     0,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,   485,   486,     0,     0,     0,     0,     0,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,     0,     0,    80,    81,    82,     0,     0,     0,
       0,    83,     0,     0,     0,   485,   486,     0,     0,     0,
       0,     0,   487,   488,   489,   490,   491,   492,   493,   494,
       0,    84,     0,     0,     0,    85,     0,     7,     8,     9,
      86,     0,     0,    87,    10,     0,     0,    88,    11,     0,
      12,     0,    13,    14,    15,    16,    17,  -402,     0,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,     0,     0,     0,     0,    29,   -16,   -16,    30,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    37,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,    45,    46,    47,     0,     0,    48,    49,    50,
       0,    51,    52,    53,     0,     0,    54,     0,     0,    55,
       0,    56,    57,   495,   496,   497,   498,    58,    59,     0,
       0,  1299,     0,     0,    60,     0,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,   495,   496,   497,   498,     0,
       0,     0,     0,  1300,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    80,    81,
      82,     0,     0,     0,     0,    83,     0,     0,     0,   485,
     486,     0,     0,     0,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,     0,    84,     0,     0,     0,    85,
       0,     7,     8,     9,    86,     0,     0,    87,    10,     0,
       0,    88,    11,     0,    12,     0,    13,    14,    15,    16,
      17,  -402,     0,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,   -16,     0,     0,     0,    29,
     -16,     0,    30,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,    35,    36,   485,   486,     0,    37,    38,
       0,     0,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
      44,     0,     0,     0,     0,     0,    45,    46,    47,     0,
       0,    48,    49,    50,     0,    51,    52,    53,     0,     0,
      54,     0,     0,    55,     0,    56,    57,     0,     0,     0,
       0,    58,    59,     0,     0,     0,     0,     0,    60,     0,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,   495,
     496,   497,   498,   485,   486,     0,     0,  1303,     0,     0,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,    80,    81,    82,   485,   486,     0,     0,    83,
       0,     0,   487,   488,   489,   490,   491,   492,   493,   494,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    84,
       0,     0,     0,    85,     0,     0,     0,     0,    86,   485,
     486,    87,     0,     0,     0,    88,   487,   488,   489,   490,
     491,   492,   493,   494,     0,   495,   496,   497,   498,   485,
     486,     0,     0,  1304,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,   485,   486,     0,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,   493,   494,   485,
     486,     0,     0,     0,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,   485,   486,     0,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,   493,   494,   485,
     486,     0,     0,     0,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,   496,   497,   498,   485,   486,     0,
       0,  1307,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,   495,   496,   497,   498,   485,
     486,     0,     0,  1315,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,   485,   486,     0,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   485,   486,     0,     0,  1318,     0,     0,
     487,   488,   489,   490,   491,   492,   493,   494,     0,   495,
     496,   497,   498,     0,     0,     0,     0,  1333,     0,     0,
       0,     0,     0,     0,   495,   496,   497,   498,     0,     0,
       0,     0,  1420,     0,     0,     0,     0,     0,     0,   495,
     496,   497,   498,     0,     0,     0,     0,  1424,     0,     0,
       0,     0,     0,     0,   495,   496,   497,   498,     0,     0,
       0,     0,  1466,     0,     0,     0,     0,     0,     0,   495,
     496,   497,   498,   485,   486,     0,     0,  1475,     0,     0,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,   485,   486,     0,     0,  1478,     0,     0,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,   495,
     496,   497,   498,     0,     0,     0,     0,  1479,     0,     0,
       0,     0,     0,     0,   495,   496,   497,   498,   485,   486,
       0,     0,  1481,     0,     0,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   485,   486,     0,
       0,  1498,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,   485,   486,     0,     0,     0,     0,     0,   487,
     488,   489,   490,   491,   492,   493,   494,   485,   486,     0,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,   485,   486,     0,     0,     0,     0,     0,   487,
     488,   489,   490,   491,   492,   493,   494,   485,   486,     0,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,     0,   495,   496,   497,   498,   485,   486,     0,
       0,  1574,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   495,   496,   497,   498,   485,   486,     0,     0,  1587,
       0,     0,   487,   488,   489,   490,   491,   492,   493,   494,
     485,   486,     0,     0,     0,     0,     0,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,   495,   496,
     497,   498,   485,   486,     0,     0,  1621,     0,     0,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,     0,     0,     0,     0,  1638,     0,     0,     0,     0,
       0,     0,   495,   496,   497,   498,     0,     0,     0,     0,
    1651,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,     0,     0,   568,     0,     0,     0,     0,     0,     0,
       0,     0,   495,   496,   497,   498,     0,     0,   838,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,   485,   486,   927,     0,     0,     0,     0,   487,   488,
     489,   490,   491,   492,   493,   494,     0,   495,   496,   497,
     498,   485,   486,   928,     0,     0,     0,     0,   487,   488,
     489,   490,   491,   492,   493,   494,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   495,   496,   497,   498,     0,
       0,   930,     0,     0,     0,     0,     0,     0,     0,     0,
     495,   496,   497,   498,   485,   486,   931,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,   495,   496,   497,   498,   485,   486,   932,     0,
       0,     0,     0,   487,   488,   489,   490,   491,   492,   493,
     494,   485,   486,     0,     0,     0,     0,     0,   487,   488,
     489,   490,   491,   492,   493,   494,   485,   486,     0,     0,
       0,     0,     0,   487,   488,   489,   490,   491,   492,   493,
     494,   485,   486,     0,     0,     0,     0,     0,   487,   488,
     489,   490,   491,   492,   493,   494,   485,   486,     0,     0,
       0,     0,     0,   487,   488,   489,   490,   491,   492,   493,
     494,   495,   496,   497,   498,   485,   486,   946,     0,     0,
       0,     0,   487,   488,   489,   490,   491,   492,   493,   494,
       0,   495,   496,   497,   498,   485,   486,   969,     0,     0,
       0,     0,   487,   488,   489,   490,   491,   492,   493,   494,
     485,   486,     0,     0,     0,     0,     0,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   495,   496,   497,   498,   485,   486,
     976,     0,     0,     0,     0,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,   495,   496,   497,   498,
       0,     0,   977,     0,     0,     0,     0,     0,     0,     0,
       0,   495,   496,   497,   498,     0,     0,   997,     0,     0,
       0,     0,     0,     0,     0,     0,   495,   496,   497,   498,
       0,     0,  1049,     0,     0,     0,     0,     0,     0,     0,
       0,   495,   496,   497,   498,     0,     0,  1072,     0,     0,
       0,     0,     0,     0,     0,     0,   495,   496,   497,   498,
     485,   486,  1073,     0,     0,     0,     0,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   485,
     486,  1080,     0,     0,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,     0,   495,   496,   497,   498,     0,
       0,  1086,     0,     0,     0,     0,     0,     0,     0,     0,
     495,   496,   497,   498,   485,   486,  1087,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   496,
     497,   498,   485,   486,  1126,     0,     0,     0,     0,   487,
     488,   489,   490,   491,   492,   493,   494,   485,   486,     0,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,   485,   486,     0,     0,     0,     0,     0,   487,
     488,   489,   490,   491,   492,   493,   494,   485,   486,     0,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,   485,   486,     0,     0,     0,     0,     0,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
     495,   496,   497,   498,   485,   486,  1144,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   485,   486,  1145,     0,     0,     0,     0,
     487,   488,   489,   490,   491,   492,   493,   494,   485,   486,
       0,     0,     0,     0,     0,   487,   488,   489,   490,   491,
     492,   493,   494,     0,   495,   496,   497,   498,   485,   486,
    1206,     0,     0,     0,     0,   487,   488,   489,   490,   491,
     492,   493,   494,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   495,   496,   497,   498,     0,     0,  1211,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,     0,     0,  1225,     0,     0,     0,     0,     0,     0,
       0,     0,   495,   496,   497,   498,     0,     0,  1237,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,     0,     0,  1242,     0,     0,     0,     0,     0,     0,
       0,     0,   495,   496,   497,   498,   485,   486,  1243,     0,
       0,     0,     0,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,   495,   496,   497,   498,   485,   486,
    1244,     0,     0,     0,     0,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,     0,     0,  1316,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   496,
     497,   498,   485,   486,  1317,     0,     0,     0,     0,   487,
     488,   489,   490,   491,   492,   493,   494,     0,   495,   496,
     497,   498,   485,   486,  1339,     0,     0,     0,     0,   487,
     488,   489,   490,   491,   492,   493,   494,   485,   486,     0,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,   485,   486,     0,     0,     0,     0,     0,   487,
     488,   489,   490,   491,   492,   493,   494,   485,   486,     0,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,   485,   486,     0,     0,     0,     0,     0,   487,
     488,   489,   490,   491,   492,   493,   494,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   495,   496,   497,   498,
     485,   486,  1353,     0,     0,     0,     0,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,   495,   496,
     497,   498,   485,   486,  1439,     0,     0,     0,     0,   487,
     488,   489,   490,   491,   492,   493,   494,   485,   486,     0,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   485,   486,  1440,     0,
       0,     0,     0,   487,   488,   489,   490,   491,   492,   493,
     494,     0,   495,   496,   497,   498,     0,     0,  1441,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,     0,     0,  1443,     0,     0,     0,     0,     0,     0,
       0,     0,   495,   496,   497,   498,     0,     0,  1448,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,     0,     0,  1451,     0,     0,     0,     0,     0,     0,
       0,     0,   495,   496,   497,   498,   485,   486,  1456,     0,
       0,     0,     0,   487,   488,   489,   490,   491,   492,   493,
     494,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     495,   496,   497,   498,   485,   486,  1457,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,   495,   496,   497,   498,     0,     0,  1474,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,   485,   486,  1493,     0,     0,     0,     0,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     485,   486,  1512,     0,     0,     0,     0,   487,   488,   489,
     490,   491,   492,   493,   494,   485,   486,     0,     0,     0,
       0,     0,   487,   488,   489,   490,   491,   492,   493,   494,
     485,   486,     0,     0,     0,     0,     0,   487,   488,   489,
     490,   491,   492,   493,   494,   485,   486,     0,     0,     0,
       0,     0,   487,   488,   489,   490,   491,   492,   493,   494,
     485,   486,     0,     0,     0,     0,     0,   487,   488,   489,
     490,   491,   492,   493,   494,     0,   495,   496,   497,   498,
     485,   486,  1513,     0,     0,     0,     0,   487,   488,   489,
     490,   491,   492,   493,   494,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   495,   496,   497,   498,   485,   486,
    1516,     0,     0,     0,     0,   487,   488,   489,   490,   491,
     492,   493,   494,   485,   486,     0,     0,     0,     0,     0,
     487,   488,   489,   490,   491,   492,   493,   494,     0,     0,
       0,   495,   496,   497,   498,   485,   486,  1522,     0,     0,
       0,     0,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,     0,     0,  1527,     0,     0,     0,
       0,     0,     0,     0,     0,   495,   496,   497,   498,     0,
       0,  1528,     0,     0,     0,     0,     0,     0,     0,     0,
     495,   496,   497,   498,     0,     0,  1550,     0,     0,     0,
       0,     0,     0,     0,     0,   495,   496,   497,   498,     0,
       0,  1552,     0,     0,     0,     0,     0,     0,     0,     0,
     495,   496,   497,   498,   485,   486,  1553,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,   493,   494,     0,
     495,   496,   497,   498,   485,   486,  1555,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,   493,   494,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   496,
     497,   498,     0,     0,  1560,     0,     0,     0,     0,     0,
       0,     0,     0,   495,   496,   497,   498,   485,   486,  1563,
       0,     0,     0,     0,   487,   488,   489,   490,   491,   492,
     493,   494,     0,     0,     0,   495,   496,   497,   498,   485,
     486,  1567,     0,     0,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,   485,   486,     0,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,   493,   494,   485,
     486,     0,     0,     0,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,   485,   486,     0,     0,     0,     0,
       0,   487,   488,   489,   490,   491,   492,   493,   494,   485,
     486,     0,     0,     0,     0,     0,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   485,   486,
    1586,     0,     0,     0,     0,   487,   488,   489,   490,   491,
     492,   493,   494,     0,   495,   496,   497,   498,     0,     0,
    1603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,     0,     0,  1605,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   495,
     496,   497,   498,     0,     0,  1607,     0,     0,     0,     0,
       0,     0,     0,     0,   495,   496,   497,   498,     0,     0,
    1608,     0,     0,     0,     0,     0,     0,     0,     0,   495,
     496,   497,   498,     0,     0,  1620,     0,     0,     0,     0,
       0,     0,     0,     0,   495,   496,   497,   498,     0,     0,
    1622,     0,     0,     0,     0,     0,     0,     0,     0,   495,
     496,   497,   498,     0,     0,  1644,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   496,
     497,   498,     0,     0,  1645
};

static const yytype_int16 yycheck[] =
{
       3,   396,     1,    15,    16,     4,   228,     4,     1,    40,
       7,     4,  1061,  1062,     4,    43,    44,     7,    21,    44,
      58,    24,    60,    61,   246,    61,    12,    75,    11,    41,
      33,    75,    28,   224,    37,    38,     0,    33,    12,    42,
     231,     3,    77,  1342,    77,     7,     8,     9,    10,   365,
     366,    54,    55,    56,    53,    12,     7,    85,    23,     3,
      53,     4,     5,     7,     8,     9,    10,    70,    71,    72,
      58,    16,    60,    61,   224,   111,    12,    75,    76,    77,
      28,   231,    85,    86,    87,    88,    25,    70,    71,    72,
      73,    74,    75,    76,    81,    82,    14,   224,    16,    44,
      18,    88,     4,     5,   231,    44,    63,    64,     4,     5,
      92,    93,    59,    70,    71,    72,    73,    74,    75,    76,
      77,   110,   104,    41,   111,    95,    44,    63,    64,   307,
     308,    49,   310,   230,    70,    71,    72,    73,    74,    75,
      76,    77,    89,    90,    91,   224,   324,   325,   230,    96,
     229,   467,   231,   469,   332,   224,    13,   100,   224,   337,
     229,    44,   231,   229,   342,   231,   344,    70,    71,    72,
      73,    74,    75,    76,   229,    14,   231,    16,   356,    18,
     358,   359,   230,   361,   362,   363,   230,   230,   223,   224,
     225,   226,   225,   226,   232,   224,     4,     5,  1497,   224,
     229,  1500,    41,   224,   207,    44,    63,    64,   229,   229,
      49,   231,   215,    70,    71,    72,    73,    74,    75,    76,
      77,   224,   165,   166,   167,   223,   224,   225,   226,   228,
     230,     4,    75,   230,     7,   228,   230,   240,   269,   270,
     230,   224,   245,   229,   232,  1544,   224,   246,  1547,   252,
     224,   229,   224,   246,   229,   229,   231,   229,   223,   231,
     225,   223,   224,   165,   166,   167,   223,   224,   225,   226,
     224,   224,   229,   276,   224,   229,   229,   231,   231,   223,
     224,   231,   112,   113,   287,   288,   289,   223,   224,   225,
     226,   224,   295,   224,  1343,    75,   229,  1346,   231,    24,
     231,    70,    71,    72,    73,    74,    75,    76,   229,   531,
     231,   230,   224,   224,   230,   318,   319,   229,   229,   231,
     231,   224,   230,   326,   224,   328,   229,   330,   331,   229,
     333,   334,   335,   336,    35,    36,   339,   340,   341,   224,
     343,  1640,   345,  1642,   347,   229,   231,   231,   351,   352,
     353,   354,   355,   230,   357,   224,  1655,   360,  1657,   230,
     229,   112,   231,   391,   392,   368,   223,   224,   225,   226,
      73,    74,    75,    76,    77,   230,   224,   380,   230,  1428,
      76,    77,   224,   231,   224,   413,   564,   229,   391,   231,
     393,   231,     4,     5,   230,   224,   399,   400,   401,   402,
     578,   224,   231,   230,   224,   583,   229,   585,   231,   587,
     588,   231,   224,     4,     5,   593,   594,   382,   383,   231,
     423,   424,   425,   426,   427,   453,   224,   430,     4,     5,
     433,   230,   435,   231,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   230,   447,   448,   449,   450,   451,   452,
     453,   454,   228,   229,   457,   224,   459,   460,   461,   462,
     463,   224,   231,   466,   230,   468,   229,   470,   471,   472,
     648,   649,   230,   476,   477,   478,   479,   480,   481,   482,
     483,   230,    70,    71,    72,    73,    74,    75,    76,   224,
     455,   456,   224,   230,   672,   224,   231,  1546,     5,   231,
    1549,   224,   231,    10,     4,     5,   229,    70,    71,    72,
      73,    74,    75,    76,    20,    21,    86,    87,   224,   230,
     223,   224,   225,   226,    31,   231,   557,   223,   224,   225,
     226,   534,   531,   224,   224,   230,   224,   224,   531,  1588,
     231,   231,  1591,   231,   231,     4,     5,    70,    71,    72,
      73,    74,    75,    76,   112,   224,   224,    63,    64,   562,
     112,   783,   231,   231,    70,    71,    72,    73,    74,    75,
      76,    77,   575,    70,    71,    72,    73,    74,    75,    76,
       3,   230,   547,   548,     7,     8,     9,   552,   553,   224,
     230,    74,    75,    76,    77,   598,   231,   600,   105,   224,
     107,  1650,   224,  1652,   229,   224,   609,   230,   224,   231,
     229,  1660,  1661,   230,   617,   231,   224,   620,   621,   126,
     127,   229,    44,  1018,    49,    50,  1021,    70,    71,    72,
      73,    74,    75,    76,    60,    61,   224,   224,   224,   642,
     643,    63,    64,   231,   231,   231,     4,     5,    70,    71,
      72,    73,    74,    75,    76,    77,   224,   230,   165,   166,
     167,   224,   224,   231,   171,   172,   173,   224,   175,   231,
     177,   178,   179,    44,   231,   224,   224,   184,   185,   186,
     187,   188,   231,   231,   191,   224,   193,   224,   195,   230,
     224,   198,   231,   200,   231,   230,   203,   231,   230,   206,
     207,   224,   209,   210,   224,   212,   229,   214,   231,   224,
      44,   231,    39,    40,   230,   222,   231,   223,   224,   225,
     226,    46,   224,   230,   231,   224,   224,   224,   224,   231,
     224,   229,   231,   229,   231,   229,     4,     5,    63,    64,
     223,   224,   225,   226,   230,    70,    71,    72,    73,    74,
      75,    76,    77,    60,    61,   230,   230,    70,    71,    72,
      73,    74,    75,    76,    77,    14,   224,    16,   224,    18,
     224,   229,   224,   229,   224,   229,    58,   229,   224,   791,
     792,   224,   230,   229,   783,   230,   229,    14,   224,    16,
     783,    18,    41,   229,   224,    44,   799,   230,   230,   229,
      49,   223,   224,   225,   226,   224,   224,   231,   224,   230,
     229,   229,   815,   229,    41,   818,   224,    44,   821,   224,
     224,   229,    49,  1045,   229,   229,     4,   230,   793,   794,
     230,   796,   797,   230,   230,    90,    91,    92,    93,    94,
     224,   230,   845,   224,   230,   229,   849,   224,   229,   104,
     230,   230,   229,   856,   224,   110,   111,   860,   230,   229,
     863,   116,   117,   118,   119,   120,   230,   224,   230,   230,
     230,   874,   229,   876,   877,   878,   224,   230,   881,   882,
     883,   229,   885,   224,   224,   230,   889,   224,   229,   229,
     893,   894,   229,   896,   230,    63,   899,   230,   223,   224,
     225,   226,    70,    71,    72,    73,    74,    75,    76,    77,
     223,   224,   225,   226,  1092,   224,   224,  1095,   224,   918,
     229,   229,  1100,   229,   224,   918,   230,   224,   230,   229,
     229,   934,   229,   936,   224,   938,    46,   224,   230,   229,
     229,   906,   229,    71,   947,    73,    74,    75,    76,    77,
     224,   224,   224,    63,    64,   229,   229,   229,     5,   230,
      70,    71,    72,    73,    74,    75,    76,    77,   224,   230,
    1148,   230,   224,   229,   224,   229,   979,   229,   224,   229,
     224,    75,   230,   229,   224,   229,    51,  1165,   224,   229,
      43,   230,   230,   229,   997,   998,   999,  1000,    63,    64,
     230,   230,   230,  1006,   230,    70,    71,    72,    73,    74,
      75,    76,    77,   224,   230,   224,  1019,   224,   229,  1022,
     229,  1024,   229,   231,   230,   224,   224,   224,    63,    64,
     229,   229,   229,    77,   230,    70,    71,    72,    73,    74,
      75,    76,    77,   230,   230,   230,  1045,   230,  1051,  1077,
    1078,  1054,  1045,    63,    64,   223,   224,   225,   226,   230,
      70,    71,    72,    73,    74,    75,    76,    77,   224,   224,
     224,   230,   230,   229,   229,   229,  1079,  1080,   224,    63,
      64,  1084,   230,   229,   229,  1088,    70,    71,    72,    73,
      74,    75,    76,    77,   230,   223,   224,   225,   226,  1102,
    1103,   230,  1105,   224,  1107,  1070,  1071,  1110,   229,   231,
     230,  1114,  1115,   223,   224,   225,   226,  1120,   230,  1122,
     224,  1124,   224,  1126,   230,   229,   229,   229,   224,  1132,
     230,  1134,  1135,   229,  1137,  1138,  1139,    63,    64,   230,
     230,  1144,  1145,   230,    70,    71,    72,    73,    74,    75,
      76,    77,   224,   230,   230,   230,   230,   229,   223,   224,
     225,   226,   224,   224,   224,   224,   224,   229,   229,   229,
     229,   229,   224,   224,   224,   224,   224,   229,   229,   229,
     229,   229,  1360,  1195,  1196,   230,  1364,   230,   223,   224,
     225,   226,  1414,  1415,   229,   224,   231,   224,  1201,   230,
     229,   229,   229,    71,    72,    73,    74,    75,    76,    77,
    1213,   230,   224,   223,   224,   225,   226,   229,   224,   229,
     224,   231,  1225,   229,   224,   229,   224,  1230,  1231,   229,
     224,   229,   229,  1236,  1237,   229,  1239,  1240,   224,   223,
     224,   225,   226,   229,   224,   229,   224,   231,   230,   229,
     224,   229,  1255,  1218,  1219,   229,  1259,   229,   224,   229,
     229,   229,  1265,   229,  1267,    63,    64,  1489,   231,   230,
     230,   229,    70,    71,    72,    73,    74,    75,    76,    77,
     216,   217,   218,   219,   220,   230,  1289,   230,   229,   229,
      43,    46,  1295,   230,    58,     2,   230,   223,   224,   225,
     226,   230,  1305,   229,    10,   231,  1309,   229,   229,   229,
      17,  1533,   229,  1316,  1536,   229,  1319,   230,   229,  1322,
     229,   229,   229,    30,   229,   231,    33,   231,   231,    36,
      37,    38,   231,   230,  1337,    42,    43,    44,   230,    43,
     231,   231,   229,   229,    51,    85,   231,   231,   231,  1352,
    1353,  1354,   231,   230,  1576,   223,   224,   225,   226,   231,
     231,   230,    85,  1366,   230,     5,  1369,   231,   231,  1372,
     229,   229,   229,  1376,   229,  1378,   229,   229,    85,   229,
     229,  1384,   229,  1386,   229,   229,  1389,  1390,  1391,  1392,
     229,  1394,   229,    63,    64,   231,   231,   229,   229,    58,
      70,    71,    72,    73,    74,    75,    76,    77,   231,   231,
     231,   231,   230,   120,   230,  1414,  1415,   229,   229,   229,
     229,  1414,  1415,   229,   231,   223,   224,   225,   226,   230,
    1433,   229,   231,   231,  1437,   231,    43,  1440,    38,    43,
     230,    58,   231,   231,    75,    75,    75,    63,    64,    48,
      58,   230,   229,   231,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,   231,   230,    47,   230,   230,    70,
      71,    72,    73,    74,    75,    76,    77,    75,   230,    58,
     231,   231,    38,   230,   230,   229,   229,     4,  1491,     4,
    1489,   918,    53,    53,   396,     5,  1489,   795,   799,   206,
     207,   557,   798,  1471,  1201,  1636,  1057,   570,  1511,  1512,
    1513,  1514,   554,  1516,  1517,   222,    -1,    -1,  1521,    -1,
     227,    -1,  1525,    -1,    -1,  1528,  1529,    -1,    -1,    -1,
      -1,    -1,    -1,   240,  1533,    -1,    -1,  1536,   245,    -1,
    1533,    -1,  1545,  1536,    -1,   252,    -1,    -1,  1551,  1552,
      -1,  1554,  1555,   223,   224,   225,   226,    -1,    -1,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,
     277,    -1,    -1,    -1,    -1,    -1,    -1,  1576,    -1,    -1,
      -1,  1584,    -1,  1576,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1600,    -1,    -1,
      -1,  1604,    -1,    -1,  1607,  1608,    -1,   223,   224,   225,
     226,    -1,    -1,    -1,  1617,   231,    -1,    -1,    -1,  1622,
      -1,    -1,   223,   224,   225,   226,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,  1644,  1645,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,  1659,    -1,    -1,    -1,
     367,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,   379,    -1,    -1,    -1,    -1,   384,   385,    -1,
     387,   388,   389,   390,   391,   392,    -1,    -1,    -1,    -1,
      -1,   398,    -1,    -1,    -1,    -1,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,    -1,    -1,    -1,    -1,
      -1,   428,   429,   430,   431,   432,    -1,   434,    -1,   436,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   446,
      -1,    -1,    -1,    -1,    -1,    -1,   453,    -1,    -1,    -1,
      -1,   458,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    -1,     3,     4,     5,   231,     7,     8,
       9,    10,    -1,    -1,   223,   224,   225,   226,    -1,    -1,
      -1,    -1,   231,    -1,    -1,   532,    -1,    -1,    -1,    -1,
     537,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   550,   551,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   563,    -1,    -1,    -1,
      -1,   568,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,   579,   580,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,   110,   619,    -1,    -1,    -1,   115,   223,   224,   225,
     226,    -1,    -1,   122,    -1,   231,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,   642,   643,   644,   645,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,    -1,   197,   198,
     199,   200,    -1,   202,   203,    -1,   205,   206,   207,    -1,
     209,   210,   211,   212,   213,   214,   215,    -1,    -1,    -1,
      -1,    -1,   221,   222,   223,    -1,    -1,    -1,    -1,    -1,
      -1,   230,    -1,   232,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,   766,
     767,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   786,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   799,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   812,    -1,    -1,    -1,    -1,
      -1,   818,   819,    63,    64,    -1,    -1,   824,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,   838,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   858,    -1,    -1,    -1,    -1,   863,   864,   865,    -1,
      -1,    -1,    -1,   870,    -1,   872,    -1,   874,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   883,    -1,    -1,    -1,
     887,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   895,    -1,
     897,    -1,    -1,    -1,    -1,   902,   223,   224,   225,   226,
     907,   908,   909,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   919,    -1,   223,   224,   225,   226,    -1,    -1,
     927,   928,   231,   930,   931,   932,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   943,   944,    -1,   946,
      -1,    -1,    -1,    -1,    -1,    -1,     5,   954,    -1,    -1,
     957,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   969,    -1,    -1,   972,   973,   974,    -1,   976,
     977,    -1,    31,   223,   224,   225,   226,    -1,   985,    -1,
      -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,
     225,   226,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1013,    -1,  1015,  1016,
    1017,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,  1029,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1049,    -1,    -1,    -1,   105,    -1,   107,    63,
      64,    -1,  1059,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,  1072,  1073,   126,   127,    -1,
    1077,  1078,    -1,    47,    48,    -1,    -1,    -1,    -1,  1086,
    1087,    -1,    -1,    -1,    58,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,   165,   166,   167,    -1,
      -1,    -1,   171,   172,   173,    -1,   175,    -1,   177,   178,
     179,    -1,    -1,    -1,    -1,   184,   185,   186,   187,   188,
      -1,    -1,   191,    -1,   193,    -1,   195,    -1,    -1,   198,
      -1,   200,    -1,    -1,   203,    -1,    -1,   206,   207,    -1,
     209,   210,    -1,   212,    -1,   214,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   230,   231,    -1,    -1,    -1,   223,   224,   225,   226,
      -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1201,    -1,    -1,    -1,    -1,  1206,
      -1,    -1,    -1,    -1,  1211,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    -1,    63,    64,    -1,   231,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,  1242,  1243,  1244,    -1,  1246,
      -1,    -1,    -1,    -1,    -1,  1252,    -1,    -1,    -1,  1256,
    1257,    -1,    -1,    63,    64,  1262,    -1,  1264,  1265,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,  1276,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1294,    -1,    -1,
      -1,    -1,    -1,    -1,  1301,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1310,    -1,  1312,    -1,    -1,    -1,    -1,
    1317,    -1,   286,    -1,    -1,    -1,    -1,    -1,   292,  1326,
      -1,    -1,    -1,    -1,    -1,   299,   300,    -1,    -1,  1336,
      -1,    -1,  1339,    -1,    -1,    -1,    -1,   311,   312,   313,
     314,   315,   316,   317,    63,    64,   320,   321,   322,   323,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
    1367,  1368,    -1,    -1,  1371,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1379,    -1,   223,   224,   225,   226,    -1,    -1,
    1387,  1388,   231,    -1,    -1,    -1,    -1,    -1,  1395,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   376,   377,   378,    -1,    -1,    -1,    -1,  1416,
      -1,    -1,    -1,   223,   224,   225,   226,    -1,    -1,    -1,
    1427,   231,    -1,   397,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1439,    -1,  1441,    -1,  1443,    -1,    -1,    -1,
      -1,  1448,    -1,    -1,  1451,    -1,  1453,    -1,    -1,  1456,
    1457,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1474,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1484,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1492,  1493,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,    -1,
     229,    -1,  1519,    -1,    -1,  1522,    -1,    -1,    -1,  1526,
    1527,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1548,    -1,  1550,    -1,    -1,  1553,    -1,    -1,    -1,
      -1,    -1,    -1,  1560,    63,    64,  1563,    -1,    -1,    -1,
    1567,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1586,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,  1603,    -1,  1605,   573,
      -1,    -1,    -1,   577,    -1,    -1,    -1,   581,    -1,    -1,
      30,    31,    -1,  1620,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   595,   596,    -1,    -1,    -1,    -1,    -1,    -1,   603,
      -1,    -1,    -1,    -1,   608,    -1,    -1,    -1,    -1,   613,
      -1,   615,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,   627,    -1,   629,   630,    -1,   632,   633,
     634,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,    -1,
      -1,    -1,   231,    -1,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,    -1,   197,   198,   199,
     200,    -1,   202,   203,    -1,   205,   206,   207,    -1,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
      -1,   221,   222,   223,    -1,    -1,    63,    64,    -1,    -1,
     230,    -1,   232,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
     844,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   852,    -1,
      -1,    -1,    -1,   857,    -1,   859,    -1,   861,   862,    -1,
      -1,    -1,   866,   867,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      97,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,   920,   921,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,
      -1,   945,    -1,    -1,   231,    -1,    -1,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,    -1,
     197,   198,   199,   200,    -1,   202,   203,    -1,   205,   206,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,    -1,
      -1,    -1,    -1,    -1,   221,   222,   223,    -1,    -1,    -1,
      -1,    -1,    -1,   230,    -1,   232,     3,     4,     5,    -1,
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
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    63,    64,    -1,   126,
     127,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,    -1,
     197,   198,   199,   200,  1238,   202,   203,  1241,   205,   206,
     207,  1245,   209,   210,   211,   212,   213,   214,   215,    -1,
      -1,    -1,    -1,    -1,   221,   222,   223,    -1,    -1,    -1,
      -1,    -1,    -1,   230,    -1,   232,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1280,    -1,   223,   224,
     225,   226,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,
      -1,    -1,    -1,    -1,   231,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,
      63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    63,    64,
      -1,   126,   127,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,  1438,    -1,    -1,    -1,  1442,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,    -1,   197,   198,   199,   200,    -1,   202,   203,    -1,
     205,   206,   207,    -1,   209,   210,   211,   212,   213,   214,
     215,    -1,    -1,    -1,    -1,    -1,   221,   222,   223,    -1,
      -1,    -1,    -1,    -1,    -1,   230,   231,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
     223,   224,   225,   226,    -1,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,
     225,   226,    -1,    -1,    -1,    -1,   231,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,
      64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    63,    64,    -1,
     126,   127,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
      -1,   197,   198,   199,   200,    -1,   202,   203,    -1,   205,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,    -1,   221,   222,   223,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   231,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,    -1,    -1,    -1,    -1,   231,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,
      -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    63,    64,    -1,   126,
     127,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,    -1,
     197,   198,   199,   200,    -1,   202,   203,    -1,   205,   206,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,    -1,
      -1,    -1,    -1,    -1,   221,   222,   223,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,   223,   224,
     225,   226,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,
      -1,    -1,    -1,    61,   231,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,   111,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    -1,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,    -1,   197,
     198,   199,   200,    -1,   202,   203,    -1,   205,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,    -1,   221,   222,   223,    -1,    -1,    -1,     3,
       4,     5,   230,     7,     8,     9,    10,    -1,    -1,    -1,
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
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    63,
      64,    -1,   126,   127,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,    -1,   197,   198,   199,   200,    -1,   202,   203,
      -1,   205,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,    -1,   221,   222,   223,
      -1,    -1,    -1,     3,     4,     5,   230,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,    -1,    -1,    -1,    -1,   231,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,   111,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,    -1,   197,   198,   199,
     200,    -1,   202,   203,    -1,   205,   206,   207,    -1,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
      -1,   221,   222,   223,    -1,    -1,    -1,     3,     4,     5,
     230,     7,     8,     9,    10,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,
      -1,    -1,    -1,   231,    30,    31,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
      -1,   197,   198,   199,   200,    -1,   202,   203,    -1,   205,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,    -1,   221,   222,   223,    -1,    -1,
      -1,     3,     4,     5,   230,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    -1,    -1,    -1,    -1,   231,    30,    31,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,    -1,   197,   198,   199,   200,    -1,
     202,   203,    -1,   205,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,    -1,   221,
     222,   223,    -1,    -1,    -1,     3,     4,     5,   230,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,
      -1,    89,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,   112,   113,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,    -1,   197,
     198,   199,   200,    -1,   202,   203,    -1,   205,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,    -1,   221,   222,   223,    -1,    -1,    -1,     3,
       4,     5,   230,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,    -1,    -1,    -1,    -1,   231,    30,    31,    -1,    -1,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,    -1,   197,   198,   199,   200,    -1,   202,   203,
      -1,   205,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,    -1,   221,   222,   223,
      -1,    -1,    -1,     3,     4,     5,   230,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,    -1,    -1,    -1,    -1,   231,
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
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,    -1,   197,   198,   199,
     200,    -1,   202,   203,    -1,   205,   206,   207,    -1,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
      -1,   221,   222,   223,    -1,    -1,    -1,     3,     4,     5,
     230,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,
      -1,    -1,    -1,   231,    30,    31,    -1,    -1,    -1,    -1,
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
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
      -1,   197,   198,   199,   200,    -1,   202,   203,    -1,   205,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,    -1,   221,   222,   223,    -1,    -1,
      -1,     3,     4,     5,   230,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    -1,    -1,    -1,    -1,   231,    30,    31,
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
      -1,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,    -1,   197,   198,   199,   200,    -1,
     202,   203,    -1,   205,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,    -1,   221,
     222,   223,    -1,    -1,    -1,     3,     4,     5,   230,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   223,   224,   225,   226,    -1,    -1,    -1,
      -1,   231,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
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
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,    -1,   197,
     198,   199,   200,    -1,   202,   203,    -1,   205,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,    -1,   221,   222,   223,    -1,    -1,    -1,     3,
       4,     5,   230,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,    -1,    -1,    -1,    -1,   231,    30,    31,    -1,    -1,
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
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,    -1,   197,   198,   199,   200,    -1,   202,   203,
      -1,   205,   206,   207,    -1,   209,   210,   211,   212,   213,
     214,   215,    -1,    -1,    -1,    -1,    -1,   221,   222,   223,
      -1,    -1,    -1,     3,     4,     5,   230,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,    -1,    -1,    -1,    -1,   231,
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
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,    -1,   197,   198,   199,
     200,    -1,   202,   203,    -1,   205,   206,   207,    -1,   209,
     210,   211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,
      -1,   221,   222,   223,    -1,    -1,    -1,     3,     4,     5,
     230,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,
      -1,    -1,    -1,   231,    30,    31,    -1,    -1,    -1,    -1,
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
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
      -1,   197,   198,   199,   200,    -1,   202,   203,    -1,   205,
     206,   207,    -1,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,    -1,   221,   222,   223,    -1,    -1,
      -1,     3,     4,     5,   230,     7,     8,     9,    10,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    -1,    -1,    -1,    -1,   231,    30,    31,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,    -1,   197,   198,   199,   200,    -1,
     202,   203,    -1,   205,   206,   207,    -1,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,    -1,   221,
     222,   223,    -1,    -1,    -1,     3,     4,     5,   230,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   223,   224,   225,   226,    -1,    -1,    -1,
      -1,   231,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,
      -1,    89,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,     5,    -1,
      -1,    -1,    -1,    10,   122,    -1,    -1,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,    -1,   197,
     198,   199,   200,    -1,   202,   203,    -1,   205,   206,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   105,    -1,
     107,    -1,    -1,   221,   222,   223,     5,    -1,    -1,    -1,
      -1,    10,   230,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,    -1,    31,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,    -1,    -1,    -1,   171,   172,   173,    -1,   175,    -1,
     177,   178,   179,    -1,    -1,    -1,    -1,   184,   185,   186,
     187,   188,    -1,    -1,   191,    -1,   193,    -1,   195,    -1,
      -1,   198,    -1,   200,    -1,    -1,   203,    -1,    -1,   206,
     207,    -1,   209,   210,    -1,   212,   105,   214,   107,    -1,
      -1,    -1,     5,    -1,    -1,   222,    -1,    10,    -1,    -1,
      -1,    -1,    -1,   230,   231,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,    -1,
      -1,    -1,   171,   172,   173,    -1,   175,    -1,   177,   178,
     179,    -1,    -1,    -1,    -1,   184,   185,   186,   187,   188,
      -1,    -1,   191,    -1,   193,    -1,   195,    -1,    -1,   198,
      -1,   200,    -1,    -1,   203,    -1,    -1,   206,   207,    -1,
     209,   210,   105,   212,   107,   214,    -1,    -1,   111,    -1,
       5,    -1,    -1,   222,    -1,    10,    -1,    -1,    -1,    -1,
      -1,   230,   231,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,    -1,    -1,    -1,   171,   172,
     173,    -1,   175,    -1,   177,   178,   179,    -1,    -1,    -1,
      -1,   184,   185,   186,   187,   188,    -1,    -1,   191,    -1,
     193,    -1,   195,    -1,    -1,   198,    -1,   200,    -1,    -1,
     203,    -1,    97,   206,   207,    -1,   209,   210,    -1,   212,
     105,   214,   107,    -1,    -1,    -1,    -1,    -1,     5,   222,
      -1,    -1,    -1,    10,    -1,    -1,    -1,   230,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     165,   166,   167,    -1,    -1,    -1,   171,   172,   173,    -1,
     175,    -1,   177,   178,   179,    -1,    -1,    -1,    -1,   184,
     185,   186,   187,   188,    -1,    -1,   191,    -1,   193,    -1,
     195,    -1,    -1,   198,    -1,   200,    -1,    -1,   203,    -1,
      97,   206,   207,    -1,   209,   210,    -1,   212,   105,   214,
     107,    -1,    -1,    -1,     5,    -1,    -1,   222,    -1,    10,
      -1,    -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,    -1,    -1,    -1,   171,   172,   173,    -1,   175,    -1,
     177,   178,   179,    -1,    -1,    -1,    -1,   184,   185,   186,
     187,   188,    -1,    -1,   191,    -1,   193,    -1,   195,    -1,
      -1,   198,    -1,   200,    -1,    -1,   203,    -1,    -1,   206,
     207,    -1,   209,   210,   105,   212,   107,   214,    -1,    -1,
      -1,    -1,     5,    -1,    -1,   222,    -1,    10,    -1,    -1,
      -1,    -1,    -1,   230,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,
     171,   172,   173,    -1,   175,    -1,   177,   178,   179,    -1,
      -1,    -1,    -1,   184,   185,   186,   187,   188,    -1,    -1,
     191,    -1,   193,    -1,   195,    -1,    -1,   198,    -1,   200,
      -1,    -1,   203,    -1,    -1,   206,   207,    -1,   209,   210,
      -1,   212,   105,   214,   107,    -1,    -1,    -1,    -1,    -1,
      -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,
      63,    64,    -1,   126,   127,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,    -1,    -1,    -1,   171,   172,
     173,    -1,   175,    -1,   177,   178,   179,    -1,    -1,    -1,
      -1,   184,   185,   186,   187,   188,    -1,    -1,   191,    -1,
     193,    -1,   195,    -1,    -1,   198,    -1,   200,    -1,    -1,
     203,    -1,    -1,   206,   207,    -1,   209,   210,    -1,   212,
      -1,   214,    -1,     4,     5,     6,    -1,    -1,    -1,   222,
      11,    -1,    -1,    -1,    15,    -1,    17,   230,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     223,   224,   225,   226,    -1,    -1,   229,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    92,    93,    94,    95,    96,    -1,    98,    99,   100,
      -1,    -1,   103,   104,    -1,   106,    -1,   108,   109,    -1,
      -1,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,
     121,    -1,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,
      -1,   172,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   192,    -1,    -1,    -1,   196,    -1,     4,     5,     6,
     201,    -1,    -1,   204,    11,    -1,    -1,   208,    15,    -1,
      17,    -1,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    -1,    -1,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,    -1,    -1,   106,
      -1,   108,   109,   223,   224,   225,   226,   114,   115,    -1,
      -1,   231,    -1,    -1,   121,    -1,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   223,   224,   225,   226,    -1,
      -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,
     167,    -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   192,    -1,    -1,    -1,   196,
      -1,     4,     5,     6,   201,    -1,    -1,   204,    11,    -1,
      -1,   208,    15,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    38,    -1,    -1,    -1,    42,
      43,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    63,    64,    -1,    61,    62,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    -1,
      -1,    94,    95,    96,    -1,    98,    99,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,   108,   109,    -1,    -1,    -1,
      -1,   114,   115,    -1,    -1,    -1,    -1,    -1,   121,    -1,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   223,
     224,   225,   226,    63,    64,    -1,    -1,   231,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,   165,   166,   167,    63,    64,    -1,    -1,   172,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
      -1,    -1,    -1,   196,    -1,    -1,    -1,    -1,   201,    63,
      64,   204,    -1,    -1,    -1,   208,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   223,   224,   225,   226,    63,
      64,    -1,    -1,   231,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   223,   224,   225,   226,    63,    64,    -1,
      -1,   231,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,   223,   224,   225,   226,    63,
      64,    -1,    -1,   231,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   223,
     224,   225,   226,    63,    64,    -1,    -1,   231,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   223,
     224,   225,   226,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,    -1,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,    -1,
      -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    63,    64,    -1,    -1,   231,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,    63,    64,    -1,    -1,   231,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,   223,
     224,   225,   226,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    -1,   223,   224,   225,   226,    63,    64,
      -1,    -1,   231,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,   223,   224,   225,   226,    63,    64,    -1,
      -1,   231,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   223,   224,   225,   226,    63,    64,    -1,
      -1,   231,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,    63,    64,    -1,    -1,   231,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,   223,   224,
     225,   226,    63,    64,    -1,    -1,   231,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   223,   224,   225,
     226,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   224,   225,   226,    -1,    -1,    -1,    -1,
     231,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   224,   225,   226,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,    63,    64,   229,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   223,   224,   225,
     226,    63,    64,   229,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     223,   224,   225,   226,    63,    64,   229,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,   223,   224,   225,   226,    63,    64,   229,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,   223,   224,   225,   226,    63,    64,   229,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   223,   224,   225,   226,    63,    64,   229,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   223,   224,   225,   226,    63,    64,
     229,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,   223,   224,   225,   226,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,
      -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,    -1,    -1,   229,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,
      63,    64,   229,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,   223,   224,   225,   226,    63,
      64,   229,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   223,   224,   225,   226,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     223,   224,   225,   226,    63,    64,   229,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,
     225,   226,    63,    64,   229,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
     223,   224,   225,   226,    63,    64,   229,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   223,
     224,   225,   226,    63,    64,   229,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   223,   224,   225,   226,    63,    64,
     229,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   224,   225,   226,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   224,   225,   226,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   224,   225,   226,    63,    64,   229,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,   223,   224,   225,   226,    63,    64,
     229,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,   223,   224,   225,   226,    -1,    -1,   229,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,
     225,   226,    63,    64,   229,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   223,   224,
     225,   226,    63,    64,   229,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,
      63,    64,   229,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,   223,   224,
     225,   226,    63,    64,   229,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   223,   224,   225,   226,    63,    64,   229,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   223,   224,   225,   226,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   224,   225,   226,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   224,   225,   226,    63,    64,   229,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     223,   224,   225,   226,    63,    64,   229,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,   223,   224,   225,   226,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,    63,    64,   229,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   223,   224,   225,   226,
      63,    64,   229,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   223,   224,   225,   226,
      63,    64,   229,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   223,   224,   225,   226,    63,    64,
     229,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,   223,   224,   225,   226,    63,    64,   229,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
     223,   224,   225,   226,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     223,   224,   225,   226,    -1,    -1,   229,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,
      -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     223,   224,   225,   226,    63,    64,   229,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     223,   224,   225,   226,    63,    64,   229,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,
     225,   226,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   223,   224,   225,   226,    63,    64,   229,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,   223,   224,   225,   226,    63,
      64,   229,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   223,   224,   225,   226,    63,    64,
     229,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   223,   224,   225,   226,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,   225,
     226,    -1,    -1,   229,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   223,   224,   225,   226,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,
     224,   225,   226,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,
     225,   226,    -1,    -1,   229
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   216,   217,   218,   219,   220,   234,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   114,   115,
     121,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     165,   166,   167,   172,   192,   196,   201,   204,   208,   235,
     236,   239,   240,   247,   248,   250,   251,   255,   267,   268,
     273,   279,   286,   294,   302,   305,   309,   312,   318,     3,
       4,     5,     7,     8,     9,    10,    30,    31,    63,    64,
      65,    66,    67,    68,    69,    81,    84,    89,   101,   102,
     105,   107,   115,   122,   126,   127,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   197,   198,
     199,   200,   202,   203,   205,   206,   207,   209,   210,   211,
     212,   213,   214,   215,   221,   222,   223,   230,   253,   254,
     256,   262,   264,   267,   268,   230,   253,   239,   267,   268,
     273,     0,    75,   230,    75,   230,   287,   306,   310,     4,
       7,   265,   265,   265,    34,   256,   241,   242,   253,   269,
     270,   269,   253,    28,     7,   295,   303,   256,    58,    60,
      61,   232,   349,   245,   253,   256,     4,     5,   266,   256,
     253,   256,   253,   256,     4,     5,   329,   330,    10,   223,
     224,   263,   264,   331,   265,    89,    97,   232,   253,   256,
     350,    89,    97,   110,   350,   350,    81,    82,    88,   111,
     256,   261,    12,    53,   261,   111,   261,    59,    89,    90,
      91,    96,    95,   256,   248,   255,   253,   253,   253,   110,
     261,    90,    91,    92,    93,    94,   104,   110,   111,   116,
     117,   118,   119,   120,   261,   261,   111,   261,   111,   261,
      95,   111,   261,    61,    95,   111,   142,   261,   261,    22,
      61,   111,   261,   111,   261,   111,   261,   111,   253,   253,
     253,    61,   111,   111,   142,   143,   261,   111,   261,   261,
     111,   261,   261,   261,   230,   230,   230,   230,   230,   253,
     350,   253,   253,   253,    44,   237,    92,    93,   104,    75,
      75,    24,   230,   230,   230,   230,   256,   230,   230,   230,
     230,   230,   230,   112,   113,   230,   230,   230,   230,   112,
     230,   112,   112,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   256,   253,   256,    70,    71,    72,    73,
      74,    75,    76,   224,    44,    63,    64,    70,    71,    72,
      73,    74,    75,    76,    77,   223,   224,   225,   226,   253,
      44,    44,    44,   256,   269,   253,   269,     4,   256,   236,
      35,    36,    20,    21,     4,     5,   280,   281,     4,     5,
     282,   283,   253,   256,   271,   272,   253,   256,   297,   236,
     313,   319,   230,    58,   230,     4,     7,   230,   253,   256,
     332,    58,    60,    61,   232,   334,   347,   230,   230,   229,
     229,   229,   230,   230,   229,   264,   264,   229,   256,   253,
     256,    11,   229,   229,   261,   253,   253,   253,   229,   261,
     246,    12,   229,   249,   253,   229,   261,    12,   261,   249,
     249,   249,   261,   261,   261,   261,   261,   261,   261,   253,
     253,   261,   261,   261,   261,   249,   249,   253,   229,   253,
     229,   253,   253,   249,   253,   253,   253,   253,   249,   229,
     253,   253,   253,   249,   253,   249,   253,   229,   253,   229,
     229,   229,   253,   253,   253,   253,   253,   249,   253,   249,
     249,   253,   249,   249,   249,     5,   252,   252,   252,   231,
     256,   253,   229,   229,   229,   229,    43,   261,   261,   261,
     256,   253,   274,   269,   269,   256,   256,   256,   256,   256,
     256,    97,   253,   350,   350,   253,     4,     5,   259,   260,
     259,   260,   261,   256,   253,   253,   253,   253,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   350,   256,
     256,   256,   256,   256,   256,   256,   256,   231,   256,   253,
     253,   253,   253,   253,   256,   256,   253,   256,   231,   256,
     256,   253,   256,   253,   256,   253,   253,   231,   253,   231,
     253,   231,   253,   231,   253,   253,   253,   253,   256,   253,
     253,   253,   253,   253,   253,   253,   350,   253,   269,   269,
     253,   256,   253,   253,   253,   253,   253,   231,   231,   253,
     252,   253,   252,   253,   253,   253,   231,   231,   253,   253,
     253,   253,   253,   253,   253,   253,   258,   257,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     231,   231,    75,   307,    14,    16,    18,    41,    44,    49,
     311,   243,   244,   230,   230,   229,   230,   230,   229,   229,
      43,   296,    14,    16,    18,    41,    44,    49,   304,    46,
     236,   256,   230,   253,   256,    51,   333,   228,   229,   230,
      58,   230,     4,     7,   230,    10,   348,   269,   269,     4,
       5,   256,   256,   269,   269,   330,    10,   263,   229,    86,
      87,    97,   253,   256,   249,   229,   256,   334,   261,   229,
     253,   261,   249,   256,   256,   261,   229,   249,   229,   249,
     229,   249,   249,   229,   229,   229,   249,   249,   261,   261,
     229,   253,   229,   253,   229,   261,   229,   229,   229,   261,
     253,   229,   229,   229,   261,   229,   261,   229,   253,   229,
     256,   253,   253,   229,   229,   229,   229,   229,   261,   229,
     261,   261,   229,   261,   261,   261,   230,   229,   229,   229,
     231,   231,   253,   256,   253,   256,   256,   256,   238,   229,
     249,   249,     4,     5,   278,   231,   231,   229,   229,   231,
     229,   229,   229,   231,   229,   231,   229,   231,   229,   230,
     230,   231,   231,   229,   229,   249,   229,   229,   231,   231,
     231,   231,   231,   231,   229,   231,   231,   229,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   229,
     231,   231,   229,   229,   229,   231,   229,   229,   231,   229,
     231,   231,   231,   231,   231,   229,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   229,   229,   229,
     229,   231,   231,   231,   231,   231,   229,   231,   231,   231,
     231,   231,   231,   229,   231,   229,   229,   229,   229,   229,
     231,   229,   229,   231,   229,   231,   231,   256,   256,   288,
     236,   256,   265,   351,   265,   352,   269,   269,   281,   269,
     269,   283,   272,    43,   298,   314,    49,    50,   320,   229,
     256,   229,   231,   231,   230,   253,   253,   256,   256,   230,
     253,   335,   336,   256,     4,     5,   326,   328,   231,   231,
     230,   230,   229,   229,   231,   231,   256,    85,    85,   229,
     229,   261,   253,   253,   229,   261,   229,   229,   229,   253,
     261,   256,   261,   253,   261,   261,   253,   256,   256,   256,
     261,   261,   229,   229,   256,   229,   256,   229,   253,   256,
     229,   253,   253,   253,   229,   229,   253,   253,   253,   256,
     229,   253,   229,   256,   229,   253,   229,   253,   253,   256,
     253,   256,   229,   253,   229,   229,   256,   229,   229,   229,
     269,   256,   256,   256,   229,   229,   240,   256,   261,   261,
     275,   256,   256,   256,   256,   256,   253,    97,   253,   253,
     231,   231,   256,   256,   261,   256,   253,   256,   256,   256,
     256,   256,   256,   256,   256,   253,   256,   253,   253,   253,
     253,   253,   256,   256,   256,   256,   260,   253,   260,   253,
     253,   256,    16,    44,   308,   229,   229,   231,   231,   231,
     231,    39,    40,   300,   236,   256,   229,   253,    58,   253,
     333,   229,   256,   229,   231,   326,   326,   231,   230,   230,
     229,   269,   269,   256,   256,   229,   350,   350,   253,   253,
     229,   229,   253,   256,   256,   253,   229,   229,   249,   229,
     229,   249,   229,   229,   229,   249,   229,   253,   253,   253,
     253,   253,   229,   253,   253,   229,   229,   229,   253,   229,
     253,   253,   229,   253,   229,   229,   253,   229,   253,   253,
     253,   253,   253,   231,   231,   231,   229,   231,   253,   253,
     249,   230,   231,   231,   231,   231,   231,   231,   231,   229,
     231,   231,   231,   231,   249,   229,   231,   231,   231,   231,
     231,   229,   231,   231,   231,   229,   231,   231,   231,   229,
     229,   231,   229,   231,   231,   231,   229,   229,   231,   229,
     231,   231,   229,   231,   231,   231,    12,   265,   265,   297,
      43,    38,   315,   231,   256,   231,   230,   229,   256,   229,
     253,    58,   342,   337,   269,   269,   327,   231,   231,   253,
     253,   253,   229,   229,   229,   253,   253,   261,   253,   253,
     261,   256,   256,   256,   261,   256,   229,   229,   229,   229,
     256,   229,   229,   253,   256,   256,   229,   253,   229,   229,
     256,   256,   253,   256,   229,   253,   229,   229,   229,   229,
     229,    75,    75,   256,    75,   229,   261,     4,     5,   284,
     285,   253,   256,   253,   256,   253,   253,   256,   256,   253,
     256,   253,   253,   256,   299,   301,    48,   322,    60,    61,
     231,    58,   256,   253,   231,   256,   231,   230,   348,   326,
     231,   231,   326,   229,   253,   253,   253,   229,   249,   229,
     229,   229,   249,   229,   253,   256,   256,   253,   229,   256,
     253,   229,   253,   229,   253,   256,   229,   229,   253,   253,
     256,   256,   253,   253,   253,   253,   231,   253,   256,   230,
     230,   229,   231,   231,   229,   231,   231,   231,   231,   231,
     231,   231,   231,   231,    13,   292,   236,   236,   256,    47,
     321,   230,   230,   229,   231,    60,    61,   338,   231,    58,
     343,   256,   326,   253,   253,   261,   256,   253,   256,   261,
     256,   229,   229,   229,   229,   256,   229,   229,   256,   229,
     256,   229,   229,   256,   256,   229,   229,   229,   229,    75,
     231,   231,   285,   276,   256,   256,   289,    46,   325,   236,
     316,   253,   256,   256,   344,   230,   348,   339,   230,   348,
     229,   229,   229,   229,   229,   229,   253,   253,   253,   253,
     229,   253,   253,   229,   256,   253,   256,   229,   253,   256,
     256,   253,   253,   236,   231,   236,   323,    14,    16,    18,
      41,    44,    49,   317,   229,   231,   229,   231,   348,   253,
     326,   348,   256,   326,   256,   253,   253,   256,   253,   253,
     229,   256,   256,   229,   229,   229,   256,   229,   229,    25,
      44,   277,   290,   236,   253,   256,   326,   229,   231,   326,
     229,   231,   229,   253,   256,   253,   256,   253,   253,    14,
      16,    18,    41,    44,    49,   291,   324,   231,   231,   253,
     345,   256,   340,   253,   229,   229,     4,   293,   322,   231,
     348,   231,   348,   253,   253,   346,   326,   341,   326,   229,
     348,   348,   253,   326,   326
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   233,   234,   234,   234,   234,   234,   235,   236,   237,
     238,   236,   239,   239,   239,   239,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   241,   240,   242,   240,   240,   240,   240,   240,   240,
     240,   243,   240,   244,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   245,   240,   246,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   247,   247,   247,   247,   247,   248,   248,   248,
     248,   248,   248,   249,   249,   250,   250,   250,   250,   250,
     251,   251,   252,   252,   253,   253,   253,   253,   253,   253,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   255,   255,   257,   256,   258,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   259,   260,   261,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   263,   263,   263,   264,   264,   264,   264,   265,
     265,   266,   266,   266,   266,   267,   268,   270,   269,   271,
     271,   271,   272,   272,   274,   275,   276,   273,   277,   277,
     278,   278,   279,   279,   279,   279,   280,   280,   281,   281,
     281,   281,   282,   282,   283,   283,   283,   283,   284,   284,
     284,   285,   285,   285,   285,   287,   288,   289,   290,   286,
     291,   291,   291,   291,   291,   291,   292,   292,   293,   293,
     295,   294,   296,   296,   297,   297,   298,   299,   298,   300,
     301,   300,   303,   302,   304,   304,   304,   304,   304,   304,
     306,   307,   305,   308,   308,   310,   309,   311,   311,   311,
     311,   311,   311,   313,   314,   315,   316,   312,   317,   317,
     317,   317,   317,   317,   319,   318,   320,   320,   321,   321,
     322,   323,   324,   322,   325,   325,   326,   327,   326,   328,
     328,   328,   328,   329,   329,   330,   330,   330,   330,   331,
     331,   331,   331,   332,   332,   332,   332,   332,   333,   333,
     333,   335,   334,   336,   334,   337,   334,   338,   334,   339,
     334,   340,   334,   341,   334,   342,   334,   343,   334,   344,
     334,   345,   334,   346,   334,   347,   334,   348,   348,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   349,   349,
     349,   349,   349,   350,   350,   351,   351,   352,   352
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
       2,     3,     2,     2,     1,     1,     3,     4,     4,     4,
       4,     4,     4,     1,     1,     2,     1,     2,     2,     8,
       6,     6,     0,     1,     1,     2,     2,     3,    10,     8,
       8,     8,     3,     1,     1,     6,     4,     4,     6,     6,
       4,     6,     1,     4,     1,     1,     1,     1,     3,     3,
       6,     6,     8,     6,     4,     6,     8,     4,     1,     3,
       4,     4,     4,     4,     4,     4,     4,     6,     8,     4,
       4,     4,     4,     4,     6,     1,     3,     1,     3,     4,
       3,     3,     6,     6,     4,     6,     4,     6,    10,     4,
       4,     4,     8,     6,     4,     3,     3,     0,     4,     0,
       4,     2,     3,     3,     3,     3,     3,     3,     3,     4,
       6,     1,     4,     4,     6,     6,     1,     1,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     3,     4,     4,     4,     4,
       4,     4,     6,     4,     4,     6,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     4,     3,     6,     6,
       4,     4,     4,     4,     6,     6,     8,     6,     8,     4,
       4,     4,     8,     4,     4,     4,     4,     1,     3,     4,
       1,     3,     4,     1,     3,     4,     1,     3,     6,     6,
       4,     6,     6,     6,     4,     8,     6,     8,     6,     4,
       4,     4,     6,     6,     6,     8,     4,     2,     5,     5,
       7,     4,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     4,     6,     4,     6,     4,     4,     0,     2,     0,
       1,     3,     1,     1,     0,     0,     0,    11,     1,     1,
       1,     1,     0,     1,     1,     2,     1,     3,     1,     1,
       4,     4,     1,     3,     1,     1,     4,     4,     0,     1,
       3,     1,     1,     3,     3,     0,     0,     0,     0,    14,
       1,     1,     1,     1,     1,     1,     0,     2,     0,     1,
       0,     7,     1,     2,     1,     1,     0,     0,     5,     0,
       0,     4,     0,     4,     1,     1,     1,     1,     1,     1,
       0,     0,     6,     1,     1,     0,     4,     1,     2,     1,
       1,     1,     1,     0,     0,     0,     0,    11,     1,     1,
       1,     1,     1,     1,     0,     5,     1,     1,     0,     2,
       0,     0,     0,     7,     0,     1,     1,     0,     4,     1,
       4,     1,     4,     1,     3,     1,     4,     1,     4,     1,
       1,     3,     3,     0,     2,     4,     1,     3,     0,     2,
       6,     0,     4,     0,     4,     0,     6,     0,     9,     0,
      10,     0,    13,     0,    15,     0,     7,     0,     9,     0,
      10,     0,    13,     0,    15,     0,     3,     0,     1,     0,
       2,     2,     4,     1,     4,     6,     6,     7,    10,    12,
       7,    10,    12,     2,     1,     1,     3,     1,     3
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

  case 160: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 161: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 162: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 163: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 164: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 165: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 166: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 167: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 168: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 169: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 170: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 171: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 172: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 173: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 174: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 175: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 176: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 177: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 178: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 179: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 180: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 181: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 182: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 183: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 184: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 185: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 186: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 187: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 188: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 189: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 190: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 191: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 192: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 195: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 196: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 197: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 198: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 199: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 200: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 201: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 202: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 203: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 204: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 206: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 207: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 208: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 210: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 211: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 212: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 213: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 214: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 215: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 216: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 217: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 218: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 219: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 220: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 221: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 222: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 223: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 224: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 225: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 226: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 227: /* string_function: tSTRING2 '(' expression ',' string_expression ')'  */
                                                      {create_function(fSTRING);}
    break;

  case 228: /* string_function: tREPLACE '(' string_expression ',' string_expression ',' string_expression ')'  */
                                                                                    {create_function(fREPLACE);}
    break;

  case 229: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 230: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 231: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 232: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 233: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 234: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 235: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 236: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 237: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 238: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 239: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 240: /* string_function: tTEXTCONTROL tGET string_expression  */
                                        {create_function(fYABTEXTCONTROLGET);}
    break;

  case 241: /* string_function: tTEXTEDIT tGET string_expression  */
                                     {create_function(fYABTEXTEDITGET);}
    break;

  case 242: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 243: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 244: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 245: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 246: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 247: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 248: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 249: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 250: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 251: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 252: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 253: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 254: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 255: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 256: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 257: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 258: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 259: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 260: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 261: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 262: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 263: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 264: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 265: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 266: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 267: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 268: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 269: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 270: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 271: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 272: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 273: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 274: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 275: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 276: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 277: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 278: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 279: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 280: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 281: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 282: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 283: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 284: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 285: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 286: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 287: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 288: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 289: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 290: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 293: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 294: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 296: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 297: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 298: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 299: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 300: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 301: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 302: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 303: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 304: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 305: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 306: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 307: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 308: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 309: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 310: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 311: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 312: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 313: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 314: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 315: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 316: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 317: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 318: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 319: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 320: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 321: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 322: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 323: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 324: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 325: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 326: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 327: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 328: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 329: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 330: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 331: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 332: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 333: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 334: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 335: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 336: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 337: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 338: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 339: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 340: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 341: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 342: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 343: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 344: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 345: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 346: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 347: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 348: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 349: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 350: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 351: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 352: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 353: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 354: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 355: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 356: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 357: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 358: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 359: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 360: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 361: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 362: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 363: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 364: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 365: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 366: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 367: /* function: tWINDOW tCOUNT  */
                   {create_function(fYABNUMWINDOWS);}
    break;

  case 368: /* function: tWINDOW tGET string_expression ',' string_expression  */
                                                         {create_function(fYABWINDOWGET);}
    break;

  case 369: /* function: tDRAW tGET string_expression ',' string_expression  */
                                                       {create_function(fYABDRAWGET);}
    break;

  case 370: /* function: tDRAW tGET string_expression ',' string_expression ',' string_expression  */
                                                                             {create_function(fYABDRAWGETTEXT);}
    break;

  case 371: /* function: tBFILESIZE '(' string_expression ')'  */
                                         {create_function(fYABBFILESIZE);}
    break;

  case 372: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 373: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 374: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 375: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 376: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 377: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 378: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 379: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 380: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 381: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 382: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 383: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 384: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 385: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 386: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 387: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 394: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 395: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 396: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 397: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 398: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 399: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 400: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 401: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 402: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 403: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 404: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 405: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 408: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 409: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 410: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 411: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 414: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 415: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 416: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 417: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 421: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 422: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 423: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 424: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 425: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 426: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 427: /* $@17: %empty  */
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

  case 428: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 429: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 430: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 431: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 432: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 433: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 434: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 435: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 436: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 438: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 439: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 440: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 441: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 447: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 448: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 450: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 452: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 454: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 455: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 456: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 457: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 458: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 459: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 460: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 461: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 463: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 464: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 465: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 467: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 468: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 469: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 470: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 471: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 472: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 473: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 474: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 475: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 476: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 478: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 479: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 480: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 481: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 482: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 483: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 484: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 486: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 487: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 491: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 492: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 497: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 499: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 500: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 501: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 502: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 505: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 506: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 507: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 508: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 509: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 510: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 511: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 512: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 516: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 517: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 518: /* using: %empty  */
       {create_print('d');}
    break;

  case 519: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 520: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 521: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 522: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 523: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 524: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 525: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 526: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 527: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 528: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 529: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 530: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 531: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 532: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 533: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 534: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 535: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 536: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 537: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 538: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 539: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 540: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 541: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 542: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 543: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 544: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 545: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 546: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 547: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 548: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 549: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 550: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 551: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 552: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 553: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 554: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 555: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 556: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 557: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 558: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 559: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 560: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 561: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 562: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 565: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 566: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 567: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 568: /* gosub_list: gosub_list ',' symbol_or_lineno  */
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

