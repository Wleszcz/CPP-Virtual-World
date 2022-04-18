//
// Created by wiktor on 12.04.2022.
//

#ifndef UNTITLED_PLANSZA_H
#define UNTITLED_PLANSZA_H
#include <ostream>
#include <vector>
#include "Organizmy/Organizm.h"

class Organizm;
class Swiat;

class Plansza{
public:
    Plansza(int x, int y);
    void PostawOrganizm(Organizm* organizm);
    void RysujPlansze();
    void AktualizujPlansze(std::vector<Organizm *> vector);
    Organizm* getOrganizm(int x,int y);

    bool CzyMaZwierze(int x, int y);
    bool poprawnyRuch(int,int);
    bool CzyPusty(int x, int y);

    int GetX();
    int GetY();


private:
    int x;
    int y;
    Organizm*** pola;



};

#endif //UNTITLED_PLANSZA_H
