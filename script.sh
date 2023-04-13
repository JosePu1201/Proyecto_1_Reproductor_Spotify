#!/bin/bash
sudo apt-get install libtinyxml2-dev 
g++ -o salida Main.cpp Cancion.h ListaCircular.h ListaListas.h NodoListas.h PlayListNormal.h -ltinyxml2
./salida