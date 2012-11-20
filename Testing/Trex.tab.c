/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CONST = 258,
     FINAL = 259,
     SUPER = 260,
     WHILE = 261,
     FOR = 262,
     IF = 263,
     ELSE = 264,
     NOT = 265,
     READ = 266,
     PRINT = 267,
     PROGRAM = 268,
     RETURN = 269,
     FUNCTION = 270,
     ID = 271,
     INT = 272,
     FLOAT = 273,
     STRING = 274,
     BOOLEAN = 275,
     CHAR = 276,
     MAX = 277,
     MIN = 278,
     REMAINDER = 279,
     FLOOR = 280,
     CEILING = 281,
     SQRT = 282,
     POW = 283,
     RANDOM = 284,
     LLAVEIZQ = 285,
     LLAVEDER = 286,
     COMA = 287,
     PUNTOYCOMA = 288,
     IGUAL = 289,
     MENORQUE = 290,
     MAYORQUE = 291,
     DIFERENTE = 292,
     IGUALIGUAL = 293,
     SUMA = 294,
     RESTA = 295,
     MULTIPLICACION = 296,
     DIVISION = 297,
     PARENTESISIZQ = 298,
     PARENTESISDER = 299,
     CORIZQ = 300,
     CORDER = 301,
     AND = 302,
     OR = 303,
     CTE_ID = 304,
     CTE_INT = 305,
     CTE_FLOAT = 306,
     CTE_STRING = 307,
     CTE_BOOLEAN = 308,
     CTE_CHAR = 309
   };
#endif
/* Tokens.  */
#define CONST 258
#define FINAL 259
#define SUPER 260
#define WHILE 261
#define FOR 262
#define IF 263
#define ELSE 264
#define NOT 265
#define READ 266
#define PRINT 267
#define PROGRAM 268
#define RETURN 269
#define FUNCTION 270
#define ID 271
#define INT 272
#define FLOAT 273
#define STRING 274
#define BOOLEAN 275
#define CHAR 276
#define MAX 277
#define MIN 278
#define REMAINDER 279
#define FLOOR 280
#define CEILING 281
#define SQRT 282
#define POW 283
#define RANDOM 284
#define LLAVEIZQ 285
#define LLAVEDER 286
#define COMA 287
#define PUNTOYCOMA 288
#define IGUAL 289
#define MENORQUE 290
#define MAYORQUE 291
#define DIFERENTE 292
#define IGUALIGUAL 293
#define SUMA 294
#define RESTA 295
#define MULTIPLICACION 296
#define DIVISION 297
#define PARENTESISIZQ 298
#define PARENTESISDER 299
#define CORIZQ 300
#define CORDER 301
#define AND 302
#define OR 303
#define CTE_ID 304
#define CTE_INT 305
#define CTE_FLOAT 306
#define CTE_STRING 307
#define CTE_BOOLEAN 308
#define CTE_CHAR 309




/* Copy the first part of user declarations.  */
#line 2 "Trex.y"

#include <cstdio>
#include <iostream>
#include "semantic_methods.h"

using namespace std;

extern "C" int yylex();
extern "C" int yyparse();
extern "C" FILE *yyin;
extern int yylineno; 
extern char *yytext;
 
char *var_type;
char *name;
char *size;
char *function_name;
char *main_func;
char *function_called;
 
void yyerror(const char *s);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "Trex.y"
{
	char *sval;
}
/* Line 193 of yacc.c.  */
#line 232 "Trex.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 245 "Trex.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   283

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  115
/* YYNRULES -- Number of rules.  */
#define YYNRULES  182
/* YYNRULES -- Number of states.  */
#define YYNSTATES  306

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,    12,    13,    19,    20,    26,    27,
      31,    32,    33,    39,    42,    43,    46,    47,    50,    53,
      54,    57,    58,    62,    65,    66,    69,    70,    74,    81,
      83,    85,    87,    89,    91,    93,    95,    97,    99,   101,
     103,   105,   107,   109,   111,   113,   115,   117,   119,   121,
     122,   130,   132,   134,   135,   140,   141,   142,   147,   152,
     153,   157,   158,   161,   164,   165,   167,   169,   171,   173,
     175,   177,   178,   182,   183,   188,   189,   191,   193,   194,
     195,   199,   200,   205,   206,   208,   210,   212,   215,   217,
     219,   220,   225,   231,   232,   233,   234,   235,   247,   248,
     249,   250,   259,   260,   261,   269,   270,   275,   277,   279,
     281,   282,   283,   289,   293,   294,   295,   300,   301,   308,
     309,   310,   317,   320,   321,   323,   324,   328,   330,   331,
     332,   333,   342,   344,   345,   346,   351,   352,   358,   359,
     360,   364,   365,   366,   372,   373,   374,   375,   376,   384,
     386,   388,   390,   392,   394,   396,   398,   400,   402,   404,
     406,   408,   410,   412,   414,   416,   419,   422,   425,   428,
     434,   440,   445,   451,   454,   457,   460,   463,   468,   473,
     477,   482,   489
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      56,     0,    -1,    -1,    61,    72,    64,   124,    65,    57,
      66,    -1,    -1,    61,   124,    65,    58,    66,    -1,    -1,
      61,    72,    64,    59,    66,    -1,    -1,    61,    60,    66,
      -1,    -1,    -1,    13,    62,    49,    63,    30,    -1,    72,
      64,    -1,    -1,   124,    65,    -1,    -1,    67,    31,    -1,
      75,    68,    -1,    -1,    75,    68,    -1,    -1,    30,    70,
      31,    -1,    75,    71,    -1,    -1,    75,    71,    -1,    -1,
      73,    49,    33,    -1,    73,    49,    45,    50,    46,    33,
      -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,    21,
      -1,    50,    -1,    51,    -1,    52,    -1,    53,    -1,    54,
      -1,    49,    -1,   115,    -1,    81,    -1,    76,    -1,   102,
      -1,   112,    -1,    72,    -1,   122,    -1,   132,    -1,   150,
      -1,    -1,    12,    43,    77,    78,    79,    44,    33,    -1,
      89,    -1,   151,    -1,    -1,    32,    80,    78,    79,    -1,
      -1,    -1,    83,    82,    69,    84,    -1,     8,    43,    86,
      44,    -1,    -1,     9,    85,    69,    -1,    -1,    89,    87,
      -1,    88,    89,    -1,    -1,    36,    -1,    35,    -1,    37,
      -1,    38,    -1,    47,    -1,    48,    -1,    -1,    94,    90,
      91,    -1,    -1,    93,    94,    92,    91,    -1,    -1,    39,
      -1,    40,    -1,    -1,    -1,    99,    95,    96,    -1,    -1,
      98,    99,    97,    96,    -1,    -1,    41,    -1,    42,    -1,
     100,    -1,    93,    74,    -1,    74,    -1,   146,    -1,    -1,
      43,   101,    86,    44,    -1,     7,    43,   103,    44,    69,
      -1,    -1,    -1,    -1,    -1,    49,   104,    34,   105,    74,
      33,   106,    86,    33,   107,   108,    -1,    -1,    -1,    -1,
      49,   109,    34,   110,    49,   111,    93,    50,    -1,    -1,
      -1,     6,   113,    43,    86,    44,   114,    69,    -1,    -1,
      49,   116,   121,   118,    -1,    86,    -1,   122,    -1,   151,
      -1,    -1,    -1,    34,   119,   117,   120,    33,    -1,    45,
      89,    46,    -1,    -1,    -1,    11,   123,    43,    44,    -1,
      -1,    15,    49,   125,    43,   130,   126,    -1,    -1,    -1,
      44,   127,    30,   128,   131,    31,    -1,    72,   129,    -1,
      -1,   137,    -1,    -1,    72,   129,    67,    -1,    67,    -1,
      -1,    -1,    -1,    49,   133,    43,   134,   136,    44,   135,
      33,    -1,   141,    -1,    -1,    -1,    73,    49,   138,   139,
      -1,    -1,    32,    73,    49,   140,   139,    -1,    -1,    -1,
      89,   142,   143,    -1,    -1,    -1,    32,   144,    89,   145,
     143,    -1,    -1,    -1,    -1,    -1,    49,   147,    45,   148,
      89,   149,    46,    -1,   152,    -1,   153,    -1,   156,    -1,
     157,    -1,   154,    -1,   158,    -1,   159,    -1,   155,    -1,
     160,    -1,   161,    -1,   164,    -1,   165,    -1,   162,    -1,
     166,    -1,   167,    -1,   163,    -1,    23,   168,    -1,    22,
     168,    -1,    28,   168,    -1,    24,   168,    -1,    25,    43,
      89,    44,    33,    -1,    26,    43,    89,    44,    33,    -1,
      29,    43,    44,    33,    -1,    27,    43,    89,    44,    33,
      -1,    23,   169,    -1,    22,   169,    -1,    28,   169,    -1,
      24,   169,    -1,    25,    43,    89,    44,    -1,    26,    43,
      89,    44,    -1,    29,    43,    44,    -1,    27,    43,    89,
      44,    -1,    43,    89,    32,    89,    44,    33,    -1,    43,
      89,    32,    89,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    86,    86,    86,    87,    87,    88,    88,    89,    89,
      93,    93,    93,    97,    98,   102,   103,   107,   111,   112,
     116,   117,   121,   125,   126,   130,   131,   135,   136,   140,
     141,   142,   143,   144,   148,   149,   150,   151,   152,   153,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   169,
     169,   173,   174,   178,   178,   179,   183,   183,   187,   191,
     191,   192,   196,   200,   201,   205,   206,   207,   208,   209,
     210,   214,   214,   218,   218,   219,   223,   224,   225,   229,
     229,   233,   233,   234,   238,   239,   243,   244,   245,   246,
     250,   250,   254,   258,   258,   258,   258,   258,   262,   262,
     262,   262,   266,   266,   266,   270,   270,   274,   275,   276,
     280,   280,   280,   284,   285,   289,   289,   293,   293,   297,
     297,   297,   301,   302,   306,   307,   311,   312,   316,   316,
     316,   316,   320,   321,   325,   325,   329,   329,   330,   334,
     334,   338,   338,   338,   339,   343,   343,   343,   343,   347,
     348,   349,   350,   351,   352,   353,   354,   358,   359,   360,
     361,   362,   363,   364,   365,   369,   373,   377,   381,   385,
     389,   392,   396,   400,   404,   408,   412,   416,   420,   423,
     427,   431,   435
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONST", "FINAL", "SUPER", "WHILE",
  "FOR", "IF", "ELSE", "NOT", "READ", "PRINT", "PROGRAM", "RETURN",
  "FUNCTION", "ID", "INT", "FLOAT", "STRING", "BOOLEAN", "CHAR", "MAX",
  "MIN", "REMAINDER", "FLOOR", "CEILING", "SQRT", "POW", "RANDOM",
  "LLAVEIZQ", "LLAVEDER", "COMA", "PUNTOYCOMA", "IGUAL", "MENORQUE",
  "MAYORQUE", "DIFERENTE", "IGUALIGUAL", "SUMA", "RESTA", "MULTIPLICACION",
  "DIVISION", "PARENTESISIZQ", "PARENTESISDER", "CORIZQ", "CORDER", "AND",
  "OR", "CTE_ID", "CTE_INT", "CTE_FLOAT", "CTE_STRING", "CTE_BOOLEAN",
  "CTE_CHAR", "$accept", "programa", "@1", "@2", "@3", "@4", "programa_a",
  "@5", "@6", "programa_b", "programa_c", "programa_d", "bloque", "b",
  "bloque2", "bloque21", "c", "vars", "tipo", "var_cte", "estatuto",
  "escritura", "@7", "escritura_a", "d", "@8", "condicion", "@9",
  "condicion_a", "condicion_b", "@10", "expresion", "expresion_b",
  "expresion_a", "exp", "@11", "e", "@12", "sumaresta", "termino", "@13",
  "f", "@14", "multdiv", "factor", "factor_a", "@15", "loopfor",
  "bloque_for", "@16", "@17", "@18", "@19", "bloque_for_2", "@20", "@21",
  "@22", "loopwhile", "@23", "@24", "asignacion", "@25", "asignacion_b",
  "asignacion_c", "@26", "@27", "asignacion_d", "lectura", "@28",
  "funcion", "@29", "funcion_a", "@30", "@31", "funcion_b", "funcion_c",
  "funcion_d", "llamada", "@32", "@33", "@34", "llamada_2", "param", "@35",
  "g", "@36", "param2", "@37", "h", "@38", "@39", "arr", "@40", "@41",
  "@42", "especial", "especial3", "min", "max", "pow", "remainder",
  "floor", "ceiling", "random", "sqrt", "min2", "max2", "pow2",
  "remainder2", "floor2", "ceiling2", "random2", "sqrt2", "especial2",
  "especial4", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    57,    56,    58,    56,    59,    56,    60,    56,
      62,    63,    61,    64,    64,    65,    65,    66,    67,    67,
      68,    68,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    74,    74,    74,    74,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    77,
      76,    78,    78,    80,    79,    79,    82,    81,    83,    85,
      84,    84,    86,    87,    87,    88,    88,    88,    88,    88,
      88,    90,    89,    92,    91,    91,    93,    93,    93,    95,
      94,    97,    96,    96,    98,    98,    99,    99,    99,    99,
     101,   100,   102,   104,   105,   106,   107,   103,   109,   110,
     111,   108,   113,   114,   112,   116,   115,   117,   117,   117,
     119,   120,   118,   121,   121,   123,   122,   125,   124,   127,
     128,   126,   129,   129,   130,   130,   131,   131,   133,   134,
     135,   132,   136,   136,   138,   137,   140,   139,   139,   142,
     141,   144,   145,   143,   143,   147,   148,   149,   146,   150,
     150,   150,   150,   150,   150,   150,   150,   151,   151,   151,
     151,   151,   151,   151,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     0,     5,     0,     5,     0,     3,
       0,     0,     5,     2,     0,     2,     0,     2,     2,     0,
       2,     0,     3,     2,     0,     2,     0,     3,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       7,     1,     1,     0,     4,     0,     0,     4,     4,     0,
       3,     0,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     0,     3,     0,     4,     0,     1,     1,     0,     0,
       3,     0,     4,     0,     1,     1,     1,     2,     1,     1,
       0,     4,     5,     0,     0,     0,     0,    11,     0,     0,
       0,     8,     0,     0,     7,     0,     4,     1,     1,     1,
       0,     0,     5,     3,     0,     0,     4,     0,     6,     0,
       0,     6,     2,     0,     1,     0,     3,     1,     0,     0,
       0,     8,     1,     0,     0,     4,     0,     5,     0,     0,
       3,     0,     0,     5,     0,     0,     0,     0,     7,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     5,
       5,     4,     5,     2,     2,     2,     2,     4,     4,     3,
       4,     6,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,     0,     8,     0,     1,     0,    29,    30,    31,
      32,    33,    19,    14,     0,    16,    11,   117,   102,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,     9,     0,    45,    21,    42,    41,    56,    43,
      44,    40,    46,    47,    48,   149,   150,   153,   156,   151,
     152,   154,   155,     6,    14,     0,     4,    16,     0,     0,
       0,     0,     0,     0,    49,     0,   166,   165,   168,     0,
       0,     0,   167,     0,   114,     0,    17,    18,    21,     0,
      19,    16,    13,    27,     0,    19,    15,    12,   125,     0,
      93,     0,    76,    77,    90,    39,    34,    35,    36,    37,
      38,    88,     0,    64,     0,    71,    79,    86,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,    20,
      24,    61,     7,     2,     0,     5,     0,     0,   124,     0,
       0,     0,     0,     0,    58,    66,    65,    67,    68,    69,
      70,    62,     0,    39,    87,    75,    83,   116,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    51,    52,   157,
     158,   161,   164,   159,   160,   162,   163,     0,     0,     0,
       0,   171,     0,   110,   106,   133,     0,    26,    59,    57,
      19,     0,   134,   119,   118,   103,    94,    92,     0,   146,
      63,    72,     0,    84,    85,    80,     0,     0,   174,   173,
     176,     0,     0,     0,   175,     0,    53,     0,     0,   169,
     170,   172,   113,     0,   139,     0,   132,    22,    23,    26,
       0,     3,    28,   138,     0,     0,     0,    91,     0,    73,
      81,     0,     0,     0,     0,   179,     0,     0,     0,   107,
     111,   108,   109,   144,   130,    25,    60,     0,   135,   120,
     104,     0,   147,    75,    83,     0,   177,   178,   180,    55,
      50,   181,     0,   141,   140,     0,     0,    19,    95,     0,
      74,    82,     0,    54,   112,     0,   131,   136,   127,    45,
       0,     0,   148,   182,   142,   138,   123,    19,   121,     0,
     144,   137,   122,   126,    96,   143,     0,    98,    97,     0,
      99,     0,   100,    78,     0,   101
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   180,    85,    80,    12,     3,     4,    58,    53,
      56,    32,    33,    77,   121,   176,   218,    34,    14,   101,
      35,    36,   110,   156,   207,   236,    37,    79,    38,   179,
     220,   102,   141,   142,   103,   145,   191,   253,   104,   105,
     146,   195,   254,   196,   106,   107,   132,    39,    91,   130,
     226,   281,   296,   298,   299,   301,   303,    40,    60,   225,
      41,    74,   240,   174,   213,   262,   117,    42,    63,    57,
      59,   184,   224,   267,   287,   127,   280,    43,    75,   175,
     265,   215,   128,   223,   248,   285,   216,   243,   264,   275,
     290,   108,   133,   228,   269,    44,   158,    45,    46,    47,
      48,    49,    50,    51,    52,   159,   160,   161,   162,   163,
     164,   165,   166,    66,   198
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -247
static const yytype_int16 yypact[] =
{
      11,  -247,    43,    41,     6,  -247,    23,  -247,  -247,  -247,
    -247,  -247,     8,   184,    24,    68,  -247,  -247,  -247,    45,
      47,  -247,    54,    55,    55,    55,    56,    58,    59,    55,
      61,    63,  -247,    76,  -247,     8,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,    68,   184,     5,  -247,    68,    78,    71,
      72,    69,    70,    74,  -247,    70,  -247,  -247,  -247,    70,
      70,    70,  -247,    81,    82,    85,  -247,  -247,     8,    99,
       8,    68,  -247,  -247,     4,     8,  -247,  -247,   184,    70,
    -247,    86,  -247,  -247,  -247,    87,  -247,  -247,  -247,  -247,
    -247,  -247,    90,    39,    91,  -247,  -247,  -247,  -247,    92,
     128,   103,   104,   105,   114,   126,    70,   113,  -247,  -247,
       8,   151,  -247,  -247,   115,  -247,   116,   119,  -247,   125,
     136,    99,    70,   129,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,    70,  -247,  -247,   146,   -19,  -247,   130,   130,
     130,   132,   133,   140,   130,   141,   155,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,    70,   157,   159,
     160,  -247,   161,  -247,  -247,    70,   175,     8,  -247,  -247,
       8,   176,  -247,  -247,  -247,  -247,  -247,  -247,   164,  -247,
    -247,  -247,    70,  -247,  -247,  -247,    70,    70,  -247,  -247,
    -247,    70,    70,    70,  -247,   166,  -247,   168,   169,  -247,
    -247,  -247,  -247,    42,  -247,   170,  -247,  -247,  -247,     8,
      99,  -247,  -247,   183,   186,    99,    91,  -247,    70,  -247,
    -247,   185,   174,   177,   178,  -247,   128,   187,   190,  -247,
    -247,  -247,  -247,   192,  -247,  -247,  -247,   184,  -247,  -247,
    -247,   193,  -247,   146,   -19,    70,  -247,  -247,  -247,   155,
    -247,  -247,   194,  -247,  -247,   195,   180,     8,  -247,   173,
    -247,  -247,   181,  -247,  -247,    70,  -247,  -247,  -247,   184,
     199,    70,  -247,  -247,  -247,   183,   184,     8,  -247,   198,
     192,  -247,  -247,  -247,  -247,  -247,   188,  -247,  -247,   200,
    -247,   189,  -247,     9,   182,  -247
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,   179,
     -39,   -68,  -246,   158,  -120,  -247,    16,    -3,   -85,   -95,
     -31,  -247,  -247,     3,   -18,  -247,  -247,  -247,  -247,  -247,
    -247,   -87,  -247,  -247,   -64,  -247,   -13,  -247,  -137,    50,
    -247,   -11,  -247,  -247,    48,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,    32,  -247,    10,
    -247,  -247,  -247,  -247,   -40,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,   -38,  -247,  -247,  -247,   -42,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,    36,  -247,  -247,  -247,
    -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,  -247,
    -247,  -247,  -247,    15,   -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -146
static const yytype_int16 yytable[] =
{
      13,   111,   129,   126,    78,   112,   113,   114,   192,   144,
      54,   187,   122,    15,    18,    19,    20,   125,    86,    21,
      22,   278,   193,   194,     1,     7,     8,     9,    10,    11,
      23,    24,    25,    26,    27,    28,    29,    30,    83,    67,
      68,   293,   123,     5,    72,   188,   157,    78,    92,    93,
      84,    54,   172,    21,   124,    16,     6,    31,     7,     8,
       9,    10,    11,    81,   148,   149,   150,   151,   152,   153,
     154,   155,    17,    55,   135,   136,   137,   138,   190,   199,
     200,    92,    93,     6,   204,    94,   139,   140,    61,   177,
      62,    95,    96,    97,    98,    99,   100,    64,    65,    69,
     246,    70,    71,   208,    73,   250,  -128,    76,    87,    92,
      93,   214,   221,    94,    88,    89,   192,   109,    90,    95,
      96,    97,    98,    99,   100,   115,   239,   116,   118,   120,
     131,   251,  -145,   231,   134,   167,   147,   232,   233,   234,
     143,    96,    97,    98,    99,   100,   219,   173,   168,   169,
     148,   149,   150,   151,   152,   153,   154,   155,   170,   171,
     178,   181,   266,   183,   252,   182,   304,    92,    93,   185,
     186,    94,   157,   197,   189,   201,   202,    95,    96,    97,
      98,    99,   100,   203,   205,    92,    93,   206,   219,   -78,
     209,   272,   210,   211,   289,   -78,   -78,   -78,   -78,   -78,
     -78,     7,     8,     9,    10,    11,   217,   212,   227,   222,
     235,   284,   237,   238,   244,   247,   249,   255,   256,   282,
     260,   257,   258,   261,   263,   283,   268,   274,   276,   277,
     288,   294,   305,    82,   300,   245,   119,   297,   302,   259,
     270,   273,   229,   271,   230,   241,   292,   291,   295,   242,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   279,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   286,     0,     0,     0,
       0,     0,     0,   286
};

static const yytype_int16 yycheck[] =
{
       3,    65,    89,    88,    35,    69,    70,    71,   145,   104,
      13,   131,    80,     3,     6,     7,     8,    85,    57,    11,
      12,   267,    41,    42,    13,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    33,    24,
      25,   287,    81,     0,    29,   132,   110,    78,    39,    40,
      45,    54,   116,    11,    50,    49,    15,    49,    17,    18,
      19,    20,    21,    53,    22,    23,    24,    25,    26,    27,
      28,    29,    49,    49,    35,    36,    37,    38,   142,   149,
     150,    39,    40,    15,   154,    43,    47,    48,    43,   120,
      43,    49,    50,    51,    52,    53,    54,    43,    43,    43,
     220,    43,    43,   167,    43,   225,    43,    31,    30,    39,
      40,   175,   180,    43,    43,    43,   253,    43,    49,    49,
      50,    51,    52,    53,    54,    44,   213,    45,    43,    30,
      44,   226,    45,   197,    44,    32,    44,   201,   202,   203,
      49,    50,    51,    52,    53,    54,   177,    34,    44,    44,
      22,    23,    24,    25,    26,    27,    28,    29,    44,    33,
       9,    46,   247,    44,   228,    49,   303,    39,    40,    44,
      34,    43,   236,    43,    45,    43,    43,    49,    50,    51,
      52,    53,    54,    43,    43,    39,    40,    32,   219,    43,
      33,   255,    33,    33,   281,    49,    50,    51,    52,    53,
      54,    17,    18,    19,    20,    21,    31,    46,    44,    33,
      44,   275,    44,    44,    44,    32,    30,    32,    44,    46,
      33,    44,    44,    33,    32,    44,    33,    33,    33,    49,
      31,    33,    50,    54,    34,   219,    78,    49,    49,   236,
     253,   259,   192,   254,   196,   213,   286,   285,   290,   213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   267,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   279,    -1,    -1,    -1,
      -1,    -1,    -1,   286
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    56,    61,    62,     0,    15,    17,    18,    19,
      20,    21,    60,    72,    73,   124,    49,    49,     6,     7,
       8,    11,    12,    22,    23,    24,    25,    26,    27,    28,
      29,    49,    66,    67,    72,    75,    76,    81,    83,   102,
     112,   115,   122,   132,   150,   152,   153,   154,   155,   156,
     157,   158,   159,    64,    72,    49,    65,   124,    63,   125,
     113,    43,    43,   123,    43,    43,   168,   168,   168,    43,
      43,    43,   168,    43,   116,   133,    31,    68,    75,    82,
      59,   124,    64,    33,    45,    58,    65,    30,    43,    43,
      49,   103,    39,    40,    43,    49,    50,    51,    52,    53,
      54,    74,    86,    89,    93,    94,    99,   100,   146,    43,
      77,    89,    89,    89,    89,    44,    45,   121,    43,    68,
      30,    69,    66,    65,    50,    66,    73,   130,   137,    86,
     104,    44,   101,   147,    44,    35,    36,    37,    38,    47,
      48,    87,    88,    49,    74,    90,    95,    44,    22,    23,
      24,    25,    26,    27,    28,    29,    78,    89,   151,   160,
     161,   162,   163,   164,   165,   166,   167,    32,    44,    44,
      44,    33,    89,    34,   118,   134,    70,    75,     9,    84,
      57,    46,    49,    44,   126,    44,    34,    69,    86,    45,
      89,    91,    93,    41,    42,    96,    98,    43,   169,   169,
     169,    43,    43,    43,   169,    43,    32,    79,    89,    33,
      33,    33,    46,   119,    89,   136,   141,    31,    71,    75,
      85,    66,    33,   138,   127,   114,   105,    44,   148,    94,
      99,    89,    89,    89,    89,    44,    80,    44,    44,    86,
     117,   122,   151,   142,    44,    71,    69,    32,   139,    30,
      69,    74,    89,    92,    97,    32,    44,    44,    44,    78,
      33,    33,   120,    32,   143,   135,    73,   128,    33,   149,
      91,    96,    89,    79,    33,   144,    33,    49,    67,    72,
     131,   106,    46,    44,    89,   140,    72,   129,    31,    86,
     145,   139,   129,    67,    33,   143,   107,    49,   108,   109,
      34,   110,    49,   111,    93,    50
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 86 "Trex.y"
    { set_start_function(main_func); fillQuadruple_main(); ;}
    break;

  case 3:
#line 86 "Trex.y"
    { generate_obj(); cout << "EXITO" << endl; ;}
    break;

  case 4:
#line 87 "Trex.y"
    { set_start_function(main_func); fillQuadruple_main(); ;}
    break;

  case 5:
#line 87 "Trex.y"
    { generate_obj(); cout << "EXITO" << endl; ;}
    break;

  case 6:
#line 88 "Trex.y"
    { set_start_function(main_func); fillQuadruple_main(); ;}
    break;

  case 7:
#line 88 "Trex.y"
    { generate_obj(); cout << "EXITO" << endl; ;}
    break;

  case 8:
#line 89 "Trex.y"
    { set_start_function(main_func); fillQuadruple_main(); ;}
    break;

  case 9:
#line 89 "Trex.y"
    { generate_obj(); cout << "EXITO" << endl; ;}
    break;

  case 10:
#line 93 "Trex.y"
    { initialize(); generateQuadruple_main(); ;}
    break;

  case 11:
#line 93 "Trex.y"
    { function_name = yylval.sval; main_func = function_name; insert_to_procs_table(function_name); main_function_name(function_name); set_current_function("0", function_name);;}
    break;

  case 17:
#line 107 "Trex.y"
    { set_fin_main(); ;}
    break;

  case 27:
#line 135 "Trex.y"
    { name = (yyvsp[(2) - (3)].sval); insert_to_vars_table(name,var_type,function_name); ;}
    break;

  case 28:
#line 136 "Trex.y"
    { name = (yyvsp[(2) - (6)].sval);  size = (yyvsp[(4) - (6)].sval); insert_arr_to_vars_table(name,var_type, size, function_name); ;}
    break;

  case 29:
#line 140 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 30:
#line 141 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 31:
#line 142 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 32:
#line 143 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 33:
#line 144 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 34:
#line 148 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "0"); push_to_pilaTipos_directly("10"); ;}
    break;

  case 35:
#line 149 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "1"); push_to_pilaTipos_directly("11"); ;}
    break;

  case 36:
#line 150 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "2"); push_to_pilaTipos_directly("12"); ;}
    break;

  case 37:
#line 151 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "3"); push_to_pilaTipos_directly("13"); ;}
    break;

  case 38:
#line 152 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "4"); push_to_pilaTipos_directly("14"); ;}
    break;

  case 39:
#line 153 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5");  push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 49:
#line 169 "Trex.y"
    { push_to_pilaOperadores("print"); ;}
    break;

  case 51:
#line 173 "Trex.y"
    { generateQuadruple_print(); ;}
    break;

  case 52:
#line 174 "Trex.y"
    { generateQuadruple_print(); ;}
    break;

  case 53:
#line 178 "Trex.y"
    { push_to_pilaOperadores("print"); ;}
    break;

  case 56:
#line 183 "Trex.y"
    { generateQuadruple_if(); ;}
    break;

  case 57:
#line 183 "Trex.y"
    { generate_fin_if(); ;}
    break;

  case 59:
#line 191 "Trex.y"
    { generateQuadruple_else(); ;}
    break;

  case 63:
#line 200 "Trex.y"
    { quadruple_relational(); ;}
    break;

  case 65:
#line 205 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 66:
#line 206 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 67:
#line 207 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 68:
#line 208 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 69:
#line 209 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 70:
#line 210 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 71:
#line 214 "Trex.y"
    { quadruple_add_sub(); ;}
    break;

  case 73:
#line 218 "Trex.y"
    { quadruple_add_sub(); ;}
    break;

  case 76:
#line 223 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 77:
#line 224 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 79:
#line 229 "Trex.y"
    { quadruple_mult_div(); ;}
    break;

  case 81:
#line 233 "Trex.y"
    { quadruple_mult_div(); ;}
    break;

  case 84:
#line 238 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 85:
#line 239 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 90:
#line 250 "Trex.y"
    { push_to_pilaOperadores("#"); ;}
    break;

  case 91:
#line 250 "Trex.y"
    { pop_of_pilaOperadores(); ;}
    break;

  case 92:
#line 254 "Trex.y"
    { generate_fin_for(); ;}
    break;

  case 93:
#line 258 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 94:
#line 258 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 95:
#line 258 "Trex.y"
    { generateQuadruple_asignacion(); ;}
    break;

  case 96:
#line 258 "Trex.y"
    { generateQuadruple_for2(); ;}
    break;

  case 98:
#line 262 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 99:
#line 262 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 100:
#line 262 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (5)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (5)].sval)); ;}
    break;

  case 101:
#line 262 "Trex.y"
    { push_to_pilaOperandos(yylval.sval, "0");  generateQuadruple_for3(); ;}
    break;

  case 102:
#line 266 "Trex.y"
    { push_quadruple_index_to_pilaSaltos(); ;}
    break;

  case 103:
#line 266 "Trex.y"
    { generateQuadruple_while(); ;}
    break;

  case 104:
#line 266 "Trex.y"
    { generate_fin_while(); ;}
    break;

  case 105:
#line 270 "Trex.y"
    { name = (yyvsp[(1) - (1)].sval); push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 110:
#line 280 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 111:
#line 280 "Trex.y"
    { quadruple_relational(); ;}
    break;

  case 113:
#line 284 "Trex.y"
    { verify_arr_limit(name); generateQuadruple_array(); ;}
    break;

  case 115:
#line 289 "Trex.y"
    { push_to_pilaOperadores("read"); ;}
    break;

  case 116:
#line 289 "Trex.y"
    { generateQuadruple_read(); ;}
    break;

  case 117:
#line 293 "Trex.y"
    { function_name = yylval.sval; insert_to_procs_table(function_name); set_current_function("1", function_name); reset_conts(); ;}
    break;

  case 119:
#line 297 "Trex.y"
    { reset_param_counter(); ;}
    break;

  case 120:
#line 297 "Trex.y"
    { set_start_function(function_name); ;}
    break;

  case 121:
#line 297 "Trex.y"
    { set_current_function("0", main_func); set_fin_function(function_name, "1"); ;}
    break;

  case 128:
#line 316 "Trex.y"
    { function_called = (yyvsp[(1) - (1)].sval); verify_function_name(function_called); ;}
    break;

  case 129:
#line 316 "Trex.y"
    { generate_activation_record(function_called); ;}
    break;

  case 130:
#line 316 "Trex.y"
    { reset_param_counter(); ;}
    break;

  case 131:
#line 316 "Trex.y"
    { generate_fin_llamada(function_called); ;}
    break;

  case 134:
#line 325 "Trex.y"
    { name = yylval.sval; insert_to_vars_table(name,var_type,function_name); count_params(); insert_param_type(function_name, var_type); ;}
    break;

  case 136:
#line 329 "Trex.y"
    { name = yylval.sval; insert_to_vars_table(name,var_type,function_name); count_params(); insert_param_type(function_name, var_type); ;}
    break;

  case 139:
#line 334 "Trex.y"
    { verify_parameters(function_called); ;}
    break;

  case 141:
#line 338 "Trex.y"
    { count_params(); ;}
    break;

  case 142:
#line 338 "Trex.y"
    { verify_parameters(function_called); ;}
    break;

  case 145:
#line 343 "Trex.y"
    { name = (yyvsp[(1) - (1)].sval); push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 146:
#line 343 "Trex.y"
    { push_to_pilaOperadores("#"); ;}
    break;

  case 147:
#line 343 "Trex.y"
    { pop_of_pilaOperadores(); ;}
    break;

  case 148:
#line 343 "Trex.y"
    { verify_arr_limit(name); generateQuadruple_array(); ;}
    break;

  case 165:
#line 369 "Trex.y"
    { cout << ""; generateQuadruple_min(); ;}
    break;

  case 166:
#line 373 "Trex.y"
    { cout << ""; generateQuadruple_max(); ;}
    break;

  case 167:
#line 377 "Trex.y"
    { cout << ""; generateQuadruple_pow(); ;}
    break;

  case 168:
#line 381 "Trex.y"
    { cout << ""; generateQuadruple_remainder(); ;}
    break;

  case 169:
#line 385 "Trex.y"
    { cout << ""; generateQuadruple_floor(); ;}
    break;

  case 170:
#line 389 "Trex.y"
    { cout << ""; generateQuadruple_ceiling(); ;}
    break;

  case 171:
#line 392 "Trex.y"
    { cout << ""; generateQuadruple_random(); ;}
    break;

  case 172:
#line 396 "Trex.y"
    { cout << ""; generateQuadruple_sqrt(); ;}
    break;

  case 173:
#line 400 "Trex.y"
    { cout << ""; generateQuadruple_min(); ;}
    break;

  case 174:
#line 404 "Trex.y"
    { cout << ""; generateQuadruple_max(); ;}
    break;

  case 175:
#line 408 "Trex.y"
    { cout << ""; generateQuadruple_pow(); ;}
    break;

  case 176:
#line 412 "Trex.y"
    { cout << ""; generateQuadruple_remainder(); ;}
    break;

  case 177:
#line 416 "Trex.y"
    { cout << ""; generateQuadruple_floor(); ;}
    break;

  case 178:
#line 420 "Trex.y"
    { cout << ""; generateQuadruple_ceiling(); ;}
    break;

  case 179:
#line 423 "Trex.y"
    { cout << ""; generateQuadruple_random(); ;}
    break;

  case 180:
#line 427 "Trex.y"
    { cout << ""; generateQuadruple_sqrt(); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2241 "Trex.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 440 "Trex.y"


main(int argc, char *argv[]) {

	if ( argc != 2 ){
		printf( "Se necesita un archivo\n");
		return -1;
	}

	FILE *myfile = fopen(argv[1], "r");

	if (!myfile) {
		cout << "No se puede abrir el archivo que especificaste" << endl;
		return -1;
	}

	yyin = myfile;

	do {
		yyparse();
	} while (!feof(yyin));
}

void yyerror(const char *s) {
	/*cout << "Error: " << s << endl;*/
	printf("Error near line %d: %s near %s \n", yylineno, s, yytext);
	exit(-1);
}
