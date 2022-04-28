//
// Created by Wiktor on 14.04.2022.
//

#include "Mlecz.h"

Mlecz::Mlecz(Swiat *swiat, int x, int y, int wiek, int sila) {
    polozenie = new Punkt(x, y);
    this->swiat = swiat;
    this->sila = sila;
    this->wiek = wiek;
    this->symbol = 'm';
    this->typ = "Mlecz";
}

Mlecz::Mlecz(Swiat *swiat, int x, int y) {
    polozenie = new Punkt(x, y);
    this->swiat = swiat;
    this->sila = 0;
    this->symbol = 'm';
    this->typ = "Mlecz";
}

Mlecz::Mlecz(Swiat *swiat) {
    polozenie = new Punkt();
    this->swiat = swiat;
    this->sila = 0;
    this->symbol = 'm';
    this->typ = "Mlecz";
}

Organizm *Mlecz::Konstuktor(int x, int y) {
    return new Mlecz(swiat, x, y);
}

void Mlecz::akcja() {
    for (int i = 0; i < 3; ++i) {
        rozmnozSie();
    }
}

