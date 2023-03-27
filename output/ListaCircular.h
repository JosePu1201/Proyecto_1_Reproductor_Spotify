#ifndef LISTACIRCULAR_H
#define lISTACIRCULAR_H
#endif // !LISTACIRCULAR_H 

#include "Cancion.h"
#include<iostream>
#include <cstdlib>
#include "string"
using namespace std;

struct ListaCircular
{
    Cancion* inicio;
    ListaCircular(Cancion* nuevo){
        this->inicio = nuevo;
        this->inicio->setSiguiente(nuevo); 
        this->inicio->setAnterior(nuevo);
    }

    void agregarInicio(Cancion* nuevo){
        nuevo->setAnterior(inicio->getAnterior());
        nuevo->setSiguiente(inicio);

        inicio->getAnterior()->setSiguiente(nuevo);
        inicio->setAnterior(nuevo);

        inicio = inicio->getAnterior();
    }
    void agregarFinal(Cancion* nuevo){
        nuevo->setAnterior(inicio->getAnterior());
        nuevo->setSiguiente(inicio);

        inicio->getAnterior()->setSiguiente(nuevo);
        inicio->setAnterior(nuevo);
    }
    void imprimirSiguiente(Cancion* actual){
        cout<<actual->getNombre()<<endl;
        if(actual->getSiguiente()!= inicio){
            imprimirSiguiente(actual->getSiguiente());
        }
    }
    void imprimirTodo(){
        imprimirSiguiente(inicio);
    }

    int buscarEnLista(Cancion* actual, int inicioCancion,char* informacionBuscada){
        if(actual->getNombre() == informacionBuscada){
            return inicioCancion;
        }
        else{
            if(actual->getSiguiente() != inicio){
                return buscarEnLista(actual->getSiguiente(),inicioCancion+1,informacionBuscada);
            }
            else{
                return -1;
            }
        }
    }

    int buscar(char* buscado){
        if(inicio->getNombre() == buscado){
            return 0;
        }
        else{
            return buscarEnLista(inicio->getSiguiente(),1,buscado);
        }
    }

    void eliminarEnLista(Cancion* actual, char* infoEliminar){
        if((actual->getNombre() == infoEliminar) && (actual != inicio)){
            if(actual->getSiguiente() != inicio){
                actual->getAnterior()->setSiguiente(actual->getSiguiente());
                actual->getSiguiente()->setAnterior(actual->getAnterior());

                Cancion* siguiente = actual->getSiguiente();
                actual->setAnterior(NULL);
                actual->setSiguiente(NULL);
                actual->setNombre(NULL);
                eliminarEnLista(siguiente,infoEliminar);
            }
            else{
                actual->getAnterior()->setSiguiente(inicio);
                inicio->setAnterior(actual->getAnterior());
                actual->setAnterior(NULL);
                actual->setSiguiente(NULL);
                actual->setNombre(NULL);               
            }
        }
        else if((actual->getNombre()==infoEliminar) && (actual == inicio)){
            actual->getAnterior()->setSiguiente(actual->getSiguiente());
            actual->getSiguiente()->setAnterior(actual->getAnterior());
            inicio = inicio->getSiguiente();
            actual->setAnterior(NULL);
            actual->setSiguiente(NULL);
            actual->setNombre(NULL);
            eliminarEnLista(inicio,infoEliminar);
        }
        else{
            if(actual->getSiguiente() != inicio){
                eliminarEnLista(actual->getSiguiente(),infoEliminar);
            }
        }
    }

    void eliminar(char* eliminar){
        eliminarEnLista(inicio,eliminar);
    }
    
};
