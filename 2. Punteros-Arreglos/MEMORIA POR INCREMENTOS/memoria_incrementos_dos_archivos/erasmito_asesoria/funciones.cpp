/* 
 * Proyecto: erasmito_asesoria
 * Archivo:   funciones.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 11 de abril de 2024, 21:17
 */

#include <iostream>
#include <iomanip> 
#include <cstring> 
#include <fstream> 
using namespace std;

char **leerProductos(ifstream &input){
    char **codigo_descrip; //n->2
    codigo_descrip = new char *[2]; //reservo dos cadenas de caracteres (cod, desc)
    
    codigo_descrip[0] /*char*  */= leerCadena(input,8,','); //char *
    codigo_descrip[1]= leerCadena(input,200,',');
    
    return codigo_descrip;
}

char *leerCadena(ifstream &arch,int tam,char delim){
    char *cad,buffer[tam];
    arch.getline(buffer,tam,delim);
    if(arch.eof()) return nullptr;
   
    cad = new char[strlen(buffer)+1];
    strcpy(cad,buffer);
    
    return cad;
}
//char ***productos
// productos[i] es char**
//productos[i][0] es char* -> cadena 
void pruebaDeLecturaDeProductos(const char*filename,char ***productos,
        int *stock,double *precios){
    ofstream arch(filename,ios::out);
    if(not arch.is_open()){
        cout <<"no se abrio el arch "<<filename; 
        exit(1);
    }
    char **aux_productos; //aterrizar la variable productos
    
    for(int i=0;productos[i];i++){ //productos es el q tiene el delimitador
        aux_productos=productos[i]; //puntero doble que apunta al elemento i de prod
        arch<<setw(10)<<aux_productos[0]<<setw(5)<<aux_productos[1];
        arch<<setw(10)<<stock[i]<<setw(10)<<precios[i]<<endl; 
    }
}


void lecturaDeProductos(const char*nomb, char***&productos,int *&stock,
        double *&precios){
    ifstream input(nomb,ios::in);
    
    //1. DECLARACION DE BUFFERS
    char **buffer_productos[200]{},c;
    int buffer_stock[200]{},n_datos=0;
    double buffer_precios[200]{};
    
    //lectura
    while(true){
        buffer_productos[n_datos]= leerProductos(input);
        input>>buffer_stock[n_datos]>>c>>buffer_precios[n_datos];
        input.get(); //salto de linea
        n_datos++; 
    }
    actualizarProductos(productos,stock,precios,buffer_productos,buffer_stock,
            buffer_precios,n_datos);
}

void actualizarProductos(char ***&productos,int *&stock,double *&precios,
        char***buffer_productos,int *buffer_stock,double *buffer_precios,
        int n){
    //4. RESERVA DE ESPACIO DE MEMORIA (a originales) -> se le suma 1 para las paradas
    productos = new char**[n+1]{}; //basta con q a uno de ellos le ponga la parada ya que comparten indices
    precios = new double[n]{};
    stock = new int[n]{};
    //5. ASIGNACIONNNNN 
    for(int i=0; i<n;i++){
        productos[i] = buffer_productos[i];
        precios[i] = buffer_precios[i];
        stock[i] = buffer_stock[i];
    }
}


//mientras se lee, se hace la busqueda -> CUANDO ALGO NO SE REPITE 
void pruebaDeLecturaDePedidos(const char *filename,int *fechaPedidos,
        char ***codigoPedidos, int ***dniCantPedidos){
    ifstream archPed(filename,ios::in);
    if(not archPed.is_open()){
        cout <<"no se abrio el arch "<<filename; 
        exit(1);
    }  
    int buffer_fechas[600]{}, **buffer_dni[600]{}, n_datos=0,dni,mes,anho,dia,
            fecha,posFecha;
    char **buffer_cods[600]{},*codigo,c;
    int cantPed[600];//ARREGLO QUE MIDA LA CANT DE PEDIDOS POR FECHA 
    while(true){
        //guardo en variables aux  pq no iran de frente al buffer
        codigo = leerCadena(archPed,8,',');
        if(archPed.eof()) break;
        archPed>>dni>>c>>dia>>c>>mes>>c>>anho;
        archPed.get();
        fecha = dia + mes*100 + anho*10000;
        posFecha=buscarFecha(buffer_fechas,fecha,n_datos);
        if(posFecha==-1) agregarFecha(buffer_fechas,buffer_cods,buffer_dni,
                fecha,posFecha,n_datos,cantPed);
        //pos de fecha no es nuevo
        agregarPedidoFecha(buffer_dni[posFecha],buffer_cods[posFecha],
                buffer_fechas[posFecha],cantPed[posFecha]); 
    }
}
void agregarPedidoFecha(int **buffer_dni,char **buffer_cods, int buffer_fechas,
                int cantidadPed){
    int *aux_int;
    buffer_dni[cantidadPed] = new int[2];
    aux_int = buffer_dni[cantidadPed];
    
    //aux_int[0] = dnil
    
}

void agregarFecha(int *buffer_fechas,char ***buffer_cods,int ***buffer_dni,
                int fecha,int &pos_fecha,int n,int *buffCantPed){
    buffer_fechas[n] = fecha;
    buffer_cods[n] = new char*[200]{};
    buffer_dni[n]= new int *[200]{};
    buffCantPed[n] = 0; 
    pos_fecha = n; //pos_fecha ya no es un num negativo 
    n++;
}

int buscarFecha(int *buffer_fechas,int fecha, int n){
    for(int i=0;i<n;i++){
        if(buffer_fechas[i]==fecha) return i;
    }
    return -1;
}
//LOS CHAR* SE PUEDEN IMPRIMIR ASI NOMAS
//UN INT*** SE DEBE ATERRIZAR DOS VECES  -> cantPed -> 2elem(dni,cant)  
void lecturaDePedidos(const char *filename,int *&fechaPedidos,char ***&codigoPedidos,
        int ***&dniCantPedidos);