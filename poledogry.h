#ifndef POLEDOGRY_H

#define POLEDOGRY_H

using namespace std;



/*Klasa w której znajduje się plansza do gry */

class Pole_do_gry

{

public:

    char **macierz; //Plansza

    int ilosc_zapelnionych_pol=0;

    int rozmiar; //rozmiar planszy

    char gracz1 = 'x';

    char gracz2 = 'o';

    Pole_do_gry(int r);

    ~Pole_do_gry();

    void wyswietl(); //wyswietlamy plansze

};





#endif // GRA_H


