#ifndef CANCION_H
#define CANCION_H

#endif // !CANCION_H

struct Cancion
{
    Cancion* anterior;
    Cancion* ultimo;
    char* path;
    char* nombre;
    int pos;

    Cancion(char* path){
       this->path = path;
    }

    void se anterior(Cancion* anterior){
        this- anterior = anterior;
    }

    Cancion* ge anterior(){
        return this- anterior;
    }

    void setUltimo(Cancion* ultimo){
        this->ultimo = ultimo;
    }

    Cancion* getUltimo(){
        return this->ultimo;
    }

    void setPath(char* path){
        this->path = path;
    }

    char* getPath(){
        return this->path;
    }

    void setNombre(char* nombre){
        this->nombre = nombre;
    }

    char* getNombre(){
        return this->nombre;
    }

    void setPos(int pos){
        this->pos = pos;
    }

    int getPos(){
        return this->pos;
    }
};
