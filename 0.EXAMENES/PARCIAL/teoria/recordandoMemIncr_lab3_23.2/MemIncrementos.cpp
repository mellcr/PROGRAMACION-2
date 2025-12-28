/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "utils.h"
#include "MemIncrementos.h"
#define INCREMENTO 5
#define NOT_FOUND -1 
using namespace std;

char *leeCadDelim(ifstream &arch, char delim){
    char *str, buff[100];
    arch.getline(buff,100,delim);
    //if(arch.eof()) return nullptr;
    str = new char[strlen(buff)+1]{};
    strcpy(str,buff);
    
    return str;
}
// cod desc precio stock
void lecturaDeProdutos(const char *filename,char ***&productos,int *&stock,double *&precios){
    ifstream arch(filename,ios::in);
    if(not arch.is_open()){
        cout <<"no"<<endl;
        exit(1);
    }
    //VARIABLES PARA LECTURA 
    char *codProd, *desc,c;
    double preciosLect;
    int stockLeido;
    //VARIABLES PARA MET MEM INCRE E INICIALIZACION
    int capacity =0, numDat = 0;
    productos = nullptr;
    stock = nullptr;
    precios = nullptr;
    
    while(true){
        codProd = leeCadDelim(arch,',');
        if(arch.eof()) break;
        desc = leeCadDelim(arch,',');
        arch>>preciosLect>>c>>stockLeido;
        arch.get(); //lee salto
        
        if(capacity ==numDat) //estructuras, numdat, capacity 
            incrementarMemInc(productos,stock,precios,capacity,numDat);
        
        //val leidas + numDat + estructuras[numDat-1]
        insertarEnMemoriaProd(codProd,desc,preciosLect,stockLeido,
                productos[numDat-1],stock[numDat-1],precios[numDat-1],numDat);
    }
}

//enum Prod{COD,DESC};
void insertarEnMemoriaProd(char *codProd,char *desc,double preciosLect,int stockLeido,
                char **&productos,int &stock,double &precios,int &numDat){
    productos  = new char*[2]{};
    productos[COD] = codProd;
    productos[DESC] = desc;
    
    stock = stockLeido;
    precios = preciosLect;
    
    numDat++;
}
void incrementarMemInc(char ***&productos,int *&stock,double *&precios,int &capacity,int &numDat){
    //1. AUX DINAMICOS
    char ***aux_prod;
    int *aux_stock;
    double *aux_precios; 
    
    //2. AUMENTAR CAPACITY
    capacity += INCREMENTO;
    
    //3. INICIO
    if(productos ==nullptr){
        productos = new char **[capacity]{};
        stock = new int [capacity]{};
        precios = new double [capacity]{};
        numDat = 1;
    }else{//4. CUANDO YA HAY DATOS 
        aux_prod = new char **[capacity]{};
        aux_stock = new int [capacity]{};
        aux_precios = new double [capacity]{};
        for(int i=0; i<numDat; i++){
            aux_prod[i] = productos[i];
            aux_stock[i] = stock[i];
            aux_precios[i] = precios[i];
        }
        //adios del salon
        delete productos;
        delete stock;
        delete precios;
        //les digo q pasen pq ya hay espacio 
        productos = aux_prod;     
        precios = aux_precios;     
        stock = aux_stock;     
    }
}
void pruebaDeLecturaDeProductos(const char *filename,char ***productos,int *stock,double *precios){
    ofstream arch(filename,ios::out);
    if(not arch.is_open()){
        cout <<"no"<<endl;
        exit(1);
    }
    
    arch << "CODIGO "<< setw(40)<< "DESCRIPCION"<< setw(10)<<"STOCK"<< setw(10)<< "PRECIO"<<endl;
    arch << setfill('=')<<setw(100)<< " "<<setfill(' ')<<endl; //imprime linea
    
    for(int i=0; productos[i]!=nullptr; i++){
        char **aux_prod = productos[i];
        
        arch<<left<<setw(10)<<aux_prod[COD] <<left<< setw(40)<<aux_prod[DESC]<<setw(10)<<stock[i]<<setw(10)<<precios[i]<<endl;
    }
}

void lecturaDePedidos(const char *filename,int *&fechaPedidos, char ***&codigoPedidos,int ***&dniCantPedidos){
    ifstream arch(filename,ios::in);
    if(not arch.is_open()){
        cout <<"no"<<endl;
        exit(1);
    }
    //1. VARIABLES AUX 
    char *codLeido,c;
    int dniLeid,  cantLeida,fechaLeid, dia, mes,anho, posFecha;
    //2.VARIABLES INCREMENTOS
    int numFecha = 0, capFechas=0;
    int cantPed[500]{},capPed[500]{}; //cantPed,capPed -> por fecha
    fechaPedidos = nullptr;
    codigoPedidos = nullptr;
    dniCantPedidos=nullptr;
    while(true){
        //LECTURA
        codLeido= leeCadDelim(arch,',');
        if(arch.eof()) break;
        arch>>dniLeid>>c>>cantLeida>>c>>dia>>c>>mes>>c>>anho;
        arch.get();
        fechaLeid = anho*100000 + mes*100 + dia;
        //cout<<dniLeid<<" "<<endl;
        
       
        //ASIGNAMOS MEMORIA SI ES UNA NUEVA FECHA
        if(numFecha ==capFechas)     asignaMemFecha(fechaPedidos,numFecha,capFechas,codigoPedidos,dniCantPedidos);
         //Como las fechas no se repiten ... 
        posFecha = buscarFecha(fechaLeid,fechaPedidos);
        if(posFecha!=NOT_FOUND){ //existe una fecha -> se inserta en la lista de pedidos de esa fechas
            colocarCodPed(codLeido,cantLeida,dniLeid,codigoPedidos[posFecha],dniCantPedidos[posFecha],
                    cantPed[posFecha],capPed[posFecha]);
            
        }else{
            fechaPedidos[numFecha-1] = fechaLeid; //asignamos la primera fecha
            colocarCodPed(codLeido,cantLeida,dniLeid,codigoPedidos[numFecha-1],dniCantPedidos[numFecha-1],
                    cantPed[numFecha-1],capPed[numFecha-1]);
            numFecha++; //se añade una nueva fecha :))
        }
    }
}

void colocarCodPed(char *codLeido,int cantLeida,int dniLeid,
        char **&codigoPedidos,int **&dniCantPedidos, int &cantPed,int &capPed){
    if(cantPed ==capPed) asignaMemPedidos(codigoPedidos,dniCantPedidos,cantPed,capPed);
    
     int *datosCli = new int[2]{};
    datosCli[0] = dniLeid;
    datosCli[1] = cantLeida;
    
    codigoPedidos[cantPed-1] = codLeido;
    dniCantPedidos[cantPed-1] = datosCli;
    
    cantPed++;
}

void asignaMemPedidos( char **&codigoPedidos,int **&dniCantPedidos,int &numPed, int &capPed){
    int **aux_dni;
    char **aux_codigo;
    
    //1. AUMENTO CAP
    capPed+=INCREMENTO;
    //2. INICIO (NO TENGO DATOS)
    if(codigoPedidos==nullptr){
        codigoPedidos = new char *[capPed]{};
        dniCantPedidos = new int *[capPed]{};
        numPed=1;
    }
    //3. TENGO DATOS -> uso auxiliares. deleteo, vuelvo asignar
    else{
        aux_codigo = new char *[capPed]{};
        aux_dni = new int *[capPed]{};
        for(int i=0;i<numPed;i++){
            aux_codigo[i] = codigoPedidos[i];
            aux_dni[i] = dniCantPedidos[i];
        }
        delete codigoPedidos;
        delete dniCantPedidos;
        codigoPedidos = aux_codigo;
        dniCantPedidos = aux_dni;
    }
}
    

void asignaMemFecha(int *&fechaPedidos,int &numFecha,int &capFechas, char ***&codigoPedidos,
        int ***&dniCantPedidos){
    int *aux_fecha, ***aux_dni;
    char ***aux_codigo;
    
    //1. AUMENTO CAP
    capFechas+=INCREMENTO;
    //2. INICIO (NO TENGO DATOS)
    if(fechaPedidos==nullptr){
        fechaPedidos = new int[capFechas]{};
        codigoPedidos = new char **[capFechas]{};
        dniCantPedidos = new int **[capFechas]{};
        numFecha=1;
    }
    //3. TENGO DATOS -> uso auxiliares. deleteo, vuelvo asignar
    else{
        aux_fecha = new int[capFechas]{};
        aux_codigo = new char **[capFechas]{};
        aux_dni = new int **[capFechas]{};
        for(int i=0;i<numFecha;i++){
            aux_fecha[i] = fechaPedidos[i];
            aux_codigo[i] = codigoPedidos[i];
            aux_dni[i] = dniCantPedidos[i];
        }
        delete fechaPedidos;
        delete codigoPedidos;
        delete dniCantPedidos;
        fechaPedidos = aux_fecha;
        codigoPedidos = aux_codigo;
        dniCantPedidos = aux_dni;
    }
}

int buscarFecha(int fechaBus,int *fechaPedidos){ //busqueda en un arreglo 
    if(fechaPedidos == nullptr) return NOT_FOUND;
    for(int i=0;fechaPedidos[i];i++){
        if(fechaBus==fechaPedidos[i]) return i;
    }
    return NOT_FOUND;
}
void ImprimirLinea(ofstream &arch,int cant ,char letra){
    for(int i=0;i<cant;i++) arch<<letra;
    arch<<endl;
}
void ReporteDeEnviosDePedidos(const char *namefile,char***producto,int*&stock,double *precios,
                                                 int *fechaPedidos,char ***codigoPedidos, int ***dniCantPedidos){
    ofstream arch (namefile,ios::out);
    arch<<right<<setw(70)<<"REPORTE DE ENTRADA DE PEDIDOS"<<endl;
    for(int i=0; fechaPedidos[i];i++){
        ImprimirLinea(arch,150,'=');
        arch<<left<<setw(8)<<"FECHA:"<<fechaPedidos[i]<<endl;
        ImprimirLinea(arch,150,'=');
        arch<<setw(25)<<"No.   DNI"<<setw(60)<<"Producto"<<setw(15)<<"Cantidad"<<setw(10)<<"Precio"<<
                "Total de ingreso"<<endl;
         ImprimirLinea(arch,150,'-');
        ImprimirPedidos(arch,dniCantPedidos[i],codigoPedidos[i],producto,stock,precios);
    }
}

void ImprimirPedidos(ofstream &arch,int **dniCantPedidos,char **codigoPedidos,char ***producto,
        int *&stock, double *precio){
    int *DatosDCP,posProd;
    double montoIngresado=0,montoPerdido=0;
    char **DatosProducto;
    arch.precision(2);
    arch<<fixed;
    for(int i=0; codigoPedidos[i];i++){
        posProd = BuscarProducto(producto,codigoPedidos[i]);
        DatosProducto = producto[posProd];
        DatosDCP = dniCantPedidos[i];
        arch<<right<<setw(2)<<i+1<<")"<<setw(10)<<DatosDCP[0]<<setw(15)<<codigoPedidos[i]<<left<<"  "
                <<setw(55)<<DatosProducto[1]<<right <<setw(5)<<DatosDCP[1]<<setw(16)<<precio[posProd];
        VerificacionStockyCalculoIngreso(arch,precio[posProd],DatosDCP[1],stock[posProd],montoIngresado,montoPerdido);
    }
     ImprimirLinea(arch,150,'-');
     arch<<left<<setw(50)<<"Total Ingresado:"<<montoIngresado<<endl;
     arch<<left<<setw(50)<<"Total perdido por falta de stock:"<<montoPerdido<<endl;
}

int BuscarProducto(char ***producto,char *codigoPedidos){
    for(int i=0;producto[i];i++){
        char **Datos = producto[i];
        if(strcmp(Datos[0],codigoPedidos)==0) return i;
    }
    return -1;
}

void VerificacionStockyCalculoIngreso(ofstream &arch,double precio, int cantidad,int &stock,
        double &montoIngresado,double &montoPerdido){
    if(stock>0){
        stock -= cantidad;
        montoIngresado += precio *cantidad;
        arch<<setw(15)<<precio *cantidad<<endl;
    } else{
        stock =0;
        montoPerdido += precio*cantidad;
        arch<<setw(15)<<"SIN STOCK"<<endl;
    }
}