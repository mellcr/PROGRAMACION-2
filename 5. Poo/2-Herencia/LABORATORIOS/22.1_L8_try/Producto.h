

/* 
 * File:   Producto.h
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 10:41
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto {
private:
    int codprod; 
    char *nombre; 
    int stock; 
    double precio; 
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetNombre(const char* nombre);
    void  GetNombre(char *c) const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
    void SetPrecio(double precio);
    double GetPrecio() const; 
    //extra
    void asignaProducto(int );
};

#endif /* PRODUCTO_H */

