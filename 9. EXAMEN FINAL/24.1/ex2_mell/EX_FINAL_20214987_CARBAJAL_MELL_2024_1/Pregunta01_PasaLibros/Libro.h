/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Libro.h
 * Author: alulab14
 *
 * Created on 9 de julio de 2024, 09:30 AM
 */

#ifndef LIBRO_H
#define LIBRO_H
using namespace std; 
class Libro {
public:
    Libro();
    Libro(const Libro& orig);
    virtual ~Libro();
    void SetPeso(double peso);
    double GetPeso() const;
    void SetPaginas(int paginas);
    int GetPaginas() const;
    void SetNombre(const char* nombre);
    void GetNombre(char*c) const;
    //
    //void asignarMemoria(char tipo);
    virtual void lee(ifstream &arch); 
private:
    char *nombre;
    int paginas;
    double peso; 
    
};

#endif /* LIBRO_H */

