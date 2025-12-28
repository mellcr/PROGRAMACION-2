/* 
 * Proyecto: Fuentes_Biblioteca_2023_2
 * Archivo:   Funciones.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 31 de marzo de 2024, 12:22
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;
#include "Estructuras.h"

bool operator>>(ifstream&arch, struct Cliente&c) {
  int cod;
  arch >> cod;
  if (arch.eof()){
      //c.dni = 0; 
      return false;
  }
      
  arch.get();
  arch.getline(c.nombre, 60, ',');
  arch >> c.telefono;
  c.dni = cod;
  c.cantidadProductosEntrgados = 0;
  c.montoTotal = .0;
  return true;
}

bool operator>>(ifstream&arch, struct Producto&p) {
  char cod[8];
  char c;
  arch.getline(cod, 8, ',');
  if (arch.eof())return false;
  arch.getline(p.descripcion, 60, ',');
  arch >> p.precio>>c >> p.stock>>ws;
  p.cantidadClientesNoServidos = 0;
  p.cantidadClientesServidos = 0;
  strcpy(p.codigo, cod);
  return true;
}

bool operator>>(ifstream&arch, struct Pedido&p) {
  char cod[8];
  arch.getline(cod, 8, ',');
  if (arch.eof())return false;
  arch >> p.dniCliente>>ws;
  strcpy(p.CodigoProducto, cod);
  p.precioProducto = .0;
  return true;
}

void operator+=(struct Cliente*arrCli, const struct Pedido&p) {
  struct Cliente *c;
  for (int i = 0; arrCli[i].dni; i++) {
    c = arrCli + i;
    if (c->dni == p.dniCliente) {
      strcpy(c->productosEntregados[c->cantidadProductosEntrgados].codigo, p.CodigoProducto);
      c->productosEntregados[c->cantidadProductosEntrgados].precio = p.precioProducto;
      c->cantidadProductosEntrgados++;
      c->montoTotal+= p.precioProducto;
      return;
    }
  }
}

void operator+=(struct Producto*arrPro, const struct Pedido&ped) {
  struct Producto *pro;
  for (int i = 0; strcmp(arrPro[i].codigo, "XXXXXXX"); i++) {
    pro = arrPro + i;
    if (strcmp(pro->codigo, ped.CodigoProducto) == 0) {
      if (pro->stock > 0) {
        pro->stock--;
        pro->clientesServidos[pro->cantidadClientesServidos] = ped.dniCliente;
        pro->cantidadClientesServidos++;
      } else {
        pro->clientesNoServidos[pro->cantidadClientesNoServidos] = ped.dniCliente;
        pro->cantidadClientesNoServidos++;
      }
      return;
    }
  }

}

void operator<<(ofstream&arch,const struct Cliente&c){
  arch << setprecision(2)<<fixed;
  arch <<left<< setw(10)<<c.dni<<setw(40)<<c.nombre
          <<setw(12)<<c.telefono<<setw(10)<<c.montoTotal
          <<"Productos entregados: ";
  struct ProductoEntregado pe;
  for (int i = 0; i < c.cantidadProductosEntrgados; i++) {
    pe = c.productosEntregados[i];
    arch << pe.codigo<< " ";
  }
  if(c.cantidadProductosEntrgados == 0)
    arch << "NO SE LE ENTREGARON PRODUCTOS";
  
  arch<<endl;
}

void operator<<(ofstream&arch,const struct Producto&p){
  arch << setprecision(2)<<fixed;
  arch<<left<<setw(9) << p.codigo<<setw(50)<<p.descripcion
          <<setw(10)<<p.precio<<p.stock<<endl;
  arch << "Clientes atendidos: ";
  
  for (int i = 0; i < p.cantidadClientesServidos; i++) {
    arch << p.clientesServidos[i]<<" ";
  }
  if(p.cantidadClientesServidos==0)
    arch << "NO SE ATENDIERON PEDIDOS";
  arch <<endl;
  arch << "Clientes no atendidos: ";
  for (int i = 0; i < p.cantidadClientesNoServidos; i++) {
    arch << p.clientesNoServidos[i]<<" ";
  }
  if(p.cantidadClientesNoServidos == 0)
    arch << "NO HAY CLIENTES SIN ATENDER";
  arch <<endl;
}