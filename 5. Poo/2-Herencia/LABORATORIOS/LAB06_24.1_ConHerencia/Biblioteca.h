

/* 
 * File:   Biblioteca.h
 * Author: BlueCod (mell1)
 *
 * Created on 31 de mayo de 2024, 4:05
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "Estante.h"
#include "Libro.h"

class Biblioteca {
private:
    class Estante estantes[100];
    int cantidad_estantes;
    class Libro libros[100];
    int cantidad_libros;
public:
    Biblioteca();
    Biblioteca(const Biblioteca& orig);
    virtual ~Biblioteca();
    
    void cargar_libros(); 
    void cargar_estantes(); 
    void posicionar_libros(); 
    void mostrar_datos(); 
    
    
};

#endif /* BIBLIOTECA_H */

