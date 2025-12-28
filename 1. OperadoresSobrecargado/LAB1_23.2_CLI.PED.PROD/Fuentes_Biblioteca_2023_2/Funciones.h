/* 
 * Proyecto: Fuentes_Biblioteca_2023_2
 * Archivo:   Funciones.h
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 31 de marzo de 2024, 12:23
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

bool operator >>(ifstream&arch,struct Cliente&c);

bool operator>>(ifstream&arch,struct Producto&p);
bool operator>>(ifstream&arch,struct Pedido&p);
void operator+=(struct Cliente*arrCli,const struct Pedido&p);
void operator+=(struct Producto*arrPro,const struct Pedido&p);
void operator<<(ofstream&arch,const struct Cliente&c);
void operator<<(ofstream&arch,const struct Producto&p);

#endif /* FUNCIONES_H */

