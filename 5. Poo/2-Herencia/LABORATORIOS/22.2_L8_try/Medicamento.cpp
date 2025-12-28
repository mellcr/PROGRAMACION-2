
/* 
 * File:   Medicamento.cpp
 * Author: mell1
 * 
 * Created on 30 de mayo de 2024, 12:41
 */
#include "Utils.h"
#include "Medicamento.h"
using namespace std; 

Medicamento::Medicamento() {
    nombre = nullptr; 
}

Medicamento::Medicamento(const Medicamento& orig) {
}

Medicamento::~Medicamento() {
    if(nombre) delete nombre; 
}

void Medicamento::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Medicamento::GetFecha() const {
    return fecha;
}

void Medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double Medicamento::GetPrecio() const {
    return precio;
}

void Medicamento::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int Medicamento::GetCantidad() const {
    return cantidad;
}

void Medicamento::SetNombre(const char* nombre) {
    if(this->nombre!=nullptr) delete this->nombre; 
    //le damos espacio
    this->nombre = new char[strlen(nombre)+1]; 
    strcpy(this->nombre,nombre); 
}

void Medicamento::GetNombre(char *c) const {
    if(this->nombre==nullptr) c[0] = 0; 
    else strcpy(c,this->nombre);
}

void Medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Medicamento::GetCodigo() const {
    return codigo;
}

void Medicamento::GetNombYPrecioEnArchivo(int codBus,char *nomb, double &prec){
    ifstream arch("medicamentos.txt",ios::in);
    if(not arch.is_open()){
        cout <<"maldito medicamento toy enfermAAAA"<<endl;
        exit(1);
    }
    int codLeid;
    char c,buffNomb[60];
    double precioLeid;
    
    while(true){
        arch>>codLeid;
        if(arch.eof()){
            prec = 0;
            nomb[0]=0; // no encontro nada , retorna cadena vacia
            return ;
        }
        if(codBus==codLeid){
            arch>>c;
            arch.getline(buffNomb,60,',');
            arch>>precioLeid;
            
            // lo setea de frente
            SetNombre(buffNomb);
            SetPrecio(precioLeid);
            //pasamos los parametros porsiaca xd
            prec = precioLeid;
            strcpy(nomb,buffNomb);
        }
        else while(arch.get()!='\n');
    }
}

void Medicamento::imprime(ofstream &arch){
    arch<<left<<setw(10)<<codigo<<setw(50)<<nombre<<right<<setw(10)<<" "
            <<setw(5)<<cantidad<<setw(10)<<" ";
}