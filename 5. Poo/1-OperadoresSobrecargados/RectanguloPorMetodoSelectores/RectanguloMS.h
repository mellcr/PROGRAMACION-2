

/* 
 * File:   RectanguloMS.h
 * Author: BlueCod (mell1)
 *
 * Created on 19 de mayo de 2024, 17:05
 */

#ifndef RECTANGULOMS_H
#define RECTANGULOMS_H

class RectanguloMS {
private:
    char *nombre;
    double base;
    double altura;
public:
    RectanguloMS(); //CONSTRUCTOR POR DEFECTO
    RectanguloMS(double, double, const char*); //C. POR PARAMETROS
    RectanguloMS(const RectanguloMS& orig); //C.Copia
    ~RectanguloMS(); //DESTRUCTOR
    
    void setBase(double);
    void setAltura(double);
    void leeDatos();  //si no le paso nada como parametros -> void
    //me entrega los valores
    double getBase()const;
    double getAltura()const;
    //muestra resultados
    void muestraDatos() ;
    double area();
    double perimetro();
    void mostrarResultados() ;
    void setNombre(const char* cad);
    void getNombre(char *cad) const;
    void inicializa();
    void elimina();
};

#endif /* RECTANGULOMS_H */

