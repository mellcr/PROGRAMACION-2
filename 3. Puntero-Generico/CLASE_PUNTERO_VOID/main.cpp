/* 
 * Proyecto: CLASE_PUNTERO_VOID
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 11 de abril de 2024, 8:27
 */

#include <iostream>
#include <iomanip> 
using namespace std;

int main(int argc, char** argv) {
    void *generico, *generico1; 
    int a=64; 
    char b[20] = "hola que tal"; 
    generico = &a; 
    //cout << generico<<endl; //imprie la direcc 
    //cout << &a<<endl; 
    
    //cout << (int*)generico << endl;  // imprime la dire
    cout << *(int*)generico << endl;  // lo referenciamos con *
    cout << a << endl; 
    cout <<"imprime el ascii: "<< (char *)generico << endl<<endl; //recordar q no es correcto hacer esto 
    
    
    generico1 = b; 
    cout << (char*) generico1 << endl; //correcto
    cout << *(int*)generico1 <<endl;  //???
    cout << ((int *)generico1)[3]<<endl; //esta muy al fondo de la comp 
    
    
    return 0;
}

