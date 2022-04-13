//
// Created by wikto on 12.04.2022.
//

#include "Owca.h"
Owca::Owca() {
    polozenie=new Punkt();
}

Owca::Owca(int x, int y){
    polozenie=new Punkt(x,y);
    this->sila=4;
    this->inicjatywa=4;
    this->symbol='o';
}

Organizm *Owca::Konstuktor() {
    return new Owca();
}

void Owca::akcja(Swiat *swiat) {
    Zwierze::akcja(swiat);
}

void Owca::kolizja(Swiat *swiat) {
    Zwierze::kolizja(swiat);
}

