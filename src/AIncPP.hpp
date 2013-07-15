/* 
 * File:   AIncPP.hpp
 * Author: alfonso
 *
 * Created on June 22, 2013, 8:59 PM
 */

#ifndef AINCPP_HPP
#define	AINCPP_HPP

#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#include "Poligono.hpp"
#include "Punto.hpp"
#include "RecursoC.hpp"

class AIncPP {
       
public:
    long npubi;
    AIncPP(vector<RecursoC>& vRec,  vector<Poligono>& vPol);
    virtual ~AIncPP();
private:

    bool punto_en_pol(const Punto& p, Poligono&  PPol);
    double distPunPol(const Punto& p, Poligono&  PPol);
};

#endif	/* AINCPP_HPP */

