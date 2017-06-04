#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>
#include "Clase.h"

using namespace std;

class Main{
protected:
	vector<Clase>clases;
public:
	Main();

	vector<Clase> getClases();
	void setClases(vector<Clase>);

	string getCpp();
	string agregar();
	string listar();
};

#endif