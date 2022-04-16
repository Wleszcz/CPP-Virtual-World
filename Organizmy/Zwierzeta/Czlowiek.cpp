//
// Created by Wiktor on 16.04.2022.
//
#include <conio.h>
#include <unistd.h>
#include "Czlowiek.h"

using namespace std;
Czlowiek::Czlowiek() {
    polozenie=new Punkt();
    this->swiat=swiat;
    this->sila=5;
    this->inicjatywa=4;
    this->symbol='Y';
    this->typ="Czlowiek";
}

Czlowiek::Czlowiek(Swiat *swiat, int x, int y) {
    this->swiat=swiat;
    polozenie=new Punkt(x,y);
    this->sila=5;
    this->inicjatywa=4;
    this->symbol='Y';
    this->typ="Czlowiek";
}

Organizm *Czlowiek::Konstuktor(int x, int y) {
    return nullptr;
}

void Czlowiek::akcja() {
    char c;
    cin>>c;
    int x=getX();
    int y=getY();
    if(c=='w'){
        y--;
    }
    else if(c=='s'){
        y++;
    }
    else if(c=='a'){
        x--;
    }
    else if(c=='d'){
        x++;
    }
    if(swiat->plansza->poprawnyRuch(x,y)){
        ruch(x,y);
    }
}


