

/* 
 * File:   Medicamento.h
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 12:41
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H
using namespace std;

class Medicamento {
private:
    int codigo; 
    char *nombre; 
    int cantidad; 
    double precio; 
    int fecha; 
public:
    Medicamento();
    Medicamento(const Medicamento& orig);
    virtual ~Medicamento();
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetPrecio(double precio);
    double GetPrecio() const;
    void SetCantidad(int cantidad);
    int GetCantidad() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *c) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void GetNombYPrecioEnArchivo(int codBus, char *nomb, double &prec);
    void imprime(ofstream &arch);
};

#endif /* MEDICAMENTO_H */

