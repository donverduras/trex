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
     REMINDER = 279,
     FLOOR = 280,
     CEILING = 281,
     SQRT = 282,
     POW = 283,
     SUBSTRING = 284,
     STRINGAPPEND = 285,
     RANDOM = 286,
     LLAVEIZQ = 287,
     LLAVEDER = 288,
     COMA = 289,
     PUNTOYCOMA = 290,
     IGUAL = 291,
     MENORQUE = 292,
     MAYORQUE = 293,
     DIFERENTE = 294,
     IGUALIGUAL = 295,
     SUMA = 296,
     RESTA = 297,
     MULTIPLICACION = 298,
     DIVISION = 299,
     PARENTESISIZQ = 300,
     PARENTESISDER = 301,
     CORIZQ = 302,
     CORDER = 303,
     AND = 304,
     OR = 305,
     CTE_ID = 306,
     CTE_INT = 307,
     CTE_FLOAT = 308,
     CTE_STRING = 309,
     CTE_BOOLEAN = 310,
     CTE_CHAR = 311
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
#define REMINDER 279
#define FLOOR 280
#define CEILING 281
#define SQRT 282
#define POW 283
#define SUBSTRING 284
#define STRINGAPPEND 285
#define RANDOM 286
#define LLAVEIZQ 287
#define LLAVEDER 288
#define COMA 289
#define PUNTOYCOMA 290
#define IGUAL 291
#define MENORQUE 292
#define MAYORQUE 293
#define DIFERENTE 294
#define IGUALIGUAL 295
#define SUMA 296
#define RESTA 297
#define MULTIPLICACION 298
#define DIVISION 299
#define PARENTESISIZQ 300
#define PARENTESISDER 301
#define CORIZQ 302
#define CORDER 303
#define AND 304
#define OR 305
#define CTE_ID 306
#define CTE_INT 307
#define CTE_FLOAT 308
#define CTE_STRING 309
#define CTE_BOOLEAN 310
#define CTE_CHAR 311




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
#line 25 "Trex.y"
{
	char *sval;
}
/* Line 193 of yacc.c.  */
#line 235 "Trex.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 248 "Trex.tab.c"

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
#define YYLAST   205

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  91
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNRULES -- Number of states.  */
#define YYNSTATES  225

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    15,    20,    23,    24,    25,    31,
      34,    35,    38,    39,    42,    45,    46,    49,    50,    54,
      57,    58,    61,    62,    67,    74,    77,    78,    80,    82,
      84,    86,    88,    90,    92,    94,    96,    98,   100,   102,
     104,   106,   108,   110,   112,   114,   116,   117,   125,   127,
     128,   133,   134,   135,   140,   145,   146,   150,   151,   154,
     157,   158,   160,   162,   164,   166,   168,   170,   171,   175,
     176,   181,   182,   184,   186,   187,   191,   192,   197,   198,
     200,   202,   204,   207,   209,   211,   212,   217,   223,   224,
     225,   226,   227,   239,   240,   241,   242,   251,   252,   253,
     261,   262,   267,   269,   271,   272,   273,   279,   283,   284,
     289,   290,   297,   298,   299,   306,   309,   310,   312,   313,
     317,   319,   320,   321,   322,   331,   333,   334,   335,   340,
     341,   347,   348,   349,   353,   354,   355,   361,   362,   363,
     364,   365
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      58,     0,    -1,    59,    70,    62,   122,    63,    64,    -1,
      59,   122,    63,    64,    -1,    59,    70,    62,    64,    -1,
      59,    64,    -1,    -1,    -1,    13,    60,    51,    61,    32,
      -1,    70,    62,    -1,    -1,   122,    63,    -1,    -1,    65,
      33,    -1,    74,    66,    -1,    -1,    74,    66,    -1,    -1,
      32,    68,    33,    -1,    74,    69,    -1,    -1,    74,    69,
      -1,    -1,    72,    51,    71,    35,    -1,    72,    51,    47,
      52,    48,    35,    -1,    36,    73,    -1,    -1,    17,    -1,
      18,    -1,    19,    -1,    20,    -1,    21,    -1,    52,    -1,
      53,    -1,    54,    -1,    55,    -1,    56,    -1,    51,    -1,
     114,    -1,    80,    -1,    75,    -1,   101,    -1,   111,    -1,
      70,    -1,   121,    -1,   130,    -1,    -1,    12,    45,    76,
      77,    78,    46,    35,    -1,    88,    -1,    -1,    34,    79,
      77,    78,    -1,    -1,    -1,    82,    81,    67,    83,    -1,
       8,    45,    85,    46,    -1,    -1,     9,    84,    67,    -1,
      -1,    88,    86,    -1,    87,    88,    -1,    -1,    38,    -1,
      37,    -1,    39,    -1,    40,    -1,    49,    -1,    50,    -1,
      -1,    93,    89,    90,    -1,    -1,    92,    93,    91,    90,
      -1,    -1,    41,    -1,    42,    -1,    -1,    98,    94,    95,
      -1,    -1,    97,    98,    96,    95,    -1,    -1,    43,    -1,
      44,    -1,    99,    -1,    92,    73,    -1,    73,    -1,   144,
      -1,    -1,    45,   100,    85,    46,    -1,     7,    45,   102,
      46,    67,    -1,    -1,    -1,    -1,    -1,    51,   103,    36,
     104,    73,    35,   105,    85,    35,   106,   107,    -1,    -1,
      -1,    -1,    51,   108,    36,   109,    51,   110,    92,    52,
      -1,    -1,    -1,     6,   112,    45,    85,    46,   113,    67,
      -1,    -1,    51,   115,   120,   117,    -1,    85,    -1,   121,
      -1,    -1,    -1,    36,   118,   116,   119,    35,    -1,    47,
      88,    48,    -1,    -1,    11,    45,    46,    35,    -1,    -1,
      15,    51,   123,    45,   128,   124,    -1,    -1,    -1,    46,
     125,    32,   126,   129,    33,    -1,    70,   127,    -1,    -1,
     135,    -1,    -1,    70,   127,    65,    -1,    65,    -1,    -1,
      -1,    -1,    51,   131,    45,   132,   134,    46,   133,    35,
      -1,   139,    -1,    -1,    -1,    72,    51,   136,   137,    -1,
      -1,    34,    72,    51,   138,   137,    -1,    -1,    -1,    88,
     140,   141,    -1,    -1,    -1,    34,   142,    88,   143,   141,
      -1,    -1,    -1,    -1,    -1,    51,   145,    47,   146,    88,
     147,    48,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,    88,    89,    90,    94,    94,    94,    98,
      99,   103,   104,   108,   112,   113,   117,   118,   122,   126,
     127,   131,   132,   136,   137,   141,   142,   146,   147,   148,
     149,   150,   154,   155,   156,   157,   158,   159,   163,   164,
     165,   166,   167,   168,   169,   170,   174,   174,   178,   182,
     182,   183,   187,   187,   191,   195,   195,   196,   200,   204,
     205,   209,   210,   211,   212,   213,   214,   218,   218,   222,
     222,   223,   227,   228,   232,   232,   236,   236,   237,   241,
     242,   246,   247,   248,   249,   253,   253,   257,   261,   261,
     261,   261,   261,   265,   265,   265,   265,   269,   269,   269,
     273,   273,   277,   278,   282,   282,   282,   286,   287,   291,
     295,   295,   299,   299,   299,   303,   304,   308,   309,   313,
     314,   318,   318,   318,   318,   322,   323,   327,   327,   331,
     331,   332,   336,   336,   340,   340,   340,   341,   345,   345,
     345,   345
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
  "MIN", "REMINDER", "FLOOR", "CEILING", "SQRT", "POW", "SUBSTRING",
  "STRINGAPPEND", "RANDOM", "LLAVEIZQ", "LLAVEDER", "COMA", "PUNTOYCOMA",
  "IGUAL", "MENORQUE", "MAYORQUE", "DIFERENTE", "IGUALIGUAL", "SUMA",
  "RESTA", "MULTIPLICACION", "DIVISION", "PARENTESISIZQ", "PARENTESISDER",
  "CORIZQ", "CORDER", "AND", "OR", "CTE_ID", "CTE_INT", "CTE_FLOAT",
  "CTE_STRING", "CTE_BOOLEAN", "CTE_CHAR", "$accept", "programa",
  "programa_a", "@1", "@2", "programa_b", "programa_c", "programa_d",
  "bloque", "b", "bloque2", "bloque21", "c", "vars", "vars2", "tipo",
  "var_cte", "estatuto", "escritura", "@3", "escritura_a", "d", "@4",
  "condicion", "@5", "condicion_a", "condicion_b", "@6", "expresion",
  "expresion_b", "expresion_a", "exp", "@7", "e", "@8", "sumaresta",
  "termino", "@9", "f", "@10", "multdiv", "factor", "factor_a", "@11",
  "loopfor", "bloque_for", "@12", "@13", "@14", "@15", "bloque_for_2",
  "@16", "@17", "@18", "loopwhile", "@19", "@20", "asignacion", "@21",
  "asignacion_b", "asignacion_c", "@22", "@23", "asignacion_d", "lectura",
  "funcion", "@24", "funcion_a", "@25", "@26", "funcion_b", "funcion_c",
  "funcion_d", "llamada", "@27", "@28", "@29", "llamada_2", "param", "@30",
  "g", "@31", "param2", "@32", "h", "@33", "@34", "arr", "@35", "@36",
  "@37", 0
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
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    60,    61,    59,    62,
      62,    63,    63,    64,    65,    65,    66,    66,    67,    68,
      68,    69,    69,    70,    70,    71,    71,    72,    72,    72,
      72,    72,    73,    73,    73,    73,    73,    73,    74,    74,
      74,    74,    74,    74,    74,    74,    76,    75,    77,    79,
      78,    78,    81,    80,    82,    84,    83,    83,    85,    86,
      86,    87,    87,    87,    87,    87,    87,    89,    88,    91,
      90,    90,    92,    92,    94,    93,    96,    95,    95,    97,
      97,    98,    98,    98,    98,   100,    99,   101,   103,   104,
     105,   106,   102,   108,   109,   110,   107,   112,   113,   111,
     115,   114,   116,   116,   118,   119,   117,   120,   120,   121,
     123,   122,   125,   126,   124,   127,   127,   128,   128,   129,
     129,   131,   132,   133,   130,   134,   134,   136,   135,   138,
     137,   137,   140,   139,   142,   143,   141,   141,   145,   146,
     147,   144
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     4,     4,     2,     0,     0,     5,     2,
       0,     2,     0,     2,     2,     0,     2,     0,     3,     2,
       0,     2,     0,     4,     6,     2,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     7,     1,     0,
       4,     0,     0,     4,     4,     0,     3,     0,     2,     2,
       0,     1,     1,     1,     1,     1,     1,     0,     3,     0,
       4,     0,     1,     1,     0,     3,     0,     4,     0,     1,
       1,     1,     2,     1,     1,     0,     4,     5,     0,     0,
       0,     0,    11,     0,     0,     0,     8,     0,     0,     7,
       0,     4,     1,     1,     0,     0,     5,     3,     0,     4,
       0,     6,     0,     0,     6,     2,     0,     1,     0,     3,
       1,     0,     0,     0,     8,     1,     0,     0,     4,     0,
       5,     0,     0,     3,     0,     0,     5,     0,     0,     0,
       0,     7
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     0,    15,     0,     1,    97,     0,     0,     0,
       0,     0,    27,    28,    29,    30,    31,   100,     5,     0,
      10,     0,    17,    40,    39,    52,    41,    42,    38,    44,
      12,    45,     7,     0,     0,     0,     0,    46,   110,   108,
       0,    13,    15,    10,    26,    14,    43,    17,     0,    15,
      12,     0,     0,    88,     0,    72,    73,    85,    37,    32,
      33,    34,    35,    36,    83,     0,    60,     0,    67,    74,
      81,    84,     0,     0,     0,     0,     0,   122,     4,    12,
       9,     0,     0,     0,    16,    20,    57,     3,    11,     8,
       0,     0,     0,     0,     0,    54,    62,    61,    63,    64,
      65,    66,    58,     0,    37,    82,    71,    78,   109,    51,
      48,   118,     0,   104,   101,   126,    15,    25,     0,    23,
       0,    22,    55,    53,    98,    89,    87,     0,   139,    59,
      68,     0,    79,    80,    75,     0,    49,     0,     0,     0,
     117,   107,     0,   132,     0,   125,     2,     0,    18,    19,
      22,     0,     0,     0,    86,     0,    69,    76,     0,     0,
     127,   112,   111,   102,   105,   103,   137,   123,    24,    21,
      56,    99,     0,   140,    71,    78,    51,    47,   131,     0,
       0,   134,   133,     0,    90,     0,    70,    77,    50,     0,
     128,   113,   106,     0,   124,     0,   141,     0,    15,   135,
       0,   129,   120,    43,     0,   137,    91,   131,   116,    15,
     114,   136,     0,   130,   115,   119,    93,    92,     0,    94,
       0,    95,     0,     0,    96
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    51,    42,    49,    18,    19,    45,
      86,   120,   149,    46,    83,    21,    64,    22,    23,    73,
     109,   137,   158,    24,    48,    25,   123,   151,    65,   102,
     103,    66,   106,   130,   174,    67,    68,   107,   134,   175,
     135,    69,    70,    93,    26,    54,    91,   153,   195,   212,
     217,   218,   220,   222,    27,    33,   152,    28,    39,   164,
     114,   142,   180,    76,    29,    50,    74,   162,   179,   198,
     209,   139,   204,    31,    40,   115,   183,   144,   140,   178,
     190,   207,   145,   166,   182,   193,   205,    71,    94,   155,
     185
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -171
static const yytype_int16 yypact[] =
{
      18,  -171,    32,     4,   -15,  -171,  -171,    -7,    -4,    -2,
      -1,    -5,  -171,  -171,  -171,  -171,  -171,     6,  -171,    23,
     120,     7,    42,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
      51,  -171,  -171,    12,    16,    73,    24,  -171,  -171,    26,
      29,  -171,     4,   120,   -10,  -171,  -171,    42,    39,    42,
      51,    43,    73,  -171,    30,  -171,  -171,  -171,    35,  -171,
    -171,  -171,  -171,  -171,  -171,    37,    40,    80,  -171,  -171,
    -171,  -171,    49,    73,    52,    73,    60,  -171,  -171,    51,
    -171,    80,    47,    65,  -171,    42,    78,  -171,  -171,  -171,
      56,    67,    39,    73,    63,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,    73,  -171,  -171,   -12,    -9,  -171,    77,
    -171,   120,    64,  -171,  -171,    73,    42,  -171,    68,  -171,
      84,    42,  -171,  -171,  -171,  -171,  -171,    75,  -171,  -171,
    -171,    73,  -171,  -171,  -171,    73,  -171,    76,    62,    96,
    -171,  -171,    53,  -171,    97,  -171,  -171,   110,  -171,  -171,
      42,    39,    39,    80,  -171,    73,  -171,  -171,    73,   111,
    -171,  -171,  -171,  -171,  -171,  -171,    85,  -171,  -171,  -171,
    -171,  -171,   112,  -171,   -12,    -9,    77,  -171,   114,   117,
     115,  -171,  -171,   116,  -171,   104,  -171,  -171,  -171,   120,
    -171,  -171,  -171,    73,  -171,    73,  -171,   102,    42,  -171,
     119,  -171,  -171,   120,   122,    85,  -171,   114,   120,    42,
    -171,  -171,   105,  -171,  -171,  -171,  -171,  -171,   121,  -171,
     107,  -171,   -12,   108,  -171
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,  -171,  -171,  -171,   118,   -32,   -35,  -170,   123,
     -83,  -171,     9,    -3,  -171,  -103,   -61,   -20,  -171,  -171,
       5,   -14,  -171,  -171,  -171,  -171,  -171,  -171,   -51,  -171,
    -171,   -70,  -171,    -8,  -171,  -102,    33,  -171,    -6,  -171,
    -171,    36,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,  -171,    25,    10,  -171,  -171,  -171,  -171,
     -43,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
     -39,  -171,  -171,  -171,   -33,  -171,  -171,  -171,  -171,  -171,
    -171
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -139
static const yytype_int16 yytable[] =
{
      20,    90,    47,   110,   131,   112,   105,    78,   138,   126,
       6,     7,     8,    30,    87,     9,    10,    43,    88,    11,
     117,    12,    13,    14,    15,    16,    81,    47,   202,    55,
      56,     1,     5,   129,   132,   133,    32,    82,    34,   215,
      43,    35,   127,    36,    37,   143,    38,   116,     6,     7,
       8,  -121,    79,     9,    10,    17,    41,    52,    44,    12,
      13,    14,    15,    16,     9,   121,    11,    53,   170,   171,
      72,    85,   131,    75,    77,    89,    92,    96,    97,    98,
      99,   146,  -138,    95,   108,   173,   197,   122,   110,   100,
     101,   163,   172,    17,    55,    56,   113,   111,    57,   118,
     119,   150,   124,   125,    58,    59,    60,    61,    62,    63,
     128,   136,   141,   160,    55,    56,   147,   148,    57,   181,
     223,   154,   159,   199,    58,    59,    60,    61,    62,    63,
     150,   104,    59,    60,    61,    62,    63,    12,    13,    14,
      15,    16,   161,   167,   200,   168,   177,   184,   189,   191,
     192,   194,   196,   201,   206,   210,   216,   219,   221,   169,
     224,    80,   188,   176,   156,   214,   186,   165,   213,   187,
      84,   157,   211,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   203,     0,     0,     0,     0,
     208,     0,     0,     0,     0,   208
};

static const yytype_int16 yycheck[] =
{
       3,    52,    22,    73,   106,    75,    67,    42,   111,    92,
       6,     7,     8,     3,    49,    11,    12,    20,    50,    15,
      81,    17,    18,    19,    20,    21,    36,    47,   198,    41,
      42,    13,     0,   103,    43,    44,    51,    47,    45,   209,
      43,    45,    93,    45,    45,   115,    51,    79,     6,     7,
       8,    45,    42,    11,    12,    51,    33,    45,    51,    17,
      18,    19,    20,    21,    11,    85,    15,    51,   151,   152,
      46,    32,   174,    47,    45,    32,    46,    37,    38,    39,
      40,   116,    47,    46,    35,   155,   189,     9,   158,    49,
      50,   142,   153,    51,    41,    42,    36,    45,    45,    52,
      35,   121,    46,    36,    51,    52,    53,    54,    55,    56,
      47,    34,    48,    51,    41,    42,    48,    33,    45,    34,
     222,    46,    46,   193,    51,    52,    53,    54,    55,    56,
     150,    51,    52,    53,    54,    55,    56,    17,    18,    19,
      20,    21,    46,    46,   195,    35,    35,    35,    34,    32,
      35,    35,    48,    51,    35,    33,    51,    36,    51,   150,
      52,    43,   176,   158,   131,   208,   174,   142,   207,   175,
      47,   135,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,    -1,
     203,    -1,    -1,    -1,    -1,   208
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    58,    59,    60,     0,     6,     7,     8,    11,
      12,    15,    17,    18,    19,    20,    21,    51,    64,    65,
      70,    72,    74,    75,    80,    82,   101,   111,   114,   121,
     122,   130,    51,   112,    45,    45,    45,    45,    51,   115,
     131,    33,    62,    70,    51,    66,    70,    74,    81,    63,
     122,    61,    45,    51,   102,    41,    42,    45,    51,    52,
      53,    54,    55,    56,    73,    85,    88,    92,    93,    98,
      99,   144,    46,    76,   123,    47,   120,    45,    64,   122,
      62,    36,    47,    71,    66,    32,    67,    64,    63,    32,
      85,   103,    46,   100,   145,    46,    37,    38,    39,    40,
      49,    50,    86,    87,    51,    73,    89,    94,    35,    77,
      88,    45,    88,    36,   117,   132,    63,    73,    52,    35,
      68,    74,     9,    83,    46,    36,    67,    85,    47,    88,
      90,    92,    43,    44,    95,    97,    34,    78,    72,   128,
     135,    48,   118,    88,   134,   139,    64,    48,    33,    69,
      74,    84,   113,   104,    46,   146,    93,    98,    79,    46,
      51,    46,   124,    85,   116,   121,   140,    46,    35,    69,
      67,    67,    73,    88,    91,    96,    77,    35,   136,   125,
     119,    34,   141,   133,    35,   147,    90,    95,    78,    34,
     137,    32,    35,   142,    35,   105,    48,    72,   126,    88,
      85,    51,    65,    70,   129,   143,    35,   138,    70,   127,
      33,   141,   106,   137,   127,    65,    51,   107,   108,    36,
     109,    51,   110,    92,    52
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
#line 87 "Trex.y"
    {cout << "EXITO" << endl;;}
    break;

  case 3:
#line 88 "Trex.y"
    {cout << "EXITO" << endl;;}
    break;

  case 4:
#line 89 "Trex.y"
    {cout << "EXITO" << endl;;}
    break;

  case 5:
#line 90 "Trex.y"
    {cout << "EXITO" << endl;;}
    break;

  case 6:
#line 94 "Trex.y"
    { initialize(); ;}
    break;

  case 7:
#line 94 "Trex.y"
    { function_name = yylval.sval; insert_to_procs_table(function_name); main_function_name(function_name); set_current_function("0");;}
    break;

  case 23:
#line 136 "Trex.y"
    { name = (yyvsp[(2) - (4)].sval); insert_to_vars_table(name,var_type); ;}
    break;

  case 24:
#line 137 "Trex.y"
    { name = (yyvsp[(2) - (6)].sval);  size = (yyvsp[(4) - (6)].sval); insert_arr_to_vars_table(name,var_type, size); ;}
    break;

  case 27:
#line 146 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 28:
#line 147 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 29:
#line 148 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 30:
#line 149 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 31:
#line 150 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 32:
#line 154 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "0"); push_to_pilaTipos_directly("10"); ;}
    break;

  case 33:
#line 155 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "1"); push_to_pilaTipos_directly("11"); ;}
    break;

  case 34:
#line 156 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "2"); push_to_pilaTipos_directly("12"); ;}
    break;

  case 35:
#line 157 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "3"); push_to_pilaTipos_directly("13"); ;}
    break;

  case 36:
#line 158 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "4"); push_to_pilaTipos_directly("14"); ;}
    break;

  case 37:
#line 159 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5");  push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 46:
#line 174 "Trex.y"
    { push_to_pilaOperadores("print"); ;}
    break;

  case 48:
#line 178 "Trex.y"
    { generateQuadruple_print(); ;}
    break;

  case 49:
#line 182 "Trex.y"
    { push_to_pilaOperadores("print"); ;}
    break;

  case 52:
#line 187 "Trex.y"
    { generateQuadruple_if(); ;}
    break;

  case 53:
#line 187 "Trex.y"
    { generate_fin_if(); ;}
    break;

  case 55:
#line 195 "Trex.y"
    { generateQuadruple_else(); ;}
    break;

  case 59:
#line 204 "Trex.y"
    { quadruple_relational(); ;}
    break;

  case 61:
#line 209 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 62:
#line 210 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 63:
#line 211 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 64:
#line 212 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 65:
#line 213 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 66:
#line 214 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 67:
#line 218 "Trex.y"
    { quadruple_add_sub(); ;}
    break;

  case 69:
#line 222 "Trex.y"
    { quadruple_add_sub(); ;}
    break;

  case 72:
#line 227 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 73:
#line 228 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 74:
#line 232 "Trex.y"
    { quadruple_mult_div(); ;}
    break;

  case 76:
#line 236 "Trex.y"
    { quadruple_mult_div(); ;}
    break;

  case 79:
#line 241 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 80:
#line 242 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 85:
#line 253 "Trex.y"
    { push_to_pilaOperadores("#"); ;}
    break;

  case 86:
#line 253 "Trex.y"
    { pop_of_pilaOperadores(); ;}
    break;

  case 87:
#line 257 "Trex.y"
    { generate_fin_for(); ;}
    break;

  case 88:
#line 261 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 89:
#line 261 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 90:
#line 261 "Trex.y"
    { generateQuadruple_asignacion(); ;}
    break;

  case 91:
#line 261 "Trex.y"
    { generateQuadruple_for2(); ;}
    break;

  case 93:
#line 265 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 94:
#line 265 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 95:
#line 265 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (5)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (5)].sval)); ;}
    break;

  case 96:
#line 265 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (8)].sval), "0");  generateQuadruple_for3(); ;}
    break;

  case 97:
#line 269 "Trex.y"
    { push_quadruple_index_to_pilaSaltos(); ;}
    break;

  case 98:
#line 269 "Trex.y"
    { generateQuadruple_while(); ;}
    break;

  case 99:
#line 269 "Trex.y"
    { generate_fin_while(); ;}
    break;

  case 100:
#line 273 "Trex.y"
    { name = (yyvsp[(1) - (1)].sval); push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 104:
#line 282 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 105:
#line 282 "Trex.y"
    { quadruple_relational(); ;}
    break;

  case 107:
#line 286 "Trex.y"
    { verify_arr_limit(name); generateQuadruple_array(); ;}
    break;

  case 110:
#line 295 "Trex.y"
    { function_name = yylval.sval; insert_to_procs_table(function_name); set_current_function("1");;}
    break;

  case 112:
#line 299 "Trex.y"
    { reset_param_counter(); ;}
    break;

  case 113:
#line 299 "Trex.y"
    { set_start_function(function_name); ;}
    break;

  case 114:
#line 299 "Trex.y"
    { set_current_function("0"); set_fin_function(function_name); ;}
    break;

  case 121:
#line 318 "Trex.y"
    { function_called = (yyvsp[(1) - (1)].sval); verify_function_name(function_called); ;}
    break;

  case 122:
#line 318 "Trex.y"
    { generate_activation_record(function_called); ;}
    break;

  case 123:
#line 318 "Trex.y"
    { reset_param_counter(); ;}
    break;

  case 124:
#line 318 "Trex.y"
    { generate_fin_llamada(function_called); ;}
    break;

  case 127:
#line 327 "Trex.y"
    { name = yylval.sval; insert_to_vars_table(name,var_type); count_params(); insert_param_type(function_name, var_type); ;}
    break;

  case 129:
#line 331 "Trex.y"
    { name = yylval.sval; insert_to_vars_table(name,var_type); count_params(); insert_param_type(function_name, var_type); ;}
    break;

  case 132:
#line 336 "Trex.y"
    { verify_parameters(function_called); ;}
    break;

  case 134:
#line 340 "Trex.y"
    { count_params(); ;}
    break;

  case 135:
#line 340 "Trex.y"
    { verify_parameters(function_called); ;}
    break;

  case 138:
#line 345 "Trex.y"
    { name = (yyvsp[(1) - (1)].sval); push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 139:
#line 345 "Trex.y"
    { push_to_pilaOperadores("#"); ;}
    break;

  case 140:
#line 345 "Trex.y"
    { pop_of_pilaOperadores(); ;}
    break;

  case 141:
#line 345 "Trex.y"
    { verify_arr_limit(name); generateQuadruple_array(); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2050 "Trex.tab.c"
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


#line 348 "Trex.y"


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
