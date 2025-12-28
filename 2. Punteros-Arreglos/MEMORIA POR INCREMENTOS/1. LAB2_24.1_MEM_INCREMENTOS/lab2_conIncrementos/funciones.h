/* 
 * Proyecto: lab2_conIncrementos
 * Archivo:   funciones.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 18 de abril de 2024, 9:15
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
using namespace std; 
void lecturaDeLibros(const char*archName,char ***&libros,int **&stock); 
void pruebaDeLecturaDeLibros(const char*archName,char ***libros,int **stock); 
char *leeCadDelim(ifstream &archLib,char delim); 
void asignarDatosDelLibro(char **&libros,int *&stock,char *cod,char *nomb,
        char *autor,int cantStok); 
void reservaMemIncrementos(char ***&libros,int **&stock,int &numLib,int &capacity); 


void atencionDePedidos(const char*filename,char ***libros,int **&stock,
        int **&pedidosClientes,char ***&pedidosLibros, bool **&pedidosAtendidos);
char *leeCadCin(ifstream &archLib); 
char **LeeLibPorPed(ifstream &archPed); 
void incrementarPedLib(char **&pedidosLibros_,int &numLib,
                int &capLib); 
void IncrementarEspaciosClientes(int **&pedidosClientes,
                int &cantCli,int &capacityCli,int *&arr_nPedCli,int *&arr_CapPedCli);
void IncrementarEspaciosPedidos(int &cantPed,int &capacityPed, char ***&pedidosLibros,
        bool **&pedidosAtendidos);
int buscarCliente(int **pedidosClientes,int dni);
void ColocarDatos(int**&PedidosClientes,char*** &PedidosLibros,bool **&PedidoAtendidos,
        int &nClientes,int &nPedido,int posDni,int dni,int numPedido,int *&Arr_nPedCli,
        int *&Arr_CapPedCli, char **CodigoPedLib,char ***Libros,int **&stock);
void IncrementarPedidoClientes(int *&PedCliente,int &nPedCli,int &CapPedCli);
int* ColocarPedidosCliente(int dni,int numPedido,int *&PedidosClientes,int &nPedCli,
        int &CapPedCli); 
#endif /* FUNCIONES_H */

