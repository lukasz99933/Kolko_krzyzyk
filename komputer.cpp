#include "komputer.h"



using namespace std;



Komputer::Komputer(Pole_do_gry & K, Wynik W) : pole(K), wyn(W)

{}



/*Funkcja odpowiedzialna za ruch komputera*/

void Komputer::ruch_komputera()

{

    int w; //pomocnicza zmienna

    int wynik= -10; // przykładowa wartosc dla komputera

    for(int i=0;i<pole.rozmiar;i++) //poruszamy się po macierzy

    {

        for(int j=0;j<pole.rozmiar;j++)

        {

                if(pole.macierz[i][j]==' ')

                {

                    pole.macierz[i][j]='o'; //w wolne miejsce wstawiamy 'o'

                    w=algorytm_minmax('o'); //przeprowadzamy algorytm minmax

                    pole.macierz[i][j]=' '; //zerujemy pole

                    if(w>wynik) //sprawdzamy rezultat algorytmu , jeśli zachodzi warunek to ruch jest korzystny dla komputera

                    {

                        wynik=w;

                        wsp1=i;

                        wsp2=j;

                    }

                }

        }

    }

}



int Komputer::algorytm_minmax(char gracz)

{

    int wynik=-30;

    int w=-30;

    wyn.czy_ktos_wygral(); //sprawdzamy czy ktoś wygrał

    if(wyn.m==gracz) 

    {

        if(gracz=='o') //wygrał komputer

        {

            return 1;

        }

        else // wygrał gracz

        {

            return -1;

        }

    }

    if(wyn.remis()) //sprawdzamy czy jest remis

    {
        return 0;

    }

    if(gracz=='x') //zmieniamy gracza

    {

        gracz='o';

    }

    else

    {

        gracz='x';

    }

    if(gracz=='x')

    {

        wynik=10;

    }

    else

    {

        wynik=-10;

    }

    for(int i=0;i<pole.rozmiar;i++) //poruszamy się po macierzy i wypełniamy ją ruchami i sprawdzamy dla kogo ruchy są korzystne

    {

        for(int j=0;j<pole.rozmiar;j++)

        {

                if(pole.macierz[i][j]==' ')

                {

                    pole.macierz[i][j]=gracz; //wpisujemy dana wartosc do planszy

                    w=algorytm_minmax(gracz);

                    pole.macierz[i][j]=' '; //zerujemy to co wpisalismy

                    if((gracz=='x'&& w<wynik) ||( gracz=='o' && w>wynik))

                    {

                        wynik=w;

                    }

                }

        }

    }

    return wynik; // zwracay wynik algorytmu

}


