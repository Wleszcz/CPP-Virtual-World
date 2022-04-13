//
// Created by wiktor on 12.04.2022.
//

#include "Punkt.h"

Punkt::Punkt(int x,int y) {
this->x=x;
this->y=y;
}
void Punkt::setX(int x) {
        this->x = x;
    }
    void Punkt::setY(int y) {
        this->y = y;
    }
    int Punkt:: getX() {
        return x;
    }
    int Punkt::getY() {
        return y;
    }

Punkt::Punkt() {
}


