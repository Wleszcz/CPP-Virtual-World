//
// Created by wikto on 12.04.2022.
//

#include "Owca.h"
Owca::Owca(Swiat* swiat,int x, int y,int wiek,int sila){
    this->swiat=swiat;
    polozenie=new Punkt(x,y);
    this->sila=sila;
    this->wiek=wiek;
    this->inicjatywa=4;
    this->symbol='o';
    this->typ="Owca";
}

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

