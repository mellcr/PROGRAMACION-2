/* 
 * Proyecto: LAB2_CON_INCREMENTOS
 * Archivo:   funciones.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 16 de abril de 2024, 13:23
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
using namespace std;
void atencionDePedidos(const char *nombPed,char*** libros,int **stock,
        int **pedidosClientes,char ***pedidosLibros,bool **pedidosAtendidos); 
void pruebaDeLecturaDeLibros(const char*filename,char ***libros,
        int **stock);
void pruebaDeLecturaDeLibros(const char*filename,char***libros,int **stock);
void lecturaDeLibros(const char*filename,char***&libros,int **&stock); 
char *asignaCadena(char *cad); 
void llenaLibs(char **&buff_lib,char *codLib,char *nomb,char *autor); 
void llenaStock(int *&buff_stock,int stockDis); 
void imprimeLib(char **libros); 



void asignarMemoriaCliente(int &cantClientes,int *&buffClientes,int dni,
                    int &posCliente);
void agregarNumPedido(int numPed,int *&buffClientes);
char *LeerCadenaTxt(ifstream &archPed); 
int buscarLibro(char ***libros,char *cod);
void asignarMemoriaLibros(char **&buffPedLibros,bool *&buffAtendidos,
                    char *cod,int **&stock,char ***libros,int numPed,
                    int &cantPedidos,int &cantSolicitFil);
void imprimirLibros(bool **pedidosAtendidos,char ***pedidosLibros,
        int *pedidosClientes ,ofstream &archRep);
void imprimeLineas(ofstream &archRep,int lineas, char car);
void imprimeAtendido(bool *pedidosAtendidos,char **pedidosLibros,ofstream &arcRep);
void reporteDeEntregaDePedidos(const char*nombArch,int **pedidosClientes,
            char ***pedidosLibros,bool **pedidosAtendidos);

#endif /* FUNCIONES_H */

