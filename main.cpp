#include <iostream>
#include "Swiat.h"
#include "Organizmy/Zwierze.h"
#include "Organizmy/Roslina.h"
#include "Organizmy/Zwierzeta/Owca.h"
#include "Organizmy/Zwierzeta/Wilk.h"


int main() {
    Swiat swiat(20,20);
    //swiat.rysujSwiat();


    swiat.dodajOrganizm(new Owca(0,0));
    swiat.dodajOrganizm(new Wilk(20,20));

    swiat.rysujSwiat();
    return 0;

}
