

/* 
 * File:   Estante.h
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 22:04
 */

#ifndef ESTANTE_H
#define ESTANTE_H
#include "Utils.h"
#include "Libro.h"
#include "Espacio.h"
using namespace std;

class Estante {
private:
    char *codigo;
    int anchura;
    int altura;
    class Libro libros[100];
    class Espacio *espacios;
    int cantidad_libros;
public:
    Estante();
    Estante(const Estante& orig);
    virtual ~Estante();
    void SetCantidad_libros(int cantidad_libros);
    int GetCantidad_libros() const;
    void SetAltura(int altura);
    int GetAltura() const;
    void SetAnchura(int anchura);
    int GetAnchura() const;
    void SetCodigo(const char* codigo);
    void GetCodigo(char *c) const;
    //
    void leer(ifstream &arch);
    void creaEspacios();
    void imprimir(ofstream &arch);
    void imprimeEspacios(ofstream &arch);
    void imprimeLibros(ofstream &arch);
    bool operator +=(class Libro &libro);
    int calcularEspaciosLibres();
    void colocarLibro(int altLibro, int ancLibro, int sobrante);
};

#endif /* ESTANTE_H */

