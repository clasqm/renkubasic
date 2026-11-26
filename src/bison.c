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
  YYSYMBOL_tSIN = 123,                     /* tSIN  */
  YYSYMBOL_tASIN = 124,                    /* tASIN  */
  YYSYMBOL_tCOS = 125,                     /* tCOS  */
  YYSYMBOL_tACOS = 126,                    /* tACOS  */
  YYSYMBOL_tTAN = 127,                     /* tTAN  */
  YYSYMBOL_tATAN = 128,                    /* tATAN  */
  YYSYMBOL_tEXP = 129,                     /* tEXP  */
  YYSYMBOL_tLOG = 130,                     /* tLOG  */
  YYSYMBOL_tSQRT = 131,                    /* tSQRT  */
  YYSYMBOL_tSQR = 132,                     /* tSQR  */
  YYSYMBOL_tMYEOF = 133,                   /* tMYEOF  */
  YYSYMBOL_tABS = 134,                     /* tABS  */
  YYSYMBOL_tSIG = 135,                     /* tSIG  */
  YYSYMBOL_tINT = 136,                     /* tINT  */
  YYSYMBOL_tCEIL = 137,                    /* tCEIL  */
  YYSYMBOL_tFLOOR = 138,                   /* tFLOOR  */
  YYSYMBOL_tFRAC = 139,                    /* tFRAC  */
  YYSYMBOL_tROUND = 140,                   /* tROUND  */
  YYSYMBOL_tMOD = 141,                     /* tMOD  */
  YYSYMBOL_tRAN = 142,                     /* tRAN  */
  YYSYMBOL_tVAL = 143,                     /* tVAL  */
  YYSYMBOL_tLEFT = 144,                    /* tLEFT  */
  YYSYMBOL_tRIGHT = 145,                   /* tRIGHT  */
  YYSYMBOL_tMID = 146,                     /* tMID  */
  YYSYMBOL_tLEN = 147,                     /* tLEN  */
  YYSYMBOL_tMIN = 148,                     /* tMIN  */
  YYSYMBOL_tMAX = 149,                     /* tMAX  */
  YYSYMBOL_tSTR = 150,                     /* tSTR  */
  YYSYMBOL_tINKEY = 151,                   /* tINKEY  */
  YYSYMBOL_tCHR = 152,                     /* tCHR  */
  YYSYMBOL_tASC = 153,                     /* tASC  */
  YYSYMBOL_tHEX = 154,                     /* tHEX  */
  YYSYMBOL_tDEC = 155,                     /* tDEC  */
  YYSYMBOL_tBIN = 156,                     /* tBIN  */
  YYSYMBOL_tUPPER = 157,                   /* tUPPER  */
  YYSYMBOL_tLOWER = 158,                   /* tLOWER  */
  YYSYMBOL_tMOUSEX = 159,                  /* tMOUSEX  */
  YYSYMBOL_tMOUSEY = 160,                  /* tMOUSEY  */
  YYSYMBOL_tMOUSEB = 161,                  /* tMOUSEB  */
  YYSYMBOL_tMOUSEMOD = 162,                /* tMOUSEMOD  */
  YYSYMBOL_tTRIM = 163,                    /* tTRIM  */
  YYSYMBOL_tLTRIM = 164,                   /* tLTRIM  */
  YYSYMBOL_tRTRIM = 165,                   /* tRTRIM  */
  YYSYMBOL_tSTRING2 = 166,                 /* tSTRING2  */
  YYSYMBOL_tREPLACE = 167,                 /* tREPLACE  */
  YYSYMBOL_tINSTR = 168,                   /* tINSTR  */
  YYSYMBOL_tRINSTR = 169,                  /* tRINSTR  */
  YYSYMBOL_tCHOMP = 170,                   /* tCHOMP  */
  YYSYMBOL_tSYSTEM = 171,                  /* tSYSTEM  */
  YYSYMBOL_tSYSTEM2 = 172,                 /* tSYSTEM2  */
  YYSYMBOL_tPEEK = 173,                    /* tPEEK  */
  YYSYMBOL_tPEEK2 = 174,                   /* tPEEK2  */
  YYSYMBOL_tPOKE = 175,                    /* tPOKE  */
  YYSYMBOL_tFRNFN_CALL = 176,              /* tFRNFN_CALL  */
  YYSYMBOL_tFRNFN_CALL2 = 177,             /* tFRNFN_CALL2  */
  YYSYMBOL_tFRNFN_SIZE = 178,              /* tFRNFN_SIZE  */
  YYSYMBOL_tFRNBF_ALLOC = 179,             /* tFRNBF_ALLOC  */
  YYSYMBOL_tFRNBF_FREE = 180,              /* tFRNBF_FREE  */
  YYSYMBOL_tFRNBF_SIZE = 181,              /* tFRNBF_SIZE  */
  YYSYMBOL_tFRNBF_DUMP = 182,              /* tFRNBF_DUMP  */
  YYSYMBOL_tFRNBF_SET = 183,               /* tFRNBF_SET  */
  YYSYMBOL_tFRNBF_GET = 184,               /* tFRNBF_GET  */
  YYSYMBOL_tFRNBF_GET2 = 185,              /* tFRNBF_GET2  */
  YYSYMBOL_tFRNBF_GET_BUFFER = 186,        /* tFRNBF_GET_BUFFER  */
  YYSYMBOL_tFRNBF_SET_BUFFER = 187,        /* tFRNBF_SET_BUFFER  */
  YYSYMBOL_tDATE = 188,                    /* tDATE  */
  YYSYMBOL_tTIME = 189,                    /* tTIME  */
  YYSYMBOL_tTOKEN = 190,                   /* tTOKEN  */
  YYSYMBOL_tTOKENALT = 191,                /* tTOKENALT  */
  YYSYMBOL_tSPLIT = 192,                   /* tSPLIT  */
  YYSYMBOL_tSPLITALT = 193,                /* tSPLITALT  */
  YYSYMBOL_tGLOB = 194,                    /* tGLOB  */
  YYSYMBOL_tSTART_PROGRAM = 195,           /* tSTART_PROGRAM  */
  YYSYMBOL_tSTART_EXPRESSION = 196,        /* tSTART_EXPRESSION  */
  YYSYMBOL_tSTART_STRING_EXPRESSION = 197, /* tSTART_STRING_EXPRESSION  */
  YYSYMBOL_tSTART_ASSIGNMENT = 198,        /* tSTART_ASSIGNMENT  */
  YYSYMBOL_tSTART_FUNCTION_DEFINITION = 199, /* tSTART_FUNCTION_DEFINITION  */
  YYSYMBOL_tEVAL = 200,                    /* tEVAL  */
  YYSYMBOL_tEVAL2 = 201,                   /* tEVAL2  */
  YYSYMBOL_202_ = 202,                     /* '-'  */
  YYSYMBOL_203_ = 203,                     /* '+'  */
  YYSYMBOL_204_ = 204,                     /* '*'  */
  YYSYMBOL_205_ = 205,                     /* '/'  */
  YYSYMBOL_UMINUS = 206,                   /* UMINUS  */
  YYSYMBOL_207_ = 207,                     /* ';'  */
  YYSYMBOL_208_ = 208,                     /* ','  */
  YYSYMBOL_209_ = 209,                     /* '('  */
  YYSYMBOL_210_ = 210,                     /* ')'  */
  YYSYMBOL_211_ = 211,                     /* '#'  */
  YYSYMBOL_YYACCEPT = 212,                 /* $accept  */
  YYSYMBOL_program_or_expression = 213,    /* program_or_expression  */
  YYSYMBOL_program = 214,                  /* program  */
  YYSYMBOL_statement_list = 215,           /* statement_list  */
  YYSYMBOL_216_1 = 216,                    /* $@1  */
  YYSYMBOL_217_2 = 217,                    /* $@2  */
  YYSYMBOL_assignment = 218,               /* assignment  */
  YYSYMBOL_statement = 219,                /* statement  */
  YYSYMBOL_220_3 = 220,                    /* $@3  */
  YYSYMBOL_221_4 = 221,                    /* $@4  */
  YYSYMBOL_222_5 = 222,                    /* $@5  */
  YYSYMBOL_223_6 = 223,                    /* $@6  */
  YYSYMBOL_224_7 = 224,                    /* $@7  */
  YYSYMBOL_225_8 = 225,                    /* $@8  */
  YYSYMBOL_clear_fill_clause = 226,        /* clear_fill_clause  */
  YYSYMBOL_string_assignment = 227,        /* string_assignment  */
  YYSYMBOL_to = 228,                       /* to  */
  YYSYMBOL_open_clause = 229,              /* open_clause  */
  YYSYMBOL_seek_clause = 230,              /* seek_clause  */
  YYSYMBOL_string_scalar_or_array = 231,   /* string_scalar_or_array  */
  YYSYMBOL_string_expression = 232,        /* string_expression  */
  YYSYMBOL_string_function = 233,          /* string_function  */
  YYSYMBOL_number_assignment = 234,        /* number_assignment  */
  YYSYMBOL_expression = 235,               /* expression  */
  YYSYMBOL_236_9 = 236,                    /* $@9  */
  YYSYMBOL_237_10 = 237,                   /* $@10  */
  YYSYMBOL_arrayref = 238,                 /* arrayref  */
  YYSYMBOL_string_arrayref = 239,          /* string_arrayref  */
  YYSYMBOL_coordinates = 240,              /* coordinates  */
  YYSYMBOL_function = 241,                 /* function  */
  YYSYMBOL_const = 242,                    /* const  */
  YYSYMBOL_number = 243,                   /* number  */
  YYSYMBOL_symbol_or_lineno = 244,         /* symbol_or_lineno  */
  YYSYMBOL_dimlist = 245,                  /* dimlist  */
  YYSYMBOL_function_or_array = 246,        /* function_or_array  */
  YYSYMBOL_stringfunction_or_array = 247,  /* stringfunction_or_array  */
  YYSYMBOL_call_list = 248,                /* call_list  */
  YYSYMBOL_249_11 = 249,                   /* $@11  */
  YYSYMBOL_calls = 250,                    /* calls  */
  YYSYMBOL_call_item = 251,                /* call_item  */
  YYSYMBOL_function_definition = 252,      /* function_definition  */
  YYSYMBOL_253_12 = 253,                   /* $@12  */
  YYSYMBOL_254_13 = 254,                   /* $@13  */
  YYSYMBOL_255_14 = 255,                   /* $@14  */
  YYSYMBOL_endsub = 256,                   /* endsub  */
  YYSYMBOL_function_name = 257,            /* function_name  */
  YYSYMBOL_export = 258,                   /* export  */
  YYSYMBOL_local_list = 259,               /* local_list  */
  YYSYMBOL_local_item = 260,               /* local_item  */
  YYSYMBOL_static_list = 261,              /* static_list  */
  YYSYMBOL_static_item = 262,              /* static_item  */
  YYSYMBOL_paramlist = 263,                /* paramlist  */
  YYSYMBOL_paramitem = 264,                /* paramitem  */
  YYSYMBOL_for_loop = 265,                 /* for_loop  */
  YYSYMBOL_266_15 = 266,                   /* $@15  */
  YYSYMBOL_267_16 = 267,                   /* $@16  */
  YYSYMBOL_268_17 = 268,                   /* $@17  */
  YYSYMBOL_269_18 = 269,                   /* $@18  */
  YYSYMBOL_next = 270,                     /* next  */
  YYSYMBOL_step_part = 271,                /* step_part  */
  YYSYMBOL_next_symbol = 272,              /* next_symbol  */
  YYSYMBOL_switch_number_or_string = 273,  /* switch_number_or_string  */
  YYSYMBOL_274_19 = 274,                   /* $@19  */
  YYSYMBOL_sep_list = 275,                 /* sep_list  */
  YYSYMBOL_number_or_string = 276,         /* number_or_string  */
  YYSYMBOL_case_list = 277,                /* case_list  */
  YYSYMBOL_278_20 = 278,                   /* $@20  */
  YYSYMBOL_default = 279,                  /* default  */
  YYSYMBOL_280_21 = 280,                   /* $@21  */
  YYSYMBOL_do_loop = 281,                  /* do_loop  */
  YYSYMBOL_282_22 = 282,                   /* $@22  */
  YYSYMBOL_loop = 283,                     /* loop  */
  YYSYMBOL_while_loop = 284,               /* while_loop  */
  YYSYMBOL_285_23 = 285,                   /* $@23  */
  YYSYMBOL_286_24 = 286,                   /* $@24  */
  YYSYMBOL_wend = 287,                     /* wend  */
  YYSYMBOL_repeat_loop = 288,              /* repeat_loop  */
  YYSYMBOL_289_25 = 289,                   /* $@25  */
  YYSYMBOL_until = 290,                    /* until  */
  YYSYMBOL_if_clause = 291,                /* if_clause  */
  YYSYMBOL_292_26 = 292,                   /* $@26  */
  YYSYMBOL_293_27 = 293,                   /* $@27  */
  YYSYMBOL_294_28 = 294,                   /* $@28  */
  YYSYMBOL_295_29 = 295,                   /* $@29  */
  YYSYMBOL_endif = 296,                    /* endif  */
  YYSYMBOL_short_if = 297,                 /* short_if  */
  YYSYMBOL_298_30 = 298,                   /* $@30  */
  YYSYMBOL_end_of_if = 299,                /* end_of_if  */
  YYSYMBOL_else_part = 300,                /* else_part  */
  YYSYMBOL_elsif_part = 301,               /* elsif_part  */
  YYSYMBOL_302_31 = 302,                   /* $@31  */
  YYSYMBOL_303_32 = 303,                   /* $@32  */
  YYSYMBOL_maybe_then = 304,               /* maybe_then  */
  YYSYMBOL_inputlist = 305,                /* inputlist  */
  YYSYMBOL_306_33 = 306,                   /* $@33  */
  YYSYMBOL_input = 307,                    /* input  */
  YYSYMBOL_readlist = 308,                 /* readlist  */
  YYSYMBOL_readitem = 309,                 /* readitem  */
  YYSYMBOL_datalist = 310,                 /* datalist  */
  YYSYMBOL_printlist = 311,                /* printlist  */
  YYSYMBOL_using = 312,                    /* using  */
  YYSYMBOL_inputbody = 313,                /* inputbody  */
  YYSYMBOL_314_34 = 314,                   /* $@34  */
  YYSYMBOL_315_35 = 315,                   /* $@35  */
  YYSYMBOL_316_36 = 316,                   /* $@36  */
  YYSYMBOL_317_37 = 317,                   /* $@37  */
  YYSYMBOL_318_38 = 318,                   /* $@38  */
  YYSYMBOL_319_39 = 319,                   /* $@39  */
  YYSYMBOL_320_40 = 320,                   /* $@40  */
  YYSYMBOL_321_41 = 321,                   /* $@41  */
  YYSYMBOL_322_42 = 322,                   /* $@42  */
  YYSYMBOL_323_43 = 323,                   /* $@43  */
  YYSYMBOL_324_44 = 324,                   /* $@44  */
  YYSYMBOL_325_45 = 325,                   /* $@45  */
  YYSYMBOL_326_46 = 326,                   /* $@46  */
  YYSYMBOL_prompt = 327,                   /* prompt  */
  YYSYMBOL_printintro = 328,               /* printintro  */
  YYSYMBOL_hashed_number = 329,            /* hashed_number  */
  YYSYMBOL_goto_list = 330,                /* goto_list  */
  YYSYMBOL_gosub_list = 331                /* gosub_list  */
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
#define YYFINAL  200
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7472

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  212
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  120
/* YYNRULES -- Number of rules.  */
#define YYNRULES  521
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1359

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   457


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
       2,     2,     2,     2,     2,   211,     2,     2,     2,     2,
     209,   210,   204,   203,   208,   202,     2,   205,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   207,
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
     195,   196,   197,   198,   199,   200,   201,   206
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   204,   204,   205,   206,   207,   208,   211,   214,   215,
     215,   215,   218,   219,   220,   221,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   239,   240,   240,   241,   242,   243,   244,   245,
     246,   247,   247,   249,   249,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   261,   262,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   279,   280,
     281,   282,   283,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   357,   358,   359,
     360,   361,   365,   366,   367,   368,   369,   370,   373,   374,
     377,   378,   379,   380,   381,   384,   385,   388,   389,   392,
     393,   394,   395,   396,   397,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   445,   446,
     449,   449,   450,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   485,   488,   491,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     567,   568,   569,   570,   571,   574,   575,   576,   579,   580,
     581,   582,   585,   586,   589,   590,   591,   592,   595,   598,
     601,   601,   604,   605,   606,   609,   610,   613,   614,   617,
     613,   622,   623,   626,   627,   630,   631,   632,   633,   636,
     637,   640,   641,   642,   643,   646,   647,   650,   651,   652,
     653,   656,   657,   658,   661,   662,   663,   664,   667,   668,
     673,   688,   667,   693,   694,   695,   696,   697,   698,   701,
     702,   705,   706,   711,   711,   715,   716,   719,   720,   724,
     726,   725,   730,   731,   731,   735,   735,   741,   742,   743,
     744,   745,   746,   750,   751,   750,   757,   758,   762,   762,
     767,   768,   769,   770,   771,   772,   775,   776,   776,   778,
     775,   782,   783,   784,   785,   786,   787,   790,   790,   795,
     796,   799,   800,   803,   805,   807,   804,   811,   812,   815,
     816,   816,   819,   820,   822,   823,   827,   828,   831,   832,
     834,   835,   839,   840,   841,   842,   845,   846,   847,   848,
     849,   852,   853,   854,   857,   857,   858,   858,   859,   859,
     860,   860,   861,   861,   862,   862,   863,   863,   864,   864,
     865,   865,   866,   866,   867,   867,   868,   868,   869,   869,
     872,   873,   876,   877,   878,   879,   880,   881,   882,   883,
     884,   885,   886,   887,   888,   889,   892,   893,   895,   896,
     899,   900
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
  "tBFILESIZE", "tSIN", "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP",
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

#define YYPACT_NINF (-1105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-427)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      58,  4977,  4108,  4559,    43,    -8,   111,   -44,   -42, -1105,
   -1105, -1105, -1105, -1105,    33,    33,    33,  3702, -1105, -1105,
   -1105,  4559, -1105, -1105,  4559,   124,   110, -1105, -1105, -1105,
    4108,   -16, -1105,  4108,    75, -1105,  4108,  4108,  4108,    92,
      66,    33,  1495,   454,  2463,    11,  4108,  3296,  4108,    19,
      40,  4108, -1105,    67,  4559,  4559,  4559,    34,  4108,  1423,
    4108,   -39,   -11,     6,     8,    14,  2463,  4559,  4559,  4559,
   -1105,   152, -1105, -1105,    32, -1105, -1105, -1105, -1105,   135,
     162, -1105,   217, -1105, -1105, -1105, -1105, -1105, -1105, -1105,
   -1105,    72,   147, -1105, -1105, -1105, -1105,   171,   200,   209,
     226,  4108,   238,   241,   247,   251,   274,   283,    49,   285,
     291,   300,   302,   166,   304,   331,   345,   420,   428,   449,
     453,   459,   469,   471,   505,   521,   558,   566,   580,   582,
     650,   673,   674,   677,   695,   709,   710,   711,   712,   726,
     727,   745,   753,   755,   766,   767,   780,   810,   811,   812,
     828,   831,   839,   841,   842,   848,   854,   855,   868,   882,
     902,   903,   905,   914,   916,   917,   918,   922,   923,   925,
     926,   927,   928,   929,   930,   931,   932,   933,   937,   938,
     939,   940,   941,   942,   943,  4108,  4108,    30, -1105,   645,
   -1105, -1105, -1105, -1105,  4559,   -31,   199,   135,   162,   299,
   -1105,  4108, -1105,  4559, -1105,   327,  4108,  4804, -1105, -1105,
   -1105, -1105, -1105,   386,   275,   385,   429,   151, -1105,  4108,
   -1105,   151, -1105, -1105,  4108,  4804,   685,   944,   349,   945,
      10,  4108,    -2,    30,  7267,   946,   947,   358,  7267,    30,
    6171,    30,  6186,   950,   954,   366, -1105, -1105,  1007,  1007,
   -1105, -1105,   462, -1105,  3499,  4559,  4108,    15,  7267,   504,
      49, -1105, -1105, -1105,   536,  4108,  4559,  4559,  4559,  6206,
   -1105,  4108, -1105,    16,   575, -1105, -1105,  4108,  3905, -1105,
   -1105,  7267, -1105, -1105,   151,    31,    31, -1105,    16,  4108,
    4108,  4108,  4108,  4108,  4108,  4108,  4559,  4559,  4108,  4108,
    4108,  4108,    16,   875,   875,   875,  2672,  4559,   354,   577,
     151,  -162,    -9, -1105,   765,  4108,  4108,  4108,  4108,  4559,
   -1105, -1105, -1105,  4108,  4108,   840,  4108,  4108,  4108,  4108,
    2254,  2463,  4559, -1105,   522,   522,  4108,  4108,  4559,  4559,
    4108,  4108,  4108,  4108,  4108,  4108,  4108,  4108,  4108,  4108,
    2463,  4108,  4108,  4108,  4108,  4108,  4108,  4108,  4108,  2880,
    4559,  4559,  4559,  4559,  4559,  4108,  4108,  4108,  3088,  4108,
    4559,  4108,  4559,  4108,  4559,  4559,  1826,  2023,  4198,  4306,
    4559,  4559,  4559,  4108,  4559,  4559,  4559,  4559,  4559,  4559,
    2463,  4559, -1105, -1105,  4559,  4108,  4559,  4559,  4559,  4559,
    4559,   728,   790,  4559,   875,  4559,   875,  4559,  4559,  4559,
     959,   131,   794,  4559,  4559,  4559,  4559,  4559,  4559,  4559,
    4559, -1105, -1105, -1105,  4108,  4108,  4108,  4108,  4108,  4108,
    4108,  4108,  4108,  4108,  4108,  4108,   -69, -1105, -1105, -1105,
    7267,   829,   151,   850,  1028,  7267,   256, -1105, -1105, -1105,
   -1105,   955,   956,   897, -1105,   957,   958,   968, -1105,    30,
    7267,   969, -1105,    30,  7267,  1087,   257,  1132,  4804,  4108,
     970,  4559, -1105, -1105,  4108,    30,   368,   474,   971,  1123,
     973,    20, -1105,  1173, -1105, -1105,   690,  4108,  4108, -1105,
   -1105,    92, -1105, -1105,    74,  6274,   151,  7267,   656,  4393,
    4108,    16,   151,   151,    76,  4108, -1105,    -2, -1105, -1105,
    4108,  4559, -1105,  4108,    16,  4108,  4108,  4108,   978,    16,
     979,    16,   980,    16,    16,   125,   151,   981,   984,    16,
      16,  4108,   985,   987,   988,   989, -1105,   821,   -37,  4108,
    4108,  4108,  4108, -1105,   990,    16,    16,  7267,   151,   759,
     983,   991,  6295,  6329,  1705,  6349,  6364,  6379,   994,   653,
     992,   997,   195,   999,  1001,  1002,  1003,  1006,  1008,    16,
    6394,   262,   -13,  1819,  1879,  2084,  2485,  2694,   740,  2902,
    1045,  3110,  3318,  1005,  3521,  3724,  3927,  4859,  4897,  5070,
    5145,  6417, -1105,  5213,    79,   307,   341,   503,    89,  6438,
    6453,   431,  1098, -1105,  5234,  5268,   189,  5288,   -96,  5303,
     198,   245, -1105,   264, -1105,   321, -1105,   342, -1105,   357,
     365,   457,   461,  6472,   638,   669,   771,   463,   473,   483,
     748,  1009,   -87,  1010,  1011,   531,  5318,   535,    17,   819,
     827,   830, -1105, -1105,   851,  -153,   863,   -60,   864,   543,
     574, -1105, -1105,   151,   151,   151,   151,   151,   151,   151,
   -1105,  4108,  4108,   763,   576,   697,   249,   109,   116,   -65,
   -1105,   -41,   -41,   959,   959, -1105, -1105, -1105,  4804, -1105,
   -1105,  4108, -1105, -1105, -1105, -1105,    33,    33, -1105, -1105,
     385, -1105, -1105,   429,  4108, -1105,  1168, -1105, -1105, -1105,
   -1105, -1105, -1105, -1105, -1105,   716,  6537,  4108,   134,  5333,
    4613, -1105, -1105,  4108,  4108,  1013,  4559, -1105, -1105,  4108,
   -1105,   801,  1014,  1015,  1017,  1018,  6560,  6596,  1019,  1020,
   -1105, -1105, -1105,  4108,  1143,  1146, -1105,   870,  6615,  4108,
    4559,  7267, -1105, -1105,   876, -1105,  4108,  6630,  6645,  1024,
    4559,  4108,  4108,  4108,  4559,  4108,  4108,  4108,  4108,  4108,
    4108,  4108,  1026, -1105,  4108,  4108,  4108, -1105, -1105,    30,
    7267,    30,  7267,  6660,  6680,  4804,  4108,  4108,  4108, -1105,
   -1105, -1105, -1105, -1105,  4108,  4108, -1105,  4108,  4108,  4108,
   -1105,  4559, -1105,  4491, -1105,  4559,  1025,  1030, -1105, -1105,
    4108,  4108,  4108,  4108,  4559, -1105, -1105, -1105, -1105, -1105,
   -1105,  4108, -1105, -1105,  4108, -1105, -1105, -1105, -1105, -1105,
   -1105, -1105, -1105, -1105, -1105, -1105,  4108, -1105, -1105,  4108,
    4108,  4108, -1105,  4108,  4108, -1105,  4559, -1105, -1105, -1105,
   -1105, -1105,  4108, -1105, -1105, -1105, -1105, -1105, -1105, -1105,
   -1105, -1105, -1105, -1105,  4559,  4559,  4559,  4559, -1105, -1105,
   -1105, -1105, -1105,  4559, -1105, -1105, -1105, -1105, -1105, -1105,
    4108, -1105,  4108,  4108,  4108,  1231,  4559, -1105,  1231,  4559,
   -1105,  4559, -1105, -1105,   840,   627,  4108,    54,  7267, -1105,
    1033, -1105,  1034,  1036,  1042, -1105,  1044,  1048, -1105, -1105,
   -1105,   786,  4804, -1105, -1105, -1105,  4108,  6703,  4559,  1185,
   -1105,  4559,   151,    30,   368,  6718,  4108,   160,   801,   801,
    5356,  1035,  1050, -1105,  1052, -1105, -1105, -1105, -1105,  4108,
    4108, -1105, -1105,  6739,  2463,  2463,  4559,  4559,  1053,   884,
    4559, -1105,  4108,  4108,  4559,   151,  1054,  6803,    16,   885,
    1056,    16,    30,  6823,  6861,  6882,    16,  1058,  4559,  1057,
    5377,  5392,  1269,  4559,  4559, -1105,  7267,    16, -1105,  1060,
    5411,  5476,  5499,  5535,  5554,   599,  1062,   263,   151, -1105,
   -1105,  5569,  5584,  1065,    83,   886,  5599,  5619,  5642,  5657,
    5678,  1645,  5742,  5762,   278,  5800,   652,   887,   279,   287,
     671,  5821,  6897,  6912,  5836,   107,   719,   122,   720,   721,
      56, -1105, -1105, -1105,    33,    33, -1105, -1105, -1105, -1105,
    4108,  1227,  1238,  1234,  5851,  4108,   729,  1069,   322, -1105,
    4108,  6927,  4559,  1223, -1105, -1105, -1105, -1105, -1105, -1105,
    1074,  1075,  7267,  7267,  4559, -1105, -1105,   151,   151,  4559,
    4559,   894,  6946,  7267,   896,  4559,  4559,  4108,  4559,  4559,
    4108,  4108,  4108,  4108,  4108,  4108,   151, -1105,  1212,  1214,
    4108,  1215,   898,   151,  4108,   823, -1105, -1105, -1105, -1105,
   -1105, -1105, -1105,  4559, -1105, -1105, -1105, -1105,  4108,  4559,
   -1105, -1105, -1105, -1105, -1105,  4108, -1105, -1105, -1105,  4559,
   -1105, -1105, -1105,  4559,  4108, -1105,  4108, -1105, -1105, -1105,
    4559,  4108, -1105,  4559, -1105, -1105,  4559, -1105, -1105, -1105,
    4108, -1105, -1105, -1105, -1105, -1105,  1243,   782,  5866,  1235,
    4108,  4559,  5885,  4108,   737,  1085,  1173,   801,  1089,  1094,
     801, -1105, -1105,   151,   921,   151,  4559,  4559,  4559,   151,
     151,  1097,   151,   151,    16,  6966,  6981,  7004,    16,  7070,
    4559,  4559,  5905,  4559,  4108, -1105,  1086,  1088,   145, -1105,
     743,  7089,   151,  5920,   746,   749,  5943,  6009,   770,  6028,
     785,   791,   105,  4804,  5150,  4108,  1260, -1105,  1100, -1105,
    1101,  7124,   802,   784,  6063,  1253,  4108,   801, -1105, -1105,
   -1105, -1105,  4559,   151,   151,   151,  4559,  4108,  4108,  4559,
    4108,  4108,  4108,   151,   151,  1237,   151,  7267,  1103,  1104,
     823, -1105, -1105,  4108, -1105, -1105, -1105, -1105, -1105, -1105,
   -1105, -1105, -1105,  4108, -1105,  1234,  1277,   723,  4804, -1105,
    4559,  4108,  4108, -1105, -1105,  1107,  1173, -1105,  1108,  1173,
    7147, -1105,   151,   151,  1110,  7162,   151,  7177,  1111,  7192,
    4559, -1105, -1105, -1105,  4804,  6086,  7267,  4804, -1105, -1105,
    1234,   498,   338,  7213,  6101,  1173,  4559,   801,  1173,  4108,
     801,  4108,  4559,  4559,  4108,  4559,  4559,   151,    69, -1105,
    1234,  4804, -1105, -1105, -1105, -1105, -1105, -1105, -1105,  4559,
   -1105,  4108, -1105,   801,   355, -1105,   801,  7232, -1105,  6116,
     151,   151,  7247,   151,   151, -1105, -1105, -1105,   643,  1234,
     803,  6131, -1105,  4559, -1105, -1105,  4108, -1105,  4559, -1105,
   -1105, -1105, -1105, -1105, -1105,  1317,  1243, -1105, -1105,   808,
    1173,  6152,  1173,   151, -1105, -1105, -1105, -1105,   801, -1105,
     801,  1173, -1105,  1173, -1105,   801,   801, -1105, -1105
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   137,     0,     0,     0,   355,     0,     0,     0,   131,
     378,   413,   418,    18,     0,     0,     0,     0,    31,    33,
     356,     0,   340,   340,     0,   357,    25,    27,   393,   405,
       0,   502,    55,    67,     0,   128,   129,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,   138,
     139,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,     0,     0,     0,     0,     0,
       2,     9,    17,     8,     0,    12,    46,    48,    14,    29,
      30,    28,     0,    20,    21,    24,    23,    22,    35,    36,
     328,   230,   159,   329,   330,   331,   162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,     0,     0,     0,     0,     0,     0,
       0,   290,   293,   296,   299,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   190,   192,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,     0,
     244,   224,   229,   161,     0,     0,     0,     0,     0,     0,
       1,     0,   340,     0,   340,     0,     0,    16,   333,   332,
      37,    38,    45,     0,     0,     0,     0,    19,    50,   342,
      51,    49,   358,    26,     0,    16,   437,     0,   506,     0,
       0,   466,   498,    69,    68,     0,     0,    70,   130,    60,
       0,    62,     0,   458,   460,    63,   456,   462,     0,     0,
     463,   325,    64,    66,     0,   115,     0,     0,   517,     0,
      93,   117,    86,    47,     0,     0,     0,     0,     0,     0,
      74,     0,    57,    79,     0,    95,    94,     0,     0,   140,
     141,   118,    13,    15,   132,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,     0,     7,     0,     0,     0,     0,     0,     0,
     347,   340,   340,     0,     0,   214,     0,     0,     0,     0,
       0,     0,     0,   320,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   340,   340,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,   212,   210,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     5,     6,
     208,     0,   142,     0,     0,   414,     9,    39,    40,    41,
      43,   361,   362,    32,   359,   367,   368,    34,   365,   345,
     346,   341,   343,   398,   397,     0,     9,     0,    16,     0,
       0,     0,   503,   504,     0,   469,   471,    52,     0,     0,
       0,     0,    56,   500,   340,   340,     0,     0,     0,   340,
     340,     0,   327,   326,     0,     0,   116,   516,     0,     0,
       0,     0,    97,    73,     0,     0,    78,   498,   149,   148,
       0,     0,    75,     0,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,   157,     0,     0,     0,   121,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,   209,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   270,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   174,     0,     0,     0,     0,     0,     0,
       0,     0,   291,     0,   294,     0,   297,     0,   300,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   193,     0,     0,     0,     0,     0,     0,
       0,   164,   245,   239,   241,   243,   240,   242,   237,   238,
     163,     0,     0,   217,   219,   221,   218,   220,   215,   216,
     235,   232,   231,   233,   234,   338,   339,   379,    16,   425,
     423,     0,   424,   420,   422,   419,     0,     0,   340,   340,
       0,   340,   340,     0,     0,   395,   399,   412,   410,   411,
     408,   407,   409,   406,   427,     9,     0,     0,     0,     0,
       0,   467,    53,    54,     0,     0,     0,   474,   476,     0,
     501,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     457,   464,   465,     0,     0,     0,   152,   151,   155,     0,
       0,   248,    58,    76,    89,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   340,     0,     0,     0,   122,   123,   124,
     125,   126,   127,     0,     0,    16,     0,     0,     0,   353,
     354,   348,   312,   204,     0,     0,   303,     0,     0,     0,
     313,     0,   314,     0,   307,     0,     0,     0,   225,   226,
       0,     0,     0,     0,     0,   324,   249,   250,   251,   252,
     253,     0,   254,   256,     0,   257,   259,   260,   222,   266,
     267,   261,   263,   264,   265,   262,     0,   269,   274,     0,
       0,     0,   273,     0,     0,   172,     0,   169,   175,   176,
     275,   202,     0,   276,   203,   177,   178,   289,   292,   295,
     298,   181,   179,   180,     0,     0,     0,     0,   184,   282,
     185,   288,   287,     0,   194,   283,   186,   284,   187,   286,
       0,   188,     0,     0,     0,     0,     0,   197,     0,     0,
     199,     0,   319,   207,   213,   211,     0,     9,   421,   518,
      42,   520,    44,     0,     0,   360,     0,     0,   366,   344,
     396,   402,    16,   439,   440,   438,     0,     0,     0,   507,
     505,     0,   472,   470,   471,     0,     0,     0,     0,     0,
       0,   452,   454,   499,   449,   334,   336,   340,   340,     0,
       0,   459,   461,    71,     0,     0,     0,     0,     0,     0,
       0,    77,     0,     0,     0,   103,     0,     0,     0,     0,
       0,     0,   100,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    87,     0,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   321,   246,
     247,     0,     0,     0,     0,   322,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   417,   416,   415,     0,     0,   363,   364,   369,   370,
       0,     0,     0,   428,     0,     0,     0,     0,     0,   468,
       0,     0,     0,   488,   475,   477,   478,   340,   340,   450,
       0,     0,    59,    61,     0,   153,   154,   150,   156,     0,
       0,    90,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   158,     0,     0,
       0,     0,   135,   136,     0,   371,   301,   302,   304,   305,
     306,   315,   316,     0,   317,   227,   228,   200,     0,     0,
     255,   258,   268,   165,   166,     0,   168,   271,   272,     0,
     170,   277,   182,     0,     0,   278,     0,   280,   195,   189,
       0,     0,   206,     0,   309,   196,     0,   311,   198,   223,
       0,   519,   521,   400,   403,   394,   443,   509,     0,   508,
       0,     0,     0,     0,     0,     0,   500,     0,     0,     0,
       0,   335,   337,    72,     0,    98,     0,     0,     0,   104,
     107,     0,   102,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,   374,   375,     0,   372,
       0,     0,   323,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   389,    16,   137,     0,   441,   513,     0,   510,
       0,     0,     0,   480,     0,   490,     0,     0,   479,   453,
     455,   451,     0,    91,    82,    99,     0,     0,     0,     0,
       0,     0,     0,   145,   146,     0,   144,   134,     0,     0,
       0,   349,   318,     0,   167,   171,   183,   279,   281,   285,
     205,   308,   310,     0,   380,   401,     9,   447,    16,   429,
       0,     0,     0,   473,   492,     0,   500,   482,     0,   500,
       0,   489,    96,   111,     0,     0,   108,     0,     0,     0,
       0,   376,   377,   373,    16,     0,   390,    16,   448,   444,
     442,     0,     0,     0,     0,   500,     0,     0,   500,     0,
       0,     0,     0,     0,     0,     0,     0,   143,     9,   201,
     381,    16,   436,   433,   434,   435,   431,   432,   430,     0,
     514,     0,   511,     0,     0,   481,     0,     0,   491,     0,
     110,   101,     0,   112,   106,   352,   351,   350,     0,   445,
       0,     0,   493,     0,   494,   483,     0,   484,     0,   384,
     386,   387,   388,   383,   385,   391,   443,   515,   512,     0,
     500,     0,   500,   109,   392,   382,   446,   496,     0,   486,
       0,   500,   495,   500,   485,     0,     0,   497,   487
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1105, -1105, -1105,  -206, -1105, -1105,  1318,   548, -1105, -1105,
   -1105, -1105, -1105, -1105, -1105,  1271,  -279, -1105, -1105,  -255,
      -3, -1105,  1273,  1032, -1105, -1105,   993,  -325,   692, -1105,
     833,   -18,   -12, -1105,     1,     7,    44, -1105, -1105,   635,
    1325, -1105, -1105, -1105, -1105, -1105, -1105, -1105,   641, -1105,
     642, -1105,   114, -1105, -1105, -1105, -1105, -1105, -1105, -1105,
   -1105, -1105, -1105, -1105,   316, -1105, -1105, -1105, -1105, -1105,
   -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105,
   -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105,    12,
   -1105, -1105, -1105,  -857, -1105, -1105, -1105,   846, -1105, -1105,
     433,   844, -1105, -1105, -1105, -1105, -1105, -1105, -1105, -1105,
   -1105, -1105, -1105, -1105, -1105, -1104, -1105,   -28, -1105, -1105
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,    70,    71,   314,   775,    72,    73,   215,   216,
     686,   687,   232,   507,    74,    75,   510,    76,    77,   533,
     187,   188,    78,   269,   662,   661,   565,   566,   270,   190,
     250,   191,   210,   237,   192,   193,   218,   219,   461,   462,
      81,   549,   969,  1264,  1317,   781,    82,   453,   454,   457,
     458,  1168,  1169,    83,   205,   886,  1267,  1318,  1335,  1234,
    1345,    84,   224,   696,   465,   901,  1183,  1022,  1184,    85,
     225,   703,    86,   206,   678,  1013,    87,   207,   685,    88,
     467,   902,  1126,  1271,  1298,    89,   468,   905,  1239,  1186,
    1291,  1336,  1269,   923,  1140,   924,   245,   246,   252,   477,
     711,   482,   918,   919,  1137,  1246,  1278,  1342,  1353,  1136,
    1249,  1275,  1340,  1351,   483,   721,   231,   259,   890,   892
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     195,   446,    79,   211,   212,   197,   515,   516,    80,   517,
     568,   198,   431,   437,   472,   263,   264,   473,   217,   466,
      20,   221,   251,   531,   717,    25,   498,   718,   508,   253,
     233,   201,  1197,   203,   239,   241,   431,   208,   309,   257,
     209,   420,   227,   508,   228,   229,   541,     7,     8,   534,
     535,   284,   285,   286,   197,   876,   478,   877,   479,   480,
     198,  1034,  1035,   308,   310,   311,   312,   220,  1120,    90,
    1011,     7,     8,    93,    94,    95,   247,    90,   275,   235,
     236,    93,    94,    95,   731,   413,   414,   415,   416,   417,
     418,   419,   265,   266,  1315,   508,   243,   244,  1012,   267,
     413,   414,   415,   416,   417,   418,   419,   420,   276,   277,
     278,   200,   842,  1316,   843,   279,   420,   223,  1233,   422,
     423,   863,   268,   864,   315,   316,   424,   425,   426,   427,
     428,   429,   430,   431,   420,   280,   317,   432,   433,   434,
     435,   651,  1277,    53,   287,  1280,   422,   423,   879,   645,
     880,   647,   222,   424,   425,   426,   427,   428,   429,   430,
     431,   332,   333,   434,   435,   202,   420,   204,   422,   423,
     303,  1303,   420,   768,  1306,   424,   425,   426,   427,   428,
     429,   430,   431,   411,   429,   430,   431,    61,    62,    63,
     420,   436,   430,   431,   420,   230,   313,   805,   304,   542,
     442,   413,   414,   415,   416,   417,   418,   419,    79,   481,
     318,    61,    62,    63,    80,   305,   459,   306,   420,   474,
     420,   463,   739,   307,   509,   870,    79,   871,   475,   719,
     492,   493,    80,   420,   420,   746,  1348,   319,  1350,   509,
     751,   320,   753,   438,   755,   756,   441,  1355,   443,  1356,
     760,   761,   496,     1,     2,     3,     4,     5,   432,   433,
     434,   435,   705,   502,   503,   504,   777,   778,   248,   249,
     679,   697,   680,   698,   681,   699,   248,   249,   338,   420,
    1198,   202,   420,  1201,   740,   432,   433,   434,   435,   828,
     802,   509,   420,   525,   526,   449,   450,   682,   700,   832,
     683,   701,   560,   561,   538,   684,   702,   432,   433,   434,
     435,   432,   433,   434,   435,  1113,   548,  1114,   432,   433,
     434,   435,   583,   428,   429,   430,   431,   559,   420,   562,
    1116,   444,  1117,   757,   420,   571,   572,   420,   422,   423,
    1251,   651,   908,   439,   909,   424,   425,   426,   427,   428,
     429,   430,   431,  1220,   420,  1221,   204,   594,   595,   596,
     597,   598,   631,   420,   601,   550,   551,   606,  1032,   608,
    1033,   610,   611,   613,   615,   617,   619,   620,   621,   622,
     321,   624,   625,   626,   627,   628,   629,   630,   632,   451,
     452,   635,   420,   637,   638,   639,   640,   641,   420,   840,
     644,   420,   646,   795,   648,   649,   650,   470,   845,   322,
     653,   654,   655,   656,   657,   658,   659,   660,   323,   710,
    1305,   447,   448,  1308,   413,   414,   415,   416,   417,   418,
     419,   422,   423,   455,   456,   324,   633,   634,   424,   425,
     426,   427,   428,   429,   430,   431,  1322,   326,   420,  1325,
     327,   432,   433,   434,   435,   846,   328,    90,    91,    92,
     329,    93,    94,    95,    96,   420,   420,   420,   708,    79,
     804,  1083,   887,  1084,   847,    80,   251,   432,   433,   434,
     435,   420,   420,   330,    97,    98,  1099,  1104,  1100,  1105,
     420,  1352,   331,  1354,   334,  1106,   737,  1107,  1357,  1358,
     335,   413,   414,   415,   416,   417,   418,   419,   744,   336,
     420,   337,  1292,   339,  1293,   829,  1294,    99,   100,   101,
     102,   103,   104,   105,   420,   420,   563,   564,   722,   723,
    1131,   848,   651,   728,   729,   106,   769,   771,   107,  1295,
     340,   420,  1296,   260,   420,   420,  1299,  1297,  1300,   830,
    1005,   261,   849,  1007,   341,   109,   110,   420,   420,   111,
     420,   112,   539,  1323,   262,  1324,   486,   850,   420,   113,
     432,   433,   434,   435,   491,   851,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   342,
     167,   168,   169,   170,   420,   171,   172,   343,   173,   174,
     175,   835,   176,   177,   178,   179,   180,   181,   182,   427,
     428,   429,   430,   431,   183,   184,   185,  1329,   344,  1330,
     420,  1331,   345,   186,   420,   256,   420,   852,   346,  1057,
     494,   853,  1060,   858,   889,   891,   420,  1064,   347,    79,
     348,   712,   713,   859,  1332,    80,   420,  1333,  1074,   421,
     422,   459,  1334,   860,   724,   725,  1023,   424,   425,   426,
     427,   428,   429,   430,   431,  1088,   420,   912,   422,   423,
     913,   831,   499,   917,   349,   424,   425,   426,   427,   428,
     429,   430,   431,   413,   414,   415,   416,   417,   418,   419,
     350,  -426,   893,   894,   420,   896,   897,   939,   420,   273,
     274,   867,   734,   735,   500,   869,   420,   945,   422,   423,
     288,   949,   302,   882,   952,   424,   425,   426,   427,   428,
     429,   430,   431,   779,   780,   903,   904,   351,   425,  1268,
     427,   428,   429,   430,   431,   352,    79,   420,   432,   433,
     434,   435,    80,   511,   883,   540,   422,   423,   975,   353,
     977,   354,   978,   424,   425,   426,   427,   428,   429,   430,
     431,   985,   420,   422,   423,   921,   922,   959,   543,  1081,
     424,   425,   426,   427,   428,   429,   430,   431,   413,   414,
     415,   416,   417,   418,   419,  1020,  1021,  1166,  1167,   432,
     433,   434,   435,   994,   425,   426,   427,   428,   429,   430,
     431,   420,  1187,  1188,  1244,  1245,   855,   432,   433,   434,
     435,   996,   997,   998,   999,   420,   420,   422,   423,   355,
    1000,   791,  1102,   792,   424,   425,   426,   427,   428,   429,
     430,   431,   420,  1006,   420,  1207,  1008,   856,  1009,  1211,
     532,  1108,   356,   357,   422,   423,   358,   432,   433,   434,
     435,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,    79,   359,  1026,  1045,  1046,  1028,    80,
     424,   425,   426,   427,   428,   429,   430,   431,   360,   361,
     362,   363,   420,   420,   420,   432,   433,   434,   435,  1115,
    1118,  1119,   420,  1047,  1048,   364,   365,  1051,   642,  1129,
     420,  1054,   432,   433,   434,   435,   420,  1195,   811,   420,
     812,   420,   420,  1222,   366,  1066,  1225,   501,   861,  1226,
    1072,  1073,   367,   506,   368,   432,   433,   434,   435,   512,
     514,  1040,  1041,   420,   420,   369,   370,  1235,  1236,   857,
    1229,   518,   519,   520,   521,   522,   523,   524,   420,   371,
     527,   528,   529,   530,   420,  1231,   432,   433,   434,   435,
     643,  1232,  1121,  1122,   652,   420,   420,   544,   545,   546,
      90,   420,  1243,  1337,    93,    94,    95,   463,  1347,   372,
     373,   374,   420,   432,   433,   434,   435,   872,   569,  1134,
     420,   767,  1270,   420,   189,   873,   431,   375,   874,   675,
     376,  1143,   432,   433,   434,   435,  1144,  1145,   377,   214,
     378,   379,  1149,  1150,   420,  1152,  1153,   380,  1288,   875,
     676,  1290,   226,   381,   382,   234,   420,   420,   238,   240,
     242,   878,   881,   420,   258,   258,   258,   383,   936,   420,
    1170,  1138,  1139,   281,   940,  1319,  1172,   420,   420,   420,
     420,   384,  1050,  1058,  1089,  1103,  1174,   420,   258,   420,
    1175,   420,  1146,   677,  1148,   690,  1164,  1178,   422,   423,
    1180,   385,   386,  1181,   387,   424,   425,   426,   427,   428,
     429,   430,   431,   388,   420,   389,   390,   391,  1192,  1202,
     695,   392,   393,   325,   394,   395,   396,   397,   398,   399,
     400,   401,   402,  1203,  1204,  1205,   403,   404,   405,   406,
     407,   408,   409,   469,   471,   484,   485,  1213,  1214,   489,
    1216,   422,   423,   490,   688,   689,   691,   692,   424,   425,
     426,   427,   428,   429,   430,   431,   693,   694,   704,   707,
     714,   715,   716,   720,    79,    79,   750,   752,   754,   758,
      80,    80,   759,   782,   763,   764,   765,   766,   776,  1252,
     793,   783,   743,  1253,   790,   745,  1256,   794,   796,   749,
     797,   900,   798,   799,   800,   818,   801,   410,   412,   862,
     865,   866,   916,   762,   925,   926,   927,   928,   934,   931,
     932,   935,   944,   440,   958,   979,   564,  1272,   445,    79,
     980,  1014,  1015,  1027,  1037,    80,  1016,   432,   433,   434,
     435,   460,  1017,   814,  1018,   815,   464,  1287,  1019,  1038,
    1039,  1049,  1055,   476,  1059,    79,  1065,  1067,    79,  1075,
    1124,    80,  1082,  1304,    80,  1087,  1125,    -9,  1130,  1310,
    1311,  1135,  1313,  1314,  1141,  1142,   495,  1160,   497,  1161,
    1163,  1185,    79,  1190,  1196,  1218,  1320,  1219,    80,  1199,
     432,   433,   434,   435,  1200,  1206,   836,  1238,   837,  1240,
    1241,  1248,  1260,  1261,  1262,  -404,  1276,  1279,  1282,  1285,
    1339,  1344,   196,   965,   282,  1343,   283,   732,   567,   899,
     199,   895,   422,   423,  1263,   898,  1123,   730,   537,   424,
     425,   426,   427,   428,   429,   430,   431,  1029,  1346,     0,
     547,   742,     0,     0,     0,   552,   553,     0,   554,   555,
     556,   557,   258,   258,     0,     0,     0,     0,     0,   570,
       0,     0,   573,   574,   575,   576,   577,   578,   579,   580,
     581,   582,   258,   584,   585,   586,   587,   588,   589,   590,
     591,   593,     0,     0,     0,     0,     0,   599,   600,   602,
     604,   605,     0,   607,     0,   609,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   623,     0,     0,     0,     0,
       0,     0,   258,     0,     0,     0,     0,   636,     0,     0,
       0,   938,     0,     0,     0,     0,     0,     0,   941,     0,
       0,     0,     0,   946,     0,   948,     0,   950,   951,     0,
       0,     0,   956,   957,     0,     0,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   672,   673,   674,     0,   967,
     968,   432,   433,   434,   435,     0,     0,  1070,     0,  1071,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   983,     0,     0,     0,    90,    91,
      92,   706,    93,    94,    95,    96,   709,     0,     0,     0,
       0,     0,     0,   289,   290,   291,   292,   293,     0,   726,
     727,     0,     0,     0,     0,    97,    98,   294,     0,     0,
       0,     0,   738,   295,   296,     0,     0,   741,     0,   297,
     298,   299,   300,   301,     0,     0,     0,   747,   748,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,   770,   772,   773,   774,     0,   106,     0,     0,   107,
       0,     0,     0,     0,   254,     0,     0,     0,     0,     0,
       0,     0,   255,     0,     0,     0,   109,   110,     0,     0,
     111,     0,   112,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
       0,   167,   168,   169,   170,     0,   171,   172,     0,   173,
     174,   175,     0,   176,   177,   178,   179,   180,   181,   182,
       0,     0,     0,   884,   885,   183,   184,   185,     0,     0,
       0,     0,     0,     0,   186,     0,   256,     0,   422,   423,
       0,     0,     0,   888,     0,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,   460,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   907,
       0,     0,     0,     0,     0,   914,   915,     0,     0,  1151,
       0,   920,  1154,     0,     0,     0,  1158,     0,     0,     0,
       0,     0,     0,     0,     0,   933,  1165,     0,   422,   423,
       0,     0,     0,     0,     0,   424,   425,   426,   427,   428,
     429,   430,   431,     0,   947,     0,     0,     0,     0,   953,
     954,   955,     0,     0,     0,     0,   960,   961,   962,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   966,     0,
       0,     0,     0,     0,     0,     0,   970,   971,     0,   972,
     973,   974,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,   981,   982,     0,   984,    96,     0,     0,     0,
       0,     0,     0,   986,     0,     0,   987,   432,   433,   434,
     435,     0,     0,  1095,     0,  1096,     0,    98,   988,     0,
       0,   989,   990,   991,     0,   992,   993,     0,     0,     0,
       0,     0,     0,     0,   995,     0,     0,     0,     0,     0,
       0,     0,   422,   423,     0,     0,     0,     0,     0,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,  1254,
       0,     0,  1001,  1258,  1002,  1003,  1004,   432,   433,   434,
     435,     0,     0,     0,     0,   786,     0,     0,  1010,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,   112,     0,     0,     0,     0,  1024,     0,
       0,     0,   422,   423,     0,     0,     0,     0,  1031,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,  1042,  1043,     0,     0,     0,   258,   258,     0,     0,
     136,   137,   138,     0,  1052,  1053,   142,   143,   144,     0,
     146,     0,   148,   149,   150,     0,     0,     0,     0,   155,
     156,   157,   158,   159,     0,     0,   162,     0,   164,     0,
     166,     0,     0,   168,     0,   170,     0,     0,   172,     0,
       0,   174,   175,     0,   176,   177,     0,   179,     0,   181,
       0,   432,   433,   434,   435,     0,     0,   184,    92,   806,
       0,     0,     0,    96,     0,   194,   612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   464,     0,    98,     0,     0,  1128,     0,     0,
       0,     0,  1132,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   432,   433,   434,   435,     0,     0,     0,     0,   807,
       0,     0,     0,  1155,  1156,  1157,     0,  1159,     0,     0,
       0,     0,  1162,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1171,     0,     0,     0,     0,     0,     0,  1173,   111,     0,
     112,     0,     0,     0,     0,     0,  1176,     0,  1177,     0,
       0,     0,     0,  1179,     0,     0,     0,   422,   423,     0,
       0,     0,  1182,     0,   424,   425,   426,   427,   428,   429,
     430,   431,  1191,     0,     0,  1194,     0,   136,   137,   138,
       0,     0,     0,   142,   143,   144,     0,   146,     0,   148,
     149,   150,     0,     0,     0,     0,   155,   156,   157,   158,
     159,     0,     0,   162,     0,   164,  1217,   166,     0,     0,
     168,     0,   170,     0,     0,   172,     0,     0,   174,   175,
       0,   176,   177,     0,   179,     0,   181,  1237,     0,     0,
       0,     0,     0,     0,   184,     0,     0,     0,  1250,     0,
       0,     0,   194,   614,     0,     0,     0,     0,     0,     0,
    1255,     0,  1257,     0,  1259,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1265,     0,    90,    91,    92,
       0,    93,    94,    95,    96,  1266,     0,     0,     0,     0,
       0,     0,     0,  1273,  1274,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,    98,   432,   433,   434,   435,
       0,     0,     0,     0,   808,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1307,     0,  1309,     0,     0,  1312,    99,   100,   101,
     102,   103,   104,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1321,     0,   106,     0,     0,   107,     0,
       0,     0,     0,   108,     0,     0,     0,     0,     0,     0,
       0,   558,     0,     0,     0,   109,   110,     0,  1341,   111,
       0,   112,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,     0,
     167,   168,   169,   170,     0,   171,   172,     0,   173,   174,
     175,     0,   176,   177,   178,   179,   180,   181,   182,     0,
       0,     0,     0,     0,   183,   184,   185,     0,     0,     0,
       0,     0,     0,   186,     0,   256,    90,    91,    92,     0,
      93,    94,    95,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,     0,     0,   107,   422,   423,
       0,     0,   108,     0,     0,   424,   425,   426,   427,   428,
     429,   430,   431,     0,   109,   110,     0,     0,   111,     0,
     112,     0,     0,     0,     0,     0,     0,     0,   113,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,     0,   167,
     168,   169,   170,     0,   171,   172,     0,   173,   174,   175,
       0,   176,   177,   178,   179,   180,   181,   182,     0,     0,
       0,     0,     0,   183,   184,   185,     0,     0,     0,     0,
       0,     0,   186,     0,   256,    90,    91,    92,     0,    93,
      94,    95,    96,     0,     0,     0,     0,   432,   433,   434,
     435,     0,     0,     0,     0,   809,     0,     0,     0,     0,
       0,     0,    97,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,     0,     0,   107,   422,   423,     0,
       0,   108,     0,     0,   424,   425,   426,   427,   428,   429,
     430,   431,     0,   109,   110,     0,     0,   111,     0,   112,
       0,     0,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,     0,   167,   168,
     169,   170,     0,   171,   172,     0,   173,   174,   175,     0,
     176,   177,   178,   179,   180,   181,   182,     0,     0,     0,
       0,     0,   183,   184,   185,     0,     0,     0,     0,     0,
       0,   186,   536,    90,    91,    92,     0,    93,    94,    95,
      96,     0,     0,     0,     0,     0,   432,   433,   434,   435,
       0,     0,     0,     0,   810,     0,     0,     0,     0,     0,
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,     0,     0,   107,   422,   423,     0,     0,   108,
       0,     0,   424,   425,   426,   427,   428,   429,   430,   431,
       0,   109,   110,     0,     0,   111,     0,   112,     0,     0,
       0,     0,     0,     0,     0,   113,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,     0,   167,   168,   169,   170,
       0,   171,   172,     0,   173,   174,   175,     0,   176,   177,
     178,   179,   180,   181,   182,     0,     0,     0,     0,     0,
     183,   184,   185,     0,     0,     0,     0,     0,     0,   186,
     592,    90,    91,    92,     0,    93,    94,    95,    96,     0,
       0,     0,     0,     0,   432,   433,   434,   435,     0,     0,
       0,     0,   813,     0,     0,     0,     0,     0,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
       0,     0,   107,   422,   423,     0,     0,   108,     0,     0,
     424,   425,   426,   427,   428,   429,   430,   431,     0,   109,
     110,     0,     0,   111,     0,   112,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,     0,   167,   168,   169,   170,     0,   171,
     172,     0,   173,   174,   175,     0,   176,   177,   178,   179,
     180,   181,   182,     0,     0,     0,     0,     0,   183,   184,
     185,     0,     0,     0,     0,     0,     0,   186,   603,    90,
      91,    92,     0,    93,    94,    95,    96,     0,   271,     0,
       0,     0,   432,   433,   434,   435,     0,     0,     0,     0,
     816,     0,     0,     0,     0,     0,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   272,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,     0,     0,
     107,   422,   423,     0,     0,   108,     0,     0,   424,   425,
     426,   427,   428,   429,   430,   431,     0,   109,   110,     0,
       0,   111,     0,   112,     0,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,     0,   167,   168,   169,   170,     0,   171,   172,     0,
     173,   174,   175,     0,   176,   177,   178,   179,   180,   181,
     182,     0,     0,     0,     0,     0,   183,   184,   185,     0,
       0,     0,    90,    91,    92,   186,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     432,   433,   434,   435,     0,     0,     0,     0,   817,    97,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,     0,     0,   107,   422,   423,     0,     0,   108,     0,
       0,   424,   425,   426,   427,   428,   429,   430,   431,     0,
     109,   110,     0,     0,   111,     0,   112,     0,     0,     0,
       0,   332,   333,     0,   113,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,     0,   167,   168,   169,   170,     0,
     171,   172,     0,   173,   174,   175,     0,   176,   177,   178,
     179,   180,   181,   182,     0,     0,     0,     0,     0,   183,
     184,   185,     0,     0,     0,    90,    91,    92,   186,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   432,   433,   434,   435,     0,     0,     0,
       0,   819,    97,    98,     0,     0,   213,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,     0,     0,   107,   422,   423,     0,
       0,   108,     0,     0,   424,   425,   426,   427,   428,   429,
     430,   431,     0,   109,   110,     0,     0,   111,     0,   112,
       0,     0,     0,     0,     0,     0,     0,   113,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,     0,   167,   168,
     169,   170,     0,   171,   172,     0,   173,   174,   175,     0,
     176,   177,   178,   179,   180,   181,   182,     0,     0,     0,
       0,     0,   183,   184,   185,     0,     0,     0,    90,    91,
      92,   186,    93,    94,    95,    96,     0,   513,     0,     0,
       0,     0,     0,     0,     0,     0,   432,   433,   434,   435,
       0,     0,     0,     0,   820,    97,    98,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106,     0,     0,   107,
     422,   423,     0,     0,   108,     0,     0,   424,   425,   426,
     427,   428,   429,   430,   431,     0,   109,   110,     0,     0,
     111,     0,   112,     0,     0,     0,     0,     0,     0,     0,
     113,     0,     0,     0,     0,     0,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
       0,   167,   168,   169,   170,     0,   171,   172,     0,   173,
     174,   175,     0,   176,   177,   178,   179,   180,   181,   182,
       0,     0,     0,     0,     0,   183,   184,   185,     0,     0,
       0,    90,    91,    92,   186,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   432,
     433,   434,   435,     0,     0,     0,     0,   821,    97,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
       0,     0,   107,     0,     0,     0,     0,   108,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,    96,   109,
     110,     0,     0,   111,     0,   112,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,    98,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,     0,   167,   168,   169,   170,     0,   171,
     172,     0,   173,   174,   175,     0,   176,   177,   178,   179,
     180,   181,   182,   111,     0,   112,     0,     0,   183,   184,
     185,    92,     0,     0,     0,     0,    96,   186,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    98,     0,     0,
       0,     0,   136,   137,   138,     0,     0,     0,   142,   143,
     144,     0,   146,     0,   148,   149,   150,     0,     0,     0,
       0,   155,   156,   157,   158,   159,     0,     0,   162,     0,
     164,     0,   166,     0,     0,   168,     0,   170,     0,     0,
     172,     0,     0,   174,   175,     0,   176,   177,     0,   179,
       0,   181,     0,     0,     0,     0,     0,     0,    92,   184,
       0,     0,     0,    96,     0,     0,     0,   194,   616,     0,
       0,   111,     0,   112,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     136,   137,   138,     0,     0,     0,   142,   143,   144,     0,
     146,     0,   148,   149,   150,     0,     0,     0,     0,   155,
     156,   157,   158,   159,     0,     0,   162,     0,   164,     0,
     166,     0,     0,   168,     0,   170,     0,     0,   172,     0,
     736,   174,   175,     0,   176,   177,    92,   179,   111,   181,
     112,    96,     0,     0,     0,     0,     0,   184,     0,     0,
       0,     0,     0,     0,     0,   194,   618,     0,     0,     0,
       0,     0,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   136,   137,   138,
       0,     0,     0,   142,   143,   144,     0,   146,     0,   148,
     149,   150,     0,     0,     0,     0,   155,   156,   157,   158,
     159,     0,     0,   162,    92,   164,     0,   166,     0,    96,
     168,     0,   170,     0,     0,   172,     0,     0,   174,   175,
       0,   176,   177,     0,   179,     0,   181,     0,   976,     0,
      98,     0,     0,     0,   184,     0,   111,     0,   112,     0,
       0,     0,   194,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
       0,     0,     0,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   136,   137,   138,     0,     0,
       0,   142,   143,   144,    98,   146,     0,   148,   149,   150,
       0,     0,     0,     0,   155,   156,   157,   158,   159,     0,
       0,   162,     0,   164,   111,   166,   112,     0,   168,     0,
     170,     0,     0,   172,     0,     0,   174,   175,     0,   176,
     177,     0,   179,     0,   181,     0,     0,     0,     0,     0,
       0,     0,   184,     0,     0,     0,     0,     0,     0,     0,
     194,     0,     0,   136,   137,   138,     0,     0,     0,   142,
     143,   144,     0,   146,     0,   148,   149,   150,   111,     0,
     112,     0,   155,   156,   157,   158,   159,     0,     0,   162,
       0,   164,     0,   166,     0,     0,   168,     0,   170,     0,
       0,   172,     0,     0,   174,   175,     0,   176,   177,     0,
     179,     0,   181,     0,     0,     0,     0,   136,   137,   138,
     184,     0,     0,   142,   143,   144,     0,   146,   194,   148,
     149,   150,     0,     0,     0,     0,   155,   156,   157,   158,
     159,     0,     0,   162,     0,   164,     0,   166,     0,     0,
     168,     0,   170,     0,     0,   172,     0,     0,   174,   175,
       0,   176,   177,     0,   179,     0,   181,     0,     7,     8,
       9,     0,     0,     0,   184,    10,     0,     0,     0,    11,
       0,    12,   911,    13,    14,    15,    16,    17,  -355,     0,
      18,    19,    20,    21,    22,    23,    24,    25,     0,    26,
      27,    28,     0,     0,     0,     0,    29,     0,     0,    30,
       0,     0,     0,     0,     0,     0,    31,    32,    33,    34,
      35,    36,     0,     0,     0,    37,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,    41,    42,    43,    44,     0,     0,
       0,     0,     0,    45,    46,    47,  -137,  -137,    48,    49,
      50,     0,    51,    52,    53,     0,     0,    54,  -137,     0,
      55,     0,    56,    57,     0,     0,     0,     0,    58,    59,
       0,     0,   422,   423,     0,    60,     0,     0,     0,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    61,    62,
      63,     0,     0,     0,     0,    64,     0,     0,     0,     0,
     422,   423,     0,     0,     0,     0,     0,   424,   425,   426,
     427,   428,   429,   430,   431,    65,     0,     0,     0,    66,
       0,     7,     8,     9,    67,     0,     0,    68,    10,     0,
       0,    69,    11,     0,    12,     0,    13,    14,    15,    16,
      17,  -355,     0,    18,    19,    20,    21,    22,    23,    24,
      25,     0,    26,    27,    28,     0,     0,     0,     0,    29,
     -16,   -16,    30,     0,     0,     0,     0,     0,     0,    31,
      32,    33,    34,    35,    36,     0,     0,     0,    37,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    40,    41,    42,    43,
      44,   432,   433,   434,   435,     0,    45,    46,    47,   822,
       0,    48,    49,    50,     0,    51,    52,    53,     0,     0,
      54,     0,     0,    55,     0,    56,    57,     0,     0,     0,
       0,    58,    59,     0,     0,     0,     0,     0,    60,   432,
     433,   434,   435,     0,     0,     0,     0,   823,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    62,    63,     0,     0,     0,     0,    64,     0,
       0,     0,     0,   422,   423,     0,     0,     0,     0,     0,
     424,   425,   426,   427,   428,   429,   430,   431,    65,     0,
       0,     0,    66,     0,     7,     8,     9,    67,     0,     0,
      68,    10,     0,     0,    69,    11,     0,    12,     0,    13,
      14,    15,    16,    17,  -355,     0,    18,    19,    20,    21,
      22,    23,    24,    25,     0,    26,    27,    28,   -16,     0,
       0,     0,    29,   -16,     0,    30,     0,     0,     0,     0,
       0,     0,    31,    32,    33,    34,    35,    36,   422,   423,
       0,    37,    38,     0,     0,   424,   425,   426,   427,   428,
     429,   430,   431,     0,     0,     0,     0,     0,    39,    40,
      41,    42,    43,    44,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,    48,    49,    50,     0,    51,    52,
      53,     0,     0,    54,     0,     0,    55,     0,    56,    57,
       0,     0,     0,     0,    58,    59,     0,     0,     0,     0,
       0,    60,   432,   433,   434,   435,   422,   423,     0,     0,
     824,     0,     0,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,    61,    62,    63,   422,   423,     0,
       0,    64,     0,     0,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,     0,    66,     0,     0,     0,     0,
      67,   422,   423,    68,     0,     0,     0,    69,   424,   425,
     426,   427,   428,   429,   430,   431,     0,   432,   433,   434,
     435,   422,   423,     0,     0,   825,     0,     0,   424,   425,
     426,   427,   428,   429,   430,   431,   422,   423,     0,     0,
       0,     0,     0,   424,   425,   426,   427,   428,   429,   430,
     431,   422,   423,     0,     0,     0,     0,     0,   424,   425,
     426,   427,   428,   429,   430,   431,   422,   423,     0,     0,
       0,     0,     0,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,   433,   434,   435,   422,
     423,     0,     0,   827,     0,     0,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,   432,   433,   434,   435,
     422,   423,     0,     0,   838,     0,     0,   424,   425,   426,
     427,   428,   429,   430,   431,   422,   423,     0,     0,     0,
       0,     0,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   422,   423,     0,     0,   839,     0,
       0,   424,   425,   426,   427,   428,   429,   430,   431,     0,
     432,   433,   434,   435,     0,     0,     0,     0,   841,     0,
       0,     0,     0,     0,     0,   432,   433,   434,   435,     0,
       0,     0,     0,   844,     0,     0,     0,     0,     0,     0,
     432,   433,   434,   435,     0,     0,     0,     0,   868,     0,
       0,     0,     0,     0,     0,   432,   433,   434,   435,   422,
     423,     0,     0,   910,     0,     0,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,   433,
     434,   435,   422,   423,     0,     0,  1036,     0,     0,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,   432,
     433,   434,   435,     0,     0,     0,     0,  1068,     0,     0,
       0,     0,     0,     0,   432,   433,   434,   435,   422,   423,
       0,     0,  1069,     0,     0,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   422,   423,     0,
       0,  1076,     0,     0,   424,   425,   426,   427,   428,   429,
     430,   431,   422,   423,     0,     0,     0,     0,     0,   424,
     425,   426,   427,   428,   429,   430,   431,   422,   423,     0,
       0,     0,     0,     0,   424,   425,   426,   427,   428,   429,
     430,   431,   422,   423,     0,     0,     0,     0,     0,   424,
     425,   426,   427,   428,   429,   430,   431,     0,   432,   433,
     434,   435,   422,   423,     0,     0,  1077,     0,     0,   424,
     425,   426,   427,   428,   429,   430,   431,     0,     0,     0,
       0,   432,   433,   434,   435,   422,   423,     0,     0,  1078,
       0,     0,   424,   425,   426,   427,   428,   429,   430,   431,
     422,   423,     0,     0,     0,     0,     0,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,   432,   433,   434,
     435,   422,   423,     0,     0,  1079,     0,     0,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   435,
       0,     0,     0,     0,  1080,     0,     0,     0,     0,     0,
       0,   432,   433,   434,   435,     0,     0,     0,     0,  1085,
       0,     0,     0,     0,     0,     0,   432,   433,   434,   435,
       0,     0,     0,     0,  1086,     0,     0,     0,     0,     0,
       0,   432,   433,   434,   435,   422,   423,     0,     0,  1090,
       0,     0,   424,   425,   426,   427,   428,   429,   430,   431,
       0,   432,   433,   434,   435,   422,   423,     0,     0,  1091,
       0,     0,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,     0,     0,   432,   433,   434,   435,     0,     0,
       0,     0,  1092,     0,     0,     0,     0,     0,     0,   432,
     433,   434,   435,   422,   423,     0,     0,  1093,     0,     0,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
     432,   433,   434,   435,   422,   423,     0,     0,  1094,     0,
       0,   424,   425,   426,   427,   428,   429,   430,   431,   422,
     423,     0,     0,     0,     0,     0,   424,   425,   426,   427,
     428,   429,   430,   431,   422,   423,     0,     0,     0,     0,
       0,   424,   425,   426,   427,   428,   429,   430,   431,   422,
     423,     0,     0,     0,     0,     0,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   422,   423,
       0,     0,  1097,     0,     0,   424,   425,   426,   427,   428,
     429,   430,   431,     0,   432,   433,   434,   435,   422,   423,
       0,     0,  1098,     0,     0,   424,   425,   426,   427,   428,
     429,   430,   431,   422,   423,     0,     0,     0,     0,     0,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,   433,   434,   435,   422,   423,     0,     0,
    1101,     0,     0,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,   432,   433,   434,   435,     0,     0,     0,
       0,  1109,     0,     0,     0,     0,     0,     0,   432,   433,
     434,   435,     0,     0,     0,     0,  1112,     0,     0,     0,
       0,     0,     0,   432,   433,   434,   435,     0,     0,     0,
       0,  1127,     0,     0,     0,     0,     0,     0,   432,   433,
     434,   435,   422,   423,     0,     0,  1189,     0,     0,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   422,   423,     0,     0,  1193,     0,     0,   424,   425,
     426,   427,   428,   429,   430,   431,     0,   432,   433,   434,
     435,     0,     0,     0,     0,  1215,     0,     0,     0,     0,
       0,     0,   432,   433,   434,   435,   422,   423,     0,     0,
    1224,     0,     0,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,   433,   434,   435,   422,
     423,     0,     0,  1227,     0,     0,   424,   425,   426,   427,
     428,   429,   430,   431,   422,   423,     0,     0,     0,     0,
       0,   424,   425,   426,   427,   428,   429,   430,   431,   422,
     423,     0,     0,     0,     0,     0,   424,   425,   426,   427,
     428,   429,   430,   431,   422,   423,     0,     0,     0,     0,
       0,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,   432,   433,   434,   435,   422,   423,     0,     0,  1228,
       0,     0,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   422,   423,     0,     0,  1230,     0,
       0,   424,   425,   426,   427,   428,   429,   430,   431,   422,
     423,     0,     0,     0,     0,     0,   424,   425,   426,   427,
     428,   429,   430,   431,     0,   432,   433,   434,   435,   422,
     423,     0,     0,  1247,     0,     0,   424,   425,   426,   427,
     428,   429,   430,   431,     0,     0,     0,     0,   432,   433,
     434,   435,     0,     0,     0,     0,  1289,     0,     0,     0,
       0,     0,     0,   432,   433,   434,   435,     0,     0,     0,
       0,  1302,     0,     0,     0,     0,     0,     0,   432,   433,
     434,   435,     0,     0,     0,     0,  1327,     0,     0,     0,
       0,     0,     0,   432,   433,   434,   435,   422,   423,     0,
       0,  1338,     0,     0,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,   432,   433,   434,   435,   422,   423,
       0,     0,  1349,     0,     0,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,     0,     0,   487,
       0,     0,     0,     0,     0,     0,     0,     0,   432,   433,
     434,   435,   422,   423,   488,     0,     0,     0,     0,   424,
     425,   426,   427,   428,   429,   430,   431,     0,   432,   433,
     434,   435,   422,   423,   505,     0,     0,     0,     0,   424,
     425,   426,   427,   428,   429,   430,   431,   422,   423,     0,
       0,     0,     0,     0,   424,   425,   426,   427,   428,   429,
     430,   431,   422,   423,     0,     0,     0,     0,     0,   424,
     425,   426,   427,   428,   429,   430,   431,   422,   423,     0,
       0,     0,     0,     0,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,   433,   434,   435,
     422,   423,   733,     0,     0,     0,     0,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,   432,   433,   434,
     435,   422,   423,   784,     0,     0,     0,     0,   424,   425,
     426,   427,   428,   429,   430,   431,   422,   423,     0,     0,
       0,     0,     0,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   422,   423,   785,     0,     0,
       0,     0,   424,   425,   426,   427,   428,   429,   430,   431,
       0,   432,   433,   434,   435,     0,     0,   787,     0,     0,
       0,     0,     0,     0,     0,     0,   432,   433,   434,   435,
       0,     0,   788,     0,     0,     0,     0,     0,     0,     0,
       0,   432,   433,   434,   435,     0,     0,   789,     0,     0,
       0,     0,     0,     0,     0,     0,   432,   433,   434,   435,
     422,   423,   803,     0,     0,     0,     0,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
     433,   434,   435,   422,   423,   826,     0,     0,     0,     0,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
     432,   433,   434,   435,     0,     0,   833,     0,     0,     0,
       0,     0,     0,     0,     0,   432,   433,   434,   435,   422,
     423,   834,     0,     0,     0,     0,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   422,   423,
     854,     0,     0,     0,     0,   424,   425,   426,   427,   428,
     429,   430,   431,   422,   423,     0,     0,     0,     0,     0,
     424,   425,   426,   427,   428,   429,   430,   431,   422,   423,
       0,     0,     0,     0,     0,   424,   425,   426,   427,   428,
     429,   430,   431,   422,   423,     0,     0,     0,     0,     0,
     424,   425,   426,   427,   428,   429,   430,   431,     0,   432,
     433,   434,   435,   422,   423,   906,     0,     0,     0,     0,
     424,   425,   426,   427,   428,   429,   430,   431,     0,     0,
       0,     0,   432,   433,   434,   435,   422,   423,   929,     0,
       0,     0,     0,   424,   425,   426,   427,   428,   429,   430,
     431,   422,   423,     0,     0,     0,     0,     0,   424,   425,
     426,   427,   428,   429,   430,   431,     0,     0,   432,   433,
     434,   435,   422,   423,   930,     0,     0,     0,     0,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,     0,     0,   937,     0,     0,     0,     0,     0,     0,
       0,     0,   432,   433,   434,   435,     0,     0,   942,     0,
       0,     0,     0,     0,     0,     0,     0,   432,   433,   434,
     435,     0,     0,   943,     0,     0,     0,     0,     0,     0,
       0,     0,   432,   433,   434,   435,   422,   423,   963,     0,
       0,     0,     0,   424,   425,   426,   427,   428,   429,   430,
     431,     0,   432,   433,   434,   435,   422,   423,   964,     0,
       0,     0,     0,   424,   425,   426,   427,   428,   429,   430,
     431,     0,     0,     0,     0,   432,   433,   434,   435,     0,
       0,  1025,     0,     0,     0,     0,     0,     0,     0,     0,
     432,   433,   434,   435,   422,   423,  1030,     0,     0,     0,
       0,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,   432,   433,   434,   435,   422,   423,  1044,     0,     0,
       0,     0,   424,   425,   426,   427,   428,   429,   430,   431,
     422,   423,     0,     0,     0,     0,     0,   424,   425,   426,
     427,   428,   429,   430,   431,   422,   423,     0,     0,     0,
       0,     0,   424,   425,   426,   427,   428,   429,   430,   431,
     422,   423,     0,     0,     0,     0,     0,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   422,
     423,  1056,     0,     0,     0,     0,   424,   425,   426,   427,
     428,   429,   430,   431,     0,   432,   433,   434,   435,   422,
     423,  1061,     0,     0,     0,     0,   424,   425,   426,   427,
     428,   429,   430,   431,   422,   423,     0,     0,     0,     0,
       0,   424,   425,   426,   427,   428,   429,   430,   431,     0,
       0,     0,     0,   432,   433,   434,   435,   422,   423,  1062,
       0,     0,     0,     0,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,   432,   433,   434,   435,     0,     0,
    1063,     0,     0,     0,     0,     0,     0,     0,     0,   432,
     433,   434,   435,     0,     0,  1110,     0,     0,     0,     0,
       0,     0,     0,     0,   432,   433,   434,   435,     0,     0,
    1111,     0,     0,     0,     0,     0,     0,     0,     0,   432,
     433,   434,   435,   422,   423,  1133,     0,     0,     0,     0,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   422,   423,  1147,     0,     0,     0,     0,   424,
     425,   426,   427,   428,   429,   430,   431,     0,   432,   433,
     434,   435,     0,     0,  1208,     0,     0,     0,     0,     0,
       0,     0,     0,   432,   433,   434,   435,   422,   423,  1209,
       0,     0,     0,     0,   424,   425,   426,   427,   428,   429,
     430,   431,     0,     0,     0,     0,   432,   433,   434,   435,
     422,   423,  1210,     0,     0,     0,     0,   424,   425,   426,
     427,   428,   429,   430,   431,   422,   423,     0,     0,     0,
       0,     0,   424,   425,   426,   427,   428,   429,   430,   431,
     422,   423,     0,     0,     0,     0,     0,   424,   425,   426,
     427,   428,   429,   430,   431,   422,   423,     0,     0,     0,
       0,     0,   424,   425,   426,   427,   428,   429,   430,   431,
       0,     0,   432,   433,   434,   435,   422,   423,  1212,     0,
       0,     0,     0,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   422,   423,  1223,     0,     0,
       0,     0,   424,   425,   426,   427,   428,   429,   430,   431,
     422,   423,     0,     0,     0,     0,     0,   424,   425,   426,
     427,   428,   429,   430,   431,     0,   432,   433,   434,   435,
     422,   423,  1242,     0,     0,     0,     0,   424,   425,   426,
     427,   428,   429,   430,   431,     0,     0,     0,     0,   432,
     433,   434,   435,     0,     0,  1281,     0,     0,     0,     0,
       0,     0,     0,     0,   432,   433,   434,   435,     0,     0,
    1283,     0,     0,     0,     0,     0,     0,     0,     0,   432,
     433,   434,   435,     0,     0,  1284,     0,     0,     0,     0,
       0,     0,     0,     0,   432,   433,   434,   435,     0,     0,
    1286,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   432,   433,   434,   435,     0,
       0,  1301,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   432,   433,   434,   435,     0,     0,
    1326,     0,     0,     0,     0,     0,     0,     0,     0,   432,
     433,   434,   435,     0,     0,  1328,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   432,
     433,   434,   435
};

static const yytype_int16 yycheck[] =
{
       3,   207,     1,    15,    16,     4,   285,   286,     1,   288,
     335,     4,    77,    44,     4,    43,    44,     7,    21,   225,
      28,    24,    40,   302,     4,    33,    11,     7,    12,    41,
      33,    75,  1136,    75,    37,    38,    77,     4,    66,    42,
       7,   203,    58,    12,    60,    61,   208,     4,     5,   304,
     305,    54,    55,    56,    53,   208,    58,   210,    60,    61,
      53,   918,   919,    66,    67,    68,    69,    23,    12,     3,
      16,     4,     5,     7,     8,     9,    10,     3,    59,     4,
       5,     7,     8,     9,    10,    70,    71,    72,    73,    74,
      75,    76,    81,    82,    25,    12,     4,     5,    44,    88,
      70,    71,    72,    73,    74,    75,    76,   203,    89,    90,
      91,     0,   208,    44,   210,    96,   203,     7,    13,    63,
      64,   208,   111,   210,    92,    93,    70,    71,    72,    73,
      74,    75,    76,    77,   203,    95,   104,   202,   203,   204,
     205,   210,  1246,   100,   110,  1249,    63,    64,   208,   404,
     210,   406,    28,    70,    71,    72,    73,    74,    75,    76,
      77,   112,   113,   204,   205,   209,   203,   209,    63,    64,
     209,  1275,   203,   210,  1278,    70,    71,    72,    73,    74,
      75,    76,    77,   186,    75,    76,    77,   144,   145,   146,
     203,   194,    76,    77,   203,   211,    44,   210,   209,   208,
     203,    70,    71,    72,    73,    74,    75,    76,   207,   211,
      75,   144,   145,   146,   207,   209,   219,   209,   203,   209,
     203,   224,   501,   209,   208,   208,   225,   210,   231,   209,
     248,   249,   225,   203,   203,   514,  1340,    75,  1342,   208,
     519,    24,   521,    44,   523,   524,   202,  1351,   204,  1353,
     529,   530,   255,   195,   196,   197,   198,   199,   202,   203,
     204,   205,   468,   266,   267,   268,   545,   546,   202,   203,
      14,    14,    16,    16,    18,    18,   202,   203,   112,   203,
    1137,   209,   203,  1140,   208,   202,   203,   204,   205,   210,
     569,   208,   203,   296,   297,    20,    21,    41,    41,   210,
      44,    44,   330,   331,   307,    49,    49,   202,   203,   204,
     205,   202,   203,   204,   205,   208,   319,   210,   202,   203,
     204,   205,   350,    74,    75,    76,    77,   330,   203,   332,
     208,     4,   210,   208,   203,   338,   339,   203,    63,    64,
    1197,   210,   208,    44,   210,    70,    71,    72,    73,    74,
      75,    76,    77,   208,   203,   210,   209,   360,   361,   362,
     363,   364,   390,   203,   367,   321,   322,   370,   208,   372,
     210,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     209,   384,   385,   386,   387,   388,   389,   390,   391,     4,
       5,   394,   203,   396,   397,   398,   399,   400,   203,   210,
     403,   203,   405,   208,   407,   408,   409,    58,   210,   209,
     413,   414,   415,   416,   417,   418,   419,   420,   209,    51,
    1277,    35,    36,  1280,    70,    71,    72,    73,    74,    75,
      76,    63,    64,     4,     5,   209,   392,   393,    70,    71,
      72,    73,    74,    75,    76,    77,  1303,   209,   203,  1306,
     209,   202,   203,   204,   205,   210,   209,     3,     4,     5,
     209,     7,     8,     9,    10,   203,   203,   203,   471,   468,
     208,   208,   678,   210,   210,   468,   494,   202,   203,   204,
     205,   203,   203,   209,    30,    31,   208,   208,   210,   210,
     203,  1348,   209,  1350,   209,   208,   499,   210,  1355,  1356,
     209,    70,    71,    72,    73,    74,    75,    76,   511,   209,
     203,   209,    14,   209,    16,   208,    18,    63,    64,    65,
      66,    67,    68,    69,   203,   203,     4,     5,   484,   485,
     208,   210,   210,   489,   490,    81,   539,   540,    84,    41,
     209,   203,    44,    89,   203,   203,   208,    49,   210,   208,
     875,    97,   210,   878,   209,   101,   102,   203,   203,   105,
     203,   107,   208,   208,   110,   210,   208,   210,   203,   115,
     202,   203,   204,   205,   208,   210,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   209,
     176,   177,   178,   179,   203,   181,   182,   209,   184,   185,
     186,   210,   188,   189,   190,   191,   192,   193,   194,    73,
      74,    75,    76,    77,   200,   201,   202,    14,   209,    16,
     203,    18,   209,   209,   203,   211,   203,   210,   209,   948,
     208,   210,   951,   210,   686,   687,   203,   956,   209,   678,
     209,   207,   208,   210,    41,   678,   203,    44,   967,    44,
      63,   694,    49,   210,     4,     5,   902,    70,    71,    72,
      73,    74,    75,    76,    77,   984,   203,   710,    63,    64,
     713,   208,   208,   716,   209,    70,    71,    72,    73,    74,
      75,    76,    77,    70,    71,    72,    73,    74,    75,    76,
     209,    46,   688,   689,   203,   691,   692,   740,   203,    47,
      48,   210,    86,    87,   208,   210,   203,   750,    63,    64,
      58,   754,    60,   210,   757,    70,    71,    72,    73,    74,
      75,    76,    77,     4,     5,    49,    50,   209,    71,    46,
      73,    74,    75,    76,    77,   209,   775,   203,   202,   203,
     204,   205,   775,   208,   210,   208,    63,    64,   791,   209,
     793,   209,   795,    70,    71,    72,    73,    74,    75,    76,
      77,   804,   203,    63,    64,     4,     5,   763,    43,   210,
      70,    71,    72,    73,    74,    75,    76,    77,    70,    71,
      72,    73,    74,    75,    76,    39,    40,     4,     5,   202,
     203,   204,   205,   836,    71,    72,    73,    74,    75,    76,
      77,   203,    60,    61,    60,    61,   208,   202,   203,   204,
     205,   854,   855,   856,   857,   203,   203,    63,    64,   209,
     863,   208,   210,   210,    70,    71,    72,    73,    74,    75,
      76,    77,   203,   876,   203,  1154,   879,   208,   881,  1158,
       5,   210,   209,   209,    63,    64,   209,   202,   203,   204,
     205,    70,    71,    72,    73,    74,    75,    76,    77,   202,
     203,   204,   205,   902,   209,   908,   934,   935,   911,   902,
      70,    71,    72,    73,    74,    75,    76,    77,   209,   209,
     209,   209,   203,   203,   203,   202,   203,   204,   205,   210,
     210,   210,   203,   936,   937,   209,   209,   940,   210,   210,
     203,   944,   202,   203,   204,   205,   203,   210,   208,   203,
     210,   203,   203,   210,   209,   958,   210,   265,   210,   210,
     963,   964,   209,   271,   209,   202,   203,   204,   205,   277,
     278,   927,   928,   203,   203,   209,   209,  1183,  1184,   208,
     210,   289,   290,   291,   292,   293,   294,   295,   203,   209,
     298,   299,   300,   301,   203,   210,   202,   203,   204,   205,
     210,   210,  1014,  1015,   210,   203,   203,   315,   316,   317,
       3,   203,   210,   210,     7,     8,     9,  1020,   210,   209,
     209,   209,   203,   202,   203,   204,   205,   208,   336,  1032,
     203,   210,  1238,   203,     2,   208,    77,   209,   208,   210,
     209,  1044,   202,   203,   204,   205,  1049,  1050,   209,    17,
     209,   209,  1055,  1056,   203,  1058,  1059,   209,  1264,   208,
     210,  1267,    30,   209,   209,    33,   203,   203,    36,    37,
      38,   208,   208,   203,    42,    43,    44,   209,   208,   203,
    1083,  1037,  1038,    51,   208,  1291,  1089,   203,   203,   203,
     203,   209,   208,   208,   208,   208,  1099,   203,    66,   203,
    1103,   203,   208,    75,   208,   208,   208,  1110,    63,    64,
    1113,   209,   209,  1116,   209,    70,    71,    72,    73,    74,
      75,    76,    77,   209,   203,   209,   209,   209,  1131,   208,
      43,   209,   209,   101,   209,   209,   209,   209,   209,   209,
     209,   209,   209,  1146,  1147,  1148,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,  1160,  1161,   209,
    1163,    63,    64,   209,   209,   209,   209,   209,    70,    71,
      72,    73,    74,    75,    76,    77,   208,   208,    46,   209,
     209,    58,   209,    10,  1183,  1184,   208,   208,   208,   208,
    1183,  1184,   208,   210,   209,   208,   208,   208,   208,  1202,
     208,   210,   510,  1206,   210,   513,  1209,   210,   209,   517,
     209,    43,   210,   210,   208,   210,   208,   185,   186,   210,
     210,   210,   209,   531,   210,   210,   209,   209,    85,   210,
     210,    85,   208,   201,   208,   210,     5,  1240,   206,  1238,
     210,   208,   208,    58,   209,  1238,   210,   202,   203,   204,
     205,   219,   210,   208,   210,   210,   224,  1260,   210,   209,
     208,   208,   208,   231,   208,  1264,   208,   210,  1267,   209,
      43,  1264,   210,  1276,  1267,   210,    38,    43,   209,  1282,
    1283,    58,  1285,  1286,   210,   210,   254,    75,   256,    75,
      75,    48,  1291,    58,   209,   209,  1299,   209,  1291,   210,
     202,   203,   204,   205,   210,   208,   208,    47,   210,   209,
     209,    58,    75,   210,   210,    38,   209,   209,   208,   208,
    1323,     4,     4,   775,    53,  1328,    53,   494,   335,   694,
       5,   690,    63,    64,  1220,   693,  1020,   491,   306,    70,
      71,    72,    73,    74,    75,    76,    77,   914,  1336,    -1,
     318,   507,    -1,    -1,    -1,   323,   324,    -1,   326,   327,
     328,   329,   330,   331,    -1,    -1,    -1,    -1,    -1,   337,
      -1,    -1,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,    -1,    -1,    -1,    -1,    -1,   365,   366,   367,
     368,   369,    -1,   371,    -1,   373,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   383,    -1,    -1,    -1,    -1,
      -1,    -1,   390,    -1,    -1,    -1,    -1,   395,    -1,    -1,
      -1,   739,    -1,    -1,    -1,    -1,    -1,    -1,   746,    -1,
      -1,    -1,    -1,   751,    -1,   753,    -1,   755,   756,    -1,
      -1,    -1,   760,   761,    -1,    -1,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,    -1,   777,
     778,   202,   203,   204,   205,    -1,    -1,   208,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   802,    -1,    -1,    -1,     3,     4,
       5,   469,     7,     8,     9,    10,   474,    -1,    -1,    -1,
      -1,    -1,    -1,    90,    91,    92,    93,    94,    -1,   487,
     488,    -1,    -1,    -1,    -1,    30,    31,   104,    -1,    -1,
      -1,    -1,   500,   110,   111,    -1,    -1,   505,    -1,   116,
     117,   118,   119,   120,    -1,    -1,    -1,   515,   516,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,   539,   540,   541,   542,    -1,    81,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    97,    -1,    -1,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,   176,   177,   178,   179,    -1,   181,   182,    -1,   184,
     185,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,   661,   662,   200,   201,   202,    -1,    -1,
      -1,    -1,    -1,    -1,   209,    -1,   211,    -1,    63,    64,
      -1,    -1,    -1,   681,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,   694,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   707,
      -1,    -1,    -1,    -1,    -1,   713,   714,    -1,    -1,  1057,
      -1,   719,  1060,    -1,    -1,    -1,  1064,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   733,  1074,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   752,    -1,    -1,    -1,    -1,   757,
     758,   759,    -1,    -1,    -1,    -1,   764,   765,   766,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   776,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   784,   785,    -1,   787,
     788,   789,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,   800,   801,    -1,   803,    10,    -1,    -1,    -1,
      -1,    -1,    -1,   811,    -1,    -1,   814,   202,   203,   204,
     205,    -1,    -1,   208,    -1,   210,    -1,    31,   826,    -1,
      -1,   829,   830,   831,    -1,   833,   834,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   842,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,  1207,
      -1,    -1,   870,  1211,   872,   873,   874,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,   886,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,   906,    -1,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,   916,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,   929,   930,    -1,    -1,    -1,   934,   935,    -1,    -1,
     144,   145,   146,    -1,   942,   943,   150,   151,   152,    -1,
     154,    -1,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,    -1,    -1,   170,    -1,   172,    -1,
     174,    -1,    -1,   177,    -1,   179,    -1,    -1,   182,    -1,
      -1,   185,   186,    -1,   188,   189,    -1,   191,    -1,   193,
      -1,   202,   203,   204,   205,    -1,    -1,   201,     5,   210,
      -1,    -1,    -1,    10,    -1,   209,   210,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1020,    -1,    31,    -1,    -1,  1025,    -1,    -1,
      -1,    -1,  1030,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,  1061,  1062,  1063,    -1,  1065,    -1,    -1,
      -1,    -1,  1070,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1088,    -1,    -1,    -1,    -1,    -1,    -1,  1095,   105,    -1,
     107,    -1,    -1,    -1,    -1,    -1,  1104,    -1,  1106,    -1,
      -1,    -1,    -1,  1111,    -1,    -1,    -1,    63,    64,    -1,
      -1,    -1,  1120,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,  1130,    -1,    -1,  1133,    -1,   144,   145,   146,
      -1,    -1,    -1,   150,   151,   152,    -1,   154,    -1,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,    -1,    -1,   170,    -1,   172,  1164,   174,    -1,    -1,
     177,    -1,   179,    -1,    -1,   182,    -1,    -1,   185,   186,
      -1,   188,   189,    -1,   191,    -1,   193,  1185,    -1,    -1,
      -1,    -1,    -1,    -1,   201,    -1,    -1,    -1,  1196,    -1,
      -1,    -1,   209,   210,    -1,    -1,    -1,    -1,    -1,    -1,
    1208,    -1,  1210,    -1,  1212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1223,    -1,     3,     4,     5,
      -1,     7,     8,     9,    10,  1233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1241,  1242,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1279,    -1,  1281,    -1,    -1,  1284,    63,    64,    65,
      66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1301,    -1,    81,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    97,    -1,    -1,    -1,   101,   102,    -1,  1326,   105,
      -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,   177,   178,   179,    -1,   181,   182,    -1,   184,   185,
     186,    -1,   188,   189,   190,   191,   192,   193,   194,    -1,
      -1,    -1,    -1,    -1,   200,   201,   202,    -1,    -1,    -1,
      -1,    -1,    -1,   209,    -1,   211,     3,     4,     5,    -1,
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
      -1,    -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   176,
     177,   178,   179,    -1,   181,   182,    -1,   184,   185,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,    -1,   200,   201,   202,    -1,    -1,    -1,    -1,
      -1,    -1,   209,    -1,   211,     3,     4,     5,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,
      -1,    89,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,   177,
     178,   179,    -1,   181,   182,    -1,   184,   185,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,    -1,   200,   201,   202,    -1,    -1,    -1,    -1,    -1,
      -1,   209,   210,     3,     4,     5,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,   177,   178,   179,
      -1,   181,   182,    -1,   184,   185,   186,    -1,   188,   189,
     190,   191,   192,   193,   194,    -1,    -1,    -1,    -1,    -1,
     200,   201,   202,    -1,    -1,    -1,    -1,    -1,    -1,   209,
     210,     3,     4,     5,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,   202,   203,   204,   205,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,   177,   178,   179,    -1,   181,
     182,    -1,   184,   185,   186,    -1,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,    -1,    -1,    -1,   200,   201,
     202,    -1,    -1,    -1,    -1,    -1,    -1,   209,   210,     3,
       4,     5,    -1,     7,     8,     9,    10,    -1,    12,    -1,
      -1,    -1,   202,   203,   204,   205,    -1,    -1,    -1,    -1,
     210,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      84,    63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   101,   102,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,   177,   178,   179,    -1,   181,   182,    -1,
     184,   185,   186,    -1,   188,   189,   190,   191,   192,   193,
     194,    -1,    -1,    -1,    -1,    -1,   200,   201,   202,    -1,
      -1,    -1,     3,     4,     5,   209,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    68,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    84,    63,    64,    -1,    -1,    89,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     101,   102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,
      -1,   112,   113,    -1,   115,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,   177,   178,   179,    -1,
     181,   182,    -1,   184,   185,   186,    -1,   188,   189,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,    -1,   200,
     201,   202,    -1,    -1,    -1,     3,     4,     5,   209,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    30,    31,    -1,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    81,    -1,    -1,    84,    63,    64,    -1,
      -1,    89,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,   101,   102,    -1,    -1,   105,    -1,   107,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,   177,
     178,   179,    -1,   181,   182,    -1,   184,   185,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,    -1,    -1,    -1,
      -1,    -1,   200,   201,   202,    -1,    -1,    -1,     3,     4,
       5,   209,     7,     8,     9,    10,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    84,
      63,    64,    -1,    -1,    89,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   101,   102,    -1,    -1,
     105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,   176,   177,   178,   179,    -1,   181,   182,    -1,   184,
     185,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
      -1,    -1,    -1,    -1,    -1,   200,   201,   202,    -1,    -1,
      -1,     3,     4,     5,   209,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    10,   101,
     102,    -1,    -1,   105,    -1,   107,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,    31,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,   177,   178,   179,    -1,   181,
     182,    -1,   184,   185,   186,    -1,   188,   189,   190,   191,
     192,   193,   194,   105,    -1,   107,    -1,    -1,   200,   201,
     202,     5,    -1,    -1,    -1,    -1,    10,   209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,   144,   145,   146,    -1,    -1,    -1,   150,   151,
     152,    -1,   154,    -1,   156,   157,   158,    -1,    -1,    -1,
      -1,   163,   164,   165,   166,   167,    -1,    -1,   170,    -1,
     172,    -1,   174,    -1,    -1,   177,    -1,   179,    -1,    -1,
     182,    -1,    -1,   185,   186,    -1,   188,   189,    -1,   191,
      -1,   193,    -1,    -1,    -1,    -1,    -1,    -1,     5,   201,
      -1,    -1,    -1,    10,    -1,    -1,    -1,   209,   210,    -1,
      -1,   105,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     144,   145,   146,    -1,    -1,    -1,   150,   151,   152,    -1,
     154,    -1,   156,   157,   158,    -1,    -1,    -1,    -1,   163,
     164,   165,   166,   167,    -1,    -1,   170,    -1,   172,    -1,
     174,    -1,    -1,   177,    -1,   179,    -1,    -1,   182,    -1,
      97,   185,   186,    -1,   188,   189,     5,   191,   105,   193,
     107,    10,    -1,    -1,    -1,    -1,    -1,   201,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   209,   210,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,   146,
      -1,    -1,    -1,   150,   151,   152,    -1,   154,    -1,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,    -1,    -1,   170,     5,   172,    -1,   174,    -1,    10,
     177,    -1,   179,    -1,    -1,   182,    -1,    -1,   185,   186,
      -1,   188,   189,    -1,   191,    -1,   193,    -1,    97,    -1,
      31,    -1,    -1,    -1,   201,    -1,   105,    -1,   107,    -1,
      -1,    -1,   209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   144,   145,   146,    -1,    -1,
      -1,   150,   151,   152,    31,   154,    -1,   156,   157,   158,
      -1,    -1,    -1,    -1,   163,   164,   165,   166,   167,    -1,
      -1,   170,    -1,   172,   105,   174,   107,    -1,   177,    -1,
     179,    -1,    -1,   182,    -1,    -1,   185,   186,    -1,   188,
     189,    -1,   191,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,    -1,    -1,   144,   145,   146,    -1,    -1,    -1,   150,
     151,   152,    -1,   154,    -1,   156,   157,   158,   105,    -1,
     107,    -1,   163,   164,   165,   166,   167,    -1,    -1,   170,
      -1,   172,    -1,   174,    -1,    -1,   177,    -1,   179,    -1,
      -1,   182,    -1,    -1,   185,   186,    -1,   188,   189,    -1,
     191,    -1,   193,    -1,    -1,    -1,    -1,   144,   145,   146,
     201,    -1,    -1,   150,   151,   152,    -1,   154,   209,   156,
     157,   158,    -1,    -1,    -1,    -1,   163,   164,   165,   166,
     167,    -1,    -1,   170,    -1,   172,    -1,   174,    -1,    -1,
     177,    -1,   179,    -1,    -1,   182,    -1,    -1,   185,   186,
      -1,   188,   189,    -1,   191,    -1,   193,    -1,     4,     5,
       6,    -1,    -1,    -1,   201,    11,    -1,    -1,    -1,    15,
      -1,    17,   209,    19,    20,    21,    22,    23,    24,    -1,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    42,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91,    92,    93,    94,    95,
      96,    -1,    98,    99,   100,    -1,    -1,   103,   104,    -1,
     106,    -1,   108,   109,    -1,    -1,    -1,    -1,   114,   115,
      -1,    -1,    63,    64,    -1,   121,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,   171,    -1,    -1,    -1,   175,
      -1,     4,     5,     6,   180,    -1,    -1,   183,    11,    -1,
      -1,   187,    15,    -1,    17,    -1,    19,    20,    21,    22,
      23,    24,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    36,    37,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    61,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,    82,
      83,   202,   203,   204,   205,    -1,    89,    90,    91,   210,
      -1,    94,    95,    96,    -1,    98,    99,   100,    -1,    -1,
     103,    -1,    -1,   106,    -1,   108,   109,    -1,    -1,    -1,
      -1,   114,   115,    -1,    -1,    -1,    -1,    -1,   121,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,   145,   146,    -1,    -1,    -1,    -1,   151,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,   171,    -1,
      -1,    -1,   175,    -1,     4,     5,     6,   180,    -1,    -1,
     183,    11,    -1,    -1,   187,    15,    -1,    17,    -1,    19,
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
      -1,   121,   202,   203,   204,   205,    63,    64,    -1,    -1,
     210,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,   144,   145,   146,    63,    64,    -1,
      -1,   151,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,
     180,    63,    64,   183,    -1,    -1,    -1,   187,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   202,   203,   204,
     205,    63,    64,    -1,    -1,   210,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,   202,   203,   204,   205,    63,
      64,    -1,    -1,   210,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,   202,   203,   204,   205,
      63,    64,    -1,    -1,   210,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
     202,   203,   204,   205,    63,    64,    -1,    -1,   210,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,    -1,
      -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,    63,
      64,    -1,    -1,   210,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,   202,   203,
     204,   205,    63,    64,    -1,    -1,   210,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,   202,
     203,   204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   203,   204,   205,    63,    64,
      -1,    -1,   210,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,   202,   203,   204,   205,    63,    64,    -1,
      -1,   210,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   202,   203,
     204,   205,    63,    64,    -1,    -1,   210,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,    -1,    -1,
      -1,   202,   203,   204,   205,    63,    64,    -1,    -1,   210,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   202,   203,   204,
     205,    63,    64,    -1,    -1,   210,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   203,   204,   205,    -1,    -1,    -1,    -1,   210,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,
      -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   203,   204,   205,    63,    64,    -1,    -1,   210,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   202,   203,   204,   205,    63,    64,    -1,    -1,   210,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    -1,   202,   203,   204,   205,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,    63,    64,    -1,    -1,   210,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     202,   203,   204,   205,    63,    64,    -1,    -1,   210,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   202,   203,   204,   205,    63,    64,
      -1,    -1,   210,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,   202,   203,   204,   205,    63,    64,
      -1,    -1,   210,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,   202,   203,   204,   205,    63,    64,    -1,    -1,
     210,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,
     204,   205,    63,    64,    -1,    -1,   210,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   202,   203,   204,
     205,    63,    64,    -1,    -1,   210,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,   202,   203,   204,
     205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   203,   204,   205,    63,    64,    -1,    -1,
     210,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,   202,   203,   204,   205,    63,
      64,    -1,    -1,   210,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,   202,   203,   204,   205,    63,    64,    -1,    -1,   210,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
     202,   203,   204,   205,    63,    64,    -1,    -1,   210,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   202,   203,   204,   205,    63,
      64,    -1,    -1,   210,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   203,   204,   205,    -1,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,
     204,   205,    -1,    -1,    -1,    -1,   210,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   203,   204,   205,    63,    64,    -1,
      -1,   210,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   202,   203,   204,   205,    63,    64,
      -1,    -1,   210,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,   202,   203,   204,   205,    -1,    -1,   208,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,
     204,   205,    63,    64,   208,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   202,   203,
     204,   205,    63,    64,   208,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,   202,   203,   204,   205,
      63,    64,   208,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,   202,   203,   204,
     205,    63,    64,   208,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,   202,   203,   204,   205,    63,    64,   208,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,   202,   203,   204,   205,    -1,    -1,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,
      -1,    -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   203,   204,   205,    -1,    -1,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,
      63,    64,   208,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,    63,    64,   208,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
     202,   203,   204,   205,    -1,    -1,   208,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,    63,
      64,   208,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,   202,   203,   204,   205,    63,    64,
     208,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    63,    64,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,
      75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,   202,
     203,   204,   205,    63,    64,   208,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    -1,   202,   203,   204,   205,    63,    64,   208,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,   202,   203,
     204,   205,    63,    64,   208,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,   202,   203,   204,
     205,    -1,    -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   203,   204,   205,    -1,    -1,   208,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,
     205,    -1,    -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   203,   204,   205,    63,    64,   208,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,   202,   203,   204,   205,    63,    64,   208,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,   202,   203,   204,   205,    -1,
      -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     202,   203,   204,   205,    63,    64,   208,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,   202,   203,   204,   205,    63,    64,   208,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,   202,   203,   204,   205,    63,
      64,   208,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,   202,   203,   204,   205,    63,
      64,   208,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      74,    75,    76,    77,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,   202,   203,   204,   205,    63,    64,   208,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,   202,   203,   204,   205,    -1,    -1,
     208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,    -1,    -1,   208,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   203,   204,   205,    -1,    -1,
     208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,    63,    64,   208,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    74,    75,    76,    77,   202,   203,
     204,   205,    63,    64,   208,    -1,    -1,    -1,    -1,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   202,   203,
     204,   205,    -1,    -1,   208,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,   203,   204,   205,    63,    64,   208,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      76,    77,    -1,    -1,    -1,    -1,   202,   203,   204,   205,
      63,    64,   208,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    63,    64,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,   202,   203,   204,   205,    63,    64,   208,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    76,
      77,   202,   203,   204,   205,    63,    64,   208,    -1,    -1,
      -1,    -1,    70,    71,    72,    73,    74,    75,    76,    77,
      63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,   202,   203,   204,   205,
      63,    64,   208,    -1,    -1,    -1,    -1,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,    -1,    -1,   208,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   203,   204,   205,    -1,    -1,
     208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,    -1,    -1,   208,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   203,   204,   205,    -1,    -1,
     208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   202,   203,   204,   205,    -1,
      -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   203,   204,   205,    -1,    -1,
     208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,    -1,    -1,   208,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,   204,   205
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   195,   196,   197,   198,   199,   213,     4,     5,     6,
      11,    15,    17,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    32,    33,    35,    36,    37,    42,
      45,    52,    53,    54,    55,    56,    57,    61,    62,    78,
      79,    80,    81,    82,    83,    89,    90,    91,    94,    95,
      96,    98,    99,   100,   103,   106,   108,   109,   114,   115,
     121,   144,   145,   146,   151,   171,   175,   180,   183,   187,
     214,   215,   218,   219,   226,   227,   229,   230,   234,   246,
     247,   252,   258,   265,   273,   281,   284,   288,   291,   297,
       3,     4,     5,     7,     8,     9,    10,    30,    31,    63,
      64,    65,    66,    67,    68,    69,    81,    84,    89,   101,
     102,   105,   107,   115,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   176,   177,   178,
     179,   181,   182,   184,   185,   186,   188,   189,   190,   191,
     192,   193,   194,   200,   201,   202,   209,   232,   233,   235,
     241,   243,   246,   247,   209,   232,   218,   246,   247,   252,
       0,    75,   209,    75,   209,   266,   285,   289,     4,     7,
     244,   244,   244,    34,   235,   220,   221,   232,   248,   249,
     248,   232,    28,     7,   274,   282,   235,    58,    60,    61,
     211,   328,   224,   232,   235,     4,     5,   245,   235,   232,
     235,   232,   235,     4,     5,   308,   309,    10,   202,   203,
     242,   243,   310,   244,    89,    97,   211,   232,   235,   329,
      89,    97,   110,   329,   329,    81,    82,    88,   111,   235,
     240,    12,    53,   240,   240,    59,    89,    90,    91,    96,
      95,   235,   227,   234,   232,   232,   232,   110,   240,    90,
      91,    92,    93,    94,   104,   110,   111,   116,   117,   118,
     119,   120,   240,   209,   209,   209,   209,   209,   232,   329,
     232,   232,   232,    44,   216,    92,    93,   104,    75,    75,
      24,   209,   209,   209,   209,   235,   209,   209,   209,   209,
     209,   209,   112,   113,   209,   209,   209,   209,   112,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     235,   232,   235,    70,    71,    72,    73,    74,    75,    76,
     203,    44,    63,    64,    70,    71,    72,    73,    74,    75,
      76,    77,   202,   203,   204,   205,   232,    44,    44,    44,
     235,   248,   232,   248,     4,   235,   215,    35,    36,    20,
      21,     4,     5,   259,   260,     4,     5,   261,   262,   232,
     235,   250,   251,   232,   235,   276,   215,   292,   298,   209,
      58,   209,     4,     7,   209,   232,   235,   311,    58,    60,
      61,   211,   313,   326,   209,   209,   208,   208,   208,   209,
     209,   208,   243,   243,   208,   235,   232,   235,    11,   208,
     208,   240,   232,   232,   232,   208,   240,   225,    12,   208,
     228,   208,   240,    12,   240,   228,   228,   228,   240,   240,
     240,   240,   240,   240,   240,   232,   232,   240,   240,   240,
     240,   228,     5,   231,   231,   231,   210,   235,   232,   208,
     208,   208,   208,    43,   240,   240,   240,   235,   232,   253,
     248,   248,   235,   235,   235,   235,   235,   235,    97,   232,
     329,   329,   232,     4,     5,   238,   239,   238,   239,   240,
     235,   232,   232,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   329,   235,   235,   235,   235,   235,   235,
     235,   235,   210,   235,   232,   232,   232,   232,   232,   235,
     235,   232,   235,   210,   235,   235,   232,   235,   232,   235,
     232,   232,   210,   232,   210,   232,   210,   232,   210,   232,
     232,   232,   232,   235,   232,   232,   232,   232,   232,   232,
     232,   329,   232,   248,   248,   232,   235,   232,   232,   232,
     232,   232,   210,   210,   232,   231,   232,   231,   232,   232,
     232,   210,   210,   232,   232,   232,   232,   232,   232,   232,
     232,   237,   236,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   210,   210,    75,   286,    14,
      16,    18,    41,    44,    49,   290,   222,   223,   209,   209,
     208,   209,   209,   208,   208,    43,   275,    14,    16,    18,
      41,    44,    49,   283,    46,   215,   235,   209,   232,   235,
      51,   312,   207,   208,   209,    58,   209,     4,     7,   209,
      10,   327,   248,   248,     4,     5,   235,   235,   248,   248,
     309,    10,   242,   208,    86,    87,    97,   232,   235,   228,
     208,   235,   313,   240,   232,   240,   228,   235,   235,   240,
     208,   228,   208,   228,   208,   228,   228,   208,   208,   208,
     228,   228,   240,   209,   208,   208,   208,   210,   210,   232,
     235,   232,   235,   235,   235,   217,   208,   228,   228,     4,
       5,   257,   210,   210,   208,   208,   210,   208,   208,   208,
     210,   208,   210,   208,   210,   208,   209,   209,   210,   210,
     208,   208,   228,   208,   208,   210,   210,   210,   210,   210,
     210,   208,   210,   210,   208,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   208,   210,   210,   208,
     208,   208,   210,   208,   208,   210,   208,   210,   210,   210,
     210,   210,   208,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   208,   208,   208,   208,   210,   210,
     210,   210,   210,   208,   210,   210,   210,   210,   210,   210,
     208,   210,   208,   208,   208,   208,   208,   210,   208,   208,
     210,   208,   210,   210,   235,   235,   267,   215,   235,   244,
     330,   244,   331,   248,   248,   260,   248,   248,   262,   251,
      43,   277,   293,    49,    50,   299,   208,   235,   208,   210,
     210,   209,   232,   232,   235,   235,   209,   232,   314,   315,
     235,     4,     5,   305,   307,   210,   210,   209,   209,   208,
     208,   210,   210,   235,    85,    85,   208,   208,   240,   232,
     208,   240,   208,   208,   208,   232,   240,   235,   240,   232,
     240,   240,   232,   235,   235,   235,   240,   240,   208,   248,
     235,   235,   235,   208,   208,   219,   235,   240,   240,   254,
     235,   235,   235,   235,   235,   232,    97,   232,   232,   210,
     210,   235,   235,   240,   235,   232,   235,   235,   235,   235,
     235,   235,   235,   235,   232,   235,   232,   232,   232,   232,
     232,   235,   235,   235,   235,   239,   232,   239,   232,   232,
     235,    16,    44,   287,   208,   208,   210,   210,   210,   210,
      39,    40,   279,   215,   235,   208,   232,    58,   232,   312,
     208,   235,   208,   210,   305,   305,   210,   209,   209,   208,
     248,   248,   235,   235,   208,   329,   329,   232,   232,   208,
     208,   232,   235,   235,   232,   208,   208,   228,   208,   208,
     228,   208,   208,   208,   228,   208,   232,   210,   210,   210,
     208,   210,   232,   232,   228,   209,   210,   210,   210,   210,
     210,   210,   210,   208,   210,   210,   210,   210,   228,   208,
     210,   210,   210,   210,   210,   208,   210,   210,   210,   208,
     210,   210,   210,   208,   208,   210,   208,   210,   210,   210,
     208,   208,   210,   208,   210,   210,   208,   210,   210,   210,
      12,   244,   244,   276,    43,    38,   294,   210,   235,   210,
     209,   208,   235,   208,   232,    58,   321,   316,   248,   248,
     306,   210,   210,   232,   232,   232,   208,   208,   208,   232,
     232,   240,   232,   232,   240,   235,   235,   235,   240,   235,
      75,    75,   235,    75,   208,   240,     4,     5,   263,   264,
     232,   235,   232,   235,   232,   232,   235,   235,   232,   235,
     232,   232,   235,   278,   280,    48,   301,    60,    61,   210,
      58,   235,   232,   210,   235,   210,   209,   327,   305,   210,
     210,   305,   208,   232,   232,   232,   208,   228,   208,   208,
     208,   228,   208,   232,   232,   210,   232,   235,   209,   209,
     208,   210,   210,   208,   210,   210,   210,   210,   210,   210,
     210,   210,   210,    13,   271,   215,   215,   235,    47,   300,
     209,   209,   208,   210,    60,    61,   317,   210,    58,   322,
     235,   305,   232,   232,   240,   235,   232,   235,   240,   235,
      75,   210,   210,   264,   255,   235,   235,   268,    46,   304,
     215,   295,   232,   235,   235,   323,   209,   327,   318,   209,
     327,   208,   208,   208,   208,   208,   208,   232,   215,   210,
     215,   302,    14,    16,    18,    41,    44,    49,   296,   208,
     210,   208,   210,   327,   232,   305,   327,   235,   305,   235,
     232,   232,   235,   232,   232,    25,    44,   256,   269,   215,
     232,   235,   305,   208,   210,   305,   208,   210,   208,    14,
      16,    18,    41,    44,    49,   270,   303,   210,   210,   232,
     324,   235,   319,   232,     4,   272,   301,   210,   327,   210,
     327,   325,   305,   320,   305,   327,   327,   305,   305
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   212,   213,   213,   213,   213,   213,   214,   215,   216,
     217,   215,   218,   218,   218,   218,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   220,   219,   221,   219,   219,   219,   219,   219,   219,
     219,   222,   219,   223,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   224,   219,   225,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   226,   226,   226,
     226,   226,   227,   227,   227,   227,   227,   227,   228,   228,
     229,   229,   229,   229,   229,   230,   230,   231,   231,   232,
     232,   232,   232,   232,   232,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   234,   234,
     236,   235,   237,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   238,   239,   240,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   242,   242,   242,   243,   243,
     243,   243,   244,   244,   245,   245,   245,   245,   246,   247,
     249,   248,   250,   250,   250,   251,   251,   253,   254,   255,
     252,   256,   256,   257,   257,   258,   258,   258,   258,   259,
     259,   260,   260,   260,   260,   261,   261,   262,   262,   262,
     262,   263,   263,   263,   264,   264,   264,   264,   266,   267,
     268,   269,   265,   270,   270,   270,   270,   270,   270,   271,
     271,   272,   272,   274,   273,   275,   275,   276,   276,   277,
     278,   277,   279,   280,   279,   282,   281,   283,   283,   283,
     283,   283,   283,   285,   286,   284,   287,   287,   289,   288,
     290,   290,   290,   290,   290,   290,   292,   293,   294,   295,
     291,   296,   296,   296,   296,   296,   296,   298,   297,   299,
     299,   300,   300,   301,   302,   303,   301,   304,   304,   305,
     306,   305,   307,   307,   307,   307,   308,   308,   309,   309,
     309,   309,   310,   310,   310,   310,   311,   311,   311,   311,
     311,   312,   312,   312,   314,   313,   315,   313,   316,   313,
     317,   313,   318,   313,   319,   313,   320,   313,   321,   313,
     322,   313,   323,   313,   324,   313,   325,   313,   326,   313,
     327,   327,   328,   328,   328,   328,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   329,   329,   330,   330,
     331,   331
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
       6,     8,     5,     2,     2,     2,     9,     3,     7,     8,
       5,    11,     7,     5,     7,     7,    11,     7,     9,    13,
      11,     9,    11,     3,     6,     2,     3,     2,     2,     1,
       1,     3,     4,     4,     4,     4,     4,     4,     1,     1,
       2,     1,     2,     2,     8,     6,     6,     0,     1,     1,
       2,     2,     3,    10,     8,     8,     8,     3,     1,     1,
       6,     4,     4,     6,     6,     4,     6,     1,     4,     1,
       1,     1,     1,     3,     3,     6,     6,     8,     6,     4,
       6,     8,     4,     1,     3,     4,     4,     4,     4,     4,
       4,     4,     6,     8,     4,     4,     4,     4,     4,     6,
       1,     3,     1,     3,     4,     6,     6,     4,     6,     4,
       6,    10,     4,     4,     4,     8,     6,     4,     3,     3,
       0,     4,     0,     4,     2,     3,     3,     3,     3,     3,
       3,     3,     4,     6,     1,     4,     4,     6,     6,     1,
       1,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     4,
       4,     4,     4,     4,     4,     6,     4,     4,     6,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     4,
       3,     6,     6,     4,     4,     4,     4,     6,     6,     8,
       6,     8,     4,     4,     4,     8,     4,     4,     4,     4,
       1,     3,     4,     1,     3,     4,     1,     3,     4,     1,
       3,     6,     6,     4,     6,     6,     6,     4,     8,     6,
       8,     6,     4,     4,     4,     6,     6,     6,     8,     4,
       2,     5,     5,     7,     4,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     4,     6,     4,     6,     4,     4,
       0,     2,     0,     1,     3,     1,     1,     0,     0,     0,
      11,     1,     1,     1,     1,     0,     1,     1,     2,     1,
       3,     1,     1,     4,     4,     1,     3,     1,     1,     4,
       4,     0,     1,     3,     1,     1,     3,     3,     0,     0,
       0,     0,    14,     1,     1,     1,     1,     1,     1,     0,
       2,     0,     1,     0,     7,     1,     2,     1,     1,     0,
       0,     5,     0,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     1,     0,     0,     6,     1,     1,     0,     4,
       1,     2,     1,     1,     1,     1,     0,     0,     0,     0,
      11,     1,     1,     1,     1,     1,     1,     0,     5,     1,
       1,     0,     2,     0,     0,     0,     7,     0,     1,     1,
       0,     4,     1,     4,     1,     4,     1,     3,     1,     4,
       1,     4,     1,     1,     3,     3,     0,     2,     4,     1,
       3,     0,     2,     6,     0,     4,     0,     4,     0,     6,
       0,     9,     0,    10,     0,    13,     0,    15,     0,     7,
       0,     9,     0,    10,     0,    13,     0,    15,     0,     3,
       0,     1,     0,     2,     2,     4,     1,     4,     6,     6,
       7,    10,    12,     7,    10,    12,     2,     1,     1,     3,
       1,     3
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

  case 91: /* statement: tTEXT coordinates ',' string_expression ',' string_expression ',' string_expression  */
                                                                                        {add_command(cTEXT3);}
    break;

  case 92: /* statement: clear_fill_clause tRECT coordinates to coordinates  */
                                                       {add_command(cRECT);putindrawmode(0);}
    break;

  case 93: /* statement: tCLOSE tWINDOW  */
                   {add_command(cCLOSEWIN);}
    break;

  case 94: /* statement: tCLEAR tWINDOW  */
                   {add_command(cCLEARWIN);}
    break;

  case 95: /* statement: tCLEAR tSCREEN  */
                   {add_command(cCLEARSCR);}
    break;

  case 96: /* statement: tWINDOW tOPEN coordinates to coordinates ',' string_expression ',' string_expression  */
                                                                                         {add_command(cYABOPENWIN);}
    break;

  case 97: /* statement: tWINDOW tCLOSE string_expression  */
                                     {add_command(cYABCLOSEWIN);}
    break;

  case 98: /* statement: tWINDOW tSET string_expression ',' string_expression ',' string_expression  */
                                                                               {add_command(cYABWINSET);}
    break;

  case 99: /* statement: tVIEW coordinates to coordinates ',' string_expression ',' string_expression  */
                                                                                 {add_command(cYABVIEW);}
    break;

  case 100: /* statement: tDRAW tSET string_expression ',' string_expression  */
                                                       {add_command(cYABDRAWSETTEXT);}
    break;

  case 101: /* statement: tDRAW tSET string_expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                    {add_command(cYABDRAWSETCOLOUR);}
    break;

  case 102: /* statement: tDRAW tTEXT coordinates ',' string_expression ',' string_expression  */
                                                                        {add_command(cYABDRAWTEXT);}
    break;

  case 103: /* statement: tDRAW tDOT coordinates ',' string_expression  */
                                                 {add_command(cYABDRAWDOT);}
    break;

  case 104: /* statement: tDRAW tLINE coordinates to coordinates ',' string_expression  */
                                                                 {add_command(cYABDRAWLINE);}
    break;

  case 105: /* statement: tDRAW tRECT coordinates to coordinates ',' string_expression  */
                                                                 {add_command(cYABDRAWRECT);}
    break;

  case 106: /* statement: tDRAW tROUNDRECT coordinates to coordinates ',' expression ',' expression ',' string_expression  */
                                                                                                    {add_command(cYABDRAWROUNDRECT);}
    break;

  case 107: /* statement: tDRAW tCIRCLE coordinates ',' expression ',' string_expression  */
                                                                   {add_command(cYABDRAWCIRCLE);}
    break;

  case 108: /* statement: tDRAW tELLIPSE coordinates ',' expression ',' expression ',' string_expression  */
                                                                                   {add_command(cYABDRAWELLIPSE);}
    break;

  case 109: /* statement: tDRAW tARC coordinates ',' expression ',' expression ',' expression ',' expression ',' string_expression  */
                                                                                                             {add_command(cYABDRAWARC);}
    break;

  case 110: /* statement: tDRAW tCURVE coordinates to coordinates to coordinates to coordinates ',' string_expression  */
                                                                                                {add_command(cYABDRAWCURVE);}
    break;

  case 111: /* statement: tDRAW tTRIANGLE coordinates to coordinates to coordinates ',' string_expression  */
                                                                                    {add_command(cYABDRAWTRIANGLE);}
    break;

  case 112: /* statement: tDRAW tPOLYGON coordinates to coordinates to coordinates to coordinates ',' string_expression  */
                                                                                                  {add_command(cYABDRAWPOLYGON);}
    break;

  case 113: /* statement: tDRAW tFLUSH string_expression  */
                                   {add_command(cYABDRAWFLUSH);}
    break;

  case 114: /* statement: tSCREENSHOT coordinates to coordinates ',' string_expression  */
                                                                 {add_command(cYABSCREENSHOT);}
    break;

  case 115: /* statement: tOPEN tPRINTER  */
                   {create_openprinter(0);}
    break;

  case 116: /* statement: tOPEN tPRINTER string_expression  */
                                     {create_openprinter(1);}
    break;

  case 117: /* statement: tCLOSE tPRINTER  */
                    {add_command(cCLOSEPRN);}
    break;

  case 118: /* statement: tWAIT expression  */
                     {add_command(cWAIT);}
    break;

  case 119: /* statement: tBELL  */
          {add_command(cBELL);}
    break;

  case 120: /* statement: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 121: /* statement: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP);}
    break;

  case 122: /* statement: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);add_command(cPOP);}
    break;

  case 123: /* statement: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);
	add_command(cPOP);}
    break;

  case 124: /* statement: tPOKE string_expression ',' string_expression  */
                                                  {create_poke('s');}
    break;

  case 125: /* statement: tPOKE string_expression ',' expression  */
                                           {create_poke('d');}
    break;

  case 126: /* statement: tPOKE hashed_number ',' string_expression  */
                                              {create_poke('S');}
    break;

  case 127: /* statement: tPOKE hashed_number ',' expression  */
                                       {create_poke('D');}
    break;

  case 128: /* statement: tEND  */
         {add_command(cEND);}
    break;

  case 129: /* statement: tEXIT  */
          {create_pushdbl(0);add_command(cEXIT);}
    break;

  case 130: /* statement: tEXIT expression  */
                     {add_command(cEXIT);}
    break;

  case 131: /* statement: tDOCU  */
          {create_docu((yyvsp[0].symbol));}
    break;

  case 132: /* statement: tBIND string_expression  */
                            {add_command(cBIND);}
    break;

  case 133: /* statement: tFRNBF_FREE string_expression  */
                                  {add_command(cFRNBF_FREE);}
    break;

  case 134: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression ',' expression  */
                                                                                     {add_command(cFRNBF_SET_NUMBER);}
    break;

  case 135: /* statement: tFRNBF_SET string_expression ',' expression ',' string_expression  */
                                                                      {add_command(cFRNBF_SET_STRING);}
    break;

  case 136: /* statement: tFRNBF_SET_BUFFER string_expression ',' expression ',' string_expression  */
                                                                             {add_command(cFRNBF_SET_BUFFER);}
    break;

  case 137: /* clear_fill_clause: %empty  */
                               {drawmode=0;}
    break;

  case 138: /* clear_fill_clause: tCLEAR  */
           {drawmode=dmCLEAR;}
    break;

  case 139: /* clear_fill_clause: tFILL  */
          {drawmode=dmFILL;}
    break;

  case 140: /* clear_fill_clause: tCLEAR tFILL  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 141: /* clear_fill_clause: tFILL tCLEAR  */
                 {drawmode=dmFILL+dmCLEAR;}
    break;

  case 142: /* string_assignment: tSTRSYM tEQU string_expression  */
                                                  {add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 143: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ',' expression ')' tEQU string_expression  */
                                                                                             {create_changestring(fMID);}
    break;

  case 144: /* string_assignment: tMID '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                              {create_changestring(fMID2);}
    break;

  case 145: /* string_assignment: tLEFT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                               {create_changestring(fLEFT);}
    break;

  case 146: /* string_assignment: tRIGHT '(' string_scalar_or_array ',' expression ')' tEQU string_expression  */
                                                                                {create_changestring(fRIGHT);}
    break;

  case 147: /* string_assignment: stringfunction_or_array tEQU string_expression  */
                                                   {create_doarray(dotify((yyvsp[-2].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 150: /* open_clause: tOPEN hashed_number ',' string_expression ',' string_expression  */
                                                                             {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 151: /* open_clause: tOPEN hashed_number ',' string_expression  */
                                              {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 152: /* open_clause: tOPEN hashed_number ',' tPRINTER  */
                                     {create_myopen(OPEN_HAS_STREAM+OPEN_PRINTER);}
    break;

  case 153: /* open_clause: tOPEN string_expression tFOR tREADING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 154: /* open_clause: tOPEN string_expression tFOR tWRITING tAS hashed_number  */
                                                            {add_command(cSWAP);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 155: /* seek_clause: tSEEK hashed_number ',' expression  */
                                                {add_command(cSEEK);}
    break;

  case 156: /* seek_clause: tSEEK hashed_number ',' expression ',' string_expression  */
                                                             {add_command(cSEEK2);}
    break;

  case 157: /* string_scalar_or_array: tSTRSYM  */
                                {add_command_with_sym_and_diag(cPUSHSTRPTR,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 158: /* string_scalar_or_array: tSTRSYM '(' call_list ')'  */
                              {create_doarray(dotify((yyvsp[-3].symbol),FALSE),GETSTRINGPOINTER);}
    break;

  case 159: /* string_expression: tSTRSYM  */
                           {add_command_with_sym_and_diag(cPUSHSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 161: /* string_expression: stringfunction_or_array  */
                            {add_command_with_sym_and_diag(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 162: /* string_expression: tSTRING  */
            {if ((yyvsp[0].string)==NULL) {lyyerror(sERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[0].string));}}
    break;

  case 163: /* string_expression: string_expression '+' string_expression  */
                                            {add_command(cCONCAT);}
    break;

  case 165: /* string_function: tLEFT '(' string_expression ',' expression ')'  */
                                                                {create_function(fLEFT);}
    break;

  case 166: /* string_function: tRIGHT '(' string_expression ',' expression ')'  */
                                                    {create_function(fRIGHT);}
    break;

  case 167: /* string_function: tMID '(' string_expression ',' expression ',' expression ')'  */
                                                                 {create_function(fMID);}
    break;

  case 168: /* string_function: tMID '(' string_expression ',' expression ')'  */
                                                  {create_function(fMID2);}
    break;

  case 169: /* string_function: tSTR '(' expression ')'  */
                            {create_function(fSTR);}
    break;

  case 170: /* string_function: tSTR '(' expression ',' string_expression ')'  */
                                                  {create_function(fSTR2);}
    break;

  case 171: /* string_function: tSTR '(' expression ',' string_expression ',' string_expression ')'  */
                                                                        {create_function(fSTR3);}
    break;

  case 172: /* string_function: tSTR '(' string_expression ')'  */
                                   {create_function(fSTR4);}
    break;

  case 173: /* string_function: tINKEY  */
           {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 174: /* string_function: tINKEY '(' ')'  */
                   {create_pushdbl(-1);create_function(fINKEY);}
    break;

  case 175: /* string_function: tINKEY '(' expression ')'  */
                              {create_function(fINKEY);}
    break;

  case 176: /* string_function: tCHR '(' expression ')'  */
                            {create_function(fCHR);}
    break;

  case 177: /* string_function: tUPPER '(' string_expression ')'  */
                                     {create_function(fUPPER);}
    break;

  case 178: /* string_function: tLOWER '(' string_expression ')'  */
                                     {create_function(fLOWER);}
    break;

  case 179: /* string_function: tLTRIM '(' string_expression ')'  */
                                     {create_function(fLTRIM);}
    break;

  case 180: /* string_function: tRTRIM '(' string_expression ')'  */
                                     {create_function(fRTRIM);}
    break;

  case 181: /* string_function: tTRIM '(' string_expression ')'  */
                                    {create_function(fTRIM);}
    break;

  case 182: /* string_function: tSTRING2 '(' expression ',' string_expression ')'  */
                                                      {create_function(fSTRING);}
    break;

  case 183: /* string_function: tREPLACE '(' string_expression ',' string_expression ',' string_expression ')'  */
                                                                                    {create_function(fREPLACE);}
    break;

  case 184: /* string_function: tCHOMP '(' string_expression ')'  */
                                     {create_function(fCHOMP);}
    break;

  case 185: /* string_function: tSYSTEM2 '(' string_expression ')'  */
                                       {create_function(fSYSTEM2);}
    break;

  case 186: /* string_function: tFRNFN_CALL2 '(' call_list ')'  */
                                   {create_function(fFRNFN_CALL2);}
    break;

  case 187: /* string_function: tFRNBF_ALLOC '(' expression ')'  */
                                    {create_function(fFRNBF_ALLOC);}
    break;

  case 188: /* string_function: tFRNBF_DUMP '(' string_expression ')'  */
                                          {create_function(fFRNBF_DUMP);}
    break;

  case 189: /* string_function: tFRNBF_DUMP '(' string_expression ',' expression ')'  */
                                                         {create_function(fFRNBF_DUMP2);}
    break;

  case 190: /* string_function: tDATE  */
          {create_function(fDATE);}
    break;

  case 191: /* string_function: tDATE '(' ')'  */
                  {create_function(fDATE);}
    break;

  case 192: /* string_function: tTIME  */
          {create_function(fTIME);}
    break;

  case 193: /* string_function: tTIME '(' ')'  */
                  {create_function(fTIME);}
    break;

  case 194: /* string_function: tPEEK2 '(' string_expression ')'  */
                                     {create_function(fPEEK2);}
    break;

  case 195: /* string_function: tPEEK2 '(' string_expression ',' string_expression ')'  */
                                                           {create_function(fPEEK3);}
    break;

  case 196: /* string_function: tTOKENALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cTOKENALT2);}
    break;

  case 197: /* string_function: tTOKENALT '(' string_scalar_or_array ')'  */
                                             {add_command(cTOKENALT);}
    break;

  case 198: /* string_function: tSPLITALT '(' string_scalar_or_array ',' string_expression ')'  */
                                                                   {add_command(cSPLITALT2);}
    break;

  case 199: /* string_function: tSPLITALT '(' string_scalar_or_array ')'  */
                                             {add_command(cSPLITALT);}
    break;

  case 200: /* string_function: tGETBIT '(' coordinates to coordinates ')'  */
                                               {create_function(fGETBIT);}
    break;

  case 201: /* string_function: tGETCHAR '(' expression ',' expression to expression ',' expression ')'  */
                                                                            {create_function(fGETCHAR);}
    break;

  case 202: /* string_function: tHEX '(' expression ')'  */
                            {create_function(fHEX);}
    break;

  case 203: /* string_function: tBIN '(' expression ')'  */
                            {create_function(fBIN);}
    break;

  case 204: /* string_function: tEXECUTE2 '(' call_list ')'  */
                                {create_execute(1);add_command(cSWAP);add_command(cPOP);}
    break;

  case 205: /* string_function: tFRNBF_GET2 '(' string_expression ',' expression ',' expression ')'  */
                                                                        {create_function(fFRNBF_GET_STRING);}
    break;

  case 206: /* string_function: tFRNBF_GET_BUFFER '(' string_expression ',' expression ')'  */
                                                               {create_function(fFRNBF_GET_BUFFER);}
    break;

  case 207: /* string_function: tEVAL2 '(' string_expression ')'  */
                                     {create_eval(evSTRING);}
    break;

  case 208: /* number_assignment: tSYMBOL tEQU expression  */
                                           {add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[-2].symbol),FALSE),NULL);}
    break;

  case 209: /* number_assignment: function_or_array tEQU expression  */
                                      {create_doarray((yyvsp[-2].symbol),ASSIGNARRAY);}
    break;

  case 210: /* $@9: %empty  */
                           {add_command(cORSHORT);pushlabel();}
    break;

  case 211: /* expression: expression tOR $@9 expression  */
                                                                           {poplabel();create_boole('|');}
    break;

  case 212: /* $@10: %empty  */
                    {add_command(cANDSHORT);pushlabel();}
    break;

  case 213: /* expression: expression tAND $@10 expression  */
                                                                     {poplabel();create_boole('&');}
    break;

  case 214: /* expression: tNOT expression  */
                    {create_boole('!');}
    break;

  case 215: /* expression: expression tEQU expression  */
                               {create_dblrelop('=');}
    break;

  case 216: /* expression: expression tEQU2 expression  */
                                {create_dblrelop('=');}
    break;

  case 217: /* expression: expression tNEQ expression  */
                               {create_dblrelop('!');}
    break;

  case 218: /* expression: expression tLTN expression  */
                               {create_dblrelop('<');}
    break;

  case 219: /* expression: expression tLEQ expression  */
                               {create_dblrelop('{');}
    break;

  case 220: /* expression: expression tGTN expression  */
                               {create_dblrelop('>');}
    break;

  case 221: /* expression: expression tGEQ expression  */
                               {create_dblrelop('}');}
    break;

  case 222: /* expression: tMYEOF '(' hashed_number ')'  */
                                 {add_command(cTESTEOF);}
    break;

  case 223: /* expression: tGLOB '(' string_expression ',' string_expression ')'  */
                                                          {add_command(cGLOB);}
    break;

  case 224: /* expression: number  */
           {create_pushdbl((yyvsp[0].fnum));}
    break;

  case 225: /* expression: tARDIM '(' arrayref ')'  */
                            {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 226: /* expression: tARDIM '(' string_arrayref ')'  */
                                   {add_command_with_sym_and_diag(cARDIM,"",NULL);}
    break;

  case 227: /* expression: tARSIZE '(' arrayref ',' expression ')'  */
                                            {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 228: /* expression: tARSIZE '(' string_arrayref ',' expression ')'  */
                                                   {add_command_with_sym_and_diag(cARSIZE,"",NULL);}
    break;

  case 229: /* expression: function_or_array  */
                      {add_command_with_sym_and_diag(cFUNCTION_OR_ARRAY,(yyvsp[0].symbol),NULL);}
    break;

  case 230: /* expression: tSYMBOL  */
            {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 231: /* expression: expression '+' expression  */
                              {create_dblbin('+');}
    break;

  case 232: /* expression: expression '-' expression  */
                              {create_dblbin('-');}
    break;

  case 233: /* expression: expression '*' expression  */
                              {create_dblbin('*');}
    break;

  case 234: /* expression: expression '/' expression  */
                              {create_dblbin('/');}
    break;

  case 235: /* expression: expression tPOW expression  */
                               {create_dblbin('^');}
    break;

  case 236: /* expression: '-' expression  */
                                {add_command(cNEGATE);}
    break;

  case 237: /* expression: string_expression tEQU string_expression  */
                                             {create_strrelop('=');}
    break;

  case 238: /* expression: string_expression tEQU2 string_expression  */
                                              {create_strrelop('=');}
    break;

  case 239: /* expression: string_expression tNEQ string_expression  */
                                             {create_strrelop('!');}
    break;

  case 240: /* expression: string_expression tLTN string_expression  */
                                             {create_strrelop('<');}
    break;

  case 241: /* expression: string_expression tLEQ string_expression  */
                                             {create_strrelop('{');}
    break;

  case 242: /* expression: string_expression tGTN string_expression  */
                                             {create_strrelop('>');}
    break;

  case 243: /* expression: string_expression tGEQ string_expression  */
                                             {create_strrelop('}');}
    break;

  case 246: /* arrayref: tSYMBOL '(' ')'  */
                          {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 247: /* string_arrayref: tSTRSYM '(' ')'  */
                                 {create_pusharrayref(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 249: /* function: tSIN '(' expression ')'  */
                                  {create_function(fSIN);}
    break;

  case 250: /* function: tASIN '(' expression ')'  */
                             {create_function(fASIN);}
    break;

  case 251: /* function: tCOS '(' expression ')'  */
                            {create_function(fCOS);}
    break;

  case 252: /* function: tACOS '(' expression ')'  */
                             {create_function(fACOS);}
    break;

  case 253: /* function: tTAN '(' expression ')'  */
                            {create_function(fTAN);}
    break;

  case 254: /* function: tATAN '(' expression ')'  */
                             {create_function(fATAN);}
    break;

  case 255: /* function: tATAN '(' expression ',' expression ')'  */
                                             {create_function(fATAN2);}
    break;

  case 256: /* function: tEXP '(' expression ')'  */
                            {create_function(fEXP);}
    break;

  case 257: /* function: tLOG '(' expression ')'  */
                            {create_function(fLOG);}
    break;

  case 258: /* function: tLOG '(' expression ',' expression ')'  */
                                           {create_function(fLOG2);}
    break;

  case 259: /* function: tSQRT '(' expression ')'  */
                             {create_function(fSQRT);}
    break;

  case 260: /* function: tSQR '(' expression ')'  */
                            {create_function(fSQR);}
    break;

  case 261: /* function: tINT '(' expression ')'  */
                            {create_function(fINT);}
    break;

  case 262: /* function: tROUND '(' expression ')'  */
                              {create_function(fROUND);}
    break;

  case 263: /* function: tCEIL '(' expression ')'  */
                             {create_function(fCEIL);}
    break;

  case 264: /* function: tFLOOR '(' expression ')'  */
                              {create_function(fFLOOR);}
    break;

  case 265: /* function: tFRAC '(' expression ')'  */
                             {create_function(fFRAC);}
    break;

  case 266: /* function: tABS '(' expression ')'  */
                            {create_function(fABS);}
    break;

  case 267: /* function: tSIG '(' expression ')'  */
                            {create_function(fSIG);}
    break;

  case 268: /* function: tMOD '(' expression ',' expression ')'  */
                                           {create_function(fMOD);}
    break;

  case 269: /* function: tRAN '(' expression ')'  */
                            {create_function(fRAN);}
    break;

  case 270: /* function: tRAN '(' ')'  */
                 {create_function(fRAN2);}
    break;

  case 271: /* function: tMIN '(' expression ',' expression ')'  */
                                           {create_function(fMIN);}
    break;

  case 272: /* function: tMAX '(' expression ',' expression ')'  */
                                           {create_function(fMAX);}
    break;

  case 273: /* function: tLEN '(' string_expression ')'  */
                                   {create_function(fLEN);}
    break;

  case 274: /* function: tVAL '(' string_expression ')'  */
                                   {create_function(fVAL);}
    break;

  case 275: /* function: tASC '(' string_expression ')'  */
                                   {create_function(fASC);}
    break;

  case 276: /* function: tDEC '(' string_expression ')'  */
                                   {create_function(fDEC);}
    break;

  case 277: /* function: tDEC '(' string_expression ',' expression ')'  */
                                                  {create_function(fDEC2);}
    break;

  case 278: /* function: tINSTR '(' string_expression ',' string_expression ')'  */
                                                           {if (check_compat) lyyerror(sWARNING,"instr() has changed in version 2.712"); create_function(fINSTR);}
    break;

  case 279: /* function: tINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                          {create_function(fINSTR2);}
    break;

  case 280: /* function: tRINSTR '(' string_expression ',' string_expression ')'  */
                                                            {create_function(fRINSTR);}
    break;

  case 281: /* function: tRINSTR '(' string_expression ',' string_expression ',' expression ')'  */
                                                                            {create_function(fRINSTR2);}
    break;

  case 282: /* function: tSYSTEM '(' string_expression ')'  */
                                      {create_function(fSYSTEM);}
    break;

  case 283: /* function: tFRNFN_CALL '(' call_list ')'  */
                                  {create_function(fFRNFN_CALL);}
    break;

  case 284: /* function: tFRNFN_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNFN_SIZE);}
    break;

  case 285: /* function: tFRNBF_GET '(' string_expression ',' expression ',' string_expression ')'  */
                                                                              {create_function(fFRNBF_GET_NUMBER);}
    break;

  case 286: /* function: tFRNBF_SIZE '(' string_expression ')'  */
                                          {create_function(fFRNBF_SIZE);}
    break;

  case 287: /* function: tPEEK '(' hashed_number ')'  */
                                {create_function(fPEEK4);}
    break;

  case 288: /* function: tPEEK '(' string_expression ')'  */
                                    {create_function(fPEEK);}
    break;

  case 289: /* function: tMOUSEX '(' string_expression ')'  */
                                      {create_function(fMOUSEX);}
    break;

  case 290: /* function: tMOUSEX  */
            {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 291: /* function: tMOUSEX '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEX);}
    break;

  case 292: /* function: tMOUSEY '(' string_expression ')'  */
                                      {create_function(fMOUSEY);}
    break;

  case 293: /* function: tMOUSEY  */
            {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 294: /* function: tMOUSEY '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEY);}
    break;

  case 295: /* function: tMOUSEB '(' string_expression ')'  */
                                      {create_function(fMOUSEB);}
    break;

  case 296: /* function: tMOUSEB  */
            {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 297: /* function: tMOUSEB '(' ')'  */
                    {create_pushstr("");create_function(fMOUSEB);}
    break;

  case 298: /* function: tMOUSEMOD '(' string_expression ')'  */
                                        {create_function(fMOUSEMOD);}
    break;

  case 299: /* function: tMOUSEMOD  */
              {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 300: /* function: tMOUSEMOD '(' ')'  */
                      {create_pushstr("");create_function(fMOUSEMOD);}
    break;

  case 301: /* function: tAND '(' expression ',' expression ')'  */
                                           {create_function(fAND);}
    break;

  case 302: /* function: tOR '(' expression ',' expression ')'  */
                                          {create_function(fOR);}
    break;

  case 303: /* function: tBITNOT '(' expression ')'  */
                               {create_function(fBITNOT);}
    break;

  case 304: /* function: tEOR '(' expression ',' expression ')'  */
                                           {create_function(fEOR);}
    break;

  case 305: /* function: tSHL '(' expression ',' expression ')'  */
                                           {create_function(fSHL);}
    break;

  case 306: /* function: tSHR '(' expression ',' expression ')'  */
                                           {create_function(fSHR);}
    break;

  case 307: /* function: tTELL '(' hashed_number ')'  */
                                {create_function(fTELL);}
    break;

  case 308: /* function: tTOKEN '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cTOKEN2);}
    break;

  case 309: /* function: tTOKEN '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cTOKEN);}
    break;

  case 310: /* function: tSPLIT '(' string_expression ',' string_arrayref ',' string_expression ')'  */
                                                                               {add_command(cSPLIT2);}
    break;

  case 311: /* function: tSPLIT '(' string_expression ',' string_arrayref ')'  */
                                                         {add_command(cSPLIT);}
    break;

  case 312: /* function: tEXECUTE '(' call_list ')'  */
                               {create_execute(0);add_command(cSWAP);add_command(cPOP);}
    break;

  case 313: /* function: tOPEN '(' tPRINTER ')'  */
                           {create_myopen(OPEN_PRINTER);}
    break;

  case 314: /* function: tOPEN '(' string_expression ')'  */
                                    {create_myopen(0);}
    break;

  case 315: /* function: tOPEN '(' string_expression ',' string_expression ')'  */
                                                          {create_myopen(OPEN_HAS_MODE);}
    break;

  case 316: /* function: tOPEN '(' hashed_number ',' tPRINTER ')'  */
                                             {create_myopen(OPEN_PRINTER+OPEN_HAS_STREAM);}
    break;

  case 317: /* function: tOPEN '(' hashed_number ',' string_expression ')'  */
                                                      {create_myopen(OPEN_HAS_STREAM);}
    break;

  case 318: /* function: tOPEN '(' hashed_number ',' string_expression ',' string_expression ')'  */
                                                                            {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);}
    break;

  case 319: /* function: tEVAL '(' string_expression ')'  */
                                    {create_eval(evNUMBER);}
    break;

  case 320: /* function: tWINDOW tCOUNT  */
                   {create_function(fYABNUMWINDOWS);}
    break;

  case 321: /* function: tWINDOW tGET string_expression ',' string_expression  */
                                                         {create_function(fYABWINDOWGET);}
    break;

  case 322: /* function: tDRAW tGET string_expression ',' string_expression  */
                                                       {create_function(fYABDRAWGET);}
    break;

  case 323: /* function: tDRAW tGET string_expression ',' string_expression ',' string_expression  */
                                                                             {create_function(fYABDRAWGETTEXT);}
    break;

  case 324: /* function: tBFILESIZE '(' string_expression ')'  */
                                         {create_function(fYABBFILESIZE);}
    break;

  case 325: /* const: number  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 326: /* const: '+' number  */
               {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 327: /* const: '-' number  */
               {(yyval.fnum)=-(yyvsp[0].fnum);}
    break;

  case 328: /* number: tFNUM  */
              {(yyval.fnum)=(yyvsp[0].fnum);}
    break;

  case 329: /* number: tDIGITS  */
            {(yyval.fnum)=strtod((yyvsp[0].digits),NULL);}
    break;

  case 330: /* number: tHEXDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,16);}
    break;

  case 331: /* number: tBINDIGITS  */
               {(yyval.fnum)=(double)strtoul((yyvsp[0].digits),NULL,2);}
    break;

  case 332: /* symbol_or_lineno: tDIGITS  */
                          {(yyval.symbol)=my_strdup(dotify((yyvsp[0].digits),FALSE));}
    break;

  case 333: /* symbol_or_lineno: tSYMBOL  */
            {(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 334: /* dimlist: tSYMBOL '(' call_list ')'  */
                                   {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 335: /* dimlist: dimlist ',' tSYMBOL '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'D');}
    break;

  case 336: /* dimlist: tSTRSYM '(' call_list ')'  */
                              {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 337: /* dimlist: dimlist ',' tSTRSYM '(' call_list ')'  */
                                          {create_dim(dotify((yyvsp[-3].symbol),FALSE),'S');}
    break;

  case 338: /* function_or_array: tSYMBOL '(' call_list ')'  */
                                             {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 339: /* stringfunction_or_array: tSTRSYM '(' call_list ')'  */
                                                   {(yyval.symbol)=my_strdup(dotify((yyvsp[-3].symbol),FALSE));}
    break;

  case 340: /* $@11: %empty  */
           {add_command(cPUSHFREE);}
    break;

  case 347: /* $@12: %empty  */
                                 {missing_endsub++;missing_endsub_line=yylineno;pushlabel();report_if_missing("can not define a function in a loop or an if-statement",FALSE);if (function_type!=ftNONE) {lyyerror(sERROR,"nested functions not allowed");YYABORT;}}
    break;

  case 348: /* $@13: %empty  */
                      {if (exported) create_subr_link((yyvsp[0].symbol)); create_label((yyvsp[0].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST);add_command(cCLEARSYMREFS);start_symref_chain();
		       create_count_params();}
    break;

  case 349: /* $@14: %empty  */
                          {create_require(stFREE);add_command(cPOP);}
    break;

  case 350: /* function_definition: export tSUB $@12 function_name $@13 '(' paramlist ')' $@14 statement_list endsub  */
               {add_command(cCLEARSYMREFS);end_symref_chain();add_command(cPOPSYMLIST);create_check_return_value(ftNONE,function_type);function_type=ftNONE;add_command(cRETURN_FROM_CALL);create_endfunction();poplabel();}
    break;

  case 351: /* endsub: tEOPROG  */
                {if (missing_endsub) {sprintf(string,"subroutine starting at line %d has seen no 'end sub' at end of program",missing_endsub_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 352: /* endsub: tENDSUB  */
            {missing_endsub--;}
    break;

  case 353: /* function_name: tSYMBOL  */
                       {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 354: /* function_name: tSTRSYM  */
            {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[0].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[0].symbol),FALSE));}
    break;

  case 355: /* export: %empty  */
                    {exported=FALSE;}
    break;

  case 356: /* export: tEXPORT  */
            {exported=TRUE;}
    break;

  case 357: /* export: tRUNTIME_CREATED_SUB  */
                         {exported=FALSE;}
    break;

  case 358: /* export: tRUNTIME_CREATED_SUB tEXPORT  */
                                 {exported=TRUE;}
    break;

  case 361: /* local_item: tSYMBOL  */
                    {create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);}
    break;

  case 362: /* local_item: tSTRSYM  */
            {create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);}
    break;

  case 363: /* local_item: tSYMBOL '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'d');}
    break;

  case 364: /* local_item: tSTRSYM '(' call_list ')'  */
                              {create_makelocal(dotify((yyvsp[-3].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),FALSE),'s');}
    break;

  case 367: /* static_item: tSYMBOL  */
                     {create_makestatic(dotify((yyvsp[0].symbol),TRUE),syNUMBER);}
    break;

  case 368: /* static_item: tSTRSYM  */
            {create_makestatic(dotify((yyvsp[0].symbol),TRUE),sySTRING);}
    break;

  case 369: /* static_item: tSYMBOL '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'D');}
    break;

  case 370: /* static_item: tSTRSYM '(' call_list ')'  */
                              {create_makestatic(dotify((yyvsp[-3].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[-3].symbol),TRUE),'S');}
    break;

  case 374: /* paramitem: tSYMBOL  */
                   {create_require(stNUMBER);create_makelocal(dotify((yyvsp[0].symbol),FALSE),syNUMBER);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 375: /* paramitem: tSTRSYM  */
            {create_require(stSTRING);create_makelocal(dotify((yyvsp[0].symbol),FALSE),sySTRING);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 376: /* paramitem: tSYMBOL '(' ')'  */
                    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stNUMBERARRAYREF);}
    break;

  case 377: /* paramitem: tSTRSYM '(' ')'  */
                    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[-2].symbol),FALSE),stSTRINGARRAYREF);}
    break;

  case 378: /* $@15: %empty  */
               {loop_nesting++;add_command(cBEGIN_LOOP_MARK);missing_next++;missing_next_line=yylineno;}
    break;

  case 379: /* $@16: %empty  */
            {pushname(dotify((yyvsp[-1].symbol),FALSE)); /* will be used by next_symbol to check equality,NULL */
	     add_command(cRESETSKIPONCE);
	     add_command(cRESETSKIPONCE2);
	     pushgoto();add_command_with_switch_state(cCONTINUE_HERE);}
    break;

  case 380: /* $@17: %empty  */
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

  case 381: /* $@18: %empty  */
                         {
             swap();popgoto();poplabel();}
    break;

  case 382: /* for_loop: tFOR $@15 tSYMBOL tEQU $@16 expression tTO expression step_part $@17 statement_list $@18 next next_symbol  */
                           {add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 383: /* next: tEOPROG  */
              {if (missing_next) {sprintf(string,"for-loop starting at line %d has seen no 'next' at end of program",missing_next_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 384: /* next: tNEXT  */
          {missing_next--;}
    break;

  case 385: /* next: tENDIF  */
           {report_conflicting_close("a closing next is expected before endif",'e');}
    break;

  case 386: /* next: tWEND  */
          {report_conflicting_close("a closing next is expected before wend",'w');}
    break;

  case 387: /* next: tUNTIL  */
           {report_conflicting_close("a closing next is expected before until",'l');}
    break;

  case 388: /* next: tLOOP  */
          {report_conflicting_close("a closing next is expected before loop",'l');}
    break;

  case 389: /* step_part: %empty  */
           {create_pushdbl(1);}
    break;

  case 391: /* next_symbol: %empty  */
              {pop(stSTRING);}
    break;

  case 392: /* next_symbol: tSYMBOL  */
            {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[0].symbol),FALSE))) 
             {lyyerror(sERROR,"'for' and 'next' do not match"); YYABORT;}
           }
    break;

  case 393: /* $@19: %empty  */
                                 {push_switch_id();add_command(cBEGIN_SWITCH_MARK);}
    break;

  case 394: /* switch_number_or_string: tSWITCH $@19 number_or_string sep_list case_list default tSEND  */
                                                                  {add_command(cBREAK_HERE);add_command(cPOP);add_command(cEND_SWITCH_MARK);pop_switch_id();}
    break;

  case 400: /* $@20: %empty  */
      {add_command(cSWITCH_COMPARE);add_command(cDECIDE);add_command(cNEXT_CASE);}
    break;

  case 401: /* case_list: case_list tCASE number_or_string $@20 statement_list  */
                                                                                                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 403: /* $@21: %empty  */
                  {add_command(cNEXT_CASE_HERE);}
    break;

  case 405: /* $@22: %empty  */
             {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_loop++;missing_loop_line=yylineno;pushgoto();}
    break;

  case 407: /* loop: tEOPROG  */
              {if (missing_loop) {sprintf(string,"do-loop starting at at line %d has seen no 'loop' at end of program",missing_loop_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 408: /* loop: tLOOP  */
          {missing_loop--;popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 409: /* loop: tENDIF  */
           {report_conflicting_close("a closing loop is expected before endif",'e');}
    break;

  case 410: /* loop: tWEND  */
          {report_conflicting_close("a closing loop is expected before wend",'w');}
    break;

  case 411: /* loop: tUNTIL  */
           {report_conflicting_close("a closing loop is expected before until",'l');}
    break;

  case 412: /* loop: tNEXT  */
          {report_conflicting_close("a closing loop is expected before next",'n');}
    break;

  case 413: /* $@23: %empty  */
                   {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_wend++;missing_wend_line=yylineno;pushgoto();}
    break;

  case 414: /* $@24: %empty  */
              {add_command(cDECIDE);
	      pushlabel();}
    break;

  case 416: /* wend: tEOPROG  */
              {if (missing_wend) {sprintf(string,"while-loop starting at line %d has seen no 'wend' at end of program",missing_wend_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 417: /* wend: tWEND  */
          {missing_wend--;swap();popgoto();poplabel();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 418: /* $@25: %empty  */
                     {loop_nesting++;add_command(cBEGIN_LOOP_MARK);add_command_with_switch_state(cCONTINUE_HERE);missing_until++;missing_until_line=yylineno;pushgoto();}
    break;

  case 420: /* until: tEOPROG  */
               {if (missing_until) {sprintf(string,"repeat-loop starting at line %d has seen no 'until' at end of program",missing_until_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 421: /* until: tUNTIL expression  */
                      {missing_until--;add_command(cDECIDE);popgoto();add_command(cBREAK_HERE);add_command(cEND_LOOP_MARK);loop_nesting--;}
    break;

  case 422: /* until: tENDIF  */
           {report_conflicting_close("a closing until is expected before endif",'e');}
    break;

  case 423: /* until: tWEND  */
          {report_conflicting_close("a closing until is expected before wend",'w');}
    break;

  case 424: /* until: tLOOP  */
          {report_conflicting_close("a closing until is expected before loop",'l');}
    break;

  case 425: /* until: tNEXT  */
          {report_conflicting_close("a closing until is expected before next",'n');}
    break;

  case 426: /* $@26: %empty  */
                          {add_command(cDECIDE);storelabel();pushlabel();}
    break;

  case 427: /* $@27: %empty  */
                 {missing_endif++;missing_endif_line=yylineno;}
    break;

  case 428: /* $@28: %empty  */
                                                                               {swap();matchgoto();swap();poplabel();}
    break;

  case 429: /* $@29: %empty  */
                     {poplabel();}
    break;

  case 431: /* endif: tEOPROG  */
               {if (missing_endif) {sprintf(string,"if-clause starting at line %d has seen no 'endif' (or 'fi') at end of program",missing_endif_line);error_without_position(sERROR,string);} YYABORT;}
    break;

  case 432: /* endif: tENDIF  */
           {missing_endif--;}
    break;

  case 433: /* endif: tWEND  */
          {report_conflicting_close("a closing endif is expected before wend",'w');}
    break;

  case 434: /* endif: tUNTIL  */
           {report_conflicting_close("a closing endif is expected before until",'l');}
    break;

  case 435: /* endif: tLOOP  */
          {report_conflicting_close("a closing endif is expected before loop",'l');}
    break;

  case 436: /* endif: tNEXT  */
          {report_conflicting_close("a closing endif is expected before next",'n');}
    break;

  case 437: /* $@30: %empty  */
                         {in_short_if++;add_command(cDECIDE);pushlabel();}
    break;

  case 439: /* end_of_if: tENDIF  */
                  {error(sERROR,"short if-statement (i.e. without 'then') does not allow 'endif'");}
    break;

  case 440: /* end_of_if: tIMPLICITENDIF  */
                   {poplabel();}
    break;

  case 444: /* $@31: %empty  */
        {add_command(cDECIDE);pushlabel();}
    break;

  case 445: /* $@32: %empty  */
        {swap();matchgoto();swap();poplabel();}
    break;

  case 450: /* $@33: %empty  */
              {add_command(cCHKPROMPT);}
    break;

  case 452: /* input: tSYMBOL  */
               {create_myread('d',tileol);add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 453: /* input: tSYMBOL '(' call_list ')'  */
        {create_myread('d',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 454: /* input: tSTRSYM  */
            {create_myread('s',tileol);add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 455: /* input: tSTRSYM '(' call_list ')'  */
        {create_myread('s',tileol);create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 458: /* readitem: tSYMBOL  */
                  {create_readdata('d');add_command_with_sym_and_diag(cPOPDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 459: /* readitem: tSYMBOL '(' call_list ')'  */
    {create_readdata('d');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNARRAY);}
    break;

  case 460: /* readitem: tSTRSYM  */
            {create_readdata('s');add_command_with_sym_and_diag(cPOPSTRSYM,dotify((yyvsp[0].symbol),FALSE),NULL);}
    break;

  case 461: /* readitem: tSTRSYM '(' call_list ')'  */
    {create_readdata('s');create_doarray(dotify((yyvsp[-3].symbol),FALSE),ASSIGNSTRINGARRAY);}
    break;

  case 462: /* datalist: tSTRING  */
                  {create_strdata((yyvsp[0].string));}
    break;

  case 463: /* datalist: const  */
          {create_dbldata((yyvsp[0].fnum));}
    break;

  case 464: /* datalist: datalist ',' tSTRING  */
                          {create_strdata((yyvsp[0].string));}
    break;

  case 465: /* datalist: datalist ',' const  */
                       {create_dbldata((yyvsp[0].fnum));}
    break;

  case 469: /* printlist: string_expression  */
                      {create_print('s');}
    break;

  case 470: /* printlist: printlist ',' string_expression  */
                                    {create_print('s');}
    break;

  case 471: /* using: %empty  */
       {create_print('d');}
    break;

  case 472: /* using: tUSING string_expression  */
                             {create_print('u');}
    break;

  case 473: /* using: tUSING '(' string_expression ',' string_expression ')'  */
                                                           {create_print('U');}
    break;

  case 474: /* $@34: %empty  */
                       {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,1);}
    break;

  case 475: /* inputbody: '#' tSYMBOL $@34 inputlist  */
                                                                                                                               {create_pps(cPOPSTREAM,0);}
    break;

  case 476: /* $@35: %empty  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,1);}
    break;

  case 477: /* inputbody: '#' tDIGITS $@35 inputlist  */
                                                                                {create_pps(cPOPSTREAM,0);}
    break;

  case 478: /* $@36: %empty  */
                           {create_pps(cPUSHSTREAM,1);}
    break;

  case 479: /* inputbody: '#' '(' expression ')' $@36 inputlist  */
                                                                  {create_pps(cPOPSTREAM,0);}
    break;

  case 480: /* $@37: %empty  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 481: /* inputbody: tAT '(' expression ',' expression ')' $@37 prompt inputlist  */
                                                                                                                                        {create_pps(cPOPSTREAM,0);}
    break;

  case 482: /* $@38: %empty  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 483: /* inputbody: tREVERSE tAT '(' expression ',' expression ')' $@38 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 484: /* $@39: %empty  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 485: /* inputbody: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')' $@39 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 486: /* $@40: %empty  */
                                                                                                   {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 487: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')' $@40 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 488: /* $@41: %empty  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 489: /* inputbody: tCOLOUR '(' string_expression ')' $@41 prompt inputlist  */
                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 490: /* $@42: %empty  */
                                                             {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 491: /* inputbody: tCOLOUR '(' string_expression ',' string_expression ')' $@42 prompt inputlist  */
                                                                                                                                                         {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 492: /* $@43: %empty  */
                                                   {create_colour(1);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 493: /* inputbody: tAT '(' expression ',' expression ')' tREVERSE $@43 prompt inputlist  */
                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 494: /* $@44: %empty  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 495: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')' $@44 prompt inputlist  */
                                                                                                                                                                                           {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 496: /* $@45: %empty  */
                                                                                                   {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 497: /* inputbody: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')' $@45 prompt inputlist  */
                                                                                                                                                                                                                  {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 498: /* $@46: %empty  */
    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);}
    break;

  case 499: /* inputbody: $@46 prompt inputlist  */
                                                                               {create_colour(0);create_pps(cPOPSTREAM,0);}
    break;

  case 500: /* prompt: %empty  */
                    {create_pushstr("?");create_print('s');}
    break;

  case 501: /* prompt: tSTRING  */
            {create_pushstr((yyvsp[0].string));create_print('s');}
    break;

  case 502: /* printintro: %empty  */
                               {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 503: /* printintro: '#' tSYMBOL  */
                {add_command_with_sym_and_diag(cPUSHDBLSYM,dotify((yyvsp[0].symbol),FALSE),NULL);create_pps(cPUSHSTREAM,0);}
    break;

  case 504: /* printintro: '#' tDIGITS  */
                {create_pushdbl(atoi((yyvsp[0].digits)));create_pps(cPUSHSTREAM,0);}
    break;

  case 505: /* printintro: '#' '(' expression ')'  */
                           {create_pps(cPUSHSTREAM,0);}
    break;

  case 506: /* printintro: tREVERSE  */
             {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 507: /* printintro: tCOLOUR '(' string_expression ')'  */
                                      {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 508: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                            {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 509: /* printintro: tAT '(' expression ',' expression ')'  */
                                          {add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 510: /* printintro: tREVERSE tAT '(' expression ',' expression ')'  */
                                                   {add_command(cMOVE);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 511: /* printintro: tCOLOUR '(' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                            {add_command(cMOVE);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 512: /* printintro: tCOLOUR '(' string_expression ',' string_expression ')' tAT '(' expression ',' expression ')'  */
                                                                                                  {add_command(cMOVE);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 513: /* printintro: tAT '(' expression ',' expression ')' tREVERSE  */
                                                   {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE);}
    break;

  case 514: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ')'  */
                                                                            {create_colour(2);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 515: /* printintro: tAT '(' expression ',' expression ')' tCOLOUR '(' string_expression ',' string_expression ')'  */
                                                                                                  {create_colour(3);add_command(cMOVE);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);}
    break;

  case 518: /* goto_list: symbol_or_lineno  */
                            {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 519: /* goto_list: goto_list ',' symbol_or_lineno  */
                                   {create_goto((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 520: /* gosub_list: symbol_or_lineno  */
                             {create_gosub((function_type!=ftNONE)?dotify((yyvsp[0].symbol),TRUE):(yyvsp[0].symbol));add_command(cFINDNOP);}
    break;

  case 521: /* gosub_list: gosub_list ',' symbol_or_lineno  */
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

