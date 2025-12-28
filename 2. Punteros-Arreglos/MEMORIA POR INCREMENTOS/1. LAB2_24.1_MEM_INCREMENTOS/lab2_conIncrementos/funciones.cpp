/* 
 * Proyecto: lab2_conIncrementos
 * Archivo:   funciones.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 18 de abril de 2024, 9:15
 */

#include "Utils.h"
#include "funciones.h"
#define INCREMENTO 5
using namespace std;
enum libros{COD,TIT,AUT}; 
#define NOT_FOUND -1

char *leeCadDelim(ifstream &archLib,char delim){
    char aux_cad[100], *str; 
    
    archLib.getline(aux_cad,100,delim); 
    str = new char[strlen(aux_cad)+1];
    strcpy(str,aux_cad); 
    
    return str; 
}

//cod   nomb    autor   stock   precio
void lecturaDeLibros(const char*archName,char ***&libros,int **&stock){
    ifstream archLib(archName,ios::in); 
    //VARIABLES AUX -> TODO DINAMICO 
    char *cod, *nomb, *autor,c; 
    int cantStok; 
    double precio; 
    //VARIABLES PARA INCREMENTOS -> tmb inicializo orig
    int capacity = 0, numLib = 0; 
    libros = nullptr; 
    stock = nullptr; 
    
    while(true){
        cod = leeCadDelim(archLib,','); 
        if(archLib.eof()) break; 
        nomb = leeCadDelim(archLib,','); 
        autor = leeCadDelim(archLib,','); 
        archLib>>cantStok>>c>>precio>>c; 
        //cout << nomb<<endl;
        
        //CAPACITY = NUMDAT????
        if(capacity == numLib){
            reservaMemIncrementos(libros,stock,numLib,capacity); 
        }
        
        //ASIGNACION:
        asignarDatosDelLibro(libros[numLib-1],stock[numLib-1],cod,nomb,autor,cantStok);  
        //cout <<libros[numLib][0]<<endl; 
        //cout <<stock[numLib][0]<<endl; 
        numLib++; 
    }
}
void asignarDatosDelLibro(char **&libros,int *&stock,char *cod,char *nomb,
        char *autor,int cantStok){
    libros = new char*[3]{}; 
    libros[COD] = cod; 
    libros[TIT] = nomb; 
    libros[AUT] = autor; 
    
    stock = new int[2]{};
    stock[0] = cantStok;
    stock[1] = 0;
}


void reservaMemIncrementos(char ***&libros,int **&stock,int &numLib,int &capacity){
    //1. AUXILIARES DINAMICOS 
    char ***aux_libros; 
    int **aux_stock; 
    
    //2. AUMENTAR CAPACIDAD 
    capacity +=INCREMENTO; 
    
    //AL INICIO
    if(libros ==nullptr){ //se debe reservar en general:)))
        libros = new char **[capacity]{}; 
        stock = new int *[capacity]{}; 
        numLib = 1; //primer elemento 
    }
    else{ //YA HAY DATOSSS 
        aux_libros = new char **[capacity]{}; 
        aux_stock = new int*[capacity]{}; 
        for(int i=0; i<numLib; i++){
            aux_libros[i] = libros[i]; 
            aux_stock[i] = stock[i]; 
        }
        //los boto del salon
        delete libros; 
        delete stock; 
        //les digo q vuelvan a pasar pq ya hay espacio 
        libros = aux_libros; 
        stock = aux_stock; 
    }
}


void pruebaDeLecturaDeLibros(const char*archName,char ***libros,int **stock){
    ofstream arch(archName,ios::out); 
    
    char **aux_lib; 
    int cantLib, *aux_stock; 
    
    arch<<setw(60)<<"REPORTE INICIAL DE LIBROS"<<endl; 
    
    for(int i=0; libros[i]; i++){
     //  cout <<libros[i][0]<<endl;
        aux_lib = libros[i]; 
        aux_stock = stock[i]; 
        arch<<left <<setw(15)<<aux_lib[COD]<<setw(60)<<aux_lib[TIT]<<setw(60)<<aux_lib[AUT]
                <<setw(15)<<aux_stock[0]<<setw(15)<<aux_stock[1]<<endl; 
    }
}
char *leeCadCin(ifstream &archLib){
    char aux_cad[100], *str; 
    archLib>>aux_cad; 
    
    str = new char[strlen(aux_cad)+1];
    strcpy(str,aux_cad); 
    
    return str; 
}
int buscarCliente(int **pedidosClientes,int dni){
//    if(pedidosClientes==nullptr) return NOT_FOUND;
//    int *aux_cli;
//    for(int i=0; i<cantCli;i++){
//        aux_cli = pedidosClientes[i];
//        if(aux_cli[0]==dni) return i;
//    }
    if (pedidosClientes == nullptr) return -1;
    for(int i=0;pedidosClientes[i];i++){
        int * DatosClientes = pedidosClientes[i];
        if(DatosClientes[0] == dni) return i;
    }
    return -1;
    //return NOT_FOUND; 
}
void atencionDePedidos(const char*filename,char ***libros,int **&stock,
        int **&pedidosClientes,char ***&pedidosLibros, bool **&pedidosAtendidos){
    ifstream archPed(filename,ios::in);
    
    //1. VAL AUX LECT
    int numPed, dni,posCli; 
    char *codLib,c, **codigosPedLab; 
    //2. VAL MEM INCREMENTOS
    int  capacityCli=0,cantCli=0,cantPed=0, *arr_nPedCli,*arr_CapPedCli,capacityPed=0;
    int *arr_nLibPed, *arr_nAtenPed; 
    pedidosClientes = nullptr; 
    pedidosLibros = nullptr; 
    pedidosAtendidos = nullptr;
    
    while(true){
        archPed >> numPed;
        if(archPed.eof()) break; 
        archPed>>c>>dni>>c;
        codigosPedLab = LeeLibPorPed(archPed); //lee libros por pedido
        posCli = buscarCliente(pedidosClientes,dni);
        //MEMORIA POR INCREMENTOS
        if(cantCli==capacityCli) IncrementarEspaciosClientes(pedidosClientes,
                cantCli,capacityCli,arr_nPedCli,arr_CapPedCli);
        if(cantPed==capacityPed) IncrementarEspaciosPedidos(cantPed,capacityPed,
                pedidosLibros,pedidosAtendidos);
        
        //ASIGNACION 
        ColocarDatos(pedidosClientes,pedidosLibros,pedidosAtendidos,cantCli,cantPed,
                posCli,dni,numPed,arr_nPedCli,arr_CapPedCli,codigosPedLab,libros,
                stock);  
        
    } 
}
void ColocarDatos(int**&PedidosClientes,char*** &PedidosLibros,bool **&PedidoAtendidos,
        int &nClientes,int &nPedido,int posDni,int dni,int numPedido,int *&Arr_nPedCli,
        int *&Arr_CapPedCli, char **CodigoPedLib,char ***Libros,int **&stock){
    //*********LLENAMOS CLIENTES*****************************************//
    if(posDni!=NOT_FOUND){ //existe el dni :)))) SOLO AGREGAMOS LOS CODS DE LIBRO
        PedidosClientes[posDni] = colocarPedidosClientes(dni, numPedido,PedidosClientes[posDni],
                Arr_nPedCli[posDni],Arr_CapPedCli[posDni]); 
    }else{ //EL CLIENTE ES NUEVO
        PedidosClientes[nClientes-1] = ColocarPedidosClientes();  
        nClientes++; 
    }
    
    //*******************LLENAMOS PEDIDOS ********************//
    PedidosLibros[nPedido-1] = CodigoPedLib; 
    PedidoAtendidos[nPedido-1] = LeePedAtendidos(PedidosLibros[nPedido-1],Libros,
            stock); 
    nPedido++; 
}
bool * LeerPedAtendidos(char **PedidosLibros,char ***Libros,int **&stock){
    bool *PedAte=nullptr;
    int nPed=0,Cap=0, posLibro, *DatosStock;
    while(true){
        if(nPed==Cap)IncrementarPedAtendidos(PedAte,nPed,Cap);
        if(PedidosLibros[nPed-1] == nullptr) break;
        posLibro = BuscarLibro(Libros,PedidosLibros[nPed-1]);
        DatosStock = stock[posLibro];
        if(DatosStock[0] >0){
            PedAte[nPed-1] = true;
            DatosStock[0]--;
        }else{
            PedAte[nPed-1] = false;
            DatosStock[0]=0;
            DatosStock[1]++;
        }
        nPed++;
    }
    return PedAte;
}

//                                                  en la posicicion           //por ese cliente
int* ColocarPedidosCliente(int dni,int numPedido,int *&PedidosClientes,int &nPedCli,
        int &CapPedCli){
    int* aux_pedCli = PedidosClientes;
    
    if(nPedCli == CapPedCli) IncrementarPedidoClientes(aux_pedCli,nPedCli,CapPedCli);
    
    if(nPedCli-1==0){  //si la cantidad de pedidos (QUE INICIALICE!) ES CERO 
        aux_pedCli[0] = dni; 
        aux_pedCli[1] = 1; 
        aux_pedCli[2] = numPedido; 
        //tengo q botarlo con indice 3 para q añada el otro elemento
        nPedCli=nPedCli+2; 
    }else{ //ya no reservo espacio de memP?'??
        aux_pedCli[nPedCli]=numPedido; 
        aux_pedCli[1]++; 
        nPedCli++; //aumenta el num de pedidos por fila -> lo estoy guardando en un arreglo 
    }
    
    return aux_pedCli; 
}

void IncrementarPedidoClientes(int *&PedCliente,int &nPedCli,int &CapPedCli){
    CapPedCli += INCREMENTO;
    if(PedCliente == nullptr){
        PedCliente = new int [CapPedCli]{};
        nPedCli = 1;
    }
    else{
        int *AuxPedCliente = new int[CapPedCli]{};
        for(int i=0;i<nPedCli;i++){
            AuxPedCliente[i]  = PedCliente[i];
        }
        delete PedCliente;
        PedCliente =AuxPedCliente;
    }
}

void IncrementarEspaciosPedidos(int &cantPed,int &capacityPed, char ***&pedidosLibros,
        bool **&pedidosAtendidos){
    char ***aux_pedLib;
    bool **aux_pedAt;
    
    capacityPed += INCREMENTO;
    
    if(pedidosAtendidos==nullptr){ //es el primer numPed
        pedidosLibros = new char**[capacityPed]{};
        pedidosAtendidos = new bool*[capacityPed]{};
        cantPed =1;
    }else{
        aux_pedLib = new char**[capacityPed]{};
        aux_pedAt = new bool*[capacityPed]{};
        for(int i=0;i<cantPed;i++){
            aux_pedLib[i] = pedidosLibros[i];
            aux_pedAt[i] = pedidosAtendidos[i];
        }
        delete pedidosAtendidos;
        delete pedidosLibros;
        pedidosLibros = aux_pedLib;
        pedidosAtendidos = aux_pedAt;
    }
    
}
void IncrementarEspaciosClientes(int **&pedidosClientes,
                int &cantCli,int &capacityCli,int *&arr_nPedCli,int *&arr_CapPedCli){
    int **aux_pedCli, *aux_arrNped, *aux_arrcapPed;
    //aumentamos
    capacityCli +=INCREMENTO;
    if(pedidosClientes==nullptr){//nuevo cliente
        pedidosClientes = new int *[capacityCli]{};
        arr_CapPedCli = new int[capacityCli]{};
        arr_nPedCli = new int[capacityCli]{};
        cantCli=1;
    }else{//cliente existente, solo añaden productos -> necesita mas espacio
        aux_pedCli=new int *[capacityCli]{};
        aux_arrNped=new int [capacityCli]{};
        aux_arrcapPed=new int [capacityCli]{};
        for(int i=0;i<cantCli;i++){
            aux_pedCli[i] = pedidosClientes[i];
            aux_arrNped[i] = arr_nPedCli[i];
            aux_arrcapPed[i] = arr_CapPedCli[i];
        }
        delete pedidosClientes;
        delete arr_nPedCli;
        delete arr_CapPedCli;
        pedidosClientes = aux_pedCli;
        arr_nPedCli = aux_arrNped;
        arr_CapPedCli = aux_arrcapPed; 
    }
    
}

//lee una lista de pedidos
char **LeeLibPorPed(ifstream &archPed){
    //aux
    char **aux_librosPedidos; 
    char *cod; 
    //VARIABLES POR INCREMENTO 
    int numDat=0,cap=0; 
    aux_librosPedidos = nullptr; 
    
    while(true){
        cod = leeCadCin(archPed); 
        if(cap == numDat){
            incrementarPedLib(aux_librosPedidos,numDat,cap); 
        }

        aux_librosPedidos[numDat-1] = cod; 
        numDat++; 
        if(archPed.get()=='\n') break; 
    }
}

void incrementarPedLib(char **&pedidosLibros_,int &numLib,
                int &capLib){
    char **aux_pedLib;
    
    capLib +=INCREMENTO; 
    if(pedidosLibros_==nullptr){
        pedidosLibros_ = new char*[capLib]{}; 
        numLib=1; 
    }else{
        aux_pedLib = new char*[capLib]{}; 
        //lo copio
        for(int i=0; i<numLib; i++){
            aux_pedLib[i] = pedidosLibros_[i]; 
        }
        delete pedidosLibros_; 
        pedidosLibros_ = aux_pedLib; 
    }
}




//void reservaMemIncrementosCli(int **&pedidosClientes,int &cantCli,int &capacityCli){
//    //1. AUXILIARES DINAMICOS  
//    int **aux_pedCli; 
//    
//    //2. AUMENTAR CAPACIDAD 
//    capacityCli +=INCREMENTO; 
//    
//    //AL INICIO
//    if(pedidosClientes ==nullptr){ //se debe reservar en general:)))
//        pedidosClientes = new int *[capacityCli]{}; 
//        cantCli = 1; //primer elemento 
//    }
//    else{ //YA HAY DATOSSS 
//        aux_pedCli = new int*[capacityCli]{}; 
//        for(int i=0; i<cantCli; i++){
//            aux_pedCli[i] = pedidosClientes[i]; 
//        }
//        //los boto del salon
//        delete pedidosClientes; 
//        //les digo q vuelvan a pasar pq ya hay espacio 
//        pedidosClientes = aux_pedCli; 
//    }
//}