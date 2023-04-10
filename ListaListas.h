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

    void eliminarLista(int idE){
            bool bandera = false;
            NodoListas* aux = primero;
            while (aux != NULL)
            {
                if(aux->getId() == idE){
                    int ent;
                    std::cout << "Desea eliminal la Play list de nombre: " <<aux->getNombre()<<"\n1) Si \n2)No"<< std::endl;
                    cin>>ent;
                    if(ent == 1){
                        bandera = true;
                    }
                }
                aux = aux->getSiguiente();
            }
            if(bandera){
                eliminar(idE);
                std::cout << "Lista eliminada con extio" << std::endl;
            }else{
                std::cout << "No se pudo eliminar la lista" << std::endl;
            }
    }
    void modificar(int op){
        NodoListas* aux = primero;
        while (aux != NULL)
        {
            if(aux->getId() == op){
                aux->imprimirInfoNodo();
                cout<<endl;
                string nombre = "";
                string descrip = "";
                std::cout << "Ingresa el nuevo nombre de la lista" << std::endl;
                cin>>nombre;
                std::cout << "Ingresa la nueva descripcion de la lista" << std::endl;
                cin>>descrip;
                if(nombre.length() == 0 ){
                    std::cout << "El nombre esta vacio, cambios no guradados" << std::endl;
                }else{
                    aux->setNombre(nombre);
                }
                if(descrip.length() == 0){
                    std::cout << "El nombre esta vacio, cambios no guradados" << std::endl;
                }else{
                    aux->setDes(descrip);
                }
                aux->imprimirInfoNodo();
            }
            aux = aux->getSiguiente();
        }
        

    }
    void agregarCanciones(int op,PlayListNormal* lisCan){
         NodoListas* aux = primero;
            while (aux != NULL)
            {
                if(aux->getId() == op){
                    int opW = 0;
                    int opId;
                    while (opW != 2)
                    {
                        std::cout << "Elige el id de la cancion a agregar\n" << std::endl;
                        lisCan->imprimirPos();
                        std::cout << "" << std::endl;
                        cin>>opId;
                        Cancion* aux1 = lisCan->getPrimero();
                        bool bandera = false;
                        while (aux1 != NULL)
                        {
                            if(aux1->getPos() == opId){
                                
                                aux->getLista()->agregarAlFinal(aux1);
                                bandera = true;
                            }
                            aux1 = aux1->getSiguiente();
                    }
                    if(bandera){
                        std::cout << "Cancion agregada con exito" << std::endl;
                    }
                    else{
                        std::cout << "Cancion no encontrada" << std::endl;
                    }

                    std::cout << "Agregar una nueva cancion\n1) Si\n2) No" << std::endl;
                    cin>>opW;

                    
                }
                break;
                }
                aux = aux->getSiguiente();
            }
    }

    void eliminarCancionLista(int op){
        NodoListas* aux = primero;
        while (aux != NULL)
        {
            if(aux->getId() == op){
                bool bandera = true;
                while (bandera)
                {
                    int opM;
                    std::cout << "Elige el ID de la cancion que deseas eliminar" << std::endl;
                    aux->getLista()->imprimirPos();
                    cin>>opM;
                    aux->getLista()->eliminar(opM);
                    std::cout << "Deceas eliminar otra cancion\n1) Si\2)No\n" << std::endl;
                    cin>>opM;
                    if(opM == 2){
                        bandera = true;
                    }
                }
                

            }
            aux = aux->getSiguiente();
        }
        
    }

    void mostrarListas(){
        int op;
        std::cout << "Elige la opcion\n1) Mostrar Listas \n2) Mostrar canciones de una lista" << std::endl;
        cin>>op;

        if(op ==1){
            imprimirListas();
        }else if(op == 2){
            int opCan;
            std::cout << "Elige el ID de la lista para mostrar las canciones" << std::endl;
            imprimirListas();
            cin>>opCan;
            NodoListas* aux = primero;
            while (aux != NULL)
            {
                if(aux->getId() == opCan){
                    aux->getLista()->imprimirPos();
                    break;
                }
                aux = aux->getSiguiente();
            }
            
        }
        else{   
            std::cout << "Opcion no valida" << std::endl;
        }
    
    }

};
