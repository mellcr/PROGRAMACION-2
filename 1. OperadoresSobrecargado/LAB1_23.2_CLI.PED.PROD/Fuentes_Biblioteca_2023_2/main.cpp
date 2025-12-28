/* 
 * Proyecto: Fuentes_Biblioteca_2023_2
 * Archivo:   main.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 29 de marzo de 2024, 17:05
 */

#include "Utils.h"
#include "Estructuras.h"
#include "AperturaDeArchivos.h"
//#include "Sobrecargas.h"
#include "Funciones.h"
#define NMAX 600
using namespace std;

int main(int argc, char** argv) {
    //inicializamos nuestros arreglos de estructuras
//    struct Cliente clientes[NMAX]={},cli; 
//    struct Producto productos[NMAX]={},prod;
//    struct Pedido pedidos[NMAX]={},ped;
//    
//    ifstream archPed,archProd,archCli;
//    AperturaDeUnArchivoDeTextosParaLeer(archCli,"Clientes.csv");
//    AperturaDeUnArchivoDeTextosParaLeer(archPed,"Pedidos.csv");
//    AperturaDeUnArchivoDeTextosParaLeer(archProd,"Productos.csv");
//    ofstream repCli, repProd;
//    AperturaDeUnArchivoDeTextosParaEscribir(repCli,"reporteCli.txt");
//    AperturaDeUnArchivoDeTextosParaEscribir(repProd,"reporteProd.txt");
//    
//    int n=0; 
//    while(archCli>>cli){
//        lee un cliente
//        clientes[n] = cli; 
//        n++; 
//    }
//    
//    int a=0; 
//    while(archProd>>prod){
//        //lee un cliente
//        productos[a] = prod; 
//        a++; 
//    }
//     copia la ult cadena con 
//    strcpy(productos[a].codigo,"XXXXXXX"); 
//    
//    
//    int d=0; 
//    while(archPed>>ped){
//        //lee un cliente
//        pedidos[d] = ped; 
//        d++; 
//    }
//    
//
//    clientes += ped; 
//    productos += ped; 
//    
    ifstream arch("prueba.txt",ios::in);
    ofstream rep("reporte.txt",ios::out);
    struct Cliente c;
    struct Cliente C[2]{};
    struct Producto pro;
    struct Producto Pro[2]{"XXXXXXX"};
    struct Pedido ped;
    arch >> c;
    arch.get();
    arch >> pro;
    arch >> ped;
    C[0] = c;
    C[1].dni = 0;
    Pro[0] = pro;
    strcpy(Pro[0].codigo,pro.codigo);
    strcpy(Pro[1].codigo,"XXXXXXX");
    C+=ped;
    Pro+=ped;
    rep << C[0];
    rep << Pro[0];
    
    return 0;
}

