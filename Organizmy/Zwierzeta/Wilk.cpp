//
// Created by wikto on 12.04.2022.
//

#include "Wilk.h"

Wilk::Wilk() {
    polozenie=new Punkt();
};
Wilk::Wilk(int x, int y){
        polozenie=new Punkt(x,y);
        this->inicjatywa=5;
        this->sila=9;
        this->symbol='w';


    }

Organizm *Wilk::Konstuktor() {
    return new Wilk;
}

void Wilk::akcja(Swiat *swiat) {
    Zwierze::akcja(swiat);
}

void Wilk::kolizja(Swiat *swiat) {
    Zwierze::kolizja(swiat);
}

