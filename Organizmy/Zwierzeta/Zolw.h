//
// Created by Wiktor on 15.04.2022.
//

#ifndef UNTITLED_ZOLW_H
#define UNTITLED_ZOLW_H

#include "../Zwierze.h"
class Zolw :
        public Zwierze
{
public:
    Zolw(Swiat* swiat,int x,int y);
    Zolw();

    Organizm *Konstuktor(int x,int y) override;

    void akcja() override;
    void kolizja(Organizm *organizm) override;

    bool CzyOdbilAtak(Organizm* napastnik) override;
};
#endif //UNTITLED_ZOLW_H
