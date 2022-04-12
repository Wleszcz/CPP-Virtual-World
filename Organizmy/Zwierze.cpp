//
// Created by wikto on 12.04.2022.
//

#include "Zwierze.h"

Zwierze::Zwierze(int x,int y, int sila, int inicjatywa,char symbol) : Organizm(x,y,sila, inicjatywa,symbol) {}

void Zwierze::ruch(int x, int y) {
    polozenie->setX(x);
    polozenie->setY(y);
}

void Zwierze::akcja(Swiat *swiat) {

}

void Zwierze::kolizja(Swiat *swiat) {

}
