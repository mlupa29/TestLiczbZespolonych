#include "LZespolona.hh"



//funkcja wyswietlajaca liczbe zespolona
void Wyswietl(LZespolona Skl1)
{
    cout << "(" << Skl1.re << showpos << Skl1.im << noshowpos << "i)";

}
//funkcja wczytujaca liczbe zespolona
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
        //sprawdzenie bledu zapisu podczas wejscia
        cin.setstate(ios_base::badbit);
    }

}

//funkcja wyswietlajaca liczbe zespolona
ostream& operator << (ostream& wyj, LZespolona Skl1)
{
    wyj << "(" << Skl1.re << showpos << Skl1.im << noshowpos << "i)";
    return wyj;

}


/*Fukcja porownania liczb zespolonych*/
bool operator == (LZespolona Skl1, LZespolona Skl2)
{
/*zastosowanie if-a ktory ma zabobiegaac bledowi przyblizenia*/
    if (abs(Skl1.im - Skl2.im) < 0.1 && abs(Skl1.re - Skl2.re) < 0.1)
        return true;

    return false;


}

//funkcja wczytujaca od uzytkownika liczbe zespolona i sprawdzajaca jej poprawnosc wpisania
istream& operator >> (istream& wej, LZespolona& Skl1)
{
    char tab[3];

    wej >> tab[0];
    wej >> Skl1.re;
    wej >> Skl1.im;
    wej >> tab[1];
    wej >> tab[2];
    //warunki aby liczba zespolona spelniala warunki podane w zadaniu
    if (tab[0] != '(' || tab[1] != 'i' || tab[2] != ')')
    {
        //sprawdzenie bledu zapisu podczas wejscia
        wej.setstate(ios_base::badbit);
    }
    return wej;
}


void Sprzezenie(LZespolona *x)
{
    x->im = -x->im;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1, LZespolona  Skl2)
{
    LZespolona  Wynik;

    Wynik.re = Skl1.re + Skl2.re;
    Wynik.im = Skl1.im + Skl2.im;
    return Wynik;
}

LZespolona operator + (LZespolona Arg)
{
    return Arg;
}

LZespolona  operator - (LZespolona  Skl1, LZespolona  Skl2)
{
    LZespolona  Wynik;

    Wynik.re = Skl1.re - Skl2.re;
    Wynik.im = Skl1.im - Skl2.im;
    return Wynik;
}

LZespolona operator - (LZespolona Arg)
{
    Arg.re = -Arg.re; Arg.im = -Arg.im; return Arg;
}

LZespolona  operator * (LZespolona  Skl1, LZespolona  Skl2)
{
    LZespolona  Wynik;

    Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
    Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
    return Wynik;
}


double Modul2(LZespolona Skl1)
{
    return Skl1.re * Skl1.re + Skl1.im * Skl1.im;
}

LZespolona  operator / (LZespolona  Skl1, double  Skl2)
{
    LZespolona  Wynik;
    assert(Skl2 != 0);
    Wynik.re = Skl1.re / Skl2;
    Wynik.im = Skl1.im / Skl2;
    return Wynik;
}

LZespolona  operator / (LZespolona  Skl1, LZespolona  Skl2)
{
    LZespolona  Wynik;
    assert(Modul2(Skl2) != 0);
    Wynik = (Skl1 * Sprzezenie(Skl2)) / Modul2(Skl2);
    return Wynik;
}

