//
// Created by wiktor on 12.04.2022.
//

#include "Plansza.h"
#include "Punkt.h"

Plansza::Plansza(int x, int y) {
    this->x = x;
    this->y = y;

    pola = new Organizm** [x];
    for (int i = 0; i < x; i++) {
        pola[i] = new Organizm*[y];
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            pola[i][j]= nullptr;
        }
    }
}


void Plansza::PostawOrganizm(Organizm* organizm) {
    pola[organizm->getX()][organizm->getY()]=organizm;
}


void Plansza::AktualizujPlansze(std::vector<Organizm *> organizmy) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            pola[i][j]= nullptr;
        }
    }
    for (int i = 0; i < organizmy.size(); ++i) {
            pola[organizmy[i]->getX()][organizmy[i]->getY()]=organizmy[i];
    }
}

void Plansza::RysujPlansze() {
    for (int i = 0; i < x/2+1; ++i) {
        std::cout<<" _";
    }
    std::cout<<std::endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {

            if(j==0){
                std::cout<<'|';
            }

            if(pola[i][j]!= nullptr) {
                char symbol = pola[i][j]->getSymbol();
                std::cout << symbol;
            }
            else std::cout<<' ';

            if(j==x-1){
                std::cout<<'|';
            }
        }

        std::cout<<std::endl;
    }
    for (int i = 0; i < x/2 + 1; ++i) {
        std::cout<<" -";
    }
    std::cout<<std::endl<<std::endl;
}

bool Plansza::poprawnyRuch(int x, int y) {
    if(x>0 && x<this->x-1 && y>0 && y< this->y-1){
        return true;
    }
    return false;
}
bool Plansza::poprawnoscAkcji(int x,int y){
    if(pola[x][y]== nullptr){
        return true;
    }
    return false;
}

