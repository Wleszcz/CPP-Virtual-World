#include <iostream>
#include "Swiat.h"
#include "Organizmy/Zwierze.h"
#include "Organizmy/Roslina.h"
#include "Organizmy/Zwierzeta/Owca.h"
#include "Organizmy/Zwierzeta/Wilk.h"
#include "Organizmy/Rosliny/Trawa.h"
#include "Organizmy/Rosliny/Mlecz.h"
#include "Organizmy/Rosliny/Guarana.h"
#include "Organizmy/Rosliny/WilczeJagody.h"
#include "Organizmy/Rosliny/BarszczSosnowskiego.h"
#include "Organizmy/Zwierzeta/Lis.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <chrono>
#include <thread>


void wait(int czas);

int main() {
    Swiat swiat(60,20);
    //swiat.rysujSwiat();


    std::srand(std::time(nullptr));
/*
    swiat.dodajOrganizm(new Owca(&swiat,0,0));
    swiat.dodajOrganizm(new Wilk(&swiat,17,17));
    swiat.dodajOrganizm(new Trawa(&swiat,9,9));
    swiat.dodajOrganizm(new Mlecz(&swiat,14,15));
    swiat.dodajOrganizm(new Guarana(&swiat,7,4));
    swiat.dodajOrganizm(new WilczeJagody(&swiat,10,4));
    for (int i = 0; i < 10; ++i) {
        swiat.wykonajTure();
        wait(200);
    }
    swiat.dodajOrganizm(new BarszczSosnowskiego(&swiat,15,15));
*/



    for (int i = -2; i <=2; i++) {
        for (int j = -2; j <= 2; j++) {
            if(!((i>-2&&i<2)&&(j>-2&&j<2))) {
                swiat.dodajOrganizm(new Owca(&swiat, 9 +i, 9 + j));
            }
        }
    }


    Zwierze* wilg=new Lis(&swiat, 9, 9);
    swiat.dodajOrganizm(wilg);
int b=wilg->polaObokZajete();

    for (int i = 0; i < 5; ++i) {
        swiat.wykonajTure();
        wait(200);
    }

    swiat.wykonajTure();

    return 0;

}
void wait(int czas){

    std::chrono::milliseconds timespan(czas);
    std::this_thread::sleep_for(timespan);
};
