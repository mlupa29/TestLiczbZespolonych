#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <cassert>
#include <cmath>
using namespace std;
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */
double Modul2(LZespolona Skl1);
LZespolona Sprzezenie(LZespolona x);

LZespolona operator + (LZespolona Arg);
LZespolona operator – (LZespolona Arg);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1, LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1, LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1, LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1, double  Skl2);

#endif
