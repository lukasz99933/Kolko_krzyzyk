#ifndef WYNIK_H
#define WYNIK_H
#include "poledogry.h"

/*W klasie tej znajdują sie metody do sprawdzania wyniku rozgrywki */
class Wynik
{
  bool wygrana_skosna(); // Sprawdza czy ktoś wygrał na skos, korzysta z metod
                         // poniższych skosnych
  bool wygrana_pozioma(); // Sprawdza czy ktoś wygrał w poziomie , korzysta z
                          // metod poniższych poziomych
  bool wygrana_okreslonego_gracza_pionowa(
    char k); // Wygrana określonego gracza w pionie
  bool wygrana_okreslonego_gracza_pozioma(
    char k); // Wygrana okreslonego gracza w poziomie
  bool wygrana_skosna_prawa_strona(
    char k); // Wygrana określonego gracza na skos w prawo
  bool wygrana_skosna_lewa_strona(
    char k);              // Wygrana określonego gracza na skos w lewo
  bool wygrana_pionowa(); // Sprawdza czy ktoś wygrał w pionie, korzysta z metod
                          // pionowych
  Pole_do_gry& pole;
  int liczba_figur_w_rzedzie; // liczba figur w rzedzie czy też na skos
                              // potrzebna do wygranej
public:
  Wynik(Pole_do_gry& K, int w); // Konstruktor przyjmuje, dwa parametry
  bool remis();                 // Sprawdza czy jest remis
  bool czy_ktos_wygral();       // Funkcja sprawdza czy ktoś wygrał
  char m = ' ';
};

#endif // WYNIK_H
