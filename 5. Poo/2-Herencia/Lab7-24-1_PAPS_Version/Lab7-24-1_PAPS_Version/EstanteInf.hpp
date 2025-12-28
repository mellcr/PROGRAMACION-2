
                    /* CODEANDO CON PAPS */

#ifndef ESTANTEINF_HPP
#define ESTANTEINF_HPP
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "LibInf.hpp"
#include "Estante.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

class EstanteInf:public Estante{
private:
    LibroInf librosInf[10]{};
    int cantLibrosInf;
public:
    EstanteInf();
//    EstanteInf(const EstanteInf &origen);
//    virtual~EstanteInf();
    void SetCantLibrosInf(int cantLibrosInf);
    int GetCantLibrosInf() const;
    int obtieneEspaciosRestantes();
    int obtieneEspaciosUsados();
    void colocaLibro(LibroInf &libro);
    void imprimeEstante(ofstream &arch);
};

#endif /* ESTANTEINF_HPP */

                    /* CODEANDO CON PAPS */