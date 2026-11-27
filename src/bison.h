/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_BISON_H_INCLUDED
# define YY_YY_SRC_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tFNUM = 258,                   /* tFNUM  */
    tSYMBOL = 259,                 /* tSYMBOL  */
    tSTRSYM = 260,                 /* tSTRSYM  */
    tDOCU = 261,                   /* tDOCU  */
    tDIGITS = 262,                 /* tDIGITS  */
    tHEXDIGITS = 263,              /* tHEXDIGITS  */
    tBINDIGITS = 264,              /* tBINDIGITS  */
    tSTRING = 265,                 /* tSTRING  */
    tFOR = 266,                    /* tFOR  */
    tTO = 267,                     /* tTO  */
    tSTEP = 268,                   /* tSTEP  */
    tNEXT = 269,                   /* tNEXT  */
    tWHILE = 270,                  /* tWHILE  */
    tWEND = 271,                   /* tWEND  */
    tREPEAT = 272,                 /* tREPEAT  */
    tUNTIL = 273,                  /* tUNTIL  */
    tIMPORT = 274,                 /* tIMPORT  */
    tGOTO = 275,                   /* tGOTO  */
    tGOSUB = 276,                  /* tGOSUB  */
    tLABEL = 277,                  /* tLABEL  */
    tON = 278,                     /* tON  */
    tSUB = 279,                    /* tSUB  */
    tENDSUB = 280,                 /* tENDSUB  */
    tLOCAL = 281,                  /* tLOCAL  */
    tSTATIC = 282,                 /* tSTATIC  */
    tEXPORT = 283,                 /* tEXPORT  */
    tERROR = 284,                  /* tERROR  */
    tEXECUTE = 285,                /* tEXECUTE  */
    tEXECUTE2 = 286,               /* tEXECUTE2  */
    tCOMPILE = 287,                /* tCOMPILE  */
    tRUNTIME_CREATED_SUB = 288,    /* tRUNTIME_CREATED_SUB  */
    tINTERRUPT = 289,              /* tINTERRUPT  */
    tBREAK = 290,                  /* tBREAK  */
    tCONTINUE = 291,               /* tCONTINUE  */
    tSWITCH = 292,                 /* tSWITCH  */
    tSEND = 293,                   /* tSEND  */
    tCASE = 294,                   /* tCASE  */
    tDEFAULT = 295,                /* tDEFAULT  */
    tLOOP = 296,                   /* tLOOP  */
    tDO = 297,                     /* tDO  */
    tSEP = 298,                    /* tSEP  */
    tEOPROG = 299,                 /* tEOPROG  */
    tIF = 300,                     /* tIF  */
    tTHEN = 301,                   /* tTHEN  */
    tELSE = 302,                   /* tELSE  */
    tELSIF = 303,                  /* tELSIF  */
    tENDIF = 304,                  /* tENDIF  */
    tIMPLICITENDIF = 305,          /* tIMPLICITENDIF  */
    tUSING = 306,                  /* tUSING  */
    tPRINT = 307,                  /* tPRINT  */
    tINPUT = 308,                  /* tINPUT  */
    tRETURN = 309,                 /* tRETURN  */
    tDIM = 310,                    /* tDIM  */
    tEND = 311,                    /* tEND  */
    tEXIT = 312,                   /* tEXIT  */
    tAT = 313,                     /* tAT  */
    tSCREEN = 314,                 /* tSCREEN  */
    tREVERSE = 315,                /* tREVERSE  */
    tCOLOUR = 316,                 /* tCOLOUR  */
    tBACKCOLOUR = 317,             /* tBACKCOLOUR  */
    tAND = 318,                    /* tAND  */
    tOR = 319,                     /* tOR  */
    tNOT = 320,                    /* tNOT  */
    tBITNOT = 321,                 /* tBITNOT  */
    tEOR = 322,                    /* tEOR  */
    tSHL = 323,                    /* tSHL  */
    tSHR = 324,                    /* tSHR  */
    tNEQ = 325,                    /* tNEQ  */
    tLEQ = 326,                    /* tLEQ  */
    tGEQ = 327,                    /* tGEQ  */
    tLTN = 328,                    /* tLTN  */
    tGTN = 329,                    /* tGTN  */
    tEQU = 330,                    /* tEQU  */
    tEQU2 = 331,                   /* tEQU2  */
    tPOW = 332,                    /* tPOW  */
    tREAD = 333,                   /* tREAD  */
    tDATA = 334,                   /* tDATA  */
    tRESTORE = 335,                /* tRESTORE  */
    tOPEN = 336,                   /* tOPEN  */
    tCLOSE = 337,                  /* tCLOSE  */
    tSEEK = 338,                   /* tSEEK  */
    tTELL = 339,                   /* tTELL  */
    tAS = 340,                     /* tAS  */
    tREADING = 341,                /* tREADING  */
    tWRITING = 342,                /* tWRITING  */
    tORIGIN = 343,                 /* tORIGIN  */
    tWINDOW = 344,                 /* tWINDOW  */
    tDOT = 345,                    /* tDOT  */
    tLINE = 346,                   /* tLINE  */
    tCIRCLE = 347,                 /* tCIRCLE  */
    tTRIANGLE = 348,               /* tTRIANGLE  */
    tTEXT = 349,                   /* tTEXT  */
    tCLEAR = 350,                  /* tCLEAR  */
    tFILL = 351,                   /* tFILL  */
    tPRINTER = 352,                /* tPRINTER  */
    tWAIT = 353,                   /* tWAIT  */
    tBELL = 354,                   /* tBELL  */
    tLET = 355,                    /* tLET  */
    tARDIM = 356,                  /* tARDIM  */
    tARSIZE = 357,                 /* tARSIZE  */
    tBIND = 358,                   /* tBIND  */
    tRECT = 359,                   /* tRECT  */
    tGETBIT = 360,                 /* tGETBIT  */
    tPUTBIT = 361,                 /* tPUTBIT  */
    tGETCHAR = 362,                /* tGETCHAR  */
    tPUTCHAR = 363,                /* tPUTCHAR  */
    tNEW = 364,                    /* tNEW  */
    tCURVE = 365,                  /* tCURVE  */
    tSET = 366,                    /* tSET  */
    tGET = 367,                    /* tGET  */
    tCOUNT = 368,                  /* tCOUNT  */
    tVIEW = 369,                   /* tVIEW  */
    tDRAW = 370,                   /* tDRAW  */
    tFLUSH = 371,                  /* tFLUSH  */
    tELLIPSE = 372,                /* tELLIPSE  */
    tARC = 373,                    /* tARC  */
    tPOLYGON = 374,                /* tPOLYGON  */
    tROUNDRECT = 375,              /* tROUNDRECT  */
    tSCREENSHOT = 376,             /* tSCREENSHOT  */
    tBFILESIZE = 377,              /* tBFILESIZE  */
    tBUTTON = 378,                 /* tBUTTON  */
    tCHECKBOX = 379,               /* tCHECKBOX  */
    tRADIOBUTTON = 380,            /* tRADIOBUTTON  */
    tTEXTCONTROL = 381,            /* tTEXTCONTROL  */
    tTEXTEDIT = 382,               /* tTEXTEDIT  */
    tTEXTURL = 383,                /* tTEXTURL  */
    tSLIDER = 384,                 /* tSLIDER  */
    tSTATUSBAR = 385,              /* tSTATUSBAR  */
    tSPINCONTROL = 386,            /* tSPINCONTROL  */
    tSCROLLBAR = 387,              /* tSCROLLBAR  */
    tLAYOUT = 388,                 /* tLAYOUT  */
    tTOOLTIP = 389,                /* tTOOLTIP  */
    tOPTION = 390,                 /* tOPTION  */
    tTABVIEW = 391,                /* tTABVIEW  */
    tBOXVIEW = 392,                /* tBOXVIEW  */
    tSPLITVIEW = 393,              /* tSPLITVIEW  */
    tSTACKVIEW = 394,              /* tSTACKVIEW  */
    tCANVAS = 395,                 /* tCANVAS  */
    tREGION = 396,                 /* tREGION  */
    tADD = 397,                    /* tADD  */
    tREMOVE = 398,                 /* tREMOVE  */
    tLISTBOX = 399,                /* tLISTBOX  */
    tDROPBOX = 400,                /* tDROPBOX  */
    tTREEBOX = 401,                /* tTREEBOX  */
    tCOLUMNBOX = 402,              /* tCOLUMNBOX  */
    tCALENDAR = 403,               /* tCALENDAR  */
    tCOLORCONTROL = 404,           /* tCOLORCONTROL  */
    tCOLUMN = 405,                 /* tCOLUMN  */
    tSORT = 406,                   /* tSORT  */
    tEXPAND = 407,                 /* tEXPAND  */
    tCOLLAPSE = 408,               /* tCOLLAPSE  */
    tSELECT = 409,                 /* tSELECT  */
    tGETS = 410,                   /* tGETS  */
    tSIN = 411,                    /* tSIN  */
    tASIN = 412,                   /* tASIN  */
    tCOS = 413,                    /* tCOS  */
    tACOS = 414,                   /* tACOS  */
    tTAN = 415,                    /* tTAN  */
    tATAN = 416,                   /* tATAN  */
    tEXP = 417,                    /* tEXP  */
    tLOG = 418,                    /* tLOG  */
    tSQRT = 419,                   /* tSQRT  */
    tSQR = 420,                    /* tSQR  */
    tMYEOF = 421,                  /* tMYEOF  */
    tABS = 422,                    /* tABS  */
    tSIG = 423,                    /* tSIG  */
    tINT = 424,                    /* tINT  */
    tCEIL = 425,                   /* tCEIL  */
    tFLOOR = 426,                  /* tFLOOR  */
    tFRAC = 427,                   /* tFRAC  */
    tROUND = 428,                  /* tROUND  */
    tMOD = 429,                    /* tMOD  */
    tRAN = 430,                    /* tRAN  */
    tVAL = 431,                    /* tVAL  */
    tLEFT = 432,                   /* tLEFT  */
    tRIGHT = 433,                  /* tRIGHT  */
    tMID = 434,                    /* tMID  */
    tLEN = 435,                    /* tLEN  */
    tMIN = 436,                    /* tMIN  */
    tMAX = 437,                    /* tMAX  */
    tSTR = 438,                    /* tSTR  */
    tINKEY = 439,                  /* tINKEY  */
    tCHR = 440,                    /* tCHR  */
    tASC = 441,                    /* tASC  */
    tHEX = 442,                    /* tHEX  */
    tDEC = 443,                    /* tDEC  */
    tBIN = 444,                    /* tBIN  */
    tUPPER = 445,                  /* tUPPER  */
    tLOWER = 446,                  /* tLOWER  */
    tMOUSEX = 447,                 /* tMOUSEX  */
    tMOUSEY = 448,                 /* tMOUSEY  */
    tMOUSEB = 449,                 /* tMOUSEB  */
    tMOUSEMOD = 450,               /* tMOUSEMOD  */
    tTRIM = 451,                   /* tTRIM  */
    tLTRIM = 452,                  /* tLTRIM  */
    tRTRIM = 453,                  /* tRTRIM  */
    tSTRING2 = 454,                /* tSTRING2  */
    tREPLACE = 455,                /* tREPLACE  */
    tINSTR = 456,                  /* tINSTR  */
    tRINSTR = 457,                 /* tRINSTR  */
    tCHOMP = 458,                  /* tCHOMP  */
    tSYSTEM = 459,                 /* tSYSTEM  */
    tSYSTEM2 = 460,                /* tSYSTEM2  */
    tPEEK = 461,                   /* tPEEK  */
    tPEEK2 = 462,                  /* tPEEK2  */
    tPOKE = 463,                   /* tPOKE  */
    tFRNFN_CALL = 464,             /* tFRNFN_CALL  */
    tFRNFN_CALL2 = 465,            /* tFRNFN_CALL2  */
    tFRNFN_SIZE = 466,             /* tFRNFN_SIZE  */
    tFRNBF_ALLOC = 467,            /* tFRNBF_ALLOC  */
    tFRNBF_FREE = 468,             /* tFRNBF_FREE  */
    tFRNBF_SIZE = 469,             /* tFRNBF_SIZE  */
    tFRNBF_DUMP = 470,             /* tFRNBF_DUMP  */
    tFRNBF_SET = 471,              /* tFRNBF_SET  */
    tFRNBF_GET = 472,              /* tFRNBF_GET  */
    tFRNBF_GET2 = 473,             /* tFRNBF_GET2  */
    tFRNBF_GET_BUFFER = 474,       /* tFRNBF_GET_BUFFER  */
    tFRNBF_SET_BUFFER = 475,       /* tFRNBF_SET_BUFFER  */
    tDATE = 476,                   /* tDATE  */
    tTIME = 477,                   /* tTIME  */
    tTOKEN = 478,                  /* tTOKEN  */
    tTOKENALT = 479,               /* tTOKENALT  */
    tSPLIT = 480,                  /* tSPLIT  */
    tSPLITALT = 481,               /* tSPLITALT  */
    tGLOB = 482,                   /* tGLOB  */
    tSTART_PROGRAM = 483,          /* tSTART_PROGRAM  */
    tSTART_EXPRESSION = 484,       /* tSTART_EXPRESSION  */
    tSTART_STRING_EXPRESSION = 485, /* tSTART_STRING_EXPRESSION  */
    tSTART_ASSIGNMENT = 486,       /* tSTART_ASSIGNMENT  */
    tSTART_FUNCTION_DEFINITION = 487, /* tSTART_FUNCTION_DEFINITION  */
    tEVAL = 488,                   /* tEVAL  */
    tEVAL2 = 489,                  /* tEVAL2  */
    tARGUMENT = 490,               /* tARGUMENT  */
    UMINUS = 491                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{

  double fnum;          /* double number */
  int inum;             /* integer number */
  int token;            /* token of command */
  int nnl;              /* number of newlines */
  char *string;         /* quoted string */
  char *symbol;         /* general symbol */
  char *digits;         /* string of digits */
  char *docu;		/* embedded documentation */


};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_SRC_BISON_H_INCLUDED  */
