/* 
 * Proyecto: Fuentes_Biblioteca_2023_2
 * Archivo:   Sobrecargas.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 4 de abril de 2024, 23:40
 */

#include "Utils.h"
#include "Estructuras.h"
using namespace std;


//lee UN CLIENTE
bool operator >>(ifstream &archLectura, struct Cliente &cliente){
    archLectura>>cliente.dni;
    if(archLectura.eof()) return false;
    archLectura.get();
    archLectura.getline(cliente.nombre,60,',');
    archLectura >>cliente.telefono;
    
    //inicializamos lo demas
    cliente.cantidadProductosEntrgados = 0;
    cliente.montoTotal = 0.0; 
    
    return true;
}

//lee UN PRODUCTO 
bool operator >>(ifstream &archLectura, struct Producto &produc){
    archLectura.getline(produc.codigo,8,',');
    if(archLectura.eof()) return false;
    archLectura.getline(produc.descripcion,60,',');
    archLectura >> produc.precio;
    archLectura.get();
    archLectura >>produc.stock; 
    archLectura.get(); //lee el cambio de linea ya que lo primero q se lee es una cadena con getline
    
    //inici
    produc.cantidadClientesNoServidos = 0;
    produc.cantidadClientesServidos = 0;

    return true;
}

bool operator >>(ifstream &archLectura, struct Pedido &pedido){
    
    archLectura.getline(pedido.CodigoProducto,8,',');
    if(archLectura.eof()) return false;
    archLectura>>pedido.dniCliente;
    archLectura.get(); //inicia con cad

    //ACA NO LEE EL PRECIOOOOOOO
    pedido.precioProducto = 0.0;
    
    return true;
}

int buscarCli(int dniBusc,struct Cliente *arrCLi){
    for(int i=0; arrCLi[i].dni!=0; i++){
        if(dniBusc == arrCLi[i].dni) return i; 
    }
    return -1;
}

void operator += (struct Cliente *arrCLi, struct Pedido &ped){
    //tomar dni ped
    int posCLi; 
    posCLi = buscarCli(ped.dniCliente,arrCLi); 
    
    
    
}

int buscarProd(char *codProd,struct Producto *arrProd){
    for(int i=0; strcmp(codProd,"XXXXXX")!=0; i++){
        if(strcmp(codProd,"XXXXXX")==0) return i; 
    }
    return -1;    
}


void operator += (struct Producto *arrProd, struct Pedido &ped){
    int pos;
    pos= buscarProd(ped.CodigoProducto,arrProd);
}

