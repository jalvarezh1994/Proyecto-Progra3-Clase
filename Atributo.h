#include <iostream>
#include <string>

using namespace std;

#ifndef ATRIBUTO_H
#define ATRIBUTO_H
class Atributo{
protected:
    string tipo;
    string nombre;
    string visibilidad;
public:
    Atributo(string,string,string);
    Atributo();
    
    string getTipo();
    void setTipo(string);

    string getNombre();
    void setNombre(string);

    string getVisibilidad();
    void setVisibilidad(string);
};
#endif