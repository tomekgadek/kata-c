# kata-c
_Kolekcja krótkich programów, struktur danych, algorytmów zaimplementowanych w języku C._

Praca z konsolą
---------------

1. Rysowanie figur geometrycznych
    * [Prostokąt](/console/print_rectangle.c),
    * [Obramowanie prostokąta](/console/print_rectangle_with_border.c),
    * [Trójkąt prostokątny](/console/print_triangle_rectangular.c),
    * [Trójkąt równoramienny](/console/print_triangle_isosceles.c).

Algorytmy i struktury danych
----------------------------

1. Wyszukiwanie:
    * [Wyszukiwanie liniowe](/algorithms/search_line.c),
    * [Wyszukiwanie binarne](/algorithms/search_binary.c).
2. Sortowanie:
    * [Sortowanie bąbelkowe](/algorithms/bubble_sort.c).
3. Listy liniowe:
    * Lista jednokierunkowa,
    * Lista dwukierunkowa.
4. [Stos](/algorithms/stack/stack.c).

Rekurencja
----------

1. [Palindrom](/recursion/palindrome.c),
2. [Silnia](/recursion/factorial.c),
3. [Zamiana liczby dziesiętnej na liczbę dwójkową](/recursion/conver_to_binary.c).

Matematyka
----------

1. [NWD - Największy wspólny dzielnik](/math/nwd.c),
2. [NWW - Najmniejsza wspólna wielokrotność](/math/nww.c),
3. [Wyszukiwanie maksimum ze zbioru liczb całkowitych](/math/max.c),
4. [Wyszukiwanie minimum ze zbioru liczb całkowitych](/math/min.c),
5. [Średnia arytmetyczna](/math/average.c),
6. [Funkcja kwadratowa](/math/quadratic_function/quadratic_function.c),
7. [Weryfikacja, czy podana liczba to liczba pierwsza](/math/prime.c).

Pozostałe
---------

01. [Porównywanie ciągów tekstowych](/other/string_compare.c),
02. [Losowanie lotto](/other/lottery.c),
03. [Program, który weryfikuje czas trwania algorytmu](/other/algorithm_duration.c),
04. [Jeżeli wpiszesz 'x' to koniec gry](/other/x_terminate_program.c),
05. [Program, który weryfikuje, czy zostało wprowadzone słowo: 'daddy'](/other/daddy.c),
06. [Program, który potrafi tworzyć tablicę i zliczać wystąpienia podanego elementu](/other/tables.c),
07. [Program, który prezentuje obsługę linii poleceń w programie](/other/command_line.c),
08. [Program odczytujący, odwracający i wyświetlający tablicę liczb z pliku](/other/tables02.c),
09. [Program wyświetlający tekst 'Matrix cie wiezi...' - motyw z filmu 'Matrix'](/other/matrix_movie.c),
10. [Program potrafi zamienić wartości pomiędzy zmiennymi bez użycia zmiennej tymczasowej](/other/swap.c),
11. [Odbicie lustrzane liczby całkowitej](/other/mirror.c).

Poznaj C w 24 godziny, Tony Zhang - gotowe listingi (PL)
--------------------------------------------------------

Godzina...

01. Od czego zacząć?
    + [01L01.c: Wprowadzenie](./c-in-24h/01H/01L01.c)
02. Piszemy pierwsze programy w języku C
    + [02L01.c: Pierwszy prosty program w C](./c-in-24h/02H/02L01.c).
03. Podstawy programowania w C
    + [03L02.c: Obliczanie sumy i drukowanie wyniku na ekranie](./c-in-24h/03H/03L02.c).
04. Typy danych i słowa kluczowe języka C
    + [04L01.c: Drukowanie znakow](./c-in-24h/04H/04L01.c),
    + [04L02.c: Zamiana wartosci numerycznej na znak](./c-in-24h/04H/04L02.c),
    + [04L03.c: Wyprowadza numery kodu znakow ASCII](./c-in-24h/04H/04L03.c),
    + [04L04.c: Operacje zmiennoprzecinkowe](./c-in-24h/04H/04L04.c).
05. Zapis i odczyt informacji - odługa standardowego Wejścia / Wyjścia
    + [05L01.c: Wczytanie znaku z wejscia poprzez wywolanie funkcji getc()](./c-in-24h/05H/05L01.c),
    + [05L02.c: Wczytywanie znaku przez funkcje getchar()](./c-in-24h/05H/05L02.c),
    + [05L03.c: Funkcja putc() wysyla znak na ekran](./c-in-24h/05H/05L03.c),
    + [05L04.c: Wyswietlanie znakow za pomoca funkcji putchar()](./c-in-24h/05H/05L04.c),
    + [05L05.c: Zamiana liczb dziesietnych na szesnastkowe](./c-in-24h/05H/05L05.c),
    + [05L06.c: Okreslenie minimalnej szerokosci pola wyjsciowego](./c-in-24h/05H/05L06.c),
    + [05L07.c: Wyrownywanie wyjscia](./c-in-24h/05H/05L07.c),
    + [05L08.c: Zastosowanie specyfikatora precyzji](./c-in-24h/05H/05L08.c).
06. Manipulowanie danymi przy pomocy operatorów
    + [06L01.c: Arytmetyczne operatory przypisania](./c-in-24h/06H/06L01.c),
    + [06L02.c: Operatory pre- oraz post-inkrementacji (dekrementacji)](./c-in-24h/06H/06L02.c),
    + [06L03.c: Zastosowanie operatorow relacji - wyniki porownan](./c-in-24h/06H/06L03.c),
    + [06L04.c: Zastosowanie operatora rzutowania typu](./c-in-24h/06H/06L04.c).
07. Pętle programowe
    + [07L01.c: Zastosowanie petli typu while](./c-in-24h/07H/07L01.c),
    + [07L02.c: Zastosowanie petli do-while](./c-in-24h/07H/07L02.c),
    + [07L03.c: Zamiana 0...15 na liczby szesnastkowe](./c-in-24h/07H/07L03.c),
    + [07L04.c: Wiele wyrazen w naglowku petli for](./c-in-24h/07H/07L04.c),
    + [07L04b.c: Wiele wyrazen w naglowku petli for - przyklad 2](./c-in-24h/07H/07L04b.c),
    + [07L04c.c: Warunek przerwania pÍtli for](./c-in-24h/07H/07L04c.c),
    + [07L06.c: Petle zagniezdzone](./c-in-24h/07H/07L06.c).
08. Zastosowanie oparetorów warunkowych i więcej o operatorach C
    + [08L01.c: Zastosowanie operatora sizeof](./c-in-24h/08H/08L01.c),
    + [08L02.c: Zastosowanie operatora iloczynu logicznego AND - &&](./c-in-24h/08H/08L02.c),
    + [08L03.c: Operatory logiczne(Suma logiczna)](./c-in-24h/08H/08L03.c),
    + [08L04.c: Zastosowanie operatora negacji logicznej !](./c-in-24h/08H/08L04.c),
    + [08L05.c: Zastosowanie operatorow bitowych](./c-in-24h/08H/08L05.c),
    + [08L06.c: Zastosoanie operatorow przesuniecia](./c-in-24h/08H/08L06.c),
    + [08L07.c: Zastosowanie operatora warunkowego ? :](./c-in-24h/08H/08L07.c).
09. Modyfikatory danych i funkcje matematyczne
    + [09L01.c: Modyfikatory signed i unsigned, format binarny](./c-in-24h/09H/09L01.c),
    + [09L02.c: Zastosowanie modyfikatorow short oraz long](./c-in-24h/09H/09L02.c),
    + [09L03.c: Uzycie specyfikatorow %hd, %ld oraz %lu](./c-in-24h/09H/09L03.c),
    + [09L04.c: Zastosowanie funkcji: sin(); cos(); tan()](./c-in-24h/09H/09L04.c),
    + [09L05.c: Uzycie funkcji pow() i sqrt()](./c-in-24h/09H/09L05.c).
10. Instrukcje sterujące przebiegiem działania programu
    + [10L01.c: Zastosowanie instrukcji if](./c-in-24h/10H/10L01.c),
    + [10L02.c: Zastosowanie if-else](./c-in-24h/10H/10L02.c),
    + [10L03.c: Zagniezdzone instrukcje if](./c-in-24h/10H/10L03.c),
    + [10L04.c: Zastosowanie instrukcji switch](./c-in-24h/10H/10L04.c),
    + [10L05.c: Zastosowanie instrukcji switch-break](./c-in-24h/10H/10L05.c),
    + [10L06.c: Przerwanie nieskonczonej petli](./c-in-24h/10H/10L06.c),
    + [10L07.c: Zastosowanie instrukcji continue](./c-in-24h/10H/10L07.c).
11. Wprowadzenie do wskaźników
    + [11L01.c: Odczytanie adresow zmiennych](./c-in-24h/11H/11L01.c),
    + [11L02.c: Deklarowanie wskaznikow i przypisywanie im wartosci](./c-in-24h/11H/11L02.c),
    + [11L03.c: Zmiana zawartosci zmiennej wskazywanej](./c-in-24h/11H/11L03.c),
    + [11L04.c: Wiecej niz jeden wskaznik wskazuje na ten sam adres](./c-in-24h/11H/11L04.c).
12. Zapamiętanie wielu danych tego samego typu - macierze
    + [12L01.c: Inicjowanie tablicy int list_int = [10] = {1, 2, 3, 4, ...10}](./c-in-24h/12H/12L01.c),
    + [12L02.c: Calkowita wielkosc tablicy w bajtac](./c-in-24h/12H/12L02.c),
    + [12L03.c: Odwolanie sie do tablicy za posrednictwem wskaznika](./c-in-24h/12H/12L03.c),
    + [12L04.c: Wydruk elementow tablicy znakowej](./c-in-24h/12H/12L04.c),
    + [12L05.c: Stop po napotkaniu znaku \0](./c-in-24h/12H/12L05.c),
    + [12L06.c: Wydruk tablicy dwuwymiarowej](./c-in-24h/12H/12L06.c),
    + [12L07.c: Inicjowanie tablic bezwymiarowych](./c-in-24h/12H/12L07.c).
13. Manipulowanie łańcuchami znakowymi
    + [13L01.c: Inicjowanie lancuchow znakowych](./c-in-24h/13H/13L01.c),
    + [13L02.c: Pomiar dlugosci lancuchow tekstowych](./c-in-24h/13H/13L02.c),
    + [13L03.c: Kopiowanie lancuchow](./c-in-24h/13H/13L03.c),
    + [13L04.c: Zastosowanie funkcji gets() i puts()](./c-in-24h/13H/13L04.c),
    + [13L05.c: Zastosowanie funkcji scanf()](./c-in-24h/13H/13L05.c).
14. Klasy zmiennych - widocznosc i lokalizacja w pamieci
    + [14L01.c: Zmienne lokalne w blokach zagniezdzonych](./c-in-24h/14H/14L01.c),
    + [14L02.c: Porownanie zakresow program scope - kontra - block scope](./c-in-24h/14H/14L02.c),
    + [14L03.c: Zastosowanie specyfikatora static zmiennej statycznej](./c-in-24h/14H/14L03.c).
15. O funkcjach w C
    + [15L01.c: Deklaracja, definicja i wywolanie funkcji](./c-in-24h/15H/15L01.c),
    + [15L02.c: Funkcja bezargumentowa, nie zwraca wartosci](./c-in-24h/15H/15L02.c),
    + [15L03.c: Obsluga zmiennej liczby argumentow](./c-in-24h/15H/15L03.c).
