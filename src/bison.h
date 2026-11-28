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
    tDROPZONE = 401,               /* tDROPZONE  */
    tTREEBOX = 402,                /* tTREEBOX  */
    tCOLUMNBOX = 403,              /* tCOLUMNBOX  */
    tCALENDAR = 404,               /* tCALENDAR  */
    tCOLORCONTROL = 405,           /* tCOLORCONTROL  */
    tCOLUMN = 406,                 /* tCOLUMN  */
    tSORT = 407,                   /* tSORT  */
    tEXPAND = 408,                 /* tEXPAND  */
    tCOLLAPSE = 409,               /* tCOLLAPSE  */
    tSELECT = 410,                 /* tSELECT  */
    tGETS = 411,                   /* tGETS  */
    tMENU = 412,                   /* tMENU  */
    tSUBMENU = 413,                /* tSUBMENU  */
    tSUBSUBMENU = 414,             /* tSUBSUBMENU  */
    tCLIPBOARD = 415,              /* tCLIPBOARD  */
    tCOPY = 416,                   /* tCOPY  */
    tPASTE = 417,                  /* tPASTE  */
    tTRANSLATE = 418,              /* tTRANSLATE  */
    tMESSAGE = 419,                /* tMESSAGE  */
    tATTRIBUTE = 420,              /* tATTRIBUTE  */
    tBITMAP = 421,                 /* tBITMAP  */
    tALERT = 422,                  /* tALERT  */
    tFILEPANEL = 423,              /* tFILEPANEL  */
    tPOPUPMENU = 424,              /* tPOPUPMENU  */
    tSOUND = 425,                  /* tSOUND  */
    tMEDIASOUND = 426,             /* tMEDIASOUND  */
    tLOUDNESS = 427,               /* tLOUDNESS  */
    tPLAY = 428,                   /* tPLAY  */
    tSTOP = 429,                   /* tSTOP  */
    tSIN = 430,                    /* tSIN  */
    tASIN = 431,                   /* tASIN  */
    tCOS = 432,                    /* tCOS  */
    tACOS = 433,                   /* tACOS  */
    tTAN = 434,                    /* tTAN  */
    tATAN = 435,                   /* tATAN  */
    tEXP = 436,                    /* tEXP  */
    tLOG = 437,                    /* tLOG  */
    tSQRT = 438,                   /* tSQRT  */
    tSQR = 439,                    /* tSQR  */
    tMYEOF = 440,                  /* tMYEOF  */
    tABS = 441,                    /* tABS  */
    tSIG = 442,                    /* tSIG  */
    tINT = 443,                    /* tINT  */
    tCEIL = 444,                   /* tCEIL  */
    tFLOOR = 445,                  /* tFLOOR  */
    tFRAC = 446,                   /* tFRAC  */
    tROUND = 447,                  /* tROUND  */
    tMOD = 448,                    /* tMOD  */
    tRAN = 449,                    /* tRAN  */
    tVAL = 450,                    /* tVAL  */
    tLEFT = 451,                   /* tLEFT  */
    tRIGHT = 452,                  /* tRIGHT  */
    tMID = 453,                    /* tMID  */
    tLEN = 454,                    /* tLEN  */
    tMIN = 455,                    /* tMIN  */
    tMAX = 456,                    /* tMAX  */
    tSTR = 457,                    /* tSTR  */
    tINKEY = 458,                  /* tINKEY  */
    tCHR = 459,                    /* tCHR  */
    tASC = 460,                    /* tASC  */
    tHEX = 461,                    /* tHEX  */
    tDEC = 462,                    /* tDEC  */
    tBIN = 463,                    /* tBIN  */
    tUPPER = 464,                  /* tUPPER  */
    tLOWER = 465,                  /* tLOWER  */
    tMOUSEX = 466,                 /* tMOUSEX  */
    tMOUSEY = 467,                 /* tMOUSEY  */
    tMOUSEB = 468,                 /* tMOUSEB  */
    tMOUSEMOD = 469,               /* tMOUSEMOD  */
    tMOUSE = 470,                  /* tMOUSE  */
    tKEYBOARD = 471,               /* tKEYBOARD  */
    tTRIM = 472,                   /* tTRIM  */
    tLTRIM = 473,                  /* tLTRIM  */
    tRTRIM = 474,                  /* tRTRIM  */
    tSTRING2 = 475,                /* tSTRING2  */
    tREPLACE = 476,                /* tREPLACE  */
    tINSTR = 477,                  /* tINSTR  */
    tRINSTR = 478,                 /* tRINSTR  */
    tCHOMP = 479,                  /* tCHOMP  */
    tSYSTEM = 480,                 /* tSYSTEM  */
    tSYSTEM2 = 481,                /* tSYSTEM2  */
    tPEEK = 482,                   /* tPEEK  */
    tPEEK2 = 483,                  /* tPEEK2  */
    tPOKE = 484,                   /* tPOKE  */
    tFRNFN_CALL = 485,             /* tFRNFN_CALL  */
    tFRNFN_CALL2 = 486,            /* tFRNFN_CALL2  */
    tFRNFN_SIZE = 487,             /* tFRNFN_SIZE  */
    tFRNBF_ALLOC = 488,            /* tFRNBF_ALLOC  */
    tFRNBF_FREE = 489,             /* tFRNBF_FREE  */
    tFRNBF_SIZE = 490,             /* tFRNBF_SIZE  */
    tFRNBF_DUMP = 491,             /* tFRNBF_DUMP  */
    tFRNBF_SET = 492,              /* tFRNBF_SET  */
    tFRNBF_GET = 493,              /* tFRNBF_GET  */
    tFRNBF_GET2 = 494,             /* tFRNBF_GET2  */
    tFRNBF_GET_BUFFER = 495,       /* tFRNBF_GET_BUFFER  */
    tFRNBF_SET_BUFFER = 496,       /* tFRNBF_SET_BUFFER  */
    tDATE = 497,                   /* tDATE  */
    tTIME = 498,                   /* tTIME  */
    tTOKEN = 499,                  /* tTOKEN  */
    tTOKENALT = 500,               /* tTOKENALT  */
    tSPLIT = 501,                  /* tSPLIT  */
    tSPLITALT = 502,               /* tSPLITALT  */
    tGLOB = 503,                   /* tGLOB  */
    tSTART_PROGRAM = 504,          /* tSTART_PROGRAM  */
    tSTART_EXPRESSION = 505,       /* tSTART_EXPRESSION  */
    tSTART_STRING_EXPRESSION = 506, /* tSTART_STRING_EXPRESSION  */
    tSTART_ASSIGNMENT = 507,       /* tSTART_ASSIGNMENT  */
    tSTART_FUNCTION_DEFINITION = 508, /* tSTART_FUNCTION_DEFINITION  */
    tEVAL = 509,                   /* tEVAL  */
    tEVAL2 = 510,                  /* tEVAL2  */
    tARGUMENT = 511,               /* tARGUMENT  */
    UMINUS = 512                   /* UMINUS  */
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
