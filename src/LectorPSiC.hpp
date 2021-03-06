/* 
 * File:   LectorPSiC.h
 * Author: alfonso
 *
 * Created on July 14, 2013, 12:46 PM
 */

#ifndef LECTORPSIC_HPP
#define	LECTORPSIC_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "RecursoC.hpp"
#include "ITRF2CCL.hpp"

#define DELIMITER       "|"

using namespace std;

/**
 * @brief Clase que lee puntos de SiC 
 */
class LectorPSiC {
    
private:
    ITRF2CCL i2c;
public:
    vector<RecursoC> vRec;

    LectorPSiC(string snomarch);
    LectorPSiC(){};
    void leeArchivo(string snomarch);
    virtual ~LectorPSiC();
private:
  void parser(string scad);
    void split(vector<string> & theStringVector, const string & theString, const string & theDelimiter);
};

#endif	/* LECTORPSIC_H */

