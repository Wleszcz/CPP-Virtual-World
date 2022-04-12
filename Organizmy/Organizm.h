//
// Created by wiktor on 12.04.2022.
//

#ifndef UNTITLED_ORGANIZM_H
#define UNTITLED_ORGANIZM_H
#include "../Swiat.h"
#include "../Punkt.h"

class Swiat;

class Organizm
{

protected:
    int sila,inicjatywa,wiek;
    char symbol;

    Organizm(int x,int y ,int sila, int incjatywa,char symbol);

public:
    Punkt* polozenie;
    virtual void akcja(Swiat *swiat)=0;
    virtual void kolizja(Swiat* swiat)=0;
    virtual void starzejSie()=0;

    //void rysowanie();
    char getSymbol();
    Punkt* Pozycja();
};

#endif //UNTITLED_ORGANIZM_H
