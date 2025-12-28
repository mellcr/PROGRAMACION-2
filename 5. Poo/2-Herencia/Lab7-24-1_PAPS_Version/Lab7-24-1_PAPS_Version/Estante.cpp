
                    /* CODEANDO CON PAPS */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "Estante.hpp"
#include "Libro.hpp"
#include "LibInf.hpp"
#include "LibDerecho.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

Estante::Estante(){
    codigo = nullptr;
    anchura = 0;
    altura = 0;
    espacios = nullptr;
}
//Estante::Estante(const Estante &origen){
//}
//Estante::~Estante(){
//    if(codigo!=nullptr) delete codigo;
//    anchura = 0;
//    altura = 0;
//}

void Estante::SetAltura(int altura) {
    this->altura = altura;
}

int Estante::GetAltura() const {
    return altura;
}

void Estante::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estante::GetAnchura() const {
    return anchura;
}

void Estante::SetCodigo(const char* codigo) {
    if(this->codigo!=nullptr)   delete this->codigo;
    this->codigo = new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void Estante::GetCodigo(char *codigo) const {
    if(this->codigo==nullptr) codigo[0]=0;
    else strcpy(codigo,this->codigo);
}
void Estante::leeEstante(ifstream &arch){
    char codigo[8],c;
    int anchura,altura;
    arch.getline(codigo,8,',');
    if(arch.eof())return;
    arch>>anchura>>c>>altura;
    arch.get();
    SetCodigo(codigo);
    SetAnchura(anchura);
    SetAltura(altura);
    espacios = new Espacio[anchura*altura]{};
}
void Estante::colocaLibroInf(int anchoUsado, LibroInf &libro){
    for(int i = altura - 1;i>(altura -libro.GetAlto() - 1);i--){
        for(int j = anchoUsado; j < anchoUsado + libro.GetAncho();j++){
            espacios[i*anchura + j].SetPosx(i);
            espacios[i*anchura + j].SetPosy(j);
            espacios[i*anchura + j].SetContenido('*');
        }
    }
    libro.SetColocado(true);
}
void Estante::colocaLibroDer(int altoRestante, LibroDerecho &libro){
    for(int i = altoRestante -1;i>altoRestante - libro.GetAncho()-1;i--){
        for(int j = 0;j<libro.GetAlto();j++){
            espacios[i*anchura + j].SetPosx(i);
            espacios[i*anchura + j].SetPosy(j);
            espacios[i*anchura + j].SetContenido('*');
        }
    }
    libro.SetColocado(true);
}
void Estante::imprimeLinea(ofstream &arch, int max,char caracter){
    arch<<setfill(caracter)<<setw(max)<<caracter<<endl;
    arch<<setfill(' ');
}
void Estante::marcaEstante(ofstream &arch){
    for(int i=0;i<altura;i++){
        for(int j=0;j<anchura;j++){
            espacios[i*anchura + j].muestraEspacio(arch);
        }
        arch<<endl;
    }
}
void Estante::imprimeEstante(ofstream &arch,int cantLibrosInf){
    char codigo[8];
    GetCodigo(codigo);
    arch<<"Codigo Estante: "<<codigo<<setw(25)<<" "<<"Cantidad de Libros: "
            <<cantLibrosInf<<endl;
    arch<<"Anchura del Estante: "<<anchura<<setw(25)<<" "<<"Altura del Estante: "
            <<altura<<endl;
    imprimeLinea(arch,130,'-');
    arch<<endl;
    marcaEstante(arch);
    arch<<endl;
}

                    /* CODEANDO CON PAPS */