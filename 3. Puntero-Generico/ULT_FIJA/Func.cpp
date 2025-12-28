/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Utils.h"
#include "Func.h"
using namespace std;
#define NO_ENCONTRO -1

enum libro{COD,TIT,AUT,PRE};
enum cliente{DNI,NOM,PED,CAN};
void lecturaDeLibros(void *&libros,const char* nombrArch){
    ifstream archLibros(nombrArch,ios::in);
    if(not archLibros.is_open()){
        cout<<"Error: archivo "<<nombrArch<<endl;
        exit(1);
    }
    void *buffLibros[300]{},*datos,**nuevoBuff;
    int cantDatos=0;
    while(true){
        datos=leeLibros(archLibros);
        if(archLibros.eof())break;
        buffLibros[cantDatos]=datos;
        cantDatos++;
    }
    nuevoBuff=new void *[cantDatos+1]{};
    for(int i=0;i<cantDatos;i++){
        nuevoBuff[i]=buffLibros[i];
    }
    libros=nuevoBuff;
}

void *leeLibros(ifstream &archLibros){
    char *codigo,*titulo,*autor;
    int stock;
    double *precio=new double;
    codigo=leeCadena(archLibros);
    if(codigo==nullptr)return nullptr;
    titulo=leeCadena(archLibros);
    autor=leeCadena(archLibros);
    archLibros>>stock;
    archLibros.get();
    archLibros>>*precio;
    archLibros.get();
    void **datos=new void *[4];
    datos[COD]=codigo;
    datos[TIT]=titulo;
    datos[AUT]=autor;
    datos[PRE]=precio;
    return datos;
}
char *leeCadena(ifstream &arch){
    char cadena[60],*exacta;
    arch.getline(cadena,60,',');
    if(arch.eof())return nullptr;
    exacta=new char[strlen(cadena)+1];
    strcpy(exacta,cadena);
    return exacta;
}

 void lecturaDeClientes(void *&clientes,const char *nombArch){
    ifstream archClientes(nombArch,ios::in);
    if(not archClientes.is_open()){
        cout<<"Error: archivo "<<nombArch<<endl;
        exit(1);
    }
    void *buff[10]{},*datos,**nuevoBuff;
    int cantDatos=0,dni,telefono;
    char *nombre;
    while(true){
        datos=leeCliente(archClientes);
        if(archClientes.eof())break;
        archClientes.get();
        buff[cantDatos]=datos;
        cantDatos++;
    }
    nuevoBuff=new void *[cantDatos+1]{};
    for(int i=0;i<cantDatos;i++){
        nuevoBuff[i]=buff[i];
    }
    clientes=nuevoBuff;
}

void *leeCliente(ifstream &archCliente){
    char *nombre;
    int *dni=new int,telefono;
    archCliente>>*dni;
    if(archCliente.eof())return nullptr;
    archCliente.get();
    nombre=leeCadena(archCliente);
    archCliente>>telefono;
//    cout<<*dni<<" "<<nombre<<" "<<telefono<<endl;
    void **datos=new void *[4];
    int *cant=new int;
    *cant=0;
    datos[DNI]=dni;
    datos[NOM]=nombre;
    datos[PED]=nullptr;
    datos[CAN]=cant;
    return datos;
}

//GUARDO: codLib    nomB precio
//pedidos : DNI, CODLIB, NUMPED
void completarPedidos(void *&clientes,void *libros,const char *nombArch){
    ifstream arcPed(nombArch,ios::in);
    if(not arcPed.is_open()){
        cout<<"ERROR: archivo "<<nombArch<<endl;
        exit(1);
    }
    void **auxClientes=(void **)clientes,**auxLibros=(void **)libros; //para acceder al indice
    int dni,numPedido,cantPedidos[50]{},posCliente,posLibro;   //cantPed[50] -> guarda la cant de Ped por cliente
    char *codLibro; 
    while(true){
        arcPed>>dni;
        if(arcPed.eof())break;
        arcPed.get();
        codLibro=leeCadena(arcPed);
        arcPed>>numPedido;
        posCliente=buscarCliente(clientes,dni);
        if(posCliente!=NO_ENCONTRO){
            posLibro=buscarLibro(codLibro,libros);
            agregarLibro(auxClientes[posCliente],auxLibros[posLibro],numPedido,codLibro,cantPedidos[posCliente]);
        }
    }
    for(int i=0;auxClientes[i];i++){
        recortaPedidos(auxClientes[i],cantPedidos[i]);
    }
        
}

//                                          por cliente
void recortaPedidos(void *&cliente,int cantPedidos){
    void **auxClientes=(void **)cliente; //campo pedidos
    recortaBuffer(auxClientes[PED],cantPedidos);
}
void recortaBuffer(void *&pedidos,int cantPedidos){
    void **aux=(void **)pedidos,**nuevo; //acceder a los campos de los pedidos
    if(cantPedidos>0){
//        cout<<cantPedidos<<endl;
        nuevo=new void*[cantPedidos+1]{}; //buff exacto de pedidos 
        for(int i=0;i<cantPedidos;i++){  //copio cada registro de pedidos 
            nuevo[i]=aux[i];
           
        }
        delete aux; //lo boto del salon 
        pedidos=nuevo;
    }
    else{
        delete aux;  //borro el buff que le di 
        pedidos=nullptr; //le asigno nullptr
    }
}
//                      void * cliete,   void *libro                                                 cantPedCliente
void agregarLibro(void *&cliente,void *libro,int numPedido,char *codLibro,int &cant){ 
    void **auxClientes=(void **)cliente,**auxLibros=(void **)libro; 
    //void **auxCliente= (void **)cliente, **aux_libros = (void **)libro; //para acceder alos campos del cliente y del librp
    char *titulo = (char *)auxLibros[TIT]; 
    //tengo que copiar ese valor
    char *nuevoTitulo; 
    nuevoTitulo = new char [strlen(titulo)+1]; 
    strcpy(nuevoTitulo,titulo); 
    
    //si la cant deped es 0 -> le tengo que dar espacio de memoria 
    if(cant==0){
        auxClientes[PED]=new void *[200]; //le doy un espacio de 200 pedidos como max jijiji
    }
    agregamosPedido(numPedido,codLibro,nuevoTitulo,auxClientes[PED],cant);
    int *cantLibros = (int *)auxLibros[CAN];
//    int valor
    (*cantLibros)++;
//    cout<<*cantLibros<<endl;
   
    cant++; //SUMA LA CANT DE PEDIDOS POOR CLIENTE 
}

void agregamosPedido(int numPedido,char *codLibro , char *nuevoTitulo, void *pedidos,int cant){
    void **auxPed = (void **)pedidos, *registro; //accede a los indicesssssss 
    int *numPed = new int; 
    *numPed = numPedido;
    
    registro = new void *[3];
    registro[0] = codLibro;
    registro[1] = nuevoTitulo; 
    registro[2] = numPed; 
    
    auxPed[cant] = registro; //añado el registro en el indice de numPed
}


int buscarLibro(char *codLibro,void *libros){
    void **aux=(void **)libros;
    for(int i=0;aux[i];i++){
        if(compararLibros(aux[i],codLibro)==0)return i;
    }
    return NO_ENCONTRO;
}
int compararLibros(void *libro,char *codLibro){
    void **datos=(void **)libro;
    char *cod=(char *)datos[COD];
    return strcmp(cod,codLibro);
}
int buscarCliente(void *clientes,int dni){
    void **aux=(void **)clientes;
    for(int i=0;aux[i];i++){
        if(comparar(aux[i],dni))return i;
    }
    return NO_ENCONTRO;
}

bool comparar(void *cliente,int dni){
    void **datos=(void **)cliente;
    int *cod=(int *)datos[DNI];
    return dni==*cod;
}
