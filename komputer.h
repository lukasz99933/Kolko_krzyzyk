#ifndef KOMPUTER_H
#define KOMPUTER_H
#include "poledogry.h"
#include "wynik.h"

class Komputer
{
  int algorytm_minmax(char gracz); // algorytm minmax
  Pole_do_gry& pole;
  Wynik wyn;

public:
  Komputer(Pole_do_gry& K, Wynik W);
  int wsp2;              // współrzędna komputera
  int wsp1;              // wspołrzędna komputera
  void ruch_komputera(); // ruch komputera
};

#endif // KOMPUTER_H
