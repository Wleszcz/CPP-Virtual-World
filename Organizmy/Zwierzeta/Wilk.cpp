//
// Created by wikto on 12.04.2022.
//

#include "Wilk.h"
Wilk::Wilk(Swiat* swiat,int x, int y,int wiek,int sila){
    this->wiek=wiek;
    polozenie=new Punkt(x,y);
    this->swiat=swiat;
    this->inicjatywa=5;
    this->sila=sila;
    this->symbol='W';
    this->typ="Wilk";
}

Wilk::Wilk(Swiat* swiat){
    polozenie=new Punkt();
    this->swiat=swiat;
    this->inicjatywa=5;
    this->sila=9;
    this->symbol='W';
    this->typ="Wilk";
}

Wilk::Wilk(Swiat* swiat,int x, int y){
        polozenie=new Punkt(x,y);
        this->swiat=swiat;
        this->inicjatywa=5;
        this->sila=9;
        this->symbol='W';
        this->typ="Wilk";
    }

Organizm *Wilk::Konstuktor(int x,int y) {
    return new Wilk(swiat,x,y);

}
