//
// Created by Wiktor on 14.04.2022.
//

#ifndef UNTITLED_GUARANA_H
#define UNTITLED_GUARANA_H




#include "../Roslina.h"

class Guarana:
        public Roslina
{
public:
    Guarana();
    Guarana(Swiat* swiat,int x, int y);

    Organizm *Konstuktor(int x,int y) override;

    void kolizja(Organizm *organizm) override;
};

#endif //UNTITLED_GUARANA_H
