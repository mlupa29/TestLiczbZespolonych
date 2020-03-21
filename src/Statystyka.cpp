
#include "Statystyka.hh"


void Wypisz(Statystyka St)
{
    std::cout << "Ilosc dobrych odpowiedzi: " << St.poprawne << std::endl;
    std::cout << "Ilosc blednych odpowiedzi: " << St.bledne << std::endl;
    std::cout << "Wynik procentowy poprawnych odpowiedzi: " << St.procent << "%" << std::endl;
}
