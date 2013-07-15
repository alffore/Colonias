/* *
 * @file  ITRF2CCL.hpp
 *@author AAFR
 *
 * Created on July 14, 2013, 2:02 PM
 */

#ifndef ITRF2CCL_HPP
#define	ITRF2CCL_HPP

#include <cmath>

using namespace std;

/**
 * @see http://en.wikipedia.org/wiki/GRS_80
 * @author AAFR
 *
 */

class ITRF2CCL {
private:

    double a; //eje semi-mayor del elipsoide
    double f; //factor de aplanado del elipsoide 1/f=a/(a-b)
    double e; //excentricidad del elipsoide
    double n; //
    double m1;
    double m2;
    double t;
    double t1;
    double t2;
    double tf;
    double F;
    double r;
    double rf;
    double theta;
    double phy1; //primer paralelo estandar
    double phy2; //segundo paralelo estandar
    double phyf; //latitud falsa de origen
    double lambdaf; //longitud falsa de origen
    double EF; //falso este
    double NF; //falso norte
    //Parametros para calcular la transformada de PCCL a GMS
    double thetaprima;
    double tprima;
    double rprima;

    // Coordenadas Geograficas
    double phy; //latitud
    double lambda; //longitud

    // Coordenadas en la proyeccion de Lambert
    double Este;
    double Norte;
public:
    ITRF2CCL();

    void cDeg2PCCL(double latitud, double longitud);
    void cRad2PCCL(double latitud, double longitud);
    void cINEGI2CCL(double x, double y);


    double obtenNorte();
    double obtenEste();

    virtual ~ITRF2CCL();
private:

};

#endif	/* ITRF2CCL_HPP */

