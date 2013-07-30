/* 
 * File:   LectorINT.cpp
 * Author: alfonso
 * 
 * Created on June 22, 2013, 9:17 PM
 */

#include "LectorINT.hpp"

/**
 * 
 * @param snomarch
 */
LectorINT::LectorINT( vector<Poligono>& vPol) {
    
    this->vPol = vPol;

    
    
   
}

/**
 * 
 */
void LectorINT::leeArchivo(string snomarch) {
    string line;
    ifstream myfile(snomarch.c_str());
    if (myfile.is_open()) {
        while (myfile.good()) {
            getline(myfile, line);
            parser(line);
        }
        myfile.close();
    } else {cout << "(LectorINT::leeArchivo) Problemas para abrir el archivo " << snomarch << endl;}

    cout<<"#poligonos: "<<vPol.size()<<endl;
}

LectorINT::~LectorINT() {
}

/**
 * 
 * @param scad
 */
void LectorINT::parser(string scad) {

    vector<string> vc;
    split(vc, scad, DELIMITER);

    if (vc.size() > 1) {
        cout << "Campos: "<<vc.size() << endl;

        vector<Punto> vp;

        parserSPunto(vp, vc[2]);
        cout<<" #vertices: "<<vp.size()<<endl;
        Poligono auxPol(vp, vc[3], 0);


        vPol.push_back(auxPol);
    }
}

/**
 * 
 * @param vP
 * @param scad
 */
void LectorINT::parserSPunto(vector<Punto>& vP, const string & scad) {
    vector<string> vsc;

    if (scad.size() > 0) {
        split(vsc, scad, ",");

        long int tamv = vsc.size();

        if (tamv >= 2) {
            for (long int i = 0; i < tamv; i += 2) {
                Punto p(atof(vsc[i].c_str()), atof(vsc[i + 1].c_str()));
                vP.push_back(p);
            }
        }
    }
}

/**
 * 
 * @param theStringVector
 * @param theString
 * @param theDelimiter
 */
void LectorINT::split(vector<string>& theStringVector, const string& theString, const string& theDelimiter) {
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