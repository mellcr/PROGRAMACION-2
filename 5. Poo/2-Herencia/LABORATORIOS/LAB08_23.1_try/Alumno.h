

/* 
 * File:   Alumno.h
 * Author: BlueCod (mell1)
 *
 * Created on 25 de mayo de 2024, 20:41
 */

#ifndef ALUMNO_H
#define ALUMNO_H
using namespace std; 

class Alumno {
private:
    int codigo;
    char *nombre;
    int escala;
    double total;
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *c) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    //extras
    void leerDatos(ifstream &arch);
    void imprime(ofstream &arch);
};

#endif /* ALUMNO_H */

