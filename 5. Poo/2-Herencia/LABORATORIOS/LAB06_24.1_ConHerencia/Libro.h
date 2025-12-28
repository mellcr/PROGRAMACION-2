

/* 
 * File:   Libro.h
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 21:55
 */

#ifndef LIBRO_H
#define LIBRO_H
using namespace std;

class Libro {
private:
    char *codigo;
    char *nombre;
    int ancho;
    int alto;
    bool colocado;
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetColocado(bool colocado);
    bool IsColocado() const;
    void SetAlto(int alto);
    int GetAlto() const;
    void SetAncho(int ancho);
    int GetAncho() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *c) const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *c) const;
    //
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
};

#endif /* LIBRO_H */

