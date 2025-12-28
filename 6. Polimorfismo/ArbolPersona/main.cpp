
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 8 de junio de 2024, 20:26
 */

#include "Utils.h"
#include "Arbol.h"
#include "Persona.h"
using namespace std;

/*
 *      ARBOL CON DATOS PERSONA
 */
int main(int argc, char** argv) {
    class Arbol arbol;
    arbol.crear("personas.csv");
    arbol.mostrarEnOrden("Reporte-EnOrden.txt");
    
    char buffN[50];
    class Persona p;
    p = arbol.buscar(250612);
    if(p.GetDni()!=-1){
        p.GetNombre(buffN);
        cout<<"Dato buscado: "<<endl
                <<p.GetDni()<<"  "<<buffN<<"  "<<p.GetSueldo()<<endl;
    }
    else{ 
        cout<<"No se encontro"<<endl;
    }
    
    return 0;
}

