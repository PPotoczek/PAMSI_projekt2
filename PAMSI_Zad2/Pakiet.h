#ifndef PAMSI_SORTOWANIE_PAKIET_H
#define PAMSI_SORTOWANIE_PAKIET_H


#include<iostream>
#include<string>

class pakiet
{
private:
    int ranking;
    std::string tytul;
    pakiet* nastepny;
public:
    int &Wez_ranikng(); // Zwraca ranking
    const std::string &Wez_tytul(); // Zwraca tytul
    void Zmien_ranking(int &liczba); // pozwala zmienic/nadac ranikng
    void Zmien_tytul(std::string nazwa); // pozwala zmienic/nadac ranikng
    pakiet* Wez_nastepny(); // zwraca wskaznik na kolejny pakiet
    void Zmien_nastepny(pakiet* wskaznik); //pozwala zmienic/nadac wskaznik nastepny
};


#endif
