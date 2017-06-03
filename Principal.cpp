#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Main.h"
#include "Clase.h"
#include "Atributo.h"

using namespace std;

//Funcion menu
int menu();

int main(){
	bool salir=false;
	while (!salir) {
		switch (menu()) {
			case 1:{

				break;
			}
			case 2:{

				break;
			}
			case 3:{

				break;
			}
			case 4:{

				break;
			}
			case 5:{
				salir=true;
				break;
			}
			return 0;
		}//Fin swtich
	}//Fin While
}//Fin Main

int menu() {
	int opcion;
	bool valido = false;
	do {
		cout << "-----MENU-----" << endl
		<< "1.- Case 1" << endl
		<< "2.- Case 2" << endl
		<< "3.- Case 3" << endl
		<< "4.- Case 4" << endl
		<< "5.- Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin>>opcion;
		if (opcion > 0 && opcion <= 5)
			valido = true;
		else {
			cout << "Opcion no valida, intente de nuevo..." << endl;
		}

	} while (!valido);
	return opcion;
}