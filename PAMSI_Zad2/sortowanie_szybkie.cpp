#include "sortowanie_szybkie.h"

void sortowanie_szybkie(pakiet** tab, int lewy_index, int prawy_index)
{
    if(lewy_index > prawy_index)        //krok podstawowy
    {
        return;
    }
    pakiet* temp_pom1;
    int srodek = (lewy_index+prawy_index)/2; // biore srodek
    int piwot = tab[srodek]->Wez_ranikng();  //piwot biore ze srodka
    int temp_lewy = lewy_index;
    int temp_prawy = prawy_index;
    temp_pom1 = tab[temp_prawy]; //metoda insitu piwot dajemy na koniec
    tab[temp_prawy] = tab[srodek];// piwot;  //zamieniamy miejscem ostatni element z piwotem
    tab[srodek] = temp_pom1;
    temp_prawy = temp_prawy-1; //-1 bo piwota nie ruszamy
    while(temp_lewy<=temp_prawy) //szukam pary do zamiany
    {
        while(tab[temp_lewy]->Wez_ranikng()<piwot && temp_lewy<=temp_prawy)
        {
            temp_lewy++;    //ide od lewej to zwiekszam
        }
        while(tab[temp_prawy]->Wez_ranikng()>piwot && temp_prawy>=temp_lewy)
        {
            temp_prawy--;   //ide od prawej to zmniejszam
        }
        if(temp_lewy<=temp_prawy)
        {
            temp_pom1 = tab[temp_prawy];      //zamiana
            tab[temp_prawy] = tab[temp_lewy];
            tab[temp_lewy]= temp_pom1;
            temp_lewy++;    //przesuwamy sie i kontynujemy szukanie
            temp_prawy--;
        }
    }
    temp_pom1 = tab[prawy_index];   // musze teraz piwot z konca wstawic spowrotem do tablicy w odpowiadajace mu miejsce
    tab[prawy_index] = tab[temp_lewy];
    tab[temp_lewy] = temp_pom1;
    sortowanie_szybkie(tab, lewy_index, temp_lewy-1); //rekurencja dla pierwszej polowy
    sortowanie_szybkie(tab, temp_lewy+1, prawy_index); //rekurencja dla drugiej polowy
}
