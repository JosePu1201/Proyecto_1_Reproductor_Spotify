#ifndef CANCIONES_H
#define CANCIONES_H

#endif // !CANCIONES_H
#include "Cancion.h"
#include<iostream>
#include <cstdlib>
#include "string"
using namespace std;

struct Canciones
{
    Cancion* primero;
    Cancion* ultimo;
    
    Canciones(){
        primero = NULL;
        ultimo = NULL;
    }
    void agregarAlFinal(Cancion* nuevo){ //agrega un nodo al final
        if(primero == NULL && ultimo == NULL){
            primero = nuevo;
            ultimo = nuevo;
            cout<<"agrega el primero"<<endl;

        }else{
            cout<<"agrega los demas"<<endl;
        ultimo->setSiguiente(nuevo);
        ultimo->getSiguiente()->setAnterior(ultimo);

        ultimo = ultimo->getSiguiente();
        }
    }

    void eliminar(int id){
        eliminarPlayList(primero,id);
    }

    void eliminarPlayList(Cancion* actual, int id){
        if(actual->getPos() == id && actual != primero && actual != ultimo){
            if(actual->getSiguiente()!= NULL){
                actual->getAnterior()->setSiguiente(actual->getSiguiente());
                actual->getSiguiente()->setAnterior(actual->getAnterior());
                Cancion* siguiente = actual->getSiguiente();
                actual->setAnterior(NULL);
                actual->setSiguiente(NULL);
                actual->setPos(-1);
                eliminarPlayList(siguiente, id);
            }
            else{
                actual->getAnterior()->setSiguiente(NULL);
                actual->setAnterior(NULL);
                actual->setSiguiente(NULL);
                actual->setPos(-1);
            }
        }
        else if(actual->getPos() == id && actual == primero){
            if(actual->getSiguiente() != NULL){
                primero = actual->getSiguiente();
                primero->setAnterior(NULL);
                actual->setSiguiente(NULL);
                actual->setPos(-1);
                eliminarPlayList(primero,id);
            }
            else{
                actual->setAnterior(NULL);
                actual->setSiguiente(NULL);
                actual->setPos(-1);
            }
        }
        else if(actual->getPos() == id && actual == ultimo){
            ultimo = ultimo->getAnterior();
            ultimo->setSiguiente(NULL);
            actual->setAnterior(NULL);
            actual->setSiguiente(NULL);
            actual->setPos(-1);
        }
        else{
            if(actual->getSiguiente() != NULL){
                eliminarPlayList(actual->getSiguiente(),id);
            }
        }
    }

    int buscar(int pos){
        if(primero->getPos() == pos){
            return 0;
        }
        else{
            return buscarEnList(primero->getSiguiente(),1,pos);
        }
    }
    int buscarEnList(Cancion* actual, int pos,int posMatriz){
        if(actual->getPos() == pos){
            return pos;
        }
        else{
            if(actual->getSiguiente() != NULL){
                return buscarEnList(actual->getSiguiente(),pos+1,posMatriz);
            }
            else{
                return -1;
            }
        }

    }

    void imprimir(){
        Cancion* aux = primero;
        cout<<"Lista de canciones"<<endl;
        while (aux->getSiguiente() != NULL)
        {
            cout<<aux->getNombre()<<"--->";
            aux = aux->getSiguiente();
        }
        cout<<endl;
        
    }
};
