
/* 
 * File:   Item.cpp
 * Author: mell1
 * 
 * Created on 25 de mayo de 2024, 16:08
 */
#include "Utils.h"
#include "Item.h"
using namespace std;

Item::Item() {
    descripcion = nullptr;
    nombre = nullptr;
}

Item::Item(const Item& orig) {
}

Item::~Item() {
}

void Item::SetDescripcion(const char* descripcion) {
    if(this->descripcion) delete this->descripcion;
    this->descripcion = new char [strlen(descripcion)+1];
    strcpy(this->descripcion,descripcion);
}

void Item::GetDescripcion(char *c) const {
    if(this->descripcion==nullptr) c[0] = 0;
    else strcpy(c,this->descripcion);
}

void Item::SetNombre(const char* nombre) {
    if(this->nombre) delete this->nombre;
    this->nombre = new char [strlen(nombre)+1];
    strcpy(this->nombre,nombre);
}

void Item::GetNombre(char *c) const {
    if(this->nombre==nullptr) c[0] = 0;
    else strcpy(c,this->nombre);
}

//de esta forma se obtiene info de un arreglo de otra clase 
//int Item::GetHeroeHp(int indice){
//    return arrheroe[indice].getHp();
//}

void Item::mostrar(){
    cout<<"Clase Padre"<<endl;
    cout<<setw(20)<<nombre;
    cout<<setw(50)<<descripcion<<endl;
}