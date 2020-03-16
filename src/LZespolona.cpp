#include "LZespolona.hh"



LZespolona Sprzezenie(LZespolona x)
{
   return  -x;
}

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
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

LZespolona operator – (LZespolona Arg)
{
    Arg.re = –Arg.re; Arg.im = –Arg.im; return Arg;
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

    Wynik.re = Skl1.re / Skl2;
    Wynik.im = Skl1.im / Skl2;
    return Wynik;
}

LZespolona  operator / (LZespolona  Skl1, LZespolona  Skl2)
{
    LZespolona  Wynik;
    Wynik = (Skl1 * Sprzezenie(Skl2)) / Modul2(Skl2);
    return Wynik;
}

