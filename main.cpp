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
#include "fstream"

int test0(Swiat* swiat);       //roslinnosc
int test1(Swiat* swiat);       //zwierzeta
int test2(Swiat* swiat);
int test3(Swiat* swiat);
void wait(int czas);

using namespace std;

bool wczytanieZapisu();

int main() {
    std::srand(std::time(nullptr));



    Swiat swiat(60, 20);

    if (!wczytanieZapisu()){

        if (
                test0(&swiat) != 0) {

            return 0;
        }


        swiat.wykonajTure();

    }
}


int test0(Swiat(*swiat)) {

    swiat->zmienIloscTur();
    swiat->dodajOrganizm(new Czlowiek(swiat, 15, 15));
    swiat->dodajOrganizm(new Owca(swiat, 20, 2));
    swiat->dodajOrganizm(new Owca(swiat, 22, 1));
    swiat->dodajOrganizm(new Wilk(swiat, 17, 17));
    swiat->dodajOrganizm(new Wilk(swiat, 18, 16));

    swiat->dodajOrganizm(new Trawa(swiat, 9, 9));
    swiat->dodajOrganizm(new Lis(swiat, 14, 15));
    swiat->dodajOrganizm(new Lis(swiat, 13, 15));
    swiat->dodajOrganizm(new Guarana(swiat, 7, 4));
    swiat->dodajOrganizm(new WilczeJagody(swiat, 10, 4));

    swiat->dodajOrganizm(new Antylopa(swiat,40,17));
    swiat->dodajOrganizm(new Antylopa(swiat,42,16));

    swiat->dodajOrganizm(new Zolw(swiat,30,16));
    swiat->dodajOrganizm(new Zolw(swiat,32,16));

    for (int i = 0; i < swiat->GetIloscTur()-1; ++i) {
        if (swiat->Koniec != 0) {
            return 1;
        }
        swiat->wykonajTure();
        wait(200);
    }
    return 0;

}

int test1(Swiat *swiat){

    swiat->zmienIloscTur();
    for (int i = -2; i <=2; i++) {
        for (int j = -2; j <= 2; j++) {
            if(!((i>-2&&i<2)&&(j>-2&&j<2))) {
                swiat->dodajOrganizm(new Antylopa(swiat, 9 +i, 9 + j));
            }
        }
    }

    Zwierze* wilg=new Zolw(swiat, 9, 9);
    swiat->dodajOrganizm(wilg);

    for (int i = 0; i < swiat->GetIloscTur(); ++i) {

        if(swiat->Koniec!=0){
            return 1;
        }
        //swiat->wykonajTure();
        wait(200);
    }
    return 0;
}

int test2(Swiat *swiat){

    swiat->zmienIloscTur();
    for (int i = -2; i <=2; i++) {
        for (int j = -2; j <= 2; j++) {
            if(!((i>-2&&i<2)&&(j>-2&&j<2))) {
                swiat->dodajOrganizm(new Wilk(swiat, 9 +i, 9 + j));
            }
        }
    }

    Zwierze* wilg=new Antylopa(swiat, 9, 9);
    swiat->dodajOrganizm(wilg);

    for (int i = 0; i < swiat->GetIloscTur(); ++i) {

        if(swiat->Koniec!=0){
            return 1;
        }
    }
    return 0;
}


int test3(Swiat *swiat){
    return 0;
}


bool wczytanieZapisu() {
    cout<<"Czy chcesz wczytac zapis? (T/N)"<<endl;
    char opc;

    cin>>opc;
    if(opc=='n'|| opc=='N'){
        return false;
    }
    else if(opc=='t' || opc=='T') {


        std::ifstream ZAPIS;
        ZAPIS.open("save.txt", std::ios::in);
        if (ZAPIS.is_open()) {

            string x_s,y_s,tura_s,iloscTur_s,organizmy_s;
            int x,y,tura,iloscTur,organizmy;
            getline(ZAPIS ,x_s);
            getline(ZAPIS ,y_s);
            getline(ZAPIS ,tura_s);
            getline(ZAPIS ,iloscTur_s);
            getline(ZAPIS ,organizmy_s);
            x=stoi(x_s);
            y=stoi(y_s);
            tura=stoi(tura_s);
            iloscTur=stoi(iloscTur_s);
            organizmy=stoi(organizmy_s);

            Swiat swiat(x, y,tura,iloscTur);


            for (int i = 0; i < organizmy; ++i) {
                string typ,x_s2,y_s2,wiek_s,sila_s;
                int x2,y2,wiek,sila;

                getline(ZAPIS , typ);
                getline(ZAPIS ,wiek_s);
                getline(ZAPIS ,sila_s);
                getline(ZAPIS ,x_s2);
                getline(ZAPIS ,y_s2);

                wiek=stoi(wiek_s);
                sila= stoi(sila_s);
                x= stoi(x_s2);
                y= stoi(y_s2);

                if(typ=="Owca"){
                    swiat.dodajOrganizm(new Owca(&swiat,x,y,wiek,sila));}
                else if(typ=="Wilk"){
                    swiat.dodajOrganizm(new Wilk(&swiat,x,y,wiek,sila));}
                else if(typ=="Lis"){
                    swiat.dodajOrganizm(new Lis(&swiat,x,y,wiek,sila));}
                else if(typ=="Zolw"){
                    swiat.dodajOrganizm(new Zolw(&swiat,x,y,wiek,sila));}
                else if(typ=="Antylopa"){
                    swiat.dodajOrganizm(new Antylopa(&swiat,x,y,wiek,sila));}
                else if(typ=="Czlowiek"){
                    swiat.dodajOrganizm(new Czlowiek(&swiat,x,y,wiek,sila));}

                else if(typ=="Barszcz Sosnowskiego"){
                    swiat.dodajOrganizm(new BarszczSosnowskiego(&swiat,x,y,wiek,sila));}
                else if(typ=="Guarana"){
                    swiat.dodajOrganizm(new Guarana(&swiat,x,y,wiek,sila));}
                else if(typ=="Mlecz"){
                    swiat.dodajOrganizm(new Mlecz(&swiat,x,y,wiek,sila));}
                else if(typ=="Trawa"){
                    swiat.dodajOrganizm(new Trawa(&swiat,x,y,wiek,sila));}
                else if(typ=="Wilcze Jagody"){
                    swiat.dodajOrganizm(new WilczeJagody(&swiat,x,y,wiek,sila));}
            }
            swiat.rysujSwiat();

            for (int i = tura; i < iloscTur; ++i) {
                swiat.wykonajTure();
            }

            return true;
        }
        else{
            cout<<"Blad wczytywania Zapisu !"<<endl;
            return false;
        }
    }
}


void wait(int czas) {
        std::chrono::milliseconds timespan(czas);
        std::this_thread::sleep_for(timespan);
    };

