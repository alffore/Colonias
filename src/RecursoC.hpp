/* 
 * File:   RecursoC.hpp
 * Author: alfonso
 *
 * Created on June 23, 2013, 2:27 PM
 */

#ifndef RECURSOC_HPP
#define	RECURSOC_HPP

#include <string>
#include <vector>

#include "Punto.hpp"

using namespace std;

class RecursoC : public Punto{
    
private:
       
public:
    string sidpol;
    bool bubicado;
    
    double dist;
    
    vector<string> vcar;
    
    
    RecursoC(double x, double y);
    
    virtual ~RecursoC();
private:

};

#endif	/* RECURSOC_HPP */

