//
// Created by Wiktor on 15.04.2022.
//

#ifndef UNTITLED_LIS_H
#define UNTITLED_LIS_H


#include "../Zwierze.h"

class Lis :
            public Zwierze
{
    public:
        Lis(Swiat* swiat,int x,int y);
        Lis();

        Organizm *Konstuktor(int x,int y) override;

    void akcja() override;
};



#endif //UNTITLED_LIS_H
