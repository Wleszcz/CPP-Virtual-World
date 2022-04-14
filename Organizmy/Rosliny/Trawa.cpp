//
// Created by wikto on 12.04.2022.
//

#include "Trawa.h"
Trawa::Trawa(){
    polozenie=new Punkt();
}
Trawa::Trawa(Swiat* swiat,int x, int y){
    polozenie=new Punkt(x,y);
    this->swiat=swiat;
    this->sila=0;
    this->symbol='#';
}


void Trawa::akcja() {
    Roslina::akcja();
}

void Trawa::kolizja() {
    Roslina::kolizja();
}



Organizm *Trawa::Konstuktor(int x,int y)
{
    return new Trawa(swiat,x,y);
}