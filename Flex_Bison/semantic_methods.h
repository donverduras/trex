//g++ Trex.tab.c lex.yy.c `pkg-config --cflags --libs glib-2.0` semantic_methods.c semantic_methods.h -ll -o Trex

#include <iostream>
#include <string>
#include <stdlib.h>
#include <glib.h>

using namespace std;

struct VarCont;
struct Procedure;
struct Variable;

int asign_dirVirtual(char* var_type);
bool check_if_stack_exists(int key, int arrType);
void count_params();
void delete_vars_from_varTable(char *func_name);
void generate_activation_record(char *func_name);
void generate_fin_for();
void generate_fin_if();
void generate_fin_llamada(char *func_name);
void generate_fin_while();
void generate_obj();
void generateQuadruple();
void generateQuadruple_array();
void generateQuadruple_asignacion();
void generateQuadruple_else();
void generateQuadruple_for2();
void generateQuadruple_for3();
void generateQuadruple_if();
void generateQuadruple_print();
void generateQuadruple_while();
int get_hash_key(string key);
int get_operator_type(const char* op);
Procedure *get_proc(char *func);
Variable *get_var(char *var_cte);
int get_var_type(const char *var_cte);
void initialize();
void initialize_arrs();
void initialize_stacks();
void insert_arr_to_vars_table(string id, string type, string size);
void insert_param_type(char *func_name, char *var_type);
void insert_to_procs_table(string id);
void insert_to_vars_table(string id, string type, char* func_name);
void main_function_name(char *function_name);
void pop_of_pilaOperadores();
void print_hashTable(gpointer key, gpointer value, gpointer user_data);
void print_pilas(gpointer data, gpointer user_data);
void print_quadruples(gpointer data, gpointer user_data);
void push_quadruple_index_to_pilaSaltos();
void push_to_pilaOperadores(char *var_cte);
void push_to_pilaOperandos(char *var_cte, char *id_type);
void push_to_pilaTipos(char *var_cte);
void push_to_pilaTipos_directly(char *type);
void quadruple_add_sub();
void quadruple_add_sub();
void quadruple_mult_div();
void reset_conts();
void reset_func_count();
void reset_param_counter();
void quadruple_relational();
int search_for_arrLimit(char *var_cte);
int search_for_id(gconstpointer a, gconstpointer b);
int search_for_dirVirtual(char *var_cte);
char *search_for_variable_type(char *var_cte);
void set_current_function(char *function, char* func_name);
void set_fin_function(char *func);
void set_start_function(char *func);
void verify_arr_limit(char *var_cte);
void verify_function_name(char *func_name);
void verify_parameters(char *func_name);