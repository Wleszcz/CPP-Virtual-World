//
// Created by wikto on 12.04.2022.
//

#ifndef UNTITLED_OWCA_H
#define UNTITLED_OWCA_H

#include "../Zwierze.h"
class Owca :
        public Zwierze

{
public:
    Owca(int x,int y);
    Owca();

    Organizm *Konstuktor() override;

    void akcja(Swiat *swiat) override;

    void kolizja(Swiat *swiat) override;
};
#endif //UNTITLED_OWCA_H
