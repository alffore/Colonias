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
long escribeArchivo(string snomarch, LectorPSiC& lpsic);

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

    cout << "Se leen los puntos" << endl;
    LectorPSiC lpsic;
    lpsic.leeArchivo(string(argv[1]));


    cout << "Se leen los poligonos" << endl;
    LectorINT lint;
    if (!leeArchivo(string(argv[2]), lint))return 1;


    cout << "Se ubican los puntos en los poligonos" << endl;
    AIncPP ainc(lpsic.vRec, lint.vPol);


    //    checaPol(lint.vPol);

    cout << "Se imprimieron #puntos: " << escribeArchivo(string(argv[3]), lpsic) << endl;

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
            if (line.size() > 0) {
                lint.leeArchivo(line);
            }
        }
        myfile.close();
    } else {
        cout << "(leeArchivo: main) Problemas para abrir el archivo " << snomarch << endl;
        return false;
    }

    return true;
}

/**
 * 
 * @param snomarch
 * @param lpsic
 * @return 
 */
long escribeArchivo(string snomarch, LectorPSiC& lpsic) {
    long cuenta = 0;

    ofstream miar(snomarch.c_str());

    if (miar.is_open()) {


        for (vector<RecursoC>::iterator itpun = lpsic.vRec.begin(); itpun != lpsic.vRec.end(); ++itpun) {

            vector<string> vsxp = (*itpun).vcar;

            for (vector<string>::iterator itc = vsxp.begin(); itc != vsxp.end(); ++itc) {

                miar << *itc << "|";
            }

            miar << (*itpun).sidpol << "|" << (*itpun).bubicado << "|" << (*itpun).dist << endl;


            cuenta++;
        }

        miar.close();
    }


    return cuenta;
}