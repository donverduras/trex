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
		
		Memoria(int id_name, int tamanoEnteros, int tamanoFlotantes, int tamanoStrings, int tamanoBooleans, int tamanoChars){
			id = id_name;
			enteros = new int[tamanoEnteros];
			flotantes = new float[tamanoFlotantes];
			strings = new string[tamanoStrings];
			booleans = new bool[tamanoBooleans];
			chars = new char[tamanoChars];
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

struct Quadruple{
		int operador;
		int operando1;
		int operando2;
		int resultado;
	};
		
char *str;
char *pch;
int i = 0;
int numFuncion = 0;
int contPorciento = 0;
string nombreFuncion[20];//0
int cuadruploInicial[20]; //1
int numParam[20]; //2
int *localEntero; //3
int *localFlotante; //4
int *localString; //5
int *localBooleano; //6
int *localChar; //7
int *tempEntero; //8
int *tempFlotante; //9
int *tempString; //10
int *tempBooleano; //11 
int *tempChar; //12
int *globalEntero;
int *globalFlotante;
int *globalString;
int *globalBooleano;
int *globalChar;
//Contadores de variables para generar arreglos y llamar tamaño
int valorEntero = 0;
int valorFlotante = 0;
int valorString = 0;
int valorBoolean = 0;
int valorChar = 0;
int valorEnteroTemps = 0;
int valorFlotanteTemps = 0;
int valorStringTemps = 0;
int valorBooleanTemps = 0;
int valorCharTemps = 0;
//matriz de constantes
string *arrConst;
int tamanoConst = 0;
int *arrConstDirVir;
int primerValorConst = 0;
int numConst = 0;
//Cuadruplos
Quadruple *listOfQuads;
int tamanoCuadruplos = 0;
int primerValorCuadruplo = 0;
int numQuads = 0;
//Arreglo de memorias
Memoria *arrLocal;
Memoria *arrTemp;
int primerValorFunc = 0;
int tamanoFunc;
//Index principal
int main_index = 0;

string line;
//ifstream myfile ("/Users/Verduzco/Stuff/TEC/Semestre/Compiladores/trex/MV/test.obj");
ifstream myfile ("/Users/ssalazars/Developer/trex/MV/test.obj");

string getValor(int dirVir){
	cout << "La direccion a buscar es: " << dirVir << "\n";
	//Constante
	if(dirVir >= 76000 && dirVir <= 99999){
		cout << "Si es una constante! \n";
		for(int i=0; i<tamanoConst; i++){
			if(arrConstDirVir[i] == dirVir){
				cout << "El valor de dicha direccion es: " << arrConst[i] << "\n";
				return arrConst[i];
			}
		}
	}
}

int main(int argc, char *argv[]) {
	
	if (myfile.is_open()){
		while ( myfile.good()){
			getline (myfile,line);
			str = &line[0];
			
			if(strcmp(str, "%%") == 0){
				getline(myfile, line);
				str = &line[0];
				contPorciento++;
			}
			if(contPorciento == 0){
				if(primerValorFunc == 0){
					tamanoFunc = atoi(str);
					primerValorFunc++;
					arrLocal = new Memoria[tamanoFunc];
					arrTemp = new Memoria[tamanoFunc];
					cout << "Declare ambos arreglos de memorias \n";
				}
				else{
					pch = strtok (str," ,.-");
					while (pch != NULL){
						switch (i) {
							case 0 : //nombreFuncion
								nombreFuncion[numFuncion] = pch;
								arrLocal[numFuncion].setId(numFuncion);
								arrTemp[numFuncion].setId(numFuncion);
								i++;
								break;
							case 1 : 
								cuadruploInicial[numFuncion] = atoi(pch);
								i++;
								break;
							case 2 : 
								numParam[numFuncion] = atoi(pch);
								i++;
								break;
							case 3 : //enteros
								valorEntero = atoi(pch);
								arrLocal[numFuncion].setEnteros(valorEntero);
								i++;
								break;
							case 4 : //flotantes
								valorFlotante = atoi(pch);
								arrLocal[numFuncion].setFlotantes(valorFlotante);
								i++;
								break;
							case 5 : //strings
								valorString = atoi(pch);
								arrLocal[numFuncion].setStrings(valorString);
								i++;
								break;
							case 6 : //booleanos
								valorBoolean = atoi(pch);
								arrLocal[numFuncion].setBooleans(valorBoolean);
								i++;
								break;
							case 7 : //chars
								valorChar = atoi(pch);
								arrLocal[numFuncion].setChars(valorChar);
								i++;
								break;
							case 8 : //Enteros temps
								valorEnteroTemps = atoi(pch);
								arrTemp[numFuncion].setEnteros(valorEntero);
								i++;
								break;
							case 9 : //flotantes temps
								valorFlotanteTemps = atoi(pch);
								arrTemp[numFuncion].setFlotantes(valorFlotante);
								i++;
								break;
							case 10	: //string temps
								valorStringTemps = atoi(pch);
								arrTemp[numFuncion].setStrings(valorString);
								i++;
								break;
							case 11 : //booleanos temps
								valorBooleanTemps = atoi(pch);
								arrTemp[numFuncion].setBooleans(valorBoolean);
								i++;
								break;
							case 12 : //char temps
								valorCharTemps = atoi(pch);
								arrTemp[numFuncion].setChars(valorChar);
								i++;
								break;
						}
						pch = strtok (NULL, ",");
					}
					//Activacion de memoria
					//Memoria local(numFuncion, valorEntero, valorFlotante, valorString, valorBoolean, valorChar);
					//Memoria temporal(numFuncion, valorEnteroTemps, valorFlotanteTemps, valorStringTemps, valorBooleanTemps, valorCharTemps);
					//cout << "Memoria Local: " << local.getId() << "\n";
					//cout << "Memoria Temp: " << temporal.getId() << "\n";
					cout << "Id Local: " << arrLocal[1].getId() << "\n";
					cout << "Id Temp: " << arrLocal[1].getId() << "\n";
					i = 0;
					numFuncion++;
				}
			}
			else if(contPorciento == 1){
				if(primerValorConst == 0){
					tamanoConst = atoi(str);
					primerValorConst++;
					arrConst = new string[tamanoConst];
					arrConstDirVir = new int[tamanoConst];
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
					numConst++;
				}
			}
			else if(contPorciento == 2){
				if(primerValorCuadruplo == 0){
					//Declaracion del arreglo que obtendra cuadruplos del tamano especificado
					tamanoCuadruplos = atoi(str);
					cout << "Tamano de arreglo de cuadruplos: " << tamanoCuadruplos << "\n";
					primerValorCuadruplo++;
					listOfQuads = new Quadruple[tamanoCuadruplos];
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
					numFuncion++;
					numQuads++;
				}
			}
		}
		myfile.close();
	}else cout << "Unable to open file";

	
	cout << "Tabla de Constantes: \n";
	for(int i = 0; i < tamanoConst; i++){
		cout << "(" << arrConst[i] << ", " << arrConstDirVir[i] << ")\n";
	}
	
	cout << "Lista de cuadruplos: \n";
	cout << "( " << listOfQuads[0].operador << ", " << listOfQuads[0].operando1 << ", " << listOfQuads[0].operando2 << ", " << listOfQuads[0].resultado << " )" << "\n";
	/*
	cout << "contEnteroGlobales = " << contEnteroGlobales << "\n";
	cout << "contFlotanteGlobales = " << contFlotanteGlobales << "\n";
	cout << "contStringGlobales = " << contStringGlobales << "\n";
	cout << "contBooleanoGlobales = " << contBooleanoGlobales << "\n";
	cout << "contCharGlobales = " << contCharGlobales << "\n";
	cout << "\n";
	cout << "contEnteroLocales = " << contEnteroLocales << "\n";
	cout << "contFlotanteLocales = " << contFlotanteLocales << "\n";
	cout << "contStringLocales = " << contStringLocales << "\n";
	cout << "contBooleanoLocales = " << contBooleanoLocales << "\n";
	cout << "contCharLocales = " << contCharLocales << "\n";
	cout << "\n";
	cout << "contEnteroTemps = " << contEnteroTemps << "\n";
	cout << "contFlotanteTemps = " << contFlotanteTemps << "\n";
	cout << "contStringTemps = " << contStringTemps << "\n";
	cout << "contBooleanoTemps = " << contBooleanoTemps << "\n";
	cout << "contCharTemps = " << contCharTemps << "\n";
	*/
	
	while(main_index != tamanoCuadruplos){
		if(listOfQuads[main_index].operador == 6){
			const char* string_aux;
			
			string operando1 = getValor(listOfQuads[main_index].operando1);
			string_aux = operando1.c_str();
			cout << "El valor del operando1 en la asignacion es: " << operando1 << "\n";
			//Suponiendo que es global
			arrLocal[0].setValorEnteros(0, atoi(string_aux));
			cout << "El valor guardado es: " << arrLocal[0].getValorEnteros(0) << "\n";
				
			main_index++;
		}
	}
	
	//Para las variables locales si tengo que arreglar el problema de tirar las variables, porque si no, la primer variable local entera seria 26005 por ejemplo, y no 26000 como deberia de ser, y asi no jalaria la funcion que se planea
}