#include "Atributo.h"

Atributo::Atributo(string tipo,string nombre,string visibilidad){
	this->tipo=tipo;
	this->nombre=nombre;
	this->visibilidad=visibilidad;
}

Atributo::Atributo(){

}

void Atributo::setTipo(string tipo){
	this-> tipo=tipo;
}

string Atributo::getTipo(){
	return tipo;
}

void Atributo::setNombre(string nombre){
	this-> nombre=nombre;
}

string Atributo::getNombre(){
	return nombre;
}

void Atributo::setVisibilidad(string visibilidad){
	this-> visibilidad=visibilidad;
}

string Atributo::getVisibilidad(){
	return visibilidad;
}
