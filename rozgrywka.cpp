#include "rozgrywka.h"
#include <iostream>

using namespace std;

Rozgrywka::Rozgrywka(Pole_do_gry& P, Wynik& W, Komputer& K, int wyb)
  : pole(P)
  , wyn(W)
  , komp(K)
  , wybor(wyb)
{
}

void
Rozgrywka::graj()
{
  while (pole.ilosc_zapelnionych_pol < pole.rozmiar * pole.rozmiar &&
         !wyn.czy_ktos_wygral()) // Wchodzimy do pętli gdy pole nie

  // jest zapełnione oraz jak ktoś nie wygrał
  {
    if (pole.ilosc_zapelnionych_pol % 2 == 0) // Gracz
    {
      cout << "(Gracz1)Podaj pierwszą współrzędną:\n";
      cin >> wspolrzedna_1;
      cout << "(Gracz1)Podaj drugą współrzędną:\n";
      cin >> wspolrzedna_2;
      if (wspolrzedna_1 < pole.rozmiar && wspolrzedna_2 < pole.rozmiar &&
          !czy_ruch_juz_taki_byl()) {
        pole.macierz[wspolrzedna_1][wspolrzedna_2] = 'x';
        pole.ilosc_zapelnionych_pol++;
        pole.wyswietl(); // wyswietlamy pole
      }
    } else {
      if (pole.ilosc_zapelnionych_pol % 2 == 1 &&
          !wyn.czy_ktos_wygral()) // Komputer
      {
        if (wybor == 2) {
          komp.ruch_komputera();
          pole.macierz[komp.wsp1][komp.wsp2] = 'o';
          pole.ilosc_zapelnionych_pol++;
          pole.wyswietl();
        }
        if (wybor == 1) // Drugi gracz, to samo co w pierwszym graczu
        {
          cout << "(Gracz2)Podaj pierwszą współrzędną:\n";
          cin >> wspolrzedna_1;
          cout << "(Gracz2)Podaj drugą współrzędną:\n";
          cin >> wspolrzedna_2;
          if (wspolrzedna_1 < pole.rozmiar && wspolrzedna_2 < pole.rozmiar &&
              !czy_ruch_juz_taki_byl()) {
            pole.macierz[wspolrzedna_1][wspolrzedna_2] = 'o';
            pole.ilosc_zapelnionych_pol++;
            pole.wyswietl();
          }
        }
      }
    }
  }
  if (wyn.m == 'x') // Sprawdzamy kto wygrał
  {
    cout << "Wygrał gracz nr1!\n";
  }
  if (wyn.m == 'o') // Sprawdzamy kto wygrał
  {
    cout << "Wygrał komputer!\n";
  }
  wyn.remis(); // Sprawdzay czy byl remis
}

/*Funkcja sprawdza czy dany ruch już był, jeśli tak to dostajemy komunikat ,
 * zeby podać ponownie wspołrzędne  */
bool
Rozgrywka::czy_ruch_juz_taki_byl()
{
  if (pole.macierz[wspolrzedna_1][wspolrzedna_2] == 'o' ||
      pole.macierz[wspolrzedna_1][wspolrzedna_2] == 'x') {
    cout << "Taki ruch już był! Podaj ponownie!\n";
    return true;
  } else {
    return false;
  }
}
