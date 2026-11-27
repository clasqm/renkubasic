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
  YYSYMBOL_tSIN = 156,                     /* tSIN  */
  YYSYMBOL_tASIN = 157,                    /* tASIN  */
  YYSYMBOL_tCOS = 158,                     /* tCOS  */
  YYSYMBOL_tACOS = 159,                    /* tACOS  */
  YYSYMBOL_tTAN = 160,                     /* tTAN  */
  YYSYMBOL_tATAN = 161,                    /* tATAN  */
  YYSYMBOL_tEXP = 162,                     /* tEXP  */
  YYSYMBOL_tLOG = 163,                     /* tLOG  */
  YYSYMBOL_tSQRT = 164,                    /* tSQRT  */
  YYSYMBOL_tSQR = 165,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 166,                   /* tMYEOF  */
  YYSYMBOL_tABS = 167,                     /* tABS  */
  YYSYMBOL_tSIG = 168,                     /* tSIG  */
  YYSYMBOL_tINT = 169,                     /* tINT  */
  YYSYMBOL_tCEIL = 170,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 171,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 172,                    /* tFRAC  */
  YYSYMBOL_tROUND = 173,                   /* tROUND  */
  YYSYMBOL_tMOD = 174,                     /* tMOD  */
  YYSYMBOL_tRAN = 175,                     /* tRAN  */
  YYSYMBOL_tVAL = 176,                     /* tVAL  */
  YYSYMBOL_tLEFT = 177,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 178,                   /* tRIGHT  */
  YYSYMBOL_tMID = 179,                     /* tMID  */
  YYSYMBOL_tLEN = 180,                     /* tLEN  */
  YYSYMBOL_tMIN = 181,                     /* tMIN  */
  YYSYMBOL_tMAX = 182,                     /* tMAX  */
  YYSYMBOL_tSTR = 183,                     /* tSTR  */
  YYSYMBOL_tINKEY = 184,                   /* tINKEY  */
  YYSYMBOL_tCHR = 185,                     /* tCHR  */
  YYSYMBOL_tASC = 186,                     /* tASC  */
  YYSYMBOL_tHEX = 187,                     /* tHEX  */
  YYSYMBOL_tDEC = 188,                     /* tDEC  */
  YYSYMBOL_tBIN = 189,                     /* tBIN  */
  YYSYMBOL_tUPPER = 190,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 191,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 192,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 193,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 194,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 195,                /* tMOUSEMOD  */
  YYSYMBOL_tTRIM = 196,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 197,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 198,                   /* tRTRIM  */
  YYSYMBOL_tSTRING2 = 199,                 /* tSTRING2  */
  YYSYMBOL_tREPLACE = 200,                 /* tREPLACE  */
  YYSYMBOL_tINSTR = 201,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 202,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 203,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 204,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 205,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 206,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 207,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 208,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 209,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 210,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 211,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 212,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 213,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 214,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 215,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 216,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 217,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 218,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 219,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 220,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 221,                    /* tDATE  */
  YYSYMBOL_tTIME = 222,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 223,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 224,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 225,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 226,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 227,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 228,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 229,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 230, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 231,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 232, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 233,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 234,                   /* tEVAL2  */
  YYSYMBOL_tARGUMENT = 235,                /* tARGUMENT  */
  YYSYMBOL_236_ = 236,                     /* '-'  */
  YYSYMBOL_237_ = 237,                     /* '+'  */
  YYSYMBOL_238_ = 238,                     /* '*'  */
  YYSYMBOL_239_ = 239,                     /* '/'  */
  YYSYMBOL_UMINUS = 240,                   /* UMINUS  */
  YYSYMBOL_241_ = 241,                     /* ';'  */
  YYSYMBOL_242_ = 242,                     /* ','  */
  YYSYMBOL_243_ = 243,                     /* '('  */
  YYSYMBOL_244_ = 244,                     /* ')'  */
  YYSYMBOL_245_ = 245,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 246,                 /* $accept  */
  YYSYMBOL_program_or_expression = 247,    /* program_or_expression  */
  YYSYMBOL_program = 248,                  /* program  */
  YYSYMBOL_statement_list = 249,           /* statement_list  */
  YYSYMBOL_250_1 = 250,                    /* $@1  */
  YYSYMBOL_251_2 = 251,                    /* $@2  */
  YYSYMBOL_assignment = 252,               /* assignment  */
  YYSYMBOL_statement = 253,                /* statement  */
  YYSYMBOL_254_3 = 254,                    /* $@3  */
  YYSYMBOL_255_4 = 255,                    /* $@4  */
  YYSYMBOL_256_5 = 256,                    /* $@5  */
  YYSYMBOL_257_6 = 257,                    /* $@6  */
  YYSYMBOL_258_7 = 258,                    /* $@7  */
  YYSYMBOL_259_8 = 259,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 260,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 261,        /* string_assignment  */
  YYSYMBOL_to = 262,                       /* to  */
  YYSYMBOL_open_clause = 263,              /* open_clause  */
  YYSYMBOL_seek_clause = 264,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 265,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 266,        /* string_expression  */
  YYSYMBOL_string_function = 267,          /* string_function  */
  YYSYMBOL_number_assignment = 268,        /* number_assignment  */
  YYSYMBOL_expression = 269,               /* expression  */
  YYSYMBOL_270_9 = 270,                    /* $@9  */
  YYSYMBOL_271_10 = 271,                   /* $@10  */
  YYSYMBOL_arrayref = 272,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 273,          /* string_arrayref  */
  YYSYMBOL_coordinates = 274,              /* coordinates  */
  YYSYMBOL_function = 275,                 /* function  */
  YYSYMBOL_const = 276,                    /* const  */
  YYSYMBOL_number = 277,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 278,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 279,                  /* dimlist  */
  YYSYMBOL_function_or_array = 280,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 281,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 282,                /* call_list  */
  YYSYMBOL_283_11 = 283,                   /* $@11  */
  YYSYMBOL_calls = 284,                    /* calls  */
  YYSYMBOL_call_item = 285,                /* call_item  */
  YYSYMBOL_function_definition = 286,      /* function_definition  */
  YYSYMBOL_287_12 = 287,                   /* $@12  */
  YYSYMBOL_288_13 = 288,                   /* $@13  */
  YYSYMBOL_289_14 = 289,                   /* $@14  */
  YYSYMBOL_endsub = 290,                   /* endsub  */
  YYSYMBOL_function_name = 291,            /* function_name  */
  YYSYMBOL_export = 292,                   /* export  */
  YYSYMBOL_local_list = 293,               /* local_list  */
  YYSYMBOL_local_item = 294,               /* local_item  */
  YYSYMBOL_static_list = 295,              /* static_list  */
  YYSYMBOL_static_item = 296,              /* static_item  */
  YYSYMBOL_paramlist = 297,                /* paramlist  */
  YYSYMBOL_paramitem = 298,                /* paramitem  */
  YYSYMBOL_for_loop = 299,                 /* for_loop  */
  YYSYMBOL_300_15 = 300,                   /* $@15  */
  YYSYMBOL_301_16 = 301,                   /* $@16  */
  YYSYMBOL_302_17 = 302,                   /* $@17  */
  YYSYMBOL_303_18 = 303,                   /* $@18  */
  YYSYMBOL_next = 304,                     /* next  */
  YYSYMBOL_step_part = 305,                /* step_part  */
  YYSYMBOL_next_symbol = 306,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 307,  /* switch_number_or_string  */
  YYSYMBOL_308_19 = 308,                   /* $@19  */
  YYSYMBOL_sep_list = 309,                 /* sep_list  */
  YYSYMBOL_number_or_string = 310,         /* number_or_string  */
  YYSYMBOL_case_list = 311,                /* case_list  */
  YYSYMBOL_312_20 = 312,                   /* $@20  */
  YYSYMBOL_default = 313,                  /* default  */
  YYSYMBOL_314_21 = 314,                   /* $@21  */
  YYSYMBOL_do_loop = 315,                  /* do_loop  */
  YYSYMBOL_316_22 = 316,                   /* $@22  */
  YYSYMBOL_loop = 317,                     /* loop  */
  YYSYMBOL_while_loop = 318,               /* while_loop  */
  YYSYMBOL_319_23 = 319,                   /* $@23  */
  YYSYMBOL_320_24 = 320,                   /* $@24  */
  YYSYMBOL_wend = 321,                     /* wend  */
  YYSYMBOL_repeat_loop = 322,              /* repeat_loop  */
  YYSYMBOL_323_25 = 323,                   /* $@25  */
  YYSYMBOL_until = 324,                    /* until  */
  YYSYMBOL_if_clause = 325,                /* if_clause  */
  YYSYMBOL_326_26 = 326,                   /* $@26  */
  YYSYMBOL_327_27 = 327,                   /* $@27  */
  YYSYMBOL_328_28 = 328,                   /* $@28  */
  YYSYMBOL_329_29 = 329,                   /* $@29  */
  YYSYMBOL_endif = 330,                    /* endif  */
  YYSYMBOL_short_if = 331,                 /* short_if  */
  YYSYMBOL_332_30 = 332,                   /* $@30  */
  YYSYMBOL_end_of_if = 333,                /* end_of_if  */
  YYSYMBOL_else_part = 334,                /* else_part  */
  YYSYMBOL_elsif_part = 335,               /* elsif_part  */
  YYSYMBOL_336_31 = 336,                   /* $@31  */
  YYSYMBOL_337_32 = 337,                   /* $@32  */
  YYSYMBOL_maybe_then = 338,               /* maybe_then  */
  YYSYMBOL_inputlist = 339,                /* inputlist  */
  YYSYMBOL_340_33 = 340,                   /* $@33  */
  YYSYMBOL_input = 341,                    /* input  */
  YYSYMBOL_readlist = 342,                 /* readlist  */
  YYSYMBOL_readitem = 343,                 /* readitem  */
  YYSYMBOL_datalist = 344,                 /* datalist  */
  YYSYMBOL_printlist = 345,                /* printlist  */
  YYSYMBOL_using = 346,                    /* using  */
  YYSYMBOL_inputbody = 347,                /* inputbody  */
  YYSYMBOL_348_34 = 348,                   /* $@34  */
  YYSYMBOL_349_35 = 349,                   /* $@35  */
  YYSYMBOL_350_36 = 350,                   /* $@36  */
  YYSYMBOL_351_37 = 351,                   /* $@37  */
  YYSYMBOL_352_38 = 352,                   /* $@38  */
  YYSYMBOL_353_39 = 353,                   /* $@39  */
  YYSYMBOL_354_40 = 354,                   /* $@40  */
  YYSYMBOL_355_41 = 355,                   /* $@41  */
  YYSYMBOL_356_42 = 356,                   /* $@42  */
  YYSYMBOL_357_43 = 357,                   /* $@43  */
  YYSYMBOL_358_44 = 358,                   /* $@44  */
  YYSYMBOL_359_45 = 359,                   /* $@45  */
  YYSYMBOL_360_46 = 360,                   /* $@46  */
  YYSYMBOL_prompt = 361,                   /* prompt  */
  YYSYMBOL_printintro = 362,               /* printintro  */
  YYSYMBOL_hashed_number = 363,            /* hashed_number  */
  YYSYMBOL_goto_list = 364,                /* goto_list  */
  YYSYMBOL_gosub_list = 365                /* gosub_list  */
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
#define YYFINAL  237
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   13921

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  246
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  622
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1905

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   491


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
       2,     2,     2,     2,     2,   245,     2,     2,     2,     2,
     243,   244,   238,   237,   242,   236,     2,   239,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   241,
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
     235,   240
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   229,   229,   230,   231,   232,   233,   236,   239,   240,
     240,   240,   243,   244,   245,   246,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   264,   265,   265,   266,   267,   268,   269,   270,
     271,   272,   272,   274,   274,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   286,   287,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   304,   305,
     306,   307,   308,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   358,   359,   360,   361,   362,   363,
     364,   365,   366,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   470,
     471,   472,   473,   474,   478,   479,   480,   481,   482,   483,
     486,   487,   490,   491,   492,   493,   494,   497,   498,   501,
     502,   505,   506,   507,   508,   509,   510,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   545,   546,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   567,   568,   569,   572,
     573,   576,   576,   577,   577,   578,   579,   580,   581,   582,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   612,   615,   618,
     621,   622,   623,   624,   625,   626,   627,   628,   629,   630,
     631,   632,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   662,   663,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
     691,   694,   695,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   713,   714,   715,   718,
     719,   720,   721,   724,   725,   728,   729,   730,   731,   734,
     737,   740,   740,   743,   744,   745,   748,   749,   752,   753,
     756,   752,   761,   762,   765,   766,   769,   770,   771,   772,
     775,   776,   779,   780,   781,   782,   785,   786,   789,   790,
     791,   792,   795,   796,   797,   800,   801,   802,   803,   806,
     807,   812,   827,   806,   832,   833,   834,   835,   836,   837,
     840,   841,   844,   845,   850,   850,   854,   855,   858,   859,
     863,   865,   864,   869,   870,   870,   874,   874,   880,   881,
     882,   883,   884,   885,   889,   890,   889,   896,   897,   901,
     901,   906,   907,   908,   909,   910,   911,   914,   915,   915,
     917,   914,   921,   922,   923,   924,   925,   926,   929,   929,
     934,   935,   938,   939,   942,   944,   946,   943,   950,   951,
     954,   955,   955,   958,   959,   961,   962,   966,   967,   970,
     971,   973,   974,   978,   979,   980,   981,   984,   985,   986,
     987,   988,   991,   992,   993,   996,   996,   997,   997,   998,
     998,   999,   999,  1000,  1000,  1001,  1001,  1002,  1002,  1003,
    1003,  1004,  1004,  1005,  1005,  1006,  1006,  1007,  1007,  1008,
    1008,  1011,  1012,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,  1031,  1032,  1034,
    1035,  1038,  1039
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
  "tGETS", "tSIN", "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP",
  "tLOG", "tSQRT", "tSQR", "tMYEOF", "tABS", "tSIG", "tINT", "tCEIL",
  "tFLOOR", "tFRAC", "tROUND", "tMOD", "tRAN", "tVAL", "tLEFT", "tRIGHT",
  "tMID", "tLEN", "tMIN", "tMAX", "tSTR", "tINKEY", "tCHR", "tASC", "tHEX",
  "tDEC", "tBIN", "tUPPER", "tLOWER", "tMOUSEX", "tMOUSEY", "tMOUSEB",
  "tMOUSEMOD", "tTRIM", "tLTRIM", "tRTRIM", "tSTRING2", "tREPLACE",
  "tINSTR", "tRINSTR", "tCHOMP", "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2",
  "tPOKE", "tFRNFN_CALL", "tFRNFN_CALL2", "tFRNFN_SIZE", "tFRNBF_ALLOC",
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

#define YYPACT_NINF (-1476)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-528)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     902, 11210,  9757, 10661,   119,   165,    32,   -56,   -52, -1476,
   -1476, -1476, -1476, -1476,   160,   160,   160,  7150, -1476, -1476,
   -1476, 10661, -1476, -1476, 10661,    20,    52, -1476, -1476, -1476,
    9757,   -11, -1476,  9757,   255, -1476,  9757,  9757,  9757,   404,
      34,   160,  3258,  2037,  3809,    98,  9757,  6439,  7387,   512,
      14,  9757, -1476,   132, 10661, 10661, 10661,    23,  9757,  1341,
    9757,  9757,  7624,  7861,  6676,  5491,  9757,  5965,  8098,  8335,
   10108, 10661, 10661,   -30,  6202,  8572,  9757,  8809,  9757,  9757,
    5254,  5728,  4780,  5017,  9046,  9283,  -118,  -101,   -97,   -75,
     -62,  3809, 10661, 10661, 10661, -1476,   153, -1476, -1476,    73,
   -1476, -1476, -1476, -1476,   136,   147, -1476,   183, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476,   -13,    60, -1476, -1476,
   -1476, -1476,    64,    91,   108,   120,  9757,   144,   152,   177,
     192,   219,   222,   362,   230,   233,   244,   247,   101,   262,
     -20,   -17,   -47,   -28,   -26,   -15,   163,   326,   281,   291,
     354,   356,   372,   380,   392,   405,   411,   415,   417,   456,
     474,   480,   493,   531,   534,   542,   593,   608,   632,   640,
     648,   686,   700,   704,   719,   722,   725,   736,   737,   752,
     759,   761,   762,   769,   773,   775,   776,   783,   789,   790,
     818,   820,   828,   829,   835,   841,   842,   851,   878,   898,
     899,   900,   912,   920,   921,   930,   931,   932,   933,   945,
     962,   976,   984,   987,   999,  1006,  1028,  1035,  9757,  9757,
     254, -1476,    99, -1476, -1476, -1476, -1476,    95,   377,   408,
     440, 10661,   -37,   228,   136,   147,   516, -1476,  9757, -1476,
   10661, -1476,   711,  9757, 11004, -1476, -1476, -1476, -1476, -1476,
     479,   771,   579,   582,   382, -1476,  9757, -1476,   382, -1476,
   -1476,  9757, 11004,   242,  1039,   594,  1041,    13,  9757,    22,
     254,  1951,  1063,  1064,   430,  1951,   254,  9780,   254, 11648,
    1065,  1066,   510, -1476, -1476,   877,   877, -1476, -1476,   526,
   -1476,  6913, 10661,  9757,     3,  1951,   563,   362, -1476, -1476,
   -1476,   565,  9757, 10661, 10661, 10661, 11663, -1476,  9757, -1476,
      15, 10661,   597, -1476, -1476,  9757,  9520, -1476, -1476,  1951,
   -1476, -1476,   382,     4,     4, -1476,    15,  9757,  9757,  9757,
    9757,  9757,  9757,  9757, 10661, 10661,  9757,  9757,  9757,  9757,
      15,    15, 10661,   619, 10661,   627, 10661, 10661,    15, 10661,
   10661, 10661, 10661,    15,   669, 10661, 10661, 10661,    15, 10661,
      15, 10661,   823, 10661,    10,    41,    62, 10661, 10661, 10661,
   10661, 10661,    15, 10661,    15,    15, 10661,    15,    15,    15,
   10661, 10661, 10661, 10661, 10661,    15, 10661, 10661, 10661, 10661,
      15, 10661, 10661, 10661, 10661, 10661, 10661, 10661,    15, 10661,
   10661, 10661, 10212, 10661, 10661,    15, 10661,   853, 10661,   869,
     735,   735,   735,  4054, 10661,   749,   903,   382,   134,   195,
   -1476,  1077,  9757,  9757,  9757,  9757, 10661, -1476, -1476, -1476,
    9757,  9757,  1107,  9757,  9757,  9757,  9757,  3566,  3809, 10661,
   -1476,   670,   670,  9757,  9757, 10661, 10661, 10661, 10661, 10661,
   10661, 10661, 10661, 10661, 10661, 10661, 10661, 10661, 10661, 10661,
   10661, 10330, 10661, 10661, 10661,  9757,  9757,  9757,  9757,  9757,
    9757,  9757,  9757,  9757,  9757,  3809,  9757,  9757,  9757,  9757,
    9757,  9757,  9757,  9757,  4296, 10661, 10661, 10661, 10661, 10661,
    9757,  9757,  9757,  4538,  9757, 10661,  9757, 10661,  9757, 10661,
   10661,     5,   560,  9880,  9984, 10661, 10661, 10661,  9757, 10661,
   10661, 10661, 10661, 10661, 10661,  3809, 10661, -1476, -1476, 10661,
    9757, 10661, 10661, 10661, 10661, 10661,   875,   910, 10661,   735,
   10661,   735, 10661, 10661, 10661,  1180,    29,  1052, 10661, 10661,
   10661, 10661, 10661, 10661, 10661, 10661, -1476, -1476, -1476,  9757,
    9757,  9757,  9757,  9757,  9757,  9757,  9757,  9757,  9757,  9757,
    9757,   -59, -1476, -1476, -1476,  1951,   985,   382,  1083,  1141,
    1951,   598, -1476, -1476, -1476, -1476,  1093,  1104,  1084, -1476,
    1113,  1124,  1087, -1476,   254,  1951,  1096, -1476,   254,  1951,
    1331,   852,  1329, 11004,  9757,  1163, 10661, -1476, -1476,  9757,
     254,   844,   302,  1182,  1335,  1196,    18, -1476,  1412, -1476,
   -1476,   679,  9757,  9757, -1476, -1476,   404, -1476, -1476,    54,
   11686,   382,  1951,   610, 10434,  9757,    15,   382,   382,   286,
    9757, -1476,    22, -1476, -1476,  9757,   472, 10661, -1476,  9757,
      15,  9757,  9757,  9757,  1153,    15,  1181,    15,  1198,    15,
      15,   634,   382,  1201,  1204,    15,    15,  9757,  9757,   636,
   10661,   660, 10661,   382,   661,  9757,   667,   382,   668,   703,
    9757, 10661,   707,   709,   713,  9757,   724,  9757,   727, 10661,
     745,  9757, 10661, 10661,   757,   778,   788,   813,   814,  9757,
     815,  9757,  9757,   816,  9757,  9757,  9757,   382,   822,   825,
     382,   832,  9757,   382,   864,   868,   870,  9757,   382,   872,
     876,   382,   919,   948,   949,  9757,   969,   382,   970, 10661,
     971,   972,   986,  9757,  1002, 10661,  1013, 10661,  1210,  1221,
    1228,  1236, -1476,  1540,   -38,  9757,  9757,  9757,  9757, -1476,
    1243,    15,    15,  1951,   382,   833,  1244,  1253, 11710, 11725,
    1579, 11744, 11840, 11863,  1265,   396,  1258,  1266,  1014,  1260,
    1301,  1281,  1303,  1271,  1293,    15, 11902,  1024,   -23,   382,
     382,   382,   382,   382,   382,  1026,   382,   382,  1037,   382,
     382,  1043,   382, 10661,   382,  1044,   382,  1056,  1727,  2248,
    2306,  2322,  2499,   860,  2514,  1076,  2540,  2560,  1313,  2598,
    2697,  2775,  2809,  2836,  2912,  2967, 11921, -1476,  3113,   -19,
    1060,  1062,  1079,    -1, 11936, 11951,   475,  1095, -1476,  3318,
    3441,    40,  3462,  -204,  3831,    49,    50, -1476,    96, -1476,
     113, -1476,   125, -1476,   138,   181,   289,   337, 11966,  1080,
    1082,  1086,   352,   361,   425,   655,  1316,  -116,  1323,  1327,
     427,  3869,   429,  -103,  1088,  1098,  1126, -1476, -1476,  1127,
    -216,  1128,  -172,  1129,   433,   441, -1476, -1476,   382,   382,
     382,   382,   382,   382,   382, -1476,  9757,  9757,  1123,   551,
     339,   721,   626,   330,   191, -1476,    -6,    -6,  1180,  1180,
   -1476, -1476, -1476, 11004, -1476, -1476,  9757, -1476, -1476, -1476,
   -1476,   160,   160, -1476, -1476,   579, -1476, -1476,   582,  9757,
   -1476,  1443, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
     768, 11981,  9757,   180,  4076, 10779, -1476, -1476,  9757,  9757,
    1310, 10661, -1476, -1476,  9757, -1476,   845,  1330,  1339,  1355,
    1362, 11996, 12017,  1363,  1364, -1476, -1476, -1476,  9757,  1521,
    1524, -1476,  1136, 12040,  9757, 10661,  1951, -1476, -1476, 10661,
    1139, -1476,  9757, 12055, 12079,  1378, 10661,  9757,  9757,  9757,
   10661,  9757,  9757,  9757,  9757,  9757,  9757,  9757,  1390,  1396,
    9757,  1140,  9757,  1146,  9757,  1403, 10661, 10661, 10661,  1405,
    1148, 10661, 10661,  9757,  1406, 10661,  1420,  9757,  1149, 10661,
   12173,   382,   382, 10661, 10661,  9757, 10661,  9757,  1421, 10661,
    1425,  1426,  9757,  1427,  1428,  1429,  9757,  9757,  9757,  1430,
   10661,  9757,  9757,  1431, 10661,  9757, 10661, 10661,  9757,  1432,
   10661,  9757,  1150,  9757, 10661,  9757,  1433, 10661,  1152,  9757,
    1167, -1476,  9757,  9757,  9757, -1476, -1476,   254,  1951,   254,
    1951, 12194, 12232, 11004,  9757,  9757,  9757, -1476, -1476, -1476,
   -1476, -1476,  9757,  9757, -1476,  9757,  9757,  9757, -1476, 10661,
   -1476, 10557, -1476, 10661,  1434,  1435, -1476, -1476,  9757,  9757,
    9757,  9757, 10661, -1476,  9757,  9757,  9757,   382,  9757, 10661,
   -1476, -1476, -1476, -1476, -1476,  9757, -1476, -1476,  9757, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
    9757, -1476, -1476,  9757,  9757,  9757, -1476,  9757,  9757, -1476,
   10661, -1476, -1476, -1476, -1476, -1476,  9757, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, 10661, 10661,
   10661, 10661, -1476, -1476, -1476, -1476, -1476, 10661, -1476, -1476,
   -1476, -1476, -1476, -1476,  9757, -1476,  9757,  9757,  9757,  1671,
   10661, -1476,  1671, 10661, -1476, 10661, -1476, -1476,  1107,   739,
    9757,    78,  1951, -1476,  1438, -1476,  1441,  1437,  1440, -1476,
    1442,  1444, -1476, -1476, -1476,   873, 11004, -1476, -1476, -1476,
    9757, 12256, 10661,  1627, -1476, 10661,   382,   254,   844, 12271,
    9757,   189,   845,   845,  4114,  1446,  1447, -1476,  1445, -1476,
   -1476, -1476, -1476,  9757,  9757, -1476, -1476, 12286,  3809,  3809,
   10661, 10661,  1449,  1175,   382, 10661, -1476,  9757,  9757, 10661,
     382,  1450, 12301,    15,  1176,  1451,    15,   254, 12316, 12331,
   12350,    15,  1452, 10661, 10661,  1951, 10661,  1951, 10661,   254,
    1951, 10661,  1177,   382,   382, 10661, 10661,  1178,  1179,   756,
    1951, 10661,  1187, 10661,  1951, 10661,  1200, 10661,  1212,  1213,
    1951,   382,  1951, 10661,  1225, 10661, 10661,  1951, 10661, 10661,
   10661,   254, 12371,   254,  1951,  1951, 10661,   382,  1951,  1951,
   10661,  1229,   973,  1951,   382,   382,  1951, 10661,  1242, 12386,
    9757,  1951,  1250,  1951, 10661,   382, 10661, 12409, 10661,  1453,
    4318,  4356,  1161, 10661, 10661, -1476,  1951,    15, -1476,  1455,
    4560,  4598,  5987,  6224,  6461,   476,  1458,   251,   382, -1476,
   -1476,  6935,  7172,  1460,    43,  1252,  1951,  1951,  1951, 12508,
     382,  7409,  7646,  7883,  8120,  8357,  1278,  8594,  8831,   317,
    9068,   497,  1256,   320,   376,   498,  9305, 12527, 12563,  9542,
       0,   509,   117,   511,   517,    84, -1476, -1476, -1476,   160,
     160, -1476, -1476, -1476, -1476,  9757,  1653,  1661,  1662, 10204,
    9757,   525,  1463,   399, -1476,  9757, 12586, 10661,  1650, -1476,
   -1476, -1476, -1476, -1476, -1476,  1466,  1467,  1951,  1951, 10661,
   -1476, -1476,   382,   382, 10661, 10661,  1259, 12601,  1951,  1262,
   10661, 10661,  9757, 10661, 10661,  9757,  9757,  9757,  9757,  9757,
    9757,   382,  1269,  1270,  1282,  1289,  9757,  1290,  1291, 10661,
    9757,  9757,  1292, 10661,  1299,  1300,  9757,   382,  9757,  9757,
    1306, 10661,  1308,  1309,  1317,  1319,  1326, 10661,  1336,  1340,
    9757, 10661,  1343,  9757,  9757,  1951,  9757,  1344,  1347,  9757,
     382, -1476,  1637,  1638,  9757,  1639,  1350,   382,  9757,   922,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, 10661, -1476, -1476,
   -1476, -1476,  9757, 10661,  9757, -1476, -1476, -1476, -1476, -1476,
    9757, -1476, -1476, -1476, 10661, -1476, -1476, -1476, 10661,  9757,
   -1476,  9757, -1476, -1476, -1476, 10661,  9757, -1476, 10661, -1476,
   -1476, 10661, -1476, -1476, -1476,  9757, -1476, -1476, -1476, -1476,
   -1476,  1667,   893, 10652,  1658,  9757, 10661, 10837,  9757,   527,
    1474,  1412,   845,  1475,  1476,   845, -1476, -1476,   382,  1357,
     382, 10661, 10661, 10661,   382,   382,  1483,   382,   382,    15,
   12616, 12631, 12646,    15, 12661, 10661,  9757,  9757, 10661, 12685,
    9757, 10661,   382, 12704,  1951, 10661,  1358, 10661,  9757, 12719,
   12740,   254,  1951, 10661,   382, 10661,  9757,  9757, 10661, 10661,
     382,  9757, 10661,  1017,  1951,   382,  9757, 12838, 12862, 12896,
    9757, 10661, 12917, 10661, 10661, 10878, 10661,  9757, -1476,  1485,
    1486,   130, -1476,   529, 12932,   382,  1951, 11126,   539,   556,
   11332, 11411,   562, 11509,   564,   596,   618, 11004, 11416,  9757,
    1686, -1476,  1491, -1476,  1493, 12947,   615,   911, 11533,  1660,
    9757,   845, -1476, -1476, -1476, -1476, 10661,   382,   382,   382,
   10661,  9757,  9757, 10661,  9757,  9757,  9757,  1359, 12962, 12977,
    1360,  9757, 12992,  1384,  9757,  1385,  9757,  1386, 13015,  9757,
    9757,  1392,  1393, 13039, 13054,   382,   382, 13073,  1394,  9757,
   13169,  9757,  9757,  9757, 13192,  1402,  9757,   382,   382,  1666,
     382,  1951,  1499,  1500,   922, -1476, -1476,  9757, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476,  9757, -1476,  1662,
    1699,   965, 11004, -1476, 10661,  9757,  9757, -1476, -1476,  1502,
    1412, -1476,  1505,  1412, 13231, -1476,   382,   382,  1508, 13250,
     382, 13265,  1509, 13280, 10661, 10661, 10661, 10661, 13295, 10661,
   10661, 13310,  9757,  1951, 10661,  9757,  1951, 13325, 10661,  9757,
    9757, 10661, 10661, 10661,  1951, 10661, 13346, 13369, 13384, 10661,
   10661,  1951, 10661, -1476, -1476, -1476, 11004, 11567,  1951, 11004,
   -1476, -1476,  1662,  1059,   409, 13408, 11588,  1412, 10661,   845,
    1412,  9757,   845,  9757, 10661, 10661,  9757, 10661, 10661,   382,
     382,   382,  1404,  9757,   382,   382,  9757, 13502,  1422, 13523,
    9757,   382, 13561, 13585,   382,   382,   382,   382,  9757, 10661,
    9757,  1423,   382,   382,    86, -1476,  1662, 11004, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, 10661, -1476,  9757, -1476,   845,
     419, -1476,   845, 13600, -1476, 11603,   382,   382, 13615,   382,
     382, 10661,  1951,  1951,  9757, 10661,  9757,  1951, 10661, 10661,
    1951,   382, 13630, 10661, -1476, -1476, -1476,  1251,  1662,   616,
   11618, -1476, 10661, -1476, -1476,  9757, -1476, 10661,   382, 13645,
     382, 13660,   382,   382,  9757,   382, -1476, -1476, -1476, -1476,
   -1476, -1476,  1748,  1667, -1476, -1476,   630,  1412, 11633,  1412,
     382, 10661, 10661, 13679, -1476, -1476, -1476, -1476,   845, -1476,
     845,  1424,   382, 10661,  1412, -1476,  1412, -1476, 10661,   382,
     845,   845,   382, -1476, -1476
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   219,     0,     0,     0,   456,     0,     0,     0,   213,
     479,   514,   519,    18,     0,     0,     0,     0,    31,    33,
     457,     0,   441,   441,     0,   458,    25,    27,   494,   506,
       0,   603,    55,    67,     0,   210,   211,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   220,
     221,     0,   201,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   202,
       0,     0,     0,     0,     0,     2,     9,    17,     8,     0,
      12,    46,    48,    14,    29,    30,    28,     0,    20,    21,
      24,    23,    22,    35,    36,   429,   321,   241,   430,   431,
     432,   244,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   255,     0,     0,     0,
       0,     0,     0,     0,   381,   384,   387,   390,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
     274,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   242,     0,   335,   315,   320,   243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,   441,
       0,   441,     0,     0,    16,   434,   433,    37,    38,    45,
       0,     0,     0,     0,    19,    50,   443,    51,    49,   459,
      26,     0,    16,   538,     0,   607,     0,     0,   567,   599,
      69,    68,     0,     0,    70,   212,    60,     0,    62,     0,
     559,   561,    63,   557,   563,     0,     0,   564,   426,    64,
      66,     0,   197,     0,     0,   618,     0,    92,   199,    86,
      47,     0,     0,     0,     0,     0,     0,    74,     0,    57,
      79,     0,     0,    94,    93,     0,     0,   222,   223,   200,
      13,    15,   214,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   215,     0,     0,
       7,     0,     0,     0,     0,     0,     0,   448,   441,   441,
       0,     0,   305,     0,     0,     0,     0,     0,     0,     0,
     411,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   441,   441,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   327,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,   303,   301,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     5,     6,   299,     0,   224,     0,     0,
     515,     9,    39,    40,    41,    43,   462,   463,    32,   460,
     468,   469,    34,   466,   446,   447,   442,   444,   499,   498,
       0,     9,     0,    16,     0,     0,     0,   604,   605,     0,
     570,   572,    52,     0,     0,     0,     0,    56,   601,   441,
     441,     0,     0,     0,   441,   441,     0,   428,   427,     0,
       0,   198,   617,     0,     0,     0,     0,    96,    73,     0,
       0,    78,   599,   231,   230,     0,     0,     0,    75,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,     0,     0,     0,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   166,     0,     0,
     167,     0,     0,   172,     0,     0,     0,     0,   181,     0,
       0,   184,     0,     0,     0,     0,     0,   191,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   239,     0,
       0,     0,   203,     0,     0,     0,     0,     0,     0,    10,
       0,     0,     0,   300,   229,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   277,
     279,   278,   280,   414,   413,     0,   416,   415,     0,   418,
     417,     0,   421,     0,   419,     0,   285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   361,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,   382,     0,   385,
       0,   388,     0,   391,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   273,   275,     0,
       0,     0,     0,     0,     0,     0,   246,   336,   330,   332,
     334,   331,   333,   328,   329,   245,     0,     0,   308,   310,
     312,   309,   311,   306,   307,   326,   323,   322,   324,   325,
     439,   440,   480,    16,   526,   524,     0,   525,   521,   523,
     520,     0,     0,   441,   441,     0,   441,   441,     0,     0,
     496,   500,   513,   511,   512,   509,   508,   510,   507,   528,
       9,     0,     0,     0,     0,     0,   568,    53,    54,     0,
       0,     0,   575,   577,     0,   602,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   558,   565,   566,     0,     0,
       0,   234,   233,   237,     0,     0,   339,    58,    76,     0,
      89,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   114,   148,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   441,     0,     0,     0,   204,   205,   206,   207,   208,
     209,     0,     0,    16,     0,     0,     0,   454,   455,   449,
     403,   295,     0,     0,   394,     0,     0,     0,   404,     0,
     405,     0,   398,     0,     0,     0,   316,   317,     0,     0,
       0,     0,     0,   425,     0,     0,     0,   420,     0,     0,
     340,   341,   342,   343,   344,     0,   345,   347,     0,   348,
     350,   351,   313,   357,   358,   352,   354,   355,   356,   353,
       0,   360,   365,     0,     0,     0,   364,     0,     0,   254,
       0,   251,   257,   258,   366,   293,     0,   367,   294,   259,
     260,   380,   383,   386,   389,   263,   261,   262,     0,     0,
       0,     0,   266,   373,   267,   379,   378,     0,   276,   374,
     268,   375,   269,   377,     0,   270,     0,     0,     0,     0,
       0,   288,     0,     0,   290,     0,   410,   298,   304,   302,
       0,     9,   522,   619,    42,   621,    44,     0,     0,   461,
       0,     0,   467,   445,   497,   503,    16,   540,   541,   539,
       0,     0,     0,   608,   606,     0,   573,   571,   572,     0,
       0,     0,     0,     0,     0,   553,   555,   600,   550,   435,
     437,   441,   441,     0,     0,   560,   562,    71,     0,     0,
       0,     0,     0,     0,   121,     0,    77,     0,     0,     0,
     102,     0,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,   117,     0,   119,     0,   124,
     125,     0,     0,   129,   128,     0,     0,     0,     0,     0,
     137,     0,     0,     0,   144,     0,     0,     0,     0,     0,
     151,   150,   152,     0,     0,     0,     0,   157,     0,     0,
       0,   161,     0,   163,   164,   165,     0,   169,   171,   170,
       0,   174,   177,   178,   182,   183,   180,     0,     0,     0,
       0,   188,     0,   190,     0,   194,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    87,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   412,   337,
     338,     0,     0,     0,     0,   423,   281,   282,   283,     0,
     422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   518,   517,   516,     0,
       0,   464,   465,   470,   471,     0,     0,     0,   529,     0,
       0,     0,     0,     0,   569,     0,     0,     0,   589,   576,
     578,   579,   441,   441,   551,     0,     0,    59,    61,     0,
     235,   236,   232,   238,     0,     0,    90,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   189,     0,     0,     0,     0,
     195,   240,     0,     0,     0,     0,   217,   218,     0,   472,
     392,   393,   395,   396,   397,   406,   407,     0,   408,   318,
     319,   291,     0,     0,     0,   346,   349,   359,   247,   248,
       0,   250,   362,   363,     0,   252,   368,   264,     0,     0,
     369,     0,   371,   286,   271,     0,     0,   297,     0,   400,
     287,     0,   402,   289,   314,     0,   620,   622,   501,   504,
     495,   544,   610,     0,   609,     0,     0,     0,     0,     0,
       0,   601,     0,     0,     0,     0,   436,   438,    72,     0,
      97,     0,     0,     0,   103,   106,     0,   101,   104,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   134,     0,   135,     0,     0,     0,     0,   139,
       0,   145,   146,     0,   154,     0,     0,     0,     0,     0,
     162,     0,     0,     0,   176,   179,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,   475,
     476,     0,   473,     0,     0,   424,   284,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   490,    16,   219,     0,
     542,   614,     0,   611,     0,     0,     0,   581,     0,   591,
       0,     0,   580,   554,   556,   552,     0,   120,    82,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   158,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,     0,
     226,   216,     0,     0,     0,   450,   409,     0,   249,   253,
     265,   370,   372,   376,   296,   399,   401,     0,   481,   502,
       9,   548,    16,   530,     0,     0,     0,   574,   593,     0,
     601,   583,     0,   601,     0,   590,    95,   110,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   142,     0,     0,   140,     0,     0,     0,
       0,     0,     0,     0,   175,     0,     0,     0,     0,     0,
       0,   196,     0,   477,   478,   474,    16,     0,   491,    16,
     549,   545,   543,     0,     0,     0,     0,   601,     0,     0,
     601,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     116,   118,     0,     0,   127,   122,     0,     0,     0,     0,
       0,   149,     0,     0,   156,   160,   168,   173,     0,     0,
       0,     0,   193,   225,     9,   292,   482,    16,   537,   534,
     535,   536,   532,   533,   531,     0,   615,     0,   612,     0,
       0,   582,     0,     0,   592,     0,   109,   100,     0,   111,
     105,     0,   131,   136,     0,     0,     0,   147,     0,     0,
     192,   187,     0,     0,   453,   452,   451,     0,   546,     0,
       0,   594,     0,   595,   584,     0,   585,     0,   123,     0,
     141,     0,   153,   155,     0,   185,   485,   487,   488,   489,
     484,   486,   492,   544,   616,   613,     0,   601,     0,   601,
     108,     0,     0,     0,   493,   483,   547,   597,     0,   587,
       0,   132,   143,     0,   601,   596,   601,   586,     0,   186,
       0,     0,   133,   598,   588
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1476, -1476, -1476,  -238, -1476, -1476,  1749,   701, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476,  1702,   232, -1476, -1476,  -267,
      -3, -1476,  1703,  1439, -1476, -1476,  1320,  -441,  2641, -1476,
    1142,   -31,   -12, -1476,     1,     7,    35, -1476, -1476,   849,
    1754, -1476, -1476, -1476, -1476, -1476, -1476, -1476,   859, -1476,
     861, -1476,    83, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476,   393, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,  -100,
   -1476, -1476, -1476, -1190, -1476, -1476, -1476,  1154, -1476, -1476,
     584,  1151, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1475, -1476,     2, -1476, -1476
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,    95,    96,   421,  1053,    97,    98,   252,   253,
     901,   902,   269,   632,    99,   100,   635,   101,   102,   729,
     220,   221,   103,   306,   877,   876,   761,   762,   307,   223,
     287,   224,   247,   274,   225,   226,   255,   256,   586,   587,
     106,   745,  1319,  1756,  1846,  1059,   107,   578,   579,   582,
     583,  1601,  1602,   108,   242,  1170,  1759,  1847,  1872,  1698,
    1885,   109,   261,   911,   590,  1185,  1617,  1377,  1618,   110,
     262,   918,   111,   243,   893,  1368,   112,   244,   900,   113,
     592,  1186,  1521,  1763,  1814,   114,   593,  1189,  1703,  1620,
    1807,  1873,  1761,  1207,  1535,  1208,   282,   283,   289,   602,
     926,   607,  1202,  1203,  1532,  1710,  1770,  1879,  1896,  1531,
    1713,  1767,  1877,  1894,   608,   936,   268,   296,  1174,  1176
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     232,   764,   104,   248,   249,   234,   571,   562,   105,   288,
     117,   235,  1389,  1390,   623,   121,   633,   597,   254,   238,
     598,   258,   932,   240,   591,   933,  1160,   633,  1161,   290,
     270,   367,   237,   545,   276,   278,   123,   115,  1126,   294,
    1127,   118,   119,   120,   284,   300,   301,   264,   259,   265,
     266,   322,   323,   324,   234,   633,  1631,   115,   257,   260,
     235,   118,   119,   120,   946,   451,   452,   364,   365,   366,
    1163,   556,  1164,   538,   539,   540,   541,   542,   543,   544,
     603,   368,   604,   605,   454,   455,   457,   458,   415,   417,
     418,   419,   447,   416,  1366,   449,  1515,   460,   461,   538,
     539,   540,   541,   542,   543,   544,   547,   548,   453,   318,
     136,  1844,   137,   549,   550,   551,   552,   553,   554,   555,
     556,   545,  1367,     7,     8,   410,  1147,   456,  1148,   459,
    1845,   140,   141,   325,   545,   448,     7,     8,   450,  1154,
     462,  1155,   411,   546,   730,   731,   412,   547,   548,   227,
     228,   229,   230,   146,   549,   550,   551,   552,   553,   554,
     555,   556,   547,   548,   245,   422,   423,   246,   413,   549,
     550,   551,   552,   553,   554,   555,   556,   424,   545,   302,
     303,   414,   169,   170,   171,   866,   304,   239,   175,   176,
     177,   241,   179,    20,   181,   182,   183,   420,    25,   545,
     545,   188,   189,   190,   191,   192,  1046,   427,   195,   305,
     197,   425,   199,   445,   545,   201,   536,   203,   545,    53,
     205,  1083,   426,   207,   208,  1112,   209,   210,   561,   212,
     239,   214,   559,   560,   267,  1769,   545,   567,  1772,   217,
     545,   545,  1508,  1116,  1509,   104,   634,   545,   231,   827,
     453,   105,   681,   584,   617,   618,   599,   634,   588,   272,
     273,   934,   860,   104,   862,   600,   545,   606,   556,   105,
     285,   286,   563,   866,   566,   463,   568,   545,   545,   557,
     558,   559,   560,   682,  1124,   634,   545,   545,  -527,   621,
     285,   286,  1819,  1129,  1130,  1822,    86,    87,    88,   545,
     627,   628,   629,   241,   683,   547,   548,   428,   636,    86,
      87,    88,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   538,   539,   540,   541,   542,   543,
     544,   651,   652,   545,   429,   557,   558,   559,   560,   659,
    1131,   661,  1632,   663,   664,  1635,   666,   667,   668,   669,
     545,   430,   672,   673,   674,   920,   676,  1132,   678,  1511,
     680,  1512,   545,   431,   684,   685,   686,   687,   688,  1133,
     690,   545,  1684,   693,  1685,   545,   737,   697,   698,   699,
     700,   701,  1134,   703,   704,   705,   706,   433,   708,   709,
     710,   711,   712,   713,   714,   434,   716,   717,   718,   720,
     721,   722,  1888,   724,  1890,   726,   555,   556,   280,   281,
     550,   734,   552,   553,   554,   555,   556,   545,   545,  1900,
     435,  1901,  1192,   744,  1193,  1135,   545,   557,   558,   559,
     560,  1387,   545,  1388,   755,   436,   758,   738,   464,   756,
     757,  1715,   767,   768,   769,   770,   771,   772,   773,   774,
     775,   776,   777,   778,   779,   780,   781,   782,   784,   785,
     786,   787,   437,   746,   747,   438,   538,   539,   540,   541,
     542,   543,   544,   441,   439,   440,   442,   798,   557,   558,
     559,   560,   809,   810,   811,   812,   813,   443,   545,   816,
     444,   545,   821,  1477,   823,  1478,   825,   826,   828,   830,
     832,   834,   835,   836,   837,   446,   839,   840,   841,   842,
     843,   844,   845,   847,   572,   573,   850,   846,   852,   853,
     854,   855,   856,   545,   465,   859,   545,   861,   955,   863,
     864,   865,   456,  1136,   466,   868,   869,   870,   871,   872,
     873,   874,   875,   927,   928,   538,   539,   540,   541,   542,
     543,   544,   848,   849,   545,   641,   642,   545,   643,  1494,
     564,  1495,  1499,   459,  1500,   117,   557,   558,   559,   560,
     121,   313,   657,   658,   545,   557,   558,   559,   560,  1821,
     665,  1137,  1824,   576,   577,   670,   580,   581,   288,   545,
     675,   123,   677,   923,   104,   462,  1142,   467,   545,   468,
     105,   314,   315,   316,   689,  1143,   691,   692,   317,   694,
     695,   696,   894,   545,   895,   469,   896,   702,  1501,   545,
    1502,   952,   707,   470,   552,   553,   554,   555,   556,  1851,
     715,  1697,  1854,   545,   960,   471,   545,   723,  1069,   897,
    1070,  1526,   898,   866,   937,   938,   545,   899,   472,   943,
     944,  1815,   595,  1816,   473,  1171,   545,   981,   474,   983,
     475,  1852,   545,  1853,   545,   136,   545,   137,   990,  1144,
     545,  1151,   611,  1153,   759,   760,   998,  1166,   545,  1001,
    1002,   547,   548,   939,   940,  1167,   140,   141,   549,   550,
     551,   552,   553,   554,   555,   556,   949,   950,  1895,   476,
    1897,   554,   555,   556,   227,   228,   229,   230,   146,   545,
    1903,  1904,   545,   545,   959,   569,  1032,   477,  1360,  1119,
    1475,  1362,  1038,   478,  1040,   538,   539,   540,   541,   542,
     543,   544,  1047,  1049,   545,   545,   479,   169,   170,   171,
     728,  1497,  1503,   175,   176,   177,   545,   179,   545,   181,
     182,   183,   616,  1510,   545,  1513,   188,   189,   190,   191,
     192,  1514,   545,   195,   545,   197,   545,   199,   619,  1524,
     201,  1629,   203,  1686,   480,   205,   545,   481,   207,   208,
    1087,   209,   210,  1689,   212,   482,   214,   557,   558,   559,
     560,   574,   575,   545,   217,   553,   554,   555,   556,   545,
    1690,   545,   547,   231,   829,   624,  1693,   625,  1695,   549,
     550,   551,   552,   553,   554,   555,   556,  1187,  1188,   538,
     539,   540,   541,   542,   543,   544,   538,   539,   540,   541,
     542,   543,   544,   545,   547,   548,   483,  1057,  1058,   637,
    1696,   549,   550,   551,   552,   553,   554,   555,   556,  1205,
    1206,   484,   545,   545,   557,   558,   559,   560,   954,  1707,
    1874,   660,   557,   558,   559,   560,   912,   545,   913,   662,
     914,   545,   962,   545,  1887,   485,   973,   967,   980,   969,
     115,   971,   972,   486,   118,   119,   120,   976,   977,  1173,
    1175,   487,   545,   915,   104,   925,   916,   545,   545,  1145,
     105,   917,   982,   984,   545,   545,   584,   547,   548,   986,
     987,   671,  1375,  1376,   549,   550,   551,   552,   553,   554,
     555,   556,  1196,   547,   548,  1197,  1599,  1600,  1201,   488,
     549,   550,   551,   552,   553,   554,   555,   556,  1177,  1178,
     545,  1180,  1181,   489,   545,   988,   545,   490,  1378,   991,
     545,   992,  1223,  1621,  1622,   993,  1224,   557,   558,   559,
     560,   545,   491,  1230,   545,   492,   995,  1234,   493,   997,
    1237,  1708,  1709,  1055,  1056,   557,   558,   559,   560,   494,
     495,  1249,   545,  1252,  1253,  1254,   545,   999,  1257,  1258,
    1259,   735,  1262,   545,   545,   496,  1266,  1080,  1431,  1003,
    1268,  1269,   497,  1271,   498,   499,  1274,   557,   558,   559,
     560,  1760,   500,  1281,  1283,   545,   501,  1287,   502,   503,
    1004,  1291,  1292,  1294,  1295,   545,   504,  1298,   547,   548,
    1005,  1302,   505,   506,  1305,   549,   550,   551,   552,   553,
     554,   555,   556,   538,   539,   540,   541,   542,   543,   544,
     545,   545,   545,   545,   104,  1006,  1007,  1009,  1012,   545,
     105,   507,   545,   508,  1016,   679,  1325,  1017,  1327,   545,
    1328,   509,   510,  1808,  1018,  1809,  1309,  1810,   511,  1335,
     557,   558,   559,   560,   512,   513,  1340,   538,   539,   540,
     541,   542,   543,   544,   514,   725,   557,   558,   559,   560,
    1811,   545,  1095,  1812,  1096,   545,  1020,   545,  1813,   545,
    1021,   727,  1022,   545,  1024,   547,   548,  1349,  1025,   857,
     739,   515,   549,   550,   551,   552,   553,   554,   555,   556,
       1,     2,     3,     4,     5,  1351,  1352,  1353,  1354,   547,
     548,   516,   517,   518,  1355,   736,   549,   550,   551,   552,
     553,   554,   555,   556,   858,   519,   545,  1361,   547,   548,
    1363,  1026,  1364,   520,   521,   549,   550,   551,   552,   553,
     554,   555,   556,   522,   523,   524,   525,   549,   550,   551,
     552,   553,   554,   555,   556,   545,   545,   104,   526,  1381,
    1027,  1028,  1383,   105,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   527,   545,   545,   545,   545,
     545,  1030,  1031,  1033,  1034,  1451,   892,  1402,  1403,   528,
    1400,  1401,  1406,   545,   547,   548,  1409,   529,  1035,   890,
     530,   549,   550,   551,   552,   553,   554,   555,   556,   545,
    1421,  1422,   531,  1423,  1037,  1424,  1395,  1396,  1425,   532,
     545,   545,  1427,  1428,   545,  1039,  1073,   556,  1432,  1669,
    1434,   545,  1435,   545,  1437,  1866,  1082,  1867,  1084,  1868,
    1440,   533,  1442,  1443,   545,  1444,  1445,  1446,   534,  1085,
     545,   545,   594,  1448,   596,  1086,  1088,  1449,   557,   558,
     559,   560,  1869,   545,  1452,  1870,   867,   545,  1089,   545,
    1871,  1457,  1113,  1458,  1114,  1460,   609,   610,   614,   615,
    1466,  1467,   557,   558,   559,   560,   545,   545,  1098,   545,
    1099,  1115,  1139,   545,  1140,   545,   905,   891,  1141,   908,
    1156,   557,   558,   559,   560,   545,   903,  1120,   909,  1121,
    1157,   547,   548,   557,   558,   559,   560,   904,   549,   550,
     551,   552,   553,   554,   555,   556,   906,  1516,  1517,   557,
     558,   559,   560,   545,   545,   545,   545,   907,  1158,  1159,
    1162,  1165,   588,   545,   910,   919,   545,   545,  1220,  1699,
    1700,  1225,  1246,   545,  1529,   545,   545,   545,  1248,   545,
    1256,  1265,  1300,   930,  1306,   966,  1538,   557,   558,   559,
     560,  1539,  1540,  1464,   545,  1465,   922,  1544,  1545,  1308,
    1547,  1548,   545,   545,   545,   545,   545,  1405,  1413,  1426,
    1429,  1430,   935,   968,   545,   929,  1562,  1533,  1534,  1433,
    1566,   327,   328,   329,   330,   331,  1571,   545,  1574,   931,
     970,   222,  1436,   974,  1580,   332,   975,  1583,  1585,   545,
     545,   333,   334,  1041,  1438,  1439,   251,   335,   336,   337,
     338,   339,   545,  1042,  1762,  1412,   545,  1441,  1415,   263,
    1043,  1450,   271,  1419,  1603,   275,   277,   279,  1044,   545,
    1605,   295,   295,   295,  1453,  1054,  1184,   545,  1060,   545,
     319,  1608,  1456,   545,  1483,  1609,   545,  1061,  1498,   545,
    1071,  1541,  1612,  1074,  1543,  1614,   545,   545,  1615,  1068,
    1072,  1555,  1556,  1078,   557,   558,   559,   560,  1804,   545,
    1490,  1806,  1491,  1626,  1557,  1076,   545,   545,   545,   545,
     295,  1558,  1560,  1561,  1565,  1079,   545,   545,  1637,  1638,
    1639,  1567,  1568,   545,  1075,   545,   545,  1077,  1573,  1468,
    1575,  1576,  1647,  1200,   545,  1650,   545,  1102,  1653,  1577,
    1146,  1578,  1655,   545,  1657,   432,  1482,  1149,  1579,  1848,
    1661,  1150,  1662,   545,  1209,  1665,  1666,   545,  1581,  1668,
     545,   545,  1582,  1210,   545,  1586,  1590,   545,  1675,  1591,
    1677,  1678,  1597,  1680,   545,   545,   545,   545,  1211,  1636,
    1656,  1724,  1727,   547,   548,  1212,  1218,  1215,  1216,  1219,
     549,   550,   551,   552,   553,   554,   555,   556,   104,   104,
    1229,   545,   545,   545,   105,   105,  1730,  1732,  1734,   545,
     545,   545,  1243,  1716,  1738,  1739,  1743,  1717,  1244,   545,
    1720,   545,   547,   548,  1750,  1251,  1831,  1255,  1261,   549,
     550,   551,   552,   553,   554,   555,   556,   535,   537,   545,
     545,   545,  1263,  1273,  1835,  1843,  1898,  1275,  1276,  1278,
    1279,  1280,  1286,  1290,  1297,  1304,   760,   565,  1329,  1330,
    1369,  1371,   570,  1370,  1372,  1382,  1373,  1394,  1374,  1392,
    1393,  1404,  1410,  1414,  1420,   585,  1519,  1461,  1469,  1520,
     589,  1764,  1476,   104,  1481,    -9,  1525,   601,  1530,   105,
    1536,  1537,  1593,  1594,  1596,  1619,  1624,  1630,  1712,  1633,
    1634,  1779,  1780,  1781,  1782,  1640,  1784,  1785,  1682,  1683,
     620,  1788,   622,  1702,  1704,  1791,  1705,  -505,  1794,  1795,
    1796,  1752,  1797,  1753,  1754,  1768,  1801,  1802,  1771,  1803,
    1774,  1777,  1884,   233,  1315,   320,   321,   104,  1183,   236,
     104,   947,   763,   105,  1179,  1820,   105,  1755,  1518,  1182,
     945,  1826,  1827,  1886,  1829,  1830,   557,   558,   559,   560,
       0,  1641,  1384,   957,  1045,  1645,     0,     0,     0,     0,
     547,   548,     0,     0,     0,     0,  1841,   549,   550,   551,
     552,   553,   554,   555,   556,     0,     0,     0,   104,     0,
       0,     0,  1849,     0,   105,   557,   558,   559,   560,     0,
       0,     0,     0,  1064,     0,     0,     0,     0,  1858,     0,
       0,     0,  1860,     0,     0,  1862,  1863,     0,     0,     0,
    1865,     0,     0,     0,     0,     0,     0,     0,     0,  1876,
       0,     0,   733,     0,  1880,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   743,     0,     0,     0,     0,   748,
     749,     0,   750,   751,   752,   753,   295,   295,  1891,  1892,
       0,     0,     0,   766,     0,     0,     0,     0,     0,     0,
    1899,     0,     0,     0,     0,  1902,     0,     0,     0,     0,
       0,     0,     0,     0,   788,   789,   790,   791,   792,   793,
     794,   795,   796,   797,   295,   799,   800,   801,   802,   803,
     804,   805,   806,   808,     0,     0,     0,     0,     0,   814,
     815,   817,   819,   820,     0,   822,     0,   824,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   838,     0,     0,
       0,     0,     0,     0,   295,     0,     0,     0,     0,   851,
       0,     0,     0,   557,   558,   559,   560,     0,     0,     0,
       0,  1090,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   878,   879,
     880,   881,   882,   883,   884,   885,   886,   887,   888,   889,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   547,   548,     0,     0,     0,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,     0,
       0,     0,     0,   921,     0,     0,     0,     0,   924,     0,
     115,   116,   117,     0,   118,   119,   120,   121,     0,     0,
       0,   941,   942,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   953,     0,     0,   122,   123,   956,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     963,   964,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,     0,
    1000,   132,     0,     0,     0,     0,   297,     0,     0,     0,
       0,     0,     0,     0,   298,     0,     0,     0,   134,   135,
       0,     0,   136,     0,   137,     0,     0,   299,     0,     0,
       0,     0,   138,     0,     0,     0,     0,     0,     0,   139,
       0,     0,     0,   140,   141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1048,  1050,  1051,  1052,     0,     0,
       0,   142,   143,   144,   145,   146,   147,   557,   558,   559,
     560,     0,     0,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
       0,   204,   205,     0,   206,   207,   208,     0,   209,   210,
     211,   212,   213,   214,   215,     0,     0,     0,     0,     0,
     216,   217,     0,   218,     0,     0,     0,     0,     0,     0,
     219,     0,   293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   547,   548,     0,     0,  1168,  1169,     0,   549,   550,
     551,   552,   553,   554,   555,   556,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   585,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1191,     0,     0,     0,     0,     0,  1198,  1199,   547,
     548,     0,     0,  1204,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,     0,   547,   548,  1217,     0,     0,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
       0,     0,     0,     0,     0,     0,     0,  1232,     0,     0,
       0,     0,  1238,  1239,  1240,     0,     0,     0,     0,  1245,
       0,  1247,     0,  1250,     0,     0,     0,     0,     0,     0,
       0,     0,  1260,     0,     0,     0,  1264,     0,     0,     0,
       0,     0,     0,     0,  1270,     0,  1272,     0,     0,     0,
       0,  1277,     0,     0,     0,  1282,  1284,  1285,     0,     0,
    1288,  1289,     0,     0,  1293,     0,     0,  1296,     0,     0,
    1299,     0,  1301,     0,  1303,     0,     0,     0,  1307,     0,
       0,  1310,  1311,  1312,   557,   558,   559,   560,     0,     0,
       0,     0,  1091,  1316,     0,     0,     0,     0,     0,     0,
       0,  1320,  1321,     0,  1322,  1323,  1324,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1331,  1332,     0,
    1334,     0,     0,  1336,  1337,  1338,     0,  1339,     0,     0,
       0,     0,     0,     0,  1341,     0,     0,  1342,     0,     0,
       0,     0,   557,   558,   559,   560,     0,     0,     0,  1343,
    1092,     0,  1344,  1345,  1346,     0,  1347,  1348,   557,   558,
     559,   560,   547,   548,     0,  1350,  1093,     0,     0,   549,
     550,   551,   552,   553,   554,   555,   556,   547,   548,     0,
       0,     0,     0,     0,   549,   550,   551,   552,   553,   554,
     555,   556,     0,  1356,     0,  1357,  1358,  1359,     0,     0,
       0,     0,     0,   547,   548,     0,     0,     0,     0,  1365,
     549,   550,   551,   552,   553,   554,   555,   556,     0,     0,
       0,     0,     0,   547,   548,     0,     0,     0,     0,  1379,
     549,   550,   551,   552,   553,   554,   555,   556,     0,  1386,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1397,  1398,     0,     0,     0,   295,   295,     0,
       0,   547,   548,     0,     0,     0,  1407,  1408,   549,   550,
     551,   552,   553,   554,   555,   556,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   310,   312,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   326,
       0,   340,   341,   343,   345,   348,   353,   354,   358,   360,
     362,     0,     0,     0,     0,   372,   374,   375,   377,   378,
     379,   385,   390,   398,   405,   407,   409,     0,     0,     0,
       0,     0,     0,     0,     0,   557,   558,   559,   560,  1455,
       0,     0,     0,  1094,     0,     0,     0,     0,     0,     0,
     557,   558,   559,   560,     0,     0,     0,     0,  1097,     0,
     547,   548,     0,     0,     0,     0,     0,   549,   550,   551,
     552,   553,   554,   555,   556,     0,   557,   558,   559,   560,
       0,     0,     0,     0,  1100,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   557,   558,   559,   560,
       0,     0,     0,     0,  1101,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   589,     0,     0,     0,     0,  1523,
       0,     0,     0,     0,  1527,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   557,   558,   559,   560,   547,   548,
       0,     0,  1103,     0,     0,   549,   550,   551,   552,   553,
     554,   555,   556,     0,     0,  1550,  1551,  1552,     0,  1554,
       0,     0,     0,     0,     0,  1559,     0,     0,     0,  1563,
    1564,     0,   547,   548,     0,  1569,     0,  1570,  1572,   549,
     550,   551,   552,   553,   554,   555,   556,     0,     0,  1584,
       0,     0,  1587,  1588,     0,  1589,     0,     0,  1592,   547,
     548,     0,     0,  1595,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,     0,     0,     0,     0,     0,     0,
       0,  1604,     0,  1606,     0,     0,     0,     0,     0,  1607,
       0,     0,     0,   557,   558,   559,   560,     0,  1610,     0,
    1611,  1104,     0,   626,     0,  1613,     0,     0,     0,   631,
       0,     0,     0,     0,  1616,     0,   638,   640,     0,     0,
       0,     0,     0,     0,  1625,     0,     0,  1628,   644,   645,
     646,   647,   648,   649,   650,   547,   548,   653,   654,   655,
     656,     0,   549,   550,   551,   552,   553,   554,   555,   556,
       0,     0,     0,     0,     0,  1648,  1649,     0,     0,  1652,
       0,     0,     0,     0,     0,     0,     0,  1658,     0,     0,
       0,   557,   558,   559,   560,  1663,  1664,     0,     0,  1105,
    1667,     0,     0,     0,     0,  1670,     0,     0,     0,  1674,
     547,   548,     0,     0,     0,     0,  1681,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,     0,
       0,     0,     0,  1106,     0,     0,     0,     0,  1701,     0,
       0,     0,     0,   740,   741,   742,     0,     0,     0,  1714,
       0,     0,   557,   558,   559,   560,     0,     0,     0,     0,
    1107,  1719,     0,  1721,   765,  1723,     0,     0,     0,     0,
    1728,     0,     0,  1731,     0,  1733,     0,     0,  1736,  1737,
       0,     0,     0,     0,     0,     0,     0,     0,  1744,     0,
    1746,  1747,  1748,     0,     0,  1751,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1757,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1758,     0,     0,     0,
       0,     0,     0,     0,  1765,  1766,     0,     0,   557,   558,
     559,   560,     0,     0,     0,     0,  1108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1787,     0,     0,  1789,     0,   547,   548,  1792,  1793,
       0,     0,     0,   549,   550,   551,   552,   553,   554,   555,
     556,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   557,   558,   559,   560,     0,     0,     0,
    1823,  1109,  1825,     0,     0,  1828,     0,     0,     0,     0,
       0,     0,  1832,     0,     0,  1833,     0,     0,     0,  1837,
       0,     0,     0,     0,     0,     0,     0,  1840,     0,  1842,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1850,     0,     0,     0,
       0,   115,   116,   117,     0,   118,   119,   120,   121,     0,
       0,     0,     0,  1859,     0,  1861,   958,     0,     0,     0,
     961,     0,     0,     0,   965,     0,     0,     0,   122,   123,
       0,     0,     0,     0,  1878,     0,     0,     0,   978,   979,
       0,     0,     0,  1883,     0,     0,   985,     0,     0,     0,
       0,   989,     0,     0,     0,     0,   994,     0,   996,     0,
       0,   124,   125,   126,   127,   128,   129,   130,     0,     0,
    1008,     0,  1010,  1011,     0,  1013,  1014,  1015,     0,   131,
       0,     0,   132,  1019,     0,     0,     0,   291,  1023,   557,
     558,   559,   560,     0,     0,   292,  1029,  1111,     0,   134,
     135,     0,     0,   136,  1036,   137,     0,     0,     0,     0,
       0,     0,     0,   138,     0,     0,     0,     0,     0,     0,
     139,   547,   548,     0,   140,   141,     0,     0,   549,   550,
     551,   552,   553,   554,   555,   556,     0,     0,     0,     0,
       0,     0,   142,   143,   144,   145,   146,   147,     0,     0,
       0,     0,     0,     0,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,     0,   204,   205,     0,   206,   207,   208,     0,   209,
     210,   211,   212,   213,   214,   215,     0,     0,     0,     0,
       0,   216,   217,     0,   218,     0,     0,     0,     0,     0,
       0,   219,     0,   293,   547,   548,     0,     0,     0,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,     0,
       0,     0,     0,     0,     0,   547,   548,     0,     0,     0,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   557,   558,   559,   560,     0,     0,
       0,     0,  1122,     0,     0,     0,     0,     0,     0,   115,
     116,   117,     0,   118,   119,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1222,   122,   123,     0,     0,
       0,     0,     0,  1226,     0,     0,     0,     0,  1231,     0,
    1233,     0,  1235,  1236,     0,     0,     0,  1241,  1242,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,     0,     0,
     132,     0,     0,     0,     0,   133,     0,     0,     0,     0,
       0,     0,     0,   754,     0,     0,     0,   134,   135,     0,
       0,   136,     0,   137,     0,     0,     0,   557,   558,   559,
     560,   138,     0,     0,     0,  1123,     0,     0,   139,     0,
       0,     0,   140,   141,     0,     0,  1317,  1318,   557,   558,
     559,   560,     0,     0,     0,     0,  1125,     0,     0,     0,
     142,   143,   144,   145,   146,   147,     0,     0,     0,     0,
       0,  1333,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,     0,
     204,   205,     0,   206,   207,   208,     0,   209,   210,   211,
     212,   213,   214,   215,     0,     0,     0,     0,     0,   216,
     217,     0,   218,     0,     0,     0,     0,     0,     0,   219,
       0,   293,   115,   116,   117,     0,   118,   119,   120,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,     0,     0,   132,   547,   548,     0,     0,   133,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,     0,
     134,   135,     0,     0,   136,     0,   137,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,     0,
       0,   139,   547,   548,     0,   140,   141,     0,     0,   549,
     550,   551,   552,   553,   554,   555,   556,     0,     0,     0,
       0,     0,     0,   142,   143,   144,   145,   146,   147,     0,
       0,     0,     0,     0,     0,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,     0,   204,   205,     0,   206,   207,   208,     0,
     209,   210,   211,   212,   213,   214,   215,     0,     0,     0,
       0,     0,   216,   217,     0,   218,     0,     0,     0,     0,
       0,     0,   219,  1546,   293,     0,  1549,   115,   116,   117,
    1553,   118,   119,   120,   121,     0,     0,   557,   558,   559,
     560,     0,     0,     0,     0,  1128,     0,     0,     0,     0,
       0,     0,     0,     0,   122,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   557,   558,   559,   560,  1598,
       0,     0,     0,  1152,     0,     0,     0,   124,   125,   126,
     127,   128,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,     0,     0,   132,   547,
     548,     0,     0,   133,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,     0,   134,   135,     0,     0,   136,
       0,   137,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,     0,     0,   139,   547,   548,     0,
     140,   141,     0,     0,   549,   550,   551,   552,   553,   554,
     555,   556,     0,     0,     0,     0,     0,     0,   142,   143,
     144,   145,   146,   147,     0,     0,     0,     0,     0,     0,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,     0,   204,   205,
       0,   206,   207,   208,     0,   209,   210,   211,   212,   213,
     214,   215,  1718,     0,     0,     0,  1722,   216,   217,     0,
     218,     0,     0,     0,     0,     0,     0,   219,   732,   115,
     116,   117,     0,   118,   119,   120,   121,     0,     0,     0,
       0,     0,   557,   558,   559,   560,     0,     0,     0,     0,
    1194,     0,     0,     0,     0,     0,   122,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     557,   558,   559,   560,     0,     0,     0,     0,  1391,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,     0,     0,
     132,   547,   548,     0,     0,   133,     0,     0,   549,   550,
     551,   552,   553,   554,   555,   556,     0,   134,   135,     0,
       0,   136,     0,   137,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,     0,     0,     0,     0,   139,   547,
     548,     0,   140,   141,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,     0,     0,     0,     0,     0,     0,
     142,   143,   144,   145,   146,   147,     0,     0,     0,     0,
       0,     0,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,     0,
     204,   205,     0,   206,   207,   208,     0,   209,   210,   211,
     212,   213,   214,   215,     0,     0,     0,     0,     0,   216,
     217,     0,   218,     0,     0,     0,     0,     0,     0,   219,
     807,   115,   116,   117,     0,   118,   119,   120,   121,     0,
       0,     0,     0,     0,   557,   558,   559,   560,     0,     0,
       0,     0,  1462,     0,     0,     0,     0,     0,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   557,   558,   559,   560,     0,     0,     0,     0,
    1463,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
       0,     0,   132,   547,   548,     0,     0,   133,     0,     0,
     549,   550,   551,   552,   553,   554,   555,   556,     0,   134,
     135,     0,     0,   136,     0,   137,     0,     0,     0,     0,
       0,     0,     0,   138,     0,     0,     0,     0,     0,     0,
     139,   547,   548,     0,   140,   141,     0,     0,   549,   550,
     551,   552,   553,   554,   555,   556,     0,     0,     0,     0,
       0,     0,   142,   143,   144,   145,   146,   147,     0,     0,
       0,     0,     0,     0,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,     0,   204,   205,     0,   206,   207,   208,     0,   209,
     210,   211,   212,   213,   214,   215,     0,     0,     0,     0,
       0,   216,   217,     0,   218,     0,     0,     0,     0,     0,
       0,   219,   818,   115,   116,   117,     0,   118,   119,   120,
     121,     0,     0,     0,     0,     0,   557,   558,   559,   560,
       0,     0,     0,     0,  1470,     0,     0,     0,     0,     0,
     122,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   557,   558,   559,   560,     0,     0,
       0,     0,  1471,   124,   125,   126,   127,   128,   129,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,     0,   132,     0,     0,     0,     0,   133,
       0,     0,     0,     0,     0,   391,     0,     0,     0,     0,
       0,   134,   135,     0,     0,   136,     0,   137,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,     0,
       0,     0,   139,     0,     0,     0,   140,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   392,   393,   142,   143,   144,   145,   146,   147,
       0,   394,   395,   396,   397,     0,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,     0,   204,   205,     0,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,     0,     0,
       0,     0,     0,   216,   217,     0,   218,     0,     0,     0,
     115,   116,   117,   219,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   399,     0,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,     0,
       0,   132,     0,     0,     0,     0,   133,     0,     0,     0,
       0,     0,   400,     0,     0,     0,     0,     0,   134,   135,
       0,     0,   136,     0,   137,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,     0,     0,   139,
       0,     0,     0,   140,   141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   401,
     402,   142,   143,   144,   145,   146,   147,   403,     0,     0,
       0,   404,     0,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
       0,   204,   205,     0,   206,   207,   208,     0,   209,   210,
     211,   212,   213,   214,   215,     0,     0,     0,     0,     0,
     216,   217,     0,   218,     0,     0,     0,   115,   116,   117,
     219,   118,   119,   120,   121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,   125,   126,
     127,   128,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,     0,     0,   132,     0,
       0,     0,     0,   133,     0,     0,     0,     0,     0,   380,
       0,     0,     0,     0,     0,   134,   135,     0,     0,   136,
       0,   137,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,     0,     0,   139,     0,     0,     0,
     140,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   381,   382,   142,   143,
     144,   145,   146,   147,     0,   383,     0,     0,   384,     0,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,     0,   204,   205,
       0,   206,   207,   208,     0,   209,   210,   211,   212,   213,
     214,   215,     0,     0,     0,     0,     0,   216,   217,     0,
     218,     0,     0,     0,   115,   116,   117,   219,   118,   119,
     120,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   349,     0,   124,   125,   126,   127,   128,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,     0,     0,   132,     0,     0,     0,     0,
     133,     0,     0,     0,     0,     0,   350,     0,     0,     0,
       0,     0,   134,   135,     0,     0,   136,     0,   137,     0,
       0,     0,   351,     0,     0,     0,   138,     0,     0,     0,
       0,     0,     0,   139,     0,     0,     0,   140,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   352,     0,   142,   143,   144,   145,   146,
     147,     0,     0,     0,     0,     0,     0,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,     0,   204,   205,     0,   206,   207,
     208,     0,   209,   210,   211,   212,   213,   214,   215,     0,
       0,     0,     0,     0,   216,   217,     0,   218,     0,     0,
       0,   115,   116,   117,   219,   118,   119,   120,   121,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
       0,     0,   132,     0,     0,     0,     0,   133,     0,     0,
       0,     0,     0,   386,     0,     0,     0,     0,     0,   134,
     135,     0,     0,   136,     0,   137,     0,     0,     0,     0,
       0,     0,     0,   138,     0,     0,     0,     0,     0,     0,
     139,     0,     0,     0,   140,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     387,   388,   142,   143,   144,   145,   146,   147,     0,     0,
       0,     0,   389,     0,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,     0,   204,   205,     0,   206,   207,   208,     0,   209,
     210,   211,   212,   213,   214,   215,     0,     0,     0,     0,
       0,   216,   217,     0,   218,     0,     0,     0,   115,   116,
     117,   219,   118,   119,   120,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   355,     0,     0,
       0,     0,     0,     0,     0,   122,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   356,     0,   124,   125,
     126,   127,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,     0,     0,   132,
     547,   548,     0,     0,   133,     0,     0,   549,   550,   551,
     552,   553,   554,   555,   556,     0,   134,   135,     0,     0,
     136,     0,   137,     0,     0,     0,   357,     0,     0,     0,
     138,     0,     0,     0,     0,     0,     0,   139,     0,     0,
       0,   140,   141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
     143,   144,   145,   146,   147,     0,     0,     0,     0,     0,
       0,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,     0,   204,
     205,     0,   206,   207,   208,     0,   209,   210,   211,   212,
     213,   214,   215,     0,     0,     0,     0,     0,   216,   217,
       0,   218,     0,     0,     0,   115,   116,   117,   219,   118,
     119,   120,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   557,   558,   559,   560,     0,     0,     0,
       0,  1472,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,   125,   126,   127,   128,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,     0,     0,   132,   547,   548,     0,
       0,   133,     0,     0,   549,   550,   551,   552,   553,   554,
     555,   556,     0,   134,   135,     0,     0,   136,     0,   137,
       0,     0,     0,   369,     0,     0,     0,   138,     0,     0,
       0,     0,     0,     0,   139,     0,     0,     0,   140,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   370,   371,   142,   143,   144,   145,
     146,   147,     0,     0,     0,     0,     0,     0,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,     0,   204,   205,     0,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
       0,     0,     0,     0,     0,   216,   217,     0,   218,     0,
       0,     0,   115,   116,   117,   219,   118,   119,   120,   121,
       0,   308,     0,     0,     0,     0,     0,     0,     0,     0,
     557,   558,   559,   560,     0,     0,     0,     0,  1473,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,     0,     0,   132,   547,   548,     0,     0,   133,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,     0,
     134,   135,     0,     0,   136,     0,   137,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,     0,
       0,   139,     0,     0,     0,   140,   141,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   142,   143,   144,   145,   146,   147,     0,
       0,     0,     0,     0,     0,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,     0,   204,   205,     0,   206,   207,   208,     0,
     209,   210,   211,   212,   213,   214,   215,     0,     0,     0,
       0,     0,   216,   217,     0,   218,     0,     0,     0,   115,
     116,   117,   219,   118,   119,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   557,   558,   559,
     560,     0,     0,     0,     0,  1474,   122,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,     0,     0,
     132,     0,     0,     0,     0,   133,     0,     0,     0,     0,
       0,   346,     0,     0,     0,     0,     0,   134,   135,     0,
       0,   136,     0,   137,     0,     0,     0,   347,     0,     0,
       0,   138,     0,     0,     0,     0,     0,     0,   139,     0,
       0,     0,   140,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,   144,   145,   146,   147,     0,     0,     0,     0,
       0,     0,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,     0,
     204,   205,     0,   206,   207,   208,     0,   209,   210,   211,
     212,   213,   214,   215,     0,     0,     0,     0,     0,   216,
     217,     0,   218,     0,     0,     0,   115,   116,   117,   219,
     118,   119,   120,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   122,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,     0,     0,   132,   547,   548,
       0,     0,   133,     0,     0,   549,   550,   551,   552,   553,
     554,   555,   556,     0,   134,   135,     0,     0,   136,     0,
     137,     0,     0,     0,     0,   439,   440,     0,   138,     0,
       0,     0,     0,     0,     0,   139,     0,     0,     0,   140,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,   143,   144,
     145,   146,   147,     0,     0,     0,     0,     0,     0,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,     0,   204,   205,     0,
     206,   207,   208,     0,   209,   210,   211,   212,   213,   214,
     215,     0,     0,     0,     0,     0,   216,   217,     0,   218,
       0,     0,     0,   115,   116,   117,   219,   118,   119,   120,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   557,   558,   559,   560,     0,     0,     0,     0,  1479,
     122,   123,     0,     0,   250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,   129,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,     0,   132,   547,   548,     0,     0,   133,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
       0,   134,   135,     0,     0,   136,     0,   137,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,     0,
       0,     0,   139,     0,     0,     0,   140,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   144,   145,   146,   147,
       0,     0,     0,     0,     0,     0,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,     0,   204,   205,     0,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,     0,     0,
       0,     0,     0,   216,   217,     0,   218,     0,     0,     0,
     115,   116,   117,   219,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   557,   558,
     559,   560,     0,     0,     0,     0,  1480,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,     0,
       0,   132,   547,   548,     0,     0,   133,     0,     0,   549,
     550,   551,   552,   553,   554,   555,   556,     0,   134,   135,
       0,     0,   136,     0,   137,     0,     0,     0,   311,     0,
       0,     0,   138,     0,     0,     0,     0,     0,     0,   139,
       0,     0,     0,   140,   141,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,   145,   146,   147,     0,     0,     0,
       0,     0,     0,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
       0,   204,   205,     0,   206,   207,   208,     0,   209,   210,
     211,   212,   213,   214,   215,     0,     0,     0,     0,     0,
     216,   217,     0,   218,     0,     0,     0,   115,   116,   117,
     219,   118,   119,   120,   121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   557,   558,   559,   560,     0,
       0,     0,     0,  1485,   122,   123,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,   125,   126,
     127,   128,   129,   130,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,     0,     0,   132,   547,
     548,     0,     0,   133,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,     0,   134,   135,     0,     0,   136,
       0,   137,     0,     0,     0,   342,     0,     0,     0,   138,
       0,     0,     0,     0,     0,     0,   139,     0,     0,     0,
     140,   141,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   142,   143,
     144,   145,   146,   147,     0,     0,     0,     0,     0,     0,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,     0,   200,   201,   202,   203,     0,   204,   205,
       0,   206,   207,   208,     0,   209,   210,   211,   212,   213,
     214,   215,     0,     0,     0,     0,     0,   216,   217,     0,
     218,     0,     0,     0,   115,   116,   117,   219,   118,   119,
     120,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   557,   558,   559,   560,     0,     0,     0,     0,
    1486,   122,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,   125,   126,   127,   128,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,     0,     0,   132,   547,   548,     0,     0,
     133,     0,     0,   549,   550,   551,   552,   553,   554,   555,
     556,     0,   134,   135,     0,     0,   136,     0,   137,     0,
       0,     0,   344,     0,     0,     0,   138,     0,     0,     0,
       0,     0,     0,   139,     0,     0,     0,   140,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   142,   143,   144,   145,   146,
     147,     0,     0,     0,     0,     0,     0,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,     0,
     200,   201,   202,   203,     0,   204,   205,     0,   206,   207,
     208,     0,   209,   210,   211,   212,   213,   214,   215,     0,
       0,     0,     0,     0,   216,   217,     0,   218,     0,     0,
       0,   115,   116,   117,   219,   118,   119,   120,   121,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   557,
     558,   559,   560,     0,     0,     0,     0,  1487,   122,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   125,   126,   127,   128,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
       0,     0,   132,   547,   548,     0,     0,   133,     0,     0,
     549,   550,   551,   552,   553,   554,   555,   556,     0,   134,
     135,     0,     0,   136,     0,   137,     0,     0,     0,   359,
       0,     0,     0,   138,     0,     0,     0,     0,     0,     0,
     139,     0,     0,     0,   140,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   142,   143,   144,   145,   146,   147,     0,     0,
       0,     0,     0,     0,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,     0,   200,   201,   202,
     203,     0,   204,   205,     0,   206,   207,   208,     0,   209,
     210,   211,   212,   213,   214,   215,     0,     0,     0,     0,
       0,   216,   217,     0,   218,     0,     0,     0,   115,   116,
     117,   219,   118,   119,   120,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   557,   558,   559,   560,
       0,     0,     0,     0,  1488,   122,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,   125,
     126,   127,   128,   129,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,     0,     0,   132,
     547,   548,     0,     0,   133,     0,     0,   549,   550,   551,
     552,   553,   554,   555,   556,     0,   134,   135,     0,     0,
     136,     0,   137,     0,     0,     0,   361,     0,     0,     0,
     138,     0,     0,     0,     0,     0,     0,   139,     0,     0,
       0,   140,   141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
     143,   144,   145,   146,   147,     0,     0,     0,     0,     0,
       0,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,     0,   200,   201,   202,   203,     0,   204,
     205,     0,   206,   207,   208,     0,   209,   210,   211,   212,
     213,   214,   215,     0,     0,     0,     0,     0,   216,   217,
       0,   218,     0,     0,     0,   115,   116,   117,   219,   118,
     119,   120,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   557,   558,   559,   560,     0,     0,     0,
       0,  1489,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,   125,   126,   127,   128,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,     0,     0,   132,   547,   548,     0,
       0,   133,     0,     0,   549,   550,   551,   552,   553,   554,
     555,   556,     0,   134,   135,     0,     0,   136,     0,   137,
       0,     0,     0,   373,     0,     0,     0,   138,     0,     0,
       0,     0,     0,     0,   139,     0,     0,     0,   140,   141,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   142,   143,   144,   145,
     146,   147,     0,     0,     0,     0,     0,     0,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
       0,   200,   201,   202,   203,     0,   204,   205,     0,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
       0,     0,     0,     0,     0,   216,   217,     0,   218,     0,
       0,     0,   115,   116,   117,   219,   118,   119,   120,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     557,   558,   559,   560,     0,     0,     0,     0,  1492,   122,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,   126,   127,   128,   129,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,     0,     0,   132,   547,   548,     0,     0,   133,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,     0,
     134,   135,     0,     0,   136,     0,   137,     0,     0,     0,
     376,     0,     0,     0,   138,     0,     0,     0,     0,     0,
       0,   139,     0,     0,     0,   140,   141,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   142,   143,   144,   145,   146,   147,     0,
       0,     0,     0,     0,     0,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,     0,   200,   201,
     202,   203,     0,   204,   205,     0,   206,   207,   208,     0,
     209,   210,   211,   212,   213,   214,   215,     0,     0,     0,
       0,     0,   216,   217,     0,   218,     0,     0,     0,   115,
     116,   117,   219,   118,   119,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   557,   558,   559,
     560,     0,     0,     0,     0,  1493,   122,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   124,
     125,   126,   127,   128,   129,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,     0,     0,
     132,   547,   548,     0,     0,   133,     0,     0,   549,   550,
     551,   552,   553,   554,   555,   556,     0,   134,   135,     0,
       0,   136,     0,   137,     0,     0,     0,   406,     0,     0,
       0,   138,     0,     0,     0,     0,     0,     0,   139,     0,
       0,     0,   140,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     142,   143,   144,   145,   146,   147,     0,     0,     0,     0,
       0,     0,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,     0,   200,   201,   202,   203,     0,
     204,   205,     0,   206,   207,   208,     0,   209,   210,   211,
     212,   213,   214,   215,     0,     0,     0,     0,     0,   216,
     217,     0,   218,     0,     0,     0,   115,   116,   117,   219,
     118,   119,   120,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   557,   558,   559,   560,     0,     0,
       0,     0,  1496,   122,   123,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,   125,   126,   127,
     128,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,     0,     0,   132,   547,   548,
       0,     0,   133,     0,     0,   549,   550,   551,   552,   553,
     554,   555,   556,     0,   134,   135,     0,     0,   136,     0,
     137,     0,     0,     0,   408,     0,     0,     0,   138,     0,
       0,     0,     0,     0,     0,   139,     0,     0,     0,   140,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,   143,   144,
     145,   146,   147,     0,     0,     0,     0,     0,     0,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,     0,   200,   201,   202,   203,     0,   204,   205,     0,
     206,   207,   208,     0,   209,   210,   211,   212,   213,   214,
     215,     0,     0,     0,     0,     0,   216,   217,     0,   218,
       0,     0,     0,   115,   116,   117,   219,   118,   119,   120,
     121,     0,   639,     0,     0,     0,     0,     0,     0,     0,
       0,   557,   558,   559,   560,     0,     0,     0,     0,  1504,
     122,   123,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,   129,   130,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,     0,   132,   547,   548,     0,     0,   133,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
       0,   134,   135,     0,     0,   136,     0,   137,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,     0,
       0,     0,   139,     0,     0,     0,   140,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   142,   143,   144,   145,   146,   147,
       0,     0,     0,     0,     0,     0,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,     0,   200,
     201,   202,   203,     0,   204,   205,     0,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,     0,     0,
       0,     0,     0,   216,   217,     0,   218,     0,     0,     0,
     115,   116,   117,   219,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   557,   558,
     559,   560,     0,     0,     0,     0,  1507,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,   128,   129,   130,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,     0,
       0,   132,     0,   547,   548,     0,   133,     0,     0,     0,
     549,   550,   551,   552,   553,   554,   555,   556,   134,   135,
       0,     0,   136,     0,   137,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,     0,     0,     0,     0,   139,
       0,     0,     0,   140,   141,   117,     0,     0,     0,     0,
     121,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   143,   144,   145,   146,   147,     0,     0,     0,
       0,   123,     0,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,     0,   200,   201,   202,   203,
       0,   204,   205,     0,   206,   207,   208,     0,   209,   210,
     211,   212,   213,   214,   215,   136,     0,   137,     0,   117,
     216,   217,     0,   218,   121,     0,     0,     0,     0,     0,
     219,     0,     0,     0,     0,     0,   140,   141,     0,     0,
       0,     0,     0,     0,     0,   123,   557,   558,   559,   560,
       0,     0,   612,     0,   227,   228,   229,   230,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
       0,     0,     0,   175,   176,   177,     0,   179,     0,   181,
     182,   183,     0,     0,     0,     0,   188,   189,   190,   191,
     192,     0,     0,   195,     0,   197,     0,   199,     0,   136,
     201,   137,   203,     0,     0,   205,     0,     0,   207,   208,
       0,   209,   210,     0,   212,     0,   214,     0,     0,     0,
     140,   141,     0,   117,   217,     0,     0,     0,   121,     0,
       0,     0,     0,   231,   831,     0,     0,     0,   227,   228,
     229,   230,   146,     0,     0,     0,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,     0,     0,     0,   175,   176,   177,
       0,   179,     0,   181,   182,   183,     0,     0,     0,     0,
     188,   189,   190,   191,   192,     0,     0,   195,     0,   197,
       0,   199,     0,     0,   201,     0,   203,     0,     0,   205,
       0,     0,   207,   208,     0,   209,   210,     0,   212,     0,
     214,     0,     0,   136,     0,   137,     0,   117,   217,   363,
       0,     0,   121,     0,     0,     0,     0,   231,   833,     0,
       0,     0,     0,     0,   140,   141,     0,     0,     0,     0,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,   227,   228,   229,   230,   146,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   547,   548,     0,
       0,     0,     0,     0,   549,   550,   551,   552,   553,   554,
     555,   556,     0,     0,     0,   169,   170,   171,     0,     0,
       0,   175,   176,   177,     0,   179,     0,   181,   182,   183,
       0,     0,     0,     0,   188,   189,   190,   191,   192,     0,
       0,   195,     0,   197,     0,   199,     0,   136,   201,   137,
     203,     0,     0,   205,     0,     0,   207,   208,     0,   209,
     210,     0,   212,     0,   214,   117,     0,     0,   140,   141,
     121,     0,   217,     0,     0,     0,     0,     0,     0,     0,
       0,   231,     0,     0,     0,     0,   227,   228,   229,   230,
     146,   123,   719,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   169,
     170,   171,     0,     0,     0,   175,   176,   177,     0,   179,
       0,   181,   182,   183,     0,     0,     0,     0,   188,   189,
     190,   191,   192,     0,     0,   195,     0,   197,     0,   199,
       0,     0,   201,     0,   203,     0,     0,   205,     0,     0,
     207,   208,     0,   209,   210,   136,   212,   137,   214,   117,
     557,   558,   559,   560,   121,     0,   217,     0,  1522,     0,
       0,     0,     0,     0,     0,   231,   140,   141,     0,     0,
       0,     0,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,     0,   227,   228,   229,   230,   146,     0,
     783,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
       0,     0,     0,   175,   176,   177,     0,   179,     0,   181,
     182,   183,     0,     0,     0,     0,   188,   189,   190,   191,
     192,   951,     0,   195,     0,   197,     0,   199,     0,   136,
     201,   137,   203,     0,     0,   205,     0,     0,   207,   208,
       0,   209,   210,     0,   212,     0,   214,     0,     0,     0,
     140,   141,   117,     0,   217,     0,     0,   121,     0,     0,
       0,     0,     0,   231,     0,     0,     0,     0,   227,   228,
     229,   230,   146,     0,     0,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   169,   170,   171,     0,     0,     0,   175,   176,   177,
       0,   179,     0,   181,   182,   183,     0,     0,     0,     0,
     188,   189,   190,   191,   192,     0,     0,   195,     0,   197,
       0,   199,     0,     0,   201,     0,   203,     0,     0,   205,
       0,     0,   207,   208,  1326,   209,   210,     0,   212,     0,
     214,     0,   136,     0,   137,     0,   117,     0,   217,     0,
       0,   121,     0,     0,     0,     0,     0,   231,     0,     0,
       0,     0,     0,   140,   141,     0,     0,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,   227,   228,   229,   230,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   547,   548,     0,     0,     0,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
       0,     0,     0,     0,   169,   170,   171,     0,     0,     0,
     175,   176,   177,     0,   179,     0,   181,   182,   183,     0,
       0,     0,     0,   188,   189,   190,   191,   192,     0,     0,
     195,     0,   197,     0,   199,     0,   136,   201,   137,   203,
       0,     0,   205,     0,     0,   207,   208,     0,   209,   210,
       0,   212,     0,   214,   117,     0,     0,   140,   141,   121,
       0,   217,     0,     0,     0,     0,     0,     0,     0,     0,
     231,     0,     0,     0,     0,   227,   228,   229,   230,   146,
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   169,   170,
     171,     0,     0,     0,   175,   176,   177,     0,   179,     0,
     181,   182,   183,     0,     0,     0,     0,   188,   189,   190,
     191,   192,     0,     0,   195,     0,   197,     0,   199,     0,
       0,   201,     0,   203,     0,     0,   205,     0,     0,   207,
     208,     0,   209,   210,   136,   212,   137,   214,   557,   558,
     559,   560,     0,     0,     0,   217,  1623,     0,     0,     0,
     547,   548,     0,     0,   231,   140,   141,   549,   550,   551,
     552,   553,   554,   555,   556,     0,     0,     0,     0,     0,
       0,     0,     0,   227,   228,   229,   230,   146,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   547,   548,     0,     0,     0,     0,     0,   549,   550,
     551,   552,   553,   554,   555,   556,   169,   170,   171,     0,
       0,     0,   175,   176,   177,     0,   179,     0,   181,   182,
     183,     0,     0,     0,     0,   188,   189,   190,   191,   192,
       0,     0,   195,     0,   197,     0,   199,     0,     0,   201,
       0,   203,     0,     0,   205,     0,     0,   207,   208,     0,
     209,   210,     0,   212,     0,   214,     0,     0,     7,     8,
       9,     0,     0,   217,     0,    10,     0,     0,     0,    11,
       0,    12,  1195,    13,    14,    15,    16,    17,  -456,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,     0,     0,     0,     0,    29,     0,     0,    30,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    37,    38,     0,     0,     0,
       0,     0,     0,   557,   558,   559,   560,     0,     0,     0,
       0,  1627,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,    45,    46,    47,  -219,  -219,    48,    49,
      50,     0,    51,    52,    53,     0,     0,    54,  -219,     0,
      55,     0,    56,    57,   557,   558,   559,   560,    58,    59,
       0,     0,  1679,     0,     0,    60,     0,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,     0,     0,     0,     0,    89,   547,
     548,     0,     0,     0,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,     0,     0,     0,     0,    90,     0,
       0,     0,    91,     0,     7,     8,     9,    92,     0,     0,
      93,    10,     0,     0,    94,    11,     0,    12,     0,    13,
      14,    15,    16,    17,  -456,     0,    18,    19,    20,    21,
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
       0,     0,   557,   558,   559,   560,     0,     0,     0,     0,
    1688,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
       0,     0,     0,     0,    89,   547,   548,     0,     0,     0,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
       0,     0,     0,     0,    90,     0,     0,     0,    91,     0,
       7,     8,     9,    92,     0,     0,    93,    10,     0,     0,
      94,    11,     0,    12,     0,    13,    14,    15,    16,    17,
    -456,     0,    18,    19,    20,    21,    22,    23,    24,    25,
       0,    26,    27,    28,   -16,     0,     0,     0,    29,   -16,
       0,    30,     0,     0,     0,     0,     0,     0,    31,    32,
      33,    34,    35,    36,   547,   548,     0,    37,    38,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,     0,
       0,     0,     0,     0,    39,    40,    41,    42,    43,    44,
       0,     0,     0,     0,     0,    45,    46,    47,     0,     0,
      48,    49,    50,     0,    51,    52,    53,     0,     0,    54,
       0,     0,    55,     0,    56,    57,     0,     0,     0,     0,
      58,    59,     0,     0,     0,     0,     0,    60,     0,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,     0,     0,
      80,    81,    82,    83,    84,    85,     0,     0,   557,   558,
     559,   560,   547,   548,     0,     0,  1691,     0,     0,   549,
     550,   551,   552,   553,   554,   555,   556,     0,     0,     0,
       0,     0,     0,    86,    87,    88,   547,   548,     0,     0,
      89,     0,     0,   549,   550,   551,   552,   553,   554,   555,
     556,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,    91,     0,     0,     0,     0,    92,
     547,   548,    93,     0,     0,     0,    94,   549,   550,   551,
     552,   553,   554,   555,   556,     0,     0,   557,   558,   559,
     560,   547,   548,     0,     0,  1692,     0,     0,   549,   550,
     551,   552,   553,   554,   555,   556,   547,   548,     0,     0,
       0,     0,     0,   549,   550,   551,   552,   553,   554,   555,
     556,   547,   548,     0,     0,     0,     0,     0,   549,   550,
     551,   552,   553,   554,   555,   556,   547,   548,     0,     0,
       0,     0,     0,   549,   550,   551,   552,   553,   554,   555,
     556,   547,   548,     0,     0,     0,     0,     0,   549,   550,
     551,   552,   553,   554,   555,   556,   547,   548,     0,     0,
       0,     0,     0,   549,   550,   551,   552,   553,   554,   555,
     556,     0,     0,     0,     0,   557,   558,   559,   560,   547,
     548,     0,     0,  1694,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,     0,     0,     0,     0,     0,   557,
     558,   559,   560,   547,   548,     0,     0,  1711,     0,     0,
     549,   550,   551,   552,   553,   554,   555,   556,   547,   548,
       0,     0,     0,     0,     0,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   547,   548,     0,
       0,  1805,     0,     0,   549,   550,   551,   552,   553,   554,
     555,   556,     0,     0,   557,   558,   559,   560,     0,     0,
       0,     0,  1818,     0,     0,     0,     0,     0,     0,   557,
     558,   559,   560,     0,     0,     0,     0,  1856,     0,     0,
       0,     0,     0,     0,   557,   558,   559,   560,     0,     0,
       0,     0,  1875,     0,     0,     0,     0,     0,     0,   557,
     558,   559,   560,     0,     0,     0,     0,  1889,     0,     0,
       0,     0,     0,     0,   557,   558,   559,   560,     0,     0,
     613,     0,     0,     0,     0,     0,     0,     0,     0,   557,
     558,   559,   560,   547,   548,   630,     0,     0,     0,     0,
     549,   550,   551,   552,   553,   554,   555,   556,     0,     0,
       0,     0,   557,   558,   559,   560,   547,   548,   948,     0,
       0,     0,     0,   549,   550,   551,   552,   553,   554,   555,
     556,     0,     0,     0,     0,     0,   557,   558,   559,   560,
       0,     0,  1062,     0,     0,     0,     0,     0,     0,     0,
       0,   557,   558,   559,   560,   547,   548,  1063,     0,     0,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   547,   548,  1065,     0,     0,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,   547,
     548,     0,     0,     0,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,   547,   548,     0,     0,     0,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,   547,
     548,     0,     0,     0,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,   547,   548,     0,     0,     0,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,   547,
     548,     0,     0,     0,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,     0,     0,   557,   558,   559,   560,
     547,   548,  1066,     0,     0,     0,     0,   549,   550,   551,
     552,   553,   554,   555,   556,     0,     0,     0,     0,   557,
     558,   559,   560,   547,   548,  1067,     0,     0,     0,     0,
     549,   550,   551,   552,   553,   554,   555,   556,   547,   548,
       0,     0,     0,     0,     0,   549,   550,   551,   552,   553,
     554,   555,   556,     0,     0,     0,     0,     0,   557,   558,
     559,   560,   547,   548,  1081,     0,     0,     0,     0,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,     0,     0,  1110,     0,     0,     0,     0,     0,     0,
       0,     0,   557,   558,   559,   560,     0,     0,  1117,     0,
       0,     0,     0,     0,     0,     0,     0,   557,   558,   559,
     560,     0,     0,  1118,     0,     0,     0,     0,     0,     0,
       0,     0,   557,   558,   559,   560,     0,     0,  1138,     0,
       0,     0,     0,     0,     0,     0,     0,   557,   558,   559,
     560,     0,     0,  1190,     0,     0,     0,     0,     0,     0,
       0,     0,   557,   558,   559,   560,   547,   548,  1213,     0,
       0,     0,     0,   549,   550,   551,   552,   553,   554,   555,
     556,     0,     0,   557,   558,   559,   560,   547,   548,  1214,
       0,     0,     0,     0,   549,   550,   551,   552,   553,   554,
     555,   556,     0,     0,     0,     0,   557,   558,   559,   560,
       0,     0,  1221,     0,     0,     0,     0,     0,     0,     0,
       0,   557,   558,   559,   560,   547,   548,  1227,     0,     0,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
       0,     0,     0,     0,     0,   557,   558,   559,   560,   547,
     548,  1228,     0,     0,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,   547,   548,     0,     0,     0,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,   547,
     548,     0,     0,     0,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,   547,   548,     0,     0,     0,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,   547,
     548,     0,     0,     0,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,   547,   548,     0,     0,     0,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   547,   548,  1267,     0,     0,     0,     0,
     549,   550,   551,   552,   553,   554,   555,   556,     0,     0,
     557,   558,   559,   560,   547,   548,  1313,     0,     0,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,   547,
     548,     0,     0,     0,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,     0,     0,     0,     0,   557,   558,
     559,   560,   547,   548,  1314,     0,     0,     0,     0,   549,
     550,   551,   552,   553,   554,   555,   556,     0,     0,     0,
       0,     0,   557,   558,   559,   560,     0,     0,  1380,     0,
       0,     0,     0,     0,     0,     0,     0,   557,   558,   559,
     560,     0,     0,  1385,     0,     0,     0,     0,     0,     0,
       0,     0,   557,   558,   559,   560,     0,     0,  1399,     0,
       0,     0,     0,     0,     0,     0,     0,   557,   558,   559,
     560,     0,     0,  1411,     0,     0,     0,     0,     0,     0,
       0,     0,   557,   558,   559,   560,     0,     0,  1416,     0,
       0,     0,     0,     0,     0,     0,     0,   557,   558,   559,
     560,   547,   548,  1417,     0,     0,     0,     0,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
     547,   548,  1418,     0,     0,     0,     0,   549,   550,   551,
     552,   553,   554,   555,   556,     0,     0,   557,   558,   559,
     560,     0,     0,  1447,     0,     0,     0,     0,     0,     0,
       0,     0,   557,   558,   559,   560,   547,   548,  1454,     0,
       0,     0,     0,   549,   550,   551,   552,   553,   554,   555,
     556,     0,     0,     0,     0,   557,   558,   559,   560,   547,
     548,  1459,     0,     0,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,   547,   548,     0,     0,     0,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,   547,
     548,     0,     0,     0,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,   547,   548,     0,     0,     0,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,   547,
     548,     0,     0,     0,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,   547,   548,     0,     0,     0,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,     0,
       0,     0,     0,     0,   557,   558,   559,   560,   547,   548,
    1484,     0,     0,     0,     0,   549,   550,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   547,   548,  1505,
       0,     0,     0,     0,   549,   550,   551,   552,   553,   554,
     555,   556,   547,   548,     0,     0,     0,     0,     0,   549,
     550,   551,   552,   553,   554,   555,   556,     0,     0,   557,
     558,   559,   560,   547,   548,  1506,     0,     0,     0,     0,
     549,   550,   551,   552,   553,   554,   555,   556,     0,     0,
       0,     0,   557,   558,   559,   560,     0,     0,  1528,     0,
       0,     0,     0,     0,     0,     0,     0,   557,   558,   559,
     560,     0,     0,  1542,     0,     0,     0,     0,     0,     0,
       0,     0,   557,   558,   559,   560,     0,     0,  1642,     0,
       0,     0,     0,     0,     0,     0,     0,   557,   558,   559,
     560,     0,     0,  1643,     0,     0,     0,     0,     0,     0,
       0,     0,   557,   558,   559,   560,     0,     0,  1644,     0,
       0,     0,     0,     0,     0,     0,     0,   557,   558,   559,
     560,   547,   548,  1646,     0,     0,     0,     0,   549,   550,
     551,   552,   553,   554,   555,   556,     0,     0,     0,     0,
       0,   557,   558,   559,   560,   547,   548,  1651,     0,     0,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,     0,     0,  1654,     0,     0,     0,
       0,     0,     0,     0,     0,   557,   558,   559,   560,   547,
     548,  1659,     0,     0,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,     0,     0,   557,   558,   559,   560,
     547,   548,  1660,     0,     0,     0,     0,   549,   550,   551,
     552,   553,   554,   555,   556,   547,   548,     0,     0,     0,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
     547,   548,     0,     0,     0,     0,     0,   549,   550,   551,
     552,   553,   554,   555,   556,   547,   548,     0,     0,     0,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
     547,   548,     0,     0,     0,     0,     0,   549,   550,   551,
     552,   553,   554,   555,   556,   547,   548,     0,     0,     0,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
       0,     0,     0,     0,   557,   558,   559,   560,   547,   548,
    1671,     0,     0,     0,     0,   549,   550,   551,   552,   553,
     554,   555,   556,     0,     0,     0,     0,     0,   557,   558,
     559,   560,   547,   548,  1672,     0,     0,     0,     0,   549,
     550,   551,   552,   553,   554,   555,   556,   547,   548,     0,
       0,     0,     0,     0,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   547,   548,  1673,     0,
       0,     0,     0,   549,   550,   551,   552,   553,   554,   555,
     556,     0,     0,   557,   558,   559,   560,     0,     0,  1676,
       0,     0,     0,     0,     0,     0,     0,     0,   557,   558,
     559,   560,     0,     0,  1687,     0,     0,     0,     0,     0,
       0,     0,     0,   557,   558,   559,   560,     0,     0,  1706,
       0,     0,     0,     0,     0,     0,     0,     0,   557,   558,
     559,   560,     0,     0,  1725,     0,     0,     0,     0,     0,
       0,     0,     0,   557,   558,   559,   560,     0,     0,  1726,
       0,     0,     0,     0,     0,     0,     0,     0,   557,   558,
     559,   560,   547,   548,  1729,     0,     0,     0,     0,   549,
     550,   551,   552,   553,   554,   555,   556,     0,     0,     0,
       0,   557,   558,   559,   560,   547,   548,  1735,     0,     0,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
       0,     0,     0,     0,     0,   557,   558,   559,   560,     0,
       0,  1740,     0,     0,     0,     0,     0,     0,     0,     0,
     557,   558,   559,   560,   547,   548,  1741,     0,     0,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   560,   547,   548,  1742,     0,     0,     0,     0,
     549,   550,   551,   552,   553,   554,   555,   556,   547,   548,
       0,     0,     0,     0,     0,   549,   550,   551,   552,   553,
     554,   555,   556,   547,   548,     0,     0,     0,     0,     0,
     549,   550,   551,   552,   553,   554,   555,   556,   547,   548,
       0,     0,     0,     0,     0,   549,   550,   551,   552,   553,
     554,   555,   556,   547,   548,     0,     0,     0,     0,     0,
     549,   550,   551,   552,   553,   554,   555,   556,   547,   548,
       0,     0,     0,     0,     0,   549,   550,   551,   552,   553,
     554,   555,   556,     0,     0,   557,   558,   559,   560,   547,
     548,  1745,     0,     0,     0,     0,   549,   550,   551,   552,
     553,   554,   555,   556,     0,     0,     0,     0,   557,   558,
     559,   560,   547,   548,  1749,     0,     0,     0,     0,   549,
     550,   551,   552,   553,   554,   555,   556,   547,   548,     0,
       0,     0,     0,     0,   549,   550,   551,   552,   553,   554,
     555,   556,     0,     0,     0,     0,     0,   557,   558,   559,
     560,   547,   548,  1773,     0,     0,     0,     0,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
       0,     0,  1775,     0,     0,     0,     0,     0,     0,     0,
       0,   557,   558,   559,   560,     0,     0,  1776,     0,     0,
       0,     0,     0,     0,     0,     0,   557,   558,   559,   560,
       0,     0,  1778,     0,     0,     0,     0,     0,     0,     0,
       0,   557,   558,   559,   560,     0,     0,  1783,     0,     0,
       0,     0,     0,     0,     0,     0,   557,   558,   559,   560,
       0,     0,  1786,     0,     0,     0,     0,     0,     0,     0,
       0,   557,   558,   559,   560,   547,   548,  1790,     0,     0,
       0,     0,   549,   550,   551,   552,   553,   554,   555,   556,
       0,     0,   557,   558,   559,   560,   547,   548,  1798,     0,
       0,     0,     0,   549,   550,   551,   552,   553,   554,   555,
     556,     0,     0,     0,     0,   557,   558,   559,   560,     0,
       0,  1799,     0,     0,     0,     0,     0,     0,     0,     0,
     557,   558,   559,   560,   547,   548,  1800,     0,     0,     0,
       0,   549,   550,   551,   552,   553,   554,   555,   556,     0,
       0,     0,     0,     0,   557,   558,   559,   560,   547,   548,
    1817,     0,     0,     0,     0,   549,   550,   551,   552,   553,
     554,   555,   556,   547,   548,     0,     0,     0,     0,     0,
     549,   550,   551,   552,   553,   554,   555,   556,   547,   548,
       0,     0,     0,     0,     0,   549,   550,   551,   552,   553,
     554,   555,   556,   547,   548,     0,     0,     0,     0,     0,
     549,   550,   551,   552,   553,   554,   555,   556,   547,   548,
       0,     0,     0,     0,     0,   549,   550,   551,   552,   553,
     554,   555,   556,   547,   548,     0,     0,     0,     0,     0,
     549,   550,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   547,   548,  1834,     0,     0,     0,     0,   549,
     550,   551,   552,   553,   554,   555,   556,     0,     0,   557,
     558,   559,   560,     0,     0,  1836,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   557,   558,   559,
     560,     0,     0,  1838,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   557,   558,   559,   560,     0,     0,  1839,     0,     0,
       0,     0,     0,     0,     0,     0,   557,   558,   559,   560,
       0,     0,  1855,     0,     0,     0,     0,     0,     0,     0,
       0,   557,   558,   559,   560,     0,     0,  1857,     0,     0,
       0,     0,     0,     0,     0,     0,   557,   558,   559,   560,
       0,     0,  1864,     0,     0,     0,     0,     0,     0,     0,
       0,   557,   558,   559,   560,     0,     0,  1881,     0,     0,
       0,     0,     0,     0,     0,     0,   557,   558,   559,   560,
       0,     0,  1882,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   557,   558,   559,   560,     0,
       0,  1893
};

static const yytype_int16 yycheck[] =
{
       3,   442,     1,    15,    16,     4,   244,    44,     1,    40,
       5,     4,  1202,  1203,    11,    10,    12,     4,    21,    75,
       7,    24,     4,    75,   262,     7,   242,    12,   244,    41,
      33,    61,     0,   237,    37,    38,    31,     3,   242,    42,
     244,     7,     8,     9,    10,    43,    44,    58,    28,    60,
      61,    54,    55,    56,    53,    12,  1531,     3,    23,     7,
      53,     7,     8,     9,    10,   112,   113,    70,    71,    72,
     242,    77,   244,    70,    71,    72,    73,    74,    75,    76,
      58,   111,    60,    61,   112,   113,   112,   113,    91,    92,
      93,    94,   112,    91,    16,   112,    12,   112,   113,    70,
      71,    72,    73,    74,    75,    76,    63,    64,   155,    95,
     105,    25,   107,    70,    71,    72,    73,    74,    75,    76,
      77,   237,    44,     4,     5,   243,   242,   155,   244,   155,
      44,   126,   127,   110,   237,   155,     4,     5,   155,   242,
     155,   244,   243,    44,   411,   412,   243,    63,    64,   144,
     145,   146,   147,   148,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,     4,    92,    93,     7,   243,    70,
      71,    72,    73,    74,    75,    76,    77,   104,   237,    81,
      82,   243,   177,   178,   179,   244,    88,   243,   183,   184,
     185,   243,   187,    28,   189,   190,   191,    44,    33,   237,
     237,   196,   197,   198,   199,   200,   244,    24,   203,   111,
     205,    75,   207,   112,   237,   210,   219,   212,   237,   100,
     215,   244,    75,   218,   219,   244,   221,   222,   231,   224,
     243,   226,   238,   239,   245,  1710,   237,   240,  1713,   234,
     237,   237,   242,   244,   244,   244,   242,   237,   243,   244,
     155,   244,   242,   256,   285,   286,   243,   242,   261,     4,
       5,   243,   529,   262,   531,   268,   237,   245,    77,   262,
     236,   237,    44,   244,   239,   112,   241,   237,   237,   236,
     237,   238,   239,   242,   244,   242,   237,   237,    46,   292,
     236,   237,  1767,   244,   244,  1770,   177,   178,   179,   237,
     303,   304,   305,   243,   242,    63,    64,   243,   311,   177,
     178,   179,    70,    71,    72,    73,    74,    75,    76,    77,
     236,   237,   238,   239,    70,    71,    72,    73,    74,    75,
      76,   334,   335,   237,   243,   236,   237,   238,   239,   342,
     244,   344,  1532,   346,   347,  1535,   349,   350,   351,   352,
     237,   243,   355,   356,   357,   593,   359,   244,   361,   242,
     363,   244,   237,   243,   367,   368,   369,   370,   371,   244,
     373,   237,   242,   376,   244,   237,   242,   380,   381,   382,
     383,   384,   244,   386,   387,   388,   389,   243,   391,   392,
     393,   394,   395,   396,   397,   243,   399,   400,   401,   402,
     403,   404,  1877,   406,  1879,   408,    76,    77,     4,     5,
      71,   414,    73,    74,    75,    76,    77,   237,   237,  1894,
     243,  1896,   242,   426,   244,   244,   237,   236,   237,   238,
     239,   242,   237,   244,   437,   243,   439,   242,   112,   437,
     438,  1631,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   243,   428,   429,   243,    70,    71,    72,    73,
      74,    75,    76,   243,   112,   113,   243,   475,   236,   237,
     238,   239,   485,   486,   487,   488,   489,   243,   237,   492,
     243,   237,   495,   242,   497,   244,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   243,   509,   510,   511,   512,
     513,   514,   515,   516,    35,    36,   519,   515,   521,   522,
     523,   524,   525,   237,   243,   528,   237,   530,   242,   532,
     533,   534,   155,   244,   243,   538,   539,   540,   541,   542,
     543,   544,   545,   241,   242,    70,    71,    72,    73,    74,
      75,    76,   517,   518,   237,   323,   324,   237,   326,   242,
      44,   244,   242,   155,   244,     5,   236,   237,   238,   239,
      10,    59,   340,   341,   237,   236,   237,   238,   239,  1769,
     348,   244,  1772,     4,     5,   353,     4,     5,   619,   237,
     358,    31,   360,   596,   593,   155,   244,   243,   237,   243,
     593,    89,    90,    91,   372,   244,   374,   375,    96,   377,
     378,   379,    14,   237,    16,   243,    18,   385,   242,   237,
     244,   624,   390,   243,    73,    74,    75,    76,    77,  1819,
     398,    13,  1822,   237,   637,   243,   237,   405,   242,    41,
     244,   242,    44,   244,   609,   610,   237,    49,   243,   614,
     615,   242,    58,   244,   243,   893,   237,   660,   243,   662,
     243,   242,   237,   244,   237,   105,   237,   107,   671,   244,
     237,   244,   242,   244,     4,     5,   679,   244,   237,   682,
     683,    63,    64,     4,     5,   244,   126,   127,    70,    71,
      72,    73,    74,    75,    76,    77,    86,    87,  1888,   243,
    1890,    75,    76,    77,   144,   145,   146,   147,   148,   237,
    1900,  1901,   237,   237,   242,     4,   719,   243,  1159,   244,
     244,  1162,   725,   243,   727,    70,    71,    72,    73,    74,
      75,    76,   735,   736,   237,   237,   243,   177,   178,   179,
       5,   244,   244,   183,   184,   185,   237,   187,   237,   189,
     190,   191,   242,   244,   237,   244,   196,   197,   198,   199,
     200,   244,   237,   203,   237,   205,   237,   207,   242,   244,
     210,   244,   212,   244,   243,   215,   237,   243,   218,   219,
     783,   221,   222,   244,   224,   243,   226,   236,   237,   238,
     239,    20,    21,   237,   234,    74,    75,    76,    77,   237,
     244,   237,    63,   243,   244,   242,   244,   242,   244,    70,
      71,    72,    73,    74,    75,    76,    77,    49,    50,    70,
      71,    72,    73,    74,    75,    76,    70,    71,    72,    73,
      74,    75,    76,   237,    63,    64,   243,     4,     5,   242,
     244,    70,    71,    72,    73,    74,    75,    76,    77,     4,
       5,   243,   237,   237,   236,   237,   238,   239,   626,   244,
     244,   242,   236,   237,   238,   239,    14,   237,    16,   242,
      18,   237,   640,   237,   244,   243,   242,   645,   242,   647,
       3,   649,   650,   243,     7,     8,     9,   655,   656,   901,
     902,   243,   237,    41,   893,    51,    44,   237,   237,   244,
     893,    49,   242,   242,   237,   237,   909,    63,    64,   242,
     242,   242,    39,    40,    70,    71,    72,    73,    74,    75,
      76,    77,   925,    63,    64,   928,     4,     5,   931,   243,
      70,    71,    72,    73,    74,    75,    76,    77,   903,   904,
     237,   906,   907,   243,   237,   242,   237,   243,  1186,   242,
     237,   242,   955,    60,    61,   242,   959,   236,   237,   238,
     239,   237,   243,   966,   237,   243,   242,   970,   243,   242,
     973,    60,    61,   741,   742,   236,   237,   238,   239,   243,
     243,   984,   237,   986,   987,   988,   237,   242,   991,   992,
     993,   242,   995,   237,   237,   243,   999,   765,   242,   242,
    1003,  1004,   243,  1006,   243,   243,  1009,   236,   237,   238,
     239,    46,   243,  1016,  1017,   237,   243,  1020,   243,   243,
     242,  1024,  1025,  1026,  1027,   237,   243,  1030,    63,    64,
     242,  1034,   243,   243,  1037,    70,    71,    72,    73,    74,
      75,    76,    77,    70,    71,    72,    73,    74,    75,    76,
     237,   237,   237,   237,  1053,   242,   242,   242,   242,   237,
    1053,   243,   237,   243,   242,   242,  1069,   242,  1071,   237,
    1073,   243,   243,    14,   242,    16,  1041,    18,   243,  1082,
     236,   237,   238,   239,   243,   243,  1089,    70,    71,    72,
      73,    74,    75,    76,   243,   242,   236,   237,   238,   239,
      41,   237,   242,    44,   244,   237,   242,   237,    49,   237,
     242,   242,   242,   237,   242,    63,    64,  1120,   242,   244,
      43,   243,    70,    71,    72,    73,    74,    75,    76,    77,
     228,   229,   230,   231,   232,  1138,  1139,  1140,  1141,    63,
      64,   243,   243,   243,  1147,   242,    70,    71,    72,    73,
      74,    75,    76,    77,   244,   243,   237,  1160,    63,    64,
    1163,   242,  1165,   243,   243,    70,    71,    72,    73,    74,
      75,    76,    77,   243,   243,   243,   243,    70,    71,    72,
      73,    74,    75,    76,    77,   237,   237,  1186,   243,  1192,
     242,   242,  1195,  1186,    71,    72,    73,    74,    75,    76,
      77,   236,   237,   238,   239,   243,   237,   237,   237,   237,
     237,   242,   242,   242,   242,   242,    75,  1220,  1221,   243,
    1218,  1219,  1225,   237,    63,    64,  1229,   243,   242,   244,
     243,    70,    71,    72,    73,    74,    75,    76,    77,   237,
    1243,  1244,   243,  1246,   242,  1248,  1211,  1212,  1251,   243,
     237,   237,  1255,  1256,   237,   242,   242,    77,  1261,   242,
    1263,   237,  1265,   237,  1267,    14,   242,    16,   242,    18,
    1273,   243,  1275,  1276,   237,  1278,  1279,  1280,   243,   242,
     237,   237,   243,  1286,   243,   242,   242,  1290,   236,   237,
     238,   239,    41,   237,  1297,    44,   244,   237,   242,   237,
      49,  1304,   242,  1306,   242,  1308,   243,   243,   243,   243,
    1313,  1314,   236,   237,   238,   239,   237,   237,   242,   237,
     244,   242,   242,   237,   242,   237,   242,   244,   242,   242,
     242,   236,   237,   238,   239,   237,   243,   242,   242,   244,
     242,    63,    64,   236,   237,   238,   239,   243,    70,    71,
      72,    73,    74,    75,    76,    77,   243,  1369,  1370,   236,
     237,   238,   239,   237,   237,   237,   237,   243,   242,   242,
     242,   242,  1375,   237,    43,    46,   237,   237,   242,  1617,
    1618,   242,   242,   237,  1387,   237,   237,   237,   242,   237,
     242,   242,   242,    58,   242,   242,  1399,   236,   237,   238,
     239,  1404,  1405,   242,   237,   244,   243,  1410,  1411,   242,
    1413,  1414,   237,   237,   237,   237,   237,   242,   242,   242,
     242,   242,    10,   242,   237,   243,  1429,  1392,  1393,   242,
    1433,    90,    91,    92,    93,    94,  1439,   237,  1441,   243,
     242,     2,   242,   242,  1447,   104,   242,  1450,  1451,   237,
     237,   110,   111,   243,   242,   242,    17,   116,   117,   118,
     119,   120,   237,   242,  1702,  1233,   237,   242,  1236,    30,
     242,   242,    33,  1241,  1477,    36,    37,    38,   242,   237,
    1483,    42,    43,    44,   242,   242,    43,   237,   244,   237,
      51,  1494,   242,   237,   242,  1498,   237,   244,   242,   237,
     242,   242,  1505,   243,   242,  1508,   237,   237,  1511,   244,
     244,   242,   242,   242,   236,   237,   238,   239,  1756,   237,
     242,  1759,   244,  1526,   242,   244,   237,   237,   237,   237,
      91,   242,   242,   242,   242,   242,   237,   237,  1541,  1542,
    1543,   242,   242,   237,   243,   237,   237,   244,   242,  1317,
     242,   242,  1555,   243,   237,  1558,   237,   244,  1561,   242,
     244,   242,  1565,   237,  1567,   126,  1334,   244,   242,  1807,
    1573,   244,  1575,   237,   244,  1578,  1579,   237,   242,  1582,
     237,   237,   242,   244,   237,   242,   242,   237,  1591,   242,
    1593,  1594,   242,  1596,   237,   237,   237,   237,   243,   242,
     242,   242,   242,    63,    64,   243,    85,   244,   244,    85,
      70,    71,    72,    73,    74,    75,    76,    77,  1617,  1618,
     242,   237,   237,   237,  1617,  1618,   242,   242,   242,   237,
     237,   237,   242,  1636,   242,   242,   242,  1640,   242,   237,
    1643,   237,    63,    64,   242,   242,   242,   242,   242,    70,
      71,    72,    73,    74,    75,    76,    77,   218,   219,   237,
     237,   237,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,     5,   238,   244,   244,
     242,   244,   243,   242,   244,    58,   244,   242,   244,   243,
     243,   242,   242,   242,   242,   256,    43,   244,   243,    38,
     261,  1704,   244,  1702,   244,    43,   243,   268,    58,  1702,
     244,   244,    75,    75,    75,    48,    58,   243,    58,   244,
     244,  1724,  1725,  1726,  1727,   242,  1729,  1730,   243,   243,
     291,  1734,   293,    47,   243,  1738,   243,    38,  1741,  1742,
    1743,    75,  1745,   244,   244,   243,  1749,  1750,   243,  1752,
     242,   242,     4,     4,  1053,    53,    53,  1756,   909,     5,
    1759,   619,   442,  1756,   905,  1768,  1759,  1684,  1375,   908,
     616,  1774,  1775,  1873,  1777,  1778,   236,   237,   238,   239,
      -1,  1549,  1198,   632,   244,  1553,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,  1799,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,  1807,    -1,
      -1,    -1,  1815,    -1,  1807,   236,   237,   238,   239,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,  1831,    -1,
      -1,    -1,  1835,    -1,    -1,  1838,  1839,    -1,    -1,    -1,
    1843,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1852,
      -1,    -1,   413,    -1,  1857,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   425,    -1,    -1,    -1,    -1,   430,
     431,    -1,   433,   434,   435,   436,   437,   438,  1881,  1882,
      -1,    -1,    -1,   444,    -1,    -1,    -1,    -1,    -1,    -1,
    1893,    -1,    -1,    -1,    -1,  1898,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,    -1,    -1,    -1,    -1,    -1,   490,
     491,   492,   493,   494,    -1,   496,    -1,   498,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   508,    -1,    -1,
      -1,    -1,    -1,    -1,   515,    -1,    -1,    -1,    -1,   520,
      -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,    -1,
      -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   559,   560,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,   594,    -1,    -1,    -1,    -1,   599,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    -1,
      -1,   612,   613,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   625,    -1,    -1,    30,    31,   630,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     641,   642,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
     681,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,   110,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   735,   736,   737,   738,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,   236,   237,   238,
     239,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,   209,   210,   211,   212,
      -1,   214,   215,    -1,   217,   218,   219,    -1,   221,   222,
     223,   224,   225,   226,   227,    -1,    -1,    -1,    -1,    -1,
     233,   234,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,
     243,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,   876,   877,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   896,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   909,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   922,    -1,    -1,    -1,    -1,    -1,   928,   929,    63,
      64,    -1,    -1,   934,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    63,    64,   948,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   968,    -1,    -1,
      -1,    -1,   973,   974,   975,    -1,    -1,    -1,    -1,   980,
      -1,   982,    -1,   984,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   993,    -1,    -1,    -1,   997,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1005,    -1,  1007,    -1,    -1,    -1,
      -1,  1012,    -1,    -1,    -1,  1016,  1017,  1018,    -1,    -1,
    1021,  1022,    -1,    -1,  1025,    -1,    -1,  1028,    -1,    -1,
    1031,    -1,  1033,    -1,  1035,    -1,    -1,    -1,  1039,    -1,
      -1,  1042,  1043,  1044,   236,   237,   238,   239,    -1,    -1,
      -1,    -1,   244,  1054,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1062,  1063,    -1,  1065,  1066,  1067,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1078,  1079,    -1,
    1081,    -1,    -1,  1084,  1085,  1086,    -1,  1088,    -1,    -1,
      -1,    -1,    -1,    -1,  1095,    -1,    -1,  1098,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,    -1,  1110,
     244,    -1,  1113,  1114,  1115,    -1,  1117,  1118,   236,   237,
     238,   239,    63,    64,    -1,  1126,   244,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,  1154,    -1,  1156,  1157,  1158,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,  1170,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,  1190,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,  1200,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1213,  1214,    -1,    -1,    -1,  1218,  1219,    -1,
      -1,    63,    64,    -1,    -1,    -1,  1227,  1228,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,  1300,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,   238,   239,    -1,    -1,    -1,    -1,   244,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   236,   237,   238,   239,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1375,    -1,    -1,    -1,    -1,  1380,
      -1,    -1,    -1,    -1,  1385,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,   238,   239,    63,    64,
      -1,    -1,   244,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,  1416,  1417,  1418,    -1,  1420,
      -1,    -1,    -1,    -1,    -1,  1426,    -1,    -1,    -1,  1430,
    1431,    -1,    63,    64,    -1,  1436,    -1,  1438,  1439,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,  1450,
      -1,    -1,  1453,  1454,    -1,  1456,    -1,    -1,  1459,    63,
      64,    -1,    -1,  1464,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1482,    -1,  1484,    -1,    -1,    -1,    -1,    -1,  1490,
      -1,    -1,    -1,   236,   237,   238,   239,    -1,  1499,    -1,
    1501,   244,    -1,   302,    -1,  1506,    -1,    -1,    -1,   308,
      -1,    -1,    -1,    -1,  1515,    -1,   315,   316,    -1,    -1,
      -1,    -1,    -1,    -1,  1525,    -1,    -1,  1528,   327,   328,
     329,   330,   331,   332,   333,    63,    64,   336,   337,   338,
     339,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,  1556,  1557,    -1,    -1,  1560,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1568,    -1,    -1,
      -1,   236,   237,   238,   239,  1576,  1577,    -1,    -1,   244,
    1581,    -1,    -1,    -1,    -1,  1586,    -1,    -1,    -1,  1590,
      63,    64,    -1,    -1,    -1,    -1,  1597,    70,    71,    72,
      73,    74,    75,    76,    77,   236,   237,   238,   239,    -1,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,  1619,    -1,
      -1,    -1,    -1,   422,   423,   424,    -1,    -1,    -1,  1630,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,    -1,    -1,
     244,  1642,    -1,  1644,   443,  1646,    -1,    -1,    -1,    -1,
    1651,    -1,    -1,  1654,    -1,  1656,    -1,    -1,  1659,  1660,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1669,    -1,
    1671,  1672,  1673,    -1,    -1,  1676,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1687,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1697,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1705,  1706,    -1,    -1,   236,   237,
     238,   239,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1732,    -1,    -1,  1735,    -1,    63,    64,  1739,  1740,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,    -1,
    1771,   244,  1773,    -1,    -1,  1776,    -1,    -1,    -1,    -1,
      -1,    -1,  1783,    -1,    -1,  1786,    -1,    -1,    -1,  1790,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1798,    -1,  1800,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1817,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,  1834,    -1,  1836,   635,    -1,    -1,    -1,
     639,    -1,    -1,    -1,   643,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,  1855,    -1,    -1,    -1,   657,   658,
      -1,    -1,    -1,  1864,    -1,    -1,   665,    -1,    -1,    -1,
      -1,   670,    -1,    -1,    -1,    -1,   675,    -1,   677,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
     689,    -1,   691,   692,    -1,   694,   695,   696,    -1,    81,
      -1,    -1,    84,   702,    -1,    -1,    -1,    89,   707,   236,
     237,   238,   239,    -1,    -1,    97,   715,   244,    -1,   101,
     102,    -1,    -1,   105,   723,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    63,    64,    -1,   126,   127,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,   209,   210,   211,
     212,    -1,   214,   215,    -1,   217,   218,   219,    -1,   221,
     222,   223,   224,   225,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,   234,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,   243,    -1,   245,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,
      -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   954,    30,    31,    -1,    -1,
      -1,    -1,    -1,   962,    -1,    -1,    -1,    -1,   967,    -1,
     969,    -1,   971,   972,    -1,    -1,    -1,   976,   977,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,   236,   237,   238,
     239,   115,    -1,    -1,    -1,   244,    -1,    -1,   122,    -1,
      -1,    -1,   126,   127,    -1,    -1,  1055,  1056,   236,   237,
     238,   239,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,  1080,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,   209,   210,   211,   212,    -1,
     214,   215,    -1,   217,   218,   219,    -1,   221,   222,   223,
     224,   225,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,
     234,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,   243,
      -1,   245,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    63,    64,    -1,   126,   127,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,   209,   210,
     211,   212,    -1,   214,   215,    -1,   217,   218,   219,    -1,
     221,   222,   223,   224,   225,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,   234,    -1,   236,    -1,    -1,    -1,    -1,
      -1,    -1,   243,  1412,   245,    -1,  1415,     3,     4,     5,
    1419,     7,     8,     9,    10,    -1,    -1,   236,   237,   238,
     239,    -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,  1468,
      -1,    -1,    -1,   244,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,
      64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,    63,    64,    -1,
     126,   127,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,   209,   210,   211,   212,    -1,   214,   215,
      -1,   217,   218,   219,    -1,   221,   222,   223,   224,   225,
     226,   227,  1641,    -1,    -1,    -1,  1645,   233,   234,    -1,
     236,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,    -1,    -1,
     244,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,   238,   239,    -1,    -1,    -1,    -1,   244,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    63,
      64,    -1,   126,   127,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,   209,   210,   211,   212,    -1,
     214,   215,    -1,   217,   218,   219,    -1,   221,   222,   223,
     224,   225,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,
     234,    -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,
      -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,    -1,    -1,
     244,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    63,    64,    -1,   126,   127,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,   209,   210,   211,
     212,    -1,   214,   215,    -1,   217,   218,   219,    -1,   221,
     222,   223,   224,   225,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,   234,    -1,   236,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,
      -1,    -1,    -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,
      -1,    -1,   244,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,   143,   144,   145,   146,   147,   148,   149,
      -1,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,   209,
     210,   211,   212,    -1,   214,   215,    -1,   217,   218,   219,
      -1,   221,   222,   223,   224,   225,   226,   227,    -1,    -1,
      -1,    -1,    -1,   233,   234,    -1,   236,    -1,    -1,    -1,
       3,     4,     5,   243,     7,     8,     9,    10,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,   149,   150,    -1,    -1,
      -1,   154,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,   209,   210,   211,   212,
      -1,   214,   215,    -1,   217,   218,   219,    -1,   221,   222,
     223,   224,   225,   226,   227,    -1,    -1,    -1,    -1,    -1,
     233,   234,    -1,   236,    -1,    -1,    -1,     3,     4,     5,
     243,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,
     146,   147,   148,   149,    -1,   151,    -1,    -1,   154,    -1,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,   209,   210,   211,   212,    -1,   214,   215,
      -1,   217,   218,   219,    -1,   221,   222,   223,   224,   225,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,   234,    -1,
     236,    -1,    -1,    -1,     3,     4,     5,   243,     7,     8,
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
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
     209,   210,   211,   212,    -1,   214,   215,    -1,   217,   218,
     219,    -1,   221,   222,   223,   224,   225,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,   234,    -1,   236,    -1,    -1,
      -1,     3,     4,     5,   243,     7,     8,     9,    10,    -1,
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
      -1,    -1,   154,    -1,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,   209,   210,   211,
     212,    -1,   214,   215,    -1,   217,   218,   219,    -1,   221,
     222,   223,   224,   225,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,   234,    -1,   236,    -1,    -1,    -1,     3,     4,
       5,   243,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
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
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,   209,   210,   211,   212,    -1,   214,
     215,    -1,   217,   218,   219,    -1,   221,   222,   223,   224,
     225,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,   234,
      -1,   236,    -1,    -1,    -1,     3,     4,     5,   243,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,    -1,
      -1,   244,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
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
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,   209,   210,   211,   212,    -1,   214,   215,    -1,   217,
     218,   219,    -1,   221,   222,   223,   224,   225,   226,   227,
      -1,    -1,    -1,    -1,    -1,   233,   234,    -1,   236,    -1,
      -1,    -1,     3,     4,     5,   243,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,   238,   239,    -1,    -1,    -1,    -1,   244,    30,
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
      -1,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,   209,   210,
     211,   212,    -1,   214,   215,    -1,   217,   218,   219,    -1,
     221,   222,   223,   224,   225,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,   234,    -1,   236,    -1,    -1,    -1,     3,
       4,     5,   243,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,
     239,    -1,    -1,    -1,    -1,   244,    30,    31,    -1,    -1,
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
      -1,    -1,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,   209,   210,   211,   212,    -1,
     214,   215,    -1,   217,   218,   219,    -1,   221,   222,   223,
     224,   225,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,
     234,    -1,   236,    -1,    -1,    -1,     3,     4,     5,   243,
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
     107,    -1,    -1,    -1,    -1,   112,   113,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,   209,   210,   211,   212,    -1,   214,   215,    -1,
     217,   218,   219,    -1,   221,   222,   223,   224,   225,   226,
     227,    -1,    -1,    -1,    -1,    -1,   233,   234,    -1,   236,
      -1,    -1,    -1,     3,     4,     5,   243,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,    -1,    -1,    -1,    -1,   244,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,   209,
     210,   211,   212,    -1,   214,   215,    -1,   217,   218,   219,
      -1,   221,   222,   223,   224,   225,   226,   227,    -1,    -1,
      -1,    -1,    -1,   233,   234,    -1,   236,    -1,    -1,    -1,
       3,     4,     5,   243,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,
     238,   239,    -1,    -1,    -1,    -1,   244,    30,    31,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,   209,   210,   211,   212,
      -1,   214,   215,    -1,   217,   218,   219,    -1,   221,   222,
     223,   224,   225,   226,   227,    -1,    -1,    -1,    -1,    -1,
     233,   234,    -1,   236,    -1,    -1,    -1,     3,     4,     5,
     243,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,    -1,
      -1,    -1,    -1,   244,    30,    31,    -1,    -1,    -1,    -1,
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
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,   209,   210,   211,   212,    -1,   214,   215,
      -1,   217,   218,   219,    -1,   221,   222,   223,   224,   225,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,   234,    -1,
     236,    -1,    -1,    -1,     3,     4,     5,   243,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,    -1,    -1,
     244,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
     209,   210,   211,   212,    -1,   214,   215,    -1,   217,   218,
     219,    -1,   221,   222,   223,   224,   225,   226,   227,    -1,
      -1,    -1,    -1,    -1,   233,   234,    -1,   236,    -1,    -1,
      -1,     3,     4,     5,   243,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    -1,    -1,    -1,    -1,   244,    30,    31,
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
      -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,   209,   210,   211,
     212,    -1,   214,   215,    -1,   217,   218,   219,    -1,   221,
     222,   223,   224,   225,   226,   227,    -1,    -1,    -1,    -1,
      -1,   233,   234,    -1,   236,    -1,    -1,    -1,     3,     4,
       5,   243,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,
      -1,    -1,    -1,    -1,   244,    30,    31,    -1,    -1,    -1,
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
      -1,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,   209,   210,   211,   212,    -1,   214,
     215,    -1,   217,   218,   219,    -1,   221,   222,   223,   224,
     225,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,   234,
      -1,   236,    -1,    -1,    -1,     3,     4,     5,   243,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,    -1,
      -1,   244,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
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
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,   209,   210,   211,   212,    -1,   214,   215,    -1,   217,
     218,   219,    -1,   221,   222,   223,   224,   225,   226,   227,
      -1,    -1,    -1,    -1,    -1,   233,   234,    -1,   236,    -1,
      -1,    -1,     3,     4,     5,   243,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,   238,   239,    -1,    -1,    -1,    -1,   244,    30,
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
      -1,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,   209,   210,
     211,   212,    -1,   214,   215,    -1,   217,   218,   219,    -1,
     221,   222,   223,   224,   225,   226,   227,    -1,    -1,    -1,
      -1,    -1,   233,   234,    -1,   236,    -1,    -1,    -1,     3,
       4,     5,   243,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,
     239,    -1,    -1,    -1,    -1,   244,    30,    31,    -1,    -1,
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
      -1,    -1,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,   209,   210,   211,   212,    -1,
     214,   215,    -1,   217,   218,   219,    -1,   221,   222,   223,
     224,   225,   226,   227,    -1,    -1,    -1,    -1,    -1,   233,
     234,    -1,   236,    -1,    -1,    -1,     3,     4,     5,   243,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,
      -1,    -1,   244,    30,    31,    -1,    -1,    -1,    -1,    -1,
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
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,   209,   210,   211,   212,    -1,   214,   215,    -1,
     217,   218,   219,    -1,   221,   222,   223,   224,   225,   226,
     227,    -1,    -1,    -1,    -1,    -1,   233,   234,    -1,   236,
      -1,    -1,    -1,     3,     4,     5,   243,     7,     8,     9,
      10,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,    -1,    -1,    -1,    -1,   244,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,   209,
     210,   211,   212,    -1,   214,   215,    -1,   217,   218,   219,
      -1,   221,   222,   223,   224,   225,   226,   227,    -1,    -1,
      -1,    -1,    -1,   233,   234,    -1,   236,    -1,    -1,    -1,
       3,     4,     5,   243,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,
     238,   239,    -1,    -1,    -1,    -1,   244,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    -1,    63,    64,    -1,    89,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,   101,   102,
      -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,   126,   127,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    31,    -1,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,   209,   210,   211,   212,
      -1,   214,   215,    -1,   217,   218,   219,    -1,   221,   222,
     223,   224,   225,   226,   227,   105,    -1,   107,    -1,     5,
     233,   234,    -1,   236,    10,    -1,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,   236,   237,   238,   239,
      -1,    -1,   242,    -1,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
      -1,    -1,    -1,   183,   184,   185,    -1,   187,    -1,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,   197,   198,   199,
     200,    -1,    -1,   203,    -1,   205,    -1,   207,    -1,   105,
     210,   107,   212,    -1,    -1,   215,    -1,    -1,   218,   219,
      -1,   221,   222,    -1,   224,    -1,   226,    -1,    -1,    -1,
     126,   127,    -1,     5,   234,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,   243,   244,    -1,    -1,    -1,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,   178,   179,    -1,    -1,    -1,   183,   184,   185,
      -1,   187,    -1,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,   197,   198,   199,   200,    -1,    -1,   203,    -1,   205,
      -1,   207,    -1,    -1,   210,    -1,   212,    -1,    -1,   215,
      -1,    -1,   218,   219,    -1,   221,   222,    -1,   224,    -1,
     226,    -1,    -1,   105,    -1,   107,    -1,     5,   234,   111,
      -1,    -1,    10,    -1,    -1,    -1,    -1,   243,   244,    -1,
      -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,
      -1,   183,   184,   185,    -1,   187,    -1,   189,   190,   191,
      -1,    -1,    -1,    -1,   196,   197,   198,   199,   200,    -1,
      -1,   203,    -1,   205,    -1,   207,    -1,   105,   210,   107,
     212,    -1,    -1,   215,    -1,    -1,   218,   219,    -1,   221,
     222,    -1,   224,    -1,   226,     5,    -1,    -1,   126,   127,
      10,    -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,    31,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
     178,   179,    -1,    -1,    -1,   183,   184,   185,    -1,   187,
      -1,   189,   190,   191,    -1,    -1,    -1,    -1,   196,   197,
     198,   199,   200,    -1,    -1,   203,    -1,   205,    -1,   207,
      -1,    -1,   210,    -1,   212,    -1,    -1,   215,    -1,    -1,
     218,   219,    -1,   221,   222,   105,   224,   107,   226,     5,
     236,   237,   238,   239,    10,    -1,   234,    -1,   244,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
      -1,    -1,    -1,   183,   184,   185,    -1,   187,    -1,   189,
     190,   191,    -1,    -1,    -1,    -1,   196,   197,   198,   199,
     200,    97,    -1,   203,    -1,   205,    -1,   207,    -1,   105,
     210,   107,   212,    -1,    -1,   215,    -1,    -1,   218,   219,
      -1,   221,   222,    -1,   224,    -1,   226,    -1,    -1,    -1,
     126,   127,     5,    -1,   234,    -1,    -1,    10,    -1,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,   178,   179,    -1,    -1,    -1,   183,   184,   185,
      -1,   187,    -1,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,   197,   198,   199,   200,    -1,    -1,   203,    -1,   205,
      -1,   207,    -1,    -1,   210,    -1,   212,    -1,    -1,   215,
      -1,    -1,   218,   219,    97,   221,   222,    -1,   224,    -1,
     226,    -1,   105,    -1,   107,    -1,     5,    -1,   234,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,   177,   178,   179,    -1,    -1,    -1,
     183,   184,   185,    -1,   187,    -1,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,   197,   198,   199,   200,    -1,    -1,
     203,    -1,   205,    -1,   207,    -1,   105,   210,   107,   212,
      -1,    -1,   215,    -1,    -1,   218,   219,    -1,   221,   222,
      -1,   224,    -1,   226,     5,    -1,    -1,   126,   127,    10,
      -1,   234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,
     179,    -1,    -1,    -1,   183,   184,   185,    -1,   187,    -1,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,   197,   198,
     199,   200,    -1,    -1,   203,    -1,   205,    -1,   207,    -1,
      -1,   210,    -1,   212,    -1,    -1,   215,    -1,    -1,   218,
     219,    -1,   221,   222,   105,   224,   107,   226,   236,   237,
     238,   239,    -1,    -1,    -1,   234,   244,    -1,    -1,    -1,
      63,    64,    -1,    -1,   243,   126,   127,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   177,   178,   179,    -1,
      -1,    -1,   183,   184,   185,    -1,   187,    -1,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,   197,   198,   199,   200,
      -1,    -1,   203,    -1,   205,    -1,   207,    -1,    -1,   210,
      -1,   212,    -1,    -1,   215,    -1,    -1,   218,   219,    -1,
     221,   222,    -1,   224,    -1,   226,    -1,    -1,     4,     5,
       6,    -1,    -1,   234,    -1,    11,    -1,    -1,    -1,    15,
      -1,    17,   243,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,    -1,
      -1,   244,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,
     106,    -1,   108,   109,   236,   237,   238,   239,   114,   115,
      -1,    -1,   244,    -1,    -1,   121,    -1,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,   178,   179,    -1,    -1,    -1,    -1,   184,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,   204,    -1,
      -1,    -1,   208,    -1,     4,     5,     6,   213,    -1,    -1,
     216,    11,    -1,    -1,   220,    15,    -1,    17,    -1,    19,
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
      -1,    -1,   236,   237,   238,   239,    -1,    -1,    -1,    -1,
     244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,   179,
      -1,    -1,    -1,    -1,   184,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,   204,    -1,    -1,    -1,   208,    -1,
       4,     5,     6,   213,    -1,    -1,   216,    11,    -1,    -1,
     220,    15,    -1,    17,    -1,    19,    20,    21,    22,    23,
      24,    -1,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    35,    36,    37,    38,    -1,    -1,    -1,    42,    43,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,
      54,    55,    56,    57,    63,    64,    -1,    61,    62,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    -1,    -1,
      94,    95,    96,    -1,    98,    99,   100,    -1,    -1,   103,
      -1,    -1,   106,    -1,   108,   109,    -1,    -1,    -1,    -1,
     114,   115,    -1,    -1,    -1,    -1,    -1,   121,    -1,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,   236,   237,
     238,   239,    63,    64,    -1,    -1,   244,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,   177,   178,   179,    63,    64,    -1,    -1,
     184,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     204,    -1,    -1,    -1,   208,    -1,    -1,    -1,    -1,   213,
      63,    64,   216,    -1,    -1,    -1,   220,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   236,   237,   238,
     239,    63,    64,    -1,    -1,   244,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,   236,   237,   238,   239,    63,
      64,    -1,    -1,   244,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    63,    64,    -1,    -1,   244,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,   236,   237,   238,   239,    63,    64,    -1,
      -1,   244,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   236,   237,   238,   239,    -1,    -1,
      -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    -1,    -1,    -1,    -1,   244,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,
      -1,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    -1,    -1,    -1,    -1,   244,    -1,    -1,
      -1,    -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,
     242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    63,    64,   242,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    63,    64,   242,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,
      -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,    63,    64,   242,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
     236,   237,   238,   239,    63,    64,   242,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   236,   237,   238,   239,
      63,    64,   242,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,   236,
     237,   238,   239,    63,    64,   242,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,   236,   237,
     238,   239,    63,    64,   242,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   236,   237,   238,
     239,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,
     239,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,
     239,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    63,    64,   242,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   236,   237,   238,   239,    63,    64,   242,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,   236,   237,   238,   239,
      -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,    63,    64,   242,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,    63,
      64,   242,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   236,
     237,   238,   239,    63,    64,   242,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     236,   237,   238,   239,    63,    64,   242,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,   236,   237,
     238,   239,    63,    64,   242,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,
     239,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,
     239,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,
     239,    63,    64,   242,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   236,   237,   238,   239,
      63,    64,   242,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   236,   237,   238,
     239,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    63,    64,   242,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,   236,   237,   238,   239,    63,
      64,   242,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,   236,   237,   238,   239,    63,    64,
     242,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,   236,   237,   238,   239,    63,    64,   242,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   236,
     237,   238,   239,    63,    64,   242,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,
     239,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,
     239,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   236,   237,   238,   239,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,
     239,    63,    64,   242,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,    63,    64,   242,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
     236,   237,   238,   239,    -1,    -1,   242,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,    63,
      64,   242,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   236,   237,   238,   239,
      63,    64,   242,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,   236,   237,   238,   239,    63,    64,
     242,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,   236,   237,
     238,   239,    63,    64,   242,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   236,   237,   238,   239,    63,    64,   242,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   236,   237,   238,   239,    -1,    -1,   242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,
     238,   239,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,   242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,
     238,   239,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,   237,   238,   239,    -1,    -1,   242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,
     238,   239,    63,    64,   242,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,    63,    64,   242,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,    -1,
      -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,   238,   239,    63,    64,   242,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   236,
     237,   238,   239,    63,    64,   242,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   236,   237,   238,   239,    63,
      64,   242,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,   236,   237,
     238,   239,    63,    64,   242,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,
     239,    63,    64,   242,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   236,   237,   238,   239,
      -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,    -1,    -1,   242,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,
      -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,    -1,    -1,   242,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,
      -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,    63,    64,   242,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,   236,   237,   238,   239,    63,    64,   242,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,   236,   237,   238,   239,    -1,
      -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     236,   237,   238,   239,    63,    64,   242,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,   236,   237,   238,   239,    63,    64,
     242,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,   236,   237,
     238,   239,    63,    64,   242,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   236,
     237,   238,   239,    -1,    -1,   242,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,
     239,    -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,    -1,    -1,   242,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,
      -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,    -1,    -1,   242,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,
      -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   236,   237,   238,   239,    -1,    -1,   242,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,
      -1,    -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   236,   237,   238,   239,    -1,
      -1,   242
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   228,   229,   230,   231,   232,   247,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   114,   115,
     121,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     144,   145,   146,   147,   148,   149,   177,   178,   179,   184,
     204,   208,   213,   216,   220,   248,   249,   252,   253,   260,
     261,   263,   264,   268,   280,   281,   286,   292,   299,   307,
     315,   318,   322,   325,   331,     3,     4,     5,     7,     8,
       9,    10,    30,    31,    63,    64,    65,    66,    67,    68,
      69,    81,    84,    89,   101,   102,   105,   107,   115,   122,
     126,   127,   144,   145,   146,   147,   148,   149,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     209,   210,   211,   212,   214,   215,   217,   218,   219,   221,
     222,   223,   224,   225,   226,   227,   233,   234,   236,   243,
     266,   267,   269,   275,   277,   280,   281,   144,   145,   146,
     147,   243,   266,   252,   280,   281,   286,     0,    75,   243,
      75,   243,   300,   319,   323,     4,     7,   278,   278,   278,
      34,   269,   254,   255,   266,   282,   283,   282,   266,    28,
       7,   308,   316,   269,    58,    60,    61,   245,   362,   258,
     266,   269,     4,     5,   279,   269,   266,   269,   266,   269,
       4,     5,   342,   343,    10,   236,   237,   276,   277,   344,
     278,    89,    97,   245,   266,   269,   363,    89,    97,   110,
     363,   363,    81,    82,    88,   111,   269,   274,    12,    53,
     274,   111,   274,    59,    89,    90,    91,    96,    95,   269,
     261,   268,   266,   266,   266,   110,   274,    90,    91,    92,
      93,    94,   104,   110,   111,   116,   117,   118,   119,   120,
     274,   274,   111,   274,   111,   274,    95,   111,   274,    61,
      95,   111,   142,   274,   274,    22,    61,   111,   274,   111,
     274,   111,   274,   111,   266,   266,   266,    61,   111,   111,
     142,   143,   274,   111,   274,   274,   111,   274,   274,   274,
      95,   142,   143,   151,   154,   274,    95,   142,   143,   154,
     274,    95,   142,   143,   151,   152,   153,   154,   274,    61,
      95,   142,   143,   150,   154,   274,   111,   274,   111,   274,
     243,   243,   243,   243,   243,   266,   363,   266,   266,   266,
      44,   250,    92,    93,   104,    75,    75,    24,   243,   243,
     243,   243,   269,   243,   243,   243,   243,   243,   243,   112,
     113,   243,   243,   243,   243,   112,   243,   112,   155,   112,
     155,   112,   113,   155,   112,   113,   155,   112,   113,   155,
     112,   113,   155,   112,   112,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   269,   266,   269,    70,    71,
      72,    73,    74,    75,    76,   237,    44,    63,    64,    70,
      71,    72,    73,    74,    75,    76,    77,   236,   237,   238,
     239,   266,    44,    44,    44,   269,   282,   266,   282,     4,
     269,   249,    35,    36,    20,    21,     4,     5,   293,   294,
       4,     5,   295,   296,   266,   269,   284,   285,   266,   269,
     310,   249,   326,   332,   243,    58,   243,     4,     7,   243,
     266,   269,   345,    58,    60,    61,   245,   347,   360,   243,
     243,   242,   242,   242,   243,   243,   242,   277,   277,   242,
     269,   266,   269,    11,   242,   242,   274,   266,   266,   266,
     242,   274,   259,    12,   242,   262,   266,   242,   274,    12,
     274,   262,   262,   262,   274,   274,   274,   274,   274,   274,
     274,   266,   266,   274,   274,   274,   274,   262,   262,   266,
     242,   266,   242,   266,   266,   262,   266,   266,   266,   266,
     262,   242,   266,   266,   266,   262,   266,   262,   266,   242,
     266,   242,   242,   242,   266,   266,   266,   266,   266,   262,
     266,   262,   262,   266,   262,   262,   262,   266,   266,   266,
     266,   266,   262,   266,   266,   266,   266,   262,   266,   266,
     266,   266,   266,   266,   266,   262,   266,   266,   266,   150,
     266,   266,   266,   262,   266,   242,   266,   242,     5,   265,
     265,   265,   244,   269,   266,   242,   242,   242,   242,    43,
     274,   274,   274,   269,   266,   287,   282,   282,   269,   269,
     269,   269,   269,   269,    97,   266,   363,   363,   266,     4,
       5,   272,   273,   272,   273,   274,   269,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   150,   266,   266,   266,   266,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   363,   269,
     269,   269,   269,   269,   269,   269,   269,   244,   269,   266,
     266,   266,   266,   266,   269,   269,   266,   269,   244,   269,
     269,   266,   269,   266,   269,   266,   266,   244,   266,   244,
     266,   244,   266,   244,   266,   266,   266,   266,   269,   266,
     266,   266,   266,   266,   266,   266,   363,   266,   282,   282,
     266,   269,   266,   266,   266,   266,   266,   244,   244,   266,
     265,   266,   265,   266,   266,   266,   244,   244,   266,   266,
     266,   266,   266,   266,   266,   266,   271,   270,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     244,   244,    75,   320,    14,    16,    18,    41,    44,    49,
     324,   256,   257,   243,   243,   242,   243,   243,   242,   242,
      43,   309,    14,    16,    18,    41,    44,    49,   317,    46,
     249,   269,   243,   266,   269,    51,   346,   241,   242,   243,
      58,   243,     4,     7,   243,    10,   361,   282,   282,     4,
       5,   269,   269,   282,   282,   343,    10,   276,   242,    86,
      87,    97,   266,   269,   262,   242,   269,   347,   274,   242,
     266,   274,   262,   269,   269,   274,   242,   262,   242,   262,
     242,   262,   262,   242,   242,   242,   262,   262,   274,   274,
     242,   266,   242,   266,   242,   274,   242,   242,   242,   274,
     266,   242,   242,   242,   274,   242,   274,   242,   266,   242,
     269,   266,   266,   242,   242,   242,   242,   242,   274,   242,
     274,   274,   242,   274,   274,   274,   242,   242,   242,   274,
     242,   242,   242,   274,   242,   242,   242,   242,   242,   274,
     242,   242,   266,   242,   242,   242,   274,   242,   266,   242,
     266,   243,   242,   242,   242,   244,   244,   266,   269,   266,
     269,   269,   269,   251,   242,   262,   262,     4,     5,   291,
     244,   244,   242,   242,   244,   242,   242,   242,   244,   242,
     244,   242,   244,   242,   243,   243,   244,   244,   242,   242,
     262,   242,   242,   244,   242,   242,   242,   266,   242,   242,
     244,   244,   244,   244,   244,   242,   244,   244,   242,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     242,   244,   244,   242,   242,   242,   244,   242,   242,   244,
     242,   244,   244,   244,   244,   244,   242,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   242,   242,
     242,   242,   244,   244,   244,   244,   244,   242,   244,   244,
     244,   244,   244,   244,   242,   244,   242,   242,   242,   242,
     242,   244,   242,   242,   244,   242,   244,   244,   269,   269,
     301,   249,   269,   278,   364,   278,   365,   282,   282,   294,
     282,   282,   296,   285,    43,   311,   327,    49,    50,   333,
     242,   269,   242,   244,   244,   243,   266,   266,   269,   269,
     243,   266,   348,   349,   269,     4,     5,   339,   341,   244,
     244,   243,   243,   242,   242,   244,   244,   269,    85,    85,
     242,   242,   274,   266,   266,   242,   274,   242,   242,   242,
     266,   274,   269,   274,   266,   274,   274,   266,   269,   269,
     269,   274,   274,   242,   242,   269,   242,   269,   242,   266,
     269,   242,   266,   266,   266,   242,   242,   266,   266,   266,
     269,   242,   266,   242,   269,   242,   266,   242,   266,   266,
     269,   266,   269,   242,   266,   242,   242,   269,   242,   242,
     242,   266,   269,   266,   269,   269,   242,   266,   269,   269,
     242,   266,   266,   269,   266,   266,   269,   242,   266,   269,
     242,   269,   266,   269,   242,   266,   242,   269,   242,   282,
     269,   269,   269,   242,   242,   253,   269,   274,   274,   288,
     269,   269,   269,   269,   269,   266,    97,   266,   266,   244,
     244,   269,   269,   274,   269,   266,   269,   269,   269,   269,
     266,   269,   269,   269,   269,   269,   269,   269,   269,   266,
     269,   266,   266,   266,   266,   266,   269,   269,   269,   269,
     273,   266,   273,   266,   266,   269,    16,    44,   321,   242,
     242,   244,   244,   244,   244,    39,    40,   313,   249,   269,
     242,   266,    58,   266,   346,   242,   269,   242,   244,   339,
     339,   244,   243,   243,   242,   282,   282,   269,   269,   242,
     363,   363,   266,   266,   242,   242,   266,   269,   269,   266,
     242,   242,   262,   242,   242,   262,   242,   242,   242,   262,
     242,   266,   266,   266,   266,   266,   242,   266,   266,   242,
     242,   242,   266,   242,   266,   266,   242,   266,   242,   242,
     266,   242,   266,   266,   266,   266,   266,   242,   266,   266,
     242,   242,   266,   242,   242,   269,   242,   266,   266,   242,
     266,   244,   244,   244,   242,   244,   266,   266,   262,   243,
     244,   244,   244,   244,   244,   244,   244,   242,   244,   244,
     244,   244,   262,   242,   242,   244,   244,   244,   244,   244,
     242,   244,   244,   244,   242,   244,   244,   244,   242,   242,
     244,   242,   244,   244,   244,   242,   242,   244,   242,   244,
     244,   242,   244,   244,   244,    12,   278,   278,   310,    43,
      38,   328,   244,   269,   244,   243,   242,   269,   242,   266,
      58,   355,   350,   282,   282,   340,   244,   244,   266,   266,
     266,   242,   242,   242,   266,   266,   274,   266,   266,   274,
     269,   269,   269,   274,   269,   242,   242,   242,   242,   269,
     242,   242,   266,   269,   269,   242,   266,   242,   242,   269,
     269,   266,   269,   242,   266,   242,   242,   242,   242,   242,
     266,   242,   242,   266,   269,   266,   242,   269,   269,   269,
     242,   242,   269,    75,    75,   269,    75,   242,   274,     4,
       5,   297,   298,   266,   269,   266,   269,   269,   266,   266,
     269,   269,   266,   269,   266,   266,   269,   312,   314,    48,
     335,    60,    61,   244,    58,   269,   266,   244,   269,   244,
     243,   361,   339,   244,   244,   339,   242,   266,   266,   266,
     242,   262,   242,   242,   242,   262,   242,   266,   269,   269,
     266,   242,   269,   266,   242,   266,   242,   266,   269,   242,
     242,   266,   266,   269,   269,   266,   266,   269,   266,   242,
     269,   242,   242,   242,   269,   266,   242,   266,   266,   244,
     266,   269,   243,   243,   242,   244,   244,   242,   244,   244,
     244,   244,   244,   244,   244,   244,   244,    13,   305,   249,
     249,   269,    47,   334,   243,   243,   242,   244,    60,    61,
     351,   244,    58,   356,   269,   339,   266,   266,   274,   269,
     266,   269,   274,   269,   242,   242,   242,   242,   269,   242,
     242,   269,   242,   269,   242,   242,   269,   269,   242,   242,
     242,   242,   242,   242,   269,   242,   269,   269,   269,   242,
     242,   269,    75,   244,   244,   298,   289,   269,   269,   302,
      46,   338,   249,   329,   266,   269,   269,   357,   243,   361,
     352,   243,   361,   242,   242,   242,   242,   242,   242,   266,
     266,   266,   266,   242,   266,   266,   242,   269,   266,   269,
     242,   266,   269,   269,   266,   266,   266,   266,   242,   242,
     242,   266,   266,   266,   249,   244,   249,   336,    14,    16,
      18,    41,    44,    49,   330,   242,   244,   242,   244,   361,
     266,   339,   361,   269,   339,   269,   266,   266,   269,   266,
     266,   242,   269,   269,   242,   242,   242,   269,   242,   242,
     269,   266,   269,   242,    25,    44,   290,   303,   249,   266,
     269,   339,   242,   244,   339,   242,   244,   242,   266,   269,
     266,   269,   266,   266,   242,   266,    14,    16,    18,    41,
      44,    49,   304,   337,   244,   244,   266,   358,   269,   353,
     266,   242,   242,   269,     4,   306,   335,   244,   361,   244,
     361,   266,   266,   242,   359,   339,   354,   339,   242,   266,
     361,   361,   266,   339,   339
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   246,   247,   247,   247,   247,   247,   248,   249,   250,
     251,   249,   252,   252,   252,   252,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   254,   253,   255,   253,   253,   253,   253,   253,   253,
     253,   256,   253,   257,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   258,   253,   259,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   260,
     260,   260,   260,   260,   261,   261,   261,   261,   261,   261,
     262,   262,   263,   263,   263,   263,   263,   264,   264,   265,
     265,   266,   266,   266,   266,   266,   266,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   268,
     268,   270,   269,   271,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   272,   273,   274,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   276,   276,   276,   277,
     277,   277,   277,   278,   278,   279,   279,   279,   279,   280,
     281,   283,   282,   284,   284,   284,   285,   285,   287,   288,
     289,   286,   290,   290,   291,   291,   292,   292,   292,   292,
     293,   293,   294,   294,   294,   294,   295,   295,   296,   296,
     296,   296,   297,   297,   297,   298,   298,   298,   298,   300,
     301,   302,   303,   299,   304,   304,   304,   304,   304,   304,
     305,   305,   306,   306,   308,   307,   309,   309,   310,   310,
     311,   312,   311,   313,   314,   313,   316,   315,   317,   317,
     317,   317,   317,   317,   319,   320,   318,   321,   321,   323,
     322,   324,   324,   324,   324,   324,   324,   326,   327,   328,
     329,   325,   330,   330,   330,   330,   330,   330,   332,   331,
     333,   333,   334,   334,   335,   336,   337,   335,   338,   338,
     339,   340,   339,   341,   341,   341,   341,   342,   342,   343,
     343,   343,   343,   344,   344,   344,   344,   345,   345,   345,
     345,   345,   346,   346,   346,   348,   347,   349,   347,   350,
     347,   351,   347,   352,   347,   353,   347,   354,   347,   355,
     347,   356,   347,   357,   347,   358,   347,   359,   347,   360,
     347,   361,   361,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   363,   363,   364,
     364,   365,   365
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
       5,     3,    11,    10,     5,     6,     9,     2,     3,     2,
       2,     1,     1,     3,     4,     4,     4,     4,     4,     4,
       1,     1,     2,     1,     2,     2,     8,     6,     6,     0,
       1,     1,     2,     2,     3,    10,     8,     8,     8,     3,
       1,     1,     6,     4,     4,     6,     6,     4,     6,     1,
       4,     1,     1,     1,     1,     3,     3,     6,     6,     8,
       6,     4,     6,     8,     4,     1,     3,     4,     4,     4,
       4,     4,     4,     4,     6,     8,     4,     4,     4,     4,
       4,     6,     1,     3,     1,     3,     4,     3,     3,     3,
       3,     5,     5,     5,     7,     3,     6,     6,     4,     6,
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
       4,     2,     5,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     5,     5,     7,     4,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     4,     6,     4,     6,     4,
       4,     0,     2,     0,     1,     3,     1,     1,     0,     0,
       0,    11,     1,     1,     1,     1,     0,     1,     1,     2,
       1,     3,     1,     1,     4,     4,     1,     3,     1,     1,
       4,     4,     0,     1,     3,     1,     1,     3,     3,     0,
       0,     0,     0,    14,     1,     1,     1,     1,     1,     1,
       0,     2,     0,     1,     0,     7,     1,     2,     1,     1,
       0,     0,     5,     0,     0,     4,     0,     4,     1,     1,
       1,     1,     1,     1,     0,     0,     6,     1,     1,     0,
       4,     1,     2,     1,     1,     1,     1,     0,     0,     0,
       0,    11,     1,     1,     1,     1,     1,     1,     0,     5,
       1,     1,     0,     2,     0,     0,     0,     7,     0,     1,
       1,     0,     4,     1,     4,     1,     4,     1,     3,     1,
       4,     1,     4,     1,     1,     3,     3,     0,     2,     4,
       1,     3,     0,     2,     6,     0,     4,     0,     4,     0,
       6,     0,     9,     0,    10,     0,    13,     0,    15,     0,
       7,     0,     9,     0,    10,     0,    13,     0,    15,     0,
       3,     0,     1,     0,     2,     2,     4,     1,     4,     6,
       6,     7,    10,    12,     7,    10,    12,     2,     1,     1,
       3,     1,     3
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

  case 197: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 198: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 199: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 200: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 201: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 202: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 203: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 204: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 205: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 206: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 207: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 208: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 209: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 210: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 211: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 212: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 213: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 214: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 215: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 216: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 217: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 218: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 219: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 220: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 221: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 222: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 223: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 224: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 225: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 226: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 227: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 228: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 229: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 232: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 233: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 234: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 235: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 236: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 237: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 238: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 239: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 240: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 241: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 243: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 244: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 245: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 247: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 248: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 249: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 250: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 251: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 252: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 253: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 254: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 255: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 256: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 257: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 258: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 259: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 260: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 261: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 262: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 263: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 264: /* string_function: tSTRING2 '(' expression ',' string_expression ')'  */
                                                      {create_function(fSTRING);}
    break;

  case 265: /* string_function: tREPLACE '(' string_expression ',' string_expression ',' string_expression ')'  */
                                                                                    {create_function(fREPLACE);}
    break;

  case 266: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 267: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 268: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 269: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 270: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 271: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 272: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 273: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 274: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 275: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 276: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 277: /* string_function: tTEXTCONTROL tGET string_expression  */
                                        {create_function(fYABTEXTCONTROLGET);}
    break;

  case 278: /* string_function: tTEXTEDIT tGET string_expression  */
                                     {create_function(fYABTEXTEDITGET);}
    break;

  case 279: /* string_function: tTEXTCONTROL tGETS string_expression  */
                                                         {create_function(fYABTEXTCONTROLGET);}
    break;

  case 280: /* string_function: tTEXTEDIT tGETS string_expression  */
                                                      {create_function(fYABTEXTEDITGET);}
    break;

  case 281: /* string_function: tLISTBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABLISTBOXGET);}
    break;

  case 282: /* string_function: tDROPBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABDROPBOXGET);}
    break;

  case 283: /* string_function: tTREEBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABTREEBOXGET);}
    break;

  case 284: /* string_function: tCOLUMNBOX tGETS string_expression ',' expression ',' expression  */
                                                                                     {create_function(fYABCOLUMNBOXGET);}
    break;

  case 285: /* string_function: tCALENDAR tGET string_expression  */
                                                     {create_function(fYABCALENDARGET);}
    break;

  case 286: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 287: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 288: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 289: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 290: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 291: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 292: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 293: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 294: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 295: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 296: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 297: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 298: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 299: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 300: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 301: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 302: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 303: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 304: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 305: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 306: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 307: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 308: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 309: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 310: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 311: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 312: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 313: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 314: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 315: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 316: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 317: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 318: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 319: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 320: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 321: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 322: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 323: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 324: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 325: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 326: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 327: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 328: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 329: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 330: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 331: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 332: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 333: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 334: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 337: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 338: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 340: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 341: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 342: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 343: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 344: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 345: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 346: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 347: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 348: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 349: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 350: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 351: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 352: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 353: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 354: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 355: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 356: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 357: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 358: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 359: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 360: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 361: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 362: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 363: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 364: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 365: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 366: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 367: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 368: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 369: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 370: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 371: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 372: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 373: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 374: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 375: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 376: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 377: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 378: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 379: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 380: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 381: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 382: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 383: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 384: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 385: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 386: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 387: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 388: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 389: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 390: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 391: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 392: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 393: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 394: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 395: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 396: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 397: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 398: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 399: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 400: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 401: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 402: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 403: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 404: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 405: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 406: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 407: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 408: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 409: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 410: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 411: /* function: tWINDOW tCOUNT  */
                   {create_function(fYABNUMWINDOWS);}
    break;

  case 412: /* function: tWINDOW tGET string_expression ',' string_expression  */
                                                         {create_function(fYABWINDOWGET);}
    break;

  case 413: /* function: tLISTBOX tCOUNT string_expression  */
                                                      {create_function(fYABLISTBOXCOUNT);}
    break;

  case 414: /* function: tLISTBOX tGET string_expression  */
                                                    {create_function(fYABLISTBOXSELECTED);}
    break;

  case 415: /* function: tDROPBOX tCOUNT string_expression  */
                                                      {create_function(fYABDROPBOXCOUNT);}
    break;

  case 416: /* function: tDROPBOX tGET string_expression  */
                                                    {create_function(fYABDROPBOXSELECTED);}
    break;

  case 417: /* function: tTREEBOX tCOUNT string_expression  */
                                                      {create_function(fYABTREEBOXCOUNT);}
    break;

  case 418: /* function: tTREEBOX tGET string_expression  */
                                                    {create_function(fYABTREEBOXSELECTED);}
    break;

  case 419: /* function: tCOLUMNBOX tCOUNT string_expression  */
                                                        {create_function(fYABCOLUMNBOXCOUNT);}
    break;

  case 420: /* function: tCOLUMNBOX tCOUNT tCOLUMN string_expression  */
                                                                {create_function(fYABCOLUMNBOXCOUNTCOLUMNS);}
    break;

  case 421: /* function: tCOLUMNBOX tGET string_expression  */
                                                      {create_function(fYABCOLUMNBOXSELECTED);}
    break;

  case 422: /* function: tCOLORCONTROL tGET string_expression ',' string_expression  */
                                                                               {create_function(fYABCOLORCONTROLGET);}
    break;

  case 423: /* function: tDRAW tGET string_expression ',' string_expression  */
                                                       {create_function(fYABDRAWGET);}
    break;

  case 424: /* function: tDRAW tGET string_expression ',' string_expression ',' string_expression  */
                                                                             {create_function(fYABDRAWGETTEXT);}
    break;

  case 425: /* function: tBFILESIZE '(' string_expression ')'  */
                                         {create_function(fYABBFILESIZE);}
    break;

  case 426: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 427: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 428: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 429: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 430: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 431: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 432: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 433: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 434: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 435: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 436: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 437: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 438: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 439: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 440: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 441: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 448: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 449: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 450: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 451: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 452: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 453: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 454: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 455: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 456: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 457: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 458: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 459: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 462: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 463: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 464: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 465: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 468: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 469: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 470: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 471: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 475: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 476: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 477: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 478: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 479: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 480: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 481: /* $@17: %empty  */
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

  case 482: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 483: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 484: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 485: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 486: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 487: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 488: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 489: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 490: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 492: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 493: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 494: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 495: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 501: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 502: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 504: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 506: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 508: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 509: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 510: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 511: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 512: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 513: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 514: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 515: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 517: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 518: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 519: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 521: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 522: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 523: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 524: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 525: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 526: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 527: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 528: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 529: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 530: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 532: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 533: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 534: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 535: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 536: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 537: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 538: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 540: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 541: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 545: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 546: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 551: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 553: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 554: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 555: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 556: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 559: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 560: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 561: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 562: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 563: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 564: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 565: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 566: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 570: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 571: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 572: /* using: %empty  */
       {create_print('d');}
    break;

  case 573: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 574: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 575: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 576: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 577: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 578: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 579: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 580: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 581: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 582: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 583: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 584: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 585: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 586: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 587: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 588: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 589: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 590: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 591: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 592: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 593: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 594: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 595: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 596: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 597: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 598: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 599: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 600: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 601: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 602: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 603: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 604: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 605: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 606: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 607: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 608: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 609: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 610: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 611: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 612: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 613: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 614: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 615: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 616: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 619: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 620: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 621: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 622: /* gosub_list: gosub_list ',' symbol_or_lineno  */
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

