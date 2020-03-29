#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH
#include <iostream>



struct Statystyka
{
    unsigned  int poprawne;
    unsigned  int bledne;
    double procent;
};

void Wypisz(Statystyka  &St);
void Zeruj(Statystyka  &St);
void Dodaj_d(Statystyka  &St);
void Dodaj_z(Statystyka  &St);
int Suma(Statystyka  &St);
int Ile_Dobrych(Statystyka  &St);
double Procent(Statystyka  &St);
#endif // STATYSTYKA_HH
