
/* 
 * File:   Flota.cpp
 * Author: mell1
 * 
 * Created on 8 de julio de 2024, 10:33 p. m.
 */
#include "Utils.h"
using namespace std;
#include "Flota.h"
#include "Bus.h"

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

//         chofer 
//AXZ123,Erasmo Gomez,3,Lima,Chincha,Pisco
void Flota::cargar_buses(){
    ifstream arch("Buses.txt",ios::in);
    if(!arch.is_open()) cout<<"piipip"<<endl; 
    
    while(true){
        //Debido a q bus tiene una estructura compleja (vector adentro)
        Bus bus;
        bus.leer(arch);
        if(arch.eof()) return;
        // adicionamos el bus al vetor de buses
        buses.push_back(bus);
        
    }
}

//Lima,12.45,56.34
void Flota::cargar_ciudades(){
    ifstream arch("Ciudades.txt",ios::in);
    if(!arch.is_open()) cout<<"piipip"<<endl; 
    
    
    while(true){
        Ciudad ciudad;
        ciudad.leer(arch);
        if(arch.eof()) return;
        //
        ciudades.push_back(ciudad);
        //ciudad.mostra();
    }
}

//iterator ordenar y msotrar una pos en especifica
void Flota::mostrar_buses() const{//en otro
    int i=0;
    //forma 1
    for(const Bus &b:buses){// for(Bus b:buses)
        cout<<i<<": "<<b.GetPlaca()<<" "<<b.GetNombre_chofer()<<
                " "<<b.GetN_pasajeros()<<endl;
        //b.imprime_rutas();
        i++;
    }
    //forma 2
//    for( int i= 0; i!= buses.size();i++ ){
//        cout<<i<<": "<<buses[i].getPlaca()<<" "<<buses[i].getNombre_chofer()<<endl;
//        buses[i].mostrar_rutas();
//    }
}

void Flota::mostrar_buses2(){
    //cout<<"Ola"<<endl;
    int i=0;
    // es un puntero
    for(vector<Bus>::iterator it=buses.begin(); it!=buses.end();it++){
        //cout<<"Ola"<<endl;        
        cout<<i<<": "<<(*it).GetPlaca()<<"  "<<(*it).GetNombre_chofer()<<endl;
        (*it).imprime_rutas();
        i++;
    }
    cout<<endl;
}

void Flota::armar_rutas(){
    //MAP : rutas
    //recorremos todos los buses, obtenemos su palca y las ciudades
    for(const Bus &b:buses){
        for(int i=0;i<b.GetN_rutas();i++){
            string ciudadActual = b.getCiudadActual(i);
            //busco la ciudad en el vector de ciudades
            int pos = buscarCiudad(ciudadActual);
            string keyMapa = b.GetPlaca();
            //MAPA: placa(key) ciudades (values) 
            rutas[keyMapa].push_back(ciudades[pos]); // el mapa de por si le crea las keys vacias
        }
    }
}

int Flota::buscarCiudad(string ciudadActual)const {
    string ciudLeid;
    
    for(int i=0; i<ciudades.size();i++){
        ciudLeid = ciudades[i].GetNombre();
        if(ciudLeid==ciudadActual) return i;
    }
    return -1;
}


void Flota::mostrar_ciudades() const {
    int i=0;    
    cout<<"Ciudades "<<endl;
    for(const Ciudad &c:ciudades){// for(Bus b:buses)
//        cout<<i<<": "<<c.GetNombre()<< "  "<<c.GetCord_x()<<"("
//                <<c.GetCord_x()<<","<<c.GetCord_y()<<" )"<<endl;
        c.mostra();
        i++;
    }
}

void Flota::imprimir_rutas(const char *filename){
    ofstream arch(filename,ios::out);
    if(!arch.is_open()) cout<<"piipip"<<endl; 
    
    arch<<"MAP: RUTAS (PLACA) - CIUDADES"<<endl;
    for(const auto & p: rutas){
        arch<<p.first<<endl;
        arch<<"ciudades: "<<endl;
        vector < Ciudad > value_ciudad = p.second; //agarra al vector de ciudades de esa placa
        for(const auto & ciu: value_ciudad){
            ciu.mostra(arch);
        }
        arch<<endl;
    }
}

//void GrafoDirigido::imprimirGrafo() const {
//    for (const auto& par : adyacencias) { //For each
//        Persona persona = par.first; //Key
//        cout << "Persona: ";
//        persona.imprimirPersona();
//        cout << "Conectada con:"<<endl;
//        for (const Persona& vecino : par.second) { //Recorrer los values
//            vecino.imprimirPersona();
//        }
//        cout <<"*************"<<endl;
//    }
//}