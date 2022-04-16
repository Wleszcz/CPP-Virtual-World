//
// Created by Wiktor on 16.04.2022.
//

#include "Antylopa.h"

Antylopa::Antylopa() {
    polozenie=new Punkt();
    this->swiat=swiat;
    this->sila=4;
    this->inicjatywa=4;
    this->symbol='A';
    this->typ="Antylopa";
}

Antylopa::Antylopa(Swiat *swiat, int x, int y) {
    this->swiat=swiat;
    polozenie=new Punkt(x,y);
    this->sila=4;
    this->inicjatywa=4;
    this->symbol='A';
    this->typ="Antylopa";
}

Organizm *Antylopa::Konstuktor(int x,int y) {
    return new Antylopa(swiat,x, y);
}

void Antylopa::akcja() {
    Punkt* pole=losowePole();
    ruch(pole->getX(),pole->getY());
    swiat->plansza->AktualizujPlansze(swiat->organizmy);
}

Punkt* Antylopa::losowePole(){
    int xK,yK;
    while (true) {
        int x1 = rand() % 5;
        int y1 = rand() % 5;

        int x = getX()-2+x1;
        int y = getY()-2+y1;

        if (this->swiat->plansza->poprawnyRuch(x,y) && !(x1==2 && y1==2)) {
            xK=x;
            yK=y;
            break;
        }
    }
    return new Punkt(xK,yK);
}

bool Antylopa::CzyOdbilAtak(Organizm *napastnik) {
    int x=rand() % 2;
    int b=polaObokZajete();
    if(x==0 || polaObokZajete()){
        return false;
    }
    else{
        while(true) {
            Punkt *pole = losowePoleObok();
            if(!swiat->plansza->CzyMaZwierze(pole->getX(),pole->getY())){
                ruch(pole->getX(), pole->getY());
                swiat->plansza->AktualizujPlansze(swiat->organizmy);
                return true;
            }
        }
    }
    return false;
}
