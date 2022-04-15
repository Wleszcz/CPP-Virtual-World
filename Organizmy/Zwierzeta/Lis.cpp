//
// Created by Wiktor on 15.04.2022.
//

#include "Lis.h"

Lis::Lis() {
    polozenie=new Punkt();
    this->swiat=swiat;
    this->sila=3;
    this->inicjatywa=7;
    this->symbol='l';
    this->typ="Lis";
}

Lis::Lis(Swiat* swiat,int x, int y){
    this->swiat=swiat;
    polozenie=new Punkt(x,y);
    this->sila=3;
    this->inicjatywa=7;
    this->symbol='l';
    this->typ="Lis";
}

void Lis::akcja() {
    if (!(polaObokZajete())) {
        Punkt *pole = losowePoleObok();
        if(swiat->plansza->getOrganizm(pole->getX(),pole->getY())!= nullptr) {
            if (swiat->plansza->getOrganizm(pole->getX(), pole->getY())->getSila() < sila) {
                ruch(pole->getX(), pole->getY());
                swiat->plansza->AktualizujPlansze(swiat->organizmy);
            }
        }
    }
}

Organizm *Lis::Konstuktor(int x,int y) {
    return new Lis(swiat,x, y);
}

