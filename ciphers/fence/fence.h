#ifndef FENCE_H
#define FENCE_H

/**
 * Klucz (wysokość płotka) używany w algorytmie szyfrowania.
 * Wartość musi być większa lub równa 2, aby możliwe było
 * poprawne działanie algorytmu.
 */
#define KEY 4


/**
 * Struktura reprezentuje płotek używany do szyfrowania i deszyfrowania danych.
 * 
 * Każdy znak jest przypisany do konkretnego poziomu płotka, co umożliwia 
 * zastosowanie algorytmu szyfru płotkowego.
 */
struct fence_t {

    int level;    /**< Identyfikator poziomu płotka (0, 1, ..., key - 1). */
    char letter;  /**< Znak umieszczony na danym poziomie płotka. */
};

typedef struct fence_t fen_t;

/**
 * Inicjuje płotek dla algorytmu szyfrowania.
 *
 * Funkcja tworzy tablicę struktur reprezentujących płotek, przygotowując
 * go do dalszych operacji szyfrowania lub deszyfrowania danych.
 *
 * @param data_size Rozmiar danych (liczba znaków) do zakodowania.
 * @param key Klucz (wysokość płotka) - musi być większy lub równy 2.
 * 
 * @return Wskaźnik na tablicę struktur reprezentującą płotek.
 *         Zwraca 'NULL', jeśli wystąpi błąd podczas alokacji pamięci.
 */
fen_t * create_fence(int data_size, int key);

/**
 * Koduje dane wejściowe za pomocą szyfru płotkowego.
 *
 * Funkcja przetwarza dane wejściowe, rozmieszczając je w tablicy płotka 
 * zgodnie z algorytmem szyfru płotkowego, a następnie generuje wynikowy 
 * ciąg zakodowanych znaków.
 * 
 * @param input Dane wejściowe do zakodowania (ciąg znaków).
 * @param fen Tablica struktur reprezentujących płotek - długość musi być 
 *            równa długości danych wejściowych.
 * @param key Klucz (wysokość płotka) - musi być większy lub równy 2.
 * 
 * @return Wskaźnik na ciąg znaków zakodowanych. Zwraca 'NULL', jeśli 
 *         wystąpi błąd podczas alokacji pamięci.
 */
char * encode(char input[], fen_t fen[], int key);

/**
 * Dekoduje dane wejściowe za pomocą szyfru płotkowego.
 *
 * Funkcja przetwarza zakodowany ciąg znaków, rozmieszczając je w tablicy 
 * płotka, a następnie odtwarza oryginalne dane wejściowe.
 * 
 * @param input Zakodowany ciąg znaków do odkodowania.
 * @param fen Tablica struktur reprezentujących płotek - długość musi być 
 *            równa długości danych wejściowych.
 * @param key Klucz (wysokość płotka) - musi być większy lub równy 2.
 * 
 * @return Wskaźnik na ciąg odkodowanych znaków. Zwraca 'NULL', jeśli wystąpi
 *         błąd podczas alokacji pamięci.
 */
char * decode(char input[], fen_t fen[], int key);

#endif // FENCE_H
