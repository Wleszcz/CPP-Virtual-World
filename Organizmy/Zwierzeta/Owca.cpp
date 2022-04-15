//
// Created by wikto on 12.04.2022.
//

#include "Owca.h"

Owca::Owca() {
    polozenie=new Punkt();
    this->swiat=swiat;
    this->sila=4;
    this->inicjatywa=4;
    this->symbol='o';
    this->typ="Owca";
}

Owca::Owca(Swiat* swiat,int x, int y){
    this->swiat=swiat;
    polozenie=new Punkt(x,y);
    this->sila=4;
    this->inicjatywa=4;
    this->symbol='o';
    this->typ="Owca";
}

Organizm *Owca::Konstuktor(int x,int y) {
    return new Owca(swiat,x, y);
}

