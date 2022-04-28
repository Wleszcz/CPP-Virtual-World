//
// Created by Wiktor on 16.04.2022.
//
#include <conio.h>
#include <unistd.h>
#include "Czlowiek.h"

#define SILA 5

using namespace std;
Czlowiek::Czlowiek(Swiat *swiat, int x, int y, int wiek, int sila, int umiejstnosc) {
    this->swiat=swiat;
    polozenie=new Punkt(x,y);
    this->sila=sila;
    this->wiek=wiek;
    this->inicjatywa=4;
    this->symbol='Y';
    this->typ="Czlowiek";
    if(umiejstnosc==11){
        umiejetnoscTrwa= true;
        uzytoUmiejstnosc= true;
    }
    else if(umiejstnosc==0){
        uzytoUmiejstnosc= true;
        umiejetnoscTrwa= false;
    }
    else {
        umiejetnoscTrwa= false;
        uzytoUmiejstnosc= false;
    }
}

Czlowiek::Czlowiek(Swiat* swiat) {
    polozenie=new Punkt();
    this->swiat=swiat;
    this->sila=SILA;
    this->inicjatywa=4;
    this->symbol='Y';
    this->typ="Czlowiek";
    umiejetnoscTrwa= false;
    uzytoUmiejstnosc= false;
}

Czlowiek::Czlowiek(Swiat *swiat, int x, int y) {
    this->swiat=swiat;
    polozenie=new Punkt(x,y);
    this->sila=SILA;
    this->inicjatywa=4;
    this->symbol='Y';
    this->typ="Czlowiek";
    umiejetnoscTrwa= false;
    uzytoUmiejstnosc= false;
}

Organizm *Czlowiek::Konstuktor(int x, int y) {
    return new Czlowiek(swiat,x,y);
}

void Czlowiek::akcja() {
    this->swiat->InformacjeOUmiejetnosc=UmiejetnoscInfo();
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
        cout<<"Zapisano Swiat"<<endl;
        this->akcja();
        this->swiat->plansza->AktualizujPlansze(this->swiat->organizmy);
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

void Czlowiek::Umiejetnosc() {
    if(!uzytoUmiejstnosc && sila <= 10){
    umiejetnoscTrwa= true;
    uzytoUmiejstnosc=true;
    cout<<"UZYTO UMIEJETNOSCI"<<endl;
        sila = 10;
    }
}

void Czlowiek::starzejSie() {

    if(umiejetnoscTrwa){
        if(sila==SILA+1){
            umiejetnoscTrwa=false;
            cout<<"KONIEC DZIALANIA UMIEJETNOSCI"<<endl;
        }
        sila--;
    }
    Organizm::starzejSie();
}


bool Czlowiek::CzyUmTrwa() {
    return umiejetnoscTrwa;
}

bool Czlowiek::CzyUmWykorzystana() {
    return uzytoUmiejstnosc;
}

int Czlowiek::UmiejetnoscInfo() const {
    if(umiejetnoscTrwa && uzytoUmiejstnosc){return 11;}
    else if(!umiejetnoscTrwa && uzytoUmiejstnosc){return 0;}
    else if(!umiejetnoscTrwa && !uzytoUmiejstnosc){return 1;}

}






