#ifndef ROZGRYWKA_H

#define ROZGRYWKA_H

#include "poledogry.h"

#include "wynik.h"

#include "komputer.h"



using namespace std;



/*W tej klasie znajdują sie metody w których zachodzi gra */

class Rozgrywka

{

    int wybor=0; //wybor-wybor gracz czy komputer

    bool czy_ruch_juz_taki_byl(); //funkcja czy ruch juz taki był, jesli tak to okreslony gracz musi powtórzyc ruch

    int wspolrzedna_1; //Wspołrzędna do ruchu

    int wspolrzedna_2; //Współrzędna do ruchu

    Pole_do_gry & pole;

    Wynik & wyn;

    Komputer & komp;

public:

    void graj(); //Najważniejsza funkcja w której zachodzi gra

    Rozgrywka(Pole_do_gry & P, Wynik & W, Komputer & K, int wyb); //Rozgrywka przyjmuje wszystkie klasy.

};



#endif // ROZGRYWKA_H


