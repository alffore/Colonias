/* 
 * File:   Poligono.cpp
 * Author: alfonso
 * 
 * Created on June 22, 2013, 9:04 PM
 */

#include "Poligono.hpp"

Poligono::Poligono(vector<Punto>& vp,string sid,int poltipo): ObjetoGeom(POLIGONO) {
    this->vp=vp;
    this->sid=sid;
    this->poltipo=poltipo;
    
    detBox();
}

/**
 * 
 */
void Poligono::detBox(){
    vector<Punto>::iterator itp=vp.begin();
    
    xmax=(*itp).x;
    xmin=xmax;
    
    ymax=(*itp).y;
    ymin=ymax;
    
    do{
        
        if(xmax<(*itp).x){
            xmax=(*itp).x;
        }
        
         if(ymax<(*itp).y){
            ymax=(*itp).y;
        }
        
         if(xmin>(*itp).x){
            xmin=(*itp).x;
        }
        
         if(ymin>(*itp).y){
            ymin=(*itp).y;
        }
        
        itp++;
    }while(itp!=vp.end());
    
}

/**
 * 
 * @param p
 * @return 
 */
bool Poligono::estaPuntoBox(const Punto& p){
    if(p.x>=xmin && p.x<=xmax && p.y>=ymin && p.y<=ymax)return true;
    return false;
}

Poligono::~Poligono() {
}

