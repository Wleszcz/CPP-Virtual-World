//
// Created by wikto on 12.04.2022.
//

#include "Swiat.h"



Swiat::Swiat(int x, int y) {
    plansza = new Plansza(x,y);
}

void Swiat::rysujSwiat() {
    plansza->RysujPlansze();
}

void Swiat::wykonajTure() {
    plansza->AktualizujPlansze(organizmy);

    for (int i = 0; i < organizmy.size(); ++i) {
        organizmy[i]->akcja();
        organizmy[i]->starzejSie();
    }

    rysujSwiat();
}

void Swiat::dodajOrganizm(Organizm *organizm) {
    organizmy.push_back(organizm);

    plansza->AktualizujPlansze(organizmy);
}

