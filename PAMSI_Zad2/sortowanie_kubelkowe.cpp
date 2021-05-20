#include "sortowanie_kubelkowe.h"

void sortowanie_kubelkowe(pakiet** tab,int ilosc_elementow)
{
    pakiet* zm_pom;
    Lista tab_pom[10]; //Wiemy ze rankingi sa od 1 do 10 wiec wiemy ze bedzie 10 "kublow"
    for(int i=0;i<ilosc_elementow;i++)
    {
        zm_pom=tab[i];          //zapelniam kubelki
        tab_pom[zm_pom->Wez_ranikng()-1].Dodaj_pakiet_do_listy(*zm_pom);
    }
    int licznik=0;
    for(int i=0;i<10;i++)
    {
        while(tab_pom[i].Wez_liczbe_elementow()>0)  //pokolei oprozniam listy w ten sposob mam posortowana tablice
        {
            *tab[licznik] = tab_pom[i].Zwroc_element();
            licznik++;
        }
    }
}