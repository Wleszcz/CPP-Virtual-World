//
// Created by wikto on 12.04.2022.
//

#include "Trawa.h"

Trawa::Trawa(Swiat *swiat, int x, int y, int wiek, int sila) {
    polozenie = new Punkt(x, y);
    this->swiat = swiat;
    this->sila = sila;
    this->wiek = wiek;
    this->symbol = '#';
    this->typ = "Trawa";
}

Trawa::Trawa(Swiat *swiat, int x, int y) {
    polozenie = new Punkt(x, y);
    this->swiat = swiat;
    this->sila = 0;
    this->symbol = '#';
    this->typ = "Trawa";
}

Trawa::Trawa(Swiat *swiat) {
    polozenie = new Punkt();
    this->swiat = swiat;
    this->sila = 0;
    this->symbol = '#';
    this->typ = "Trawa";
}


Organizm *Trawa::Konstuktor(int x, int y) {
    return new Trawa(swiat, x, y);
}

