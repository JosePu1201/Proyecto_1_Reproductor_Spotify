#ifndef CANCION_H
#define CANCION_H

#endif // !CANCION_H
#include<iostream>
#include <cstdlib>

using namespace std;
struct Cancion
{
    Cancion* anterior;
    Cancion* siguiente;
    char* path;
    char* nombre;
    int pos;

    Cancion(){
       
    }

    void setAnterior(Cancion* anterior){
        this->anterior = anterior;
    }

    Cancion* getAnterior(){
        return this->anterior;
    }

    void setSiguiente(Cancion* siguiente){
        this->siguiente = siguiente;
    }

    Cancion* getSiguiente(){
        return this->siguiente;
    }

    void setPath(char* path){
        this->path = path;
    }

    char* getPath(){
        return this->path;
    }

    void setNombre(char* nombre){
        this->nombre = nombre;
        
    }

    char* getNombre(){
        return this->nombre;
    }

    void setPos(int pos){
        this->pos = pos;
    }

    int getPos(){
        return this->pos;
    }
    char* impresion(){
        return path;
    }
    void imprimir(){
        cout<<"Nombre: "<<nombre<<endl;
    }

};
