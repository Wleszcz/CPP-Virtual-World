//
// Created by Wiktor on 14.04.2022.
//

#include "Mlecz.h"

Mlecz::Mlecz(Swiat *swiat, int x, int y) {
    polozenie=new Punkt(x,y);
    this->swiat=swiat;
    this->sila=0;
    this->symbol='$';
}

Mlecz::Mlecz() {
    polozenie= new Punkt();
}

Organizm *Mlecz::Konstuktor(int x, int y) {
    return new Mlecz(swiat,x,y);
}

void Mlecz::akcja() {
    for (int i = 0; i < 3; ++i) {
        rozmnozSie();
    }
}
