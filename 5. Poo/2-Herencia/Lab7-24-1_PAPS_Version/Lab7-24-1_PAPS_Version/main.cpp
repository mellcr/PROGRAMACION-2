                    /* CODEANDO CON PAPS */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "Biblioteca.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

int main(int argc, char** argv) {

    Biblioteca bibliotecaPAPS;
    
    bibliotecaPAPS.cargarLibros();
    bibliotecaPAPS.cargarEstantes();
    bibliotecaPAPS.posicionarLibros();
    bibliotecaPAPS.mostrarDatos();
    
    return 0;
}

                    /* CODEANDO CON PAPS */