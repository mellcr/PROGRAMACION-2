

/* 
 * File:   Medico.h
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 12:38
 */

#ifndef MEDICO_H
#define MEDICO_H
using namespace std; 

class Medico {
private:
    int codigo; 
    char *nombre; 
    char *especialidad; 
public:
    Medico();
    Medico(const Medico& orig);
    virtual ~Medico();
    void SetEspecialidad(const char* especialidad);
    void GetEspecialidad(char *c) const;
    void SetNombre(const char* nombre);
    void GetNombre(char *c) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    //extras
    void leer(ifstream &arch);
};

#endif /* MEDICO_H */

