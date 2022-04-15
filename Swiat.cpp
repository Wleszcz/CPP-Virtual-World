//
// Created by wikto on 12.04.2022.
//

#include "Swiat.h"
#include "Organizmy/Zwierze.h"


Swiat::Swiat(int x, int y) {
    plansza = new Plansza(x,y);
}

void Swiat::rysujSwiat() {
    plansza->RysujPlansze();
}

void Swiat::wykonajTure() {
    std::cout<<tura<<std::endl;
    plansza->AktualizujPlansze(organizmy);

    for (int i = 0; i < organizmy.size(); ++i) {
        if (organizmy[i]->CzyZyje() && organizmy[i]->getWiek()!=0) {
            organizmy[i]->akcja();

        }
        organizmy[i]->starzejSie();
        organizmy[i]->gotowy= true;
    }

    //listaOrganizmow();
    rysujSwiat();
    listaZwierzat();
    tura++;
}

void Swiat::dodajOrganizm(Organizm *organizm) {
    organizmy.push_back(organizm);
    sortujOrganizmy();
    plansza->AktualizujPlansze(organizmy);
}

void Swiat::listaOrganizmow() {
    for (int i = 0; i < organizmy.size(); ++i) {
        std::cout<<"_____"<<i<<"_____"<<std::endl;
        std::cout<<"Typ:         "<<organizmy[i]->getTyp()<<std::endl;
        std::cout<<"Incicjatywa: "<<organizmy[i]->getInicjatywa()<<std::endl;
        std::cout<<"Sila:        "<<organizmy[i]->getSila()<<std::endl;
        std::cout<<"Zyje:        ";
        if(organizmy[i]->CzyZyje()==1){std::cout<<"tak"<<std::endl;}else{std::cout<<"nie"<<std::endl;}
        std::cout<<"Wiek:        "<<organizmy[i]->getWiek()<<std::endl;
        std::cout<<"Polozenie:   "<<organizmy[i]->getX()<<"  "<<organizmy[i]->getY()<<std::endl;
        std::cout<<std::endl<<std::endl;
    }
}
void Swiat::listaZwierzat() {
    for (int i = 0; i < organizmy.size(); ++i) {
        if(Zwierze* t = dynamic_cast<Zwierze*>(organizmy[i])){
        std::cout<<"_____"<<i<<"_____"<<std::endl;
        std::cout<<"Typ:         "<<organizmy[i]->getTyp()<<std::endl;
        std::cout<<"Incicjatywa: "<<organizmy[i]->getInicjatywa()<<std::endl;
        std::cout<<"Sila:        "<<organizmy[i]->getSila()<<std::endl;
        std::cout<<"Zyje:        ";
        if(organizmy[i]->CzyZyje()==1){std::cout<<"tak"<<std::endl;}else{std::cout<<"nie"<<std::endl;}
        std::cout<<"Wiek:        "<<organizmy[i]->getWiek()<<std::endl;
        std::cout<<"Polozenie:   "<<organizmy[i]->getX()<<"  "<<organizmy[i]->getY()<<std::endl;
        std::cout<<std::endl<<std::endl;
            }
        }
    }



void Swiat::sortujOrganizmy() {
        int i, j;
        Organizm* key;
        for (i = 1; i < organizmy.size(); i++)
        {
            key = organizmy[i];
            j = i - 1;

            while (j >= 0 && organizmy[j]->getInicjatywa() < key->getInicjatywa())
            {
                organizmy[j + 1] = organizmy[j];
                j = j - 1;
            }
            organizmy[j + 1] = key;
        }

}


