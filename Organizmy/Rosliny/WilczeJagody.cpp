//
// Created by Wiktor on 14.04.2022.
//

#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Swiat *swiat, int x, int y) {
    polozenie=new Punkt(x,y);
    this->swiat=swiat;
    this->sila=99;
    this->symbol='j';
    this->typ="Wilcze Jagody";
}

void WilczeJagody::kolizja(Organizm *organizm) {
    organizm->umrzyj();
    this->umrzyj();
    swiat->plansza->AktualizujPlansze(swiat->organizmy);
}

WilczeJagody::WilczeJagody() {
    polozenie= new Punkt();
    this->swiat=swiat;
    this->sila=99;
    this->symbol='j';
    this->typ="Wilcze Jagody";
}

Organizm *WilczeJagody::Konstuktor(int x, int y) {
    return new WilczeJagody(swiat,x,y);
}