//
// Created by wikto on 12.04.2022.
//

#ifndef UNTITLED_SWIAT_H
#define UNTITLED_SWIAT_H
#include <iostream>
#include <vector>
#include "Organizmy/Organizm.h"
#include "Plansza.h"

class Organizm;
class Plansza;

class Swiat{
protected:
    int tura=0;


public:
    std::vector <Organizm*> organizmy;


    Swiat(int x, int y);
    Plansza* plansza;

    void rysujSwiat();
    void listaOrganizmow();
    void listaZwierzat();
    void wykonajTure();
    void dodajOrganizm(Organizm* organizm);
    void sortujOrganizmy();
    void usunMartwe();

};

#endif //UNTITLED_SWIAT_H