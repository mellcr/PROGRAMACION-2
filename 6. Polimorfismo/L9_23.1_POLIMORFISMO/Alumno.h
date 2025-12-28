

/* 
 * File:   Alumno.h
 * Author: BlueCod (mell1)
 *
 * Created on 9 de junio de 2024, 14:32
 */

#ifndef ALUMNO_H
#define ALUMNO_H
using namespace std;

class Alumno {
private:
    int codigo;
    char *nombre;
    int escala;
    double creditos;
    double total;
public:
    Alumno();
    virtual ~Alumno();
    void SetTotal(double total);
    double GetTotal() const;
    void SetCreditos(double creditos);
    double GetCreditos() const;
    void SetEscala(int escala);
    int GetEscala() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*c) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    //extras
    virtual void lee(ifstream &arch);
    virtual void actualizatotal(double prec);
    virtual void imprime(ofstream &arch);
};

#endif /* ALUMNO_H */

