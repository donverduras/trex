/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 26 "Trex.y"
{
	char *sval;
}
/* Line 1529 of yacc.c.  */
#line 161 "Trex.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

