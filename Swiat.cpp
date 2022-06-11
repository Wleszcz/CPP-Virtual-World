#include "Swiat.h"
#include "Organizmy/Zwierze.h"
#include "Organizmy/Zwierzeta/Czlowiek.h"
#include <fstream>
#include <iostream>


#define LISTA_ORGANIZMOW false
#define LISTA_ZWIERZAT false
#define STATYSTYKI true
#define NARRATOR true
#define MARGINES 0

using namespace std;

Swiat::Swiat(int x, int y) {
    plansza = new Plansza(x, y);
    Narrator = NARRATOR;
}

Swiat::Swiat(int x, int y, int tura, int iloscTur) {
    plansza = new Plansza(x, y);
    this->tura = tura;
    this->iloscTur = iloscTur;
    Narrator = NARRATOR;
}

void Swiat::rysujSwiat() {
    for (int i = 0; i < MARGINES; ++i) {
        cout << endl;
    }

    if (LISTA_ORGANIZMOW) { listaOrganizmow(); }
    if (LISTA_ZWIERZAT) { listaZwierzat(); }
    if (STATYSTYKI) { statystyki(); }

    std::cout << "Tura: " << tura << " / " << iloscTur << std::endl;
    plansza->RysujPlansze();
}

int
Swiat::wykonajTure() {                              //Glowny mechanizm rozgrywania tur oraz prezentowania planszy na ekranie
    plansza->AktualizujPlansze(organizmy);

    for (int i = 0; i < organizmy.size(); ++i) {
        if (organizmy[i]->CzyZyje()) {

            if (organizmy[i]->getWiek() != 0) {
                organizmy[i]->akcja();
            }
            organizmy[i]->starzejSie();
            organizmy[i]->Gotowy(true);

            if (Koniec) {

                return 1;

            }
        }
    }
    tura++;
    rysujSwiat();

    return 0;
    usunMartwe();
}

void Swiat::dodajOrganizm(
        Organizm *organizm) {                     //Glowna funkcja dodajaca organizmy na liste, oraz plansze
    int x = organizm->getX();
    int y = organizm->getY();
    if (plansza->CzyPusty(x, y) && plansza->poprawnyRuch(x, y)) {
        organizmy.push_back(organizm);
        sortujOrganizmy();
        plansza->AktualizujPlansze(organizmy);
    }
}

void
Swiat::listaOrganizmow() const {                                          //Nastepne 3 funkcje ulatwiaja debugowanie, wypisuja zyjace zwierzeta
    for (int i = 0; i < organizmy.size(); ++i) {
        std::cout << "_____" << i << "_____" << std::endl;
        std::cout << "Typ:         " << organizmy[i]->getTyp() << std::endl;
        std::cout << "Incicjatywa: " << organizmy[i]->getInicjatywa() << std::endl;
        std::cout << "Sila:        " << organizmy[i]->getSila() << std::endl;
        std::cout << "Wiek:        " << organizmy[i]->getWiek() << std::endl;
        std::cout << "Polozenie:   " << organizmy[i]->getX() << "  " << organizmy[i]->getY() << std::endl;
        std::cout << std::endl << std::endl;
    }
}

void Swiat::listaZwierzat() const {
    for (int i = 0; i < organizmy.size(); ++i) {
        if (Zwierze *t = dynamic_cast<Zwierze *>(organizmy[i])) {
            std::cout << "_____" << i << "_____" << std::endl;
            std::cout << "Typ:         " << organizmy[i]->getTyp() << std::endl;
            std::cout << "Incicjatywa: " << organizmy[i]->getInicjatywa() << std::endl;
            std::cout << "Sila:        " << organizmy[i]->getSila() << std::endl;
            std::cout << "Wiek:        " << organizmy[i]->getWiek() << std::endl;
            std::cout << "Polozenie:   " << organizmy[i]->getX() << "  " << organizmy[i]->getY() << std::endl;
            std::cout << std::endl << std::endl;
        }
    }
}

void Swiat::statystyki() {
    for (int i = 0; i < organizmy.size(); ++i) {
        if (Czlowiek *t = dynamic_cast<Czlowiek *>(organizmy[i])) {
            std::cout << "___________" << std::endl;
            std::cout << "Typ:         " << organizmy[i]->getTyp() << std::endl;
            std::cout << "Incicjatywa: " << organizmy[i]->getInicjatywa() << std::endl;
            std::cout << "Sila:        " << organizmy[i]->getSila() << std::endl;
            std::cout << "Wiek:        " << organizmy[i]->getWiek() << std::endl;
            std::cout << "Polozenie:   " << organizmy[i]->getX() << "  " << organizmy[i]->getY() << std::endl;
        }
    }
}


void Swiat::sortujOrganizmy() {
    usunMartwe();
    int i, j;
    Organizm *key;
    for (i = 1; i < organizmy.size(); i++) {
        key = organizmy[i];
        j = i - 1;

        while (j >= 0 && organizmy[j]->getInicjatywa() < key->getInicjatywa()) {
            organizmy[j + 1] = organizmy[j];
            j = j - 1;
        }
        organizmy[j + 1] = key;
    }

}

void Swiat::usunMartwe() {
    int size = organizmy.size(), dead = 0;
    for (size_t i = 0; i < size; i++) {
        if (!organizmy[i]->CzyZyje()) {
            dead++;
        } else
            organizmy[i - dead] = organizmy[i];
    }
    for (int i = 0; i < dead; i++) {
        organizmy.pop_back();
    }
}

bool Swiat::zapiszSwiat() const {
    std::ofstream ZAPIS;


    ZAPIS.open("save.txt", std::ios::out | std::ios::trunc);
    if (ZAPIS.is_open()) {
        Czlowiek *czlowiek;
        ZAPIS << "Wielkosc planszy:" << endl;
        ZAPIS << this->plansza->GetX() << endl;
        ZAPIS << this->plansza->GetY() << endl;
        ZAPIS << "Tury rozegrane/wszystkie:" << endl;
        ZAPIS << this->tura << endl;
        ZAPIS << this->iloscTur << endl;
        ZAPIS << "Inforamcje o umiejetnosci(11-aktywna,1-wykorzystana,0-do uzycia):" << endl;
        ZAPIS << this->InformacjeOUmiejetnosc << endl;
        ZAPIS << "Ilosc Organizmow:" << endl;
        ZAPIS << organizmy.size() << endl;
        for (int i = 0; i < organizmy.size(); ++i) {
            ZAPIS << endl;
            ZAPIS << organizmy[i]->getTyp() << endl;
            ZAPIS << "Wiek / Sila / Pozycja :" << endl;
            ZAPIS << organizmy[i]->getWiek() << endl;
            ZAPIS << organizmy[i]->getSila() << endl;
            ZAPIS << organizmy[i]->getX() << endl;
            ZAPIS << organizmy[i]->getY() << endl;

        }
        ZAPIS.close();
    } else {
        std::cout << "Blad Zapisu!" << std::endl;
    }
}

void Swiat::zmienIloscTur() {
    cout << "Wpisz Ilosc tur do rozegrania: " << endl;
    int ilosc;
    cin >> ilosc;
    this->iloscTur = ilosc;
}

int Swiat::GetIloscTur() const {
    return iloscTur;
}
void Swiat::UsunWszystko(){
    int ilosc=organizmy.size();
    for (int i = 0; i < ilosc; ++i) {
        organizmy.pop_back();
    }
}


