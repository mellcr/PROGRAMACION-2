/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Utils.h"
using namespace std;
#include "funcionesVoid.h"
enum Reg{DNI,NOMBRE,SUELDO};

void leerDatos(void *&personal,int &np){
    ifstream arch("personal.csv",ios::in);
    void *registro, *buffer[200]{};
    np = 0;
    while(true){
        registro = leeReg(arch);
        if(registro==nullptr) break;
        buffer[np] = registro;
        np++;
    }
    void **personas = new void  *[np+1]{};
    for(int i=0;i<np;i++){
        personas[i]= buffer[i];
    }
    personal=personas ;
}

void *leeReg(ifstream &arch){
    void **registro;
    int *dni = new int;
    char buff[200], *nomb;
    double *sueldo = new double;
    
    arch>>*dni;
    if(arch.eof()) return nullptr;
    arch.get();
    arch.getline(buff,200,',');
    nomb = new char[strlen(buff)+1]{};
    strcpy(nomb,buff);
    arch>>*sueldo;
    arch.get();
    
    registro = new void*[3];
    registro[DNI] = dni;
    registro[NOMBRE] = nomb;
    registro[SUELDO] = sueldo;
    
    return registro;
}

void imprimirDatos(void *personal,int np){
    void **arr_personal = (void **)personal;
    
    for(int i=0;i<np;i++){
        imprimeUnaPersona(arr_personal[i]);
    }
}

void imprimeUnaPersona(void *persona){
    void **arrPersona = (void **)persona; //accede a los campos de la persona 
    int *dni = (int *)arrPersona[DNI];
    char *nombre = (char *)arrPersona[NOMBRE];
    double *sueldo = (double *)arrPersona[SUELDO];
    
    
    cout.precision(2);
    cout<<fixed;
    cout <<left<<setw(10)<<*dni<<setw(40)<<nombre<<setw(10)<<*sueldo<<endl;
}