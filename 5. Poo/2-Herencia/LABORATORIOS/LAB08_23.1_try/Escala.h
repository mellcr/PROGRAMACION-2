

/* 
 * File:   Escala.h
 * Author: BlueCod (mell1)
 *
 * Created on 25 de mayo de 2024, 20:41
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
//    void leeEscala(ifstream &);
};

#endif /* ESCALA_H */

