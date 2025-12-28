/* 
 * Proyecto: lab4_23.2
 * Archivo:   PunterosGenericos.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 23 de abril de 2024, 14:05
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H
using namespace std; 
//funciones adicionales
char *leeCadDelim(ifstream &arch, char delim); 
//funciones PREG1
void cargaProductos(void *&productos); 
void* leeRegistroPro(ifstream &arch); 
void cargaClientes(void *&clientes); 
void *leeRegistroCli(ifstream &arch);
void asignaMemExact(void **&auxClientes,void **buffReg,int numDat); 
//PREG2
void cargaPedidos(void *productos,void *clientes);
int buscarDni(int dniLect,void *clientes); 
int buscarCod(char *codProd,void *productos); 
void validarInsercion(void *productos,int posProd,void *clientes,int posCli,
        int cant, bool &debeInsertar,bool & debeDescontar,double &montoADescontar); 
int *asignarMemoriaTemportalEnPedidos(void *&clientes); 
void insertarPedidoEnCliente(void*& clientes, int indiceCliente, bool debeDescontar,
            char *codProducto, int cantidad, double montoPedido, int* nPedidos); 


void agregaPedido(void *&clientes,double linNecesitada,char *codProd,int cant,int *&numPed,
        int posCli); //no
#endif /* PUNTEROSGENERICOS_H */

