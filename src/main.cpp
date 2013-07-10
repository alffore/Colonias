#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "LectorINT.hpp"
#include "Poligono.hpp"
#include "Punto.hpp"

using namespace std;

void checaPol(vector<Poligono>& vP);

/**
 * 
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char **argv) {

   // vector<Poligono> vP;

    if (argc == 1) {

        cout << "Falta lista con archivos a procesar " << endl;

    }

    //LectorINT lint(vP);
    LectorINT lint;
    lint.leeArchivo(string(argv[1]));
    checaPol(lint.vPol);
    //checaPol(vP);
    
    
    return 0;
}

void checaPol(vector<Poligono>& vP) {


    cout << "Cantidad de Poligonos:  " << vP.size() << endl;

    for (vector<Poligono>::iterator it = vP.begin(); it != vP.end(); ++it) {
        cout << "Cantidad de Puntos: " << (*it).vp.size() << endl;
    }

}