/* 
 * File:   AIncPP.cpp
 * Author: alfonso
 * 
 * Created on June 22, 2013, 8:59 PM
 */

#include "AIncPP.hpp"

AIncPP::AIncPP(vector<RecursoC>& vRC, const vector<Poligono>& vPol) {
    
    
    
}

/**
 * 
 * @param p
 * @param PPol
 */
bool AIncPP::punto_en_pol(const Punto& p, const Poligono& PPol){
    
    vector<Punto>::iterator itp=PPol.vp.begin();
    
    Punto pant=*itp;
    
    for(itp=PPol.vp.begin(); itp!=PPol.vp->end();itp++){
        float xdif=((Punto)*itp).x-pant.x;
        float ydif=((Punto)*itp).y-pant.y;
        
        
        
        pant=*itp;
    }
    
    return false;
}

/**
 * 
 * @param p
 * @param vPol
 */
void AIncPP::determinaPolCer(const Punto& p,const vector<Poligono>&  vPol){
    
    for(vector<Poligono>::iterator itp=vPol.begin(); itp!=vPol.end();itp++){
        
    }
    
    
}


AIncPP::~AIncPP() {
}

