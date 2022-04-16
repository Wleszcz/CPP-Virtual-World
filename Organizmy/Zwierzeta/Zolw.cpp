//
// Created by Wiktor on 15.04.2022.
//

#include "Zolw.h"



Zolw::Zolw() {
    polozenie=new Punkt();
    this->swiat=swiat;
    this->inicjatywa=1;
    this->sila=2;
    this->symbol='Z';
    this->typ="Zolw";
}

void Zolw::kolizja(Organizm *organizm) {
    Zwierze::kolizja(organizm);
}



Zolw::Zolw(Swiat* swiat,int x, int y){
    polozenie=new Punkt(x,y);
    this->swiat=swiat;
    this->inicjatywa=1;
    this->sila=2;
    this->symbol='Z';
    this->typ="Zolw";


}

Organizm *Zolw::Konstuktor(int x,int y) {
    return new Zolw(swiat,x,y);

}

void Zolw::akcja() {
    int s=rand() % 4;
    if(s==0) {
        Zwierze::akcja();
    }
}
bool Zolw::CzyOdbilAtak(Organizm *napastnik) {
    if (napastnik->getSila()>5){
        return false;
    }
    else{
        return true;
    }
}
