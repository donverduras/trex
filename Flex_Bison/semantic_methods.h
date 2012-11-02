//g++ Trex.tab.c lex.yy.c `pkg-config --cflags --libs glib-2.0` semantic_methods.c semantic_methods.h -ll -o Trex

#include <iostream>
#include <string>
#include <stdlib.h>
#include <glib.h>

using namespace std;

int asign_dirVirtual(char* var_type);
bool check_if_stack_exists(int key, int arrType);
void generate_fin_if();
void generate_fin_while();
void generateQuadruple();
void generateQuadruple_asignacion();
void generateQuadruple_else();
void generateQuadruple_if();
void generateQuadruple_while();
int get_hash_key(string key);
int get_operator_type(const char* op);
int get_var_type(const char *var_cte);
void initialize();
void initialize_arrs();
void initialize_stacks();
void insert_to_procs_table(string id, string dirInitial, string size);
void insert_to_vars_table(string id, string type);
void main_function_name(char *function_name);
void pop_of_pilaOperadores();
void print_pilas(gpointer data, gpointer user_data);
void push_quadruple_index_to_pilaSaltos();
void push_to_pilaOperadores(char *var_cte);
void push_to_pilaOperandos(char *var_cte, char *id_type);
void push_to_pilaTipos(char *var_cte);
void quadruple_add_sub();
void quadruple_add_sub();
void quadruple_mult_div();
void quadruple_relational();
int search_for_id(gconstpointer a, gconstpointer b);
int search_for_dirVirtual(char *var_cte);
char *search_for_variable_type(char *var_cte);
void set_current_function(char *function);