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
    std::cout<<typ<<" został zjedzony"<<std::endl;
}
bool Organizm::CzyZyje() const {
    return zywy;
}
void Organizm::ruch(int x, int y) {

    if (!swiat->plansza->CzyPusty(x, y)){
        if(swiat->plansza->getOrganizm(x,y)->typ!=this->typ) {
            polozenie->setX(x);
            polozenie->setY(y);
        }
        swiat->plansza->getOrganizm(x,y)->kolizja(this);
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
        int pole = rand() % 8;

        int x = this->getX();
        int y = this->getY();

        if (pole == 0) {
            x = x - 1;
            y = y - 1;
        } else if (pole == 1) {
            y = y - 1;
        } else if (pole == 2) {
            x = x + 1;
            y = y - 1;
        } else if (pole == 3) {
            x = x - 1;
        } else if (pole == 4) {
            x = x + 1;
        } else if (pole == 5) {
            x = x - 1;
            y = y + 1;
        } else if (pole == 6) {
            y = y + 1;
        } else if (pole == 7) {
            x = x + 1;
            y = y + 1;
        }
        if (this->swiat->plansza->poprawnyRuch(x,y)) {
            xK=x;
            yK=y;
            break;
        }
    }
    return new Punkt(xK,yK);
}





