/* 
 * Proyecto: FIJA_V2_3voids
 * Archivo:   func.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 24 de abril de 2024, 17:16
 */

#include "utils.h"
#include "func.h"
#include "AperturaDeArchivos.h"
using namespace std;
enum Cli{DNI,NOMBRE};
enum Lib{CODIGO,TITULO,AUTOR,STOCK,PRECIO};
enum Ped{NPED,CLI,NOMB,PEDIDOS,NUMLIB}; 
    
char *leeCadDelim(ifstream &arch, char delim){
    char *str, aux[100];
    
    arch.getline(aux,100,delim); 
    str = new char[strlen(aux)+1];
    strcpy(str,aux); 
    
    return str; 
}
void *leeRegCli(ifstream &arch){
    void **registro=new void*[4];
    int *dni;
    char *nomb;
    
    dni = new int;
    
    arch>>*dni;
    if(arch.eof()) return nullptr;
    arch.get();
    nomb = leeCadDelim(arch,'\n');
    
    registro[DNI]=dni;
    registro[NOMBRE] = nomb;
    
    
    return registro;
}
void cargaClientes(void *&clientes){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Cientes.csv");
    
    //registro
    void *registro, *buff[200]{};
    //aux
    int numDat=0;
    while(true){
        registro = leeRegCli(arch);
        if(registro ==nullptr) break;
        
        buff[numDat] = registro; 
        numDat++;
    }
    
    void **arr_cli = new void*[numDat+1]{};
    for(int i=0;i<numDat;i++){
        arr_cli[i] = buff[i];
//        void **cli = (void**)arr_cli[i];
//        int *dni_aux = (int *)cli[DNI];
//        cout << *dni_aux<<endl;
    }
    clientes = arr_cli;
}

void *leeRegLib(ifstream &arch){
    void **registro=new void*[5];
    
    char *autor,*nomb,*cod,c;
    int *stock;
    double *precio;
    
    stock = new int;
    precio = new double;
    
    cod = leeCadDelim(arch,',');
    if(arch.eof()) return nullptr;
    nomb=leeCadDelim(arch,',');
    autor=leeCadDelim(arch,',');
    arch>>*stock>>c>>*precio;
    arch.get(); //lee el salto de liena 
    
    registro[CODIGO]=cod;
    registro[TITULO] = nomb;
    registro[AUTOR] = autor;
    registro[STOCK] = stock;
    registro[PRECIO] = precio;
    
    return registro;
}
//enum Lib{CODIGO,TIULO,AUTOR,STOCK,PRECIO};
void cargaLibros(void *&libros){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Libros.csv");
    
    void *registro,*buff[300]{};
    int numDat=0;
    while(true){
        registro = leeRegLib(arch);
        if(registro==nullptr) break;
        
        buff[numDat]=registro;
        numDat++;
    }
    void **arr_lib = new void*[numDat+1]{};
    for(int i=0;i<numDat;i++){
        arr_lib[i] = buff[i];
//        void **lib = (void**)arr_lib[i];
//        int *stock_aux = (int *)lib[STOCK];
//        cout << *stock_aux<<endl;
    }
    
    libros = arr_lib;
}


void cargaPedidos(void *pedidos,void *clientes,void *libros){
    ifstream arch; 
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Pedidos.txt");
    
    void *registro, *buffPed[200]{};
    
    int numDat=0; 
    while(true){
        registro = leeRegPedido(arch,libros,clientes);
        if(registro==nullptr); 
        buffPed[numDat] = registro;
        numDat++;
    }
}
//enum Ped{NPED,CLI,NOMB,PEDIDOS,NUMLIB};
void *leeRegPedido(ifstream &arch,void *libros,void *clientes){
    void **registro = new void*[5];
    int *numPed = new int, *dni = new int, cantLib; 
    void *pedidosXCliente; 
    
    
    
}

void pedidosExactosCliente(void *&pedidosXCliente,ifstream &arch,int &cantLib,void *libros){
    
    
    
}

