

/* 
 * File:   LFalta.h
 * Author: BlueCod (mell1)
 *
 * Created on 10 de junio de 2024, 23:02
 */

#ifndef LFALTA_H
#define LFALTA_H
#include "NFalta.h"

class LFalta {
private:
    class NFalta *lini;
    class NFalta *fin;
public:
    LFalta();
    virtual ~LFalta();
};

#endif /* LFALTA_H */

