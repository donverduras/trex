%error-verbose
%{
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

%}

%union {
	char *sval;
}

%token <sval> CONST
%token <sval> FINAL 
%token <sval> SUPER 
%token <sval> WHILE 
%token <sval> FOR 
%token <sval> IF 
%token <sval> ELSE 
%token <sval> NOT 
%token <sval> READ 
%token <sval> PRINT 
%token <sval> PROGRAM 
%token <sval> RETURN 
%token <sval> FUNCTION
%token <sval> ID 
%token <sval> INT 
%token <sval> FLOAT 
%token <sval> STRING 
%token <sval> BOOLEAN 
%token <sval> CHAR
%token <sval> MAX
%token <sval> MIN
%token <sval> REMINDER
%token <sval> FLOOR
%token <sval> CEILING
%token <sval> SQRT
%token <sval> POW
%token <sval> SUBSTRING
%token <sval> STRINGAPPEND
%token <sval> RANDOM
%token <sval> LLAVEIZQ 
%token <sval> LLAVEDER 
%token <sval> COMA 
%token <sval> PUNTOYCOMA 
%token <sval> IGUAL 
%token <sval> MENORQUE 
%token <sval> MAYORQUE 
%token <sval> DIFERENTE
%token <sval> IGUALIGUAL
%token <sval> SUMA 
%token <sval> RESTA 
%token <sval> MULTIPLICACION 
%token <sval> DIVISION 
%token <sval> PARENTESISIZQ 
%token <sval> PARENTESISDER 
%token <sval> CORIZQ 
%token <sval> CORDER
%token <sval> AND
%token <sval> OR
%token <sval> CTE_ID 
%token <sval> CTE_INT 
%token <sval> CTE_FLOAT 
%token <sval> CTE_STRING
%token <sval> CTE_BOOLEAN 
%token <sval> CTE_CHAR

%%

programa:
	programa_a  vars programa_b funcion programa_c programa_d {cout << "EXITO" << endl;}
	| programa_a funcion programa_c programa_d {cout << "EXITO" << endl;}
	| programa_a vars programa_b programa_d {cout << "EXITO" << endl;}
	| programa_a programa_d {cout << "EXITO" << endl;}
	;

programa_a:
	PROGRAM { initialize(); } CTE_ID { function_name = yylval.sval; insert_to_procs_table(function_name,"0","300"); main_function_name(function_name); set_current_function("0");} LLAVEIZQ
	;

programa_b:
	vars programa_b
	|
	;

programa_c:
	funcion programa_c
	|
	;

programa_d:
	bloque LLAVEDER
	;

bloque:
	estatuto b
	|
	;

b:
	estatuto b
	|
	;

bloque2:
	LLAVEIZQ estatuto c LLAVEDER
	|LLAVEIZQ LLAVEDER
	;

c:
	estatuto c
	|
	;

vars:
	tipo CTE_ID IGUAL var_cte PUNTOYCOMA { name = $2; insert_to_vars_table(name,var_type); }
	|tipo CTE_ID PUNTOYCOMA { name = $2; insert_to_vars_table(name,var_type); }
	|tipo CTE_ID CORIZQ CTE_INT CORDER IGUAL var_cte PUNTOYCOMA
	|tipo CTE_ID CORIZQ CTE_INT CORDER PUNTOYCOMA
	;

tipo:
	INT { var_type = yylval.sval;}
	|FLOAT { var_type = yylval.sval;}
	|STRING { var_type = yylval.sval;}
	|BOOLEAN { var_type = yylval.sval;}
	|CHAR { var_type = yylval.sval;}
	;

var_cte:
	CTE_INT { } 
	|CTE_FLOAT {  }
	|CTE_STRING {  }
	|CTE_BOOLEAN {  }
	|CTE_CHAR {  }
	|CTE_ID { push_to_pilaOperandos($1);  push_to_pilaTipos($1); }
	;

estatuto:
	asignacion
	|condicion
	|escritura
	|loopfor
	|loopwhile
	|vars
	|lectura
	|llamada
	;

escritura:
	PRINT PARENTESISIZQ escritura_a d PARENTESISDER PUNTOYCOMA
	;

escritura_a:
	exp
	|CTE_STRING
	;

d:
	SUMA escritura_a d
	|
	;

condicion:
	condicion_a bloque2
	|condicion_a bloque2 condicion_b
	;

condicion_a:
	IF PARENTESISIZQ expresion PARENTESISDER
	;

condicion_b:
	ELSE bloque2
	;

expresion:
	exp expresion_b
	;
	
expresion_b:
	expresion_a exp { quadruple_relational(); }
	|
	;

expresion_a:
	MAYORQUE { push_to_pilaOperadores(yylval.sval); }
	|MENORQUE { push_to_pilaOperadores(yylval.sval); }
	|DIFERENTE { push_to_pilaOperadores(yylval.sval); }
	|IGUALIGUAL { push_to_pilaOperadores(yylval.sval); }
	|AND { push_to_pilaOperadores(yylval.sval); }
	|OR { push_to_pilaOperadores(yylval.sval); }
	;

exp:
	termino { quadruple_add_sub(); } e
	;

e:
	sumaresta termino { quadruple_add_sub(); } e
	|
	;

sumaresta:
	SUMA { push_to_pilaOperadores(yylval.sval); }
	|RESTA { push_to_pilaOperadores(yylval.sval); }
	;

termino:
	factor { quadruple_mult_div(); } f
	;

f:
	multdiv factor { quadruple_mult_div(); } f
	|
	;

multdiv:
	MULTIPLICACION { push_to_pilaOperadores(yylval.sval); }
	|DIVISION { push_to_pilaOperadores(yylval.sval); }
	;

factor:
	factor_a
	| sumaresta var_cte
	| var_cte
	| arr
	;

factor_a:
	PARENTESISIZQ { push_to_pilaOperadores("#"); } expresion PARENTESISDER { pop_of_pilaOperadores(); }
	;

loopfor:
	FOR PARENTESISIZQ bloque_for PARENTESISDER bloque2
	;

bloque_for:
	CTE_ID IGUAL var_cte PUNTOYCOMA expresion PUNTOYCOMA bloque_for_2
	;

bloque_for_2:
	CTE_ID IGUAL CTE_ID sumaresta CTE_INT
	;

loopwhile:
	WHILE PARENTESISIZQ expresion PARENTESISDER bloque2
	;

asignacion:
	CTE_ID { push_to_pilaOperandos($1); push_to_pilaTipos($1); } IGUAL { push_to_pilaOperadores(yylval.sval); } asignacion_b { quadruple_relational(); } PUNTOYCOMA
	| CTE_ID CORIZQ exp CORDER IGUAL asignacion_b PUNTOYCOMA
	;

asignacion_b:
	expresion
	| lectura
	;
	
lectura:
	READ PARENTESISIZQ PARENTESISDER PUNTOYCOMA
	;
	
funcion:
	FUNCTION CTE_ID { function_name = yylval.sval; insert_to_procs_table(function_name,"10","20"); set_current_function("1");} PARENTESISIZQ funcion_c funcion_a
	;

funcion_a:
	PARENTESISDER LLAVEIZQ vars funcion_b bloque LLAVEDER
	|PARENTESISDER LLAVEIZQ bloque LLAVEDER { set_current_function("0"); }
	;

funcion_b:
	vars funcion_b
	|
	;

funcion_c:
	param
	|
	;

llamada:
	CTE_ID PARENTESISIZQ param2 PARENTESISDER PUNTOYCOMA
	| CTE_ID PARENTESISIZQ PARENTESISDER PUNTOYCOMA
	;

param:
	tipo CTE_ID { name = yylval.sval; insert_to_vars_table(name,var_type); } g
	;

g:
	COMA tipo CTE_ID { name = yylval.sval; insert_to_vars_table(name,var_type); } g
	|
	;

param2:
	exp h
	;

h:
	COMA exp h
	|
	;

arr:
	CTE_ID CORIZQ exp CORDER
	;

%%

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