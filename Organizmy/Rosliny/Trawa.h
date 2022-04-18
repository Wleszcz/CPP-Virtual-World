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
    Trawa(Swiat* swiat,int x,int y,int wiek,int sila);
    Trawa(Swiat* swiat,int x, int y);
    Trawa();

    Organizm *Konstuktor(int x,int y) override;
};




#endif //UNTITLED_TRAWA_H
