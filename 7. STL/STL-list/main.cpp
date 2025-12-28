
/* 
 * File:   main.cpp
 * Author: BlueCod (mell1)
 *
 * Created on 19 de junio de 2024, 14:39
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //constructores: 
//    list<double> lDouble1(10); //10 elementos nulos 
//    list<double> lDouble2(10,22.2); //10 elementos con 22.2
    //metodo
    //lDouble1.assign(10,22,2);
    list<double> lDouble={34.2,55.4,99.2, 21.1,20.2,10.23}; 
    
    if(lDouble.empty()) cout<<"Esta vacia "<<endl;
    else cout<<"No está vacia "<<endl;
    
    cout <<"Tamanho: "<<lDouble.size()<<endl;
    
    cout.precision(2);
    cout<<fixed;
    cout <<"Impresion Ini-Fin: ";
    for(list<double>::iterator it= lDouble.begin();
            it!=lDouble.end();it++){
        cout<<setw(10)<<*it;
    }
    cout<<endl;
    cout <<"Impresion Fin-Ini: ";
    for(list<double>::iterator it= lDouble.end();
            it!=lDouble.begin(); ){ //si se pone it-- se haria al final -> se queire hacer al inicio de cada iteracion 
        it--; // .end() apunta a null, entonces se debe retroceder una pos
        cout<<setw(10)<<*it;
    }
    cout<<endl;
    
    lDouble.push_back(123.2);//ENCOLA
    lDouble.push_front(20.00);// APILA
    
    double primero, ult; // no eliminan los elementos de la lista 
    primero = lDouble.front();
    ult = lDouble.back();
    cout<<"Primero: "<<primero<<"    Ultimo: "<<ult<<endl;
    cout <<"Impresion Ini-Fin: ";
    for(list<double>::iterator it= lDouble.begin();
            it!=lDouble.end();it++){
        cout<<setw(10)<<*it;
    }
    cout<<endl<<endl;
    
    
    //********* ITERADOR *************
    //itt+=2 -> no se puede, pq los elementos no estan continuos
    list<double>::iterator itt1=lDouble.begin(), itt2 = lDouble.end();
    itt1++,itt1++;// apunta a direc 3
    itt2--,itt2--,itt2--;
    for(list<double>::iterator it= lDouble.begin();
            it!=lDouble.end();it++){
        cout<<setw(10)<<*it;
    }
    cout<<endl;
    //lDouble.insert(itt1,2.00);
    for(list<double>::iterator it= lDouble.begin();
            it!=lDouble.end();it++){
        cout<<setw(10)<<*it;
    }
    //lDouble.erase(itt1);
    //BORRAREMOS UN RANGO
    lDouble.erase(itt1,itt2);
    cout<<endl<<"Elimina desde pos3 hasta fin-3: "<<endl;
    for(list<double>::iterator it= lDouble.begin();
            it!=lDouble.end();it++){
        cout<<setw(10)<<*it;
    }
    
    
    return 0;
}

