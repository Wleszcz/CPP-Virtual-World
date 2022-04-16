//
// Created by wiktor on 12.04.2022.
//

#include "Organizm.h"
#include "../Punkt.h"

int Organizm::getX() {
    return polozenie->getX();
}
int Organizm::getY() {
    return polozenie->getY();
}
int Organizm::getWiek() const {
    return wiek;
}
int Organizm::getInicjatywa() const{
    return inicjatywa;
}
int Organizm::getSila() const {
    return  sila;
}

char Organizm::getSymbol() const {
    return symbol;
}
void Organizm::starzejSie(){
    wiek++;
}
void Organizm::umrzyj() {
    zywy=false;
}
bool Organizm::CzyZyje() const {
    return zywy;
}
void Organizm::ruch(int x, int y) {

    if (!swiat->plansza->CzyPusty(x, y) && swiat->plansza->getOrganizm(x,y)!=this){

        if(swiat->plansza->getOrganizm(x,y)->typ==this->typ){
            swiat->plansza->getOrganizm(x,y)->kolizja(this);
        }
        else {
            if (!(swiat->plansza->getOrganizm(x, y)->CzyOdbilAtak(this))) {
                swiat->plansza->getOrganizm(x,y)->kolizja(this);
                polozenie->setX(x);
                polozenie->setY(y);
            }
        }

    }
    else{
        polozenie->setX(x);
        polozenie->setY(y);
    }
    swiat->plansza->AktualizujPlansze(swiat->organizmy);

    //std::cout<<typ<<" idzie na: "<<x<< " "<<y<<std::endl;
}



void Organizm::BonusSila() {
    sila=sila*3;
}

std::string Organizm::getTyp() {
    return typ;
}

Punkt* Organizm::losowePoleObok() {
    int xK,yK;
    while (true) {
        int x1 = rand() % 3;
        int y1 = rand() % 3;

        int x = getX()-1+x1;
        int y = getY()-1+y1;

        if (this->swiat->plansza->poprawnyRuch(x,y) && !(x==0 && y==0)) {
            xK=x;
            yK=y;
            break;
        }
    }
    return new Punkt(xK,yK);
}





