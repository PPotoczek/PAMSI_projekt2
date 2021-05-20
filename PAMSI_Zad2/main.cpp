#include <iostream>
#include <string>
#include <fstream>
#include "Pakiet.h"
#include "sortowanie_kubelkowe.h"
#include "sortowanie_przez_scalanie.h"
#include "sortowanie_szybkie.h"
#include <chrono>

int main()
{
    int ilosc_danych;
    std::string nazwa;
    std::fstream plik;
    std::cout << "Podaj ilosc elementow:" << std::endl;
    std::cin >> ilosc_danych;
    pakiet** tab = new pakiet*[ilosc_danych];  //tablica dynamiczna przechowujaca wskazniki na pakiety (tytul + ranking)
    float zmienna;
    int zmienna2;
    plik.open("ranking.txt",std::ios::in);  //otwieram plik z rankingami
    for(int i=0;i<ilosc_danych;i++)
    {
        tab[i] = new pakiet; //alokacja pamiecy
        plik >> zmienna;
        zmienna2 = static_cast<int>(zmienna);   //rankingi sa w formie np 1.0 wiec robie casta na inta
        tab[i]->Zmien_ranking(zmienna2);
    }
    plik.close();
    plik.open("tytul.txt",std::ios::in);    //otwieram plik z tytulami
    for(int i=0;i<ilosc_danych;i++)
    {
        std::getline(plik, nazwa);      //tytuly moga zawierac spacje wiec dzieki funkcji getline biore cala linike tekstu jako tytul
        tab[i]->Zmien_tytul(nazwa);
    }
    plik.close();
    int ilosc_danych_po_filtracji=0;
    for(int i=0;i<ilosc_danych;i++)         //teraz patrze ile bedzie danych po filtracji, w excelu wstawilem 0 tam gdzie normalnie nie było rankingow teraz musze po prostu
    {                                       // wyrzucic te dane najpierw sprawdzam ile bedzie danych po filtracji zeby moc zalokowac pamiec dla nowej tablicy
        if(tab[i]->Wez_ranikng()!=0)
        {
            ilosc_danych_po_filtracji++;
        }
    }
    pakiet** tab_po_filtracji = new pakiet*[ilosc_danych_po_filtracji]; //tablica dynamiczna przechowujaca wskazniki na pakiety (tytul + ranking)
    int licznik = 0;
    for(int i=0;i<ilosc_danych;i++)
    {
        if(tab[i]->Wez_ranikng()!=0)
        {
            tab_po_filtracji[licznik] = tab[i];         //biore tylko te dane ktore spelniaja warunki (ranking nie jest rowny 0)
            licznik++;
        }
    }

    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();   //sprawdzam czas przed wywolanie sortowania

    //sortowanie_kubelkowe(tab_po_filtracji,ilosc_danych_po_filtracji);
    //sortowanie_przez_scalanie(tab_po_filtracji,0,ilosc_danych_po_filtracji-1);
    sortowanie_szybkie(tab_po_filtracji,0,ilosc_danych_po_filtracji-1);

    std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();    //sprawdzam czas po wywolaniu sortowania

    std::chrono::duration<double, std::milli> czas_liczenia_algorytmu = stop - start;   //licze ile czasu zajelo algorytmowi posortowanie

    for(int i=0;i<ilosc_danych_po_filtracji;i++)
    {
        std::cout << tab_po_filtracji[i]->Wez_ranikng() << " " << tab_po_filtracji[i]->Wez_tytul() << std::endl;    // mozna wypisac, zeby sprawdzic czy sa posortowane
    }

    std::cout <<"=============== Algorytmowi sortowanie zajelo: " << czas_liczenia_algorytmu.count()/1000 << "s ============" <<std::endl;

    double mediana=0;
    std::cout << std::endl;
    std::cout << "=======MEDIANA==============" << std::endl;
    if(ilosc_danych_po_filtracji %2 ==1)
    {
        mediana = tab_po_filtracji[ilosc_danych_po_filtracji/2]->Wez_ranikng();         //jak nieparzysta liczba danych to mediana to wartosc srodkowa
        std::cout << mediana << std::endl;
    }
    else
    {
        mediana = tab_po_filtracji[ilosc_danych_po_filtracji/2-1]->Wez_ranikng() + tab_po_filtracji[ilosc_danych_po_filtracji/2]->Wez_ranikng();
        mediana = mediana/2;        //jak parzysta liczba danych to mediana to suma dwoch srodkowych podzielona na dwa
        std::cout << mediana << std::endl;
    }
    double srednia=0;
    for(int i=0;i<ilosc_danych_po_filtracji;i++)
    {
        srednia+=tab_po_filtracji[i]->Wez_ranikng();    //sumuje wszystkie rankingi
    }
    std::cout << "========WARTOSC SREDNIA===============" <<std::endl;
    std::cout << srednia/ilosc_danych_po_filtracji << std::endl;    //dziele sume wszystkich rankingow przez ilosc danych aby uzyskac wartosc srednia rankingow

    for(int i=0;i<ilosc_danych;i++) //zwalnianie pamieci
    {
        delete tab[i];
    }
    delete[] tab;
    delete[] tab_po_filtracji;

    return 0;

}
