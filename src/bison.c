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
  YYSYMBOL_tSIN = 169,                     /* tSIN  */
  YYSYMBOL_tASIN = 170,                    /* tASIN  */
  YYSYMBOL_tCOS = 171,                     /* tCOS  */
  YYSYMBOL_tACOS = 172,                    /* tACOS  */
  YYSYMBOL_tTAN = 173,                     /* tTAN  */
  YYSYMBOL_tATAN = 174,                    /* tATAN  */
  YYSYMBOL_tEXP = 175,                     /* tEXP  */
  YYSYMBOL_tLOG = 176,                     /* tLOG  */
  YYSYMBOL_tSQRT = 177,                    /* tSQRT  */
  YYSYMBOL_tSQR = 178,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 179,                   /* tMYEOF  */
  YYSYMBOL_tABS = 180,                     /* tABS  */
  YYSYMBOL_tSIG = 181,                     /* tSIG  */
  YYSYMBOL_tINT = 182,                     /* tINT  */
  YYSYMBOL_tCEIL = 183,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 184,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 185,                    /* tFRAC  */
  YYSYMBOL_tROUND = 186,                   /* tROUND  */
  YYSYMBOL_tMOD = 187,                     /* tMOD  */
  YYSYMBOL_tRAN = 188,                     /* tRAN  */
  YYSYMBOL_tVAL = 189,                     /* tVAL  */
  YYSYMBOL_tLEFT = 190,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 191,                   /* tRIGHT  */
  YYSYMBOL_tMID = 192,                     /* tMID  */
  YYSYMBOL_tLEN = 193,                     /* tLEN  */
  YYSYMBOL_tMIN = 194,                     /* tMIN  */
  YYSYMBOL_tMAX = 195,                     /* tMAX  */
  YYSYMBOL_tSTR = 196,                     /* tSTR  */
  YYSYMBOL_tINKEY = 197,                   /* tINKEY  */
  YYSYMBOL_tCHR = 198,                     /* tCHR  */
  YYSYMBOL_tASC = 199,                     /* tASC  */
  YYSYMBOL_tHEX = 200,                     /* tHEX  */
  YYSYMBOL_tDEC = 201,                     /* tDEC  */
  YYSYMBOL_tBIN = 202,                     /* tBIN  */
  YYSYMBOL_tUPPER = 203,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 204,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 205,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 206,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 207,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 208,                /* tMOUSEMOD  */
  YYSYMBOL_tTRIM = 209,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 210,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 211,                   /* tRTRIM  */
  YYSYMBOL_tSTRING2 = 212,                 /* tSTRING2  */
  YYSYMBOL_tREPLACE = 213,                 /* tREPLACE  */
  YYSYMBOL_tINSTR = 214,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 215,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 216,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 217,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 218,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 219,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 220,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 221,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 222,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 223,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 224,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 225,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 226,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 227,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 228,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 229,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 230,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 231,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 232,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 233,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 234,                    /* tDATE  */
  YYSYMBOL_tTIME = 235,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 236,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 237,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 238,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 239,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 240,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 241,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 242,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 243, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 244,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 245, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 246,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 247,                   /* tEVAL2  */
  YYSYMBOL_tARGUMENT = 248,                /* tARGUMENT  */
  YYSYMBOL_249_ = 249,                     /* '-'  */
  YYSYMBOL_250_ = 250,                     /* '+'  */
  YYSYMBOL_251_ = 251,                     /* '*'  */
  YYSYMBOL_252_ = 252,                     /* '/'  */
  YYSYMBOL_UMINUS = 253,                   /* UMINUS  */
  YYSYMBOL_254_ = 254,                     /* ';'  */
  YYSYMBOL_255_ = 255,                     /* ','  */
  YYSYMBOL_256_ = 256,                     /* '('  */
  YYSYMBOL_257_ = 257,                     /* ')'  */
  YYSYMBOL_258_ = 258,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 259,                 /* $accept  */
  YYSYMBOL_program_or_expression = 260,    /* program_or_expression  */
  YYSYMBOL_program = 261,                  /* program  */
  YYSYMBOL_statement_list = 262,           /* statement_list  */
  YYSYMBOL_263_1 = 263,                    /* $@1  */
  YYSYMBOL_264_2 = 264,                    /* $@2  */
  YYSYMBOL_assignment = 265,               /* assignment  */
  YYSYMBOL_statement = 266,                /* statement  */
  YYSYMBOL_267_3 = 267,                    /* $@3  */
  YYSYMBOL_268_4 = 268,                    /* $@4  */
  YYSYMBOL_269_5 = 269,                    /* $@5  */
  YYSYMBOL_270_6 = 270,                    /* $@6  */
  YYSYMBOL_271_7 = 271,                    /* $@7  */
  YYSYMBOL_272_8 = 272,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 273,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 274,        /* string_assignment  */
  YYSYMBOL_to = 275,                       /* to  */
  YYSYMBOL_open_clause = 276,              /* open_clause  */
  YYSYMBOL_seek_clause = 277,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 278,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 279,        /* string_expression  */
  YYSYMBOL_string_function = 280,          /* string_function  */
  YYSYMBOL_number_assignment = 281,        /* number_assignment  */
  YYSYMBOL_expression = 282,               /* expression  */
  YYSYMBOL_283_9 = 283,                    /* $@9  */
  YYSYMBOL_284_10 = 284,                   /* $@10  */
  YYSYMBOL_arrayref = 285,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 286,          /* string_arrayref  */
  YYSYMBOL_coordinates = 287,              /* coordinates  */
  YYSYMBOL_function = 288,                 /* function  */
  YYSYMBOL_const = 289,                    /* const  */
  YYSYMBOL_number = 290,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 291,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 292,                  /* dimlist  */
  YYSYMBOL_function_or_array = 293,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 294,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 295,                /* call_list  */
  YYSYMBOL_296_11 = 296,                   /* $@11  */
  YYSYMBOL_calls = 297,                    /* calls  */
  YYSYMBOL_call_item = 298,                /* call_item  */
  YYSYMBOL_function_definition = 299,      /* function_definition  */
  YYSYMBOL_300_12 = 300,                   /* $@12  */
  YYSYMBOL_301_13 = 301,                   /* $@13  */
  YYSYMBOL_302_14 = 302,                   /* $@14  */
  YYSYMBOL_endsub = 303,                   /* endsub  */
  YYSYMBOL_function_name = 304,            /* function_name  */
  YYSYMBOL_export = 305,                   /* export  */
  YYSYMBOL_local_list = 306,               /* local_list  */
  YYSYMBOL_local_item = 307,               /* local_item  */
  YYSYMBOL_static_list = 308,              /* static_list  */
  YYSYMBOL_static_item = 309,              /* static_item  */
  YYSYMBOL_paramlist = 310,                /* paramlist  */
  YYSYMBOL_paramitem = 311,                /* paramitem  */
  YYSYMBOL_for_loop = 312,                 /* for_loop  */
  YYSYMBOL_313_15 = 313,                   /* $@15  */
  YYSYMBOL_314_16 = 314,                   /* $@16  */
  YYSYMBOL_315_17 = 315,                   /* $@17  */
  YYSYMBOL_316_18 = 316,                   /* $@18  */
  YYSYMBOL_next = 317,                     /* next  */
  YYSYMBOL_step_part = 318,                /* step_part  */
  YYSYMBOL_next_symbol = 319,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 320,  /* switch_number_or_string  */
  YYSYMBOL_321_19 = 321,                   /* $@19  */
  YYSYMBOL_sep_list = 322,                 /* sep_list  */
  YYSYMBOL_number_or_string = 323,         /* number_or_string  */
  YYSYMBOL_case_list = 324,                /* case_list  */
  YYSYMBOL_325_20 = 325,                   /* $@20  */
  YYSYMBOL_default = 326,                  /* default  */
  YYSYMBOL_327_21 = 327,                   /* $@21  */
  YYSYMBOL_do_loop = 328,                  /* do_loop  */
  YYSYMBOL_329_22 = 329,                   /* $@22  */
  YYSYMBOL_loop = 330,                     /* loop  */
  YYSYMBOL_while_loop = 331,               /* while_loop  */
  YYSYMBOL_332_23 = 332,                   /* $@23  */
  YYSYMBOL_333_24 = 333,                   /* $@24  */
  YYSYMBOL_wend = 334,                     /* wend  */
  YYSYMBOL_repeat_loop = 335,              /* repeat_loop  */
  YYSYMBOL_336_25 = 336,                   /* $@25  */
  YYSYMBOL_until = 337,                    /* until  */
  YYSYMBOL_if_clause = 338,                /* if_clause  */
  YYSYMBOL_339_26 = 339,                   /* $@26  */
  YYSYMBOL_340_27 = 340,                   /* $@27  */
  YYSYMBOL_341_28 = 341,                   /* $@28  */
  YYSYMBOL_342_29 = 342,                   /* $@29  */
  YYSYMBOL_endif = 343,                    /* endif  */
  YYSYMBOL_short_if = 344,                 /* short_if  */
  YYSYMBOL_345_30 = 345,                   /* $@30  */
  YYSYMBOL_end_of_if = 346,                /* end_of_if  */
  YYSYMBOL_else_part = 347,                /* else_part  */
  YYSYMBOL_elsif_part = 348,               /* elsif_part  */
  YYSYMBOL_349_31 = 349,                   /* $@31  */
  YYSYMBOL_350_32 = 350,                   /* $@32  */
  YYSYMBOL_maybe_then = 351,               /* maybe_then  */
  YYSYMBOL_inputlist = 352,                /* inputlist  */
  YYSYMBOL_353_33 = 353,                   /* $@33  */
  YYSYMBOL_input = 354,                    /* input  */
  YYSYMBOL_readlist = 355,                 /* readlist  */
  YYSYMBOL_readitem = 356,                 /* readitem  */
  YYSYMBOL_datalist = 357,                 /* datalist  */
  YYSYMBOL_printlist = 358,                /* printlist  */
  YYSYMBOL_using = 359,                    /* using  */
  YYSYMBOL_inputbody = 360,                /* inputbody  */
  YYSYMBOL_361_34 = 361,                   /* $@34  */
  YYSYMBOL_362_35 = 362,                   /* $@35  */
  YYSYMBOL_363_36 = 363,                   /* $@36  */
  YYSYMBOL_364_37 = 364,                   /* $@37  */
  YYSYMBOL_365_38 = 365,                   /* $@38  */
  YYSYMBOL_366_39 = 366,                   /* $@39  */
  YYSYMBOL_367_40 = 367,                   /* $@40  */
  YYSYMBOL_368_41 = 368,                   /* $@41  */
  YYSYMBOL_369_42 = 369,                   /* $@42  */
  YYSYMBOL_370_43 = 370,                   /* $@43  */
  YYSYMBOL_371_44 = 371,                   /* $@44  */
  YYSYMBOL_372_45 = 372,                   /* $@45  */
  YYSYMBOL_373_46 = 373,                   /* $@46  */
  YYSYMBOL_prompt = 374,                   /* prompt  */
  YYSYMBOL_printintro = 375,               /* printintro  */
  YYSYMBOL_hashed_number = 376,            /* hashed_number  */
  YYSYMBOL_goto_list = 377,                /* goto_list  */
  YYSYMBOL_gosub_list = 378                /* gosub_list  */
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
#define YYFINAL  255
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   15870

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  259
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  652
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  2077

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   504


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
       2,     2,     2,     2,     2,   258,     2,     2,     2,     2,
     256,   257,   251,   250,   255,   249,     2,   252,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   254,
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
     245,   246,   247,   248,   253
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   239,   239,   240,   241,   242,   243,   246,   249,   250,
     250,   250,   253,   254,   255,   256,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   274,   275,   275,   276,   277,   278,   279,   280,
     281,   282,   282,   284,   284,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   296,   297,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   314,   315,
     316,   317,   318,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   499,   500,
     501,   502,   503,   507,   508,   509,   510,   511,   512,   515,
     516,   519,   520,   521,   522,   523,   526,   527,   530,   531,
     534,   535,   536,   537,   538,   539,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   568,   569,   570,   571,   574,   575,   578,   579,
     583,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   613,   614,   617,   617,   618,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,   630,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   653,   656,   659,   662,   663,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   715,
     716,   717,   718,   719,   720,   721,   722,   723,   724,   725,
     726,   727,   728,   729,   730,   731,   732,   735,   736,   739,
     742,   743,   744,   745,   746,   747,   748,   749,   750,   751,
     752,   753,   754,   755,   756,   757,   760,   761,   762,   765,
     766,   767,   768,   771,   772,   775,   776,   777,   778,   781,
     784,   787,   787,   790,   791,   792,   795,   796,   799,   800,
     803,   799,   808,   809,   812,   813,   816,   817,   818,   819,
     822,   823,   826,   827,   828,   829,   832,   833,   836,   837,
     838,   839,   842,   843,   844,   847,   848,   849,   850,   853,
     854,   859,   874,   853,   879,   880,   881,   882,   883,   884,
     887,   888,   891,   892,   897,   897,   901,   902,   905,   906,
     910,   912,   911,   916,   917,   917,   921,   921,   927,   928,
     929,   930,   931,   932,   936,   937,   936,   943,   944,   948,
     948,   953,   954,   955,   956,   957,   958,   961,   962,   962,
     964,   961,   968,   969,   970,   971,   972,   973,   976,   976,
     981,   982,   985,   986,   989,   991,   993,   990,   997,   998,
    1001,  1002,  1002,  1005,  1006,  1008,  1009,  1013,  1014,  1017,
    1018,  1020,  1021,  1025,  1026,  1027,  1028,  1031,  1032,  1033,
    1034,  1035,  1038,  1039,  1040,  1043,  1043,  1044,  1044,  1045,
    1045,  1046,  1046,  1047,  1047,  1048,  1048,  1049,  1049,  1050,
    1050,  1051,  1051,  1052,  1052,  1053,  1053,  1054,  1054,  1055,
    1055,  1058,  1059,  1062,  1063,  1064,  1065,  1066,  1067,  1068,
    1069,  1070,  1071,  1072,  1073,  1074,  1075,  1078,  1079,  1081,
    1082,  1085,  1086
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
  "tFILEPANEL", "tPOPUPMENU", "tSIN", "tASIN", "tCOS", "tACOS", "tTAN",
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

#define YYPACT_NINF (-1548)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-558)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1694, 13080, 11001, 12504,    11,   151,    33,   -47,   -44, -1548,
   -1548, -1548, -1548, -1548,    75,    75,    75,  8001, -1548, -1548,
   -1548, 12504, -1548, -1548, 12504,    52,    96, -1548, -1548, -1548,
   11001,   -41, -1548, 11001,   110, -1548, 11001, 11001, 11001,   157,
      35,    75,  3607,  2309,  4230,    70, 11001,  7001,  8251,   369,
      23, 11001, -1548,    32, 12504, 12504, 12504,    31, 11001,  2136,
   11001, 11001,  8501,  8751,  7251,  6001, 11001,  6501,  9001,  9251,
   11477, 12504, 12504,    -4,  6751,  9501,  9751, 10001, 11001, 11001,
    5751,  6251,  5251,  5501, 10251, 10501, 11596, 11715, 11834,    28,
     -18,  7501, 12504,  -128,   -85,   -58,   -48,     0,  4230, 12504,
   12504, 12504, -1548,   201, -1548, -1548,   128, -1548, -1548, -1548,
   -1548,   183,   187, -1548,   242, -1548, -1548, -1548, -1548, -1548,
   -1548, -1548, -1548,    26,    50, -1548, -1548, -1548, -1548,    56,
      80,   108,   114, 11001,   118,   124,   126,   138,   140,   168,
     -21,   170,   174,   176,   262,   204,   274,   -53,   -46,   226,
     360,   362,   -13,     4,    74,    87,   436,   463,   428,   169,
     321, -1548,    -2, 12504, 11001,   346,   385,   404,   423,   434,
     446,   461,   500,   504,   510,   512,   514,   516,   522,   539,
     541,   543,   563,   564,   567,   588,   601,   612,   613,   622,
     623,   641,   658,   682,   715,   716,   740,   757,   759,   760,
     761,   771,   773,   780,   782,   792,   806,   807,   829,   831,
     832,   839,   841,   850,   852,   856,   860,   879,   885,   887,
     906,   917,   918,   949,   958,   959,   960,   961,   973,   974,
     976,   977,   986,   998,  1019, 11001, 11001,   657, -1548,   634,
   -1548, -1548, -1548, -1548,   544,   585,   662,   676,   725, 12504,
     -31,   574,   183,   187,   869, -1548, 11001, -1548, 12504, -1548,
     911, 11001, 12861, -1548, -1548, -1548, -1548, -1548,   175,   610,
     239,   448,   685, -1548, 11001, -1548,   685, -1548, -1548, 11001,
   12861,    93,  1021,   928,  1027,     3, 11001,   -11,   657,  2119,
    1028,  1031,   728,  2119,   657,  1661,   657,  3053,  1044,  1046,
     826, -1548, -1548,  1070,  1070, -1548, -1548,   890, -1548,  7751,
   12504, 11001,    59,  2119,  1014,   -21, -1548, -1548, -1548,  1016,
   11001, 12504, 12504, 12504,  3144, -1548, 11001, -1548,    15, 12504,
    1048, -1548, -1548, 11001, 10751, -1548, -1548,  2119, -1548, -1548,
     685,     2,     2, -1548,    15, 11001, 11001, 11001, 11001, 11001,
   11001, 11001, 12504, 12504, 11001, 11001, 11001, 11001, 11001,    15,
      15, 12504,  1055, 12504,  1056, 12504, 12504,    15, 12504, 12504,
   12504, 12504,    15,  1057, 12504, 12504, 12504,    15, 12504,    15,
   12504,  1068, 12504,   -24,    47,   101, 12504, 12504, 12504, 12504,
   12504,    15, 12504,    15, 12504,    15, 12504,    15,    15,    15,
   12504, 12504, 12504, 12504, 12504,    15, 12504, 12504, 12504, 12504,
      15, 12504, 12504, 12504, 12504, 12504, 12504, 12504,    15, 12504,
   12504, 12504, 11953, 12504, 12504,    15, 12504,  1069, 12504,  1071,
   12504,   152, 12504,   216, 12504,   252, 12504, 12504, 12504, 12504,
   12504, 13405,   281,  1330,  1330,  1330,  4486, 12504,   218,  1090,
     685,   316,   336, -1548,   931, 11001, 11001, 11001, 11001, 12504,
   -1548, -1548, -1548, 11001, 11001,   935, 11001, 11001, 11001, 11001,
    3974,  4230, 12504, -1548,   450,   450, 11001, 11001, 12504, 12504,
   12504, 12504, 12504, 12504, 12504, 12504, 12504, 12504, 12504, 12504,
   12504, 12504, 12504, 12504, 12504, 12504, 12504, 12097, 12504, 12504,
   12504,  1097, -1548, 12504,  1099,  1103,   351,  1102, 11001, 11001,
   11001, 11001, 11001, 11001, 11001, 11001, 11001, 11001,  4230, 11001,
   11001, 11001, 11001, 11001, 11001, 11001, 11001,  4741, 12504, 12504,
   12504, 12504, 12504, 11001, 11001, 11001,  4996, 11001, 12504, 11001,
   12504, 11001, 12504, 12504,   708,  2734, 11239, 11358, 12504, 12504,
   12504, 11001, 12504, 12504, 12504, 12504, 12504, 12504,  4230, 12504,
   -1548, -1548, 12504, 11001, 12504, 12504, 12504, 12504, 12504,   926,
    1104, 12504,  1330, 12504,  1330, 12504, 12504, 12504,  1095,   119,
     969, 12504, 12504, 12504, 12504, 12504, 12504, 12504, 12504, -1548,
   -1548, -1548, 11001, 11001, 11001, 11001, 11001, 11001, 11001, 11001,
   11001, 11001, 11001, 11001,  -169, -1548, -1548, -1548,  2119,  1106,
     685,  1121,  1305,  2119,   626, -1548, -1548, -1548, -1548,  1125,
    1140,  1153, -1548,  1180,  1181,  1155, -1548,   657,  2119,  1169,
   -1548,   657,  2119,  1395,   796,  1407, 12861, 11001,  1198, 12504,
   -1548, -1548, 11001,   657,   927,   279,  1207,  1416,  1248,     5,
   -1548,  1476, -1548, -1548,   553, 11001, 11001, -1548, -1548,   157,
   -1548, -1548,    55, 13429,   685,  2119,   167, 12241, 11001,    15,
     685,   685,   421, 11001, -1548,   -11, -1548, -1548, 11001,   531,
   12504, -1548, 11001,    15, 11001, 11001, 11001,  1233,    15,  1235,
      15,  1243,    15,    15,   592,   685,  1255,  1257,    15,    15,
   13463, 11001, 11001,   627, 12504,   691, 12504,   685,   776, 11001,
     804,   685,   811,   815, 11001, 12504,   825,   834,   844, 11001,
     875, 11001,   881, 12504,   882, 11001, 12504, 12504,   883,   889,
     892,   899,   901, 11001,   902, 11001,   903, 11001,   905, 11001,
   11001, 11001,   685,   913,   914,   685,   915, 11001,   685,   916,
     925,   946, 11001,   685,   947,   948,   685,   993,   995,   996,
   11001,  1003,   685,  1005, 12504,  1007,  1011,  1013, 11001,  1015,
   12504,  1017, 12504,  1023, 12504,  1051, 12504,  1072, 12504,   685,
    1075,  1082,  1084,   685, 11001, 12504,  1264,  1258,  1274,  1278,
   -1548,  1385,  -156, 11001, 11001, 11001, 11001, -1548,  1284,    15,
      15,  2119,   685,   584,  1294,  1295, 13484, 13499,  1515, 13514,
   13529, 13544,  1312,   102,  1307,  1316,  1088,  1328,  1339,  1326,
    1348,  1359,  1365,    15, 13559,  1092,   -32,   685,   685,   685,
     685,   685,  1094,   685,   685,   685,  1101,   685,   685,  1124,
     685,   685,  1127,   685, 12504,   685,  1134,   685,  1145, 12504,
     -23, 12504, 12504, 12504, 12504,  1730,  1762,  1963,  2017,  2033,
    1118,  2104,  1136,  2565,  2725,  1370,  2755,  2945,  3004,  3034,
    3195,  3275,  3297, 13574, -1548,  3394,    10,  1148,  1152,  1154,
      18, 13595, 13619,   165,  1164, -1548,  3508,  3796,    29,  3815,
      82,  3833,    60,    71, -1548,    90, -1548,   213, -1548,   266,
   -1548,   267,   310,   319,   411, 13634,  1167,  1168,  1170,   412,
     415,   443,   438,  1382,    98,  1383,  1400,   464,  3854,   484,
     188,  1176,  1177,  1178, -1548, -1548,  1184,  -209,  1185,  -151,
    1195,   571,   572, -1548, -1548,   685,   685,   685,   685,   685,
     685,   685, -1548, 11001, 11001,   877,    -1,  1596,   365,   197,
     -36,   -45, -1548,   -55,   -55,  1095,  1095, -1548, -1548, -1548,
   12861, -1548, -1548, 11001, -1548, -1548, -1548, -1548,    75,    75,
   -1548, -1548,   239, -1548, -1548,   448, 11001, -1548,  1581, -1548,
   -1548, -1548, -1548, -1548, -1548, -1548, -1548,   554, 13653, 11001,
     207,  3875, 12623, -1548, -1548, 11001, 11001,  1409, 12504, -1548,
   -1548, 11001, -1548,   617,  1411,  1421,  1410,  1428, 13764, 13785,
    1425,  1437, -1548, -1548, -1548, 11001,  1607,  1611, -1548,  1196,
   13824, 11001, 12504,  2119, -1548, -1548, 12504,  1197, -1548, 11001,
   13843, 13858,  1445, 12504, 11001, 11001, 11001, 12504, 11001, 11001,
   11001, 11001, 11001, 11001, 11001, 11001,  1464,  1465, 11001,  1216,
   11001,  1222, 11001,  1473, 12504, 12504, 12504,  1475,  1226, 12504,
   12504, 11001,  1505, 12504,  1506, 11001,  1228, 12504, 13873,   685,
     685, 12504, 12504, 11001, 12504, 11001,  1522, 12504,  1534, 12504,
    1542, 11001,  1543,  1544,  1554, 11001, 11001, 11001,  1556, 12504,
   11001, 11001,  1557, 12504, 11001, 12504, 12504, 11001,  1565, 12504,
   11001,  1230, 11001, 12504, 11001,  1573, 12504,  1232, 11001,  1234,
   11001,  1242, 12504,  1250, 12504,  1252, 12504, 12504, 12504, 13888,
    1256, -1548, 11001, 11001, 11001, -1548, -1548,   657,  2119,   657,
    2119, 13903, 13918, 12861, 11001, 11001, 11001, -1548, -1548, -1548,
   -1548, -1548, 11001, 11001, -1548, 11001, 11001, 11001, -1548, 12504,
   -1548, 12385, -1548, 12504,  1513,  1583, -1548, -1548, 11001, 11001,
   11001, 11001, 12504, -1548, 12504, 11001, 11001, 11001,   685, 11001,
   12504,   582, -1548,  1266,  1269,  1272,  1273, -1548, -1548, -1548,
   -1548, -1548, 11001, -1548, -1548, 11001, -1548, -1548, -1548, -1548,
   -1548, -1548, -1548, -1548, -1548, -1548, -1548, 11001, -1548, -1548,
   11001, 11001, 11001, -1548, 11001, 11001, -1548, 12504, -1548, -1548,
   -1548, -1548, -1548, 11001, -1548, -1548, -1548, -1548, -1548, -1548,
   -1548, -1548, -1548, -1548, -1548, 12504, 12504, 12504, 12504, -1548,
   -1548, -1548, -1548, -1548, 12504, -1548, -1548, -1548, -1548, -1548,
   -1548, 11001, -1548, 11001, 11001, 11001,  1825, 12504, -1548,  1825,
   12504, -1548, 12504, -1548, -1548,   935,  1047, 11001,   111,  2119,
   -1548,  1576, -1548,  1586,  1585,  1595, -1548,  1609,  1617, -1548,
   -1548, -1548,   593, 12861, -1548, -1548, -1548, 11001, 13933, 12504,
    1805, -1548, 12504,   685,   657,   927, 13954, 11001,   249,   617,
     617,  4763,  1621,  1622, -1548,  1613, -1548, -1548, -1548, -1548,
   11001, 11001, -1548, -1548, 13975,  4230,  4230, 12504, 12504,  1624,
    1276,   685, 12504, -1548, 11001, 11001, 12504,   685,  1626, 13990,
      15,  1280,  1628,    15,   657, 14014, 14123, 14144,    15,  1630,
   14180, 12504, 12504,  2119, 12504,  2119, 12504,   657,  2119, 12504,
    1282,   685,   685, 12504, 12504,  1286,  1290,   524,  2119, 12504,
    1292, 12504,  2119, 12504,  1293, 12504,  1299,  1300,  2119,   685,
    2119, 12504,  1308, 12504,  1309, 12504,  2119, 12504, 12504, 12504,
     657, 14204,   657,  2119,  2119, 12504,   685,  2119,  2119, 12504,
    1310,   537,  2119,   685,   685,  2119, 12504,  1311, 14219, 11001,
    2119,  1321,  2119, 12504,   685, 12504, 14234, 12504,   583, 14249,
   12504,  1327, 12504,  1343, 12504,   685,  1346,  1347, 12504, 12504,
    1629,  5018,  6523,  1218, 12504, 12504, -1548,  2119,    15, -1548,
    1635,  6773,  7023,  7523,  7773,  8023,   586,  1636,   265,   685,
   -1548, -1548,  8273,  8523,  1638,   575,  1349,   685,  2119,  2119,
    2119, 14264,   685, -1548, 12504, 12504, 12504, 12504,  8773,  9023,
    9273,  9523,  9773,  1244, 10023, 10273,   370, 10523,   616,  1353,
     439,   507,   624, 10773, 14279, 14294, 11023,  -117,   644,   -75,
     645,   646,    49, -1548, -1548, -1548,    75,    75, -1548, -1548,
   -1548, -1548, 11001,  1855,  1861,  1857, 11240, 11001,   659,  1645,
     508, -1548, 11001, 14313, 12504,  1845, -1548, -1548, -1548, -1548,
   -1548, -1548,  1647,  1649,  2119,  2119, 12504, -1548, -1548,   685,
     685, 12504, 12504,  1356, 14334,  2119,  1357, 12504, 12504, 11001,
   12504, 12504, 11001, 11001, 11001, 11001, 11001, 11001, 12504,   685,
    1366,  1367,  1368,  1378, 11001,  1393,  1399, 12504, 11001, 11001,
    1403, 12504,  1405,  1406, 11001,   685, 11001, 11001,  1424, 12504,
    1426, 11001,  1435,  1436,  1438,  1448, 12504,  1454,  1457, 11001,
   12504,  1458, 11001, 11001,  2119, 11001,  1460,  1461, 11001,   685,
   12504, 12504,  1467, 11001,  1490, 12504,  1493, 12504, 12504,   685,
     685, -1548,  1833,  1834, 11001,  1839,  1494,   685, 11001,   711,
   -1548, -1548, -1548, -1548, -1548, -1548, -1548, 12504, -1548, -1548,
   -1548, -1548, 11001, 12504, 11001,   673,   675,   685,   685, -1548,
   -1548, -1548, -1548, -1548, 11001, -1548, -1548, -1548, 12504, -1548,
   -1548, -1548, 12504, 11001, -1548, 11001, -1548, -1548, -1548, 12504,
   11001, -1548, 12504, -1548, -1548, 12504, -1548, -1548, -1548, 11001,
   -1548, -1548, -1548, -1548, -1548,  1872,   665, 11261,  1864, 11001,
   12504, 11278, 11001,   687,  1669,  1476,   617,  1670,  1671,   617,
   -1548, -1548,   685,  1496,   685, 12504, 12504, 12504,   685,   685,
    1676,   685,   685,    15, 14349, 14370, 14484,    15, 14503,  1497,
   12504, 11001, 11001, 12504, 14539, 11001, 12504,   685, 14560,  2119,
   12504,  1500, 12504, 11001, 14575, 14590,   657,  2119, 12504,   685,
   12504, 14605, 11001, 11001, 12504, 12504,   685, 11001, 12504,   672,
    2119,   685, 11001, 14620, 14635, 14650, 11001, 12504, 14674,  1503,
     685, 12504,   679, 14693, 12504,  1504, 12504,  1518,   685, 12504,
   12504, 11825, 12504, 11001, -1548,  1684,  1685,   -27, -1548,   709,
   14708,   685,  2119, -1548, -1548, 11944,   713,   718, 12142, 12162,
     719, 12288,   727,   737,    73, 12861, 13299, 11001,  1879, -1548,
    1686, -1548,  1687, 14729,   764,   677, 12306,  1886, 11001,   617,
   -1548, -1548, -1548, -1548, 12504,   685,   685,   685, 12504, 11001,
   11001, 12504, 11001, 11001, 11001, 12504,  1519, 14840, 14864,  1526,
   11001, 14898,  1529, 11001,  1530, 11001,  1533, 14919, 11001, 11001,
    1536,  1537, 11001, 14934, 14949,   685,   685, 14964,  1540, 11001,
   14979, 11001, 11001, 11001, 14994,  1558, 11001, 12504,   685, 12504,
   12504,  1560, 11001,  1568, 12504,   685,   685,  1870,   685,  2119,
    1689,  1690,   711, -1548, -1548, 11001, -1548, -1548, -1548, -1548,
   -1548, -1548, -1548, -1548, -1548, 11001, -1548,  1857,  1910,   730,
   12861, -1548, 12504, 11001, 11001, -1548, -1548,  1693,  1476, -1548,
    1695,  1476, 15009, -1548,   685,   685,  1697, 15030,   685, 15054,
    1698, 15069,  1572, 12504, 12504, 12504, 12504, 15088, 12504, 12504,
   15199, 11001,  2119, 12504, 11001,  2119, 15220, 12504, 11001,  2119,
   11001, 12504, 12504, 12504,  2119, 12504, 15259, 15278, 15293, 12504,
   12504,  2119,   685,  1574,   685, 12504,   817, 15308, 12504,   685,
   12504, -1548, -1548, -1548, 12861, 12430,  2119, 12861, -1548, -1548,
    1857,   944,   561, 15323, 12496,  1476, 12504,   617,  1476, 11001,
     617, 11001, 12504, 12504, 11001, 12504, 12504, 12504,   685,   685,
     685,  1600, 11001,   685,   685, 11001, 15338,  1603, 15353, 11001,
     685, 15368, 15389,   685,   685,   685,   685, 11001, 12504, 11001,
    1604,   685, 12504,   685, 12504, 12504,  1606,   685,    46, -1548,
    1857, 12861, -1548, -1548, -1548, -1548, -1548, -1548, -1548, 12504,
   -1548, 11001, -1548,   617,   608, -1548,   617, 15410, -1548, 12991,
     685,   685, 15425,   685,   685,   685, 12504,  2119,  2119, 11001,
   12504, 11001,  2119, 12504, 12504,  2119,   685, 15449, 12504,   685,
    1610,   685, 12504, -1548, -1548, -1548,  1006,  1857,   768, 13210,
   -1548, 12504, -1548, -1548, 11001, -1548, 12504,   685, 15558,   685,
   15579,   685,   685, 11001,   685, 12504,   685, -1548, -1548, -1548,
   -1548, -1548, -1548,  1946,  1872, -1548, -1548,   778,  1476, 13294,
    1476,   685, 12504, 12504, 15615,   685, -1548, -1548, -1548, -1548,
     617, -1548,   617,  1612,   685, 12504,  1476, -1548,  1476, -1548,
   12504,   685,   617,   617,   685, -1548, -1548
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   238,     0,     0,     0,   486,     0,     0,     0,   232,
     509,   544,   549,    18,     0,     0,     0,     0,    31,    33,
     487,     0,   471,   471,     0,   488,    25,    27,   524,   536,
       0,   633,    55,    67,     0,   229,   230,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   239,
     240,     0,   220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   221,     0,     0,     0,
       0,     0,     2,     9,    17,     8,     0,    12,    46,    48,
      14,    29,    30,    28,     0,    20,    21,    24,    23,    22,
      35,    36,   459,   347,   260,   460,   461,   462,   263,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   310,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   274,     0,     0,     0,     0,     0,     0,
       0,   407,   410,   413,   416,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   291,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   261,     0,
     361,   341,   346,   262,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,   471,     0,   471,
       0,     0,    16,   464,   463,    37,    38,    45,     0,     0,
       0,     0,    19,    50,   473,    51,    49,   489,    26,     0,
      16,   568,     0,   637,     0,     0,   597,   629,    69,    68,
       0,     0,    70,   231,    60,     0,    62,     0,   589,   591,
      63,   587,   593,     0,     0,   594,   456,    64,    66,     0,
     216,     0,     0,   648,     0,    92,   218,    86,    47,     0,
       0,     0,     0,     0,     0,    74,     0,    57,    79,     0,
       0,    94,    93,     0,     0,   241,   242,   219,    13,    15,
     233,     0,     0,    85,     0,     0,     0,     0,     0,     0,
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
     234,     0,     0,     7,     0,     0,     0,     0,     0,     0,
     478,   471,   471,     0,     0,   331,     0,     0,     0,     0,
       0,     0,     0,   437,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     471,   471,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   353,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     3,
     329,   327,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,   325,     0,
     243,     0,     0,   545,     9,    39,    40,    41,    43,   492,
     493,    32,   490,   498,   499,    34,   496,   476,   477,   472,
     474,   529,   528,     0,     9,     0,    16,     0,     0,     0,
     634,   635,     0,   600,   602,    52,     0,     0,     0,     0,
      56,   631,   471,   471,     0,     0,     0,   471,   471,     0,
     458,   457,     0,     0,   217,   647,     0,     0,     0,     0,
      96,    73,     0,     0,    78,   629,   250,   249,     0,     0,
       0,    75,     0,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   112,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   169,     0,     0,   170,     0,     0,   175,     0,
       0,     0,     0,   184,     0,     0,   187,     0,     0,     0,
       0,     0,   194,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
       0,     0,     0,   214,     0,     0,   258,     0,     0,     0,
     222,     0,     0,     0,     0,     0,     0,    10,     0,     0,
       0,   326,   248,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   296,   300,   297,
     301,   452,     0,   451,   441,   440,     0,   443,   442,     0,
     445,   444,     0,   448,     0,   446,     0,   306,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   387,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   275,     0,     0,     0,     0,
       0,     0,     0,     0,   408,     0,   411,     0,   414,     0,
     417,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   292,   294,     0,     0,     0,     0,
       0,     0,     0,   265,   362,   356,   358,   360,   357,   359,
     354,   355,   264,     0,     0,   334,   336,   338,   335,   337,
     332,   333,   352,   349,   348,   350,   351,   469,   470,   510,
      16,   556,   554,     0,   555,   551,   553,   550,     0,     0,
     471,   471,     0,   471,   471,     0,     0,   526,   530,   543,
     541,   542,   539,   538,   540,   537,   558,     9,     0,     0,
       0,     0,     0,   598,    53,    54,     0,     0,     0,   605,
     607,     0,   632,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   588,   595,   596,     0,     0,     0,   253,   252,
     256,     0,     0,   365,    58,    76,     0,    89,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   114,
     149,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   471,     0,     0,     0,   223,   224,   225,   226,   227,
     228,     0,     0,    16,     0,     0,     0,   484,   485,   479,
     429,   321,     0,     0,   420,     0,     0,     0,   430,     0,
     431,     0,   424,     0,     0,     0,   342,   343,     0,     0,
       0,     0,     0,   455,     0,     0,     0,     0,   447,     0,
       0,     0,   307,     0,     0,     0,     0,   366,   367,   368,
     369,   370,     0,   371,   373,     0,   374,   376,   377,   339,
     383,   384,   378,   380,   381,   382,   379,     0,   386,   391,
       0,     0,     0,   390,     0,     0,   273,     0,   270,   276,
     277,   392,   319,     0,   393,   320,   278,   279,   406,   409,
     412,   415,   282,   280,   281,     0,     0,     0,     0,   285,
     399,   286,   405,   404,     0,   295,   400,   287,   401,   288,
     403,     0,   289,     0,     0,     0,     0,     0,   314,     0,
       0,   316,     0,   436,   324,   330,   328,     0,     9,   552,
     649,    42,   651,    44,     0,     0,   491,     0,     0,   497,
     475,   527,   533,    16,   570,   571,   569,     0,     0,     0,
     638,   636,     0,   603,   601,   602,     0,     0,     0,     0,
       0,     0,   583,   585,   630,   580,   465,   467,   471,   471,
       0,     0,   590,   592,    71,     0,     0,     0,     0,     0,
       0,   122,     0,    77,     0,     0,     0,   102,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,   118,     0,   120,     0,   125,   126,     0,
       0,   130,   129,     0,     0,     0,     0,     0,   138,     0,
       0,     0,   145,     0,     0,     0,     0,     0,   152,   151,
     153,     0,     0,     0,     0,     0,   160,     0,     0,     0,
     164,     0,   166,   167,   168,     0,   172,   174,   173,     0,
     177,   180,   181,   185,   186,   183,     0,     0,     0,     0,
     191,     0,   193,     0,   197,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   211,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    87,     0,    91,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   438,
     363,   364,     0,     0,     0,     0,   453,   450,   302,   303,
     304,     0,   449,   308,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   548,   547,   546,     0,     0,   494,   495,
     500,   501,     0,     0,     0,   559,     0,     0,     0,     0,
       0,   599,     0,     0,     0,   619,   606,   608,   609,   471,
     471,   581,     0,     0,    59,    61,     0,   254,   255,   251,
     257,     0,     0,    90,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   139,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   192,     0,     0,     0,     0,   198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   212,
     115,   259,     0,     0,     0,     0,   236,   237,     0,   502,
     418,   419,   421,   422,   423,   432,   433,     0,   434,   344,
     345,   317,     0,     0,     0,     0,     0,   299,   298,   372,
     375,   385,   266,   267,     0,   269,   388,   389,     0,   271,
     394,   283,     0,     0,   395,     0,   397,   312,   290,     0,
       0,   323,     0,   426,   313,     0,   428,   315,   340,     0,
     650,   652,   531,   534,   525,   574,   640,     0,   639,     0,
       0,     0,     0,     0,     0,   631,     0,     0,     0,     0,
     466,   468,    72,     0,    97,     0,     0,     0,   103,   106,
       0,   101,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,     0,   136,
       0,     0,     0,     0,   140,     0,   146,   147,     0,   155,
       0,   157,     0,     0,     0,     0,   165,     0,     0,     0,
     179,   182,     0,     0,     0,     0,     0,     0,     0,     0,
     201,     0,     0,     0,     0,     0,     0,     0,   213,     0,
       0,     0,     0,     0,    88,   505,   506,     0,   503,     0,
       0,   454,   305,   439,   311,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   520,    16,   238,     0,   572,   644,
       0,   641,     0,     0,     0,   611,     0,   621,     0,     0,
     610,   584,   586,   582,     0,   121,    82,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,   162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   200,     0,
       0,     0,     0,     0,     0,   246,   247,     0,   245,   235,
       0,     0,     0,   480,   435,     0,   268,   272,   284,   396,
     398,   402,   322,   425,   427,     0,   511,   532,     9,   578,
      16,   560,     0,     0,     0,   604,   623,     0,   631,   613,
       0,   631,     0,   620,    95,   110,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,     0,     0,   141,     0,     0,     0,   158,
       0,     0,     0,     0,   178,     0,     0,     0,     0,     0,
       0,   199,   202,     0,   204,     0,     0,     0,     0,   210,
       0,   507,   508,   504,    16,     0,   521,    16,   579,   575,
     573,     0,     0,     0,     0,   631,     0,     0,   631,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   116,   117,
     119,     0,     0,   128,   123,     0,     0,     0,     0,     0,
     150,     0,     0,   159,   163,   171,   176,     0,     0,     0,
       0,   196,     0,   203,     0,     0,     0,   244,     9,   318,
     512,    16,   567,   564,   565,   566,   562,   563,   561,     0,
     645,     0,   642,     0,     0,   612,     0,     0,   622,     0,
     109,   100,     0,   111,   105,   215,     0,   132,   137,     0,
       0,     0,   148,     0,     0,   195,   190,     0,     0,   205,
       0,   208,     0,   483,   482,   481,     0,   576,     0,     0,
     624,     0,   625,   614,     0,   615,     0,   124,     0,   142,
       0,   154,   156,     0,   188,     0,   206,   515,   517,   518,
     519,   514,   516,   522,   574,   646,   643,     0,   631,     0,
     631,   108,     0,     0,     0,   207,   523,   513,   577,   627,
       0,   617,     0,   133,   144,     0,   631,   626,   631,   616,
       0,   189,     0,     0,   134,   628,   618
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1548, -1548, -1548,  -175, -1548, -1548,  1950,   823, -1548, -1548,
   -1548, -1548, -1548, -1548, -1548,  1904,   -64, -1548, -1548,  -389,
      -3, -1548,  1905,  1608, -1548, -1548,  1485,  -469,  2980, -1548,
    1301,   -39,   -12, -1548,     1,     7,   131, -1548, -1548,   988,
    1960, -1548, -1548, -1548, -1548, -1548, -1548, -1548,   997, -1548,
     992, -1548,   136, -1548, -1548, -1548, -1548, -1548, -1548, -1548,
   -1548, -1548, -1548, -1548,   488, -1548, -1548, -1548, -1548, -1548,
   -1548, -1548, -1548, -1548, -1548, -1548, -1548, -1548, -1548, -1548,
   -1548, -1548, -1548, -1548, -1548, -1548, -1548, -1548, -1548,   -73,
   -1548, -1548, -1548, -1264, -1548, -1548, -1548,  1314, -1548, -1548,
     689,  1302, -1548, -1548, -1548, -1548, -1548, -1548, -1548, -1548,
   -1548, -1548, -1548, -1548, -1548, -1547, -1548,   -20, -1548, -1548
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,   102,   103,   454,  1133,   104,   105,   270,   271,
     968,   969,   287,   675,   106,   107,   678,   108,   109,   787,
     237,   238,   110,   324,   944,   943,   819,   820,   325,   240,
     305,   241,   265,   292,   242,   243,   273,   274,   629,   630,
     113,   803,  1420,  1914,  2015,  1139,   114,   621,   622,   625,
     626,  1737,  1738,   115,   260,  1257,  1917,  2016,  2043,  1846,
    2057,   116,   279,   978,   633,  1272,  1755,  1484,  1756,   117,
     280,   985,   118,   261,   960,  1475,   119,   262,   967,   120,
     635,  1273,  1645,  1921,  1978,   121,   636,  1276,  1851,  1758,
    1971,  2044,  1919,  1294,  1659,  1295,   300,   301,   307,   645,
     993,   650,  1289,  1290,  1656,  1858,  1928,  2050,  2068,  1655,
    1861,  1925,  2048,  2066,   651,  1003,   286,   314,  1261,  1263
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     250,   306,   111,   266,   267,   252,   822,   640,   112,   999,
     641,   253,  1000,   605,   676,     7,     8,   282,   272,   283,
     284,   276,   599,   318,   319,  1496,  1497,   676,   256,   308,
     288,   258,   599,   255,   294,   296,     7,     8,   122,   312,
     598,   599,   125,   126,   127,   302,  1247,   646,  1248,   647,
     648,   340,   341,   342,   252,   788,   789,   386,   122,   480,
     253,  1639,   125,   126,   127,  1013,   482,   383,   384,   385,
     666,  2013,   595,   596,   597,   598,   599,   437,   449,   263,
     277,   588,   264,   431,   433,   435,  1845,   614,   933,   442,
    2014,   472,   473,   438,   588,   448,   450,   451,   452,   487,
     488,  1126,   481,   278,  1250,   634,  1251,   387,  1769,   483,
     504,    53,   590,   591,   290,   291,   490,   491,   336,   592,
     593,   594,   595,   596,   597,   598,   599,  1473,   443,   581,
     582,   583,   584,   585,   586,   587,   590,   591,  1632,  -557,
    1633,   343,   489,   592,   593,   594,   595,   596,   597,   598,
     599,   320,   321,   505,   275,  1474,   590,   591,   322,   492,
     506,   298,   299,   592,   593,   594,   595,   596,   597,   598,
     599,   444,   581,   582,   583,   584,   585,   586,   587,    20,
    1635,   323,  1636,   927,    25,   929,   493,   494,   436,   581,
     582,   583,   584,   585,   586,   587,   602,   603,   445,   496,
     497,    93,    94,    95,   600,   601,   602,   603,   446,   257,
     615,   616,   259,   600,   601,   602,   603,   285,   588,   588,
     455,   456,    93,    94,    95,  1163,   588,   588,  1832,   495,
    1833,   725,   457,   579,  1172,   581,   582,   583,   584,   585,
     586,   587,   498,   619,   620,   453,   604,   649,   600,   601,
     602,   603,   588,  1016,  1017,   610,   447,   677,   458,   642,
     588,  1001,   459,   111,   660,   661,   460,  1199,   588,   112,
     677,   627,   597,   598,   599,  1203,   631,   684,   685,   588,
     686,   111,   257,   643,   303,   304,  1211,   112,   581,   582,
     583,   584,   585,   586,   587,   701,   702,   588,   600,   601,
     602,   603,   726,   709,   303,   304,   259,   664,   714,   588,
     588,  1927,   461,   719,  1930,   721,   478,  1216,   670,   671,
     672,   588,   600,   601,   602,   603,   679,   733,  1217,   735,
     502,   737,   588,   739,   740,   741,   462,  1213,   484,  1214,
     588,   747,   600,   601,   602,   603,   752,  1218,   588,   694,
     695,   588,   588,  1234,   760,  1235,   727,  1149,   703,  1150,
     705,   768,   707,   708,   463,   710,   711,   712,   713,   588,
     464,   716,   717,   718,   466,   720,   933,   722,  1983,   724,
     467,  1986,   468,   728,   729,   730,   731,   732,   609,   734,
     611,   736,  1770,   738,   469,  1773,   470,   742,   743,   744,
     745,   746,   588,   748,   749,   750,   751,   774,   753,   754,
     755,   756,   757,   758,   759,   588,   761,   762,   763,   765,
     766,   767,  1206,   769,   471,   771,   474,   773,   331,   775,
     475,   777,   476,   779,   780,   781,   782,   783,   588,   596,
     597,   598,   599,  1241,   792,  1242,   600,   601,   602,   603,
     814,   815,   623,   624,   817,   818,   802,   588,   332,   333,
     334,   987,  1279,   588,  1280,   335,   588,   813,   588,   816,
    1219,   776,   485,   793,   486,   825,   826,   827,   828,   829,
     830,   831,   832,   833,   834,   835,   836,   837,   838,   839,
     840,   841,   842,   843,   845,   846,   847,   848,   865,   588,
     850,  2060,   588,  2062,  1494,  1863,  1495,   778,   581,   582,
     583,   584,   585,   586,   587,   588,   588,   588,   477,  2072,
    1597,  2073,  1598,  1220,  1221,   876,   877,   878,   879,   880,
     479,   588,   883,   994,   995,   888,   785,   890,   913,   892,
     893,   895,   897,   899,   901,   902,   903,   904,   499,   906,
     907,   908,   909,   910,   911,   912,   914,  1006,  1007,   917,
     588,   919,   920,   921,   922,   923,   588,  1222,   926,   588,
     928,   795,   930,   931,   932,   500,  1223,   503,   935,   936,
     937,   938,   939,   940,   941,   942,   588,   676,  1137,  1138,
     501,   796,   804,   805,   581,   582,   583,   584,   585,   586,
     587,   588,   508,  1274,  1275,  1021,   853,   581,   582,   583,
     584,   585,   586,   587,   600,   601,   602,   603,   606,  1029,
     588,  1292,  1293,   306,  1034,  1618,  1036,  1619,  1038,  1039,
     617,   618,  1482,  1483,  1043,  1044,   990,   111,   590,   591,
     961,   509,   962,   112,   963,   592,   593,   594,   595,   596,
     597,   598,   599,   581,   582,   583,   584,   585,   586,   587,
     510,   588,   588,  1985,  1019,   588,  1988,   964,  1224,  1229,
     965,   588,  1230,   590,   591,   966,  1022,  1027,   589,   511,
     592,   593,   594,   595,   596,   597,   598,   599,   588,   588,
     512,   915,   916,   588,  1623,  1232,  1624,   590,   591,   489,
    1231,  1049,   513,  1051,   592,   593,   594,   595,   596,   597,
     598,   599,  1058,   124,   588,  1735,  1736,   514,   128,  2020,
    1066,  1238,  2023,  1069,  1070,  1759,  1760,   581,   582,   583,
     584,   585,   586,   587,   588,  1135,  1136,  1856,  1857,   130,
     492,  1240,   581,   582,   583,   584,   585,   586,   587,   581,
     582,   583,   584,   585,   586,   587,   515,   588,   588,  1160,
     516,  1101,  1625,  1650,  1626,   933,   517,  1107,   518,  1109,
     519,  1111,   520,  1113,   588,  1115,  1918,  1467,   521,  1539,
    1469,   588,  1120,  1004,  1005,  1258,  1026,   588,  1010,  1011,
    1127,  1129,  1560,   590,   591,   522,  2067,   523,  2069,   524,
     592,   593,   594,   595,   596,   597,   598,   599,  2075,  2076,
     979,   588,   980,   143,   981,   144,  1979,   495,  1980,   525,
     526,   588,   588,   527,   600,   601,   602,   603,  1253,  1254,
     677,   498,   588,   588,   147,   148,   588,   982,  1570,  1443,
     983,  1168,   588,  1595,   528,   984,  1171,  1040,  1173,  1174,
    1175,  1176,   244,   245,   246,   247,   156,   529,   588,   600,
     601,   602,   603,  2021,   158,  2022,   588,   159,   530,   531,
     160,   161,   248,  1621,   588,   163,   164,   588,   532,   533,
     505,  1627,  1048,   600,   601,   602,   603,   581,   582,   583,
     584,   585,   586,   587,   588,   588,   588,   534,   186,   187,
     188,  1634,  1637,  1638,   192,   193,   194,   588,   196,   588,
     198,   199,   200,   607,   535,   612,  1648,   205,   206,   207,
     208,   209,   588,   588,   212,   588,   214,  1809,   216,   588,
    1743,   218,  1744,   220,  1819,   588,   222,   588,   536,   224,
     225,   588,   226,   227,  1767,   229,  1050,   231,   593,   594,
     595,   596,   597,   598,   599,   234,  1260,  1262,  1972,   588,
    1973,   111,  1974,   588,   249,   894,  1834,   112,   588,   588,
    1837,   537,   538,   627,   797,  1838,  1841,   588,   992,   600,
     601,   602,   603,   654,  1843,  1975,   638,   588,  1976,  1283,
     590,   591,  1284,  1977,  1844,  1288,   539,   592,   593,   594,
     595,   596,   597,   598,   599,   592,   593,   594,   595,   596,
     597,   598,   599,   540,   588,   541,   542,   543,   588,  1310,
    2037,  1855,  2038,  1311,  2039,  2045,   588,   544,   588,   545,
    1317,  1052,   590,   591,  1321,  2059,   546,  1324,   547,   592,
     593,   594,   595,   596,   597,   598,   599,  2040,   548,  1337,
    2041,  1340,  1341,  1342,   588,  2042,  1345,  1346,  1347,  1054,
    1350,   588,   549,   550,  1354,   588,  1055,   588,  1356,  1357,
    1056,  1359,  1964,   122,  1362,   588,  1364,   125,   126,   127,
    1059,   659,  1370,  1372,   588,   551,  1376,   552,   553,  1060,
    1380,  1381,  1383,  1384,   588,   554,  1387,   555,  1485,  1061,
    1391,  1264,  1265,  1394,  1267,  1268,   556,  1398,   557,  1401,
     590,  1403,   558,  1405,  1406,  1407,   559,   592,   593,   594,
     595,   596,   597,   598,   599,   588,   600,   601,   602,   603,
    1063,   588,   588,   588,   111,   560,  1065,  1067,  1071,   588,
     112,   561,   588,   562,  1072,   662,  1426,  1073,  1428,   588,
    1429,   588,   588,   588,  1074,   588,  1075,  1077,  1079,  1436,
    1081,  1437,   563,   588,   588,   588,   588,  1442,  1085,  1086,
    1087,  1089,   599,   564,   565,   588,   600,   601,   602,   603,
    1090,   590,   591,   924,   600,   601,   602,   603,   592,   593,
     594,   595,   596,   597,   598,   599,   588,   588,   588,   590,
     591,  1091,  1093,  1094,  1456,   566,   592,   593,   594,   595,
     596,   597,   598,   599,   567,   568,   569,   570,   600,   601,
     602,   603,  1458,  1459,  1460,  1461,   934,   590,   591,   571,
     572,  1462,   573,   574,   592,   593,   594,   595,   596,   597,
     598,   599,   575,   588,  1468,   588,   588,  1470,  1095,  1471,
    1096,  1097,  1410,   588,   576,   588,  1519,   588,  1099,  1522,
    1100,   588,  1102,   588,  1526,   588,  1103,   588,  1104,   667,
    1106,   668,  1108,   588,   111,   577,  1488,   637,  1110,  1490,
     112,   590,   591,   639,   652,  1507,  1508,   653,   592,   593,
     594,   595,   596,   597,   598,   599,   600,   601,   602,   603,
     657,   588,   658,   680,  1509,  1510,  1112,   590,   591,  1513,
     704,   706,   715,  1516,   592,   593,   594,   595,   596,   597,
     598,   599,   588,   723,   770,   588,   772,  1114,  1529,  1530,
    1116,  1531,   588,  1532,   588,   786,  1533,  1117,   588,  1118,
    1535,  1536,   588,  1153,   588,   794,  1540,  1162,  1542,  1164,
    1543,   588,  1545,   849,  1588,   851,  1165,   854,  1548,   852,
    1550,   925,  1552,   957,  1553,  1554,  1555,   600,   601,   602,
     603,  1602,  1557,  1182,   588,  1183,  1558,   588,   958,  1166,
     959,   970,  1167,  1561,   588,   600,   601,   602,   603,  1169,
    1566,  1185,  1567,  1186,  1569,   588,   971,  1572,   588,  1574,
    1170,  1576,   588,  1200,   588,  1579,  1580,  1201,   972,  1202,
     975,  1586,  1587,   600,   601,   602,   603,   588,   588,  1207,
     588,  1208,  1226,  1227,   976,  1228,   588,   588,   588,  1502,
    1503,  1243,  1244,  1245,   588,   588,   973,   974,   977,  1246,
    1249,  1605,  1606,  1607,  1608,   588,   588,   588,   590,   591,
    1252,  1307,  1312,   986,   989,   592,   593,   594,   595,   596,
     597,   598,   599,   996,  1640,  1641,   588,   600,   601,   602,
     603,  1334,   588,  1584,   997,  1585,   588,  1336,   588,   631,
     588,  1344,   588,  1353,   588,  1389,  1002,  1395,  1033,  1397,
    1035,  1653,   588,   600,   601,   602,   603,  1400,  1037,  1614,
     588,  1615,   588,  1662,   998,  1402,   588,  1404,  1663,  1664,
    1041,  1409,  1042,  1122,  1668,  1669,   588,  1671,  1672,   588,
    1121,  1444,   588,   588,  1445,  1679,   588,  1446,  1447,  1123,
     588,  1512,   588,  1124,  1687,  1520,   588,  1534,  1691,  1134,
     588,  1537,   588,   588,  1696,  1538,  1699,  1541,  1544,   588,
     588,  1140,  1141,  1706,  1546,  1547,  1709,  1711,   588,   588,
     588,   588,  1151,  1549,  1551,  1559,  1562,  1719,  1720,  1148,
    1722,   588,  1725,  1152,  1727,  1728,  1565,   588,   590,   591,
    1847,  1848,  1573,  1156,  1154,   592,   593,   594,   595,   596,
     597,   598,   599,   588,  1739,  1155,   588,   588,  1575,   588,
    1741,  1577,  1578,   588,  1603,  1157,   588,   588,  1622,  1779,
     239,  1665,  1667,  1783,  1158,  1746,   588,   588,   588,  1747,
    1159,  1680,  1681,  1682,  1271,   269,  1750,  1189,   588,  1752,
    1657,  1658,  1753,  1683,   600,   601,   602,   603,   281,  1233,
    1236,   289,  1125,   588,   293,   295,   297,  1764,  1685,   588,
     313,   313,   313,   588,  1686,   588,   588,  1237,  1690,   337,
    1692,  1693,  1775,  1776,  1777,  1287,  1298,   593,  1296,   595,
     596,   597,   598,   599,   588,  1920,   588,  1786,  1297,  1698,
    1789,  1700,  1302,  1792,  1299,   588,   588,  1794,   588,  1796,
    1702,  1703,  1305,  1704,  1303,  1800,  1306,  1801,   588,   441,
    1316,  1805,  1806,  1705,   588,  1808,   313,   588,   588,  1707,
     588,   588,  1708,  1712,  1815,  1716,  1717,   588,  1818,  1331,
    1332,  1821,  1721,  1823,   590,   591,  1825,  1826,  1339,  1828,
    1343,   592,   593,   594,   595,   596,   597,   598,   599,  1968,
     588,   465,  1970,   588,   588,  1724,   588,   588,  1726,  1733,
     588,  1774,  1785,   588,   588,  1795,   111,   111,  1817,  1822,
    1349,  1351,   112,   112,   600,   601,   602,   603,   588,   588,
    1430,  1864,  1144,  1824,  1873,  1865,   588,  1361,  1868,   588,
     588,  1876,  1872,   588,  1879,  1881,   588,   588,  1883,  1363,
     588,  1887,  1888,   590,   591,  1893,  2017,  1365,  1367,  1368,
     592,   593,   594,   595,   596,   597,   598,   599,   588,  1369,
     588,  1375,  1379,  1900,  1902,  1905,  1903,  1904,   588,  1906,
    1386,  1909,   588,  1908,   588,   590,   591,  1937,  1393,  1962,
     818,  1476,   592,   593,   594,   595,   596,   597,   598,   599,
    1431,  1477,  1478,   578,   580,   600,   601,   602,   603,  1922,
     588,   111,  1479,   588,   588,  1996,   588,   112,  2000,  2008,
     588,  2012,   588,  1489,   608,  2035,  1480,  2070,  1501,   613,
    1938,  1939,  1940,  1941,  1481,  1943,  1944,  1499,  1500,  1511,
    1947,  1517,   628,  1521,  1950,  1527,  1581,   632,  1953,  1954,
    1955,  1589,  1956,  1596,   644,  1601,  1960,  1961,  1643,  1644,
      -9,  1649,  1963,  1654,  1660,  1966,  1661,  1967,  1729,  1730,
     600,   601,   602,   603,  1732,   111,   655,   663,   111,   665,
    1757,   112,  1762,  1984,   112,  1768,  1850,  1771,  1772,  1990,
    1991,  1778,  1993,  1994,  1995,     1,     2,     3,     4,     5,
    1830,  1831,  1852,  1853,  1860,  1910,  1911,  1912,  -535,  1926,
    2056,  1929,  1932,  1935,   251,  2006,  1416,   338,   339,  2009,
     821,  2010,  2011,  1014,  1270,   254,   700,  1269,  1913,  1266,
    1642,  2058,   111,  1012,  1491,     0,  2018,  1024,   112,   600,
     601,   602,   603,     0,     0,     0,     0,  1177,     0,     0,
       0,     0,     0,  2027,     0,     0,     0,  2029,     0,     0,
    2031,  2032,     0,     0,     0,  2034,     0,     0,     0,  2036,
       0,   600,   601,   602,   603,     0,     0,     0,  2047,  1178,
       0,     0,     0,  2051,     0,     0,   590,   591,     0,     0,
       0,     0,  2055,   592,   593,   594,   595,   596,   597,   598,
     599,     0,     0,     0,     0,     0,     0,     0,     0,  2063,
    2064,     0,     0,     0,   791,     0,     0,     0,     0,     0,
       0,     0,  2071,     0,     0,     0,   801,  2074,     0,     0,
       0,   806,   807,     0,   808,   809,   810,   811,   313,   313,
     590,   591,     0,     0,     0,   824,     0,   592,   593,   594,
     595,   596,   597,   598,   599,     0,   590,   591,     0,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,     0,     0,     0,     0,   855,   856,   857,   858,
     859,   860,   861,   862,   863,   864,   313,   866,   867,   868,
     869,   870,   871,   872,   873,   875,     0,     0,     0,     0,
       0,   881,   882,   884,   886,   887,     0,   889,     0,   891,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   905,
       0,     0,     0,     0,     0,     0,   313,   590,   591,     0,
       0,   918,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   590,   591,     0,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,     0,     0,     0,
     945,   946,   947,   948,   949,   950,   951,   952,   953,   954,
     955,   956,   600,   601,   602,   603,     0,     0,     0,     0,
    1179,     0,     0,     0,     0,     0,   345,   346,   347,   348,
     349,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     350,     0,     0,     0,     0,   988,   351,   352,     0,     0,
     991,     0,   353,   354,   355,   356,   357,     0,     0,     0,
       0,     0,     0,  1008,  1009,     0,   600,   601,   602,   603,
       0,     0,     0,     0,  1180,     0,  1020,     0,     0,     0,
       0,  1023,   600,   601,   602,   603,     0,     0,     0,     0,
    1181,     0,  1030,  1031,     0,     0,     0,     0,     0,     0,
       0,   358,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,   123,   124,     0,   125,   126,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1068,     0,     0,     0,     0,     0,   129,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   600,   601,   602,   603,     0,     0,     0,
       0,  1184,     0,     0,     0,     0,     0,     0,   600,   601,
     602,   603,   131,   132,   133,   134,   135,   136,   137,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,     0,  1119,   139,     0,     0,     0,     0,   315,     0,
       0,  1128,  1130,  1131,  1132,     0,   316,     0,     0,     0,
     141,   142,     0,     0,   143,     0,   144,     0,     0,   317,
       0,     0,     0,     0,   145,     0,     0,     0,     0,     0,
       0,   146,     0,     0,     0,   147,   148,     0,     0,     0,
       0,     0,     0,     0,     0,   149,     0,   150,   151,     0,
       0,     0,     0,   152,   153,   154,   155,   156,   157,     0,
       0,     0,     0,     0,     0,   158,     0,     0,   159,     0,
       0,   160,   161,   162,     0,     0,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
       0,   217,   218,   219,   220,     0,   221,   222,     0,   223,
     224,   225,     0,   226,   227,   228,   229,   230,   231,   232,
       0,  1255,  1256,     0,     0,   233,   234,     0,   235,     0,
       0,     0,     0,     0,     0,   236,     0,   311,     0,     0,
       0,  1259,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   628,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1278,     0,     0,
       0,     0,     0,  1285,  1286,     0,     0,     0,     0,  1291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1304,     0,     0,     0,     0,   590,   591,
       0,     0,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,  1319,     0,     0,     0,     0,  1325,  1326,
    1327,     0,     0,  1330,     0,     0,  1333,     0,  1335,     0,
    1338,     0,     0,     0,     0,     0,     0,     0,     0,  1348,
       0,     0,     0,  1352,     0,     0,     0,     0,     0,     0,
       0,  1358,     0,  1360,     0,     0,     0,     0,     0,  1366,
       0,     0,     0,  1371,  1373,  1374,     0,     0,  1377,  1378,
       0,     0,  1382,     0,     0,  1385,     0,     0,  1388,     0,
    1390,     0,  1392,     0,     0,     0,  1396,     0,  1399,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1411,  1412,  1413,     0,     0,     0,     0,     0,     0,   124,
       0,     0,  1417,     0,   128,     0,     0,     0,     0,     0,
    1421,  1422,     0,  1423,  1424,  1425,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,  1432,  1433,     0,  1435,
       0,     0,     0,  1438,  1439,  1440,     0,  1441,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   590,   591,
    1448,     0,     0,  1449,     0,   592,   593,   594,   595,   596,
     597,   598,   599,     0,     0,  1450,     0,     0,  1451,  1452,
    1453,     0,  1454,  1455,   600,   601,   602,   603,   590,   591,
       0,  1457,  1187,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,     0,     0,     0,     0,     0,     0,   143,
       0,   144,     0,     0,     0,     0,     0,     0,     0,  1463,
       0,  1464,  1465,  1466,     0,     0,     0,     0,     0,     0,
     147,   148,     0,     0,     0,  1472,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   244,   245,
     246,   247,   156,     0,     0,  1486,     0,     0,     0,     0,
     158,     0,     0,   159,     0,  1493,   160,   161,   248,     0,
       0,   163,   164,     0,     0,     0,     0,     0,  1504,  1505,
       0,     0,     0,   313,   313,     0,     0,     0,     0,     0,
       0,     0,  1514,  1515,   186,   187,   188,     0,     0,     0,
     192,   193,   194,     0,   196,     0,   198,   199,   200,     0,
       0,     0,     0,   205,   206,   207,   208,   209,     0,     0,
     212,     0,   214,     0,   216,     0,     0,   218,     0,   220,
       0,     0,   222,     0,     0,   224,   225,     0,   226,   227,
       0,   229,     0,   231,   600,   601,   602,   603,     0,     0,
       0,   234,  1188,     0,     0,     0,     0,     0,     0,     0,
     249,   896,     0,     0,     0,     0,     0,  1564,     0,     0,
       0,     0,     0,     0,   600,   601,   602,   603,   590,   591,
       0,     0,  1190,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,     0,     0,     0,     0,   328,   330,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   344,     0,
     359,   360,   362,   364,   367,   372,   373,   377,   379,   381,
       0,     0,     0,     0,   391,   393,   395,   397,   398,   399,
     405,   410,   418,   425,   427,   429,     0,   590,   591,     0,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,     0,     0,     0,     0,     0,     0,     0,     0,
     632,     0,     0,     0,     0,  1647,     0,   590,   591,     0,
    1651,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,     0,     0,     0,     0,   590,   591,     0,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,  1674,  1675,  1676,     0,  1678,     0,     0,     0,     0,
       0,     0,  1684,     0,   507,     0,  1688,  1689,     0,     0,
       0,     0,  1694,     0,  1695,  1697,     0,     0,     0,  1701,
       0,     0,     0,     0,     0,     0,     0,  1710,     0,     0,
    1713,  1714,     0,  1715,     0,     0,  1718,     0,     0,     0,
       0,  1723,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1731,     0,   600,   601,   602,   603,     0,     0,
       0,     0,  1191,     0,     0,     0,     0,   590,   591,     0,
    1740,     0,  1742,     0,   592,   593,   594,   595,   596,   597,
     598,   599,  1745,     0,     0,     0,     0,     0,     0,     0,
       0,  1748,     0,  1749,     0,     0,     0,     0,  1751,     0,
       0,     0,     0,     0,     0,     0,     0,  1754,     0,     0,
       0,     0,     0,   600,   601,   602,   603,  1763,   590,   591,
    1766,  1192,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   600,   601,   602,   603,     0,     0,  1787,
    1788,  1193,     0,  1791,     0,     0,     0,     0,     0,     0,
     669,  1797,   600,   601,   602,   603,   674,     0,   656,     0,
    1803,  1804,     0,   681,   683,  1807,     0,     0,     0,     0,
    1810,     0,     0,     0,  1814,   687,   688,   689,   690,   691,
     692,   693,     0,     0,   696,   697,   698,   699,   590,   591,
       0,  1829,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,     0,     0,     0,     0,     0,     0,     0,
     590,   591,     0,     0,     0,  1849,     0,   592,   593,   594,
     595,   596,   597,   598,   599,     0,  1862,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1867,     0,
    1869,     0,  1871,   600,   601,   602,   603,     0,  1877,   673,
       0,  1880,     0,  1882,     0,     0,  1885,  1886,     0,     0,
    1889,     0,     0,     0,     0,     0,     0,  1894,     0,  1896,
    1897,  1898,     0,     0,  1901,     0,     0,     0,     0,     0,
    1907,     0,     0,     0,     0,   798,   799,   800,     0,     0,
       0,     0,     0,  1915,   600,   601,   602,   603,     0,     0,
       0,     0,  1194,  1916,     0,     0,   823,   590,   591,     0,
       0,  1923,  1924,     0,   592,   593,   594,   595,   596,   597,
     598,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1946,
       0,     0,  1948,     0,     0,     0,  1951,     0,  1952,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   600,   601,   602,   603,     0,     0,
       0,     0,  1195,     0,     0,     0,     0,  1987,     0,  1989,
       0,     0,  1992,     0,     0,     0,   600,   601,   602,   603,
    1997,     0,     0,  1998,  1196,     0,     0,  2002,     0,     0,
       0,     0,     0,     0,     0,  2005,     0,  2007,     0,     0,
       0,   590,   591,     0,     0,     0,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   599,     0,     0,     0,  2019,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2028,     0,  2030,
     122,   123,   124,     0,   125,   126,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2049,     0,     0,     0,     0,   129,   130,     0,
       0,  2054,     0,   600,   601,   602,   603,     0,     0,     0,
       0,  1198,     0,     0,     0,     0,     0,     0,  1025,     0,
       0,     0,  1028,     0,     0,     0,  1032,     0,     0,     0,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
       0,  1046,  1047,     0,     0,     0,     0,     0,   138,  1053,
       0,   139,     0,     0,  1057,     0,   309,     0,     0,  1062,
       0,  1064,     0,     0,   310,     0,     0,     0,   141,   142,
       0,     0,   143,  1076,   144,  1078,     0,  1080,     0,  1082,
    1083,  1084,   145,     0,     0,     0,     0,  1088,     0,   146,
       0,     0,  1092,   147,   148,     0,     0,     0,     0,     0,
    1098,     0,     0,   149,     0,   150,   151,     0,  1105,     0,
       0,   152,   153,   154,   155,   156,   157,   600,   601,   602,
     603,     0,     0,   158,     0,  1209,   159,     0,     0,   160,
     161,   162,     0,     0,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,     0,   217,
     218,   219,   220,     0,   221,   222,     0,   223,   224,   225,
       0,   226,   227,   228,   229,   230,   231,   232,     0,     0,
       0,     0,     0,   233,   234,     0,   235,     0,     0,   590,
     591,     0,     0,   236,     0,   311,   592,   593,   594,   595,
     596,   597,   598,   599,     0,     0,     0,     0,   590,   591,
       0,     0,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,     0,     0,     0,   590,   591,     0,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,     0,     0,     0,     0,     0,   590,   591,     0,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,     0,     0,     0,     0,     0,     0,   590,   591,
       0,     0,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   122,   123,   124,
       0,   125,   126,   127,   128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1309,     0,     0,   129,   130,     0,     0,     0,  1313,
       0,     0,     0,     0,  1318,     0,  1320,     0,  1322,  1323,
       0,     0,     0,  1328,  1329,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   132,   133,
     134,   135,   136,   137,     0,   600,   601,   602,   603,     0,
       0,     0,     0,  1210,     0,   138,     0,     0,   139,     0,
       0,     0,     0,   140,   600,   601,   602,   603,     0,     0,
       0,   812,  1212,     0,     0,   141,   142,     0,     0,   143,
       0,   144,   600,   601,   602,   603,     0,     0,     0,   145,
    1215,     0,     0,     0,     0,     0,   146,     0,     0,     0,
     147,   148,     0,   600,   601,   602,   603,     0,     0,     0,
     149,  1239,   150,   151,     0,  1418,  1419,     0,   152,   153,
     154,   155,   156,   157,   600,   601,   602,   603,     0,     0,
     158,     0,  1281,   159,     0,     0,   160,   161,   162,     0,
    1434,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,     0,   217,   218,   219,   220,
       0,   221,   222,     0,   223,   224,   225,     0,   226,   227,
     228,   229,   230,   231,   232,     0,     0,     0,     0,     0,
     233,   234,     0,   235,     0,     0,     0,     0,     0,     0,
     236,     0,   311,   122,   123,   124,     0,   125,   126,   127,
     128,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,   132,   133,   134,   135,   136,   137,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,     0,     0,   139,     0,     0,     0,     0,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   141,   142,     0,     0,   143,     0,   144,     0,     0,
       0,     0,     0,     0,     0,   145,     0,     0,     0,     0,
       0,     0,   146,     0,     0,     0,   147,   148,     0,     0,
       0,     0,     0,     0,     0,     0,   149,     0,   150,   151,
       0,     0,     0,     0,   152,   153,   154,   155,   156,   157,
       0,     0,     0,     0,     0,     0,   158,     0,     0,   159,
       0,     0,   160,   161,   162,     0,     0,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,     0,   217,   218,   219,   220,     0,   221,   222,     0,
     223,   224,   225,     0,   226,   227,   228,   229,   230,   231,
     232,     0,     0,     0,     0,     0,   233,   234,     0,   235,
       0,     0,     0,     0,     0,     0,   236,     0,   311,   122,
     123,   124,     0,   125,   126,   127,   128,     0,     0,  1670,
       0,     0,  1673,     0,     0,     0,  1677,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,  1734,     0,
     139,     0,     0,     0,     0,   140,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,   142,     0,
       0,   143,     0,   144,     0,     0,     0,     0,     0,     0,
       0,   145,     0,     0,     0,     0,     0,     0,   146,     0,
       0,     0,   147,   148,     0,     0,     0,     0,     0,     0,
       0,     0,   149,     0,   150,   151,     0,     0,     0,     0,
     152,   153,   154,   155,   156,   157,     0,     0,     0,     0,
       0,     0,   158,     0,     0,   159,     0,     0,   160,   161,
     162,     0,     0,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,     0,   217,   218,
     219,   220,     0,   221,   222,     0,   223,   224,   225,     0,
     226,   227,   228,   229,   230,   231,   232,     0,     0,     0,
       0,     0,   233,   234,     0,   235,     0,     0,     0,     0,
       0,     0,   236,   790,   122,   123,   124,     0,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,  1866,
       0,     0,     0,  1870,     0,     0,     0,     0,     0,     0,
       0,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,     0,     0,     0,   236,   874,   122,
     123,   124,     0,   125,   126,   127,   128,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1498,     0,     0,     0,     0,     0,   129,   130,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,     0,     0,
     139,   590,   591,     0,     0,   140,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   599,     0,   141,   142,     0,
       0,   143,     0,   144,     0,     0,     0,     0,     0,     0,
       0,   145,     0,     0,     0,     0,     0,     0,   146,     0,
       0,     0,   147,   148,     0,     0,     0,     0,     0,     0,
       0,     0,   149,     0,   150,   151,     0,     0,     0,     0,
     152,   153,   154,   155,   156,   157,     0,     0,     0,     0,
       0,     0,   158,     0,     0,   159,     0,     0,   160,   161,
     162,     0,     0,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,     0,   217,   218,
     219,   220,     0,   221,   222,     0,   223,   224,   225,     0,
     226,   227,   228,   229,   230,   231,   232,     0,     0,     0,
       0,     0,   233,   234,     0,   235,     0,     0,     0,     0,
       0,     0,   236,   885,   122,   123,   124,     0,   125,   126,
     127,   128,     0,     0,     0,     0,     0,   600,   601,   602,
     603,     0,     0,     0,     0,  1582,     0,     0,     0,     0,
       0,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,     0,     0,     0,     0,
     140,     0,     0,     0,     0,     0,   411,     0,     0,     0,
       0,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,   412,   413,   152,   153,   154,   155,   156,
     157,     0,   414,   415,   416,   417,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   419,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,     0,     0,     0,     0,
     140,     0,     0,     0,     0,     0,   420,     0,     0,     0,
       0,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,   421,   422,   152,   153,   154,   155,   156,
     157,   423,     0,     0,     0,   424,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,     0,     0,     0,     0,
     140,     0,     0,     0,     0,     0,   400,     0,     0,     0,
       0,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,   401,   402,   152,   153,   154,   155,   156,
     157,     0,   403,     0,     0,   404,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   368,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,     0,     0,     0,     0,
     140,     0,     0,     0,     0,     0,   369,     0,     0,     0,
       0,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,   370,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,   371,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,     0,     0,     0,     0,
     140,     0,     0,     0,     0,     0,   406,     0,     0,     0,
       0,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,   407,   408,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,   409,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   374,     0,     0,     0,     0,     0,     0,
       0,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   375,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,   376,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1583,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,   388,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,   389,   390,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,   326,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1590,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   327,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1591,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,     0,     0,     0,     0,
     140,     0,     0,     0,     0,     0,   365,     0,     0,     0,
       0,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,   366,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,     0,   439,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,   440,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1592,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,     0,   472,   473,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1593,   129,   130,     0,     0,   268,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1594,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,   329,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1599,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,   361,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1600,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,   363,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1609,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,   378,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1610,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,   380,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1611,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,   392,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1612,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,   394,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1613,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,   396,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1616,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,   426,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1617,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,   428,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,   682,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1620,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,     0,     0,     0,   233,   234,     0,
     235,     0,     0,     0,   122,   123,   124,   236,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1628,   129,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,     0,     0,   139,   590,   591,     0,     0,
     140,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,   141,   142,     0,     0,   143,     0,   144,     0,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,   146,     0,     0,     0,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,   150,
     151,     0,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,     0,     0,     0,   158,     0,     0,
     159,     0,     0,   160,   161,   162,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,     0,   217,   218,   219,   220,     0,   221,   222,
       0,   223,   224,   225,     0,   226,   227,   228,   229,   230,
     231,   232,     0,     0,   124,     0,     0,   233,   234,   128,
     235,     0,     0,     0,     0,     0,     0,   236,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,     0,   600,   601,   602,   603,     0,     0,     0,     0,
    1631,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   590,   591,     0,     0,     0,     0,     0,
     592,   593,   594,   595,   596,   597,   598,   599,     0,     0,
       0,     0,     0,     0,   590,   591,     0,     0,     0,     0,
       0,   592,   593,   594,   595,   596,   597,   598,   599,     0,
       0,   590,   591,     0,   143,     0,   144,     0,   592,   593,
     594,   595,   596,   597,   598,   599,     0,     0,     0,     0,
       0,     0,     0,   124,     0,   147,   148,     0,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   244,   245,   246,   247,   156,     0,   130,
       0,     0,     0,     0,     0,   158,     0,     0,   159,     0,
       0,   160,   161,   248,     0,     0,   163,   164,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   186,
     187,   188,     0,     0,     0,   192,   193,   194,     0,   196,
       0,   198,   199,   200,     0,     0,     0,     0,   205,   206,
     207,   208,   209,     0,     0,   212,     0,   214,     0,   216,
       0,     0,   218,   143,   220,   144,     0,   222,     0,     0,
     224,   225,     0,   226,   227,     0,   229,     0,   231,     0,
       0,     0,   124,     0,   147,   148,   234,   128,     0,   600,
     601,   602,   603,     0,     0,   249,   898,  1646,     0,     0,
       0,     0,   244,   245,   246,   247,   156,     0,   130,     0,
     600,   601,   602,   603,   158,     0,     0,   159,  1761,     0,
     160,   161,   248,     0,     0,   163,   164,   600,   601,   602,
     603,     0,     0,     0,     0,  1765,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,   187,
     188,     0,     0,     0,   192,   193,   194,     0,   196,     0,
     198,   199,   200,     0,     0,     0,     0,   205,   206,   207,
     208,   209,     0,     0,   212,     0,   214,     0,   216,     0,
       0,   218,   143,   220,   144,     0,   222,     0,   382,   224,
     225,     0,   226,   227,     0,   229,     0,   231,     0,     0,
       0,   124,     0,   147,   148,   234,   128,     0,     0,     0,
       0,     0,     0,     0,   249,   900,     0,     0,     0,     0,
       0,   244,   245,   246,   247,   156,     0,   130,     0,     0,
       0,     0,     0,   158,     0,     0,   159,     0,     0,   160,
     161,   248,     0,     0,   163,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   186,   187,   188,
       0,     0,     0,   192,   193,   194,     0,   196,     0,   198,
     199,   200,     0,     0,     0,     0,   205,   206,   207,   208,
     209,     0,     0,   212,     0,   214,     0,   216,     0,     0,
     218,   143,   220,   144,     0,   222,     0,   430,   224,   225,
       0,   226,   227,     0,   229,     0,   231,     0,     0,     0,
     124,     0,   147,   148,   234,   128,     0,     0,     0,     0,
       0,     0,     0,   249,     0,     0,     0,     0,     0,     0,
     244,   245,   246,   247,   156,     0,   130,     0,     0,     0,
       0,     0,   158,     0,     0,   159,     0,     0,   160,   161,
     248,     0,     0,   163,   164,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   186,   187,   188,     0,
       0,     0,   192,   193,   194,     0,   196,     0,   198,   199,
     200,     0,     0,     0,     0,   205,   206,   207,   208,   209,
       0,     0,   212,     0,   214,     0,   216,     0,     0,   218,
     143,   220,   144,     0,   222,     0,   432,   224,   225,     0,
     226,   227,     0,   229,     0,   231,     0,     0,     0,   124,
       0,   147,   148,   234,   128,     0,     0,     0,     0,     0,
       0,     0,   249,     0,     0,     0,     0,     0,     0,   244,
     245,   246,   247,   156,     0,   130,     0,     0,     0,     0,
       0,   158,     0,     0,   159,     0,     0,   160,   161,   248,
       0,     0,   163,   164,     0,     0,     0,     0,   590,   591,
       0,     0,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,     0,     0,   186,   187,   188,     0,     0,
       0,   192,   193,   194,     0,   196,     0,   198,   199,   200,
       0,     0,     0,     0,   205,   206,   207,   208,   209,     0,
       0,   212,     0,   214,     0,   216,     0,     0,   218,   143,
     220,   144,     0,   222,     0,   434,   224,   225,     0,   226,
     227,     0,   229,     0,   231,     0,     0,     0,   124,     0,
     147,   148,   234,   128,     0,     0,     0,     0,     0,     0,
       0,   249,     0,     0,     0,     0,     0,     0,   244,   245,
     246,   247,   156,     0,   130,     0,     0,     0,     0,     0,
     158,     0,     0,   159,     0,     0,   160,   161,   248,     0,
       0,   163,   164,     0,     0,     0,     0,   590,   591,     0,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,     0,     0,   186,   187,   188,     0,     0,     0,
     192,   193,   194,     0,   196,     0,   198,   199,   200,     0,
       0,     0,     0,   205,   206,   207,   208,   209,     0,     0,
     212,     0,   214,     0,   216,     0,     0,   218,   143,   220,
     144,     0,   222,     0,     0,   224,   225,     0,   226,   227,
       0,   229,     0,   231,   600,   601,   602,   603,     0,   147,
     148,   234,  1827,     0,     0,     0,     0,     0,     0,     0,
     249,     0,     0,     0,     0,     0,     0,   244,   245,   246,
     247,   156,   124,   764,     0,     0,     0,   128,     0,   158,
       0,     0,   159,     0,     0,   160,   161,   248,     0,     0,
     163,   164,     0,     0,     0,     0,     0,     0,   130,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,   187,   188,     0,     0,     0,   192,
     193,   194,     0,   196,     0,   198,   199,   200,     0,     0,
       0,     0,   205,   206,   207,   208,   209,     0,     0,   212,
       0,   214,     0,   216,     0,     0,   218,     0,   220,     0,
       0,   222,     0,     0,   224,   225,     0,   226,   227,     0,
     229,     0,   231,   600,   601,   602,   603,     0,     0,     0,
     234,  1836,   143,     0,   144,   590,   591,     0,     0,   249,
       0,     0,   592,   593,   594,   595,   596,   597,   598,   599,
       0,     0,     0,   147,   148,   590,   591,     0,     0,     0,
       0,     0,   592,   593,   594,   595,   596,   597,   598,   599,
       0,   244,   245,   246,   247,   156,   124,   844,     0,     0,
       0,   128,     0,   158,     0,     0,   159,     0,     0,   160,
     161,   248,     0,     0,   163,   164,     0,     0,     0,     0,
       0,     0,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   186,   187,   188,
       0,     0,     0,   192,   193,   194,     0,   196,     0,   198,
     199,   200,     0,     0,     0,     0,   205,   206,   207,   208,
     209,     0,     0,   212,     0,   214,     0,   216,     0,     0,
     218,     0,   220,     0,     0,   222,     0,     0,   224,   225,
       0,   226,   227,     0,   229,     0,   231,     0,  1018,     0,
       0,     0,     0,     0,   234,     0,   143,     0,   144,     0,
       0,   590,   591,   249,     0,     0,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   599,     0,   147,   148,   590,
     591,     0,     0,     0,     0,     0,   592,   593,   594,   595,
     596,   597,   598,   599,     0,   244,   245,   246,   247,   156,
     124,   600,   601,   602,   603,   128,     0,   158,     0,  1839,
     159,     0,     0,   160,   161,   248,     0,     0,   163,   164,
       0,   600,   601,   602,   603,     0,   130,     0,     0,  1840,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   186,   187,   188,     0,     0,     0,   192,   193,   194,
       0,   196,     0,   198,   199,   200,     0,     0,     0,     0,
     205,   206,   207,   208,   209,     0,     0,   212,     0,   214,
       0,   216,     0,     0,   218,     0,   220,     0,     0,   222,
       0,     0,   224,   225,     0,   226,   227,     0,   229,     0,
     231,     0,  1427,     0,     0,     0,     0,     0,   234,     0,
     143,     0,   144,   590,   591,     0,     0,   249,     0,     0,
     592,   593,   594,   595,   596,   597,   598,   599,     0,   124,
       0,   147,   148,     0,   128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   244,
     245,   246,   247,   156,     0,   130,     0,   600,   601,   602,
     603,   158,     0,     0,   159,  1842,     0,   160,   161,   248,
       0,     0,   163,   164,     0,   600,   601,   602,   603,   590,
     591,     0,     0,  1859,     0,     0,   592,   593,   594,   595,
     596,   597,   598,   599,     0,   186,   187,   188,     0,     0,
       0,   192,   193,   194,     0,   196,     0,   198,   199,   200,
       0,     0,     0,     0,   205,   206,   207,   208,   209,     0,
       0,   212,     0,   214,     0,   216,     0,     0,   218,   143,
     220,   144,     0,   222,     0,     0,   224,   225,     0,   226,
     227,     0,   229,     0,   231,     0,     0,     0,   124,     0,
     147,   148,   234,   128,     0,     0,     0,     0,     0,     0,
       0,   249,     0,     0,     0,     0,     0,     0,   244,   245,
     246,   247,   156,     0,   130,     0,     0,     0,     0,     0,
     158,     0,     0,   159,     0,     0,   160,   161,   248,     0,
       0,   163,   164,     0,     0,     0,     0,     0,     0,   600,
     601,   602,   603,     0,     0,     0,     0,  1969,     0,     0,
       0,     0,     0,     0,   186,   187,   188,     0,     0,     0,
     192,   193,   194,     0,   196,     0,   198,   199,   200,     0,
       0,     0,     0,   205,   206,   207,   208,   209,     0,     0,
     212,     0,   214,     0,   216,     0,     0,   218,   143,   220,
     144,     0,   222,     0,     0,   224,   225,     0,   226,   227,
       0,   229,     0,   231,     0,   600,   601,   602,   603,   147,
     148,   234,     0,  1982,     0,     0,     0,     0,     0,     0,
     249,     0,     0,     0,     0,     0,     0,   244,   245,   246,
     247,   156,     0,     0,     0,     0,     0,     0,     0,   158,
       0,     0,   159,     0,     0,   160,   161,   248,     0,     0,
     163,   164,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,   187,   188,     0,     0,     0,   192,
     193,   194,     0,   196,     0,   198,   199,   200,     0,     0,
       0,     0,   205,   206,   207,   208,   209,     0,     0,   212,
       0,   214,     0,   216,     0,     0,   218,     0,   220,     0,
       0,   222,     0,     0,   224,   225,     0,   226,   227,     0,
     229,     0,   231,     0,     0,     7,     8,     9,     0,     0,
     234,     0,    10,     0,     0,     0,    11,     0,    12,  1282,
      13,    14,    15,    16,    17,  -486,     0,    18,    19,    20,
      21,    22,    23,    24,    25,     0,    26,    27,    28,     0,
       0,     0,     0,    29,     0,     0,    30,     0,     0,     0,
       0,     0,     0,    31,    32,    33,    34,    35,    36,     0,
       0,     0,    37,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
      40,    41,    42,    43,    44,     0,     0,     0,     0,     0,
      45,    46,    47,  -238,  -238,    48,    49,    50,     0,    51,
      52,    53,     0,     0,    54,  -238,     0,    55,     0,    56,
      57,     0,     0,     0,     0,    58,    59,     0,     0,     0,
       0,     0,    60,     0,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,    80,    81,    82,    83,    84,
      85,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,     0,     0,     0,     0,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    95,   590,   591,     0,     0,    96,     0,
       0,   592,   593,   594,   595,   596,   597,   598,   599,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,    98,     0,     7,     8,     9,    99,     0,     0,
     100,    10,     0,     0,   101,    11,     0,    12,     0,    13,
      14,    15,    16,    17,  -486,     0,    18,    19,    20,    21,
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
     600,   601,   602,   603,    90,    91,    92,     0,  2025,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      93,    94,    95,   590,   591,     0,     0,    96,     0,     0,
     592,   593,   594,   595,   596,   597,   598,   599,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,    98,     0,     7,     8,     9,    99,     0,     0,   100,
      10,     0,     0,   101,    11,     0,    12,     0,    13,    14,
      15,    16,    17,  -486,     0,    18,    19,    20,    21,    22,
      23,    24,    25,     0,    26,    27,    28,   -16,     0,     0,
       0,    29,   -16,     0,    30,     0,     0,     0,     0,     0,
       0,    31,    32,    33,    34,    35,    36,   590,   591,     0,
      37,    38,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,     0,     0,     0,     0,     0,    39,    40,    41,
      42,    43,    44,     0,     0,     0,     0,     0,    45,    46,
      47,     0,     0,    48,    49,    50,     0,    51,    52,    53,
       0,     0,    54,     0,     0,    55,     0,    56,    57,     0,
       0,     0,     0,    58,    59,     0,     0,     0,     0,     0,
      60,     0,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,    80,    81,    82,    83,    84,    85,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,   600,
     601,   602,   603,    90,    91,    92,     0,  2046,   590,   591,
       0,     0,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,     0,     0,     0,     0,     0,     0,    93,
      94,    95,   590,   591,     0,     0,    96,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,     0,     0,     0,
      98,     0,     0,     0,     0,    99,   590,   591,   100,     0,
       0,     0,   101,   592,   593,   594,   595,   596,   597,   598,
     599,     0,     0,   600,   601,   602,   603,   590,   591,     0,
       0,  2061,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   590,   591,     0,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,   590,   591,     0,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   590,   591,     0,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,   590,   591,     0,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   590,   591,     0,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,   590,   591,     0,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,     0,     0,   600,   601,   602,   603,   590,   591,
     784,     0,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,     0,     0,     0,     0,     0,   600,   601,
     602,   603,   590,   591,  1015,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,   590,   591,     0,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   590,   591,  1045,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,     0,   600,   601,   602,   603,     0,     0,  1142,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   601,
     602,   603,     0,     0,  1143,     0,     0,     0,     0,     0,
       0,     0,     0,   600,   601,   602,   603,     0,     0,  1145,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   601,
     602,   603,     0,     0,  1146,     0,     0,     0,     0,     0,
       0,     0,     0,   600,   601,   602,   603,     0,     0,  1147,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   601,
     602,   603,     0,     0,  1161,     0,     0,     0,     0,     0,
       0,     0,     0,   600,   601,   602,   603,   590,   591,  1197,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,     0,     0,   600,   601,   602,   603,   590,   591,
    1204,     0,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,     0,     0,     0,     0,     0,   600,   601,
     602,   603,     0,     0,  1205,     0,     0,     0,     0,     0,
       0,     0,     0,   600,   601,   602,   603,   590,   591,  1225,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   590,   591,  1277,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,   590,   591,     0,     0,     0,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   599,   590,   591,     0,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,   590,   591,     0,     0,     0,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   599,   590,   591,     0,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,   590,   591,     0,     0,     0,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   599,   590,   591,     0,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,     0,   600,   601,   602,   603,   590,   591,  1300,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,     0,     0,   600,   601,   602,   603,   590,   591,
    1301,     0,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,   590,   591,     0,     0,     0,     0,     0,
     592,   593,   594,   595,   596,   597,   598,   599,     0,     0,
       0,     0,     0,   600,   601,   602,   603,   590,   591,  1308,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,     0,     0,  1314,     0,
       0,     0,     0,     0,     0,     0,     0,   600,   601,   602,
     603,     0,     0,  1315,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,  1355,     0,
       0,     0,     0,     0,     0,     0,     0,   600,   601,   602,
     603,     0,     0,  1408,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,  1414,     0,
       0,     0,     0,     0,     0,     0,     0,   600,   601,   602,
     603,     0,     0,  1415,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,   590,   591,  1487,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,     0,   600,   601,   602,   603,   590,   591,  1492,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,     0,     0,   600,   601,   602,   603,     0,     0,
    1506,     0,     0,     0,     0,     0,     0,     0,     0,   600,
     601,   602,   603,   590,   591,  1518,     0,     0,     0,     0,
     592,   593,   594,   595,   596,   597,   598,   599,     0,     0,
       0,     0,     0,   600,   601,   602,   603,   590,   591,  1523,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   590,   591,     0,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,   590,   591,     0,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   590,   591,     0,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,   590,   591,     0,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   590,   591,     0,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,   590,   591,     0,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   590,   591,  1524,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,     0,   600,   601,   602,   603,   590,   591,  1525,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   590,   591,     0,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,     0,     0,   600,
     601,   602,   603,   590,   591,  1528,     0,     0,     0,     0,
     592,   593,   594,   595,   596,   597,   598,   599,     0,     0,
       0,     0,     0,   600,   601,   602,   603,     0,     0,  1556,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   601,
     602,   603,     0,     0,  1563,     0,     0,     0,     0,     0,
       0,     0,     0,   600,   601,   602,   603,     0,     0,  1568,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   601,
     602,   603,     0,     0,  1571,     0,     0,     0,     0,     0,
       0,     0,     0,   600,   601,   602,   603,     0,     0,  1604,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   601,
     602,   603,     0,     0,  1629,     0,     0,     0,     0,     0,
       0,     0,     0,   600,   601,   602,   603,   590,   591,  1630,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   590,   591,  1652,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,     0,     0,   600,   601,   602,   603,     0,     0,  1666,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   601,
     602,   603,   590,   591,  1780,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,     0,     0,   600,
     601,   602,   603,   590,   591,  1781,     0,     0,     0,     0,
     592,   593,   594,   595,   596,   597,   598,   599,   590,   591,
       0,     0,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,   590,   591,     0,     0,     0,     0,     0,
     592,   593,   594,   595,   596,   597,   598,   599,   590,   591,
       0,     0,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,   590,   591,     0,     0,     0,     0,     0,
     592,   593,   594,   595,   596,   597,   598,   599,   590,   591,
       0,     0,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,   590,   591,     0,     0,     0,     0,     0,
     592,   593,   594,   595,   596,   597,   598,   599,     0,     0,
       0,     0,     0,   600,   601,   602,   603,   590,   591,  1782,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   590,   591,  1784,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,   590,   591,     0,     0,     0,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   599,     0,     0,   600,   601,
     602,   603,   590,   591,  1790,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,     0,     0,   600,
     601,   602,   603,     0,     0,  1793,     0,     0,     0,     0,
       0,     0,     0,     0,   600,   601,   602,   603,     0,     0,
    1798,     0,     0,     0,     0,     0,     0,     0,     0,   600,
     601,   602,   603,     0,     0,  1799,     0,     0,     0,     0,
       0,     0,     0,     0,   600,   601,   602,   603,     0,     0,
    1802,     0,     0,     0,     0,     0,     0,     0,     0,   600,
     601,   602,   603,     0,     0,  1811,     0,     0,     0,     0,
       0,     0,     0,     0,   600,   601,   602,   603,     0,     0,
    1812,     0,     0,     0,     0,     0,     0,     0,     0,   600,
     601,   602,   603,   590,   591,  1813,     0,     0,     0,     0,
     592,   593,   594,   595,   596,   597,   598,   599,     0,     0,
       0,     0,     0,   600,   601,   602,   603,   590,   591,  1816,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,     0,     0,  1820,     0,
       0,     0,     0,     0,     0,     0,     0,   600,   601,   602,
     603,   590,   591,  1835,     0,     0,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   599,     0,     0,   600,   601,
     602,   603,   590,   591,  1854,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,   590,   591,     0,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   590,   591,     0,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,   590,   591,     0,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   590,   591,     0,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,   590,   591,     0,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   590,   591,     0,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,     0,     0,   600,
     601,   602,   603,   590,   591,  1874,     0,     0,     0,     0,
     592,   593,   594,   595,   596,   597,   598,   599,     0,     0,
       0,     0,     0,   600,   601,   602,   603,   590,   591,  1875,
       0,     0,     0,     0,   592,   593,   594,   595,   596,   597,
     598,   599,   590,   591,     0,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   590,   591,  1878,     0,     0,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   599,     0,     0,   600,   601,
     602,   603,     0,     0,  1884,     0,     0,     0,     0,     0,
       0,     0,     0,   600,   601,   602,   603,     0,     0,  1890,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   601,
     602,   603,     0,     0,  1891,     0,     0,     0,     0,     0,
       0,     0,     0,   600,   601,   602,   603,     0,     0,  1892,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   601,
     602,   603,     0,     0,  1895,     0,     0,     0,     0,     0,
       0,     0,     0,   600,   601,   602,   603,     0,     0,  1899,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   601,
     602,   603,   590,   591,  1931,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,     0,     0,   600,
     601,   602,   603,   590,   591,  1933,     0,     0,     0,     0,
     592,   593,   594,   595,   596,   597,   598,   599,     0,     0,
       0,     0,     0,   600,   601,   602,   603,     0,     0,  1934,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   601,
     602,   603,   590,   591,  1936,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   590,   591,  1942,     0,     0,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   599,   590,   591,     0,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,   590,   591,     0,     0,     0,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   599,   590,   591,     0,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,   590,   591,     0,     0,     0,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   599,   590,   591,     0,     0,
       0,     0,     0,   592,   593,   594,   595,   596,   597,   598,
     599,   590,   591,     0,     0,     0,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   599,     0,     0,   600,   601,
     602,   603,   590,   591,  1945,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,     0,     0,   600,
     601,   602,   603,   590,   591,  1949,     0,     0,     0,     0,
     592,   593,   594,   595,   596,   597,   598,   599,   590,   591,
       0,     0,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,     0,     0,     0,     0,     0,   600,   601,
     602,   603,   590,   591,  1957,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,     0,     0,  1958,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,  1959,     0,
       0,     0,     0,     0,     0,     0,     0,   600,   601,   602,
     603,     0,     0,  1965,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,  1981,     0,
       0,     0,     0,     0,     0,     0,     0,   600,   601,   602,
     603,     0,     0,  1999,     0,     0,     0,     0,     0,     0,
       0,     0,   600,   601,   602,   603,     0,     0,  2001,     0,
       0,     0,     0,     0,     0,     0,     0,   600,   601,   602,
     603,   590,   591,  2003,     0,     0,     0,     0,   592,   593,
     594,   595,   596,   597,   598,   599,     0,     0,   600,   601,
     602,   603,   590,   591,  2004,     0,     0,     0,     0,   592,
     593,   594,   595,   596,   597,   598,   599,     0,     0,   600,
     601,   602,   603,     0,     0,  2024,     0,     0,     0,     0,
       0,     0,     0,     0,   600,   601,   602,   603,   590,   591,
    2026,     0,     0,     0,     0,   592,   593,   594,   595,   596,
     597,   598,   599,     0,     0,     0,     0,     0,   600,   601,
     602,   603,     0,     0,  2033,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   600,   601,   602,
     603,     0,     0,  2052,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   601,
     602,   603,     0,     0,  2053,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   600,   601,   602,   603,     0,     0,
    2065
};

static const yytype_int16 yycheck[] =
{
       3,    40,     1,    15,    16,     4,   475,     4,     1,     4,
       7,     4,     7,    44,    12,     4,     5,    58,    21,    60,
      61,    24,    77,    43,    44,  1289,  1290,    12,    75,    41,
      33,    75,    77,     0,    37,    38,     4,     5,     3,    42,
      76,    77,     7,     8,     9,    10,   255,    58,   257,    60,
      61,    54,    55,    56,    53,   444,   445,    61,     3,   112,
      53,    12,     7,     8,     9,    10,   112,    70,    71,    72,
      11,    25,    73,    74,    75,    76,    77,    95,    98,     4,
      28,   250,     7,    86,    87,    88,    13,   262,   257,    92,
      44,   112,   113,   111,   250,    98,    99,   100,   101,   112,
     113,   257,   155,     7,   255,   280,   257,   111,  1655,   155,
     112,   100,    63,    64,     4,     5,   112,   113,    95,    70,
      71,    72,    73,    74,    75,    76,    77,    16,   256,    70,
      71,    72,    73,    74,    75,    76,    63,    64,   255,    46,
     257,   110,   155,    70,    71,    72,    73,    74,    75,    76,
      77,    81,    82,   155,    23,    44,    63,    64,    88,   155,
     163,     4,     5,    70,    71,    72,    73,    74,    75,    76,
      77,   256,    70,    71,    72,    73,    74,    75,    76,    28,
     255,   111,   257,   572,    33,   574,   112,   113,   160,    70,
      71,    72,    73,    74,    75,    76,   251,   252,   256,   112,
     113,   190,   191,   192,   249,   250,   251,   252,   256,   256,
      35,    36,   256,   249,   250,   251,   252,   258,   250,   250,
      92,    93,   190,   191,   192,   257,   250,   250,   255,   155,
     257,   255,   104,   236,   257,    70,    71,    72,    73,    74,
      75,    76,   155,     4,     5,    44,   249,   258,   249,   250,
     251,   252,   250,    86,    87,   258,   256,   255,    75,   256,
     250,   256,    75,   262,   303,   304,    24,   257,   250,   262,
     255,   274,    75,    76,    77,   257,   279,   341,   342,   250,
     344,   280,   256,   286,   249,   250,   257,   280,    70,    71,
      72,    73,    74,    75,    76,   359,   360,   250,   249,   250,
     251,   252,   255,   367,   249,   250,   256,   310,   372,   250,
     250,  1858,   256,   377,  1861,   379,   112,   257,   321,   322,
     323,   250,   249,   250,   251,   252,   329,   391,   257,   393,
     161,   395,   250,   397,   398,   399,   256,   255,   112,   257,
     250,   405,   249,   250,   251,   252,   410,   257,   250,   352,
     353,   250,   250,   255,   418,   257,   255,   255,   361,   257,
     363,   425,   365,   366,   256,   368,   369,   370,   371,   250,
     256,   374,   375,   376,   256,   378,   257,   380,  1925,   382,
     256,  1928,   256,   386,   387,   388,   389,   390,   257,   392,
     259,   394,  1656,   396,   256,  1659,   256,   400,   401,   402,
     403,   404,   250,   406,   407,   408,   409,   255,   411,   412,
     413,   414,   415,   416,   417,   250,   419,   420,   421,   422,
     423,   424,   257,   426,   256,   428,   256,   430,    59,   432,
     256,   434,   256,   436,   437,   438,   439,   440,   250,    74,
      75,    76,    77,   255,   447,   257,   249,   250,   251,   252,
     470,   471,     4,     5,     4,     5,   459,   250,    89,    90,
      91,   636,   255,   250,   257,    96,   250,   470,   250,   472,
     257,   255,   112,   255,   112,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   518,   250,
     503,  2048,   250,  2050,   255,  1769,   257,   255,    70,    71,
      72,    73,    74,    75,    76,   250,   250,   250,   256,  2066,
     255,  2068,   257,   257,   257,   528,   529,   530,   531,   532,
     256,   250,   535,   254,   255,   538,   255,   540,   558,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   112,   552,
     553,   554,   555,   556,   557,   558,   559,     4,     5,   562,
     250,   564,   565,   566,   567,   568,   250,   257,   571,   250,
     573,   255,   575,   576,   577,   112,   257,   256,   581,   582,
     583,   584,   585,   586,   587,   588,   250,    12,     4,     5,
     162,   255,   461,   462,    70,    71,    72,    73,    74,    75,
      76,   250,   256,    49,    50,   669,   255,    70,    71,    72,
      73,    74,    75,    76,   249,   250,   251,   252,    44,   683,
     250,     4,     5,   662,   688,   255,   690,   257,   692,   693,
      20,    21,    39,    40,   698,   699,   639,   636,    63,    64,
      14,   256,    16,   636,    18,    70,    71,    72,    73,    74,
      75,    76,    77,    70,    71,    72,    73,    74,    75,    76,
     256,   250,   250,  1927,   667,   250,  1930,    41,   257,   257,
      44,   250,   257,    63,    64,    49,   255,   680,    44,   256,
      70,    71,    72,    73,    74,    75,    76,    77,   250,   250,
     256,   560,   561,   250,   255,   257,   257,    63,    64,   155,
     257,   704,   256,   706,    70,    71,    72,    73,    74,    75,
      76,    77,   715,     5,   250,     4,     5,   256,    10,  1983,
     723,   257,  1986,   726,   727,    60,    61,    70,    71,    72,
      73,    74,    75,    76,   250,   799,   800,    60,    61,    31,
     155,   257,    70,    71,    72,    73,    74,    75,    76,    70,
      71,    72,    73,    74,    75,    76,   256,   250,   250,   823,
     256,   764,   255,   255,   257,   257,   256,   770,   256,   772,
     256,   774,   256,   776,   250,   778,    46,  1246,   256,   255,
    1249,   250,   785,   652,   653,   960,   255,   250,   657,   658,
     793,   794,   255,    63,    64,   256,  2060,   256,  2062,   256,
      70,    71,    72,    73,    74,    75,    76,    77,  2072,  2073,
      14,   250,    16,   105,    18,   107,   255,   155,   257,   256,
     256,   250,   250,   256,   249,   250,   251,   252,   257,   257,
     255,   155,   250,   250,   126,   127,   250,    41,   255,   257,
      44,   844,   250,   257,   256,    49,   849,   255,   851,   852,
     853,   854,   144,   145,   146,   147,   148,   256,   250,   249,
     250,   251,   252,   255,   156,   257,   250,   159,   256,   256,
     162,   163,   164,   257,   250,   167,   168,   250,   256,   256,
     155,   257,   255,   249,   250,   251,   252,    70,    71,    72,
      73,    74,    75,    76,   250,   250,   250,   256,   190,   191,
     192,   257,   257,   257,   196,   197,   198,   250,   200,   250,
     202,   203,   204,    44,   256,     4,   257,   209,   210,   211,
     212,   213,   250,   250,   216,   250,   218,   255,   220,   250,
     257,   223,   257,   225,   255,   250,   228,   250,   256,   231,
     232,   250,   234,   235,   257,   237,   255,   239,    71,    72,
      73,    74,    75,    76,    77,   247,   968,   969,    14,   250,
      16,   960,    18,   250,   256,   257,   257,   960,   250,   250,
     257,   256,   256,   976,    43,   257,   257,   250,    51,   249,
     250,   251,   252,   255,   257,    41,    58,   250,    44,   992,
      63,    64,   995,    49,   257,   998,   256,    70,    71,    72,
      73,    74,    75,    76,    77,    70,    71,    72,    73,    74,
      75,    76,    77,   256,   250,   256,   256,   256,   250,  1022,
      14,   257,    16,  1026,    18,   257,   250,   256,   250,   256,
    1033,   255,    63,    64,  1037,   257,   256,  1040,   256,    70,
      71,    72,    73,    74,    75,    76,    77,    41,   256,  1052,
      44,  1054,  1055,  1056,   250,    49,  1059,  1060,  1061,   255,
    1063,   250,   256,   256,  1067,   250,   255,   250,  1071,  1072,
     255,  1074,   255,     3,  1077,   250,  1079,     7,     8,     9,
     255,   255,  1085,  1086,   250,   256,  1089,   256,   256,   255,
    1093,  1094,  1095,  1096,   250,   256,  1099,   256,  1273,   255,
    1103,   970,   971,  1106,   973,   974,   256,  1110,   256,  1112,
      63,  1114,   256,  1116,  1117,  1118,   256,    70,    71,    72,
      73,    74,    75,    76,    77,   250,   249,   250,   251,   252,
     255,   250,   250,   250,  1133,   256,   255,   255,   255,   250,
    1133,   256,   250,   256,   255,   255,  1149,   255,  1151,   250,
    1153,   250,   250,   250,   255,   250,   255,   255,   255,  1162,
     255,  1164,   256,   250,   250,   250,   250,  1170,   255,   255,
     255,   255,    77,   256,   256,   250,   249,   250,   251,   252,
     255,    63,    64,   257,   249,   250,   251,   252,    70,    71,
      72,    73,    74,    75,    76,    77,   250,   250,   250,    63,
      64,   255,   255,   255,  1207,   256,    70,    71,    72,    73,
      74,    75,    76,    77,   256,   256,   256,   256,   249,   250,
     251,   252,  1225,  1226,  1227,  1228,   257,    63,    64,   256,
     256,  1234,   256,   256,    70,    71,    72,    73,    74,    75,
      76,    77,   256,   250,  1247,   250,   250,  1250,   255,  1252,
     255,   255,  1121,   250,   256,   250,  1320,   250,   255,  1323,
     255,   250,   255,   250,  1328,   250,   255,   250,   255,   255,
     255,   255,   255,   250,  1273,   256,  1279,   256,   255,  1282,
    1273,    63,    64,   256,   256,  1305,  1306,   256,    70,    71,
      72,    73,    74,    75,    76,    77,   249,   250,   251,   252,
     256,   250,   256,   255,  1307,  1308,   255,    63,    64,  1312,
     255,   255,   255,  1316,    70,    71,    72,    73,    74,    75,
      76,    77,   250,   255,   255,   250,   255,   255,  1331,  1332,
     255,  1334,   250,  1336,   250,     5,  1339,   255,   250,   255,
    1343,  1344,   250,   255,   250,   255,  1349,   255,  1351,   255,
    1353,   250,  1355,   256,  1418,   256,   255,   255,  1361,   256,
    1363,   257,  1365,   257,  1367,  1368,  1369,   249,   250,   251,
     252,  1435,  1375,   255,   250,   257,  1379,   250,   257,   255,
      75,   256,   255,  1386,   250,   249,   250,   251,   252,   255,
    1393,   255,  1395,   257,  1397,   250,   256,  1400,   250,  1402,
     255,  1404,   250,   255,   250,  1408,  1409,   255,   255,   255,
     255,  1414,  1415,   249,   250,   251,   252,   250,   250,   255,
     250,   257,   255,   255,   255,   255,   250,   250,   250,  1298,
    1299,   255,   255,   255,   250,   250,   256,   256,    43,   255,
     255,  1444,  1445,  1446,  1447,   250,   250,   250,    63,    64,
     255,   255,   255,    46,   256,    70,    71,    72,    73,    74,
      75,    76,    77,   256,  1476,  1477,   250,   249,   250,   251,
     252,   255,   250,   255,    58,   257,   250,   255,   250,  1482,
     250,   255,   250,   255,   250,   255,    10,   255,   255,   255,
     255,  1494,   250,   249,   250,   251,   252,   255,   255,   255,
     250,   257,   250,  1506,   256,   255,   250,   255,  1511,  1512,
     255,   255,   255,   255,  1517,  1518,   250,  1520,  1521,   250,
     256,   255,   250,   250,   255,  1528,   250,   255,   255,   255,
     250,   255,   250,   255,  1537,   255,   250,   255,  1541,   255,
     250,   255,   250,   250,  1547,   255,  1549,   255,   255,   250,
     250,   257,   257,  1556,   255,   255,  1559,  1560,   250,   250,
     250,   250,   255,   255,   255,   255,   255,  1570,  1571,   257,
    1573,   250,  1575,   257,  1577,  1578,   255,   250,    63,    64,
    1755,  1756,   255,   257,   256,    70,    71,    72,    73,    74,
      75,    76,    77,   250,  1597,   256,   250,   250,   255,   250,
    1603,   255,   255,   250,   255,   257,   250,   250,   255,  1673,
       2,   255,   255,  1677,   255,  1618,   250,   250,   250,  1622,
     255,   255,   255,   255,    43,    17,  1629,   257,   250,  1632,
    1499,  1500,  1635,   255,   249,   250,   251,   252,    30,   257,
     257,    33,   257,   250,    36,    37,    38,  1650,   255,   250,
      42,    43,    44,   250,   255,   250,   250,   257,   255,    51,
     255,   255,  1665,  1666,  1667,   256,   256,    71,   257,    73,
      74,    75,    76,    77,   250,  1850,   250,  1680,   257,   255,
    1683,   255,   257,  1686,   256,   250,   250,  1690,   250,  1692,
     255,   255,    85,   255,   257,  1698,    85,  1700,   250,    91,
     255,  1704,  1705,   255,   250,  1708,    98,   250,   250,   255,
     250,   250,   255,   255,  1717,   255,   255,   250,  1721,   255,
     255,  1724,   255,  1726,    63,    64,  1729,  1730,   255,  1732,
     255,    70,    71,    72,    73,    74,    75,    76,    77,  1914,
     250,   133,  1917,   250,   250,   255,   250,   250,   255,   255,
     250,   255,   255,   250,   250,   255,  1755,  1756,   255,   255,
     255,   255,  1755,  1756,   249,   250,   251,   252,   250,   250,
     257,  1774,   257,   255,   255,  1778,   250,   255,  1781,   250,
     250,   255,  1785,   250,   255,   255,   250,   250,   255,   255,
     250,   255,   255,    63,    64,   255,  1971,   255,   255,   255,
      70,    71,    72,    73,    74,    75,    76,    77,   250,   255,
     250,   255,   255,   255,  1817,   255,  1819,  1820,   250,  1822,
     255,  1824,   250,   255,   250,    63,    64,   255,   255,   255,
       5,   255,    70,    71,    72,    73,    74,    75,    76,    77,
     257,   255,   257,   235,   236,   249,   250,   251,   252,  1852,
     250,  1850,   257,   250,   250,   255,   250,  1850,   255,   255,
     250,   255,   250,    58,   256,   255,   257,   255,   255,   261,
    1873,  1874,  1875,  1876,   257,  1878,  1879,   256,   256,   255,
    1883,   255,   274,   255,  1887,   255,   257,   279,  1891,  1892,
    1893,   256,  1895,   257,   286,   257,  1899,  1900,    43,    38,
      43,   256,  1905,    58,   257,  1908,   257,  1910,    75,    75,
     249,   250,   251,   252,    75,  1914,   255,   309,  1917,   311,
      48,  1914,    58,  1926,  1917,   256,    47,   257,   257,  1932,
    1933,   255,  1935,  1936,  1937,   241,   242,   243,   244,   245,
     256,   256,   256,   256,    58,    75,   257,   257,    38,   256,
       4,   256,   255,   255,     4,  1958,  1133,    53,    53,  1962,
     475,  1964,  1965,   662,   976,     5,   358,   975,  1832,   972,
    1482,  2044,  1971,   659,  1285,    -1,  1979,   675,  1971,   249,
     250,   251,   252,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,    -1,  1996,    -1,    -1,    -1,  2000,    -1,    -1,
    2003,  2004,    -1,    -1,    -1,  2008,    -1,    -1,    -1,  2012,
      -1,   249,   250,   251,   252,    -1,    -1,    -1,  2021,   257,
      -1,    -1,    -1,  2026,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,  2035,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2052,
    2053,    -1,    -1,    -1,   446,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2065,    -1,    -1,    -1,   458,  2070,    -1,    -1,
      -1,   463,   464,    -1,   466,   467,   468,   469,   470,   471,
      63,    64,    -1,    -1,    -1,   477,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,    -1,    -1,    -1,    -1,
      -1,   533,   534,   535,   536,   537,    -1,   539,    -1,   541,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   551,
      -1,    -1,    -1,    -1,    -1,    -1,   558,    63,    64,    -1,
      -1,   563,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    93,
      94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     104,    -1,    -1,    -1,    -1,   637,   110,   111,    -1,    -1,
     642,    -1,   116,   117,   118,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,   655,   656,    -1,   249,   250,   251,   252,
      -1,    -1,    -1,    -1,   257,    -1,   668,    -1,    -1,    -1,
      -1,   673,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    -1,   684,   685,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   165,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   725,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,
      -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,   784,    84,    -1,    -1,    -1,    -1,    89,    -1,
      -1,   793,   794,   795,   796,    -1,    97,    -1,    -1,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,   110,
      -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,   222,   223,   224,   225,    -1,   227,   228,    -1,   230,
     231,   232,    -1,   234,   235,   236,   237,   238,   239,   240,
      -1,   943,   944,    -1,    -1,   246,   247,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    -1,   256,    -1,   258,    -1,    -1,
      -1,   963,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   976,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   989,    -1,    -1,
      -1,    -1,    -1,   995,   996,    -1,    -1,    -1,    -1,  1001,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1015,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,  1035,    -1,    -1,    -1,    -1,  1040,  1041,
    1042,    -1,    -1,  1045,    -1,    -1,  1048,    -1,  1050,    -1,
    1052,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1061,
      -1,    -1,    -1,  1065,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1073,    -1,  1075,    -1,    -1,    -1,    -1,    -1,  1081,
      -1,    -1,    -1,  1085,  1086,  1087,    -1,    -1,  1090,  1091,
      -1,    -1,  1094,    -1,    -1,  1097,    -1,    -1,  1100,    -1,
    1102,    -1,  1104,    -1,    -1,    -1,  1108,    -1,  1110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1122,  1123,  1124,    -1,    -1,    -1,    -1,    -1,    -1,     5,
      -1,    -1,  1134,    -1,    10,    -1,    -1,    -1,    -1,    -1,
    1142,  1143,    -1,  1145,  1146,  1147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,  1158,  1159,    -1,  1161,
      -1,    -1,    -1,  1165,  1166,  1167,    -1,  1169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
    1182,    -1,    -1,  1185,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,  1197,    -1,    -1,  1200,  1201,
    1202,    -1,  1204,  1205,   249,   250,   251,   252,    63,    64,
      -1,  1213,   257,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1241,
      -1,  1243,  1244,  1245,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,    -1,    -1,    -1,  1257,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,    -1,    -1,  1277,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,  1287,   162,   163,   164,    -1,
      -1,   167,   168,    -1,    -1,    -1,    -1,    -1,  1300,  1301,
      -1,    -1,    -1,  1305,  1306,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1314,  1315,   190,   191,   192,    -1,    -1,    -1,
     196,   197,   198,    -1,   200,    -1,   202,   203,   204,    -1,
      -1,    -1,    -1,   209,   210,   211,   212,   213,    -1,    -1,
     216,    -1,   218,    -1,   220,    -1,    -1,   223,    -1,   225,
      -1,    -1,   228,    -1,    -1,   231,   232,    -1,   234,   235,
      -1,   237,    -1,   239,   249,   250,   251,   252,    -1,    -1,
      -1,   247,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,   257,    -1,    -1,    -1,    -1,    -1,  1389,    -1,    -1,
      -1,    -1,    -1,    -1,   249,   250,   251,   252,    63,    64,
      -1,    -1,   257,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1482,    -1,    -1,    -1,    -1,  1487,    -1,    63,    64,    -1,
    1492,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,  1523,  1524,  1525,    -1,  1527,    -1,    -1,    -1,    -1,
      -1,    -1,  1534,    -1,   164,    -1,  1538,  1539,    -1,    -1,
      -1,    -1,  1544,    -1,  1546,  1547,    -1,    -1,    -1,  1551,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1559,    -1,    -1,
    1562,  1563,    -1,  1565,    -1,    -1,  1568,    -1,    -1,    -1,
      -1,  1573,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1584,    -1,   249,   250,   251,   252,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,    63,    64,    -1,
    1602,    -1,  1604,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,  1614,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1623,    -1,  1625,    -1,    -1,    -1,    -1,  1630,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1639,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,  1649,    63,    64,
    1652,   257,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,  1681,
    1682,   257,    -1,  1685,    -1,    -1,    -1,    -1,    -1,    -1,
     320,  1693,   249,   250,   251,   252,   326,    -1,   255,    -1,
    1702,  1703,    -1,   333,   334,  1707,    -1,    -1,    -1,    -1,
    1712,    -1,    -1,    -1,  1716,   345,   346,   347,   348,   349,
     350,   351,    -1,    -1,   354,   355,   356,   357,    63,    64,
      -1,  1733,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,  1757,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,  1768,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1780,    -1,
    1782,    -1,  1784,   249,   250,   251,   252,    -1,  1790,   255,
      -1,  1793,    -1,  1795,    -1,    -1,  1798,  1799,    -1,    -1,
    1802,    -1,    -1,    -1,    -1,    -1,    -1,  1809,    -1,  1811,
    1812,  1813,    -1,    -1,  1816,    -1,    -1,    -1,    -1,    -1,
    1822,    -1,    -1,    -1,    -1,   455,   456,   457,    -1,    -1,
      -1,    -1,    -1,  1835,   249,   250,   251,   252,    -1,    -1,
      -1,    -1,   257,  1845,    -1,    -1,   476,    63,    64,    -1,
      -1,  1853,  1854,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1881,
      -1,    -1,  1884,    -1,    -1,    -1,  1888,    -1,  1890,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,  1929,    -1,  1931,
      -1,    -1,  1934,    -1,    -1,    -1,   249,   250,   251,   252,
    1942,    -1,    -1,  1945,   257,    -1,    -1,  1949,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1957,    -1,  1959,    -1,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,  1981,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1999,    -1,  2001,
       3,     4,     5,    -1,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2024,    -1,    -1,    -1,    -1,    30,    31,    -1,
      -1,  2033,    -1,   249,   250,   251,   252,    -1,    -1,    -1,
      -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,   678,    -1,
      -1,    -1,   682,    -1,    -1,    -1,   686,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    68,    69,    -1,    -1,    -1,
      -1,   701,   702,    -1,    -1,    -1,    -1,    -1,    81,   709,
      -1,    84,    -1,    -1,   714,    -1,    89,    -1,    -1,   719,
      -1,   721,    -1,    -1,    97,    -1,    -1,    -1,   101,   102,
      -1,    -1,   105,   733,   107,   735,    -1,   737,    -1,   739,
     740,   741,   115,    -1,    -1,    -1,    -1,   747,    -1,   122,
      -1,    -1,   752,   126,   127,    -1,    -1,    -1,    -1,    -1,
     760,    -1,    -1,   136,    -1,   138,   139,    -1,   768,    -1,
      -1,   144,   145,   146,   147,   148,   149,   249,   250,   251,
     252,    -1,    -1,   156,    -1,   257,   159,    -1,    -1,   162,
     163,   164,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,   222,
     223,   224,   225,    -1,   227,   228,    -1,   230,   231,   232,
      -1,   234,   235,   236,   237,   238,   239,   240,    -1,    -1,
      -1,    -1,    -1,   246,   247,    -1,   249,    -1,    -1,    63,
      64,    -1,    -1,   256,    -1,   258,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1021,    -1,    -1,    30,    31,    -1,    -1,    -1,  1029,
      -1,    -1,    -1,    -1,  1034,    -1,  1036,    -1,  1038,  1039,
      -1,    -1,    -1,  1043,  1044,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    -1,   249,   250,   251,   252,    -1,
      -1,    -1,    -1,   257,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,   249,   250,   251,   252,    -1,    -1,
      -1,    97,   257,    -1,    -1,   101,   102,    -1,    -1,   105,
      -1,   107,   249,   250,   251,   252,    -1,    -1,    -1,   115,
     257,    -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,
     126,   127,    -1,   249,   250,   251,   252,    -1,    -1,    -1,
     136,   257,   138,   139,    -1,  1135,  1136,    -1,   144,   145,
     146,   147,   148,   149,   249,   250,   251,   252,    -1,    -1,
     156,    -1,   257,   159,    -1,    -1,   162,   163,   164,    -1,
    1160,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,   222,   223,   224,   225,
      -1,   227,   228,    -1,   230,   231,   232,    -1,   234,   235,
     236,   237,   238,   239,   240,    -1,    -1,    -1,    -1,    -1,
     246,   247,    -1,   249,    -1,    -1,    -1,    -1,    -1,    -1,
     256,    -1,   258,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,   139,
      -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,
      -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,   222,   223,   224,   225,    -1,   227,   228,    -1,
     230,   231,   232,    -1,   234,   235,   236,   237,   238,   239,
     240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,   249,
      -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,   258,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,  1519,
      -1,    -1,  1522,    -1,    -1,    -1,  1526,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,  1588,    -1,
      84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   136,    -1,   138,   139,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,   222,   223,
     224,   225,    -1,   227,   228,    -1,   230,   231,   232,    -1,
     234,   235,   236,   237,   238,   239,   240,    -1,    -1,    -1,
      -1,    -1,   246,   247,    -1,   249,    -1,    -1,    -1,    -1,
      -1,    -1,   256,   257,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1779,
      -1,    -1,    -1,  1783,    -1,    -1,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,    -1,    -1,    -1,   256,   257,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
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
     164,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,   222,   223,
     224,   225,    -1,   227,   228,    -1,   230,   231,   232,    -1,
     234,   235,   236,   237,   238,   239,   240,    -1,    -1,    -1,
      -1,    -1,   246,   247,    -1,   249,    -1,    -1,    -1,    -1,
      -1,    -1,   256,   257,     3,     4,     5,    -1,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,   249,   250,   251,
     252,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,
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
     149,    -1,   151,   152,   153,   154,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
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
      -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    -1,    -1,    -1,   154,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
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
     149,    -1,   151,    -1,    -1,   154,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
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
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    63,    64,    65,    66,    67,    68,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     139,    -1,    -1,   142,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,   111,    -1,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,
      89,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,   112,    -1,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,    -1,   143,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,
      89,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,
      -1,    -1,    -1,   112,   113,    -1,   115,    -1,    -1,    -1,
      -1,    -1,    -1,   122,    -1,    -1,    -1,   126,   127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   136,    -1,   138,
     139,    -1,    -1,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    34,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,    -1,    -1,    -1,   246,   247,    -1,
     249,    -1,    -1,    -1,     3,     4,     5,   256,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,   222,   223,   224,   225,    -1,   227,   228,
      -1,   230,   231,   232,    -1,   234,   235,   236,   237,   238,
     239,   240,    -1,    -1,     5,    -1,    -1,   246,   247,    10,
     249,    -1,    -1,    -1,    -1,    -1,    -1,   256,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,   249,   250,   251,   252,    -1,    -1,    -1,    -1,
     257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    63,    64,    -1,   105,    -1,   107,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    -1,   126,   127,    -1,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,   145,   146,   147,   148,    -1,    31,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,   159,    -1,
      -1,   162,   163,   164,    -1,    -1,   167,   168,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
     191,   192,    -1,    -1,    -1,   196,   197,   198,    -1,   200,
      -1,   202,   203,   204,    -1,    -1,    -1,    -1,   209,   210,
     211,   212,   213,    -1,    -1,   216,    -1,   218,    -1,   220,
      -1,    -1,   223,   105,   225,   107,    -1,   228,    -1,    -1,
     231,   232,    -1,   234,   235,    -1,   237,    -1,   239,    -1,
      -1,    -1,     5,    -1,   126,   127,   247,    10,    -1,   249,
     250,   251,   252,    -1,    -1,   256,   257,   257,    -1,    -1,
      -1,    -1,   144,   145,   146,   147,   148,    -1,    31,    -1,
     249,   250,   251,   252,   156,    -1,    -1,   159,   257,    -1,
     162,   163,   164,    -1,    -1,   167,   168,   249,   250,   251,
     252,    -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,
     192,    -1,    -1,    -1,   196,   197,   198,    -1,   200,    -1,
     202,   203,   204,    -1,    -1,    -1,    -1,   209,   210,   211,
     212,   213,    -1,    -1,   216,    -1,   218,    -1,   220,    -1,
      -1,   223,   105,   225,   107,    -1,   228,    -1,   111,   231,
     232,    -1,   234,   235,    -1,   237,    -1,   239,    -1,    -1,
      -1,     5,    -1,   126,   127,   247,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   256,   257,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,   147,   148,    -1,    31,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,    -1,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
      -1,    -1,    -1,   196,   197,   198,    -1,   200,    -1,   202,
     203,   204,    -1,    -1,    -1,    -1,   209,   210,   211,   212,
     213,    -1,    -1,   216,    -1,   218,    -1,   220,    -1,    -1,
     223,   105,   225,   107,    -1,   228,    -1,   111,   231,   232,
      -1,   234,   235,    -1,   237,    -1,   239,    -1,    -1,    -1,
       5,    -1,   126,   127,   247,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,   147,   148,    -1,    31,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,
     164,    -1,    -1,   167,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,    -1,
      -1,    -1,   196,   197,   198,    -1,   200,    -1,   202,   203,
     204,    -1,    -1,    -1,    -1,   209,   210,   211,   212,   213,
      -1,    -1,   216,    -1,   218,    -1,   220,    -1,    -1,   223,
     105,   225,   107,    -1,   228,    -1,   111,   231,   232,    -1,
     234,   235,    -1,   237,    -1,   239,    -1,    -1,    -1,     5,
      -1,   126,   127,   247,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,    -1,    31,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,
      -1,    -1,   167,   168,    -1,    -1,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,   190,   191,   192,    -1,    -1,
      -1,   196,   197,   198,    -1,   200,    -1,   202,   203,   204,
      -1,    -1,    -1,    -1,   209,   210,   211,   212,   213,    -1,
      -1,   216,    -1,   218,    -1,   220,    -1,    -1,   223,   105,
     225,   107,    -1,   228,    -1,   111,   231,   232,    -1,   234,
     235,    -1,   237,    -1,   239,    -1,    -1,    -1,     5,    -1,
     126,   127,   247,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,    -1,    31,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
      -1,   167,   168,    -1,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   190,   191,   192,    -1,    -1,    -1,
     196,   197,   198,    -1,   200,    -1,   202,   203,   204,    -1,
      -1,    -1,    -1,   209,   210,   211,   212,   213,    -1,    -1,
     216,    -1,   218,    -1,   220,    -1,    -1,   223,   105,   225,
     107,    -1,   228,    -1,    -1,   231,   232,    -1,   234,   235,
      -1,   237,    -1,   239,   249,   250,   251,   252,    -1,   126,
     127,   247,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,     5,   150,    -1,    -1,    -1,    10,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,   191,   192,    -1,    -1,    -1,   196,
     197,   198,    -1,   200,    -1,   202,   203,   204,    -1,    -1,
      -1,    -1,   209,   210,   211,   212,   213,    -1,    -1,   216,
      -1,   218,    -1,   220,    -1,    -1,   223,    -1,   225,    -1,
      -1,   228,    -1,    -1,   231,   232,    -1,   234,   235,    -1,
     237,    -1,   239,   249,   250,   251,   252,    -1,    -1,    -1,
     247,   257,   105,    -1,   107,    63,    64,    -1,    -1,   256,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,   126,   127,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   144,   145,   146,   147,   148,     5,   150,    -1,    -1,
      -1,    10,    -1,   156,    -1,    -1,   159,    -1,    -1,   162,
     163,   164,    -1,    -1,   167,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   192,
      -1,    -1,    -1,   196,   197,   198,    -1,   200,    -1,   202,
     203,   204,    -1,    -1,    -1,    -1,   209,   210,   211,   212,
     213,    -1,    -1,   216,    -1,   218,    -1,   220,    -1,    -1,
     223,    -1,   225,    -1,    -1,   228,    -1,    -1,   231,   232,
      -1,   234,   235,    -1,   237,    -1,   239,    -1,    97,    -1,
      -1,    -1,    -1,    -1,   247,    -1,   105,    -1,   107,    -1,
      -1,    63,    64,   256,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   126,   127,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   144,   145,   146,   147,   148,
       5,   249,   250,   251,   252,    10,    -1,   156,    -1,   257,
     159,    -1,    -1,   162,   163,   164,    -1,    -1,   167,   168,
      -1,   249,   250,   251,   252,    -1,    31,    -1,    -1,   257,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,   191,   192,    -1,    -1,    -1,   196,   197,   198,
      -1,   200,    -1,   202,   203,   204,    -1,    -1,    -1,    -1,
     209,   210,   211,   212,   213,    -1,    -1,   216,    -1,   218,
      -1,   220,    -1,    -1,   223,    -1,   225,    -1,    -1,   228,
      -1,    -1,   231,   232,    -1,   234,   235,    -1,   237,    -1,
     239,    -1,    97,    -1,    -1,    -1,    -1,    -1,   247,    -1,
     105,    -1,   107,    63,    64,    -1,    -1,   256,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,     5,
      -1,   126,   127,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,   146,   147,   148,    -1,    31,    -1,   249,   250,   251,
     252,   156,    -1,    -1,   159,   257,    -1,   162,   163,   164,
      -1,    -1,   167,   168,    -1,   249,   250,   251,   252,    63,
      64,    -1,    -1,   257,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   190,   191,   192,    -1,    -1,
      -1,   196,   197,   198,    -1,   200,    -1,   202,   203,   204,
      -1,    -1,    -1,    -1,   209,   210,   211,   212,   213,    -1,
      -1,   216,    -1,   218,    -1,   220,    -1,    -1,   223,   105,
     225,   107,    -1,   228,    -1,    -1,   231,   232,    -1,   234,
     235,    -1,   237,    -1,   239,    -1,    -1,    -1,     5,    -1,
     126,   127,   247,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,   147,   148,    -1,    31,    -1,    -1,    -1,    -1,    -1,
     156,    -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,
      -1,   167,   168,    -1,    -1,    -1,    -1,    -1,    -1,   249,
     250,   251,   252,    -1,    -1,    -1,    -1,   257,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   191,   192,    -1,    -1,    -1,
     196,   197,   198,    -1,   200,    -1,   202,   203,   204,    -1,
      -1,    -1,    -1,   209,   210,   211,   212,   213,    -1,    -1,
     216,    -1,   218,    -1,   220,    -1,    -1,   223,   105,   225,
     107,    -1,   228,    -1,    -1,   231,   232,    -1,   234,   235,
      -1,   237,    -1,   239,    -1,   249,   250,   251,   252,   126,
     127,   247,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,
     256,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
     147,   148,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,   159,    -1,    -1,   162,   163,   164,    -1,    -1,
     167,   168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,   191,   192,    -1,    -1,    -1,   196,
     197,   198,    -1,   200,    -1,   202,   203,   204,    -1,    -1,
      -1,    -1,   209,   210,   211,   212,   213,    -1,    -1,   216,
      -1,   218,    -1,   220,    -1,    -1,   223,    -1,   225,    -1,
      -1,   228,    -1,    -1,   231,   232,    -1,   234,   235,    -1,
     237,    -1,   239,    -1,    -1,     4,     5,     6,    -1,    -1,
     247,    -1,    11,    -1,    -1,    -1,    15,    -1,    17,   256,
      19,    20,    21,    22,    23,    24,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    35,    36,    37,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    94,    95,    96,    -1,    98,
      99,   100,    -1,    -1,   103,   104,    -1,   106,    -1,   108,
     109,    -1,    -1,    -1,    -1,   114,   115,    -1,    -1,    -1,
      -1,    -1,   121,    -1,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,    -1,    -1,   144,   145,   146,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,   164,   165,   166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,   191,   192,    63,    64,    -1,    -1,   197,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,
      -1,    -1,   221,    -1,     4,     5,     6,   226,    -1,    -1,
     229,    11,    -1,    -1,   233,    15,    -1,    17,    -1,    19,
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
     249,   250,   251,   252,   164,   165,   166,    -1,   257,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,
      -1,   221,    -1,     4,     5,     6,   226,    -1,    -1,   229,
      11,    -1,    -1,   233,    15,    -1,    17,    -1,    19,    20,
      21,    22,    23,    24,    -1,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    36,    37,    38,    -1,    -1,
      -1,    42,    43,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    53,    54,    55,    56,    57,    63,    64,    -1,
      61,    62,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    -1,    -1,    94,    95,    96,    -1,    98,    99,   100,
      -1,    -1,   103,    -1,    -1,   106,    -1,   108,   109,    -1,
      -1,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,    -1,
     121,    -1,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,    -1,    -1,   144,   145,   146,   147,   148,   149,    -1,
      -1,    -1,    -1,    -1,    -1,   156,   157,   158,   159,   249,
     250,   251,   252,   164,   165,   166,    -1,   257,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,   190,
     191,   192,    63,    64,    -1,    -1,   197,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   217,    -1,    -1,    -1,
     221,    -1,    -1,    -1,    -1,   226,    63,    64,   229,    -1,
      -1,    -1,   233,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   249,   250,   251,   252,    63,    64,    -1,
      -1,   257,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   249,   250,   251,   252,    63,    64,
     255,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   249,   250,   251,   252,    63,    64,   255,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    63,    64,   255,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   249,   250,   251,   252,    63,    64,
     255,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    63,    64,   255,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   249,   250,   251,   252,    63,    64,   255,    -1,
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
      77,    -1,    -1,   249,   250,   251,   252,    63,    64,   255,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   249,   250,   251,   252,    63,    64,
     255,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    63,    64,   255,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   249,   250,   251,   252,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,   251,
     252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,   251,
     252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,   251,
     252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    63,    64,   255,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   249,   250,   251,   252,    63,    64,   255,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   249,   250,   251,   252,    -1,    -1,
     255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
     250,   251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    63,    64,   255,
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
      76,    77,   249,   250,   251,   252,    63,    64,   255,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   249,   250,   251,   252,    63,    64,   255,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   249,
     250,   251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    63,    64,   255,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   249,   250,   251,   252,    63,    64,   255,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   249,
     250,   251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,   249,   250,   251,   252,    63,    64,   255,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   249,   250,   251,   252,    63,    64,   255,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   249,   250,
     251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   249,
     250,   251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,
     255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
     250,   251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,
     255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
     250,   251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,
     255,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,
     250,   251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    63,    64,   255,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,   249,   250,   251,   252,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,   251,
     252,    63,    64,   255,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   249,   250,
     251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   249,
     250,   251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    63,    64,   255,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   249,   250,   251,
     252,    63,    64,   255,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   249,   250,
     251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   249,
     250,   251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   249,   250,   251,
     252,    63,    64,   255,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   249,   250,
     251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   249,
     250,   251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   249,   250,   251,
     252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,   251,
     252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,   251,
     252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,   250,   251,   252,    -1,    -1,   255,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,   251,
     252,    63,    64,   255,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   249,   250,
     251,   252,    63,    64,   255,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   249,
     250,   251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,   250,   251,   252,    63,    64,
     255,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,   251,
     252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,   250,
     251,   252,    -1,    -1,   255,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   249,   250,   251,   252,    -1,    -1,
     255
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   241,   242,   243,   244,   245,   260,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   114,   115,
     121,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     144,   145,   146,   147,   148,   149,   156,   157,   158,   159,
     164,   165,   166,   190,   191,   192,   197,   217,   221,   226,
     229,   233,   261,   262,   265,   266,   273,   274,   276,   277,
     281,   293,   294,   299,   305,   312,   320,   328,   331,   335,
     338,   344,     3,     4,     5,     7,     8,     9,    10,    30,
      31,    63,    64,    65,    66,    67,    68,    69,    81,    84,
      89,   101,   102,   105,   107,   115,   122,   126,   127,   136,
     138,   139,   144,   145,   146,   147,   148,   149,   156,   159,
     162,   163,   164,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   222,   223,   224,
     225,   227,   228,   230,   231,   232,   234,   235,   236,   237,
     238,   239,   240,   246,   247,   249,   256,   279,   280,   282,
     288,   290,   293,   294,   144,   145,   146,   147,   164,   256,
     279,   265,   293,   294,   299,     0,    75,   256,    75,   256,
     313,   332,   336,     4,     7,   291,   291,   291,    34,   282,
     267,   268,   279,   295,   296,   295,   279,    28,     7,   321,
     329,   282,    58,    60,    61,   258,   375,   271,   279,   282,
       4,     5,   292,   282,   279,   282,   279,   282,     4,     5,
     355,   356,    10,   249,   250,   289,   290,   357,   291,    89,
      97,   258,   279,   282,   376,    89,    97,   110,   376,   376,
      81,    82,    88,   111,   282,   287,    12,    53,   287,   111,
     287,    59,    89,    90,    91,    96,    95,   282,   274,   281,
     279,   279,   279,   110,   287,    90,    91,    92,    93,    94,
     104,   110,   111,   116,   117,   118,   119,   120,   165,   287,
     287,   111,   287,   111,   287,    95,   111,   287,    61,    95,
     111,   142,   287,   287,    22,    61,   111,   287,   111,   287,
     111,   287,   111,   279,   279,   279,    61,   111,   111,   142,
     143,   287,   111,   287,   111,   287,   111,   287,   287,   287,
      95,   142,   143,   151,   154,   287,    95,   142,   143,   154,
     287,    95,   142,   143,   151,   152,   153,   154,   287,    61,
      95,   142,   143,   150,   154,   287,   111,   287,   111,   287,
     111,   279,   111,   279,   111,   279,   160,    95,   111,   112,
     143,   282,   279,   256,   256,   256,   256,   256,   279,   376,
     279,   279,   279,    44,   263,    92,    93,   104,    75,    75,
      24,   256,   256,   256,   256,   282,   256,   256,   256,   256,
     256,   256,   112,   113,   256,   256,   256,   256,   112,   256,
     112,   155,   112,   155,   112,   112,   112,   112,   113,   155,
     112,   113,   155,   112,   113,   155,   112,   113,   155,   112,
     112,   162,   161,   256,   112,   155,   279,   287,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   256,   282,   279,
     282,    70,    71,    72,    73,    74,    75,    76,   250,    44,
      63,    64,    70,    71,    72,    73,    74,    75,    76,    77,
     249,   250,   251,   252,   279,    44,    44,    44,   282,   295,
     279,   295,     4,   282,   262,    35,    36,    20,    21,     4,
       5,   306,   307,     4,     5,   308,   309,   279,   282,   297,
     298,   279,   282,   323,   262,   339,   345,   256,    58,   256,
       4,     7,   256,   279,   282,   358,    58,    60,    61,   258,
     360,   373,   256,   256,   255,   255,   255,   256,   256,   255,
     290,   290,   255,   282,   279,   282,    11,   255,   255,   287,
     279,   279,   279,   255,   287,   272,    12,   255,   275,   279,
     255,   287,    12,   287,   275,   275,   275,   287,   287,   287,
     287,   287,   287,   287,   279,   279,   287,   287,   287,   287,
     282,   275,   275,   279,   255,   279,   255,   279,   279,   275,
     279,   279,   279,   279,   275,   255,   279,   279,   279,   275,
     279,   275,   279,   255,   279,   255,   255,   255,   279,   279,
     279,   279,   279,   275,   279,   275,   279,   275,   279,   275,
     275,   275,   279,   279,   279,   279,   279,   275,   279,   279,
     279,   279,   275,   279,   279,   279,   279,   279,   279,   279,
     275,   279,   279,   279,   150,   279,   279,   279,   275,   279,
     255,   279,   255,   279,   255,   279,   255,   279,   255,   279,
     279,   279,   279,   279,   255,   255,     5,   278,   278,   278,
     257,   282,   279,   255,   255,   255,   255,    43,   287,   287,
     287,   282,   279,   300,   295,   295,   282,   282,   282,   282,
     282,   282,    97,   279,   376,   376,   279,     4,     5,   285,
     286,   285,   286,   287,   282,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   150,   279,   279,   279,   279,   256,
     279,   256,   256,   255,   255,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   376,   282,   282,   282,   282,
     282,   282,   282,   282,   257,   282,   279,   279,   279,   279,
     279,   282,   282,   279,   282,   257,   282,   282,   279,   282,
     279,   282,   279,   279,   257,   279,   257,   279,   257,   279,
     257,   279,   279,   279,   279,   282,   279,   279,   279,   279,
     279,   279,   279,   376,   279,   295,   295,   279,   282,   279,
     279,   279,   279,   279,   257,   257,   279,   278,   279,   278,
     279,   279,   279,   257,   257,   279,   279,   279,   279,   279,
     279,   279,   279,   284,   283,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   257,   257,    75,
     333,    14,    16,    18,    41,    44,    49,   337,   269,   270,
     256,   256,   255,   256,   256,   255,   255,    43,   322,    14,
      16,    18,    41,    44,    49,   330,    46,   262,   282,   256,
     279,   282,    51,   359,   254,   255,   256,    58,   256,     4,
       7,   256,    10,   374,   295,   295,     4,     5,   282,   282,
     295,   295,   356,    10,   289,   255,    86,    87,    97,   279,
     282,   275,   255,   282,   360,   287,   255,   279,   287,   275,
     282,   282,   287,   255,   275,   255,   275,   255,   275,   275,
     255,   255,   255,   275,   275,   255,   287,   287,   255,   279,
     255,   279,   255,   287,   255,   255,   255,   287,   279,   255,
     255,   255,   287,   255,   287,   255,   279,   255,   282,   279,
     279,   255,   255,   255,   255,   255,   287,   255,   287,   255,
     287,   255,   287,   287,   287,   255,   255,   255,   287,   255,
     255,   255,   287,   255,   255,   255,   255,   255,   287,   255,
     255,   279,   255,   255,   255,   287,   255,   279,   255,   279,
     255,   279,   255,   279,   255,   279,   255,   255,   255,   282,
     279,   256,   255,   255,   255,   257,   257,   279,   282,   279,
     282,   282,   282,   264,   255,   275,   275,     4,     5,   304,
     257,   257,   255,   255,   257,   255,   255,   255,   257,   255,
     257,   255,   257,   255,   256,   256,   257,   257,   255,   255,
     275,   255,   255,   257,   255,   255,   255,   255,   279,   255,
     255,   279,   257,   279,   279,   279,   279,   257,   257,   257,
     257,   257,   255,   257,   257,   255,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   255,   257,   257,
     255,   255,   255,   257,   255,   255,   257,   255,   257,   257,
     257,   257,   257,   255,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   255,   255,   255,   255,   257,
     257,   257,   257,   257,   255,   257,   257,   257,   257,   257,
     257,   255,   257,   255,   255,   255,   255,   255,   257,   255,
     255,   257,   255,   257,   257,   282,   282,   314,   262,   282,
     291,   377,   291,   378,   295,   295,   307,   295,   295,   309,
     298,    43,   324,   340,    49,    50,   346,   255,   282,   255,
     257,   257,   256,   279,   279,   282,   282,   256,   279,   361,
     362,   282,     4,     5,   352,   354,   257,   257,   256,   256,
     255,   255,   257,   257,   282,    85,    85,   255,   255,   287,
     279,   279,   255,   287,   255,   255,   255,   279,   287,   282,
     287,   279,   287,   287,   279,   282,   282,   282,   287,   287,
     282,   255,   255,   282,   255,   282,   255,   279,   282,   255,
     279,   279,   279,   255,   255,   279,   279,   279,   282,   255,
     279,   255,   282,   255,   279,   255,   279,   279,   282,   279,
     282,   255,   279,   255,   279,   255,   282,   255,   255,   255,
     279,   282,   279,   282,   282,   255,   279,   282,   282,   255,
     279,   279,   282,   279,   279,   282,   255,   279,   282,   255,
     282,   279,   282,   255,   279,   255,   282,   255,   279,   282,
     255,   279,   255,   279,   255,   279,   279,   279,   255,   255,
     295,   282,   282,   282,   255,   255,   266,   282,   287,   287,
     301,   282,   282,   282,   282,   282,   279,    97,   279,   279,
     257,   257,   282,   282,   287,   282,   279,   279,   282,   282,
     282,   282,   279,   257,   255,   255,   255,   255,   282,   282,
     282,   282,   282,   282,   282,   282,   279,   282,   279,   279,
     279,   279,   279,   282,   282,   282,   282,   286,   279,   286,
     279,   279,   282,    16,    44,   334,   255,   255,   257,   257,
     257,   257,    39,    40,   326,   262,   282,   255,   279,    58,
     279,   359,   255,   282,   255,   257,   352,   352,   257,   256,
     256,   255,   295,   295,   282,   282,   255,   376,   376,   279,
     279,   255,   255,   279,   282,   282,   279,   255,   255,   275,
     255,   255,   275,   255,   255,   255,   275,   255,   255,   279,
     279,   279,   279,   279,   255,   279,   279,   255,   255,   255,
     279,   255,   279,   279,   255,   279,   255,   255,   279,   255,
     279,   255,   279,   279,   279,   279,   255,   279,   279,   255,
     255,   279,   255,   255,   282,   255,   279,   279,   255,   279,
     255,   255,   279,   255,   279,   255,   279,   255,   255,   279,
     279,   257,   257,   257,   255,   257,   279,   279,   275,   256,
     257,   257,   257,   257,   257,   257,   257,   255,   257,   257,
     257,   257,   275,   255,   255,   279,   279,   279,   279,   257,
     257,   257,   257,   257,   255,   257,   257,   257,   255,   257,
     257,   257,   255,   255,   257,   255,   257,   257,   257,   255,
     255,   257,   255,   257,   257,   255,   257,   257,   257,    12,
     291,   291,   323,    43,    38,   341,   257,   282,   257,   256,
     255,   282,   255,   279,    58,   368,   363,   295,   295,   353,
     257,   257,   279,   279,   279,   255,   255,   255,   279,   279,
     287,   279,   279,   287,   282,   282,   282,   287,   282,   279,
     255,   255,   255,   255,   282,   255,   255,   279,   282,   282,
     255,   279,   255,   255,   282,   282,   279,   282,   255,   279,
     255,   282,   255,   255,   255,   255,   279,   255,   255,   279,
     282,   279,   255,   282,   282,   282,   255,   255,   282,   279,
     279,   255,   279,   282,   255,   279,   255,   279,   279,    75,
      75,   282,    75,   255,   287,     4,     5,   310,   311,   279,
     282,   279,   282,   257,   257,   282,   279,   279,   282,   282,
     279,   282,   279,   279,   282,   325,   327,    48,   348,    60,
      61,   257,    58,   282,   279,   257,   282,   257,   256,   374,
     352,   257,   257,   352,   255,   279,   279,   279,   255,   275,
     255,   255,   255,   275,   255,   255,   279,   282,   282,   279,
     255,   282,   279,   255,   279,   255,   279,   282,   255,   255,
     279,   279,   255,   282,   282,   279,   279,   282,   279,   255,
     282,   255,   255,   255,   282,   279,   255,   255,   279,   255,
     255,   279,   255,   279,   255,   279,   279,   257,   279,   282,
     256,   256,   255,   257,   257,   255,   257,   257,   257,   257,
     257,   257,   257,   257,   257,    13,   318,   262,   262,   282,
      47,   347,   256,   256,   255,   257,    60,    61,   364,   257,
      58,   369,   282,   352,   279,   279,   287,   282,   279,   282,
     287,   282,   279,   255,   255,   255,   255,   282,   255,   255,
     282,   255,   282,   255,   255,   282,   282,   255,   255,   282,
     255,   255,   255,   255,   282,   255,   282,   282,   282,   255,
     255,   282,   279,   279,   279,   255,   279,   282,   255,   279,
      75,   257,   257,   311,   302,   282,   282,   315,    46,   351,
     262,   342,   279,   282,   282,   370,   256,   374,   365,   256,
     374,   255,   255,   255,   255,   255,   255,   255,   279,   279,
     279,   279,   255,   279,   279,   255,   282,   279,   282,   255,
     279,   282,   282,   279,   279,   279,   279,   255,   255,   255,
     279,   279,   255,   279,   255,   255,   279,   279,   262,   257,
     262,   349,    14,    16,    18,    41,    44,    49,   343,   255,
     257,   255,   257,   374,   279,   352,   374,   282,   352,   282,
     279,   279,   282,   279,   279,   279,   255,   282,   282,   255,
     255,   255,   282,   255,   255,   282,   279,   282,   255,   279,
     279,   279,   255,    25,    44,   303,   316,   262,   279,   282,
     352,   255,   257,   352,   255,   257,   255,   279,   282,   279,
     282,   279,   279,   255,   279,   255,   279,    14,    16,    18,
      41,    44,    49,   317,   350,   257,   257,   279,   371,   282,
     366,   279,   255,   255,   282,   279,     4,   319,   348,   257,
     374,   257,   374,   279,   279,   255,   372,   352,   367,   352,
     255,   279,   374,   374,   279,   352,   352
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   259,   260,   260,   260,   260,   260,   261,   262,   263,
     264,   262,   265,   265,   265,   265,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   267,   266,   268,   266,   266,   266,   266,   266,   266,
     266,   269,   266,   270,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   271,   266,   272,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   273,   273,
     273,   273,   273,   274,   274,   274,   274,   274,   274,   275,
     275,   276,   276,   276,   276,   276,   277,   277,   278,   278,
     279,   279,   279,   279,   279,   279,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   281,   281,   283,   282,   284,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   285,   286,   287,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   289,   289,   289,   290,
     290,   290,   290,   291,   291,   292,   292,   292,   292,   293,
     294,   296,   295,   297,   297,   297,   298,   298,   300,   301,
     302,   299,   303,   303,   304,   304,   305,   305,   305,   305,
     306,   306,   307,   307,   307,   307,   308,   308,   309,   309,
     309,   309,   310,   310,   310,   311,   311,   311,   311,   313,
     314,   315,   316,   312,   317,   317,   317,   317,   317,   317,
     318,   318,   319,   319,   321,   320,   322,   322,   323,   323,
     324,   325,   324,   326,   327,   326,   329,   328,   330,   330,
     330,   330,   330,   330,   332,   333,   331,   334,   334,   336,
     335,   337,   337,   337,   337,   337,   337,   339,   340,   341,
     342,   338,   343,   343,   343,   343,   343,   343,   345,   344,
     346,   346,   347,   347,   348,   349,   350,   348,   351,   351,
     352,   353,   352,   354,   354,   354,   354,   355,   355,   356,
     356,   356,   356,   357,   357,   357,   357,   358,   358,   358,
     358,   358,   359,   359,   359,   361,   360,   362,   360,   363,
     360,   364,   360,   365,   360,   366,   360,   367,   360,   368,
     360,   369,   360,   370,   360,   371,   360,   372,   360,   373,
     360,   374,   374,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   376,   376,   377,
     377,   378,   378
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
       9,    11,     3,     6,     4,     6,    10,    10,     5,    10,
       5,     8,     5,    10,    12,     5,     5,     3,    10,     5,
       5,     3,    11,    14,    16,     7,     7,    11,     5,     6,
       7,     9,    12,     9,    14,     5,     7,     7,    11,     4,
      10,     5,     5,     5,    12,     7,    12,     7,     9,    10,
       5,     8,     8,    10,     5,     7,     5,     5,     5,     3,
       3,    10,     5,     5,     5,     3,    10,     5,     9,     7,
       5,     5,     7,     5,     3,     5,     5,     3,    12,    15,
      11,     5,     6,     5,     3,    11,    10,     5,     6,     9,
       8,     7,     9,    10,     9,    11,    12,    13,    11,     3,
       9,     5,     6,     7,     3,    11,     2,     3,     2,     2,
       1,     1,     3,     4,     4,     4,     4,     4,     4,     1,
       1,     2,     1,     2,     2,     8,     6,     6,     0,     1,
       1,     2,     2,     3,    10,     8,     8,     8,     3,     1,
       1,     6,     4,     4,     6,     6,     4,     6,     1,     4,
       1,     1,     1,     1,     3,     3,     6,     6,     8,     6,
       4,     6,     8,     4,     1,     3,     4,     4,     4,     4,
       4,     4,     4,     6,     8,     4,     4,     4,     4,     4,
       6,     1,     3,     1,     3,     4,     3,     3,     6,     6,
       3,     3,     5,     5,     5,     7,     3,     4,     5,     2,
       1,     7,     6,     6,     4,     6,     4,     6,    10,     4,
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
       4,     4,     6,     6,     6,     8,     4,     2,     5,     7,
       3,     3,     3,     3,     3,     3,     3,     4,     3,     5,
       5,     3,     3,     5,     7,     4,     1,     2,     2,     1,
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

  case 115: /* statement: tALERT string_expression ',' string_expression ',' string_expression  */
                                                                         {add_command(cYABALERT);}
    break;

  case 116: /* statement: tBUTTON coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                         {add_command(cYABBUTTON);}
    break;

  case 117: /* statement: tCHECKBOX coordinates ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                           {add_command(cYABCHECKBOX);}
    break;

  case 118: /* statement: tCHECKBOX tSET string_expression ',' expression  */
                                                    {add_command(cYABCHECKBOXSET);}
    break;

  case 119: /* statement: tRADIOBUTTON coordinates ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                              {add_command(cYABRADIOBUTTON);}
    break;

  case 120: /* statement: tRADIOBUTTON tSET string_expression ',' expression  */
                                                       {add_command(cYABRADIOSET);}
    break;

  case 121: /* statement: tTEXT coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                        {add_command(cYABTEXT);}
    break;

  case 122: /* statement: tTEXT tSET string_expression ',' string_expression  */
                                                       {add_command(cYABTEXTALIGN);}
    break;

  case 123: /* statement: tTEXTURL coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                 {add_command(cYABTEXTURL);}
    break;

  case 124: /* statement: tTEXTCONTROL coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                    {add_command(cYABTEXTCONTROL);}
    break;

  case 125: /* statement: tTEXTCONTROL tSET string_expression ',' string_expression  */
                                                              {add_command(cYABTEXTCONTROLSET);}
    break;

  case 126: /* statement: tTEXTCONTROL tSET string_expression ',' expression  */
                                                       {add_command(cYABTEXTCONTROLMASK);}
    break;

  case 127: /* statement: tTEXTCONTROL tCLEAR string_expression  */
                                          {add_command(cYABTEXTCONTROLCLEAR);}
    break;

  case 128: /* statement: tTEXTEDIT coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                    {add_command(cYABTEXTEDIT);}
    break;

  case 129: /* statement: tTEXTEDIT tADD string_expression ',' string_expression  */
                                                           {add_command(cYABTEXTEDITADD);}
    break;

  case 130: /* statement: tTEXTEDIT tSET string_expression ',' string_expression  */
                                                           {add_command(cYABTEXTEDITSET);}
    break;

  case 131: /* statement: tTEXTEDIT tCLEAR string_expression  */
                                       {add_command(cYABTEXTEDITCLEAR);}
    break;

  case 132: /* statement: tTEXTEDIT tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                           {add_command(cYABTEXTEDITCOLOUR);}
    break;

  case 133: /* statement: tSLIDER coordinates to coordinates ',' string_expression ',' string_expression ',' expression ',' expression ',' string_expression  */
                                                                                                                                       {add_command(cYABSLIDER);}
    break;

  case 134: /* statement: tSLIDER coordinates to coordinates ',' string_expression ',' string_expression ',' expression ',' expression ',' string_expression ',' string_expression  */
                                                                                                                                                             {add_command(cYABSLIDEROPT);}
    break;

  case 135: /* statement: tSLIDER tLABEL string_expression ',' string_expression ',' string_expression  */
                                                                                 {add_command(cYABSLIDERLABEL);}
    break;

  case 136: /* statement: tSLIDER tSET string_expression ',' string_expression ',' expression  */
                                                                        {add_command(cYABSLIDERMARKS);}
    break;

  case 137: /* statement: tSLIDER tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                         {add_command(cYABSLIDERCOLOUR);}
    break;

  case 138: /* statement: tSLIDER tSET string_expression ',' expression  */
                                                  {add_command(cYABSLIDERSET);}
    break;

  case 139: /* statement: tSCROLLBAR string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cYABSCROLLBAR);}
    break;

  case 140: /* statement: tSCROLLBAR tSET string_expression ',' string_expression ',' expression  */
                                                                           {add_command(cYABSCROLLBARSET);}
    break;

  case 141: /* statement: tSCROLLBAR tSET string_expression ',' string_expression ',' expression ',' expression  */
                                                                                          {add_command(cYABSCROLLBARRANGE);}
    break;

  case 142: /* statement: tSTATUSBAR coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                  {add_command(cYABSTATUSBAR);}
    break;

  case 143: /* statement: tSTATUSBAR tSET string_expression ',' string_expression ',' string_expression ',' expression  */
                                                                                                 {add_command(cYABSTATUSBARSET);}
    break;

  case 144: /* statement: tSPINCONTROL coordinates ',' string_expression ',' string_expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                                                            {add_command(cYABSPINCONTROL);}
    break;

  case 145: /* statement: tSPINCONTROL tSET string_expression ',' expression  */
                                                       {add_command(cYABSPINCONTROLSET);}
    break;

  case 146: /* statement: tOPTION tSET string_expression ',' string_expression ',' string_expression  */
                                                                               {add_command(cYABOPTIONTEXT);}
    break;

  case 147: /* statement: tOPTION tSET string_expression ',' string_expression ',' expression  */
                                                                        {add_command(cYABOPTIONNUMBER);}
    break;

  case 148: /* statement: tOPTION tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                         {add_command(cYABOPTIONCOLOUR);}
    break;

  case 149: /* statement: tTOOLTIP string_expression ',' string_expression  */
                                                     {add_command(cYABTOOLTIP);}
    break;

  case 150: /* statement: tTABVIEW coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                          {add_command(cYABTABVIEW);}
    break;

  case 151: /* statement: tTABVIEW tADD string_expression ',' string_expression  */
                                                          {add_command(cYABTABADD);}
    break;

  case 152: /* statement: tTABVIEW tSET string_expression ',' expression  */
                                                   {add_command(cYABTABSET);}
    break;

  case 153: /* statement: tTABVIEW tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABTABREMOVE);}
    break;

  case 154: /* statement: tBOXVIEW coordinates to coordinates ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                                         {add_command(cYABBOXVIEW);}
    break;

  case 155: /* statement: tBOXVIEW tSET string_expression ',' string_expression ',' string_expression  */
                                                                                {add_command(cYABBOXVIEWSET);}
    break;

  case 156: /* statement: tSPLITVIEW coordinates to coordinates ',' string_expression ',' expression ',' expression ',' string_expression  */
                                                                                                                    {add_command(cYABSPLITVIEW);}
    break;

  case 157: /* statement: tSPLITVIEW tSET string_expression ',' string_expression ',' expression  */
                                                                           {add_command(cYABSPLITVIEWSET);}
    break;

  case 158: /* statement: tSPLITVIEW tSET string_expression ',' string_expression ',' expression ',' expression  */
                                                                                          {add_command(cYABSPLITVIEWMIN);}
    break;

  case 159: /* statement: tSTACKVIEW coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                     {add_command(cYABSTACKVIEW);}
    break;

  case 160: /* statement: tSTACKVIEW tSET string_expression ',' expression  */
                                                     {add_command(cYABSTACKVIEWSET);}
    break;

  case 161: /* statement: tCANVAS coordinates to coordinates ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABCANVAS);}
    break;

  case 162: /* statement: tREGION coordinates to coordinates ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABREGION);}
    break;

  case 163: /* statement: tLISTBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                   {add_command(cYABLISTBOX);}
    break;

  case 164: /* statement: tLISTBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABLISTBOXADD);}
    break;

  case 165: /* statement: tLISTBOX tADD string_expression ',' expression ',' string_expression  */
                                                                         {add_command(cYABLISTBOXADD2);}
    break;

  case 166: /* statement: tLISTBOX tREMOVE string_expression ',' string_expression  */
                                                             {add_command(cYABLISTBOXREMOVE);}
    break;

  case 167: /* statement: tLISTBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABLISTBOXREMOVE2);}
    break;

  case 168: /* statement: tLISTBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABLISTBOXSELECT);}
    break;

  case 169: /* statement: tLISTBOX tCLEAR string_expression  */
                                      {add_command(cYABLISTBOXCLEAR);}
    break;

  case 170: /* statement: tLISTBOX tSORT string_expression  */
                                     {add_command(cYABLISTSORT);}
    break;

  case 171: /* statement: tDROPBOX coordinates to coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                          {add_command(cYABDROPBOX);}
    break;

  case 172: /* statement: tDROPBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABDROPBOXADD);}
    break;

  case 173: /* statement: tDROPBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABDROPBOXSELECT);}
    break;

  case 174: /* statement: tDROPBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABDROPBOXREMOVE);}
    break;

  case 175: /* statement: tDROPBOX tCLEAR string_expression  */
                                      {add_command(cYABDROPBOXCLEAR);}
    break;

  case 176: /* statement: tTREEBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression  */
                                                                                                   {add_command(cYABTREEBOX);}
    break;

  case 177: /* statement: tTREEBOX tADD string_expression ',' string_expression  */
                                                          {add_command(cYABTREEADD);}
    break;

  case 178: /* statement: tTREEBOX tADD string_expression ',' string_expression ',' string_expression ',' expression  */
                                                                                               {add_command(cYABTREEADDCHILD);}
    break;

  case 179: /* statement: tTREEBOX tADD string_expression ',' string_expression ',' expression  */
                                                                         {add_command(cYABTREEADDAT);}
    break;

  case 180: /* statement: tTREEBOX tREMOVE string_expression ',' string_expression  */
                                                             {add_command(cYABTREEREMOVE);}
    break;

  case 181: /* statement: tTREEBOX tREMOVE string_expression ',' expression  */
                                                      {add_command(cYABTREEREMOVE2);}
    break;

  case 182: /* statement: tTREEBOX tREMOVE string_expression ',' string_expression ',' string_expression  */
                                                                                   {add_command(cYABTREEREMOVECHILD);}
    break;

  case 183: /* statement: tTREEBOX tSELECT string_expression ',' expression  */
                                                      {add_command(cYABTREESELECT);}
    break;

  case 184: /* statement: tTREEBOX tCLEAR string_expression  */
                                      {add_command(cYABTREECLEAR);}
    break;

  case 185: /* statement: tTREEBOX tEXPAND string_expression ',' string_expression  */
                                                             {add_command(cYABTREEEXPAND);}
    break;

  case 186: /* statement: tTREEBOX tCOLLAPSE string_expression ',' string_expression  */
                                                               {add_command(cYABTREECOLLAPSE);}
    break;

  case 187: /* statement: tTREEBOX tSORT string_expression  */
                                     {add_command(cYABTREESORT);}
    break;

  case 188: /* statement: tCOLUMNBOX coordinates to coordinates ',' string_expression ',' expression ',' string_expression ',' string_expression  */
                                                                                                                           {add_command(cYABCOLUMNBOX);}
    break;

  case 189: /* statement: tCOLUMNBOX tCOLUMN string_expression ',' string_expression ',' expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                                                                 {add_command(cYABCOLUMNBOXCOLUMN);}
    break;

  case 190: /* statement: tCOLUMNBOX tADD string_expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                         {add_command(cYABCOLUMNBOXADD);}
    break;

  case 191: /* statement: tCOLUMNBOX tREMOVE string_expression ',' expression  */
                                                        {add_command(cYABCOLUMNBOXREMOVE);}
    break;

  case 192: /* statement: tCOLUMNBOX tREMOVE tCOLUMN string_expression ',' expression  */
                                                                {add_command(cYABCOLUMNBOXREMOVECOLUMN);}
    break;

  case 193: /* statement: tCOLUMNBOX tSELECT string_expression ',' expression  */
                                                        {add_command(cYABCOLUMNBOXSELECT);}
    break;

  case 194: /* statement: tCOLUMNBOX tCLEAR string_expression  */
                                        {add_command(cYABCOLUMNBOXCLEAR);}
    break;

  case 195: /* statement: tCOLUMNBOX tCOLOUR string_expression ',' string_expression ',' expression ',' expression ',' expression  */
                                                                                                            {add_command(cYABCOLUMNBOXCOLOUR);}
    break;

  case 196: /* statement: tCALENDAR coordinates ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                  {add_command(cYABCALENDAR);}
    break;

  case 197: /* statement: tCALENDAR tSET string_expression ',' string_expression  */
                                                           {add_command(cYABCALENDARSET);}
    break;

  case 198: /* statement: tCOLORCONTROL coordinates ',' string_expression ',' string_expression  */
                                                                          {add_command(cYABCOLORCONTROL);}
    break;

  case 199: /* statement: tCOLORCONTROL tSET string_expression ',' expression ',' expression ',' expression  */
                                                                                      {add_command(cYABCOLORCONTROLSET);}
    break;

  case 200: /* statement: tMENU string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                              {add_command(cYABMENU);}
    break;

  case 201: /* statement: tMENU tSET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cYABMENURADIO);}
    break;

  case 202: /* statement: tMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                   {add_command(cYABMENUOPTION);}
    break;

  case 203: /* statement: tSUBMENU string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                       {add_command(cYABSUBMENU);}
    break;

  case 204: /* statement: tSUBMENU tSET string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                               {add_command(cYABSUBMENURADIO);}
    break;

  case 205: /* statement: tSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                            {add_command(cYABSUBMENUOPTION);}
    break;

  case 206: /* statement: tSUBSUBMENU string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                                {add_command(cYABSUBSUBMENU);}
    break;

  case 207: /* statement: tSUBSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                                                                     {add_command(cYABSUBSUBMENUOPTION);}
    break;

  case 208: /* statement: tSUBSUBMENU tSET string_expression ',' string_expression ',' string_expression ',' expression ',' string_expression  */
                                                                                                                        {add_command(cYABSUBSUBMENURADIO);}
    break;

  case 209: /* statement: tCLIPBOARD tCOPY string_expression  */
                                       {add_command(cYABCLIPBOARDCOPY);}
    break;

  case 210: /* statement: tATTRIBUTE tSET string_expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                        {add_command(cYABATTRIBUTESET);}
    break;

  case 211: /* statement: tATTRIBUTE tCLEAR string_expression ',' string_expression  */
                                                              {add_command(cYABATTRIBUTECLEAR);}
    break;

  case 212: /* statement: tBITMAP expression ',' expression ',' string_expression  */
                                                            {add_command(cYABBITMAP);}
    break;

  case 213: /* statement: tBITMAP tGET string_expression ',' string_expression ',' string_expression  */
                                                                               {add_command(cYABBITMAPGET);}
    break;

  case 214: /* statement: tBITMAP tREMOVE string_expression  */
                                      {add_command(cYABBITMAPREMOVE);}
    break;

  case 215: /* statement: tDRAW tBITMAP expression ',' expression ',' string_expression ',' string_expression ',' string_expression  */
                                                                                                              {add_command(cYABBITMAPDRAW);}
    break;

  case 216: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 217: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 218: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 219: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 220: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 221: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 222: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 223: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 224: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 225: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 226: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 227: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 228: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 229: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 230: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 231: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 232: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 233: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 234: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 235: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 236: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 237: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 238: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 239: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 240: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 241: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 242: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 243: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 244: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 245: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 246: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 247: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 248: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 251: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 252: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 253: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 254: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 255: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 256: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 257: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 258: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 259: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 260: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 262: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 263: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 264: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 266: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 267: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 268: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 269: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 270: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 271: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 272: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 273: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 274: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 275: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 276: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 277: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 278: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 279: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 280: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 281: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 282: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 283: /* string_function: tSTRING2 '(' expression ',' string_expression ')'  */
                                                      {create_function(fSTRING);}
    break;

  case 284: /* string_function: tREPLACE '(' string_expression ',' string_expression ',' string_expression ')'  */
                                                                                    {create_function(fREPLACE);}
    break;

  case 285: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 286: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 287: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 288: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 289: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 290: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 291: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 292: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 293: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 294: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 295: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 296: /* string_function: tTEXTCONTROL tGET string_expression  */
                                        {create_function(fYABTEXTCONTROLGET);}
    break;

  case 297: /* string_function: tTEXTEDIT tGET string_expression  */
                                     {create_function(fYABTEXTEDITGET);}
    break;

  case 298: /* string_function: tPOPUPMENU coordinates ',' string_expression ',' string_expression  */
                                                                                       {create_function(fYABPOPUPMENU);}
    break;

  case 299: /* string_function: tFILEPANEL string_expression ',' string_expression ',' string_expression  */
                                                                                             {create_function(fYABFILEPANELLOAD);}
    break;

  case 300: /* string_function: tTEXTCONTROL tGETS string_expression  */
                                                         {create_function(fYABTEXTCONTROLGET);}
    break;

  case 301: /* string_function: tTEXTEDIT tGETS string_expression  */
                                                      {create_function(fYABTEXTEDITGET);}
    break;

  case 302: /* string_function: tLISTBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABLISTBOXGET);}
    break;

  case 303: /* string_function: tDROPBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABDROPBOXGET);}
    break;

  case 304: /* string_function: tTREEBOX tGETS string_expression ',' expression  */
                                                                    {create_function(fYABTREEBOXGET);}
    break;

  case 305: /* string_function: tCOLUMNBOX tGETS string_expression ',' expression ',' expression  */
                                                                                     {create_function(fYABCOLUMNBOXGET);}
    break;

  case 306: /* string_function: tCALENDAR tGET string_expression  */
                                                     {create_function(fYABCALENDARGET);}
    break;

  case 307: /* string_function: tTRANSLATE '(' string_expression ')'  */
                                         {create_function(fYABTRANSLATE);}
    break;

  case 308: /* string_function: tMENU tTRANSLATE '(' string_expression ')'  */
                                               {create_function(fYABMENUTRANSLATE);}
    break;

  case 309: /* string_function: tCLIPBOARD tPASTE  */
                      {create_function(fYABCLIPBOARDPASTE);}
    break;

  case 310: /* string_function: tMESSAGE  */
             {create_function(fYABMESSAGE);}
    break;

  case 311: /* string_function: tATTRIBUTE tGETS '(' string_expression ',' string_expression ')'  */
                                                                     {create_function(fYABATTRIBUTEGET);}
    break;

  case 312: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 313: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 314: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 315: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 316: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 317: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 318: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 319: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 320: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 321: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 322: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 323: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 324: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 325: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 326: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 327: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 328: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 329: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 330: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 331: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 332: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 333: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 334: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 335: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 336: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 337: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 338: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 339: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 340: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 341: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 342: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 343: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 344: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 345: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 346: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 347: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 348: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 349: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 350: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 351: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 352: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 353: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 354: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 355: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 356: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 357: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 358: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 359: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 360: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 363: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 364: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 366: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 367: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 368: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 369: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 370: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 371: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 372: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 373: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 374: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 375: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 376: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 377: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 378: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 379: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 380: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 381: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 382: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 383: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 384: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 385: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 386: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 387: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 388: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 389: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 390: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 391: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 392: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 393: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 394: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 395: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 396: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 397: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 398: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 399: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 400: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 401: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 402: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 403: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 404: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 405: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 406: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 407: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 408: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 409: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 410: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 411: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 412: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 413: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 414: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 415: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 416: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 417: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 418: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 419: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 420: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 421: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 422: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 423: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 424: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 425: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 426: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 427: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 428: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 429: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 430: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 431: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 432: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 433: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 434: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 435: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 436: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 437: /* function: tWINDOW tCOUNT  */
                   {create_function(fYABNUMWINDOWS);}
    break;

  case 438: /* function: tWINDOW tGET string_expression ',' string_expression  */
                                                         {create_function(fYABWINDOWGET);}
    break;

  case 439: /* function: tATTRIBUTE tGET '(' string_expression ',' string_expression ')'  */
                                                                    {create_function(fYABATTRIBUTEGETNUM);}
    break;

  case 440: /* function: tLISTBOX tCOUNT string_expression  */
                                                      {create_function(fYABLISTBOXCOUNT);}
    break;

  case 441: /* function: tLISTBOX tGET string_expression  */
                                                    {create_function(fYABLISTBOXSELECTED);}
    break;

  case 442: /* function: tDROPBOX tCOUNT string_expression  */
                                                      {create_function(fYABDROPBOXCOUNT);}
    break;

  case 443: /* function: tDROPBOX tGET string_expression  */
                                                    {create_function(fYABDROPBOXSELECTED);}
    break;

  case 444: /* function: tTREEBOX tCOUNT string_expression  */
                                                      {create_function(fYABTREEBOXCOUNT);}
    break;

  case 445: /* function: tTREEBOX tGET string_expression  */
                                                    {create_function(fYABTREEBOXSELECTED);}
    break;

  case 446: /* function: tCOLUMNBOX tCOUNT string_expression  */
                                                        {create_function(fYABCOLUMNBOXCOUNT);}
    break;

  case 447: /* function: tCOLUMNBOX tCOUNT tCOLUMN string_expression  */
                                                                {create_function(fYABCOLUMNBOXCOUNTCOLUMNS);}
    break;

  case 448: /* function: tCOLUMNBOX tGET string_expression  */
                                                      {create_function(fYABCOLUMNBOXSELECTED);}
    break;

  case 449: /* function: tCOLORCONTROL tGET string_expression ',' string_expression  */
                                                                               {create_function(fYABCOLORCONTROLGET);}
    break;

  case 450: /* function: tSPLITVIEW tGET string_expression ',' string_expression  */
                                                                            {create_function(fYABSPLITVIEWGET);}
    break;

  case 451: /* function: tSTACKVIEW tGET string_expression  */
                                                      {create_function(fYABSTACKVIEWGET);}
    break;

  case 452: /* function: tTABVIEW tGET string_expression  */
                                                    {create_function(fYABTABVIEWGET);}
    break;

  case 453: /* function: tDRAW tGET string_expression ',' string_expression  */
                                                       {create_function(fYABDRAWGET);}
    break;

  case 454: /* function: tDRAW tGET string_expression ',' string_expression ',' string_expression  */
                                                                             {create_function(fYABDRAWGETTEXT);}
    break;

  case 455: /* function: tBFILESIZE '(' string_expression ')'  */
                                         {create_function(fYABBFILESIZE);}
    break;

  case 456: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 457: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 458: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 459: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 460: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 461: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 462: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 463: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 464: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 465: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 466: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 467: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 468: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 469: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 470: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 471: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 478: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 479: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 480: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 481: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 482: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 483: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 484: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 485: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 486: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 487: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 488: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 489: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 492: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 493: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 494: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 495: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 498: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 499: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 500: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 501: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 505: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 506: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 507: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 508: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 509: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 510: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 511: /* $@17: %empty  */
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

  case 512: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 513: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 514: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 515: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 516: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 517: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 518: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 519: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 520: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 522: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 523: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 524: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 525: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 531: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 532: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 534: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 536: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 538: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 539: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 540: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 541: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 542: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 543: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 544: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 545: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 547: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 548: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 549: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 551: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 552: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 553: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 554: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 555: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 556: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 557: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 558: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 559: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 560: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 562: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 563: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 564: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 565: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 566: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 567: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 568: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 570: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 571: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 575: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 576: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 581: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 583: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 584: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 585: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 586: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 589: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 590: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 591: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 592: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 593: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 594: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 595: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 596: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 600: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 601: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 602: /* using: %empty  */
       {create_print('d');}
    break;

  case 603: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 604: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 605: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 606: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 607: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 608: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 609: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 610: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 611: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 612: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 613: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 614: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 615: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 616: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 617: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 618: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 619: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 620: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 621: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 622: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 623: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 624: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 625: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 626: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 627: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 628: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 629: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 630: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 631: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 632: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 633: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 634: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 635: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 636: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 637: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 638: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 639: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 640: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 641: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 642: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 643: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 644: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 645: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 646: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 649: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 650: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 651: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 652: /* gosub_list: gosub_list ',' symbol_or_lineno  */
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

