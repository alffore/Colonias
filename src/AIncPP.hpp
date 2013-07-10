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

#include "Poligono.hpp"
#include "Punto.hpp"

class AIncPP {
    
private:
    float dist_min;
    string sidpol_min;
    
public:
    AIncPP(vector<RecursoC>& vRC, const vector<Poligono>& vPol);
   
    virtual ~AIncPP();
private:

    bool punto_en_pol(const Punto& p, const Poligono&  PPol);
    
    void determinaPolCer(const Punto& p,const vector<Poligono>&  vPol);
    
};

#endif	/* AINCPP_HPP */

