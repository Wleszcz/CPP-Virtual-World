//
// Created by Wiktor on 14.04.2022.
//

#ifndef UNTITLED_MLECZ_H
#define UNTITLED_MLECZ_H



#include "../Roslina.h"

class Mlecz:
        public Roslina
{
public:
    Mlecz();
    Mlecz(Swiat* swiat,int x, int y);

    Organizm *Konstuktor(int x,int y) override;

    void akcja() override;


};



#endif //UNTITLED_MLECZ_H
