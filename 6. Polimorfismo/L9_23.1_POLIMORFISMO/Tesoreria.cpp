
/* 
 * File:   Tesoreria.cpp
 * Author: mell1
 * 
 * Created on 9 de junio de 2024, 15:01
 */

#include "Utils.h"
#include "Tesoreria.h"
using namespace std;

Tesoreria::Tesoreria() {

}

Tesoreria::~Tesoreria() {
}

void Tesoreria::cargaescalas(){
    ifstream arch("escalas.csv",ios::in);
    if(!arch.is_open()){
        cout<<"No se abrio"<<endl;
        exit(1);
    }
    int cod;
    double prec;
    while(true){
        arch>>cod;
        if(arch.eof()) break;
        arch.get();
        arch>>prec;
        
        lescala[cod-1].SetCodigo(cod);
        lescala[cod-1].SetPrecio(prec);
    }
}

void Tesoreria::cargaalumnos(){
    ifstream arch("alumnos.csv",ios::in);
    if(!arch.is_open()){
        cout<<"No se abrio"<<endl;
        exit(1);
    }
    
    char tipo;
    int numDat=0;
    while(true){
        arch>>tipo;
        if(arch.eof()) break;
        arch.get();
        
        lboleta[numDat].asignaMemoria(tipo);
        lboleta[numDat].leeDatos(arch);
        
        numDat++;
    }
}

void Tesoreria::actualizaboleta(){
    int esc;
    double prec;
    for(int i=0; lboleta[i].hayDato();i++){
        // se saca el precio aqui, porque en tesoreria tenemos la info de ESCALA
        esc = lboleta[i].GetEscala();
        prec=lescala[esc-1].GetPrecio();
        lboleta[i].actualizaBoleta(prec);
    }
}



void Tesoreria::imprimeboleta(){
    ofstream arch("Reporte.txt",ios::out);
    if(!arch.is_open()){
        cout<<"No se abrio"<<endl;
        exit(1);
    }
    
    arch<<left<<setw(10)<<"Codigo"<<setw(50)<<"Nombre"<<right<<setw(3)<<" "<<"Escala"<<
            setw(12)<<" "<<"Creditos"<<setw(5)<<" "<<"Licencia"<<setw(5)<<" "
            << "Total"<<endl;
    for(int i=0;i<100;i++) arch<<'-';
    arch<<endl;
    for(int i=0; lboleta[i].hayDato();i++){
        lboleta[i].imprimeBoleta(arch);
    }
}
    