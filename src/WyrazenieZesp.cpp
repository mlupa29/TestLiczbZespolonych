#include "WyrazenieZesp.hh"


/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */
void Wyswietl(LZespolona Skl1)
{
    cout << "(" << Skl1.re << showpos << Skl1.im << noshowpos << "i)";

}

void Wczytaj(LZespolona& Skl1)
{
    char tab[3];

    cin >> tab[0];
    cin >> Skl1.re;
    cin >> Skl1.im;
    cin >> tab[1];
    cin >> tab[2];

    if (tab[0] != '(' || tab[1] != 'i' || tab[2] != ')')
    {
        cin.setstate(ios_base::badbit);
    }

}
