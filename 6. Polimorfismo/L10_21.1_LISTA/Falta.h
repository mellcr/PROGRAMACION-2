

/* 
 *  GUARDA LAS INFRACCIONES COMETIDAS
 */

#ifndef FALTA_H
#define FALTA_H

class Falta {
private:
    int licencia; //conductor que comete la falta
    int fecha;
    char *placa;
public:
    Falta();
    virtual ~Falta();
    void SetPlaca(const char* placa);
    void GetPlaca(char*c) const;
    void SetFecha(int fecha);
    int GetFecha() const;
    void SetLicencia(int licencia);
    int GetLicencia() const;
};

#endif /* FALTA_H */

