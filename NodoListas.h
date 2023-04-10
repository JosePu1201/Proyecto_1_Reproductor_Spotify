#ifndef NODOLISTAS_H
#define NODOLISTAS_H
#endif //NODOLISTAS_H

#include "PlayListNormal.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct NodoListas
{
    string nombre;
    string des;
    int id;
    NodoListas* anterios;
    NodoListas* siguiente;
    PlayListNormal* lista;

    NodoListas(){
        lista = new PlayListNormal();
    }

    void setNombre(string nombre){
        this->nombre = nombre;
    }

    string getNombre(){
        return this->nombre;
    }

    void setDes(string des){
        this->des = des;
    }
    
    string getDes(){
        return this->des;
    }

    void setId(int id){
        this->id = id;
    }

    int getId(){
        return this->id;
    }

    void setAnterior(NodoListas* entrada){
        this->anterios = entrada;
    }

    NodoListas* getAnterior(){
        return this->anterios;
    }

    void setSiguiente(NodoListas* entrada){
        this->siguiente = entrada;
    }

    NodoListas* getSiguiente(){
        return this->siguiente;
    }

    void setLista(PlayListNormal* entrada){
        this->lista = entrada;
    }

    PlayListNormal* getLista(){
        return this->lista;
    }
    void imprimirInfoNodo(){
        std::cout << "ID: " <<id<<"\tNombre: "<<nombre<<"\tDescricpion: "<<des<< std::endl;
    }
};
