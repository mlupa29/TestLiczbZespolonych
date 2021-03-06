#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"
using namespace std;




int main(int argc, char** argv)
{



    if (argc < 2)
    {
        cout << endl;
        cout << " Brak opcji okreslajacej rodzaj testu." << endl;
        cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
        cout << endl;
        return 1;
    }


    BazaTestu   BazaT = { nullptr, 0, 0 };

    if (InicjalizujTest(&BazaT, argv[1]) == false)
    {
        cerr << " Inicjalizacja testu nie powiodla sie." << endl;
        return 1;
    }



    cout << endl;
    cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
    cout << endl;

    WyrazenieZesp   WyrZ_PytanieTestowe;
    LZespolona wynik;
    Statystyka stat = { 0,0,0 };
    while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
    {

        for (int i = 0; i < 3; )
        {
            //dziala mi na win cmd z cin.sync i clear a dla ignore w panamint nie wyswietla pytan
            cin.ignore();
            //cin.sync();
            //cin.clear();
            std::cout << ":? Podaj wynik operacji:" << WyrZ_PytanieTestowe << "=" << endl;
            std::cout << "Twoja odpowiedz: ";
            std::cin >> wynik;
            if (cin.bad())
            {

                i++;
                if (i < 2)
                    std::cout << "Blad zapisu liczby zespolonej. Sprobuj jeszcze raz." << endl;
            }
            else
            {
                break;
            }
            //dziala mi na win cmd z cin.sync i clear a dla ignore w panamint nie wyswietla pytan
            cin.ignore();
           // cin.sync();
           // cin.clear();
        }
        if (wynik == Oblicz(WyrZ_PytanieTestowe))
        {
            std::cout << ":) Odpowiedz poprawna" << endl;
            Dodaj_d(stat);
        }
        else
        {
            std::cout << ":( Blad. Prawidlowym wynikiem jest: " << Oblicz(WyrZ_PytanieTestowe) << endl;
            Dodaj_z(stat);
        }

    }


    cout << endl;
    cout << " Koniec testu" << endl;
    cout << endl;
    cout << "Ilosc dobrych odpowiedzi: " << Ile_Dobrych(stat) << endl;
    cout << "Ilosc blednych odpowiedzi: " << Suma(stat)- Ile_Dobrych(stat) << endl;
    cout << "Wynik procentowy poprawnych odpowiedzi: " << Procent(stat) << "%" <<endl;
    Zeruj(stat);
   // Wypisz(stat);
}
