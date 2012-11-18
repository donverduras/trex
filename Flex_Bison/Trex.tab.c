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
#line 236 "Trex.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 249 "Trex.tab.c"

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
#define YYLAST   203

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  94
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNRULES -- Number of states.  */
#define YYNSTATES  226

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
       0,     0,     3,     4,    12,    13,    19,    20,    26,    27,
      31,    32,    33,    39,    42,    43,    46,    47,    50,    53,
      54,    57,    58,    62,    65,    66,    69,    70,    74,    81,
      83,    85,    87,    89,    91,    93,    95,    97,    99,   101,
     103,   105,   107,   109,   111,   113,   115,   117,   119,   120,
     128,   130,   131,   136,   137,   138,   143,   148,   149,   153,
     154,   157,   160,   161,   163,   165,   167,   169,   171,   173,
     174,   178,   179,   184,   185,   187,   189,   190,   191,   195,
     196,   201,   202,   204,   206,   208,   211,   213,   215,   216,
     221,   227,   228,   229,   230,   231,   243,   244,   245,   246,
     255,   256,   257,   265,   266,   271,   273,   275,   276,   277,
     283,   287,   288,   293,   294,   301,   302,   303,   310,   313,
     314,   316,   317,   321,   323,   324,   325,   326,   335,   337,
     338,   339,   344,   345,   351,   352,   353,   357,   358,   359,
     365,   366,   367,   368,   369
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      58,     0,    -1,    -1,    63,    74,    66,   125,    67,    59,
      68,    -1,    -1,    63,   125,    67,    60,    68,    -1,    -1,
      63,    74,    66,    61,    68,    -1,    -1,    63,    62,    68,
      -1,    -1,    -1,    13,    64,    51,    65,    32,    -1,    74,
      66,    -1,    -1,   125,    67,    -1,    -1,    69,    33,    -1,
      77,    70,    -1,    -1,    77,    70,    -1,    -1,    32,    72,
      33,    -1,    77,    73,    -1,    -1,    77,    73,    -1,    -1,
      75,    51,    35,    -1,    75,    51,    47,    52,    48,    35,
      -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,    21,
      -1,    52,    -1,    53,    -1,    54,    -1,    55,    -1,    56,
      -1,    51,    -1,   117,    -1,    83,    -1,    78,    -1,   104,
      -1,   114,    -1,    74,    -1,   124,    -1,   133,    -1,    -1,
      12,    45,    79,    80,    81,    46,    35,    -1,    91,    -1,
      -1,    34,    82,    80,    81,    -1,    -1,    -1,    85,    84,
      71,    86,    -1,     8,    45,    88,    46,    -1,    -1,     9,
      87,    71,    -1,    -1,    91,    89,    -1,    90,    91,    -1,
      -1,    38,    -1,    37,    -1,    39,    -1,    40,    -1,    49,
      -1,    50,    -1,    -1,    96,    92,    93,    -1,    -1,    95,
      96,    94,    93,    -1,    -1,    41,    -1,    42,    -1,    -1,
      -1,   101,    97,    98,    -1,    -1,   100,   101,    99,    98,
      -1,    -1,    43,    -1,    44,    -1,   102,    -1,    95,    76,
      -1,    76,    -1,   147,    -1,    -1,    45,   103,    88,    46,
      -1,     7,    45,   105,    46,    71,    -1,    -1,    -1,    -1,
      -1,    51,   106,    36,   107,    76,    35,   108,    88,    35,
     109,   110,    -1,    -1,    -1,    -1,    51,   111,    36,   112,
      51,   113,    95,    52,    -1,    -1,    -1,     6,   115,    45,
      88,    46,   116,    71,    -1,    -1,    51,   118,   123,   120,
      -1,    88,    -1,   124,    -1,    -1,    -1,    36,   121,   119,
     122,    35,    -1,    47,    91,    48,    -1,    -1,    11,    45,
      46,    35,    -1,    -1,    15,    51,   126,    45,   131,   127,
      -1,    -1,    -1,    46,   128,    32,   129,   132,    33,    -1,
      74,   130,    -1,    -1,   138,    -1,    -1,    74,   130,    69,
      -1,    69,    -1,    -1,    -1,    -1,    51,   134,    45,   135,
     137,    46,   136,    35,    -1,   142,    -1,    -1,    -1,    75,
      51,   139,   140,    -1,    -1,    34,    75,    51,   141,   140,
      -1,    -1,    -1,    91,   143,   144,    -1,    -1,    -1,    34,
     145,    91,   146,   144,    -1,    -1,    -1,    -1,    -1,    51,
     148,    47,   149,    91,   150,    48,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    88,    88,    88,    89,    89,    90,    90,    91,    91,
      95,    95,    95,    99,   100,   104,   105,   109,   113,   114,
     118,   119,   123,   127,   128,   132,   133,   137,   138,   142,
     143,   144,   145,   146,   150,   151,   152,   153,   154,   155,
     159,   160,   161,   162,   163,   164,   165,   166,   170,   170,
     174,   178,   178,   179,   183,   183,   187,   191,   191,   192,
     196,   200,   201,   205,   206,   207,   208,   209,   210,   214,
     214,   218,   218,   219,   223,   224,   225,   229,   229,   233,
     233,   234,   238,   239,   243,   244,   245,   246,   250,   250,
     254,   258,   258,   258,   258,   258,   262,   262,   262,   262,
     266,   266,   266,   270,   270,   274,   275,   279,   279,   279,
     283,   284,   288,   292,   292,   296,   296,   296,   300,   301,
     305,   306,   310,   311,   315,   315,   315,   315,   319,   320,
     324,   324,   328,   328,   329,   333,   333,   337,   337,   337,
     338,   342,   342,   342,   342
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
  "CTE_STRING", "CTE_BOOLEAN", "CTE_CHAR", "$accept", "programa", "@1",
  "@2", "@3", "@4", "programa_a", "@5", "@6", "programa_b", "programa_c",
  "programa_d", "bloque", "b", "bloque2", "bloque21", "c", "vars", "tipo",
  "var_cte", "estatuto", "escritura", "@7", "escritura_a", "d", "@8",
  "condicion", "@9", "condicion_a", "condicion_b", "@10", "expresion",
  "expresion_b", "expresion_a", "exp", "@11", "e", "@12", "sumaresta",
  "termino", "@13", "f", "@14", "multdiv", "factor", "factor_a", "@15",
  "loopfor", "bloque_for", "@16", "@17", "@18", "@19", "bloque_for_2",
  "@20", "@21", "@22", "loopwhile", "@23", "@24", "asignacion", "@25",
  "asignacion_b", "asignacion_c", "@26", "@27", "asignacion_d", "lectura",
  "funcion", "@28", "funcion_a", "@29", "@30", "funcion_b", "funcion_c",
  "funcion_d", "llamada", "@31", "@32", "@33", "llamada_2", "param", "@34",
  "g", "@35", "param2", "@36", "h", "@37", "@38", "arr", "@39", "@40",
  "@41", 0
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
       0,    57,    59,    58,    60,    58,    61,    58,    62,    58,
      64,    65,    63,    66,    66,    67,    67,    68,    69,    69,
      70,    70,    71,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    79,    78,
      80,    82,    81,    81,    84,    83,    85,    87,    86,    86,
      88,    89,    89,    90,    90,    90,    90,    90,    90,    92,
      91,    94,    93,    93,    95,    95,    95,    97,    96,    99,
      98,    98,   100,   100,   101,   101,   101,   101,   103,   102,
     104,   106,   107,   108,   109,   105,   111,   112,   113,   110,
     115,   116,   114,   118,   117,   119,   119,   121,   122,   120,
     123,   123,   124,   126,   125,   128,   129,   127,   130,   130,
     131,   131,   132,   132,   134,   135,   136,   133,   137,   137,
     139,   138,   141,   140,   140,   143,   142,   145,   146,   144,
     144,   148,   149,   150,   147
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     0,     5,     0,     5,     0,     3,
       0,     0,     5,     2,     0,     2,     0,     2,     2,     0,
       2,     0,     3,     2,     0,     2,     0,     3,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     7,
       1,     0,     4,     0,     0,     4,     4,     0,     3,     0,
       2,     2,     0,     1,     1,     1,     1,     1,     1,     0,
       3,     0,     4,     0,     1,     1,     0,     0,     3,     0,
       4,     0,     1,     1,     1,     2,     1,     1,     0,     4,
       5,     0,     0,     0,     0,    11,     0,     0,     0,     8,
       0,     0,     7,     0,     4,     1,     1,     0,     0,     5,
       3,     0,     4,     0,     6,     0,     0,     6,     2,     0,
       1,     0,     3,     1,     0,     0,     0,     8,     1,     0,
       0,     4,     0,     5,     0,     0,     3,     0,     0,     5,
       0,     0,     0,     0,     7
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,     0,     8,     0,     1,     0,    29,    30,    31,
      32,    33,    19,    14,     0,    16,    11,   113,   100,     0,
       0,     0,     0,   103,     9,     0,    45,    21,    42,    41,
      54,    43,    44,    40,    46,    47,     6,    14,     0,     4,
      16,     0,     0,     0,     0,     0,     0,    48,   111,     0,
      17,    18,    21,     0,    19,    16,    13,    27,     0,    19,
      15,    12,   121,     0,    91,     0,    74,    75,    88,    39,
      34,    35,    36,    37,    38,    86,     0,    62,     0,    69,
      77,    84,    87,     0,     0,     0,     0,   125,    20,    24,
      59,     7,     2,     0,     5,     0,     0,   120,     0,     0,
       0,     0,     0,    56,    64,    63,    65,    66,    67,    68,
      60,     0,    39,    85,    73,    81,   112,    53,    50,     0,
     107,   104,   129,     0,    26,    57,    55,    19,     0,   130,
     115,   114,   101,    92,    90,     0,   142,    61,    70,     0,
      82,    83,    78,     0,    51,     0,   110,     0,   135,     0,
     128,    22,    23,    26,     0,     3,    28,   134,     0,     0,
       0,    89,     0,    71,    79,     0,     0,   105,   108,   106,
     140,   126,    25,    58,     0,   131,   116,   102,     0,   143,
      73,    81,    53,    49,     0,   137,   136,     0,     0,    19,
      93,     0,    72,    80,    52,   109,     0,   127,   132,   123,
      45,     0,     0,   144,   138,   134,   119,    19,   117,     0,
     140,   133,   118,   122,    94,   139,     0,    96,    95,     0,
      97,     0,    98,    76,     0,    99
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   127,    59,    54,    12,     3,     4,    41,    36,
      39,    24,    25,    51,    90,   123,   152,    26,    14,    75,
      27,    28,    84,   117,   145,   165,    29,    53,    30,   126,
     154,    76,   110,   111,    77,   114,   138,   180,    78,    79,
     115,   142,   181,   143,    80,    81,   101,    31,    65,    99,
     160,   202,   216,   218,   219,   221,   223,    32,    43,   159,
      33,    48,   168,   121,   147,   184,    86,    34,    40,    42,
     131,   158,   189,   207,    96,   201,    35,    49,   122,   187,
     149,    97,   157,   175,   205,   150,   170,   186,   196,   210,
      82,   102,   162,   191
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -172
static const yytype_int16 yypact[] =
{
      16,  -172,    37,    32,   -13,  -172,   -11,  -172,  -172,  -172,
    -172,  -172,     5,   118,    -7,    27,  -172,  -172,  -172,     0,
       1,     9,    10,    18,  -172,    35,  -172,     5,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,    27,   118,   -16,  -172,
      27,    25,    29,    38,    36,    49,    26,  -172,    39,    44,
    -172,  -172,     5,    60,     5,    27,  -172,  -172,    41,     5,
    -172,  -172,   118,    49,  -172,    50,  -172,  -172,  -172,    48,
    -172,  -172,  -172,  -172,  -172,  -172,    51,    21,    78,  -172,
    -172,  -172,  -172,    63,    49,    49,    70,  -172,  -172,     5,
      98,  -172,  -172,    62,  -172,    73,    65,  -172,    68,    77,
      60,    49,    79,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,    49,  -172,  -172,    67,   -23,  -172,    91,  -172,    93,
    -172,  -172,    49,    94,     5,  -172,  -172,     5,   107,  -172,
    -172,  -172,  -172,  -172,  -172,    97,  -172,  -172,  -172,    49,
    -172,  -172,  -172,    49,  -172,    99,  -172,    24,  -172,   100,
    -172,  -172,  -172,     5,    60,  -172,  -172,   110,   115,    60,
      78,  -172,    49,  -172,  -172,    49,   113,  -172,  -172,  -172,
     116,  -172,  -172,  -172,   118,  -172,  -172,  -172,   114,  -172,
      67,   -23,    91,  -172,   117,  -172,  -172,   119,   102,     5,
    -172,   103,  -172,  -172,  -172,  -172,    49,  -172,  -172,  -172,
     118,   122,    49,  -172,  -172,   110,   118,     5,  -172,   121,
     116,  -172,  -172,  -172,  -172,  -172,   106,  -172,  -172,   123,
    -172,   109,  -172,    -9,   111,  -172
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,   124,
     -12,   -45,  -171,   112,   -92,  -172,    13,    -3,   -57,   -72,
     -25,  -172,  -172,     2,   -24,  -172,  -172,  -172,  -172,  -172,
    -172,   -62,  -172,  -172,   -81,  -172,   -18,  -172,  -107,    30,
    -172,   -10,  -172,  -172,    22,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -172,  -172,    23,    12,  -172,
    -172,  -172,  -172,   -38,  -172,  -172,  -172,  -172,  -172,  -172,
    -172,  -172,  -172,   -33,  -172,  -172,  -172,   -37,  -172,  -172,
    -172,  -172,  -172,  -172
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -142
static const yytype_int16 yytable[] =
{
      13,    98,    52,   118,   119,    95,   113,   139,   134,    91,
      37,    18,    19,    20,    94,    15,    21,    22,   199,    57,
     140,   141,     7,     8,     9,    10,    11,    52,    60,     1,
     137,    58,    66,    67,    37,    21,   213,     5,    16,   135,
      17,   148,     6,    92,    38,    44,    45,     6,    55,     7,
       8,     9,    10,    11,    46,    47,    23,    61,   104,   105,
     106,   107,   173,  -124,   124,    66,    67,   177,    50,    68,
     108,   109,    83,   139,    62,    69,    70,    71,    72,    73,
      74,   179,   155,    63,   118,   167,    85,    64,   178,    87,
      66,    67,    89,    93,    68,  -141,   100,   103,   116,   153,
      69,    70,    71,    72,    73,    74,   120,   125,    66,    67,
     128,   130,   -76,   133,   132,   204,   224,   188,   -76,   -76,
     -76,   -76,   -76,   -76,   129,   144,   136,   151,   153,   112,
      70,    71,    72,    73,    74,     7,     8,     9,    10,    11,
     209,   146,   156,   161,   174,   166,   171,   176,   183,   190,
     185,   203,   195,   198,   197,   208,   214,   217,   194,   220,
     222,    56,   192,   225,    88,   164,   172,   182,   212,   163,
     169,   193,   211,   215,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   206,     0,     0,
       0,     0,     0,   206
};

static const yytype_int16 yycheck[] =
{
       3,    63,    27,    84,    85,    62,    78,   114,   100,    54,
      13,     6,     7,     8,    59,     3,    11,    12,   189,    35,
      43,    44,    17,    18,    19,    20,    21,    52,    40,    13,
     111,    47,    41,    42,    37,    11,   207,     0,    51,   101,
      51,   122,    15,    55,    51,    45,    45,    15,    36,    17,
      18,    19,    20,    21,    45,    45,    51,    32,    37,    38,
      39,    40,   154,    45,    89,    41,    42,   159,    33,    45,
      49,    50,    46,   180,    45,    51,    52,    53,    54,    55,
      56,   162,   127,    45,   165,   147,    47,    51,   160,    45,
      41,    42,    32,    52,    45,    47,    46,    46,    35,   124,
      51,    52,    53,    54,    55,    56,    36,     9,    41,    42,
      48,    46,    45,    36,    46,   196,   223,   174,    51,    52,
      53,    54,    55,    56,    51,    34,    47,    33,   153,    51,
      52,    53,    54,    55,    56,    17,    18,    19,    20,    21,
     202,    48,    35,    46,    34,    46,    46,    32,    35,    35,
      34,    48,    35,    51,    35,    33,    35,    51,   182,    36,
      51,    37,   180,    52,    52,   143,   153,   165,   206,   139,
     147,   181,   205,   210,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,    -1,    -1,
      -1,    -1,    -1,   206
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    58,    63,    64,     0,    15,    17,    18,    19,
      20,    21,    62,    74,    75,   125,    51,    51,     6,     7,
       8,    11,    12,    51,    68,    69,    74,    77,    78,    83,
      85,   104,   114,   117,   124,   133,    66,    74,    51,    67,
     125,    65,   126,   115,    45,    45,    45,    45,   118,   134,
      33,    70,    77,    84,    61,   125,    66,    35,    47,    60,
      67,    32,    45,    45,    51,   105,    41,    42,    45,    51,
      52,    53,    54,    55,    56,    76,    88,    91,    95,    96,
     101,   102,   147,    46,    79,    47,   123,    45,    70,    32,
      71,    68,    67,    52,    68,    75,   131,   138,    88,   106,
      46,   103,   148,    46,    37,    38,    39,    40,    49,    50,
      89,    90,    51,    76,    92,    97,    35,    80,    91,    91,
      36,   120,   135,    72,    77,     9,    86,    59,    48,    51,
      46,   127,    46,    36,    71,    88,    47,    91,    93,    95,
      43,    44,    98,   100,    34,    81,    48,   121,    91,   137,
     142,    33,    73,    77,    87,    68,    35,   139,   128,   116,
     107,    46,   149,    96,   101,    82,    46,    88,   119,   124,
     143,    46,    73,    71,    34,   140,    32,    71,    76,    91,
      94,    99,    80,    35,   122,    34,   144,   136,    75,   129,
      35,   150,    93,    98,    81,    35,   145,    35,    51,    69,
      74,   132,   108,    48,    91,   141,    74,   130,    33,    88,
     146,   140,   130,    69,    35,   144,   109,    51,   110,   111,
      36,   112,    51,   113,    95,    52
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
#line 88 "Trex.y"
    { set_start_function(main_func); fillQuadruple_main(); ;}
    break;

  case 3:
#line 88 "Trex.y"
    { generate_obj(); cout << "EXITO" << endl; ;}
    break;

  case 4:
#line 89 "Trex.y"
    { set_start_function(main_func); fillQuadruple_main(); ;}
    break;

  case 5:
#line 89 "Trex.y"
    { generate_obj(); cout << "EXITO" << endl; ;}
    break;

  case 6:
#line 90 "Trex.y"
    { set_start_function(main_func); fillQuadruple_main(); ;}
    break;

  case 7:
#line 90 "Trex.y"
    { generate_obj(); cout << "EXITO" << endl; ;}
    break;

  case 8:
#line 91 "Trex.y"
    { set_start_function(main_func); fillQuadruple_main(); ;}
    break;

  case 9:
#line 91 "Trex.y"
    { generate_obj(); cout << "EXITO" << endl; ;}
    break;

  case 10:
#line 95 "Trex.y"
    { initialize(); generateQuadruple_main(); ;}
    break;

  case 11:
#line 95 "Trex.y"
    { function_name = yylval.sval; main_func = function_name; insert_to_procs_table(function_name); main_function_name(function_name); set_current_function("0", function_name);;}
    break;

  case 17:
#line 109 "Trex.y"
    { set_fin_function(main_func, "0"); ;}
    break;

  case 27:
#line 137 "Trex.y"
    { name = (yyvsp[(2) - (3)].sval); insert_to_vars_table(name,var_type,function_name); ;}
    break;

  case 28:
#line 138 "Trex.y"
    { name = (yyvsp[(2) - (6)].sval);  size = (yyvsp[(4) - (6)].sval); insert_arr_to_vars_table(name,var_type, size, function_name); ;}
    break;

  case 29:
#line 142 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 30:
#line 143 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 31:
#line 144 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 32:
#line 145 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 33:
#line 146 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 34:
#line 150 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "0"); push_to_pilaTipos_directly("10"); ;}
    break;

  case 35:
#line 151 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "1"); push_to_pilaTipos_directly("11"); ;}
    break;

  case 36:
#line 152 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "2"); push_to_pilaTipos_directly("12"); ;}
    break;

  case 37:
#line 153 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "3"); push_to_pilaTipos_directly("13"); ;}
    break;

  case 38:
#line 154 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "4"); push_to_pilaTipos_directly("14"); ;}
    break;

  case 39:
#line 155 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5");  push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 48:
#line 170 "Trex.y"
    { push_to_pilaOperadores("print"); ;}
    break;

  case 50:
#line 174 "Trex.y"
    { generateQuadruple_print(); ;}
    break;

  case 51:
#line 178 "Trex.y"
    { push_to_pilaOperadores("print"); ;}
    break;

  case 54:
#line 183 "Trex.y"
    { generateQuadruple_if(); ;}
    break;

  case 55:
#line 183 "Trex.y"
    { generate_fin_if(); ;}
    break;

  case 57:
#line 191 "Trex.y"
    { generateQuadruple_else(); ;}
    break;

  case 61:
#line 200 "Trex.y"
    { quadruple_relational(); ;}
    break;

  case 63:
#line 205 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 64:
#line 206 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 65:
#line 207 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 66:
#line 208 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 67:
#line 209 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 68:
#line 210 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 69:
#line 214 "Trex.y"
    { quadruple_add_sub(); ;}
    break;

  case 71:
#line 218 "Trex.y"
    { quadruple_add_sub(); ;}
    break;

  case 74:
#line 223 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 75:
#line 224 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 77:
#line 229 "Trex.y"
    { quadruple_mult_div(); ;}
    break;

  case 79:
#line 233 "Trex.y"
    { quadruple_mult_div(); ;}
    break;

  case 82:
#line 238 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 83:
#line 239 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 88:
#line 250 "Trex.y"
    { push_to_pilaOperadores("#"); ;}
    break;

  case 89:
#line 250 "Trex.y"
    { pop_of_pilaOperadores(); ;}
    break;

  case 90:
#line 254 "Trex.y"
    { generate_fin_for(); ;}
    break;

  case 91:
#line 258 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 92:
#line 258 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 93:
#line 258 "Trex.y"
    { generateQuadruple_asignacion(); ;}
    break;

  case 94:
#line 258 "Trex.y"
    { generateQuadruple_for2(); ;}
    break;

  case 96:
#line 262 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 97:
#line 262 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 98:
#line 262 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (5)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (5)].sval)); ;}
    break;

  case 99:
#line 262 "Trex.y"
    { push_to_pilaOperandos(yylval.sval, "0");  generateQuadruple_for3(); ;}
    break;

  case 100:
#line 266 "Trex.y"
    { push_quadruple_index_to_pilaSaltos(); ;}
    break;

  case 101:
#line 266 "Trex.y"
    { generateQuadruple_while(); ;}
    break;

  case 102:
#line 266 "Trex.y"
    { generate_fin_while(); ;}
    break;

  case 103:
#line 270 "Trex.y"
    { name = (yyvsp[(1) - (1)].sval); push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 107:
#line 279 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 108:
#line 279 "Trex.y"
    { quadruple_relational(); ;}
    break;

  case 110:
#line 283 "Trex.y"
    { verify_arr_limit(name); generateQuadruple_array(); ;}
    break;

  case 113:
#line 292 "Trex.y"
    { function_name = yylval.sval; insert_to_procs_table(function_name); set_current_function("1", function_name); reset_conts(); ;}
    break;

  case 115:
#line 296 "Trex.y"
    { reset_param_counter(); ;}
    break;

  case 116:
#line 296 "Trex.y"
    { set_start_function(function_name); ;}
    break;

  case 117:
#line 296 "Trex.y"
    { set_current_function("0", main_func); set_fin_function(function_name, "1"); ;}
    break;

  case 124:
#line 315 "Trex.y"
    { function_called = (yyvsp[(1) - (1)].sval); verify_function_name(function_called); ;}
    break;

  case 125:
#line 315 "Trex.y"
    { generate_activation_record(function_called); ;}
    break;

  case 126:
#line 315 "Trex.y"
    { reset_param_counter(); ;}
    break;

  case 127:
#line 315 "Trex.y"
    { generate_fin_llamada(function_called); ;}
    break;

  case 130:
#line 324 "Trex.y"
    { name = yylval.sval; insert_to_vars_table(name,var_type,function_name); count_params(); insert_param_type(function_name, var_type); ;}
    break;

  case 132:
#line 328 "Trex.y"
    { name = yylval.sval; insert_to_vars_table(name,var_type,function_name); count_params(); insert_param_type(function_name, var_type); ;}
    break;

  case 135:
#line 333 "Trex.y"
    { verify_parameters(function_called); ;}
    break;

  case 137:
#line 337 "Trex.y"
    { count_params(); ;}
    break;

  case 138:
#line 337 "Trex.y"
    { verify_parameters(function_called); ;}
    break;

  case 141:
#line 342 "Trex.y"
    { name = (yyvsp[(1) - (1)].sval); push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 142:
#line 342 "Trex.y"
    { push_to_pilaOperadores("#"); ;}
    break;

  case 143:
#line 342 "Trex.y"
    { pop_of_pilaOperadores(); ;}
    break;

  case 144:
#line 342 "Trex.y"
    { verify_arr_limit(name); generateQuadruple_array(); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2076 "Trex.tab.c"
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


#line 345 "Trex.y"


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
