

#include "Utils.h"
#include "BibliotecaListaGenerica.h"
using namespace std; 
enum Reg{DATO,SIG};

void crearLista(ifstream &arch,void *&lista, 
        void* (*lee)(ifstream &), int (*comp)(const void*, const void*)){
    
    void *dato; 
    lista = nullptr; //INICIALIZACION 
    
    while(true){
        dato = lee(arch);
        if(dato ==nullptr) break; 
        insertaLista(lista,dato,comp); 
    }
}

void insertaLista(void *&lista,void * dato, int (*comp)(const void*, const void*)){
    void **p = (void **)lista; //puntero que recorre la lista
    void **ant = nullptr;    //inicializo ant a null
    void **nuevo; 
    
    nuevo = new void*[2]{}; //UN NODITO JEJE -> se inicializa en null 
    nuevo[DATO] = dato; 
    
    //recorrer con p para encontrar donde insertar nuestro dato :))))
    while(p!=nullptr){
        if(comp(p[DATO],dato)>0) break; //cuando nuestro dato que queremos insertar es mayor 
        ant = p; 
        p = (void **)p[SIG]; 
    }
    nuevo[SIG] = p; 
    
    //no se pone rec pq puede confundirse con la cola 
    if(ant ==nullptr) lista = nuevo; //si apuntamos al inicio 
    else ant[SIG] = nuevo; 
    
}

void imprimirLista(void*lista, void (*imprime)(void *)){
    void **listaCampos = (void **)lista; //para ACCEDER a los nodidos (mini arreglos) de la lista 
    
    while(listaCampos){                                         //recorre la lista 
        imprime(listaCampos[DATO]); 
        listaCampos = (void **)(listaCampos[SIG]); //avanza en el recorrido
    }
}


//OJO: ELIMINA UN REGISTRO 
void eliminarLista(void *lista, void (*elimina)(void *)){
    void **listaCampos =(void **)lista, **sale;
    
    while(listaCampos){
        sale = listaCampos; //apunta al primer elemento 
        elimina(listaCampos[DATO]); //elimina solo el DATO, no el SGTE
        listaCampos=(void **)(listaCampos[SIG]);
        delete sale;
    }
}



///////////////////////////////////// de erasmito ////////////////////////
int cmp_registro_str(const void *a, const void *b){ //OJO: yo elijo que comparar 
    void **regI = (void **)a, **regK = (void **)b; 
    
    char *nombI = (char *)
}


// qsort() -> se necesita un aterrizaje adicional (en el qort que hacemos se le pasa al elemento) 


//si no nos dicen que lo insertemos en orden, no es necesario pasarle el cmp 
//ISNERTAR AL ULT: recorrer toda la lista // tmb se puede poner en el reg un campo de COLA 
// enum{DATO,ANT,SIG};
// enum{DATO,SIG, COLA };

// REPASAR IINSERTAR FINAL, INSERTAR INICIO -> simula el comportamiento de PILAS, COLAS 

//NO VIENE QSORT 

