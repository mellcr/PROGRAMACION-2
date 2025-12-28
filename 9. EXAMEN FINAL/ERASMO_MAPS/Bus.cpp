
/* 
 * File:   Bus.cpp
 * Author: mell1
 * 
 * Created on 8 de julio de 2024, 10:38 p. m.
 */

#include "Utils.h"
using namespace std;
#include "Bus.h"
#include "Ciudad.h"

Bus::Bus() {
    n_rutas=0;
    n_pasajeros=0;
}

Bus::Bus(const Bus& orig) {
    *this = orig;
}

Bus::~Bus() {
}

void Bus::SetN_rutas(int n_rutas) {
    this->n_rutas = n_rutas;
}

int Bus::GetN_rutas() const {
    return n_rutas;
}

void Bus::SetN_pasajeros(int n_pasajeros) {
    this->n_pasajeros = n_pasajeros;
}

int Bus::GetN_pasajeros() const {
    return n_pasajeros;
}

void Bus::SetNombre_chofer(string nombre_chofer) {
    this->nombre_chofer = nombre_chofer;
}

string Bus::GetNombre_chofer() const {
    return nombre_chofer;
}

void Bus::SetPlaca(string placa) {
    this->placa = placa;
}

string Bus::GetPlaca() const {
    return placa;
}

//AXZ123,Erasmo Gomez,3,Lima,Chincha,Pisco
void Bus::leer(ifstream &arch){
    char c,buff[100];
    string rutaDes;
    
    //NUEVO GETLINE 
    arch.getline(buff,100,',');
    if(arch.eof()) return ;
    placa = buff;
    arch.getline(buff,100,',');
    nombre_chofer= buff;
    arch>>n_rutas>>c;
     rutas.clear();
    for(int i=0;i<n_rutas;i++){
        if(i==n_rutas-1) arch.getline(buff,100,'\n');
        else  arch.getline(buff,100,',');
        rutaDes = buff;
        
        //añadimos la info de la ruta del bus
        rutas.push_back(rutaDes);
    }
}
void Bus::mostrarbus() const{
    cout<<GetN_pasajeros()<<" "<<GetN_rutas()<<" "<<GetNombre_chofer()<<" "<<GetPlaca()<<endl;
}

void Bus::imprime_rutas() const {
    
        for(const auto& ruta : rutas) {
            cout << ruta << " ";
        }
        cout << endl;
    
}

string Bus::getCiudadActual(int pos)const {
    return rutas[pos];
    
//    string ciudac;
//    for(int i=0; i< rutas.size();i++){
//        if( pos== i) return ciudac=rutas[i];
//    }
//    return ciudac;
}