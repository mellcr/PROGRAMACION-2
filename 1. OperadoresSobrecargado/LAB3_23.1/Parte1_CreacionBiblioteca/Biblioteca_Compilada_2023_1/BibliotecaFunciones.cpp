/* 
 * Proyecto: Biblioteca_Fuentes_2023_1
 * Archivo:   Overloads.cpp
 * Autor: Mell Alessandra Carbajal Román
 * 
 * Created on 3 de abril de 2024, 15:25
 */

#include <iostream>
#include <fstream>
#include <iomanip> 
#include <cstring> 
using namespace std;
//#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#define NOT_FOUND -1

//cin >> 
//LEE SOLO UN CURSO 

bool operator >> (ifstream &in, struct StCurso &curso){
    
    in.getline(curso.codigoDelCurso,7,' ');
    if(in.eof()) return false; 
    in>>ws; 
    in.getline(curso.nombreDelCurso,60,' '); 
    in >> curso.creditos;
    in >> curso.codigoDelProfesor;
    in>>ws; 
    in.getline(curso.nombreDelProfesor,60); //come el salto de linea 
//        archCursos>>ws;
//    archCursos>>cursos.nombreDelProfesor;
//    archCursos.get();
//    
    
    curso.numeroDeAlumnos=0; 
    curso.ingresos=0.0;     
    
    return true; 
}

//LEE UN ALUMNO 
bool operator >> (ifstream &in, struct StAlumno &alum){
    char car; 
    
    in >> alum.semestre;
    if(in.eof()) return false; 
    in.get(); //lee la coma 
    in >> alum.codigo;
    in>>ws; 
    in.getline(alum.nombre,60,' ');
    in >> car; 
    if(car=='V'){
        strcpy(alum.modalidad,"VIRTUAL");
        in >> car; //lee la G
    }else{
        if (car=='S'){
            strcpy(alum.modalidad,"SEMIPRESENCIAL");
            in >> alum.porcentaje>>car; 
        }else{
            if(car=='G'){ //presencial es espacio en blanco -> lee la letra G de la escala
                strcpy(alum.modalidad,"PRESEENCIAL");
            }
        }
    }
    
    in >> alum.escala;    
    alum.costoTotal = 0.0;
    alum.numeroDeCursos = 0; 
    
    //ARREGLO DE CURSOS SE QUEDA VACIO 
    
    return true; 
}

//LEER UN REGISTRO DE MATRICULA 
bool operator >> (ifstream &in, struct StRegistroDeMatricula &matr){
    in.getline(matr.codigoDelCurso,7,' ');
    if(in.eof()) return false; 
    in>>matr.semestreDelAlumno;
    in.get(); 
    in>>matr.codigodelAlumno; 
    in.get(); //lee el cambio de linea pues se inicia con una cadena
    
    
    return true; 
}


//agregar UN CURSO a un ARREGLO DE CURSOS
void operator +=(struct StCurso *arrCur, struct StCurso &cur){
    //recorremos el arreglo 
    int n=0; 
    while(true){
        if(strcmp(arrCur[n].codigoDelCurso,"XXXXXX")==0) break; 
        n++; //guarda la pos del ult elemento 
    }
    
    //COPIANDO LA INFOOFFOFOFOOF 
    strcpy(arrCur[n].codigoDelCurso,cur.codigoDelCurso); 
    strcpy(arrCur[n].nombreDelCurso,cur.nombreDelCurso); 
    arrCur[n].codigoDelProfesor = cur.codigoDelProfesor; 
    arrCur[n].creditos = cur.creditos; 
    
    arrCur[n].ingresos = cur.ingresos; 
    arrCur[n].numeroDeAlumnos = cur.numeroDeAlumnos; 
    
    //coloca el nuevo ult elemento su banderita finilizadora akdjhls
    strcpy(arrCur[n+1].codigoDelCurso,"XXXXXX"); 
}


//UN ALUMNO a un ARR DE ALUMNOS
void operator +=(struct StAlumno *arrAlum, struct StAlumno &alum){
    //recorremos el arreglo 
    int n=0; 
    while(true){
        if(arrAlum[n].semestre ==0) break; 
        n++;
    }
    
    arrAlum[n].semestre = alum.semestre;
    arrAlum[n].codigo = alum.codigo;
    strcpy(arrAlum[n].nombre,alum.nombre);
    strcpy(arrAlum[n].modalidad,alum.modalidad); 
    arrAlum[n].escala = alum.escala; 
    arrAlum[n].costoTotal = alum.costoTotal;
    arrAlum[n].numeroDeCursos = alum.numeroDeCursos;
    
    //banderita para finalizar 
    arrAlum[n+1].semestre =0; 
    
}

    

int buscarEnCurso(char *codBuscado,struct StCurso *arrCur){
    int n=0; 
    while(true){
        if(strcmp(codBuscado,arrCur[n].codigoDelCurso)==0) return n; 
        n++;
    }
    return NOT_FOUND;
}

//1. en reg, agarra el curso
//2. busca ese curso en arrCur
//3. agregar alum a la lista de matriculador -> mod num de alum 
void operator *=(struct StCurso *arrCur, 
        struct StRegistroDeMatricula &regisMatric){
    int posCur,numAlum;
    posCur = buscarEnCurso(regisMatric.codigoDelCurso,arrCur);
    
    if(posCur!=NOT_FOUND){
            numAlum = arrCur[posCur].numeroDeAlumnos;
            arrCur[posCur].alumnos[numAlum]= regisMatric.codigodelAlumno;
            (arrCur[posCur].numeroDeAlumnos)++;
    }

}


int buscarEnAlum(int codAlumBus,struct StAlumno *arrAlum){
    int n=0; 
    while(true){
        if(codAlumBus == arrAlum[n].codigo) return n; 
        
        n++;
    }
    return NOT_FOUND;

}

//agregar UN CURSO al alumno en el q se matroculo
//1. buscar el alum en arrALum
//agreg curso a la lista de cursos matriculados -> numCur++
void operator *=(struct StAlumno *arrAlum, struct StRegistroDeMatricula &reg){
    int posAlum,numCur;
    posAlum = buscarEnAlum(reg.codigodelAlumno,arrAlum);
    
    if(posAlum!=NOT_FOUND){
        numCur = arrAlum[posAlum].numeroDeCursos;
        
        //arrAlum[posAlum].cursos[numCur] = new char[strlen(reg.codigoDelCurso)+1]; 
        arrAlum[posAlum].cursos[numCur] = new char[7]; 
        
        //no puedo hacer esto de frente pq no he reservado el espacio de memoria 
        strcpy(arrAlum[posAlum].cursos[numCur], reg.codigoDelCurso); 

        (arrAlum[posAlum].numeroDeCursos)++;        
    }

}
 
void operator <<(ofstream &arcRep, struct StCurso &curso){
    int longitud=strlen(curso.nombreDelCurso);
    int persona=strlen(curso.nombreDelProfesor);
    arcRep<<fixed;
    arcRep.precision(2);
    for(int i=0;i<longitud;i++){
        if(curso.nombreDelCurso[i]=='_'){
            curso.nombreDelCurso[i]=' ';
        }
    }
    for(int i=0;i<persona;i++){
        if(curso.nombreDelProfesor[i]=='_'){
            curso.nombreDelProfesor[i]=' ';
        }
    }
    arcRep<<setw(5)<<" "<<"CODIGO"<<setw(20)<<" "<<"NOMBRE"<<setw(51)<<
            " "<<"CREDITOS"<<endl;
    arcRep<<setw(5)<<" "<<setw(6)<<curso.codigoDelCurso<<left<<setw(18)<<" "<<
            setw(61)<<curso.nombreDelCurso<<
            right<<setw(4)<<curso.creditos<<endl;
    arcRep<<setw(5)<<" "<<"PROFESOR: "<<left<<setw(45)<<curso.nombreDelProfesor<<right<<" ["<<
            curso.codigoDelProfesor<<"]"<<endl;
    arcRep<<setw(5)<<" "<<"Alumnos Matriculados:"<<endl;
    arcRep<<setw(5)<<" "<<"Semestre"<<setw(5)<<" "<<"Codigo"<<endl;
    for(int i=0;i<curso.numeroDeAlumnos;i++){
        arcRep<<setw(7)<<" "<<setw(5)<<curso.alumnos[i]/10000<<
                setw(7)<<" "<<setw(4)<<curso.alumnos[i]%10000<<endl;
    }
    arcRep<<setw(5)<<" "<<"Numero de alumnos: "<<setw(3)<<curso.numeroDeAlumnos<<endl;
    arcRep<<setw(5)<<" "<<"Total ingresado:   "<<setw(8)<<curso.ingresos<<endl;
}
    
void operator <<(ofstream &arcRep, struct StAlumno &alumno){
        arcRep.precision(2);
    arcRep<<fixed;
    arcRep<<setw(5)<<" "<<"SEMESTRE"<<setw(5)<<" "<<"CODIGO"<<
            setw(4)<<" "<<"NOMBRE"<<setw(39)<<" "<<"MODALIDAD"<<
            setw(18)<<" "<<"ESCALA"<<endl;
    arcRep<<setw(5)<<" "<<setw(5)<<alumno.semestre<<setw(9)<<" "<<
            setw(4)<<alumno.codigo<<setw(5)<<" "<<left<<setw(45)<<alumno.nombre<<
            setw(15)<<alumno.modalidad<<right;
    if(strcmp(alumno.modalidad,"SEMIPRESENCIAL")==0){
        arcRep<<"CON "<<alumno.porcentaje<<"%"<<setw(7)<<" ";
    }
    else{
        arcRep<<setw(14)<<" ";
    }
    arcRep<<alumno.escala<<endl;
    arcRep<<setw(5)<<" "<<"Codigo de Cursos Matriculados"<<endl;
    if(alumno.numeroDeCursos>0){
        for(int i=0;i<alumno.numeroDeCursos;i++){
            arcRep<<setw(12)<<" "<<setw(6)<<alumno.cursos[i]<<endl;
        }
    }
    else{
        arcRep<<setw(5)<<" "<<"EL ALUMNO NO ESTA MATRICULADO ESTE CICLO"<<endl;
    }
    arcRep<<setw(5)<<" "<<"Numero de cursos: "<<setw(3)<<alumno.numeroDeCursos<<endl;
    arcRep<<setw(5)<<" "<<"Costo total: "<<setw(7)<<" "<<alumno.costoTotal<<endl;
}







































