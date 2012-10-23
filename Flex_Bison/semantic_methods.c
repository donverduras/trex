#include <iostream>
#include <string>
#include <stdlib.h>
#include <glib.h>
#include "semantic_methods.h"

using namespace std;

static GHashTable* main_table;		//Tabla de procedimientos principal

static GQueue* pilaTipos;
static GQueue* pilaSaltos;
static GQueue* pilaOperadores;
static GQueue* pilaOperandos;
static GQuere* pilaPasos;

static char* current_function;
static char* main_function;

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

typedef struct {
	char* operador;
	char* operando1;
	char* operando2;
	char* resultado;
}quadruple;

/***************************************************
 * Inicializa la tabla de procedimientos principal *
 ***************************************************/
void initialize_var_proc_table(){
	main_table = g_hash_table_new(g_str_hash, g_str_equal);								//Inicializa la tabla de procedimientos general
	cout << "Tabla inicializada \n";
}

void initialize_stacks(){
	pilaTipos = g_queue_new();
	pilaSaltos = g_queue_new();
	pilaOperadores = g_queue_new();
	pilaOperandos = g_queue_new();
}

void main_function_name(char *function_name){
	main_function = function_name;
}

/***************************************************
 * Hace una busqueda para ver si el nombre del	   *
 * procedimiento existe en dicha tabla. Si ya 	   *
 * existe, entonces marca un error. Si no, entonces*
 * agrega el nombre del procedimiento a la tabla   *
 * y crea una tabla secundaria en donde se 		   *
 * almacenaran los tipos de datos de las variables *
 * de dicho procedimiento.						   *
 ***************************************************/
void add_to_proc_table(char  *function_name) {
	cout << "Se recibe el nombre de la funcion: " << function_name << "\n";
	if(g_hash_table_lookup(main_table,function_name) == NULL){							//Busca si el nombre del procedimiento existe
		GHashTable* var_table = g_hash_table_new(g_str_hash, g_str_equal);				//Crea una nueva tabla de tipos de dato
		
		g_hash_table_insert(main_table, function_name, var_table);						//Agrega el nombre de la funcion y como valor su tabla
		current_function = function_name;
		cout << "La funcion " << function_name << " se ha agregado exitosamente \n";
	}else{
		cout << "Error, la funcion ha agregar ya existe \n";
		exit (EXIT_FAILURE);
	}
}

void add_to_var_table(char *function_name, char *var_type, char* memory_loc, char *var_name){
	cout << "Se pretende agregar a: " << function_name << " la variable: " << var_name << " de tipo: " << var_type << "\n";
	gpointer var_type_table_aux;
	gpointer dir_name_table_aux;
	GHashTable* var_type_table;
	GHashTable* dir_name_table;
	
	var_type_table_aux = g_hash_table_lookup(main_table,function_name);					//Apuntador al valor resultante de la llave de la tabla de procedimientos
	var_type_table = (GHashTable*)var_type_table_aux;									//Convertir el apuntador a valor a una tabla de Hash
	
	if(var_type_table_aux == NULL){														//El nombre del procedimiento no está en la tabla
		cout << "El nombre del procedimiento no existe \n";
		exit (EXIT_FAILURE);
	}else{
		dir_name_table_aux = g_hash_table_lookup(var_type_table,var_type);				//Apuntador al valor resultante de la tabla de tipos de datos
		
		if(dir_name_table_aux == NULL){													//Si el tipo de dato no se encuentra en la tabla...
			dir_name_table = g_hash_table_new(g_str_hash, g_str_equal);					//Creo una nueva tabla para agregar variables de ese tipo de dato
			
			g_hash_table_insert(dir_name_table, var_name, memory_loc);					//Agrego a la tabla la direccion de memoria y el nombre de la variable
			g_hash_table_insert(var_type_table, var_type, dir_name_table);				//Inserto la nueva tabla como valor a la tabla con el tipo de dato
			cout << "La variable " << var_name << " con el tipo de dato " << var_type << " ha sido agregada exitosamente \n";
		}else{
			dir_name_table = (GHashTable*)dir_name_table_aux;							//Tabla de direcciones virtuales y nombre de la variable
			
			if(g_hash_table_lookup(dir_name_table, var_name) == NULL){					//Si no existe el nombre de la variable...
				g_hash_table_insert(dir_name_table, var_name, memory_loc);
				cout << "La variable " << var_name << " con el tipo de dato " << var_type << " ha sido agregada exitosamente \n";
			}else{
				cout << "La variable a declarar ya existe! \n";
				exit (EXIT_FAILURE);
			}
		}
	}
	
}

void push_to_pilaOperandos(char *var_cte){
	g_queue_push_tail(pilaOperandos,var_cte);
}

void push_to_pilaOperadores(char *var_cte){
	g_queue_push_tail(pilaOperadores,var_cte);
}

char *get_var_type(char *cte_id){
	
}

void quadruple_mult_div(){
	char *operador = g_queue_peek_tail(pilaOperadores);
	
	if(operador == "*" || operador == "/"){
		generateQuadruple();
	}else{
		exit (EXIT_FAILURE);
	}
}

void generateQuadruple(){
	char *op;
	char *operando1;
	char *operando2;
	char *res;
	
	quadruple *new = g_slice_new(quadruple);
	op = g_queue_pop_tail(pilaOperadores);
	operando2 = g_queue_pop_tail(pilaOperandos);
	operando1 = g_queue_pop_tail(pilaOperandos);
	
}

