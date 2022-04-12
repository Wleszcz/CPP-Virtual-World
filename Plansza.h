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

private:
    int x;
    int y;
    char** pola;
};

#endif //UNTITLED_PLANSZA_H
