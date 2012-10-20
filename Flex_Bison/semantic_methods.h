//g++ Trex.tab.c lex.yy.c `pkg-config --cflags --libs glib-2.0` semanthic_method_v3.c semanthic_method_v2.h -ll -o Trex

void initialize_var_proc_table();
void add_to_proc_table(char  *function_name);
void add_to_var_table(char *function_name, char *var_type, char* memory_loc, char *var_name);