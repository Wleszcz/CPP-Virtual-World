//
// Created by wiktor on 12.04.2022.
//

#ifndef UNTITLED_ROSLINA_H
#define UNTITLED_ROSLINA_H


#include "Organizm.h"
class Roslina :
        public Organizm
{
public:
    //Roslina(int x,int y,int sila,char symbol);

    void akcja() override;

    void kolizja() override;

protected:
    void rozmnozSie();
};


#endif //UNTITLED_ROSLINA_H
