//
// Created by wiktor on 12.04.2022.
//

#include "Plansza.h"
#include "Punkt.h"

Plansza::Plansza(int x, int y) {
    this->x = x;
    this->y = y;

    pola = new char* [y];
    for (int i = 0; i < y; i++) {
        pola[i] = new char[x];
    }

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            pola[i][j]=' ';
        }
    }
}


void Plansza::PostawOrganizm(Organizm* organizm) {
    Punkt* polozenie = organizm->Pozycja();

    pola[polozenie->getX()][polozenie->getY()]=organizm->getSymbol();
}


void Plansza::RysujPlansze() {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            std::cout<<pola[i][j];
        }
        std::cout<<std::endl;
    }
}

