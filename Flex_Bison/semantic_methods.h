//g++ Trex.tab.c lex.yy.c `pkg-config --cflags --libs glib-2.0` semantic_methods.c semantic_methods.h -ll -o Trex

#include <iostream>
#include <string>
#include <stdlib.h>
#include <glib.h>

using namespace std;

bool check_if_stack_exists(int key, int arrType);
int get_hash_key(string key);
void initialize();
void initialize_arrs();
void initialize_stacks();
void insert_to_procs_table(string id, string dirInitial, string size);
void insert_to_vars_table(string id, string type, string dirVirtual);
void main_function_name(char *function_name);
int search_for_id(gconstpointer a, gconstpointer b);