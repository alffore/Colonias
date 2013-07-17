/* 
 * File:   Punto.hpp
 * Author: alfonso
 *
 * Created on June 22, 2013, 8:45 PM
 */

#ifndef PUNTO_HPP
#define	PUNTO_HPP

#include "ObjetoGeom.hpp"

class Punto : public ObjetoGeom {
public:

    /**
     * @brief Longitud - Este
     */
    double x;
    /**
     * @brief Latitud - Norte
     */
    double y;

    Punto(double x, double y) : ObjetoGeom(PUNTO), x(x), y(y) {
    };
  
    virtual ~Punto();
private:

};

#endif	/* PUNTO_HPP */

