//
// Created by Wiktor on 14.04.2022.
//

#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Swiat *swiat, int x, int y, int wiek, int sila) {
    polozenie = new Punkt(x, y);
    this->swiat = swiat;
    this->sila = sila;
    this->wiek = wiek;
    this->symbol = 'j';
    this->typ = "Wilcze Jagody";
}


WilczeJagody::WilczeJagody(Swiat *swiat, int x, int y) {
    polozenie = new Punkt(x, y);
    this->swiat = swiat;
    this->sila = 99;
    this->symbol = 'j';
    this->typ = "Wilcze Jagody";
}

void WilczeJagody::kolizja(Organizm *organizm) {
    if (swiat->Narrator) {
        std::cout << organizm->getTyp() << " zatrul sie jagodami" << std::endl;
    }

    organizm->umrzyj();
    this->umrzyj();
    swiat->plansza->AktualizujPlansze(swiat->organizmy);
}

WilczeJagody::WilczeJagody(Swiat *swiat) {
    polozenie = new Punkt();
    this->swiat = swiat;
    this->sila = 99;
    this->symbol = 'j';
    this->typ = "Wilcze Jagody";
}

Organizm *WilczeJagody::Konstuktor(int x, int y) {
    return new WilczeJagody(swiat, x, y);
}