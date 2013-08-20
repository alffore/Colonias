/* 
 * File:   AIncPP.cpp
 * Author: alfonso
 * 
 * Created on June 22, 2013, 8:59 PM
 */

#include "AIncPP.hpp"

/**
 * Constructor
 * @param vRec
 * @param vPol
 */
AIncPP::AIncPP(vector<RecursoC>& vRec, vector<Poligono>& vPol) {

    npubi = 0;

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

    long vtam = PPol.vp.size();

    complex<double> ztot(0, 0);

    for (long j = 0; j < vtam - 1; j++) {

        ztot += calculaIL(p, PPol.vp[j], PPol.vp[j + 1]);

    }

    ztot += calculaIL(p, PPol.vp[vtam - 1], PPol.vp[0]);

    if (fabs(imag(ztot)) > 0)return true;


    return false;
}

/**
 * @brief Método que estima una integral de linea en una trayectoria recta que une dos puntos
 * @param p0
 * @param p1
 * @param p2
 * @return 
 */
complex<double> AIncPP::calculaIL(const Punto& p0, const Punto& p1, const Punto& p2) {

    double t, delta, tmax;

    tmax = 100;
    delta = 1 / tmax;

    complex <double> z0(p0.x, p0.y), z1(p1.x, p1.y), z2(p2.x, p2.y), zaux(0, 0);

    for (t = 0; t < 1; t += delta) {

        zaux += (z2 - z1) * delta / ((z2 - z1) * t + z1 - z0);
    }

    return zaux;
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

