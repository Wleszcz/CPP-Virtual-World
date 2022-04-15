//
// Created by wikto on 12.04.2022.
//

#include "Wilk.h"


Wilk::Wilk(){
    polozenie=new Punkt();
    this->swiat=swiat;
    this->inicjatywa=5;
    this->sila=9;
    this->symbol='w';
    this->typ="Wilk";
}

Wilk::Wilk(Swiat* swiat,int x, int y){
        polozenie=new Punkt(x,y);
        this->swiat=swiat;
        this->inicjatywa=5;
        this->sila=9;
        this->symbol='w';
        this->typ="Wilk";


    }

Organizm *Wilk::Konstuktor(int x,int y) {
    return new Wilk(swiat,x,y);

}
