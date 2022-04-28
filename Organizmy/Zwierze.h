//
// Created by wikto on 12.04.2022.
//

#ifndef UNTITLED_ZWIERZE_H
#define UNTITLED_ZWIERZE_H

#include "Organizm.h"

class Zwierze :
        public Organizm {
private:
public:
    void akcja() override;

    bool polaObokZajete();

    void kolizja(Organizm *organizm) override;

    bool CzyOdbilAtak(Organizm *napastnik) override;

    void rozmnozSie();
};


#endif //UNTITLED_ZWIERZE_H
