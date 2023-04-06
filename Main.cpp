#include <istream>
#include <stdlib.h>
#include "Canciones.h"

using namespace std;

/*menu de operacion de cancionses */

void opPlayList(){
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
        case 1:{}
            break;
        case 2:{}
            break;
        case 3:{}
            break;
        case 4:{}
            break;
        case 5:{}
            break;
        case 6:{}
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
void opCancion(Canciones* lisCan){
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
            char nombre [500];
            char path [2000];
            int num = 1;
            std::cout << "Ingresa el nombre de la nueva cancion: " << std::endl;
            cin>> nombre;
            std::cout << "Ingresa la ubicacion en el disco" << std::endl;
            cin>> path;
            Cancion* nuevo;
            nuevo = new Cancion();
            nuevo->setPos(num);
            nuevo->setNombre(nombre);
            nuevo->setPath(path);
            nuevo->imprimir();
            lisCan->agregarAlFinal(nuevo);
            }
            break;
        case 2:{
            //asdasd
        }
            break;
        case 3:{

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
        case 1:{}
            break;
        case 2:{}
            break;
        case 3:{}
            break;
        case 4:{}
            break;
        case 5:{}
            break;
        case 6:{}
            break;
        case 7:{}
            break;
        default:{    
            std::cout << "Opcion invalida" << std::endl;}
            break;
        }
    }
}


int main()
{
    Canciones* listaCan = new Canciones();
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
            opPlayList();
        }
            break;
        case 3:{
            rep();
        }
            break;
        case 4:{}
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