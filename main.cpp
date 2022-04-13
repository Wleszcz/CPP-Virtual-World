#include <iostream>
#include "Swiat.h"
#include "Organizmy/Zwierze.h"
#include "Organizmy/Roslina.h"
#include "Organizmy/Zwierzeta/Owca.h"
#include "Organizmy/Zwierzeta/Wilk.h"
#include "Organizmy/Rosliny/Trawa.h"


int main() {
    Swiat swiat(20,20);
    //swiat.rysujSwiat();


    swiat.dodajOrganizm(new Owca(0,0));
    swiat.dodajOrganizm(new Wilk(19,19));
    swiat.dodajOrganizm(new Trawa(9,9));

    for (int i = 0; i < 4; ++i) {
        swiat.wykonajTure();
        swiat.rysujSwiat();
    }

    return 0;

}
