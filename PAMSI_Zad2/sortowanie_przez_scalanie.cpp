#include "sortowanie_przez_scalanie.h"

void sortowanie_przez_scalanie(pakiet** tab,int lewy_index, int prawy_index)
{
    int srodek = (lewy_index+prawy_index)/2; //srodek poniewaz bede dzielil tablica na pol
    if(prawy_index-lewy_index>0) //do momentu w ktorym nie jest to pojedynczy element odpalam sortowanie przez scalanie
    {
        sortowanie_przez_scalanie(tab,lewy_index,srodek);   //od pierwszej polowki
        sortowanie_przez_scalanie(tab,srodek+1,prawy_index);    //od drugiej polowki
    }
    else
    {
        return;
    }
    pakiet** tab_pom = new pakiet*[prawy_index+1];  //tworze tablice pomocnicza, alokuje jej pamiec
    int temp_lewy = lewy_index;
    int temp_prawy = srodek+1;
    for(int i = lewy_index;i<prawy_index+1; i++)
    {
        tab_pom[i] = tab[i];                        //zapełniam tablice pomocnicza
    }
    for(int i = lewy_index;i<prawy_index+1; i++)
    {
        if(temp_lewy<=srodek && temp_prawy<= prawy_index)       //dopóki jedna z polowek sie nie skonczy (1 pol od lewej do srodka)
        {                                                       //drugie pol od srodka do prawej
            if(tab_pom[temp_lewy]->Wez_ranikng()>tab_pom[temp_prawy]->Wez_ranikng())        //porownuje po jednym z elementow z i biore mniejszy
            {
                tab[i] = tab_pom[temp_prawy];
                temp_prawy++;
            }
            else
            {
                tab[i] = tab_pom[temp_lewy];
                temp_lewy++;
            }
        }
        else        //jak z jednej strony elementy sie skonczyly to dopisuje elementy z drugiej polowy na koniec
        {
            if(temp_lewy<=srodek)
            {
                tab[i] = tab_pom[temp_lewy];
                temp_lewy++;
            }
            else if(temp_prawy<= prawy_index)
            {
                tab[i] = tab_pom[i];
                temp_prawy++;
            }
        }
    }
    delete[] tab_pom;       //zwalniam pamiec
}