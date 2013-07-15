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
    float x;
    /**
     * @brief Latitud - Norte
     */
    float y;

    Punto(float x, float y) : ObjetoGeom(PUNTO), x(x), y(y) {
    };
  
    virtual ~Punto();
private:

};

#endif	/* PUNTO_HPP */

