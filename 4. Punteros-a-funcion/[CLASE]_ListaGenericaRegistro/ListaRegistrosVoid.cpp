/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include "Utils.h"
#include "BibliotecaListaGenerica.h"
#include "ListaRegistrosVoid.h"
using namespace std; 

char *leeCadDelim(ifstream &arch, char delim){
    char *str, buff[100]; 
    
    arch.getline(buff,100,delim); 
    str = new char [strlen(buff)+1]{}; 
    strcpy(str,buff); 
    
    return str;
}
void *leer_registro(ifstream &arch){
    void **registro; 
    int *dni = new int;
    double *sueldo = new double; 
    char *nomb; 
    
    arch>>*dni; 
    if(arch.eof()) return nullptr; 
    arch.get(); 
    nomb = leeCadDelim(arch,','); 
    arch>>*sueldo; 
    arch.get(); 
    
    registro = new void*[3]{}; 
    registro[DNI] = dni;
    registro[NOMB] = nomb; 
    registro[SUELDO] = sueldo; 
    
    return registro; 
}

int cmp_registro_str(const void * a, const void *b){
    //accedemos a los campos de los registros 
    void **regI = (void **)a, **regK = (void **)b; 
    char *nombA = (char *)regI[NOMB], *nombB = (char *)regK[NOMB];
    
    return strcmp(nombA,nombB); 
}





