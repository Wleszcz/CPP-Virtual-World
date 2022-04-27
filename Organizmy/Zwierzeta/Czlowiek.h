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
        Czlowiek(Swiat* swiat,int x,int y,int wiek,int sila,int umiejstnosc);
        Czlowiek(Swiat* swiat,int x,int y);
        Czlowiek();
        void Umiejetnosc();
        void UmiejetnoscWczytanie(bool uzyto, bool trwa);


        void akcja() override;
        void umrzyj() override;

    Organizm *Konstuktor(int x, int y) override;


    void starzejSie() override;

    bool CzyUmTrwa();
    bool CzyUmWykorzystana();
    int UmiejetnoscInfo() const;

private:
    bool uzytoUmiejstnosc=false;
    bool umiejetnoscTrwa=false;
};



#endif //UNTITLED_CZLOWIEK_H
