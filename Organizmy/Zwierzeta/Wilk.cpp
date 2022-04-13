//
// Created by wikto on 12.04.2022.
//

#include "Wilk.h"

Wilk::Wilk() {
    polozenie=new Punkt();
};
Wilk::Wilk(Swiat* swiat){
    polozenie=new Punkt();
    this->swiat=swiat;
}

Wilk::Wilk(Swiat* swiat,int x, int y){
        polozenie=new Punkt(x,y);
        this->inicjatywa=5;
        this->sila=9;
        this->symbol='w';


    }

Organizm *Wilk::Konstuktor(int x,int y) {
    return new Wilk(swiat,x,y);
}

void Wilk::akcja() {
    Zwierze::akcja();
}

void Wilk::kolizja() {
    Zwierze::kolizja();
}

