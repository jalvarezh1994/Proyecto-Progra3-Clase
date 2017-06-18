#ifndef C_MAIN_H
#define C_MAIN_H

#include <iostream>
#include <string>
#include <vector>
#include "Clase.h"

using namespace std;

class C_Main{
protected:
	vector<Clase*>clases;
public:
	C_Main();
	
	vector<Clase*> getClases();
	void setClases(vector<Clase*>);

	string getCpp();
	string agregar();
	string listar();
	string modificar();
};

#endif