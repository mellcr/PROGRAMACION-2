
                    /* CODEANDO CON PAPS */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "Biblioteca.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

Biblioteca::Biblioteca(){
    cantEstantesInf = 0;
    cantEstantesDerecho = 0;
    cantLibrosInf = 0;
    cantLibrosDerecho = 0;
}
//Biblioteca::Biblioteca(const Biblioteca &origen){
//}
//Biblioteca::~Biblioteca(){
//    cantEstantesInf = 0;
//    cantEstantesDerecho = 0;
//    cantLibrosInf = 0;
//    cantLibrosDerecho = 0;
//}

void Biblioteca::SetCantLibrosDerecho(int cantLibrosDerecho) {
    this->cantLibrosDerecho = cantLibrosDerecho;
}

int Biblioteca::GetCantLibrosDerecho() const {
    return cantLibrosDerecho;
}

void Biblioteca::SetCantLibrosInf(int cantLibrosInf) {
    this->cantLibrosInf = cantLibrosInf;
}

int Biblioteca::GetCantLibrosInf() const {
    return cantLibrosInf;
}

void Biblioteca::SetCantEstantesDerecho(int cantEstantesDerecho) {
    this->cantEstantesDerecho = cantEstantesDerecho;
}

int Biblioteca::GetCantEstantesDerecho() const {
    return cantEstantesDerecho;
}

void Biblioteca::SetCantEstantesInf(int cantEstantesInf) {
    this->cantEstantesInf = cantEstantesInf;
}

int Biblioteca::GetCantEstantesInf() const {
    return cantEstantesInf;
}
void Biblioteca::cargarLibros(){
    ifstream arch("Libros.csv",ios::in);
    if(!arch.is_open()){
        cout<<"Error con el archivo Libros.cvs"<<endl;
        exit(1);
    }
    char buff[5];
    while(true){
        arch.getline(buff,5,',');
        if(arch.eof())break;
        if(strcmp(buff,"INF")==0){
            librosInf[cantLibrosInf].leeLibro(arch);
            cantLibrosInf++;
        }
        if(strcmp(buff,"DER")==0){
            librosDerecho[cantLibrosDerecho].leeLibro(arch);
            cantLibrosDerecho++;
        }
    }
}
void Biblioteca::cargarEstantes(){
    ifstream arch("Estantes.csv",ios::in);
    if(!arch.is_open()){
        cout<<"Error con el archivo Estantes.cvs"<<endl;
        exit(1);
    }
    char buff[5];
    while(true){
        arch.getline(buff,5,',');
        if(arch.eof())break;
        if(strcmp(buff,"INF")==0){
            estantesInf[cantEstantesInf].leeEstante(arch);
            cantEstantesInf++;
        }
        if(strcmp(buff,"DER")==0){
            estantesDerecho[cantEstantesDerecho].leeEstante(arch);
            cantEstantesDerecho++;
        }
    }
}
void Biblioteca::posicionarLibros(){
    int limite = 0;
    for(int i=0;i<cantEstantesInf;i++){
        for(int j=limite;j<cantLibrosInf;j++){
            int vali1=(librosInf[j].GetAlto()<=estantesInf[i].GetAltura() and
                      librosInf[j].GetAncho()<=estantesInf[i].obtieneEspaciosRestantes());
            if(vali1){
                estantesInf[i].colocaLibro(librosInf[j]);
            }
            else{
                limite = j;
                break;
            }
        }
    }
    int limite2 = 0;
    for(int i=0;i<cantEstantesDerecho;i++){
        for(int j=limite2;j<cantLibrosDerecho;j++){
            int vali2=(librosDerecho[j].GetAlto()<=estantesDerecho[i].GetAnchura() and
                      librosDerecho[j].GetAncho()<=estantesDerecho[i].obtieneEspaciosRestantes());
            if(vali2){
                estantesDerecho[i].colocaLibro(librosDerecho[j]);
            }
            else{
                limite2 = j;
                break;
            }
        }
    }
}
void Biblioteca::imprimeLinea(ofstream &arch, int max,char caracter){
    arch<<setfill(caracter)<<setw(max)<<caracter<<endl;
    arch<<setfill(' ');
}
void Biblioteca::muestraDatosInf(ofstream &arch){
    arch<<setw(46)<<" "<<"Estantes de Informatica"<<endl;
    imprimeLinea(arch,130,'=');
    arch<<"Cantidad de Estantes: "<<cantEstantesInf<<endl;
    for(int i=0;i<cantEstantesInf;i++){
        imprimeLinea(arch,130,'-');
        estantesInf[i].imprimeEstante(arch);
    }
    imprimeLinea(arch,130,'=');
    arch<<"Informacion de todos los libros de Informatica:"<<endl;
    arch<<"Cantidad de Libros Total: "<<cantLibrosInf<<endl;
    for(int i=0;i<cantLibrosInf;i++){
        librosInf[i].muestraLibro(arch);
    }
    imprimeLinea(arch,130,'=');
}
void Biblioteca::muestraDatosDer(ofstream &arch){
    
    arch<<setw(46)<<" "<<"Estantes de Derecho"<<endl;
    imprimeLinea(arch,130,'=');
    arch<<"Cantidad de Estantes: "<<cantEstantesDerecho<<endl;
    for(int i=0;i<cantEstantesDerecho;i++){
        imprimeLinea(arch,130,'-');
        estantesDerecho[i].imprimeEstante(arch);
    }
    imprimeLinea(arch,130,'=');
    arch<<"Informacion de todos los libros de Derecho:"<<endl;
    arch<<"Cantidad de Libros Total: "<<cantLibrosDerecho<<endl;
    for(int i=0;i<cantLibrosDerecho;i++){
        librosDerecho[i].muestraLibro(arch);
    }
    imprimeLinea(arch,130,'=');
}
void Biblioteca::mostrarDatos(){
    ofstream arch("Reporte.txt",ios::out);
    if(!arch.is_open()){
        cout<<"Error con el archivo Reporte.txt"<<endl;
        exit(1);
    }
    imprimeLinea(arch,130,'=');
    arch<<setw(40)<<" "<<"Informacion del posicionamiento de Libros"<<endl;
    arch<<setw(42)<<" "<<"en los estantes de la Biblioteca PAPS"<<endl;
    imprimeLinea(arch,130,'=');
    muestraDatosInf(arch);
    muestraDatosDer(arch);
    arch<<endl;
}
                    /* CODEANDO CON PAPS */