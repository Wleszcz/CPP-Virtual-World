//
// Created by wikto on 12.04.2022.
//

#ifndef UNTITLED_OWCA_H
#define UNTITLED_OWCA_H

#include "../Zwierze.h"
class Owca :
        public Zwierze

{
public:
    Owca(Swiat* swiat,int x,int y,int wiek,int sila);
    Owca(Swiat* swiat,int x,int y);
    Owca(Swiat* swiat);

    Organizm *Konstuktor(int x,int y) override;

};
#endif //UNTITLED_OWCA_H
