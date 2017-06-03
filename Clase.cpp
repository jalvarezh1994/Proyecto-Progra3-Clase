#include "Clase.h"

Clase::Clase(string nombre){
	this->nombre=nombre;
}

Clase::Clase(){

}

void Clase::setNombre(string nombre){
	this-> nombre=nombre;
}

string Clase::getNombre(){
	return nombre;
}

vector<Atributo> Clase::getAtri() {
	return atri;
}

void Clase::setAtri(Atributo atri) {
	this-> atri.push_back(atri);
}