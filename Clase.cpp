#include "Clase.h"
#include <string>

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

string Clase::getHeader() {
	string retVal = "";
	retVal += "#include <iostream>\n";
	retVal += "#include <string>\n\n";
	retVal += "using namespace std;\n\n";
	retVal += "#ifndef " + nombre + "_H\n";
	retVal += "#define " + nombre + "_H\n";
	retVal += "class " + nombre + "{\n";
	retVal += "    protected:\n";
	for (int i = 0;i < atri.size();i++) {
		retVal += "        " + atri[i].getTipo() + " " + atri[i].getNombre() + ";\n";
	}
	retVal += "    public:\n";
	retVal += "        " + nombre + "(";
	
	for (int i = 0;i < atri.size();i++) {
		if (atri.size() == 1) {
			retVal += atri[i].getTipo();
		} else {
			if (i == atri.size() - 1) {
				retVal += atri[i].getTipo();
			} else {
				retVal += atri[i].getTipo() + ",";
			}
		}
	}
	retVal += ");\n";
	retVal += "        ";
	retVal += nombre + "();\n";
	for (int i = 0;i < atri.size();i++) {
		retVal += "        ";
		retVal += atri[i].GetterH();
		retVal += "        " + atri[i].SetterH() + "\n";
	}
	retVal += "};\n#endif";
	return retVal;
}

string Clase::Contructores() {
	string retVal = "";
	retVal += nombre + "::" + nombre + "(";
	for (int i = 0;i < atri.size();i++) {
		if (atri.size() == 1) {
			retVal += atri[i].getTipo() + " " + atri[i].getNombre();
		} else {

			if (i == atri.size() - 1) {
				retVal += atri[i].getTipo() + " " + atri[i].getNombre();
			} else {
				retVal += atri[i].getTipo() + " " + atri[i].getNombre() + ",";
			}
		}
	}
	retVal += "){\n";
	for (int i = 0;i < atri.size();i++) {
		retVal += "    this->" + atri[i].getNombre() + "=" + atri[i].getNombre() + ";\n";
	}
	retVal += "}\n";
	retVal += nombre + "::" + nombre + "(){\n\n}";
	return retVal;
}

string Clase::getCpp() {
	string retVal = "";
	retVal += "#include \"" + nombre + ".h\"\n\n";
	retVal += Contructores();
	for (int i = 0;i < atri.size();i++) {
		retVal += atri[i].SetterCPP(nombre);
		retVal += atri[i].GetterCPP(nombre);
	}
	return retVal;
}