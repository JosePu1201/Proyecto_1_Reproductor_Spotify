#ifndef LISTASLISTAS_H
#define LISTASLISTAS_H
#endif // DEBUG

#include "NodoListas.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

struct ListaListas
{
    NodoListas* primero;
    NodoListas* ultimo;
    int pos = 0;
    ListaListas(){
        primero = NULL;
        ultimo = NULL;
    }

    void agregarAlFinal(NodoListas* nuevo){
        pos++;
        nuevo->setId(pos); //agrega un nodo al final
        if(primero == NULL && ultimo == NULL){
            primero = nuevo;
            ultimo = nuevo;

        }else{
            ultimo->setSiguiente(nuevo);
            ultimo->getSiguiente()->setAnterior(ultimo);

            ultimo = ultimo->getSiguiente();
        }
    }

    void eliminar(int id){
        eliminarPlayList(primero,id);
    }

    void eliminarPlayList(NodoListas* actual, int id){
        if(actual->getId() == id && actual != primero && actual != ultimo){
            if(actual->getSiguiente()!= NULL){
                actual->getAnterior()->setSiguiente(actual->getSiguiente());
                actual->getSiguiente()->setAnterior(actual->getAnterior());
                NodoListas* siguiente = actual->getSiguiente();
                actual->setAnterior(NULL);
                actual->setSiguiente(NULL);
                actual->setId(-1);
                eliminarPlayList(siguiente, id);
            }
            else{
                actual->getAnterior()->setSiguiente(NULL);
                actual->setAnterior(NULL);
                actual->setSiguiente(NULL);
                actual->setId(-1);
            }
        }
        else if(actual->getId() == id && actual == primero){
            if(actual->getSiguiente() != NULL){
                primero = actual->getSiguiente();
                primero->setAnterior(NULL);
                actual->setSiguiente(NULL);
                actual->setId(-1);
                eliminarPlayList(primero,id);
            }
            else{
                actual->setAnterior(NULL);
                actual->setSiguiente(NULL);
                actual->setId(-1);
            }
        }
        else if(actual->getId() == id && actual == ultimo){
            ultimo = ultimo->getAnterior();
            ultimo->setSiguiente(NULL);
            actual->setAnterior(NULL);
            actual->setSiguiente(NULL);
            actual->setId(-1);
        }
        else{
            if(actual->getSiguiente() != NULL){
                eliminarPlayList(actual->getSiguiente(),id);
            }
        }
    }

    int buscar(int pos){
        if(primero->getId() == pos){
            return 0;
        }
        else{
            return buscarEnList(primero->getSiguiente(),1,pos);
        }
    }
    int buscarEnList(NodoListas* actual, int pos,int posMatriz){
        if(actual->getId() == pos){
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

    void imprimirListas(){
        std::cout << "-----Listas de reproducion-----\n" << std::endl;
        std::cout << "ID    Nombre\n" << std::endl;
        NodoListas* aux = primero;

        while (aux != NULL)
        {
            cout<<aux->getId()<<"\t"<<aux->getNombre()<<endl;
            aux = aux->getSiguiente();
        }
        
        
    }

    NodoListas* getPrimero(){
        return this->primero;
    }

};
