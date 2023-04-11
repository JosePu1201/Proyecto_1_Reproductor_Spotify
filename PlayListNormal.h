#ifndef PLAYLISTNORMAL_H
#define PLAYLISTNORMAL_H

#endif // ! PLAYLISTNORMAL_H
#include<iostream>
#include <cstdlib>
#include "string"
#include "ListaCircular.h"
using namespace std;

struct PlayListNormal
{   
    Cancion* primero;
    Cancion* ultimo;
    int pos = 0;
    int posPLay = 0;

    PlayListNormal(){
        primero = NULL;
        ultimo = NULL;
    }

void buscarNombre(string nombre){ //usca por nombre complejidad = O(n)
    Cancion* aux = primero;
    bool bandera = false;
    while (aux != NULL)
    {
        if(aux->getNombre() == nombre){
            aux->imprimir();
            bandera = true;
        }
        aux = aux->getSiguiente();
    }
    if(!bandera){
        std::cout << "Ninguna cancion encontrada" << std::endl;
    }
    
}
void agregarAlFinal(Cancion* nuevo){ //agrega una cancion al final de la lista complejidad = 1
        pos++;
        nuevo->setPos(pos);
        if(primero == NULL && ultimo == NULL){
            primero = nuevo;
            ultimo = nuevo;

        }else{

            ultimo->setSiguiente(nuevo);
            ultimo->getSiguiente()->setAnterior(ultimo);

            ultimo = ultimo->getSiguiente();
        }
    }
    void agregarAlFinalLista(Cancion* nuevo){ //agrega una cancion al final de la lista complejidad = 1
        posPLay++;
        //nuevo.set
        if(primero == NULL && ultimo == NULL){
            primero = nuevo;
            ultimo = nuevo;

        }else{

            ultimo->setSiguiente(nuevo);
            ultimo->getSiguiente()->setAnterior(ultimo);

            ultimo = ultimo->getSiguiente();
        }
    }
     void eliminarNombre(string id){ //recursividad
        eliminarCan(primero,id);
    }

    void eliminarCan(Cancion* actual, string id){ //eimina las canciones de forma recursiva su complejidad es O(n)
        if(actual->getNombre() == id && actual != primero && actual != ultimo){
            if(actual->getSiguiente()!= NULL){
                actual->getAnterior()->setSiguiente(actual->getSiguiente());
                actual->getSiguiente()->setAnterior(actual->getAnterior());
                Cancion* siguiente = actual->getSiguiente();
                actual->setAnterior(NULL);
                actual->setSiguiente(NULL);
                actual->setPos(-1);
                eliminarCan(siguiente, id);
            }
            else{
                actual->getAnterior()->setSiguiente(NULL);
                actual->setAnterior(NULL);
                actual->setSiguiente(NULL);
                actual->setPos(-1);
            }
        }
        else if(actual->getNombre() == id && actual == primero){
            if(actual->getSiguiente() != NULL){
                primero = actual->getSiguiente();
                primero->setAnterior(NULL);
                actual->setSiguiente(NULL);
                actual->setPos(-1);
                eliminarCan(primero,id);
            }
            else{
                actual->setAnterior(NULL);
                actual->setSiguiente(NULL);
                actual->setPos(-1);
            }
        }
        else if(actual->getNombre() == id && actual == ultimo){
            ultimo = ultimo->getAnterior();
            ultimo->setSiguiente(NULL);
            actual->setAnterior(NULL);
            actual->setSiguiente(NULL);
            actual->setPos(-1);
        }
        else{
            if(actual->getSiguiente() != NULL){
                eliminarCan(actual->getSiguiente(),id);
            }
        }
    }
    void eliminar(int id){
        eliminarPlayList(primero,id);
    }

    void eliminarPlayList(Cancion* actual, int id){//recursividad pero con id O(n)
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

    int buscar(int pos){ //busqueda por id O(n)
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
    void imprimir(){ // imrime todas las canciones O(n)
        Cancion* aux = primero;
        cout<<"-----Lista de canciones-----"<<endl;
        while (aux != NULL)
        {
            aux->imprimir();
            aux = aux->getSiguiente();
        }
        cout<<endl;
        
    }
    void imprimirPos(){
        Cancion* aux = primero;
        cout<<"-----Lista de canciones-----\n"<<endl;
        while (aux != NULL)
        {
            aux->mostrasPos();
            aux = aux->getSiguiente();
        }
        cout<<endl;

    }
    Cancion* getPrimero(){
        return this->primero;
    }

    Cancion* getUltimo(){
        return this->ultimo;
    }

    void setPrimero(Cancion* entrada){
        this->primero = entrada;
    }

    void setUlimo(Cancion* entrada){
        this->ultimo = entrada;
    }
};

