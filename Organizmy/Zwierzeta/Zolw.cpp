//
// Created by Wiktor on 15.04.2022.
//

#include "Zolw.h"
Zolw::Zolw(Swiat* swiat,int x, int y,int wiek,int sila){
    polozenie=new Punkt(x,y);
    this->swiat=swiat;
    this->inicjatywa=1;
    this->sila=sila;
    this->wiek=wiek;
    this->symbol='Z';
    this->typ="Zolw";
}

Zolw::Zolw(Swiat* swiat,int x, int y){
    polozenie=new Punkt(x,y);
    this->swiat=swiat;
    this->inicjatywa=1;
    this->sila=2;
    this->symbol='Z';
    this->typ="Zolw";
}

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
        if(swiat->Narrator){
            std::cout<<"Zolw nie odbil ataku :("<<std::endl;
        }
        return false;
    }
    else{
        if(swiat->Narrator){
            std::cout<<"Zolw odbil atak"<<std::endl;
        }
        return true;
    }
}
