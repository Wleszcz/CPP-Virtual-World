//
// Created by wikto on 12.04.2022.
//

#include "Owca.h"
Owca::Owca() {
    polozenie=new Punkt();
}
Owca::Owca(Swiat* swiat) {
    polozenie=new Punkt();
    this->swiat=swiat;
}

Owca::Owca(Swiat* swiat,int x, int y){
    this->swiat=swiat;
    polozenie=new Punkt(x,y);
    this->sila=4;
    this->inicjatywa=4;
    this->symbol='o';
}

Organizm *Owca::Konstuktor(int x,int y) {
    return new Owca(swiat,x, y);
}

void Owca::akcja() {
    Zwierze::akcja();
}

void Owca::kolizja() {
    Zwierze::kolizja();
}

