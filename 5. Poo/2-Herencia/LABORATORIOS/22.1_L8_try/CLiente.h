

/* 
 * File:   CLiente.h
 * Author: BlueCod (mell1)
 *
 * Created on 30 de mayo de 2024, 10:38
 */

#ifndef CLIENTE_H
#define CLIENTE_H
using namespace std; 

class CLiente {
private:
    int dni; 
    char categoria; 
    char *nombre;
public:
    CLiente();
    CLiente(const CLiente& orig);
    virtual ~CLiente();
    void SetNombre(const char* nombre);
    void GetNombre(char *c) const;
    void SetCategoria(char categoria);
    char GetCategoria() const;
    void SetDni(int dni);
    int GetDni() const;
    //extra
    void leer(ifstream &arch); 
    
};

#endif /* CLIENTE_H */

