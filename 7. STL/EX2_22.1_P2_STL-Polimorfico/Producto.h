

/* 
 * File:   Producto.h
 * Author: BlueCod (mell1)
 *
 * Created on 19 de junio de 2024, 19:40
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H
using namespace std;
class Producto {
private:
    int codprod;
    char *nombre;
    int stock;
public:
    Producto();
    Producto(const Producto& orig);
    virtual ~Producto();
    void SetStock(int stock);
    int GetStock() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*c) const;
    void SetCodprod(int codprod);
    int GetCodprod() const;
    
    virtual void leer(ifstream &arch);
    virtual void imprime(ofstream &arch);
    virtual int obtienePrio()=0;
};

#endif /* PRODUCTO_H */

