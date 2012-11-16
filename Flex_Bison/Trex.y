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
char *size;
char *function_name;
char *main_func;
char *function_called;
 
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
	programa_a  vars programa_b funcion programa_c programa_d { generate_obj(); cout << "EXITO" << endl;}
	| programa_a funcion programa_c programa_d { generate_obj(); cout << "EXITO" << endl;}
	| programa_a vars programa_b programa_d { generate_obj(); cout << "EXITO" << endl;}
	| programa_a programa_d { generate_obj(); cout << "EXITO" << endl;}
	;

programa_a:
	PROGRAM { initialize(); } CTE_ID { function_name = yylval.sval; main_func = function_name; insert_to_procs_table(function_name); main_function_name(function_name); set_current_function("0", function_name);} LLAVEIZQ
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
	LLAVEIZQ bloque21 LLAVEDER
	;

bloque21:
	estatuto c
	|
	;

c:
	estatuto c
	|
	;

vars:
	tipo CTE_ID vars2 PUNTOYCOMA { name = $2; insert_to_vars_table(name,var_type,function_name); }
	|tipo CTE_ID CORIZQ CTE_INT CORDER PUNTOYCOMA { name = $2;  size = $4; insert_arr_to_vars_table(name,var_type, size); }
	;

vars2:
	IGUAL var_cte
	|
	;

tipo:
	INT { var_type = yylval.sval;}
	|FLOAT { var_type = yylval.sval;}
	|STRING { var_type = yylval.sval;}
	|BOOLEAN { var_type = yylval.sval;}
	|CHAR { var_type = yylval.sval;}
	;

var_cte:
	CTE_INT { push_to_pilaOperandos($1, "0"); push_to_pilaTipos_directly("10"); } 
	|CTE_FLOAT { push_to_pilaOperandos($1, "1"); push_to_pilaTipos_directly("11"); }
	|CTE_STRING { push_to_pilaOperandos($1, "2"); push_to_pilaTipos_directly("12"); }
	|CTE_BOOLEAN { push_to_pilaOperandos($1, "3"); push_to_pilaTipos_directly("13"); }
	|CTE_CHAR { push_to_pilaOperandos($1, "4"); push_to_pilaTipos_directly("14"); }
	|CTE_ID { push_to_pilaOperandos($1, "5");  push_to_pilaTipos($1); }
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
	PRINT PARENTESISIZQ { push_to_pilaOperadores("print"); } escritura_a d PARENTESISDER PUNTOYCOMA
	;

escritura_a:
	exp { generateQuadruple_print(); }
	;

d:
	COMA { push_to_pilaOperadores("print"); } escritura_a d
	|
	;

condicion:
	condicion_a { generateQuadruple_if(); } bloque2 condicion_b { generate_fin_if(); }
	;

condicion_a:
	IF PARENTESISIZQ expresion PARENTESISDER
	;

condicion_b:
	ELSE { generateQuadruple_else(); } bloque2
	|
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
	FOR PARENTESISIZQ bloque_for PARENTESISDER bloque2 { generate_fin_for(); }
	;

bloque_for:
	CTE_ID { push_to_pilaOperandos($1, "5"); push_to_pilaTipos($1); } IGUAL { push_to_pilaOperadores(yylval.sval); } var_cte PUNTOYCOMA { generateQuadruple_asignacion(); } expresion PUNTOYCOMA { generateQuadruple_for2(); } bloque_for_2
	;

bloque_for_2:
	CTE_ID { push_to_pilaOperandos($1, "5"); push_to_pilaTipos($1); } IGUAL { push_to_pilaOperadores(yylval.sval); } CTE_ID { push_to_pilaOperandos($1, "5"); push_to_pilaTipos($1); } sumaresta CTE_INT { push_to_pilaOperandos($1, "0");  generateQuadruple_for3(); } 
	;

loopwhile:
	WHILE { push_quadruple_index_to_pilaSaltos(); } PARENTESISIZQ expresion PARENTESISDER { generateQuadruple_while(); } bloque2 { generate_fin_while(); }
	;

asignacion:
	CTE_ID { name = $1; push_to_pilaOperandos($1, "5"); push_to_pilaTipos($1); } asignacion_d asignacion_c
	;

asignacion_b:
	expresion
	| lectura
	;
	
asignacion_c:
	IGUAL { push_to_pilaOperadores(yylval.sval); } asignacion_b { quadruple_relational(); } PUNTOYCOMA
	;

asignacion_d:
	CORIZQ exp CORDER { verify_arr_limit(name); generateQuadruple_array(); }
	|
	;
	
lectura:
	READ PARENTESISIZQ PARENTESISDER PUNTOYCOMA
	;
	
funcion:
	FUNCTION CTE_ID { function_name = yylval.sval; insert_to_procs_table(function_name); set_current_function("1", function_name); reset_conts(); } PARENTESISIZQ funcion_c funcion_a
	;

funcion_a:
	PARENTESISDER { reset_param_counter(); } LLAVEIZQ { set_start_function(function_name); } funcion_d LLAVEDER { set_current_function("0", main_func); set_fin_function(function_name); } 
	;

funcion_b:
	vars funcion_b
	|
	;

funcion_c:
	param
	|
	;

funcion_d:
	vars funcion_b bloque
	| bloque
	;

llamada:
	CTE_ID { function_called = $1; verify_function_name(function_called); } PARENTESISIZQ { generate_activation_record(function_called); } llamada_2 PARENTESISDER { reset_param_counter(); } PUNTOYCOMA { generate_fin_llamada(function_called); }
	;
	
llamada_2:
	param2
	|
	;

param:
	tipo CTE_ID { name = yylval.sval; insert_to_vars_table(name,var_type,function_name); count_params(); insert_param_type(function_name, var_type); } g
	;

g:
	COMA tipo CTE_ID { name = yylval.sval; insert_to_vars_table(name,var_type,function_name); count_params(); insert_param_type(function_name, var_type); } g
	|
	;

param2:
	exp { verify_parameters(function_called); } h
	;

h:
	COMA { count_params(); } exp { verify_parameters(function_called); } h
	|
	;

arr:
	CTE_ID { name = $1; push_to_pilaOperandos($1, "5"); push_to_pilaTipos($1); } CORIZQ { push_to_pilaOperadores("#"); } exp { pop_of_pilaOperadores(); } CORDER { verify_arr_limit(name); generateQuadruple_array(); }
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