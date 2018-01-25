#include<iostream>

#include<stdlib.h>

#include"poledogry.h"



using namespace std;





Pole_do_gry::Pole_do_gry(int r) : rozmiar(r)

{

    macierz=new char*[rozmiar]; //Wypełniamy plansze spacjami

    for(int i=0;i<rozmiar;i++)

    {

        macierz[i]=new char[rozmiar];

        for(int j=0;j<rozmiar;j++)

        {

                macierz[i][j]=' ';

        }

    }

}



Pole_do_gry::~Pole_do_gry()

{

    for(int i=0;i<rozmiar;i++)

    {

        delete[] macierz[i]; //usuwanie macierzy

    }

    delete[] macierz;

}



void Pole_do_gry::wyswietl()

{

    system("clear"); //czyścimy konsole

    cout<<"***Plansza***\n";

    cout<<"  ";

    for(int k=0;k<rozmiar;k++)

    {

        cout<<"("<<k<<")";

    }

    cout<<"\n";

    for(int i=0;i<rozmiar;i++)

    {

        for(int j=0;j<rozmiar;j++)

        {

            if(j!=0 && j!=rozmiar)

            {

                cout<<"|";

            }

            if(j==0)

            {

                cout<<"("<<i<<")"<<" ";

            }

            cout<<macierz[i][j];

        }

        cout<<"\n";

    }

}


