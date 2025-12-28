/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <list>

#include "Utils.h"
#include "MemIncremento.h"
#include "AperturaDeArchivos.h"
#define INCREMENTO 5
#define NOT_FOUND -1
using namespace std;
enum Libro{COD,TIT,AUTOR};
enum Stock{STOCK,NO_ATEN};

char *leeCadDelim(ifstream &arch, char delim){
    char *str, buff[100];
    arch.getline(buff,100,delim);
    //if(arch.eof()) return nullptr;
    str = new char[strlen(buff)+1]{};
    strcpy(str,buff);
    
    return str;
}
char *leeCadTxt(ifstream &arch){
    char *str, buff[100];
    arch>>buff;
    //if(arch.eof()) return nullptr;
    str = new char[strlen(buff)+1]{};
    strcpy(str,buff);
    return str;
}
void lecturaDeLibros(const char *filename,char ***&libros,int **&stock){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,filename);
    
    //1. VAL LECT
    char *codLib, *titulo, *autor,c;
    int stockLib;
    double precio;
    //2. VAL INCREMENTOS
    int numLib =0,capLib=0;
    libros=nullptr;
    stock=nullptr;
    while(true){
        codLib = leeCadDelim(arch,',');
        if(arch.eof()) break;
        titulo = leeCadDelim(arch,',');
        autor = leeCadDelim(arch,',');
        arch>>stockLib>>c>>precio;
        arch.get();
        
        //reservamos memoria  con el metodo de incrementos
        if(numLib==capLib) asignaMemLib(libros,stock,numLib,capLib);
        colocarDatos(codLib,titulo,autor,stockLib,libros[numLib-1],stock[numLib-1]);
        numLib++;
    }
}
//enum Libro{COD,TIT,AUTOR};
//enum Stock{STOCK,NO_ATEN};
void colocarDatos(char *codLib,char *titulo,char *autor,int stockLib,char **&libros,
        int *&stock){
    char **datosLib = new char*[3]{};
    datosLib[COD] = codLib;
    datosLib[TIT] = titulo;
    datosLib[AUTOR] = autor;
    
    int *datosStock = new int[2]{};
    datosStock[STOCK] = stockLib;
    datosStock[NO_ATEN] = 0;
    
    libros = datosLib;
    stock = datosStock;
}

void asignaMemLib(char ***&libros,int **&stock,int &numLib,int &capLib){
    //definimos variables auxiliares:))
    char ***buff_lib;
    int **buff_stock;
    
    capLib+=INCREMENTO;
    //AUN NO TIENE DATOS
    if(libros==nullptr){
        libros = new char **[capLib+1]{};
        stock = new int *[capLib+1]{};
        numLib=1;
    }
    //YA HAY DATOS
    else{
        buff_lib = new char **[capLib+1]{};
        buff_stock = new int *[capLib+1]{};
        for(int i=0;i<numLib;i++){
            buff_lib[i] = libros[i];
            buff_stock[i] = stock[i];
        }
        delete libros;
        delete stock;
        libros = buff_lib;
        stock = buff_stock;
    }
}

void pruebaDeLecturaDeLibros(const char*filename,char ***libros,int **stock){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,filename);
    
    arch<<left<<setw(15)<<"CODIGO"<<setw(55)<<"TITULO"<<setw(40)<<"AUTOR"
            <<setw(10)<<"STOCK INI"<<setw(10)<<"NO ATEND."<<endl;
    for(int i=0; libros[i];i++){
        imprimeLibro(arch,libros[i],stock[i]);
    }
}
//enum Libro{COD,TIT,AUTOR};
//enum Stock{STOCK,NO_ATEN};
void imprimeLibro(ofstream &arch,char **libro,int *stock){
    char *cod = libro[COD];
    char *titulo = libro[TIT];
    char *autor = libro[AUTOR];
    arch<<left<<setw(15)<<cod<<setw(55)<<titulo<<setw(40)<<libro[AUTOR]
            <<right<<setw(10)<<stock[STOCK]<<setw(10)<<stock[NO_ATEN]<<endl;
}

/////////////////////////////////////////////////////// PREGUNTA B ////////////////////////////////////////////////////////////////////////////
void atencionDePedidos(const char*filename,char ***&libros,int **&stock,
        int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,filename);
    
    //.1 VAL LECT
    int numLeid, dniLeid,posCli;
    char **codigos,c,cod[8];
    //2. VAR INCREMENTOS
    pedidosClientes=nullptr;
    pedidosLibros=nullptr;
    pedidosAtendidos=nullptr;
    int numCli=0, capCli=0,numPedCli[500]{},capPedCli[500]{}; //para clientes
    int numPedLib[500]{},capPedLib[500]{},numPed=0,capPed=0; //para pedLib y pedAtend
    while(true){
        arch>>numLeid;
        if(arch.eof()) break;
        arch>>c>>dniLeid;
        //lectura de la lista de libros por pedido
        codigos = leerLibrosPedidos(arch,capPedLib[numLeid],numPedLib[numLeid]);
//        for(int i=0;codigos[i];i++){
//            char *codigosol=codigos[i];
//            cout <<codigosol<<"  ";
//        }
//        cout<<endl;
        
        //ASIGNAMOS MEMORIA PARA CLI
        if(numCli==capCli) asignaMemCli(pedidosClientes,numCli,capCli); //numCli=1
        posCli = buscarCli(dniLeid,pedidosClientes);
        //cout<<posCli<<endl;
        colocaDatosCliente(posCli,dniLeid,numLeid,pedidosClientes,numCli,
                numPedCli,capPedCli);
        
        //ASIGNAMOS MEMORIA PARA PEDIDOS
        if(numPed==capPed or numLeid>=capPed) incrementaMemPed(pedidosLibros,pedidosAtendidos,numPed,
                capPed,numLeid); //numPed =1 
        colocaDatosPedidos(numLeid,codigos,pedidosLibros,
                pedidosAtendidos,numPedLib,capPedLib,numPed, stock,libros);
        numPed++;
    }
}
//                                                                              cap y num para el pedido en ese indice
char ** leerLibrosPedidos(ifstream &arch,int &capPedLib,int &numPedLib){
    char **librosPedidos=nullptr,*codigo;
    while(true){  
            if(arch.get()=='\n') break;
            codigo=leeCadTxt(arch);
            if(numPedLib==capPedLib) incremEspPed(librosPedidos,numPedLib,capPedLib);
            librosPedidos[numPedLib-1] = codigo;
            numPedLib++;
        }
    
    return librosPedidos;
}

void incremEspPed(char **&librosPedidos,int &num,int &cap){
    char **buff_LibPed;
    
    cap+=INCREMENTO;
    //INICIO
    if(librosPedidos==nullptr){
        librosPedidos = new char* [cap+1]{};
        num=1;
    }
    //YA HAY DATOS
    else{
        buff_LibPed= new char* [cap+1]{};
        for(int i=0;i<num;i++){
            buff_LibPed[i] = librosPedidos[i];
        }
        delete librosPedidos;
        librosPedidos = buff_LibPed;
    }
}

void colocaDatosPedidos(int numLeid,char **codigos,char ***&pedidosLibros,
        bool **&pedidosAtendidos,int *numPedLib,int *capPedLib,int &numPed,
        int **&stock, char ***libros){
    pedidosLibros[numLeid]=codigos;
//            for(int i=0;codigos[i];i++){
//            char *codigosol=codigos[i];
//            cout <<codigosol<<"  ";
//        }
//        cout<<endl;
    
    pedidosAtendidos[numLeid] =  llenaPedAtendido(codigos,pedidosLibros[numLeid],stock,libros,
            numPedLib[numLeid],capPedLib[numLeid]);
}

bool* llenaPedAtendido(char **codigosLeid,char **listaLibPed,int **&stock,char ***libros,
        int numPedLib, int capPedLib){
    bool *pedAtend = nullptr;
    int posLib, *DatosStock;
    
    int numDat=0,cap=0;
        for(int i=0;codigosLeid[i];i++){
            if(numDat==cap)incremEspPed(pedAtend,numDat,cap); //numDat=1
//            char *codigosol=codigosLeid[i];
//           cout <<codigosol<<"  ";
            posLib = BuscarLibro(libros,codigosLeid[i]);
//            cout<<posLib<<' ';
            
            if(posLib!=NOT_FOUND){
                DatosStock = stock[posLib];
                if(DatosStock[0]>0){ //hay stock!!
                    pedAtend[numDat-1] = true;
                    (DatosStock[0])--;
                }else{
                    pedAtend[numDat-1] = false;
                    DatosStock[0]=0;
                    (DatosStock[1])++;
                }                
            }
            numDat++;
            }
//        cout<<endl;
    return pedAtend;
}

void incremEspPed(bool *&pedAtend,int &num,int &cap){
    bool *buff_PedAtn;
    
    cap+=INCREMENTO;
    //INICIO
    if(pedAtend==nullptr){
        pedAtend = new bool [cap+1]{};
        num=1;
    }
    //YA HAY DATOS
    else{
        buff_PedAtn= new bool[cap+1]{};
        for(int i=0;i<num;i++){
            buff_PedAtn[i] = pedAtend[i];
        }
        delete pedAtend;
        pedAtend = buff_PedAtn;
    }
}

int buscarProd(char *codBus,char ***libros){
    if(codBus==nullptr) return NOT_FOUND;
    for(int i=0;libros[i];i++){
        char **libro = libros[i];
        char *cod = libro[0];
        if(strcmp(libro[0],codBus)==0) return i;
    }
    return NOT_FOUND;
}
int BuscarLibro(char ***Libros,char *PedLibros){
    for(int i=0;Libros[i];i++){
        char **DatosLibro = Libros[i];
        if(strcmp(DatosLibro[0],PedLibros)==0) return i;
    }
    return -1;
}

void incrementaMemPed(char ***&pedidosLibros,bool **&pedidosAtendidos,int &numPed,
                int &capPed,int numLeid){
    char ***buff_Lib;
    bool **buff_Atend;
    
    if(numLeid>=capPed){
        capPed = capPed+INCREMENTO+numLeid;
    }else{
        capPed+=INCREMENTO;
    }
    
    //INICIO
    if(pedidosLibros==nullptr){
        pedidosLibros = new char** [capPed+1]{};
        pedidosAtendidos = new bool *[capPed+1]{};
        numPed=1;
    }
    //YA HAY DATOS
    else{
        buff_Lib = new char** [capPed+1]{};
        buff_Atend = new bool *[capPed+1]{};
        for(int i=0;i<numPed;i++){
            buff_Lib[i] = pedidosLibros[i];
            buff_Atend[i] = pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros = buff_Lib;
        pedidosAtendidos = buff_Atend;
    }
}

void colocaDatosCliente(int posCli,int dniLeid,int numLeid,int **&pedidosClientes,
        int &numCli, int *numPedCli, int *capPedCli){
    
    if(posCli!=NOT_FOUND){ //existe el cliente -> solo se añade codigos
            colocaCli(dniLeid,numLeid,pedidosClientes[posCli],numPedCli[posCli],
                    capPedCli[posCli]);
    }
    //ES UN NUEVO CLIENTE
    else{ 
            colocaCli(dniLeid,numLeid,pedidosClientes[numCli-1],numPedCli[numCli-1],
                    capPedCli[numCli-1]);
            numCli++;
    }
}

void colocaCli(int dniLeid,int numLeid,int *&pedidosCliente,int &numPedCli,
                    int &capPedCli){
    if(numPedCli==capPedCli) incrementoEspaciosCli(pedidosCliente,numPedCli,capPedCli);
    //ES EL PRIMER CLIENTE
    if(numPedCli-1==0){ 
        pedidosCliente[0] = dniLeid;
        pedidosCliente[1]=1;
        pedidosCliente[2] = numLeid;
        numPedCli+=2;       //3=1+2  -> ind 3 es donde se insertara el sgte numPedCli
    }
    //SOLO AÑADE LOS CODS DE LIBROS PEDIDOS
    else{
        pedidosCliente[numPedCli]=numLeid;
        (pedidosCliente[1])++; //incrementa el numPed
        numPedCli++;
    }
}

void incrementoEspaciosCli(int *&pedidosCliente,int &num,int &cap){
    int *buff_Cli;
    
    cap+=INCREMENTO;
    //INICIO
    if(pedidosCliente==nullptr){
        pedidosCliente = new int [cap]{};
        num=1;
    }
    //YA HAY DATOS
    else{
        buff_Cli= new int [cap]{};
        for(int i=0;i<num;i++){
            buff_Cli[i] = pedidosCliente[i];
        }
        delete pedidosCliente;
        pedidosCliente = buff_Cli;
    }
}
void asignaMemCli(int **&pedidosClientes,int &numCli,int &capCli){
    int **buff_Cli;
    
    capCli+=INCREMENTO;
    //INICIO
    if(pedidosClientes==nullptr){
        pedidosClientes = new int *[capCli]{};
        numCli=1;
    }
    //YA HAY DATOS
    else{
        buff_Cli= new int *[capCli]{};
        for(int i=0;i<numCli;i++){
            buff_Cli[i] = pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes = buff_Cli;
    }
}

int buscarCli(int dniBus,int **pedidosClientes){
    //if(pedidosClientes==nullptr) return NOT_FOUND;
    for(int i=0;pedidosClientes[i];i++){ //int *
        int *cliente =pedidosClientes[i];
        int dni = cliente[0];
        if(dni==dniBus) return i;
    }
    return NOT_FOUND;
}


//////////////////////////////////////////////////////////// REPORTE //////////////////////////////////////////////////////////////////
void pruebaPedidosCli(const char*filename,
        int **pedidosClientes,char ***pedidosLibros,bool **pedidosAtendidos){
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,filename);
    
    for(int i=0; pedidosClientes[i];i++){
        int *cliente = pedidosClientes[i];
        arch<<"DNI:"<<left<<setw(20)<<cliente[0]<<setw(20)<<cliente[1]<<endl;
        arch<<"Libros Pedidos: "<<endl;
        
        int cant = cliente[1];
        for(int k=0;k<cant;k++){
            arch<<cliente[k+2]<<endl;
        }
    }
    
    ofstream archPed("FINAL.txt",ios::out);
    bool *pedido;
    char **listaCod;
    for(int i=1; pedidosAtendidos[i];i++){
        listaCod =pedidosLibros[i];
        pedido = pedidosAtendidos[i];
        archPed<<"N. Pedido  "<<i<<":"<<endl;
        
        for(int k=0;pedido[k];k++){
            archPed<<listaCod[k];
         if(pedido[i]==true){
             archPed<<"  T  ";
         }else{
             archPed<<"  F  ";
         }
         archPed<<endl;
        }
    }
    
}