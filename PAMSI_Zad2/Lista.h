#ifndef PAMSI_SORTOWANIE_LISTA_H
#define PAMSI_SORTOWANIE_LISTA_H

#include<iostream>
#include<string>
#include "Pakiet.h"

class Lista
{
private:
    int liczba_elementow;
    pakiet* glowa;
public:
    Lista(); // konstruktor bezparametryczny dla listy
    const int &Wez_liczbe_elementow(); // zwraca ilosc elementow na liscie
    pakiet* Wez_glowe(); // zwraca wskaznik na glowe listy (pierwszy element)
    void Dodaj_pakiet_do_listy(pakiet element); //dodaje pakiet do listy
    pakiet Zwroc_element(); //zwraca pakiet
};


#endif
