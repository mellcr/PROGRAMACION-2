/* 
 * Proyecto: LAB6_18.1_LIBROS_PRESTADOS
 * Archivo:   Bib_Func_Preg1.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 21 de abril de 2024, 20:01
 */
#include "Utils.h"
#include "Bib_Func_Preg1.h"
#define INCREMENTO 5
using namespace std;
enum Usuario{CODIGO, NOMBRE,PREST,CANTP};
enum Prestamo{CODLIB,FECHA};
//codUsu, codLib, fechaDev
//USUARIOS: codUsu,nombUsu

char *leeCadDelim(ifstream &arch,char delim){
    char *str, buff[200]; 
    arch.getline(buff,200,delim); 
    str = new char[strlen(buff)+1]{};
    strcpy(str,buff);
    
    return str;
}
void* leeRegistroUs(ifstream &arch){
    void **registro; 
    char *nomb;
    int *codUsu,cod; 
    
    arch>>cod;
    if(arch.eof()) return nullptr; 
    arch.get(); 
    nomb = leeCadDelim(arch,'\n'); 
    
    registro = new void *[4]{}; 
    codUsu = new int;
    *codUsu = cod;  //* asigna el valor 
    registro[CODIGO] = codUsu;
    registro[NOMBRE] = nomb; 
    registro[PREST] = nullptr;
    registro[CANTP] = nullptr; 
    
    return registro;
}
//////////////////////////////// MET. EXACTO ///////////////////////////////////
void leerUsuarios(void *&usu){
    ifstream arch("Usuarios.csv",ios::in);
    //VAL AUX
    void **usuarios, *buff[100],*u;
    int numDat=0; 
    
    while(true){
        u = leeRegistroUs(arch);
        if(u==nullptr) break;
        buff[numDat] = u; //void* a void *
        numDat++;
    }
    
    //reserva de memoria
    usuarios = new void *[numDat+1]{}; //al ultimo le asigna null
    for(int i=0; i<numDat; i++){
        usuarios[i]=buff[i];
    }
    
    //prueba de impresion 
    //imprimirReg(usuarios[0]); 
    
    usu = usuarios; 
}
void imprimirReg(void *usu, ofstream &arch){
//    ofstream arch("Reporte.txt",ios::out);
//    if(not arch.is_open()){
//        cout << "no se abrio"<<endl; 
//        exit(1);
//    }
    char *nomb; 
    int *codLib; 
    //1. REGISTRO APUNTA A VOID* 
    void **registro = (void **)usu; 
    //2. ASIGNAR LAS VAL AUX DIN CON CAST
    codLib = (int *)(registro[CODIGO]);
    nomb = (char *)(registro[NOMBRE]);
    //3. IMPRESION
    arch.precision(2);
    arch<<fixed; 
    arch<<left<<setw(15)<<*codLib<<setw(50)<<nomb<<endl; 
}

void imprimirUsuarios(void *usu){
    ofstream arch("Reporte.txt",ios::out);
    if(not arch.is_open()){
        cout << "no se abrio"<<endl; 
        exit(1);
    }
    arch<<setw(60)<<"REPORTE DE USUARIOS"<<endl; 
    
    void **usuarios = (void**)usu; 
    for(int i=0; usuarios[i];i++){
        imprimirReg(usuarios[i],arch); 
    }
}


//1. BUFF AUX
//2. NUM EXACTO DE DATOS
//3. LECTURA Y LLENADO DE BUFFS
//4. RESERVA MEM A ORIGINAL 
//5. COPIAR BUFF A ARR_DIN

//////IMPRESION////////
//1. REGISTRO APUNTA A PERSONA
//2. ASIGNAR LAS VAL AUX DIN CON CAST
//3. IMPRESION

////////////////////// MET. POR INCREMENTOS (PREG2) ////////////////////////////
//codUsu, codLib, fechaDev
void leerPRestamos(void *us){
    ifstream arch("Perstamos.csv",ios::in);
    //VAL AUX DIN 
    int *codUs,*fecha,posUsu, cap[100]={}; 
    char *codLib; 
    void **usuarios = (void**)us; //para tener acceso a los indices 
    
    while(true){
        leeUnPrestamo(arch,codUs,codLib,fecha); //todos las direcciones de datos 
        if(arch.eof()) break; 
        //cout <<*codUs<<endl;
        posUsu = buscarUsuario( *codUs,usuarios); //* pasa el valor
        //cout <<posUsu<<endl; 
        if(posUsu!=-1){
            agregarPrestamo(usuarios[posUsu],cap[posUsu],codLib,fecha);
        }
    }    
}

void agregarPrestamo(void *&usu,int &capUsu, char *codLib,int *fecha){
    void **usuario = (void **)usu; //YA PUEDO ACCEDER A SUS 4 ELEMENTOS 
    int *numPres = (int *)(usuario[CANTP]); 
    void **prestamos = (void**)(usuario[PREST]);
    
    //guarda el prestamo de UN libro 
    void **prestamo = new void *[2];
    prestamo[CODLIB] = codLib; 
    prestamo[FECHA] = fecha; 
    
     
    if(capUsu==0 or capUsu == *numPres){ //AUMENTAMOS LA CAPACIDAAAD
        incrementarEspacios(prestamos,numPres,capUsu);
    }
     
    prestamos[*numPres] = prestamo; 
    (*numPres)++;
    //agregamos a USUARIO
    usuario[PREST] = prestamos;
    usuario[CANTP] = numPres; 
}

void incrementarEspacios(void **&prestamos,int *&numPres,int &capUsu){
    // aux 
    void **aux; 
    //aumentar la capacidad 
    capUsu += INCREMENTO;
    
    if(prestamos==nullptr){
        //reserva de memoria
        prestamos = new void*[capUsu]{}; 
        numPres = new int{}; 
        //*numPres = 1;
    }else{
        aux = new void *[capUsu]{}; 
        for(int i=0; i<*numPres;i++){
            aux[i] = prestamos[i];
        }
        delete prestamos; 
        prestamos = aux; 
    }
}

int buscarUsuario(int codUs,void **us){            // ACA ESTA DISTINTOOO 
    //void **usuarios = (void **)us;
    for(int i=0; us[i]; i++){
        if(iguales(codUs,us[i])) return i;
    }
    return -1; 
}

bool iguales(int codUs,void *usu){
    void **usuario = (void**) usu; 
    int *cod = (int *)(usuario[CODIGO]);
    
    return codUs == *cod; 
    
}
void leeUnPrestamo(ifstream &arch,int *&codUs,char *&codLib,int *&fecha){
    int cU,dd,mm,aa;
    char c;
    
    arch>>cU;
    if(arch.eof()) return; 
    arch.get(); 
    codLib = leeCadDelim(arch,','); 
    arch>>dd>>c>>mm>>c>>aa; 
    
    
    //reserva de mem
    codUs = new int; 
    *codUs = cU; 
    fecha = new int; 
    *fecha = aa*10000 + mm*100 + dd; 
    
}
void imprimirReg2(void *usu, ofstream &arch){
    //1. REGISTRO APUNTA A VOID* 
    void **registro = (void **)usu; 
    //2. ASIGNAR LAS VAL AUX DIN CON CAST
    int *cod = (int *)(registro[CODIGO]);
    char *nomb = (char *)(registro[NOMBRE]);
    void **prestamos = (void**)(registro[PREST]);
    int *cantPrest = (int *)(registro[CANTP]); 
    
    //3. IMPRESION
    arch.precision(2);
    arch<<fixed; 
    arch<<left<<setw(15)<<*cod<<setw(50)<<nomb<<setw(15)<<*cantPrest; 
    if(prestamos!=nullptr){ //para evitar error en el for de abajo 
        for(int i=0; i< *cantPrest; i++){
            imprimeLibro(prestamos[i],arch);
        }
    } 
 
     
    arch<<endl;
    
}
void imprimeLibro(void *prest,ofstream &arch){
    void **prestamo = (void**)prest; 
    char *codLib = (char * )(prestamo[CODLIB]);
    int *fecha = (int * )(prestamo[FECHA]);
    
    arch<<setw(15)<<*codLib<<setw(15)<<*fecha<<endl;
    
}
void imprimirPrestamso(void *usu){
    ofstream arch("ReportePrest.txt",ios::out);
    if(not arch.is_open()){
        cout << "no se abrio"<<endl; 
        exit(1);
    }
    arch<<setw(60)<<"REPORTE DE PRESTAMOS"<<endl; 
    
    void **usuarios = (void**)usu; 
    for(int i=0; usuarios[i];i++){
        imprimirReg2(usuarios[i],arch); 
    }
}




