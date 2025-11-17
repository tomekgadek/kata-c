#ifndef CAESAR_H
#define CAESAR_H

// Klucz szyfru Cezara, używany do przesunięcia znaków w ASCII
#define KEY 4

/**
 * Funkcja kodująca tekst za pomocą szyfru Cezara.
 * 
 * @param input Tekst wejściowy do zakodowania.
 * @param key   Klucz przesunięcia znaków.
 * @return Zakodowany tekst.
 */
char * encode(char input[], int key);

/**
 * Funkcja dekodująca tekst zakodowany szyfrem Cezara.
 * 
 * @param input Tekst wejściowy do odkodowania.
 * @param key   Klucz przesunięcia znaków.
 * @return Odkodowany tekst.
 */
char * decode(char input[], int key);

#endif // CAESAR_H
