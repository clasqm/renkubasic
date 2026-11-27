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
  YYSYMBOL_tBITMAP = 163,                  /* tBITMAP  */
  YYSYMBOL_tSIN = 164,                     /* tSIN  */
  YYSYMBOL_tASIN = 165,                    /* tASIN  */
  YYSYMBOL_tCOS = 166,                     /* tCOS  */
  YYSYMBOL_tACOS = 167,                    /* tACOS  */
  YYSYMBOL_tTAN = 168,                     /* tTAN  */
  YYSYMBOL_tATAN = 169,                    /* tATAN  */
  YYSYMBOL_tEXP = 170,                     /* tEXP  */
  YYSYMBOL_tLOG = 171,                     /* tLOG  */
  YYSYMBOL_tSQRT = 172,                    /* tSQRT  */
  YYSYMBOL_tSQR = 173,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 174,                   /* tMYEOF  */
  YYSYMBOL_tABS = 175,                     /* tABS  */
  YYSYMBOL_tSIG = 176,                     /* tSIG  */
  YYSYMBOL_tINT = 177,                     /* tINT  */
  YYSYMBOL_tCEIL = 178,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 179,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 180,                    /* tFRAC  */
  YYSYMBOL_tROUND = 181,                   /* tROUND  */
  YYSYMBOL_tMOD = 182,                     /* tMOD  */
  YYSYMBOL_tRAN = 183,                     /* tRAN  */
  YYSYMBOL_tVAL = 184,                     /* tVAL  */
  YYSYMBOL_tLEFT = 185,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 186,                   /* tRIGHT  */
  YYSYMBOL_tMID = 187,                     /* tMID  */
  YYSYMBOL_tLEN = 188,                     /* tLEN  */
  YYSYMBOL_tMIN = 189,                     /* tMIN  */
  YYSYMBOL_tMAX = 190,                     /* tMAX  */
  YYSYMBOL_tSTR = 191,                     /* tSTR  */
  YYSYMBOL_tINKEY = 192,                   /* tINKEY  */
  YYSYMBOL_tCHR = 193,                     /* tCHR  */
  YYSYMBOL_tASC = 194,                     /* tASC  */
  YYSYMBOL_tHEX = 195,                     /* tHEX  */
  YYSYMBOL_tDEC = 196,                     /* tDEC  */
  YYSYMBOL_tBIN = 197,                     /* tBIN  */
  YYSYMBOL_tUPPER = 198,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 199,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 200,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 201,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 202,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 203,                /* tMOUSEMOD  */
  YYSYMBOL_tTRIM = 204,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 205,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 206,                   /* tRTRIM  */
  YYSYMBOL_tSTRING2 = 207,                 /* tSTRING2  */
  YYSYMBOL_tREPLACE = 208,                 /* tREPLACE  */
  YYSYMBOL_tINSTR = 209,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 210,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 211,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 212,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 213,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 214,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 215,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 216,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 217,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 218,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 219,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 220,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 221,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 222,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 223,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 224,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 225,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 226,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 227,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 228,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 229,                    /* tDATE  */
  YYSYMBOL_tTIME = 230,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 231,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 232,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 233,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 234,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 235,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 236,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 237,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 238, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 239,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 240, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 241,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 242,                   /* tEVAL2  */
  YYSYMBOL_tARGUMENT = 243,                /* tARGUMENT  */
  YYSYMBOL_244_ = 244,                     /* '-'  */
  YYSYMBOL_245_ = 245,                     /* '+'  */
  YYSYMBOL_246_ = 246,                     /* '*'  */
  YYSYMBOL_247_ = 247,                     /* '/'  */
  YYSYMBOL_UMINUS = 248,                   /* UMINUS  */
  YYSYMBOL_249_ = 249,                     /* ';'  */
  YYSYMBOL_250_ = 250,                     /* ','  */
  YYSYMBOL_251_ = 251,                     /* '('  */
  YYSYMBOL_252_ = 252,                     /* ')'  */
  YYSYMBOL_253_ = 253,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 254,                 /* $accept  */
  YYSYMBOL_program_or_expression = 255,    /* program_or_expression  */
  YYSYMBOL_program = 256,                  /* program  */
  YYSYMBOL_statement_list = 257,           /* statement_list  */
  YYSYMBOL_258_1 = 258,                    /* $@1  */
  YYSYMBOL_259_2 = 259,                    /* $@2  */
  YYSYMBOL_assignment = 260,               /* assignment  */
  YYSYMBOL_statement = 261,                /* statement  */
  YYSYMBOL_262_3 = 262,                    /* $@3  */
  YYSYMBOL_263_4 = 263,                    /* $@4  */
  YYSYMBOL_264_5 = 264,                    /* $@5  */
  YYSYMBOL_265_6 = 265,                    /* $@6  */
  YYSYMBOL_266_7 = 266,                    /* $@7  */
  YYSYMBOL_267_8 = 267,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 268,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 269,        /* string_assignment  */
  YYSYMBOL_to = 270,                       /* to  */
  YYSYMBOL_open_clause = 271,              /* open_clause  */
  YYSYMBOL_seek_clause = 272,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 273,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 274,        /* string_expression  */
  YYSYMBOL_string_function = 275,          /* string_function  */
  YYSYMBOL_number_assignment = 276,        /* number_assignment  */
  YYSYMBOL_expression = 277,               /* expression  */
  YYSYMBOL_278_9 = 278,                    /* $@9  */
  YYSYMBOL_279_10 = 279,                   /* $@10  */
  YYSYMBOL_arrayref = 280,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 281,          /* string_arrayref  */
  YYSYMBOL_coordinates = 282,              /* coordinates  */
  YYSYMBOL_function = 283,                 /* function  */
  YYSYMBOL_const = 284,                    /* const  */
  YYSYMBOL_number = 285,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 286,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 287,                  /* dimlist  */
  YYSYMBOL_function_or_array = 288,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 289,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 290,                /* call_list  */
  YYSYMBOL_291_11 = 291,                   /* $@11  */
  YYSYMBOL_calls = 292,                    /* calls  */
  YYSYMBOL_call_item = 293,                /* call_item  */
  YYSYMBOL_function_definition = 294,      /* function_definition  */
  YYSYMBOL_295_12 = 295,                   /* $@12  */
  YYSYMBOL_296_13 = 296,                   /* $@13  */
  YYSYMBOL_297_14 = 297,                   /* $@14  */
  YYSYMBOL_endsub = 298,                   /* endsub  */
  YYSYMBOL_function_name = 299,            /* function_name  */
  YYSYMBOL_export = 300,                   /* export  */
  YYSYMBOL_local_list = 301,               /* local_list  */
  YYSYMBOL_local_item = 302,               /* local_item  */
  YYSYMBOL_static_list = 303,              /* static_list  */
  YYSYMBOL_static_item = 304,              /* static_item  */
  YYSYMBOL_paramlist = 305,                /* paramlist  */
  YYSYMBOL_paramitem = 306,                /* paramitem  */
  YYSYMBOL_for_loop = 307,                 /* for_loop  */
  YYSYMBOL_308_15 = 308,                   /* $@15  */
  YYSYMBOL_309_16 = 309,                   /* $@16  */
  YYSYMBOL_310_17 = 310,                   /* $@17  */
  YYSYMBOL_311_18 = 311,                   /* $@18  */
  YYSYMBOL_next = 312,                     /* next  */
  YYSYMBOL_step_part = 313,                /* step_part  */
  YYSYMBOL_next_symbol = 314,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 315,  /* switch_number_or_string  */
  YYSYMBOL_316_19 = 316,                   /* $@19  */
  YYSYMBOL_sep_list = 317,                 /* sep_list  */
  YYSYMBOL_number_or_string = 318,         /* number_or_string  */
  YYSYMBOL_case_list = 319,                /* case_list  */
  YYSYMBOL_320_20 = 320,                   /* $@20  */
  YYSYMBOL_default = 321,                  /* default  */
  YYSYMBOL_322_21 = 322,                   /* $@21  */
  YYSYMBOL_do_loop = 323,                  /* do_loop  */
  YYSYMBOL_324_22 = 324,                   /* $@22  */
  YYSYMBOL_loop = 325,                     /* loop  */
  YYSYMBOL_while_loop = 326,               /* while_loop  */
  YYSYMBOL_327_23 = 327,                   /* $@23  */
  YYSYMBOL_328_24 = 328,                   /* $@24  */
  YYSYMBOL_wend = 329,                     /* wend  */
  YYSYMBOL_repeat_loop = 330,              /* repeat_loop  */
  YYSYMBOL_331_25 = 331,                   /* $@25  */
  YYSYMBOL_until = 332,                    /* until  */
  YYSYMBOL_if_clause = 333,                /* if_clause  */
  YYSYMBOL_334_26 = 334,                   /* $@26  */
  YYSYMBOL_335_27 = 335,                   /* $@27  */
  YYSYMBOL_336_28 = 336,                   /* $@28  */
  YYSYMBOL_337_29 = 337,                   /* $@29  */
  YYSYMBOL_endif = 338,                    /* endif  */
  YYSYMBOL_short_if = 339,                 /* short_if  */
  YYSYMBOL_340_30 = 340,                   /* $@30  */
  YYSYMBOL_end_of_if = 341,                /* end_of_if  */
  YYSYMBOL_else_part = 342,                /* else_part  */
  YYSYMBOL_elsif_part = 343,               /* elsif_part  */
  YYSYMBOL_344_31 = 344,                   /* $@31  */
  YYSYMBOL_345_32 = 345,                   /* $@32  */
  YYSYMBOL_maybe_then = 346,               /* maybe_then  */
  YYSYMBOL_inputlist = 347,                /* inputlist  */
  YYSYMBOL_348_33 = 348,                   /* $@33  */
  YYSYMBOL_input = 349,                    /* input  */
  YYSYMBOL_readlist = 350,                 /* readlist  */
  YYSYMBOL_readitem = 351,                 /* readitem  */
  YYSYMBOL_datalist = 352,                 /* datalist  */
  YYSYMBOL_printlist = 353,                /* printlist  */
  YYSYMBOL_using = 354,                    /* using  */
  YYSYMBOL_inputbody = 355,                /* inputbody  */
  YYSYMBOL_356_34 = 356,                   /* $@34  */
  YYSYMBOL_357_35 = 357,                   /* $@35  */
  YYSYMBOL_358_36 = 358,                   /* $@36  */
  YYSYMBOL_359_37 = 359,                   /* $@37  */
  YYSYMBOL_360_38 = 360,                   /* $@38  */
  YYSYMBOL_361_39 = 361,                   /* $@39  */
  YYSYMBOL_362_40 = 362,                   /* $@40  */
  YYSYMBOL_363_41 = 363,                   /* $@41  */
  YYSYMBOL_364_42 = 364,                   /* $@42  */
  YYSYMBOL_365_43 = 365,                   /* $@43  */
  YYSYMBOL_366_44 = 366,                   /* $@44  */
  YYSYMBOL_367_45 = 367,                   /* $@45  */
  YYSYMBOL_368_46 = 368,                   /* $@46  */
  YYSYMBOL_prompt = 369,                   /* prompt  */
  YYSYMBOL_printintro = 370,               /* printintro  */
  YYSYMBOL_hashed_number = 371,            /* hashed_number  */
  YYSYMBOL_goto_list = 372,                /* goto_list  */
  YYSYMBOL_gosub_list = 373                /* gosub_list  */
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
#define YYFINAL  245
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   15216

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  254
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  639
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2012

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   499


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
       2,     2,     2,     2,     2,   253,     2,     2,     2,     2,
     251,   252,   246,   245,   250,   244,     2,   247,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   249,
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
     235,   236,   237,   238,   239,   240,   241,   242,   243,   248
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   235,   235,   236,   237,   238,   239,   242,   245,   246,
     246,   246,   249,   250,   251,   252,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   270,   271,   271,   272,   273,   274,   275,   276,
     277,   278,   278,   280,   280,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   292,   293,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   310,   311,
     312,   313,   314,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     413,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   490,   491,   492,   493,   494,   498,   499,
     500,   501,   502,   503,   506,   507,   510,   511,   512,   513,
     514,   517,   518,   521,   522,   525,   526,   527,   528,   529,
     530,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   565,   566,   570,   571,   572,   573,   574,   575,   576,
     577,   578,   579,   580,   581,   582,   583,   584,   585,   586,
     587,   588,   589,   590,   591,   592,   595,   596,   599,   599,
     600,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   635,   638,   641,   644,   645,   646,
     647,   648,   649,   650,   651,   652,   653,   654,   655,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   672,   673,   674,   675,   676,
     677,   678,   679,   680,   681,   682,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   714,   717,   718,
     721,   722,   723,   724,   725,   726,   727,   728,   729,   730,
     731,   732,   733,   736,   737,   738,   741,   742,   743,   744,
     747,   748,   751,   752,   753,   754,   757,   760,   763,   763,
     766,   767,   768,   771,   772,   775,   776,   779,   775,   784,
     785,   788,   789,   792,   793,   794,   795,   798,   799,   802,
     803,   804,   805,   808,   809,   812,   813,   814,   815,   818,
     819,   820,   823,   824,   825,   826,   829,   830,   835,   850,
     829,   855,   856,   857,   858,   859,   860,   863,   864,   867,
     868,   873,   873,   877,   878,   881,   882,   886,   888,   887,
     892,   893,   893,   897,   897,   903,   904,   905,   906,   907,
     908,   912,   913,   912,   919,   920,   924,   924,   929,   930,
     931,   932,   933,   934,   937,   938,   938,   940,   937,   944,
     945,   946,   947,   948,   949,   952,   952,   957,   958,   961,
     962,   965,   967,   969,   966,   973,   974,   977,   978,   978,
     981,   982,   984,   985,   989,   990,   993,   994,   996,   997,
    1001,  1002,  1003,  1004,  1007,  1008,  1009,  1010,  1011,  1014,
    1015,  1016,  1019,  1019,  1020,  1020,  1021,  1021,  1022,  1022,
    1023,  1023,  1024,  1024,  1025,  1025,  1026,  1026,  1027,  1027,
    1028,  1028,  1029,  1029,  1030,  1030,  1031,  1031,  1034,  1035,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,
    1048,  1049,  1050,  1051,  1054,  1055,  1057,  1058,  1061,  1062
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
  "tPASTE", "tTRANSLATE", "tBITMAP", "tSIN", "tASIN", "tCOS", "tACOS",
  "tTAN", "tATAN", "tEXP", "tLOG", "tSQRT", "tSQR", "tMYEOF", "tABS",
  "tSIG", "tINT", "tCEIL", "tFLOOR", "tFRAC", "tROUND", "tMOD", "tRAN",
  "tVAL", "tLEFT", "tRIGHT", "tMID", "tLEN", "tMIN", "tMAX", "tSTR",
  "tINKEY", "tCHR", "tASC", "tHEX", "tDEC", "tBIN", "tUPPER", "tLOWER",
  "tMOUSEX", "tMOUSEY", "tMOUSEB", "tMOUSEMOD", "tTRIM", "tLTRIM",
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

#define YYPACT_NINF (-1368)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-545)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     975, 12397, 10581, 11824,    27,    17,    36,   -64,   -53, -1368,
   -1368, -1368, -1368, -1368,   106,   106,   106,  7886, -1368, -1368,
   -1368, 11824, -1368, -1368, 11824,   111,   105, -1368, -1368, -1368,
   10581,   -35, -1368, 10581,    97, -1368, 10581, 10581, 10581,   196,
      34,   106,  3606,  2343,  4178,    41, 10581,  6906,  8131,   131,
      73, 10581, -1368,    84, 11824, 11824, 11824,    71, 10581,  2205,
   10581, 10581,  8376,  8621,  7151,  5926, 10581,  6416,  8866,  9111,
   10843, 11824, 11824,   -32,  6661,  9356, 10581,  9601, 10581, 10581,
    5681,  6171,  5191,  5436,  9846, 10091, 10969, 11095, 11221,    50,
    7396,   -34,   -18,    -4,     0,     8,  4178, 11824, 11824, 11824,
   -1368,   171, -1368, -1368,   112, -1368, -1368, -1368, -1368,   154,
     188, -1368,   241, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368,    35,    52, -1368, -1368, -1368, -1368,    56,    63,    91,
     170, 10581,   178,   190,   203,   205,   209,   235,   247,   258,
     276,   288,   299,   210,   305,   -65,   -50,   -31,   -21,   -15,
     -13,   221,   260,   130,   333,   314,   316,   340,   355,   361,
     384,   386,   406,   416,   418,   424,   430,   447,   456,   487,
     489,   495,   505,   518,   580,   586,   602,   608,   617,   631,
     633,   655,   664,   668,   680,   682,   691,   692,   704,   719,
     738,   742,   752,   761,   762,   763,   780,   793,   803,   804,
     811,   814,   820,   824,   828,   841,   843,   845,   858,   862,
     864,   865,   891,   898,   899,   916,   925,   934,   947,   976,
     977,   986,  1007,  1008,  1018,  1019, 10581, 10581,   613, -1368,
     650, -1368, -1368, -1368, -1368,   399,   541,   603,   624, 11824,
     -37,   414,   154,   188,   627, -1368, 10581, -1368, 11824, -1368,
     813, 10581, 12183, -1368, -1368, -1368, -1368, -1368,   408,   363,
     508,   532,   555, -1368, 10581, -1368,   555, -1368, -1368, 10581,
   12183,   837,  1020,   904,  1031,     9, 10581,   -12,   613,  1098,
    1032,  1034,   649,  1098,   613,  2643,   613, 12055,  1043,  1053,
     736, -1368, -1368,   585,   585, -1368, -1368,   751, -1368,  7641,
   11824, 10581,     1,  1098,   853,   247, -1368, -1368, -1368,   875,
   10581, 11824, 11824, 11824, 12836, -1368, 10581, -1368,    12, 11824,
     884, -1368, -1368, 10581, 10336, -1368, -1368,  1098, -1368, -1368,
     555,   -10,   -10, -1368,    12, 10581, 10581, 10581, 10581, 10581,
   10581, 10581, 11824, 11824, 10581, 10581, 10581, 10581, 10581,    12,
      12, 11824,   893, 11824,   945, 11824, 11824,    12, 11824, 11824,
   11824, 11824,    12,  1056, 11824, 11824, 11824,    12, 11824,    12,
   11824,  1062, 11824,  -180,  -120,  -119, 11824, 11824, 11824, 11824,
   11824,    12, 11824,    12,    12, 11824,    12,    12,    12, 11824,
   11824, 11824, 11824, 11824,    12, 11824, 11824, 11824, 11824,    12,
   11824, 11824, 11824, 11824, 11824, 11824, 11824,    12, 11824, 11824,
   11824, 11330, 11824, 11824,    12, 11824,  1064, 11824,  1079, 11824,
     -62, 11824,    -7, 11824,    -6, 11824, 11824, 11824, 12851,  1136,
    1136,  1136,  4441, 11824,   121,  1089,   555,   135,   146, -1368,
    1123, 10581, 10581, 10581, 10581, 11824, -1368, -1368, -1368, 10581,
   10581,   658, 10581, 10581, 10581, 10581,  3927,  4178, 11824, -1368,
     574,   574, 10581, 10581, 11824, 11824, 11824, 11824, 11824, 11824,
   11824, 11824, 11824, 11824, 11824, 11824, 11824, 11824, 11824, 11824,
   11456, 11824, 11824, 11824,  1096, -1368, 11824, 10581, 10581, 10581,
   10581, 10581, 10581, 10581, 10581, 10581, 10581,  4178, 10581, 10581,
   10581, 10581, 10581, 10581, 10581, 10581,  4691, 11824, 11824, 11824,
   11824, 11824, 10581, 10581, 10581,  4941, 10581, 11824, 10581, 11824,
   10581, 11824, 11824,   637,  1868,  2910, 10713, 11824, 11824, 11824,
   10581, 11824, 11824, 11824, 11824, 11824, 11824,  4178, 11824, -1368,
   -1368, 11824, 10581, 11824, 11824, 11824, 11824, 11824,  1097,  1104,
   11824,  1136, 11824,  1136, 11824, 11824, 11824,  1226,   375,  1203,
   11824, 11824, 11824, 11824, 11824, 11824, 11824, 11824, -1368, -1368,
   -1368, 10581, 10581, 10581, 10581, 10581, 10581, 10581, 10581, 10581,
   10581, 10581, 10581,  -117, -1368, -1368, -1368,  1098,  1106,   555,
    1112,  1293,  1098,   193, -1368, -1368, -1368, -1368,  1126,  1127,
    1137, -1368,  1135,  1167,  1138, -1368,   613,  1098,  1159, -1368,
     613,  1098,  1395,   297,  1365, 12183, 10581,  1209, 11824, -1368,
   -1368, 10581,   613,   901,   404,  1212,  1362,  1222,    13, -1368,
    1444, -1368, -1368,   732, 10581, 10581, -1368, -1368,   196, -1368,
   -1368,    51, 12866,   555,  1098,   703, 11568, 10581,    12,   555,
     555,   420, 10581, -1368,   -12, -1368, -1368, 10581,   445, 11824,
   -1368, 10581,    12, 10581, 10581, 10581,  1224,    12,  1239,    12,
    1245,    12,    12,   525,   555,  1247,  1253,    12,    12, 12881,
   10581, 10581,   566, 11824,   570, 11824,   555,   604, 10581,   606,
     555,   620,   635, 10581, 11824,   636,   642,   648, 10581,   671,
   10581,   684, 11824,   708, 10581, 11824, 11824,   709,   711,   735,
     766,   777, 10581,   784, 10581, 10581,   785, 10581, 10581, 10581,
     555,   788,   795,   555,   796, 10581,   555,   798,   806,   816,
   10581,   555,   819,   823,   555,   827,   848,   850, 10581,   861,
     555,   872, 11824,   879,   881,   882, 10581,   883, 11824,   890,
   11824,   914, 11824,   915, 11824,   941, 11824,   555,   942,   555,
   10581,  1267,  1289,  1292,  1298, -1368,  1406,   -46, 10581, 10581,
   10581, 10581, -1368,  1300,    12,    12,  1098,   555,   787,  1210,
    1220, 12901, 12921,  1773, 12936, 12955, 13066,  1305,    99,  1317,
    1344,   943,  1319,  1360,  1373,  1393,  1343,  1371,    12, 13086,
     944,   -26,   555,   555,   555,   555,   555,   555,   951,   555,
     555,   954,   555,   555,   957,   555, 11824,   555,   979,   555,
     980, 11824,   -20,  1906,  1971,  2041,  2058,  2169,  1146,  2184,
    1169,  2537,  2594,  1433,  2613,  2755,  2904,  3007,  3158,  3281,
    3297, 13121, -1368,  3319,    78,   981,  1002,  1003,    79, 13140,
   13155,   427,  1299, -1368,  3396,  3666,   102,  3791,  -141,  3811,
     159,   180, -1368,   243, -1368,   303, -1368,   330, -1368,   332,
     359,   376,   377, 13170,  1004,  1005,  1011,   378,   379,   380,
     498,  1434,  -109,  1436,  1438,   388,  4238,   393,   -22,  1012,
    1036,  1039, -1368, -1368,  1048,  -172,  1051,   -70,  1052,   394,
     403, -1368, -1368,   555,   555,   555,   555,   555,   555,   555,
   -1368, 10581, 10581,  1308,    82,   933,   892,   750,   405,   -68,
   -1368,   -44,   -44,  1226,  1226, -1368, -1368, -1368, 12183, -1368,
   -1368, 10581, -1368, -1368, -1368, -1368,   106,   106, -1368, -1368,
     508, -1368, -1368,   532, 10581, -1368,  1567, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368,   812, 13185, 10581,     3,  4463,
   11950, -1368, -1368, 10581, 10581,  1384, 11824, -1368, -1368, 10581,
   -1368,   886,  1439,  1440,  1397,  1442, 13200, 13215,  1443,  1448,
   -1368, -1368, -1368, 10581,  1594,  1616, -1368,  1065, 13230, 10581,
   11824,  1098, -1368, -1368, 11824,  1068, -1368, 10581, 13251, 13271,
    1452, 11824, 10581, 10581, 10581, 11824, 10581, 10581, 10581, 10581,
   10581, 10581, 10581, 10581,  1453,  1454, 10581,  1071, 10581,  1086,
   10581,  1455, 11824, 11824, 11824,  1456,  1087, 11824, 11824, 10581,
    1457, 11824,  1458, 10581,  1088, 11824, 13286,   555,   555, 11824,
   11824, 10581, 11824, 10581,  1461, 11824,  1462,  1463, 10581,  1465,
    1466,  1468, 10581, 10581, 10581,  1469, 11824, 10581, 10581,  1470,
   11824, 10581, 11824, 11824, 10581,  1473, 11824, 10581,  1090, 10581,
   11824, 10581,  1474, 11824,  1101, 10581,  1115, 10581,  1144, 11824,
    1150, 11824,  1152, 11824, 13306, -1368, 10581, 10581, 10581, -1368,
   -1368,   613,  1098,   613,  1098, 13415, 13436, 12183, 10581, 10581,
   10581, -1368, -1368, -1368, -1368, -1368, 10581, 10581, -1368, 10581,
   10581, 10581, -1368, 11824, -1368, 11715, -1368, 11824,  1475,  1479,
   -1368, -1368, 10581, 10581, 10581, 10581, 11824, -1368, 10581, 10581,
   10581,   555, 10581, 11824,   421, -1368, -1368, -1368, -1368, -1368,
   -1368, 10581, -1368, -1368, 10581, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, 10581, -1368, -1368, 10581,
   10581, 10581, -1368, 10581, 10581, -1368, 11824, -1368, -1368, -1368,
   -1368, -1368, 10581, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, 11824, 11824, 11824, 11824, -1368, -1368,
   -1368, -1368, -1368, 11824, -1368, -1368, -1368, -1368, -1368, -1368,
   10581, -1368, 10581, 10581, 10581,  1721, 11824, -1368,  1721, 11824,
   -1368, 11824, -1368, -1368,   658,  1081, 10581,    22,  1098, -1368,
    1482, -1368,  1483,  1485,  1486, -1368,  1487,  1488, -1368, -1368,
   -1368,   878, 12183, -1368, -1368, -1368, 10581, 13471, 11824,  1683,
   -1368, 11824,   555,   613,   901, 13491, 10581,    31,   886,   886,
    4501,  1491,  1493, -1368,  1495, -1368, -1368, -1368, -1368, 10581,
   10581, -1368, -1368, 13506,  4178,  4178, 11824, 11824,  1496,  1154,
     555, 11824, -1368, 10581, 10581, 11824,   555,  1497, 13521,    12,
    1156,  1498,    12,   613, 13536, 13551, 13566,    12,  1499, 13581,
   11824, 11824,  1098, 11824,  1098, 11824,   613,  1098, 11824,  1158,
     555,   555, 11824, 11824,  1160,  1162,   527,  1098, 11824,  1172,
   11824,  1098, 11824,  1182, 11824,  1183,  1185,  1098,   555,  1098,
   11824,  1186, 11824, 11824,  1098, 11824, 11824, 11824,   613, 13600,
     613,  1098,  1098, 11824,   555,  1098,  1098, 11824,  1189,   588,
    1098,   555,   555,  1098, 11824,  1192, 13621, 10581,  1098,  1195,
    1098, 11824,   555, 11824, 13636, 11824,   734, 13656, 11824,  1201,
   11824,  1207, 11824,  1211, 11824,  1501,  4713,  4751,  1437, 11824,
   11824, -1368,  1098,    12, -1368,  1500,  4963,  5001,  6438,  6683,
    6928,   463,  1504,    32,   555, -1368, -1368,  7418,  7663,  1506,
      44,  1221,  1098,  1098,  1098, 13766,   555, -1368,  7908,  8153,
    8398,  8643,  8888,  1702,  9133,  9378,    48,  9623,   465,  1240,
     207,   239,   466,  9868, 13785, 13821, 10113,    93,   467,   118,
     496,   507,    74, -1368, -1368, -1368,   106,   106, -1368, -1368,
   -1368, -1368, 10581,  1707,  1722,  1716, 10358, 10581,   510,  1510,
     240, -1368, 10581, 13841, 11824,  1704, -1368, -1368, -1368, -1368,
   -1368, -1368,  1511,  1512,  1098,  1098, 11824, -1368, -1368,   555,
     555, 11824, 11824,  1241, 13856,  1098,  1242, 11824, 11824, 10581,
   11824, 11824, 10581, 10581, 10581, 10581, 10581, 10581, 11824,   555,
    1248,  1254,  1270,  1277, 10581,  1279,  1280, 11824, 10581, 10581,
    1281, 11824,  1283,  1287, 10581,   555, 10581, 10581,  1290, 11824,
    1311,  1314,  1315,  1318,  1321, 11824,  1328,  1329, 10581, 11824,
    1331, 10581, 10581,  1098, 10581,  1332,  1335, 10581,   555, 11824,
   11824,  1338, 10581,  1339, 11824,  1341, 11824,   555, -1368,  1693,
    1694, 10581,  1695,  1342,   555, 10581,   935, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, 11824, -1368, -1368, -1368, -1368, 10581,
   11824, 10581, -1368, -1368, -1368, -1368, -1368, 10581, -1368, -1368,
   -1368, 11824, -1368, -1368, -1368, 11824, 10581, -1368, 10581, -1368,
   -1368, -1368, 11824, 10581, -1368, 11824, -1368, -1368, 11824, -1368,
   -1368, -1368, 10581, -1368, -1368, -1368, -1368, -1368,  1719,   922,
   11322,  1713, 10581, 11824, 11559, 10581,   515,  1529,  1444,   886,
    1531,  1532,   886, -1368, -1368,   555,  1349,   555, 11824, 11824,
   11824,   555,   555,  1535,   555,   555,    12, 13871, 13886, 13901,
      12, 13916,  1350, 11824, 10581, 10581, 11824, 13931, 10581, 11824,
     555, 13951,  1098, 11824,  1352, 11824, 10581, 13970, 13985,   613,
    1098, 11824,   555, 11824, 10581, 10581, 11824, 11824,   555, 10581,
   11824,   802,  1098,   555, 10581, 14006, 14116, 14136, 10581, 11824,
   14170,  1358,   555, 11824,   852, 14191, 11824,  1359, 11824,   555,
   11824, 11824, 11815, 11824, 10581, -1368,  1530,  1536,   167, -1368,
     516, 14206,   555,  1098, 12008,   526,   528, 12317, 12531,   543,
   12606,   549,   567,    90, 12183, 12611, 10581,  1743, -1368,  1541,
   -1368,  1542, 14221,   569,   939, 12716,  1736, 10581,   886, -1368,
   -1368, -1368, -1368, 11824,   555,   555,   555, 11824, 10581, 10581,
   11824, 10581, 10581, 10581, 11824,  1367, 14236, 14251,  1368, 10581,
   14266,  1369, 10581,  1377, 10581,  1379, 14281, 10581, 10581,  1383,
    1386, 14301, 14321,   555,   555, 14336,  1389, 10581, 14355, 10581,
   10581, 10581, 14466,  1392, 10581, 11824,   555, 11824, 11824,  1396,
   10581,  1404,   555,   555,  1720,   555,  1098,  1544,  1545,   935,
   -1368, -1368, 10581, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, 10581, -1368,  1716,  1760,   874, 12183, -1368, 11824,
   10581, 10581, -1368, -1368,  1548,  1444, -1368,  1549,  1444, 14486,
   -1368,   555,   555,  1551, 14521,   555, 14540,  1552, 14555,  1412,
   11824, 11824, 11824, 11824, 14570, 11824, 11824, 14585, 10581,  1098,
   11824, 10581,  1098, 14600, 11824, 10581, 10581, 11824, 11824, 11824,
    1098, 11824, 14615, 14630, 14651, 11824, 11824,  1098,   555,  1414,
     555, 11824,  1015, 14671, 11824, 11824, -1368, -1368, -1368, 12183,
   12736,  1098, 12183, -1368, -1368,  1716,   660,   265, 14686, 12770,
    1444, 11824,   886,  1444, 10581,   886, 10581, 11824, 11824, 10581,
   11824, 11824, 11824,   555,   555,   555,  1416, 10581,   555,   555,
   10581, 14706,  1424, 14815, 10581,   555, 14836, 14871,   555,   555,
     555,   555, 10581, 11824, 10581,  1426,   555, 11824,   555, 11824,
   11824,  1427,   555,    62, -1368,  1716, 12183, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, 11824, -1368, 10581, -1368,   886,   331,
   -1368,   886, 14891, -1368, 12791,   555,   555, 14906,   555,   555,
     555, 11824,  1098,  1098, 10581, 11824, 10581,  1098, 11824, 11824,
    1098,   555, 14921, 11824,   555,  1428,   555, 11824, -1368, -1368,
   -1368,   974,  1716,   594, 12806, -1368, 11824, -1368, -1368, 10581,
   -1368, 11824,   555, 14936,   555, 14951,   555,   555, 10581,   555,
   11824,   555, -1368, -1368, -1368, -1368, -1368, -1368,  1799,  1719,
   -1368, -1368,   595,  1444, 12821,  1444,   555, 11824, 11824, 14966,
     555, -1368, -1368, -1368, -1368,   886, -1368,   886,  1430,   555,
   11824,  1444, -1368,  1444, -1368, 11824,   555,   886,   886,   555,
   -1368, -1368
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   233,     0,     0,     0,   473,     0,     0,     0,   227,
     496,   531,   536,    18,     0,     0,     0,     0,    31,    33,
     474,     0,   458,   458,     0,   475,    25,    27,   511,   523,
       0,   620,    55,    67,     0,   224,   225,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   234,
     235,     0,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   216,     0,     0,     0,     0,     0,
       2,     9,    17,     8,     0,    12,    46,    48,    14,    29,
      30,    28,     0,    20,    21,    24,    23,    22,    35,    36,
     446,   338,   255,   447,   448,   449,   258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   269,     0,     0,     0,     0,     0,
       0,     0,   398,   401,   404,   407,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   286,   288,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   256,
       0,   352,   332,   337,   257,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,   458,     0,   458,
       0,     0,    16,   451,   450,    37,    38,    45,     0,     0,
       0,     0,    19,    50,   460,    51,    49,   476,    26,     0,
      16,   555,     0,   624,     0,     0,   584,   616,    69,    68,
       0,     0,    70,   226,    60,     0,    62,     0,   576,   578,
      63,   574,   580,     0,     0,   581,   443,    64,    66,     0,
     211,     0,     0,   635,     0,    92,   213,    86,    47,     0,
       0,     0,     0,     0,     0,    74,     0,    57,    79,     0,
       0,    94,    93,     0,     0,   236,   237,   214,    13,    15,
     228,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   229,     0,     0,     7,
       0,     0,     0,     0,     0,     0,   465,   458,   458,     0,
       0,   322,     0,     0,     0,     0,     0,     0,     0,   428,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   302,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   458,
     458,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   344,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,   320,
     318,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     6,   316,     0,   238,
       0,     0,   532,     9,    39,    40,    41,    43,   479,   480,
      32,   477,   485,   486,    34,   483,   463,   464,   459,   461,
     516,   515,     0,     9,     0,    16,     0,     0,     0,   621,
     622,     0,   587,   589,    52,     0,     0,     0,     0,    56,
     618,   458,   458,     0,     0,     0,   458,   458,     0,   445,
     444,     0,     0,   212,   634,     0,     0,     0,     0,    96,
      73,     0,     0,    78,   616,   245,   244,     0,     0,     0,
      75,     0,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,     0,     0,     0,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     166,     0,     0,   167,     0,     0,   172,     0,     0,     0,
       0,   181,     0,     0,   184,     0,     0,     0,     0,     0,
     191,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   206,     0,   209,
       0,   253,     0,     0,     0,   217,     0,     0,     0,     0,
       0,     0,    10,     0,     0,     0,   317,   243,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   291,   293,   292,   294,   431,   430,     0,   433,
     432,     0,   435,   434,     0,   438,     0,   436,     0,   299,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   378,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,     0,     0,     0,     0,     0,     0,
       0,     0,   399,     0,   402,     0,   405,     0,   408,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   287,   289,     0,     0,     0,     0,     0,     0,
       0,   260,   353,   347,   349,   351,   348,   350,   345,   346,
     259,     0,     0,   325,   327,   329,   326,   328,   323,   324,
     343,   340,   339,   341,   342,   456,   457,   497,    16,   543,
     541,     0,   542,   538,   540,   537,     0,     0,   458,   458,
       0,   458,   458,     0,     0,   513,   517,   530,   528,   529,
     526,   525,   527,   524,   545,     9,     0,     0,     0,     0,
       0,   585,    53,    54,     0,     0,     0,   592,   594,     0,
     619,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     575,   582,   583,     0,     0,     0,   248,   247,   251,     0,
       0,   356,    58,    76,     0,    89,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   458,     0,     0,     0,   218,
     219,   220,   221,   222,   223,     0,     0,    16,     0,     0,
       0,   471,   472,   466,   420,   312,     0,     0,   411,     0,
       0,     0,   421,     0,   422,     0,   415,     0,     0,     0,
     333,   334,     0,     0,     0,     0,     0,   442,     0,     0,
       0,   437,     0,     0,     0,   300,   357,   358,   359,   360,
     361,     0,   362,   364,     0,   365,   367,   368,   330,   374,
     375,   369,   371,   372,   373,   370,     0,   377,   382,     0,
       0,     0,   381,     0,     0,   268,     0,   265,   271,   272,
     383,   310,     0,   384,   311,   273,   274,   397,   400,   403,
     406,   277,   275,   276,     0,     0,     0,     0,   280,   390,
     281,   396,   395,     0,   290,   391,   282,   392,   283,   394,
       0,   284,     0,     0,     0,     0,     0,   305,     0,     0,
     307,     0,   427,   315,   321,   319,     0,     9,   539,   636,
      42,   638,    44,     0,     0,   478,     0,     0,   484,   462,
     514,   520,    16,   557,   558,   556,     0,     0,     0,   625,
     623,     0,   590,   588,   589,     0,     0,     0,     0,     0,
       0,   570,   572,   617,   567,   452,   454,   458,   458,     0,
       0,   577,   579,    71,     0,     0,     0,     0,     0,     0,
     121,     0,    77,     0,     0,     0,   102,     0,     0,     0,
       0,     0,     0,    99,     0,     0,     0,     0,     0,     0,
       0,     0,   117,     0,   119,     0,   124,   125,     0,     0,
     129,   128,     0,     0,     0,     0,     0,   137,     0,     0,
       0,   144,     0,     0,     0,     0,     0,   151,   150,   152,
       0,     0,     0,     0,   157,     0,     0,     0,   161,     0,
     163,   164,   165,     0,   169,   171,   170,     0,   174,   177,
     178,   182,   183,   180,     0,     0,     0,     0,   188,     0,
     190,     0,   194,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    87,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   429,   354,   355,     0,     0,     0,
       0,   440,   295,   296,   297,     0,   439,   301,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   535,   534,   533,     0,     0,   481,   482,
     487,   488,     0,     0,     0,   546,     0,     0,     0,     0,
       0,   586,     0,     0,     0,   606,   593,   595,   596,   458,
     458,   568,     0,     0,    59,    61,     0,   249,   250,   246,
     252,     0,     0,    90,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   189,     0,     0,     0,     0,   195,     0,
       0,     0,     0,     0,     0,     0,     0,   207,   254,     0,
       0,     0,     0,   231,   232,     0,   489,   409,   410,   412,
     413,   414,   423,   424,     0,   425,   335,   336,   308,     0,
       0,     0,   363,   366,   376,   261,   262,     0,   264,   379,
     380,     0,   266,   385,   278,     0,     0,   386,     0,   388,
     303,   285,     0,     0,   314,     0,   417,   304,     0,   419,
     306,   331,     0,   637,   639,   518,   521,   512,   561,   627,
       0,   626,     0,     0,     0,     0,     0,     0,   618,     0,
       0,     0,     0,   453,   455,    72,     0,    97,     0,     0,
       0,   103,   106,     0,   101,   104,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     134,     0,   135,     0,     0,     0,     0,   139,     0,   145,
     146,     0,   154,     0,     0,     0,     0,     0,   162,     0,
       0,     0,   176,   179,     0,     0,     0,     0,     0,     0,
       0,     0,   198,     0,     0,     0,     0,     0,     0,   208,
       0,     0,     0,     0,     0,    88,   492,   493,     0,   490,
       0,     0,   441,   298,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   507,    16,   233,     0,   559,   631,     0,
     628,     0,     0,     0,   598,     0,   608,     0,     0,   597,
     571,   573,   569,     0,   120,    82,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   158,   159,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   197,     0,     0,     0,
       0,     0,   241,   242,     0,   240,   230,     0,     0,     0,
     467,   426,     0,   263,   267,   279,   387,   389,   393,   313,
     416,   418,     0,   498,   519,     9,   565,    16,   547,     0,
       0,     0,   591,   610,     0,   618,   600,     0,   618,     0,
     607,    95,   110,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
       0,     0,   140,     0,     0,     0,     0,     0,     0,     0,
     175,     0,     0,     0,     0,     0,     0,   196,   199,     0,
     201,     0,     0,     0,     0,     0,   494,   495,   491,    16,
       0,   508,    16,   566,   562,   560,     0,     0,     0,     0,
     618,     0,     0,   618,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   116,   118,     0,     0,   127,   122,
       0,     0,     0,     0,     0,   149,     0,     0,   156,   160,
     168,   173,     0,     0,     0,     0,   193,     0,   200,     0,
       0,     0,   239,     9,   309,   499,    16,   554,   551,   552,
     553,   549,   550,   548,     0,   632,     0,   629,     0,     0,
     599,     0,     0,   609,     0,   109,   100,     0,   111,   105,
     210,     0,   131,   136,     0,     0,     0,   147,     0,     0,
     192,   187,     0,     0,   202,     0,   205,     0,   470,   469,
     468,     0,   563,     0,     0,   611,     0,   612,   601,     0,
     602,     0,   123,     0,   141,     0,   153,   155,     0,   185,
       0,   203,   502,   504,   505,   506,   501,   503,   509,   561,
     633,   630,     0,   618,     0,   618,   108,     0,     0,     0,
     204,   510,   500,   564,   614,     0,   604,     0,   132,   143,
       0,   618,   613,   618,   603,     0,   186,     0,     0,   133,
     615,   605
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1368, -1368, -1368,  -251, -1368, -1368,  1800,   714, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368,  1752,   -82, -1368, -1368,  -367,
      -3, -1368,  1753,  1692, -1368, -1368,  1353,  -451,  2966, -1368,
    1174,   -36,    -1, -1368,     2,     4,   166, -1368, -1368,   876,
    1811, -1368, -1368, -1368, -1368, -1368, -1368, -1368,   887, -1368,
     888, -1368,    49, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368,   387, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,  -157,
   -1368, -1368, -1368, -1221, -1368, -1368, -1368,  1191, -1368, -1368,
     590,  1176, -1368, -1368, -1368, -1368, -1368, -1368, -1368, -1368,
   -1368, -1368, -1368, -1368, -1368, -1367, -1368,    89, -1368, -1368
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,   100,   101,   440,  1097,   102,   103,   260,   261,
     936,   937,   277,   654,   104,   105,   657,   106,   107,   762,
     228,   229,   108,   314,   912,   911,   794,   795,   315,   231,
     295,   232,   255,   282,   233,   234,   263,   264,   608,   609,
     111,   778,  1375,  1849,  1950,  1103,   112,   600,   601,   604,
     605,  1678,  1679,   113,   250,  1216,  1852,  1951,  1978,  1783,
    1992,   114,   269,   946,   612,  1231,  1694,  1434,  1695,   115,
     270,   953,   116,   251,   928,  1425,   117,   252,   935,   118,
     614,  1232,  1588,  1856,  1913,   119,   615,  1235,  1788,  1697,
    1906,  1979,  1854,  1253,  1602,  1254,   290,   291,   297,   624,
     961,   629,  1248,  1249,  1599,  1795,  1863,  1985,  2003,  1598,
    1798,  1860,  1983,  2001,   630,   971,   276,   304,  1220,  1222
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     240,   593,   655,   109,   296,   110,   242,   584,   243,   578,
     797,   246,   645,   619,   256,   257,   620,   967,   262,   613,
     968,   266,   248,   272,   655,   273,   274,  1446,  1447,   376,
     278,     7,     8,   578,   284,   286,   245,   120,  1423,   302,
     298,   123,   124,   125,   292,    20,   625,   466,   626,   627,
      25,   330,   331,   332,   120,   242,   655,   243,   123,   124,
     125,   981,   468,   763,   764,   567,  1424,   373,   374,   375,
     704,   560,   561,   562,   563,   564,   565,   566,  1206,   377,
    1207,   470,   471,   420,   422,   424,  1582,  1948,     7,     8,
     467,   473,   474,   434,   436,   437,   438,   476,   477,   479,
     480,   280,   281,  1782,   567,   469,  1949,   569,   570,  1172,
     253,  1173,   268,   254,   571,   572,   573,   574,   575,   576,
     577,   578,   310,   311,   472,   567,   567,    53,   567,   312,
     705,   706,   308,   309,   475,   901,   567,   569,   570,   267,
     478,  1193,   481,  1194,   571,   572,   573,   574,   575,   576,
     577,   578,   313,   569,   570,   574,   575,   576,   577,   578,
     571,   572,   573,   574,   575,   576,   577,   578,   326,   560,
     561,   562,   563,   564,   565,   566,   579,   580,   581,   582,
    1209,   333,  1210,   567,   895,   435,   897,   247,   752,   265,
     321,   560,   561,   562,   563,   564,   565,   566,   249,   567,
     288,   289,   581,   582,   441,   442,  1090,   929,   567,   930,
     425,   931,    91,    92,    93,   439,   443,   429,   275,   567,
     322,   323,   324,   567,   558,   567,  1127,   325,  1200,   444,
    1201,  1708,  1135,   430,   932,   567,   583,   933,   567,   567,
     656,   628,   934,   754,   756,   589,   567,   431,   567,   663,
     664,   432,   665,  1238,   109,  1239,   110,   639,   640,   433,
     621,   606,   656,   445,   969,   446,   610,   680,   681,    91,
      92,    93,   109,   622,   110,   688,   567,   567,   293,   294,
     693,  1444,  1544,  1445,  1545,   698,   247,   700,   579,   580,
     581,   582,   484,   567,   656,   293,   294,   643,  1561,   712,
    1562,   714,   715,   249,   717,   718,   719,   447,   649,   650,
     651,   947,   725,   948,   448,   949,   658,   730,   579,   580,
     581,   582,   464,   567,   567,   738,   579,   580,   581,   582,
    1158,  1162,   746,   482,   579,   580,   581,   582,   950,   673,
     674,   951,   449,  1575,   567,  1576,   952,   567,   682,  1113,
     684,  1114,   686,   687,  1170,   689,   690,   691,   692,   458,
     459,   695,   696,   697,   955,   699,   567,   701,  1578,   703,
    1579,   768,   483,   707,   708,   709,   710,   711,  1709,   713,
     567,  1712,   716,   596,   597,   770,   720,   721,   722,   723,
     724,   567,   726,   727,   728,   729,   771,   731,   732,   733,
     734,   735,   736,   737,   567,   739,   740,   741,   743,   744,
     745,  1175,   747,   588,   749,   590,   751,  1769,   753,  1770,
     755,   450,   757,   758,   759,   567,   569,   570,  1862,   452,
     767,  1865,  1176,   571,   572,   573,   574,   575,   576,   577,
     578,   453,   777,   594,   595,   560,   561,   562,   563,   564,
     565,   566,   567,   788,   454,   791,   455,  1566,   585,  1567,
     456,   800,   801,   802,   803,   804,   805,   806,   807,   808,
     809,   810,   811,   812,   813,   814,   815,   817,   818,   819,
     820,   577,   578,   822,   567,   567,   457,  1800,   567,  1568,
    1593,  1569,   901,  1918,   485,  1177,  1921,   560,   561,   562,
     563,   564,   565,   566,   844,   845,   846,   847,   848,   460,
     567,   851,   598,   599,   856,  1914,   858,  1915,   860,   861,
     863,   865,   867,   869,   870,   871,   872,   461,   874,   875,
     876,   877,   878,   879,   880,   882,   602,   603,   885,   462,
     887,   888,   889,   890,   891,   789,   790,   894,   567,   896,
     463,   898,   899,   900,   472,  1178,   465,   903,   904,   905,
     906,   907,   908,   909,   910,   486,   989,   487,   560,   561,
     562,   563,   564,   565,   566,   567,   567,   567,   792,   793,
     997,  1956,  1179,  1957,  1180,  1002,   833,  1004,   120,  1006,
    1007,   488,   123,   124,   125,  1011,  1012,   560,   561,   562,
     563,   564,   565,   566,   567,   296,   489,   579,   580,   581,
     582,  1181,   490,   779,   780,   958,  1995,   109,  1997,   110,
     567,   567,   567,   567,   567,   567,   881,   901,  1182,  1183,
    1188,  1189,  1190,   567,  2007,   491,  2008,   492,   567,   567,
    1197,  1920,   122,   987,  1923,  1199,  1212,   126,   567,   579,
     580,   581,   582,   962,   963,  1213,   995,   493,   560,   561,
     562,   563,   564,   565,   566,   567,   567,   494,   128,   495,
     990,   586,   567,  1397,  1907,   496,  1908,  1217,  1909,  1165,
    1017,   497,  1019,   560,   561,   562,   563,   564,   565,   566,
     567,  1026,  1099,  1100,   568,   994,   475,  1955,   498,  1034,
    1958,  1910,  1037,  1038,  1911,   883,   884,   499,   567,  1912,
     567,   567,   567,   569,   570,  1542,  1124,  1564,  1570,  1577,
     571,   572,   573,   574,   575,   576,   577,   578,   571,   572,
     573,   574,   575,   576,   577,   578,   974,   975,   500,  1068,
     501,   567,   141,   567,   142,  1074,   502,  1076,  1580,  1078,
    1191,  1080,   567,  1082,  1417,   567,   503,  1419,   478,  1581,
     567,   567,  1591,   145,   146,  1091,  1093,  1706,  1771,   504,
     567,   567,   567,   567,  2002,  1008,  2004,  1489,  1774,   481,
    1775,   235,   236,   237,   238,   151,  2010,  2011,   567,   984,
     985,  1101,  1102,   153,   567,  1778,   154,   972,   973,   155,
     567,  1780,   978,   979,   560,   561,   562,   563,   564,   565,
     566,   567,   567,  1131,   567,   567,  1016,   591,  1134,  1781,
    1018,  1792,   177,   178,   179,   576,   577,   578,   183,   184,
     185,   505,   187,   567,   189,   190,   191,   506,  1509,   567,
     567,   196,   197,   198,   199,   200,  1980,  1994,   203,   567,
     205,   567,   207,   507,  1020,   209,  1022,   211,   567,   508,
     213,  1233,  1234,   215,   216,   567,   217,   218,   509,   220,
    1023,   222,   560,   561,   562,   563,   564,   565,   566,   225,
     567,   567,   510,  -544,   511,  1024,  1027,   567,   239,   862,
    1251,  1252,  1028,   567,   579,   580,   581,   582,  1029,   633,
     569,   570,   579,   580,   581,   582,   512,   571,   572,   573,
     574,   575,   576,   577,   578,   513,   567,  1432,  1433,   514,
    1853,  1031,   560,   561,   562,   563,   564,   565,   566,   567,
     109,   515,   110,   516,  1033,  1219,  1221,   569,   570,  1676,
    1677,   606,   517,   518,   571,   572,   573,   574,   575,   576,
     577,   578,   960,   567,   567,   519,   567,  1242,  1035,  1039,
    1243,  1040,   617,  1247,   569,   570,   575,   576,   577,   578,
     520,   571,   572,   573,   574,   575,   576,   577,   578,   567,
     567,  1435,  1698,  1699,  1519,  1041,   638,  1269,  1972,   521,
    1973,  1270,  1974,   522,   579,   580,   581,   582,  1276,  1793,
    1794,   641,  1280,   523,   572,  1283,   574,   575,   576,   577,
     578,   567,   524,   525,   526,  1975,  1042,  1296,  1976,  1299,
    1300,  1301,   567,  1977,  1304,  1305,  1306,  1043,  1309,   567,
     567,   527,  1313,   567,  1045,  1048,  1315,  1316,  1052,  1318,
     567,   567,  1321,   567,   528,  1053,  1054,   567,  1056,  1328,
    1330,   567,  1747,  1334,   529,   530,  1057,  1338,  1339,  1341,
    1342,   567,   531,  1345,   567,   532,  1058,  1349,   567,  1060,
    1352,   533,   567,  1061,  1356,   534,  1359,  1062,  1361,   535,
    1363,   579,   580,   581,   582,   560,   561,   562,   563,   564,
     565,   566,   536,   567,   537,   567,   538,   567,  1063,   109,
    1064,   110,  1757,   646,  1223,  1224,   567,  1226,  1227,   539,
    1381,  1066,  1383,   540,  1384,   541,   542,   567,   579,   580,
     581,   582,  1067,  1391,   567,   647,   567,   567,   567,  1069,
    1396,  1070,  1071,  1073,   659,   567,   579,   580,   581,   582,
    1075,   761,   543,   683,   569,   579,   580,   581,   582,   544,
     545,   571,   572,   573,   574,   575,   576,   577,   578,   567,
     567,   569,   570,  1406,  1077,  1079,   772,   546,   571,   572,
     573,   574,   575,   576,   577,   578,   547,   579,   580,   581,
     582,  1408,  1409,  1410,  1411,   548,   567,   567,   567,   567,
    1412,  1081,  1083,  1117,  1126,   685,   567,  1469,   549,   567,
    1472,  1128,   567,  1418,  1129,  1476,  1420,  1130,  1421,   569,
     570,     1,     2,     3,     4,     5,   571,   572,   573,   574,
     575,   576,   577,   578,   567,   567,   567,   550,   551,  1132,
    1133,  1159,   569,   570,   109,  1438,   110,   552,  1440,   571,
     572,   573,   574,   575,   576,   577,   578,   567,   567,   567,
     567,  1365,  1160,  1161,  1185,  1186,   567,   567,   553,   554,
     567,  1187,  1202,  1459,  1460,  1899,   569,   570,  1463,   555,
     556,   616,  1466,   571,   572,   573,   574,   575,   576,   577,
     578,   567,   618,   631,   567,   632,  1203,  1479,  1480,  1204,
    1481,  1535,  1482,   567,   636,  1483,   567,   567,  1205,  1485,
    1486,  1208,  1211,   578,   637,  1490,   694,  1492,  1549,  1493,
     567,  1495,   702,   567,   748,  1266,   567,  1498,  1271,  1500,
    1501,  1293,  1502,  1503,  1504,   579,   580,   581,   582,   750,
    1506,   567,   567,   567,  1507,   567,  1295,  1303,  1312,   769,
    1347,  1510,   579,   580,   581,   582,   567,   821,  1515,   892,
    1516,  1353,  1518,  1457,  1458,  1521,   893,  1523,   925,  1525,
     567,  1527,   569,   570,   926,  1355,  1533,  1534,   927,   571,
     572,   573,   574,   575,   576,   577,   578,   938,   939,   572,
     573,   574,   575,   576,   577,   578,   941,   940,   943,   567,
     579,   580,   581,   582,  1358,   567,  1141,   567,  1142,   567,
    1360,   567,  1362,   567,  1462,   567,  1470,   567,  1484,   944,
    1487,   954,  1488,   579,   580,   581,   582,   567,   942,  1144,
     965,  1145,  1491,  1452,  1453,  1583,  1584,   567,   567,   610,
     567,   567,  1494,  1496,   567,  1497,  1499,   567,   945,  1508,
     567,  1596,  1511,  1784,  1785,  1514,   567,   579,   580,   581,
     582,  1522,   567,  1605,   970,   902,   567,  1524,  1606,  1607,
     957,  1526,  1104,   964,  1611,  1612,   567,  1614,  1615,   569,
     570,  1550,  1105,   966,  1001,  1622,   571,   572,   573,   574,
     575,   576,   577,   578,  1630,   567,   567,   567,  1634,  1003,
    1565,  1608,  1610,   567,  1639,  1005,  1642,  1009,  1623,   567,
     569,   570,  1648,  1010,  1624,  1651,  1653,   571,   572,   573,
     574,   575,   576,   577,   578,   567,  1661,  1662,  1085,  1664,
    1625,  1667,   567,  1669,   567,   567,   567,  1626,   567,  1628,
    1629,  1633,   567,  1635,  1718,   567,  1855,  1636,  1722,  1086,
    1641,  1680,  1087,   579,   580,   581,   582,  1682,  1088,  1166,
    1098,  1167,   579,   580,   581,   582,   567,  1112,  1685,   567,
     567,  1643,  1686,   567,  1644,  1645,   567,  1115,  1646,  1689,
    1118,  1647,  1691,   567,   567,  1692,   567,   567,  1649,  1650,
     567,  1654,  1658,   567,   567,  1659,   567,   567,  1663,  1666,
    1703,  1668,  1674,  1122,   567,   567,  1116,   567,  1903,  1713,
    1724,  1905,  1734,   567,   567,  1714,  1715,  1716,  1755,  1760,
    1230,  1119,   567,   567,   567,  1600,  1601,  1810,  1813,  1816,
    1725,  1123,   567,  1728,   567,  1120,  1731,  1818,   567,  1820,
    1733,   567,  1735,  1824,   567,  1246,  1825,   567,  1739,  1829,
    1740,   567,  1836,  1743,  1744,  1121,  1841,  1746,  1257,   567,
     579,   580,   581,   582,  1844,  1952,  1753,   567,  1089,   567,
    1756,   567,  1872,  1759,  1897,  1761,  1931,  1762,  1763,   567,
    1765,   567,   567,   567,  1935,   567,  1943,  1947,  1970,  1264,
    2005,   579,   580,   581,   582,  1148,  1192,  1531,  1195,  1532,
    1196,  1255,  1256,  1258,   230,  1261,   109,   109,   110,   110,
    1262,  1265,  1275,  1290,  1291,  1298,  1302,  1308,  1310,   259,
    1801,  1320,  1322,  1323,  1802,  1325,  1326,  1805,  1327,  1333,
    1337,  1809,   271,  1344,  1351,   279,   793,  1385,   283,   285,
     287,  1386,  1426,  1427,   303,   303,   303,  1428,  1429,  1430,
    1431,  1439,  1449,   327,  1450,  1451,  1461,  1467,  1471,  1477,
    1586,  1536,  1838,  1528,  1839,  1840,  1543,  1842,  1548,    -9,
    1587,  1592,  1597,  1603,  1604,   569,   570,  1696,  1670,  1671,
    1673,  1701,   571,   572,   573,   574,   575,   576,   577,   578,
    1707,  1767,   428,  1710,  1711,  1717,  1857,  1768,   303,   109,
    1787,   110,  1789,  1790,  1797,  1845,  1846,  1847,  -522,  1861,
    1864,  1867,  1870,  1991,   241,   328,   329,  1873,  1874,  1875,
    1876,  1371,  1878,  1879,   796,   982,   244,  1882,  1848,  1585,
    1229,  1885,  1993,   451,  1888,  1889,  1890,  1225,  1891,   980,
     992,  1228,  1895,  1896,  1441,     0,   569,   570,  1898,     0,
       0,  1901,  1902,   571,   572,   573,   574,   575,   576,   577,
     578,   109,     0,   110,   109,     0,   110,     0,  1919,     0,
       0,     0,     0,     0,  1925,  1926,     0,  1928,  1929,  1930,
       0,     0,     0,   122,     0,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1941,     0,     0,     0,  1944,     0,  1945,  1946,     0,   128,
       0,     0,     0,     0,     0,     0,     0,     0,   109,     0,
     110,  1953,     0,     0,     0,     0,     0,     0,   557,   559,
       0,     0,     0,     0,     0,     0,     0,     0,  1962,     0,
       0,     0,  1964,     0,     0,  1966,  1967,     0,   587,     0,
    1969,     0,     0,   592,  1971,     0,   579,   580,   581,   582,
       0,     0,  1557,  1982,  1558,     0,   607,     0,  1986,     0,
       0,   611,     0,     0,     0,     0,     0,  1990,   623,   569,
     570,     0,     0,   141,     0,   142,   571,   572,   573,   574,
     575,   576,   577,   578,  1998,  1999,     0,     0,     0,     0,
       0,   642,     0,   644,   145,   146,     0,  2006,     0,     0,
       0,     0,  2009,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   235,   236,   237,   238,   151,   579,   580,   581,
     582,     0,     0,     0,   153,  1108,     0,   154,     0,     0,
     155,     0,     0,     0,   569,   570,     0,     0,     0,     0,
     679,   571,   572,   573,   574,   575,   576,   577,   578,     0,
       0,     0,     0,   177,   178,   179,     0,     0,     0,   183,
     184,   185,     0,   187,     0,   189,   190,   191,     0,     0,
       0,     0,   196,   197,   198,   199,   200,     0,     0,   203,
       0,   205,     0,   207,     0,     0,   209,     0,   211,     0,
       0,   213,     0,     0,   215,   216,     0,   217,   218,     0,
     220,     0,   222,     0,   569,   570,     0,     0,     0,     0,
     225,   571,   572,   573,   574,   575,   576,   577,   578,   239,
     864,   569,   570,     0,   766,     0,     0,     0,   571,   572,
     573,   574,   575,   576,   577,   578,   776,     0,     0,     0,
       0,   781,   782,     0,   783,   784,   785,   786,   303,   303,
     579,   580,   581,   582,     0,   799,     0,     0,  1136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   823,
     824,   825,   826,   827,   828,   829,   830,   831,   832,   303,
     834,   835,   836,   837,   838,   839,   840,   841,   843,     0,
       0,     0,     0,     0,   849,   850,   852,   854,   855,     0,
     857,     0,   859,     0,     0,   579,   580,   581,   582,     0,
       0,     0,   873,  1137,     0,     0,     0,     0,     0,   303,
       0,     0,   569,   570,   886,     0,     0,     0,     0,   571,
     572,   573,   574,   575,   576,   577,   578,   569,   570,     0,
       0,     0,     0,     0,   571,   572,   573,   574,   575,   576,
     577,   578,     0,   913,   914,   915,   916,   917,   918,   919,
     920,   921,   922,   923,   924,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,     0,     0,  1138,     0,   335,   336,   337,   338,   339,
       0,     0,   579,   580,   581,   582,     0,     0,   956,   340,
    1139,     0,     0,   959,     0,   341,   342,     0,     0,     0,
       0,   343,   344,   345,   346,   347,   976,   977,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   988,
       0,     0,     0,     0,   991,     0,   120,   121,   122,     0,
     123,   124,   125,   126,     0,   998,   999,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   348,     0,
       0,     0,     0,   127,   128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1036,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   131,   132,
     133,   134,   135,   579,   580,   581,   582,     0,     0,     0,
       0,  1140,     0,     0,   136,     0,     0,   137,   579,   580,
     581,   582,   305,     0,     0,     0,  1143,     0,     0,     0,
     306,     0,     0,     0,   139,   140,     0,     0,   141,     0,
     142,     0,  1084,   307,     0,     0,     0,     0,   143,     0,
    1092,  1094,  1095,  1096,     0,   144,     0,     0,     0,   145,
     146,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   147,   148,   149,
     150,   151,   152,     0,     0,     0,     0,     0,     0,   153,
       0,     0,   154,     0,     0,   155,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,     0,
     208,   209,   210,   211,     0,   212,   213,     0,   214,   215,
     216,     0,   217,   218,   219,   220,   221,   222,   223,     0,
       0,     0,     0,     0,   224,   225,     0,   226,     0,     0,
       0,     0,     0,     0,   227,     0,   301,     0,     0,     0,
     569,   570,     0,  1214,  1215,     0,     0,   571,   572,   573,
     574,   575,   576,   577,   578,     0,     0,     0,     0,     0,
       0,     0,     0,  1218,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   607,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1237,
       0,     0,     0,     0,     0,  1244,  1245,   569,   570,     0,
       0,  1250,     0,     0,   571,   572,   573,   574,   575,   576,
     577,   578,     0,     0,     0,  1263,   569,   570,     0,     0,
       0,     0,     0,   571,   572,   573,   574,   575,   576,   577,
     578,     0,     0,     0,     0,  1278,     0,     0,     0,     0,
    1284,  1285,  1286,     0,     0,  1289,   569,   570,  1292,     0,
    1294,     0,  1297,   571,   572,   573,   574,   575,   576,   577,
     578,  1307,     0,     0,     0,  1311,     0,     0,     0,     0,
       0,     0,     0,  1317,     0,  1319,     0,     0,     0,     0,
    1324,     0,     0,     0,  1329,  1331,  1332,     0,     0,  1335,
    1336,     0,     0,  1340,     0,     0,  1343,     0,     0,  1346,
       0,  1348,     0,  1350,     0,     0,     0,  1354,     0,  1357,
       0,     0,     0,     0,     0,     0,     0,     0,  1366,  1367,
    1368,   579,   580,   581,   582,     0,     0,     0,     0,  1146,
    1372,     0,     0,     0,     0,     0,     0,     0,  1376,  1377,
       0,  1378,  1379,  1380,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1387,  1388,     0,  1390,   569,   570,
    1392,  1393,  1394,     0,  1395,   571,   572,   573,   574,   575,
     576,   577,   578,  1398,     0,     0,  1399,     0,   579,   580,
     581,   582,     0,     0,     0,     0,  1147,     0,  1400,     0,
       0,  1401,  1402,  1403,     0,  1404,  1405,   579,   580,   581,
     582,     0,     0,     0,  1407,  1149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   579,   580,   581,
     582,     0,  1413,   634,  1414,  1415,  1416,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1422,     0,
       0,     0,     0,     0,     0,   122,     0,     0,     0,     0,
     126,     0,     0,     0,     0,     0,     0,     0,  1436,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1443,     0,
       0,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1454,  1455,     0,     0,     0,   303,   303,     0,     0,
       0,     0,     0,     0,     0,  1464,  1465,   569,   570,     0,
       0,     0,     0,     0,   571,   572,   573,   574,   575,   576,
     577,   578,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   579,
     580,   581,   582,     0,     0,     0,     0,  1150,     0,     0,
       0,     0,     0,   318,   320,   141,     0,   142,     0,     0,
       0,     0,     0,     0,   334,     0,   349,   350,   352,   354,
     357,   362,   363,   367,   369,   371,   145,   146,     0,  1513,
     381,   383,   384,   386,   387,   388,   394,   399,   407,   414,
     416,   418,     0,     0,   235,   236,   237,   238,   151,     0,
       0,     0,     0,     0,     0,     0,   153,     0,     0,   154,
     569,   570,   155,     0,     0,     0,     0,   571,   572,   573,
     574,   575,   576,   577,   578,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,   179,     0,     0,
       0,   183,   184,   185,     0,   187,     0,   189,   190,   191,
       0,     0,     0,     0,   196,   197,   198,   199,   200,     0,
       0,   203,     0,   205,   611,   207,     0,     0,   209,  1590,
     211,     0,     0,   213,  1594,     0,   215,   216,     0,   217,
     218,     0,   220,     0,   222,     0,     0,     0,   579,   580,
     581,   582,   225,     0,     0,     0,  1151,     0,     0,     0,
       0,   239,   866,     0,     0,  1617,  1618,  1619,     0,  1621,
       0,     0,     0,     0,     0,     0,  1627,     0,     0,     0,
    1631,  1632,     0,     0,     0,     0,  1637,     0,  1638,  1640,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1652,     0,     0,  1655,  1656,     0,  1657,     0,     0,  1660,
       0,     0,     0,     0,  1665,     0,     0,     0,     0,     0,
       0,   569,   570,  1672,     0,     0,     0,     0,   571,   572,
     573,   574,   575,   576,   577,   578,     0,     0,     0,     0,
       0,  1681,     0,  1683,     0,     0,     0,     0,     0,  1684,
       0,   579,   580,   581,   582,     0,     0,     0,  1687,  1152,
    1688,     0,     0,     0,     0,  1690,     0,     0,     0,     0,
       0,     0,     0,     0,  1693,     0,   648,     0,     0,     0,
       0,     0,   653,     0,  1702,     0,     0,  1705,     0,   660,
     662,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   666,   667,   668,   669,   670,   671,   672,     0,     0,
     675,   676,   677,   678,     0,     0,  1726,  1727,     0,     0,
    1730,     0,     0,     0,     0,     0,     0,     0,  1736,     0,
       0,     0,     0,     0,     0,     0,  1741,  1742,     0,     0,
       0,  1745,     0,     0,   569,   570,  1748,     0,     0,     0,
    1752,   571,   572,   573,   574,   575,   576,   577,   578,     0,
     569,   570,     0,     0,     0,     0,  1766,   571,   572,   573,
     574,   575,   576,   577,   578,     0,     0,     0,     0,     0,
       0,     0,   569,   570,     0,     0,     0,     0,  1786,   571,
     572,   573,   574,   575,   576,   577,   578,     0,     0,  1799,
       0,     0,   579,   580,   581,   582,     0,   773,   774,   775,
    1153,  1804,     0,  1806,     0,  1808,     0,     0,     0,     0,
       0,  1814,     0,     0,  1817,     0,  1819,     0,   798,  1822,
    1823,     0,     0,     0,     0,     0,     0,     0,     0,  1830,
       0,  1832,  1833,  1834,     0,     0,  1837,     0,     0,     0,
       0,     0,  1843,     0,     0,     0,     0,     0,     0,   569,
     570,     0,     0,     0,  1850,     0,   571,   572,   573,   574,
     575,   576,   577,   578,  1851,     0,     0,     0,     0,     0,
       0,     0,  1858,  1859,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1881,     0,     0,  1883,     0,     0,     0,  1886,  1887,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,     0,     0,  1154,     0,     0,     0,     0,     0,     0,
       0,   579,   580,   581,   582,     0,     0,     0,     0,  1155,
       0,     0,     0,     0,     0,     0,  1922,     0,  1924,     0,
       0,  1927,     0,   579,   580,   581,   582,     0,     0,  1932,
       0,  1157,  1933,     0,     0,     0,  1937,     0,     0,     0,
       0,     0,     0,     0,  1940,     0,  1942,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1954,   120,
     121,   122,     0,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,   993,     0,     0,  1963,   996,  1965,     0,
       0,  1000,     0,     0,     0,     0,   127,   128,     0,     0,
     579,   580,   581,   582,     0,     0,  1014,  1015,  1168,     0,
       0,  1984,     0,     0,  1021,     0,     0,     0,     0,  1025,
    1989,     0,     0,     0,  1030,     0,  1032,     0,     0,   129,
     130,   131,   132,   133,   134,   135,     0,     0,  1044,     0,
    1046,  1047,     0,  1049,  1050,  1051,     0,   136,     0,     0,
     137,  1055,     0,     0,     0,   299,  1059,     0,     0,     0,
       0,     0,     0,   300,  1065,     0,     0,   139,   140,     0,
       0,   141,  1072,   142,     0,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,   144,   569,
     570,     0,   145,   146,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,     0,     0,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,   153,     0,     0,   154,     0,     0,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,     0,   208,   209,   210,   211,     0,   212,   213,
       0,   214,   215,   216,     0,   217,   218,   219,   220,   221,
     222,   223,     0,     0,     0,     0,     0,   224,   225,     0,
     226,     0,     0,     0,   569,   570,     0,   227,     0,   301,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
       0,     0,     0,     0,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,     0,     0,  1169,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   121,   122,     0,   123,   124,   125,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1268,     0,   127,   128,     0,
       0,     0,     0,  1272,     0,     0,     0,     0,  1277,     0,
    1279,     0,  1281,  1282,     0,     0,     0,  1287,  1288,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   136,     0,
       0,   137,     0,     0,     0,     0,   138,     0,     0,     0,
       0,     0,     0,     0,   787,     0,     0,     0,   139,   140,
       0,     0,   141,     0,   142,   579,   580,   581,   582,     0,
       0,     0,   143,  1171,     0,     0,     0,     0,     0,   144,
       0,     0,     0,   145,   146,   579,   580,   581,   582,     0,
       0,     0,     0,  1174,     0,  1373,  1374,     0,     0,     0,
       0,   147,   148,   149,   150,   151,   152,     0,     0,     0,
       0,     0,     0,   153,     0,     0,   154,     0,     0,   155,
    1389,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,     0,   208,   209,   210,   211,     0,   212,
     213,     0,   214,   215,   216,     0,   217,   218,   219,   220,
     221,   222,   223,     0,     0,     0,     0,     0,   224,   225,
       0,   226,     0,     0,     0,     0,     0,     0,   227,     0,
     301,   120,   121,   122,     0,   123,   124,   125,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   130,   131,   132,   133,   134,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   136,
       0,     0,   137,     0,     0,     0,     0,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   139,
     140,     0,     0,   141,     0,   142,     0,     0,     0,     0,
       0,     0,     0,   143,     0,     0,     0,     0,     0,     0,
     144,   569,   570,     0,   145,   146,     0,     0,   571,   572,
     573,   574,   575,   576,   577,   578,     0,     0,     0,     0,
       0,     0,   147,   148,   149,   150,   151,   152,     0,     0,
       0,     0,     0,     0,   153,     0,     0,   154,     0,     0,
     155,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,     0,   208,   209,   210,   211,     0,
     212,   213,     0,   214,   215,   216,     0,   217,   218,   219,
     220,   221,   222,   223,     0,     0,     0,     0,     0,   224,
     225,     0,   226,     0,     0,     0,     0,     0,     0,   227,
       0,   301,     0,     0,     0,  1613,     0,     0,  1616,     0,
       0,     0,  1620,     0,   120,   121,   122,     0,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   579,   580,   581,   582,     0,     0,     0,     0,
    1198,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1675,     0,     0,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,   569,   570,     0,     0,
     138,     0,     0,   571,   572,   573,   574,   575,   576,   577,
     578,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   144,   569,   570,     0,   145,   146,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
       0,     0,     0,     0,     0,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   224,   225,  1803,   226,     0,     0,  1807,     0,
       0,     0,   227,   765,   120,   121,   122,     0,   123,   124,
     125,   126,     0,     0,     0,     0,     0,   579,   580,   581,
     582,     0,     0,     0,     0,  1240,     0,     0,     0,     0,
       0,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,     0,     0,  1448,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,   569,   570,     0,     0,
     138,     0,     0,   571,   572,   573,   574,   575,   576,   577,
     578,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   144,   569,   570,     0,   145,   146,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
       0,     0,     0,     0,     0,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   224,   225,     0,   226,     0,     0,     0,     0,
       0,     0,   227,   842,   120,   121,   122,     0,   123,   124,
     125,   126,     0,     0,     0,     0,     0,   579,   580,   581,
     582,     0,     0,     0,     0,  1529,     0,     0,     0,     0,
       0,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,     0,     0,  1530,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,   569,   570,     0,     0,
     138,     0,     0,   571,   572,   573,   574,   575,   576,   577,
     578,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   144,   569,   570,     0,   145,   146,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
       0,     0,     0,     0,     0,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   224,   225,     0,   226,     0,     0,     0,     0,
       0,     0,   227,   853,   120,   121,   122,     0,   123,   124,
     125,   126,     0,     0,     0,     0,     0,   579,   580,   581,
     582,     0,     0,     0,     0,  1537,     0,     0,     0,     0,
       0,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,     0,     0,  1538,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   401,   402,   147,   148,   149,   150,   151,
     152,     0,   403,   404,   405,   406,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   224,   225,     0,   226,     0,     0,     0,   120,
     121,   122,   227,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   408,     0,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
     137,     0,     0,     0,     0,   138,     0,     0,     0,     0,
       0,   409,     0,     0,     0,     0,     0,   139,   140,     0,
       0,   141,     0,   142,     0,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   410,   411,
     147,   148,   149,   150,   151,   152,   412,     0,     0,     0,
     413,     0,   153,     0,     0,   154,     0,     0,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,     0,   208,   209,   210,   211,     0,   212,   213,
       0,   214,   215,   216,     0,   217,   218,   219,   220,   221,
     222,   223,     0,     0,     0,     0,     0,   224,   225,     0,
     226,     0,     0,     0,   120,   121,   122,   227,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   389,     0,     0,     0,
       0,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   390,   391,   147,   148,   149,   150,   151,
     152,     0,   392,     0,     0,   393,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   224,   225,     0,   226,     0,     0,     0,   120,
     121,   122,   227,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   358,     0,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
     137,     0,     0,     0,     0,   138,     0,     0,     0,     0,
       0,   359,     0,     0,     0,     0,     0,   139,   140,     0,
       0,   141,     0,   142,     0,     0,     0,   360,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   361,     0,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,   153,     0,     0,   154,     0,     0,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,     0,   208,   209,   210,   211,     0,   212,   213,
       0,   214,   215,   216,     0,   217,   218,   219,   220,   221,
     222,   223,     0,     0,     0,     0,     0,   224,   225,     0,
     226,     0,     0,     0,   120,   121,   122,   227,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   395,     0,     0,     0,
       0,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   396,   397,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,   398,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   224,   225,     0,   226,     0,     0,     0,   120,
     121,   122,   227,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   364,     0,
       0,     0,     0,     0,     0,     0,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   365,     0,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
     137,   569,   570,     0,     0,   138,     0,     0,   571,   572,
     573,   574,   575,   576,   577,   578,     0,   139,   140,     0,
       0,   141,     0,   142,     0,     0,     0,   366,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,   153,     0,     0,   154,     0,     0,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,     0,   208,   209,   210,   211,     0,   212,   213,
       0,   214,   215,   216,     0,   217,   218,   219,   220,   221,
     222,   223,     0,     0,     0,     0,     0,   224,   225,     0,
     226,     0,     0,     0,   120,   121,   122,   227,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   579,   580,   581,   582,     0,     0,     0,     0,
    1539,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,   569,   570,     0,     0,
     138,     0,     0,   571,   572,   573,   574,   575,   576,   577,
     578,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,   378,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   379,   380,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   224,   225,     0,   226,     0,     0,     0,   120,
     121,   122,   227,   123,   124,   125,   126,     0,   316,     0,
       0,     0,     0,     0,     0,     0,     0,   579,   580,   581,
     582,     0,     0,     0,     0,  1540,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   317,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
     137,   569,   570,     0,     0,   138,     0,     0,   571,   572,
     573,   574,   575,   576,   577,   578,     0,   139,   140,     0,
       0,   141,     0,   142,     0,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,   153,     0,     0,   154,     0,     0,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,     0,   208,   209,   210,   211,     0,   212,   213,
       0,   214,   215,   216,     0,   217,   218,   219,   220,   221,
     222,   223,     0,     0,     0,     0,     0,   224,   225,     0,
     226,     0,     0,     0,   120,   121,   122,   227,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   579,   580,   581,   582,     0,     0,     0,     0,
    1541,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,   355,     0,     0,     0,
       0,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,   356,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   224,   225,     0,   226,     0,     0,     0,   120,
     121,   122,   227,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
     137,   569,   570,     0,     0,   138,     0,     0,   571,   572,
     573,   574,   575,   576,   577,   578,     0,   139,   140,     0,
       0,   141,     0,   142,     0,     0,     0,     0,   426,     0,
       0,   143,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   427,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,   153,     0,     0,   154,     0,     0,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,     0,   208,   209,   210,   211,     0,   212,   213,
       0,   214,   215,   216,     0,   217,   218,   219,   220,   221,
     222,   223,     0,     0,     0,     0,     0,   224,   225,     0,
     226,     0,     0,     0,   120,   121,   122,   227,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   579,   580,   581,   582,     0,     0,     0,     0,
    1546,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,   569,   570,     0,     0,
     138,     0,     0,   571,   572,   573,   574,   575,   576,   577,
     578,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,     0,   458,   459,     0,   143,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   224,   225,     0,   226,     0,     0,     0,   120,
     121,   122,   227,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   579,   580,   581,
     582,     0,     0,     0,     0,  1547,   127,   128,     0,     0,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
     137,   569,   570,     0,     0,   138,     0,     0,   571,   572,
     573,   574,   575,   576,   577,   578,     0,   139,   140,     0,
       0,   141,     0,   142,     0,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,   153,     0,     0,   154,     0,     0,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,     0,   208,   209,   210,   211,     0,   212,   213,
       0,   214,   215,   216,     0,   217,   218,   219,   220,   221,
     222,   223,     0,     0,     0,     0,     0,   224,   225,     0,
     226,     0,     0,     0,   120,   121,   122,   227,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   579,   580,   581,   582,     0,     0,     0,     0,
    1552,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,   569,   570,     0,     0,
     138,     0,     0,   571,   572,   573,   574,   575,   576,   577,
     578,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,   319,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   224,   225,     0,   226,     0,     0,     0,   120,
     121,   122,   227,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   579,   580,   581,
     582,     0,     0,     0,     0,  1553,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
     137,   569,   570,     0,     0,   138,     0,     0,   571,   572,
     573,   574,   575,   576,   577,   578,     0,   139,   140,     0,
       0,   141,     0,   142,     0,     0,     0,   351,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,   153,     0,     0,   154,     0,     0,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,     0,   208,   209,   210,   211,     0,   212,   213,
       0,   214,   215,   216,     0,   217,   218,   219,   220,   221,
     222,   223,     0,     0,     0,     0,     0,   224,   225,     0,
     226,     0,     0,     0,   120,   121,   122,   227,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   579,   580,   581,   582,     0,     0,     0,     0,
    1554,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,   569,   570,     0,     0,
     138,     0,     0,   571,   572,   573,   574,   575,   576,   577,
     578,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,   353,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   224,   225,     0,   226,     0,     0,     0,   120,
     121,   122,   227,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   579,   580,   581,
     582,     0,     0,     0,     0,  1555,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
     137,   569,   570,     0,     0,   138,     0,     0,   571,   572,
     573,   574,   575,   576,   577,   578,     0,   139,   140,     0,
       0,   141,     0,   142,     0,     0,     0,   368,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,   153,     0,     0,   154,     0,     0,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,     0,   208,   209,   210,   211,     0,   212,   213,
       0,   214,   215,   216,     0,   217,   218,   219,   220,   221,
     222,   223,     0,     0,     0,     0,     0,   224,   225,     0,
     226,     0,     0,     0,   120,   121,   122,   227,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   579,   580,   581,   582,     0,     0,     0,     0,
    1556,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,   569,   570,     0,     0,
     138,     0,     0,   571,   572,   573,   574,   575,   576,   577,
     578,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,   370,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   224,   225,     0,   226,     0,     0,     0,   120,
     121,   122,   227,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   579,   580,   581,
     582,     0,     0,     0,     0,  1559,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
     137,   569,   570,     0,     0,   138,     0,     0,   571,   572,
     573,   574,   575,   576,   577,   578,     0,   139,   140,     0,
       0,   141,     0,   142,     0,     0,     0,   382,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,   153,     0,     0,   154,     0,     0,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,     0,   208,   209,   210,   211,     0,   212,   213,
       0,   214,   215,   216,     0,   217,   218,   219,   220,   221,
     222,   223,     0,     0,     0,     0,     0,   224,   225,     0,
     226,     0,     0,     0,   120,   121,   122,   227,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   579,   580,   581,   582,     0,     0,     0,     0,
    1560,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,   569,   570,     0,     0,
     138,     0,     0,   571,   572,   573,   574,   575,   576,   577,
     578,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,   385,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   224,   225,     0,   226,     0,     0,     0,   120,
     121,   122,   227,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   579,   580,   581,
     582,     0,     0,     0,     0,  1563,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
     137,   569,   570,     0,     0,   138,     0,     0,   571,   572,
     573,   574,   575,   576,   577,   578,     0,   139,   140,     0,
       0,   141,     0,   142,     0,     0,     0,   415,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,   153,     0,     0,   154,     0,     0,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,     0,   208,   209,   210,   211,     0,   212,   213,
       0,   214,   215,   216,     0,   217,   218,   219,   220,   221,
     222,   223,     0,     0,     0,     0,     0,   224,   225,     0,
     226,     0,     0,     0,   120,   121,   122,   227,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   579,   580,   581,   582,     0,     0,     0,     0,
    1571,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,   569,   570,     0,     0,
     138,     0,     0,   571,   572,   573,   574,   575,   576,   577,
     578,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,   417,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,     0,     0,
       0,     0,   224,   225,     0,   226,     0,     0,     0,   120,
     121,   122,   227,   123,   124,   125,   126,     0,   661,     0,
       0,     0,     0,     0,     0,     0,     0,   579,   580,   581,
     582,     0,     0,     0,     0,  1574,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
     137,   569,   570,     0,     0,   138,     0,     0,   571,   572,
     573,   574,   575,   576,   577,   578,     0,   139,   140,     0,
       0,   141,     0,   142,     0,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,     0,     0,     0,   144,     0,
       0,     0,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,     0,   153,     0,     0,   154,     0,     0,   155,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,     0,   208,   209,   210,   211,     0,   212,   213,
       0,   214,   215,   216,     0,   217,   218,   219,   220,   221,
     222,   223,     0,     0,     0,     0,     0,   224,   225,     0,
     226,     0,     0,     0,   120,   121,   122,   227,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   579,   580,   581,   582,     0,     0,     0,     0,
    1589,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,   133,   134,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   136,     0,     0,   137,     0,     0,     0,     0,
     138,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   139,   140,     0,     0,   141,     0,   142,     0,
       0,     0,     0,     0,     0,     0,   143,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,     0,
       0,     0,     0,   126,     0,   147,   148,   149,   150,   151,
     152,     0,     0,     0,     0,     0,     0,   153,     0,     0,
     154,     0,     0,   155,   128,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,   208,   209,
     210,   211,     0,   212,   213,     0,   214,   215,   216,     0,
     217,   218,   219,   220,   221,   222,   223,     0,   141,     0,
     142,     0,   224,   225,     0,   226,     0,     0,     0,     0,
       0,     0,   227,     0,     0,     0,     0,     0,     0,   145,
     146,     0,     0,     0,     0,     0,     0,     0,   122,     0,
       0,     0,     0,   126,     0,     0,     0,   235,   236,   237,
     238,   151,     0,     0,     0,     0,     0,     0,     0,   153,
       0,     0,   154,     0,   128,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,     0,     0,     0,   183,   184,   185,     0,   187,     0,
     189,   190,   191,     0,     0,     0,     0,   196,   197,   198,
     199,   200,     0,     0,   203,     0,   205,     0,   207,     0,
       0,   209,     0,   211,     0,     0,   213,     0,     0,   215,
     216,     0,   217,   218,     0,   220,     0,   222,   141,     0,
     142,     0,     0,     0,   372,   225,     0,     0,     0,     0,
       0,     0,     0,     0,   239,   868,     0,     0,     0,   145,
     146,     0,     0,     0,   122,     0,     0,     0,     0,   126,
       0,     0,     0,     0,     0,     0,     0,   235,   236,   237,
     238,   151,     0,     0,     0,     0,     0,     0,     0,   153,
     128,     0,   154,     0,     0,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,     0,     0,     0,   183,   184,   185,     0,   187,     0,
     189,   190,   191,     0,     0,     0,     0,   196,   197,   198,
     199,   200,     0,     0,   203,     0,   205,     0,   207,     0,
       0,   209,     0,   211,     0,     0,   213,     0,     0,   215,
     216,     0,   217,   218,   141,   220,   142,   222,     0,     0,
     419,     0,     0,     0,     0,   225,     0,     0,     0,     0,
       0,     0,     0,     0,   239,   145,   146,     0,     0,     0,
     122,     0,     0,     0,     0,   126,     0,     0,     0,     0,
       0,     0,     0,   235,   236,   237,   238,   151,     0,     0,
       0,     0,     0,     0,     0,   153,   128,     0,   154,     0,
       0,   155,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,   179,     0,     0,     0,
     183,   184,   185,     0,   187,     0,   189,   190,   191,     0,
       0,     0,     0,   196,   197,   198,   199,   200,     0,     0,
     203,     0,   205,     0,   207,     0,     0,   209,     0,   211,
       0,     0,   213,     0,     0,   215,   216,     0,   217,   218,
     141,   220,   142,   222,     0,     0,   421,     0,     0,     0,
       0,   225,     0,     0,     0,     0,     0,     0,     0,     0,
     239,   145,   146,     0,     0,     0,   122,     0,     0,     0,
       0,   126,     0,     0,     0,     0,     0,     0,     0,   235,
     236,   237,   238,   151,     0,     0,     0,     0,     0,     0,
       0,   153,   128,     0,   154,     0,     0,   155,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     177,   178,   179,     0,     0,     0,   183,   184,   185,     0,
     187,     0,   189,   190,   191,     0,     0,     0,     0,   196,
     197,   198,   199,   200,     0,     0,   203,     0,   205,     0,
     207,     0,     0,   209,     0,   211,     0,     0,   213,     0,
       0,   215,   216,     0,   217,   218,   141,   220,   142,   222,
       0,     0,   423,     0,     0,   122,     0,   225,     0,     0,
     126,     0,     0,     0,     0,     0,   239,   145,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,     0,     0,     0,   235,   236,   237,   238,   151,
       0,     0,     0,     0,     0,     0,     0,   153,     0,     0,
     154,     0,     0,   155,     0,   569,   570,     0,     0,     0,
       0,     0,   571,   572,   573,   574,   575,   576,   577,   578,
       0,     0,     0,     0,     0,     0,   177,   178,   179,     0,
       0,     0,   183,   184,   185,     0,   187,     0,   189,   190,
     191,     0,     0,     0,     0,   196,   197,   198,   199,   200,
       0,     0,   203,     0,   205,   141,   207,   142,     0,   209,
       0,   211,     0,     0,   213,     0,     0,   215,   216,     0,
     217,   218,     0,   220,     0,   222,   145,   146,     0,     0,
       0,   122,     0,   225,     0,     0,   126,     0,     0,     0,
       0,     0,   239,     0,   235,   236,   237,   238,   151,     0,
     742,     0,     0,     0,     0,     0,   153,   128,     0,   154,
       0,     0,   155,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,   179,     0,     0,
       0,   183,   184,   185,     0,   187,     0,   189,   190,   191,
       0,     0,     0,     0,   196,   197,   198,   199,   200,     0,
       0,   203,     0,   205,     0,   207,     0,     0,   209,     0,
     211,     0,     0,   213,     0,     0,   215,   216,     0,   217,
     218,   141,   220,   142,   222,     0,   579,   580,   581,   582,
       0,     0,   225,   122,  1700,     0,     0,     0,   126,     0,
       0,   239,   145,   146,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
     235,   236,   237,   238,   151,     0,   816,     0,     0,     0,
       0,     0,   153,     0,     0,   154,     0,     0,   155,     0,
       0,     0,   569,   570,     0,     0,     0,     0,     0,   571,
     572,   573,   574,   575,   576,   577,   578,     0,     0,     0,
       0,   177,   178,   179,     0,     0,     0,   183,   184,   185,
       0,   187,     0,   189,   190,   191,     0,     0,     0,     0,
     196,   197,   198,   199,   200,   986,     0,   203,     0,   205,
       0,   207,     0,   141,   209,   142,   211,     0,     0,   213,
       0,     0,   215,   216,     0,   217,   218,     0,   220,     0,
     222,     0,     0,     0,   145,   146,     0,     0,   225,     0,
       0,     0,     0,     0,     0,     0,     0,   239,     0,     0,
       0,     0,   235,   236,   237,   238,   151,     0,     0,     0,
     122,     0,     0,     0,   153,   126,     0,   154,     0,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,   177,   178,   179,     0,     0,     0,   183,
     184,   185,     0,   187,     0,   189,   190,   191,     0,     0,
       0,     0,   196,   197,   198,   199,   200,     0,     0,   203,
       0,   205,     0,   207,     0,     0,   209,     0,   211,     0,
       0,   213,     0,     0,   215,   216,     0,   217,   218,     0,
     220,     0,   222,   579,   580,   581,   582,     0,     0,     0,
     225,  1704,  1382,     0,     0,     0,     0,     0,     0,   239,
     141,     0,   142,     0,     0,     0,     0,     0,     0,   122,
       0,     0,     0,     0,   126,     0,     0,     0,     0,     0,
       0,   145,   146,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,   235,
     236,   237,   238,   151,     0,     0,     0,     0,     0,     0,
       0,   153,     0,     0,   154,     0,     0,   155,   569,   570,
       0,     0,     0,     0,     0,   571,   572,   573,   574,   575,
     576,   577,   578,     0,     0,     0,     0,     0,     0,     0,
     177,   178,   179,     0,     0,     0,   183,   184,   185,     0,
     187,     0,   189,   190,   191,     0,     0,     0,     0,   196,
     197,   198,   199,   200,     0,     0,   203,     0,   205,   141,
     207,   142,     0,   209,     0,   211,     0,     0,   213,     0,
       0,   215,   216,     0,   217,   218,     0,   220,     0,   222,
     145,   146,     0,     0,     0,   122,     0,   225,     0,     0,
     126,     0,     0,     0,     0,     0,   239,     0,   235,   236,
     237,   238,   151,     0,     0,     0,     0,     0,     0,     0,
     153,   128,     0,   154,     0,     0,   155,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   177,
     178,   179,     0,     0,     0,   183,   184,   185,     0,   187,
       0,   189,   190,   191,     0,     0,     0,     0,   196,   197,
     198,   199,   200,     0,     0,   203,     0,   205,     0,   207,
       0,     0,   209,     0,   211,     0,     0,   213,     0,     0,
     215,   216,     0,   217,   218,   141,   220,   142,   222,   579,
     580,   581,   582,     0,     0,     0,   225,  1764,     0,     0,
       0,   569,   570,     0,     0,   239,   145,   146,   571,   572,
     573,   574,   575,   576,   577,   578,     0,     0,     0,     0,
       0,     0,     0,     0,   235,   236,   237,   238,   151,     0,
       0,     0,     0,     0,     0,     0,   153,     0,     0,   154,
       0,     0,   155,     0,     0,     0,     0,     0,   569,   570,
       0,     0,     0,     0,     0,   571,   572,   573,   574,   575,
     576,   577,   578,     0,     0,   177,   178,   179,     0,     0,
       0,   183,   184,   185,     0,   187,     0,   189,   190,   191,
       0,     0,     0,     0,   196,   197,   198,   199,   200,     0,
       0,   203,     0,   205,     0,   207,     0,     0,   209,     0,
     211,     0,     0,   213,     0,     0,   215,   216,     0,   217,
     218,     0,   220,     0,   222,     0,     0,     7,     8,     9,
       0,     0,   225,     0,    10,     0,     0,     0,    11,     0,
      12,  1241,    13,    14,    15,    16,    17,  -473,     0,    18,
      19,    20,    21,    22,    23,    24,    25,     0,    26,    27,
      28,     0,     0,     0,     0,    29,     0,     0,    30,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,     0,     0,     0,    37,    38,     0,     0,     0,     0,
       0,     0,   579,   580,   581,   582,     0,     0,     0,     0,
    1773,    39,    40,    41,    42,    43,    44,     0,     0,     0,
       0,     0,    45,    46,    47,  -233,  -233,    48,    49,    50,
       0,    51,    52,    53,     0,     0,    54,  -233,     0,    55,
       0,    56,    57,     0,     0,     0,     0,    58,    59,   579,
     580,   581,   582,     0,    60,   635,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,     0,    80,    81,    82,
      83,    84,    85,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,     0,     0,     0,    90,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,     0,     0,     0,     0,    94,     0,     0,     0,     0,
     569,   570,     0,     0,     0,     0,     0,   571,   572,   573,
     574,   575,   576,   577,   578,    95,     0,     0,     0,    96,
       0,     7,     8,     9,    97,     0,     0,    98,    10,     0,
       0,    99,    11,     0,    12,     0,    13,    14,    15,    16,
      17,  -473,     0,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,     0,     0,     0,     0,    29,
     -16,   -16,    30,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,    35,    36,     0,     0,     0,    37,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
      44,     0,     0,     0,     0,     0,    45,    46,    47,     0,
       0,    48,    49,    50,     0,    51,    52,    53,     0,     0,
      54,     0,     0,    55,     0,    56,    57,     0,     0,     0,
       0,    58,    59,     0,     0,     0,     0,     0,    60,     0,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,    80,    81,    82,    83,    84,    85,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,     0,     0,     0,
      90,   579,   580,   581,   582,     0,     0,     0,     0,  1776,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,     0,     0,     0,     0,    94,
       0,     0,     0,     0,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,    95,
       0,     0,     0,    96,     0,     7,     8,     9,    97,     0,
       0,    98,    10,     0,     0,    99,    11,     0,    12,     0,
      13,    14,    15,    16,    17,  -473,     0,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,   -16,
       0,     0,     0,    29,   -16,     0,    30,     0,     0,     0,
       0,     0,     0,    31,    32,    33,    34,    35,    36,   569,
     570,     0,    37,    38,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,    44,     0,     0,     0,     0,     0,
      45,    46,    47,     0,     0,    48,    49,    50,     0,    51,
      52,    53,     0,     0,    54,     0,     0,    55,     0,    56,
      57,     0,     0,     0,     0,    58,    59,     0,     0,     0,
       0,     0,    60,     0,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,    80,    81,    82,    83,    84,
      85,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,     0,     0,    90,   579,   580,   581,   582,   569,
     570,     0,     0,  1777,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,     0,    91,    92,    93,   569,
     570,     0,     0,    94,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,    96,     0,     0,
       0,     0,    97,   569,   570,    98,     0,     0,     0,    99,
     571,   572,   573,   574,   575,   576,   577,   578,     0,     0,
     579,   580,   581,   582,   569,   570,     0,     0,  1779,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
     579,   580,   581,   582,   569,   570,     0,     0,  1796,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
     579,   580,   581,   582,   569,   570,     0,     0,  1904,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   569,   570,
       0,     0,  1917,     0,     0,   571,   572,   573,   574,   575,
     576,   577,   578,     0,     0,   579,   580,   581,   582,     0,
       0,     0,     0,  1960,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,     0,     0,  1981,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,     0,     0,  1996,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,   652,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,   760,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,   983,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,   569,
     570,  1013,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,   579,   580,   581,   582,   569,
     570,  1106,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,   579,   580,   581,   582,     0,
       0,  1107,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,   569,   570,  1109,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   569,   570,  1110,     0,     0,     0,     0,
     571,   572,   573,   574,   575,   576,   577,   578,   569,   570,
       0,     0,     0,     0,     0,   571,   572,   573,   574,   575,
     576,   577,   578,   569,   570,     0,     0,     0,     0,     0,
     571,   572,   573,   574,   575,   576,   577,   578,   569,   570,
       0,     0,     0,     0,     0,   571,   572,   573,   574,   575,
     576,   577,   578,   569,   570,     0,     0,     0,     0,     0,
     571,   572,   573,   574,   575,   576,   577,   578,   569,   570,
       0,     0,     0,     0,     0,   571,   572,   573,   574,   575,
     576,   577,   578,   569,   570,     0,     0,     0,     0,     0,
     571,   572,   573,   574,   575,   576,   577,   578,     0,     0,
     579,   580,   581,   582,   569,   570,  1111,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
     579,   580,   581,   582,   569,   570,  1125,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,   579,   580,   581,   582,   569,
     570,  1156,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,     0,     0,
    1163,     0,     0,     0,     0,     0,     0,     0,     0,   579,
     580,   581,   582,     0,     0,  1164,     0,     0,     0,     0,
       0,     0,     0,     0,   579,   580,   581,   582,     0,     0,
    1184,     0,     0,     0,     0,     0,     0,     0,     0,   579,
     580,   581,   582,     0,     0,  1236,     0,     0,     0,     0,
       0,     0,     0,     0,   579,   580,   581,   582,     0,     0,
    1259,     0,     0,     0,     0,     0,     0,     0,     0,   579,
     580,   581,   582,     0,     0,  1260,     0,     0,     0,     0,
       0,     0,     0,     0,   579,   580,   581,   582,   569,   570,
    1267,     0,     0,     0,     0,   571,   572,   573,   574,   575,
     576,   577,   578,     0,     0,   579,   580,   581,   582,   569,
     570,  1273,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,   579,   580,   581,   582,     0,
       0,  1274,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,   569,   570,  1314,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
     579,   580,   581,   582,   569,   570,  1364,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   569,   570,  1369,     0,     0,     0,     0,
     571,   572,   573,   574,   575,   576,   577,   578,     0,     0,
     579,   580,   581,   582,   569,   570,  1370,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,   579,   580,   581,   582,   569,
     570,  1437,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,   579,   580,   581,   582,     0,
       0,  1442,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,  1456,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,  1468,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,  1473,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,  1474,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,  1475,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,   569,
     570,  1478,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   569,   570,
    1505,     0,     0,     0,     0,   571,   572,   573,   574,   575,
     576,   577,   578,     0,     0,   579,   580,   581,   582,     0,
       0,  1512,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,   569,   570,  1517,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
     579,   580,   581,   582,   569,   570,  1520,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
     579,   580,   581,   582,   569,   570,  1551,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   569,   570,  1572,     0,     0,     0,     0,
     571,   572,   573,   574,   575,   576,   577,   578,   569,   570,
       0,     0,     0,     0,     0,   571,   572,   573,   574,   575,
     576,   577,   578,     0,     0,   579,   580,   581,   582,   569,
     570,  1573,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,   579,   580,   581,   582,     0,
       0,  1595,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,  1609,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,  1719,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,  1720,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,  1721,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,  1723,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,   569,
     570,  1729,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,   579,   580,   581,   582,   569,
     570,  1732,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,     0,     0,
    1737,     0,     0,     0,     0,     0,     0,     0,     0,   579,
     580,   581,   582,   569,   570,  1738,     0,     0,     0,     0,
     571,   572,   573,   574,   575,   576,   577,   578,     0,     0,
     579,   580,   581,   582,   569,   570,  1749,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
     579,   580,   581,   582,   569,   570,  1750,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
     579,   580,   581,   582,   569,   570,  1751,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   569,   570,
    1754,     0,     0,     0,     0,   571,   572,   573,   574,   575,
     576,   577,   578,     0,     0,   579,   580,   581,   582,     0,
       0,  1758,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,  1772,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,  1791,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,  1811,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,  1812,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,  1815,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,   569,
     570,  1821,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,   579,   580,   581,   582,   569,
     570,  1826,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,   579,   580,   581,   582,     0,
       0,  1827,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,   569,   570,  1828,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   569,   570,  1831,     0,     0,     0,     0,
     571,   572,   573,   574,   575,   576,   577,   578,   569,   570,
       0,     0,     0,     0,     0,   571,   572,   573,   574,   575,
     576,   577,   578,   569,   570,     0,     0,     0,     0,     0,
     571,   572,   573,   574,   575,   576,   577,   578,   569,   570,
       0,     0,     0,     0,     0,   571,   572,   573,   574,   575,
     576,   577,   578,   569,   570,     0,     0,     0,     0,     0,
     571,   572,   573,   574,   575,   576,   577,   578,   569,   570,
       0,     0,     0,     0,     0,   571,   572,   573,   574,   575,
     576,   577,   578,   569,   570,     0,     0,     0,     0,     0,
     571,   572,   573,   574,   575,   576,   577,   578,     0,     0,
     579,   580,   581,   582,   569,   570,  1835,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
     579,   580,   581,   582,   569,   570,  1866,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,   579,   580,   581,   582,   569,
     570,  1868,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,     0,     0,
    1869,     0,     0,     0,     0,     0,     0,     0,     0,   579,
     580,   581,   582,     0,     0,  1871,     0,     0,     0,     0,
       0,     0,     0,     0,   579,   580,   581,   582,     0,     0,
    1877,     0,     0,     0,     0,     0,     0,     0,     0,   579,
     580,   581,   582,     0,     0,  1880,     0,     0,     0,     0,
       0,     0,     0,     0,   579,   580,   581,   582,     0,     0,
    1884,     0,     0,     0,     0,     0,     0,     0,     0,   579,
     580,   581,   582,     0,     0,  1892,     0,     0,     0,     0,
       0,     0,     0,     0,   579,   580,   581,   582,   569,   570,
    1893,     0,     0,     0,     0,   571,   572,   573,   574,   575,
     576,   577,   578,     0,     0,   579,   580,   581,   582,   569,
     570,  1894,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,   579,   580,   581,   582,     0,
       0,  1900,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,   569,   570,  1916,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,     0,
     579,   580,   581,   582,   569,   570,  1934,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,   569,   570,     0,     0,     0,     0,
       0,   571,   572,   573,   574,   575,   576,   577,   578,   569,
     570,     0,     0,     0,     0,     0,   571,   572,   573,   574,
     575,   576,   577,   578,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   579,
     580,   581,   582,     0,     0,  1936,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,  1938,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,  1939,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,  1959,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,  1961,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,  1968,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,  1987,     0,     0,     0,
       0,     0,     0,     0,     0,   579,   580,   581,   582,     0,
       0,  1988,     0,     0,     0,     0,     0,     0,     0,     0,
     579,   580,   581,   582,     0,     0,  2000
};

static const yytype_int16 yycheck[] =
{
       3,   252,    12,     1,    40,     1,     4,    44,     4,    77,
     461,    75,    11,     4,    15,    16,     7,     4,    21,   270,
       7,    24,    75,    58,    12,    60,    61,  1248,  1249,    61,
      33,     4,     5,    77,    37,    38,     0,     3,    16,    42,
      41,     7,     8,     9,    10,    28,    58,   112,    60,    61,
      33,    54,    55,    56,     3,    53,    12,    53,     7,     8,
       9,    10,   112,   430,   431,   245,    44,    70,    71,    72,
     250,    70,    71,    72,    73,    74,    75,    76,   250,   111,
     252,   112,   113,    86,    87,    88,    12,    25,     4,     5,
     155,   112,   113,    96,    97,    98,    99,   112,   113,   112,
     113,     4,     5,    13,   245,   155,    44,    63,    64,   250,
       4,   252,     7,     7,    70,    71,    72,    73,    74,    75,
      76,    77,    81,    82,   155,   245,   245,   100,   245,    88,
     250,   250,    43,    44,   155,   252,   245,    63,    64,    28,
     155,   250,   155,   252,    70,    71,    72,    73,    74,    75,
      76,    77,   111,    63,    64,    73,    74,    75,    76,    77,
      70,    71,    72,    73,    74,    75,    76,    77,    95,    70,
      71,    72,    73,    74,    75,    76,   244,   245,   246,   247,
     250,   110,   252,   245,   551,    96,   553,   251,   250,    23,
      59,    70,    71,    72,    73,    74,    75,    76,   251,   245,
       4,     5,   246,   247,    92,    93,   252,    14,   245,    16,
     160,    18,   185,   186,   187,    44,   104,   251,   253,   245,
      89,    90,    91,   245,   227,   245,   252,    96,   250,    75,
     252,  1598,   252,   251,    41,   245,   239,    44,   245,   245,
     250,   253,    49,   250,   250,   248,   245,   251,   245,   331,
     332,   251,   334,   250,   252,   252,   252,   293,   294,   251,
     251,   264,   250,    75,   251,    24,   269,   349,   350,   185,
     186,   187,   270,   276,   270,   357,   245,   245,   244,   245,
     362,   250,   250,   252,   252,   367,   251,   369,   244,   245,
     246,   247,   162,   245,   250,   244,   245,   300,   250,   381,
     252,   383,   384,   251,   386,   387,   388,   251,   311,   312,
     313,    14,   394,    16,   251,    18,   319,   399,   244,   245,
     246,   247,   112,   245,   245,   407,   244,   245,   246,   247,
     252,   252,   414,   112,   244,   245,   246,   247,    41,   342,
     343,    44,   251,   250,   245,   252,    49,   245,   351,   250,
     353,   252,   355,   356,   252,   358,   359,   360,   361,   112,
     113,   364,   365,   366,   615,   368,   245,   370,   250,   372,
     252,   250,   112,   376,   377,   378,   379,   380,  1599,   382,
     245,  1602,   385,    20,    21,   250,   389,   390,   391,   392,
     393,   245,   395,   396,   397,   398,   250,   400,   401,   402,
     403,   404,   405,   406,   245,   408,   409,   410,   411,   412,
     413,   252,   415,   247,   417,   249,   419,   250,   421,   252,
     423,   251,   425,   426,   427,   245,    63,    64,  1795,   251,
     433,  1798,   252,    70,    71,    72,    73,    74,    75,    76,
      77,   251,   445,    35,    36,    70,    71,    72,    73,    74,
      75,    76,   245,   456,   251,   458,   251,   250,    44,   252,
     251,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,    76,    77,   486,   245,   245,   251,  1708,   245,   250,
     250,   252,   252,  1860,   161,   252,  1863,    70,    71,    72,
      73,    74,    75,    76,   507,   508,   509,   510,   511,   251,
     245,   514,     4,     5,   517,   250,   519,   252,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   251,   531,   532,
     533,   534,   535,   536,   537,   538,     4,     5,   541,   251,
     543,   544,   545,   546,   547,   456,   457,   550,   245,   552,
     251,   554,   555,   556,   155,   252,   251,   560,   561,   562,
     563,   564,   565,   566,   567,   251,   648,   251,    70,    71,
      72,    73,    74,    75,    76,   245,   245,   245,     4,     5,
     662,   250,   252,   252,   252,   667,   497,   669,     3,   671,
     672,   251,     7,     8,     9,   677,   678,    70,    71,    72,
      73,    74,    75,    76,   245,   641,   251,   244,   245,   246,
     247,   252,   251,   447,   448,   618,  1983,   615,  1985,   615,
     245,   245,   245,   245,   245,   245,   537,   252,   252,   252,
     252,   252,   252,   245,  2001,   251,  2003,   251,   245,   245,
     252,  1862,     5,   646,  1865,   252,   252,    10,   245,   244,
     245,   246,   247,   249,   250,   252,   659,   251,    70,    71,
      72,    73,    74,    75,    76,   245,   245,   251,    31,   251,
     250,    44,   245,   252,    14,   251,    16,   928,    18,   252,
     683,   251,   685,    70,    71,    72,    73,    74,    75,    76,
     245,   694,   774,   775,    44,   250,   155,  1918,   251,   702,
    1921,    41,   705,   706,    44,   539,   540,   251,   245,    49,
     245,   245,   245,    63,    64,   252,   798,   252,   252,   252,
      70,    71,    72,    73,    74,    75,    76,    77,    70,    71,
      72,    73,    74,    75,    76,    77,     4,     5,   251,   742,
     251,   245,   105,   245,   107,   748,   251,   750,   252,   752,
     252,   754,   245,   756,  1205,   245,   251,  1208,   155,   252,
     245,   245,   252,   126,   127,   768,   769,   252,   252,   251,
     245,   245,   245,   245,  1995,   250,  1997,   250,   252,   155,
     252,   144,   145,   146,   147,   148,  2007,  2008,   245,    86,
      87,     4,     5,   156,   245,   252,   159,   631,   632,   162,
     245,   252,   636,   637,    70,    71,    72,    73,    74,    75,
      76,   245,   245,   816,   245,   245,   250,     4,   821,   252,
     250,   252,   185,   186,   187,    75,    76,    77,   191,   192,
     193,   251,   195,   245,   197,   198,   199,   251,   250,   245,
     245,   204,   205,   206,   207,   208,   252,   252,   211,   245,
     213,   245,   215,   251,   250,   218,   250,   220,   245,   251,
     223,    49,    50,   226,   227,   245,   229,   230,   251,   232,
     250,   234,    70,    71,    72,    73,    74,    75,    76,   242,
     245,   245,   251,    46,   251,   250,   250,   245,   251,   252,
       4,     5,   250,   245,   244,   245,   246,   247,   250,   250,
      63,    64,   244,   245,   246,   247,   251,    70,    71,    72,
      73,    74,    75,    76,    77,   251,   245,    39,    40,   251,
      46,   250,    70,    71,    72,    73,    74,    75,    76,   245,
     928,   251,   928,   251,   250,   936,   937,    63,    64,     4,
       5,   944,   251,   251,    70,    71,    72,    73,    74,    75,
      76,    77,    51,   245,   245,   251,   245,   960,   250,   250,
     963,   250,    58,   966,    63,    64,    74,    75,    76,    77,
     251,    70,    71,    72,    73,    74,    75,    76,    77,   245,
     245,  1232,    60,    61,   250,   250,   250,   990,    14,   251,
      16,   994,    18,   251,   244,   245,   246,   247,  1001,    60,
      61,   250,  1005,   251,    71,  1008,    73,    74,    75,    76,
      77,   245,   251,   251,   251,    41,   250,  1020,    44,  1022,
    1023,  1024,   245,    49,  1027,  1028,  1029,   250,  1031,   245,
     245,   251,  1035,   245,   250,   250,  1039,  1040,   250,  1042,
     245,   245,  1045,   245,   251,   250,   250,   245,   250,  1052,
    1053,   245,   250,  1056,   251,   251,   250,  1060,  1061,  1062,
    1063,   245,   251,  1066,   245,   251,   250,  1070,   245,   250,
    1073,   251,   245,   250,  1077,   251,  1079,   250,  1081,   251,
    1083,   244,   245,   246,   247,    70,    71,    72,    73,    74,
      75,    76,   251,   245,   251,   245,   251,   245,   250,  1097,
     250,  1097,   250,   250,   938,   939,   245,   941,   942,   251,
    1113,   250,  1115,   251,  1117,   251,   251,   245,   244,   245,
     246,   247,   250,  1126,   245,   250,   245,   245,   245,   250,
    1133,   250,   250,   250,   250,   245,   244,   245,   246,   247,
     250,     5,   251,   250,    63,   244,   245,   246,   247,   251,
     251,    70,    71,    72,    73,    74,    75,    76,    77,   245,
     245,    63,    64,  1166,   250,   250,    43,   251,    70,    71,
      72,    73,    74,    75,    76,    77,   251,   244,   245,   246,
     247,  1184,  1185,  1186,  1187,   251,   245,   245,   245,   245,
    1193,   250,   250,   250,   250,   250,   245,  1279,   251,   245,
    1282,   250,   245,  1206,   250,  1287,  1209,   250,  1211,    63,
      64,   236,   237,   238,   239,   240,    70,    71,    72,    73,
      74,    75,    76,    77,   245,   245,   245,   251,   251,   250,
     250,   250,    63,    64,  1232,  1238,  1232,   251,  1241,    70,
      71,    72,    73,    74,    75,    76,    77,   245,   245,   245,
     245,  1085,   250,   250,   250,   250,   245,   245,   251,   251,
     245,   250,   250,  1266,  1267,   250,    63,    64,  1271,   251,
     251,   251,  1275,    70,    71,    72,    73,    74,    75,    76,
      77,   245,   251,   251,   245,   251,   250,  1290,  1291,   250,
    1293,  1373,  1295,   245,   251,  1298,   245,   245,   250,  1302,
    1303,   250,   250,    77,   251,  1308,   250,  1310,  1390,  1312,
     245,  1314,   250,   245,   250,   250,   245,  1320,   250,  1322,
    1323,   250,  1325,  1326,  1327,   244,   245,   246,   247,   250,
    1333,   245,   245,   245,  1337,   245,   250,   250,   250,   250,
     250,  1344,   244,   245,   246,   247,   245,   251,  1351,   252,
    1353,   250,  1355,  1264,  1265,  1358,   252,  1360,   252,  1362,
     245,  1364,    63,    64,   252,   250,  1369,  1370,    75,    70,
      71,    72,    73,    74,    75,    76,    77,   251,   251,    71,
      72,    73,    74,    75,    76,    77,   251,   250,   250,   245,
     244,   245,   246,   247,   250,   245,   250,   245,   252,   245,
     250,   245,   250,   245,   250,   245,   250,   245,   250,   250,
     250,    46,   250,   244,   245,   246,   247,   245,   251,   250,
      58,   252,   250,  1257,  1258,  1426,  1427,   245,   245,  1432,
     245,   245,   250,   250,   245,   250,   250,   245,    43,   250,
     245,  1444,   250,  1694,  1695,   250,   245,   244,   245,   246,
     247,   250,   245,  1456,    10,   252,   245,   250,  1461,  1462,
     251,   250,   252,   251,  1467,  1468,   245,  1470,  1471,    63,
      64,   250,   252,   251,   250,  1478,    70,    71,    72,    73,
      74,    75,    76,    77,  1487,   245,   245,   245,  1491,   250,
     250,   250,   250,   245,  1497,   250,  1499,   250,   250,   245,
      63,    64,  1505,   250,   250,  1508,  1509,    70,    71,    72,
      73,    74,    75,    76,    77,   245,  1519,  1520,   251,  1522,
     250,  1524,   245,  1526,   245,   245,   245,   250,   245,   250,
     250,   250,   245,   250,  1616,   245,  1787,   250,  1620,   250,
     250,  1544,   250,   244,   245,   246,   247,  1550,   250,   250,
     250,   252,   244,   245,   246,   247,   245,   252,  1561,   245,
     245,   250,  1565,   245,   250,   250,   245,   250,   250,  1572,
     251,   250,  1575,   245,   245,  1578,   245,   245,   250,   250,
     245,   250,   250,   245,   245,   250,   245,   245,   250,   250,
    1593,   250,   250,   250,   245,   245,   252,   245,  1849,   250,
     250,  1852,   250,   245,   245,  1608,  1609,  1610,   250,   250,
      43,   251,   245,   245,   245,  1449,  1450,   250,   250,   250,
    1623,   250,   245,  1626,   245,   252,  1629,   250,   245,   250,
    1633,   245,  1635,   250,   245,   251,   250,   245,  1641,   250,
    1643,   245,   250,  1646,  1647,   252,   250,  1650,   251,   245,
     244,   245,   246,   247,   250,  1906,  1659,   245,   252,   245,
    1663,   245,   250,  1666,   250,  1668,   250,  1670,  1671,   245,
    1673,   245,   245,   245,   250,   245,   250,   250,   250,    85,
     250,   244,   245,   246,   247,   252,   252,   250,   252,   252,
     252,   252,   252,   251,     2,   252,  1694,  1695,  1694,  1695,
     252,    85,   250,   250,   250,   250,   250,   250,   250,    17,
    1713,   250,   250,   250,  1717,   250,   250,  1720,   250,   250,
     250,  1724,    30,   250,   250,    33,     5,   252,    36,    37,
      38,   252,   250,   250,    42,    43,    44,   252,   252,   252,
     252,    58,   251,    51,   251,   250,   250,   250,   250,   250,
      43,   251,  1755,   252,  1757,  1758,   252,  1760,   252,    43,
      38,   251,    58,   252,   252,    63,    64,    48,    75,    75,
      75,    58,    70,    71,    72,    73,    74,    75,    76,    77,
     251,   251,    90,   252,   252,   250,  1789,   251,    96,  1787,
      47,  1787,   251,   251,    58,    75,   252,   252,    38,   251,
     251,   250,   250,     4,     4,    53,    53,  1810,  1811,  1812,
    1813,  1097,  1815,  1816,   461,   641,     5,  1820,  1769,  1432,
     944,  1824,  1979,   131,  1827,  1828,  1829,   940,  1831,   638,
     654,   943,  1835,  1836,  1244,    -1,    63,    64,  1841,    -1,
      -1,  1844,  1845,    70,    71,    72,    73,    74,    75,    76,
      77,  1849,    -1,  1849,  1852,    -1,  1852,    -1,  1861,    -1,
      -1,    -1,    -1,    -1,  1867,  1868,    -1,  1870,  1871,  1872,
      -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1893,    -1,    -1,    -1,  1897,    -1,  1899,  1900,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1906,    -1,
    1906,  1914,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1931,    -1,
      -1,    -1,  1935,    -1,    -1,  1938,  1939,    -1,   246,    -1,
    1943,    -1,    -1,   251,  1947,    -1,   244,   245,   246,   247,
      -1,    -1,   250,  1956,   252,    -1,   264,    -1,  1961,    -1,
      -1,   269,    -1,    -1,    -1,    -1,    -1,  1970,   276,    63,
      64,    -1,    -1,   105,    -1,   107,    70,    71,    72,    73,
      74,    75,    76,    77,  1987,  1988,    -1,    -1,    -1,    -1,
      -1,   299,    -1,   301,   126,   127,    -1,  2000,    -1,    -1,
      -1,    -1,  2005,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   244,   245,   246,
     247,    -1,    -1,    -1,   156,   252,    -1,   159,    -1,    -1,
     162,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
     348,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,   185,   186,   187,    -1,    -1,    -1,   191,
     192,   193,    -1,   195,    -1,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,   205,   206,   207,   208,    -1,    -1,   211,
      -1,   213,    -1,   215,    -1,    -1,   218,    -1,   220,    -1,
      -1,   223,    -1,    -1,   226,   227,    -1,   229,   230,    -1,
     232,    -1,   234,    -1,    63,    64,    -1,    -1,    -1,    -1,
     242,    70,    71,    72,    73,    74,    75,    76,    77,   251,
     252,    63,    64,    -1,   432,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   444,    -1,    -1,    -1,
      -1,   449,   450,    -1,   452,   453,   454,   455,   456,   457,
     244,   245,   246,   247,    -1,   463,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,    -1,
      -1,    -1,    -1,    -1,   512,   513,   514,   515,   516,    -1,
     518,    -1,   520,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,    -1,   530,   252,    -1,    -1,    -1,    -1,    -1,   537,
      -1,    -1,    63,    64,   542,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    90,    91,    92,    93,    94,
      -1,    -1,   244,   245,   246,   247,    -1,    -1,   616,   104,
     252,    -1,    -1,   621,    -1,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,   634,   635,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   647,
      -1,    -1,    -1,    -1,   652,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    -1,   663,   664,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   704,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,   244,   245,   246,   247,    -1,    -1,    -1,
      -1,   252,    -1,    -1,    81,    -1,    -1,    84,   244,   245,
     246,   247,    89,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      97,    -1,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,   760,   110,    -1,    -1,    -1,    -1,   115,    -1,
     768,   769,   770,   771,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,    -1,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,    -1,
     217,   218,   219,   220,    -1,   222,   223,    -1,   225,   226,
     227,    -1,   229,   230,   231,   232,   233,   234,   235,    -1,
      -1,    -1,    -1,    -1,   241,   242,    -1,   244,    -1,    -1,
      -1,    -1,    -1,    -1,   251,    -1,   253,    -1,    -1,    -1,
      63,    64,    -1,   911,   912,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   931,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   944,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   957,
      -1,    -1,    -1,    -1,    -1,   963,   964,    63,    64,    -1,
      -1,   969,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,   983,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,  1003,    -1,    -1,    -1,    -1,
    1008,  1009,  1010,    -1,    -1,  1013,    63,    64,  1016,    -1,
    1018,    -1,  1020,    70,    71,    72,    73,    74,    75,    76,
      77,  1029,    -1,    -1,    -1,  1033,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1041,    -1,  1043,    -1,    -1,    -1,    -1,
    1048,    -1,    -1,    -1,  1052,  1053,  1054,    -1,    -1,  1057,
    1058,    -1,    -1,  1061,    -1,    -1,  1064,    -1,    -1,  1067,
      -1,  1069,    -1,  1071,    -1,    -1,    -1,  1075,    -1,  1077,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1086,  1087,
    1088,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
    1098,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1106,  1107,
      -1,  1109,  1110,  1111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1122,  1123,    -1,  1125,    63,    64,
    1128,  1129,  1130,    -1,  1132,    70,    71,    72,    73,    74,
      75,    76,    77,  1141,    -1,    -1,  1144,    -1,   244,   245,
     246,   247,    -1,    -1,    -1,    -1,   252,    -1,  1156,    -1,
      -1,  1159,  1160,  1161,    -1,  1163,  1164,   244,   245,   246,
     247,    -1,    -1,    -1,  1172,   252,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,    -1,  1200,   250,  1202,  1203,  1204,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1216,    -1,
      -1,    -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1236,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1246,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1259,  1260,    -1,    -1,    -1,  1264,  1265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1273,  1274,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
     245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,    -1,
      -1,    -1,    -1,    47,    48,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,   126,   127,    -1,  1347,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    -1,    -1,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      63,    64,   162,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   186,   187,    -1,    -1,
      -1,   191,   192,   193,    -1,   195,    -1,   197,   198,   199,
      -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,    -1,
      -1,   211,    -1,   213,  1432,   215,    -1,    -1,   218,  1437,
     220,    -1,    -1,   223,  1442,    -1,   226,   227,    -1,   229,
     230,    -1,   232,    -1,   234,    -1,    -1,    -1,   244,   245,
     246,   247,   242,    -1,    -1,    -1,   252,    -1,    -1,    -1,
      -1,   251,   252,    -1,    -1,  1473,  1474,  1475,    -1,  1477,
      -1,    -1,    -1,    -1,    -1,    -1,  1484,    -1,    -1,    -1,
    1488,  1489,    -1,    -1,    -1,    -1,  1494,    -1,  1496,  1497,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1508,    -1,    -1,  1511,  1512,    -1,  1514,    -1,    -1,  1517,
      -1,    -1,    -1,    -1,  1522,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,  1531,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,  1549,    -1,  1551,    -1,    -1,    -1,    -1,    -1,  1557,
      -1,   244,   245,   246,   247,    -1,    -1,    -1,  1566,   252,
    1568,    -1,    -1,    -1,    -1,  1573,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1582,    -1,   310,    -1,    -1,    -1,
      -1,    -1,   316,    -1,  1592,    -1,    -1,  1595,    -1,   323,
     324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   335,   336,   337,   338,   339,   340,   341,    -1,    -1,
     344,   345,   346,   347,    -1,    -1,  1624,  1625,    -1,    -1,
    1628,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1636,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1644,  1645,    -1,    -1,
      -1,  1649,    -1,    -1,    63,    64,  1654,    -1,    -1,    -1,
    1658,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      63,    64,    -1,    -1,    -1,    -1,  1674,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,  1696,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,  1707,
      -1,    -1,   244,   245,   246,   247,    -1,   441,   442,   443,
     252,  1719,    -1,  1721,    -1,  1723,    -1,    -1,    -1,    -1,
      -1,  1729,    -1,    -1,  1732,    -1,  1734,    -1,   462,  1737,
    1738,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1747,
      -1,  1749,  1750,  1751,    -1,    -1,  1754,    -1,    -1,    -1,
      -1,    -1,  1760,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,  1772,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,  1782,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1790,  1791,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1818,    -1,    -1,  1821,    -1,    -1,    -1,  1825,  1826,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,  1864,    -1,  1866,    -1,
      -1,  1869,    -1,   244,   245,   246,   247,    -1,    -1,  1877,
      -1,   252,  1880,    -1,    -1,    -1,  1884,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1892,    -1,  1894,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1916,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,   657,    -1,    -1,  1934,   661,  1936,    -1,
      -1,   665,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   680,   681,   252,    -1,
      -1,  1959,    -1,    -1,   688,    -1,    -1,    -1,    -1,   693,
    1968,    -1,    -1,    -1,   698,    -1,   700,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,   712,    -1,
     714,   715,    -1,   717,   718,   719,    -1,    81,    -1,    -1,
      84,   725,    -1,    -1,    -1,    89,   730,    -1,    -1,    -1,
      -1,    -1,    -1,    97,   738,    -1,    -1,   101,   102,    -1,
      -1,   105,   746,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    63,
      64,    -1,   126,   127,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,   219,   220,    -1,   222,   223,
      -1,   225,   226,   227,    -1,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
     244,    -1,    -1,    -1,    63,    64,    -1,   251,    -1,   253,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   989,    -1,    30,    31,    -1,
      -1,    -1,    -1,   997,    -1,    -1,    -1,    -1,  1002,    -1,
    1004,    -1,  1006,  1007,    -1,    -1,    -1,  1011,  1012,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,    -1,   107,   244,   245,   246,   247,    -1,
      -1,    -1,   115,   252,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,   126,   127,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,  1099,  1100,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
    1124,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,   217,   218,   219,   220,    -1,   222,
     223,    -1,   225,   226,   227,    -1,   229,   230,   231,   232,
     233,   234,   235,    -1,    -1,    -1,    -1,    -1,   241,   242,
      -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,   251,    -1,
     253,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,    63,    64,    -1,   126,   127,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,   149,    -1,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,    -1,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,   217,   218,   219,   220,    -1,
     222,   223,    -1,   225,   226,   227,    -1,   229,   230,   231,
     232,   233,   234,   235,    -1,    -1,    -1,    -1,    -1,   241,
     242,    -1,   244,    -1,    -1,    -1,    -1,    -1,    -1,   251,
      -1,   253,    -1,    -1,    -1,  1469,    -1,    -1,  1472,    -1,
      -1,    -1,  1476,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1535,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,
      89,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    63,    64,    -1,   126,   127,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,   242,  1718,   244,    -1,    -1,  1722,    -1,
      -1,    -1,   251,   252,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,
      89,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    63,    64,    -1,   126,   127,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,   244,    -1,    -1,    -1,    -1,
      -1,    -1,   251,   252,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,
      89,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    63,    64,    -1,   126,   127,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,   244,    -1,    -1,    -1,    -1,
      -1,    -1,   251,   252,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,   151,   152,   153,   154,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,   244,    -1,    -1,    -1,     3,
       4,     5,   251,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    -1,    -1,    -1,
     154,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,   219,   220,    -1,   222,   223,
      -1,   225,   226,   227,    -1,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
     244,    -1,    -1,    -1,     3,     4,     5,   251,     7,     8,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,   151,    -1,    -1,   154,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,   244,    -1,    -1,    -1,     3,
       4,     5,   251,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,   111,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,   219,   220,    -1,   222,   223,
      -1,   225,   226,   227,    -1,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
     244,    -1,    -1,    -1,     3,     4,     5,   251,     7,     8,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,   244,    -1,    -1,    -1,     3,
       4,     5,   251,     7,     8,     9,    10,    -1,    -1,    -1,
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
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,   219,   220,    -1,   222,   223,
      -1,   225,   226,   227,    -1,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
     244,    -1,    -1,    -1,     3,     4,     5,   251,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,   244,    -1,    -1,    -1,     3,
       4,     5,   251,     7,     8,     9,    10,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,   219,   220,    -1,   222,   223,
      -1,   225,   226,   227,    -1,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
     244,    -1,    -1,    -1,     3,     4,     5,   251,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,   111,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,   244,    -1,    -1,    -1,     3,
       4,     5,   251,     7,     8,     9,    10,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,   219,   220,    -1,   222,   223,
      -1,   225,   226,   227,    -1,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
     244,    -1,    -1,    -1,     3,     4,     5,   251,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,
      89,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,   112,   113,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,   244,    -1,    -1,    -1,     3,
       4,     5,   251,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    30,    31,    -1,    -1,
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
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,   219,   220,    -1,   222,   223,
      -1,   225,   226,   227,    -1,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
     244,    -1,    -1,    -1,     3,     4,     5,   251,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     159,    -1,    -1,   162,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,   244,    -1,    -1,    -1,     3,
       4,     5,   251,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    30,    31,    -1,    -1,
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
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,   219,   220,    -1,   222,   223,
      -1,   225,   226,   227,    -1,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
     244,    -1,    -1,    -1,     3,     4,     5,   251,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     159,    -1,    -1,   162,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,   244,    -1,    -1,    -1,     3,
       4,     5,   251,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    30,    31,    -1,    -1,
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
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,   219,   220,    -1,   222,   223,
      -1,   225,   226,   227,    -1,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
     244,    -1,    -1,    -1,     3,     4,     5,   251,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     159,    -1,    -1,   162,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,   244,    -1,    -1,    -1,     3,
       4,     5,   251,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    30,    31,    -1,    -1,
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
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,   219,   220,    -1,   222,   223,
      -1,   225,   226,   227,    -1,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
     244,    -1,    -1,    -1,     3,     4,     5,   251,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     159,    -1,    -1,   162,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,   244,    -1,    -1,    -1,     3,
       4,     5,   251,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    30,    31,    -1,    -1,
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
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,   219,   220,    -1,   222,   223,
      -1,   225,   226,   227,    -1,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
     244,    -1,    -1,    -1,     3,     4,     5,   251,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     159,    -1,    -1,   162,    -1,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,    -1,    -1,
      -1,    -1,   241,   242,    -1,   244,    -1,    -1,    -1,     3,
       4,     5,   251,     7,     8,     9,    10,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,   245,   246,
     247,    -1,    -1,    -1,    -1,   252,    30,    31,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,    -1,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,    -1,   217,   218,   219,   220,    -1,   222,   223,
      -1,   225,   226,   227,    -1,   229,   230,   231,   232,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,   241,   242,    -1,
     244,    -1,    -1,    -1,     3,     4,     5,   251,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,
      -1,    -1,    -1,    10,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,    31,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,    -1,   217,   218,
     219,   220,    -1,   222,   223,    -1,   225,   226,   227,    -1,
     229,   230,   231,   232,   233,   234,   235,    -1,   105,    -1,
     107,    -1,   241,   242,    -1,   244,    -1,    -1,    -1,    -1,
      -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    31,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,   186,
     187,    -1,    -1,    -1,   191,   192,   193,    -1,   195,    -1,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,   205,   206,
     207,   208,    -1,    -1,   211,    -1,   213,    -1,   215,    -1,
      -1,   218,    -1,   220,    -1,    -1,   223,    -1,    -1,   226,
     227,    -1,   229,   230,    -1,   232,    -1,   234,   105,    -1,
     107,    -1,    -1,    -1,   111,   242,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   251,   252,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      31,    -1,   159,    -1,    -1,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,   186,
     187,    -1,    -1,    -1,   191,   192,   193,    -1,   195,    -1,
     197,   198,   199,    -1,    -1,    -1,    -1,   204,   205,   206,
     207,   208,    -1,    -1,   211,    -1,   213,    -1,   215,    -1,
      -1,   218,    -1,   220,    -1,    -1,   223,    -1,    -1,   226,
     227,    -1,   229,   230,   105,   232,   107,   234,    -1,    -1,
     111,    -1,    -1,    -1,    -1,   242,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   251,   126,   127,    -1,    -1,    -1,
       5,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    31,    -1,   159,    -1,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   185,   186,   187,    -1,    -1,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,    -1,
      -1,    -1,    -1,   204,   205,   206,   207,   208,    -1,    -1,
     211,    -1,   213,    -1,   215,    -1,    -1,   218,    -1,   220,
      -1,    -1,   223,    -1,    -1,   226,   227,    -1,   229,   230,
     105,   232,   107,   234,    -1,    -1,   111,    -1,    -1,    -1,
      -1,   242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     251,   126,   127,    -1,    -1,    -1,     5,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    31,    -1,   159,    -1,    -1,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     185,   186,   187,    -1,    -1,    -1,   191,   192,   193,    -1,
     195,    -1,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
     205,   206,   207,   208,    -1,    -1,   211,    -1,   213,    -1,
     215,    -1,    -1,   218,    -1,   220,    -1,    -1,   223,    -1,
      -1,   226,   227,    -1,   229,   230,   105,   232,   107,   234,
      -1,    -1,   111,    -1,    -1,     5,    -1,   242,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,   251,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,   185,   186,   187,    -1,
      -1,    -1,   191,   192,   193,    -1,   195,    -1,   197,   198,
     199,    -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,
      -1,    -1,   211,    -1,   213,   105,   215,   107,    -1,   218,
      -1,   220,    -1,    -1,   223,    -1,    -1,   226,   227,    -1,
     229,   230,    -1,   232,    -1,   234,   126,   127,    -1,    -1,
      -1,     5,    -1,   242,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,   251,    -1,   144,   145,   146,   147,   148,    -1,
     150,    -1,    -1,    -1,    -1,    -1,   156,    31,    -1,   159,
      -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   186,   187,    -1,    -1,
      -1,   191,   192,   193,    -1,   195,    -1,   197,   198,   199,
      -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,    -1,
      -1,   211,    -1,   213,    -1,   215,    -1,    -1,   218,    -1,
     220,    -1,    -1,   223,    -1,    -1,   226,   227,    -1,   229,
     230,   105,   232,   107,   234,    -1,   244,   245,   246,   247,
      -1,    -1,   242,     5,   252,    -1,    -1,    -1,    10,    -1,
      -1,   251,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
     144,   145,   146,   147,   148,    -1,   150,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,   185,   186,   187,    -1,    -1,    -1,   191,   192,   193,
      -1,   195,    -1,   197,   198,   199,    -1,    -1,    -1,    -1,
     204,   205,   206,   207,   208,    97,    -1,   211,    -1,   213,
      -1,   215,    -1,   105,   218,   107,   220,    -1,    -1,   223,
      -1,    -1,   226,   227,    -1,   229,   230,    -1,   232,    -1,
     234,    -1,    -1,    -1,   126,   127,    -1,    -1,   242,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,    -1,    -1,    -1,
       5,    -1,    -1,    -1,   156,    10,    -1,   159,    -1,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,   185,   186,   187,    -1,    -1,    -1,   191,
     192,   193,    -1,   195,    -1,   197,   198,   199,    -1,    -1,
      -1,    -1,   204,   205,   206,   207,   208,    -1,    -1,   211,
      -1,   213,    -1,   215,    -1,    -1,   218,    -1,   220,    -1,
      -1,   223,    -1,    -1,   226,   227,    -1,   229,   230,    -1,
     232,    -1,   234,   244,   245,   246,   247,    -1,    -1,    -1,
     242,   252,    97,    -1,    -1,    -1,    -1,    -1,    -1,   251,
     105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,     5,
      -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     185,   186,   187,    -1,    -1,    -1,   191,   192,   193,    -1,
     195,    -1,   197,   198,   199,    -1,    -1,    -1,    -1,   204,
     205,   206,   207,   208,    -1,    -1,   211,    -1,   213,   105,
     215,   107,    -1,   218,    -1,   220,    -1,    -1,   223,    -1,
      -1,   226,   227,    -1,   229,   230,    -1,   232,    -1,   234,
     126,   127,    -1,    -1,    -1,     5,    -1,   242,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,   251,    -1,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    31,    -1,   159,    -1,    -1,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,
     186,   187,    -1,    -1,    -1,   191,   192,   193,    -1,   195,
      -1,   197,   198,   199,    -1,    -1,    -1,    -1,   204,   205,
     206,   207,   208,    -1,    -1,   211,    -1,   213,    -1,   215,
      -1,    -1,   218,    -1,   220,    -1,    -1,   223,    -1,    -1,
     226,   227,    -1,   229,   230,   105,   232,   107,   234,   244,
     245,   246,   247,    -1,    -1,    -1,   242,   252,    -1,    -1,
      -1,    63,    64,    -1,    -1,   251,   126,   127,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   185,   186,   187,    -1,    -1,
      -1,   191,   192,   193,    -1,   195,    -1,   197,   198,   199,
      -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,    -1,
      -1,   211,    -1,   213,    -1,   215,    -1,    -1,   218,    -1,
     220,    -1,    -1,   223,    -1,    -1,   226,   227,    -1,   229,
     230,    -1,   232,    -1,   234,    -1,    -1,     4,     5,     6,
      -1,    -1,   242,    -1,    11,    -1,    -1,    -1,    15,    -1,
      17,   251,    19,    20,    21,    22,    23,    24,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,   244,   245,   246,   247,    -1,    -1,    -1,    -1,
     252,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    94,    95,    96,
      -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,   106,
      -1,   108,   109,    -1,    -1,    -1,    -1,   114,   115,   244,
     245,   246,   247,    -1,   121,   250,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
     157,   158,   159,    -1,    -1,    -1,   163,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,   186,
     187,    -1,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,   212,    -1,    -1,    -1,   216,
      -1,     4,     5,     6,   221,    -1,    -1,   224,    11,    -1,
      -1,   228,    15,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    -1,
      -1,    94,    95,    96,    -1,    98,    99,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,   108,   109,    -1,    -1,    -1,
      -1,   114,   115,    -1,    -1,    -1,    -1,    -1,   121,    -1,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    -1,
      -1,   144,   145,   146,   147,   148,   149,    -1,    -1,    -1,
      -1,    -1,    -1,   156,   157,   158,   159,    -1,    -1,    -1,
     163,   244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   185,   186,   187,    -1,    -1,    -1,    -1,   192,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   212,
      -1,    -1,    -1,   216,    -1,     4,     5,     6,   221,    -1,
      -1,   224,    11,    -1,    -1,   228,    15,    -1,    17,    -1,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    38,
      -1,    -1,    -1,    42,    43,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    57,    63,
      64,    -1,    61,    62,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    -1,    -1,    94,    95,    96,    -1,    98,
      99,   100,    -1,    -1,   103,    -1,    -1,   106,    -1,   108,
     109,    -1,    -1,    -1,    -1,   114,   115,    -1,    -1,    -1,
      -1,    -1,   121,    -1,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,    -1,    -1,    -1,   163,   244,   245,   246,   247,    63,
      64,    -1,    -1,   252,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   185,   186,   187,    63,
      64,    -1,    -1,   192,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   212,    -1,    -1,    -1,   216,    -1,    -1,
      -1,    -1,   221,    63,    64,   224,    -1,    -1,    -1,   228,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     244,   245,   246,   247,    63,    64,    -1,    -1,   252,    -1,
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
     244,   245,   246,   247,    63,    64,    -1,    -1,   252,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     244,   245,   246,   247,    63,    64,    -1,    -1,   252,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   244,   245,   246,   247,    63,    64,
      -1,    -1,   252,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,    -1,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,    -1,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    63,
      64,   250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   244,   245,   246,   247,    63,
      64,   250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   244,
     245,   246,   247,    63,    64,   250,    -1,    -1,    -1,    -1,
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
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   244,   245,   246,   247,    63,
      64,   250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   244,   245,   246,   247,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
     245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
     245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
     245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,   245,   246,   247,    63,    64,
     250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   244,   245,   246,   247,    63,
      64,   250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   244,
     245,   246,   247,    63,    64,   250,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   244,   245,   246,   247,    63,
      64,   250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    63,
      64,   250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   244,   245,   246,   247,    63,    64,
     250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
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
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   244,
     245,   246,   247,    63,    64,   250,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   244,   245,   246,   247,    63,
      64,   250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    63,
      64,   250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   244,   245,   246,   247,    63,
      64,   250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   244,   245,   246,   247,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
     245,   246,   247,    63,    64,   250,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
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
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   244,   245,   246,   247,    63,    64,
     250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    63,
      64,   250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   244,   245,   246,   247,    63,
      64,   250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   244,
     245,   246,   247,    63,    64,   250,    -1,    -1,    -1,    -1,
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
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   244,   245,   246,   247,    63,
      64,   250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   244,   245,   246,   247,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
     245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
     245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,    -1,
     250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
     245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   244,   245,   246,   247,    63,    64,
     250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   244,   245,   246,   247,    63,
      64,   250,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     244,   245,   246,   247,    63,    64,   250,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   244,
     245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   244,   245,   246,   247,    -1,
      -1,   250,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     244,   245,   246,   247,    -1,    -1,   250
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   236,   237,   238,   239,   240,   255,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   114,   115,
     121,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     144,   145,   146,   147,   148,   149,   156,   157,   158,   159,
     163,   185,   186,   187,   192,   212,   216,   221,   224,   228,
     256,   257,   260,   261,   268,   269,   271,   272,   276,   288,
     289,   294,   300,   307,   315,   323,   326,   330,   333,   339,
       3,     4,     5,     7,     8,     9,    10,    30,    31,    63,
      64,    65,    66,    67,    68,    69,    81,    84,    89,   101,
     102,   105,   107,   115,   122,   126,   127,   144,   145,   146,
     147,   148,   149,   156,   159,   162,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   217,   218,
     219,   220,   222,   223,   225,   226,   227,   229,   230,   231,
     232,   233,   234,   235,   241,   242,   244,   251,   274,   275,
     277,   283,   285,   288,   289,   144,   145,   146,   147,   251,
     274,   260,   288,   289,   294,     0,    75,   251,    75,   251,
     308,   327,   331,     4,     7,   286,   286,   286,    34,   277,
     262,   263,   274,   290,   291,   290,   274,    28,     7,   316,
     324,   277,    58,    60,    61,   253,   370,   266,   274,   277,
       4,     5,   287,   277,   274,   277,   274,   277,     4,     5,
     350,   351,    10,   244,   245,   284,   285,   352,   286,    89,
      97,   253,   274,   277,   371,    89,    97,   110,   371,   371,
      81,    82,    88,   111,   277,   282,    12,    53,   282,   111,
     282,    59,    89,    90,    91,    96,    95,   277,   269,   276,
     274,   274,   274,   110,   282,    90,    91,    92,    93,    94,
     104,   110,   111,   116,   117,   118,   119,   120,   163,   282,
     282,   111,   282,   111,   282,    95,   111,   282,    61,    95,
     111,   142,   282,   282,    22,    61,   111,   282,   111,   282,
     111,   282,   111,   274,   274,   274,    61,   111,   111,   142,
     143,   282,   111,   282,   282,   111,   282,   282,   282,    95,
     142,   143,   151,   154,   282,    95,   142,   143,   154,   282,
      95,   142,   143,   151,   152,   153,   154,   282,    61,    95,
     142,   143,   150,   154,   282,   111,   282,   111,   282,   111,
     274,   111,   274,   111,   274,   160,   112,   143,   277,   251,
     251,   251,   251,   251,   274,   371,   274,   274,   274,    44,
     258,    92,    93,   104,    75,    75,    24,   251,   251,   251,
     251,   277,   251,   251,   251,   251,   251,   251,   112,   113,
     251,   251,   251,   251,   112,   251,   112,   155,   112,   155,
     112,   113,   155,   112,   113,   155,   112,   113,   155,   112,
     113,   155,   112,   112,   162,   161,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   277,   274,   277,
      70,    71,    72,    73,    74,    75,    76,   245,    44,    63,
      64,    70,    71,    72,    73,    74,    75,    76,    77,   244,
     245,   246,   247,   274,    44,    44,    44,   277,   290,   274,
     290,     4,   277,   257,    35,    36,    20,    21,     4,     5,
     301,   302,     4,     5,   303,   304,   274,   277,   292,   293,
     274,   277,   318,   257,   334,   340,   251,    58,   251,     4,
       7,   251,   274,   277,   353,    58,    60,    61,   253,   355,
     368,   251,   251,   250,   250,   250,   251,   251,   250,   285,
     285,   250,   277,   274,   277,    11,   250,   250,   282,   274,
     274,   274,   250,   282,   267,    12,   250,   270,   274,   250,
     282,    12,   282,   270,   270,   270,   282,   282,   282,   282,
     282,   282,   282,   274,   274,   282,   282,   282,   282,   277,
     270,   270,   274,   250,   274,   250,   274,   274,   270,   274,
     274,   274,   274,   270,   250,   274,   274,   274,   270,   274,
     270,   274,   250,   274,   250,   250,   250,   274,   274,   274,
     274,   274,   270,   274,   270,   270,   274,   270,   270,   270,
     274,   274,   274,   274,   274,   270,   274,   274,   274,   274,
     270,   274,   274,   274,   274,   274,   274,   274,   270,   274,
     274,   274,   150,   274,   274,   274,   270,   274,   250,   274,
     250,   274,   250,   274,   250,   274,   250,   274,   274,   274,
     250,     5,   273,   273,   273,   252,   277,   274,   250,   250,
     250,   250,    43,   282,   282,   282,   277,   274,   295,   290,
     290,   277,   277,   277,   277,   277,   277,    97,   274,   371,
     371,   274,     4,     5,   280,   281,   280,   281,   282,   277,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   150,   274,   274,   274,
     274,   251,   274,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   371,   277,   277,   277,   277,   277,   277,
     277,   277,   252,   277,   274,   274,   274,   274,   274,   277,
     277,   274,   277,   252,   277,   277,   274,   277,   274,   277,
     274,   274,   252,   274,   252,   274,   252,   274,   252,   274,
     274,   274,   274,   277,   274,   274,   274,   274,   274,   274,
     274,   371,   274,   290,   290,   274,   277,   274,   274,   274,
     274,   274,   252,   252,   274,   273,   274,   273,   274,   274,
     274,   252,   252,   274,   274,   274,   274,   274,   274,   274,
     274,   279,   278,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   252,   252,    75,   328,    14,
      16,    18,    41,    44,    49,   332,   264,   265,   251,   251,
     250,   251,   251,   250,   250,    43,   317,    14,    16,    18,
      41,    44,    49,   325,    46,   257,   277,   251,   274,   277,
      51,   354,   249,   250,   251,    58,   251,     4,     7,   251,
      10,   369,   290,   290,     4,     5,   277,   277,   290,   290,
     351,    10,   284,   250,    86,    87,    97,   274,   277,   270,
     250,   277,   355,   282,   250,   274,   282,   270,   277,   277,
     282,   250,   270,   250,   270,   250,   270,   270,   250,   250,
     250,   270,   270,   250,   282,   282,   250,   274,   250,   274,
     250,   282,   250,   250,   250,   282,   274,   250,   250,   250,
     282,   250,   282,   250,   274,   250,   277,   274,   274,   250,
     250,   250,   250,   250,   282,   250,   282,   282,   250,   282,
     282,   282,   250,   250,   250,   282,   250,   250,   250,   282,
     250,   250,   250,   250,   250,   282,   250,   250,   274,   250,
     250,   250,   282,   250,   274,   250,   274,   250,   274,   250,
     274,   250,   274,   250,   277,   251,   250,   250,   250,   252,
     252,   274,   277,   274,   277,   277,   277,   259,   250,   270,
     270,     4,     5,   299,   252,   252,   250,   250,   252,   250,
     250,   250,   252,   250,   252,   250,   252,   250,   251,   251,
     252,   252,   250,   250,   270,   250,   250,   252,   250,   250,
     250,   274,   250,   250,   274,   252,   252,   252,   252,   252,
     252,   250,   252,   252,   250,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   250,   252,   252,   250,
     250,   250,   252,   250,   250,   252,   250,   252,   252,   252,
     252,   252,   250,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   250,   250,   250,   250,   252,   252,
     252,   252,   252,   250,   252,   252,   252,   252,   252,   252,
     250,   252,   250,   250,   250,   250,   250,   252,   250,   250,
     252,   250,   252,   252,   277,   277,   309,   257,   277,   286,
     372,   286,   373,   290,   290,   302,   290,   290,   304,   293,
      43,   319,   335,    49,    50,   341,   250,   277,   250,   252,
     252,   251,   274,   274,   277,   277,   251,   274,   356,   357,
     277,     4,     5,   347,   349,   252,   252,   251,   251,   250,
     250,   252,   252,   277,    85,    85,   250,   250,   282,   274,
     274,   250,   282,   250,   250,   250,   274,   282,   277,   282,
     274,   282,   282,   274,   277,   277,   277,   282,   282,   277,
     250,   250,   277,   250,   277,   250,   274,   277,   250,   274,
     274,   274,   250,   250,   274,   274,   274,   277,   250,   274,
     250,   277,   250,   274,   250,   274,   274,   277,   274,   277,
     250,   274,   250,   250,   277,   250,   250,   250,   274,   277,
     274,   277,   277,   250,   274,   277,   277,   250,   274,   274,
     277,   274,   274,   277,   250,   274,   277,   250,   277,   274,
     277,   250,   274,   250,   277,   250,   274,   277,   250,   274,
     250,   274,   250,   274,   250,   290,   277,   277,   277,   250,
     250,   261,   277,   282,   282,   296,   277,   277,   277,   277,
     277,   274,    97,   274,   274,   252,   252,   277,   277,   282,
     277,   274,   277,   277,   277,   277,   274,   252,   277,   277,
     277,   277,   277,   277,   277,   277,   274,   277,   274,   274,
     274,   274,   274,   277,   277,   277,   277,   281,   274,   281,
     274,   274,   277,    16,    44,   329,   250,   250,   252,   252,
     252,   252,    39,    40,   321,   257,   277,   250,   274,    58,
     274,   354,   250,   277,   250,   252,   347,   347,   252,   251,
     251,   250,   290,   290,   277,   277,   250,   371,   371,   274,
     274,   250,   250,   274,   277,   277,   274,   250,   250,   270,
     250,   250,   270,   250,   250,   250,   270,   250,   250,   274,
     274,   274,   274,   274,   250,   274,   274,   250,   250,   250,
     274,   250,   274,   274,   250,   274,   250,   250,   274,   250,
     274,   274,   274,   274,   274,   250,   274,   274,   250,   250,
     274,   250,   250,   277,   250,   274,   274,   250,   274,   250,
     250,   274,   250,   274,   250,   274,   250,   274,   252,   252,
     252,   250,   252,   274,   274,   270,   251,   252,   252,   252,
     252,   252,   252,   252,   250,   252,   252,   252,   252,   270,
     250,   250,   252,   252,   252,   252,   252,   250,   252,   252,
     252,   250,   252,   252,   252,   250,   250,   252,   250,   252,
     252,   252,   250,   250,   252,   250,   252,   252,   250,   252,
     252,   252,    12,   286,   286,   318,    43,    38,   336,   252,
     277,   252,   251,   250,   277,   250,   274,    58,   363,   358,
     290,   290,   348,   252,   252,   274,   274,   274,   250,   250,
     250,   274,   274,   282,   274,   274,   282,   277,   277,   277,
     282,   277,   274,   250,   250,   250,   250,   277,   250,   250,
     274,   277,   277,   250,   274,   250,   250,   277,   277,   274,
     277,   250,   274,   250,   250,   250,   250,   250,   274,   250,
     250,   274,   277,   274,   250,   277,   277,   277,   250,   250,
     277,   274,   274,   250,   274,   277,   250,   274,   250,   274,
      75,    75,   277,    75,   250,   282,     4,     5,   305,   306,
     274,   277,   274,   277,   277,   274,   274,   277,   277,   274,
     277,   274,   274,   277,   320,   322,    48,   343,    60,    61,
     252,    58,   277,   274,   252,   277,   252,   251,   369,   347,
     252,   252,   347,   250,   274,   274,   274,   250,   270,   250,
     250,   250,   270,   250,   250,   274,   277,   277,   274,   250,
     277,   274,   250,   274,   250,   274,   277,   250,   250,   274,
     274,   277,   277,   274,   274,   277,   274,   250,   277,   250,
     250,   250,   277,   274,   250,   250,   274,   250,   250,   274,
     250,   274,   274,   274,   252,   274,   277,   251,   251,   250,
     252,   252,   250,   252,   252,   252,   252,   252,   252,   252,
     252,   252,    13,   313,   257,   257,   277,    47,   342,   251,
     251,   250,   252,    60,    61,   359,   252,    58,   364,   277,
     347,   274,   274,   282,   277,   274,   277,   282,   277,   274,
     250,   250,   250,   250,   277,   250,   250,   277,   250,   277,
     250,   250,   277,   277,   250,   250,   250,   250,   250,   250,
     277,   250,   277,   277,   277,   250,   250,   277,   274,   274,
     274,   250,   274,   277,   250,    75,   252,   252,   306,   297,
     277,   277,   310,    46,   346,   257,   337,   274,   277,   277,
     365,   251,   369,   360,   251,   369,   250,   250,   250,   250,
     250,   250,   250,   274,   274,   274,   274,   250,   274,   274,
     250,   277,   274,   277,   250,   274,   277,   277,   274,   274,
     274,   274,   250,   250,   250,   274,   274,   250,   274,   250,
     250,   274,   274,   257,   252,   257,   344,    14,    16,    18,
      41,    44,    49,   338,   250,   252,   250,   252,   369,   274,
     347,   369,   277,   347,   277,   274,   274,   277,   274,   274,
     274,   250,   277,   277,   250,   250,   250,   277,   250,   250,
     277,   274,   277,   250,   274,   274,   274,   250,    25,    44,
     298,   311,   257,   274,   277,   347,   250,   252,   347,   250,
     252,   250,   274,   277,   274,   277,   274,   274,   250,   274,
     250,   274,    14,    16,    18,    41,    44,    49,   312,   345,
     252,   252,   274,   366,   277,   361,   274,   250,   250,   277,
     274,     4,   314,   343,   252,   369,   252,   369,   274,   274,
     250,   367,   347,   362,   347,   250,   274,   369,   369,   274,
     347,   347
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   254,   255,   255,   255,   255,   255,   256,   257,   258,
     259,   257,   260,   260,   260,   260,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   262,   261,   263,   261,   261,   261,   261,   261,   261,
     261,   264,   261,   265,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   266,   261,   267,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   268,   268,   268,   268,   268,   269,   269,
     269,   269,   269,   269,   270,   270,   271,   271,   271,   271,
     271,   272,   272,   273,   273,   274,   274,   274,   274,   274,
     274,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   276,   276,   278,   277,
     279,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   280,   281,   282,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   284,   284,   284,   285,   285,   285,   285,
     286,   286,   287,   287,   287,   287,   288,   289,   291,   290,
     292,   292,   292,   293,   293,   295,   296,   297,   294,   298,
     298,   299,   299,   300,   300,   300,   300,   301,   301,   302,
     302,   302,   302,   303,   303,   304,   304,   304,   304,   305,
     305,   305,   306,   306,   306,   306,   308,   309,   310,   311,
     307,   312,   312,   312,   312,   312,   312,   313,   313,   314,
     314,   316,   315,   317,   317,   318,   318,   319,   320,   319,
     321,   322,   321,   324,   323,   325,   325,   325,   325,   325,
     325,   327,   328,   326,   329,   329,   331,   330,   332,   332,
     332,   332,   332,   332,   334,   335,   336,   337,   333,   338,
     338,   338,   338,   338,   338,   340,   339,   341,   341,   342,
     342,   343,   344,   345,   343,   346,   346,   347,   348,   347,
     349,   349,   349,   349,   350,   350,   351,   351,   351,   351,
     352,   352,   352,   352,   353,   353,   353,   353,   353,   354,
     354,   354,   356,   355,   357,   355,   358,   355,   359,   355,
     360,   355,   361,   355,   362,   355,   363,   355,   364,   355,
     365,   355,   366,   355,   367,   355,   368,   355,   369,   369,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   371,   371,   372,   372,   373,   373
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
      10,     9,    11,    12,    13,    11,     3,     6,     7,     3,
      11,     2,     3,     2,     2,     1,     1,     3,     4,     4,
       4,     4,     4,     4,     1,     1,     2,     1,     2,     2,
       8,     6,     6,     0,     1,     1,     2,     2,     3,    10,
       8,     8,     8,     3,     1,     1,     6,     4,     4,     6,
       6,     4,     6,     1,     4,     1,     1,     1,     1,     3,
       3,     6,     6,     8,     6,     4,     6,     8,     4,     1,
       3,     4,     4,     4,     4,     4,     4,     4,     6,     8,
       4,     4,     4,     4,     4,     6,     1,     3,     1,     3,
       4,     3,     3,     3,     3,     5,     5,     5,     7,     3,
       4,     5,     2,     6,     6,     4,     6,     4,     6,    10,
       4,     4,     4,     8,     6,     4,     3,     3,     0,     4,
       0,     4,     2,     3,     3,     3,     3,     3,     3,     3,
       4,     6,     1,     4,     4,     6,     6,     1,     1,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     4,     4,     4,
       4,     4,     4,     6,     4,     4,     6,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     4,     3,     6,
       6,     4,     4,     4,     4,     6,     6,     8,     6,     8,
       4,     4,     4,     8,     4,     4,     4,     4,     1,     3,
       4,     1,     3,     4,     1,     3,     4,     1,     3,     6,
       6,     4,     6,     6,     6,     4,     8,     6,     8,     6,
       4,     4,     4,     6,     6,     6,     8,     4,     2,     5,
       3,     3,     3,     3,     3,     3,     3,     4,     3,     5,
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

  case 207: /* statement: tBITMAP expression ',' expression ',' string_expression  */
                                                            {add_command(cYABBITMAP);}
    break;

  case 208: /* statement: tBITMAP tGET string_expression ',' string_expression ',' string_expression  */
                                                                               {add_command(cYABBITMAPGET);}
    break;

  case 209: /* statement: tBITMAP tREMOVE string_expression  */
                                      {add_command(cYABBITMAPREMOVE);}
    break;

  case 210: /* statement: tDRAW tBITMAP expression ',' expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                              {add_command(cYABBITMAPDRAW);}
    break;

  case 211: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 212: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 213: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 214: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 215: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 216: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 217: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 218: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 219: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 220: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 221: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 222: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 223: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 224: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 225: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 226: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 227: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 228: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 229: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 230: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 231: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 232: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 233: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 234: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 235: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 236: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 237: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 238: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 239: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 240: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 241: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 242: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 243: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 246: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 247: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 248: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 249: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 250: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 251: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 252: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 253: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 254: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 255: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 257: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 258: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 259: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 261: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 262: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 263: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 264: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 265: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 266: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 267: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 268: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 269: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 270: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 271: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 272: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 273: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 274: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 275: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 276: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 277: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 278: /* string_function: tSTRING2 '(' expression ',' string_expression ')'  */
                                                      {create_function(fSTRING);}
    break;

  case 279: /* string_function: tREPLACE '(' string_expression ',' string_expression ',' string_expression ')'  */
                                                                                    {create_function(fREPLACE);}
    break;

  case 280: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 281: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 282: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 283: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 284: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 285: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 286: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 287: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 288: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 289: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 290: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 291: /* string_function: tTEXTCONTROL tGET string_expression  */
                                        {create_function(fYABTEXTCONTROLGET);}
    break;

  case 292: /* string_function: tTEXTEDIT tGET string_expression  */
                                     {create_function(fYABTEXTEDITGET);}
    break;

  case 293: /* string_function: tTEXTCONTROL tGETS string_expression  */
                                                         {create_function(fYABTEXTCONTROLGET);}
    break;

  case 294: /* string_function: tTEXTEDIT tGETS string_expression  */
                                                      {create_function(fYABTEXTEDITGET);}
    break;

  case 295: /* string_function: tLISTBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABLISTBOXGET);}
    break;

  case 296: /* string_function: tDROPBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABDROPBOXGET);}
    break;

  case 297: /* string_function: tTREEBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABTREEBOXGET);}
    break;

  case 298: /* string_function: tCOLUMNBOX tGETS string_expression ',' expression ',' expression  */
                                                                                     {create_function(fYABCOLUMNBOXGET);}
    break;

  case 299: /* string_function: tCALENDAR tGET string_expression  */
                                                     {create_function(fYABCALENDARGET);}
    break;

  case 300: /* string_function: tTRANSLATE '(' string_expression ')'  */
                                         {create_function(fYABTRANSLATE);}
    break;

  case 301: /* string_function: tMENU tTRANSLATE '(' string_expression ')'  */
                                               {create_function(fYABMENUTRANSLATE);}
    break;

  case 302: /* string_function: tCLIPBOARD tPASTE  */
                      {create_function(fYABCLIPBOARDPASTE);}
    break;

  case 303: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 304: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 305: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 306: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 307: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 308: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 309: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 310: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 311: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 312: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 313: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 314: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 315: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 316: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 317: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 318: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 319: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 320: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 321: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 322: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 323: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 324: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 325: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 326: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 327: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 328: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 329: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 330: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 331: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 332: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 333: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 334: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 335: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 336: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 337: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 338: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 339: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 340: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 341: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 342: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 343: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 344: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 345: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 346: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 347: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 348: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 349: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 350: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 351: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 354: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 355: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 357: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 358: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 359: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 360: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 361: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 362: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 363: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 364: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 365: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 366: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 367: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 368: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 369: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 370: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 371: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 372: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 373: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 374: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 375: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 376: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 377: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 378: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 379: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 380: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 381: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 382: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 383: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 384: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 385: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 386: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 387: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 388: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 389: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 390: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 391: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 392: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 393: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 394: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 395: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 396: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 397: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 398: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 399: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 400: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 401: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 402: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 403: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 404: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 405: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 406: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 407: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 408: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 409: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 410: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 411: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 412: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 413: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 414: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 415: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 416: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 417: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 418: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 419: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 420: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 421: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 422: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 423: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 424: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 425: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 426: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 427: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 428: /* function: tWINDOW tCOUNT  */
                   {create_function(fYABNUMWINDOWS);}
    break;

  case 429: /* function: tWINDOW tGET string_expression ',' string_expression  */
                                                         {create_function(fYABWINDOWGET);}
    break;

  case 430: /* function: tLISTBOX tCOUNT string_expression  */
                                                      {create_function(fYABLISTBOXCOUNT);}
    break;

  case 431: /* function: tLISTBOX tGET string_expression  */
                                                    {create_function(fYABLISTBOXSELECTED);}
    break;

  case 432: /* function: tDROPBOX tCOUNT string_expression  */
                                                      {create_function(fYABDROPBOXCOUNT);}
    break;

  case 433: /* function: tDROPBOX tGET string_expression  */
                                                    {create_function(fYABDROPBOXSELECTED);}
    break;

  case 434: /* function: tTREEBOX tCOUNT string_expression  */
                                                      {create_function(fYABTREEBOXCOUNT);}
    break;

  case 435: /* function: tTREEBOX tGET string_expression  */
                                                    {create_function(fYABTREEBOXSELECTED);}
    break;

  case 436: /* function: tCOLUMNBOX tCOUNT string_expression  */
                                                        {create_function(fYABCOLUMNBOXCOUNT);}
    break;

  case 437: /* function: tCOLUMNBOX tCOUNT tCOLUMN string_expression  */
                                                                {create_function(fYABCOLUMNBOXCOUNTCOLUMNS);}
    break;

  case 438: /* function: tCOLUMNBOX tGET string_expression  */
                                                      {create_function(fYABCOLUMNBOXSELECTED);}
    break;

  case 439: /* function: tCOLORCONTROL tGET string_expression ',' string_expression  */
                                                                               {create_function(fYABCOLORCONTROLGET);}
    break;

  case 440: /* function: tDRAW tGET string_expression ',' string_expression  */
                                                       {create_function(fYABDRAWGET);}
    break;

  case 441: /* function: tDRAW tGET string_expression ',' string_expression ',' string_expression  */
                                                                             {create_function(fYABDRAWGETTEXT);}
    break;

  case 442: /* function: tBFILESIZE '(' string_expression ')'  */
                                         {create_function(fYABBFILESIZE);}
    break;

  case 443: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 444: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 445: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 446: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 447: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 448: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 449: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 450: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 451: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 452: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 453: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 454: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 455: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 456: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 457: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 458: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 465: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 466: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 467: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 468: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 469: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 470: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 471: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 472: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 473: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 474: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 475: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 476: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 479: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 480: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 481: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 482: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 485: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 486: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 487: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 488: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 492: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 493: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 494: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 495: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 496: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 497: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 498: /* $@17: %empty  */
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

  case 499: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 500: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 501: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 502: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 503: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 504: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 505: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 506: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 507: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 509: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 510: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 511: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 512: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 518: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 519: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 521: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 523: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 525: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 526: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 527: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 528: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 529: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 530: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 531: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 532: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 534: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 535: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 536: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 538: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 539: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 540: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 541: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 542: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 543: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 544: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 545: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 546: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 547: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 549: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 550: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 551: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 552: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 553: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 554: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 555: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 557: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 558: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 562: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 563: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 568: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 570: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 571: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 572: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 573: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 576: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 577: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 578: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 579: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 580: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 581: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 582: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 583: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 587: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 588: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 589: /* using: %empty  */
       {create_print('d');}
    break;

  case 590: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 591: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 592: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 593: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 594: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 595: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 596: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 597: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 598: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 599: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 600: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 601: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 602: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 603: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 604: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 605: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 606: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 607: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 608: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 609: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 610: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 611: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 612: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 613: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 614: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 615: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 616: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 617: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 618: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 619: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 620: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 621: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 622: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 623: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 624: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 625: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 626: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 627: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 628: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 629: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 630: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 631: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 632: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 633: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 636: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 637: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 638: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 639: /* gosub_list: gosub_list ',' symbol_or_lineno  */
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

