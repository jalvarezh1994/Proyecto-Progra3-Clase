#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "Main.h"
#include "Clase.h"
#include "Atributo.h"

using namespace std;

//Funcion menu
int menu();
//Funcion para crear el archivo
void crearArchivo();

int main(){
	vector<Clase>clases;
	bool salir=false;
	while (!salir) {
		switch (menu()) {
			case 1:{
				string nombre;
				cout<<"Ingrese nombre de la clase: "<<endl;
				cin>>nombre;
				Clase clase(nombre);
				clases.push_back(clase);
				cout<<"Clase agregada exitosamente!\n\n";
				break;
			}
			case 2:{
				for (int i = 0; i < clases.size(); ++i)
				{
					cout<<i<<".- "<<clases[i].getNombre()<<endl;
				}
				int pos;
				cout<<"Seleccione la clase a la cual le desea agregar el atributo: "<<endl;
				cin>>pos;
				string tipo="";
				string nombre="";
				string visibilidad="";
				cout<<"Ingrese el tipo de atributo[int,float,double,string,bool]: "<<endl;
				cin>>tipo;
				cout<<"Ingrese el nombre del atributo: "<<endl;
				cin>>nombre;
				//cout<<"Indique el tipo de visibilidad del atributo: "<<endl;
				//cin>>visibilidad;
				Atributo atributo(tipo,nombre);
				clases[pos].setAtri(atributo);
				break;
			}
			case 3:{
				for (int i = 0; i < clases.size(); i++)
				{
					cout<<i<<".- "<<clases[i].getNombre()<<endl;
					cout<<"    Atributos: "<<endl;
					for (int j = 0; j < clases[i].getAtri().size(); j++)
					{
						cout<<"    "<<j<<".- "<<clases[i].getAtri()[j].getNombre()<<endl;
					}
					cout<<"\n";
				}
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
		<< "1.- Agregar clase" << endl
		<< "2.- Agregar atributo a clase" << endl
		<< "3.- Ver" << endl
		<< "4.- Generar archivos" << endl
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

void crearArchivo(){
	ofstream archivo;
	string filename,contenido;

	cout<<"Ingrese el nombre del archivo: ";
	getline(cin,filename);

	archivo.open(filename.c_str(),ios::out);//Abriendo el archivo

	if(archivo.fail()){
		cout<<"Error";
		exit(1);
	}

	cout<<"Ingrese el contenido que desea ingresar al archivo: "<<endl;
	getline(cin,contenido);

	archivo<<contenido;
	
	archivo.close();
}




