/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include "utils.h"
#include "Preg01_PuntMult.h"
#define INC 5
using namespace std;
enum Pedido{CODPROD,DNI,CANT,FECHA};

char *leeCadDelim(ifstream &arch, char delim){
    char *str, buff[100];
    arch.getline(buff,100,delim);
    //if(arch.eof()) return nullptr;
    str = new char[strlen(buff)+1]{};
    strcpy(str,buff);
    
    return str;
}

// CODPROD  DNI CANT    FECHA
void cargarPedidos(int **&fechaClienteCantidad,char **&codigoDelProducto,const char *filename){
    ifstream arch(filename,ios::in);
    if(not arch.is_open()){
        cout<<"no"<<endl;
        exit(1);
    }
    //1. VAL LECT
    char *codProd,c;
    int dni, cant,fecha=0,dia,mes,anho;
    //2. VAL INC
    int numDat =0, cap=0;
    fechaClienteCantidad= nullptr;
    codigoDelProducto = nullptr;
    while(true){
        codProd = leeCadDelim(arch,',');
        if(arch.eof()) break;
        arch>>dni>>c>>cant>>c>>dia>>c>>mes>>c>>anho;
        arch.get();
        fecha = anho*10000 + mes*100 + dia;
//        cout <<fecha<<" ";
        if(numDat==cap) incrementaMemPed(fechaClienteCantidad,codigoDelProducto,numDat,cap);
        
        colocaDatosFechaCod(codProd,dni,fecha,cant,
                fechaClienteCantidad[numDat-1],codigoDelProducto[numDat-1]);
        numDat++;
    }
    
    //ordenamos usando qsort de la biblioteca cstlib
    qsort(fechaClienteCantidad,numDat-1,sizeof(int *),compara);
}

int compara(const void *a,const void *b){
    int **a1=( int**)a,**bi=(int **)b;
    int *datoA=(int *)a1[0],*datoB=(int *)bi[0];
    return *datoA-*datoB;
}

void colocaDatosFechaCod(char *codProd,int dni,int  fecha,int cant,
        int *&fechaClienteCantidad,char *&codigoDelProducto){
    codigoDelProducto = codProd;
    
    int *datosCli = new int[3]{};
    datosCli[0] = fecha;
    datosCli[1] = dni;
    datosCli[2] = cant;
    
    fechaClienteCantidad = datosCli;
}

void incrementaMemPed(int **&fechaClienteCantidad,char **&codigoDelProducto,int &numDat,int &cap){
    int **aux_fecha;
    char **aux_cod;
    cap+=INC;
    //NO HAY DATOS
    if(fechaClienteCantidad==nullptr){
        fechaClienteCantidad = new int*[cap]{};
        codigoDelProducto = new char *[cap]{};
        numDat=1;
    }
    //YA HAY DATOS
    else{
        aux_fecha = new int*[cap]{};
        aux_cod = new char *[cap]{};
        for(int i=0;i<numDat;i++){
            aux_cod[i] = codigoDelProducto[i];
            aux_fecha[i] = fechaClienteCantidad[i];
        }
        delete codigoDelProducto;
        delete fechaClienteCantidad;
        codigoDelProducto = aux_cod;
        fechaClienteCantidad = aux_fecha;
    }
}
void pruebaDeCargaDePedidos(int **fechaClienteCantidad,char **codigoDelProducto,
        const char *nombArch){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR EN EL ARCHIVO "<<nombArch<<endl;
        exit(1);
    }
    archRep<<setw(30)<<" "<<"REPORTE DE PEDIDOS"<<endl;
    imprimeLinea(archRep,'=');
    archRep<<setw(5)<<" "<<"CODIGO"<<setw(7)<<" "<<"FECHA DEL PEDIDO"<<
            setw(10)<<" "<<"DNI"<<setw(7)<<" "<<"CANTIDAD"<<endl;
    imprimeLinea(archRep,'-');
    int *auxFecha;
    char *auxCod;
    int dd,mm,aaaa;
    for(int i=0;fechaClienteCantidad[i];i++){
        auxFecha=fechaClienteCantidad[i];
        auxCod=codigoDelProducto[i];
        aaaa=auxFecha[0]/10000;
        mm=(auxFecha[0]%10000)/100;
        dd=(auxFecha[0]%10000)%100;
        archRep<<setw(5)<<" "<<setw(7)<<auxCod<<setw(10)<<" "<<
                setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<
                setw(4)<<aaaa<<setfill(' ')<<setw(10)<<" "<<setw(8)<<auxFecha[1]<<
                setw(7)<<" "<<setw(2)<<auxFecha[2]<<endl;
    }
}
void imprimeLinea(ofstream &arch,char car){
    for(int i=0;i<200;i++)arch.put(car);
    arch<<endl;
}