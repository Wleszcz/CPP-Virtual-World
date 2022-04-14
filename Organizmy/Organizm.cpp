//
// Created by wiktor on 12.04.2022.
//

#include "Organizm.h"
#include "../Punkt.h"

int Organizm::getX() {
    return polozenie->getX();
}
int Organizm::getY() {
    return polozenie->getY();
}

char Organizm::getSymbol() {
    return symbol;
}
void Organizm::starzejSie(){
    wiek++;
}
void Organizm::ruch(int x, int y) {

    this->polozenie->setX(x);
    this->polozenie->setY(y);
}

