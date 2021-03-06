/*
#Salvador Salazar
#Luis Verduzco

#Maquina Virtual

*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <stack>
#include <stdio.h>
#include <sstream>
#include <cmath>

using namespace std;

/*****************************
 * Clase Memoria			 *
 * Almacena arreglos de los  *
 * diferentes tipos de datos *
 * para su manipulacion en 	 *
 * ejecucion de la VM		 *
 *****************************/
class Memoria{
	private:
		int id;
		int *enteros;
		float *flotantes;
		string *strings;
		bool *booleans;
		char *chars;
	
	public:
		Memoria(){
		
		}
		
		int getId(){
			return id;
		}
		
		void setId(int id_name){
			id = id_name;
		}
		
		void setEnteros(int tamanoEnteros){
			enteros = new int[tamanoEnteros];
		}
		
		void setFlotantes(int tamanoFlotantes){
			flotantes = new float[tamanoFlotantes];
		}
		
		void setStrings(int tamanoStrings){
			strings = new string[tamanoStrings];
		}
		
		void setBooleans(int tamanoBooleans){
			booleans = new bool[tamanoBooleans];
		}
		
		void setChars(int tamanoChars){
			chars = new char[tamanoChars];
		}
		
		int getValorEnteros(int index){
			return enteros[index];
		}
		
		void setValorEnteros(int index, int valor){
			enteros[index] = valor;
		}
		
		float getValorFlotantes(int index){
			return flotantes[index];
		}
		
		void setValorFlotantes(int index, float valor){
			flotantes[index] = valor;
		}
		
		string getValorStrings(int index){
			return strings[index];
		}
		
		void setValorStrings(int index, string valor){
			strings[index] = valor;
		}
		
		bool getValorBooleans(int index){
			return booleans[index];
		}
		
		void setValorBooleans(int index, bool valor){
			booleans[index] = valor;
		}
		
		char getValorChars(int index){
			return chars[index];
		}
		
		void setValorChars(int index, char valor){
			chars[index] = valor;
		}
};

//Estructura que cuenta los diferentes tipos de dato para variables globales/locales y temporales por funcion
struct VarCont{
	int integers;
	int flotantes;
	int estrings;
	int booleans;
	int chars;
};

//Estructura para la manipulacion de cuadruplos
struct Quadruple{
		int operador;
		int operando1;
		int operando2;
		int resultado;
	};

//Estructura para la manipulacion de funciones	
struct Procedure{
	string name;
	int dirInitial;					//Cuadruplo inicial
	int numParams;
	VarCont locals;
	VarCont temps;
};

enum symbols {	BASE_GLOBAL_INT = 1000,	BASE_GLOBAL_FLOAT = 6000,	BASE_GLOBAL_STRING = 11000,	BASE_GLOBAL_BOOLEAN = 16000,	BASE_GLOBAL_CHAR = 21000,
				BASE_LOCAL_INT = 26000,	BASE_LOCAL_FLOAT = 31000, 	BASE_LOCAL_STRING = 36000, 	BASE_LOCAL_BOOLEAN = 41000, 	BASE_LOCAL_CHAR = 46000,
				BASE_TEMP_INT = 51000,	BASE_TEMP_FLOAT = 56000, 	BASE_TEMP_STRING = 61000, 	BASE_TEMP_BOOLEAN = 66000, 		BASE_TEMP_CHAR = 71000,
				CONST_INT = 76000,		CONST_FLOAT = 81000, 		CONST_STRING = 86000, 		CONST_BOOLEAN = 91000, 			CONST_CHAR = 96000,
				BASE_POINTERS = 100000, BLOQUE = 5000, 				INTEGER = 0,				FLOAT = 1,						STRING = 2,
				BOOLEAN = 3, 			CHAR = 4, 					LOCAL_INT = 5,				LOCAL_FLOAT = 6, 				LOCAL_STRING = 7,
				LOCAL_BOOLEAN = 8, 		LOCAL_CHAR = 9,				TEMP_INT = 10,				TEMP_FLOAT = 11,				TEMP_STRING = 12,
				TEMP_BOOLEAN = 13,		TEMP_CHAR = 14,				CTE_INT = 15, 				CTE_FLOAT = 16, 				CTE_STRING = 17,
				CTE_BOOLEAN = 18, 		CTE_CHAR = 19, 				GOTO = 200,					GOTOF = 201,					PRINT = 300,
				ERA = 400,				GOSUB = 401,				PARAM = 402,				VER = 403,						INIPROC = 500,
				RET = 501,				SPECIALSUM = 800,			POINTER = 20, 				READ = 301,						MIN = 404,
				MAX = 405,				POW = 406,					REMAINDER = 407,			FLOOR = 408,					CEILING = 409,
				RANDOM = 410,			SQRT = 411 };

//Arreglo de memorias
Procedure *proc;
int sizeOfProc;
		
//Matriz de constantes
string *arrConst;
int *arrConstDirVir;
int primerValorConst = 0;
int tamanoConst;

//Cuadruplos
Quadruple *listOfQuads;
int tamanoCuadruplos;

//Index principal
int main_index = 0;
stack<Memoria> memStack;
int *apuntadores;
stack<int> return_index;
int contFunciones = 0;

//Generacion de creacion de memoria para funciones y clonacion de los datos a la misma
void activation_record(int funcion){
	Memoria *nueva = new Memoria;
	int contEnteros, contFlotantes, contStrings, contBooleans, contChars;
	int globalEnteros, globalFlotantes, globalStrings, globalBooleans, globalChars;
	contFunciones++;
	int cloneMem = memStack.top().getId();
	
	//Si la funcion a clonar no es la misma (para recursion)
	if(funcion != cloneMem){
		//Tamano para memoria global
		globalEnteros = proc[0].locals.integers + proc[0].temps.integers;
		globalFlotantes = proc[0].locals.flotantes + proc[0].temps.flotantes;
		globalStrings = proc[0].locals.estrings + proc[0].temps.estrings;
		globalBooleans = proc[0].locals.booleans + proc[0].temps.booleans;
		globalChars = proc[0].locals.chars + proc[0].temps.chars;
		
		//Tamano para memoria local
		contEnteros = globalEnteros + proc[funcion].locals.integers + proc[funcion].temps.integers;
		contFlotantes = globalFlotantes + proc[funcion].locals.flotantes + proc[funcion].temps.flotantes;
		contStrings = globalStrings + proc[funcion].locals.estrings + proc[funcion].temps.estrings;
		contBooleans = globalBooleans + proc[funcion].locals.booleans + proc[funcion].temps.booleans;
		contChars = globalChars + proc[funcion].locals.chars + proc[funcion].temps.chars;
	}else{
		globalEnteros = proc[cloneMem].locals.integers + proc[cloneMem].temps.integers;
		globalFlotantes = proc[cloneMem].locals.flotantes + proc[cloneMem].temps.flotantes;
		globalStrings = proc[cloneMem].locals.estrings + proc[cloneMem].temps.estrings;
		globalBooleans = proc[cloneMem].locals.booleans + proc[cloneMem].temps.booleans;
		globalChars = proc[cloneMem].locals.chars + proc[cloneMem].temps.chars;
		
		//Tamano para memoria local
		contEnteros = globalEnteros;
		contFlotantes = globalFlotantes;
		contStrings = globalStrings;
		contBooleans = globalBooleans;
		contChars = globalChars;
	}
	
	//Creacion de nuevos arreglos de memoria
	nueva->setId(contFunciones);
	nueva->setEnteros(contEnteros);
	nueva->setFlotantes(contFlotantes);
	nueva->setStrings(contStrings);
	nueva->setBooleans(contBooleans);
	nueva->setChars(contChars);
	
	//Clonacion de memoria global entera a local entera
	for(int i=0; i<globalEnteros; i++){
		nueva->setValorEnteros(i, memStack.top().getValorEnteros(i));
	}
	//Clonacion de memoria global flotante a local flotante
	for(int i=0; i<globalFlotantes; i++){
		nueva->setValorFlotantes(i, memStack.top().getValorFlotantes(i));
	}
	//Clonacion de memoria global string a local string
	for(int i=0; i<globalStrings; i++){
		nueva->setValorStrings(i, memStack.top().getValorStrings(i));
	}
	//Clonacion de memoria global boolean a local boolean
	for(int i=0; i<globalBooleans; i++){
		nueva->setValorBooleans(i, memStack.top().getValorBooleans(i));
	}
	//Clonacion de memoria global char a local char
	for(int i=0; i<globalChars; i++){
		nueva->setValorChars(i, memStack.top().getValorChars(i));
	}
	
	//Push to stack
	memStack.push(*nueva);
	
}

//Obtencion del valor constante de la tabla de constantes
string getConstantValue(int dirVir){
	for(int i=0; i<tamanoConst; i++){
		if(arrConstDirVir[i] == dirVir){
			return arrConst[i];
		}
	}
}

//Busqueda de una funcion por nombre
int searchForProc(string name){
	const char* aux;
	const char* func = name.c_str();
	int index = 0;
	
	for(int i=0; i<sizeOfProc; i++){
		aux = proc[index].name.c_str();
		
		if(strcmp(aux,func) == 0)
			return index;
		
		index++;
	}
}

//Generacion del tipo de dato de la direccion virtual
int generateDataType(int dirVir){
	return dirVir / BLOQUE;
}

//Regresa el tipo de dato que le corresponde a cada direccion virtual
int getDataType(int dirVir){
	int tipoDato = generateDataType(dirVir);
	
	switch(tipoDato){
		case 0: case 5: case 10: case 15:
			return INTEGER;
			break;
		case 1: case 6: case 11: case 16:
			return FLOAT;
			break;
		case 2: case 7: case 12: case 17:
			return STRING;
			break;
		case 3: case 8: case 13: case 18:
			return BOOLEAN;
			break;
		case 4 : case 9: case 14: case 19:
			return CHAR;
			break;
	}
}

//Generacion de offsets para Enteros
int generateOffsetInt(int dirVir, int tipoDato){
	int offset = 0;
	
	switch(tipoDato){
		case 0 :
			offset = dirVir - BASE_GLOBAL_INT;
			break;
		case 5 :
			offset = dirVir - BASE_LOCAL_INT + proc[0].locals.integers + proc[(memStack.size() - 1)].temps.integers;
			break;
		case 10 :
			offset = dirVir - BASE_TEMP_INT + proc[0].locals.integers;
			break;
	}
	return offset;
}

//Generacion de offsets para Flotantes
int generateOffsetFloat(int dirVir, int tipoDato){
	int offset = 0;
	
	switch(tipoDato){
		case 1 :
			offset = dirVir - BASE_GLOBAL_FLOAT;
			break;
		case 6 :
			offset = dirVir - BASE_LOCAL_FLOAT + proc[0].locals.flotantes + proc[(memStack.size() - 1)].temps.flotantes;
			break;
		case 11 :
			offset = dirVir - BASE_TEMP_FLOAT + proc[0].locals.flotantes;
			break;
	}
	return offset;
}

//Generacion de offsets para Strings
int generateOffsetString(int dirVir, int tipoDato){
	int offset = 0;

	switch(tipoDato){
		case 2 :
			offset = dirVir - BASE_GLOBAL_STRING;
			break;
		case 7 :
			offset = dirVir - BASE_LOCAL_STRING + proc[0].locals.estrings + proc[(memStack.size() - 1)].temps.estrings;
			break;
		case 12 :
			offset = dirVir - BASE_TEMP_STRING + proc[0].locals.estrings;
			break;
	}

	return offset;
}

//Generacion de offsets para Booleans
int generateOffsetBoolean(int dirVir, int tipoDato){
	int offset = 0;
	
	switch(tipoDato){
		case 3 :
			offset = dirVir - BASE_GLOBAL_BOOLEAN;
			break;
		case 8 :
			offset = dirVir - BASE_LOCAL_BOOLEAN + proc[0].locals.booleans + proc[(memStack.size() - 1)].temps.booleans;
			break;
		case 13 :
			offset = dirVir - BASE_TEMP_BOOLEAN + proc[0].locals.booleans;
			break;
	}
	return offset;
}

//Generacion de offsets para Chars
int generateOffsetChar(int dirVir, int tipoDato){
	int offset = 0;
	
	switch(tipoDato){
		case 4 :
			offset = dirVir - BASE_GLOBAL_CHAR;
			break;
		case 9 :
			offset = dirVir - BASE_LOCAL_CHAR + proc[0].locals.chars + proc[(memStack.size() - 1)].temps.chars;
			break;
		case 14 :
			offset = dirVir - BASE_TEMP_CHAR + proc[0].locals.chars;
			break;
	}
	return offset;
}

//Metodo que asigna a su respectiva direccion en memoria el valor obtenido de los parametros
void asignacion_parametros(int operando1, int resultado){
	int tipo_dato1, tipo_dato2, tipo_resultado, offsetRes, offsetOp1, offsetOp2;
	int genDT1, genDT2;
	
	int op1_int, op2_int, res_int, read_int;
	float op1_float, op2_float, res_float, read_float;
	string op1_string, op2_string, res_string, read_string;
	bool op1_boolean, op2_boolean, res_boolean, read_boolean;
	char op1_char, op2_char, res_char, read_char;
	
	tipo_dato1 = getDataType(operando1);
	tipo_resultado = getDataType(resultado);
	
	genDT1 = generateDataType(operando1);

	switch(tipo_dato1){
		case INTEGER:
			resultado = resultado + BASE_LOCAL_INT;
			if(genDT1 == CTE_INT){
				op1_int = atoi(getConstantValue(operando1).c_str());							
				res_int = op1_int;
				offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
				memStack.top().setValorEnteros(offsetRes, res_int);

			}else{
								
				offsetOp1 = generateOffsetInt(operando1, genDT1);
				op1_int = memStack.top().getValorEnteros(offsetOp1);							
				res_int = op1_int;
				offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
				memStack.top().setValorEnteros(offsetRes, res_int);
			}
		break;
		case FLOAT:
			resultado = resultado + BASE_LOCAL_FLOAT;
			if(genDT1 == CTE_FLOAT){
				op1_float = atof(getConstantValue(operando1).c_str());							
				res_float = op1_float;
				offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
				memStack.top().setValorFlotantes(offsetRes, res_float);
			}else{
				offsetOp1 = generateOffsetFloat(operando1, genDT1);
				op1_float = memStack.top().getValorFlotantes(offsetOp1);							
				res_float = op1_float;
				offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
				memStack.top().setValorFlotantes(offsetRes, res_float);
			}
		break;
		case STRING:
			resultado = resultado + BASE_LOCAL_STRING;
			if(genDT1 == CTE_STRING){
				op1_string = getConstantValue(operando1);						
				res_string = op1_string;
				offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
				memStack.top().setValorStrings(offsetRes, res_string);
			}else{
				offsetOp1 = generateOffsetString(operando1, genDT1);
				op1_string = memStack.top().getValorStrings(offsetOp1);							
				res_string = op1_string;
				offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
				memStack.top().setValorStrings(offsetRes, res_string);
			}
		break;
		case BOOLEAN:
			resultado = resultado + BASE_LOCAL_BOOLEAN;
			if(genDT1 == CTE_BOOLEAN){
				if(strcmp("true",getConstantValue(operando1).c_str()) == 0)
					op1_boolean = true;
				else
					op1_boolean = false;
						
				res_boolean = op1_boolean;
				offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
				memStack.top().setValorBooleans(offsetRes, res_boolean);
			}else{
				offsetOp1 = generateOffsetBoolean(operando1, genDT1);
				op1_boolean = memStack.top().getValorBooleans(offsetOp1);							
				res_boolean = op1_boolean;
				offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
				memStack.top().setValorBooleans(offsetRes, res_boolean);
			}
		break;
		case CHAR:
			resultado = resultado + BASE_LOCAL_CHAR;
			if(genDT1 == CTE_CHAR){
				op1_char = getConstantValue(operando1)[1];	
				res_char = op1_char;
				offsetRes = generateOffsetChar(resultado, generateDataType(resultado));
							
				memStack.top().setValorChars(offsetRes, res_char);
			}else{
				offsetOp1 = generateOffsetChar(operando1, genDT1);
				op1_char = memStack.top().getValorChars(offsetOp1);							
				res_char = op1_char;
				offsetRes = generateOffsetChar(resultado, generateDataType(resultado));
							
				memStack.top().setValorChars(offsetRes, res_char);
			}
		break;
	}
}

//Ejecucion de la funcion MAX
void maxfunc(int operando1, int operando2, int resultado){
	int tipo_dato1, tipo_dato2, tipo_resultado, genDT1, genDT2, offsetRes, offsetOp1, offsetOp2, offset;
	
	int op1_int, op2_int, res_int, read_int;
	float op1_float, op2_float, res_float, read_float;
	
	tipo_dato1 = getDataType(operando1);
	tipo_dato2 = getDataType(operando2);
	tipo_resultado = getDataType(resultado);
			
	genDT1 = generateDataType(operando1);
	genDT2 = generateDataType(operando2);
	
	switch(tipo_dato1){
		case INTEGER:
			//1 max(cte_int, cte_int)
			if(genDT1 == CTE_INT && genDT2 == CTE_INT){ 
			op1_int = atoi(getConstantValue(operando1).c_str());
			op2_int = atoi(getConstantValue(operando2).c_str());						
			res_int = max(op1_int, op2_int);
			offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
			memStack.top().setValorEnteros(offsetRes, res_int);
			
			}
			//3 max(cte_int, int)
			else if(genDT1 == CTE_INT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
				op1_int = atoi(getConstantValue(operando1).c_str());
				offsetOp2 = generateOffsetInt(operando2, genDT2);
				op2_int = memStack.top().getValorEnteros(offsetOp2);						
				res_int = max(op1_int, op2_int);
				offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
				memStack.top().setValorEnteros(offsetRes, res_int);	
			}
			//5 max(int, cte_int)
			else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_INT){
				offsetOp1 = generateOffsetInt(operando1, genDT1);
				op1_int = memStack.top().getValorEnteros(offsetOp1);	
				op2_int = atoi(getConstantValue(operando2).c_str());						
				res_int = max(op1_int, op2_int);
				offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
				memStack.top().setValorEnteros(offsetRes, res_int);
			}
			//7 max(int, int)
			else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
				offsetOp1 = generateOffsetInt(operando1, genDT1);
				op1_int = memStack.top().getValorEnteros(offsetOp1);
				offsetOp2 = generateOffsetInt(operando2, genDT2);
				op2_int = memStack.top().getValorEnteros(offsetOp2);						
				res_int = max(op1_int, op2_int);
				offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
				memStack.top().setValorEnteros(offsetRes, res_int);
			}
		break;
		case FLOAT:
			//10 max(cte_float, cte_float)
			if(genDT1 == CTE_FLOAT && genDT2 == CTE_FLOAT){
				op1_float = atof(getConstantValue(operando1).c_str());
				op2_float = atof(getConstantValue(operando2).c_str());						
				res_float = max(op1_float, op2_float);
				offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
				
				memStack.top().setValorFlotantes(offsetRes, res_float);	
			}
			//12 max(cte_float, float)
			else if(genDT1 == CTE_FLOAT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
				op1_float = atof(getConstantValue(operando1).c_str());
				offsetOp2 = generateOffsetInt(operando2, genDT2);
				op2_float = memStack.top().getValorFlotantes(offsetOp2);						
				res_float = max(op1_float, op2_float);
				offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
				
				memStack.top().setValorFlotantes(offsetRes, res_float);
			}
			//14 max(float, cte_float)
			else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_FLOAT){
				offsetOp1 = generateOffsetFloat(operando1, genDT1);
				op1_float = memStack.top().getValorFlotantes(offsetOp1);	
				op2_float = atof(getConstantValue(operando2).c_str());						
				res_float = max(op1_float, op2_float);
				offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
				
				memStack.top().setValorFlotantes(offsetRes, res_float);
			}
			//16 max(float, float)
			else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
				offsetOp1 = generateOffsetFloat(operando1, genDT1);
				op1_float = memStack.top().getValorFlotantes(offsetOp1);
				offsetOp2 = generateOffsetFloat(operando2, genDT2);
				op2_float = memStack.top().getValorFlotantes(offsetOp2);						
				res_float = max(op1_float, op2_float);
				offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
				
				memStack.top().setValorFlotantes(offsetRes, res_float);
			}
		break;
	}
}

//Ejecucion de la funcion MAX
void minfunc(int operando1, int operando2, int resultado){
	int tipo_dato1, tipo_dato2, tipo_resultado, genDT1, genDT2, offsetRes, offsetOp1, offsetOp2, offset;
	
	int op1_int, op2_int, res_int, read_int;
	float op1_float, op2_float, res_float, read_float;
	
	tipo_dato1 = getDataType(operando1);
	tipo_dato2 = getDataType(operando2);
	tipo_resultado = getDataType(resultado);
			
	genDT1 = generateDataType(operando1);
	genDT2 = generateDataType(operando2);
	
	switch(tipo_dato1){
		case INTEGER:
			//1 min(cte_int, cte_int)
			if(genDT1 == CTE_INT && genDT2 == CTE_INT){ 
			op1_int = atoi(getConstantValue(operando1).c_str());
			op2_int = atoi(getConstantValue(operando2).c_str());						
			res_int = min(op1_int, op2_int);
			offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
			memStack.top().setValorEnteros(offsetRes, res_int);
			
			}
			//3 min(cte_int, int)
			else if(genDT1 == CTE_INT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
				op1_int = atoi(getConstantValue(operando1).c_str());
				offsetOp2 = generateOffsetInt(operando2, genDT2);
				op2_int = memStack.top().getValorEnteros(offsetOp2);						
				res_int = min(op1_int, op2_int);
				offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
				memStack.top().setValorEnteros(offsetRes, res_int);	
			}
			//5 min(int, cte_int)
			else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_INT){
				offsetOp1 = generateOffsetInt(operando1, genDT1);
				op1_int = memStack.top().getValorEnteros(offsetOp1);	
				op2_int = atoi(getConstantValue(operando2).c_str());						
				res_int = min(op1_int, op2_int);
				offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
				memStack.top().setValorEnteros(offsetRes, res_int);
			}
			//7 min(int, int)
			else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
				offsetOp1 = generateOffsetInt(operando1, genDT1);
				op1_int = memStack.top().getValorEnteros(offsetOp1);
				offsetOp2 = generateOffsetInt(operando2, genDT2);
				op2_int = memStack.top().getValorEnteros(offsetOp2);						
				res_int = min(op1_int, op2_int);
				offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
				memStack.top().setValorEnteros(offsetRes, res_int);
			}
		break;
		case FLOAT:
			//10 min(cte_float, cte_float)
			if(genDT1 == CTE_FLOAT && genDT2 == CTE_FLOAT){
				op1_float = atof(getConstantValue(operando1).c_str());
				op2_float = atof(getConstantValue(operando2).c_str());						
				res_float = min(op1_float, op2_float);
				offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
				
				memStack.top().setValorFlotantes(offsetRes, res_float);	
			}
			//12 min(cte_float, float)
			else if(genDT1 == CTE_FLOAT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
				op1_float = atof(getConstantValue(operando1).c_str());
				offsetOp2 = generateOffsetInt(operando2, genDT2);
				op2_float = memStack.top().getValorFlotantes(offsetOp2);						
				res_float = min(op1_float, op2_float);
				offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
				
				memStack.top().setValorFlotantes(offsetRes, res_float);
			}
			//14 min(float, cte_float)
			else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_FLOAT){
				offsetOp1 = generateOffsetFloat(operando1, genDT1);
				op1_float = memStack.top().getValorFlotantes(offsetOp1);	
				op2_float = atof(getConstantValue(operando2).c_str());						
				res_float = min(op1_float, op2_float);
				offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
				
				memStack.top().setValorFlotantes(offsetRes, res_float);
			}
			//16 min(float, float)
			else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
				offsetOp1 = generateOffsetFloat(operando1, genDT1);
				op1_float = memStack.top().getValorFlotantes(offsetOp1);
				offsetOp2 = generateOffsetFloat(operando2, genDT2);
				op2_float = memStack.top().getValorFlotantes(offsetOp2);						
				res_float = min(op1_float, op2_float);
				offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
				
				memStack.top().setValorFlotantes(offsetRes, res_float);
			}
		break;
	}
}

//Ejecucion de la funcion POW
void powfunc(int operando1, int operando2, int resultado){
	int tipo_dato1, tipo_dato2, tipo_resultado, genDT1, genDT2, offsetRes, offsetOp1, offsetOp2, offset;
	
	float op1_float, op2_float, res_float, read_float;
	
	tipo_dato1 = getDataType(operando1);
	tipo_dato2 = getDataType(operando2);
	tipo_resultado = getDataType(resultado);
			
	genDT1 = generateDataType(operando1);
	genDT2 = generateDataType(operando2);
	
	switch(tipo_dato1){
		case FLOAT:
			//14 cte_float ^ cte_float
			if(genDT1 == CTE_FLOAT && genDT2 == CTE_FLOAT){
				op1_float = atof(getConstantValue(operando1).c_str());
				op2_float = atof(getConstantValue(operando2).c_str());						
				res_float = pow(op1_float, op2_float);
				offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
				
				memStack.top().setValorFlotantes(offsetRes, res_float);	
			}
			//17 cte_float ^ float
			else if(genDT1 == CTE_FLOAT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
				op1_float = atof(getConstantValue(operando1).c_str());
				offsetOp2 = generateOffsetInt(operando2, genDT2);
				op2_float = memStack.top().getValorFlotantes(offsetOp2);						
				res_float = pow(op1_float, op2_float);
				offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
				
				memStack.top().setValorFlotantes(offsetRes, res_float);
			}
			//20 float ^ cte_float
			else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_FLOAT){
				offsetOp1 = generateOffsetFloat(operando1, genDT1);
				op1_float = memStack.top().getValorFlotantes(offsetOp1);	
				op2_float = atof(getConstantValue(operando2).c_str());						
				res_float = pow(op1_float, op2_float);
				offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
				
				memStack.top().setValorFlotantes(offsetRes, res_float);
			}
			//23 float ^ float
			else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
				offsetOp1 = generateOffsetFloat(operando1, genDT1);
				op1_float = memStack.top().getValorFlotantes(offsetOp1);
				offsetOp2 = generateOffsetFloat(operando2, genDT2);
				op2_float = memStack.top().getValorFlotantes(offsetOp2);						
				res_float = pow(op1_float, op2_float);
				offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
				
				memStack.top().setValorFlotantes(offsetRes, res_float);
			}
		break;
	}
}

//Ejecucion de la funcion REMAINDER
void remainderfunc(int operando1, int operando2, int resultado){
	int tipo_dato1, tipo_dato2, tipo_resultado, genDT1, genDT2, offsetRes, offsetOp1, offsetOp2, offset;
	int op1_int, op2_int, res_int, read_int;
	
	tipo_dato1 = getDataType(operando1);
	tipo_dato2 = getDataType(operando2);
	tipo_resultado = getDataType(resultado);
		
	genDT1 = generateDataType(operando1);
	genDT2 = generateDataType(operando2);
	
	switch(tipo_dato1){
		case INTEGER:
			//1 cte_int % cte_int
			if(genDT1 == CTE_INT && genDT2 == CTE_INT){ 
				op1_int = atoi(getConstantValue(operando1).c_str());
				op2_int = atoi(getConstantValue(operando2).c_str());						
				res_int = op1_int % op2_int;
				offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
				memStack.top().setValorEnteros(offsetRes, res_int);	

			}
			//4 cte_int % int
			else if(genDT1 == CTE_INT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
				op1_int = atoi(getConstantValue(operando1).c_str());
				offsetOp2 = generateOffsetInt(operando2, genDT2);
				op2_int = memStack.top().getValorEnteros(offsetOp2);						
				res_int = op1_int % op2_int;
				offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
				memStack.top().setValorEnteros(offsetRes, res_int);	
			}
			//7 int % cte_int
			else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_INT){
				offsetOp1 = generateOffsetInt(operando1, genDT1);
				op1_int = memStack.top().getValorEnteros(offsetOp1);	
				op2_int = atoi(getConstantValue(operando2).c_str());						
				res_int = op1_int % op2_int;
				offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
				memStack.top().setValorEnteros(offsetRes, res_int);
			}
			//10 int % int
			else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
				offsetOp1 = generateOffsetInt(operando1, genDT1);
				op1_int = memStack.top().getValorEnteros(offsetOp1);
				offsetOp2 = generateOffsetInt(operando2, genDT2);
				op2_int = memStack.top().getValorEnteros(offsetOp2);						
				res_int = op1_int % op2_int;
				offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
				memStack.top().setValorEnteros(offsetRes, res_int);
			}
		break;
	}
}

//Ejecucion de la funcion FLOOR
void floorfunc(int operando1, int resultado){
	int genDT1;
	float offsetRes, offsetOp1, offset;
	
	float op1_float, res_float, read_float;
			
	genDT1 = generateDataType(operando1);
	
	if(genDT1 == CTE_FLOAT){
		op1_float = atof(getConstantValue(operando1).c_str());					
		res_float = floor(op1_float);
		offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
		
		memStack.top().setValorFlotantes(offsetRes, res_float);	
		
	}else {
		offsetOp1 = generateOffsetInt(operando1, genDT1);
		op1_float = memStack.top().getValorFlotantes(offsetOp1);						
		res_float = floor(op1_float);
		offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
		
		memStack.top().setValorFlotantes(offsetRes, res_float);
	}
}

//Ejecucion de la funcion CEILING
void ceilingfunc(int operando1, int resultado){
	int genDT1;
	float offsetRes, offsetOp1, offset;
	
	float op1_float, res_float, read_float;
			
	genDT1 = generateDataType(operando1);
	
	if(genDT1 == CTE_FLOAT){
		op1_float = atof(getConstantValue(operando1).c_str());					
		res_float = ceil(op1_float);
		offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
		
		memStack.top().setValorFlotantes(offsetRes, res_float);	
		
	}else {
		offsetOp1 = generateOffsetInt(operando1, genDT1);
		op1_float = memStack.top().getValorFlotantes(offsetOp1);						
		res_float = ceil(op1_float);
		offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
		
		memStack.top().setValorFlotantes(offsetRes, res_float);
	}
}

//Ejecucion de la funcion RANDOM
void randomfunc(int resultado){
	int res_int, offsetRes, genDT1;
	
	resultado = listOfQuads[main_index].resultado;
	
	genDT1 = generateDataType(resultado);
	
	res_int = rand();
	offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
				
	memStack.top().setValorEnteros(offsetRes, res_int);	
}

//Ejecucion de la funcion SQRT
void sqrtfunc(int operando1, int resultado){
	int genDT1;
	float offsetRes, offsetOp1, offset;
	
	float op1_float, res_float, read_float;
			
	genDT1 = generateDataType(operando1);
	
	if(genDT1 == CTE_FLOAT){
		op1_float = atof(getConstantValue(operando1).c_str());					
		res_float = sqrt(op1_float);
		offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
		
		memStack.top().setValorFlotantes(offsetRes, res_float);	
		
	}else {
		offsetOp1 = generateOffsetInt(operando1, genDT1);
		op1_float = memStack.top().getValorFlotantes(offsetOp1);						
		res_float = sqrt(op1_float);
		offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
		
		memStack.top().setValorFlotantes(offsetRes, res_float);
	}
}

//Lectura del codigo .obj
void readFile(){
	ifstream myfile ("/Users/ssalazars/Developer/trex/Testing/test.obj");
	string line;
	char *str, *pch;
	int i = 0, contPorciento = 0, primerValor = 0, tamano = 0, numFuncion = 0, numConst = 0, numQuads = 0;
	int contEnteros = 0, contFlotantes = 0, contStrings = 0, contBooleans = 0, contChars = 0;
	VarCont *locales;
	VarCont *temporales;
	Memoria *arrGlobal;
	
	if (myfile.is_open()){
		while (myfile.good()){
			getline (myfile,line);
			str = &line[0];
			
			if(strcmp(str, "%%") == 0){													//Se consume la linea
				getline(myfile, line);
				str = &line[0];
				contPorciento++;
				primerValor = 0;
				i = 0;
			}
			
			//Primer bloque - Funciones
			if(contPorciento == 0){
				if(primerValor == 0){
					tamano = atoi(str);
					sizeOfProc = tamano;
					primerValor++;
					arrGlobal = new Memoria;
					proc = new Procedure[tamano];
					locales = new VarCont;
					temporales = new VarCont;
				}else{
					pch = strtok (str," ,.-");
					while (pch != NULL){
						switch (i) {
							case 0 : //nombreFuncion
								proc[numFuncion].name = pch;
								if(numFuncion == 0){
									arrGlobal->setId(numFuncion);
								}
								i++;
								break;
							case 1 : //Cuadruplo Inicial
								proc[numFuncion].dirInitial = atoi(pch);
								i++;
								break;
							case 2 : //Numero de Parametros
								proc[numFuncion].numParams = atoi(pch);
								i++;
								break;
							case 3 : //enteros
								locales->integers = atoi(pch);
								if(numFuncion == 0){
									contEnteros += atoi(pch);
								}
								i++;
								break;
							case 4 : //flotantes
								locales->flotantes = atoi(pch);
								if(numFuncion == 0){
									contFlotantes += atoi(pch);
								}
								i++;
								break;
							case 5 : //strings
								locales->estrings = atoi(pch);
								if(numFuncion == 0){
									contStrings += atoi(pch);
								}
								i++;
								break;
							case 6 : //booleanos
								locales->booleans = atoi(pch);
								if(numFuncion == 0){
									contBooleans += atoi(pch);
								}
								i++;
								break;
							case 7 : //chars
								locales->chars = atoi(pch);
								if(numFuncion == 0){
									contChars += atoi(pch);
								}
								i++;
								break;
							case 8 : //Enteros temps
								temporales->integers = atoi(pch);
								if(numFuncion == 0){
									contEnteros += atoi(pch);
								}
								i++;
								break;
							case 9 : //flotantes temps
								temporales->flotantes = atoi(pch);
								if(numFuncion == 0){
									contFlotantes += atoi(pch);
								}
								i++;
								break;
							case 10	: //string temps
								temporales->estrings = atoi(pch);
								if(numFuncion == 0){
									contStrings += atoi(pch);
								}
								i++;
								break;
							case 11 : //booleanos temps
								temporales->booleans = atoi(pch);
								if(numFuncion == 0){
									contBooleans += atoi(pch);
								}
								i++;
								break;
							case 12 : //char temps
								temporales->chars = atoi(pch);
								if(numFuncion == 0){
									contChars += atoi(pch);
								}
								i++;
								break;
						}
						pch = strtok (NULL, ",");
					}
					arrGlobal->setEnteros(contEnteros);
					arrGlobal->setFlotantes(contFlotantes);
					arrGlobal->setStrings(contStrings);
					arrGlobal->setBooleans(contBooleans);
					arrGlobal->setChars(contChars);
					memStack.push(*arrGlobal);
					proc[numFuncion].locals = *locales;
					proc[numFuncion].temps = *temporales;
					i = 0;
					
					numFuncion++;
				}
			}
			//Segundo bloque - Tabla de constantes
			else if(contPorciento == 1){
				if(primerValor == 0){
					tamano = atoi(str);
					tamanoConst = tamano;
					primerValor++;
					arrConst = new string[tamano];
					arrConstDirVir = new int[tamano];
				}
				else{
					pch = strtok (str,",-");
					while (pch != NULL){
						switch (i){
						case 0 : //nombre Constante
							arrConst[numConst] = pch;
							i++;
							break;
						case 1 : //Dir de constante
							arrConstDirVir[numConst] = atoi(pch);
							i++;
							break;
						}
						pch = strtok(NULL, ",.-");
					}
					i = 0;
					
					
					numConst++;
				}
			}
			//Tercer bloque - Cuadruplos
			else if(contPorciento == 2){
				if(primerValor == 0){
					//Declaracion del arreglo que obtendra cuadruplos del tamano especificado
					tamano = atoi(str);
					tamanoCuadruplos = tamano;
					primerValor++;
					listOfQuads = new Quadruple[tamano];
				}
				else{
					pch = strtok (str," ,-");
					while (pch != NULL){
						switch (i) {
						case 0 : 
							listOfQuads[numQuads].operador = atoi(pch);
							i++;
							break;
						case 1 : 
							listOfQuads[numQuads].operando1 = atoi(pch);
							i++;
							break;
						case 2 : 
							listOfQuads[numQuads].operando2 = atoi(pch);
							i++;
							break;
						case 3 : //enteros
							listOfQuads[numQuads].resultado = atoi(pch);
							i++;
							break;		
						}
						pch = strtok (NULL, ",");
					}
					i = 0;
					
					numQuads++;
				}
			}
			//Cuarto bloque - apuntadores
			else if(contPorciento == 3){
				tamano = atoi(str);
				apuntadores = new int[tamano];
			}
		}
		myfile.close();
	}else cout << "Unable to open file";
}

//Ejecucion de la maquina virtual
void run(){
	int tipo_dato1, tipo_dato2, tipo_resultado, offsetRes, offsetOp1, offsetOp2;
	int operador, operando1, operando2, resultado;
	int genDT1, genDT2;
	int tipo;
	ostringstream ostr;
	
	int op1_int, op2_int, res_int, read_int;
	float op1_float, op2_float, res_float, read_float;
	string op1_string, op2_string, res_string, read_string;
	bool op1_boolean, op2_boolean, res_boolean, read_boolean;
	char op1_char, op2_char, res_char, read_char;
	
	while(main_index != tamanoCuadruplos){
		operador = listOfQuads[main_index].operador;
		operando1 = listOfQuads[main_index].operando1;
		operando2 = listOfQuads[main_index].operando2;
		resultado = listOfQuads[main_index].resultado;
				
		if(operador != SPECIALSUM){
			if(generateDataType(operando1) == POINTER){
				operando1 = apuntadores[operando1 - BASE_POINTERS];
			}
			if(generateDataType(operando2) == POINTER){
				operando2 = apuntadores[operando2 - BASE_POINTERS];
			}
			if(generateDataType(resultado) == POINTER){
				resultado = apuntadores[resultado - BASE_POINTERS];
			}
		}
		
		genDT1 = generateDataType(operando1);
		genDT2 = generateDataType(operando2);
		
		switch(operador){
			case 0:																			//+ PROBADA
				tipo_dato1 = getDataType(operando1);
				tipo_dato2 = getDataType(operando2);
				tipo_resultado = getDataType(resultado);
				switch(tipo_dato1){
					case INTEGER:
						//1 cte_int + cte_int
						if(genDT1 == CTE_INT && genDT2 == CTE_INT){ 
							op1_int = atoi(getConstantValue(operando1).c_str());
							op2_int = atoi(getConstantValue(operando2).c_str());						
							res_int = op1_int + op2_int;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
							
							memStack.top().setValorEnteros(offsetRes, res_int);	
	
						}
						//2 cte_int + cte_float
						else if(genDT1 == CTE_INT && genDT2 == CTE_FLOAT){
							op1_int = atoi(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							res_float = op1_int + op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);	
						}
						//3 cte_int + cte_string
						else if(genDT1 == CTE_INT && genDT2 == CTE_STRING){
							op1_string = getConstantValue(operando1).c_str();
							op2_string = getConstantValue(operando2).c_str();						
							res_string = "\"" + op1_string + &op2_string[1];
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//4 cte_int + int
						else if(genDT1 == CTE_INT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_int = atoi(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							res_int = op1_int + op2_int;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
							
							memStack.top().setValorEnteros(offsetRes, res_int);	
						}
						//5 cte_int + float
						else if(genDT1 == CTE_INT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_int = atoi(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							res_float = op1_int + op2_float;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_int);
						}
						//6 cte_int + string
						else if(genDT1 == CTE_INT && (genDT2 == STRING || genDT2 == LOCAL_STRING || genDT2 == TEMP_STRING)){
							op1_string = getConstantValue(operando1).c_str();
							offsetOp2 = generateOffsetString(operando2, generateDataType(offsetOp2));
							op2_string = memStack.top().getValorStrings(offsetOp2);					
							res_string = "\"" + op1_string + &op2_string[1];
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//7 int + cte_int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);	
							op2_int = atoi(getConstantValue(operando2).c_str());						
							res_int = op1_int + op2_int;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
							
							memStack.top().setValorEnteros(offsetRes, res_int);
						}
						//8 int + cte_float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							res_float = op1_int + op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						}
						//9 int + cte_string FALTA
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_STRING){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							//op1_int = memStack.top().getValorEnteros(offsetOp1);
							ostr << memStack.top().getValorEnteros(offsetOp1);
							op1_string = ostr.str();
							ostr.str(string());
							op2_string = getConstantValue(operando2).c_str();						
							res_string = "\"" + op1_string + &op2_string[1];
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//10 int + int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							res_int = op1_int + op2_int;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
							
							memStack.top().setValorEnteros(offsetRes, res_int);
						}
						//11 int + float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							res_float = op1_int + op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						}
						//12 int + string 																				
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == STRING || genDT2 == LOCAL_STRING || genDT2 == TEMP_STRING)){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							ostr << memStack.top().getValorEnteros(offsetOp1);
							op1_string = ostr.str();
							ostr.str(string());
							offsetOp2 = generateOffsetString(operando2, generateDataType(offsetOp2));
							op2_string = memStack.top().getValorStrings(offsetOp2);					
							res_string = "\"" + op1_string + &op2_string[1];
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
							
						}
						break;
					case FLOAT:
						//13 cte_float + cte_int
						if(genDT1 == CTE_FLOAT && genDT2 == CTE_INT){
							op1_float = atof(getConstantValue(operando1).c_str());	
							op2_int = atoi(getConstantValue(operando2).c_str());					
							res_float = op1_float + op2_int;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						}
						//14 cte_float + cte_float
						else if(genDT1 == CTE_FLOAT && genDT2 == CTE_FLOAT){
							op1_float = atof(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							res_float = op1_float + op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);	
						}
						//15 cte_float + cte_string
						else if(genDT1 == CTE_FLOAT && genDT2 == CTE_STRING){
							op1_string = getConstantValue(operando1).c_str();
							op2_string = getConstantValue(operando2).c_str();						
							res_string = "\"" + op1_string + &op2_string[1];
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//16 cte_float + int
						else if(genDT1 == CTE_FLOAT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							res_float = op1_float + op2_int;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						}
						//17 cte_float + float
						else if(genDT1 == CTE_FLOAT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							res_float = op1_float + op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						}
						//18  cte_float + string
						else if(genDT1 == CTE_FLOAT && (genDT2 == STRING || genDT2 == LOCAL_STRING || genDT2 == TEMP_STRING)){
							op1_string = getConstantValue(operando1).c_str();
							offsetOp2 = generateOffsetString(operando2, generateDataType(offsetOp2));
							op2_string = memStack.top().getValorStrings(offsetOp2);					
							res_string = "\"" + op1_string + &op2_string[1];
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//19 float + cte_int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_int = atoi(getConstantValue(operando2).c_str());						
							res_float = op1_float + op2_int;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						}
						//20 float + cte_float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							res_float = op1_float + op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						}
						//21 float + cte_string
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_STRING){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							//op1_float = memStack.top().getValorFlotantes(offsetOp1);
							ostr << memStack.top().getValorFlotantes(offsetOp1);
							op1_string = ostr.str();
							ostr.str(string());
							op2_string = getConstantValue(operando2).c_str();						
							res_string = "\"" + op1_string + &op2_string[1];
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//22 float + int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							res_float = op1_float + op2_int;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						}
						//23 float + float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							res_float = op1_float + op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						}
						//24 float + string
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == STRING || genDT2 == LOCAL_STRING || genDT2 == TEMP_STRING)){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							//op1_string = memStack.top().getValorFlotantes(offsetOp1);
							ostr << memStack.top().getValorFlotantes(offsetOp1);
							op1_string = ostr.str();
							ostr.str(string());
							offsetOp2 = generateOffsetString(operando2, generateDataType(offsetOp2));
							op2_string = memStack.top().getValorStrings(offsetOp2);					
							res_string = "\"" + op1_string + &op2_string[1];
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						break;
					case STRING:
						//25 cte_string + cte_int
						if(genDT1 == CTE_STRING && genDT2 == CTE_INT){
							op1_string = getConstantValue(operando1).c_str();
							op2_string = getConstantValue(operando2).c_str();						
							res_string = op1_string.substr(0, op1_string.size()-1) + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//26 cte_string + cte_float
						else if(genDT1 == CTE_STRING && genDT2 == CTE_FLOAT){
							op1_string = getConstantValue(operando1).c_str();
							op2_string = getConstantValue(operando2).c_str();						
							res_string = op1_string.substr(0, op1_string.size()-1) + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//27 cte_string + cte_string
						else if(genDT1 == CTE_STRING && genDT2 == CTE_STRING){
							op1_string = getConstantValue(operando1).c_str();
							op2_string = getConstantValue(operando2).c_str();						
							res_string = op1_string.substr(0, op1_string.size()-1) + &op2_string[1];
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//27.5 cte_string + cte_char
						else if(genDT1 == CTE_STRING && genDT2 == CTE_CHAR){
							op1_string = getConstantValue(operando1).c_str();
							op2_string = getConstantValue(operando2).c_str()[1];						
							res_string = op1_string.substr(0, op1_string.size()-1) + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//28 cte_string + int
						else if(genDT1 == CTE_STRING && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){
							op1_string = getConstantValue(operando1).c_str();
							offsetOp2 = generateOffsetInt(operando2, generateDataType(offsetOp2));
							ostr << memStack.top().getValorEnteros(offsetOp2);	
							op2_string = ostr.str();
							ostr.str(string());				
							res_string = op1_string.substr(0, op1_string.size()-1) + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//29 cte_string + float
						else if(genDT1 == CTE_STRING && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_string = getConstantValue(operando1).c_str();
							offsetOp2 = generateOffsetFloat(operando2, generateDataType(offsetOp2));
							ostr << memStack.top().getValorFlotantes(offsetOp2);	
							op2_string = ostr.str();
							ostr.str(string());				
							res_string = op1_string.substr(0, op1_string.size()-1) + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//30 cte_string + string
						else if(genDT1 == CTE_STRING && (genDT2 == STRING || genDT2 == LOCAL_STRING || genDT2 == TEMP_STRING)){
							op1_string = getConstantValue(operando1).c_str();
							offsetOp2 = generateOffsetString(operando2, generateDataType(offsetOp2));
							op2_string = memStack.top().getValorStrings(offsetOp2);							
							res_string = op1_string.substr(0, op1_string.size()-1) + &op2_string[1];
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//30.5 cte_string + char
						else if(genDT1 == CTE_STRING && (genDT2 == CHAR || genDT2 == LOCAL_CHAR || genDT2 == TEMP_CHAR)){
							op1_string = getConstantValue(operando1).c_str();
							offsetOp2 = generateOffsetChar(operando2, generateDataType(offsetOp2));
							op2_string = memStack.top().getValorChars(offsetOp2);								
							res_string = op1_string.substr(0, op1_string.size()-1) + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//31 string + cte_int
						else if((genDT1 == STRING || genDT1 == LOCAL_STRING || genDT1 == TEMP_STRING) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetString(operando1, generateDataType(offsetOp1));
							op1_string = memStack.top().getValorStrings(offsetOp1);
							op2_string = getConstantValue(operando2).c_str();					
							res_string = op1_string.substr(0, op1_string.size()-1) + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//32 string + cte_float
						else if((genDT1 == STRING || genDT1 == LOCAL_STRING || genDT1 == TEMP_STRING) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetString(operando1, generateDataType(offsetOp1));
							op1_string = memStack.top().getValorStrings(offsetOp1);
							op2_string = getConstantValue(operando2).c_str();					
							res_string = op1_string.substr(0, op1_string.size()-1) + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//33 string + cte_string
						else if((genDT1 == STRING || genDT1 == LOCAL_STRING || genDT1 == TEMP_STRING) && genDT2 == CTE_STRING){
							offsetOp1 = generateOffsetString(operando1, generateDataType(offsetOp1));
							op1_string = memStack.top().getValorStrings(offsetOp1);
							op2_string = getConstantValue(operando2).c_str();					
							res_string = op1_string.substr(0, op1_string.size()-1) + op2_string.substr(1, op1_string.size());
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//33.5 string + cte_string
						else if((genDT1 == STRING || genDT1 == LOCAL_STRING || genDT1 == TEMP_STRING) && genDT2 == CTE_CHAR){
							offsetOp1 = generateOffsetString(operando1, generateDataType(offsetOp1));
							op1_string = memStack.top().getValorStrings(offsetOp1);
							op2_string = getConstantValue(operando2).c_str()[1];						
							res_string = op1_string.substr(0, op1_string.size()-1) + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//34 string + int
						else if((genDT1 == STRING || genDT1 == LOCAL_STRING || genDT1 == TEMP_STRING) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){
							offsetOp1 = generateOffsetString(operando1, generateDataType(offsetOp1));
							op1_string = memStack.top().getValorStrings(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, generateDataType(offsetOp2));
							ostr << memStack.top().getValorEnteros(offsetOp2);	
							op2_string = ostr.str();
							ostr.str(string());				
							res_string = op1_string.substr(0, op1_string.size()-1) + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//35 string + float
						else if((genDT1 == STRING || genDT1 == LOCAL_STRING || genDT1 == TEMP_STRING) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							offsetOp1 = generateOffsetString(operando1, generateDataType(offsetOp1));
							op1_string = memStack.top().getValorStrings(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, generateDataType(offsetOp2));
							ostr << memStack.top().getValorFlotantes(offsetOp2);	
							op2_string = ostr.str();
							ostr.str(string());				
							res_string = op1_string.substr(0, op1_string.size()-1) + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//36 string + string
						else if((genDT1 == STRING || genDT1 == LOCAL_STRING || genDT1 == TEMP_STRING) && (genDT2 == STRING || genDT2 == LOCAL_STRING || genDT2 == TEMP_STRING)){
							offsetOp1 = generateOffsetString(operando1, generateDataType(offsetOp1));
							op1_string = memStack.top().getValorStrings(offsetOp1);
							offsetOp2 = generateOffsetString(operando2, generateDataType(offsetOp2));
							op2_string = memStack.top().getValorStrings(offsetOp2);							
							res_string = op1_string.substr(0, op1_string.size()-1) + &op2_string[1];
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//36.5 string + char
						else if((genDT1 == STRING || genDT1 == LOCAL_STRING || genDT1 == TEMP_STRING) && (genDT2 == CHAR || genDT2 == LOCAL_CHAR || genDT2 == TEMP_CHAR)){
							offsetOp1 = generateOffsetString(operando1, generateDataType(offsetOp1));
							op1_string = memStack.top().getValorStrings(offsetOp1);
							offsetOp2 = generateOffsetChar(operando2, generateDataType(offsetOp2));
							op2_string = memStack.top().getValorChars(offsetOp2);					
							res_string = op1_string.substr(0, op1_string.size()-1) + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						break;
					case CHAR:
						//37 cte_char + cte_string
						if(genDT1 == CTE_CHAR && genDT2 == CTE_STRING){
							op1_string = getConstantValue(operando1).c_str()[1];
							op2_string = getConstantValue(operando2).c_str();						
							res_string = "\"" + op1_string + op2_string.substr(1, op2_string.size());
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//38 cte_char + cte_char
						else if(genDT1 == CTE_CHAR && genDT2 == CTE_CHAR){
							op1_string = getConstantValue(operando1).c_str()[1];
							op2_string = getConstantValue(operando2).c_str()[1];						
							res_string = "\"" + op1_string + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//39 cte_char + string
						if(genDT1 == CTE_CHAR && (genDT2 == STRING || genDT2 == LOCAL_STRING || genDT2 == TEMP_STRING)){
							op1_string = getConstantValue(operando1).c_str()[1];
							offsetOp2 = generateOffsetString(operando2, generateDataType(offsetOp2));
							op2_string = memStack.top().getValorStrings(offsetOp2);							
							res_string = "\"" + op1_string + op2_string.substr(1, op2_string.size());
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//40 cte_char + char
						else if(genDT1 == CTE_CHAR && (genDT2 == CHAR || genDT2 == LOCAL_CHAR || genDT2 == TEMP_CHAR)){
							op1_string = getConstantValue(operando1).c_str()[1];
							offsetOp2 = generateOffsetChar(operando2, generateDataType(offsetOp2));
							op2_string = memStack.top().getValorChars(offsetOp2);						
							res_string = "\"" + op1_string + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//41 char + cte_string
						if((genDT1 == CHAR || genDT1 == LOCAL_CHAR || genDT1 == TEMP_CHAR) && genDT2 == CTE_STRING){
							offsetOp1 = generateOffsetChar(operando1, generateDataType(offsetOp1));
							op1_string = memStack.top().getValorChars(offsetOp1);
							op2_string = getConstantValue(operando2).c_str();						
							res_string = "\"" + op1_string + op2_string.substr(1, op2_string.size());
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//42 char + cte_char
						else if((genDT1 == CHAR || genDT1 == LOCAL_CHAR || genDT1 == TEMP_CHAR) && genDT2 == CTE_CHAR){
							offsetOp1 = generateOffsetChar(operando1, generateDataType(offsetOp1));
							op1_string = memStack.top().getValorChars(offsetOp1);
							op2_string = getConstantValue(operando2).c_str()[1];						
							res_string = "\"" + op1_string + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//43 char + string
						if((genDT1 == CHAR || genDT1 == LOCAL_CHAR || genDT1 == TEMP_CHAR) && (genDT2 == STRING || genDT2 == LOCAL_STRING || genDT2 == TEMP_STRING)){
							offsetOp1 = generateOffsetChar(operando1, generateDataType(offsetOp1));
							op1_string = memStack.top().getValorChars(offsetOp1);
							offsetOp2 = generateOffsetString(operando2, generateDataType(offsetOp2));
							op2_string = memStack.top().getValorStrings(offsetOp2);							
							res_string = "\"" + op1_string + op2_string.substr(1, op2_string.size());
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						//44 char + char
						else if((genDT1 == CHAR || genDT1 == LOCAL_CHAR || genDT1 == TEMP_CHAR) && (genDT2 == CHAR || genDT2 == LOCAL_CHAR || genDT2 == TEMP_CHAR)){
							offsetOp1 = generateOffsetChar(operando1, generateDataType(offsetOp1));
							op1_string = memStack.top().getValorChars(offsetOp1);
							offsetOp2 = generateOffsetChar(operando2, generateDataType(offsetOp2));
							op2_string = memStack.top().getValorChars(offsetOp2);						
							res_string = "\"" + op1_string + op2_string + "\"";
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
							
						}
						break;
					}
				break;
			case 1:																			//- PROBADA
				tipo_dato1 = getDataType(operando1);
				tipo_dato2 = getDataType(operando2);
				tipo_resultado = getDataType(resultado);
				switch(tipo_dato1){
					case INTEGER:
						//1 cte_int - cte_int
						if(genDT1 == CTE_INT && genDT2 == CTE_INT){ 
							op1_int = atoi(getConstantValue(operando1).c_str());
							op2_int = atoi(getConstantValue(operando2).c_str());						
							res_int = op1_int - op2_int;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
							
							memStack.top().setValorEnteros(offsetRes, res_int);
							
						}
						//2 cte_int - cte_float
						else if(genDT1 == CTE_INT && genDT2 == CTE_FLOAT){
							op1_int = atoi(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							res_float = op1_int - op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);	
							
							
						}
						//3 cte_int - int
						else if(genDT1 == CTE_INT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_int = atoi(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							res_int = op1_int - op2_int;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
							
							memStack.top().setValorEnteros(offsetRes, res_int);	
							
						}
						//4 cte_int - float
						else if(genDT1 == CTE_INT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_int = atoi(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							res_float = op1_int - op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
							
						}
						//5 int - cte_int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);	
							op2_int = atoi(getConstantValue(operando2).c_str());						
							res_int = op1_int - op2_int;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
							
							memStack.top().setValorEnteros(offsetRes, res_int);
							
						}
						//6 int - cte_float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							res_float = op1_int - op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
							
						}
						//7 int - int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							res_int = op1_int - op2_int;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
							
							memStack.top().setValorEnteros(offsetRes, res_int);
							
						}
						//8 int - float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							res_float = op1_int - op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
							
						}
						break;
					case FLOAT:
						//9 cte_float - cte_int
						if(genDT1 == CTE_FLOAT && genDT2 == CTE_INT){
							op1_float = atof(getConstantValue(operando1).c_str());	
							op2_int = atoi(getConstantValue(operando2).c_str());					
							res_float = op1_float - op2_int;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
							
							
						}
						//10 cte_float - cte_float
						else if(genDT1 == CTE_FLOAT && genDT2 == CTE_FLOAT){
							op1_float = atof(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							res_float = op1_float - op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						
						}
						//11 cte_float - int
						else if(genDT1 == CTE_FLOAT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							res_float = op1_float - op2_int;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
							
						}
						//12 cte_float - float
						else if(genDT1 == CTE_FLOAT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							res_float = op1_float - op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
							
						}
						//13 float - cte_int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_int = atoi(getConstantValue(operando2).c_str());						
							res_float = op1_float - op2_int;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
							
						}
						//14 float - cte_float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							res_float = op1_float - op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
							
						}
						//15 float - int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							res_float = op1_float - op2_int;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						
						}
						//16 float - float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							res_float = op1_float - op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
							
						}
						break;
				}
				break;
			case 2:																			/// PROBADA 
				tipo_dato1 = getDataType(operando1);
				tipo_dato2 = getDataType(operando2);
				tipo_resultado = getDataType(resultado);
				switch(tipo_dato1){
					case INTEGER:
						//1 cte_int / cte_int
						if(genDT1 == CTE_INT && genDT2 == CTE_INT){ 
							op1_float = atof(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());
							if(op2_float == 0.0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{						
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);
							}
							
						}
						//2 cte_int / cte_float
						else if(genDT1 == CTE_INT && genDT2 == CTE_FLOAT){
							op1_float = atof(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());
							if(op2_float == 0.0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{						
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);	
							}
							
						}
						//3 cte_int / int
						else if(genDT1 == CTE_INT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_float = memStack.top().getValorEnteros(offsetOp2);					
							if(op2_float == 0.0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{	
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);	
							}
						
						}
						//4 cte_int / float
						else if(genDT1 == CTE_INT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);
							if(op2_float == 0.0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{						
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);
							}
						}
						//5 int / cte_int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_float = memStack.top().getValorEnteros(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());
							if(op2_float == 0.0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{						
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);
							}
						}
						//6 int / cte_float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_float = memStack.top().getValorEnteros(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op2_float == 0.0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{						
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);	
							}
						}
						//7 int / int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_float = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_float = memStack.top().getValorEnteros(offsetOp2);						
							if(op2_float == 0.0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{	
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);	
							}
						}
						//8 int / float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_float = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op2_float == 0.0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{						
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);
							}
						}
						break;
					case FLOAT:
						//9 cte_float / cte_int
						if(genDT1 == CTE_FLOAT && genDT2 == CTE_INT){
							op1_float = atof(getConstantValue(operando1).c_str());	
							op2_float = atof(getConstantValue(operando2).c_str());					
							if(op2_float == 0.0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{						
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);
							}
						}
						//10 cte_float / cte_float
						else if(genDT1 == CTE_FLOAT && genDT2 == CTE_FLOAT){
							op1_float = atof(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op2_float == 0.0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{						
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);
							}
						}
						//11 cte_float / int
						else if(genDT1 == CTE_FLOAT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_float = memStack.top().getValorEnteros(offsetOp2);						
							if(op2_float == 0.0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{						
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);
							}
						}
						//12 cte_float / float
						else if(genDT1 == CTE_FLOAT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op2_float == 0.0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{						
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);
							}
						}
						//13 float / cte_int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op2_float == 0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{						
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);
							}
						}
						//14 float / cte_float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op2_float == 0.0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{						
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);
							}
						}
						//15 float / int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_float = memStack.top().getValorEnteros(offsetOp2);						
							if(op2_float == 0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{						
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);
							}
						}
						//16 float / float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op2_float == 0.0){
								cout << "Error: No se puede dividir entre 0. \n";
								exit (EXIT_FAILURE);
							}
							else{						
								res_float = op1_float / op2_float;
								offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
								
								memStack.top().setValorFlotantes(offsetRes, res_float);
							}
						}
						break;
				}
				break;
			case 3:																			//* PROBADA
				tipo_dato1 = getDataType(operando1);
				tipo_dato2 = getDataType(operando2);
				tipo_resultado = getDataType(resultado);
				switch(tipo_dato1){
					case INTEGER:
						//1 cte_int * cte_int
						if(genDT1 == CTE_INT && genDT2 == CTE_INT){ 
							op1_int = atoi(getConstantValue(operando1).c_str());
							op2_int = atoi(getConstantValue(operando2).c_str());						
							res_int = op1_int * op2_int;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
							
							memStack.top().setValorEnteros(offsetRes, res_int);	
							
						}
						//2 cte_int * cte_float
						else if(genDT1 == CTE_INT && genDT2 == CTE_FLOAT){
							op1_int = atoi(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							res_float = op1_int * op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);	
							
						}
						//3 cte_int * int
						else if(genDT1 == CTE_INT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_int = atoi(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							res_int = op1_int * op2_int;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
							
							memStack.top().setValorEnteros(offsetRes, res_int);	
						
						}
						//4 cte_int * float
						else if(genDT1 == CTE_INT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_int = atoi(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							res_float = op1_int * op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
							
						}
						//5 int * cte_int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);	
							op2_int = atoi(getConstantValue(operando2).c_str());						
							res_int = op1_int * op2_int;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
							
							memStack.top().setValorEnteros(offsetRes, res_int);
						
						}
						//6 int * cte_float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							res_float = op1_int * op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
							
						}
						//7 int * int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							res_int = op1_int * op2_int;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
							
							memStack.top().setValorEnteros(offsetRes, res_int);
							
						}
						//8 int * float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							res_float = op1_int * op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
							
						}
						break;
					case FLOAT:
						//9 cte_float * cte_int
						if(genDT1 == CTE_FLOAT && genDT2 == CTE_INT){
							op1_float = atof(getConstantValue(operando1).c_str());	
							op2_int = atoi(getConstantValue(operando2).c_str());					
							res_float = op1_float * op2_int;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						
						}
						//10 cte_float * cte_float
						else if(genDT1 == CTE_FLOAT && genDT2 == CTE_FLOAT){
							op1_float = atof(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							res_float = op1_float * op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);	
						
						}
						//11 cte_float * int
						else if(genDT1 == CTE_FLOAT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							res_float = op1_float * op2_int;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
							
						}
						//12 cte_float * float
						else if(genDT1 == CTE_FLOAT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							res_float = op1_float * op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
					
						}
						//13 float * cte_int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_int = atoi(getConstantValue(operando2).c_str());						
							res_float = op1_float * op2_int;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						
						}
						//14 float * cte_float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							res_float = op1_float * op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						
						}
						//15 float * int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							res_float = op1_float * op2_int;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						
						}
						//16 float * float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							res_float = op1_float * op2_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
							
						}
						break;
				}
				break;
			case 4:																			//< PROBADA
				tipo_dato1 = getDataType(operando1);
				tipo_dato2 = getDataType(operando2);
				tipo_resultado = getDataType(resultado);
				switch(tipo_dato1){
					case INTEGER:
						//1 cte_int < cte_int
						if(genDT1 == CTE_INT && genDT2 == CTE_INT){ 
							op1_int = atoi(getConstantValue(operando1).c_str());
							op2_int = atoi(getConstantValue(operando2).c_str());
							if(op1_int < op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//2 cte_int < cte_float
						else if(genDT1 == CTE_INT && genDT2 == CTE_FLOAT){
							op1_int = atoi(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_int < op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
					
						}
						//3 cte_int < int
						else if(genDT1 == CTE_INT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_int = atoi(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_int < op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//4 cte_int < float
						else if(genDT1 == CTE_INT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_int = atoi(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_int < op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//5 int < cte_int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);	
							op2_int = atoi(getConstantValue(operando2).c_str());						
							if(op1_int < op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//6 int < cte_float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_int < op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//7 int < int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_int < op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
					
						}
						//8 int < float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_int < op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);	
						
						}
						break;
					case FLOAT:
						//9 cte_float < cte_int
						if(genDT1 == CTE_FLOAT && genDT2 == CTE_INT){
							op1_float = atof(getConstantValue(operando1).c_str());	
							op2_int = atoi(getConstantValue(operando2).c_str());					
							if(op1_float < op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//10 cte_float < cte_float
						else if(genDT1 == CTE_FLOAT && genDT2 == CTE_FLOAT){
							op1_float = atof(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_float < op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//11 cte_float < int
						else if(genDT1 == CTE_FLOAT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_float < op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
						
						}
						//12 cte_float < float
						else if(genDT1 == CTE_FLOAT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_float < op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//13 float < cte_int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_int = atoi(getConstantValue(operando2).c_str());						
							if(op1_float < op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
					
						}
						//14 float < cte_float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_float < op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//15 float < int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_float < op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
					
						}
						//16 float < float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_float < op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);	
							
					
						}
						break;
				}
				break;
			case 5:																			//> PROBADA
				tipo_dato1 = getDataType(operando1);
				tipo_dato2 = getDataType(operando2);
				tipo_resultado = getDataType(resultado);
				switch(tipo_dato1){
					case INTEGER:
						//1 cte_int > cte_int
						if(genDT1 == CTE_INT && genDT2 == CTE_INT){ 
							op1_int = atoi(getConstantValue(operando1).c_str());
							op2_int = atoi(getConstantValue(operando2).c_str());
							if(op1_int > op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//2 cte_int > cte_float
						else if(genDT1 == CTE_INT && genDT2 == CTE_FLOAT){
							op1_int = atoi(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_int > op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
						//3 cte_int > int
						else if(genDT1 == CTE_INT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_int = atoi(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_int > op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
						
						}
						//4 cte_int > float
						else if(genDT1 == CTE_INT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_int = atoi(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_int > op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//5 int > cte_int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);	
							op2_int = atoi(getConstantValue(operando2).c_str());						
							if(op1_int > op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							/*
							cout << "Direccion 1: " << operando1 << "\n";
							cout << "Operando 1: " << op1_int << "\n";
							cout << "Direccion 2: " << operando2 << "\n";
							cout << "Operando 2: " << op2_int << "\n";
							cout << "Resultado: " << res_boolean << "\n";
							cout << "Index: " << offsetRes << "\n";
							cout << "Direccion Final: " << resultado << "\n";
							cout << "Valor Guardado: " << memStack.top().getValorBooleans(offsetRes) << "\n";
							*/
						}
						//6 int > cte_float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_int > op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//7 int > int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_int > op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
						//8 int > float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_int > op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);	
							
							
						}
						break;
					case FLOAT:
						//9 cte_float > cte_int
						if(genDT1 == CTE_FLOAT && genDT2 == CTE_INT){
							op1_float = atof(getConstantValue(operando1).c_str());	
							op2_int = atoi(getConstantValue(operando2).c_str());					
							if(op1_float > op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
						//10 cte_float > cte_float
						else if(genDT1 == CTE_FLOAT && genDT2 == CTE_FLOAT){
							op1_float = atof(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_float > op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//11 cte_float > int
						else if(genDT1 == CTE_FLOAT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_float > op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//12 cte_float > float
						else if(genDT1 == CTE_FLOAT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_float > op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//13 float > cte_int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_int = atoi(getConstantValue(operando2).c_str());						
							if(op1_float > op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//14 float > cte_float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_float > op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
						//15 float > int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_float > op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//16 float > float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_float > op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);	
							
						
						}
						break;
				}
				break;
			case 6:																			//= PROBADA
				tipo_dato1 = getDataType(operando1);
				tipo_resultado = getDataType(resultado);
				switch(tipo_dato1){
					case INTEGER:
						if(genDT1 == CTE_INT){
							op1_int = atoi(getConstantValue(operando1).c_str());							
							res_int = op1_int;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
							
							memStack.top().setValorEnteros(offsetRes, res_int);
							
						
							//cout << "Direccion: " << operando1 << "\n";
							//cout << "Operando 1: " << op1_int << "\n";
							//cout << "Resultado: " << res_int << "\n";
							//cout << "Index: " << offsetRes << "\n";
							//cout << "Direccion Final: " << resultado << "\n";
							//cout << "Valor Guardado: " << memStack.top().getValorEnteros(offsetRes) << "\n";

							
						}else{
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);							
							res_int = op1_int;
							offsetRes = generateOffsetInt(resultado, generateDataType(resultado));
													
							memStack.top().setValorEnteros(offsetRes, res_int);
							
							//cout << "Direccion Final: " << apuntadores[resultado - BASE_POINTERS] << "\n";
							//cout << "Valor Guardado: " << memStack.top().getValorEnteros(offsetRes) << "\n";
						}
						break;
					case FLOAT:
						if(genDT1 == CTE_FLOAT){
							op1_float = atof(getConstantValue(operando1).c_str());							
							res_float = op1_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						}else{
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);							
							res_float = op1_float;
							offsetRes = generateOffsetFloat(resultado, generateDataType(resultado));
							
							memStack.top().setValorFlotantes(offsetRes, res_float);
						}
						break;
					case STRING:
						if(genDT1 == CTE_STRING){
							op1_string = getConstantValue(operando1);						
							res_string = op1_string;
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}else{
							offsetOp1 = generateOffsetString(operando1, genDT1);
							op1_string = memStack.top().getValorStrings(offsetOp1);							
							res_string = op1_string;
							offsetRes = generateOffsetString(resultado, generateDataType(resultado));
							
							memStack.top().setValorStrings(offsetRes, res_string);
						}
						break;
					case BOOLEAN:
						if(genDT1 == CTE_BOOLEAN){
							if(strcmp("true",getConstantValue(operando1).c_str()) == 0)
								op1_boolean = true;
							else
								op1_boolean = false;
						
							res_boolean = op1_boolean;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
						}else{
							offsetOp1 = generateOffsetBoolean(operando1, genDT1);
							op1_boolean = memStack.top().getValorBooleans(offsetOp1);							
							res_boolean = op1_boolean;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
						}
						break;
					case CHAR:
						if(genDT1 == CTE_CHAR){
							op1_char = getConstantValue(operando1)[1];	
							res_char = op1_char;
							offsetRes = generateOffsetChar(resultado, generateDataType(resultado));
							
							memStack.top().setValorChars(offsetRes, res_char);
						}else{
							offsetOp1 = generateOffsetChar(operando1, genDT1);
							op1_char = memStack.top().getValorChars(offsetOp1);							
							res_char = op1_char;
							offsetRes = generateOffsetChar(resultado, generateDataType(resultado));
							
							memStack.top().setValorChars(offsetRes, res_char);
						}
						break;
				}
				break;
			case 7:																			//<>
				tipo_dato1 = getDataType(operando1);
				tipo_dato2 = getDataType(operando2);
				tipo_resultado = getDataType(resultado);
				switch(tipo_dato1){
					case INTEGER:
						//1 cte_int <> cte_int
						if(genDT1 == CTE_INT && genDT2 == CTE_INT){ 
							op1_int = atoi(getConstantValue(operando1).c_str());
							op2_int = atoi(getConstantValue(operando2).c_str());
							if(op1_int != op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
						//2 cte_int <> cte_float
						else if(genDT1 == CTE_INT && genDT2 == CTE_FLOAT){
							op1_int = atoi(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_int != op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);

						}
						//3 cte_int <> int
						else if(genDT1 == CTE_INT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_int = atoi(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_int != op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//4 cte_int <> float
						else if(genDT1 == CTE_INT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_int = atoi(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_int != op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
						
						}
						//5 int <> cte_int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);	
							op2_int = atoi(getConstantValue(operando2).c_str());						
							if(op1_int != op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							/*
							cout << "Direccion 1: " << operando1 << "\n";
							cout << "Operando 1: " << op1_int << "\n";
							cout << "Direccion 2: " << operando2 << "\n";
							cout << "Operando 2: " << op2_int << "\n";
							cout << "Resultado: " << res_boolean << "\n";
							cout << "Index: " << offsetRes << "\n";
							cout << "Direccion Final: " << resultado << "\n";
							cout << "Valor Guardado: " << memStack.top().getValorBooleans(offsetRes) << "\n";
							*/
						}
						//6 int <> cte_float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_int != op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
						//7 int <> int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_int != op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//8 int <> float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_int != op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);	
							
						
						}
						break;
					case FLOAT:
						//9 cte_float <> cte_int
						if(genDT1 == CTE_FLOAT && genDT2 == CTE_INT){
							op1_float = atof(getConstantValue(operando1).c_str());	
							op2_int = atoi(getConstantValue(operando2).c_str());					
							if(op1_float != op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
						//10 cte_float <> cte_float
						else if(genDT1 == CTE_FLOAT && genDT2 == CTE_FLOAT){
							op1_float = atof(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_float != op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
						//11 cte_float <> int
						else if(genDT1 == CTE_FLOAT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_float != op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
						
						}
						//12 cte_float <> float
						else if(genDT1 == CTE_FLOAT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_float != op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//13 float <> cte_int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_int = atoi(getConstantValue(operando2).c_str());						
							if(op1_float != op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//14 float <> cte_float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_float != op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//15 float <> int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_float != op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//16 float <> float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_float != op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);	
							
						
						}
						break;
					case BOOLEAN:
						//17 cte_bool <> cte_bool
						if(genDT1 == CTE_BOOLEAN && genDT2 == CTE_BOOLEAN){
							op1_string = getConstantValue(operando1);
							op2_string = getConstantValue(operando2);
							if(strcmp(op1_string.c_str(), op2_string.c_str()) != 0)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
							
						}
						//18 cte_bool <> bool
						else if(genDT1 == CTE_BOOLEAN && (genDT2 == BOOLEAN || genDT2 == LOCAL_BOOLEAN || genDT2 == TEMP_BOOLEAN)){
							op1_string = getConstantValue(operando1);
							if(strcmp("true", op1_string.c_str()) == 0)	
								op1_boolean = true;
							else
								op1_boolean = false;
							offsetOp2 = generateOffsetBoolean(operando2, genDT2);
							op2_boolean = memStack.top().getValorBooleans(offsetOp2);
							
							if(op1_boolean != op2_boolean)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
						//19 bool <> cte_bool
						else if((genDT1 == BOOLEAN || genDT1 == LOCAL_BOOLEAN || genDT1 == TEMP_BOOLEAN) && genDT2 == CTE_BOOLEAN){
							offsetOp1 = generateOffsetBoolean(operando1, genDT1);
							op1_boolean = memStack.top().getValorBooleans(offsetOp1);
							op2_string = getConstantValue(operando2);
							if(strcmp("true",op2_string.c_str()) == 0)
								op2_boolean = true;
							else
								op2_boolean = false;
							
							if(op1_boolean != op2_boolean)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//20 bool <> bool
						else if((genDT1 == BOOLEAN || genDT1 == LOCAL_BOOLEAN || genDT1 == TEMP_BOOLEAN) && (genDT2 == BOOLEAN || genDT2 == LOCAL_BOOLEAN || genDT2 == TEMP_BOOLEAN)){
							offsetOp1 = generateOffsetBoolean(operando1, genDT1);
							op1_boolean = memStack.top().getValorBooleans(offsetOp1);
							offsetOp2 = generateOffsetBoolean(operando2, genDT2);
							op2_boolean = memStack.top().getValorBooleans(offsetOp2);
							
							if(op1_boolean != op2_boolean)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
				}
				break;
			case 8:																			//==
				tipo_dato1 = getDataType(operando1);
				tipo_dato2 = getDataType(operando2);
				tipo_resultado = getDataType(resultado);
				switch(tipo_dato1){
					case INTEGER:
						//1 cte_int == cte_int
						if(genDT1 == CTE_INT && genDT2 == CTE_INT){ 
							op1_int = atoi(getConstantValue(operando1).c_str());
							op2_int = atoi(getConstantValue(operando2).c_str());
							if(op1_int == op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);

						}
						//2 cte_int == cte_float
						else if(genDT1 == CTE_INT && genDT2 == CTE_FLOAT){
							op1_int = atoi(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_int == op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);

						}
						//3 cte_int == int
						else if(genDT1 == CTE_INT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_int = atoi(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_int == op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						}
						//4 cte_int == float
						else if(genDT1 == CTE_INT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_int = atoi(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_int == op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
						
						}
						//5 int == cte_int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);	
							op2_int = atoi(getConstantValue(operando2).c_str());						
							if(op1_int == op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						}
						//6 int == cte_float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_int == op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						}
						//7 int == int
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_int == op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
						//8 int == float
						else if((genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetInt(operando1, genDT1);
							op1_int = memStack.top().getValorEnteros(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_int == op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);	
						
						}
						break;
					case FLOAT:
						//9 cte_float == cte_int
						if(genDT1 == CTE_FLOAT && genDT2 == CTE_INT){
							op1_float = atof(getConstantValue(operando1).c_str());	
							op2_int = atoi(getConstantValue(operando2).c_str());					
							if(op1_float == op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						}
						//10 cte_float == cte_float
						else if(genDT1 == CTE_FLOAT && genDT2 == CTE_FLOAT){
							op1_float = atof(getConstantValue(operando1).c_str());
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_float == op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
						//11 cte_float == int
						else if(genDT1 == CTE_FLOAT && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_float == op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
						//12 cte_float == float
						else if(genDT1 == CTE_FLOAT && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){
							op1_float = atof(getConstantValue(operando1).c_str());
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_float == op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
						//13 float == cte_int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_INT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_int = atoi(getConstantValue(operando2).c_str());						
							if(op1_float == op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
						//14 float == cte_float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && genDT2 == CTE_FLOAT){
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);	
							op2_float = atof(getConstantValue(operando2).c_str());						
							if(op1_float == op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
							
						}
						//15 float == int
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == INTEGER || genDT2 == LOCAL_INT || genDT2 == TEMP_INT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetInt(operando2, genDT2);
							op2_int = memStack.top().getValorEnteros(offsetOp2);						
							if(op1_float == op2_int)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
						
						}
						//16 float == float
						else if((genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT) && (genDT2 == FLOAT || genDT2 == LOCAL_FLOAT || genDT2 == TEMP_FLOAT)){ 
							offsetOp1 = generateOffsetFloat(operando1, genDT1);
							op1_float = memStack.top().getValorFlotantes(offsetOp1);
							offsetOp2 = generateOffsetFloat(operando2, genDT2);
							op2_float = memStack.top().getValorFlotantes(offsetOp2);						
							if(op1_float == op2_float)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);	
							
							
						}
						break;
					case BOOLEAN:
						//17 cte_bool == cte_bool
						if(genDT1 == CTE_BOOLEAN && genDT2 == CTE_BOOLEAN){
							op1_string = getConstantValue(operando1);
							op2_string = getConstantValue(operando2);
							if(strcmp(op1_string.c_str(), op2_string.c_str()) == 0)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							

							
						}
						//18 cte_bool == bool
						else if(genDT1 == CTE_BOOLEAN && (genDT2 == BOOLEAN || genDT2 == LOCAL_BOOLEAN || genDT2 == TEMP_BOOLEAN)){
							op1_string = getConstantValue(operando1);
							if(strcmp("true", op1_string.c_str()) == 0)	
								op1_boolean = true;
							else
								op1_boolean = false;
							offsetOp2 = generateOffsetBoolean(operando2, genDT2);
							op2_boolean = memStack.top().getValorBooleans(offsetOp2);
							
							if(op1_boolean == op2_boolean)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
							
						}
						//19 bool == cte_bool
						else if((genDT1 == BOOLEAN || genDT1 == LOCAL_BOOLEAN || genDT1 == TEMP_BOOLEAN) && genDT2 == CTE_BOOLEAN){
							offsetOp1 = generateOffsetBoolean(operando1, genDT1);
							op1_boolean = memStack.top().getValorBooleans(offsetOp1);
							op2_string = getConstantValue(operando2);
							if(strcmp("true",op2_string.c_str()) == 0)
								op2_boolean = true;
							else
								op2_boolean = false;
							
							if(op1_boolean == op2_boolean)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
							
						}
						//20 bool == bool
						else if((genDT1 == BOOLEAN || genDT1 == LOCAL_BOOLEAN || genDT1 == TEMP_BOOLEAN) && (genDT2 == BOOLEAN || genDT2 == LOCAL_BOOLEAN || genDT2 == TEMP_BOOLEAN)){
							offsetOp1 = generateOffsetBoolean(operando1, genDT1);
							op1_boolean = memStack.top().getValorBooleans(offsetOp1);
							offsetOp2 = generateOffsetBoolean(operando2, genDT2);
							op2_boolean = memStack.top().getValorBooleans(offsetOp2);
							
							if(op1_boolean == op2_boolean)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						
						}
					}
				break;
			case 9:																			//&&
				tipo_dato1 = getDataType(operando1);
				tipo_dato2 = getDataType(operando2);
				tipo_resultado = getDataType(resultado);
				switch(tipo_dato1){
					case BOOLEAN:
						//17 cte_bool && cte_bool
						if(genDT1 == CTE_BOOLEAN && genDT2 == CTE_BOOLEAN){
							op1_string = getConstantValue(operando1);
							op2_string = getConstantValue(operando2);
							if(strcmp(op1_string.c_str(), op2_string.c_str()) == 0){
								if(strcmp(op1_string.c_str(), "true") == 0)
									res_boolean = true;
							}
							else
								res_boolean = false;
								
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						}
						//18 cte_bool && bool
						else if(genDT1 == CTE_BOOLEAN && (genDT2 == BOOLEAN || genDT2 == LOCAL_BOOLEAN || genDT2 == TEMP_BOOLEAN)){
							op1_string = getConstantValue(operando1);
							if(strcmp("true", op1_string.c_str()) == 0)	
								op1_boolean = true;
							else
								op1_boolean = false;
							offsetOp2 = generateOffsetBoolean(operando2, genDT2);
							op2_boolean = memStack.top().getValorBooleans(offsetOp2);
							
							if(op1_boolean && op2_boolean)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
														
						}
						//19 bool == cte_bool
						else if((genDT1 == BOOLEAN || genDT1 == LOCAL_BOOLEAN || genDT1 == TEMP_BOOLEAN) && genDT2 == CTE_BOOLEAN){
							offsetOp1 = generateOffsetBoolean(operando1, genDT1);
							op1_boolean = memStack.top().getValorBooleans(offsetOp1);
							op2_string = getConstantValue(operando2);
							if(strcmp("true",op2_string.c_str()) == 0)
								op2_boolean = true;
							else
								op2_boolean = false;
							
							if(op1_boolean && op2_boolean)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
														
						}
						//20 bool == bool
						else if((genDT1 == BOOLEAN || genDT1 == LOCAL_BOOLEAN || genDT1 == TEMP_BOOLEAN) && (genDT2 == BOOLEAN || genDT2 == LOCAL_BOOLEAN || genDT2 == TEMP_BOOLEAN)){
							offsetOp1 = generateOffsetBoolean(operando1, genDT1);
							op1_boolean = memStack.top().getValorBooleans(offsetOp1);
							offsetOp2 = generateOffsetBoolean(operando2, genDT2);
							op2_boolean = memStack.top().getValorBooleans(offsetOp2);
							
							
							
							if(op1_boolean && op2_boolean)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
													
						}
					}
				break;
			case 10:																		//||
				tipo_dato1 = getDataType(operando1);
				tipo_dato2 = getDataType(operando2);
				tipo_resultado = getDataType(resultado);
				switch(tipo_dato1){
					case BOOLEAN:
						//17 cte_bool && cte_bool
						if(genDT1 == CTE_BOOLEAN && genDT2 == CTE_BOOLEAN){
							op1_string = getConstantValue(operando1);
							op2_string = getConstantValue(operando2);
							if((strcmp(op1_string.c_str(), "true") == 0) || (strcmp(op2_string.c_str(), "true") == 0)){
								res_boolean = true;
							}else{
								res_boolean = false;
							}
								
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
							
						}
						//18 cte_bool && bool
						else if(genDT1 == CTE_BOOLEAN && (genDT2 == BOOLEAN || genDT2 == LOCAL_BOOLEAN || genDT2 == TEMP_BOOLEAN)){
							op1_string = getConstantValue(operando1);
							if(strcmp("true", op1_string.c_str()) == 0)	
								op1_boolean = true;
							else
								op1_boolean = false;
							offsetOp2 = generateOffsetBoolean(operando2, genDT2);
							op2_boolean = memStack.top().getValorBooleans(offsetOp2);
							
							if(op1_boolean || op2_boolean)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
														
						}
						//19 bool == cte_bool
						else if((genDT1 == BOOLEAN || genDT1 == LOCAL_BOOLEAN || genDT1 == TEMP_BOOLEAN) && genDT2 == CTE_BOOLEAN){
							offsetOp1 = generateOffsetBoolean(operando1, genDT1);
							op1_boolean = memStack.top().getValorBooleans(offsetOp1);
							op2_string = getConstantValue(operando2);
							if(strcmp("true",op2_string.c_str()) == 0)
								op2_boolean = true;
							else
								op2_boolean = false;
							
							if(op1_boolean || op2_boolean)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
														
						}
						//20 bool == bool
						else if((genDT1 == BOOLEAN || genDT1 == LOCAL_BOOLEAN || genDT1 == TEMP_BOOLEAN) && (genDT2 == BOOLEAN || genDT2 == LOCAL_BOOLEAN || genDT2 == TEMP_BOOLEAN)){
							offsetOp1 = generateOffsetBoolean(operando1, genDT1);
							op1_boolean = memStack.top().getValorBooleans(offsetOp1);
							offsetOp2 = generateOffsetBoolean(operando2, genDT2);
							op2_boolean = memStack.top().getValorBooleans(offsetOp2);
							
							
							
							if(op1_boolean || op2_boolean)						
								res_boolean = true;
							else
								res_boolean = false;
							offsetRes = generateOffsetBoolean(resultado, generateDataType(resultado));
							
							memStack.top().setValorBooleans(offsetRes, res_boolean);
													
						}
					}
				break;
			case GOTO:																		//GOTO
				main_index = resultado - 2;
				break;
			case GOTOF:																		//GOTOF
				offsetOp1 = generateOffsetBoolean(operando1, genDT1);
				op1_boolean = memStack.top().getValorBooleans(offsetOp1);
				if(op1_boolean == 0)
					main_index = resultado - 2;
				break;
			case PRINT:																		//PRINT PROBADA
				tipo_resultado = getDataType(resultado);
				switch(tipo_resultado){
					case INTEGER:
						if(generateDataType(resultado) == CTE_INT){
							op1_int = atoi(getConstantValue(resultado).c_str());							
							res_int = op1_int;
							
							cout << res_int;
						}else{
							offsetOp1 = generateOffsetInt(resultado, generateDataType(resultado));
							op1_int = memStack.top().getValorEnteros(offsetOp1);							
							res_int = op1_int;
							
							cout << res_int;
						}
					break;
					case FLOAT:
						if(generateDataType(resultado) == CTE_FLOAT){
							op1_float = atof(getConstantValue(resultado).c_str());							
							res_float = op1_float;
							
							cout << res_float;
						}else{
							offsetOp1 = generateOffsetFloat(resultado, generateDataType(resultado));
							op1_float = memStack.top().getValorFlotantes(offsetOp1);							
							res_float = op1_float;
	
							cout << res_float;
						}
					break;
					case STRING:
						if(generateDataType(resultado) == CTE_STRING){
							op1_string = getConstantValue(resultado);
							res_string = op1_string;
							
							cout << res_string;
						}else{
							offsetOp1 = generateOffsetString(resultado, generateDataType(resultado));
							op1_string = memStack.top().getValorStrings(offsetOp1);							
							res_string = op1_string;
							
							cout << res_string;
						}
					break;
					case BOOLEAN:
						if(generateDataType(resultado) == CTE_BOOLEAN){
							if(strcmp("true",getConstantValue(resultado).c_str()) == 0)
								op1_string = "true";
							else
								op1_string = "false";
						
							res_string = op1_string;
							
							cout << res_string;
						}else{
							offsetOp1 = generateOffsetBoolean(resultado, generateDataType(resultado));
							op1_boolean = memStack.top().getValorBooleans(offsetOp1);
							if(op1_boolean == 1)
								res_string = "true";
							else
								res_string = "false";

							cout << res_string;
						}
						break;
					case CHAR:
						if(generateDataType(resultado) == CTE_CHAR){
							op1_char = getConstantValue(resultado)[1];	
							res_char = op1_char;
							
							cout << res_char;
						}else{
							offsetOp1 = generateOffsetChar(resultado, generateDataType(resultado));
							op1_char = memStack.top().getValorChars(offsetOp1);							
							res_char = op1_char;
							
							cout << res_char;
						}
						break;
				}
				break;
			case READ:
				tipo = generateDataType(resultado);
				if(tipo == TEMP_INT){
					cin >> read_int;
					memStack.top().setValorEnteros(generateOffsetInt(resultado, generateDataType(resultado)), read_int);
				}else if(tipo == TEMP_FLOAT){
					cin >> read_float;
					memStack.top().setValorFlotantes(generateOffsetFloat(resultado, generateDataType(resultado)), read_float);
				}else if(tipo == TEMP_STRING){
					cin >> read_string;
					memStack.top().setValorStrings(generateOffsetString(resultado, generateDataType(resultado)), read_string);
				}else if(tipo == TEMP_BOOLEAN){
					cin >> read_boolean;
					memStack.top().setValorBooleans(generateOffsetBoolean(resultado, generateDataType(resultado)), read_boolean);
				}else if(tipo == TEMP_CHAR){
					cin >> read_char;
					memStack.top().setValorChars(generateOffsetChar(resultado, generateDataType(resultado)), read_char);
				}
				break;
			case ERA:																		//ERA
				//Activation record
				activation_record(resultado);				
				break;
			case GOSUB:																		//GOSUB
				return_index.push(main_index);
				main_index = proc[resultado].dirInitial;
				break;
			case PARAM:																		//PARAM
				asignacion_parametros(operando1, resultado);
				break;
			case VER:																		//VER
				if(genDT1 == CTE_INT){
					op1_int = atoi(getConstantValue(operando1).c_str());							
				}else if(genDT1 == INTEGER || genDT1 == LOCAL_INT || genDT1 == TEMP_INT){
					offsetOp1 = generateOffsetInt(operando1, genDT1);
					op1_int = memStack.top().getValorEnteros(offsetOp1);							
				}else if(genDT1 == CTE_FLOAT){
					op1_float = atof(getConstantValue(operando1).c_str());		
					op1_int = (int)op1_float;					
				}else if(genDT1 == FLOAT || genDT1 == LOCAL_FLOAT || genDT1 == TEMP_FLOAT){
					offsetOp1 = generateOffsetFloat(operando1, genDT1);
					op1_float = memStack.top().getValorFlotantes(offsetOp1);							
					op1_int = (int)op1_float;
				}
				
				op2_int = resultado;

				if(op1_int >= op2_int){
					cout << "Error: ArrayOutOfBounds \n";
					exit (EXIT_FAILURE);
				}
				break;
			case INIPROC:																	//INIPROC
				//Do nothing
				break;
			case RET:
				main_index = return_index.top();
				return_index.pop();
				memStack.pop();
				break;
			case SPECIALSUM:																//Addition of dirVir
				if(genDT2 == CTE_INT){
					op2_int = atoi(getConstantValue(operando2).c_str());							
				}else{
					offsetOp2 = generateOffsetInt(operando2, genDT2);
					op2_int = memStack.top().getValorEnteros(offsetOp2);							
				}
				apuntadores[resultado - BASE_POINTERS] = operando1 + op2_int;

				break;
			case MIN:
				minfunc(operando1, operando2, resultado);
			break;
			case MAX:
				maxfunc(operando1, operando2, resultado);
			break;
			case POW:
				powfunc(operando1, operando2, resultado);
			break;
			case REMAINDER:
				remainderfunc(operando1, operando2, resultado);
			break;
			case FLOOR:
				floorfunc(operando1, resultado);
			break;
			case CEILING:
				ceilingfunc(operando1, resultado);
			break;
			case RANDOM:
				randomfunc(resultado);
			break;
			case SQRT:
				sqrtfunc(operando1, resultado);
			break;
		}
		main_index++;
	}
}

int main(int argc, char *argv[]) {
	int proc_index;
	
	readFile();
	
	run();
	
	cout << "\n";

}