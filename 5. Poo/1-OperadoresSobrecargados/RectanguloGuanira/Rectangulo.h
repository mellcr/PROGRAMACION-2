/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   Rectangulo.h
 * Author: mell1
 *
 * Created on 19 de mayo de 2024, 14:50
 */

#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo {
    //bloquea el uso de atributos -> private 
private: //ATRIBUTOS
    double base;
    double altura;
    
public: //METODOS
    void setBase(double);
    void setAltura(double);
    void leeDatos();  //si no le paso nada como parametros -> void
    //me entrega los valores
    double getBase();
    double getAltura();
    //muestra resultados
    void muestraDatos();
    double area();
    double perimetro();
    void mostrarResultados();
};

#endif /* RECTANGULO_H */

