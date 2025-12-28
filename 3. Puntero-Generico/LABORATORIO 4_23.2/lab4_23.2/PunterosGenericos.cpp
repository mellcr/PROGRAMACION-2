/* 
 * Proyecto: lab4_23.2
 * Archivo:   PunterosGenericos.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 23 de abril de 2024, 14:06
 */

#include "Utils.h"
#include "MuestraPunteros.h"
#include "PunterosGenericos.h"
using namespace std; 
#define NO_ENCONTRADO -1
enum Producto{COD,DESC,PRE,TIPOL};
enum Cliente{DNI,NOMB,LISTAPED,LCRED};
enum Pedido{CODIGOPRODUCTO,CANTPRODUCTO,TOTALPEDIDO};
//PRODUCTOS
//cod   desc    precio  tipoLinea(char)
void cargaProductos(void *&pro){
    ifstream arch("Productos2.csv",ios::in);
    if(!arch.is_open()){
        cout <<"no se abrio "<<endl; 
        exit(1);
    }
    
    void *registro; 
    void *buffReg[200]{}; 
    //2. NUM EXACTO DE DATOS 
    int numProd = 0; 
    
    while(true){
        registro = leeRegistroPro(arch);
        if(registro==nullptr) break; 
        
        buffReg[numProd] = registro;
//        void **product = (void**)(registro);
//        double *pre = (double *)(product[PRE]);
//        cout <<*pre<<endl;
        numProd++; 
    }
    
    void **auxExact = new void*[numProd+1]{}; 
    for(int i=0; i<numProd; i++){
        auxExact[i] = buffReg[i]; 
    }
    //auxExact[numProd] = nullptr; 
    pro = auxExact; 
    
    imprimeproductos(pro); 
}
void* leeRegistroPro(ifstream &arch){
    void **registro = new void *[4]; 
    //datos
    char *cod, *desc, *tipoLin,c;
    double *precio,p; 
    
    
    cod = leeCadDelim(arch,',');
    if(arch.eof()) return nullptr; //retorna NULL (NO OLVIDAR)  
    desc = leeCadDelim(arch,','); 
    arch>>p>>c;
    tipoLin = leeCadDelim(arch,'\n'); 

    //llenamos los datos no directos
    precio = new double; 
    *precio =p;
    
    //llenamos el registro 
    registro[COD] = cod; 
    registro[DESC] = desc; 
    registro[PRE] = precio;
    registro[TIPOL] = tipoLin; 
    
    return registro; 
}

char *leeCadDelim(ifstream &arch, char delim){
    char *str, aux[100];
    
    arch.getline(aux,100,delim); 
    str = new char[strlen(aux)+1];
    strcpy(str,aux); 
    
    return str; 
}

//CLIENTES
//dni   nomb    telef   lineaCred
void cargaClientes(void *&clientes){
    ifstream arch("Clientes2.csv",ios::in);
    if(!arch.is_open()){
        cout <<"no se abrio :p"<<endl; 
        exit(1); 
    }
    
    void *registro; 
    void *buffReg[200]{};
    
    int numDat = 0; 
    while(true){
        registro = leeRegistroCli(arch);
        if(registro ==nullptr) break; 
        
        buffReg[numDat] = registro; 
//        void **cli = (void**)(registro);
//        int  *dni = (int *)(cli[DNI]);
//        cout <<*dni<<endl;
        
        numDat++; 
    }
    
    void **auxClientes;
    asignaMemExact(auxClientes,buffReg,numDat); 
    clientes = auxClientes; 
    
    imprimeclientes(clientes); 
} 

void *leeRegistroCli(ifstream &arch){
    void **reg = new void *[4];
    //variables
    int *dni, *telef;
    double *linCred; 
    char *nomb,c;
    
    dni = new int;
    telef = new int; 
    linCred = new double;
    
    arch>>*dni; 
    if(arch.eof()) return nullptr;
    arch.get(); 
    nomb = leeCadDelim(arch,',');
    arch>>*telef>>c>>*linCred;
    arch.get(); //lee el salto de linea 
    
    //guardamos en el regi
    reg[DNI] = dni; 
    reg[NOMB] = nomb; 
    reg[LISTAPED] = nullptr; 
    reg[LCRED] = linCred; 
    
    return reg; 
}

void asignaMemExact(void **&auxClientes,void **buffReg,int numDat){
    auxClientes= new void *[numDat+1]; 
    for(int i=0; i<numDat;i++){
        auxClientes[i] = buffReg[i];
        
        //void **cli = (void**)(auxClientes);
        //int  *dni = (int *)(cli[DNI]);
        //cout <<*dni<<endl;
    }
    auxClientes[numDat] = nullptr; 
}

//PEDIDOS
//codProd   dni cant
void cargaPedidos(void *productos,void *clientes){
    ifstream arch("Pedidos2.csv",ios::in);
    if(!arch.is_open()){
        cout <<"no se abrio :p"<<endl; 
        exit(1); 
    }
    int dniLect,cant,posCli,posProd, *numPed; 
    char *codProd,c;
    bool debeInsertar, debeDescontar; 
    double montoADescontar; 
    //auxiliares para prod
    void **arr_prod = (void**)productos; 
    void **prod;
    char *tipoL; 
    double *precio; 
    //auxiliares para cliente 
    void **arr_cli = (void**)clientes; 
    void **client; 
    double *linCred; 
    
    numPed = asignarMemoriaTemportalEnPedidos(clientes);
    
    while(true){
        codProd = leeCadDelim(arch,','); 
        if(arch.eof()) break; 
        arch>>dniLect>>c>>cant;
        arch.get(); 
        
        posCli = buscarDni(dniLect,clientes); 
        if(posCli!=NO_ENCONTRADO){ //existe el cliente 
            posProd = buscarCod(codProd,productos); 
            if(posCli!=NO_ENCONTRADO){
                //validamos 
                validarInsercion(productos,posProd,clientes,posCli,cant, debeInsertar,
                        debeDescontar,montoADescontar); 
                
                if(debeInsertar){
                    insertarPedidoEnCliente(clientes,posCli,debeDescontar,
                            codProd,cant,montoADescontar,numPed); 
                    
                }
                
            }
            
        }
    }
    
}
void insertarPedidoEnCliente(void*& clientes, int indiceCliente, bool debeDescontar,
            char *codProducto, int cantidad, double montoPedido, int* nPedidos){
        void **auxClientes = (void**)clientes;
    void **auxCliente  = (void**)auxClientes[indiceCliente];
    void **auxPedidos = (void**)auxCliente[LISTAPED];
    void **registro = new void*[3];
    int *auxCantidad = new int;
    *auxCantidad = cantidad;
    double *auxMonto = new double, *auxLinea;
    *auxMonto = montoPedido;
    registro[CODIGOPRODUCTO] = codProducto;
    registro[CANTPRODUCTO] = auxCantidad;
    registro[TOTALPEDIDO] = auxMonto;
    
    // Insertar en puntero de pedidos
    int indiceInsertado = nPedidos[indiceCliente];
    auxPedidos[indiceInsertado] = registro;
    auxCliente[LISTAPED] = auxPedidos;
    
    // Descontar de la línea en caso corresponda.
    if(debeDescontar){
        auxLinea = (double*) auxCliente[LCRED];
        *auxLinea -= montoPedido;
        auxCliente[LCRED] = auxLinea; 
    }
    
    auxClientes[indiceCliente] = auxCliente;
    clientes = auxClientes;
    nPedidos[indiceCliente]++;

}

void validarInsercion(void *productos,int posProd,void *clientes,int posCli,
        int cant, bool &debeInsertar,bool & debeDescontar,double &montoPedido){
    char *tipo;  
    // auxiliares
    void **auxProductos = (void**) productos;
    void **auxProducto = (void**) auxProductos[posProd];
    void **auxClientes = (void**) clientes;
    void **auxCliente = (void**) auxClientes[posCli];
    
    double *aux_precio = (double *)auxProducto[PRE]; 
    montoPedido = cant* (*aux_precio); 
    
    //char tipo ---> tipo = *((char*)auxProducto[TIPOL]);  //* adelante indica que es el valor (solo char)
    
    tipo = (char *)auxProducto[TIPOL]; 
    if(strcmp(tipo,"N")==0){
        debeDescontar = false; 
        debeInsertar = true;
    }else{
        //verificar la linea de credito 
        double *lineaCredito = (double *) auxCliente[LCRED]; 
        if(*lineaCredito >=montoPedido){
            debeInsertar = true; 
            debeDescontar = true; 
        }else{
            debeInsertar = false; 
        }
    }
}

void agregaPedido(void *&clientes,double linNecesitada,char *codProd,int cant,int *&numPed,
        int posCli){
    //aux
    int *cantReg = new int{}; 
    *cantReg = cant; 
    double *monto = new double{}; 
    *monto = linNecesitada; 
    
    //auxiliares para cliente 
    void **arr_cli = (void**)clientes; 
    void **client; //un solo cliente }
    void **auxPedidos = (void**)client[LISTAPED]; //para acc a los pedidiso 
    
    void **registro = new void *[3]; //codProd  cant  totalPagar 
    registro[CODIGOPRODUCTO] = codProd;
    registro[CANTPRODUCTO] = cantReg; 
    registro[TOTALPEDIDO] = monto;
    
    //hallamos ind del cliente en el arrreglo de num de pedios
    int indCliPed =  numPed[posCli];
    auxPedidos[indCliPed] = registro; 
    client[LISTAPED] = auxPedidos; //para guardar el puntero 
    
    
    
    arr_cli[posCli] = client; 
    clientes = arr_cli; 
    numPed[posCli]++; 
}


int buscarCod(char *codProd,void *productos){
    void **auxProductos = (void **)productos, **auxProd; //para acceder
    char *auxCad; 
    
    for(int i=0; auxProductos[i]; i++){
        auxProd = (void**)auxProductos[i]; //para acceder a sus indices 
        auxCad = (char *)(auxProd[COD]);
        if(strcmp(auxCad,codProd)==0) return i; 
    }
    return NO_ENCONTRADO; 
}

int buscarDni(int dniLect,void *clientes){
    void **auxClientes = (void**)clientes, **auxCliente;
    int *auxDNI;
    
    for(int i=0; auxClientes[i]; i++){
        auxCliente = (void**)auxClientes[i];
        auxDNI = (int*) auxCliente[DNI];
        if(*auxDNI == dniLect)
            return i;
    }
    return NO_ENCONTRADO;    
}


//crea un buff de 50 para cada lista de ped de clientes
// crea un arreglo de enteros que guarda el numPed por cliente 
int *asignarMemoriaTemportalEnPedidos(void *&clientes){
    //creo la memoria adentro de clientes 
    int nCli = 0, *nPedXCliente; 
    
    void **arr_Cli = (void**)clientes, **aux_Cli; 
    
    for(nCli; arr_Cli[nCli];nCli++){
        //puntero temporal de 50 registros
        aux_Cli = (void **)arr_Cli[nCli];  //acceder a los campos de cliente 
        aux_Cli[LISTAPED] = new void*[50]{}; 
        
        arr_Cli[nCli] = aux_Cli; //asigno el aux al antiguo 
    }
    
    clientes = arr_Cli; 
    nPedXCliente = new int[nCli]{}; //crea un arreglo segun el num de clientes 
    return nPedXCliente; 
}


