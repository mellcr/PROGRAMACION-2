
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 25 de mayo de 2024, 16:07
 */

#include "Utils.h"
#include "Pokeball.h" // CLASE DERIVADA - HIJA 
#include "Consumible.h"
#include "Item.h"     // CLASE PADRE 
using namespace std;

/*
 *  HERENCIA 
 */
int main(int argc, char** argv) {
    Item i;
    
    i.SetNombre("Pokeball");
    i.SetDescripcion("Es una pokebola normal");
    i.mostrar();
//    char buffer[20];
//    i.GetNombre(buffer);
//    cout<<buffer<<endl;
    
    // USO LOS METODOS DE LA CLASE PADRE PARA LA CLASE DERIVADA 
    Pokeball p;
    p.SetNombre("Master Ball");
    p.SetDescripcion("Es una master ball poderosa ");
    p.mostrar(); // metodo exclusivo para pokeball 
//    char buffer2[20];
//    p.GetNombre(buffer2);
//    cout<<buffer2;
    
    Consumible c;
    c.SetNombre("Baya");
    c.SetDescripcion("Cura 10 de hp");
    c.mostrar(); // metodo exclusivo para pokeball 

    
    return 0;
}

