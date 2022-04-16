#include "Roslina.h"

//
// Created by wikto on 12.04.2022.
//
#include "Roslina.h"

void Roslina::akcja() {
    rozmnozSie();
}

void Roslina::kolizja(Organizm *organizm) {
    if(typ==organizm->getTyp()) {
        //rozmnozSie();
    }
    else{
        if(getSila()>organizm->getSila()){
            organizm->umrzyj();
        }
        else if(getSila()<organizm->getSila()){
            umrzyj();
        }
        else {
            umrzyj();
            organizm->umrzyj();
        }
    }
}

void Roslina::rozmnozSie() {
    int szansa = rand() % 4;
    if (this->wiek != 0 && szansa == 0) {
        Punkt* pole=losowePoleObok();
        int x = pole->getX();
        int y =pole->getY();

        if (swiat->plansza->CzyPusty(x, y)) {
             Organizm *organizm = this->Konstuktor(x,y);
             swiat->dodajOrganizm(organizm);
    }
}
}
bool Roslina::CzyOdbilAtak(Organizm *organizm) {
    return false;
}
