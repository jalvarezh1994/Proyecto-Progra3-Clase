#include "C_Main.h"
#include <string>

C_Main::C_Main(){

}

vector<Clase*> C_Main::getClases() {
	return clases;
}

void C_Main::setClases(vector<Clase*> clases) {
	this->clases = clases;
}

string C_Main::getCpp() {
    string retVal = "";
    retVal += "#include <iostream>\n";
    retVal += "#include <fstream>\n";
    retVal += "#include <string>\n";
    retVal += "#include <vector>\n";
    for (int i = 0; i < clases.size(); i++) {
        retVal += "#include " + '\"' + clases[i]->getNombre() + ".h\"\n";
    }
    retVal += "\nusing namespace std;\n\n";
    retVal += "int main(){\n";
    for (int i = 0; i < clases.size(); i++) {
        retVal += "vector<" + clases[i]->getNombre() + ">" + " v" + clases[i]->getNombre() + ";\n";
    }
    retVal += "int opcMenu;\n";
    retVal += "do{\n";
    retVal += "cout<<\"Menú\"<<endl;\n";
    retVal += "cout<<\"1. Agregar\"<<endl;\n";
    retVal += "cout<<\"2. Listar\"<<endl;\n";
    retVal += "cout<<\"3. Modificar\"<<endl;\n";
    retVal += "cout<<\"4. Eliminar\"<<endl;\n";
    retVal += "cout<<\"5. Guardar en archivos de texto\"<<endl;\n";
    retVal += "cout<<\"6. Leer de archivos de texto\"<<endl;\n";
    retVal += "cout<<\"7. Guardar en binarios\"<<endl;\n";
    retVal += "cout<<\"7. Leer de binarios\"<<endl;\n";
    retVal += "cout<<\"8. Salir\"<<endl;\n";
    retVal += "cout<<\"Ingrese opción: \"<<endl;\n";
    retVal += "cin>>opcMenu;\n";
    retVal += "switch(opcMenu){\n";
    retVal += "case 1:{\n";
    retVal += agregar();
    retVal += "break;\n}\n";
    retVal += "case 2:\n{\n";
    retVal += listar();
    retVal += "break;\n}\n";
    retVal += "case 3:{\n";
    retVal += "break;\n}\n";
    retVal += "case 4:{\n";
    retVal += "break;\n}\n";
    retVal += "case 5:{\n";
    retVal += "break;\n}\n";
        retVal += "}\n";//fin del switch
        retVal += "}while(opcMenu!=8);\n";
        retVal += "}";
        return retVal;
    }

    string C_Main::agregar() {
        string retVal = "cout<<\"Menú agregar\"<<endl;\n";
        
        for (int i = 0; i < clases.size(); i++) {
            retVal += "cout<<\"" + (i + 1);
            retVal += ". " + clases[i]->getNombre() + "\"<<endl;\n";
        }
        
        retVal += "int opcAgregar;\n";
        retVal += "cout<<\"Ingrese la opción: \";\n";
        retVal += "cin>>opcAgregar";
        retVal += ";\n";
        retVal += "switch(opcAgregar){\n";
        
        for (int i = 0; i < clases.size(); i++) {
            retVal += "case " + (i + 1);
            retVal += ":{\n";
            vector<Atributo>atr=clases[i]->getAtri();
            for (int j = 0; j < atr.size(); j++) {
                retVal += atr[j].getTipo();
                retVal += " " + atr[j].getNombre();
                retVal += ";\n";
                retVal += "cout<<\"Ingrese " + atr[j].getNombre();
                retVal += ": \";\n";
                retVal += "cin>>" + atr[j].getNombre();
                retVal += ";\n";
            }

            retVal += clases[i]->getNombre() + " temporal(";
            for (int j = 0; j < atr.size(); j++) {
                retVal += atr[j].getNombre();
                if (clases[i]->getAtri().size() - 1 != i) {
                    retVal += ",";
                }
            }   

            retVal += ");\n";
            retVal += "v" + clases[i]->getNombre() + ".push_back(temporal);\n";
            retVal += "break;\n}\n";
        }
        retVal += "}\n";
        return retVal;
    }

    string C_Main::listar() {
        string retVal = "cout<<\"Menú listar\"<<endl;\n";
        for (int i = 0; i < clases.size(); i++) {
            retVal += "cout<<\"" + (i + 1);
            retVal += ". " + clases[i]->getNombre() + "\"<<endl;\n";
        }
        retVal += "int opcListar;\n";
        retVal += "cout<<\"Ingrese la opción: \";\n";
        retVal += "cin>>opcListar";
        retVal += ";\n";
        retVal += "switch(opcListar){\n";
        for (int i = 0; i < clases.size(); i++) {
            retVal += "case " + (i + 1);
            retVal += ":\n";
            retVal += "for(int i=0;i<v" + clases[i]->getNombre() + ".size();i++){\n";
            vector<Atributo>atr=clases[i]->getAtri();
            for (int j = 0; j < atr.size(); j++) {
                retVal += "cout<<\"" + atr[j].getNombre() + "\"<<\" = \"<<" + "v" + 
                clases[i]->getNombre() + "[i].get" + atr[j].getNombre() + "();\n";
            }    
            retVal += "cout<<endl;\n";
            retVal += "\n}";
            retVal += "break;\n";
        }
        retVal += "}\n";
    
        return retVal;
    }

    string C_Main::modificar() {
        string retVal = "";
        return retVal;
    }


