
                    /* CODEANDO CON PAPS */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "EstanteInf.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

EstanteInf::EstanteInf(){
    cantLibrosInf = 0;
}
//EstanteInf::EstanteInf(const EstanteInf &origen){
//}
//EstanteInf::~EstanteInf(){
//    cantLibrosInf = 0;
//}

void EstanteInf::SetCantLibrosInf(int cantLibrosInf) {
    this->cantLibrosInf = cantLibrosInf;
}

int EstanteInf::GetCantLibrosInf() const {
    return cantLibrosInf;
}
int EstanteInf::obtieneEspaciosRestantes(){
    int anchoUsado = 0;
    for(int i=0;i < cantLibrosInf;i++){
        anchoUsado += librosInf[i].GetAncho();
    }
    return GetAnchura() - anchoUsado;
}
int EstanteInf::obtieneEspaciosUsados(){
    int anchoUsado = 0;
    for(int i=0;i < cantLibrosInf;i++){
        anchoUsado += librosInf[i].GetAncho();
    }
    return anchoUsado;
}
void EstanteInf::colocaLibro(LibroInf &libro){
    Estante::colocaLibroInf(obtieneEspaciosUsados(),libro);
    librosInf[cantLibrosInf] = libro;
    cantLibrosInf++;
}
void EstanteInf::imprimeEstante(ofstream &arch){
    Estante::imprimeEstante(arch,cantLibrosInf);
    arch<<"CODIGO"<<setw(5)<<" "<<"NOMBRE"<<setw(30)<<" "<<setw(5)<<"ANCHO"<<setw(4)<<" "<<"ALTO"
            <<setw(8)<<" "<<"TEMA"<<setw(20)<<" "<<"LENGUAJE"<<setw(25)<<" ""DIFICULTAD"<<endl;
    imprimeLinea(arch,130,'.');
    for(int i=0;i<cantLibrosInf;i++){
        librosInf[i].muestraLibro(arch);
    }
}
                    /* CODEANDO CON PAPS */