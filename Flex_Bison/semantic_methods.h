//g++ Trex.tab.c lex.yy.c `pkg-config --cflags --libs glib-2.0` semantic_methods.c semantic_methods.h -ll -o Trex

void initialize_var_proc_table();
void add_to_proc_table(char  *function_name);
void add_to_var_table(char *function_name, char *var_type, char* memory_loc, char *var_name);