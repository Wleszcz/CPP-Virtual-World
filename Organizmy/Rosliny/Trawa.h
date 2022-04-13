//
// Created by wikto on 12.04.2022.
//

#ifndef UNTITLED_TRAWA_H
#define UNTITLED_TRAWA_H


#include "../Roslina.h"

class Trawa:
        public Roslina
{
public:
    Trawa();
    Trawa(Swiat* swiat);
    Trawa(Swiat* swiat,int x, int y);
    Organizm *Konstuktor(int x,int y) override;

    void akcja() override;

    void kolizja() override;


};




#endif //UNTITLED_TRAWA_H
