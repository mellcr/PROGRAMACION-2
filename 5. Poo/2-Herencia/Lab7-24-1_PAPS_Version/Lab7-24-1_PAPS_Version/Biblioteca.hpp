
                    /* CODEANDO CON PAPS */

#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "LibInf.hpp"
#include "LibDerecho.hpp"
#include "EstanteInf.hpp"
#include "EstanteDerecho.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

class Biblioteca{
private:
    EstanteInf estantesInf[10]{};
    int cantEstantesInf;
    EstanteDerecho estantesDerecho[10]{};
    int cantEstantesDerecho;
    LibroInf librosInf[10]{};
    int cantLibrosInf;
    LibroDerecho librosDerecho[10]{};
    int cantLibrosDerecho;
public:
    Biblioteca();
//    Biblioteca(const Biblioteca &origen);
//    virtual~Biblioteca();
    void SetCantLibrosDerecho(int cantLibrosDerecho);
    int GetCantLibrosDerecho() const;
    void SetCantLibrosInf(int cantLibrosInf);
    int GetCantLibrosInf() const;
    void SetCantEstantesDerecho(int cantEstantesDerecho);
    int GetCantEstantesDerecho() const;
    void SetCantEstantesInf(int cantEstantesInf);
    int GetCantEstantesInf() const;
    void imprimeLinea(ofstream &arch, int max,char caracter);
    void muestraDatosInf(ofstream &arch);
    void muestraDatosDer(ofstream &arch);
    //Sin Sobrecarga
    void cargarLibros();
    void cargarEstantes();
    void posicionarLibros();
    void mostrarDatos();
};

#endif /* BIBLIOTECA_HPP */

                    /* CODEANDO CON PAPS */