//
// Created by wikto on 12.04.2022.
//

#ifndef UNTITLED_WILK_H
#define UNTITLED_WILK_H


#include "../Zwierze.h"

class Wilk :
        public Zwierze {
public:
    Wilk(Swiat *swiat, int x, int y, int wiek, int sila);

    Wilk(Swiat *swiat, int x, int y);

    Wilk(Swiat *swiat);

    Organizm *Konstuktor(int x, int y) override;


};


#endif //UNTITLED_WILK_H
