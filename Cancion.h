#ifndef CANCION_H
#define CANCION_H

#endif // !CANCION_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;
struct Cancion
{
    Cancion* anterior;
    Cancion* siguiente;
    string path;
    string nombre;
    string carajo;
    int pos;
    int posPlay;

    Cancion(string nombre,string path){
        this->nombre = nombre;
        this->path = path;
    }
    void setPosPlay(int end){
        this->posPlay = end;
    }

    int getPosPlay(){
        return this->posPlay;
    }
    void setAnterior(Cancion* entrada){
        this->anterior = entrada;
    }

    Cancion* getAnterior(){
        return this->anterior;
    }

    void setSiguiente(Cancion* entrada){
        this->siguiente = entrada;
    }

    Cancion* getSiguiente(){
        return this->siguiente;
    }

    void setPath(string entrada){
        this->path = entrada;
    }

    string getPath(){
        return this->path;
    }

    void setNombre(string entrada){
        this->nombre = entrada;
        
    }

    string getNombre(){
        return this->nombre;
    }

    void setPos(int entrada){
        this->pos = entrada;
    }

    int getPos(){
        return this->pos;
    }
    void imprimir(){
        if(pos > 0){
        cout<<"Nombre: "<<getNombre();
        cout<<"\tPath: "<<getPath();
        cout<<"\tId: "<<getPos()<<endl;
        }

    }

    void mostrasPos(){
        if(pos>0){
            cout<<"ID: "<<pos<<" Nombre: "<<nombre<<endl;
        }
    }

};
