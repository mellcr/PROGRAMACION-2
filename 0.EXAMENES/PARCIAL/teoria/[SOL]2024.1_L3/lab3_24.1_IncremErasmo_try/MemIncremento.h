/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MemIncremento.h
 * Author: mell1
 *
 * Created on 12 de mayo de 2024, 19:05
 */

#ifndef MEMINCREMENTO_H
#define MEMINCREMENTO_H
using namespace std;
char *leeCadTxt(ifstream &arch);
void lecturaDeLibros(const char *filename,char ***&libros,int **&stock);
char *leeCadDelim(ifstream &arch, char delim);
void asignaMemLib(char ***&libros,int **&stock,int &numLib,int &capLib);
void colocarDatos(char *codLib,char *titulo,char *autor,int stockLib,char **&libros,
        int *&stock);
void imprimeLibro(ofstream &arch,char **libro,int *stock);
void pruebaDeLecturaDeLibros(const char*filename,char ***libros,int **stock);
//
void atencionDePedidos(const char*filename,char ***&libros,int **&stock,
        int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos);
int buscarCli(int dniBus,int **pedidosClientes);
void asignaMemCli(int **&pedidosClientes,int &numCli,int &capCli);
void incrementoEspaciosCli(int *&pedidosCliente,int &num,int &cap);
void colocaCli(int dniLeid,int numLeid,int *&pedidosCliente,int &numPedCli,
                    int &capPedCli);
void colocaDatosCliente(int posCli,int dniLeid,int numLeid,int **&pedidosClientes,
        int &numCli, int *numPedCli, int *capPedCli);
// PARA ESTRUCTURAS DE PEDIDO
void incrementaMemPed(char ***&pedidosLibros,bool **&pedidosAtendidos,int &numPed,
                int &capPed,int numLeid);
void colocaDatosPedidos(int numLeid,char **codigos,char ***&pedidosLibros,
        bool **&pedidosAtendidos,int *numPedLib,int *capPedLib, int &numPed,
        int **&stock, char ***libros);
void incremEspPed(char **&librosPedidos,int &num,int &cap);
char ** leerLibrosPedidos(ifstream &arch,int &capPedLib,int &numPedLib);
int buscarProd(char *codBus,char ***libros);
int BuscarLibro(char ***Libros,char *PedLibros);
bool* llenaPedAtendido(char **codigosLeid,char **listaLibPed,int **&stock,char ***libros,
        int numPedLib, int capPedLib);
void incremEspPed(bool *&pedAtend,int &num,int &cap);
//
void pruebaPedidosCli(const char*filename,int **pedidosClientes,char ***pedidosLibros,
        bool **pedidosAtendidos);
#endif /* MEMINCREMENTO_H */

