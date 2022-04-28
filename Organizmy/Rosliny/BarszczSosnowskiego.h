//
// Created by Wiktor on 14.04.2022.
//

#ifndef UNTITLED_BARSZCZSOSNOWSKIEGO_H
#define UNTITLED_BARSZCZSOSNOWSKIEGO_H


#include "../Roslina.h"

class BarszczSosnowskiego:
        public Roslina
{
public:
    BarszczSosnowskiego(Swiat* swiat,int x,int y,int wiek,int sila);
    BarszczSosnowskiego(Swiat* swiat, int x, int y);
    BarszczSosnowskiego(Swiat* swiat);


    Organizm *Konstuktor(int x,int y) override;

    void akcja() override;

    void kolizja(Organizm *organizm) override;
};



#endif //UNTITLED_BARSZCZSOSNOWSKIEGO_H
