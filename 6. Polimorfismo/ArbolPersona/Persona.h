

/* 
 * File:   Persona.h
 * Author: BlueCod (mell1)
 *
 * Created on 8 de junio de 2024, 12:57
 */

#ifndef PERSONA_H
#define PERSONA_H
#include "Utils.h"
using namespace std;

class Persona {
private:
    int dni;
    char *nombre;
    double sueldo;
public:
    Persona();
    Persona(const Persona& orig);
    virtual ~Persona();
    void SetSueldo(double sueldo);
    double GetSueldo() const;
    void SetNombre(const char* nombre);
    void GetNombre(char *c) const;
    void SetDni(int dni);
    int GetDni() const;
    //extras
    void operator =(const class Persona &);//nuevo->dato(persona) = dato(pesona);
    bool operator >(const class Persona&); //rec->dato (per) > dato(per)
};
// arch>>dato;
// arch<<dato;
ifstream &operator >>(ifstream &arch, class Persona &dato);
ofstream &operator <<(ofstream &arch, const class Persona &dato);

// * 378708,SAENZ ARANDA WILMER,23455.6
#endif /* PERSONA_H */

