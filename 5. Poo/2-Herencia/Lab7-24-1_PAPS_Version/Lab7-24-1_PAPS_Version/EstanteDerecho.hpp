
                    /* CODEANDO CON PAPS */

#ifndef ESTANTEDERECHO_HPP
#define ESTANTEDERECHO_HPP
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "LibDerecho.hpp"
#include "Estante.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

class EstanteDerecho:public Estante{
private:
    LibroDerecho librosDerecho[10]{};
    int cantLibrosDer;
public:
    EstanteDerecho();
//    EstanteDerecho(const EstanteDerecho &origen);
//    virtual~EstanteDerecho();
    void SetCantLibrosDer(int cantLibrosDer);
    int GetCantLibrosDer() const;
    int obtieneEspaciosRestantes();
    int obtieneEspaciosUsados();
    void colocaLibro(LibroDerecho &libro);
    void imprimeEstante(ofstream &arch);
};

#endif /* ESTANTEDERECHO_HPP */

                    /* CODEANDO CON PAPS */