/* 
 * Proyecto: FIJA_V2_3voids
 * Archivo:   func.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 24 de abril de 2024, 17:16
 */

#ifndef FUNC_H
#define FUNC_H
using namespace std; 

void *leeRegCli(ifstream &arch);
void cargaClientes(void *&clientes); 
char *leeCadDelim(ifstream &arch, char delim);
void cargaLibros(void *&libros);
void *leeRegLib(ifstream &arch);

void cargaPedidos(void *pedidos,void *clientes,void *libros);
void *leeRegPedido(ifstream &arch,void *libros,void *clientes);
#endif /* FUNC_H */

