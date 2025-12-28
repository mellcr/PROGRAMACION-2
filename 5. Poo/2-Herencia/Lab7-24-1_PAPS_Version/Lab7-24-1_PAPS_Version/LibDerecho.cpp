
                    /* CODEANDO CON PAPS */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "LibDerecho.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

LibroDerecho::LibroDerecho(){
    area = nullptr;
    jurisdiccion = nullptr;
    edicion = 0;
}
//LibroDerecho::LibroDerecho(const LibroDerecho &origen){
//}
//LibroDerecho::~LibroDerecho(){
//    if(area!=nullptr) delete area;
//    if(jurisdiccion!=nullptr) delete jurisdiccion;
//    edicion = 0;
//}

void LibroDerecho::SetEdicion(int edicion) {
    this->edicion = edicion;
}

int LibroDerecho::GetEdicion() const {
    return edicion;
}

void LibroDerecho::SetJurisdiccion(const char* jurisdiccion) {
    if(this->jurisdiccion!=nullptr)   delete this->jurisdiccion;
    this->jurisdiccion = new char[strlen(jurisdiccion)+1];
    strcpy(this->jurisdiccion,jurisdiccion);
}

void LibroDerecho::GetJurisdiccion(char *jurisdiccion) const {
    if(this->jurisdiccion==nullptr) jurisdiccion[0]=0;
    else strcpy(jurisdiccion,this->jurisdiccion);
}

void LibroDerecho::SetArea(const char* area) {
    if(this->area!=nullptr)   delete this->area;
    this->area = new char[strlen(area)+1];
    strcpy(this->area,area);
}

void LibroDerecho::GetArea(char *area) const {
    if(this->area==nullptr) area[0]=0;
    else strcpy(area,this->area);
}
void LibroDerecho::leeLibro(ifstream &arch){
    char area[100],jurisdiccion[50];
    int edicion;
    Libro::leeLibro(arch);
    arch.getline(area,100,',');
    if(arch.eof())return;
    arch.getline(jurisdiccion,50,',');
    arch>>edicion;
    arch.get();
    SetArea(area);
    SetJurisdiccion(jurisdiccion);
    SetEdicion(edicion);
}
void LibroDerecho::muestraLibro(ofstream &arch){
    char area[100],jurisdiccion[50];
    int edicion;
    GetArea(area);
    GetJurisdiccion(jurisdiccion);
    edicion = GetEdicion();
    Libro::muestraLibro(arch);
    arch<<setw(30)<<area<<setw(40)<<jurisdiccion<<setw(5)<<edicion<<endl;
}

                    /* CODEANDO CON PAPS */