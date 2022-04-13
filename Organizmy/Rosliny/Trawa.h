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
    Trawa(int x, int y, int sila, char symbol);

    Organizm *Konstuktor() override;

    void akcja(Swiat *swiat) override;

    void kolizja(Swiat *swiat) override;

    Trawa(int x, int y);
};




#endif //UNTITLED_TRAWA_H
