#include "wynik.h"
#include "poledogry.h"

using namespace std;

Wynik::Wynik(Pole_do_gry& K, int w)
  : pole(K)
  , liczba_figur_w_rzedzie(w) // pole=K , liczba_figur_w_rzedzie=w;
{
}

/*Funkcja nie rózni się za duzo od innych funkcji sprawdzających, po prostu
 * funkcje różnią się poruszaniem po macierzy, a reszta tak samo. */

bool
Wynik::wygrana_skosna_prawa_strona(char k)
{
  int ilosc_takiej_samej_figury_obok_siebie = 0;
  int j = 0; // Zmienna służaca do poruszania sie po macierzy.
  int a = 0;
  for (int i = 0; i < pole.rozmiar; i++) {
    if (j < pole.rozmiar) {
      if (pole.macierz[i][j] == k) // Sprawdzamy czy w tym polu jest 'o' czy 'x'
                                   // zalezy od parametru k i sumujemy tak jak
                                   // nalezy.
      {
        ilosc_takiej_samej_figury_obok_siebie++; // Tutaj sumujemy liczbe figur
                                                 // obok siebie
        if (ilosc_takiej_samej_figury_obok_siebie ==
            liczba_figur_w_rzedzie) // Tutaj ktoś wygrał..
        {
          return true;
        }
        j++; // przesuwamy się j
      } else {
        ilosc_takiej_samej_figury_obok_siebie = 0; // zerujemy ponieważ kolejnym
                                                   // elementem był inny znak ,
                                                   // musi teraz liczyc od nowa
        j++;
      }
      if (pole.rozmiar - 1 == i) {
        ilosc_takiej_samej_figury_obok_siebie = 0; // zerujemy ponieważ nowy
                                                   // skos
        a++;
        j = a;
        i = -1;
      }
    }
  }
  return false;
}

bool
Wynik::wygrana_skosna_lewa_strona(char k)
{
  int ilosc_takiej_samej_figury_obok_siebie = 0;
  int j = pole.rozmiar - 1;
  int a = pole.rozmiar - 1;
  for (int i = 0; i < pole.rozmiar; i++) {
    if (j >= 0) {
      if (pole.macierz[i][j] == k) {
        ilosc_takiej_samej_figury_obok_siebie++;
        if (ilosc_takiej_samej_figury_obok_siebie == liczba_figur_w_rzedzie) {
          return true;
        }
        j--;
      } else {
        ilosc_takiej_samej_figury_obok_siebie = 0;
        j--;
      }
      if (pole.rozmiar - 1 == i) {
        ilosc_takiej_samej_figury_obok_siebie = 0;
        a--;
        j = a;
        i = -1;
      }
    }
  }
  return false;
}

bool
Wynik::wygrana_okreslonego_gracza_pionowa(char k)
{
  int ilosc_takiej_samej_figury_obok_siebie = 0;
  for (int j = 0; j < pole.rozmiar; j++) {
    for (int i = 0; i < pole.rozmiar; i++) {
      if (pole.macierz[i][j] == k) {
        ilosc_takiej_samej_figury_obok_siebie++;
        if (ilosc_takiej_samej_figury_obok_siebie == liczba_figur_w_rzedzie) {
          return true;
        }
      } else {
        ilosc_takiej_samej_figury_obok_siebie = 0;
      }
      if (i == pole.rozmiar - 1) {
        ilosc_takiej_samej_figury_obok_siebie = 0;
      }
    }
  }
  return false;
}

bool
Wynik::wygrana_okreslonego_gracza_pozioma(char k)
{
  int ilosc_takiej_samej_figury_obok_siebie;
  for (int i = 0; i < pole.rozmiar; i++) {
    for (int j = 0; j < pole.rozmiar; j++) {
      if (pole.macierz[i][j] == k) {
        ilosc_takiej_samej_figury_obok_siebie++;
        if (ilosc_takiej_samej_figury_obok_siebie == liczba_figur_w_rzedzie) {
          return true;
        }
      } else {
        ilosc_takiej_samej_figury_obok_siebie = 0;
      }
      if (j == pole.rozmiar - 1) {
        ilosc_takiej_samej_figury_obok_siebie = 0;
      }
    }
  }
  return false;
}

bool
Wynik::wygrana_pionowa()
{
  if (wygrana_okreslonego_gracza_pionowa('x')) {
    // cout<<"Wygrał gracz nr1!\n";
    m = 'x';
    return true;
  }
  if (wygrana_okreslonego_gracza_pionowa('o')) {
    // cout<<"Wygrał gracz nr2!\n";
    m = 'o';
    return true;
  }
  return false;
}

bool
Wynik::wygrana_pozioma()
{
  if (wygrana_okreslonego_gracza_pozioma('x')) {
    // cout<<"Wygrał gracz nr1!\n";
    m = 'x';
    return true;
  }
  if (wygrana_okreslonego_gracza_pozioma('o')) {
    // cout<<"Wygrał gracz nr2!\n";
    m = 'o';
    return true;
  }
  return false;
}

bool
Wynik::wygrana_skosna()
{
  if (wygrana_skosna_prawa_strona('x') || wygrana_skosna_lewa_strona('x')) {
    // cout<<"Wygrał gracz nr1!\n";
    m = 'x';
    return true;
  }
  if (wygrana_skosna_prawa_strona('o') || wygrana_skosna_lewa_strona('o')) {
    // cout<<"Wygrał gracz nr2aa!\n";
    m = 'o';
    return true;
  }
  return false;
}

bool
Wynik::czy_ktos_wygral()
{
  if (wygrana_pionowa() || wygrana_pozioma() || wygrana_skosna()) {
    return true;
  } else {
    return false;
  }
}

bool
Wynik::remis()
{
  if (pole.ilosc_zapelnionych_pol == pole.rozmiar * pole.rozmiar) {
    // cout<<"Remis!!!\n";
    return true;
  }
  return false;
}
