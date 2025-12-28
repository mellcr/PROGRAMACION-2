
                    /* CODEANDO CON PAPS */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <fstream>
#include "EstanteDerecho.hpp"

                    /* CODEANDO CON PAPS */

using namespace std;

EstanteDerecho::EstanteDerecho(){
    cantLibrosDer = 0;
}
//EstanteDerecho::EstanteDerecho(const EstanteDerecho &origen){
//}
//EstanteDerecho::~EstanteDerecho(){
//    cantLibrosDer = 0;
//}

void EstanteDerecho::SetCantLibrosDer(int cantLibrosDer) {
    this->cantLibrosDer = cantLibrosDer;
}

int EstanteDerecho::GetCantLibrosDer() const {
    return cantLibrosDer;
}
int EstanteDerecho::obtieneEspaciosRestantes(){
    int altoUsado = 0;
    for(int i=0;i < cantLibrosDer;i++){
        altoUsado += librosDerecho[i].GetAncho();
    }
    return GetAltura() - altoUsado;
}
int EstanteDerecho::obtieneEspaciosUsados(){
    int altoUsado = 0;
    for(int i=0;i < cantLibrosDer;i++){
        altoUsado += librosDerecho[i].GetAncho();
    }
    return altoUsado;
}
void EstanteDerecho::colocaLibro(LibroDerecho &libro){
    Estante::colocaLibroDer(obtieneEspaciosRestantes(),libro);
    librosDerecho[cantLibrosDer] = libro;
    cantLibrosDer++;
}
void EstanteDerecho::imprimeEstante(ofstream &arch){
    Estante::imprimeEstante(arch,cantLibrosDer);
    arch<<"CODIGO"<<setw(5)<<" "<<"NOMBRE"<<setw(30)<<" "<<setw(5)<<"ANCHO"<<setw(4)<<" "<<"ALTO"
            <<setw(8)<<"AREA"<<setw(20)<<" "<<"JURISDICCION"<<setw(25)<<" "<<"EDICION"<<endl;
    imprimeLinea(arch,130,'.');
    for(int i=0;i<cantLibrosDer;i++){
        librosDerecho[i].muestraLibro(arch);
    }
}

                    /* CODEANDO CON PAPS */