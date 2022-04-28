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

class Swiat {
protected:
    int tura = 0;
    int iloscTur = 10;


public:
    std::vector<Organizm *> organizmy;


    Swiat(int x, int y);

    Swiat(int x, int y, int tura, int iloscTur);

    Plansza *plansza;
    bool Koniec;
    bool Narrator;

    void rysujSwiat();

    void listaOrganizmow() const;

    void listaZwierzat() const;

    void zmienIloscTur();

    int wykonajTure();

    int GetIloscTur() const;

    int InformacjeOUmiejetnosc;

    void dodajOrganizm(Organizm *organizm);

    void sortujOrganizmy();

    void usunMartwe();

    bool zapiszSwiat();

    void statystyki();

};

#endif //UNTITLED_SWIAT_H