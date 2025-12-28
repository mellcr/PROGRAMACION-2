
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 22 de junio de 2024, 17:27
 */
#include "Utils.h"
#include <map> //biblioteca map 
#include <iterator>
#include "Persona.h"
using namespace std;

/*
 * STL - Map , simula tabla hash
 */
int main(int argc, char** argv) {
    //clave(first) dato(second)
    map<int,double>mapaDbl;
    
    // no hay repetidos
    mapaDbl[3] = 33.1;
    mapaDbl[8] = 8.1;
    mapaDbl[2] = 22.1;
    mapaDbl[10] = 100.1;
    mapaDbl[5] = 99.1;
    mapaDbl[4] = 44.1;
    mapaDbl[2] = 20.20; //chanca el valor anterior pq no permite repetidos
    
    //aca no funciona el * 
    // los datos salen ordenados, sin huecos
    for(map<int,double>::iterator it=mapaDbl.begin();it!=mapaDbl.end();
            it++){
        cout << setw(4)<< it->first << " - " << setw(10)<<it->second<<endl;
    }
    
    int p;
    cout <<endl<<"Ingrese una posicion: ";
    p=6; //no está en la lista -> da un valor nulo, en esta caso int=0
    cout<<endl<<"Dato = "<<mapaDbl[p]<<endl;
    
    //////////////////////// PERSONA ////////////////////////////
    map<int,Persona>mPer;
    Persona per;
    ifstream arch("personal.csv",ios::in);
    if(!arch){
        cout<<"pipiip"<<endl;
        exit(1);
    }
    
    while(true){
        arch>>per;
        if(arch.eof()) break;
        mPer[per.GetDni()] = per;
    }
    //IMPRESION - salen ordenados por dni pq esa es la clave
    cout<<endl<<"Impresion mapa de personas: "<<endl;
    for(map<int,Persona>::iterator it = mPer.begin(); it!=mPer.end();
            it++){
        cout<<it->second; 
    }
    //BUSQUEDA
    int dniBuscado = 275448;
    cout<<"Clave(dni) buscada: "<<endl<<mPer[dniBuscado]<<endl;
    
    return 0;
}

