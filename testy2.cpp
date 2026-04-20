#include <iostream>
#include "lista_jednokierunkowa.h"
#include "tablica_dynamiczna.h"
#include <chrono>
#include <fstream>

const int delta = 400000;
const int start = 400000;
const int end = 10000000;

int main() {
    std::fstream plik;
    plik.open( "Wyniki/Lista koniec poczatek N.csv", std::ios::trunc | std::ios::out );
    plik << "N; Dodawanie na koniec; Usuwanie z konca; Dodawanie na poczatek; Usuwanie z poczatku" << std::endl;
    ListaJednokierunkowa<int> lista;

    for (int i=0; i<start; i++) {
        lista.dodajNaKoniec(i);
    }

    for (int k = start; k <= end; k += delta) {
        std::cout << "N = " << k << std::endl;
        plik << k << "; ";

        // Dodawanie na koniec
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= 50; i++) {
            lista.dodajNaKoniec(i);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        plik << elapsed.count() << "; ";

        // Usuwanie z końca
        start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= 50; i++) {
            lista.usunZKonca();
        }
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        plik << elapsed.count() << "; ";

        // Dodawanie na początek
        start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= 50; i++) {
            lista.dodajNaPoczatek(i);
        }
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        plik << elapsed.count() << "; ";

        // Usuwanie z początku
        start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= 50; i++) {
            lista.usunZPoczatku();
        }
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        plik << elapsed.count() << std::endl;

        for (int i=1; i<=k; i++) {
            lista.usunZPoczatku();
        }

        for (int i=0; i<delta; i++) {
            lista.dodajNaKoniec(i);
        }
    }


    plik.close();

    std::cout << "######### TABLICA DYNAMICZNA ##############" << std::endl;
    // TABLICA DYNAMICZNA
    plik.open( "Wyniki/Tablica koniec poczatek N.csv", std::ios::trunc | std::ios::out );
    plik << "N; Dodawanie na koniec; Usuwanie z konca; Dodawanie na poczatek; Usuwanie z poczatku" << std::endl;
    DynamicArray<int> tablica;
    for (int i=0; i<start; i++) {
        tablica.push_back(i);
    }

    for (int k = start; k <= end; k += delta) {
        plik << k << "; ";
        std::cout << "N = " << k << std::endl;

        // Dodawanie na koniec

        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= 50; i++) {
            tablica.push_back(i);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        plik << elapsed.count() << "; ";

        // Usuwanie z końca
        start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= 50; i++) {
            tablica.pop_back();
        }
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        plik << elapsed.count() << "; ";

        // Dodawanie na początek
        start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= 50; i++) {
            tablica.push_front(i);
        }
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        plik << elapsed.count() << "; ";

        // Usuwanie z początku
        start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i <= 50; i++) {
            tablica.pop_front();
        }
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        plik << elapsed.count() << std::endl;
        

        for (int i=0; i<delta; i++) {
            tablica.push_back(i);
        }
    }

    plik.close();



}
