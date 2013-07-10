/* 
 * File:   Poligono.hpp
 * Author: alfonso
 *
 * Created on June 22, 2013, 9:04 PM
 */

#ifndef POLIGONO_HPP
#define	POLIGONO_HPP

#include <vector>
#include <string>


#include "Punto.hpp"


using namespace std;

class Poligono : public ObjetoGeom{
private:
    float xmax,xmin;
    float ymax,ymin;
    
public:
    int  poltipo;
    string sid;
    
    vector<Punto> vp;
    Poligono(vector<Punto>& vp,string sid,int poltipo);
 
    bool estaPuntoBox(const Punto& p);
    
    virtual ~Poligono();
private:
    
    void detBox();

};

#endif	/* POLIGONO_HPP */

