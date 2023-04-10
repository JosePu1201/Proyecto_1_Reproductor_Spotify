#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>
#include "ListaListas.h"


using namespace std;

/*menu de operacion de cancionses */

void opPlayList(ListaListas* listas,PlayListNormal* lisCan){
    int opCan = 0;
    
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
            cin>>nombre;
            cout<<"Ingresa la descripcion de la Play List"<<endl;
            cin>>des;
            nuevo->setNombre(nombre);
            nuevo->setDes(des);
            std::cout << "Quieres agregar canciones\n1) Si\n2) No" << std::endl;
            cin>>op;
            if(op == 1){
                int opW = 0;
                int opId;
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
                            nuevo->getLista()->agregarAlFinal(aux);
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
            cin >> nombre;
            std::cout << "Ingresa la ubicacion en el disco" << std::endl;
            cin >> path;
            Cancion* nuevo = new Cancion(nombre,path);
            lisCan->agregarAlFinal(nuevo);
            break;
            }
            
        case 2:{
            std::cout << "Elige la cancion a eliminar por su ID" << std::endl;
            lisCan->imprimirPos();
            int id;
            cout<<"ELige la cancion a eliminar"<<endl;
            cin>>id;
            lisCan->eliminar(id);
        }
            break;
        case 3:{
            string entrada;
            std::cout << "Buscar cancion \nIngresa el nombre de la canion que deceas encontrar:" << std::endl;
            cin>>entrada;
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
            char direccion [] = "/Documentos/Estructuras de datos/Proyecto_1/AC_DC-T.N.T..mp3";
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


int main()
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