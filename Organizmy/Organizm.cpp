//
// Created by wiktor on 12.04.2022.
//

#include "Organizm.h"
#include "../Punkt.h"

Organizm::Organizm(int x,int y,int sila, int inicjatywa,char symbol) {
    this->inicjatywa = inicjatywa;
    this->sila = sila;
    this->symbol=symbol;
    this->polozenie = new Punkt(x, y);
}

Punkt* Organizm::Pozycja() {
    return polozenie;
}

char Organizm::getSymbol() {
    return symbol;
}
void Organizm::starzejSie(){
    wiek++;
}