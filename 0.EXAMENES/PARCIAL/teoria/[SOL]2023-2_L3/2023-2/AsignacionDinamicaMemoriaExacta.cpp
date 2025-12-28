/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"
#define LINEAS 200
#define INCREMENTO 5
#define NO_ENCONTRO -1
enum producto{COD,NOM};
void lecturaDeProductos(const char *nombArch,char ***&productos,int *&stock,double *&precios){
    ifstream archProd(nombArch,ios::in);
    if(not archProd.is_open()){
        cout<<"ERROR: No se puso abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    char *nombre,*codigo,car;
    double precio;
    int stockInicial, cantDatos=0,cap=0;
    productos=nullptr;
    stock=nullptr;
    while(true){
        codigo=leerCadena(archProd,',');
        if(archProd.eof())break;
        nombre=leerCadena(archProd,',');
        archProd>>precio>>car>>stockInicial>>ws;
        if(cantDatos==cap){
            aumentarEspacios(productos,stock,precios,cantDatos,cap);
        }
        asignamosDatosProductos(productos[cantDatos-1],stock[cantDatos-1],
                precios[cantDatos-1],codigo,nombre,stockInicial,precio);
        cantDatos++;
    }
    cout<<cantDatos<<endl;
}
void asignamosDatosProductos(char **&productos,int &stock,double &precios,char *codigo,
        char *nombre,int stockInicial,double precio){
    stock=stockInicial;
    precios=precio;
    productos=new char *[2];
    productos[COD]=codigo;
    productos[NOM]=nombre;
}
void aumentarEspacios(char ***&productos,int *&stock,double *&precios,
        int &cantDatos,int &cap){
    cap+=INCREMENTO;
    if(productos==nullptr){
        productos=new char **[cap]{};
        stock= new int [cap]{};
        precios=new double [cap]{};
        cantDatos=1;
    }
    else{
        char ***auxProductos=new char **[cap]{};
        int *auxStock=new int [cap]{};
        double *auxPrecios=new double [cap]{};
        for(int i=0;i<cantDatos;i++){
            auxProductos[i]=productos[i];
            auxStock[i]=stock[i];
            auxPrecios[i]=precios[i];
        }
        delete productos;
        delete stock;
        delete precios;
        productos=auxProductos;
        stock=auxStock;
        precios=auxPrecios;
    }
}
char *leerCadena(ifstream &arch,char limitador){
    char cadena[60],*nuevaCadena;
    arch.getline(cadena,60,',');
    if(arch.eof())return nullptr;
    int longitud=strlen(cadena)+1;
    nuevaCadena=new char[longitud];
    strcpy(nuevaCadena,cadena);
    return nuevaCadena;
}

void pruebaDeLecturaDeProductos(const char *nombArch,char ***productos,int *stock,
        double *precios){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR:No se pudo abrir el archivo de "<<nombArch<<endl;
        exit(1);
    }
    archRep<<fixed;
    archRep.precision(2);
    archRep<<setw(65)<<"REPORTE DE PRODUCTOS"<<endl;
    imprimeLinea(archRep,LINEAS,'=');
    archRep<<setw(5)<<" "<<"CODIGO"<<setw(10)<<" "<<"NOMBRE DEL PRODUCTO"<<
            setw(45)<<" "<<"PRECIO"<<setw(4)<<" "<<"STOCK"<<endl;
    imprimeLinea(archRep,LINEAS,'-');
    for(int i=0;productos[i];i++){
        imprimirDatosProducto(archRep,productos[i]);
        archRep<<setw(8)<<precios[i]<<setw(5)<<" "<<setw(2)<<stock[i]<<endl;
    }
}

void imprimirDatosProducto(ofstream &archRep,char **productos){
    archRep<<setw(5)<<" "<<setw(7)<<productos[COD]<<setw(9)<<" "<<left<<
            setw(62)<<productos[NOM]<<right;
}
void imprimeLinea(ofstream &archRep,int lineas,char car){
    for(int i=0;i<lineas;i++){
        archRep.put(car);
    }
    archRep<<endl;
}

//////////////////////////////////////////////////////////////////////////////////////

void lecturaDePedidos(const char*nombArch,int *&fechaPedidos,char ***&codigoPedidos,
        int ***&dniCantPedidos){
    ifstream archPedidos(nombArch,ios::in);
    if(not archPedidos.is_open()){
        cout<<"ERROR: No se puso abrir el archivo "<<nombArch<<endl;
        exit(1);
    } 
    int fecha,cantFechas=0,capFechas=0,cantPedidos[600]{},capPedidos[600]{},dni,
            cantidad,dd,mm,aa,posFecha=0,val;
    char *cod,c;
    fechaPedidos=nullptr;
    codigoPedidos=nullxptr;
    dniCantPedidos=nullptr;
    while(true){
        cod=leerCadena(archPedidos,',');
        if(archPedidos.eof())break;
        
        archPedidos>>dni>>c>>cantidad>>c>>dd>>c>>mm>>c>>aa>>ws;
        fecha=dd+mm*100+aa*10000;
        posFecha=buscarFecha(fechaPedidos,fecha,cantFechas);
        if(posFecha==NO_ENCONTRO){
            agregarFecha(fechaPedidos,codigoPedidos,dniCantPedidos,posFecha,cantFechas,
                    fecha,cantPedidos,capPedidos,capFechas);
            cantFechas++;
        }
//        val=cantPedidos[posFecha];
        agregarPedidos(codigoPedidos[posFecha],dniCantPedidos[posFecha],
                cantPedidos[posFecha],capPedidos[posFecha],cantidad,dni,cod);
    }
}

void agregarPedidos(char **&codigoPedidos,int **&dniCantPedidos,int &cant,
        int &cap,int cantidad,int dni,char *cod){
    if(cant==cap){
        aumentarEspacioPedidos(codigoPedidos,dniCantPedidos,cant,cap);
    }
    int *aux=new int[2]{};
    
    codigoPedidos[cant-1]=cod;
    aux[0]=dni;
    aux[1]=cantidad;
    dniCantPedidos[cant-1]=aux;
    cant++;
    
}
void aumentarEspacioPedidos(char **&codigoPedidos,int **&dniCantPedidos,int &cant,
        int &cap){
    cap+=INCREMENTO;
    if(codigoPedidos==nullptr){
        codigoPedidos=new char *[cap]{};
        dniCantPedidos=new int *[cap]{};
        cant=1;
    }
    else{
        char **auxCod=new char *[cap]{};
        int **auxDniCant=new int *[cap]{};
        for(int i=0;i<cant;i++){
            auxCod[i]=codigoPedidos[i];
            auxDniCant[i]=dniCantPedidos[i];
        }
        delete codigoPedidos;
        delete dniCantPedidos;
        codigoPedidos=auxCod;
        dniCantPedidos=auxDniCant;
    }
}
void agregarFecha(int *&fechaPedidos,char ***&codigoPedidos,int ***&dniCantPedidos,
        int &posFecha,int &cantFechas,int fecha,int *cantPedidos,int *capPedidos,int &capFechas){
    if(cantFechas==capFechas){
        aumentarEspacios(fechaPedidos,codigoPedidos,dniCantPedidos,capFechas,cantFechas);
    }    
//    posFecha=cantFechas-1;//esto esta mal, yo quiero tener la posicion de la fecha
    //despues de hacer los nuevos cambios, por eso debe sre esto igual a cant
    int cant=cantFechas-1;
    while(true){
        cant--;
        if(cant<0 or fechaPedidos[cant]<fecha)break;
        fechaPedidos[cant+1]=fechaPedidos[cant];
        codigoPedidos[cant+1]=codigoPedidos[cant];
        dniCantPedidos[cant+1]=dniCantPedidos[cant];
        capPedidos[cant+1]=capPedidos[cant];
        cantPedidos[cant+1]=cantPedidos[cant];
    }
    fechaPedidos[cant+1]=fecha;
    codigoPedidos[cant+1]=nullptr;
    dniCantPedidos[cant+1]=nullptr;  
    cantPedidos[cant+1]=0;
    capPedidos[cant+1]=0;
    posFecha=cant+1;//esta será la posicion en la que se encontrará la fecha despues
        //de mover el arreglo
}

void aumentarEspacios(int *&fechaPedidos,char ***&codigoPedidos,int ***&dniCantPedidos,
        int &capFechas,int &cantFechas){
    capFechas+=INCREMENTO;
    if(fechaPedidos==nullptr){
        fechaPedidos=new int [capFechas]{};
        codigoPedidos=new char **[capFechas]{};
        dniCantPedidos=new int **[capFechas]{};
        cantFechas=1;
    }
    else{
        int *auxFechas=new int [capFechas]{},***auxDniCant=new int **[capFechas]{};
        char ***auxCod=new char **[capFechas]{};
        for(int i=0;i<cantFechas;i++){
            auxFechas[i]=fechaPedidos[i];
            auxDniCant[i]=dniCantPedidos[i];
            auxCod[i]=codigoPedidos[i];
        }
        delete fechaPedidos;
        delete codigoPedidos;
        delete dniCantPedidos;
        fechaPedidos=auxFechas;
        codigoPedidos=auxCod;
        dniCantPedidos=auxDniCant;
    }
    
}
int buscarFecha(int *fechaPedidos,int fecha,int cantFechas){
    for(int i=0;i<cantFechas;i++){
        if(fechaPedidos[i]==fecha)return i;
    }
    return NO_ENCONTRO ;
}

void pruebaDeLecturaDePedidos(const char*nombArch,int *fechaPedidos,char ***codigoPedidos,
        int ***dniCantPedidos){
    ofstream archRep (nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: no se pudo abrir el archivo de "<<nombArch<<endl;
        exit(1);
    }
    archRep<<setw(60)<<" "<<"REPORTE DE PEDIDOS"<<endl;
    imprimeLinea(archRep,LINEAS,'=');
    imprimeLinea(archRep,LINEAS,'-');
    int dd,mm,aa;
    for(int i=0;fechaPedidos[i];i++){
        aa=fechaPedidos[i]/10000;
        mm=(fechaPedidos[i]%10000)/100;
        dd=(fechaPedidos[i]%10000)%100;
        archRep<<"Fecha: "<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<
                "/"<<setw(4)<<aa<<setfill(' ')<<endl;
        imprimeLinea(archRep,LINEAS,'-');
        archRep<<setw(10)<<" "<<"CODIGO"<<setw(10)<<" "<<"CLIENTE"<<setw(10)<<" "<<
                "CANTIDAD"<<endl;
        imprimeLinea(archRep,LINEAS,'-');
        imprimePedidos(codigoPedidos[i],dniCantPedidos[i],archRep);
        imprimeLinea(archRep,LINEAS,'=');
    }
    
}

void imprimePedidos(char **codigoPedidos,int **dniCantPedidos,ofstream &archRep){
    int *aux;
    for(int i=0;codigoPedidos[i];i++){
        aux=dniCantPedidos[i];
        archRep<<setw(10)<<" "<<setw(7)<<codigoPedidos[i]<<setw(9)<<" "<<setw(8)<<
                aux[0]<<setw(11)<<" "<<setw(2)<<aux[1]<<endl;
    }
}

void reporteDeEnvioDePedidos(const char*nombArch,char ***productos,int *stock,
        double *precios,int *fechaPedidos,char ***codigoPedidos,
        int ***dniCantPedidos){
    ofstream archRep(nombArch,ios::out);
    if(not archRep.is_open()){
        cout<<"ERROR: no se pudo abrir el archivo"<<nombArch<<endl;
        exit(1);
    }
    archRep<<setw(60)<<" "<<"REPORTE DE ENTREGA DE PEDIDOS"<<endl;
    int dd,mm,aa;
    archRep<<fixed;
    archRep.precision(2);
    imprimeLinea(archRep,LINEAS,'=');
    double totalIngresado=0,totalperdido=0;
    for(int i=0;fechaPedidos[i];i++){
        totalIngresado=0;
        totalperdido=0;
        aa=fechaPedidos[i]/10000;
        mm=(fechaPedidos[i]%10000)/100;
        dd=(fechaPedidos[i]%10000)%100;
        archRep<<"Fecha: "<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<
                "/"<<setw(4)<<aa<<setfill(' ')<<endl;
        imprimeLinea(archRep,LINEAS,'=');
        archRep<<"No."<<setw(5)<<" "<<"DNI"<<setw(15)<<" "<<
                "Producto"<<setw(54)<<" "<<"Cantidad"<<setw(11)<<" "<<"Precio"<<setw(11)<<
                " "<<"Total de ingresos"<<endl;
        imprimeLinea(archRep,LINEAS,'-');
        imprimirProductos(codigoPedidos[i],dniCantPedidos[i],productos,stock,precios,archRep,
                totalIngresado,totalperdido);
        imprimeLinea(archRep,LINEAS,'-');
        archRep<<left<<setw(60)<<"Total ingresado:"<<right<<setw(10)<<totalIngresado<<endl;
        archRep<<left<<setw(60)<<"Total perdido por falta de stock:"<<right<<setw(10)<<totalperdido<<endl;
        imprimeLinea(archRep,LINEAS,'=');
    }
}

void imprimirProductos(char **codigoPedidos,int **dniCantPedidos,char ***productos,
        int *stock,double *precios,ofstream &archRep,double &totalIngresado,double &totalperdido){
    int posProducto,*aux;
    char **auxProd;
    double total;
    for(int i=0;codigoPedidos[i];i++){
        aux=dniCantPedidos[i];
        posProducto=buscarProducto(codigoPedidos[i],productos);
        if(posProducto!=NO_ENCONTRO){
            auxProd=productos[posProducto];
            total=precios[posProducto]*aux[1];
            archRep<<setw(2)<<i+1<<")"<<setw(3)<<" "<<setw(8)<<aux[0]<<
                    setw(7)<<" "<<setw(7)<<codigoPedidos[i]<<" "<<left<<
                    setw(55)<<auxProd[1]<<right<<setw(6)<<" "<<setw(2)<<
                    aux[1]<<setw(10)<<" "<<setw(12)<<precios[posProducto]<<setw(5)<<" ";
            if(stock[posProducto]>0){
                totalIngresado+=total;
                archRep<<setw(16)<<total<<endl;
                stock[posProducto]-=aux[1];
            }
            else{
                totalperdido+=total;
                archRep<<setw(8)<<" "<<"SIN STOCK"<<endl;
            }
        }
    }
}

int buscarProducto(char *codigoPedidos,char ***productos){
    char **aux;
    for(int i=0;productos[i];i++){
        aux=productos[i];
        if(strcmp(codigoPedidos,aux[0])==0)return i;
    }
    
    return NO_ENCONTRO;
}