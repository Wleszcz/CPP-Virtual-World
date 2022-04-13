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
    int sila,inicjatywa,wiek=0;
    char symbol;

public:
    Swiat* swiat;
    Punkt* polozenie;
    virtual void akcja()=0;
    virtual void kolizja()=0;
    void starzejSie();
    virtual Organizm* Konstuktor(int x,int y)=0;

    void ruch(int x,int y);

    //void rysowanie();
    char getSymbol();
    int getX();
    int getY();
};

#endif //UNTITLED_ORGANIZM_H
