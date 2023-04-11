#include <cstdlib>
#include <iostream>
#include <istream>
#include <string>
#include <stdio.h>
#include "ListaListas.h"

#include "cstdlib"
//#include "pugixml.hpp"

using namespace std;

/*entrada de XML
void xml(){
    pugi::xml_document doc;
    if (!doc.load_file("mapa.tmx"))
    {
        std::cerr << "Error al cargar el documento XML." << std::endl;
        
    }
}
menu de operacion de cancionses */

void opPlayList(ListaListas* listas,PlayListNormal* lisCan){
    
    int opCan = 0;
    system("cls");
    while (opCan != 7)
    {
        std::cout << "+++++  Operaciones de PlayList  +++++" << std::endl;
        std::cout << "1) Crear" << std::endl; 
        std::cout << "2) Eliminar" << std::endl;
        std::cout << "3) Actualizar" << std::endl;       
        std::cout << "4) Listar" << std::endl;
        std::cout << "5) Agregar canciones" << std::endl;
        std::cout << "6) Eliminar canciones" << std::endl;
        std::cout << "7) Regresar al menu principal" << std::endl;
        cin>>opCan;
        switch (opCan)
        {
        case 1:{
            int op;
            NodoListas* nuevo = new NodoListas();
            string nombre;
            string des;
            cout<<"Ingresa el nombre de la Play List"<<endl;
            cin.ignore();
            getline(cin,nombre);
            //cin>>nombre;
            cout<<"Ingresa la descripcion de la Play List"<<endl;
            getline(cin,des);
            //cin>>des;
            nuevo->setNombre(nombre);
            nuevo->setDes(des);
            std::cout << "Quieres agregar canciones\n1) Si\n2) No" << std::endl;
            cin>>op;
            if(op == 1){
                int opW = 0;
                int opId;
                PlayListNormal* auxPlay = new PlayListNormal();
                while (opW != 2)
                {
                    std::cout << "Elige el id de la cancion a agregar\n" << std::endl;
                    lisCan->imprimirPos();
                    std::cout << "" << std::endl;
                    cin>>opId;
                    Cancion* aux = lisCan->getPrimero();
                    bool bandera = false;
                    while (aux != NULL)
                    {
                        if(aux->getPos() == opId){
                            aux->imprimir();
                            std::cout << "Canciones de la lista: " <<opId<< std::endl;
                            auxPlay->imprimirPos();
                            Cancion* otro = new Cancion(aux->getNombre(),aux->getPath());
                            otro->imprimir();
                            auxPlay->agregarAlFinal(otro);
                            std::cout << "Canciones de la lista: " <<opId<< std::endl;
                            auxPlay->imprimirPos();
                            bandera = true;
                        }
                        aux = aux->getSiguiente();
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
                nuevo->setLista(auxPlay);
                nuevo->getLista()->imprimirPos();
                listas->agregarAlFinal(nuevo);
            }else{
                listas->agregarAlFinal(nuevo);
                std::cout << "Lista de reproduccion creada" << std::endl;
            }
            
        }
            break;
        case 2:{
            int idE;
            std::cout << "Elige el Id de la lista que deceas eliminar" << std::endl;
            listas->imprimirListas();
            cin>>idE;
            listas->eliminarLista(idE);
        }
            break;
        case 3:{
            int op;
            std::cout << "Selecciona el ID de la PlayList que deceas modificar" << std::endl;
            listas->imprimirListas();
            cin>>op;
            listas->modificar(op);
        }
            break;
        case 4:{
                listas->mostrarListas();
        }
            break;
        case 5:{
            int op;
            std::cout << "Elige el ID de la lista a la que le quieres agregar canciones\n" << std::endl;
            listas->imprimirListas();
            cin>>op;
           listas->agregarCanciones(op,lisCan);
        }
            break;
        case 6:{
            int ops;
            std::cout << "Elige el ID de la PlayList para eliminar canciones\n" << std::endl;
            listas->imprimirListas();
            cin>>ops;
            listas->eliminarCancionLista(ops);
        }
            break;
        case 7:{}
            break;
        default:{ 
            std::cout << "Opcion invalida" << std::endl;
            opCan = 7;
            break;
        }
            
        }
    }
}
/*Menu de canciones*/
void opCancion(PlayListNormal* lisCan){
    int opCan = 0;
    while (opCan != 5)
    {

        std::cout << "+++++  Operaciones de canciones  +++++" << std::endl;
        std::cout << "1) Insertar" << std::endl; 
        std::cout << "2) Eliminar" << std::endl;
        std::cout << "3) Buscar nombre" << std::endl;       
        std::cout << "4) Listar canciones" << std::endl;
        std::cout << "5) Regresar al menu principal" << std::endl;

        cin>>opCan;
        switch (opCan)
        {
        case 1:{
            string nombre;
            string path;
            std::cout << "Ingresa el nombre de la nueva cancion: " << std::endl;
            cin.ignore();
            getline(cin,nombre);
            std::cout << "Ingresa la ubicacion en el disco" << std::endl;
            getline(cin,path);
            Cancion* nuevo = new Cancion(nombre,path);
            lisCan->agregarAlFinal(nuevo);
            break;
            }
            
        case 2:{
            int op;
            std::cout << "1) Eliminar por ID \n2) Eliminar por nombre \n3) regresar" << std::endl;
            cin>>op;
            if(op == 1){
                int eliminar;
                std::cout << "Elige la cancion a eliminar por su ID" << std::endl;
                lisCan->imprimirPos();
                int id;
                cout<<"ELige la cancion a eliminar"<<endl;
                cin>>id;
                std::cout << "Eliminar cancion\n1) Aceptar\n2) Cancelar" << std::endl;
                cin>>eliminar;
                if(eliminar == 1){
                    lisCan->eliminar(id);
                    std::cout << "Eliminado con exito" << std::endl;
                }
                if(eliminar == 2){
                    std::cout << "No se elimino la cancion" << std::endl;
                }
                
            }
            if(op == 2){
                int eliminar;
                string nom;
                std::cout << "Elige la cancion a eliminar por su nombre" << std::endl;
                lisCan->imprimirPos();
                std::cout << "Elige la cancion a eliminar" << std::endl;
                cin.ignore();
                getline(cin,nom);
                std::cout << "Eliminar cancion\n1) Aceptar\n2) Cancelar" << std::endl;
                cin>>eliminar;
                if(eliminar == 1){
                    lisCan->eliminarNombre(nom);
                    std::cout << "Eliminado con exito" << std::endl;
                }
                if(eliminar == 2){
                    std::cout << "No se elimino la cancion" << std::endl;
                }
            }
            if(op == 3){}

        }
            break;
        case 3:{
            string entrada;
            std::cout << "Buscar cancion \nIngresa el nombre de la canion que deceas encontrar:" << std::endl;
            cin.ignore();
            getline(cin,entrada);
            lisCan->buscarNombre(entrada);
        }
            break;
        case 4:{
                lisCan->imprimir();
        }
            break;
        case 5:{


        }
            break;
        default:{    
            std::cout << "Opcion invalida" << std::endl;}
            break;
        }
    }
    

}
/*reproduccion de canciones*/
void repr(ListaCircular* repetir, PlayListNormal* normal,Cancion* actual,int op){
    if(op == 1){

    }
    if(op == 2){

    }
}
/*Menu de reproduccion*/
void rep(){
    int opCan = 0;
    while (opCan != 7)
    {
        std::cout << "+++++  Reproduccion  +++++" << std::endl;
        std::cout << "1) Normal" << std::endl; 
        std::cout << "2) Repetir" << std::endl;
        std::cout << "3) Siguiente" << std::endl;       
        std::cout << "4) Anterior" << std::endl;
        std::cout << "5) Lista de Reproduccion" << std::endl;
        std::cout << "6) Agregar canciones a la lista de reproduccion" << std::endl;
        std::cout << "7) Regresar al menu principal" << std::endl;
        cin>>opCan;
        switch (opCan)
        {
        case 1:{
            
        }
            break;
        case 2:{

        }
            break;
        case 3:{

        }
            break;
        case 4:{

        }
            break;
        case 5:{

        }
            break;
        case 6:{

        }
            break;
        case 7:{

        }
            break;
        default:{    
            std::cout << "Opcion invalida" << std::endl;}
            break;
        }
    }
}

void leerString(string entrada){
    cin.ignore();
    getline(cin, entrada);
}

int main(int argc, char *argv[])
{
    PlayListNormal* listaCan = new PlayListNormal();
    ListaListas* listas = new ListaListas();
    //ListaListas* listas = new ListaListas();
    int opMenu = 0;

    while(opMenu != 5)
    {
        std::cout << "+++++  Terminal Spotify  +++++" << std::endl;
        std::cout << "1) Operaciones de canciones" << std::endl;
        std::cout << "2) Operaciones de PlayList" << std::endl;
        std::cout << "3) Reproduccion" << std::endl;
        std::cout << "4) Carga de archivos" << std::endl;
        std::cout << "5) Salir" << std::endl;
        cin>>opMenu;
        switch (opMenu)
        {
        case 1:{
            opCancion(listaCan);
        }
            break;
        case 2:{
            opPlayList(listas,listaCan);
        }
            break;
        case 3:{
            rep();
        }
            break;
        case 4:{
            //xml();
        }
            break;
        case 5:{}
            break;
        default:{
            std::cout << "$$$ Warning: Opcion no valida $$$" << std::endl;
        }
            break;
        }

    }

    
    return 0;
}