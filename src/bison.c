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
  YYSYMBOL_tSIN = 163,                     /* tSIN  */
  YYSYMBOL_tASIN = 164,                    /* tASIN  */
  YYSYMBOL_tCOS = 165,                     /* tCOS  */
  YYSYMBOL_tACOS = 166,                    /* tACOS  */
  YYSYMBOL_tTAN = 167,                     /* tTAN  */
  YYSYMBOL_tATAN = 168,                    /* tATAN  */
  YYSYMBOL_tEXP = 169,                     /* tEXP  */
  YYSYMBOL_tLOG = 170,                     /* tLOG  */
  YYSYMBOL_tSQRT = 171,                    /* tSQRT  */
  YYSYMBOL_tSQR = 172,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 173,                   /* tMYEOF  */
  YYSYMBOL_tABS = 174,                     /* tABS  */
  YYSYMBOL_tSIG = 175,                     /* tSIG  */
  YYSYMBOL_tINT = 176,                     /* tINT  */
  YYSYMBOL_tCEIL = 177,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 178,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 179,                    /* tFRAC  */
  YYSYMBOL_tROUND = 180,                   /* tROUND  */
  YYSYMBOL_tMOD = 181,                     /* tMOD  */
  YYSYMBOL_tRAN = 182,                     /* tRAN  */
  YYSYMBOL_tVAL = 183,                     /* tVAL  */
  YYSYMBOL_tLEFT = 184,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 185,                   /* tRIGHT  */
  YYSYMBOL_tMID = 186,                     /* tMID  */
  YYSYMBOL_tLEN = 187,                     /* tLEN  */
  YYSYMBOL_tMIN = 188,                     /* tMIN  */
  YYSYMBOL_tMAX = 189,                     /* tMAX  */
  YYSYMBOL_tSTR = 190,                     /* tSTR  */
  YYSYMBOL_tINKEY = 191,                   /* tINKEY  */
  YYSYMBOL_tCHR = 192,                     /* tCHR  */
  YYSYMBOL_tASC = 193,                     /* tASC  */
  YYSYMBOL_tHEX = 194,                     /* tHEX  */
  YYSYMBOL_tDEC = 195,                     /* tDEC  */
  YYSYMBOL_tBIN = 196,                     /* tBIN  */
  YYSYMBOL_tUPPER = 197,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 198,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 199,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 200,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 201,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 202,                /* tMOUSEMOD  */
  YYSYMBOL_tTRIM = 203,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 204,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 205,                   /* tRTRIM  */
  YYSYMBOL_tSTRING2 = 206,                 /* tSTRING2  */
  YYSYMBOL_tREPLACE = 207,                 /* tREPLACE  */
  YYSYMBOL_tINSTR = 208,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 209,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 210,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 211,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 212,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 213,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 214,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 215,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 216,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 217,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 218,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 219,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 220,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 221,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 222,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 223,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 224,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 225,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 226,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 227,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 228,                    /* tDATE  */
  YYSYMBOL_tTIME = 229,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 230,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 231,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 232,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 233,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 234,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 235,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 236,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 237, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 238,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 239, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 240,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 241,                   /* tEVAL2  */
  YYSYMBOL_tARGUMENT = 242,                /* tARGUMENT  */
  YYSYMBOL_243_ = 243,                     /* '-'  */
  YYSYMBOL_244_ = 244,                     /* '+'  */
  YYSYMBOL_245_ = 245,                     /* '*'  */
  YYSYMBOL_246_ = 246,                     /* '/'  */
  YYSYMBOL_UMINUS = 247,                   /* UMINUS  */
  YYSYMBOL_248_ = 248,                     /* ';'  */
  YYSYMBOL_249_ = 249,                     /* ','  */
  YYSYMBOL_250_ = 250,                     /* '('  */
  YYSYMBOL_251_ = 251,                     /* ')'  */
  YYSYMBOL_252_ = 252,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 253,                 /* $accept  */
  YYSYMBOL_program_or_expression = 254,    /* program_or_expression  */
  YYSYMBOL_program = 255,                  /* program  */
  YYSYMBOL_statement_list = 256,           /* statement_list  */
  YYSYMBOL_257_1 = 257,                    /* $@1  */
  YYSYMBOL_258_2 = 258,                    /* $@2  */
  YYSYMBOL_assignment = 259,               /* assignment  */
  YYSYMBOL_statement = 260,                /* statement  */
  YYSYMBOL_261_3 = 261,                    /* $@3  */
  YYSYMBOL_262_4 = 262,                    /* $@4  */
  YYSYMBOL_263_5 = 263,                    /* $@5  */
  YYSYMBOL_264_6 = 264,                    /* $@6  */
  YYSYMBOL_265_7 = 265,                    /* $@7  */
  YYSYMBOL_266_8 = 266,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 267,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 268,        /* string_assignment  */
  YYSYMBOL_to = 269,                       /* to  */
  YYSYMBOL_open_clause = 270,              /* open_clause  */
  YYSYMBOL_seek_clause = 271,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 272,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 273,        /* string_expression  */
  YYSYMBOL_string_function = 274,          /* string_function  */
  YYSYMBOL_number_assignment = 275,        /* number_assignment  */
  YYSYMBOL_expression = 276,               /* expression  */
  YYSYMBOL_277_9 = 277,                    /* $@9  */
  YYSYMBOL_278_10 = 278,                   /* $@10  */
  YYSYMBOL_arrayref = 279,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 280,          /* string_arrayref  */
  YYSYMBOL_coordinates = 281,              /* coordinates  */
  YYSYMBOL_function = 282,                 /* function  */
  YYSYMBOL_const = 283,                    /* const  */
  YYSYMBOL_number = 284,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 285,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 286,                  /* dimlist  */
  YYSYMBOL_function_or_array = 287,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 288,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 289,                /* call_list  */
  YYSYMBOL_290_11 = 290,                   /* $@11  */
  YYSYMBOL_calls = 291,                    /* calls  */
  YYSYMBOL_call_item = 292,                /* call_item  */
  YYSYMBOL_function_definition = 293,      /* function_definition  */
  YYSYMBOL_294_12 = 294,                   /* $@12  */
  YYSYMBOL_295_13 = 295,                   /* $@13  */
  YYSYMBOL_296_14 = 296,                   /* $@14  */
  YYSYMBOL_endsub = 297,                   /* endsub  */
  YYSYMBOL_function_name = 298,            /* function_name  */
  YYSYMBOL_export = 299,                   /* export  */
  YYSYMBOL_local_list = 300,               /* local_list  */
  YYSYMBOL_local_item = 301,               /* local_item  */
  YYSYMBOL_static_list = 302,              /* static_list  */
  YYSYMBOL_static_item = 303,              /* static_item  */
  YYSYMBOL_paramlist = 304,                /* paramlist  */
  YYSYMBOL_paramitem = 305,                /* paramitem  */
  YYSYMBOL_for_loop = 306,                 /* for_loop  */
  YYSYMBOL_307_15 = 307,                   /* $@15  */
  YYSYMBOL_308_16 = 308,                   /* $@16  */
  YYSYMBOL_309_17 = 309,                   /* $@17  */
  YYSYMBOL_310_18 = 310,                   /* $@18  */
  YYSYMBOL_next = 311,                     /* next  */
  YYSYMBOL_step_part = 312,                /* step_part  */
  YYSYMBOL_next_symbol = 313,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 314,  /* switch_number_or_string  */
  YYSYMBOL_315_19 = 315,                   /* $@19  */
  YYSYMBOL_sep_list = 316,                 /* sep_list  */
  YYSYMBOL_number_or_string = 317,         /* number_or_string  */
  YYSYMBOL_case_list = 318,                /* case_list  */
  YYSYMBOL_319_20 = 319,                   /* $@20  */
  YYSYMBOL_default = 320,                  /* default  */
  YYSYMBOL_321_21 = 321,                   /* $@21  */
  YYSYMBOL_do_loop = 322,                  /* do_loop  */
  YYSYMBOL_323_22 = 323,                   /* $@22  */
  YYSYMBOL_loop = 324,                     /* loop  */
  YYSYMBOL_while_loop = 325,               /* while_loop  */
  YYSYMBOL_326_23 = 326,                   /* $@23  */
  YYSYMBOL_327_24 = 327,                   /* $@24  */
  YYSYMBOL_wend = 328,                     /* wend  */
  YYSYMBOL_repeat_loop = 329,              /* repeat_loop  */
  YYSYMBOL_330_25 = 330,                   /* $@25  */
  YYSYMBOL_until = 331,                    /* until  */
  YYSYMBOL_if_clause = 332,                /* if_clause  */
  YYSYMBOL_333_26 = 333,                   /* $@26  */
  YYSYMBOL_334_27 = 334,                   /* $@27  */
  YYSYMBOL_335_28 = 335,                   /* $@28  */
  YYSYMBOL_336_29 = 336,                   /* $@29  */
  YYSYMBOL_endif = 337,                    /* endif  */
  YYSYMBOL_short_if = 338,                 /* short_if  */
  YYSYMBOL_339_30 = 339,                   /* $@30  */
  YYSYMBOL_end_of_if = 340,                /* end_of_if  */
  YYSYMBOL_else_part = 341,                /* else_part  */
  YYSYMBOL_elsif_part = 342,               /* elsif_part  */
  YYSYMBOL_343_31 = 343,                   /* $@31  */
  YYSYMBOL_344_32 = 344,                   /* $@32  */
  YYSYMBOL_maybe_then = 345,               /* maybe_then  */
  YYSYMBOL_inputlist = 346,                /* inputlist  */
  YYSYMBOL_347_33 = 347,                   /* $@33  */
  YYSYMBOL_input = 348,                    /* input  */
  YYSYMBOL_readlist = 349,                 /* readlist  */
  YYSYMBOL_readitem = 350,                 /* readitem  */
  YYSYMBOL_datalist = 351,                 /* datalist  */
  YYSYMBOL_printlist = 352,                /* printlist  */
  YYSYMBOL_using = 353,                    /* using  */
  YYSYMBOL_inputbody = 354,                /* inputbody  */
  YYSYMBOL_355_34 = 355,                   /* $@34  */
  YYSYMBOL_356_35 = 356,                   /* $@35  */
  YYSYMBOL_357_36 = 357,                   /* $@36  */
  YYSYMBOL_358_37 = 358,                   /* $@37  */
  YYSYMBOL_359_38 = 359,                   /* $@38  */
  YYSYMBOL_360_39 = 360,                   /* $@39  */
  YYSYMBOL_361_40 = 361,                   /* $@40  */
  YYSYMBOL_362_41 = 362,                   /* $@41  */
  YYSYMBOL_363_42 = 363,                   /* $@42  */
  YYSYMBOL_364_43 = 364,                   /* $@43  */
  YYSYMBOL_365_44 = 365,                   /* $@44  */
  YYSYMBOL_366_45 = 366,                   /* $@45  */
  YYSYMBOL_367_46 = 367,                   /* $@46  */
  YYSYMBOL_prompt = 368,                   /* prompt  */
  YYSYMBOL_printintro = 369,               /* printintro  */
  YYSYMBOL_hashed_number = 370,            /* hashed_number  */
  YYSYMBOL_goto_list = 371,                /* goto_list  */
  YYSYMBOL_gosub_list = 372                /* gosub_list  */
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
#define YYFINAL  244
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   14853

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  253
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  635
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1988

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   498


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
       2,     2,     2,     2,     2,   252,     2,     2,     2,     2,
     250,   251,   245,   244,   249,   243,     2,   246,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   248,
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
     235,   236,   237,   238,   239,   240,   241,   242,   247
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   232,   232,   233,   234,   235,   236,   239,   242,   243,
     243,   243,   246,   247,   248,   249,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   267,   268,   268,   269,   270,   271,   272,   273,
     274,   275,   275,   277,   277,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   289,   290,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   307,   308,
     309,   310,   311,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     410,   411,   412,   413,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   483,
     484,   485,   486,   487,   491,   492,   493,   494,   495,   496,
     499,   500,   503,   504,   505,   506,   507,   510,   511,   514,
     515,   518,   519,   520,   521,   522,   523,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   544,   545,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   558,   559,   563,
     564,   565,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   588,   589,   592,   592,   593,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   625,
     628,   631,   634,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   653,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
     664,   665,   666,   667,   668,   669,   670,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
     684,   685,   686,   687,   688,   689,   690,   691,   692,   693,
     694,   695,   696,   697,   698,   699,   700,   701,   702,   703,
     704,   705,   706,   707,   710,   711,   714,   715,   716,   717,
     718,   719,   720,   721,   722,   723,   724,   725,   726,   729,
     730,   731,   734,   735,   736,   737,   740,   741,   744,   745,
     746,   747,   750,   753,   756,   756,   759,   760,   761,   764,
     765,   768,   769,   772,   768,   777,   778,   781,   782,   785,
     786,   787,   788,   791,   792,   795,   796,   797,   798,   801,
     802,   805,   806,   807,   808,   811,   812,   813,   816,   817,
     818,   819,   822,   823,   828,   843,   822,   848,   849,   850,
     851,   852,   853,   856,   857,   860,   861,   866,   866,   870,
     871,   874,   875,   879,   881,   880,   885,   886,   886,   890,
     890,   896,   897,   898,   899,   900,   901,   905,   906,   905,
     912,   913,   917,   917,   922,   923,   924,   925,   926,   927,
     930,   931,   931,   933,   930,   937,   938,   939,   940,   941,
     942,   945,   945,   950,   951,   954,   955,   958,   960,   962,
     959,   966,   967,   970,   971,   971,   974,   975,   977,   978,
     982,   983,   986,   987,   989,   990,   994,   995,   996,   997,
    1000,  1001,  1002,  1003,  1004,  1007,  1008,  1009,  1012,  1012,
    1013,  1013,  1014,  1014,  1015,  1015,  1016,  1016,  1017,  1017,
    1018,  1018,  1019,  1019,  1020,  1020,  1021,  1021,  1022,  1022,
    1023,  1023,  1024,  1024,  1027,  1028,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,
    1047,  1048,  1050,  1051,  1054,  1055
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
  "tPASTE", "tTRANSLATE", "tSIN", "tASIN", "tCOS", "tACOS", "tTAN",
  "tATAN", "tEXP", "tLOG", "tSQRT", "tSQR", "tMYEOF", "tABS", "tSIG",
  "tINT", "tCEIL", "tFLOOR", "tFRAC", "tROUND", "tMOD", "tRAN", "tVAL",
  "tLEFT", "tRIGHT", "tMID", "tLEN", "tMIN", "tMAX", "tSTR", "tINKEY",
  "tCHR", "tASC", "tHEX", "tDEC", "tBIN", "tUPPER", "tLOWER", "tMOUSEX",
  "tMOUSEY", "tMOUSEB", "tMOUSEMOD", "tTRIM", "tLTRIM", "tRTRIM",
  "tSTRING2", "tREPLACE", "tINSTR", "tRINSTR", "tCHOMP", "tSYSTEM",
  "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tFRNFN_CALL", "tFRNFN_CALL2",
  "tFRNFN_SIZE", "tFRNBF_ALLOC", "tFRNBF_FREE", "tFRNBF_SIZE",
  "tFRNBF_DUMP", "tFRNBF_SET", "tFRNBF_GET", "tFRNBF_GET2",
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

#define YYPACT_NINF (-1549)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-541)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     482, 12207, 10223, 11651,    67,   149,    76,   -44,   -42, -1549,
   -1549, -1549, -1549, -1549,   161,   161,   161,  7539, -1549, -1549,
   -1549, 11651, -1549, -1549, 11651,    21,    84, -1549, -1549, -1549,
   10223,   -41, -1549, 10223,   205, -1549, 10223, 10223, 10223,   265,
      33,   161,  3590,  2273,  4096,   259, 10223,  6807,  7783,    44,
      11, 10223, -1549,    18, 11651, 11651, 11651,    12, 10223,  2195,
   10223, 10223,  8027,  8271,  7051,  5831, 10223,  6319,  8515,  8759,
   10702, 11651, 11651,   -24,  6563,  9003, 10223,  9247, 10223, 10223,
    5587,  6075,  5099,  5343,  9491,  9735, 10829, 10956, 11083,    34,
     -45,   -43,   -35,   -22,   -20,  4096, 11651, 11651, 11651, -1549,
     174, -1549, -1549,    49, -1549, -1549, -1549, -1549,   162,   166,
   -1549,   219, -1549, -1549, -1549, -1549, -1549, -1549, -1549, -1549,
      28,    30, -1549, -1549, -1549, -1549,    64,    70,    78,    80,
   10223,   102,   108,   118,   129,   131,   144,    26,   165,   169,
     193,   260,   133,   272,   -74,   -23,   -65,   -57,   -39,   -34,
     136,   142,   100,   143,   291,   322,   347,   349,   351,   371,
     419,   423,   436,   480,   490,   492,   540,   541,   557,   599,
     610,   613,   624,   626,   638,   644,   668,   685,   702,   703,
     723,   727,   734,   741,   771,   784,   795,   802,   805,   808,
     811,   815,   817,   840,   851,   853,   863,   866,   867,   881,
     890,   902,   903,   904,   905,   914,   915,   916,   917,   918,
     925,   926,   927,   929,   938,   939,   947,   948,   959,   960,
     961,   962,   963,   975,   982, 10223, 10223,   251, -1549,   519,
   -1549, -1549, -1549, -1549,   137,   194,   268,   300, 11651,   -28,
     383,   162,   166,   407, -1549, 10223, -1549, 11651, -1549,   545,
   10223, 11994, -1549, -1549, -1549, -1549, -1549,   266,    99,   284,
     475,   369, -1549, 10223, -1549,   369, -1549, -1549, 10223, 11994,
     552,   989,   605,  1014,    -1, 10223,   -32,   251,  1086,  1015,
    1030,   483,  1086,   251,  1443,   251, 11867,  1039,  1040,   501,
   -1549, -1549,   822,   822, -1549, -1549,   505, -1549,  7295, 11651,
   10223,    85,  1086,   579,    26, -1549, -1549, -1549,   653, 10223,
   11651, 11651, 11651, 12124, -1549, 10223, -1549,     1, 11651,   678,
   -1549, -1549, 10223,  9979, -1549, -1549,  1086, -1549, -1549,   369,
      -2,    -2, -1549,     1, 10223, 10223, 10223, 10223, 10223, 10223,
   10223, 11651, 11651, 10223, 10223, 10223, 10223,     1,     1, 11651,
     688, 11651,   697, 11651, 11651,     1, 11651, 11651, 11651, 11651,
       1,   701, 11651, 11651, 11651,     1, 11651,     1, 11651,   717,
   11651,    15,    42,   134, 11651, 11651, 11651, 11651, 11651,     1,
   11651,     1,     1, 11651,     1,     1,     1, 11651, 11651, 11651,
   11651, 11651,     1, 11651, 11651, 11651, 11651,     1, 11651, 11651,
   11651, 11651, 11651, 11651, 11651,     1, 11651, 11651, 11651, 11191,
   11651, 11651,     1, 11651,   755, 11651,   848, 11651,   197, 11651,
     296, 11651,   387, 11651,  1242,  1242,  1242,  4352, 11651,   834,
    1000,   369,   428,   601, -1549,   891, 10223, 10223, 10223, 10223,
   11651, -1549, -1549, -1549, 10223, 10223,  1892, 10223, 10223, 10223,
   10223,  3846,  4096, 11651, -1549,   488,   488, 10223, 10223, 11651,
   11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651, 11651,
   11651, 11651, 11651, 11651, 11651, 11318, 11651, 11651, 11651,  1041,
   -1549, 11651, 10223, 10223, 10223, 10223, 10223, 10223, 10223, 10223,
   10223, 10223,  4096, 10223, 10223, 10223, 10223, 10223, 10223, 10223,
   10223,  4601, 11651, 11651, 11651, 11651, 11651, 10223, 10223, 10223,
    4850, 10223, 11651, 10223, 11651, 10223, 11651, 11651,  1791, 10353,
   10464, 10575, 11651, 11651, 11651, 10223, 11651, 11651, 11651, 11651,
   11651, 11651,  4096, 11651, -1549, -1549, 11651, 10223, 11651, 11651,
   11651, 11651, 11651,   869,  1012, 11651,  1242, 11651,  1242, 11651,
   11651, 11651,   967,   125,  1110, 11651, 11651, 11651, 11651, 11651,
   11651, 11651, 11651, -1549, -1549, -1549, 10223, 10223, 10223, 10223,
   10223, 10223, 10223, 10223, 10223, 10223, 10223, 10223,    -5, -1549,
   -1549, -1549,  1086,  1048,   369,  1050,  1230,  1086,   222, -1549,
   -1549, -1549, -1549,  1062,  1066,  1074, -1549,  1075,  1076,  1085,
   -1549,   251,  1086,  1098, -1549,   251,  1086,  1281,   794,  1303,
   11994, 10223,  1100, 11651, -1549, -1549, 10223,   251,   637,   283,
    1117,  1310,  1119,     8, -1549,  1360, -1549, -1549,   503, 10223,
   10223, -1549, -1549,   265, -1549, -1549,    51, 12337,   369,  1086,
     474, 11429, 10223,     1,   369,   369,   667, 10223, -1549,   -32,
   -1549, -1549, 10223,   673, 11651, -1549, 10223,     1, 10223, 10223,
   10223,  1136,     1,  1143,     1,  1147,     1,     1,   675,   369,
    1150,  1160,     1,     1, 10223, 10223,   677, 11651,   681, 11651,
     369,   684, 10223,   687,   369,   694,   700, 10223, 11651,   715,
     716,   718, 10223,   726, 10223,   730, 11651,   736, 10223, 11651,
   11651,   737,   739,   743,   746,   750, 10223,   753, 10223, 10223,
     754, 10223, 10223, 10223,   369,   756,   757,   369,   764, 10223,
     369,   768,   775,   776, 10223,   369,   779,   786,   369,   787,
     789,   793, 10223,   797,   369,   807, 11651,   810,   833,   835,
   10223,   836, 11651,   837, 11651,   843, 11651,   844, 11651,   847,
   11651,   369,  1162,  1166,  1167,  1176, -1549,  1129,    23, 10223,
   10223, 10223, 10223, -1549,  1186,     1,     1,  1086,   369,   645,
    1194,  1197, 12415, 12521,  1144, 12544, 12578, 12599,  1203,   113,
    1187,  1204,   850,  1213,  1217,  1224,  1234,  1188,  1198,     1,
   12614,   870,    24,   369,   369,   369,   369,   369,   369,   884,
     369,   369,   886,   369,   369,   888,   369, 11651,   369,   897,
     369,   898, 11651,   138,  1330,  1347,  1461,  1646,  1680,   413,
    1973,   652,  1990,  2022,  1236,  2102,  2120,  2182,  2333,  2466,
    2489,  2526, 12629, -1549,  2544,   158,   899,   946,   978,   198,
   12644, 12659,   261,   696, -1549,  2683,  2730,   201,  2755,  -174,
    2770,   253,   299, -1549,   318, -1549,   337, -1549,   367, -1549,
     368,   386,   388,   389, 12674,   984,   985,   987,   416,   417,
     443,   608,  1240,   -30,  1251,  1257,   447,  2787,   448,   -27,
     991,   997,  1009, -1549, -1549,  1013,  -169,  1032,   -97,  1044,
     451,   487, -1549, -1549,   369,   369,   369,   369,   369,   369,
     369, -1549, 10223, 10223,  2077,   491,   359,   578,   363,   -12,
     -53, -1549,   -33,   -33,   967,   967, -1549, -1549, -1549, 11994,
   -1549, -1549, 10223, -1549, -1549, -1549, -1549,   161,   161, -1549,
   -1549,   284, -1549, -1549,   475, 10223, -1549,  1466, -1549, -1549,
   -1549, -1549, -1549, -1549, -1549, -1549,   640, 12705, 10223,    61,
    2825, 11762, -1549, -1549, 10223, 10223,  1260, 11651, -1549, -1549,
   10223, -1549,   748,  1261,  1276,  1278,  1280, 12728, 12743,  1288,
    1302, -1549, -1549, -1549, 10223,  1426,  1464, -1549,  1053, 12762,
   10223, 11651,  1086, -1549, -1549, 11651,  1059, -1549, 10223, 12858,
   12889,  1306, 11651, 10223, 10223, 10223, 11651, 10223, 10223, 10223,
   10223, 10223, 10223, 10223,  1307,  1318, 10223,  1069, 10223,  1070,
   10223,  1319, 11651, 11651, 11651,  1320,  1071, 11651, 11651, 10223,
    1329, 11651,  1357, 10223,  1078, 11651, 12927,   369,   369, 11651,
   11651, 10223, 11651, 10223,  1367, 11651,  1380,  1383, 10223,  1387,
    1393,  1394, 10223, 10223, 10223,  1402, 11651, 10223, 10223,  1403,
   11651, 10223, 11651, 11651, 10223,  1411, 11651, 10223,  1089, 10223,
   11651, 10223,  1412, 11651,  1092, 10223,  1096, 10223,  1099, 11651,
    1113, 11651,  1114, -1549, 10223, 10223, 10223, -1549, -1549,   251,
    1086,   251,  1086, 12946, 12961, 11994, 10223, 10223, 10223, -1549,
   -1549, -1549, -1549, -1549, 10223, 10223, -1549, 10223, 10223, 10223,
   -1549, 11651, -1549, 11540, -1549, 11651,  1345,  1413, -1549, -1549,
   10223, 10223, 10223, 10223, 11651, -1549, 10223, 10223, 10223,   369,
   10223, 11651,   500, -1549, -1549, -1549, -1549, -1549, -1549, 10223,
   -1549, -1549, 10223, -1549, -1549, -1549, -1549, -1549, -1549, -1549,
   -1549, -1549, -1549, -1549, 10223, -1549, -1549, 10223, 10223, 10223,
   -1549, 10223, 10223, -1549, 11651, -1549, -1549, -1549, -1549, -1549,
   10223, -1549, -1549, -1549, -1549, -1549, -1549, -1549, -1549, -1549,
   -1549, -1549, 11651, 11651, 11651, 11651, -1549, -1549, -1549, -1549,
   -1549, 11651, -1549, -1549, -1549, -1549, -1549, -1549, 10223, -1549,
   10223, 10223, 10223,  1547, 11651, -1549,  1547, 11651, -1549, 11651,
   -1549, -1549,  1892,  1196, 10223,   107,  1086, -1549,  1414, -1549,
    1424,  1429,  1430, -1549,  1448,  1450, -1549, -1549, -1549,   665,
   11994, -1549, -1549, -1549, 10223, 12976, 11651,  1644, -1549, 11651,
     369,   251,   637, 12991, 10223,    62,   748,   748,  2842,  1463,
    1465, -1549,  1462, -1549, -1549, -1549, -1549, 10223, 10223, -1549,
   -1549, 13006,  4096,  4096, 11651, 11651,  1477,  1115,   369, 11651,
   -1549, 10223, 10223, 11651,   369,  1479, 13021,     1,  1116,  1489,
       1,   251, 13042, 13073, 13088,     1,  1496, 11651, 11651,  1086,
   11651,  1086, 11651,   251,  1086, 11651,  1122,   369,   369, 11651,
   11651,  1132,  1133,  1034,  1086, 11651,  1134, 11651,  1086, 11651,
    1135, 11651,  1142,  1164,  1086,   369,  1086, 11651,  1183, 11651,
   11651,  1086, 11651, 11651, 11651,   251, 13111,   251,  1086,  1086,
   11651,   369,  1086,  1086, 11651,  1184,  1051,  1086,   369,   369,
    1086, 11651,  1185, 13205, 10223,  1086,  1202,  1086, 11651,   369,
   11651, 13226, 11651,  1386, 13272, 11651,  1220, 11651,  1221, 11651,
    1498,  2915,  3044,   712, 11651, 11651, -1549,  1086,     1, -1549,
    1510,  3077,  3202,  3303,  3336,  3386,   504,  1520,   173,   369,
   -1549, -1549,  3650,  3906,  1530,    54,  1222,  1086,  1086,  1086,
   13295,   369, -1549,  4156,  4374,  4412,  4623,  4661,   999,  4872,
    4910,   177,  6341,   530,  1232,   247,   326,   548,  6585, 13310,
   13325,  6829,   -85,   549,   -71,   550,   562,    38, -1549, -1549,
   -1549,   161,   161, -1549, -1549, -1549, -1549, 10223,  1671,  1710,
    1749,  7317, 10223,   567,  1543,   327, -1549, 10223, 13340, 11651,
    1739, -1549, -1549, -1549, -1549, -1549, -1549,  1549,  1554,  1086,
    1086, 11651, -1549, -1549,   369,   369, 11651, 11651,  1233, 13355,
    1086,  1235, 11651, 11651, 10223, 11651, 11651, 10223, 10223, 10223,
   10223, 10223, 10223,   369,  1239,  1255,  1277,  1297, 10223,  1298,
    1299, 11651, 10223, 10223,  1301, 11651,  1321,  1322, 10223,   369,
   10223, 10223,  1333, 11651,  1335,  1336,  1350,  1351,  1353, 11651,
    1359,  1361, 10223, 11651,  1365, 10223, 10223,  1086, 10223,  1368,
    1371, 10223,   369, 11651, 11651,  1374, 10223,  1378, 11651,  1382,
   -1549,  1723,  1732, 10223,  1733,  1389,   369, 10223,   773, -1549,
   -1549, -1549, -1549, -1549, -1549, -1549, 11651, -1549, -1549, -1549,
   -1549, 10223, 11651, 10223, -1549, -1549, -1549, -1549, -1549, 10223,
   -1549, -1549, -1549, 11651, -1549, -1549, -1549, 11651, 10223, -1549,
   10223, -1549, -1549, -1549, 11651, 10223, -1549, 11651, -1549, -1549,
   11651, -1549, -1549, -1549, 10223, -1549, -1549, -1549, -1549, -1549,
    1761,   719,  7561,  1754, 10223, 11651,  7805, 10223,   582,  1563,
    1360,   748,  1564,  1566,   748, -1549, -1549,   369,  1396,   369,
   11651, 11651, 11651,   369,   369,  1565,   369,   369,     1, 13370,
   13389, 13410,     1, 13425, 11651, 10223, 10223, 11651, 13456, 10223,
   11651,   369, 13554,  1086, 11651,  1423, 11651, 10223, 13573, 13609,
     251,  1086, 11651,   369, 11651, 10223, 10223, 11651, 11651,   369,
   10223, 11651,  1422,  1086,   369, 10223, 13640, 13655, 13670, 10223,
   11651, 13685,  1433,   369, 11651,  1488, 13700, 11651,  1447, 11651,
   11651, 11651,  8049, 11651, 10223, -1549,  1568,  1571,   -70, -1549,
     597, 13715,   369,  1086,  8293,   611,   617,  8537,  8781,   621,
    9025,   622,   627,    73, 11994, 12420, 10223,  1776, -1549,  1574,
   -1549,  1575, 13738,   635,   830,  9269,  1768, 10223,   748, -1549,
   -1549, -1549, -1549, 11651,   369,   369,   369, 11651, 10223, 10223,
   11651, 10223, 10223, 10223,  1449, 13757, 13772,  1451, 10223, 13793,
    1459, 10223,  1480, 10223,  1481, 13899, 10223, 10223,  1491,  1497,
   13922, 13956,   369,   369, 13977,  1514, 10223, 13992, 10223, 10223,
   10223, 14007,  1515, 10223, 11651,   369, 11651, 11651,  1517, 10223,
    1523,   369,   369,  1753,   369,  1086,  1578,  1582,   773, -1549,
   -1549, 10223, -1549, -1549, -1549, -1549, -1549, -1549, -1549, -1549,
   -1549, 10223, -1549,  1749,  1797,   571, 11994, -1549, 11651, 10223,
   10223, -1549, -1549,  1588,  1360, -1549,  1589,  1360, 14022, -1549,
     369,   369,  1592, 14037,   369, 14052,  1595, 14083, 11651, 11651,
   11651, 11651, 14106, 11651, 11651, 14121, 10223,  1086, 11651, 10223,
    1086, 14140, 11651, 10223, 10223, 11651, 11651, 11651,  1086, 11651,
   14236, 14267, 14305, 11651, 11651,  1086,   369,  1524,   369, 11651,
    1583, 14324, 11651, 11651, -1549, -1549, -1549, 11994,  9513,  1086,
   11994, -1549, -1549,  1749,   826,   335, 14339,  9757,  1360, 11651,
     748,  1360, 10223,   748, 10223, 11651, 11651, 10223, 11651, 11651,
     369,   369,   369,  1525, 10223,   369,   369, 10223, 14354,  1531,
   14369, 10223,   369, 14384, 14399,   369,   369,   369,   369, 10223,
   11651, 10223,  1533,   369, 11651,   369, 11651, 11651,  1534,   369,
      63, -1549,  1749, 11994, -1549, -1549, -1549, -1549, -1549, -1549,
   -1549, 11651, -1549, 10223, -1549,   748,   336, -1549,   748, 14420,
   -1549, 10001,   369,   369, 14451,   369,   369, 11651,  1086,  1086,
   10223, 11651, 10223,  1086, 11651, 11651,  1086,   369, 14466, 11651,
     369,  1535,   369, 11651, -1549, -1549, -1549,   871,  1749,   648,
   10245, -1549, 11651, -1549, -1549, 10223, -1549, 11651,   369, 14489,
     369, 14583,   369,   369, 10223,   369, 11651,   369, -1549, -1549,
   -1549, -1549, -1549, -1549,  1844,  1761, -1549, -1549,   649,  1360,
   11184,  1360,   369, 11651, 11651, 14604,   369, -1549, -1549, -1549,
   -1549,   748, -1549,   748,  1545,   369, 11651,  1360, -1549,  1360,
   -1549, 11651,   369,   748,   748,   369, -1549, -1549
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   229,     0,     0,     0,   469,     0,     0,     0,   223,
     492,   527,   532,    18,     0,     0,     0,     0,    31,    33,
     470,     0,   454,   454,     0,   471,    25,    27,   507,   519,
       0,   616,    55,    67,     0,   220,   221,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   230,
     231,     0,   211,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   212,     0,     0,     0,     0,     0,     2,
       9,    17,     8,     0,    12,    46,    48,    14,    29,    30,
      28,     0,    20,    21,    24,    23,    22,    35,    36,   442,
     334,   251,   443,   444,   445,   254,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,     0,
       0,   394,   397,   400,   403,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   282,   284,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   252,     0,
     348,   328,   333,   253,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,   454,     0,   454,     0,
       0,    16,   447,   446,    37,    38,    45,     0,     0,     0,
       0,    19,    50,   456,    51,    49,   472,    26,     0,    16,
     551,     0,   620,     0,     0,   580,   612,    69,    68,     0,
       0,    70,   222,    60,     0,    62,     0,   572,   574,    63,
     570,   576,     0,     0,   577,   439,    64,    66,     0,   207,
       0,     0,   631,     0,    92,   209,    86,    47,     0,     0,
       0,     0,     0,     0,    74,     0,    57,    79,     0,     0,
      94,    93,     0,     0,   232,   233,   210,    13,    15,   224,
       0,     0,    85,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,     0,     0,     7,     0,     0,     0,     0,     0,
       0,   461,   454,   454,     0,     0,   318,     0,     0,     0,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     298,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   454,   454,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   340,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     3,   316,   314,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     6,   312,     0,   234,     0,     0,   528,     9,    39,
      40,    41,    43,   475,   476,    32,   473,   481,   482,    34,
     479,   459,   460,   455,   457,   512,   511,     0,     9,     0,
      16,     0,     0,     0,   617,   618,     0,   583,   585,    52,
       0,     0,     0,     0,    56,   614,   454,   454,     0,     0,
       0,   454,   454,     0,   441,   440,     0,     0,   208,   630,
       0,     0,     0,     0,    96,    73,     0,     0,    78,   612,
     241,   240,     0,     0,     0,    75,     0,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     126,     0,     0,     0,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   166,     0,     0,   167,     0,     0,
     172,     0,     0,     0,     0,   181,     0,     0,   184,     0,
       0,     0,     0,     0,   191,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   206,   249,     0,     0,     0,   213,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,   313,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   287,   289,   288,   290,   427,   426,     0,
     429,   428,     0,   431,   430,     0,   434,     0,   432,     0,
     295,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   374,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   266,     0,     0,     0,     0,     0,
       0,     0,     0,   395,     0,   398,     0,   401,     0,   404,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   283,   285,     0,     0,     0,     0,     0,
       0,     0,   256,   349,   343,   345,   347,   344,   346,   341,
     342,   255,     0,     0,   321,   323,   325,   322,   324,   319,
     320,   339,   336,   335,   337,   338,   452,   453,   493,    16,
     539,   537,     0,   538,   534,   536,   533,     0,     0,   454,
     454,     0,   454,   454,     0,     0,   509,   513,   526,   524,
     525,   522,   521,   523,   520,   541,     9,     0,     0,     0,
       0,     0,   581,    53,    54,     0,     0,     0,   588,   590,
       0,   615,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   571,   578,   579,     0,     0,     0,   244,   243,   247,
       0,     0,   352,    58,    76,     0,    89,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   454,     0,     0,     0,   214,   215,   216,
     217,   218,   219,     0,     0,    16,     0,     0,     0,   467,
     468,   462,   416,   308,     0,     0,   407,     0,     0,     0,
     417,     0,   418,     0,   411,     0,     0,     0,   329,   330,
       0,     0,     0,     0,     0,   438,     0,     0,     0,   433,
       0,     0,     0,   296,   353,   354,   355,   356,   357,     0,
     358,   360,     0,   361,   363,   364,   326,   370,   371,   365,
     367,   368,   369,   366,     0,   373,   378,     0,     0,     0,
     377,     0,     0,   264,     0,   261,   267,   268,   379,   306,
       0,   380,   307,   269,   270,   393,   396,   399,   402,   273,
     271,   272,     0,     0,     0,     0,   276,   386,   277,   392,
     391,     0,   286,   387,   278,   388,   279,   390,     0,   280,
       0,     0,     0,     0,     0,   301,     0,     0,   303,     0,
     423,   311,   317,   315,     0,     9,   535,   632,    42,   634,
      44,     0,     0,   474,     0,     0,   480,   458,   510,   516,
      16,   553,   554,   552,     0,     0,     0,   621,   619,     0,
     586,   584,   585,     0,     0,     0,     0,     0,     0,   566,
     568,   613,   563,   448,   450,   454,   454,     0,     0,   573,
     575,    71,     0,     0,     0,     0,     0,     0,   121,     0,
      77,     0,     0,     0,   102,     0,     0,     0,     0,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,   117,
       0,   119,     0,   124,   125,     0,     0,   129,   128,     0,
       0,     0,     0,     0,   137,     0,     0,     0,   144,     0,
       0,     0,     0,     0,   151,   150,   152,     0,     0,     0,
       0,   157,     0,     0,     0,   161,     0,   163,   164,   165,
       0,   169,   171,   170,     0,   174,   177,   178,   182,   183,
     180,     0,     0,     0,     0,   188,     0,   190,     0,   194,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    87,     0,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   425,
     350,   351,     0,     0,     0,     0,   436,   291,   292,   293,
       0,   435,   297,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   531,   530,
     529,     0,     0,   477,   478,   483,   484,     0,     0,     0,
     542,     0,     0,     0,     0,     0,   582,     0,     0,     0,
     602,   589,   591,   592,   454,   454,   564,     0,     0,    59,
      61,     0,   245,   246,   242,   248,     0,     0,    90,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   189,     0,     0,
       0,     0,   195,     0,     0,     0,     0,     0,     0,     0,
     250,     0,     0,     0,     0,   227,   228,     0,   485,   405,
     406,   408,   409,   410,   419,   420,     0,   421,   331,   332,
     304,     0,     0,     0,   359,   362,   372,   257,   258,     0,
     260,   375,   376,     0,   262,   381,   274,     0,     0,   382,
       0,   384,   299,   281,     0,     0,   310,     0,   413,   300,
       0,   415,   302,   327,     0,   633,   635,   514,   517,   508,
     557,   623,     0,   622,     0,     0,     0,     0,     0,     0,
     614,     0,     0,     0,     0,   449,   451,    72,     0,    97,
       0,     0,     0,   103,   106,     0,   101,   104,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,     0,   135,     0,     0,     0,     0,   139,     0,
     145,   146,     0,   154,     0,     0,     0,     0,     0,   162,
       0,     0,     0,   176,   179,     0,     0,     0,     0,     0,
       0,     0,     0,   198,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,   488,   489,     0,   486,
       0,     0,   437,   294,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   503,    16,   229,     0,   555,   627,     0,
     624,     0,     0,     0,   594,     0,   604,     0,     0,   593,
     567,   569,   565,     0,   120,    82,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   158,   159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   197,     0,     0,     0,     0,
       0,   237,   238,     0,   236,   226,     0,     0,     0,   463,
     422,     0,   259,   263,   275,   383,   385,   389,   309,   412,
     414,     0,   494,   515,     9,   561,    16,   543,     0,     0,
       0,   587,   606,     0,   614,   596,     0,   614,     0,   603,
      95,   110,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   142,     0,     0,
     140,     0,     0,     0,     0,     0,     0,     0,   175,     0,
       0,     0,     0,     0,     0,   196,   199,     0,   201,     0,
       0,     0,     0,     0,   490,   491,   487,    16,     0,   504,
      16,   562,   558,   556,     0,     0,     0,     0,   614,     0,
       0,   614,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   118,     0,     0,   127,   122,     0,     0,     0,
       0,     0,   149,     0,     0,   156,   160,   168,   173,     0,
       0,     0,     0,   193,     0,   200,     0,     0,     0,   235,
       9,   305,   495,    16,   550,   547,   548,   549,   545,   546,
     544,     0,   628,     0,   625,     0,     0,   595,     0,     0,
     605,     0,   109,   100,     0,   111,   105,     0,   131,   136,
       0,     0,     0,   147,     0,     0,   192,   187,     0,     0,
     202,     0,   205,     0,   466,   465,   464,     0,   559,     0,
       0,   607,     0,   608,   597,     0,   598,     0,   123,     0,
     141,     0,   153,   155,     0,   185,     0,   203,   498,   500,
     501,   502,   497,   499,   505,   557,   629,   626,     0,   614,
       0,   614,   108,     0,     0,     0,   204,   506,   496,   560,
     610,     0,   600,     0,   132,   143,     0,   614,   609,   614,
     599,     0,   186,     0,     0,   133,   611,   601
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1549, -1549, -1549,  -244, -1549, -1549,  1845,   765, -1549, -1549,
   -1549, -1549, -1549, -1549, -1549,  1798,   472, -1549, -1549,  -321,
      -3, -1549,  1799,  1632, -1549, -1549,  1397,  -447,  2877, -1549,
    1218,   -36,   -14, -1549,     4,    10,    39, -1549, -1549,   920,
    1851, -1549, -1549, -1549, -1549, -1549, -1549, -1549,   928, -1549,
     930, -1549,   112, -1549, -1549, -1549, -1549, -1549, -1549, -1549,
   -1549, -1549, -1549, -1549,   444, -1549, -1549, -1549, -1549, -1549,
   -1549, -1549, -1549, -1549, -1549, -1549, -1549, -1549, -1549, -1549,
   -1549, -1549, -1549, -1549, -1549, -1549, -1549, -1549, -1549,   -93,
   -1549, -1549, -1549, -1137, -1549, -1549, -1549,  1237, -1549, -1549,
     631,  1216, -1549, -1549, -1549, -1549, -1549, -1549, -1549, -1549,
   -1549, -1549, -1549, -1549, -1549, -1548, -1549,     2, -1549, -1549
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,    99,   100,   435,  1085,   101,   102,   259,   260,
     927,   928,   276,   649,   103,   104,   652,   105,   106,   753,
     227,   228,   107,   313,   903,   902,   785,   786,   314,   230,
     294,   231,   254,   281,   232,   233,   262,   263,   603,   604,
     110,   769,  1360,  1827,  1926,  1091,   111,   595,   596,   599,
     600,  1658,  1659,   112,   249,  1204,  1830,  1927,  1954,  1762,
    1968,   113,   268,   937,   607,  1219,  1674,  1419,  1675,   114,
     269,   944,   115,   250,   919,  1410,   116,   251,   926,   117,
     609,  1220,  1570,  1834,  1890,   118,   610,  1223,  1767,  1677,
    1883,  1955,  1832,  1241,  1584,  1242,   289,   290,   296,   619,
     952,   624,  1236,  1237,  1581,  1774,  1841,  1961,  1979,  1580,
    1777,  1838,  1959,  1977,   625,   962,   275,   303,  1208,  1210
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     239,   255,   256,   614,   295,   108,   615,   588,   241,   788,
     650,   109,   958,   650,   242,   959,   579,   271,   261,   272,
     273,   265,     7,     8,   573,   608,   620,   297,   621,   622,
     277,   245,  1688,   247,   283,   285,   119,   374,   461,   301,
     122,   123,   124,   291,   573,   307,   308,   465,   466,   266,
    1564,   329,   330,   331,   119,   468,   469,   241,   122,   123,
     124,   972,   264,   242,   572,   573,   650,   371,   372,   373,
     562,     7,     8,   471,   472,  1160,   244,  1161,   474,   475,
    1194,   462,  1195,   418,   420,   422,  1761,   375,  1924,   463,
     467,   267,   429,   431,   432,   433,   640,   430,   470,  1431,
    1432,   564,   565,   320,   754,   755,   325,  1925,   566,   567,
     568,   569,   570,   571,   572,   573,   473,   564,   565,   591,
     592,   476,   332,  1408,   566,   567,   568,   569,   570,   571,
     572,   573,   464,   321,   322,   323,   564,   565,   453,   454,
     324,   436,   437,   566,   567,   568,   569,   570,   571,   572,
     573,  1409,  1197,   438,  1198,   555,   556,   557,   558,   559,
     560,   561,   564,   565,  1557,   252,  1558,    53,   253,   566,
     567,   568,   569,   570,   571,   572,   573,    20,  1560,  1748,
    1561,  1749,    25,   555,   556,   557,   558,   559,   560,   561,
     574,   575,   576,   577,   423,   555,   556,   557,   558,   559,
     560,   561,    90,    91,    92,   424,   246,   425,   248,   279,
     280,   274,   576,   577,   562,   426,   562,   562,   434,  1181,
     623,  1182,  1188,   553,  1189,   886,  1840,   888,   427,  1843,
     428,   574,   575,   576,   577,   578,   920,   439,   921,   562,
     922,   440,   562,   441,   584,   459,   892,   651,   477,   616,
     651,    90,    91,    92,   478,   108,   634,   635,   960,   562,
     601,   109,   479,   923,   698,   605,   924,   562,   562,   287,
     288,   925,   617,   108,  1078,  1115,   292,   293,   246,   109,
     248,   574,   575,   576,   577,   583,   562,   585,   593,   594,
    1895,   699,   467,  1898,   292,   293,   638,   574,   575,   576,
     577,   589,   590,   651,   480,   562,   562,   644,   645,   646,
    1226,  1429,  1227,  1430,   442,   653,   574,   575,   576,   577,
     443,   555,   556,   557,   558,   559,   560,   561,   444,   562,
     445,   555,   556,   557,   558,   559,   560,   561,   668,   669,
     309,   310,   574,   575,   576,   577,   676,   311,   678,   470,
     680,   681,   447,   683,   684,   685,   686,   562,   448,   689,
     690,   691,  1101,   693,  1102,   695,   946,   697,   449,   562,
     312,   701,   702,   703,   704,   705,   892,   707,   562,   450,
     710,   451,   562,   700,   714,   715,   716,   717,   718,  1123,
     720,   721,   722,   723,   452,   725,   726,   727,   728,   729,
     730,   731,   562,   733,   734,   735,   737,   738,   739,  1146,
     741,  1971,   743,  1973,   745,   455,   747,   562,   749,   456,
     751,   562,  1526,   473,  1527,   758,  1543,   580,  1544,  1983,
     567,  1984,   569,   570,   571,   572,   573,   768,   571,   572,
     573,   562,   562,   457,  1689,   562,   746,  1692,   779,  1150,
     782,   581,  1158,   780,   781,   476,   791,   792,   793,   794,
     795,   796,   797,   798,   799,   800,   801,   802,   803,   804,
     805,   806,   808,   809,   810,   811,   564,   565,   813,   597,
     598,   770,   771,   566,   567,   568,   569,   570,   571,   572,
     573,   562,   783,   784,   824,   562,  1548,   562,  1549,   835,
     836,   837,   838,   839,  1163,   562,   842,   965,   966,   847,
     458,   849,  1153,   851,   852,   854,   856,   858,   860,   861,
     862,   863,   460,   865,   866,   867,   868,   869,   870,   871,
     873,   953,   954,   876,   872,   878,   879,   880,   881,   882,
     562,   481,   885,   562,   887,   748,   889,   890,   891,   586,
    1164,  1779,   894,   895,   896,   897,   898,   899,   900,   901,
     975,   976,   562,   563,   569,   570,   571,   572,   573,  1165,
     562,   562,   482,   874,   875,  1550,  1575,  1551,   892,   562,
     562,   562,   564,   565,  1891,  1932,  1892,  1933,  1166,   566,
     567,   568,   569,   570,   571,   572,   573,   483,  -540,   484,
     295,   485,   574,   575,   576,   577,   574,   575,   576,   577,
     949,   562,   562,   562,   108,   564,   565,  1831,  1167,  1168,
     109,   486,   566,   567,   568,   569,   570,   571,   572,   573,
     562,   562,   562,   562,   564,   565,   750,  1169,   978,  1170,
    1171,   566,   567,   568,   569,   570,   571,   572,   573,  1089,
    1090,   986,   570,   571,   572,   573,   574,   575,   576,   577,
     562,   562,  1129,   612,  1130,   963,   964,  1176,  1177,   487,
     969,   970,   562,   488,  1007,  1205,  1009,   761,   555,   556,
     557,   558,   559,   560,   561,  1016,   489,   562,   951,  1221,
    1222,   562,   562,  1024,  1178,   562,  1027,  1028,  1185,  1187,
     564,   565,  1200,  1897,  1417,  1418,  1900,   566,   567,   568,
     569,   570,   571,   572,   573,   564,   565,     1,     2,     3,
       4,     5,   566,   567,   568,   569,   570,   571,   572,   573,
     490,   562,   628,  1058,   574,   575,   576,   577,  1201,  1064,
     491,  1066,   492,  1068,   562,  1070,  1402,  1072,   562,  1404,
     633,  1382,  1239,  1240,   636,  1524,  1079,  1081,  1931,   564,
     565,  1934,   574,   575,   576,   577,   566,   567,   568,   569,
     570,   571,   572,   573,   562,   564,   565,  1656,  1657,  1678,
    1679,  1546,   566,   567,   568,   569,   570,   571,   572,   573,
     493,   494,   562,   562,   562,   574,   575,   576,   577,  1552,
    1559,  1562,   658,   659,  1119,   660,   562,   495,   938,  1122,
     939,   562,   940,  1563,   574,   575,   576,   577,  1573,   674,
     675,   574,   575,   576,   577,   119,   562,   682,   641,   122,
     123,   124,   687,  1686,  1978,   941,  1980,   692,   942,   694,
    1884,   562,  1885,   943,  1886,   562,  1986,  1987,  1750,   496,
     762,   706,   562,   708,   709,   562,   711,   712,   713,  1179,
     497,   562,  1753,   498,   719,   562,   562,  1887,  1754,   724,
    1888,   562,  1757,  1759,   499,  1889,   500,   732,  1760,   562,
     574,   575,   576,   577,   740,  1948,  1771,  1949,   501,  1950,
    1772,  1773,   562,   562,   502,   574,   575,   576,   577,  1956,
    1970,  1132,   642,  1133,   555,   556,   557,   558,   559,   560,
     561,   562,  1951,  1207,  1209,  1952,   981,   562,   503,   562,
    1953,   562,   985,   108,   999,   562,  1006,   654,   562,   109,
    1008,   562,   601,  1010,   763,   504,  1012,   677,   562,   574,
     575,   576,   577,  1013,   562,  1154,   679,  1155,  1230,  1014,
     688,  1231,   505,   506,  1235,   574,   575,   576,   577,   562,
     562,  1513,   562,  1514,  1017,  1018,   696,  1019,  1211,  1212,
     562,  1214,  1215,   507,   562,  1021,  1420,   508,  1257,  1023,
     562,   562,  1258,   562,   509,  1025,  1029,   562,  1030,  1264,
     562,   510,  1031,  1268,   562,  1032,  1271,   562,   562,  1033,
     562,   562,  1035,  1038,   742,  1042,  1043,  1283,   562,  1286,
    1287,  1288,   562,  1044,  1291,  1292,  1293,  1046,  1296,   562,
     562,   511,  1300,   562,  1047,  1048,  1302,  1303,  1050,  1305,
     562,   562,  1308,   562,   512,  1051,  1052,   562,  1053,  1315,
    1317,   562,  1054,  1321,   573,   513,  1056,  1325,  1326,  1328,
    1329,   562,   514,  1332,   562,   515,  1057,  1336,   516,  1059,
    1339,   517,   564,   565,  1343,   518,  1346,   519,  1348,   566,
     567,   568,   569,   570,   571,   572,   573,   562,   562,   562,
     562,   562,  1060,   759,  1061,  1063,  1065,   562,   562,   108,
     520,   562,  1067,  1069,   562,   109,  1071,   744,  1366,  1105,
    1368,   521,  1369,   522,   555,   556,   557,   558,   559,   560,
     561,  1376,  1350,   523,   562,   980,   524,   525,  1381,  1114,
     883,   555,   556,   557,   558,   559,   560,   561,   562,   988,
     562,   526,   562,  1116,   993,  1117,   995,  1118,   997,   998,
     527,   562,   562,   562,  1002,  1003,  1120,  1121,  1147,   564,
     565,  1391,   528,   529,   530,   531,   566,   567,   568,   569,
     570,   571,   572,   573,   532,   533,   534,   535,   536,  1393,
    1394,  1395,  1396,   564,   565,   537,   538,   539,  1397,   540,
     566,   567,   568,   569,   570,   571,   572,   573,   541,   542,
     562,  1403,   564,   565,  1405,  1148,  1406,   543,   544,   566,
     567,   568,   569,   570,   571,   572,   573,   564,   565,   545,
     546,   547,   548,   549,   566,   567,   568,   569,   570,   571,
     572,   573,   562,  1423,   108,   550,  1425,  1149,   562,   562,
     109,   562,   551,  1173,  1174,   562,  1175,  1087,  1088,   611,
    1190,   562,   574,   575,   576,   577,  1191,   752,  1539,   760,
    1540,  1444,  1445,   562,  1442,  1443,  1448,   562,  1192,   564,
    1451,  1112,  1193,   884,   613,   626,   566,   567,   568,   569,
     570,   571,   572,   573,  1463,  1464,   562,  1465,   562,  1466,
     627,  1196,  1467,  1473,  1437,  1438,  1469,  1470,   562,   631,
     632,   812,  1474,  1199,  1476,   562,  1477,   562,  1479,   916,
    1493,   917,  1254,   562,  1482,   918,  1484,  1485,  1259,  1486,
    1487,  1488,   929,   562,   562,   562,   930,  1490,  1280,  1282,
    1290,  1491,   562,   931,   936,   932,   933,  1299,  1494,   574,
     575,   576,   577,   562,   934,  1499,   562,  1500,  1334,  1502,
     562,  1340,  1505,   562,  1507,  1342,  1509,   935,  1345,   945,
     948,  1515,  1516,   574,   575,   576,   577,   562,   562,   562,
     562,   893,  1347,  1349,  1447,  1455,   562,   955,   956,   957,
     961,  1468,   574,   575,   576,   577,   562,   562,   562,   562,
    1077,  1471,  1472,  1475,  1478,   992,   562,   574,   575,   576,
     577,  1480,   994,   564,   565,  1096,   996,  1565,  1566,  1000,
     566,   567,   568,   569,   570,   571,   572,   573,   562,  1001,
     564,   565,  1073,  1481,   605,  1074,  1075,   566,   567,   568,
     569,   570,   571,   572,   573,  1076,  1578,   562,   562,   562,
    1763,  1764,  1483,  1492,  1495,  1086,  1103,  1110,  1587,   574,
     575,   576,   577,  1588,  1589,  1092,   562,  1111,  1093,  1593,
    1594,  1498,  1596,  1597,  1100,  1104,   555,   556,   557,   558,
     559,   560,   561,  1106,   562,   562,   562,  1107,  1611,  1506,
    1508,  1532,  1615,  1582,  1583,  1108,   562,   562,  1620,   562,
    1623,  1547,  1590,   562,  1592,  1109,  1629,  1136,  1604,  1632,
    1634,  1180,   555,   556,   557,   558,   559,   560,   561,   562,
    1642,  1643,  1183,  1645,  1605,  1648,   564,   565,  1184,  1218,
    1234,  1252,  1243,   566,   567,   568,   569,   570,   571,   572,
     573,   562,  1833,  1660,   564,   565,  1606,  1244,  1245,  1662,
    1246,   566,   567,   568,   569,   570,   571,   572,   573,  1249,
    1665,   562,   562,   562,  1666,   562,  1607,  1609,  1610,  1253,
    1614,  1669,   784,  1250,  1671,  1263,  1277,  1672,   555,   556,
     557,   558,   559,   560,   561,   562,   562,  1278,  1285,  1289,
    1616,  1617,  1683,   574,   575,   576,   577,   562,  1295,   562,
     562,  1124,  1622,  1880,  1624,  1625,  1882,  1694,  1695,  1696,
     574,   575,   576,   577,   562,   562,  1370,   562,  1125,  1626,
    1627,  1704,  1628,   562,  1707,   562,  1297,  1710,  1630,   562,
    1631,  1712,   562,  1714,  1635,   562,  1307,  1639,   562,  1718,
    1640,  1719,   562,  1644,  1722,  1723,   562,  1647,  1725,  1309,
     562,  1649,  1310,   562,   229,  1503,  1312,  1732,  1654,  1928,
     562,  1735,  1313,  1314,  1738,  1693,  1740,  1741,  1742,   258,
    1744,  1320,  1324,   555,   556,   557,   558,   559,   560,   561,
    1331,  1338,   270,  1411,  1371,   278,   562,   562,   282,   284,
     286,  1726,  1713,  1412,   302,   302,   302,   562,   108,   108,
    1413,  1414,  1734,   326,   109,   109,   574,   575,   576,   577,
    1780,   562,   629,   562,  1781,   562,  1739,  1784,  1788,  1415,
    1791,  1416,  1424,   562,   574,   575,   576,   577,  1794,   564,
     565,  1436,  1126,  1434,  1568,  1435,   566,   567,   568,   569,
     570,   571,   572,   573,   562,   562,  1446,   302,  1452,  1796,
    1798,  1816,   562,  1817,  1818,   562,  1820,  1736,  1456,  1454,
    1802,   562,  1457,   564,   565,  1462,  1803,  1461,  1569,  1510,
     566,   567,   568,   569,   570,   571,   572,   573,   562,   562,
    1518,   562,   446,  1807,  1814,  1835,  1819,   562,   562,   562,
     108,  1525,  1822,  1874,  1907,   562,   109,   562,   562,   562,
    1911,  1530,  1919,  1923,  1946,  1850,  1851,  1852,  1853,   562,
    1855,  1856,    -9,  1574,  1981,  1859,   121,  1579,  1650,  1862,
    1585,   125,  1865,  1866,  1867,  1586,  1868,  1651,  1653,  1676,
    1872,  1873,  1681,  1687,  1697,  1690,  1875,  1691,  1746,  1878,
    1879,  1747,   127,  1766,  1768,  1769,  1776,   562,  1823,  1824,
    1517,   108,  1876,  1825,   108,  -518,  1896,   109,  1839,  1842,
     109,  1845,  1902,  1903,  1848,  1905,  1906,  1531,  1967,   240,
    1356,   327,   328,   787,   973,  1217,   243,   552,   554,  1213,
    1826,  1567,  1969,  1426,  1216,   983,     0,  1917,     0,     0,
     971,  1920,     0,  1921,  1922,     0,     0,   582,     0,     0,
       0,     0,   587,     0,     0,     0,     0,   108,  1929,   574,
     575,   576,   577,   109,     0,   602,   140,  1127,   141,     0,
     606,     0,     0,     0,  1938,     0,     0,   618,  1940,     0,
       0,  1942,  1943,     0,     0,     0,  1945,   144,   145,     0,
    1947,     0,     0,   574,   575,   576,   577,     0,     0,  1958,
     637,  1128,   639,     0,  1962,   234,   235,   236,   237,   150,
       0,     0,     0,  1966,     0,     0,     0,   152,     0,     0,
     153,     0,     0,   154,     0,     0,     0,     0,     0,     0,
    1974,  1975,   566,   567,   568,   569,   570,   571,   572,   573,
       0,     0,     0,  1982,     0,   176,   177,   178,  1985,     0,
       0,   182,   183,   184,     0,   186,     0,   188,   189,   190,
       0,     0,     0,     0,   195,   196,   197,   198,   199,     0,
       0,   202,     0,   204,     0,   206,     0,     0,   208,     0,
     210,     0,     0,   212,     0,     0,   214,   215,     0,   216,
     217,     0,   219,     0,   221,     0,     0,     0,     0,     0,
       0,     0,   224,     0,     0,     0,   564,   565,     0,     0,
       0,   238,   853,   566,   567,   568,   569,   570,   571,   572,
     573,     0,     0,   564,   565,     0,     0,     0,     0,   757,
     566,   567,   568,   569,   570,   571,   572,   573,     0,     0,
    1698,   767,     0,     0,  1702,     0,   772,   773,     0,   774,
     775,   776,   777,   302,   302,   564,   565,     0,     0,     0,
     790,     0,   566,   567,   568,   569,   570,   571,   572,   573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   814,   815,   816,   817,   818,   819,
     820,   821,   822,   823,   302,   825,   826,   827,   828,   829,
     830,   831,   832,   834,     0,   574,   575,   576,   577,   840,
     841,   843,   845,   846,     0,   848,     0,   850,   567,   568,
     569,   570,   571,   572,   573,     0,     0,   864,     0,     0,
       0,     0,     0,     0,   302,   564,   565,     0,     0,   877,
       0,     0,   566,   567,   568,   569,   570,   571,   572,   573,
       0,     0,     0,   564,   565,     0,     0,     0,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   573,   904,   905,
     906,   907,   908,   909,   910,   911,   912,   913,   914,   915,
       0,     0,     0,     0,     0,     0,   574,   575,   576,   577,
       0,     0,     0,     0,  1131,     0,     0,     0,     0,     0,
       0,     0,     0,   574,   575,   576,   577,     0,     0,     0,
       0,  1134,     0,   947,     0,   564,   565,     0,   950,     0,
       0,     0,   566,   567,   568,   569,   570,   571,   572,   573,
       0,   967,   968,     0,     0,   574,   575,   576,   577,     0,
       0,     0,     0,  1135,   979,     0,   119,   120,   121,   982,
     122,   123,   124,   125,     0,   334,   335,   336,   337,   338,
     989,   990,     0,     0,     0,     0,     0,     0,     0,   339,
       0,     0,     0,   126,   127,   340,   341,     0,     0,     0,
       0,   342,   343,   344,   345,   346,     0,     0,     0,     0,
     574,   575,   576,   577,     0,     0,     0,     0,     0,     0,
    1026,     0,     0,     0,     0,     0,   128,   129,   130,   131,
     132,   133,   134,     0,     0,   574,   575,   576,   577,     0,
       0,     0,     0,  1137,   135,     0,     0,   136,     0,     0,
       0,     0,   304,   574,   575,   576,   577,     0,     0,     0,
     305,  1138,     0,     0,   138,   139,     0,     0,   140,     0,
     141,     0,     0,   306,     0,     0,     0,     0,   142,     0,
       0,  1080,  1082,  1083,  1084,   143,   564,   565,     0,   144,
     145,     0,     0,   566,   567,   568,   569,   570,   571,   572,
     573,     0,     0,     0,     0,     0,     0,   146,   147,   148,
     149,   150,   151,     0,     0,   574,   575,   576,   577,   152,
       0,     0,   153,  1139,     0,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,     0,   207,
     208,   209,   210,     0,   211,   212,     0,   213,   214,   215,
       0,   216,   217,   218,   219,   220,   221,   222,     0,     0,
       0,     0,     0,   223,   224,     0,   225,     0,     0,     0,
       0,     0,     0,   226,     0,   300,     0,     0,     0,   564,
     565,     0,     0,     0,  1202,  1203,   566,   567,   568,   569,
     570,   571,   572,   573,     0,     0,     0,     0,     0,     0,
       0,     0,   564,   565,  1206,     0,     0,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,   602,     0,     0,
       0,     0,     0,     0,     0,     0,   574,   575,   576,   577,
    1225,     0,     0,     0,  1140,     0,  1232,  1233,     0,   564,
     565,     0,  1238,     0,     0,     0,   566,   567,   568,   569,
     570,   571,   572,   573,     0,     0,  1251,   564,   565,     0,
       0,     0,     0,     0,   566,   567,   568,   569,   570,   571,
     572,   573,     0,     0,     0,     0,  1266,     0,     0,     0,
       0,  1272,  1273,  1274,     0,     0,     0,     0,  1279,     0,
    1281,     0,  1284,     0,     0,     0,     0,     0,     0,     0,
       0,  1294,     0,     0,     0,  1298,     0,     0,     0,     0,
       0,     0,     0,  1304,     0,  1306,     0,     0,     0,     0,
    1311,     0,     0,     0,  1316,  1318,  1319,     0,     0,  1322,
    1323,     0,     0,  1327,     0,     0,  1330,     0,     0,  1333,
       0,  1335,     0,  1337,     0,     0,     0,  1341,     0,  1344,
       0,     0,     0,     0,     0,     0,  1351,  1352,  1353,   574,
     575,   576,   577,     0,     0,     0,     0,  1141,  1357,     0,
       0,     0,     0,     0,     0,     0,  1361,  1362,     0,  1363,
    1364,  1365,   574,   575,   576,   577,     0,     0,     0,     0,
    1142,     0,  1372,  1373,     0,  1375,   564,   565,  1377,  1378,
    1379,     0,  1380,   566,   567,   568,   569,   570,   571,   572,
     573,  1383,     0,     0,  1384,     0,     0,     0,     0,   574,
     575,   576,   577,     0,     0,     0,  1385,  1143,     0,  1386,
    1387,  1388,     0,  1389,  1390,     0,     0,   574,   575,   576,
     577,     0,  1392,   564,   565,  1145,     0,     0,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   573,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   564,   565,
    1398,     0,  1399,  1400,  1401,   566,   567,   568,   569,   570,
     571,   572,   573,   564,   565,     0,  1407,     0,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   573,     0,     0,
     564,   565,     0,     0,     0,     0,  1421,   566,   567,   568,
     569,   570,   571,   572,   573,     0,  1428,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1439,
    1440,     0,     0,     0,   302,   302,     0,     0,   564,   565,
       0,     0,     0,  1449,  1450,   566,   567,   568,   569,   570,
     571,   572,   573,     0,     0,   564,   565,     0,     0,     0,
       0,     0,   566,   567,   568,   569,   570,   571,   572,   573,
       0,     0,     0,     0,   317,   319,   574,   575,   576,   577,
       0,     0,     0,     0,  1156,   333,     0,   347,   348,   350,
     352,   355,   360,   361,   365,   367,   369,     0,     0,     0,
       0,   379,   381,   382,   384,   385,   386,   392,   397,   405,
     412,   414,   416,     0,     0,     0,  1497,     0,     0,     0,
       0,     0,     0,   574,   575,   576,   577,     0,   564,   565,
       0,  1157,     0,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,     0,     0,     0,     0,     0,   574,   575,
     576,   577,     0,     0,     0,     0,  1159,     0,     0,     0,
       0,     0,     0,   574,   575,   576,   577,     0,     0,     0,
       0,  1162,     0,     0,     0,     0,     0,     0,     0,     0,
     574,   575,   576,   577,     0,     0,     0,     0,  1186,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   606,
       0,     0,     0,     0,  1572,     0,     0,     0,     0,  1576,
       0,     0,     0,     0,     0,     0,     0,     0,   574,   575,
     576,   577,     0,     0,     0,     0,  1228,     0,     0,     0,
       0,     0,     0,     0,     0,   574,   575,   576,   577,     0,
    1599,  1600,  1601,  1433,  1603,     0,     0,     0,     0,     0,
    1608,     0,     0,     0,  1612,  1613,     0,   564,   565,     0,
    1618,     0,  1619,  1621,   566,   567,   568,   569,   570,   571,
     572,   573,     0,     0,  1633,     0,     0,  1636,  1637,     0,
    1638,     0,     0,  1641,     0,     0,     0,     0,  1646,     0,
     564,   565,     0,     0,     0,  1652,     0,   566,   567,   568,
     569,   570,   571,   572,   573,     0,     0,     0,   574,   575,
     576,   577,     0,  1661,     0,  1663,  1511,     0,     0,     0,
       0,  1664,     0,     0,     0,     0,     0,     0,     0,     0,
    1667,     0,  1668,     0,     0,     0,   643,  1670,     0,     0,
       0,     0,   648,     0,     0,     0,  1673,     0,     0,   655,
     657,     0,     0,     0,     0,     0,  1682,     0,     0,  1685,
       0,   661,   662,   663,   664,   665,   666,   667,     0,     0,
     670,   671,   672,   673,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1705,  1706,     0,
       0,  1709,     0,     0,     0,     0,     0,     0,     0,  1715,
       0,     0,     0,     0,     0,     0,     0,  1720,  1721,     0,
       0,     0,  1724,     0,     0,   564,   565,  1727,     0,     0,
       0,  1731,   566,   567,   568,   569,   570,   571,   572,   573,
       0,     0,     0,     0,     0,     0,  1745,   574,   575,   576,
     577,     0,     0,     0,     0,  1512,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1765,     0,
       0,     0,     0,   764,   765,   766,     0,     0,     0,  1778,
     574,   575,   576,   577,     0,     0,     0,     0,  1519,     0,
       0,  1783,     0,  1785,   789,  1787,     0,     0,     0,     0,
    1792,     0,     0,  1795,     0,  1797,     0,     0,  1800,  1801,
       0,     0,     0,     0,     0,     0,     0,     0,  1808,     0,
    1810,  1811,  1812,     0,     0,  1815,   564,   565,     0,     0,
       0,  1821,     0,   566,   567,   568,   569,   570,   571,   572,
     573,     0,     0,  1828,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1829,     0,     0,     0,     0,     0,   564,
     565,  1836,  1837,     0,     0,     0,   566,   567,   568,   569,
     570,   571,   572,   573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1858,     0,
       0,  1860,     0,     0,     0,  1863,  1864,     0,     0,     0,
       0,     0,     0,     0,     0,   574,   575,   576,   577,   564,
     565,     0,     0,  1520,     0,     0,   566,   567,   568,   569,
     570,   571,   572,   573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1899,     0,  1901,     0,     0,  1904,
       0,     0,     0,     0,     0,     0,  1908,     0,     0,  1909,
       0,     0,     0,  1913,     0,     0,     0,     0,     0,     0,
       0,  1916,     0,  1918,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1930,     0,     0,     0,   984,
       0,     0,     0,   987,     0,     0,     0,   991,     0,     0,
       0,     0,  1939,     0,  1941,     0,   574,   575,   576,   577,
       0,  1004,  1005,     0,  1521,     0,     0,     0,     0,  1011,
       0,     0,     0,     0,  1015,     0,     0,  1960,     0,  1020,
       0,  1022,     0,     0,     0,     0,  1965,     0,     0,   574,
     575,   576,   577,  1034,     0,  1036,  1037,  1522,  1039,  1040,
    1041,     0,     0,   119,   120,   121,  1045,   122,   123,   124,
     125,  1049,     0,     0,     0,     0,     0,     0,     0,  1055,
       0,     0,     0,     0,     0,     0,     0,  1062,     0,     0,
     126,   127,     0,     0,     0,     0,     0,     0,     0,   574,
     575,   576,   577,     0,     0,     0,     0,  1523,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,   129,   130,   131,   132,   133,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,     0,     0,   136,     0,     0,     0,     0,   298,
       0,     0,     0,     0,     0,     0,     0,   299,     0,     0,
       0,   138,   139,     0,     0,   140,     0,   141,     0,     0,
       0,     0,     0,     0,     0,   142,     0,     0,     0,     0,
       0,     0,   143,   564,   565,     0,   144,   145,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   573,     0,     0,
       0,     0,     0,     0,   146,   147,   148,   149,   150,   151,
       0,     0,     0,     0,     0,     0,   152,     0,     0,   153,
       0,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,     0,   207,   208,   209,   210,
       0,   211,   212,     0,   213,   214,   215,     0,   216,   217,
     218,   219,   220,   221,   222,     0,     0,     0,     0,     0,
     223,   224,     0,   225,     0,     0,     0,     0,     0,     0,
     226,     0,   300,     0,     0,     0,     0,     0,     0,   119,
     120,   121,     0,   122,   123,   124,   125,  1256,     0,     0,
       0,     0,     0,     0,     0,  1260,     0,     0,     0,     0,
    1265,     0,  1267,     0,  1269,  1270,   126,   127,     0,  1275,
    1276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   574,   575,   576,   577,     0,     0,     0,
       0,  1528,     0,     0,     0,     0,     0,     0,     0,   128,
     129,   130,   131,   132,   133,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,     0,     0,
     136,     0,     0,     0,     0,   137,     0,     0,     0,     0,
       0,     0,     0,   778,     0,     0,     0,   138,   139,     0,
       0,   140,     0,   141,     0,     0,     0,     0,     0,     0,
       0,   142,     0,     0,  1358,  1359,     0,     0,   143,   564,
     565,     0,   144,   145,     0,     0,   566,   567,   568,   569,
     570,   571,   572,   573,     0,     0,     0,     0,     0,  1374,
     146,   147,   148,   149,   150,   151,     0,     0,     0,     0,
       0,     0,   152,     0,     0,   153,     0,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,     0,   207,   208,   209,   210,     0,   211,   212,     0,
     213,   214,   215,     0,   216,   217,   218,   219,   220,   221,
     222,     0,     0,     0,     0,     0,   223,   224,     0,   225,
       0,     0,     0,     0,     0,     0,   226,     0,   300,   119,
     120,   121,     0,   122,   123,   124,   125,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   574,
     575,   576,   577,     0,     0,     0,     0,  1529,     0,   128,
     129,   130,   131,   132,   133,   134,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,     0,     0,
     136,     0,     0,     0,     0,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   139,     0,
       0,   140,     0,   141,     0,     0,     0,     0,     0,     0,
       0,   142,     0,     0,     0,     0,     0,     0,   143,   564,
     565,     0,   144,   145,     0,     0,   566,   567,   568,   569,
     570,   571,   572,   573,     0,     0,     0,     0,     0,     0,
     146,   147,   148,   149,   150,   151,     0,     0,     0,     0,
       0,     0,   152,     0,     0,   153,     0,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,     0,   207,   208,   209,   210,     0,   211,   212,     0,
     213,   214,   215,     0,   216,   217,   218,   219,   220,   221,
     222,  1595,     0,     0,  1598,     0,   223,   224,  1602,   225,
       0,     0,     0,     0,     0,     0,   226,     0,   300,     0,
       0,     0,     0,     0,     0,   119,   120,   121,     0,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1655,     0,     0,     0,     0,   574,
     575,   576,   577,     0,     0,     0,     0,  1534,     0,     0,
       0,     0,     0,     0,     0,   128,   129,   130,   131,   132,
     133,   134,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   135,     0,     0,   136,   564,   565,     0,
       0,   137,     0,     0,   566,   567,   568,   569,   570,   571,
     572,   573,     0,   138,   139,     0,     0,   140,     0,   141,
       0,     0,     0,     0,     0,     0,     0,   142,     0,     0,
       0,     0,     0,     0,   143,   564,   565,     0,   144,   145,
       0,     0,   566,   567,   568,   569,   570,   571,   572,   573,
       0,     0,     0,     0,     0,     0,   146,   147,   148,   149,
     150,   151,     0,     0,     0,     0,     0,     0,   152,     0,
       0,   153,     0,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,     0,   207,   208,
     209,   210,     0,   211,   212,  1782,   213,   214,   215,  1786,
     216,   217,   218,   219,   220,   221,   222,     0,     0,     0,
       0,     0,   223,   224,     0,   225,     0,     0,     0,     0,
       0,     0,   226,   756,   119,   120,   121,     0,   122,   123,
     124,   125,     0,     0,     0,     0,     0,   574,   575,   576,
     577,     0,     0,     0,     0,  1535,     0,     0,     0,     0,
       0,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   574,   575,   576,   577,     0,
       0,     0,     0,  1536,   128,   129,   130,   131,   132,   133,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,     0,     0,   136,   564,   565,     0,     0,
     137,     0,     0,   566,   567,   568,   569,   570,   571,   572,
     573,     0,   138,   139,     0,     0,   140,     0,   141,     0,
       0,     0,     0,     0,     0,     0,   142,     0,     0,     0,
       0,     0,     0,   143,   564,   565,     0,   144,   145,     0,
       0,   566,   567,   568,   569,   570,   571,   572,   573,     0,
       0,     0,     0,     0,     0,   146,   147,   148,   149,   150,
     151,     0,     0,     0,     0,     0,     0,   152,     0,     0,
     153,     0,     0,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,     0,   207,   208,   209,
     210,     0,   211,   212,     0,   213,   214,   215,     0,   216,
     217,   218,   219,   220,   221,   222,     0,     0,     0,     0,
       0,   223,   224,     0,   225,     0,     0,     0,     0,     0,
       0,   226,   833,   119,   120,   121,     0,   122,   123,   124,
     125,     0,     0,     0,     0,     0,   574,   575,   576,   577,
       0,     0,     0,     0,  1537,     0,     0,     0,     0,     0,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,   576,   577,     0,     0,
       0,     0,  1538,   128,   129,   130,   131,   132,   133,   134,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,     0,     0,   136,   564,   565,     0,     0,   137,
       0,     0,   566,   567,   568,   569,   570,   571,   572,   573,
       0,   138,   139,     0,     0,   140,     0,   141,     0,     0,
       0,     0,     0,     0,     0,   142,     0,     0,     0,     0,
       0,     0,   143,   564,   565,     0,   144,   145,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   573,     0,     0,
       0,     0,     0,     0,   146,   147,   148,   149,   150,   151,
       0,     0,     0,     0,     0,     0,   152,     0,     0,   153,
       0,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,     0,   207,   208,   209,   210,
       0,   211,   212,     0,   213,   214,   215,     0,   216,   217,
     218,   219,   220,   221,   222,     0,     0,     0,     0,     0,
     223,   224,     0,   225,     0,     0,     0,     0,     0,     0,
     226,   844,   119,   120,   121,     0,   122,   123,   124,   125,
       0,     0,     0,     0,     0,   574,   575,   576,   577,     0,
       0,     0,     0,  1541,     0,     0,     0,     0,     0,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   574,   575,   576,   577,     0,     0,     0,
       0,  1542,   128,   129,   130,   131,   132,   133,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,     0,     0,   136,     0,     0,     0,     0,   137,     0,
       0,     0,     0,     0,   398,     0,     0,     0,     0,     0,
     138,   139,     0,     0,   140,     0,   141,     0,     0,     0,
       0,     0,     0,     0,   142,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,   144,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   399,   400,   146,   147,   148,   149,   150,   151,     0,
     401,   402,   403,   404,     0,   152,     0,     0,   153,     0,
       0,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,     0,   207,   208,   209,   210,     0,
     211,   212,     0,   213,   214,   215,     0,   216,   217,   218,
     219,   220,   221,   222,     0,     0,     0,     0,     0,   223,
     224,     0,   225,     0,     0,     0,   119,   120,   121,   226,
     122,   123,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   406,     0,   128,   129,   130,   131,
     132,   133,   134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,     0,     0,   136,     0,     0,
       0,     0,   137,     0,     0,     0,     0,     0,   407,     0,
       0,     0,     0,     0,   138,   139,     0,     0,   140,     0,
     141,     0,     0,     0,     0,     0,     0,     0,   142,     0,
       0,     0,     0,     0,     0,   143,     0,     0,     0,   144,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   408,   409,   146,   147,   148,
     149,   150,   151,   410,     0,     0,     0,   411,     0,   152,
       0,     0,   153,     0,     0,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,     0,   207,
     208,   209,   210,     0,   211,   212,     0,   213,   214,   215,
       0,   216,   217,   218,   219,   220,   221,   222,     0,     0,
       0,     0,     0,   223,   224,     0,   225,     0,     0,     0,
     119,   120,   121,   226,   122,   123,   124,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   129,   130,   131,   132,   133,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
       0,   136,     0,     0,     0,     0,   137,     0,     0,     0,
       0,     0,   387,     0,     0,     0,     0,     0,   138,   139,
       0,     0,   140,     0,   141,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,   143,
       0,     0,     0,   144,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   388,
     389,   146,   147,   148,   149,   150,   151,     0,   390,     0,
       0,   391,     0,   152,     0,     0,   153,     0,     0,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,     0,   207,   208,   209,   210,     0,   211,   212,
       0,   213,   214,   215,     0,   216,   217,   218,   219,   220,
     221,   222,     0,     0,     0,     0,     0,   223,   224,     0,
     225,     0,     0,     0,   119,   120,   121,   226,   122,   123,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   356,     0,   128,   129,   130,   131,   132,   133,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,     0,     0,   136,     0,     0,     0,     0,
     137,     0,     0,     0,     0,     0,   357,     0,     0,     0,
       0,     0,   138,   139,     0,     0,   140,     0,   141,     0,
       0,     0,   358,     0,     0,     0,   142,     0,     0,     0,
       0,     0,     0,   143,     0,     0,     0,   144,   145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   359,     0,   146,   147,   148,   149,   150,
     151,     0,     0,     0,     0,     0,     0,   152,     0,     0,
     153,     0,     0,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,     0,   207,   208,   209,
     210,     0,   211,   212,     0,   213,   214,   215,     0,   216,
     217,   218,   219,   220,   221,   222,     0,     0,     0,     0,
       0,   223,   224,     0,   225,     0,     0,     0,   119,   120,
     121,   226,   122,   123,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,   129,
     130,   131,   132,   133,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,     0,   136,
       0,     0,     0,     0,   137,     0,     0,     0,     0,     0,
     393,     0,     0,     0,     0,     0,   138,   139,     0,     0,
     140,     0,   141,     0,     0,     0,     0,     0,     0,     0,
     142,     0,     0,     0,     0,     0,     0,   143,     0,     0,
       0,   144,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   394,   395,   146,
     147,   148,   149,   150,   151,     0,     0,     0,     0,   396,
       0,   152,     0,     0,   153,     0,     0,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
       0,   207,   208,   209,   210,     0,   211,   212,     0,   213,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
       0,     0,     0,     0,     0,   223,   224,     0,   225,     0,
       0,     0,   119,   120,   121,   226,   122,   123,   124,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   362,     0,     0,     0,     0,     0,     0,     0,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     363,     0,   128,   129,   130,   131,   132,   133,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,     0,     0,   136,   564,   565,     0,     0,   137,     0,
       0,   566,   567,   568,   569,   570,   571,   572,   573,     0,
     138,   139,     0,     0,   140,     0,   141,     0,     0,     0,
     364,     0,     0,     0,   142,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,   144,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   146,   147,   148,   149,   150,   151,     0,
       0,     0,     0,     0,     0,   152,     0,     0,   153,     0,
       0,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,     0,   207,   208,   209,   210,     0,
     211,   212,     0,   213,   214,   215,     0,   216,   217,   218,
     219,   220,   221,   222,     0,     0,     0,     0,     0,   223,
     224,     0,   225,     0,     0,     0,   119,   120,   121,   226,
     122,   123,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,   576,   577,     0,     0,
       0,     0,  1545,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,   129,   130,   131,
     132,   133,   134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,     0,     0,   136,   564,   565,
       0,     0,   137,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,     0,   138,   139,     0,     0,   140,     0,
     141,     0,     0,     0,   376,     0,     0,     0,   142,     0,
       0,     0,     0,     0,     0,   143,     0,     0,     0,   144,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   377,   378,   146,   147,   148,
     149,   150,   151,     0,     0,     0,     0,     0,     0,   152,
       0,     0,   153,     0,     0,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,     0,   207,
     208,   209,   210,     0,   211,   212,     0,   213,   214,   215,
       0,   216,   217,   218,   219,   220,   221,   222,     0,     0,
       0,     0,     0,   223,   224,     0,   225,     0,     0,     0,
     119,   120,   121,   226,   122,   123,   124,   125,     0,   315,
       0,     0,     0,     0,     0,     0,     0,     0,   574,   575,
     576,   577,     0,     0,     0,     0,  1553,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     316,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   129,   130,   131,   132,   133,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
       0,   136,   564,   565,     0,     0,   137,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,     0,   138,   139,
       0,     0,   140,     0,   141,     0,     0,     0,     0,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,   143,
       0,     0,     0,   144,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   147,   148,   149,   150,   151,     0,     0,     0,
       0,     0,     0,   152,     0,     0,   153,     0,     0,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,     0,   207,   208,   209,   210,     0,   211,   212,
       0,   213,   214,   215,     0,   216,   217,   218,   219,   220,
     221,   222,     0,     0,     0,     0,     0,   223,   224,     0,
     225,     0,     0,     0,   119,   120,   121,   226,   122,   123,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   574,   575,   576,   577,     0,     0,     0,     0,
    1556,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,   129,   130,   131,   132,   133,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,     0,     0,   136,     0,     0,     0,     0,
     137,     0,     0,     0,     0,     0,   353,     0,     0,     0,
       0,     0,   138,   139,     0,     0,   140,     0,   141,     0,
       0,     0,   354,     0,     0,     0,   142,     0,     0,     0,
       0,     0,     0,   143,     0,     0,     0,   144,   145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,   147,   148,   149,   150,
     151,     0,     0,     0,     0,     0,     0,   152,     0,     0,
     153,     0,     0,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,     0,   207,   208,   209,
     210,     0,   211,   212,     0,   213,   214,   215,     0,   216,
     217,   218,   219,   220,   221,   222,     0,     0,     0,     0,
       0,   223,   224,     0,   225,     0,     0,     0,   119,   120,
     121,   226,   122,   123,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,   129,
     130,   131,   132,   133,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,     0,   136,
     564,   565,     0,     0,   137,     0,     0,   566,   567,   568,
     569,   570,   571,   572,   573,     0,   138,   139,     0,     0,
     140,     0,   141,     0,     0,     0,     0,   453,   454,     0,
     142,     0,     0,     0,     0,     0,     0,   143,     0,     0,
       0,   144,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
     147,   148,   149,   150,   151,     0,     0,     0,     0,     0,
       0,   152,     0,     0,   153,     0,     0,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
       0,   207,   208,   209,   210,     0,   211,   212,     0,   213,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
       0,     0,     0,     0,     0,   223,   224,     0,   225,     0,
       0,     0,   119,   120,   121,   226,   122,   123,   124,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     574,   575,   576,   577,     0,     0,     0,     0,  1571,   126,
     127,     0,     0,   257,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,   129,   130,   131,   132,   133,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,     0,     0,   136,   564,   565,     0,     0,   137,     0,
       0,   566,   567,   568,   569,   570,   571,   572,   573,     0,
     138,   139,     0,     0,   140,     0,   141,     0,     0,     0,
       0,     0,     0,     0,   142,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,   144,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   146,   147,   148,   149,   150,   151,     0,
       0,     0,     0,     0,     0,   152,     0,     0,   153,     0,
       0,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,     0,   207,   208,   209,   210,     0,
     211,   212,     0,   213,   214,   215,     0,   216,   217,   218,
     219,   220,   221,   222,     0,     0,     0,     0,     0,   223,
     224,     0,   225,     0,     0,     0,   119,   120,   121,   226,
     122,   123,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,   576,   577,     0,     0,
       0,     0,  1680,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,   129,   130,   131,
     132,   133,   134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,     0,     0,   136,   564,   565,
       0,     0,   137,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,     0,   138,   139,     0,     0,   140,     0,
     141,     0,     0,     0,   318,     0,     0,     0,   142,     0,
       0,     0,     0,     0,     0,   143,     0,     0,     0,   144,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   146,   147,   148,
     149,   150,   151,     0,     0,     0,     0,     0,     0,   152,
       0,     0,   153,     0,     0,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,     0,   207,
     208,   209,   210,     0,   211,   212,     0,   213,   214,   215,
       0,   216,   217,   218,   219,   220,   221,   222,     0,     0,
       0,     0,     0,   223,   224,     0,   225,     0,     0,     0,
     119,   120,   121,   226,   122,   123,   124,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   574,   575,
     576,   577,     0,     0,     0,     0,  1684,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   129,   130,   131,   132,   133,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
       0,   136,   564,   565,     0,     0,   137,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,     0,   138,   139,
       0,     0,   140,     0,   141,     0,     0,     0,   349,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,   143,
       0,     0,     0,   144,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   147,   148,   149,   150,   151,     0,     0,     0,
       0,     0,     0,   152,     0,     0,   153,     0,     0,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,     0,   207,   208,   209,   210,     0,   211,   212,
       0,   213,   214,   215,     0,   216,   217,   218,   219,   220,
     221,   222,     0,     0,     0,     0,     0,   223,   224,     0,
     225,     0,     0,     0,   119,   120,   121,   226,   122,   123,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   574,   575,   576,   577,     0,     0,     0,     0,
    1743,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,   129,   130,   131,   132,   133,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,     0,     0,   136,   564,   565,     0,     0,
     137,     0,     0,   566,   567,   568,   569,   570,   571,   572,
     573,     0,   138,   139,     0,     0,   140,     0,   141,     0,
       0,     0,   351,     0,     0,     0,   142,     0,     0,     0,
       0,     0,     0,   143,     0,     0,     0,   144,   145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,   147,   148,   149,   150,
     151,     0,     0,     0,     0,     0,     0,   152,     0,     0,
     153,     0,     0,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,     0,   207,   208,   209,
     210,     0,   211,   212,     0,   213,   214,   215,     0,   216,
     217,   218,   219,   220,   221,   222,     0,     0,     0,     0,
       0,   223,   224,     0,   225,     0,     0,     0,   119,   120,
     121,   226,   122,   123,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   574,   575,   576,   577,
       0,     0,     0,     0,  1752,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,   129,
     130,   131,   132,   133,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,     0,   136,
     564,   565,     0,     0,   137,     0,     0,   566,   567,   568,
     569,   570,   571,   572,   573,     0,   138,   139,     0,     0,
     140,     0,   141,     0,     0,     0,   366,     0,     0,     0,
     142,     0,     0,     0,     0,     0,     0,   143,     0,     0,
       0,   144,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
     147,   148,   149,   150,   151,     0,     0,     0,     0,     0,
       0,   152,     0,     0,   153,     0,     0,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
       0,   207,   208,   209,   210,     0,   211,   212,     0,   213,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
       0,     0,     0,     0,     0,   223,   224,     0,   225,     0,
       0,     0,   119,   120,   121,   226,   122,   123,   124,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     574,   575,   576,   577,     0,     0,     0,     0,  1755,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,   129,   130,   131,   132,   133,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,     0,     0,   136,   564,   565,     0,     0,   137,     0,
       0,   566,   567,   568,   569,   570,   571,   572,   573,     0,
     138,   139,     0,     0,   140,     0,   141,     0,     0,     0,
     368,     0,     0,     0,   142,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,   144,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   146,   147,   148,   149,   150,   151,     0,
       0,     0,     0,     0,     0,   152,     0,     0,   153,     0,
       0,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,     0,   207,   208,   209,   210,     0,
     211,   212,     0,   213,   214,   215,     0,   216,   217,   218,
     219,   220,   221,   222,     0,     0,     0,     0,     0,   223,
     224,     0,   225,     0,     0,     0,   119,   120,   121,   226,
     122,   123,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,   576,   577,     0,     0,
       0,     0,  1756,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,   129,   130,   131,
     132,   133,   134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,     0,     0,   136,   564,   565,
       0,     0,   137,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,     0,   138,   139,     0,     0,   140,     0,
     141,     0,     0,     0,   380,     0,     0,     0,   142,     0,
       0,     0,     0,     0,     0,   143,     0,     0,     0,   144,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   146,   147,   148,
     149,   150,   151,     0,     0,     0,     0,     0,     0,   152,
       0,     0,   153,     0,     0,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,     0,   207,
     208,   209,   210,     0,   211,   212,     0,   213,   214,   215,
       0,   216,   217,   218,   219,   220,   221,   222,     0,     0,
       0,     0,     0,   223,   224,     0,   225,     0,     0,     0,
     119,   120,   121,   226,   122,   123,   124,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   574,   575,
     576,   577,     0,     0,     0,     0,  1758,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,   129,   130,   131,   132,   133,   134,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   135,     0,
       0,   136,   564,   565,     0,     0,   137,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,     0,   138,   139,
       0,     0,   140,     0,   141,     0,     0,     0,   383,     0,
       0,     0,   142,     0,     0,     0,     0,     0,     0,   143,
       0,     0,     0,   144,   145,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,   147,   148,   149,   150,   151,     0,     0,     0,
       0,     0,     0,   152,     0,     0,   153,     0,     0,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,     0,   207,   208,   209,   210,     0,   211,   212,
       0,   213,   214,   215,     0,   216,   217,   218,   219,   220,
     221,   222,     0,     0,     0,     0,     0,   223,   224,     0,
     225,     0,     0,     0,   119,   120,   121,   226,   122,   123,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   574,   575,   576,   577,     0,     0,     0,     0,
    1775,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,   129,   130,   131,   132,   133,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   135,     0,     0,   136,   564,   565,     0,     0,
     137,     0,     0,   566,   567,   568,   569,   570,   571,   572,
     573,     0,   138,   139,     0,     0,   140,     0,   141,     0,
       0,     0,   413,     0,     0,     0,   142,     0,     0,     0,
       0,     0,     0,   143,     0,     0,     0,   144,   145,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   146,   147,   148,   149,   150,
     151,     0,     0,     0,     0,     0,     0,   152,     0,     0,
     153,     0,     0,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,     0,   207,   208,   209,
     210,     0,   211,   212,     0,   213,   214,   215,     0,   216,
     217,   218,   219,   220,   221,   222,     0,     0,     0,     0,
       0,   223,   224,     0,   225,     0,     0,     0,   119,   120,
     121,   226,   122,   123,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   574,   575,   576,   577,
       0,     0,     0,     0,  1881,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,   129,
     130,   131,   132,   133,   134,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,     0,     0,   136,
     564,   565,     0,     0,   137,     0,     0,   566,   567,   568,
     569,   570,   571,   572,   573,     0,   138,   139,     0,     0,
     140,     0,   141,     0,     0,     0,   415,     0,     0,     0,
     142,     0,     0,     0,     0,     0,     0,   143,     0,     0,
       0,   144,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   146,
     147,   148,   149,   150,   151,     0,     0,     0,     0,     0,
       0,   152,     0,     0,   153,     0,     0,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
       0,   207,   208,   209,   210,     0,   211,   212,     0,   213,
     214,   215,     0,   216,   217,   218,   219,   220,   221,   222,
       0,     0,     0,     0,     0,   223,   224,     0,   225,     0,
       0,     0,   119,   120,   121,   226,   122,   123,   124,   125,
       0,   656,     0,     0,     0,     0,     0,     0,     0,     0,
     574,   575,   576,   577,     0,     0,     0,     0,  1894,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,   129,   130,   131,   132,   133,   134,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,     0,     0,   136,   564,   565,     0,     0,   137,     0,
       0,   566,   567,   568,   569,   570,   571,   572,   573,     0,
     138,   139,     0,     0,   140,     0,   141,     0,     0,     0,
       0,     0,     0,     0,   142,     0,     0,     0,     0,     0,
       0,   143,     0,     0,     0,   144,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   146,   147,   148,   149,   150,   151,     0,
       0,     0,     0,     0,     0,   152,     0,     0,   153,     0,
       0,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,     0,   207,   208,   209,   210,     0,
     211,   212,     0,   213,   214,   215,     0,   216,   217,   218,
     219,   220,   221,   222,     0,     0,     0,     0,     0,   223,
     224,     0,   225,     0,     0,     0,   119,   120,   121,   226,
     122,   123,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,   576,   577,     0,     0,
       0,     0,  1936,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,   129,   130,   131,
     132,   133,   134,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,     0,     0,   136,   564,   565,
       0,     0,   137,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,     0,   138,   139,     0,     0,   140,     0,
     141,     0,     0,     0,     0,     0,     0,     0,   142,     0,
       0,     0,     0,     0,     0,   143,     0,     0,     0,   144,
     145,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,     0,   125,     0,     0,     0,   146,   147,   148,
     149,   150,   151,     0,     0,     0,     0,     0,     0,   152,
       0,     0,   153,     0,   127,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,     0,   207,
     208,   209,   210,     0,   211,   212,     0,   213,   214,   215,
       0,   216,   217,   218,   219,   220,   221,   222,   140,     0,
     141,     0,     0,   223,   224,     0,   225,     0,     0,   121,
       0,     0,     0,   226,   125,     0,     0,     0,     0,   144,
     145,     0,     0,     0,     0,     0,     0,     0,   574,   575,
     576,   577,     0,     0,     0,   127,  1957,   234,   235,   236,
     237,   150,     0,     0,     0,     0,     0,     0,     0,   152,
       0,     0,   153,     0,     0,   154,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   176,   177,   178,
       0,     0,     0,   182,   183,   184,     0,   186,     0,   188,
     189,   190,     0,     0,     0,     0,   195,   196,   197,   198,
     199,     0,     0,   202,     0,   204,     0,   206,     0,   140,
     208,   141,   210,     0,     0,   212,     0,     0,   214,   215,
     121,   216,   217,     0,   219,   125,   221,     0,     0,     0,
     144,   145,     0,     0,   224,     0,     0,     0,     0,     0,
       0,     0,     0,   238,   855,     0,   127,     0,   234,   235,
     236,   237,   150,     0,     0,     0,     0,     0,     0,     0,
     152,     0,     0,   153,     0,     0,   154,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   176,   177,
     178,     0,     0,     0,   182,   183,   184,     0,   186,     0,
     188,   189,   190,     0,     0,     0,     0,   195,   196,   197,
     198,   199,     0,     0,   202,     0,   204,     0,   206,     0,
     140,   208,   141,   210,     0,     0,   212,     0,     0,   214,
     215,     0,   216,   217,     0,   219,     0,   221,     0,     0,
       0,   144,   145,     0,     0,   224,     0,   121,     0,     0,
       0,     0,   125,     0,   238,   857,     0,     0,     0,   234,
     235,   236,   237,   150,     0,     0,     0,     0,     0,     0,
       0,   152,     0,   127,   153,     0,     0,   154,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   176,
     177,   178,     0,     0,     0,   182,   183,   184,     0,   186,
       0,   188,   189,   190,     0,     0,     0,     0,   195,   196,
     197,   198,   199,     0,     0,   202,     0,   204,     0,   206,
       0,     0,   208,     0,   210,     0,     0,   212,     0,     0,
     214,   215,     0,   216,   217,     0,   219,   140,   221,   141,
       0,     0,     0,   370,     0,     0,   224,     0,     0,     0,
       0,     0,     0,     0,     0,   238,   859,     0,   144,   145,
       0,     0,     0,     0,   121,     0,     0,     0,     0,   125,
       0,     0,     0,     0,     0,     0,   234,   235,   236,   237,
     150,     0,     0,     0,     0,     0,     0,     0,   152,     0,
     127,   153,     0,     0,   154,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   176,   177,   178,     0,
       0,     0,   182,   183,   184,     0,   186,     0,   188,   189,
     190,     0,     0,     0,     0,   195,   196,   197,   198,   199,
       0,     0,   202,     0,   204,     0,   206,     0,     0,   208,
       0,   210,     0,     0,   212,     0,     0,   214,   215,     0,
     216,   217,     0,   219,   140,   221,   141,     0,     0,     0,
     417,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,   238,     0,     0,   144,   145,     0,     0,     0,
       0,   121,     0,     0,     0,     0,   125,     0,     0,     0,
       0,     0,     0,   234,   235,   236,   237,   150,     0,     0,
       0,     0,     0,     0,     0,   152,     0,   127,   153,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   176,   177,   178,     0,     0,     0,   182,
     183,   184,     0,   186,     0,   188,   189,   190,     0,     0,
       0,     0,   195,   196,   197,   198,   199,     0,     0,   202,
       0,   204,     0,   206,     0,     0,   208,     0,   210,     0,
       0,   212,     0,     0,   214,   215,     0,   216,   217,     0,
     219,   140,   221,   141,     0,     0,     0,   419,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,     0,   144,   145,     0,     0,     0,     0,   121,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
     234,   235,   236,   237,   150,     0,     0,     0,     0,     0,
       0,     0,   152,     0,   127,   153,     0,     0,   154,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,     0,     0,     0,   182,   183,   184,     0,
     186,     0,   188,   189,   190,     0,     0,     0,     0,   195,
     196,   197,   198,   199,     0,     0,   202,     0,   204,     0,
     206,     0,     0,   208,     0,   210,     0,     0,   212,     0,
       0,   214,   215,     0,   216,   217,     0,   219,   140,   221,
     141,     0,     0,     0,   421,     0,   121,   224,     0,     0,
       0,   125,     0,     0,     0,     0,   238,     0,     0,   144,
     145,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,     0,     0,   234,   235,   236,
     237,   150,     0,     0,     0,     0,     0,     0,     0,   152,
       0,     0,   153,     0,     0,   154,     0,   564,   565,     0,
       0,     0,     0,     0,   566,   567,   568,   569,   570,   571,
     572,   573,     0,     0,     0,     0,     0,   176,   177,   178,
       0,     0,     0,   182,   183,   184,     0,   186,     0,   188,
     189,   190,     0,     0,     0,     0,   195,   196,   197,   198,
     199,     0,     0,   202,     0,   204,   140,   206,   141,     0,
     208,     0,   210,     0,     0,   212,     0,     0,   214,   215,
       0,   216,   217,     0,   219,     0,   221,   144,   145,     0,
       0,     0,     0,   121,   224,     0,     0,     0,   125,     0,
       0,     0,     0,   238,     0,   234,   235,   236,   237,   150,
       0,   736,     0,     0,     0,     0,     0,   152,     0,   127,
     153,     0,     0,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   176,   177,   178,     0,     0,
       0,   182,   183,   184,     0,   186,     0,   188,   189,   190,
       0,     0,     0,     0,   195,   196,   197,   198,   199,     0,
       0,   202,     0,   204,     0,   206,     0,     0,   208,     0,
     210,     0,     0,   212,     0,     0,   214,   215,     0,   216,
     217,     0,   219,   140,   221,   141,     0,   574,   575,   576,
     577,     0,   224,     0,   121,  1972,     0,     0,     0,   125,
       0,   238,     0,     0,   144,   145,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,     0,   234,   235,   236,   237,   150,     0,   807,     0,
       0,     0,     0,     0,   152,     0,     0,   153,     0,     0,
     154,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,   177,   178,     0,     0,     0,   182,   183,
     184,     0,   186,     0,   188,   189,   190,     0,     0,     0,
       0,   195,   196,   197,   198,   199,   977,     0,   202,     0,
     204,     0,   206,     0,   140,   208,   141,   210,     0,     0,
     212,     0,     0,   214,   215,   121,   216,   217,     0,   219,
     125,   221,     0,     0,     0,   144,   145,     0,     0,   224,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
       0,   127,     0,   234,   235,   236,   237,   150,     0,     0,
       0,     0,     0,     0,     0,   152,     0,     0,   153,     0,
       0,   154,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   176,   177,   178,     0,     0,     0,   182,
     183,   184,     0,   186,     0,   188,   189,   190,     0,     0,
       0,     0,   195,   196,   197,   198,   199,  1367,     0,   202,
       0,   204,     0,   206,     0,   140,   208,   141,   210,     0,
       0,   212,     0,     0,   214,   215,   121,   216,   217,     0,
     219,   125,   221,     0,     0,     0,   144,   145,     0,     0,
     224,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,     0,   127,     0,   234,   235,   236,   237,   150,     0,
       0,     0,     0,     0,     0,     0,   152,     0,     0,   153,
       0,     0,   154,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176,   177,   178,     0,     0,     0,
     182,   183,   184,     0,   186,     0,   188,   189,   190,     0,
       0,     0,     0,   195,   196,   197,   198,   199,     0,     0,
     202,     0,   204,     0,   206,     0,   140,   208,   141,   210,
       0,     0,   212,     0,     0,   214,   215,   121,   216,   217,
       0,   219,   125,   221,     0,     0,     0,   144,   145,     0,
       0,   224,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,     0,   127,     0,   234,   235,   236,   237,   150,
       0,     0,     0,     0,     0,     0,     0,   152,     0,     0,
     153,     0,     0,   154,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   176,   177,   178,     0,     0,
       0,   182,   183,   184,     0,   186,     0,   188,   189,   190,
       0,     0,     0,     0,   195,   196,   197,   198,   199,     0,
       0,   202,     0,   204,     0,   206,     0,   140,   208,   141,
     210,     0,     0,   212,     0,     0,   214,   215,     0,   216,
     217,     0,   219,     0,   221,     0,     0,     0,   144,   145,
       0,     0,   224,     0,     0,     0,     0,     0,     0,     0,
       0,   238,     0,     0,     0,     0,   234,   235,   236,   237,
     150,     0,     0,     0,     0,     0,     0,     0,   152,     0,
       0,   153,     0,     0,   154,     0,     0,     0,     0,     0,
     564,   565,     0,     0,     0,     0,     0,   566,   567,   568,
     569,   570,   571,   572,   573,     0,   176,   177,   178,     0,
       0,     0,   182,   183,   184,     0,   186,     0,   188,   189,
     190,     0,     0,     0,     0,   195,   196,   197,   198,   199,
       0,     0,   202,     0,   204,     0,   206,     0,     0,   208,
       0,   210,     0,     0,   212,     0,     0,   214,   215,     0,
     216,   217,     0,   219,     0,   221,     0,     0,     7,     8,
       9,     0,     0,   224,     0,    10,     0,     0,     0,    11,
       0,    12,  1229,    13,    14,    15,    16,    17,  -469,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,     0,     0,     0,     0,    29,     0,     0,    30,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    37,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,    45,    46,    47,  -229,  -229,    48,    49,
      50,     0,    51,    52,    53,     0,     0,    54,  -229,     0,
      55,     0,    56,    57,     0,     0,     0,     0,    58,    59,
     574,   575,   576,   577,     0,    60,   630,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,     0,     0,
      86,    87,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      92,     0,     0,     0,     0,    93,     0,   564,   565,     0,
       0,     0,     0,     0,   566,   567,   568,   569,   570,   571,
     572,   573,     0,     0,     0,    94,     0,     0,     0,    95,
       0,     7,     8,     9,    96,     0,     0,    97,    10,     0,
       0,    98,    11,     0,    12,     0,    13,    14,    15,    16,
      17,  -469,     0,    18,    19,    20,    21,    22,    23,    24,
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
       0,     0,     0,    86,    87,    88,    89,   574,   575,   576,
     577,     0,     0,   647,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    90,    91,    92,     0,     0,     0,     0,    93,     0,
     564,   565,     0,     0,     0,     0,     0,   566,   567,   568,
     569,   570,   571,   572,   573,     0,     0,     0,    94,     0,
       0,     0,    95,     0,     7,     8,     9,    96,     0,     0,
      97,    10,     0,     0,    98,    11,     0,    12,     0,    13,
      14,    15,    16,    17,  -469,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,   -16,     0,
       0,     0,    29,   -16,     0,    30,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,   564,   565,
       0,    37,    38,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,    48,    49,    50,     0,    51,    52,
      53,     0,     0,    54,     0,     0,    55,     0,    56,    57,
       0,     0,     0,     0,    58,    59,     0,     0,     0,     0,
       0,    60,     0,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,     0,    80,    81,    82,    83,    84,    85,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
     574,   575,   576,   577,   564,   565,   974,     0,     0,     0,
       0,   566,   567,   568,   569,   570,   571,   572,   573,     0,
       0,     0,     0,     0,    90,    91,    92,   564,   565,     0,
       0,    93,     0,     0,   566,   567,   568,   569,   570,   571,
     572,   573,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,     0,     0,     0,    95,     0,     0,     0,     0,
      96,   564,   565,    97,     0,     0,     0,    98,   566,   567,
     568,   569,   570,   571,   572,   573,     0,     0,   574,   575,
     576,   577,   564,   565,  1094,     0,     0,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,   564,   565,     0,
       0,     0,     0,     0,   566,   567,   568,   569,   570,   571,
     572,   573,   564,   565,     0,     0,     0,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,   564,   565,     0,
       0,     0,     0,     0,   566,   567,   568,   569,   570,   571,
     572,   573,   564,   565,     0,     0,     0,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,   564,   565,     0,
       0,     0,     0,     0,   566,   567,   568,   569,   570,   571,
     572,   573,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,   576,   577,   564,   565,
    1095,     0,     0,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,     0,     0,     0,     0,   574,   575,   576,
     577,   564,   565,  1097,     0,     0,     0,     0,   566,   567,
     568,   569,   570,   571,   572,   573,   564,   565,     0,     0,
       0,     0,     0,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   564,   565,  1098,     0,     0,
       0,     0,   566,   567,   568,   569,   570,   571,   572,   573,
       0,     0,   574,   575,   576,   577,     0,     0,  1099,     0,
       0,     0,     0,     0,     0,     0,     0,   574,   575,   576,
     577,     0,     0,  1113,     0,     0,     0,     0,     0,     0,
       0,     0,   574,   575,   576,   577,     0,     0,  1144,     0,
       0,     0,     0,     0,     0,     0,     0,   574,   575,   576,
     577,     0,     0,  1151,     0,     0,     0,     0,     0,     0,
       0,     0,   574,   575,   576,   577,     0,     0,  1152,     0,
       0,     0,     0,     0,     0,     0,     0,   574,   575,   576,
     577,   564,   565,  1172,     0,     0,     0,     0,   566,   567,
     568,   569,   570,   571,   572,   573,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   574,   575,
     576,   577,   564,   565,  1224,     0,     0,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,     0,     0,     0,
       0,   574,   575,   576,   577,     0,     0,  1247,     0,     0,
       0,     0,     0,     0,     0,     0,   574,   575,   576,   577,
     564,   565,  1248,     0,     0,     0,     0,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   564,
     565,  1255,     0,     0,     0,     0,   566,   567,   568,   569,
     570,   571,   572,   573,   564,   565,     0,     0,     0,     0,
       0,   566,   567,   568,   569,   570,   571,   572,   573,   564,
     565,     0,     0,     0,     0,     0,   566,   567,   568,   569,
     570,   571,   572,   573,   564,   565,     0,     0,     0,     0,
       0,   566,   567,   568,   569,   570,   571,   572,   573,   564,
     565,     0,     0,     0,     0,     0,   566,   567,   568,   569,
     570,   571,   572,   573,   564,   565,     0,     0,     0,     0,
       0,   566,   567,   568,   569,   570,   571,   572,   573,     0,
       0,   574,   575,   576,   577,   564,   565,  1261,     0,     0,
       0,     0,   566,   567,   568,   569,   570,   571,   572,   573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   574,   575,   576,   577,   564,   565,  1262,     0,
       0,     0,     0,   566,   567,   568,   569,   570,   571,   572,
     573,   564,   565,     0,     0,     0,     0,     0,   566,   567,
     568,   569,   570,   571,   572,   573,     0,     0,     0,     0,
     574,   575,   576,   577,   564,   565,  1301,     0,     0,     0,
       0,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,     0,     0,  1354,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,   576,   577,     0,     0,
    1355,     0,     0,     0,     0,     0,     0,     0,     0,   574,
     575,   576,   577,     0,     0,  1422,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,   576,   577,     0,     0,
    1427,     0,     0,     0,     0,     0,     0,     0,     0,   574,
     575,   576,   577,     0,     0,  1441,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,   576,   577,   564,   565,
    1453,     0,     0,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,     0,     0,   574,   575,   576,   577,   564,
     565,  1458,     0,     0,     0,     0,   566,   567,   568,   569,
     570,   571,   572,   573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   574,   575,   576,   577,
       0,     0,  1459,     0,     0,     0,     0,     0,     0,     0,
       0,   574,   575,   576,   577,   564,   565,  1460,     0,     0,
       0,     0,   566,   567,   568,   569,   570,   571,   572,   573,
       0,     0,     0,     0,   574,   575,   576,   577,   564,   565,
    1489,     0,     0,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,   564,   565,     0,     0,     0,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   573,   564,   565,
       0,     0,     0,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,   564,   565,     0,     0,     0,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   573,   564,   565,
       0,     0,     0,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,   564,   565,     0,     0,     0,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
     576,   577,   564,   565,  1496,     0,     0,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,     0,     0,   574,
     575,   576,   577,   564,   565,  1501,     0,     0,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   573,   564,   565,
       0,     0,     0,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   574,   575,   576,   577,   564,
     565,  1504,     0,     0,     0,     0,   566,   567,   568,   569,
     570,   571,   572,   573,     0,     0,     0,     0,   574,   575,
     576,   577,     0,     0,  1533,     0,     0,     0,     0,     0,
       0,     0,     0,   574,   575,   576,   577,     0,     0,  1554,
       0,     0,     0,     0,     0,     0,     0,     0,   574,   575,
     576,   577,     0,     0,  1555,     0,     0,     0,     0,     0,
       0,     0,     0,   574,   575,   576,   577,     0,     0,  1577,
       0,     0,     0,     0,     0,     0,     0,     0,   574,   575,
     576,   577,     0,     0,  1591,     0,     0,     0,     0,     0,
       0,     0,     0,   574,   575,   576,   577,   564,   565,  1699,
       0,     0,     0,     0,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,   576,   577,   564,   565,  1700,     0,
       0,     0,     0,   566,   567,   568,   569,   570,   571,   572,
     573,     0,     0,   574,   575,   576,   577,     0,     0,  1701,
       0,     0,     0,     0,     0,     0,     0,     0,   574,   575,
     576,   577,   564,   565,  1703,     0,     0,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   574,
     575,   576,   577,   564,   565,  1708,     0,     0,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   573,   564,   565,
       0,     0,     0,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,   564,   565,     0,     0,     0,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   573,   564,   565,
       0,     0,     0,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,   564,   565,     0,     0,     0,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   573,   564,   565,
       0,     0,     0,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,     0,     0,     0,     0,   574,   575,   576,
     577,   564,   565,  1711,     0,     0,     0,     0,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
     564,   565,  1716,     0,     0,     0,     0,   566,   567,   568,
     569,   570,   571,   572,   573,   564,   565,     0,     0,     0,
       0,     0,   566,   567,   568,   569,   570,   571,   572,   573,
       0,     0,   574,   575,   576,   577,   564,   565,  1717,     0,
       0,     0,     0,   566,   567,   568,   569,   570,   571,   572,
     573,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   574,   575,   576,   577,     0,     0,  1728,
       0,     0,     0,     0,     0,     0,     0,     0,   574,   575,
     576,   577,     0,     0,  1729,     0,     0,     0,     0,     0,
       0,     0,     0,   574,   575,   576,   577,     0,     0,  1730,
       0,     0,     0,     0,     0,     0,     0,     0,   574,   575,
     576,   577,     0,     0,  1733,     0,     0,     0,     0,     0,
       0,     0,     0,   574,   575,   576,   577,     0,     0,  1737,
       0,     0,     0,     0,     0,     0,     0,     0,   574,   575,
     576,   577,   564,   565,  1751,     0,     0,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,     0,     0,     0,
       0,   574,   575,   576,   577,   564,   565,  1770,     0,     0,
       0,     0,   566,   567,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,     0,     0,  1789,     0,     0,     0,
       0,     0,     0,     0,     0,   574,   575,   576,   577,   564,
     565,  1790,     0,     0,     0,     0,   566,   567,   568,   569,
     570,   571,   572,   573,     0,     0,   574,   575,   576,   577,
     564,   565,  1793,     0,     0,     0,     0,   566,   567,   568,
     569,   570,   571,   572,   573,   564,   565,     0,     0,     0,
       0,     0,   566,   567,   568,   569,   570,   571,   572,   573,
     564,   565,     0,     0,     0,     0,     0,   566,   567,   568,
     569,   570,   571,   572,   573,   564,   565,     0,     0,     0,
       0,     0,   566,   567,   568,   569,   570,   571,   572,   573,
     564,   565,     0,     0,     0,     0,     0,   566,   567,   568,
     569,   570,   571,   572,   573,   564,   565,     0,     0,     0,
       0,     0,   566,   567,   568,   569,   570,   571,   572,   573,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   574,   575,   576,   577,   564,   565,  1799,     0,
       0,     0,     0,   566,   567,   568,   569,   570,   571,   572,
     573,     0,     0,     0,     0,   574,   575,   576,   577,   564,
     565,  1804,     0,     0,     0,     0,   566,   567,   568,   569,
     570,   571,   572,   573,   564,   565,     0,     0,     0,     0,
       0,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   564,   565,  1805,     0,     0,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   573,     0,     0,
     574,   575,   576,   577,     0,     0,  1806,     0,     0,     0,
       0,     0,     0,     0,     0,   574,   575,   576,   577,     0,
       0,  1809,     0,     0,     0,     0,     0,     0,     0,     0,
     574,   575,   576,   577,     0,     0,  1813,     0,     0,     0,
       0,     0,     0,     0,     0,   574,   575,   576,   577,     0,
       0,  1844,     0,     0,     0,     0,     0,     0,     0,     0,
     574,   575,   576,   577,     0,     0,  1846,     0,     0,     0,
       0,     0,     0,     0,     0,   574,   575,   576,   577,   564,
     565,  1847,     0,     0,     0,     0,   566,   567,   568,   569,
     570,   571,   572,   573,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   574,   575,   576,   577,
     564,   565,  1849,     0,     0,     0,     0,   566,   567,   568,
     569,   570,   571,   572,   573,     0,     0,     0,     0,   574,
     575,   576,   577,     0,     0,  1854,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,   576,   577,   564,   565,
    1857,     0,     0,     0,     0,   566,   567,   568,   569,   570,
     571,   572,   573,   574,   575,   576,   577,   564,   565,  1861,
       0,     0,     0,     0,   566,   567,   568,   569,   570,   571,
     572,   573,   564,   565,     0,     0,     0,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,   564,   565,     0,
       0,     0,     0,     0,   566,   567,   568,   569,   570,   571,
     572,   573,   564,   565,     0,     0,     0,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,   564,   565,     0,
       0,     0,     0,     0,   566,   567,   568,   569,   570,   571,
     572,   573,   564,   565,     0,     0,     0,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,     0,     0,   574,
     575,   576,   577,   564,   565,  1869,     0,     0,     0,     0,
     566,   567,   568,   569,   570,   571,   572,   573,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     574,   575,   576,   577,   564,   565,  1870,     0,     0,     0,
       0,   566,   567,   568,   569,   570,   571,   572,   573,   564,
     565,     0,     0,     0,     0,     0,   566,   567,   568,   569,
     570,   571,   572,   573,     0,     0,     0,     0,   574,   575,
     576,   577,   564,   565,  1871,     0,     0,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   576,
     577,     0,     0,  1877,     0,     0,     0,     0,     0,     0,
       0,     0,   574,   575,   576,   577,     0,     0,  1893,     0,
       0,     0,     0,     0,     0,     0,     0,   574,   575,   576,
     577,     0,     0,  1910,     0,     0,     0,     0,     0,     0,
       0,     0,   574,   575,   576,   577,     0,     0,  1912,     0,
       0,     0,     0,     0,     0,     0,     0,   574,   575,   576,
     577,     0,     0,  1914,     0,     0,     0,     0,     0,     0,
       0,     0,   574,   575,   576,   577,   564,   565,  1915,     0,
       0,     0,     0,   566,   567,   568,   569,   570,   571,   572,
     573,     0,     0,   574,   575,   576,   577,   564,   565,  1935,
       0,     0,     0,     0,   566,   567,   568,   569,   570,   571,
     572,   573,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   574,   575,   576,   577,     0,     0,
    1937,     0,     0,     0,     0,     0,     0,     0,     0,   574,
     575,   576,   577,     0,     0,  1944,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   574,   575,   576,   577,     0,     0,  1963,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   574,   575,   576,   577,
       0,     0,  1964,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   574,   575,   576,
     577,     0,     0,  1976
};

static const yytype_int16 yycheck[] =
{
       3,    15,    16,     4,    40,     1,     7,   251,     4,   456,
      12,     1,     4,    12,     4,     7,    44,    58,    21,    60,
      61,    24,     4,     5,    77,   269,    58,    41,    60,    61,
      33,    75,  1580,    75,    37,    38,     3,    61,   112,    42,
       7,     8,     9,    10,    77,    43,    44,   112,   113,    28,
      12,    54,    55,    56,     3,   112,   113,    53,     7,     8,
       9,    10,    23,    53,    76,    77,    12,    70,    71,    72,
     244,     4,     5,   112,   113,   249,     0,   251,   112,   113,
     249,   155,   251,    86,    87,    88,    13,   111,    25,   112,
     155,     7,    95,    96,    97,    98,    11,    95,   155,  1236,
    1237,    63,    64,    59,   425,   426,    95,    44,    70,    71,
      72,    73,    74,    75,    76,    77,   155,    63,    64,    20,
      21,   155,   110,    16,    70,    71,    72,    73,    74,    75,
      76,    77,   155,    89,    90,    91,    63,    64,   112,   113,
      96,    92,    93,    70,    71,    72,    73,    74,    75,    76,
      77,    44,   249,   104,   251,    70,    71,    72,    73,    74,
      75,    76,    63,    64,   249,     4,   251,   100,     7,    70,
      71,    72,    73,    74,    75,    76,    77,    28,   249,   249,
     251,   251,    33,    70,    71,    72,    73,    74,    75,    76,
     243,   244,   245,   246,   160,    70,    71,    72,    73,    74,
      75,    76,   184,   185,   186,   250,   250,   250,   250,     4,
       5,   252,   245,   246,   244,   250,   244,   244,    44,   249,
     252,   251,   249,   226,   251,   546,  1774,   548,   250,  1777,
     250,   243,   244,   245,   246,   238,    14,    75,    16,   244,
      18,    75,   244,    24,   247,   112,   251,   249,   112,   250,
     249,   184,   185,   186,   112,   251,   292,   293,   250,   244,
     263,   251,   162,    41,   249,   268,    44,   244,   244,     4,
       5,    49,   275,   269,   251,   251,   243,   244,   250,   269,
     250,   243,   244,   245,   246,   246,   244,   248,     4,     5,
    1838,   249,   155,  1841,   243,   244,   299,   243,   244,   245,
     246,    35,    36,   249,   161,   244,   244,   310,   311,   312,
     249,   249,   251,   251,   250,   318,   243,   244,   245,   246,
     250,    70,    71,    72,    73,    74,    75,    76,   250,   244,
     250,    70,    71,    72,    73,    74,    75,    76,   341,   342,
      81,    82,   243,   244,   245,   246,   349,    88,   351,   155,
     353,   354,   250,   356,   357,   358,   359,   244,   250,   362,
     363,   364,   249,   366,   251,   368,   610,   370,   250,   244,
     111,   374,   375,   376,   377,   378,   251,   380,   244,   250,
     383,   250,   244,   249,   387,   388,   389,   390,   391,   251,
     393,   394,   395,   396,   250,   398,   399,   400,   401,   402,
     403,   404,   244,   406,   407,   408,   409,   410,   411,   251,
     413,  1959,   415,  1961,   417,   250,   419,   244,   421,   250,
     423,   244,   249,   155,   251,   428,   249,    44,   251,  1977,
      71,  1979,    73,    74,    75,    76,    77,   440,    75,    76,
      77,   244,   244,   250,  1581,   244,   249,  1584,   451,   251,
     453,    44,   251,   451,   452,   155,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,    63,    64,   481,     4,
       5,   442,   443,    70,    71,    72,    73,    74,    75,    76,
      77,   244,     4,     5,   492,   244,   249,   244,   251,   502,
     503,   504,   505,   506,   251,   244,   509,     4,     5,   512,
     250,   514,   251,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   250,   526,   527,   528,   529,   530,   531,   532,
     533,   248,   249,   536,   532,   538,   539,   540,   541,   542,
     244,   250,   545,   244,   547,   249,   549,   550,   551,     4,
     251,  1688,   555,   556,   557,   558,   559,   560,   561,   562,
      86,    87,   244,    44,    73,    74,    75,    76,    77,   251,
     244,   244,   250,   534,   535,   249,   249,   251,   251,   244,
     244,   244,    63,    64,   249,   249,   251,   251,   251,    70,
      71,    72,    73,    74,    75,    76,    77,   250,    46,   250,
     636,   250,   243,   244,   245,   246,   243,   244,   245,   246,
     613,   244,   244,   244,   610,    63,    64,    46,   251,   251,
     610,   250,    70,    71,    72,    73,    74,    75,    76,    77,
     244,   244,   244,   244,    63,    64,   249,   251,   641,   251,
     251,    70,    71,    72,    73,    74,    75,    76,    77,     4,
       5,   654,    74,    75,    76,    77,   243,   244,   245,   246,
     244,   244,   249,    58,   251,   626,   627,   251,   251,   250,
     631,   632,   244,   250,   677,   919,   679,   249,    70,    71,
      72,    73,    74,    75,    76,   688,   250,   244,    51,    49,
      50,   244,   244,   696,   251,   244,   699,   700,   251,   251,
      63,    64,   251,  1840,    39,    40,  1843,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,   235,   236,   237,
     238,   239,    70,    71,    72,    73,    74,    75,    76,    77,
     250,   244,   249,   736,   243,   244,   245,   246,   251,   742,
     250,   744,   250,   746,   244,   748,  1193,   750,   244,  1196,
     249,   251,     4,     5,   249,   251,   759,   760,  1895,    63,
      64,  1898,   243,   244,   245,   246,    70,    71,    72,    73,
      74,    75,    76,    77,   244,    63,    64,     4,     5,    60,
      61,   251,    70,    71,    72,    73,    74,    75,    76,    77,
     250,   250,   244,   244,   244,   243,   244,   245,   246,   251,
     251,   251,   330,   331,   807,   333,   244,   250,    14,   812,
      16,   244,    18,   251,   243,   244,   245,   246,   251,   347,
     348,   243,   244,   245,   246,     3,   244,   355,   249,     7,
       8,     9,   360,   251,  1971,    41,  1973,   365,    44,   367,
      14,   244,    16,    49,    18,   244,  1983,  1984,   251,   250,
     249,   379,   244,   381,   382,   244,   384,   385,   386,   251,
     250,   244,   251,   250,   392,   244,   244,    41,   251,   397,
      44,   244,   251,   251,   250,    49,   250,   405,   251,   244,
     243,   244,   245,   246,   412,    14,   251,    16,   250,    18,
      60,    61,   244,   244,   250,   243,   244,   245,   246,   251,
     251,   249,   249,   251,    70,    71,    72,    73,    74,    75,
      76,   244,    41,   927,   928,    44,   249,   244,   250,   244,
      49,   244,   249,   919,   249,   244,   249,   249,   244,   919,
     249,   244,   935,   249,    43,   250,   249,   249,   244,   243,
     244,   245,   246,   249,   244,   249,   249,   251,   951,   249,
     249,   954,   250,   250,   957,   243,   244,   245,   246,   244,
     244,   249,   244,   251,   249,   249,   249,   249,   929,   930,
     244,   932,   933,   250,   244,   249,  1220,   250,   981,   249,
     244,   244,   985,   244,   250,   249,   249,   244,   249,   992,
     244,   250,   249,   996,   244,   249,   999,   244,   244,   249,
     244,   244,   249,   249,   249,   249,   249,  1010,   244,  1012,
    1013,  1014,   244,   249,  1017,  1018,  1019,   249,  1021,   244,
     244,   250,  1025,   244,   249,   249,  1029,  1030,   249,  1032,
     244,   244,  1035,   244,   250,   249,   249,   244,   249,  1042,
    1043,   244,   249,  1046,    77,   250,   249,  1050,  1051,  1052,
    1053,   244,   250,  1056,   244,   250,   249,  1060,   250,   249,
    1063,   250,    63,    64,  1067,   250,  1069,   250,  1071,    70,
      71,    72,    73,    74,    75,    76,    77,   244,   244,   244,
     244,   244,   249,   249,   249,   249,   249,   244,   244,  1085,
     250,   244,   249,   249,   244,  1085,   249,   249,  1101,   249,
    1103,   250,  1105,   250,    70,    71,    72,    73,    74,    75,
      76,  1114,  1073,   250,   244,   643,   250,   250,  1121,   249,
     251,    70,    71,    72,    73,    74,    75,    76,   244,   657,
     244,   250,   244,   249,   662,   249,   664,   249,   666,   667,
     250,   244,   244,   244,   672,   673,   249,   249,   249,    63,
      64,  1154,   250,   250,   250,   250,    70,    71,    72,    73,
      74,    75,    76,    77,   250,   250,   250,   250,   250,  1172,
    1173,  1174,  1175,    63,    64,   250,   250,   250,  1181,   250,
      70,    71,    72,    73,    74,    75,    76,    77,   250,   250,
     244,  1194,    63,    64,  1197,   249,  1199,   250,   250,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,   250,
     250,   250,   250,   250,    70,    71,    72,    73,    74,    75,
      76,    77,   244,  1226,  1220,   250,  1229,   249,   244,   244,
    1220,   244,   250,   249,   249,   244,   249,   765,   766,   250,
     249,   244,   243,   244,   245,   246,   249,     5,   249,   249,
     251,  1254,  1255,   244,  1252,  1253,  1259,   244,   249,    63,
    1263,   789,   249,   251,   250,   250,    70,    71,    72,    73,
      74,    75,    76,    77,  1277,  1278,   244,  1280,   244,  1282,
     250,   249,  1285,   249,  1245,  1246,  1289,  1290,   244,   250,
     250,   250,  1295,   249,  1297,   244,  1299,   244,  1301,   251,
     249,   251,   249,   244,  1307,    75,  1309,  1310,   249,  1312,
    1313,  1314,   250,   244,   244,   244,   250,  1320,   249,   249,
     249,  1324,   244,   249,    43,   250,   250,   249,  1331,   243,
     244,   245,   246,   244,   249,  1338,   244,  1340,   249,  1342,
     244,   249,  1345,   244,  1347,   249,  1349,   249,   249,    46,
     250,  1354,  1355,   243,   244,   245,   246,   244,   244,   244,
     244,   251,   249,   249,   249,   249,   244,   250,    58,   250,
      10,   249,   243,   244,   245,   246,   244,   244,   244,   244,
     251,   249,   249,   249,   249,   249,   244,   243,   244,   245,
     246,   249,   249,    63,    64,   251,   249,  1411,  1412,   249,
      70,    71,    72,    73,    74,    75,    76,    77,   244,   249,
      63,    64,   250,   249,  1417,   249,   249,    70,    71,    72,
      73,    74,    75,    76,    77,   249,  1429,   244,   244,   244,
    1674,  1675,   249,   249,   249,   249,   249,   249,  1441,   243,
     244,   245,   246,  1446,  1447,   251,   244,   249,   251,  1452,
    1453,   249,  1455,  1456,   251,   251,    70,    71,    72,    73,
      74,    75,    76,   250,   244,   244,   244,   250,  1471,   249,
     249,   249,  1475,  1434,  1435,   251,   244,   244,  1481,   244,
    1483,   249,   249,   244,   249,   251,  1489,   251,   249,  1492,
    1493,   251,    70,    71,    72,    73,    74,    75,    76,   244,
    1503,  1504,   251,  1506,   249,  1508,    63,    64,   251,    43,
     250,    85,   251,    70,    71,    72,    73,    74,    75,    76,
      77,   244,  1766,  1526,    63,    64,   249,   251,   250,  1532,
     250,    70,    71,    72,    73,    74,    75,    76,    77,   251,
    1543,   244,   244,   244,  1547,   244,   249,   249,   249,    85,
     249,  1554,     5,   251,  1557,   249,   249,  1560,    70,    71,
      72,    73,    74,    75,    76,   244,   244,   249,   249,   249,
     249,   249,  1575,   243,   244,   245,   246,   244,   249,   244,
     244,   251,   249,  1827,   249,   249,  1830,  1590,  1591,  1592,
     243,   244,   245,   246,   244,   244,   251,   244,   251,   249,
     249,  1604,   249,   244,  1607,   244,   249,  1610,   249,   244,
     249,  1614,   244,  1616,   249,   244,   249,   249,   244,  1622,
     249,  1624,   244,   249,  1627,  1628,   244,   249,  1631,   249,
     244,   249,   249,   244,     2,   249,   249,  1640,   249,  1883,
     244,  1644,   249,   249,  1647,   249,  1649,  1650,  1651,    17,
    1653,   249,   249,    70,    71,    72,    73,    74,    75,    76,
     249,   249,    30,   249,   251,    33,   244,   244,    36,    37,
      38,   249,   249,   249,    42,    43,    44,   244,  1674,  1675,
     251,   251,   249,    51,  1674,  1675,   243,   244,   245,   246,
    1693,   244,   249,   244,  1697,   244,   249,  1700,   249,   251,
     249,   251,    58,   244,   243,   244,   245,   246,   249,    63,
      64,   249,   251,   250,    43,   250,    70,    71,    72,    73,
      74,    75,    76,    77,   244,   244,   249,    95,   249,   249,
     249,  1734,   244,  1736,  1737,   244,  1739,   249,   249,  1267,
     249,   244,  1270,    63,    64,   249,   249,  1275,    38,   251,
      70,    71,    72,    73,    74,    75,    76,    77,   244,   244,
     250,   244,   130,   249,   249,  1768,   249,   244,   244,   244,
    1766,   251,   249,   249,   249,   244,  1766,   244,   244,   244,
     249,   251,   249,   249,   249,  1788,  1789,  1790,  1791,   244,
    1793,  1794,    43,   250,   249,  1798,     5,    58,    75,  1802,
     251,    10,  1805,  1806,  1807,   251,  1809,    75,    75,    48,
    1813,  1814,    58,   250,   249,   251,  1819,   251,   250,  1822,
    1823,   250,    31,    47,   250,   250,    58,   244,    75,   251,
    1358,  1827,   249,   251,  1830,    38,  1839,  1827,   250,   250,
    1830,   249,  1845,  1846,   249,  1848,  1849,  1375,     4,     4,
    1085,    53,    53,   456,   636,   935,     5,   225,   226,   931,
    1748,  1417,  1955,  1232,   934,   649,    -1,  1870,    -1,    -1,
     633,  1874,    -1,  1876,  1877,    -1,    -1,   245,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,  1883,  1891,   243,
     244,   245,   246,  1883,    -1,   263,   105,   251,   107,    -1,
     268,    -1,    -1,    -1,  1907,    -1,    -1,   275,  1911,    -1,
      -1,  1914,  1915,    -1,    -1,    -1,  1919,   126,   127,    -1,
    1923,    -1,    -1,   243,   244,   245,   246,    -1,    -1,  1932,
     298,   251,   300,    -1,  1937,   144,   145,   146,   147,   148,
      -1,    -1,    -1,  1946,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,
    1963,  1964,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,  1976,    -1,   184,   185,   186,  1981,    -1,
      -1,   190,   191,   192,    -1,   194,    -1,   196,   197,   198,
      -1,    -1,    -1,    -1,   203,   204,   205,   206,   207,    -1,
      -1,   210,    -1,   212,    -1,   214,    -1,    -1,   217,    -1,
     219,    -1,    -1,   222,    -1,    -1,   225,   226,    -1,   228,
     229,    -1,   231,    -1,   233,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   241,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,   250,   251,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,   427,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
    1598,   439,    -1,    -1,  1602,    -1,   444,   445,    -1,   447,
     448,   449,   450,   451,   452,    63,    64,    -1,    -1,    -1,
     458,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   482,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,    -1,   243,   244,   245,   246,   507,
     508,   509,   510,   511,    -1,   513,    -1,   515,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   525,    -1,    -1,
      -1,    -1,    -1,    -1,   532,    63,    64,    -1,    -1,   537,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,   576,   577,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,
      -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,    -1,
      -1,   251,    -1,   611,    -1,    63,    64,    -1,   616,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   629,   630,    -1,    -1,   243,   244,   245,   246,    -1,
      -1,    -1,    -1,   251,   642,    -1,     3,     4,     5,   647,
       7,     8,     9,    10,    -1,    90,    91,    92,    93,    94,
     658,   659,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   104,
      -1,    -1,    -1,    30,    31,   110,   111,    -1,    -1,    -1,
      -1,   116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,
     243,   244,   245,   246,    -1,    -1,    -1,    -1,    -1,    -1,
     698,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,   243,   244,   245,   246,    -1,
      -1,    -1,    -1,   251,    81,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    89,   243,   244,   245,   246,    -1,    -1,    -1,
      97,   251,    -1,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,   110,    -1,    -1,    -1,    -1,   115,    -1,
      -1,   759,   760,   761,   762,   122,    63,    64,    -1,   126,
     127,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,   243,   244,   245,   246,   156,
      -1,    -1,   159,   251,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,    -1,   216,
     217,   218,   219,    -1,   221,   222,    -1,   224,   225,   226,
      -1,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,    -1,   240,   241,    -1,   243,    -1,    -1,    -1,
      -1,    -1,    -1,   250,    -1,   252,    -1,    -1,    -1,    63,
      64,    -1,    -1,    -1,   902,   903,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,   922,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   935,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,
     948,    -1,    -1,    -1,   251,    -1,   954,   955,    -1,    63,
      64,    -1,   960,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   974,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,   994,    -1,    -1,    -1,
      -1,   999,  1000,  1001,    -1,    -1,    -1,    -1,  1006,    -1,
    1008,    -1,  1010,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1019,    -1,    -1,    -1,  1023,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1031,    -1,  1033,    -1,    -1,    -1,    -1,
    1038,    -1,    -1,    -1,  1042,  1043,  1044,    -1,    -1,  1047,
    1048,    -1,    -1,  1051,    -1,    -1,  1054,    -1,    -1,  1057,
      -1,  1059,    -1,  1061,    -1,    -1,    -1,  1065,    -1,  1067,
      -1,    -1,    -1,    -1,    -1,    -1,  1074,  1075,  1076,   243,
     244,   245,   246,    -1,    -1,    -1,    -1,   251,  1086,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1094,  1095,    -1,  1097,
    1098,  1099,   243,   244,   245,   246,    -1,    -1,    -1,    -1,
     251,    -1,  1110,  1111,    -1,  1113,    63,    64,  1116,  1117,
    1118,    -1,  1120,    70,    71,    72,    73,    74,    75,    76,
      77,  1129,    -1,    -1,  1132,    -1,    -1,    -1,    -1,   243,
     244,   245,   246,    -1,    -1,    -1,  1144,   251,    -1,  1147,
    1148,  1149,    -1,  1151,  1152,    -1,    -1,   243,   244,   245,
     246,    -1,  1160,    63,    64,   251,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
    1188,    -1,  1190,  1191,  1192,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,  1204,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,  1224,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,  1234,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1247,
    1248,    -1,    -1,    -1,  1252,  1253,    -1,    -1,    63,    64,
      -1,    -1,    -1,  1261,  1262,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    47,    48,   243,   244,   245,   246,
      -1,    -1,    -1,    -1,   251,    58,    -1,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    -1,    -1,    -1,  1334,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,    -1,    63,    64,
      -1,   251,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,   245,   246,    -1,    -1,    -1,    -1,   251,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1417,
      -1,    -1,    -1,    -1,  1422,    -1,    -1,    -1,    -1,  1427,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,    -1,
    1458,  1459,  1460,   251,  1462,    -1,    -1,    -1,    -1,    -1,
    1468,    -1,    -1,    -1,  1472,  1473,    -1,    63,    64,    -1,
    1478,    -1,  1480,  1481,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,  1492,    -1,    -1,  1495,  1496,    -1,
    1498,    -1,    -1,  1501,    -1,    -1,    -1,    -1,  1506,    -1,
      63,    64,    -1,    -1,    -1,  1513,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,  1531,    -1,  1533,   251,    -1,    -1,    -1,
      -1,  1539,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1548,    -1,  1550,    -1,    -1,    -1,   309,  1555,    -1,    -1,
      -1,    -1,   315,    -1,    -1,    -1,  1564,    -1,    -1,   322,
     323,    -1,    -1,    -1,    -1,    -1,  1574,    -1,    -1,  1577,
      -1,   334,   335,   336,   337,   338,   339,   340,    -1,    -1,
     343,   344,   345,   346,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1605,  1606,    -1,
      -1,  1609,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1617,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1625,  1626,    -1,
      -1,    -1,  1630,    -1,    -1,    63,    64,  1635,    -1,    -1,
      -1,  1639,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,  1654,   243,   244,   245,
     246,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1676,    -1,
      -1,    -1,    -1,   436,   437,   438,    -1,    -1,    -1,  1687,
     243,   244,   245,   246,    -1,    -1,    -1,    -1,   251,    -1,
      -1,  1699,    -1,  1701,   457,  1703,    -1,    -1,    -1,    -1,
    1708,    -1,    -1,  1711,    -1,  1713,    -1,    -1,  1716,  1717,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1726,    -1,
    1728,  1729,  1730,    -1,    -1,  1733,    63,    64,    -1,    -1,
      -1,  1739,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,  1751,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1761,    -1,    -1,    -1,    -1,    -1,    63,
      64,  1769,  1770,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1796,    -1,
      -1,  1799,    -1,    -1,    -1,  1803,  1804,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,    63,
      64,    -1,    -1,   251,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1842,    -1,  1844,    -1,    -1,  1847,
      -1,    -1,    -1,    -1,    -1,    -1,  1854,    -1,    -1,  1857,
      -1,    -1,    -1,  1861,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1869,    -1,  1871,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1893,    -1,    -1,    -1,   652,
      -1,    -1,    -1,   656,    -1,    -1,    -1,   660,    -1,    -1,
      -1,    -1,  1910,    -1,  1912,    -1,   243,   244,   245,   246,
      -1,   674,   675,    -1,   251,    -1,    -1,    -1,    -1,   682,
      -1,    -1,    -1,    -1,   687,    -1,    -1,  1935,    -1,   692,
      -1,   694,    -1,    -1,    -1,    -1,  1944,    -1,    -1,   243,
     244,   245,   246,   706,    -1,   708,   709,   251,   711,   712,
     713,    -1,    -1,     3,     4,     5,   719,     7,     8,     9,
      10,   724,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   732,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   740,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,   245,   246,    -1,    -1,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    63,    64,    -1,   126,   127,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,    -1,   216,   217,   218,   219,
      -1,   221,   222,    -1,   224,   225,   226,    -1,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,    -1,
     240,   241,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
     250,    -1,   252,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,     8,     9,    10,   980,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   988,    -1,    -1,    -1,    -1,
     993,    -1,   995,    -1,   997,   998,    30,    31,    -1,  1002,
    1003,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,    -1,
      -1,   251,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,  1087,  1088,    -1,    -1,   122,    63,
      64,    -1,   126,   127,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,  1112,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,    -1,   216,   217,   218,   219,    -1,   221,   222,    -1,
     224,   225,   226,    -1,   228,   229,   230,   231,   232,   233,
     234,    -1,    -1,    -1,    -1,    -1,   240,   241,    -1,   243,
      -1,    -1,    -1,    -1,    -1,    -1,   250,    -1,   252,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,   245,   246,    -1,    -1,    -1,    -1,   251,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    63,
      64,    -1,   126,   127,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,    -1,   216,   217,   218,   219,    -1,   221,   222,    -1,
     224,   225,   226,    -1,   228,   229,   230,   231,   232,   233,
     234,  1454,    -1,    -1,  1457,    -1,   240,   241,  1461,   243,
      -1,    -1,    -1,    -1,    -1,    -1,   250,    -1,   252,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1517,    -1,    -1,    -1,    -1,   243,
     244,   245,   246,    -1,    -1,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,
      -1,    89,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,    63,    64,    -1,   126,   127,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,   159,    -1,    -1,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,    -1,   216,   217,
     218,   219,    -1,   221,   222,  1698,   224,   225,   226,  1702,
     228,   229,   230,   231,   232,   233,   234,    -1,    -1,    -1,
      -1,    -1,   240,   241,    -1,   243,    -1,    -1,    -1,    -1,
      -1,    -1,   250,   251,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,
     246,    -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,    -1,
      -1,    -1,    -1,   251,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,
      89,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    63,    64,    -1,   126,   127,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,    -1,   216,   217,   218,
     219,    -1,   221,   222,    -1,   224,   225,   226,    -1,   228,
     229,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
      -1,   240,   241,    -1,   243,    -1,    -1,    -1,    -1,    -1,
      -1,   250,   251,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,
      -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,
      -1,    -1,   251,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    63,    64,    -1,   126,   127,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,    -1,   216,   217,   218,   219,
      -1,   221,   222,    -1,   224,   225,   226,    -1,   228,   229,
     230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,    -1,
     240,   241,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
     250,   251,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,    -1,
      -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,    -1,
      -1,   251,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,   143,   144,   145,   146,   147,   148,   149,    -1,
     151,   152,   153,   154,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,    -1,   216,   217,   218,   219,    -1,
     221,   222,    -1,   224,   225,   226,    -1,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,    -1,   240,
     241,    -1,   243,    -1,    -1,    -1,     3,     4,     5,   250,
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
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,
     147,   148,   149,   150,    -1,    -1,    -1,   154,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,    -1,   216,
     217,   218,   219,    -1,   221,   222,    -1,   224,   225,   226,
      -1,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,    -1,   240,   241,    -1,   243,    -1,    -1,    -1,
       3,     4,     5,   250,     7,     8,     9,    10,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,   144,   145,   146,   147,   148,   149,    -1,   151,    -1,
      -1,   154,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,    -1,   216,   217,   218,   219,    -1,   221,   222,
      -1,   224,   225,   226,    -1,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,    -1,   240,   241,    -1,
     243,    -1,    -1,    -1,     3,     4,     5,   250,     7,     8,
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
     159,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,    -1,   216,   217,   218,
     219,    -1,   221,   222,    -1,   224,   225,   226,    -1,   228,
     229,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
      -1,   240,   241,    -1,   243,    -1,    -1,    -1,     3,     4,
       5,   250,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,   143,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,   154,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
      -1,   216,   217,   218,   219,    -1,   221,   222,    -1,   224,
     225,   226,    -1,   228,   229,   230,   231,   232,   233,   234,
      -1,    -1,    -1,    -1,    -1,   240,   241,    -1,   243,    -1,
      -1,    -1,     3,     4,     5,   250,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
     111,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,    -1,   216,   217,   218,   219,    -1,
     221,   222,    -1,   224,   225,   226,    -1,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,    -1,   240,
     241,    -1,   243,    -1,    -1,    -1,     3,     4,     5,   250,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,
      -1,    -1,   251,    30,    31,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   142,   143,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,    -1,   216,
     217,   218,   219,    -1,   221,   222,    -1,   224,   225,   226,
      -1,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,    -1,   240,   241,    -1,   243,    -1,    -1,    -1,
       3,     4,     5,   250,     7,     8,     9,    10,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,    -1,    -1,    -1,   251,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,    -1,   216,   217,   218,   219,    -1,   221,   222,
      -1,   224,   225,   226,    -1,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,    -1,   240,   241,    -1,
     243,    -1,    -1,    -1,     3,     4,     5,   250,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,    -1,    -1,    -1,    -1,
     251,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     159,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,    -1,   216,   217,   218,
     219,    -1,   221,   222,    -1,   224,   225,   226,    -1,   228,
     229,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
      -1,   240,   241,    -1,   243,    -1,    -1,    -1,     3,     4,
       5,   250,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
      -1,   216,   217,   218,   219,    -1,   221,   222,    -1,   224,
     225,   226,    -1,   228,   229,   230,   231,   232,   233,   234,
      -1,    -1,    -1,    -1,    -1,   240,   241,    -1,   243,    -1,
      -1,    -1,     3,     4,     5,   250,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,   245,   246,    -1,    -1,    -1,    -1,   251,    30,
      31,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,    -1,   216,   217,   218,   219,    -1,
     221,   222,    -1,   224,   225,   226,    -1,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,    -1,   240,
     241,    -1,   243,    -1,    -1,    -1,     3,     4,     5,   250,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,
      -1,    -1,   251,    30,    31,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   159,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,    -1,   216,
     217,   218,   219,    -1,   221,   222,    -1,   224,   225,   226,
      -1,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,    -1,   240,   241,    -1,   243,    -1,    -1,    -1,
       3,     4,     5,   250,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,    -1,    -1,    -1,   251,    30,    31,    -1,
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
      -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,    -1,   216,   217,   218,   219,    -1,   221,   222,
      -1,   224,   225,   226,    -1,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,    -1,   240,   241,    -1,
     243,    -1,    -1,    -1,     3,     4,     5,   250,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,    -1,    -1,    -1,    -1,
     251,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     159,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,    -1,   216,   217,   218,
     219,    -1,   221,   222,    -1,   224,   225,   226,    -1,   228,
     229,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
      -1,   240,   241,    -1,   243,    -1,    -1,    -1,     3,     4,
       5,   250,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,
      -1,    -1,    -1,    -1,   251,    30,    31,    -1,    -1,    -1,
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
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
      -1,   216,   217,   218,   219,    -1,   221,   222,    -1,   224,
     225,   226,    -1,   228,   229,   230,   231,   232,   233,   234,
      -1,    -1,    -1,    -1,    -1,   240,   241,    -1,   243,    -1,
      -1,    -1,     3,     4,     5,   250,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,   245,   246,    -1,    -1,    -1,    -1,   251,    30,
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
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,    -1,   216,   217,   218,   219,    -1,
     221,   222,    -1,   224,   225,   226,    -1,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,    -1,   240,
     241,    -1,   243,    -1,    -1,    -1,     3,     4,     5,   250,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,
      -1,    -1,   251,    30,    31,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   159,    -1,    -1,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,    -1,   216,
     217,   218,   219,    -1,   221,   222,    -1,   224,   225,   226,
      -1,   228,   229,   230,   231,   232,   233,   234,    -1,    -1,
      -1,    -1,    -1,   240,   241,    -1,   243,    -1,    -1,    -1,
       3,     4,     5,   250,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,    -1,    -1,    -1,   251,    30,    31,    -1,
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
      -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,    -1,   216,   217,   218,   219,    -1,   221,   222,
      -1,   224,   225,   226,    -1,   228,   229,   230,   231,   232,
     233,   234,    -1,    -1,    -1,    -1,    -1,   240,   241,    -1,
     243,    -1,    -1,    -1,     3,     4,     5,   250,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,    -1,    -1,    -1,    -1,
     251,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     159,    -1,    -1,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,    -1,   216,   217,   218,
     219,    -1,   221,   222,    -1,   224,   225,   226,    -1,   228,
     229,   230,   231,   232,   233,   234,    -1,    -1,    -1,    -1,
      -1,   240,   241,    -1,   243,    -1,    -1,    -1,     3,     4,
       5,   250,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,
      -1,    -1,    -1,    -1,   251,    30,    31,    -1,    -1,    -1,
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
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
      -1,   216,   217,   218,   219,    -1,   221,   222,    -1,   224,
     225,   226,    -1,   228,   229,   230,   231,   232,   233,   234,
      -1,    -1,    -1,    -1,    -1,   240,   241,    -1,   243,    -1,
      -1,    -1,     3,     4,     5,   250,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,   245,   246,    -1,    -1,    -1,    -1,   251,    30,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,    -1,   216,   217,   218,   219,    -1,
     221,   222,    -1,   224,   225,   226,    -1,   228,   229,   230,
     231,   232,   233,   234,    -1,    -1,    -1,    -1,    -1,   240,
     241,    -1,   243,    -1,    -1,    -1,     3,     4,     5,   250,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,
      -1,    -1,   251,    30,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,
      67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,
      -1,    -1,    89,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,   144,   145,   146,
     147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    31,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,    -1,   216,
     217,   218,   219,    -1,   221,   222,    -1,   224,   225,   226,
      -1,   228,   229,   230,   231,   232,   233,   234,   105,    -1,
     107,    -1,    -1,   240,   241,    -1,   243,    -1,    -1,     5,
      -1,    -1,    -1,   250,    10,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,    -1,    -1,    31,   251,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,   185,   186,
      -1,    -1,    -1,   190,   191,   192,    -1,   194,    -1,   196,
     197,   198,    -1,    -1,    -1,    -1,   203,   204,   205,   206,
     207,    -1,    -1,   210,    -1,   212,    -1,   214,    -1,   105,
     217,   107,   219,    -1,    -1,   222,    -1,    -1,   225,   226,
       5,   228,   229,    -1,   231,    10,   233,    -1,    -1,    -1,
     126,   127,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   250,   251,    -1,    31,    -1,   144,   145,
     146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,   185,
     186,    -1,    -1,    -1,   190,   191,   192,    -1,   194,    -1,
     196,   197,   198,    -1,    -1,    -1,    -1,   203,   204,   205,
     206,   207,    -1,    -1,   210,    -1,   212,    -1,   214,    -1,
     105,   217,   107,   219,    -1,    -1,   222,    -1,    -1,   225,
     226,    -1,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
      -1,   126,   127,    -1,    -1,   241,    -1,     5,    -1,    -1,
      -1,    -1,    10,    -1,   250,   251,    -1,    -1,    -1,   144,
     145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    31,   159,    -1,    -1,   162,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,
     185,   186,    -1,    -1,    -1,   190,   191,   192,    -1,   194,
      -1,   196,   197,   198,    -1,    -1,    -1,    -1,   203,   204,
     205,   206,   207,    -1,    -1,   210,    -1,   212,    -1,   214,
      -1,    -1,   217,    -1,   219,    -1,    -1,   222,    -1,    -1,
     225,   226,    -1,   228,   229,    -1,   231,   105,   233,   107,
      -1,    -1,    -1,   111,    -1,    -1,   241,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   250,   251,    -1,   126,   127,
      -1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      31,   159,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   184,   185,   186,    -1,
      -1,    -1,   190,   191,   192,    -1,   194,    -1,   196,   197,
     198,    -1,    -1,    -1,    -1,   203,   204,   205,   206,   207,
      -1,    -1,   210,    -1,   212,    -1,   214,    -1,    -1,   217,
      -1,   219,    -1,    -1,   222,    -1,    -1,   225,   226,    -1,
     228,   229,    -1,   231,   105,   233,   107,    -1,    -1,    -1,
     111,    -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   250,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,     5,    -1,    -1,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    31,   159,    -1,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   185,   186,    -1,    -1,    -1,   190,
     191,   192,    -1,   194,    -1,   196,   197,   198,    -1,    -1,
      -1,    -1,   203,   204,   205,   206,   207,    -1,    -1,   210,
      -1,   212,    -1,   214,    -1,    -1,   217,    -1,   219,    -1,
      -1,   222,    -1,    -1,   225,   226,    -1,   228,   229,    -1,
     231,   105,   233,   107,    -1,    -1,    -1,   111,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,     5,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    31,   159,    -1,    -1,   162,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     184,   185,   186,    -1,    -1,    -1,   190,   191,   192,    -1,
     194,    -1,   196,   197,   198,    -1,    -1,    -1,    -1,   203,
     204,   205,   206,   207,    -1,    -1,   210,    -1,   212,    -1,
     214,    -1,    -1,   217,    -1,   219,    -1,    -1,   222,    -1,
      -1,   225,   226,    -1,   228,   229,    -1,   231,   105,   233,
     107,    -1,    -1,    -1,   111,    -1,     5,   241,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,   250,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,   184,   185,   186,
      -1,    -1,    -1,   190,   191,   192,    -1,   194,    -1,   196,
     197,   198,    -1,    -1,    -1,    -1,   203,   204,   205,   206,
     207,    -1,    -1,   210,    -1,   212,   105,   214,   107,    -1,
     217,    -1,   219,    -1,    -1,   222,    -1,    -1,   225,   226,
      -1,   228,   229,    -1,   231,    -1,   233,   126,   127,    -1,
      -1,    -1,    -1,     5,   241,    -1,    -1,    -1,    10,    -1,
      -1,    -1,    -1,   250,    -1,   144,   145,   146,   147,   148,
      -1,   150,    -1,    -1,    -1,    -1,    -1,   156,    -1,    31,
     159,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   185,   186,    -1,    -1,
      -1,   190,   191,   192,    -1,   194,    -1,   196,   197,   198,
      -1,    -1,    -1,    -1,   203,   204,   205,   206,   207,    -1,
      -1,   210,    -1,   212,    -1,   214,    -1,    -1,   217,    -1,
     219,    -1,    -1,   222,    -1,    -1,   225,   226,    -1,   228,
     229,    -1,   231,   105,   233,   107,    -1,   243,   244,   245,
     246,    -1,   241,    -1,     5,   251,    -1,    -1,    -1,    10,
      -1,   250,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,   144,   145,   146,   147,   148,    -1,   150,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   184,   185,   186,    -1,    -1,    -1,   190,   191,
     192,    -1,   194,    -1,   196,   197,   198,    -1,    -1,    -1,
      -1,   203,   204,   205,   206,   207,    97,    -1,   210,    -1,
     212,    -1,   214,    -1,   105,   217,   107,   219,    -1,    -1,
     222,    -1,    -1,   225,   226,     5,   228,   229,    -1,   231,
      10,   233,    -1,    -1,    -1,   126,   127,    -1,    -1,   241,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,    -1,
      -1,    31,    -1,   144,   145,   146,   147,   148,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   184,   185,   186,    -1,    -1,    -1,   190,
     191,   192,    -1,   194,    -1,   196,   197,   198,    -1,    -1,
      -1,    -1,   203,   204,   205,   206,   207,    97,    -1,   210,
      -1,   212,    -1,   214,    -1,   105,   217,   107,   219,    -1,
      -1,   222,    -1,    -1,   225,   226,     5,   228,   229,    -1,
     231,    10,   233,    -1,    -1,    -1,   126,   127,    -1,    -1,
     241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   250,
      -1,    -1,    31,    -1,   144,   145,   146,   147,   148,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   184,   185,   186,    -1,    -1,    -1,
     190,   191,   192,    -1,   194,    -1,   196,   197,   198,    -1,
      -1,    -1,    -1,   203,   204,   205,   206,   207,    -1,    -1,
     210,    -1,   212,    -1,   214,    -1,   105,   217,   107,   219,
      -1,    -1,   222,    -1,    -1,   225,   226,     5,   228,   229,
      -1,   231,    10,   233,    -1,    -1,    -1,   126,   127,    -1,
      -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     250,    -1,    -1,    31,    -1,   144,   145,   146,   147,   148,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   184,   185,   186,    -1,    -1,
      -1,   190,   191,   192,    -1,   194,    -1,   196,   197,   198,
      -1,    -1,    -1,    -1,   203,   204,   205,   206,   207,    -1,
      -1,   210,    -1,   212,    -1,   214,    -1,   105,   217,   107,
     219,    -1,    -1,   222,    -1,    -1,   225,   226,    -1,   228,
     229,    -1,   231,    -1,   233,    -1,    -1,    -1,   126,   127,
      -1,    -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   250,    -1,    -1,    -1,    -1,   144,   145,   146,   147,
     148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,
      -1,   159,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   184,   185,   186,    -1,
      -1,    -1,   190,   191,   192,    -1,   194,    -1,   196,   197,
     198,    -1,    -1,    -1,    -1,   203,   204,   205,   206,   207,
      -1,    -1,   210,    -1,   212,    -1,   214,    -1,    -1,   217,
      -1,   219,    -1,    -1,   222,    -1,    -1,   225,   226,    -1,
     228,   229,    -1,   231,    -1,   233,    -1,    -1,     4,     5,
       6,    -1,    -1,   241,    -1,    11,    -1,    -1,    -1,    15,
      -1,    17,   250,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,
     106,    -1,   108,   109,    -1,    -1,    -1,    -1,   114,   115,
     243,   244,   245,   246,    -1,   121,   249,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    -1,    -1,   144,   145,
     146,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
     156,   157,   158,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,   185,
     186,    -1,    -1,    -1,    -1,   191,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,   211,    -1,    -1,    -1,   215,
      -1,     4,     5,     6,   220,    -1,    -1,   223,    11,    -1,
      -1,   227,    15,    -1,    17,    -1,    19,    20,    21,    22,
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
      -1,    -1,    -1,   156,   157,   158,   159,   243,   244,   245,
     246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   184,   185,   186,    -1,    -1,    -1,    -1,   191,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,   211,    -1,
      -1,    -1,   215,    -1,     4,     5,     6,   220,    -1,    -1,
     223,    11,    -1,    -1,   227,    15,    -1,    17,    -1,    19,
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
     243,   244,   245,   246,    63,    64,   249,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,   184,   185,   186,    63,    64,    -1,
      -1,   191,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   211,    -1,    -1,    -1,   215,    -1,    -1,    -1,    -1,
     220,    63,    64,   223,    -1,    -1,    -1,   227,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   243,   244,
     245,   246,    63,    64,   249,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,   245,   246,    63,    64,
     249,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,   243,   244,   245,
     246,    63,    64,   249,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,   243,   244,   245,   246,    63,    64,   249,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,
     246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,
     246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,
     246,    63,    64,   249,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    63,    64,   249,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,   243,   244,   245,   246,    -1,    -1,   249,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,
      63,    64,   249,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,   243,   244,   245,   246,    63,
      64,   249,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,   243,   244,   245,   246,    63,    64,   249,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,    63,    64,   249,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
     243,   244,   245,   246,    63,    64,   249,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   243,
     244,   245,   246,    -1,    -1,   249,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,
     249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,   245,   246,    -1,    -1,   249,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,
     249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,   245,   246,    -1,    -1,   249,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,   245,   246,    63,    64,
     249,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   243,   244,   245,   246,    63,
      64,   249,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,
      -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   243,   244,   245,   246,    63,    64,   249,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,   243,   244,   245,   246,    63,    64,
     249,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,   243,   244,
     245,   246,    63,    64,   249,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   243,
     244,   245,   246,    63,    64,   249,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,    63,
      64,   249,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,    63,    64,   249,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   243,   244,   245,   246,    63,    64,   249,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    63,    64,   249,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,   245,   246,    63,    64,   249,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,   243,   244,   245,
     246,    63,    64,   249,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   243,   244,   245,   246,
      63,    64,   249,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,   243,   244,   245,   246,    63,    64,   249,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    63,    64,   249,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,   243,   244,   245,   246,    63,    64,   249,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
     243,   244,   245,   246,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,    63,
      64,   249,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   243,   244,   245,   246,
      63,    64,   249,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,    63,    64,   249,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,   243,   244,   245,   246,    63,
      64,   249,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,   243,
     244,   245,   246,    63,    64,   249,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     243,   244,   245,   246,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,   245,   246,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,    -1,
      -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,   245,   246,    -1,    -1,   249,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,    63,
      64,   249,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,
      63,    64,   249,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,   243,
     244,   245,   246,    -1,    -1,   249,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,   245,   246,    63,    64,
     249,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,   243,   244,   245,   246,    63,    64,   249,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   243,
     244,   245,   246,    63,    64,   249,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     243,   244,   245,   246,    63,    64,   249,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,   243,   244,
     245,   246,    63,    64,   249,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   243,   244,   245,
     246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,
     246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,
     246,    -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,    63,    64,   249,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   243,   244,   245,   246,    63,    64,   249,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   243,   244,   245,   246,    -1,    -1,
     249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,
     244,   245,   246,    -1,    -1,   249,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   243,   244,   245,   246,    -1,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,   246,
      -1,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,   244,   245,
     246,    -1,    -1,   249
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   235,   236,   237,   238,   239,   254,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   114,   115,
     121,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     144,   145,   146,   147,   148,   149,   156,   157,   158,   159,
     184,   185,   186,   191,   211,   215,   220,   223,   227,   255,
     256,   259,   260,   267,   268,   270,   271,   275,   287,   288,
     293,   299,   306,   314,   322,   325,   329,   332,   338,     3,
       4,     5,     7,     8,     9,    10,    30,    31,    63,    64,
      65,    66,    67,    68,    69,    81,    84,    89,   101,   102,
     105,   107,   115,   122,   126,   127,   144,   145,   146,   147,
     148,   149,   156,   159,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   216,   217,   218,
     219,   221,   222,   224,   225,   226,   228,   229,   230,   231,
     232,   233,   234,   240,   241,   243,   250,   273,   274,   276,
     282,   284,   287,   288,   144,   145,   146,   147,   250,   273,
     259,   287,   288,   293,     0,    75,   250,    75,   250,   307,
     326,   330,     4,     7,   285,   285,   285,    34,   276,   261,
     262,   273,   289,   290,   289,   273,    28,     7,   315,   323,
     276,    58,    60,    61,   252,   369,   265,   273,   276,     4,
       5,   286,   276,   273,   276,   273,   276,     4,     5,   349,
     350,    10,   243,   244,   283,   284,   351,   285,    89,    97,
     252,   273,   276,   370,    89,    97,   110,   370,   370,    81,
      82,    88,   111,   276,   281,    12,    53,   281,   111,   281,
      59,    89,    90,    91,    96,    95,   276,   268,   275,   273,
     273,   273,   110,   281,    90,    91,    92,    93,    94,   104,
     110,   111,   116,   117,   118,   119,   120,   281,   281,   111,
     281,   111,   281,    95,   111,   281,    61,    95,   111,   142,
     281,   281,    22,    61,   111,   281,   111,   281,   111,   281,
     111,   273,   273,   273,    61,   111,   111,   142,   143,   281,
     111,   281,   281,   111,   281,   281,   281,    95,   142,   143,
     151,   154,   281,    95,   142,   143,   154,   281,    95,   142,
     143,   151,   152,   153,   154,   281,    61,    95,   142,   143,
     150,   154,   281,   111,   281,   111,   281,   111,   273,   111,
     273,   111,   273,   160,   250,   250,   250,   250,   250,   273,
     370,   273,   273,   273,    44,   257,    92,    93,   104,    75,
      75,    24,   250,   250,   250,   250,   276,   250,   250,   250,
     250,   250,   250,   112,   113,   250,   250,   250,   250,   112,
     250,   112,   155,   112,   155,   112,   113,   155,   112,   113,
     155,   112,   113,   155,   112,   113,   155,   112,   112,   162,
     161,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   276,   273,   276,    70,    71,    72,    73,    74,
      75,    76,   244,    44,    63,    64,    70,    71,    72,    73,
      74,    75,    76,    77,   243,   244,   245,   246,   273,    44,
      44,    44,   276,   289,   273,   289,     4,   276,   256,    35,
      36,    20,    21,     4,     5,   300,   301,     4,     5,   302,
     303,   273,   276,   291,   292,   273,   276,   317,   256,   333,
     339,   250,    58,   250,     4,     7,   250,   273,   276,   352,
      58,    60,    61,   252,   354,   367,   250,   250,   249,   249,
     249,   250,   250,   249,   284,   284,   249,   276,   273,   276,
      11,   249,   249,   281,   273,   273,   273,   249,   281,   266,
      12,   249,   269,   273,   249,   281,    12,   281,   269,   269,
     269,   281,   281,   281,   281,   281,   281,   281,   273,   273,
     281,   281,   281,   281,   269,   269,   273,   249,   273,   249,
     273,   273,   269,   273,   273,   273,   273,   269,   249,   273,
     273,   273,   269,   273,   269,   273,   249,   273,   249,   249,
     249,   273,   273,   273,   273,   273,   269,   273,   269,   269,
     273,   269,   269,   269,   273,   273,   273,   273,   273,   269,
     273,   273,   273,   273,   269,   273,   273,   273,   273,   273,
     273,   273,   269,   273,   273,   273,   150,   273,   273,   273,
     269,   273,   249,   273,   249,   273,   249,   273,   249,   273,
     249,   273,     5,   272,   272,   272,   251,   276,   273,   249,
     249,   249,   249,    43,   281,   281,   281,   276,   273,   294,
     289,   289,   276,   276,   276,   276,   276,   276,    97,   273,
     370,   370,   273,     4,     5,   279,   280,   279,   280,   281,
     276,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   150,   273,   273,
     273,   273,   250,   273,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   370,   276,   276,   276,   276,   276,
     276,   276,   276,   251,   276,   273,   273,   273,   273,   273,
     276,   276,   273,   276,   251,   276,   276,   273,   276,   273,
     276,   273,   273,   251,   273,   251,   273,   251,   273,   251,
     273,   273,   273,   273,   276,   273,   273,   273,   273,   273,
     273,   273,   370,   273,   289,   289,   273,   276,   273,   273,
     273,   273,   273,   251,   251,   273,   272,   273,   272,   273,
     273,   273,   251,   251,   273,   273,   273,   273,   273,   273,
     273,   273,   278,   277,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   251,   251,    75,   327,
      14,    16,    18,    41,    44,    49,   331,   263,   264,   250,
     250,   249,   250,   250,   249,   249,    43,   316,    14,    16,
      18,    41,    44,    49,   324,    46,   256,   276,   250,   273,
     276,    51,   353,   248,   249,   250,    58,   250,     4,     7,
     250,    10,   368,   289,   289,     4,     5,   276,   276,   289,
     289,   350,    10,   283,   249,    86,    87,    97,   273,   276,
     269,   249,   276,   354,   281,   249,   273,   281,   269,   276,
     276,   281,   249,   269,   249,   269,   249,   269,   269,   249,
     249,   249,   269,   269,   281,   281,   249,   273,   249,   273,
     249,   281,   249,   249,   249,   281,   273,   249,   249,   249,
     281,   249,   281,   249,   273,   249,   276,   273,   273,   249,
     249,   249,   249,   249,   281,   249,   281,   281,   249,   281,
     281,   281,   249,   249,   249,   281,   249,   249,   249,   281,
     249,   249,   249,   249,   249,   281,   249,   249,   273,   249,
     249,   249,   281,   249,   273,   249,   273,   249,   273,   249,
     273,   249,   273,   250,   249,   249,   249,   251,   251,   273,
     276,   273,   276,   276,   276,   258,   249,   269,   269,     4,
       5,   298,   251,   251,   249,   249,   251,   249,   249,   249,
     251,   249,   251,   249,   251,   249,   250,   250,   251,   251,
     249,   249,   269,   249,   249,   251,   249,   249,   249,   273,
     249,   249,   273,   251,   251,   251,   251,   251,   251,   249,
     251,   251,   249,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   249,   251,   251,   249,   249,   249,
     251,   249,   249,   251,   249,   251,   251,   251,   251,   251,
     249,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   249,   249,   249,   249,   251,   251,   251,   251,
     251,   249,   251,   251,   251,   251,   251,   251,   249,   251,
     249,   249,   249,   249,   249,   251,   249,   249,   251,   249,
     251,   251,   276,   276,   308,   256,   276,   285,   371,   285,
     372,   289,   289,   301,   289,   289,   303,   292,    43,   318,
     334,    49,    50,   340,   249,   276,   249,   251,   251,   250,
     273,   273,   276,   276,   250,   273,   355,   356,   276,     4,
       5,   346,   348,   251,   251,   250,   250,   249,   249,   251,
     251,   276,    85,    85,   249,   249,   281,   273,   273,   249,
     281,   249,   249,   249,   273,   281,   276,   281,   273,   281,
     281,   273,   276,   276,   276,   281,   281,   249,   249,   276,
     249,   276,   249,   273,   276,   249,   273,   273,   273,   249,
     249,   273,   273,   273,   276,   249,   273,   249,   276,   249,
     273,   249,   273,   273,   276,   273,   276,   249,   273,   249,
     249,   276,   249,   249,   249,   273,   276,   273,   276,   276,
     249,   273,   276,   276,   249,   273,   273,   276,   273,   273,
     276,   249,   273,   276,   249,   276,   273,   276,   249,   273,
     249,   276,   249,   273,   276,   249,   273,   249,   273,   249,
     289,   276,   276,   276,   249,   249,   260,   276,   281,   281,
     295,   276,   276,   276,   276,   276,   273,    97,   273,   273,
     251,   251,   276,   276,   281,   276,   273,   276,   276,   276,
     276,   273,   251,   276,   276,   276,   276,   276,   276,   276,
     276,   273,   276,   273,   273,   273,   273,   273,   276,   276,
     276,   276,   280,   273,   280,   273,   273,   276,    16,    44,
     328,   249,   249,   251,   251,   251,   251,    39,    40,   320,
     256,   276,   249,   273,    58,   273,   353,   249,   276,   249,
     251,   346,   346,   251,   250,   250,   249,   289,   289,   276,
     276,   249,   370,   370,   273,   273,   249,   249,   273,   276,
     276,   273,   249,   249,   269,   249,   249,   269,   249,   249,
     249,   269,   249,   273,   273,   273,   273,   273,   249,   273,
     273,   249,   249,   249,   273,   249,   273,   273,   249,   273,
     249,   249,   273,   249,   273,   273,   273,   273,   273,   249,
     273,   273,   249,   249,   273,   249,   249,   276,   249,   273,
     273,   249,   273,   249,   249,   273,   249,   273,   249,   273,
     251,   251,   251,   249,   251,   273,   273,   269,   250,   251,
     251,   251,   251,   251,   251,   251,   249,   251,   251,   251,
     251,   269,   249,   249,   251,   251,   251,   251,   251,   249,
     251,   251,   251,   249,   251,   251,   251,   249,   249,   251,
     249,   251,   251,   251,   249,   249,   251,   249,   251,   251,
     249,   251,   251,   251,    12,   285,   285,   317,    43,    38,
     335,   251,   276,   251,   250,   249,   276,   249,   273,    58,
     362,   357,   289,   289,   347,   251,   251,   273,   273,   273,
     249,   249,   249,   273,   273,   281,   273,   273,   281,   276,
     276,   276,   281,   276,   249,   249,   249,   249,   276,   249,
     249,   273,   276,   276,   249,   273,   249,   249,   276,   276,
     273,   276,   249,   273,   249,   249,   249,   249,   249,   273,
     249,   249,   273,   276,   273,   249,   276,   276,   276,   249,
     249,   276,   273,   273,   249,   273,   276,   249,   273,   249,
      75,    75,   276,    75,   249,   281,     4,     5,   304,   305,
     273,   276,   273,   276,   276,   273,   273,   276,   276,   273,
     276,   273,   273,   276,   319,   321,    48,   342,    60,    61,
     251,    58,   276,   273,   251,   276,   251,   250,   368,   346,
     251,   251,   346,   249,   273,   273,   273,   249,   269,   249,
     249,   249,   269,   249,   273,   276,   276,   273,   249,   276,
     273,   249,   273,   249,   273,   276,   249,   249,   273,   273,
     276,   276,   273,   273,   276,   273,   249,   276,   249,   249,
     249,   276,   273,   249,   249,   273,   249,   249,   273,   249,
     273,   273,   273,   251,   273,   276,   250,   250,   249,   251,
     251,   249,   251,   251,   251,   251,   251,   251,   251,   251,
     251,    13,   312,   256,   256,   276,    47,   341,   250,   250,
     249,   251,    60,    61,   358,   251,    58,   363,   276,   346,
     273,   273,   281,   276,   273,   276,   281,   276,   249,   249,
     249,   249,   276,   249,   249,   276,   249,   276,   249,   249,
     276,   276,   249,   249,   249,   249,   249,   249,   276,   249,
     276,   276,   276,   249,   249,   276,   273,   273,   273,   249,
     273,   276,   249,    75,   251,   251,   305,   296,   276,   276,
     309,    46,   345,   256,   336,   273,   276,   276,   364,   250,
     368,   359,   250,   368,   249,   249,   249,   249,   249,   249,
     273,   273,   273,   273,   249,   273,   273,   249,   276,   273,
     276,   249,   273,   276,   276,   273,   273,   273,   273,   249,
     249,   249,   273,   273,   249,   273,   249,   249,   273,   273,
     256,   251,   256,   343,    14,    16,    18,    41,    44,    49,
     337,   249,   251,   249,   251,   368,   273,   346,   368,   276,
     346,   276,   273,   273,   276,   273,   273,   249,   276,   276,
     249,   249,   249,   276,   249,   249,   276,   273,   276,   249,
     273,   273,   273,   249,    25,    44,   297,   310,   256,   273,
     276,   346,   249,   251,   346,   249,   251,   249,   273,   276,
     273,   276,   273,   273,   249,   273,   249,   273,    14,    16,
      18,    41,    44,    49,   311,   344,   251,   251,   273,   365,
     276,   360,   273,   249,   249,   276,   273,     4,   313,   342,
     251,   368,   251,   368,   273,   273,   249,   366,   346,   361,
     346,   249,   273,   368,   368,   273,   346,   346
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   253,   254,   254,   254,   254,   254,   255,   256,   257,
     258,   256,   259,   259,   259,   259,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   261,   260,   262,   260,   260,   260,   260,   260,   260,
     260,   263,   260,   264,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   265,   260,   266,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   267,
     267,   267,   267,   267,   268,   268,   268,   268,   268,   268,
     269,   269,   270,   270,   270,   270,   270,   271,   271,   272,
     272,   273,   273,   273,   273,   273,   273,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   275,   275,   277,   276,   278,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     279,   280,   281,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   283,
     283,   283,   284,   284,   284,   284,   285,   285,   286,   286,
     286,   286,   287,   288,   290,   289,   291,   291,   291,   292,
     292,   294,   295,   296,   293,   297,   297,   298,   298,   299,
     299,   299,   299,   300,   300,   301,   301,   301,   301,   302,
     302,   303,   303,   303,   303,   304,   304,   304,   305,   305,
     305,   305,   307,   308,   309,   310,   306,   311,   311,   311,
     311,   311,   311,   312,   312,   313,   313,   315,   314,   316,
     316,   317,   317,   318,   319,   318,   320,   321,   320,   323,
     322,   324,   324,   324,   324,   324,   324,   326,   327,   325,
     328,   328,   330,   329,   331,   331,   331,   331,   331,   331,
     333,   334,   335,   336,   332,   337,   337,   337,   337,   337,
     337,   339,   338,   340,   340,   341,   341,   342,   343,   344,
     342,   345,   345,   346,   347,   346,   348,   348,   348,   348,
     349,   349,   350,   350,   350,   350,   351,   351,   351,   351,
     352,   352,   352,   352,   352,   353,   353,   353,   355,   354,
     356,   354,   357,   354,   358,   354,   359,   354,   360,   354,
     361,   354,   362,   354,   363,   354,   364,   354,   365,   354,
     366,   354,   367,   354,   368,   368,   369,   369,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   369,
     370,   370,   371,   371,   372,   372
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
      10,     9,    11,    12,    13,    11,     3,     2,     3,     2,
       2,     1,     1,     3,     4,     4,     4,     4,     4,     4,
       1,     1,     2,     1,     2,     2,     8,     6,     6,     0,
       1,     1,     2,     2,     3,    10,     8,     8,     8,     3,
       1,     1,     6,     4,     4,     6,     6,     4,     6,     1,
       4,     1,     1,     1,     1,     3,     3,     6,     6,     8,
       6,     4,     6,     8,     4,     1,     3,     4,     4,     4,
       4,     4,     4,     4,     6,     8,     4,     4,     4,     4,
       4,     6,     1,     3,     1,     3,     4,     3,     3,     3,
       3,     5,     5,     5,     7,     3,     4,     5,     2,     6,
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
       6,     6,     8,     4,     2,     5,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     5,     5,     7,     4,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     4,     6,
       4,     6,     4,     4,     0,     2,     0,     1,     3,     1,
       1,     0,     0,     0,    11,     1,     1,     1,     1,     0,
       1,     1,     2,     1,     3,     1,     1,     4,     4,     1,
       3,     1,     1,     4,     4,     0,     1,     3,     1,     1,
       3,     3,     0,     0,     0,     0,    14,     1,     1,     1,
       1,     1,     1,     0,     2,     0,     1,     0,     7,     1,
       2,     1,     1,     0,     0,     5,     0,     0,     4,     0,
       4,     1,     1,     1,     1,     1,     1,     0,     0,     6,
       1,     1,     0,     4,     1,     2,     1,     1,     1,     1,
       0,     0,     0,     0,    11,     1,     1,     1,     1,     1,
       1,     0,     5,     1,     1,     0,     2,     0,     0,     0,
       7,     0,     1,     1,     0,     4,     1,     4,     1,     4,
       1,     3,     1,     4,     1,     4,     1,     1,     3,     3,
       0,     2,     4,     1,     3,     0,     2,     6,     0,     4,
       0,     4,     0,     6,     0,     9,     0,    10,     0,    13,
       0,    15,     0,     7,     0,     9,     0,    10,     0,    13,
       0,    15,     0,     3,     0,     1,     0,     2,     2,     4,
       1,     4,     6,     6,     7,    10,    12,     7,    10,    12,
       2,     1,     1,     3,     1,     3
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

  case 207: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 208: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 209: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 210: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 211: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 212: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 213: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 214: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 215: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 216: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 217: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 218: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 219: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 220: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 221: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 222: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 223: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 224: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 225: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 226: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 227: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 228: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 229: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 230: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 231: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 232: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 233: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 234: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 235: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 236: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 237: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 238: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 239: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 242: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 243: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 244: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 245: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 246: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 247: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 248: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 249: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 250: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 251: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 253: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 254: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 255: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 257: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 258: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 259: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 260: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 261: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 262: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 263: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 264: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 265: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 266: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 267: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 268: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 269: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 270: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 271: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 272: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 273: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 274: /* string_function: tSTRING2 '(' expression ',' string_expression ')'  */
                                                      {create_function(fSTRING);}
    break;

  case 275: /* string_function: tREPLACE '(' string_expression ',' string_expression ',' string_expression ')'  */
                                                                                    {create_function(fREPLACE);}
    break;

  case 276: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 277: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 278: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 279: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 280: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 281: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 282: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 283: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 284: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 285: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 286: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 287: /* string_function: tTEXTCONTROL tGET string_expression  */
                                        {create_function(fYABTEXTCONTROLGET);}
    break;

  case 288: /* string_function: tTEXTEDIT tGET string_expression  */
                                     {create_function(fYABTEXTEDITGET);}
    break;

  case 289: /* string_function: tTEXTCONTROL tGETS string_expression  */
                                                         {create_function(fYABTEXTCONTROLGET);}
    break;

  case 290: /* string_function: tTEXTEDIT tGETS string_expression  */
                                                      {create_function(fYABTEXTEDITGET);}
    break;

  case 291: /* string_function: tLISTBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABLISTBOXGET);}
    break;

  case 292: /* string_function: tDROPBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABDROPBOXGET);}
    break;

  case 293: /* string_function: tTREEBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABTREEBOXGET);}
    break;

  case 294: /* string_function: tCOLUMNBOX tGETS string_expression ',' expression ',' expression  */
                                                                                     {create_function(fYABCOLUMNBOXGET);}
    break;

  case 295: /* string_function: tCALENDAR tGET string_expression  */
                                                     {create_function(fYABCALENDARGET);}
    break;

  case 296: /* string_function: tTRANSLATE '(' string_expression ')'  */
                                         {create_function(fYABTRANSLATE);}
    break;

  case 297: /* string_function: tMENU tTRANSLATE '(' string_expression ')'  */
                                               {create_function(fYABMENUTRANSLATE);}
    break;

  case 298: /* string_function: tCLIPBOARD tPASTE  */
                      {create_function(fYABCLIPBOARDPASTE);}
    break;

  case 299: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 300: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 301: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 302: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 303: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 304: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 305: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 306: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 307: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 308: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 309: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 310: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 311: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 312: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 313: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 314: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 315: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 316: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 317: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 318: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 319: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 320: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 321: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 322: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 323: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 324: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 325: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 326: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 327: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 328: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 329: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 330: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 331: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 332: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 333: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 334: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 335: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 336: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 337: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 338: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 339: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 340: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 341: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 342: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 343: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 344: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 345: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 346: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 347: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 350: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 351: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 353: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 354: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 355: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 356: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 357: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 358: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 359: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 360: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 361: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 362: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 363: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 364: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 365: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 366: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 367: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 368: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 369: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 370: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 371: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 372: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 373: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 374: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 375: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 376: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 377: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 378: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 379: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 380: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 381: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 382: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 383: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 384: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 385: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 386: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 387: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 388: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 389: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 390: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 391: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 392: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 393: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 394: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 395: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 396: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 397: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 398: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 399: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 400: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 401: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 402: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 403: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 404: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 405: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 406: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 407: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 408: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 409: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 410: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 411: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 412: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 413: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 414: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 415: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 416: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 417: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 418: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 419: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 420: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 421: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 422: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 423: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 424: /* function: tWINDOW tCOUNT  */
                   {create_function(fYABNUMWINDOWS);}
    break;

  case 425: /* function: tWINDOW tGET string_expression ',' string_expression  */
                                                         {create_function(fYABWINDOWGET);}
    break;

  case 426: /* function: tLISTBOX tCOUNT string_expression  */
                                                      {create_function(fYABLISTBOXCOUNT);}
    break;

  case 427: /* function: tLISTBOX tGET string_expression  */
                                                    {create_function(fYABLISTBOXSELECTED);}
    break;

  case 428: /* function: tDROPBOX tCOUNT string_expression  */
                                                      {create_function(fYABDROPBOXCOUNT);}
    break;

  case 429: /* function: tDROPBOX tGET string_expression  */
                                                    {create_function(fYABDROPBOXSELECTED);}
    break;

  case 430: /* function: tTREEBOX tCOUNT string_expression  */
                                                      {create_function(fYABTREEBOXCOUNT);}
    break;

  case 431: /* function: tTREEBOX tGET string_expression  */
                                                    {create_function(fYABTREEBOXSELECTED);}
    break;

  case 432: /* function: tCOLUMNBOX tCOUNT string_expression  */
                                                        {create_function(fYABCOLUMNBOXCOUNT);}
    break;

  case 433: /* function: tCOLUMNBOX tCOUNT tCOLUMN string_expression  */
                                                                {create_function(fYABCOLUMNBOXCOUNTCOLUMNS);}
    break;

  case 434: /* function: tCOLUMNBOX tGET string_expression  */
                                                      {create_function(fYABCOLUMNBOXSELECTED);}
    break;

  case 435: /* function: tCOLORCONTROL tGET string_expression ',' string_expression  */
                                                                               {create_function(fYABCOLORCONTROLGET);}
    break;

  case 436: /* function: tDRAW tGET string_expression ',' string_expression  */
                                                       {create_function(fYABDRAWGET);}
    break;

  case 437: /* function: tDRAW tGET string_expression ',' string_expression ',' string_expression  */
                                                                             {create_function(fYABDRAWGETTEXT);}
    break;

  case 438: /* function: tBFILESIZE '(' string_expression ')'  */
                                         {create_function(fYABBFILESIZE);}
    break;

  case 439: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 440: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 441: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 442: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 443: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 444: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 445: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 446: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 447: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 448: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 449: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 450: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 451: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 452: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 453: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 454: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 461: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 462: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 463: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 464: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 465: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 466: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 467: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 468: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 469: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 470: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 471: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 472: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 475: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 476: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 477: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 478: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 481: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 482: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 483: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 484: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 488: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 489: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 490: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 491: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 492: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 493: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 494: /* $@17: %empty  */
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

  case 495: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 496: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 497: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 498: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 499: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 500: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 501: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 502: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 503: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 505: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 506: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 507: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 508: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 514: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 515: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 517: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 519: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 521: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 522: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 523: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 524: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 525: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 526: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 527: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 528: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 530: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 531: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 532: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 534: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 535: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 536: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 537: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 538: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 539: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 540: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 541: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 542: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 543: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 545: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 546: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 547: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 548: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 549: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 550: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 551: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 553: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 554: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 558: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 559: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 564: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 566: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 567: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 568: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 569: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 572: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 573: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 574: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 575: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 576: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 577: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 578: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 579: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 583: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 584: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 585: /* using: %empty  */
       {create_print('d');}
    break;

  case 586: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 587: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 588: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 589: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 590: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 591: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 592: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 593: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 594: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 595: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 596: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 597: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 598: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 599: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 600: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 601: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 602: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 603: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 604: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 605: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 606: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 607: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 608: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 609: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 610: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 611: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 612: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 613: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 614: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 615: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 616: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 617: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 618: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 619: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 620: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 621: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 622: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 623: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 624: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 625: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 626: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 627: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 628: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 629: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 632: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 633: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 634: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 635: /* gosub_list: gosub_list ',' symbol_or_lineno  */
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

