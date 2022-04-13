#include "Roslina.h"

//
// Created by wikto on 12.04.2022.
//
#include "Roslina.h"

void Roslina::akcja(Swiat *swiat) {
int szansa = rand() % 3;
if (szansa == 0) {
    rozmnozSie(swiat);
}
}

void Roslina::kolizja(Swiat *swiat) {

}

void Roslina::rozmnozSie(Swiat* swiat) {
    int x = this->getX();
    int y = this->getY();

    while (1) {
        int pole = rand() % 7;

        switch (pole) {
            case 0:
                x = x-1;
                y= y-1;
            case 1:
                y=y-1;
            case 2:
                x=x+1;
                y=y-1;
            case 3:
                x=x-1;
            case 4:
                x=x+1;
            case 5:
                x=x-1;
                y=y+1;
            case 6:
                y=y+1;
            case 7:
                x=x+1;
                y=y+1;
        }
        if (swiat->plansza->poprawnyRuch(x,y)) {
            break;
        }

    }
    if(swiat->plansza->poprawnoscAkcji(x,y)){
        Organizm* organizm = this->Konstuktor();
        organizm->ruch(x,y);
    }
}



