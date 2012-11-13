#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
		
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
	int contEnteroLocales = 0;
	int contFlotanteLocales = 0;
	int contStringLocales = 0;
	int contBooleanoLocales = 0;
	int contCharLocales = 0;
	int contEnteroTemps = 0;
	int contFlotanteTemps = 0;
	int contStringTemps = 0;
	int contBooleanoTemps = 0;
	int contCharTemps = 0;
	int contEnteroGlobales = 0;
	int contFlotanteGlobales = 0;
	int contStringGlobales = 0;
	int contBooleanoGlobales = 0;
	int contCharGlobales = 0;
	//matriz de constantes
	string *arrConst;
	int tamanoConst = 0;
	int *arrConstDirVir;
	int primerValorConst = 0;
	int numConst = 0;
	//cuadruplos
	int tamanoCuadruplos = 0;
	int primerValorCuadruplo = 0;
	
	string line;
	ifstream myfile ("/Users/Verduzco/Stuff/TEC/Semestre/Compiladores/trex/MV/test.obj");
	
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
				pch = strtok (str," ,.-");
				while (pch != NULL){
					switch (i) {
						case 0 : //nombreFuncion
							nombreFuncion[numFuncion] = pch;
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
							if(numFuncion == 0){
								contEnteroGlobales = atoi(pch);
								globalEntero = new int[contEnteroGlobales];
							}
							else
								contEnteroLocales += atoi(pch);
							i++;
							break;
						case 4 : //flotantes
							if(numFuncion == 0){
								contFlotanteGlobales = atoi(pch);
								globalFlotante = new int[contFlotanteGlobales];
							}
							else
								contFlotanteLocales += atoi(pch);
							i++;
							break;
						case 5 : //strings
							if(numFuncion == 0){
								contStringGlobales = atoi(pch);
								globalString = new int[contStringGlobales];
							}
							else
								contStringLocales += atoi(pch);
							i++;
							break;
						case 6 : //booleanos
							if(numFuncion == 0){
								contBooleanoGlobales = atoi(pch);
								globalBooleano = new int[contBooleanoGlobales];
							}
							else
								contBooleanoLocales += atoi(pch);
							i++;
							break;
						case 7 : //chars
							if(numFuncion == 0){
								contCharGlobales = atoi(pch);
								globalChar = new int[contCharGlobales];
							}
							else
								contCharLocales += atoi(pch);
							i++;
							break;
						case 8 : //Enteros temps
							contEnteroTemps += atoi(pch);
							i++;
							break;
						case 9 : //flotantes temps
							contFlotanteTemps += atoi(pch);
							i++;
							break;
						case 10	: //string temps
							contStringTemps += atoi(pch);
							i++;
							break;
						case 11 : //booleanos temps
							contBooleanoTemps += atoi(pch);
							i++;
							break;
						case 12 : //char temps
							contCharTemps += atoi(pch);
							i++;
							break;
					}
					pch = strtok (NULL, ",");
				}
				i = 0;
				numFuncion++;
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
					tamanoCuadruplos = atoi(str);
					primerValorCuadruplo++;
					cout << tamanoCuadruplos << "\n";
				}
				else{
					pch = strtok (str," ,-");
					while (pch != NULL){
						switch (i) {
						case 0 : 
							cout << atoi(pch) << "\n";
							i++;
							break;
						case 1 : 
							cout << atoi(pch) << "\n";
							i++;
							break;
						case 2 : 
							cout << atoi(pch) << "\n";
							i++;
							break;
						case 3 : //enteros
							cout << atoi(pch) << "\n";
							i++;
							break;
					}
					pch = strtok (NULL, ",");
				}
					i = 0;
					numFuncion++;
				}
			}
		}
		myfile.close();
	}else cout << "Unable to open file";
	
	localEntero = new int[contEnteroLocales];
	localFlotante = new int[contFlotanteLocales];
	localString = new int[contStringLocales];
	localBooleano = new int[contBooleanoLocales];
	localChar = new int[contCharLocales];
	tempEntero = new int[contEnteroTemps];
	tempFlotante = new int[contFlotanteTemps];
	tempString = new int[contStringTemps];
	tempBooleano = new int[contBooleanoTemps];
	tempChar = new int[contCharTemps];
	
	for(int i = 0; i < tamanoConst; i++){
		cout << "(" << arrConst[i] << ", " << arrConstDirVir[i] << ")\n";
	}
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
}