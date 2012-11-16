#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

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

struct VarCont{
	int integers;
	int flotantes;
	int estrings;
	int booleans;
	int chars;
};

struct Quadruple{
		int operador;
		int operando1;
		int operando2;
		int resultado;
	};
	
struct Procedure{
	string name;
	int dirInitial;					//Cuadruplo inicial
	int numParams;
	VarCont locals;
	VarCont temps;
};

enum tipos { G_INT = 0,		G_FLOAT = 1,	G_STRING = 2,	G_BOOLEAN = 3,	G_CHAR = 4,
			 L_INT = 5,		L_FLOAT = 6,	L_STRINL = 7,	L_BOOLEAN = 8,	L_CHAR = 9,
			 T_INT = 10,	T_FLOAT = 11,	T_STRINT = 12,	T_BOOLEAN = 13,	T_CHAR = 14,
			 C_INT = 15,	C_FLOAT = 16,	C_STRINC = 17,	C_BOOLEAN = 18,	C_CHAR =19,
			 P = 20 };

enum symbols {	BASE_GLOBAL_INT = 1000,	BASE_GLOBAL_FLOAT = 6000,	BASE_GLOBAL_STRING = 11000,	BASE_GLOBAL_BOOLEAN = 16000,	BASE_GLOBAL_CHAR = 21000,
				BASE_LOCAL_INT = 1000,	BASE_LOCAL_FLOAT = 6000, 	BASE_LOCAL_STRING = 11000, 	BASE_LOCAL_BOOLEAN = 16000, 	BASE_LOCAL_CHAR = 21000,
				BASE_TEMP_INT = 1000,	BASE_TEMP_FLOAT = 6000, 	BASE_TEMP_STRING = 11000, 	BASE_TEMP_BOOLEAN = 16000, 		BASE_TEMP_CHAR = 21000,
				CONST_INT = 1000,		CONST_FLOAT = 6000, 		CONST_STRING = 11000, 		CONST_BOOLEAN = 16000, 			CONST_CHAR = 21000,
				BASE_POINTERS = 100000, BLOQUE = 5000	};

//Arreglo de memorias
Memoria *arrGlobal;
Memoria *arrGlobalTemp;
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

string getConstantValue(int dirVir){
	for(int i=0; i<tamanoConst; i++){
		if(arrConstDirVir[i] == dirVir){
			return arrConst[i];
		}
	}
}

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

void readFile(){
	ifstream myfile ("/Users/ssalazars/Developer/trex/MV/test.obj");
	string line;
	char *str, *pch;
	int i = 0, contPorciento = 0, primerValor = 0, tamano = 0, numFuncion = 0, numConst = 0, numQuads = 0;
	VarCont *locales;
	VarCont *temporales;
	
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
			
			if(contPorciento == 0){
				if(primerValor == 0){
					tamano = atoi(str);
					sizeOfProc = tamano;
					primerValor++;
					arrGlobal = new Memoria;
					arrGlobalTemp = new Memoria;
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
									arrGlobalTemp->setId(numFuncion);
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
									arrGlobal->setEnteros(atoi(pch));
								}
								i++;
								break;
							case 4 : //flotantes
								locales->flotantes = atoi(pch);
								if(numFuncion == 0){
									arrGlobal->setFlotantes(atoi(pch));
								}
								i++;
								break;
							case 5 : //strings
								locales->estrings = atoi(pch);
								if(numFuncion == 0){
									arrGlobal->setStrings(atoi(pch));
								}
								i++;
								break;
							case 6 : //booleanos
								locales->booleans = atoi(pch);
								if(numFuncion == 0){
									arrGlobal->setBooleans(atoi(pch));
								}
								i++;
								break;
							case 7 : //chars
								locales->chars = atoi(pch);
								if(numFuncion == 0){
									arrGlobal->setChars(atoi(pch));
								}
								i++;
								break;
							case 8 : //Enteros temps
								temporales->integers = atoi(pch);
								if(numFuncion == 0){
									arrGlobalTemp->setEnteros(atoi(pch));
								}
								i++;
								break;
							case 9 : //flotantes temps
								temporales->flotantes = atoi(pch);
								if(numFuncion == 0){
									arrGlobalTemp->setFlotantes(atoi(pch));
								}
								i++;
								break;
							case 10	: //string temps
								temporales->estrings = atoi(pch);
								if(numFuncion == 0){
									arrGlobalTemp->setStrings(atoi(pch));
								}
								i++;
								break;
							case 11 : //booleanos temps
								temporales->booleans = atoi(pch);
								if(numFuncion == 0){
									arrGlobalTemp->setBooleans(atoi(pch));
								}
								i++;
								break;
							case 12 : //char temps
								temporales->chars = atoi(pch);
								if(numFuncion == 0){
									arrGlobalTemp->setChars(atoi(pch));
								}
								i++;
								break;
						}
						pch = strtok (NULL, ",");
					}
					proc[numFuncion].locals = *locales;
					proc[numFuncion].temps = *temporales;
					i = 0;
					
					/*
					cout << "Nombre funcion: " << proc[numFuncion].name << "\n";
					cout << "Cuadruplo inicial: " << proc[numFuncion].dirInitial << "\n";
					cout << "Num params: " << proc[numFuncion].numParams << "\n";
					cout << "Globales enteros: " << proc[numFuncion].locals.integers << "\n";
					cout << "Globales flotantes: " << proc[numFuncion].locals.flotantes << "\n";
					cout << "Globales strings: " << proc[numFuncion].locals.estrings << "\n";
					cout << "Globales booleans: " << proc[numFuncion].locals.booleans << "\n";
					cout << "Globales chars: " << proc[numFuncion].locals.chars << "\n";
					cout << "Temporales enteros: " << proc[numFuncion].temps.integers << "\n";
					cout << "Temporales flotantes: " << proc[numFuncion].temps.flotantes << "\n";
					cout << "Temporales strings: " << proc[numFuncion].temps.estrings << "\n";
					cout << "Temporales boolans: " << proc[numFuncion].temps.booleans << "\n";
					cout << "Temporales chars: " << proc[numFuncion].temps.chars << "\n";
					*/
					
					numFuncion++;
				}
			}else if(contPorciento == 1){
				if(primerValor == 0){
					tamano = atoi(str);
					tamanoConst = tamano;
					primerValor++;
					arrConst = new string[tamano];
					arrConstDirVir = new int[tamano];
				}
				else{
					pch = strtok (str," ,-");
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
						pch = strtok(NULL, " ,.-");
					}
					i = 0;
					
					/*
					cout << "( " << arrConst[numConst] << ", " << arrConstDirVir[numConst] << " ) \n";
					*/
					
					numConst++;
				}
			}else if(contPorciento == 2){
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
					
					/*
					cout << "( " << listOfQuads[numQuads].operador << ", " << listOfQuads[numQuads].operando1 << ", " <<
									listOfQuads[numQuads].operando2 << ", " << listOfQuads[numQuads].resultado << " ) \n";
					*/
					
					numQuads++;
				}
			}
		}
		myfile.close();
	}else cout << "Unable to open file";
}

void run(){
	int tipo_dato1, tipo_dato2, tipo_resultado, index;
	int operador = listOfQuads[main_index].operador;
	int operando1 = listOfQuads[main_index].operando1;
	int operando2 = listOfQuads[main_index].operando2;
	int resultado = listOfQuads[main_index].resultado;
	
	int op1_int, op2_int, res_int;
	
	while(main_index != tamanoCuadruplos){
		switch(operador){
			case 0:																			//+
				cout << "Suma \n";
				tipo_dato1 = operando1 / BLOQUE;
				tipo_dato2 = operando2 / BLOQUE;
				tipo_resultado = resultado / BLOQUE;
				if(tipo_dato1 == C_INT && tipo_dato2 == C_INT){								//Suma de dos enteros
					if(tipo_resultado == G_INT){											//Guardado en casilla entera global
						op1_int = atoi(getConstantValue(operando1).c_str());
						op2_int = atoi(getConstantValue(operando2).c_str());
						res_int = op1_int + op2_int;
						index = resultado - BASE_GLOBAL_INT;
						arrGlobal->setValorEnteros(index, res_int);
						cout << "Operando 1: " << op1_int << "\n";
						cout << "Operando 2: " << op2_int << "\n";
						cout << "Resultado: " << res_int << "\n";
						cout << "Offset: " << index << "\n";
						cout << "El valor almacenado en memoria es: " << arrGlobal->getValorEnteros(index) << "\n";
					}else if(tipo_resultado == L_INT){										//Guardado en casilla entera local
					
					}else if(tipo_resultado == T_INT){										//Guardado en casilla entera temporal
						
					}
				} 
				break;
			case 1:																			//-
				break;
			case 2:																			///
				break;
			case 3:																			//*
				break;
			case 4:																			//<
				break;
			case 5:																			//>
				break;
			case 6:																			//=
				cout << "Asignacion \n";
				break;
			case 7:																			//<>
				break;
			case 8:																			//==
				break;
			case 15:																		//POINTER
				break;
			case 300:																		//PRINT	
				break;
		}
		main_index++;
	}
}

int main(int argc, char *argv[]) {
	int proc_index;
	
	readFile();
	
	run();
}