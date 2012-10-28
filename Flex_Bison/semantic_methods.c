#include <iostream>
#include <string>
#include <stdlib.h>
#include <glib.h>
#include "semantic_methods.h"

using namespace std;

/******************************Declaración de variables**********************************/

//Bloque de variables utilizadas para la generación de tablas de procedimientos y variables
static int procedure_index[26];			//Tabla de Hash para los procedimientos
static int table_size = 26;				//Tamaño de las "tablas"
static int variable_index[26];			//Tabla de Hash para las variables

static GQueue* tableProc_stack;			//Lista donde están almacenados los nodos con la información de cada procedimiento
static GQueue* tableVar_stack;			//Lista donde están almacenados los nodos con la información de cada variable

static char* main_function;

/*********************************Estructuras de datos***********************************/

//Nodo que contiene información importante de cada procedimiento
struct Procedure{
	string name;
	string dirInitial;
	string size;
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

void initialize(){
	initialize_arrs();
	initialize_stacks();
	
	cout << "PROCESO DE INICIALIZACION: CHECK \n";
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
	cout << "La funcion " << id << " ha sido agregada exitosamente\n";
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
	cout << "La variable " << id << " ha sido agregada exitosamente\n";
}

void main_function_name(char *function_name){
	main_function = function_name;
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

