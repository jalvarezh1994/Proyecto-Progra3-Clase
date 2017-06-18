#ifndef CLASE_H
#define CLASE_H

#include "Atributo.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Clase{
protected:
	string nombre;
	vector<Atributo>atri;
public:
	Clase(string);
	Clase();

	string getNombre();
	void setNombre(string);
	
	vector<Atributo> getAtri();
	void setAtri(Atributo atri);

	string getHeader();
	string Contructores();
	string getCpp();

};

#endif