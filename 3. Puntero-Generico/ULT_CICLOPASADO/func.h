/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   func.h
 * Author: mell1
 *
 * Created on 25 de abril de 2024, 20:15
 */

#ifndef FUNC_H
#define FUNC_H
using namespace std;
  void cargaProductos(void * &productos,const char *filename);
   char *leeCadDelim(ifstream  &arch, char delim);
    void *leeRegLib(ifstream &arch);

 void cargaClientes(void * &clientes,const char *filename);
    void *leeRegCli(ifstream &arch);
    int buscarProducto(char *codLeid,void *productos);
   int buscarCli(int dniLeid,void *clientes);
   void *cargaPedidos(void *productos,void *clientes);
   void agregaPedidos(void *producto,void *cliente, int &cantPedCli,int cant,int dniLeid,char *codLeid);
   void agregaUnPedido(void *arrPedidos,int cantPedCli,char *codLeid,int cant,double total);
      void recortaPedidos(void *cliente,int cantPedCli);
      void recortaExtraPedsCli(void *&arrListaped,int cantPedCli);
#endif /* FUNC_H */

