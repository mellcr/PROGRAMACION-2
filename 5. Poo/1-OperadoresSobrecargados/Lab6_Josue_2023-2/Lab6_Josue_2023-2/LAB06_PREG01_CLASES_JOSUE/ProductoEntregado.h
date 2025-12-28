/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   ProductoEntregado.h
 * Author: Josue
 *
 * Created on 22 de mayo de 2024, 10:47 PM
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H

class ProductoEntregado {
public:
    ProductoEntregado();
    ProductoEntregado(const ProductoEntregado& orig);
    virtual ~ProductoEntregado();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(const char* cod);
    void GetCodigo(char *) const;
private:
    char *codigo;
    double precio;
};

#endif /* PRODUCTOENTREGADO_H */

