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
char *function_name;
 
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
#line 23 "Trex.y"
{
	char *sval;
}
/* Line 193 of yacc.c.  */
#line 233 "Trex.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 246 "Trex.tab.c"

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
#define YYLAST   215

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNRULES -- Number of states.  */
#define YYNSTATES  207

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
      34,    35,    38,    39,    42,    45,    46,    49,    50,    55,
      58,    61,    62,    68,    72,    81,    88,    90,    92,    94,
      96,    98,   100,   102,   104,   106,   108,   110,   112,   114,
     116,   118,   120,   122,   124,   126,   133,   135,   137,   141,
     142,   145,   149,   154,   157,   160,   163,   164,   166,   168,
     170,   172,   174,   176,   177,   181,   182,   187,   188,   190,
     192,   193,   197,   198,   203,   204,   206,   208,   210,   213,
     215,   217,   218,   223,   229,   237,   243,   249,   250,   251,
     252,   260,   268,   270,   272,   277,   278,   285,   292,   297,
     300,   301,   303,   304,   310,   315,   316,   321,   322,   328,
     329,   332,   336,   337
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      58,     0,    -1,    59,    69,    62,   105,    63,    64,    -1,
      59,   105,    63,    64,    -1,    59,    69,    62,    64,    -1,
      59,    64,    -1,    -1,    -1,    13,    60,    51,    61,    32,
      -1,    69,    62,    -1,    -1,   105,    63,    -1,    -1,    65,
      33,    -1,    72,    66,    -1,    -1,    72,    66,    -1,    -1,
      32,    72,    68,    33,    -1,    32,    33,    -1,    72,    68,
      -1,    -1,    70,    51,    36,    71,    35,    -1,    70,    51,
      35,    -1,    70,    51,    47,    52,    48,    36,    71,    35,
      -1,    70,    51,    47,    52,    48,    35,    -1,    17,    -1,
      18,    -1,    19,    -1,    20,    -1,    21,    -1,    52,    -1,
      53,    -1,    54,    -1,    55,    -1,    56,    -1,    51,    -1,
      99,    -1,    76,    -1,    73,    -1,    95,    -1,    98,    -1,
      69,    -1,   104,    -1,   110,    -1,    12,    45,    74,    75,
      46,    35,    -1,    82,    -1,    54,    -1,    41,    74,    75,
      -1,    -1,    77,    67,    -1,    77,    67,    78,    -1,     8,
      45,    79,    46,    -1,     9,    67,    -1,    82,    80,    -1,
      81,    82,    -1,    -1,    38,    -1,    37,    -1,    39,    -1,
      40,    -1,    49,    -1,    50,    -1,    -1,    87,    83,    84,
      -1,    -1,    86,    87,    85,    84,    -1,    -1,    41,    -1,
      42,    -1,    -1,    92,    88,    89,    -1,    -1,    91,    92,
      90,    89,    -1,    -1,    43,    -1,    44,    -1,    93,    -1,
      86,    71,    -1,    71,    -1,   117,    -1,    -1,    45,    94,
      79,    46,    -1,     7,    45,    96,    46,    67,    -1,    51,
      36,    71,    35,    79,    35,    97,    -1,    51,    36,    51,
      86,    52,    -1,     6,    45,    79,    46,    67,    -1,    -1,
      -1,    -1,    51,   100,    36,   101,   103,   102,    35,    -1,
      51,    47,    82,    48,    36,   103,    35,    -1,    79,    -1,
     104,    -1,    11,    45,    46,    35,    -1,    -1,    15,    51,
     106,    45,   109,   107,    -1,    46,    32,    69,   108,    65,
      33,    -1,    46,    32,    65,    33,    -1,    69,   108,    -1,
      -1,   111,    -1,    -1,    51,    45,   115,    46,    35,    -1,
      51,    45,    46,    35,    -1,    -1,    70,    51,   112,   113,
      -1,    -1,    34,    70,    51,   114,   113,    -1,    -1,    82,
     116,    -1,    34,    82,   116,    -1,    -1,    51,    47,    82,
      48,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    86,    87,    88,    92,    92,    92,    96,
      97,   101,   102,   106,   110,   111,   115,   116,   120,   121,
     125,   126,   130,   131,   132,   133,   137,   138,   139,   140,
     141,   145,   146,   147,   148,   149,   150,   154,   155,   156,
     157,   158,   159,   160,   161,   165,   169,   170,   174,   175,
     179,   180,   184,   188,   192,   196,   197,   201,   202,   203,
     204,   205,   206,   210,   210,   214,   214,   215,   219,   220,
     224,   224,   228,   228,   229,   233,   234,   238,   239,   240,
     241,   245,   245,   249,   253,   257,   261,   265,   265,   265,
     265,   266,   270,   271,   275,   279,   279,   283,   284,   288,
     289,   293,   294,   298,   299,   303,   303,   307,   307,   308,
     312,   316,   317,   321
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
  "bloque", "b", "bloque2", "c", "vars", "tipo", "var_cte", "estatuto",
  "escritura", "escritura_a", "d", "condicion", "condicion_a",
  "condicion_b", "expresion", "expresion_b", "expresion_a", "exp", "@3",
  "e", "@4", "sumaresta", "termino", "@5", "f", "@6", "multdiv", "factor",
  "factor_a", "@7", "loopfor", "bloque_for", "bloque_for_2", "loopwhile",
  "asignacion", "@8", "@9", "@10", "asignacion_b", "lectura", "funcion",
  "@11", "funcion_a", "funcion_b", "funcion_c", "llamada", "param", "@12",
  "g", "@13", "param2", "h", "arr", 0
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
      62,    63,    63,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    70,
      70,    71,    71,    71,    71,    71,    71,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    74,    74,    75,    75,
      76,    76,    77,    78,    79,    80,    80,    81,    81,    81,
      81,    81,    81,    83,    82,    85,    84,    84,    86,    86,
      88,    87,    90,    89,    89,    91,    91,    92,    92,    92,
      92,    94,    93,    95,    96,    97,    98,   100,   101,   102,
      99,    99,   103,   103,   104,   106,   105,   107,   107,   108,
     108,   109,   109,   110,   110,   112,   111,   114,   113,   113,
     115,   116,   116,   117
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     4,     4,     2,     0,     0,     5,     2,
       0,     2,     0,     2,     2,     0,     2,     0,     4,     2,
       2,     0,     5,     3,     8,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     1,     1,     3,     0,
       2,     3,     4,     2,     2,     2,     0,     1,     1,     1,
       1,     1,     1,     0,     3,     0,     4,     0,     1,     1,
       0,     3,     0,     4,     0,     1,     1,     1,     2,     1,
       1,     0,     4,     5,     7,     5,     5,     0,     0,     0,
       7,     7,     1,     1,     4,     0,     6,     6,     4,     2,
       0,     1,     0,     5,     4,     0,     4,     0,     5,     0,
       2,     3,     0,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     6,     0,    15,     0,     1,     0,     0,     0,     0,
       0,     0,    26,    27,    28,    29,    30,    87,     5,     0,
      10,     0,    17,    39,    38,     0,    40,    41,    37,    43,
      12,    44,     7,     0,     0,     0,     0,     0,    95,     0,
       0,     0,    13,    15,    10,     0,    14,    42,    17,     0,
      50,    15,    12,     0,    68,    69,    81,    36,    31,    32,
      33,    34,    35,    79,     0,    56,     0,    63,    70,    77,
      80,     0,     0,     0,     0,    33,    49,    46,     0,     0,
     112,     0,     0,    88,     4,    12,     9,    23,     0,     0,
      16,    19,    21,     0,    51,     3,    11,     8,     0,     0,
       0,    58,    57,    59,    60,    61,    62,    54,     0,    36,
      78,    67,    74,     0,     0,    52,    94,     0,     0,   102,
     104,     0,   110,     0,     0,     0,    15,     0,     0,     0,
      21,    53,     0,     0,    86,    55,    64,     0,    75,    76,
      71,     0,     0,    83,    49,     0,     0,     0,   101,   112,
     103,     0,    92,    89,    93,     2,    22,     0,    18,    20,
      82,   113,    65,    72,     0,    48,    45,   105,     0,    96,
     111,     0,     0,    25,     0,    67,    74,     0,   109,    15,
      91,    90,     0,    66,    73,     0,     0,   106,     0,    42,
      24,     0,    84,     0,    98,   100,    15,     0,   107,    99,
       0,     0,   109,    97,     0,   108,    85
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    53,    43,    51,    18,    19,    46,
      50,   129,    47,    21,    63,    22,    23,    76,   118,    24,
      25,    94,   152,   107,   108,    65,   111,   136,   175,    66,
      67,   112,   140,   176,   141,    68,    69,    98,    26,    72,
     192,    27,    28,    41,   125,   172,   153,    29,    52,    78,
     169,   196,   147,    31,   148,   178,   187,   202,    81,   122,
      70
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -141
static const yytype_int16 yypact[] =
{
      -2,  -141,    30,    25,   -24,  -141,     5,    12,    20,    28,
      39,    16,  -141,  -141,  -141,  -141,  -141,   -26,  -141,    -8,
      79,    24,    41,  -141,  -141,    53,  -141,  -141,  -141,  -141,
      72,  -141,  -141,   115,    37,   115,    43,   142,  -141,    99,
     115,    55,  -141,    25,    79,   -12,  -141,  -141,    41,    96,
      92,    41,    72,    73,  -141,  -141,  -141,    59,  -141,  -141,
    -141,  -141,  -141,  -141,    63,    81,    27,  -141,  -141,  -141,
    -141,    75,    76,    77,    91,  -141,    86,  -141,    88,   107,
     109,   100,   101,  -141,  -141,    72,  -141,  -141,    27,   106,
    -141,  -141,    41,    53,  -141,  -141,  -141,  -141,   115,   115,
      53,  -141,  -141,  -141,  -141,  -141,  -141,  -141,   115,  -141,
    -141,    22,   -28,    27,    53,  -141,  -141,   142,   102,    79,
    -141,   115,  -141,   124,   125,    83,    41,   127,   116,   130,
      41,  -141,   119,   126,  -141,  -141,  -141,   115,  -141,  -141,
    -141,   115,   137,  -141,    86,   138,   128,   129,  -141,   109,
    -141,    83,  -141,  -141,  -141,  -141,  -141,    35,  -141,  -141,
    -141,  -141,  -141,  -141,   115,  -141,  -141,  -141,   145,  -141,
    -141,   143,   146,  -141,    27,    22,   -28,   147,   151,    41,
    -141,  -141,   153,  -141,  -141,   139,    79,  -141,   156,    79,
    -141,   144,  -141,   140,  -141,    79,    41,   148,  -141,  -141,
     167,    22,   151,  -141,   149,  -141,  -141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,  -141,  -141,   158,   -30,   -33,  -140,   155,
     -80,    74,    -3,  -112,   -62,   -20,  -141,    89,    61,  -141,
    -141,  -141,   -32,  -141,  -141,   -31,  -141,    32,  -141,  -106,
      71,  -141,    33,  -141,  -141,    69,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,    60,  -113,    11,  -141,
    -141,    17,  -141,  -141,  -141,  -141,    13,  -141,  -141,    64,
    -141
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      20,    64,    48,    73,   110,   137,    77,   146,    80,    82,
      84,     1,   154,   131,    30,   138,   139,    44,    95,    39,
     134,    40,    96,    87,    88,    42,   127,    32,    48,    92,
       5,     6,     7,     8,   143,    89,     9,    10,   154,   188,
      11,    44,    12,    13,    14,    15,    16,     6,     7,     8,
      33,   142,     9,    10,    85,   126,   200,    34,    12,    13,
      14,    15,    16,    54,    55,    35,   132,    38,   133,   137,
     173,   174,   130,    36,   193,    45,    17,   135,   109,    58,
      59,    60,    61,    62,    37,    49,    77,    11,    71,    74,
     149,    83,    17,   155,     9,   204,    12,    13,    14,    15,
      16,    93,     6,     7,     8,    97,    99,     9,    10,   100,
     130,   113,   182,    12,    13,    14,    15,    16,   101,   102,
     103,   104,   114,   115,    54,    55,   116,   117,    56,    91,
     105,   106,   177,   119,    57,    58,    59,    60,    61,    62,
      54,    55,   120,   121,    56,    79,   123,    17,   145,   124,
      57,    58,    59,    60,    61,    62,    54,    55,   128,   150,
      56,   151,   156,   158,   157,   160,    57,    58,    59,    60,
      61,    62,   164,   166,   161,   168,   189,   179,   180,   167,
     197,   181,   185,    54,    55,   186,   195,    56,   190,   194,
     191,   198,   195,    57,    58,    59,    75,    61,    62,   201,
     203,   206,    86,    90,   159,   165,   144,   183,   162,   184,
     163,   171,   199,   170,     0,   205
};

static const yytype_int16 yycheck[] =
{
       3,    33,    22,    35,    66,   111,    37,   119,    39,    40,
      43,    13,   125,    93,     3,    43,    44,    20,    51,    45,
     100,    47,    52,    35,    36,    33,    88,    51,    48,    49,
       0,     6,     7,     8,   114,    47,    11,    12,   151,   179,
      15,    44,    17,    18,    19,    20,    21,     6,     7,     8,
      45,   113,    11,    12,    43,    85,   196,    45,    17,    18,
      19,    20,    21,    41,    42,    45,    98,    51,    99,   175,
      35,    36,    92,    45,   186,    51,    51,   108,    51,    52,
      53,    54,    55,    56,    45,    32,   117,    15,    51,    46,
     121,    36,    51,   126,    11,   201,    17,    18,    19,    20,
      21,     9,     6,     7,     8,    32,    47,    11,    12,    46,
     130,    36,   174,    17,    18,    19,    20,    21,    37,    38,
      39,    40,    46,    46,    41,    42,    35,    41,    45,    33,
      49,    50,   164,    45,    51,    52,    53,    54,    55,    56,
      41,    42,    35,    34,    45,    46,    46,    51,    46,    48,
      51,    52,    53,    54,    55,    56,    41,    42,    52,    35,
      45,    36,    35,    33,    48,    46,    51,    52,    53,    54,
      55,    56,    35,    35,    48,    46,   179,    32,    35,    51,
      36,    35,    35,    41,    42,    34,   189,    45,    35,    33,
      51,    51,   195,    51,    52,    53,    54,    55,    56,    51,
      33,    52,    44,    48,   130,   144,   117,   175,   137,   176,
     141,   151,   195,   149,    -1,   202
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    58,    59,    60,     0,     6,     7,     8,    11,
      12,    15,    17,    18,    19,    20,    21,    51,    64,    65,
      69,    70,    72,    73,    76,    77,    95,    98,    99,   104,
     105,   110,    51,    45,    45,    45,    45,    45,    51,    45,
      47,   100,    33,    62,    69,    51,    66,    69,    72,    32,
      67,    63,   105,    61,    41,    42,    45,    51,    52,    53,
      54,    55,    56,    71,    79,    82,    86,    87,    92,    93,
     117,    51,    96,    79,    46,    54,    74,    82,   106,    46,
      82,   115,    82,    36,    64,   105,    62,    35,    36,    47,
      66,    33,    72,     9,    78,    64,    63,    32,    94,    47,
      46,    37,    38,    39,    40,    49,    50,    80,    81,    51,
      71,    83,    88,    36,    46,    46,    35,    41,    75,    45,
      35,    34,   116,    46,    48,   101,    63,    71,    52,    68,
      72,    67,    79,    82,    67,    82,    84,    86,    43,    44,
      89,    91,    71,    67,    74,    46,    70,   109,   111,    82,
      35,    36,    79,   103,   104,    64,    35,    48,    33,    68,
      46,    48,    87,    92,    35,    75,    35,    51,    46,   107,
     116,   103,   102,    35,    36,    85,    90,    79,   112,    32,
      35,    35,    71,    84,    89,    35,    34,   113,    65,    69,
      35,    51,    97,    70,    33,    69,   108,    36,    51,   108,
      65,    51,   114,    33,    86,   113,    52
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
#line 85 "Trex.y"
    {cout << "EXITO" << endl;;}
    break;

  case 3:
#line 86 "Trex.y"
    {cout << "EXITO" << endl;;}
    break;

  case 4:
#line 87 "Trex.y"
    {cout << "EXITO" << endl;;}
    break;

  case 5:
#line 88 "Trex.y"
    {cout << "EXITO" << endl;;}
    break;

  case 6:
#line 92 "Trex.y"
    { initialize(); ;}
    break;

  case 7:
#line 92 "Trex.y"
    { function_name = yylval.sval; insert_to_procs_table(function_name,"0","300"); main_function_name(function_name); set_current_function("0");;}
    break;

  case 22:
#line 130 "Trex.y"
    { name = (yyvsp[(2) - (5)].sval); insert_to_vars_table(name,var_type); ;}
    break;

  case 23:
#line 131 "Trex.y"
    { name = (yyvsp[(2) - (3)].sval); insert_to_vars_table(name,var_type); ;}
    break;

  case 26:
#line 137 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 27:
#line 138 "Trex.y"
    { var_type = yylval.sval;;}
    break;

  case 28:
#line 139 "Trex.y"
    { var_type = yylval.sval;;}
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
#line 145 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "0"); ;}
    break;

  case 32:
#line 146 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "1"); ;}
    break;

  case 33:
#line 147 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "2"); ;}
    break;

  case 34:
#line 148 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "3"); ;}
    break;

  case 35:
#line 149 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "4"); ;}
    break;

  case 36:
#line 150 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5");  push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 55:
#line 196 "Trex.y"
    { quadruple_relational(); ;}
    break;

  case 57:
#line 201 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 58:
#line 202 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 59:
#line 203 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 60:
#line 204 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 61:
#line 205 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 62:
#line 206 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 63:
#line 210 "Trex.y"
    { quadruple_add_sub(); ;}
    break;

  case 65:
#line 214 "Trex.y"
    { quadruple_add_sub(); ;}
    break;

  case 68:
#line 219 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 69:
#line 220 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 70:
#line 224 "Trex.y"
    { quadruple_mult_div(); ;}
    break;

  case 72:
#line 228 "Trex.y"
    { quadruple_mult_div(); ;}
    break;

  case 75:
#line 233 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 76:
#line 234 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 81:
#line 245 "Trex.y"
    { push_to_pilaOperadores("#"); ;}
    break;

  case 82:
#line 245 "Trex.y"
    { pop_of_pilaOperadores(); ;}
    break;

  case 87:
#line 265 "Trex.y"
    { push_to_pilaOperandos((yyvsp[(1) - (1)].sval), "5"); push_to_pilaTipos((yyvsp[(1) - (1)].sval)); ;}
    break;

  case 88:
#line 265 "Trex.y"
    { push_to_pilaOperadores(yylval.sval); ;}
    break;

  case 89:
#line 265 "Trex.y"
    { quadruple_relational(); ;}
    break;

  case 95:
#line 279 "Trex.y"
    { function_name = yylval.sval; insert_to_procs_table(function_name,"10","20"); set_current_function("1");;}
    break;

  case 98:
#line 284 "Trex.y"
    { set_current_function("0"); ;}
    break;

  case 105:
#line 303 "Trex.y"
    { name = yylval.sval; insert_to_vars_table(name,var_type); ;}
    break;

  case 107:
#line 307 "Trex.y"
    { name = yylval.sval; insert_to_vars_table(name,var_type); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1859 "Trex.tab.c"
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


#line 324 "Trex.y"


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
