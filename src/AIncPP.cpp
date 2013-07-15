/* 
 * File:   AIncPP.cpp
 * Author: alfonso
 * 
 * Created on June 22, 2013, 8:59 PM
 */

#include "AIncPP.hpp"

/**
 * 
 * @param vRec
 * @param vPol
 */
AIncPP::AIncPP(vector<RecursoC>& vRec, vector<Poligono>& vPol) {

    npubi=0;
    
    for (vector<RecursoC>::iterator itrec = vRec.begin(); itrec != vRec.end(); itrec++) {
        for (vector<Poligono>::iterator itpol = vPol.begin(); itpol != vPol.end(); itpol++) {

            if (itpol->estaPuntoBox(*itrec)) {
                if (punto_en_pol(*itrec, *itpol)) {

                    itrec->sidpol = itpol->sid;
                    itrec->bubicado = true;
                    npubi++;
                    break;
                } else {
                    double distmin = distPunPol(*itrec, *itpol);
                    if (distmin < itrec->dist) {
                        itrec->dist = distmin;
                        itrec->sidpol = itpol->sid;
                    }
                }
            }

        }
    }
}

/**
 * @brief Detemina si un punto esta o no contenido por un poligono
 * @param p
 * @param PPol
 */
bool AIncPP::punto_en_pol(const Punto& p, Poligono& PPol) {

    long vtam= PPol.vp.size();
    
    
    for(long j=0;j<vtam;j+=2){
        
        
    }

    return false;
}

/**
 * @brief Determina la distancia minima entre un poligono y un punto
 */
double AIncPP::distPunPol(const Punto& p, Poligono& PPol) {
    double dist = 10E9;
    double aux = dist;

    for (vector<Punto>::iterator itpol = PPol.vp.begin(); itpol != PPol.vp.end(); itpol++) {

        aux = pow(itpol->x - p.x, 2) + pow(itpol->y - p.y, 2);
        aux = sqrt(aux);
        if (aux < dist) {
            dist = aux;
        }

    }

    return dist;
}

AIncPP::~AIncPP() {
}

