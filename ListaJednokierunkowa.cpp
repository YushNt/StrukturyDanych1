#include <iostream>
#include "lista_jednokierunkowa.h"
using namespace std;



int main() {

    ListaJednokierunkowa<int> lista;

    while (1)
    {
        cout << "----- Wybierz operacje Listy Jednokierunkowej: -----" << endl;
        cout << "1 - Dodaj na poczatek" << endl;
        cout << "2 - Dodaj na koniec" << endl;
        cout << "3 - Dodaj na pozycji" << endl;
        cout << "4 - Usun z poczatku" << endl;
        cout << "5 - Usun z konca" << endl;
        cout << "6 - Usun z pozycji" << endl;
        cout << "7 - Wyszukaj" << endl;
        cout << "8 - Wyswietl cala liste" << endl;
        cout << "0 - Wyjscie" << endl;

        int wybor;
        cin >> wybor;
        int wartosc, index;
        switch (wybor) {
        case 1:
            cout << "Podaj wartosc do dodania na poczatek: ";
            cin >> wartosc;
            lista.dodajNaPoczatek(wartosc);
            break;
        case 2:
            cout << "Podaj wartosc do dodania na koniec: ";
            cin >> wartosc;
            lista.dodajNaKoniec(wartosc);
            break;
        case 3:
            cout << "Podaj wartosc do dodania: ";
            cin >> wartosc;
            cout << "Podaj indeks do dodania: ";
            cin >> index;
            lista.dodajNaPozycji(index, wartosc);
            break;
        case 4:
            lista.usunZPoczatku();
            break;
        case 5:
            lista.usunZKonca();
            break;
        case 6:
            cout << "Podaj indeks do usuniecia: ";
            cin >> index;
            lista.usunZPozycji(index);
            break;
        case 7:
            cout << "Podaj wartosc do wyszukania: ";
            cin >> wartosc;
            index = lista.wyszukaj(wartosc);
            if (index != -1) {
                cout << "Wartosc znaleziona na indeksie: " << index << endl;
            }
            else {
                cout << "Wartosc nie znaleziona!" << endl;
            }
            break;
        case 8:
            lista.wyswietl();
            break;
        case 0:
            cout << "Koniec programu." << endl;
            return 0;
        default:
            cout << "Nierozpoznano operacji" << endl;
            break;
        }
        cout << endl;
    }

    



    return 0;
}