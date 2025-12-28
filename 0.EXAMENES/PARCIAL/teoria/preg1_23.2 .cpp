#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "funciones.h"
#define INCREMENTO 10

void lecturaDeProductos(const char *nom, char ***&productos, int *&stock, double *&precios){
    ifstream input(nom, ios::in);
    char *codigo_producto, *nombre_producto, car, *decripcion_producto;
    double precios_productos;
    int stock_productos, cantidad_productos = 0, capacity = 0;
    productos = nullptr;
    stock = nullptr;
    precios = nullptr;
    while(true){
        codigo_producto = leerCadena(input, 8, ',');
        if(input.eof()) break;
        decripcion_producto = leerCadena(input,300, ',');
        input>>precios_productos>>car>>stock_productos;
        input.get();
        //resrva de memoria
        if(cantidad_productos == capacity)
            incrementar_productos(productos, stock, precios, cantidad_productos, capacity);
        
        insertarProducto(productos[cantidad_productos-1], stock[cantidad_productos-1],
                precios[cantidad_productos-1], cantidad_productos, codigo_producto, 
                nombre_producto, precios_productos, stock_productos);
    }
}

void incrementar_productos(char ***&productos, int *&stock, double *&precios,int &n,int &c){
    //voy necesitar un arreglo auxiliar por cada elemento
    char **aux_productos;
    int *aux_stock;
    double * aux_precios;
    c += INCREMENTO; // aqui se coloca la funcion de cambio de la capacidad
    if(productos == nullptr){ //significa que estamos en un inicio
        productos = new char**[c]{};
        stock = new int[c]{};
        precios = new double[c]{};
        n = 1;
    }
    else{
        productos = new char**[c]{};
        stock = new int[c]{};
        precios = new double[c]{};
        for(int i = 0; i<n; i++){
            aux_productos[i] = productos[i];
            aux_precios[i] = precios[i];
            aux_stock[i] = stock[i];
        }
        delete productos;
        delete precios;
        delete stock;
        productos = aux_productos;
        precios = aux_precios;
        stock = aux_stock;
    }
    
}

void insertarProducto(char **&productos, int &stock,
                double &precios, int &cantidad_productos, char *codigo_producto, 
                char *nombre_producto, double *precios_productos, int *stock_productos){
    productos = new char*[2]{};
    productos[0] = codigo_producto;
    productos[1] = nombre_producto;
    stock = stock_productos;
    precios = precios_productos;
    cantidad_productos++;
}