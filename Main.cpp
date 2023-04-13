#include <cstdlib>
#include <iostream>
#include <istream>
#include <string>
#include <stdio.h>
#include "ListaListas.h"
#include "tinyxml2.h"
#include "cstdlib"

using namespace tinyxml2;
using namespace std;

/*xmlotro*/
 void agregarCancion(string nombre, string path, PlayListNormal* canciones){
    Cancion* nuevo = new Cancion(nombre,path);
    canciones->agregarAlFinal(nuevo);
    canciones->imprimirPos();
}
void Clear()
{
    cout << "\x1B[2J\x1B[H";
}

void limpiar(){
        cout << "Some console filling text ..." << endl;
    cout << "Another filler string for the stdout\n"
            "Another filler string for the stdout\n"
            "Another filler string for the stdout\n"
            "Another filler string for the stdout\n"
            "Another filler string for the stdout\n" << endl;
    Clear();
}
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
        std::cout << "5) Agrega cancion a lista" << std::endl;
        std::cout << "6) Elimina cancion de lista" << std::endl;
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
            std::cout << "Quieres agrega Cancion\n1) Si\n2) No" << std::endl;
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
                            std::cout <<" lisCan de la lista: " <<opId<< std::endl;
                            auxPlay->imprimirPos();
                            Cancion* otro = new Cancion(aux->getNombre(),aux->getPath());
                            otro->imprimir();
                            auxPlay->agregarAlFinal(otro);
                            std::cout <<" lisCan de la lista: " <<opId<< std::endl;
                            auxPlay->imprimirPos();
                            bandera = true;
                        }
                        aux = aux->getSiguiente();
                    }
                    if(bandera){
                        limpiar();
                        std::cout << "Cancion agregada con exito" << std::endl;
                    }
                    else{
                        limpiar();
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
            limpiar();
            int idE;
            std::cout << "Elige el Id de la lista que deceas eliminar" << std::endl;
            listas->imprimirListas();
            cin>>idE;
            listas->eliminarLista(idE);
        }
            break;
        case 3:{
            limpiar();
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
            limpiar();
            int op;
            std::cout << "Elige el ID de la lista a la que le quieres agregar cancion\n" << std::endl;
            listas->imprimirListas();
            cin>>op;
           listas->agregarCanciones(op,lisCan);
           
        }
            break;
        case 6:{
            limpiar();
            int ops;
            std::cout << "Elige el ID de la PlayList para eliminar cancion\n" << std::endl;
            listas->imprimirListas();
            cin>>ops;
            listas->eliminarCancionLista(ops);
            
        }
            break;
        case 7:{}
            break;
        default:{ 
            limpiar();
            std::cout << "Opcion invalida" << std::endl;
            opCan = 7;
            break;
        }
            
        }
    }
}
/*Menu d* lisCan*/
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
            limpiar();
            string nombre;
            string path;
            std::cout << "Ingresa el nombre de la nueva cancion: " << std::endl;
            cin.ignore();
            getline(cin,nombre);
            std::cout << "Ingresa la ubicacion en el disco" << std::endl;
            getline(cin,path);
            agregarCancion(nombre,path,lisCan);
            break;
            }
            
        case 2:{
            limpiar();
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
            limpiar();
            string entrada;
            std::cout << "Buscar cancion \nIngresa el nombre de la canion que deceas encontrar:" << std::endl;
            cin.ignore();
            getline(cin,entrada);
            lisCan->buscarNombre(entrada);
            limpiar();
        }
            break;
        case 4:{
                lisCan->imprimirPos();
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
/*reproduccion d* lisCan*/
void repr(ListaCircular* repetir, PlayListNormal* normal,Cancion* actual,int op){
    if(op == 1){

    }
    if(op == 2){

    }
}
/*Menu de reproduccion*/
void rep(ListaListas* listas){
    int opCan = 0;
    while (opCan != 3)
    {
        int id;
        std::cout << "+++++  Reproduccion  +++++" << std::endl;
        std::cout << "Elige la lista que deceas reproducir, seleccion su ID" << std::endl;
        listas->imprimirListas();
        cin>>id;
        std::cout << "Elige como deseas reproducir" << std::endl;
        std::cout << "1) Normal" << std::endl; 
        std::cout << "2) Repetir" << std::endl;
        std::cout << "3) Regresar al menu principal" << std::endl;
        cin>>opCan;
        PlayListNormal* nuevo;
        NodoListas* aux = listas->getPrimero();
        while (aux != NULL)
        {
            if(aux->getId() == id){
                nuevo = aux->getLista();
            }
            aux = aux->getSiguiente();
        }
        switch (opCan)
        {
        case 1:{
            int salir = 0;

            if(nuevo->getPrimero() != NULL){
                Cancion* aux1 = nuevo->getPrimero();
                int dir;
                while (aux1 != NULL)
                {
                    cout<<"Reproduciendo: "<<endl;
                    aux1->imprimir();
                    std::cout << "1) Siguiente\n2) Anterior\n3) Salir" << std::endl;
                    cin>>dir;
                    if(dir == 1){
                        aux1 = aux1->getSiguiente();
                    }
                    else if(dir == 2){
                        aux1 = aux1->getAnterior();
                    }
                    else if(dir == 3){
                        break;
                    }
                    else{
                        std::cout << "Opcion invalida" << std::endl;
                    }
                    
                }
                cout<<"Reproduccion terminada\n";
                
            }

        }
            break;
        case 2:{
            /*int salir=0;
            ListaCircular* nuevoCir = new ListaCircular();

            Cancion* auxCan = nuevo->getPrimero();
            while (auxCan != NULL)
            {
                Cancion* can = new Cancion(auxCan->getNombre(),auxCan->getPath());
                can->setPos(auxCan->getPos());
                nuevoCir->agregarFinal(can);
                auxCan = auxCan->getSiguiente();
            }
            Cancion* auxCircular = nuevoCir->getInicio();
            while (salir != 3 && auxCircular!=NULL )
            {
                std::cout << "Reproduciendo: \n" << std::endl;
                auxCircular->imprimir();
                cout<<"\n1) Siguiente\n2) Anterior\n3)Salir"<<endl;
                cin>>salir;
                if(salir == 1){
                    auxCircular->getSiguiente();
                }
                else if (salir == 2)
                {
                    auxCircular->getAnterior();
                }
                else if (salir == 3)
                {
                    break;
                }
                else{

                }
            }
            
            */
        }
            break;
        case 3:{

        }
            
        default:{    
            std::cout << "Opcion invalida" << std::endl;}
            break;
        }
    }
}


/*entrada de XML*/
void xml(PlayListNormal* lisCan,ListaListas* listas){//Ingreso del XML
    XMLDocument doc;
    string direccion;

    std::cout << "Ingresa la direccion del archivo de carga en formato XML" << std::endl;
    cin.ignore();
    getline(cin,direccion); // lectura del path
    doc.LoadFile(direccion.c_str());
    if(doc.Error()){//Verifica si hay un error del archivo
        std::cout << "Error en la carga del archivo XML en la direccion: " <<direccion<< std::endl;
        return;
    }
    //std::cout << "lee en espa pos: 1" << std::endl;
    XMLElement *insert = doc.FirstChildElement("Insertar"); //<Insertar> </Insertar>
    int vueltasInsert = 0;
    while (insert != nullptr) //Recorre los insert
    {
        vueltasInsert++;
        std::cout << "Cancioens: " << std::endl;
        XMLElement *cancioN = insert->FirstChildElement("cancion");
        int vCan = 0;
        while(cancioN != nullptr){
            vCan++;
            string path;
            string nombre;
            string posId;
            nombre = cancioN->FirstChildElement("Nombre")->GetText();//obtiene el nombre
            path = cancioN->FirstChildElement("path")->GetText();//obtiene el path
            XMLElement* pos = cancioN->FirstChildElement("Pos");
            if(pos != nullptr){ // obtiene la posicion en caso de que este
                posId = pos->GetText();
            }
            if(!nombre.empty() && !path.empty()){
                std::cout << "\tNombre: " <<nombre<<"\tPath: "<<path<< std::endl;
            }
            else{
                std::cout << "Todos los parametros deben de estar llenos " << std::endl;
            }
            cancioN = cancioN->NextSiblingElement("cancion");
        }
        lisCan->imprimirPos();
    
        XMLElement* lista = insert->FirstChildElement("Lista");
        while (lista != nullptr)
        {
            string nombreLista;
            string desLista;

            nombreLista = lista->FirstChildElement("Nombre")->GetText();
            desLista = lista->FirstChildElement("Description")->GetText();
            XMLElement* canciones = lista->FirstChildElement("Canciones");
            if(!nombreLista.empty() && !desLista.empty()){//Agrega Lista sin canciones 
                std::cout << "Nueva Lista de Reproduccion" << std::endl;
                std::cout << "Nombre: " <<nombreLista<<"\tDescripcion: "<<desLista<<std::endl;
                if(canciones != nullptr){ // Agrega lista con canciones
                std::cout << "Posicion de canciones" << std::endl; 
                XMLElement* cancionesEntrada = lista->FirstChildElement("pos");
                while (cancionesEntrada != nullptr)
                {
                    cout <<cancionesEntrada->GetText()<<"-";
                    cancionesEntrada = cancionesEntrada->NextSiblingElement("pos");
                }
                cout<<endl;                    
                }
                else{

                }
            }
            else{
                std::cout << "Hay un campo vacio" << std::endl;
            }
            lista = lista->NextSiblingElement("Lista");
        }
        insert = insert->NextSiblingElement("Insertar");
    }
    
    XMLElement *eliminar = doc.FirstChildElement("Eliminar");
    while (eliminar != nullptr){
        std::cout << "ELiminar" << std::endl;
        XMLElement *canciones = eliminar->FirstChildElement("cancion");
        while (canciones != nullptr)
        {
            std::cout << "\tCancion" << std::endl;
            XMLElement *id = canciones->FirstChildElement("id");
            XMLElement *name = canciones->FirstChildElement("Nombre");
            if(id != nullptr){
                std::cout << "\t\tId: "<<id->GetText()<< std::endl;
            }
            if(name != nullptr){
                std::cout << "\t\tNombre: " <<name->GetText()<< std::endl;
            }
            canciones = canciones->NextSiblingElement("cancion");
        }
        eliminar = eliminar->NextSiblingElement("Eliminar");
    }
        
    }
    

/*menu de operacion de cancionses */


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
            limpiar();
        }
            break;
        case 2:{
            opPlayList(listas,listaCan);
            limpiar();
        }
            break;
        case 3:{
            rep(listas);
            limpiar();
        }
            break;
        case 4:{
            xml(listaCan,listas);
        }
            break;
        case 5:{}
            break;
        default:{
            std::cout << "$$$ Warning: Opcion no valida $$$" << std::endl;
            limpiar();
        }
            break;
        }

    }

    
    return 0;
}
