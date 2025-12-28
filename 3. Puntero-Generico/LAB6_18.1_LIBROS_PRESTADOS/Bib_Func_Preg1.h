/* 
 * Proyecto: LAB6_18.1_LIBROS_PRESTADOS
 * Archivo:   Bib_Func_Preg1.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 21 de abril de 2024, 20:01
 */

#ifndef BIB_FUNC_PREG1_H
#define BIB_FUNC_PREG1_H
using namespace std; 

void leerUsuarios(void *&usuarios);
void imprimirUsuarios(void *usuarios);
void* leeRegistroUs(ifstream &arch); 
char *leeCadDelim(ifstream &arch,char delim);
void imprimirReg(void *usu, ofstream &arch); // new 

void leerPRestamos(void *usuarios); 
void leeUnPrestamo(ifstream &arch,int *&codUs,char *&codLib,int *&fecha); 
bool iguales(int codUs,void *usu); 
int buscarUsuario(int codUs,void **us); 
void incrementarEspacios(void **&prestamos,int *&numPres,int &capUsu); 
void agregarPrestamo(void *&usu,int &capUsu, char *codLib,int *fecha); 

void imprimeLibro(void *prest,ofstream &arch); 
void imprimirPrestamso(void *usu); 
void imprimirReg2(void *usu, ofstream &arch); 

#endif /* BIB_FUNC_PREG1_H */

