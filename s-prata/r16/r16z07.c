/*
    r16z07.c: Program implementujący funkcję wait()

    7. Biblioteka ANSI zawiera funkcję clock() o następującym opisie:

    ```c
    #include <time.h>
    clock_t clock (void);
    ```

    clock_t jest typem zdefiniowanym w pliku time.h. Funkcja zwraca czas 
    procesora wyrażony w jednostkach zależnych od implementacji. (Jeśli 
    czas procesora jest niedostępny lub nie może zostać wyrażony, funkcja 
    zwraca wartość -1.) Plik time.h zawiera również definicję stałej 
    CLOCKS_PER_SEC, która reprezentuje liczbę jednostek czasu procesora w 
    jednej sekundzie. Tym samym, podzielenie różnicy między dwiema wartościami 
    zwróconymi przez clock() przez CLOCKS_PER_SEC daje liczbę sekund, jakie 
    upłynęły między wywołaniami. Przekształcenie zwróconych wartości na typ 
    double przed ich podzieleniem pozwala uzyskać ułamki sekundy. Napisz 
    funkcję, która pobiera argument typu double wyrażający żądane 
    opóźnienie, a następnie wykonuje pętlę do momentu upłynięcia zadanej 
    ilości czasu. Wypróbuj ją w prostym programie.
*/

#include <stdio.h>
#include <time.h>

void wait(double seconds);

int main(void) {

    printf("Czekam 3.5 sekundy...\n");
    wait(3.5);
    printf("Koniec oczekiwania.\n");

    return 0;
}


/*
    Nie ma potrzeby wykonywać dzielenia przez CLOCKS_PER_SEC w pętli, ponieważ 
    wartość end jest już wyrażona w jednostkach zegara.
*/
void wait(double seconds) {

    clock_t start = clock();
    clock_t end = start + (clock_t)(seconds * CLOCKS_PER_SEC);

    while (clock() < end)
        ;
}
