#include <iostream>
#include "Lista.h"

Lista::Lista()
{
    glowa = nullptr;
    liczba_elementow = 0;
}

const int &Lista::Wez_liczbe_elementow()
{
    return liczba_elementow;
}

pakiet *Lista::Wez_glowe()
{
    return glowa;
}

void Lista::Dodaj_pakiet_do_listy(pakiet element)
{
    pakiet *nowy_element;
    nowy_element = new pakiet;  //alokuje pamiec dla pakietu
    nowy_element->Zmien_ranking(element.Wez_ranikng()); //tworze nowy pakiet z podanych danych
    nowy_element->Zmien_tytul(element.Wez_tytul());
    nowy_element->Zmien_nastepny(nullptr);
    pakiet* pakiet_pomocniczy;
    if(glowa == nullptr)
    {
        glowa = nowy_element;   //jezeli nie ma glowy to podany element staje sie glowa
        liczba_elementow++;
    }
    else
    {
        pakiet_pomocniczy = glowa;
        while(pakiet_pomocniczy->Wez_nastepny()!=nullptr)       //jezeli jest glowa to przechodze po wszystkich elementach dolaczonych do glowy i na koncu "dodczepiam"
        {                                                       //nowy element
            pakiet_pomocniczy = pakiet_pomocniczy->Wez_nastepny();
        }
        pakiet_pomocniczy->Zmien_nastepny(nowy_element);
        liczba_elementow++;
    }
}

pakiet Lista::Zwroc_element()
{
    pakiet pakiet_pomocniczy2;
    pakiet *pakiet_pomocniczy;
    pakiet_pomocniczy = glowa;  //daje glowe do zmiennej pomocniczej, poniewaz bede zwracal glowe
    glowa = glowa->Wez_nastepny();  //teraz nastepny element staje sie glowa
    pakiet_pomocniczy2 = *pakiet_pomocniczy;
    delete pakiet_pomocniczy;   //czyszcze pamiec aby uniknac wyciekow pamieci
    liczba_elementow--;
    return pakiet_pomocniczy2;
}
