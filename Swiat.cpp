//
// Created by wikto on 12.04.2022.
//

#include "Swiat.h"

Swiat::Swiat(int x, int y) {
    plansza = new Plansza(int (x), int (y));
}

void Swiat::rysujSwiat() {
    plansza->RysujPlansze();
}

void Swiat::wykonajTure() {

    for (int i = 0; i < organizmy.size(); ++i) {
        organizmy[i]->starzejSie();
    }
}

void Swiat::dodajOrganizm(Organizm *organizm) {
    organizmy.push_back(organizm);
    plansza->PostawOrganizm(organizm);
}

