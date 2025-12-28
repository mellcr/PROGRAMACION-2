

/* 
 * File:   NFalta.h
 * Author: BlueCod (mell1)
 *
 * Created on 10 de junio de 2024, 23:00
 */

#ifndef NFALTA_H
#define NFALTA_H
#include "Infraccion.h"
#include "Falta.h"


class NFalta {
private:
    class Infraccion *pfalta;
    class Falta dfalta;
    class NFalta *sig;
public:
    NFalta();
    
    friend class LFalta;
};

#endif /* NFALTA_H */

