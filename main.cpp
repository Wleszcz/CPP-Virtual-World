#include <iostream>
#include "Swiat.h"
#include "Organizmy/Zwierze.h"
#include "Organizmy/Roslina.h"
#include "Organizmy/Zwierzeta/Owca.h"
#include "Organizmy/Zwierzeta/Wilk.h"
#include "Organizmy/Rosliny/Trawa.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */



int main() {
    Swiat swiat(20,20);
    //swiat.rysujSwiat();


    srand(std::time(nullptr));

    swiat.dodajOrganizm(new Owca(&swiat,0,0));
    swiat.dodajOrganizm(new Wilk(&swiat,19,19));
    swiat.dodajOrganizm(new Trawa(&swiat,9,9));

    for (int i = 0; i < 2; ++i) {
        swiat.wykonajTure();

    }
    swiat.wykonajTure();
    return 0;

}
