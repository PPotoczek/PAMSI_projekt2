#include "Pakiet.h"

int &pakiet::Wez_ranikng()
{
    return ranking;
}

const std::string &pakiet::Wez_tytul()
{
    return tytul;
}

void pakiet::Zmien_ranking(int &liczba)
{
    ranking = liczba;
}

void pakiet::Zmien_tytul(std::string nazwa)
{
    tytul = nazwa;
}

pakiet *pakiet::Wez_nastepny()
{
    return nastepny;
}

void pakiet::Zmien_nastepny(pakiet *wskaznik)
{
    nastepny = wskaznik;
}
