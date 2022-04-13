//
// Created by wikto on 12.04.2022.
//

#include "Trawa.h"
Trawa::Trawa(){
    polozenie=new Punkt();
}
Trawa::Trawa(int x, int y){
    polozenie=new Punkt(x,y);
    this->sila=0;
    this->symbol='#';
}


void Trawa::akcja(Swiat *swiat) {
    Roslina::akcja(swiat);
}

void Trawa::kolizja(Swiat *swiat) {
    Roslina::kolizja(swiat);
}



Organizm *Trawa::Konstuktor()
{
    return new Trawa;
}