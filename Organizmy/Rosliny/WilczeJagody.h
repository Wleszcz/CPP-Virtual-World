//
// Created by Wiktor on 14.04.2022.
//

#ifndef UNTITLED_WILCZEJAGODY_H
#define UNTITLED_WILCZEJAGODY_H


#include "../Roslina.h"

class WilczeJagody :
public Roslina {
public:
    WilczeJagody();

    WilczeJagody(Swiat *swiat, int x, int y);

    Organizm *Konstuktor(int x, int y) override;

    void kolizja(Organizm *organizm) override;


};
#endif //UNTITLED_WILCZEJAGODY_H
