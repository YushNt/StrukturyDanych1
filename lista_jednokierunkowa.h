#pragma once
#include <iostream>


template <typename T>
class ListaJednokierunkowa {
    struct Wezel {
        T dane;
        Wezel* nastepny;
        Wezel(const T& d) : dane(d), nastepny(nullptr) {}
    };

    Wezel* head;
    Wezel* tail;
    int rozmiar;

public:
    ListaJednokierunkowa() : head(nullptr), tail(nullptr), rozmiar(0) {}

    ~ListaJednokierunkowa() {
        Wezel* aktualny = head;
        while (aktualny != nullptr) {
            Wezel* temp = aktualny;
            aktualny = aktualny->nastepny;
            delete temp;
        }
    }

    void dodajNaPoczatek(const T& wartosc) {
        Wezel* nowy = new Wezel(wartosc);
        nowy->nastepny = head;
        head = nowy;
        if (tail == nullptr) {
            tail = nowy;
        }
        rozmiar++;
    }

    void dodajNaKoniec(const T& wartosc) {
        Wezel* nowy = new Wezel(wartosc);
        if (tail == nullptr) {
            head = tail = nowy;
        }
        else {
            tail->nastepny = nowy;
            tail = nowy;
        }
        rozmiar++;
    }

    void dodajNaPozycji(int index, const T& wartosc) {
        if (index < 0 || index > rozmiar) {
            cout << "Nieprawidlowy indeks!" << endl;
            return;
        }
        if (index == 0) {
            dodajNaPoczatek(wartosc);
            return;
        }
        if (index == rozmiar) {
            dodajNaKoniec(wartosc);
            return;
        }

        Wezel* nowy = new Wezel(wartosc);
        Wezel* aktualny = head;

        for (int i = 0; i < index - 1; i++) {
            aktualny = aktualny->nastepny;
        }

        nowy->nastepny = aktualny->nastepny;
        aktualny->nastepny = nowy;
        rozmiar++;
    }

    void usunZPoczatku() {
        if (head == nullptr) {
            cout << "Lista jest pusta!" << endl;
            return;
        }

        Wezel* temp = head;
        head = head->nastepny;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
        rozmiar--;
    }

    void usunZKonca() {
        if (head == nullptr) {
            cout << "Lista jest pusta!" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Wezel* aktualny = head;
            while (aktualny->nastepny != tail) {
                aktualny = aktualny->nastepny;
            }

            delete tail;
            tail = aktualny;
            tail->nastepny = nullptr;
        }

        rozmiar--;
    }

    void usunZPozycji(int index) {
        if (index < 0 || index >= rozmiar) {
            cout << "Nieprawidlowy indeks!" << endl;
            return;
        }

        if (index == 0) {
            usunZPoczatku();
            return;
        }

        if (index == rozmiar - 1) {
            usunZKonca();
            return;
        }

        Wezel* aktualny = head;

        for (int i = 0; i < index - 1; i++) {
            aktualny = aktualny->nastepny;
        }

        Wezel* temp = aktualny->nastepny;
        aktualny->nastepny = temp->nastepny;

        delete temp;
        rozmiar--;
    }

    int wyszukaj(const T& wartosc) const {
        Wezel* aktualny = head;
        int index = 0;

        while (aktualny != nullptr) {
            if (aktualny->dane == wartosc) {
                return index;
            }
            aktualny = aktualny->nastepny;
            index++;
        }

        return -1;
    }

    void wyswietl() const {
        if (head == nullptr) {
            std::cout << "Lista jest pusta!" << std::endl;
            return;
        }

        std::cout << "Elementy: ";
        Wezel* aktualny = head;

        while (aktualny != nullptr) {
            std::cout << aktualny->dane;
            if (aktualny->nastepny != nullptr) std::cout << ", ";
            aktualny = aktualny->nastepny;
        }
        cout << endl;
    }

    T& operator[](int index) {
        if (index < 0 || index >= rozmiar) {
            std::cout << "Blad: Indeks poza zakresem! Zwrocono wartosc awaryjna -1." << std::endl;
            static T wartosc_awaryjna = T(-1);
            return wartosc_awaryjna;
        }
        
        Wezel* aktualny = head;
        for (int i = 0; i < index; i++) {
            aktualny = aktualny->nastepny;
        }
        return aktualny->dane;
    }

    int zwroc_rozmiar() const {
        return rozmiar;
    }
};
