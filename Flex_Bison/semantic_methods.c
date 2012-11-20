#include <iostream>
#include <string>
#include <sstream> 
#include <stdlib.h>
#include <glib.h>
#include <fstream>
#include "semantic_methods.h"
#define GPOINTER_TO_INT(p) ((gint)  (glong) (p))
#define GINT_TO_POINTER(i) ((gpointer) (glong) (i))

using namespace std;

/******************************Declaración de variables**********************************/

//Inicio de bloques de memoria
enum virtual_memory { GLOBAL_INT=1000, GLOBAL_FLOAT=6000, GLOBAL_STRING=11000, GLOBAL_BOOLEAN=16000, GLOBAL_CHAR=21000,
					  LOCAL_INT=26000, LOCAL_FLOAT=31000, LOCAL_STRING=36000,  LOCAL_BOOLEAN=41000,  LOCAL_CHAR=46000,
					  TEMP_INT=51000,  TEMP_FLOAT=56000,  TEMP_STRING=61000,   TEMP_BOOLEAN=66000,   TEMP_CHAR=71000,
					  CONST_INT=76000, CONST_FLOAT=81000, CONST_STRING=86000,  CONST_BOOLEAN=91000,  CONST_CHAR=96000,
					  POINTERS = 100000 };

//Simbolos
enum symbols {	GOTO=200,	GOTOF=201,	PRINT=300,	ERA=400,	GOSUB=401,	RET=501,	VER=403, 		POINTER=15,
				INIPROC=500,PARAM=402, 	READ=301, 	MIN=404,	MAX=405,	POW=406,	REMAINDER=407,	FLOOR=408,
				CEILING=409,RANDOM=410,	SQRT=411 };

//Contadores de direcciones virtuales
int global_int_cont = 0,	global_float_cont = 0,	global_string_cont = 0,	global_boolean_cont = 0,	global_char_cont = 0,
	local_int_cont = 0,		local_float_cont = 0, 	local_string_cont = 0, 	local_boolean_cont = 0,		local_char_cont = 0,
	temp_int_cont = 0, 		temp_float_cont = 0, 	temp_string_cont = 0, 	temp_boolean_cont = 0, 		temp_char_cont = 0,
	const_int_cont = 0, 	const_float_cont = 0, 	const_string_cont = 0, 	const_boolean_cont = 0, 	const_char_cont = 0,
	pointers_cont = 0;

//Locales y temporales x funcion
int local_int_cont_func = 0,	local_float_cont_func = 0, 	local_string_cont_func = 0, local_boolean_cont_func = 0,	local_char_cont_func = 0,
	temp_int_cont_func = 0, 	temp_float_cont_func = 0, 	temp_string_cont_func = 0, 	temp_boolean_cont_func = 0, 	temp_char_cont_func = 0;

//Bloque de variables utilizadas para la generación de tablas de procedimientos y variables
static int procedure_index[26];			//Tabla de Hash para los procedimientos
static int table_size = 26;				//Tamaño de las "tablas"
static int variable_index[26];			//Tabla de Hash para las variables

static GQueue* tableProc_stack;			//Lista donde están almacenados los nodos con la información de cada procedimiento
static GQueue* tableVar_stack;			//Lista donde están almacenados los nodos con la información de cada variable

//Bloque de variables utilizadas para la generación de código intermedio
static int quadruple_index = 1;
static int param_counter = 0;
static int current_function;
static char* main_function;
static char* current_function_name;
static int numeroFuncionLlamada_index = 0;
static int numeroFuncionLlamada;

static ofstream objeto;

static GHashTable* constants;		//Tabla de constantes

static GQueue* pilaOperadores;
static GQueue* pilaOperandos;
static GQueue* pilaPasos;
static GQueue* pilaSaltos;
static GQueue* pilaTipos;
static GQueue* pilaAuxFor;
//static GQueue* pilaParametros;

static int cubo[11][5][5] =
{
		{//"+"
			{1, 2, 3, -1, -1},
			{2, 2, 3, -1, -1},
			{3, 3, 3, 3, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, 3, -1, -1}
		},
		{//"-"
			{1, 2, -1, -1, -1},
			{2, 2, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1}
		},
		{//"/"
			{2, 2, -1, -1, -1},
			{2, 2, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1}
		},
		{//"*"
			{1, 2, -1, -1, -1},
			{2, 2, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1}
		},
		{//"<"
			{4, 4, -1, -1, -1},
			{4, 4, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1}
		},
		{//">"
			{4, 4, -1, -1, -1},
			{4, 4, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1}
		},
		{//"="
			{1, -1, -1, -1, -1},
			{-1, 2, -1, -1, -1},
			{-1, -1, 3, -1, -1},
			{-1, -1, -1, 4, -1},
			{-1, -1, -1, -1, 5}
		},
		{//"<>"
			{4, 4, -1, -1, -1},
			{4, 4, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, 4, -1},
			{-1, -1, -1, -1,-1}
		},
		{//"=="
			{4, 4, -1, -1, -1},
			{4, 4, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, 4, -1},
			{-1, -1, -1, -1, -1}
		},
		{//"&&"
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, 4, -1},
			{-1, -1, -1, -1, -1}
		},
		{//"||"
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, 4, -1},
			{-1, -1, -1, -1, -1}
		}
};

/*********************************Estructuras de datos***********************************/

struct Function{
	int operador;
	int operando1;
	int operando2;
	char *resultado;
};

//Nodo que contiene la cantidad de variables dentro de una funcion
struct VarCont{
	int integers;
	int flotantes;
	int estrings;
	int booleans;
	int chars;
};

//Nodo que contiene información importante de cada procedimiento
struct Procedure{
	string name;
	int dirInitial;					//Cuadruplo inicial
	int numParams;
	VarCont locals;
	VarCont temps;
	GQueue *pilaParams;
};

//Nodo que contiene información referente a la generación de cuádruplos
struct Quadruple{
	int operador;
	int operando1;
	int operando2;
	int resultado;
};

//Nodo que contiene información importante de cada variable
struct Variable{
	string name;
	string type;
	int dirVirtual;
	int limite;
	char* procName;
};

/****************************************Métodos*****************************************/

void alter_dirVirtual(char* var_type, int m0){
	int type, dirVirtual;
	const char* aux;

	aux = var_type;
	type = get_var_type(aux);
	
	if(current_function == 0){
		if(type == 0){
			global_int_cont = global_int_cont + m0;
		}else if(type == 1){
			global_float_cont = global_float_cont + m0;
		}else if(type == 2){
			global_string_cont = global_string_cont + m0;
		}else if(type == 3){
			global_boolean_cont = global_boolean_cont + m0;
		}else if(type == 4){
			global_char_cont = global_char_cont + m0;
		}
	}else if(current_function != 0){
		if(type == 0){
			local_int_cont = local_int_cont + m0;
		}else if(type == 1){
			local_float_cont = local_float_cont + m0;
		}else if(type == 2){
			local_string_cont = local_string_cont + m0;
		}else if(type == 3){
			local_boolean_cont = local_boolean_cont + m0;
		}else if(type == 4){
			local_char_cont = local_char_cont + m0;
		}
	}
}

int asign_dirVirtual(char* var_type){
	int type, dirVirtual;
	const char* aux;
	
	aux = var_type;
	type = get_var_type(aux);
	
	if(current_function == 0){
		if(type == 0){
			dirVirtual = GLOBAL_INT + global_int_cont;
			global_int_cont++;
		}else if(type == 1){
			dirVirtual = GLOBAL_FLOAT + global_float_cont;
			global_float_cont++;
		}else if(type == 2){
			dirVirtual = GLOBAL_STRING + global_string_cont;
			global_string_cont++;
		}else if(type == 3){
			dirVirtual = GLOBAL_BOOLEAN + global_boolean_cont;
			global_boolean_cont++;
		}else if(type == 4){
			dirVirtual = GLOBAL_CHAR + global_char_cont;
			global_char_cont++;
		}
	}else if(current_function != 0){
		if(type == 0){
			dirVirtual = LOCAL_INT + local_int_cont;
			local_int_cont++;
			local_int_cont_func++;
		}else if(type == 1){
			dirVirtual = LOCAL_FLOAT + local_float_cont;
			local_float_cont++;
			local_float_cont_func++;
		}else if(type == 2){
			dirVirtual = LOCAL_STRING + local_string_cont;
			local_string_cont++;
			local_string_cont_func++;
		}else if(type == 3){
			dirVirtual = LOCAL_BOOLEAN + local_boolean_cont;
			local_boolean_cont++;
			local_boolean_cont_func++;
		}else if(type == 4){
			dirVirtual = LOCAL_CHAR + local_char_cont;
			local_char_cont++;
			local_char_cont_func++;
		}
	}
	
	if(type == 10){
		dirVirtual = CONST_INT + const_int_cont;
		const_int_cont++;
	}else if(type == 11){
		dirVirtual = CONST_FLOAT + const_float_cont;
		const_float_cont++;
	}else if(type == 12){
		dirVirtual = CONST_STRING + const_string_cont;
		const_string_cont++;
	}else if(type == 13){
		dirVirtual = CONST_BOOLEAN + const_boolean_cont;
		const_boolean_cont++;
	}else if(type == 14){
		dirVirtual = CONST_CHAR + const_char_cont;
		const_char_cont++;
	}
	
	return dirVirtual;
}

/*******************************************
 * Función que checa si existe una lista de*
 * variables o procedimientos dentro de la *
 * lista principal						   *
 *******************************************/
bool check_if_stack_exists(int key, int arrType){
	if(arrType == 0){						//Procedimientos
		if(procedure_index[key] != -1)		//Si tiene un valor de -1 significa que no hay listas creadas para esa letra
			return true;
		else
			return false;
	}else if(arrType == 1){					//Variables
		if(variable_index[key] != -1)
			return true;
		else
			return false;
	}
}

void count_params(){
	param_counter++;
}

void fillQuadruple_main(){
	Quadruple *aux = (Quadruple *)g_queue_peek_nth(pilaPasos,0);
	aux->resultado = quadruple_index;
	
	//cout << "La siguiente instruccion es la numero: " << quadruple_index << "\n";
	//cout << "Cuadruplo actualizado: ";
	//cout << "( " << aux->operador << ", " << aux->operando1 << ", " << aux->operando2 << ", " << aux->resultado << " ) \n";
	
	g_queue_push_nth(pilaPasos, aux, 0);
	g_queue_pop_nth(pilaPasos, 1);
}

void delete_vars_from_varTable(char *func_name){
	GQueue *aux = g_queue_new();
	const char* aux_func_name = func_name;
	const char* aux_var_func_name;
	
	for(int i=0; i<g_queue_get_length(tableVar_stack); i++){
		aux = (GQueue *)g_queue_peek_nth(tableVar_stack,i);
		
		for(int j=0; j<g_queue_get_length(aux); j++){
			Variable *var = new Variable;
			
			var = (Variable *)g_queue_peek_nth(aux, j);
			aux_var_func_name = var->procName;
			
			//cout << "Func name: " << aux_func_name << "\n";
			//cout << "Var func name: " << aux_var_func_name << "\n";
			
			if(strcmp(aux_var_func_name,aux_func_name) == 0){
				g_queue_pop_nth(aux, j);
			}
		}
	}
}

void generate_activation_record(char *func_name){
	Quadruple *new_quadruple = new Quadruple;
	GQueue* stack_aux = g_queue_new();
	
	//Directorio de Procedimientos
	numeroFuncionLlamada_index = 0;
	for(int i=0; i< g_queue_get_length(tableProc_stack); i++){
		stack_aux = (GQueue *)g_queue_peek_nth(tableProc_stack, i);
		g_queue_foreach(stack_aux,search_in_pilas,func_name);
	}
	
	new_quadruple->operador = ERA;
	new_quadruple->operando2 = -1;
	new_quadruple->operando1 = -1;
	new_quadruple->resultado = numeroFuncionLlamada;
	//cout << "#" << quadruple_index << " ";
	//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
	g_queue_push_tail(pilaPasos, new_quadruple);
	quadruple_index++;
}

void generate_fin_for(){
	int falso = GPOINTER_TO_INT(g_queue_pop_tail(pilaSaltos));
	Quadruple *aux1 = new Quadruple();
	Quadruple *aux2 = new Quadruple();
	
	aux2 = (Quadruple *)g_queue_pop_tail(pilaAuxFor);
	aux1 = (Quadruple *)g_queue_pop_tail(pilaAuxFor);
	
	//cout << "**\n";
	//cout << "( " << aux1->operador << ", " << aux1->operando1 << ", " << aux1->operando2 << ", " << aux1->resultado << " ) \n";
	g_queue_push_tail(pilaPasos, aux1);
	//cout << "( " << aux2->operador << ", " << aux2->operando1 << ", " << aux2->operando2 << ", " << aux2->resultado << " ) \n";
	g_queue_push_tail(pilaPasos, aux2);
	//cout << "**\n";
	
	Quadruple *new_quadruple = new Quadruple;
	new_quadruple->operador = GOTO;
	new_quadruple->operando2 = -1;
	new_quadruple->operando1 = -1;
	new_quadruple->resultado = falso;
	
	//cout << "#" << quadruple_index << " ";
	//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
	g_queue_push_tail(pilaPasos, new_quadruple);
	quadruple_index++;

	
	Quadruple *aux = (Quadruple *)g_queue_peek_nth(pilaPasos,falso);
	aux->resultado = quadruple_index;
	
	//cout << "La siguiente instruccion es la numero: " << retorno << "\n";
	//cout << "Cuadruplo actualizado: ";
	//cout << "( " << aux->operador << ", " << aux->operando1 << ", " << aux->operando2 << ", " << aux->resultado << " ) \n";
	
	g_queue_push_nth(pilaPasos, aux, falso);
	g_queue_pop_nth(pilaPasos, falso+1);
}

void generate_fin_if(){
	int quad_number = GPOINTER_TO_INT(g_queue_pop_tail(pilaSaltos));
	Quadruple *aux = (Quadruple *)g_queue_peek_nth(pilaPasos,quad_number);
	aux->resultado = quadruple_index;
	
	//cout << "La siguiente instruccion es la numero: " << quadruple_index << "\n";
	//cout << "Cuadruplo actualizado: ";
	//cout << "( " << aux->operador << ", " << aux->operando1 << ", " << aux->operando2 << ", " << aux->resultado << " ) \n";//cout << "Push to pila operandos: temp o " << temp << "\n";
	
	g_queue_push_nth(pilaPasos, aux, quad_number);
	g_queue_pop_nth(pilaPasos, quad_number+1);

}

void generate_fin_llamada(char *func_name){
	Quadruple *new_quadruple = new Quadruple;
	GQueue* stack_aux = g_queue_new();
	
	//Directorio de Procedimientos
	numeroFuncionLlamada_index = 0;
	for(int i=0; i< g_queue_get_length(tableProc_stack); i++){
		stack_aux = (GQueue *)g_queue_peek_nth(tableProc_stack, i);
		g_queue_foreach(stack_aux,search_in_pilas,func_name);
	}
	
	new_quadruple->operador = GOSUB;
	new_quadruple->operando2 = -1;
	new_quadruple->operando1 = -1;
	new_quadruple->resultado = numeroFuncionLlamada;
	
	//cout << "#" << quadruple_index << " ";
	//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
	g_queue_push_tail(pilaPasos, new_quadruple);
	
	quadruple_index++;
}

void generate_fin_while(){
	int falso = GPOINTER_TO_INT(g_queue_pop_tail(pilaSaltos));
	int retorno = GPOINTER_TO_INT(g_queue_pop_tail(pilaSaltos));
	
	Quadruple *new_quadruple = new Quadruple;
	new_quadruple->operador = GOTO;
	new_quadruple->operando2 = -1;
	new_quadruple->operando1 = -1;
	new_quadruple->resultado = retorno;
	
	//cout << "#" << quadruple_index << " ";
	//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
	g_queue_push_tail(pilaPasos, new_quadruple);
	quadruple_index++;
	
	Quadruple *aux = (Quadruple *)g_queue_peek_nth(pilaPasos,falso);
	aux->resultado = quadruple_index;
	
	//cout << "La siguiente instruccion es la numero: " << retorno << "\n";
	//cout << "Cuadruplo actualizado: ";
	//cout << "( " << aux->operador << ", " << aux->operando1 << ", " << aux->operando2 << ", " << aux->resultado << " ) \n";
	
	g_queue_push_nth(pilaPasos, aux, falso);
	g_queue_pop_nth(pilaPasos, falso+1);
}

void generate_obj(){
	GQueue* stack_aux = g_queue_new();
	
	objeto.open("test.obj");
	
	//Directorio de Procedimientos
	objeto << g_queue_get_length(tableProc_stack) << "\n";
	for(int i=0; i< g_queue_get_length(tableProc_stack); i++){
		stack_aux = (GQueue *)g_queue_peek_nth(tableProc_stack, i);
		g_queue_foreach(stack_aux,print_pilas,NULL);
	}
	
	objeto << "%%" << "\n";
	
	//Directorio de constantes
	objeto << g_hash_table_size(constants) << "\n";
	g_hash_table_foreach(constants, print_hashTable, NULL);

	objeto << "%%" << "\n";
	
	//Cuadruplos
	objeto << g_queue_get_length(pilaPasos) << "\n";
	g_queue_foreach(pilaPasos,print_quadruples,NULL);
	
	objeto << "%%" << "\n";
	//Numero de apuntadores
	objeto << pointers_cont;
	
	objeto.close();
	
}

void generateQuadruple(){
	int op, operando1, operando2, temp;
	char *aux, *temp_aux;
	int resultadoCubo, operador, op1, op2, dirVir;
	
	operador = GPOINTER_TO_INT(g_queue_peek_tail(pilaOperadores));	
	op2 = GPOINTER_TO_INT(g_queue_peek_nth(pilaTipos,(g_queue_get_length(pilaTipos)-2)));
	op1 = GPOINTER_TO_INT(g_queue_peek_tail(pilaTipos));

	resultadoCubo = cubo[operador][op1][op2] - 1;						//Para que int empiece de 0
	

	
	if(resultadoCubo != -1){
		g_queue_pop_tail(pilaTipos);
		g_queue_pop_tail(pilaTipos);
		
		Quadruple *new_quadruple = new Quadruple;
		op = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperadores));
		operando2 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
		operando1 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
			
		if(resultadoCubo == 0){
			dirVir = TEMP_INT + temp_int_cont;
			temp_int_cont++;
			temp_int_cont_func++;
		}else if(resultadoCubo == 1){
			dirVir = TEMP_FLOAT + temp_float_cont;
			temp_float_cont++;
			temp_float_cont_func++;
		}else if(resultadoCubo == 2){
			dirVir = TEMP_STRING + temp_string_cont;
			temp_string_cont++;
			temp_string_cont_func++;
		}else if(resultadoCubo == 3){
			dirVir = TEMP_BOOLEAN + temp_boolean_cont;
			temp_boolean_cont++;
			temp_boolean_cont_func++;
		}else if(resultadoCubo == 4){
			dirVir = TEMP_CHAR + temp_char_cont;
			temp_char_cont++;
			temp_char_cont_func++;
		}
		
		//temp = convert_to_char(dirVir);
		g_queue_push_tail(pilaOperandos, (gpointer) dirVir);
		
		new_quadruple->operador = op;
		new_quadruple->operando2 = operando2;
		new_quadruple->operando1 = operando1;
		new_quadruple->resultado = dirVir;
		
		cout << "#" << quadruple_index << " ";
		cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		g_queue_push_tail(pilaPasos, new_quadruple);
		quadruple_index++;
		
		//temp_aux = convert_to_char(resultadoCubo);
		g_queue_push_tail(pilaTipos, (gpointer) resultadoCubo);
		
		
		/*
		//cout << "Push to pila operandos: temp o " << temp << "\n";
		cout << "Pila Operandos: ";
		g_queue_foreach(pilaOperandos, (GFunc)print_pilas, NULL);
		cout << "\n";
		cout << "Pila Tipos: ";
		g_queue_foreach(pilaTipos, (GFunc)print_pilas, NULL);
		cout << "\n";
		cout << "Pila Operadores: ";
		g_queue_foreach(pilaOperadores, (GFunc)print_pilas, NULL);
		cout << "\n\n";
		*/
		
	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
}

void generateQuadruple_array(){

	int operando2, operando1, dirVir;
	
	g_queue_pop_tail(pilaTipos);
	
	Quadruple *new_quadruple = new Quadruple;
	operando2 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));					//Resultado
	operando1 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));					//dirBase
	dirVir = POINTERS + pointers_cont;												
	pointers_cont++;
	
	new_quadruple->operador = 800;													//Suma
	new_quadruple->operando2 = operando2;
	new_quadruple->operando1 = operando1;
	new_quadruple->resultado = dirVir;
	
	//cout << "#" << quadruple_index << " ";
	//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
	g_queue_push_tail(pilaPasos, new_quadruple);
	quadruple_index++;
	
	g_queue_push_tail(pilaOperandos, GINT_TO_POINTER(dirVir));
	g_queue_push_tail(pilaTipos, GINT_TO_POINTER(0));
	
	/*
	cout << "Pila Operandos: ";
	g_queue_foreach(pilaOperandos, (GFunc)print_pilas, NULL);
	cout << "\n";
	cout << "Pila Tipos: ";
	g_queue_foreach(pilaTipos, (GFunc)print_pilas, NULL);
	cout << "\n";
	cout << "Pila Operadores: ";
	g_queue_foreach(pilaOperadores, (GFunc)print_pilas, NULL);
	cout << "\n\n";
	*/
}

void generateQuadruple_asignacion(){
	//cout << "#" << quadruple_index << " ";
	int op, operando1, temp;
	char *aux;
	int operador, op1, op2, resultadoCubo, res;
	char *result;
	
	//cout << "ENTRE ASIGNACION \n";
	
	operador = GPOINTER_TO_INT(g_queue_peek_tail(pilaOperadores));	
	op2 = GPOINTER_TO_INT(g_queue_peek_nth(pilaTipos,(g_queue_get_length(pilaTipos)-2)));
	op1 = GPOINTER_TO_INT(g_queue_peek_tail(pilaTipos));
	resultadoCubo = cubo[operador][op1][op2] - 1;						//Para que int empiece de 0
	
	if( resultadoCubo >= 0 ){
		g_queue_pop_tail(pilaTipos);
		g_queue_pop_tail(pilaTipos);
		
		Quadruple *new_quadruple = new Quadruple;
		op = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperadores));
		operando1 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
		res = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
	
		new_quadruple->operador = op;
		new_quadruple->operando2 = -1;
		new_quadruple->operando1 = operando1;
		new_quadruple->resultado = res;
		
		//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		//cout << "Cuadruplo creado \n";
		g_queue_push_tail(pilaPasos, new_quadruple);
		quadruple_index++;
		
		/*cout << "Pila Tipos: ";
		g_queue_foreach(pilaTipos, (GFunc)print_pilas, NULL);
		cout << "\n";
		cout << "Pila Operandos: ";
		g_queue_foreach(pilaOperandos, (GFunc)print_pilas, NULL);
		cout << "\n";
		cout << "Pila Operadores: ";
		g_queue_foreach(pilaOperadores, (GFunc)print_pilas, NULL);
		cout << "\n";*/
		
	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
}

void generateQuadruple_ceiling(){
	int op, operando1, temp;
	char *aux, *temp_aux;
	int resultadoCubo, operador, op1, dirVir;
	
	op1 = GPOINTER_TO_INT(g_queue_peek_tail(pilaTipos));
	
		
	if(op1 == 1){
		g_queue_pop_tail(pilaTipos);
		
		Quadruple *new_quadruple = new Quadruple;
		operando1 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
			

		dirVir = TEMP_FLOAT + temp_float_cont;
		temp_float_cont++;
		temp_float_cont_func++;

		
		g_queue_push_tail(pilaOperandos, (gpointer) dirVir);
		
		new_quadruple->operador = CEILING;
		new_quadruple->operando2 = -1;
		new_quadruple->operando1 = operando1;
		new_quadruple->resultado = dirVir;
		
		//cout << "#" << quadruple_index << " ";
		//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		g_queue_push_tail(pilaPasos, new_quadruple);
		quadruple_index++;
		
		g_queue_push_tail(pilaTipos, (gpointer) resultadoCubo);
		
	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
}

void generateQuadruple_else(){
	//Sacar la instruccion a rellenar del IF
	int quad_number = GPOINTER_TO_INT(g_queue_pop_tail(pilaSaltos));
	
	//cout << "#" << quadruple_index << " ";
	//Generar GOTO
	Quadruple *new_quadruple = new Quadruple;
	new_quadruple->operador = GOTO;
	new_quadruple->operando1 = -1;
	new_quadruple->operando2 = -1;
	new_quadruple->resultado = -1;
	
	//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
	
	g_queue_push_tail(pilaPasos, new_quadruple);
	g_queue_push_tail(pilaSaltos, GINT_TO_POINTER(quadruple_index-1));
	quadruple_index++;
	
	//cout << "****************Pila Saltos: ";
	//g_queue_foreach(pilaSaltos, (GFunc)print_pilas, NULL);
	//cout << "\n";
	
	//Rellenar GOTOF del IF
	Quadruple *aux = (Quadruple *)g_queue_peek_nth(pilaPasos,quad_number);
	aux->resultado = quadruple_index;
	
	//cout << "La siguiente instruccion es la numero: " << quadruple_index << "\n";
	//cout << "Cuadruplo actualizado: ";
	//cout << "( " << aux->operador << ", " << aux->operando1 << ", " << aux->operando2 << ", " << aux->resultado << " ) \n";
	
	g_queue_push_nth(pilaPasos, aux, quad_number);
	g_queue_pop_nth(pilaPasos, quad_number+1);
	
}

void generateQuadruple_floor(){
	int op, operando1, temp;
	char *aux, *temp_aux;
	int resultadoCubo, operador, op1, dirVir;
	
	op1 = GPOINTER_TO_INT(g_queue_peek_tail(pilaTipos));
	
		
	if(op1 == 1){
		g_queue_pop_tail(pilaTipos);
		
		Quadruple *new_quadruple = new Quadruple;
		operando1 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
			

		dirVir = TEMP_FLOAT + temp_float_cont;
		temp_float_cont++;
		temp_float_cont_func++;

		
		g_queue_push_tail(pilaOperandos, (gpointer) dirVir);
		
		new_quadruple->operador = FLOOR;
		new_quadruple->operando2 = -1;
		new_quadruple->operando1 = operando1;
		new_quadruple->resultado = dirVir;
		
		//cout << "#" << quadruple_index << " ";
		//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		g_queue_push_tail(pilaPasos, new_quadruple);
		quadruple_index++;
		
		g_queue_push_tail(pilaTipos, (gpointer) resultadoCubo);
		
	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
}

void generateQuadruple_for2(){
	//cout << "#" << quadruple_index << " ";
	int aux, resultado;
	
	aux = GPOINTER_TO_INT(g_queue_pop_tail(pilaTipos));
	
	if(aux == 3){
		resultado = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
		
		Quadruple *new_quadruple = new Quadruple;
		new_quadruple->operador = GOTOF;
		new_quadruple->operando1 = resultado;
		new_quadruple->operando2 = -1;
		new_quadruple->resultado = -1;
		
		//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		g_queue_push_tail(pilaPasos, new_quadruple);
		g_queue_push_tail(pilaSaltos, GINT_TO_POINTER(quadruple_index-1));
		
		quadruple_index++;
	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
}

void generateQuadruple_for3(){
	int op, operando1, operando2, temp;
	char *aux, *temp_aux;
	int resultadoCubo, operador, op1, op2, dirVir, res;
	
	operador = GPOINTER_TO_INT(g_queue_peek_tail(pilaOperadores));	
	op2 = GPOINTER_TO_INT(g_queue_peek_nth(pilaTipos,(g_queue_get_length(pilaTipos)-2)));
	op1 = GPOINTER_TO_INT(g_queue_peek_tail(pilaTipos));
	resultadoCubo = cubo[operador][op1][op2] - 1;						//Para que int empiece de 0
		
	if(resultadoCubo != -1){
		g_queue_pop_tail(pilaTipos);
		g_queue_pop_tail(pilaTipos);
		
		Quadruple *new_quadruple = new Quadruple;
		op = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperadores));
		operando2 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
		operando1 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
			
		if(resultadoCubo == 0){
			dirVir = TEMP_INT + temp_int_cont;
			temp_int_cont++;
			temp_int_cont_func++;
		}else if(resultadoCubo == 1){
			dirVir = TEMP_FLOAT + temp_float_cont;
			temp_float_cont++;
			temp_float_cont_func++;
		}else if(resultadoCubo == 2){
			dirVir = TEMP_STRING + temp_string_cont;
			temp_string_cont++;
			temp_string_cont_func++;
		}else if(resultadoCubo == 3){
			dirVir = TEMP_BOOLEAN + temp_boolean_cont;
			temp_boolean_cont++;
			temp_boolean_cont_func++;
		}else if(resultadoCubo == 4){
			dirVir = TEMP_CHAR + temp_char_cont;
			temp_char_cont++;
			temp_char_cont_func++;
		}
		
		g_queue_push_tail(pilaOperandos, (gpointer) dirVir);
		
		new_quadruple->operador = op;
		new_quadruple->operando2 = operando2;
		new_quadruple->operando1 = operando1;
		new_quadruple->resultado = dirVir;
		
		//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		g_queue_push_tail(pilaAuxFor, new_quadruple);
		quadruple_index++;
		
		g_queue_push_tail(pilaTipos, (gpointer) resultadoCubo);
		
	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
	
	/********************************************************************************************************************************/
	
	operador = GPOINTER_TO_INT(g_queue_peek_tail(pilaOperadores));	
	op2 = GPOINTER_TO_INT(g_queue_peek_nth(pilaTipos,(g_queue_get_length(pilaTipos)-2)));
	op1 = GPOINTER_TO_INT(g_queue_peek_tail(pilaTipos));
	resultadoCubo = cubo[operador][op1][op2] - 1;						//Para que int empiece de 0
	
	if(resultadoCubo != -1){
		g_queue_pop_tail(pilaTipos);
		g_queue_pop_tail(pilaTipos);
		
		Quadruple *new_quadruple = new Quadruple;
		op = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperadores));
		operando1 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
		res = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
	
		new_quadruple->operador = op;
		new_quadruple->operando2 = -1;
		new_quadruple->operando1 = operando1;
		new_quadruple->resultado = res;
		
		//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";

		g_queue_push_tail(pilaAuxFor, new_quadruple);
		quadruple_index++;

	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
}

void generateQuadruple_if(){
	//cout << "#" << quadruple_index << " ";
	int aux, resultado;
	
	aux = GPOINTER_TO_INT(g_queue_pop_tail(pilaTipos));
	
	if(aux == 3){
		resultado = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
		
		Quadruple *new_quadruple = new Quadruple;
		new_quadruple->operador = GOTOF;
		new_quadruple->operando1 = resultado;
		new_quadruple->operando2 = -1;
		new_quadruple->resultado = -1;
		
		//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		g_queue_push_tail(pilaPasos, new_quadruple);
		g_queue_push_tail(pilaSaltos, GINT_TO_POINTER(quadruple_index-1));
		
		quadruple_index++;
	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
	
	//cout << ".........................Pila Saltos: ";
	//g_queue_foreach(pilaSaltos, (GFunc)print_pilas, NULL);
	//cout << "\n";
}

void generateQuadruple_max(){
	int op, operando1, operando2, temp;
	char *aux, *temp_aux;
	int resultadoCubo, operador, op1, op2, dirVir;
	
	op2 = GPOINTER_TO_INT(g_queue_peek_nth(pilaTipos,(g_queue_get_length(pilaTipos)-2)));
	op1 = GPOINTER_TO_INT(g_queue_peek_tail(pilaTipos));
	resultadoCubo = cubo[operador][op1][op2] - 1;
	
		
	if(op1 == op2){
		g_queue_pop_tail(pilaTipos);
		g_queue_pop_tail(pilaTipos);
		
		Quadruple *new_quadruple = new Quadruple;
		operando2 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
		operando1 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
			
		if(resultadoCubo == 0){
			dirVir = TEMP_INT + temp_int_cont;
			temp_int_cont++;
			temp_int_cont_func++;
		}else if(resultadoCubo == 1){
			dirVir = TEMP_FLOAT + temp_float_cont;
			temp_float_cont++;
			temp_float_cont_func++;
		}
		
		g_queue_push_tail(pilaOperandos, (gpointer) dirVir);
		
		new_quadruple->operador = MAX;
		new_quadruple->operando2 = operando2;
		new_quadruple->operando1 = operando1;
		new_quadruple->resultado = dirVir;
		
		//cout << "#" << quadruple_index << " ";
		//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		g_queue_push_tail(pilaPasos, new_quadruple);
		quadruple_index++;
		
		g_queue_push_tail(pilaTipos, (gpointer) resultadoCubo);
		
	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
}

void generateQuadruple_main(){
	int aux, resultado;
	
	Quadruple *new_quadruple = new Quadruple;
	new_quadruple->operador = GOTO;
	new_quadruple->operando1 = -1;
	new_quadruple->operando2 = -1;
	new_quadruple->resultado = -1;
		
	//cout << "#" << quadruple_index << " ";
	//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
	g_queue_push_tail(pilaPasos, new_quadruple);
	g_queue_push_tail(pilaSaltos, GINT_TO_POINTER(quadruple_index-1));
		
	quadruple_index++;
}

void generateQuadruple_min(){
	int op, operando1, operando2, temp;
	char *aux, *temp_aux;
	int resultadoCubo, operador, op1, op2, dirVir;
	
	op2 = GPOINTER_TO_INT(g_queue_peek_nth(pilaTipos,(g_queue_get_length(pilaTipos)-2)));
	op1 = GPOINTER_TO_INT(g_queue_peek_tail(pilaTipos));
	resultadoCubo = cubo[operador][op1][op2] - 1;
	
		
	if(op1 == op2){
		g_queue_pop_tail(pilaTipos);
		g_queue_pop_tail(pilaTipos);
		
		Quadruple *new_quadruple = new Quadruple;
		operando2 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
		operando1 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
			
		if(resultadoCubo == 0){
			dirVir = TEMP_INT + temp_int_cont;
			temp_int_cont++;
			temp_int_cont_func++;
		}else if(resultadoCubo == 1){
			dirVir = TEMP_FLOAT + temp_float_cont;
			temp_float_cont++;
			temp_float_cont_func++;
		}
		
		g_queue_push_tail(pilaOperandos, (gpointer) dirVir);
		
		new_quadruple->operador = MIN;
		new_quadruple->operando2 = operando2;
		new_quadruple->operando1 = operando1;
		new_quadruple->resultado = dirVir;
		
		//cout << "#" << quadruple_index << " ";
		//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		g_queue_push_tail(pilaPasos, new_quadruple);
		quadruple_index++;
		
		g_queue_push_tail(pilaTipos, (gpointer) resultadoCubo);
		
	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
}

void generateQuadruple_print(){
	int print = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperadores));
	int resultado = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
	g_queue_pop_tail(pilaTipos);

	Quadruple *new_quadruple = new Quadruple;
	new_quadruple->operador = print;
	new_quadruple->operando1 = -1;
	new_quadruple->operando2 = -1;
	new_quadruple->resultado = resultado;
	
	//cout << "#" << quadruple_index << " ";
	//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
	g_queue_push_tail(pilaPasos, new_quadruple);
	quadruple_index++;
}

void generateQuadruple_pow(){
	int op, operando1, operando2, temp;
	char *aux, *temp_aux;
	int resultadoCubo, operador, op1, op2, dirVir;
	
	op2 = GPOINTER_TO_INT(g_queue_peek_nth(pilaTipos,(g_queue_get_length(pilaTipos)-2)));
	op1 = GPOINTER_TO_INT(g_queue_peek_tail(pilaTipos));
	
		
	if(op1 == 1 && op2 == 1){
		g_queue_pop_tail(pilaTipos);
		g_queue_pop_tail(pilaTipos);
		
		Quadruple *new_quadruple = new Quadruple;
		operando2 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
		operando1 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
			
		
		dirVir = TEMP_FLOAT + temp_float_cont;
		temp_float_cont++;
		temp_float_cont_func++;

		
		g_queue_push_tail(pilaOperandos, (gpointer) dirVir);
		
		new_quadruple->operador = POW;
		new_quadruple->operando2 = operando2;
		new_quadruple->operando1 = operando1;
		new_quadruple->resultado = dirVir;
		
		//cout << "#" << quadruple_index << " ";
		//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		g_queue_push_tail(pilaPasos, new_quadruple);
		quadruple_index++;
		
		g_queue_push_tail(pilaTipos, (gpointer) resultadoCubo);
		
	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
}

void generateQuadruple_random(){
	int dirVir;
	
	Quadruple *new_quadruple = new Quadruple;
	dirVir = TEMP_INT + temp_int_cont;
	temp_int_cont++;
	temp_int_cont_func++;
	
	g_queue_push_tail(pilaOperandos, (gpointer) dirVir);
		
	new_quadruple->operador = RANDOM;
	new_quadruple->operando2 = -1;
	new_quadruple->operando1 = -1;
	new_quadruple->resultado = dirVir;
		
	//cout << "#" << quadruple_index << " ";
	//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
	g_queue_push_tail(pilaPasos, new_quadruple);
	quadruple_index++;
		
	g_queue_push_tail(pilaTipos, (gpointer) 0);
}

void generateQuadruple_read(){
	int dirVir, read;
	
	int tipo = GPOINTER_TO_INT(g_queue_peek_tail(pilaTipos));
	read = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperadores));

	if(tipo == 0){
			dirVir = TEMP_INT + temp_int_cont;
			temp_int_cont++;
		}else if(tipo == 1){
			dirVir = TEMP_FLOAT + temp_float_cont;
			temp_float_cont++;
		}else if(tipo == 2){
			dirVir = TEMP_STRING + temp_string_cont;
			temp_string_cont++;
		}else if(tipo == 3){
			dirVir = TEMP_BOOLEAN + temp_boolean_cont;
			temp_boolean_cont++;
		}else if(tipo == 4){
			dirVir = TEMP_CHAR + temp_char_cont;
			temp_char_cont++;
		}
	
	Quadruple *new_quadruple = new Quadruple;
	new_quadruple->operador = read;
	new_quadruple->operando1 = -1;
	new_quadruple->operando2 = -1;
	new_quadruple->resultado = dirVir;
	
	cout << "#" << quadruple_index << " ";
	cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
	g_queue_push_tail(pilaPasos, new_quadruple);
	g_queue_push_tail(pilaOperandos, GINT_TO_POINTER(dirVir));
	g_queue_push_tail(pilaTipos, GINT_TO_POINTER(tipo));
	quadruple_index++;
}

void generateQuadruple_remainder(){
	int op, operando1, operando2, temp;
	char *aux, *temp_aux;
	int resultadoCubo, operador, op1, op2, dirVir;
	
	op2 = GPOINTER_TO_INT(g_queue_peek_nth(pilaTipos,(g_queue_get_length(pilaTipos)-2)));
	op1 = GPOINTER_TO_INT(g_queue_peek_tail(pilaTipos));
	resultadoCubo = cubo[operador][op1][op2] - 1;
	
		
	if(op1 == 0 && op2 == 0){
		g_queue_pop_tail(pilaTipos);
		g_queue_pop_tail(pilaTipos);
		
		Quadruple *new_quadruple = new Quadruple;
		operando2 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
		operando1 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
			
		if(resultadoCubo == 0 || resultadoCubo == 1){
			dirVir = TEMP_INT + temp_int_cont;
			temp_int_cont++;
			temp_int_cont_func++;
		}
		
		g_queue_push_tail(pilaOperandos, (gpointer) dirVir);
		
		new_quadruple->operador = REMAINDER;
		new_quadruple->operando2 = operando2;
		new_quadruple->operando1 = operando1;
		new_quadruple->resultado = dirVir;
		
		//cout << "#" << quadruple_index << " ";
		//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		g_queue_push_tail(pilaPasos, new_quadruple);
		quadruple_index++;
		
		g_queue_push_tail(pilaTipos, (gpointer) resultadoCubo);
		
	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
}

void generateQuadruple_sqrt(){
	int op, operando1, temp;
	char *aux, *temp_aux;
	int resultadoCubo, operador, op1, dirVir;
	
	op1 = GPOINTER_TO_INT(g_queue_peek_tail(pilaTipos));
		
	if(op1 == 1){
		g_queue_pop_tail(pilaTipos);
		
		Quadruple *new_quadruple = new Quadruple;
		operando1 = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
			
		dirVir = TEMP_FLOAT + temp_float_cont;
		temp_float_cont++;
		temp_float_cont_func++;
		
		g_queue_push_tail(pilaOperandos, (gpointer) dirVir);
		
		new_quadruple->operador = SQRT;
		new_quadruple->operando2 = -1;
		new_quadruple->operando1 = operando1;
		new_quadruple->resultado = dirVir;
		
		//cout << "#" << quadruple_index << " ";
		//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		g_queue_push_tail(pilaPasos, new_quadruple);
		quadruple_index++;
		
		g_queue_push_tail(pilaTipos, (gpointer) resultadoCubo);
		
	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
}

void generateQuadruple_while(){
	//cout << "#" << quadruple_index << " ";
	int aux, resultado;
	
	aux = GPOINTER_TO_INT(g_queue_pop_tail(pilaTipos));
	
	if(aux == 3){
		resultado = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
		
		Quadruple *new_quadruple = new Quadruple;
		new_quadruple->operador = GOTOF;
		new_quadruple->operando1 = resultado;
		new_quadruple->operando2 = -1;
		new_quadruple->resultado = -1;
		
		//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		g_queue_push_tail(pilaPasos, new_quadruple);
		g_queue_push_tail(pilaSaltos, GINT_TO_POINTER(quadruple_index-1));
		quadruple_index++;
	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
}

/*******************************************
 * Función que calcula la llave para la 	*
 * tabla de hash, tomando en cuenta la 		*
 * primera letra de la variable o 			*
 * procedimiento, convirtiendolo en un 		*
 * entero 									*
 *******************************************/
int get_hash_key(string key){
	char firstLetter;
	//cout << "La llave a cambiar es: " << key << "\n";
	firstLetter = key[0];
	//cout << "La primera letra del string es: " << firstLetter << "\n";
	//cout << "Cambiado a ASCII: " << int(firstLetter)-97 << "\n";
	
	return int(firstLetter)-97;
}

int get_operator_type(const char* op){
	//cout << "Push to pila operadores: " << op << "\n";
	
	if(strcmp(op,"+") == 0){
		return 0;
	}else if(strcmp(op,"-") == 0){
		return 1;
	}else if(strcmp(op,"/") == 0){
		return 2;
	}else if(strcmp(op,"*") == 0){
		return 3;
	}else if(strcmp(op,"<") == 0){
		return 4;
	}else if(strcmp(op,">") == 0){
		return 5;
	}else if(strcmp(op,"=") == 0){
		return 6;
	}else if(strcmp(op,"<>") == 0){
		return 7;
	}else if(strcmp(op,"==") == 0){
		return 8;
	}else if(strcmp(op,"&&") == 0){
		return 9;
	}else if(strcmp(op,"||") == 0){
		return 10;
	}else if(strcmp(op,"#") == 0){
		return -1;
	}else if(strcmp(op,"print") == 0){
		return PRINT;
	}else if(strcmp(op,"read") == 0){
		return READ;
	}
}

Procedure *get_proc(char *var_cte){
	int ascii, stack_position;
	const char *string_aux;					//String auxiliar
	GQueue* stack_aux = g_queue_new();		//Pila auxiliar
	GList* variable_in_stack;				//Lista utilizada para encontrar alguna variable
	Procedure *node_aux = new Procedure;	//Nodo auxiliar
	int dirVirtual;
	
	ascii = get_hash_key(var_cte);
	stack_position = procedure_index[ascii]-1;
	
	if(stack_position >= 0){
	
		stack_aux = (GQueue *)g_queue_peek_nth(tableProc_stack, stack_position);
	
		if(g_queue_get_length(stack_aux) == 1){
			node_aux = (Procedure *)g_queue_peek_head(stack_aux);
		
			//dirVirtual = node_aux->dirVirtual;
			return node_aux;
		}else{
			for(int i=0; i<g_queue_get_length(stack_aux); i++){
				node_aux = (Procedure *)g_queue_peek_nth(stack_aux,i);
				string_aux = node_aux->name.c_str();
			
				if(strcmp(string_aux,var_cte) == 0){
					//dirVirtual = node_aux->dirVirtual;
					return node_aux;
				}
			}
		}
	}else{
		cout << "Error: Procedimiento no declarado. \n";
		exit (EXIT_FAILURE);
	}
}

Variable *get_var(char *var_cte){
	int ascii, stack_position;
	const char *string_aux;					//String auxiliar
	GQueue* stack_aux = g_queue_new();		//Pila auxiliar
	GList* variable_in_stack;				//Lista utilizada para encontrar alguna variable
	Variable *node_aux = new Variable;		//Nodo auxiliar
	int dirVirtual;
	
	ascii = get_hash_key(var_cte);
	stack_position = variable_index[ascii]-1;
	if(stack_position >= 0){
	
		stack_aux = (GQueue *)g_queue_peek_nth(tableVar_stack, stack_position);
	
		if(g_queue_get_length(stack_aux) == 1){
			node_aux = (Variable *)g_queue_peek_head(stack_aux);
		
			//dirVirtual = node_aux->dirVirtual;
			return node_aux;
		}else{
			for(int i=g_queue_get_length(stack_aux)-1; i>0; i--){
				node_aux = (Variable *)g_queue_peek_nth(stack_aux,i);
				string_aux = node_aux->name.c_str();
			
				if(strcmp(string_aux,var_cte) == 0){
					//dirVirtual = node_aux->dirVirtual;
					return node_aux;
				}
			}
		}
	}else{
		cout << "1Error: Variable no declarada. \n";
		exit (EXIT_FAILURE);
	}
}

int get_var_type(const char *var_cte){
	//cout << "Push to pila tipos: " << var_cte << "\n";
	
	if(strcmp(var_cte,"int") == 0){
		return 0;
	}else if(strcmp(var_cte,"float") == 0){
		return 1;
	}else if(strcmp(var_cte,"string") == 0){
		return 2;
	}else if(strcmp(var_cte,"boolean") == 0){
		return 3;
	}else if(strcmp(var_cte,"char") == 0){
		return 4;
	}else if(strcmp(var_cte,"const_int") == 0){
		return 10;
	}else if(strcmp(var_cte,"const_float") == 0){
		return 11;
	}else if(strcmp(var_cte,"const_string") == 0){
		return 12;
	}else if(strcmp(var_cte,"const_boolean") == 0){
		return 13;
	}else if(strcmp(var_cte,"const_char") == 0){
		return 14;
	}else if(strcmp(var_cte,"pointer") == 0){
		return 0;
	}
}

void initialize(){
	initialize_arrs();
	initialize_stacks();
	
	//cout << "PROCESO DE INICIALIZACION: CHECK \n";
}

//Método que inicializa ambos arreglos (Tablas de Hash) con -1
void initialize_arrs(){
	int i;
	
	for(i=0; i<table_size; i++){
		procedure_index[i] = -1;
		variable_index[i] = -1;
	}
}

//Método que inicializa pilas
void initialize_stacks(){
	pilaPasos = g_queue_new();
	pilaTipos = g_queue_new();
	pilaSaltos = g_queue_new();
	pilaOperadores = g_queue_new();
	pilaOperandos = g_queue_new();
	pilaAuxFor = g_queue_new();
	//pilaParametros = g_queue_new();
	
	tableProc_stack = g_queue_new();
	tableVar_stack = g_queue_new();
	
	constants = g_hash_table_new(g_str_hash, g_str_equal);
}

void insert_arr_to_vars_table(string id, string type, string size, char* func_name){
	int hash_key, value_inside_array, dirVirtual;
	bool stack_exists;
	const char *string_aux;
	char *var_type, *size_aux;
	GList* variable_in_stack;
	
	int limsup, m0;
	
	size_aux = &size[0];
	limsup = atoi(size_aux);
	m0 = limsup-1;
	
	GQueue *stack_aux = g_queue_new();
	Variable *node = new Variable;
	
	var_type = &type[0];
	dirVirtual = asign_dirVirtual(var_type);
	alter_dirVirtual(var_type,m0);
	
	node->name = id;					//Se asigna el id al nodo
	node->type = type;					//Se asigna el tipo de dato al nodo
	node->dirVirtual = dirVirtual;		//Se asigna la direccion virtual al nodo
	node->limite = limsup;				//Se asigna la dimension
	node->procName = func_name;			//Se asigna el nombre de la funcion a la que pertenece
	
	hash_key = get_hash_key(id);
	stack_exists = check_if_stack_exists(hash_key, 1);
	
	if(!stack_exists){														//Si no existe
		stack_aux = g_queue_new();											//Creo una nueva lista
		g_queue_push_tail(stack_aux,node);									//Meto el nodo
		g_queue_push_tail(tableVar_stack,stack_aux);						//Meto esa lista a la lista principal
		variable_index[hash_key] = g_queue_get_length(tableVar_stack);		//Guardo la posicion donde fue puesta la lista en la lista principal en el arreglo
		
		//cout << "El arreglo en la posicion " << hash_key << " tiene el valor: " << g_queue_get_length(tableVar_stack) << "\n";
	}else{																					//Si ya existía una lista
		value_inside_array = variable_index[hash_key] - 1;									//Checo el valor que le corresponde dentro del arreglo
		//cout << "Valor en la posicion del arreglo " << value_inside_array << "\n";
		stack_aux = (GQueue *)g_queue_peek_nth(tableVar_stack, value_inside_array);			//Obtengo la lista con las variables dentro de la lista principal
		
		string_aux = id.c_str();															//Convierto el nombre del id en char *
		variable_in_stack = g_queue_find_custom(stack_aux, string_aux, search_for_id);		//Checo si existe el nombre del id dentro de la lista
		
		if(!variable_in_stack){														//Si no existe el nombre de la variable en la lista
			g_queue_push_tail(stack_aux, node);										//Agrego el nuevo id (nodo) a la lista
			g_queue_push_nth(tableVar_stack, stack_aux, value_inside_array);		//Meto la lista actualizada en la posicion original de la lista
			g_queue_pop_nth(tableVar_stack, value_inside_array+1);					//Elimino la lista "desactualizada" que se encuentra una posicion adelante de la recien agregada
		}else{																	//Si ya existia la variable, truena el programa
			const char* aux1, *aux2;
			Variable *nova = new Variable;
			
			nova = get_var(&id[0]);
			aux1 = nova->procName;
			aux2 = func_name;
			
			//cout << aux1 << "\n";
			//cout << aux2 << "\n";
			
			if(strcmp(aux1,aux2) == 0){
				cout << "Error: La variable ya ha sido declarada anteriormente. \n";
				exit (EXIT_FAILURE);
			}else{
				g_queue_push_tail(stack_aux, node);											//Agrego el nuevo id (nodo) a la lista
				g_queue_push_nth(tableVar_stack, stack_aux, value_inside_array);			//Meto la lista actualizada en la posicion original de la lista
				g_queue_pop_nth(tableVar_stack, value_inside_array+1);						//Elimino la lista "desactualizada" que se encuentra una posicion adelante de la recien agregada
			}
		}
	}
}

void insert_param_type(char *func_name, char *var_type){
	const char* aux = var_type;
	int type = get_var_type(aux);
	Procedure *proc = new Procedure;
	
	proc = get_proc(func_name);
	
	//g_queue_push_tail(pilaParametros, GINT_TO_POINTER(type));
	//proc->pilaParams = pilaParametros;
	g_queue_push_tail(proc->pilaParams, GINT_TO_POINTER(type));
	
	/*cout << "######Insert param type: " << func_name << ", " << var_type << "\n";
	cout << "Proc Name: " << proc->name << "\n";
	cout << "Pila Parametros: ";
	g_queue_foreach(proc->pilaParams, (GFunc)print_pilas, NULL);
	cout << "\n";*/
}

/*******************************************
 * Función para agregar un nuevo id con su *
 * tipo de dato y direccion virtual a la   *
 * tabla de procedimientos 				   *
 *******************************************/
void insert_to_procs_table(string id){
	int hash_key;						//Valor que le corresponde dependiendo la primera letra del id
	int value_inside_array;				//Valor que se encuentre dentro de la casilla del arreglo, que corresponde a la posicion dentro de la lista principal			
	bool stack_exists;					//Checa si hay alguna lista dentro de alguna casilla de la lista principal
	const char * string_aux;			//String auxiliar
	GList* procedure_in_stack;			//Lista utilizada para encontrar alguna variable repetida
		
	GQueue* stack_aux = g_queue_new();		//Pila auxiliar
	Procedure *node = new Procedure;		//Nodo
	
	node->name = id;					//Se asigna el id al nodo
	//node->dirInitial = dirInitial;		//Se asigna el tipo de dato al nodo
	//node->size = size;					//Se asigna la direccion virtual al nodo
	//cout << "Nodo creado \n";
	node->pilaParams = g_queue_new();
	
	hash_key = get_hash_key(id);							//Busca la hash key que le corresponde al identificador
	stack_exists = check_if_stack_exists(hash_key, 0);		//Checa si en esa posicion existe alguna lista almacenando alguna otra variable
	
	if(!stack_exists){															//Si no existe
		stack_aux = g_queue_new();												//Creo una nueva lista
		g_queue_push_tail(stack_aux,node);										//Meto el nodo
		g_queue_push_tail(tableProc_stack,stack_aux);							//Meto esa lista a la lista principal
		procedure_index[hash_key] = g_queue_get_length(tableProc_stack);		//Guardo la posicion donde fue puesta la lista en la lista principal en el arreglo
		
		//cout << "El arreglo en la posicion " << hash_key << " tiene el valor: " << g_queue_get_length(tableProc_stack) << "\n";
	}else{																					//Si ya existía una lista
		value_inside_array = procedure_index[hash_key] - 1;									//Checo el valor que le corresponde dentro del arreglo
		//cout << "Valor en la posicion del arreglo " << value_inside_array << "\n";
		stack_aux = (GQueue *)g_queue_peek_nth(tableProc_stack, value_inside_array);		//Obtengo la lista con las variables dentro de la lista principal
		
		string_aux = id.c_str();															//Convierto el nombre del id en char *
		procedure_in_stack = g_queue_find_custom(stack_aux, string_aux, search_for_id);		//Checo si existe el nombre del id dentro de la lista
		
		if(!procedure_in_stack){														//Si no existe el nombre de la variable en la lista
			g_queue_push_tail(stack_aux, node);										//Agrego el nuevo id (nodo) a la lista
			g_queue_push_nth(tableProc_stack, stack_aux, value_inside_array);		//Meto la lista actualizada en la posicion original de la lista
			g_queue_pop_nth(tableProc_stack, value_inside_array+1);					//Elimino la lista "desactualizada" que se encuentra una posicion adelante de la recien agregada
			//cout << "La pila tiene :" << g_queue_get_length(tableProc_stack) << "\n";
		}else{																	//Si ya existia la variable, truena el programa
			cout << "LA VARIABLE YA HA SIDO DECLARADA ANTERIORMENTE \n";
			exit (EXIT_FAILURE);
		}
	}
	//cout << "La funcion " << id << " ha sido agregada exitosamente\n";
}

/*******************************************
 * Función para agregar un nuevo id con su *
 * tipo de dato y direccion virtual a la   *
 * tabla de variables	   				   *
 *******************************************/
void insert_to_vars_table(string id, string type, char* func_name){
	int hash_key;						//Valor que le corresponde dependiendo la primera letra del id
	int value_inside_array;				//Valor que se encuentre dentro de la casilla del arreglo, que corresponde a la posicion dentro de la lista principal			
	bool stack_exists;					//Checa si hay alguna lista dentro de alguna casilla de la lista principal
	const char * string_aux;			//String auxiliar
	GList* variable_in_stack;			//Lista utilizada para encontrar alguna variable repetida
	int dirVirtual;						//Direccion virtual asignada
	char *var_type;
		
	GQueue* stack_aux = g_queue_new();	//Pila auxiliar
	Variable *node = new Variable;		//Nodo
	Variable *node_aux = new Variable;	//Nodo auxiliar
	
	var_type = &type[0];
	dirVirtual = asign_dirVirtual(var_type);
	
	node->name = id;					//Se asigna el id al nodo
	node->type = type;					//Se asigna el tipo de dato al nodo
	node->dirVirtual = dirVirtual;		//Se asigna la direccion virtual al nodo
	node->procName = func_name;			//Se asigna el nombre de la funcion a la que pertenece
	
	//cout << "Dir virtual: " << dirVirtual << "\n";
	
	hash_key = get_hash_key(id);							//Busca la hash key que le corresponde al identificador
	stack_exists = check_if_stack_exists(hash_key, 1);		//Checa si en esa posicion existe alguna lista almacenando alguna otra variable
	
	if(!stack_exists){														//Si no existe
		stack_aux = g_queue_new();											//Creo una nueva lista
		g_queue_push_tail(stack_aux,node);									//Meto el nodo
		g_queue_push_tail(tableVar_stack,stack_aux);						//Meto esa lista a la lista principal
		variable_index[hash_key] = g_queue_get_length(tableVar_stack);		//Guardo la posicion donde fue puesta la lista en la lista principal en el arreglo
		
		//cout << "El arreglo en la posicion " << hash_key << " tiene el valor: " << g_queue_get_length(tableVar_stack) << "\n";
	}else{																					//Si ya existía una lista
		value_inside_array = variable_index[hash_key] - 1;									//Checo el valor que le corresponde dentro del arreglo
		//cout << "Valor en la posicion del arreglo " << value_inside_array << "\n";
		stack_aux = (GQueue *)g_queue_peek_nth(tableVar_stack, value_inside_array);			//Obtengo la lista con las variables dentro de la lista principal
		
		string_aux = id.c_str();															//Convierto el nombre del id en char *
		variable_in_stack = g_queue_find_custom(stack_aux, string_aux, search_for_id);		//Checo si existe el nombre del id dentro de la lista
		
		if(!variable_in_stack){															//Si no existe el nombre de la variable en la lista
			g_queue_push_tail(stack_aux, node);											//Agrego el nuevo id (nodo) a la lista
			g_queue_push_nth(tableVar_stack, stack_aux, value_inside_array);			//Meto la lista actualizada en la posicion original de la lista
			g_queue_pop_nth(tableVar_stack, value_inside_array+1);						//Elimino la lista "desactualizada" que se encuentra una posicion adelante de la recien agregada
			//cout << "La pila tiene :" << g_queue_get_length(tableVar_stack) << "\n";
			//node_aux = (Variable *)g_queue_peek_head(stack_aux);
			//cout << node_aux->name << "\n";
		}else{																			//Si ya existia la variable, truena el programa
			const char* aux1, *aux2;
			Variable *nova = new Variable;
			
			nova = get_var(&id[0]);
			aux1 = nova->procName;
			aux2 = func_name;
			
			//cout << aux1 << "\n";
			//cout << aux2 << "\n";
			
			if(strcmp(aux1,aux2) == 0){
				cout << "Error: La variable ya ha sido declarada anteriormente. \n";
				exit (EXIT_FAILURE);
			}else{
				g_queue_push_tail(stack_aux, node);											//Agrego el nuevo id (nodo) a la lista
				g_queue_push_nth(tableVar_stack, stack_aux, value_inside_array);			//Meto la lista actualizada en la posicion original de la lista
				g_queue_pop_nth(tableVar_stack, value_inside_array+1);						//Elimino la lista "desactualizada" que se encuentra una posicion adelante de la recien agregada
			}
		}
	}
	//cout << "La variable " << id << " ha sido agregada exitosamente\n";
}

void main_function_name(char *function_name){
	Procedure *proc = new Procedure;

	main_function = function_name;	
	proc = get_proc(function_name);
	proc->numParams = 0;
	
}

void pop_of_pilaOperadores(){
	//cout << "POP PILA OPERADORES \n";
	g_queue_pop_tail(pilaOperadores);
}

void print_hashTable(gpointer key, gpointer value, gpointer user_data){
	objeto << (char *)key << ", " << GPOINTER_TO_INT(value) << "\n";
}

void print_pilas(gpointer data, gpointer user_data){
	Procedure *proc = new Procedure;
	VarCont *locales = new VarCont;
	VarCont *temporales = new VarCont;
	
	proc = (Procedure *)data;
	
	//cout << proc->name << ", " << proc->dirInitial << ", " << proc->numParams << ", " <<
		//	  proc->locals.integers << ", " << proc->locals.flotantes  << ", " << proc->locals.estrings << ", " << proc->locals.booleans << ", " << proc->locals.chars << ", " <<
			//  proc->temps.integers << ", " << proc->temps.flotantes  << ", " << proc->temps.estrings << ", " << proc->temps.booleans << ", " << proc->temps.chars << "\n";
	

	objeto << proc->name << ", " << proc->dirInitial << ", " << proc->numParams << ", " <<
			  proc->locals.integers << ", " << proc->locals.flotantes  << ", " << proc->locals.estrings << ", " << proc->locals.booleans << ", " << proc->locals.chars << ", " <<
			  proc->temps.integers << ", " << proc->temps.flotantes  << ", " << proc->temps.estrings << ", " << proc->temps.booleans << ", " << proc->temps.chars << "\n";
	
	//cout << GPOINTER_TO_INT(data) << " ";
}

void print_quadruples(gpointer data, gpointer user_data){
	Quadruple *quad = new Quadruple;
	
	quad = (Quadruple *)data;
	
	objeto << quad->operador << ", " << quad->operando1 << ", " << quad->operando2 << ", " << quad->resultado << "\n";
}

void push_quadruple_index_to_pilaSaltos(){
	g_queue_push_tail(pilaSaltos, GINT_TO_POINTER(quadruple_index));
}

void push_to_pilaOperadores(char *op){
	int result;
	const char *aux;
	
	aux = op;
	
	result = get_operator_type(aux);
	g_queue_push_tail(pilaOperadores, GINT_TO_POINTER(result));
	
	//cout << "Pila Operadores: ";
	//g_queue_foreach(pilaOperadores, (GFunc)print_pilas, NULL);
	//cout << "\n";
}

void push_to_pilaOperandos(char *var_cte, char *id_type){
	int dirVirtual;
	int type = atoi(id_type);
	
	if(type == 5){
		dirVirtual = search_for_dirVirtual(var_cte);										//Search for dirVirtual de var_cte
		g_queue_push_tail(pilaOperandos,GINT_TO_POINTER(dirVirtual));
	}else{
		if(type == 0){
			id_type = "const_int";
		}else if(type == 1){
			id_type = "const_float";
		}else if(type == 2){
			id_type = "const_string";
		}else if(type == 3){
			id_type = "const_boolean";
		}else if(type == 4){
			id_type = "const_char";
		}
		
		if(g_hash_table_lookup(constants,var_cte) == NULL){
			dirVirtual = asign_dirVirtual(id_type);
			g_hash_table_insert(constants,var_cte,GINT_TO_POINTER(dirVirtual));
			g_queue_push_tail(pilaOperandos,GINT_TO_POINTER(dirVirtual));
		}else{
			dirVirtual = GPOINTER_TO_INT(g_hash_table_lookup(constants,var_cte));
			g_queue_push_tail(pilaOperandos,GINT_TO_POINTER(dirVirtual));
		}
	}
	
	//cout << "Push to pila operandos: " << var_cte << " o " << dirVirtual << "\n";
	//cout << "Pila Operandos: ";
	//g_queue_foreach(pilaOperandos, (GFunc)print_pilas, NULL);
	//cout << "\n";
	
}

void push_to_pilaTipos(char *var_cte){
	char *var_type;
	const char* aux;
	int type;
	
	var_type = search_for_variable_type(var_cte);
	aux = var_type;
	type = get_var_type(aux);
	
	g_queue_push_tail(pilaTipos, GINT_TO_POINTER(type));
	
	//cout << "Pila Tipos: ";
	//g_queue_foreach(pilaTipos, (GFunc)printprint, NULL);
	//cout << "\n";
}

void push_to_pilaTipos_directly(char *type){
	int aux = atoi(type) - 10;
	g_queue_push_tail(pilaTipos, GINT_TO_POINTER(aux));
}

void quadruple_add_sub(){
	int op = GPOINTER_TO_INT(g_queue_peek_tail(pilaOperadores));
	//int op;
	
	//op = atoi(operador);
	
	//cout << "ADD-SUB \n";
	//cout << "El operador es: " << operador << "\n";
	
	if((op == 0 || op == 1) && g_queue_get_length(pilaOperadores) > 0){
		generateQuadruple();
	}
}

void quadruple_mult_div(){
	int op = GPOINTER_TO_INT(g_queue_peek_tail(pilaOperadores));
	//int op;
	
	//op = atoi(operador);
	
	//cout << "MULT-DIV \n";
	//cout << "El operador es: " << operador << "\n";
	
	if((op == 2 || op == 3) && g_queue_get_length(pilaOperadores) > 0){
		generateQuadruple();
	}
}

void quadruple_relational(){
	int op = GPOINTER_TO_INT(g_queue_peek_tail(pilaOperadores));
	//int op;
	
	//op = atoi(operador);
	
	//cout << "RELACIONAL \n";
	//cout << "El operador es: " << operador << "\n";
	
	if(op == 4 || op == 5 || op == 7 || op == 8 || op == 9 || op == 10){
		generateQuadruple();
	}else if(op == 6){
		generateQuadruple_asignacion();
	}
}

void reset_conts(){
	local_int_cont = 0;
	local_float_cont = 0;
	local_string_cont = 0;
	local_boolean_cont = 0;
	local_char_cont = 0;
	temp_int_cont = 0;
	temp_float_cont = 0;
	temp_string_cont = 0;
	temp_boolean_cont = 0;
	temp_char_cont = 0;
}

void reset_func_count(){	
	local_int_cont_func = 0;
	local_float_cont_func = 0;
	local_string_cont_func = 0;
	local_boolean_cont_func = 0;
	local_char_cont_func = 0;
	temp_int_cont_func = 0;
	temp_float_cont_func = 0;
	temp_string_cont_func = 0;
	temp_boolean_cont_func = 0;
	temp_char_cont_func = 0;
	param_counter = 0;
}

void reset_param_counter(){
	param_counter = 0;
	//g_queue_clear(pilaParametros);
}

int search_for_arrLimit(char *var_cte){
	int ascii, stack_position;
	const char *string_aux;				//String auxiliar
	GQueue* stack_aux = g_queue_new();	//Pila auxiliar
	GList* variable_in_stack;			//Lista utilizada para encontrar alguna variable
	Variable *node_aux = new Variable;	//Nodo auxiliar
	int limit;
	
	ascii = get_hash_key(var_cte);
	stack_position = variable_index[ascii]-1;
	
	if(stack_position >= 0){
	
		stack_aux = (GQueue *)g_queue_peek_nth(tableVar_stack, stack_position);
	
		if(g_queue_get_length(stack_aux) == 1){
			node_aux = (Variable *)g_queue_peek_head(stack_aux);
		
			limit = node_aux->limite;
			return limit;
		}else{
			for(int i=0; i<g_queue_get_length(stack_aux); i++){
				node_aux = (Variable *)g_queue_peek_nth(stack_aux,i);
				string_aux = node_aux->name.c_str();
			
				if(strcmp(string_aux,var_cte) == 0){
					limit = node_aux->limite;
					return limit;
				}
			}
		}
	}else{
		cout << "Error: Variable no declarada. \n";
		exit (EXIT_FAILURE);
	}
}

/*******************************************
 * Función que recibe un nodo y el nombre  *
 * de identificador, y busca en cada nodo  *
 * si existe tal nombre guardado en algun  *
 * nodo. Si existe, regresa un 0.		   *
 *******************************************/
int search_for_id(gconstpointer a, gconstpointer b){
	Variable *node = (Variable *) a;					//Convierte el parametro en "Variable"
	const char *id = (char *) b;						//Convierte el parametro en char *
	const char *id_node = node->name.c_str();			//Convierte el valor de nombre dentro del nodo en char *
	
	
	//cout << "Primer string : " << id << "\n";
	//cout << "Segundo string: " << id_node << "\n";
	
	if(strcmp(id,id_node) == 0){						//Si los strings son equivalente...
		//cout << "Variables del mismo nombre \n";
		return 0;
	}else{
		return -1;
	}
}

int search_for_dirVirtual(char *var_cte){
	int ascii, stack_position;
	const char *string_aux;				//String auxiliar
	GQueue* stack_aux = g_queue_new();	//Pila auxiliar
	GList* variable_in_stack;			//Lista utilizada para encontrar alguna variable
	Variable *node_aux = new Variable;	//Nodo auxiliar
	int dirVirtual;
		
	ascii = get_hash_key(var_cte);
	stack_position = variable_index[ascii]-1;

	if(stack_position >= 0){
	
		stack_aux = (GQueue *)g_queue_peek_nth(tableVar_stack, stack_position);
		
		if(g_queue_get_length(stack_aux) == 0){
			cout << "Error: Variable no declarada. \n";
			exit (EXIT_FAILURE);
		}
			
		
		if(g_queue_get_length(stack_aux) == 1){
			node_aux = (Variable *)g_queue_peek_head(stack_aux);
			string_aux = node_aux->name.c_str();

			if(strcmp(string_aux,var_cte) == 0){
				dirVirtual = node_aux->dirVirtual;
				return dirVirtual;
			}else{
				cout << "Error: Variable no declarada. \n";
				exit (EXIT_FAILURE);
			}
		}else{
			for(int i=g_queue_get_length(stack_aux)-1; i>=0; i--){
				node_aux = (Variable *)g_queue_peek_nth(stack_aux,i);
				string_aux = node_aux->name.c_str();
				if(strcmp(string_aux,var_cte) == 0){
					dirVirtual = node_aux->dirVirtual;
					return dirVirtual;
				}
			}
		}
	}else{
		cout << "Error: Variable no declarada. \n";
		exit (EXIT_FAILURE);
	}
}

char *search_for_variable_type(char *var_cte){
	int ascii, stack_position;
	const char *string_aux;				//String auxiliar
	GQueue* stack_aux = g_queue_new();	//Pila auxiliar
	GList* variable_in_stack;			//Lista utilizada para encontrar alguna variable
	Variable *node_aux = new Variable;	//Nodo auxiliar
	char *var_type;
	
	ascii = get_hash_key(var_cte);
	stack_position = variable_index[ascii]-1;
	
	stack_aux = (GQueue *)g_queue_peek_nth(tableVar_stack, stack_position);
	
	if(stack_position < 0){
		cout << "Error: Variable no declarada. \n";
		exit (EXIT_FAILURE);
	}
	if(g_queue_get_length(stack_aux) == 1){
		node_aux = (Variable *)g_queue_peek_head(stack_aux);
		
		var_type = &node_aux->type[0];
		return var_type;
	}else{
		for(int i=0; i<g_queue_get_length(stack_aux); i++){
			node_aux = (Variable *)g_queue_peek_nth(stack_aux,i);
			string_aux = node_aux->name.c_str();
			
			if(strcmp(string_aux,var_cte) == 0){
				var_type = &node_aux->type[0];
				return var_type;
			}
		}
	}
}

void search_in_pilas(gpointer data, gpointer user_data){
	Procedure *proc = new Procedure;
	const char *aux = (char *)user_data;
	proc = (Procedure *)data;
	
	//cout << "FUNC NAME" << (char *)user_data << "\n"; 
	//cout << proc->name << "\n";
	
	if(strcmp(aux,proc->name.c_str()) == 0)
		numeroFuncionLlamada = numeroFuncionLlamada_index;
	
	numeroFuncionLlamada_index++;
}

void set_current_function(char *function, char* func_name){
	//cout << "CURRENT FUNCTION: " << function << "\n";
	
	current_function = atoi(function);
	current_function_name = func_name;
}

void set_fin_main(){
	VarCont *locales = new VarCont;
	VarCont *temporales = new VarCont;

	Procedure *proc = new Procedure;
	int curr_func = 0;
	
	proc = get_proc(main_function);

	proc->numParams = g_queue_get_length(proc->pilaParams);
	
	
	locales->integers = global_int_cont;
	locales->flotantes = global_float_cont;
	locales->estrings = global_string_cont;
	locales->booleans = global_boolean_cont;
	locales->chars = global_char_cont;
	
	proc->locals = *locales;
		
	temporales->integers = temp_int_cont_func;
	temporales->flotantes = temp_float_cont_func;
	temporales->estrings = temp_string_cont_func;
	temporales->booleans = temp_boolean_cont_func;
	temporales->chars = temp_char_cont_func;
	
	proc->temps = *temporales;
		
	reset_func_count();
	delete_vars_from_varTable(main_function);
}

void set_fin_function(char *func, char *curr){
	VarCont *locales = new VarCont;
	VarCont *temporales = new VarCont;
	Quadruple *new_quadruple = new Quadruple;
	Procedure *proc = new Procedure;
	int curr_func = atoi(curr);
	
	proc = get_proc(func);
	//cout << "Metodo: " << func << "\n";
	//cout << "Num params: " << g_queue_get_length(proc->pilaParams) << "\n";
	proc->numParams = g_queue_get_length(proc->pilaParams);
	
	if(curr_func == 0){
		locales->integers = global_int_cont;
		locales->flotantes = global_float_cont;
		locales->estrings = global_string_cont;
		locales->booleans = global_boolean_cont;
		locales->chars = global_char_cont;
	}else if(curr_func == 1){
		locales->integers = local_int_cont_func;
		locales->flotantes = local_float_cont_func;
		locales->estrings = local_string_cont_func;
		locales->booleans = local_boolean_cont_func;
		locales->chars = local_char_cont_func;
	}
	
	/*
	cout << "Variables locales int: " << locales->integers << "\n";
	cout << "Variables locales float: " << locales->flotantes << "\n";
	cout << "Variables locales string: " << locales->estrings << "\n";
	cout << "Variables locales boolean: " << locales->booleans << "\n";
	cout << "Variables locales char: " << locales->chars << "\n";
	*/
	
	proc->locals = *locales;
		
	temporales->integers = temp_int_cont_func;
	temporales->flotantes = temp_float_cont_func;
	temporales->estrings = temp_string_cont_func;
	temporales->booleans = temp_boolean_cont_func;
	temporales->chars = temp_char_cont_func;
	
	/*
	cout << "Variables temporales int: " << temporales->integers << "\n";
	cout << "Variables temporales float: " << temporales->flotantes << "\n";
	cout << "Variables temporales string: " << temporales->estrings << "\n";
	cout << "Variables temporales boolean: " << temporales->booleans << "\n";
	cout << "Variables temporales char: " << temporales->chars << "\n";
	*/
	
	proc->temps = *temporales;
		
	new_quadruple->operador = RET;
	new_quadruple->operando2 = -1;
	new_quadruple->operando1 = -1;
	new_quadruple->resultado = -1;
	
	//cout << "#" << quadruple_index << " ";
	//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
	g_queue_push_tail(pilaPasos, new_quadruple);
	quadruple_index++;
	
	reset_func_count();
	delete_vars_from_varTable(func);
}

void set_start_function(char *func){
	Procedure *proc = new Procedure;
	Quadruple *new_quadruple = new Quadruple;
	
	new_quadruple->operador = INIPROC;													//Suma
	new_quadruple->operando2 = -1;
	new_quadruple->operando1 = -1;
	new_quadruple->resultado = -1;
	
	//cout << "Empieza la funcion: " << func << "\n";
	
	//cout << "#" << quadruple_index << " ";
	//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
	g_queue_push_tail(pilaPasos, new_quadruple);
	
	proc = get_proc(func);
	proc->dirInitial = quadruple_index-1;
	
	quadruple_index++;
}

void verify_arr_limit(char *var_cte){

	int resultado = GPOINTER_TO_INT(g_queue_peek_tail(pilaOperandos));
	int limit = search_for_arrLimit(var_cte);
	
	Quadruple *new_quadruple = new Quadruple;
	new_quadruple->operador = VER;
	new_quadruple->operando2 = -1;
	new_quadruple->operando1 = resultado;
	new_quadruple->resultado = limit;
	
	//cout << "#" << quadruple_index << " ";
	//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
	g_queue_push_tail(pilaPasos, new_quadruple);
	quadruple_index++;

	/*	
	cout << "Pila Operandos: ";
	g_queue_foreach(pilaOperandos, (GFunc)print_pilas, NULL);
	cout << "\n";
	cout << "Pila Tipos: ";
	g_queue_foreach(pilaTipos, (GFunc)print_pilas, NULL);
	cout << "\n";
	cout << "Pila Operadores: ";
	g_queue_foreach(pilaOperadores, (GFunc)print_pilas, NULL);
	cout << "\n\n";
	*/
}

void verify_function_name(char *func_name){
	int ascii, stack_position;
	const char *string_aux;
	GQueue* stack_aux = g_queue_new();
	Procedure *node_aux = new Procedure;
	
	ascii = get_hash_key(func_name);
	stack_position = procedure_index[ascii]-1;
	
	if(stack_position >= 0){
		stack_aux = (GQueue *)g_queue_peek_nth(tableProc_stack, stack_position);
		
		if(g_queue_get_length(stack_aux) == 1){
			node_aux = (Procedure *)g_queue_peek_nth(stack_aux,0);
			string_aux = node_aux->name.c_str();
			
			if(strcmp(string_aux,func_name) != 0){
				cout << "Error: Función no declarada. \n";
				exit (EXIT_FAILURE);
			}
		}else{
			for(int i=0; i<g_queue_get_length(stack_aux); i++){
				node_aux = (Procedure *)g_queue_peek_nth(stack_aux,i);
				string_aux = node_aux->name.c_str();
			
				if(strcmp(string_aux,func_name) != 0){
					cout << "Error: Función no declarada. \n";
					exit (EXIT_FAILURE);
				}
			}
		}
	}else{
		cout << "Error: Función no declarada. \n";
		exit (EXIT_FAILURE);
	}
}

void verify_parameters(char *func_name){
	int argumento, tipoArg, tipoOriginal;
	Procedure *proc = new Procedure;
	GQueue *pilaAux = g_queue_new();
	
	proc = get_proc(func_name);
	pilaAux = proc->pilaParams;
	
	argumento = GPOINTER_TO_INT(g_queue_pop_tail(pilaOperandos));
	tipoArg = GPOINTER_TO_INT(g_queue_pop_tail(pilaTipos));
	tipoOriginal = GPOINTER_TO_INT(g_queue_peek_nth(pilaAux, param_counter));
	
	/*cout << "*********Name: " << proc->name << "\n";
	cout << "Pila Parametros: ";
	g_queue_foreach(proc->pilaParams, (GFunc)print_pilas, NULL);
	cout << "\n";
	cout << "Param counter: " << param_counter << "\n";
	cout << "Tipo Argumento: " << tipoArg << "\n";
	cout << "Argumento Original: " << tipoOriginal << "\n";*/
	
	if(tipoArg != tipoOriginal){
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}else{
		Quadruple *new_quadruple = new Quadruple;
		new_quadruple->operador = PARAM;
		new_quadruple->operando2 = -1;
		new_quadruple->operando1 = argumento;
		new_quadruple->resultado = param_counter;
		
		//cout << "#" << quadruple_index << " ";
		//cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		g_queue_push_tail(pilaPasos, new_quadruple);
	
		quadruple_index++;
	}
	
}