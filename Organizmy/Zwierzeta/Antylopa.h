//
// Created by Wiktor on 16.04.2022.
//

#ifndef UNTITLED_ANTYLOPA_H
#define UNTITLED_ANTYLOPA_H


#include "../Zwierze.h"

class Antylopa:
public Zwierze
    {
        public:
        Antylopa(Swiat* swiat,int x,int y);
        Antylopa();

    bool CzyOdbilAtak(Organizm *napastnik) override;

    Organizm *Konstuktor(int x,int y) override;

        void akcja() override;

    Punkt *losowePole();
};
#endif //UNTITLED_ANTYLOPA_H
