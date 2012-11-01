#include <iostream>
#include <string>
#include <sstream> 
#include <stdlib.h>
#include <glib.h>
#include "semantic_methods.h"

using namespace std;

/******************************Declaración de variables**********************************/

//Inicio de bloques de memoria
enum virtual_memory { GLOBAL_INT=1000, GLOBAL_FLOAT=6000, GLOBAL_STRING=11000, GLOBAL_BOOLEAN=16000, GLOBAL_CHAR=21000,
					  LOCAL_INT=26000, LOCAL_FLOAT=31000, LOCAL_STRING=36000,  LOCAL_BOOLEAN=41000,  LOCAL_CHAR=46000,
					  TEMP_INT=51000,  TEMP_FLOAT=56000,  TEMP_STRING=61000,   TEMP_BOOLEAN=66000,   TEMP_CHAR=71000,
					  CONST_INT=76000, CONST_FLOAT=81000, CONST_STRING=86000,  CONST_BOOLEAN=91000,  CONST_CHAR=96000 };

//Contadores de direcciones virtuales
int global_int_cont = 0,	global_float_cont = 0,	global_string_cont = 0,	global_boolean_cont = 0,	global_char_cont = 0,
	local_int_cont = 0,		local_float_cont = 0, 	local_string_cont = 0, 	local_boolean_cont = 0,		local_char_cont = 0,
	temp_int_cont = 0, 		temp_float_cont = 0, 	temp_string_cont = 0, 	temp_boolean_cont = 0, 		temp_char_cont = 0,
	const_int_cont = 0, 	const_float_cont = 0, 	const_string_cont = 0, 	const_boolean_cont = 0, 	const_char_cont = 0;

//Bloque de variables utilizadas para la generación de tablas de procedimientos y variables
static int procedure_index[26];			//Tabla de Hash para los procedimientos
static int table_size = 26;				//Tamaño de las "tablas"
static int variable_index[26];			//Tabla de Hash para las variables

static GQueue* tableProc_stack;			//Lista donde están almacenados los nodos con la información de cada procedimiento
static GQueue* tableVar_stack;			//Lista donde están almacenados los nodos con la información de cada variable

//Bloque de variables utilizadas para la generación de código intermedio
static int current_function;
static char* main_function;

static GHashTable* main_table;		//Tabla de procedimientos principal

static GQueue* pilaOperadores;
static GQueue* pilaOperandos;
static GQueue* pilaPasos;
static GQueue* pilaSaltos;
static GQueue* pilaTipos;

static int cubo[9][5][5] =
{
		{//"+"
			{1, 2, 3, -1, -1},
			{2, 2, 3, -1, -1},
			{3, 3, 3, -1, -1},
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
			{-1, -1, 4, -1, -1},
			{-1, -1, -1, 4, -1},
			{-1, -1, -1, -1, 4}
		},
		{//"=="
			{4, 4, -1, -1, -1},
			{4, 4, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1}
		}
};

/*********************************Estructuras de datos***********************************/

//Nodo que contiene información importante de cada procedimiento
struct Procedure{
	string name;
	string dirInitial;
	string size;
};

//Nodo que contiene información referente a la generación de cuádruplos
struct Quadruple{
	char* operador;
	char* operando1;
	char* operando2;
	char* resultado;
};

//Nodo que contiene información importante de cada variable
struct Variable{
	string name;
	string type;
	string dirVirtual;
};

/****************************************Métodos*****************************************/

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

char *convert_to_char(int number){
	stringstream s;
	string aux = "";
	char *resultado;
	
	//int to string
	s.clear();
	s.str("");
	s << number;
	aux = s.str();
	//String to char*
	resultado = &aux[0];
	
	return resultado;
}

void generateQuadruple(){
	char *op;
	char *operando1;
	char *operando2;
	char *temp;
	char *aux;
	char *resultadoParcial_aux;
	int operador, op1, op2, resultadoParcial, resAux;

	
	aux = (char *)g_queue_peek_tail(pilaOperadores);
	operador = atoi(aux);		
	aux = (char *)g_queue_peek_nth(pilaTipos,(g_queue_get_length(pilaTipos)-2));
	op2 = atoi(aux);
	aux = (char *)g_queue_peek_tail(pilaTipos);
	op1 = atoi(aux);
	resultadoParcial = cubo[operador][op1][op2];
		
	if(resultadoParcial != -1){
		g_queue_pop_tail(pilaTipos);
		g_queue_pop_tail(pilaTipos);
		
		Quadruple *new_quadruple = new Quadruple;
		op = (char *)g_queue_pop_tail(pilaOperadores);
		operando2 = (char *)g_queue_pop_tail(pilaOperandos);
		operando1 = (char *)g_queue_pop_tail(pilaOperandos);
			
		if(resultadoParcial == 1){
			resAux = TEMP_INT + temp_int_cont;
			temp_int_cont++;
		}else if(resultadoParcial == 2){
			resAux = TEMP_FLOAT + temp_float_cont;
			temp_float_cont++;
		}else if(resultadoParcial == 3){
			resAux = TEMP_STRING + temp_string_cont;
			temp_string_cont++;
		}else if(resultadoParcial == 4){
			resAux = TEMP_BOOLEAN + temp_boolean_cont;
			temp_boolean_cont++;
		}else if(resultadoParcial == 5){
			resAux = TEMP_CHAR + temp_char_cont;
			temp_char_cont++;
		}
		
		temp = convert_to_char(resAux);
		g_queue_push_tail(pilaOperandos, temp);
		cout << "Push to pila operandos: temp o " << temp << "\n";
		cout << "Pila Operandos: ";
		g_queue_foreach(pilaOperandos, (GFunc)print_pilas, NULL);
		cout << "\n";
		
		new_quadruple->operador = op;
		new_quadruple->operando2 = operando2;
		new_quadruple->operando1 = operando1;
		new_quadruple->resultado = temp;
		
		cout << "( " << new_quadruple->operador << ", " << new_quadruple->operando1 << ", " << new_quadruple->operando2 << ", " << new_quadruple->resultado << " ) \n";
		
		//resultadoParcial = resultadoParcial - 1;
		//resultadoParcial_aux = convert_to_char(resultadoParcial);
		g_queue_push_tail(pilaTipos, (char *)"0");
		
	}else{
		cout << "Error de semántica: tipos incompatibles. \n";
		exit (EXIT_FAILURE);
	}
}

void generateQuadruple_asignacion(){
	char *op;
	char *operando1;
	char *res;
	char *aux;
	int operador, op1, op2, resultado, resAux;
	char *result;
	
	/*
	cout << "******************************************************\n";
	cout << "Pila Tipos: ";
	g_queue_foreach(pilaTipos, (GFunc)print_pilas, NULL);
	cout << "\n";
	cout << "Pila Operandos: ";
	g_queue_foreach(pilaOperandos, (GFunc)print_pilas, NULL);
	cout << "\n";
	cout << "Pila Operadores: ";
	g_queue_foreach(pilaOperadores, (GFunc)print_pilas, NULL);
	cout << "\n";
	*/
	cout << "ENTRE ASIGNACION \n";
	
	aux = (char *)g_queue_peek_tail(pilaOperadores);
	operador = atoi(aux);		
	aux = (char *)g_queue_peek_nth(pilaTipos,(g_queue_get_length(pilaTipos)-2));
	op2 = atoi(aux);
	aux = (char *)g_queue_peek_tail(pilaTipos);
	op1 = atoi(aux);
	resultado = cubo[operador][op1][op2];
	
	if(resultado != -1){
		g_queue_pop_tail(pilaTipos);
		g_queue_pop_tail(pilaTipos);
			
		Quadruple *new_quadruple = new Quadruple;
		op = (char *)g_queue_pop_tail(pilaOperadores);
		cout << "Operador: " << op << "\n";
		operando1 = (char *)g_queue_pop_tail(pilaOperandos);
		cout << "Operando1: " << operando1 << "\n";
		res = (char *)g_queue_pop_tail(pilaOperandos);
		cout << "Resultado: " << res << "\n";
	
		new_quadruple->operador = op;
		new_quadruple->operando2 = (char *)"-1";
		new_quadruple->operando1 = operando1;
		new_quadruple->resultado = res;
		
		cout << "( " << op << ", " << operando1 << ", " << new_quadruple->operando2 << ", " << res << " ) \n";
		cout << "Cuadruplo creado \n";
		
		cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
		cout << "Pila Tipos: ";
		g_queue_foreach(pilaTipos, (GFunc)print_pilas, NULL);
		cout << "\n";
		cout << "Pila Operandos: ";
		g_queue_foreach(pilaOperandos, (GFunc)print_pilas, NULL);
		cout << "\n";
		cout << "Pila Operadores: ";
		g_queue_foreach(pilaOperadores, (GFunc)print_pilas, NULL);
		cout << "\n";
		
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

char * get_operator_type(const char* op){
	//cout << "Push to pila operadores: " << op << "\n";
	
	if(strcmp(op,"+") == 0){
		return ((char *)"0");
	}else if(strcmp(op,"-") == 0){
		return ((char *)"1");
	}else if(strcmp(op,"/") == 0){
		return ((char *)"2");
	}else if(strcmp(op,"*") == 0){
		return ((char *)"3");
	}else if(strcmp(op,"<") == 0){
		return ((char *)"4");
	}else if(strcmp(op,">") == 0){
		return ((char *)"5");
	}else if(strcmp(op,"=") == 0){
		return ((char *)"6");
	}else if(strcmp(op,"<>") == 0){
		return ((char *)"7");
	}else if(strcmp(op,"==") == 0){
		return ((char *)"8");
	}else if(strcmp(op,"#") == 0){
		return ((char *)"-1");
	}
}

char *get_var_type(const char *var_cte){
	//cout << "Push to pila tipos: " << var_cte << "\n";
	
	if(strcmp(var_cte,"int") == 0){
		return ((char *)"0");
	}else if(strcmp(var_cte,"float") == 0){
		return ((char *)"1");
	}else if(strcmp(var_cte,"string") == 0){
		return ((char *)"2");
	}else if(strcmp(var_cte,"boolean") == 0){
		return ((char *)"3");
	}else if(strcmp(var_cte,"char") == 0){
		return ((char *)"4");
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
	pilaTipos = g_queue_new();
	pilaSaltos = g_queue_new();
	pilaOperadores = g_queue_new();
	pilaOperandos = g_queue_new();
	
	tableProc_stack = g_queue_new();
	tableVar_stack = g_queue_new();
}

/*******************************************
 * Función para agregar un nuevo id con su *
 * tipo de dato y direccion virtual a la   *
 * tabla de procedimientos 				   *
 *******************************************/
void insert_to_procs_table(string id, string dirInitial, string size){
	int hash_key;						//Valor que le corresponde dependiendo la primera letra del id
	int value_inside_array;				//Valor que se encuentre dentro de la casilla del arreglo, que corresponde a la posicion dentro de la lista principal			
	bool stack_exists;					//Checa si hay alguna lista dentro de alguna casilla de la lista principal
	const char * string_aux;			//String auxiliar
	GList* procedure_in_stack;			//Lista utilizada para encontrar alguna variable repetida
		
	GQueue* stack_aux = g_queue_new();		//Pila auxiliar
	Procedure *node = new Procedure;		//Nodo
	
	node->name = id;					//Se asigna el id al nodo
	node->dirInitial = dirInitial;		//Se asigna el tipo de dato al nodo
	node->size = size;					//Se asigna la direccion virtual al nodo
	//cout << "Nodo creado \n";
	
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
void insert_to_vars_table(string id, string type, string dirVirtual){
	int hash_key;						//Valor que le corresponde dependiendo la primera letra del id
	int value_inside_array;				//Valor que se encuentre dentro de la casilla del arreglo, que corresponde a la posicion dentro de la lista principal			
	bool stack_exists;					//Checa si hay alguna lista dentro de alguna casilla de la lista principal
	const char * string_aux;			//String auxiliar
	GList* variable_in_stack;			//Lista utilizada para encontrar alguna variable repetida
		
	GQueue* stack_aux = g_queue_new();	//Pila auxiliar
	Variable *node = new Variable;		//Nodo
	Variable *node_aux = new Variable;	//Nodo auxiliar
	
	node->name = id;					//Se asigna el id al nodo
	node->type = type;					//Se asigna el tipo de dato al nodo
	node->dirVirtual = dirVirtual;		//Se asigna la direccion virtual al nodo
	//cout << "Nodo creado \n";
	
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
		
		if(!variable_in_stack){														//Si no existe el nombre de la variable en la lista
			g_queue_push_tail(stack_aux, node);										//Agrego el nuevo id (nodo) a la lista
			g_queue_push_nth(tableVar_stack, stack_aux, value_inside_array);		//Meto la lista actualizada en la posicion original de la lista
			g_queue_pop_nth(tableVar_stack, value_inside_array+1);					//Elimino la lista "desactualizada" que se encuentra una posicion adelante de la recien agregada
			//cout << "La pila tiene :" << g_queue_get_length(tableVar_stack) << "\n";
			//node_aux = (Variable *)g_queue_peek_head(stack_aux);
			//cout << node_aux->name << "\n";
		}else{																	//Si ya existia la variable, truena el programa
			cout << "LA VARIABLE YA HA SIDO DECLARADA ANTERIORMENTE \n";
			exit (EXIT_FAILURE);
		}
	}
	//cout << "La variable " << id << " ha sido agregada exitosamente\n";
}

void main_function_name(char *function_name){
	main_function = function_name;
	//cout << "MAIN FUNCTION: " << main_function << "\n";
}

void pop_of_pilaOperadores(){
	g_queue_pop_tail(pilaOperadores);
}

void print_pilas(gpointer data, gpointer user_data){
	cout << (char *)data << " ";
}

void push_to_pilaOperadores(char *op){
	char *result;
	const char *aux;
	int op_type;
	
	aux = op;
	
	result = get_operator_type(aux);
	g_queue_push_tail(pilaOperadores, result);
	
	//cout << "Pila Operadores: ";
	//g_queue_foreach(pilaOperadores, (GFunc)print_pilas, NULL);
	//cout << "\n";
}

void push_to_pilaOperandos(char *var_cte){
	char *var_type, *var_type_aux, *dirVirtual_aux;
	int type, dirVirtual;
	
	var_type = search_for_variable_type(var_cte);
	var_type_aux = get_var_type(var_type);
	type = atoi(var_type_aux);
	
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
		}else if(type == 1){
			dirVirtual = LOCAL_FLOAT + local_float_cont;
			local_float_cont++;
		}else if(type == 2){
			dirVirtual = LOCAL_STRING + local_string_cont;
			local_string_cont++;
		}else if(type == 3){
			dirVirtual = LOCAL_BOOLEAN + local_boolean_cont;
			local_boolean_cont++;
		}else if(type == 4){
			dirVirtual = LOCAL_CHAR + local_char_cont;
			local_char_cont++;
		}
	}
	
	
	dirVirtual_aux = convert_to_char(dirVirtual);
	
	g_queue_push_tail(pilaOperandos,dirVirtual_aux);
	
	cout << "Push to pila operandos: " << var_cte << " o " << dirVirtual_aux << "\n";
	cout << "Pila Operandos: ";
	g_queue_foreach(pilaOperandos, (GFunc)print_pilas, NULL);
	cout << "\n";
}

void push_to_pilaTipos(char *var_cte){
	char *var_type, *result;
	const char* aux;
	
	var_type = search_for_variable_type(var_cte);
	aux = var_type;
	
	result = get_var_type(aux);
	
	g_queue_push_tail(pilaTipos, result);
	
	//cout << "Pila Tipos: ";
	//g_queue_foreach(pilaTipos, (GFunc)print_pilas, NULL);
	//cout << "\n";
}

void quadruple_add_sub(){
	char *operador = (char *)g_queue_peek_tail(pilaOperadores);
	int op;
	
	op = atoi(operador);
	
	//cout << "ADD-SUB \n";
	//cout << "El operador es: " << operador << "\n";
	
	if(op == 0 || op == 1){
		generateQuadruple();
	}
}

void quadruple_mult_div(){
	char *operador = (char *)g_queue_peek_tail(pilaOperadores);
	int op;
	
	op = atoi(operador);
	
	//cout << "MULT-DIV \n";
	//cout << "El operador es: " << operador << "\n";
	
	if(op == 2 || op == 3){
		generateQuadruple();
	}
}

void quadruple_relational(){
	char *operador = (char *)g_queue_peek_tail(pilaOperadores);
	int op;
	
	op = atoi(operador);
	
	//cout << "RELACIONAL \n";
	//cout << "El operador es: " << operador << "\n";
	
	if(op == 4 || op == 5 || op == 7 || op == 8){
		generateQuadruple();
	}else if(op == 6){
		generateQuadruple_asignacion();
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
		cout << "Variables del mismo nombre \n";
		return 0;
	}else{
		return -1;
	}
}

char *search_for_variable_type(char *var_cte){
	int ascii, stack_position;
	const char *string_aux;				//String auxiliar
	GQueue* stack_aux = g_queue_new();	//Pila auxiliar
	GList* variable_in_stack;			//Lista utilizada para encontrar alguna variable
	Variable *node_aux = new Variable;	//Nodo auxiliar
	char * var_type;
	
	ascii = get_hash_key(var_cte);
	stack_position = variable_index[ascii]-1;
	
	stack_aux = (GQueue *)g_queue_peek_nth(tableVar_stack, stack_position);
	
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

void set_current_function(char *function){
	//cout << "CURRENT FUNCTION: " << function << "\n";
	
	current_function = atoi(function);
}