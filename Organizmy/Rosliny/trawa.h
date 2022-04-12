//
// Created by wikto on 12.04.2022.
//

#ifndef UNTITLED_TRAWA_H
#define UNTITLED_TRAWA_H


#include "../Roslina.h"

class trawa:
        public Roslina
{
public:
    trawa(int x, int y, int sila, char symbol);

private:
    Trawa(int x,int y);
};


#endif //UNTITLED_TRAWA_H
