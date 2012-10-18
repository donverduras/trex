%{
#include <iostream>
#include <stdio.h>
using namespace std;
#define YY_DECL extern "C" int yylex()
#include "trex.tab.h" //incluye los tipos de token que fueron definidos en el archivo de bison
%}

%option yylineno

cte_identificador [a-z][_a-zA-Z0-9]*
cte_int			-?[0-9]+
cte_float		-?[0-9]+"."[0-9]+
cte_string		\"[^"\r\n]*\"
cte_boolean		("true"|"false"|"TRUE"|"FALSE")
cte_char		[a-zA-Z]
espacio 		[ \t]+
%%

[\t\n]         		;
const				{ yylval.sval = strdup(yytext);return CONST; }
final				{ yylval.sval = strdup(yytext); return FINAL; }
super				{ yylval.sval = strdup(yytext); return SUPER; }
while				{ yylval.sval = strdup(yytext); return WHILE; }
for					{ yylval.sval = strdup(yytext); return FOR; }
if					{ yylval.sval = strdup(yytext); return IF; }
else				{ yylval.sval = strdup(yytext); return ELSE; }
not					{ yylval.sval = strdup(yytext); return NOT; }
read				{ yylval.sval = strdup(yytext); return READ; }
print				{ yylval.sval = strdup(yytext); return PRINT;}
program				{ yylval.sval = strdup(yytext); return PROGRAM; }
return				{ yylval.sval = strdup(yytext); return RETURN; }
function			{ yylval.sval = strdup(yytext); return FUNCTION; }
id					{ yylval.sval = strdup(yytext); return ID; }
int					{ yylval.sval = strdup(yytext); return INT; }
float				{ yylval.sval = strdup(yytext); return FLOAT; }
string				{ yylval.sval = strdup(yytext); return STRING; }
boolean				{ yylval.sval = strdup(yytext); return BOOLEAN; }
char				{ yylval.sval = strdup(yytext); return CHAR; }
max					{ yylval.sval = strdup(yytext); return MAX; }
min					{ yylval.sval = strdup(yytext); return MIN; }
reminder			{ yylval.sval = strdup(yytext); return REMINDER; }
floor				{ yylval.sval = strdup(yytext); return FLOOR; }
ceiling				{ yylval.sval = strdup(yytext); return CEILING; }
sqrt				{ yylval.sval = strdup(yytext); return SQRT; }
pow					{ yylval.sval = strdup(yytext); return POW; }
substring			{ yylval.sval = strdup(yytext); return SUBSTRING; }
stringappend		{ yylval.sval = strdup(yytext); return STRINGAPPEND; }
random				{ yylval.sval = strdup(yytext); return RANDOM; }
"{"					{ yylval.sval = strdup(yytext); return LLAVEIZQ; }
"}"					{ yylval.sval = strdup(yytext); return LLAVEDER; }
","					{ yylval.sval = strdup(yytext); return COMA; }
";"					{ yylval.sval = strdup(yytext); return PUNTOYCOMA; }
"="					{ yylval.sval = strdup(yytext); return IGUAL; }
"<"					{ yylval.sval = strdup(yytext); return MENORQUE; }
">"					{ yylval.sval = strdup(yytext); return MAYORQUE; }
"<>"				{ yylval.sval = strdup(yytext); return DIFERENTE; }
"=="				{ yylval.sval = strdup(yytext); return IGUALIGUAL; }
"+"					{ yylval.sval = strdup(yytext); return SUMA; }
"-"					{ yylval.sval = strdup(yytext); return RESTA; }
"*"					{ yylval.sval = strdup(yytext); return MULTIPLICACION; }
"/"					{ yylval.sval = strdup(yytext); return DIVISION; }
"("					{ yylval.sval = strdup(yytext); return PARENTESISIZQ; }
")"					{ yylval.sval = strdup(yytext); return PARENTESISDER; }
"["					{ yylval.sval = strdup(yytext); return CORIZQ; }
"]"					{ yylval.sval = strdup(yytext); return CORDER; }
"&&"				{ yylval.sval = strdup(yytext); return AND; }
"||"				{ yylval.sval = strdup(yytext); return OR; }
{cte_identificador}	{ yylval.sval = strdup(yytext); return CTE_ID; }
{cte_int}			{ yylval.sval = strdup(yytext); return CTE_INT; }
{cte_float}			{ yylval.sval = strdup(yytext); return CTE_FLOAT; }
{cte_string}		{ yylval.sval = strdup(yytext); return CTE_STRING; }
{cte_boolean}		{ yylval.sval = strdup(yytext); return CTE_BOOLEAN; }
{cte_char}			{ yylval.sval = strdup(yytext); return CTE_CHAR; }
\"[^"\r\n]*$ 		{ printf("Unterminated String "); yylval.sval = strdup(yytext); return CTE_STRING; };
.					;
%%