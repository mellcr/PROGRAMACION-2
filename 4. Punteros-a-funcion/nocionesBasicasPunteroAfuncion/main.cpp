/* 
 * File:   main.cpp
 * Author: mell1
 *
 * Created on 27 de abril de 2024, 16:28
 */

#include <iostream>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;

double division(int a, int b){
	return (double)a/b;
}
double promedio(int a, int b){
	return (double)(a+b)/2;
}
double f(int a, int b){
	return sqrt(a); 
}

int multiplicacion(int a, int b){
    return a*b;
}

/////////////////////// FUNCIONES GENERICAS ////////////////////////////////////////////////
int operacion(int p, int g,int (&pF)(int ,int) ){//los mismos parametros + pF
    return pF(p, g);
}
double ejecutar_func(int a, int b, double (*erasmo)(int,int)){
    return erasmo(a,b); 
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv) {
    int a=15, b=3,c; 
    int (*ptFunc)( int , int );
    
    ptFunc = multiplicacion; //asigna la direccion 
    //cout <<"Forma 1: "<<ptFunc(a,b)<<endl;
    //cout <<"Forma 2: "<<multiplicacion(a,b)<<endl; 
    c=ptFunc(a,b);
    //cout <<"Forma 3: "<<c<<endl;
    ///////////////////////////// DIRECTO /////////////////////////////////////////////////////
    c = operacion(a,b,multiplicacion); //le pasa cualquier nombre de funcion del tipo (int, int) 
    cout <<"FORMA DIRECTA MULT: "<<c<<endl;
    //////////////////////////// ARREGLO DE PUNTEROS A FUNCION /////////////
    for(int i=0;i<60;i++) cout.put('-');
    double (*arr_f[3])(int, int){division,promedio,f}; 
    cout<<endl<<"sqrt: "<<arr_f[2](a,b) << endl; 
    double z; 
    double (*pf)(int,int); 
    
    z=ejecutar_func(a,b,arr_f[0]); 
    cout << "Division: "<<z<<endl;
    z = ejecutar_func(a,b,promedio); 
    cout << "Promedio: "<<z<<endl;
    return 0;
    
    
    
    
    
}

