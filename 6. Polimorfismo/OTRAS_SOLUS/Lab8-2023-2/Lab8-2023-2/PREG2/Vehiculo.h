/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Vehiculo.h
 * Author: Josue
 *
 * Created on 13 de junio de 2024, 10:00 AM
 */

#ifndef VEHICULO_H
#define VEHICULO_H
#include "NPedido.h"

class Vehiculo {
public:
    Vehiculo();
 
    virtual ~Vehiculo();
    void SetActcarga(double actcarga);
    double GetActcarga() const;
    void SetMaxcarga(double maxcarga);
    double GetMaxcarga() const;
    void SetPlaca(const char* plac);
    void GetPlaca(char* plac) const;
    void SetCliente(int cliente);
    int GetCliente() const;
    virtual void lee(ifstream &arch );
    virtual void  imprime(ofstream &arch);
    void imprimePedidos(ofstream &arch);
    void push(char *codPedido,int cantidad,double peso);
    bool pilavacia();
private:
    int cliente;
    char *placa;
    double maxcarga;
    double actcarga;
    class NPedido *ped;
    
};

#endif /* VEHICULO_H */

