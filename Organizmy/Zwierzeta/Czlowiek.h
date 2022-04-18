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
        Czlowiek(Swiat* swiat,int x,int y,int wiek,int sila);
        Czlowiek(Swiat* swiat,int x,int y);
        Czlowiek();
        bool Umiejetnosc();

        void akcja() override;
        void umrzyj() override;

    Organizm *Konstuktor(int x, int y) override;

    void starzejSie() override;

    bool uzytoUmiejstnosc=false;
    bool umiejetnoscAktywna=false;
private:

};



#endif //UNTITLED_CZLOWIEK_H
