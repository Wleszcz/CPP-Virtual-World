//
// Created by Wiktor on 14.04.2022.
//
#define ZASIEG 1
#include "BarszczSosnowskiego.h"
#include "../Zwierze.h"

void BarszczSosnowskiego::kolizja(Organizm *organizm) {
    organizm->umrzyj();
}

BarszczSosnowskiego::BarszczSosnowskiego(Swiat *swiat, int x, int y) {
    polozenie=new Punkt(x,y);
    this->swiat=swiat;
    this->sila=0;
    this->symbol='X';
    this->typ="Barszcz Sosnowskiego";
}
BarszczSosnowskiego::BarszczSosnowskiego(){
    polozenie= new Punkt();
    this->swiat=swiat;
    this->sila=0;
    this->symbol='X';
    this->typ="Barszcz Sosnowskiego";
}

Organizm *BarszczSosnowskiego::Konstuktor(int x, int y) {
    return new BarszczSosnowskiego(swiat, x, y);
}

void BarszczSosnowskiego::akcja() {
    int x=this->getX();
    int y=this->getY();
    for (int i = -ZASIEG; i <= ZASIEG; ++i) {
        for (int j = -ZASIEG; j <= ZASIEG; ++j) {
            if(swiat->plansza->poprawnyRuch(x+i,y+j)){

                if(!swiat->plansza->CzyPusty(x+i,y+j)){
                    if(Zwierze* t = dynamic_cast<Zwierze*>(swiat->plansza->getOrganizm(x+i,y+j))){
                    swiat->plansza->getOrganizm(x+i,y+j)->umrzyj();
                }
                }
            }
        }
    }
    swiat->plansza->AktualizujPlansze(swiat->organizmy);
}

