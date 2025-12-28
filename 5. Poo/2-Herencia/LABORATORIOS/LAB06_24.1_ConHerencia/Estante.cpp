
/* 
 * File:   Estante.cpp
 * Author: mell1
 * 
 * Created on 30 de mayo de 2024, 22:04
 */
#include "Utils.h"
#include "Estante.h"
using namespace std;
#define N 50

Estante::Estante() {
}

Estante::Estante(const Estante& orig) {
}

Estante::~Estante() {
}

void Estante::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Estante::GetCantidad_libros() const {
    return cantidad_libros;
}

void Estante::SetAltura(int altura) {
    this->altura = altura;
}

int Estante::GetAltura() const {
    return altura;
}

void Estante::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estante::GetAnchura() const {
    return anchura;
}

void Estante::SetCodigo(const char* codigo) {
    if(this->codigo!=nullptr) delete this->codigo;
    //asignamos memoria
    this->codigo = new char[strlen(codigo)+1];
    strcpy(this->codigo,codigo);
}

void Estante::GetCodigo(char *c) const {
    if(this->codigo==nullptr) c[0] = 0;
    else strcpy(c,this->codigo);
}

//

void Estante::leer(ifstream &arch){
    char codigo[10];
    int altura,anchura;
    arch.getline(codigo,10,',');
    if(arch.eof())return;
    arch>>anchura;
    arch.get();
    arch>>altura;
    arch.get(); 
    //seteamos lo leido y creamos espacios 
    SetAltura(altura);
    SetAnchura(anchura);
    SetCodigo(codigo);
    creaEspacios();
}

void Estante::creaEspacios(){
    int anch=0, alt=0; //contadores para guardar posx, posy
    
    if(altura!=0 and anchura!=0){
        espacios = new class Espacio[anchura*altura];
        for(int i=0; i<anchura*altura; i++){
            espacios[i].SetPosx(alt);
            espacios[i].SetPosy(anch);
            anch++;
            
            if(anch==anchura){
                anch=0;
                alt++;
            }
        }
    }
}
    
void Estante::imprimir(ofstream &arch){
    arch<<left<<setw(15)<<"Codigo Estante: "<<setw(10)<<codigo
            <<"Cantidad de Libros:"<<setw(5)<<cantidad_libros<<endl;
    arch<<left<<setw(20)<<"Anchura del Estante: "
            <<setw(5)<<GetAnchura()<<"Altura del Estante: "
            <<GetAltura()<<endl;
    for(int i=0; i<N; i++)arch.put('-');
    arch<<endl;
    
    imprimeEspacios(arch);
    imprimeLibros(arch);
}

void Estante::imprimeEspacios(ofstream &arch){
    for(int i=0;i<anchura*altura;i++){
        espacios[i].imprimir(arch);
        if(espacios[i].GetPosy()==anchura-1) arch<<endl;
    }
}

void Estante::imprimeLibros(ofstream &arch){
    arch<<left<<setw(10)<<"CODIGO"<<setw(25)<<"NOMBRE"<<setw(10)<<
            "ANCHO"<<"ALTO"<<endl;
    for(int i=0; i<N; i++)arch.put('.');
    arch<<endl;
    // IMPRESION DEL ARREGLO DE LIBROS
    for(int i=0; i<cantidad_libros;i++){
        libros[i].imprimir(arch);
    }
    arch<<endl;
}
    

bool Estante::operator +=(class Libro &libro){
    int espacioLibre = calcularEspaciosLibres(), altoLibro,anchoLibro;
    altoLibro = libro.GetAlto();
    anchoLibro = libro.GetAncho();
    
    if(anchoLibro <=espacioLibre and altoLibro<=altura and espacioLibre>0){
     colocarLibro(altoLibro,anchoLibro,espacioLibre); 
     char nomb[60], cod[20]; 
     libro.GetCodigo(cod); 
     libro.GetNombre(nomb); 
     //agregamos el libro 
     libros[cantidad_libros].SetNombre(nomb); 
     libros[cantidad_libros].SetAlto(libro.GetAlto()); 
     libros[cantidad_libros].SetAncho(libro.GetAncho()); 
     libros[cantidad_libros].SetCodigo(cod); 
     libros[cantidad_libros].SetColocado(true); 
     return true; 
    }
    else{
        return false; 
    }
}

//suma la anchura de todos los libros colocados -> retorna la resta (espLibres)
int Estante::calcularEspaciosLibres(){
    int sumaAnchLib=0;
    
    for(int i=0; i<cantidad_libros;i++){
        sumaAnchLib += libros[i].GetAncho();
    }
    return anchura-sumaAnchLib;
}

void Estante::colocarLibro(int altLibro, int ancLibro, int sobrante){
    int posLib = altura*anchura - sobrante; 
    for(int i=0; i<altLibro; i++){
        for(int k=0; k<ancLibro; k++){
            espacios[posLib+k].SetContenido('*'); 
        }
        posLib -=anchura; 
    }
}
    