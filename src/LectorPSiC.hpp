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

#define DELIMITER       "|"

using namespace std;

class LectorPSiC {
public:
    vector<RecursoC> vRec;

    LectorPSiC(string snomarch);
    void leeArchivo(string snomarch);
    virtual ~LectorPSiC();
private:
  void parser(string scad);
    void split(vector<string> & theStringVector, const string & theString, const string & theDelimiter);
};

#endif	/* LECTORPSIC_H */

