#include "Roslina.h"

//
// Created by wikto on 12.04.2022.
//
#include "Roslina.h"

void Roslina::akcja() {
int szansa = rand() % 3;
if (this->wiek != 0) {
    rozmnozSie();
}
}

void Roslina::kolizja() {

}

void Roslina::rozmnozSie() {
    int x = this->getX();
    int y = this->getY();

    while (1) {
        int pole = rand() % 8;

        if (pole == 0) {
            x = x - 1;
            y = y - 1;
        } else if (pole == 1) {
            y = y - 1;
        } else if (pole == 2) {
            x = x + 1;
            y = y - 1;
        } else if (pole == 3) {
            x = x - 1;
        } else if (pole == 4) {
            x = x + 1;
        } else if (pole == 5) {
            x = x - 1;
            y = y + 1;
        } else if (pole == 6) {
            y = y + 1;
        } else if (pole == 7) {
            x = x + 1;
            y = y + 1;
        }
        if(swiat->plansza->poprawnyRuch(x,y)){
            break;
        }
    }
    if (swiat->plansza->poprawnoscAkcji(x, y)) {
        Organizm *organizm = this->Konstuktor(x,y);

        swiat->dodajOrganizm(organizm);

    }
}
