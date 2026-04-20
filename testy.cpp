#include <iostream>
#include "lista_jednokierunkowa.h"
#include "tablica_dynamiczna.h"
#include <chrono>
#include <fstream>

const int N = 100000;

int main() {
    std::fstream plik;
    plik.open( "Wyniki/Lista od indeksu.csv", std::ios::trunc | std::ios::out );
    plik << "indeks; dodawanie indx; odczyt" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;

    ListaJednokierunkowa<int> lista2;
    for(int i = 0; i < N; i++) {
        lista2.dodajNaKoniec(i);
    }
    
    // Dodawanie na pozycji od indeksu
    for(int i = 0; i < N-50; i+= N/20) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 50; j++) {
            lista2.dodajNaPozycji(i, i);
        }
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        plik << i << "; " << elapsed.count() << "; ";

        for (int j = 0; j < 50; j++) {
            lista2.usunZPozycji(i);
        }
        
    
        // odczyt z pozycji od indeksu
        volatile int temp;
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 50; j++) {
            volatile int temp = lista2[i+j];
        }
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        plik << elapsed.count() << std::endl;
    }

    plik.close();



    // TABLICA DYNAMICZNA

    DynamicArray<int> tablica2;
    for(int i = 0; i < N; i++) {
        tablica2.push_back(i);
    }
    
    // Dodawanie na pozycji od indeksu
    plik.close();
    plik.open( "Wyniki/Tablica dodawanie od indeksu.csv", std::ios::trunc | std::ios::out );
    plik << "indeks; dodawanie indx; odczyt" << std::endl;
    for(int i = 0; i < N-50; i+= N/20) {
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 50; j++) {
            tablica2.insert(i, i);
        }
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        plik << i << "; " << elapsed.count() << "; ";

        for (int j = 0; j < 50; j++) {
            tablica2.remove(i);
        }

    
        // odczyt z pozycji od indeksu
        volatile int temp2;
        start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 50; j++) {
            volatile int temp = tablica2[i+j];
        }
        end = std::chrono::high_resolution_clock::now();
        elapsed = end - start;
        plik << elapsed.count() << std::endl;
    }

    plik.close();

}
