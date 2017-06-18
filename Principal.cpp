#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include "C_Main.h"
#include "Clase.h"
#include "Atributo.h"

using namespace std;

//Funcion menu
int menu();
//Funcion para crear el archivo
void crearMain(C_Main*);
//Funcion para crear el archivo
void crearClase(Clase*);

int main(){
	vector<Clase*>clases;
	bool salir=false;
	while (!salir) {
		switch (menu()) {
			case 1:{
				string nombre;
				cout<<"Ingrese nombre de la clase: "<<endl;
				cin>>nombre;
				Clase* clase=new Clase(nombre);
				clases.push_back(clase);
				cout<<"Clase agregada exitosamente!\n\n";
				break;
			}
			case 2:{
				for (int i = 0; i < clases.size(); ++i)
				{
					cout<<i<<".- "<<clases[i]->getNombre()<<endl;
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
				clases[pos]->setAtri(atributo);
				break;
			}
			case 3:{
				for (int i = 0; i < clases.size(); i++)
				{
					cout<<i<<".- "<<clases[i]->getNombre()<<endl;
					cout<<"    Atributos: "<<endl;
					for (int j = 0; j < clases[i]->getAtri().size(); j++)
					{
						cout<<"    "<<j<<".- "<<clases[i]->getAtri()[j].getTipo()<<" "<<clases[i]->getAtri()[j].getNombre()<<endl;
					}
					cout<<"\n";
				}
				break;
			}
			case 4:{
				//Escribir main
				C_Main* m = new C_Main();
				m->setClases(clases);
				crearMain(m);
				//Escribir clases
				for (int i = 0; i < clases.size(); i++)
				{
					Clase* c = new Clase(clases[i]->getNombre());
					crearClase(c);
				}
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


void crearMain(C_Main* m){
	ofstream archivo;
	string ruta="Nombre.txt";
	stringstream ss;
	ss<<"El_Main.cpp";
	ruta=ss.str();
	archivo.open(ruta.c_str());
	archivo<<m->getCpp()<<endl;		
	archivo.close();
}

void crearClase(Clase* c){
	//Header
	ofstream archivo;
	string ruta="Nombre.txt";
	stringstream ss;
	ss<<c->getNombre()+".cpp";
	ruta=ss.str();
	archivo.open(ruta.c_str());
	archivo<<c->getHeader()<<endl;
	//CPP
	ofstream archivo2;
	string ruta2="Nombre.txt";
	stringstream ss2;
	ss2<<c->getNombre()+".h";
	ruta2=ss2.str();
	archivo2.open(ruta2.c_str());
	archivo2<<c->getCpp()<<endl;
	archivo2.close();
}
