/* 
 * Proyecto: AsignacionDinamicaMemoriaExacta-2023-2
 * Archivo:   AsignacionDinamicaMemoriaExacta.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 10 de abril de 2024, 17:10
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H
using namespace std;

void lecturaDeProductos(const char*filename,char ***&productos,
        int *&stock,double *&precios);
void pruebaDeLecturaDeProductos(const char*filename,char ***productos,
        int *stock,double *precios);
char ** asignarMemoria(const char *cod,const char *desc);
char *asignaCadenaExacta(const char *cad);
void imprimeCodYDesc(ofstream &arch,char **producto);
void pruebaDeLecturaDePedidos(const char *filename,int *fechaPedidos,
        char ***codigoPedidos, int ***dniCantPedidos);
void lecturaDePedidos(const char *filename,int *&fechaPedidos,char ***&codigoPedidos,
        int ***&dniCantPedidos);
int buscarEnFecha(int fecha,int *bufferFechas);
//YO
void llenadoBuffCods(char **&buffer_cods,char *codProd,int numPorFila);
void llenadoBuffDni(int **&buff_dnis,int dni,int cant, int numPorFila);
void asignaDni(int *buffDniCant, int dni) ;
void asignaCant(int *buffDniCant, int cant);
void imprimePedidos(ofstream &arch,char **codigoPedidos,int **dniCantPedidos);
void imprimeDnis(ofstream &arch,int *dniCantPedidos);
void cut(char **&codigoPedidos,int **&dniCantPedidos,int numXFil); 
//reporte
void imprimeLinea(ofstream &arch, char car); 
void reporteDeEnvioDePedidos(const char*filename,char ***productos,int *stock,
            double *precios,int *fechaPedidos,char ***codigoPedidos,
        int ***dniCantPedidos);
void convierteFecha(int &dd,int &mm,int &aa,int fecha); 
int busca(char *codProd,char ***productos); 
void imprimePedidosPorFecha(ofstream &arch,char ***productos,int *stock,
        double *precios,int **dniCantPedidos,char **codigoPedidos); 

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

