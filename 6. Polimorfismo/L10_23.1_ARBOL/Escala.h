

/* 
 * File:   Escala.h
 * Author: BlueCod (mell1)
 *
 * Created on 9 de junio de 2024, 14:37
 */

#ifndef ESCALA_H
#define ESCALA_H
using namespace std;

class Escala {
private:
    int codigo;
    double precio;
public:
    Escala();
    virtual ~Escala();
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    //extras
    
};

#endif /* ESCALA_H */

