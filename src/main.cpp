#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "LectorINT.hpp"
#include "LectorPSiC.hpp"
#include "Poligono.hpp"
#include "Punto.hpp"
#include "AIncPP.hpp"

using namespace std;

void checaPol(vector<Poligono>& vP);
bool leeArchivo(string snomarch, LectorINT &lint);

/**
 * 
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char **argv) {
    
    if (argc == 1) {

        cout << "Falta lista con archivos a procesar " << endl;
        return 1;
    }

    cout<<"Se leen los puntos"<<endl;
    LectorPSiC lpsic;
    lpsic.leeArchivo(string(argv[1]));
   
    
    cout << "Se leen los poligonos"<<endl;
    LectorINT lint;
   if(!leeArchivo(string(argv[1]),lint))return 1;
    
    
     cout << "Se ubican los puntos en los poligonos"<<endl;
     AIncPP ainc(lpsic.vRec,lint.vPol);
    
    
    checaPol(lint.vPol);
   
    
    
    return 0;
}




/**
 * @brief Metodo para depurar y checar 
 * @param vP
 */
void checaPol(vector<Poligono>& vP) {


    cout << "Cantidad de Poligonos:  " << vP.size() << endl;

    for (vector<Poligono>::iterator it = vP.begin(); it != vP.end(); ++it) {
        cout << "Cantidad de Puntos: " << (*it).vp.size() << endl;
    }

}

/**
 * 
 * @param snomarch
 * @param lint
 */
bool leeArchivo(string snomarch, LectorINT &lint) {
    string line;
    ifstream myfile(snomarch.c_str());
    if (myfile.is_open()) {
        while (myfile.good()) {
            getline(myfile, line);
            lint.leeArchivo(line);
        }
        myfile.close();
    } else {
        cout << "Problemas para abrir el archivo " << snomarch << endl;
        return false;
    }

    return true;
}