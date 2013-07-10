/* *
 * @file    LectorINT.hpp
 * @author  AAFR
 *
 * Created on June 22, 2013, 9:17 PM
 */

#ifndef LECTORINT_HPP
#define	LECTORINT_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Poligono.hpp"

#define DELIMITER       "|"


using namespace std;

/**
 */
class LectorINT {
private:


 


public:
   vector<Poligono> vPol;

    LectorINT(vector<Poligono>& vPol);
    LectorINT(){};
    void leeArchivo(string snomarch);
    virtual ~LectorINT();


private:

    void parser(string scad);
    void split(vector<string> & theStringVector, const string & theString, const string & theDelimiter);

    void parserSPunto(vector<Punto>& vP, const string & scad);
};

#endif	/* LECTORINT_HPP */

