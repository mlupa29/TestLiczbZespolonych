#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH
#include <iostream>



struct Statystyka
{
    unsigned  int poprawne;
    unsigned  int bledne;
    double procent;
};

void Wypisz(Statystyka St);
#endif // STATYSTYKA_HH
