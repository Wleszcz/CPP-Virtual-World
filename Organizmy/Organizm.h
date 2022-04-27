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
    bool zywy=1;
    int sila=0,inicjatywa=0,wiek=0;
    char symbol='?';
    std::string typ;
    Punkt* polozenie;

    bool gotowy=true;
public:
    Swiat* swiat;
    virtual void akcja()=0;
    virtual void kolizja(Organizm*)=0;
    virtual Organizm* Konstuktor(int x,int y)=0;
    virtual bool CzyOdbilAtak(Organizm* napastnik)=0;
    virtual void umrzyj();
    virtual void starzejSie();
    virtual void Gotowy(bool);

    void ruch(int x,int y);
    void BonusSila();



    char getSymbol() const;
    int getX();
    int getY();
    int getWiek() const;
    int getSila() const;
    bool CzyZyje() const;
    bool CzyGotowy() const;
    int getInicjatywa() const;
    std::string getTyp();

    Punkt* losowePoleObok();



};


#endif //UNTITLED_ORGANIZM_H
