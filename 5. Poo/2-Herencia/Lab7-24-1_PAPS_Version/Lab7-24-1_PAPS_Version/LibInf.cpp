
                    /* CODEANDO CON PAPS */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "LibInf.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

LibroInf::LibroInf(){
    tema = nullptr;
    lenguaje = nullptr;
    dificultad = 0;
}
//LibroInf::LibroInf(const LibroInf &origen){
//}
//LibroInf::~LibroInf(){
//    if(tema!=nullptr) delete tema;
//    if(lenguaje!=nullptr) delete lenguaje;
//    dificultad = 0;
//}

void LibroInf::SetDificultad(int dificultad) {
    this->dificultad = dificultad;
}

int LibroInf::GetDificultad() const {
    return dificultad;
}

void LibroInf::SetLenguaje(const char* lenguaje) {
    if(this->lenguaje!=nullptr)   delete this->lenguaje;
    this->lenguaje = new char[strlen(lenguaje)+1];
    strcpy(this->lenguaje,lenguaje);
}

void LibroInf::GetLenguaje(char *lenguaje) const {
    if(this->lenguaje==nullptr) lenguaje[0]=0;
    else strcpy(lenguaje,this->lenguaje);
}

void LibroInf::SetTema(const char* tema) {
    if(this->tema!=nullptr)   delete this->tema;
    this->tema = new char[strlen(tema)+1];
    strcpy(this->tema,tema);
}

void LibroInf::GetTema(char *tema) const {
    if(this->tema==nullptr) tema[0]=0;
    else strcpy(tema,this->tema);
}
void LibroInf::leeLibro(ifstream &arch){
    char tema[100],lenguaje[50],c;
    int dificultad;
    Libro::leeLibro(arch);
    arch.getline(tema,100,',');
    if(arch.eof())return;
    arch.getline(lenguaje,50,',');
    arch>>dificultad;
    arch.get();    
    SetTema(tema);
    SetLenguaje(lenguaje);
    SetDificultad(dificultad);
}
void LibroInf::muestraLibro(ofstream &arch){
    char tema[100],lenguaje[50];
    int dificultad;
    GetTema(tema);
    GetLenguaje(lenguaje);
    dificultad = GetDificultad();
    Libro::muestraLibro(arch);
    arch<<setw(30)<<tema<<setw(40)<<lenguaje<<setw(5)<<dificultad<<endl;
}

                    /* CODEANDO CON PAPS */