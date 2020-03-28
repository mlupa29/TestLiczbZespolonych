
#include "Statystyka.hh"


void Wypisz(Statystyka St)
{
    std::cout << "Ilosc dobrych odpowiedzi: " << St.poprawne << std::endl;
    std::cout << "Ilosc blednych odpowiedzi: " << St.bledne << std::endl;
    std::cout << "Wynik procentowy poprawnych odpowiedzi: " << St.procent << "%" << std::endl;
}

void Dodaj_d(Statystyka &St)
{
    St.poprawne++;
}

void Dodaj_z(Statystyka &St)
{
    St.bledne++;
}

int Ile_Dobrych(Statystyka &St)
{
    return St.poprawne;

}


int Suma(Statystyka &St)
{
    return St.poprawne + St.bledne;
}

double Procent(Statystyka &St)
{
    St.procent = (St.poprawne * 100) / (St.poprawne + St.bledne);
    return St.procent;
}
void Zeruj(Statystyka &St)
{
    St.poprawne = 0;
    St.bledne = 0;
    St.procent = 0;
}