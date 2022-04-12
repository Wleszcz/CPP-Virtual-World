//
// Created by wikto on 12.04.2022.
//

#ifndef UNTITLED_ZWIERZE_H
#define UNTITLED_ZWIERZE_H
#include "Organizm.h"

class Zwierze :
        public Organizm
{

public:
    Zwierze(int x,int y, int sila, int inicjatywa,char symbol);

    void ruch(int x,int y);

    void akcja(Swiat *swiat) override;

    void kolizja(Swiat *swiat) override;


};


#endif //UNTITLED_ZWIERZE_H
