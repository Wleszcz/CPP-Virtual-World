//
// Created by Wiktor on 14.04.2022.
//

#include "Guarana.h"
Guarana::Guarana(Swiat *swiat, int x, int y,int wiek,int sila) {
    polozenie=new Punkt(x,y);
    this->swiat=swiat;
    this->sila=sila;
    this->wiek=wiek;
    this->symbol='g';
    this->typ="Guarana";
}

Guarana::Guarana(Swiat *swiat, int x, int y) {
    polozenie=new Punkt(x,y);
    this->swiat=swiat;
    this->sila=0;
    this->symbol='g';
    this->typ="Guarana";
}
Guarana::Guarana() {
    polozenie= new Punkt();
    this->swiat=swiat;
    this->sila=0;
    this->symbol='g';
    this->typ="Guarana";
}

Organizm *Guarana::Konstuktor(int x, int y) {
    return new Guarana(swiat,x,y);
}

void Guarana::kolizja(Organizm *organizm) {
    this->umrzyj();
    organizm->BonusSila();
}
