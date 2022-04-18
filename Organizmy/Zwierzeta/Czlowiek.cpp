//
// Created by Wiktor on 16.04.2022.
//
#include <conio.h>
#include <unistd.h>
#include "Czlowiek.h"

#define SILA 5

using namespace std;
Czlowiek::Czlowiek(Swiat *swiat, int x, int y,int wiek,int sila) {
    this->swiat=swiat;
    polozenie=new Punkt(x,y);
    this->sila=sila;
    this->wiek=wiek;
    this->inicjatywa=4;
    this->symbol='Y';
    this->typ="Czlowiek";
}

Czlowiek::Czlowiek() {
    polozenie=new Punkt();
    this->swiat=swiat;
    this->sila=SILA;
    this->inicjatywa=4;
    this->symbol='Y';
    this->typ="Czlowiek";
}

Czlowiek::Czlowiek(Swiat *swiat, int x, int y) {
    this->swiat=swiat;
    polozenie=new Punkt(x,y);
    this->sila=SILA;
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
    else if(c=='q'){
        Umiejetnosc();
    }
    else if (c=='z'){
        swiat->zapiszSwiat();
        this->akcja();
    }
    if(swiat->plansza->poprawnyRuch(x,y)){
        ruch(x,y);
    }
}

void Czlowiek::umrzyj() {
    Organizm::umrzyj();
    std::cout<<"Czy chcesz kontynuowac ?  (T/N) "<<std::endl;
    char kom;
    cin>>kom;
    if(kom=='t' || kom =='T'){
    }
    else if(kom=='n' || kom =='N'){
        swiat->Koniec=true;
    }
}

bool Czlowiek::Umiejetnosc() {
    if(!uzytoUmiejstnosc && sila <= 10){
    umiejetnoscAktywna=true;
    uzytoUmiejstnosc=true;
    cout<<"UZYTO UMIEJETNOSCI"<<endl;
        sila = 10;
}

}

void Czlowiek::starzejSie() {

    if(umiejetnoscAktywna){
        if(sila==SILA+1){
            umiejetnoscAktywna=false;
            cout<<"KONIEC DZIALANIA UMIEJETNOSCI"<<endl;
        }
        sila--;
    }
    Organizm::starzejSie();
}




