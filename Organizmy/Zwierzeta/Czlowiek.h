//
// Created by Wiktor on 16.04.2022.
//

#ifndef UNTITLED_CZLOWIEK_H
#define UNTITLED_CZLOWIEK_H


#include "../../Swiat.h"
#include "../Zwierze.h"

class Czlowiek:
public Zwierze
    {
        public:
        Czlowiek(Swiat* swiat,int x,int y);
        Czlowiek();

        void akcja() override;

    Organizm *Konstuktor(int x, int y) override;
};



#endif //UNTITLED_CZLOWIEK_H
