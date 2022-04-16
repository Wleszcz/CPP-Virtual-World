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
#include "Organizmy/Zwierzeta/Zolw.h"
#include "Organizmy/Zwierzeta/Antylopa.h"
#include "Organizmy/Zwierzeta/Czlowiek.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include <chrono>
#include <thread>

void test0(Swiat* swiat);       //roslinnosc
void test1(Swiat* swiat);       //zwierzeta
void test2(Swiat* swiat);
void test3(Swiat* swiat);
void wait(int czas);

int main() {
    std::srand(std::time(nullptr));
    Swiat swiat(60,20);

    test0(&swiat);
    //test1(&swiat);
    //test2(&swiat);

    swiat.wykonajTure();

    return 0;

}
void wait(int czas){

    std::chrono::milliseconds timespan(czas);
    std::this_thread::sleep_for(timespan);
};

void test0(Swiat(* swiat)){
    swiat->dodajOrganizm(new Czlowiek(swiat,15,15));

   swiat->dodajOrganizm(new Owca(swiat,20,2));
    swiat->dodajOrganizm(new Owca(swiat,22,1));
    swiat->dodajOrganizm(new Wilk(swiat,17,17));
    swiat->dodajOrganizm(new Wilk(swiat,18,16));

    swiat->dodajOrganizm(new Trawa(swiat,9,9));
    swiat->dodajOrganizm(new Lis(swiat,14,15));
    swiat->dodajOrganizm(new Lis(swiat,13,15));
    swiat->dodajOrganizm(new Guarana(swiat,7,4));
    swiat->dodajOrganizm(new WilczeJagody(swiat,10,4));
    for (int i = 0; i < 200; ++i) {
        swiat->wykonajTure();
        wait(200);
    }

}

void test1(Swiat *swiat){
    for (int i = -2; i <=2; i++) {
        for (int j = -2; j <= 2; j++) {
            if(!((i>-2&&i<2)&&(j>-2&&j<2))) {
                swiat->dodajOrganizm(new Antylopa(swiat, 9 +i, 9 + j));
            }
        }
    }

    Zwierze* wilg=new Zolw(swiat, 9, 9);
    swiat->dodajOrganizm(wilg);

    for (int i = 0; i < 5; ++i) {
        swiat->wykonajTure();
        wait(200);
    }

}

void test2(Swiat *swiat){

    for (int i = -2; i <=2; i++) {
        for (int j = -2; j <= 2; j++) {
            if(!((i>-2&&i<2)&&(j>-2&&j<2))) {
                swiat->dodajOrganizm(new Wilk(swiat, 9 +i, 9 + j));
            }
        }
    }

    Zwierze* wilg=new Antylopa(swiat, 9, 9);
    swiat->dodajOrganizm(wilg);

    for (int i = 0; i < 5; ++i) {
        swiat->wykonajTure();
        wait(200);
    }
}
void test3(Swiat *swiat){}