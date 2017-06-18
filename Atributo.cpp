#include "Atributo.h"

Atributo::Atributo(string tipo,string nombre){
	this->tipo=tipo;
	this->nombre=nombre;
	//this->visibilidad=visibilidad;
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

string Atributo::GetterH() {
	return tipo + " get" + nombre + "();\n";
}

string Atributo::SetterH() {
	return  "void set" + nombre + "(" + tipo + ");\n";
}

string Atributo::GetterCPP(string clase) {
	return tipo + " " + clase + "::get" + nombre + "(){\n"
	+ "   return " + nombre + ";\n"
	+ "}\n";
}

string Atributo::SetterCPP(string clase) {
	return "void " + clase + "::set" + nombre + "(" + tipo + " " + nombre + "){\n"
	+ "   this-> " + nombre + "=" + nombre + ";\n"
	+ "}\n";
}

/*
void Atributo::setVisibilidad(string visibilidad){
	this-> visibilidad=visibilidad;
}

string Atributo::getVisibilidad(){
	return visibilidad;
}*/
