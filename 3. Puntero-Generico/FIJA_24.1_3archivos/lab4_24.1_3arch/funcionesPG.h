/* 
 * Proyecto: lab4_24.1_3arch
 * Archivo:   funcionesPG.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 24 de abril de 2024, 8:32
 */

#ifndef FUNCIONESPG_H
#define FUNCIONESPG_H
using namespace std;
void imprimeLinea(ofstream& arch, char caracter, int repeticiones);
char *leeCadDelim(ifstream &arch, char delim);
void cargaClientes(void *&clientes);
void cargaLibros(void *&libros);
void *leeRegCli(ifstream &arch);
void *leeRegLib(ifstream &arch);

void cargaPedidos(void *clientes,void *libros);
int buscarCliente(int dniLeid,void *clientes);
int buscarLibro(char * codLeido,void *libros);

int *asignaMemTempEnPedidosxCliente(void *clientes);
void agregarPedidoCliente(void *clientes,int posCli,void *libros,int posLib,
                        char *codLeido, int &numPedCli);
void *obtieneRegLib(void *libros,int posLib);

void imprimereporte(void* clientes);
void imprimeCliente(ofstream& archReporte, void* cliente);

void asignarMemoriaExactaEnPedidos(void *& clientes, int* nPedidos);

#endif /* FUNCIONESPG_H */

