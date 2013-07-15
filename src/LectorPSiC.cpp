/* 
 * File:   LectorPSiC.cpp
 * Author: alfonso
 * 
 * Created on July 14, 2013, 12:46 PM
 */

#include "LectorPSiC.hpp"

LectorPSiC::LectorPSiC(string snomarch) {
    
    leeArchivo(snomarch);
}

void LectorPSiC::leeArchivo(string snomarch) {
    string line;
    ifstream myfile(snomarch.c_str());
    if (myfile.is_open()) {
        while (myfile.good()) {
            getline(myfile, line);
            parser(line);
        }
        myfile.close();
    } else cout << "Problemas para abrir el archivo " << snomarch << endl;

    cout << "#puntos: " << vRec.size() << endl;
}

LectorPSiC::~LectorPSiC() {
}

/**
 * 
 * @param scad
 */
void LectorPSiC::parser(string scad) {

    vector<string> vc;
    split(vc, scad, DELIMITER);

    if (vc.size() > 1) {
        cout << "Campos: "<<vc.size() << endl;

        RecursoC auxP(atof(vc[0].c_str()),atof(vc[1].c_str()));

        i2c.cDeg2PCCL(auxP.y,auxP.x);
        
        auxP.x=i2c.obtenEste();
        auxP.y=i2c.obtenNorte();
        
        auxP.vcar=vc;
        
        vRec.push_back(auxP);
    }
}



/**
 * Metodo que separa los tokens de una una cadena de acuerdo  a un caracter delimitador
 * @param theStringVector
 * @param theString
 * @param theDelimiter
 */
void LectorPSiC::split(vector<string>& theStringVector, const string& theString, const string& theDelimiter) {
    size_t start = 0, end = 0;

    while (end != string::npos) {
        end = theString.find(theDelimiter, start);

        // If at end, use length=maxLength.  Else use length=end-start.
        theStringVector.push_back(theString.substr(start,
                (end == string::npos) ? string::npos : end - start));

        // If at end, use start=maxSize.  Else use start=end+delimiter.
        start = ((end > (string::npos - theDelimiter.size()))
                ? string::npos : end + theDelimiter.size());
    }
}
