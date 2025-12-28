

/* 
 * File:   Infraccion.h
 * Author: BlueCod (mell1)
 *
 * Created on 10 de junio de 2024, 22:44
 */

#ifndef INFRACCION_H
#define INFRACCION_H

class Infraccion {
private:
    int codigo;
    char *gravedad; // LEVE  GRAVE  MUY GRAVE 
    double multa; ///pago q se hace por la multa
public:
    Infraccion();
    virtual ~Infraccion();
    void SetMulta(double multa);
    double GetMulta() const;
    void SetGravedad(const char* gravedad);
    void GetGravedad( char*c) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
};

#endif /* INFRACCION_H */

