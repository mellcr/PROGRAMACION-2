/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 8 de septiembre de 2023, 08:02 AM
 */
//Fabrizio Randall Montoya Pinto 20212486
#include "AsignacionDinamicaMemoriaExacta.h"

int main(int argc,char **argv){
  char ***productos,***codigoPedidos;
  int *stock,*fechaPedidos,***dniCantPedidos;
  double *precios;
  
  lecturaDeProductos("Productos.csv",productos,stock,precios);
  pruebaDeLecturaDeProductos("reporteDeProductos.txt",productos,stock,precios);
  lecturaDePedidos("Pedidos.csv",fechaPedidos,codigoPedidos,dniCantPedidos);
  pruebaDeLecturaDeProductos("ReporteDePedidos.txt",fechaPedidos,codigoPedidos,dniCantPedidos);
  //reporteDeEnvioDePedidos("ReporteDeEntregaDePedidos.txt",productos,stock,precios,
    //      fechaPedidos,codigoPedidos,dniCantPedidos);
}
