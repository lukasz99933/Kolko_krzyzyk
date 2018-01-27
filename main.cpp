#include "komputer.h"
#include "poledogry.h"
#include "rozgrywka.h"
#include "wynik.h"
#include <iostream>

int
main()
{
  int rozmiar, liczba_figur_w_rzedzie, wybor;
  cout << "Podaj rozmiar pola:\n";
  cin >> rozmiar;
  cout << "Podaj liczbe figur w rzędzie:\n";
  cin >> liczba_figur_w_rzedzie;
  cout << "Podaj z kim chcesz grać: 1-Gracz , 2-Komputer\n";
  cin >> wybor;
  Pole_do_gry K(rozmiar);
  Wynik W(K, liczba_figur_w_rzedzie);
  Komputer Komp(K, W);
  Rozgrywka R(K, W, Komp, wybor);
  R.graj();
  return 0;
}
