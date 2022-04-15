//
// Created by wikto on 12.04.2022.
//

#include "Zwierze.h"

void Zwierze::akcja() {
    Punkt* pole=losowePoleObok();
    ruch(pole->getX(),pole->getY());
    swiat->plansza->AktualizujPlansze(swiat->organizmy);
}

void Zwierze::kolizja(Organizm *organizm) {
    //if(obronilSie( organizm))
    if(typ==organizm->getTyp()){
        if(organizm->getWiek()!=0 && this->gotowy && organizm->gotowy && !(this->polaObokZajete())) {
            rozmnozSie();
            gotowy = false;
            organizm->gotowy = false;
        }
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

bool Zwierze::polaObokZajete(){
    bool zajete= true;
    for (int i = -1; i <=1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if(swiat->plansza->poprawnyRuch(getX()+i,getY()+j) && !(swiat->plansza->CzyMaZwierze(getX()+i,getY()+j))){
                return false;
            }
        }
    }
    return true;
}

void Zwierze::rozmnozSie() {
    int Kx,Ky,i=0;

    while(true) {
        Punkt *pole = losowePoleObok();
        int x = pole->getX();
        int y = pole->getY();
        i++;

        if (swiat->plansza->CzyPusty(x, y)) {
            Kx=x;
            Ky=y;
            break;
        }
    }
        Organizm *organizm = this->Konstuktor(Kx, Ky);
        swiat->dodajOrganizm(organizm);
}



