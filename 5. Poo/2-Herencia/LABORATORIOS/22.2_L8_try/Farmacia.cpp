
/* 
 * File:   Farmacia.cpp
 * Author: mell1
 * 
 * Created on 30 de mayo de 2024, 12:50
 */
#include "Utils.h"
#include "Farmacia.h"
using namespace std; 

Farmacia::Farmacia() {
}

Farmacia::Farmacia(const Farmacia& orig) {
}

Farmacia::~Farmacia() {
}

void Farmacia::cargamedido(){
    ifstream arch("medicos.txt",ios::in); 
    if(not arch.is_open()){
        cout <<"no se abrio"<<endl; 
        exit(1); 
    }
    
    int nMed=0; 
    while(true){
        lmedico[nMed].leer(arch);
        if(arch.eof()) break;
        nMed++; 
    }
    lmedico[nMed].SetCodigo(0); //marca el fin 
    
}


void Farmacia::leerecetas(){
    ifstream arch("recetas.txt",ios::in); 
    if(not arch.is_open()){
        cout <<"no se abrio"<<endl; 
        exit(1); 
    }
    int dia,mes,anho,dniCli,codMedico, fecha; 
    char c, nombCli[60]; 
    
    while(true){
        arch>>dia; 
        if(arch.eof()) break; 
        arch>>c>>mes>>c>>anho>>c>>dniCli>>c; 
        arch.getline(nombCli,60,','); 
        arch>>codMedico>>c; 
        fecha = 100000*anho + 100*mes + dia; 
        
        asignaMedicamentos(arch,fecha,dniCli,nombCli,
                codMedico); 
    }
} 

void Farmacia::asignaMedicamentos(ifstream &arch,
        int fecha,int dniCli,char *nombCli,int codMedico){
    
    int codMedicam,cant,nConRec=0, nSinRec=0, posMedico,codigoM; 
    char c, buffEspc[60]{}; 
    
    while(arch.get()!='\n'){
            arch>>codMedicam>>c>>cant; 
            codigoM = codMedicam;
            if((codMedicam/10000)%2==0){ //ES PAR 
                posMedico = buscarEnMedico(codMedico); 
                if(posMedico!=-1){
                    lmedico[posMedico].GetEspecialidad(buffEspc);
                    lconreceta[nConRec].leer(codMedico, 
                    codigoM,cant,fecha,buffEspc); 
                    nConRec++; 
                }
            }
            else{
               lsinreceta[nSinRec].leer(dniCli,nombCli,codMedicam,cant,
                       fecha); 
                nSinRec++;  
            }
        }
}

int Farmacia::buscarEnMedico(int codBus){
    for(int i=0; lmedico[i].GetCodigo(); i++){
        if(codBus == lmedico[i].GetCodigo()) return i;
    }
    return -1; 
}
//es un reporte de CONRECETAS y SINRECETAS 
void Farmacia::imprimirrecetas(){
    ofstream arch("ReporteFinal.txt",ios::out); 
    if(not arch.is_open()){
        cout <<"no se abrio"<<endl; 
        exit(1); 
    }
    
    arch<<left<<setw(10)<<"Codigo"<<setw(50)<<"Descripcion"<<right<<setw(10)<<" "
            <<setw(5)<<"Cant."<<setw(10)<<" "<<setw(10)<<"DNI"<<left<<setw(5)<<" "
            <<setw(50)<<"Nombre"<<endl;
    for(int i=0;lsinreceta[i].GetCodigo();i++){
        lsinreceta[i].imprime(arch);
    }
    
    arch<<left<<setw(10)<<"Codigo"<<setw(50)<<"Descripcion"<<right<<setw(10)<<" "
            <<setw(5)<<"Cant."<<setw(10)<<" "<<setw(10)<<"Cod. Med"<<left
            <<setw(5)<<" "<<setw(50)<<"Especialidad"<<endl;
    for(int i=0;lconreceta[i].GetCodigo();i++){
        //cout <<lconreceta[i].GetCodigo()<<endl;
        lconreceta[i].imprime(arch);
    }
}