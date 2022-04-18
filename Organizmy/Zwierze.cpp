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
        if ((typ == organizm->getTyp())) {
            if (organizm->getWiek() != 0 && this->gotowy && organizm->gotowy && !(this->polaObokZajete())) {
                rozmnozSie();
                gotowy = false;
                organizm->gotowy = false;
            }
        } else {
            if (getSila() > organizm->getSila()) {

                if(swiat->Narrator) {
                    std::cout << organizm->getY() << " zostal zjedzony przez " << typ << std::endl;
                }
                organizm->umrzyj();
            } else if (getSila() < organizm->getSila()) {

                if(swiat->Narrator) {
                    std::cout << typ << " zostal zjedzony przez " << organizm->getTyp() << std::endl;
                }
                umrzyj();
            } else {
                if(swiat->Narrator) {
                    std::cout << typ << " i " << organizm->getTyp() << " zjadly sie nawzajem" << std::endl;
                }
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
    int Kx, Ky, i = 0;

    while (i < 20) {
        Punkt *pole = losowePoleObok();
        int x = pole->getX();
        int y = pole->getY();
        i++;

        if (!swiat->plansza->CzyMaZwierze(x, y)) {
            Kx = x;
            Ky = y;
            Organizm *organizm = this->Konstuktor(Kx, Ky);
            swiat->dodajOrganizm(organizm);
            break;
        }
    }
}


bool Zwierze::CzyOdbilAtak(Organizm *napastnik) {
        if(napastnik->getSila() > sila){
            return false;
        }
        else{
            return true;
        }
    }



