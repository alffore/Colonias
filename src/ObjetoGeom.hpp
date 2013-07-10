#ifndef  __OBJETOGEOM_HPP__
#define __OBJETOGEOM_HPP__

#define NO_DEFINIDO -1
#define POLIGONO 1
#define PUNTO 2
#define LINEA 3

class ObjetoGeom {
public:
    int tipo;
    ObjetoGeom():tipo(NO_DEFINIDO){};
    ObjetoGeom(int tipo);


};



#endif 
