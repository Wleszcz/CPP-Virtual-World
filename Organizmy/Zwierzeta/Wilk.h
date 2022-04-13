//
// Created by wikto on 12.04.2022.
//

#ifndef UNTITLED_WILK_H
#define UNTITLED_WILK_H


#include "../Zwierze.h"

class Wilk:
        public Zwierze
{
public:
    Wilk(int x, int y);
    Wilk();

    Organizm *Konstuktor() override;

    void akcja(Swiat *swiat) override;

    void kolizja(Swiat *swiat) override;
};


#endif //UNTITLED_WILK_H
