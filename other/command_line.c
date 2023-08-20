/*
	Program powinien realizowac nastepujace zalozenia:
	- Wybierz '1' aby wyswietlic tekst z podkresleniami.
	- Wybierz '2' aby wyswietlic tekst wspak.
	Pierwszym parametrem w lini polecen bedzie dowolny ciag znakow, a drugi
	parametr powinien zdecydowac jaka operacja bedzie wykonana na ciagu.
	wyniki powinny byc umieszcone w pliku underscore.txt lub reverse.txt w zaleznosi od wyboru
	operacji.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Funkcja otwiera plik o podanej nazwie w trybie zapisu i zwraca wskaźnik do pliku.
 * 
 * @param filename Nazwa pliku, który ma zostać otwarty do zapisu.
 * @return Wskaźnik do otwartego pliku, lub NULL w przypadku błędu otwarcia.
 */
FILE * openFileToSave(char filename[]);

/**
 * Funkcja zapisuje podany ciąg znaków wraz z podkreśleniami do pliku.
 * 
 * @param file Wskaźnik do otwartego pliku, do którego ma być zapisany ciąg znaków.
 * @param word Ciąg znaków, który ma zostać zapisany.
 * @return Wskaźnik do pliku po zapisaniu danych, lub NULL w przypadku błędu zapisu.
 */
FILE * saveDataToFileWithUnderscore(FILE * file, char * word);

/**
 * Funkcja zapisuje podany ciąg znaków w odwróconej kolejności do pliku.
 * 
 * @param file Wskaźnik do otwartego pliku, do którego ma być zapisany ciąg znaków w odwróconej kolejności.
 * @param word Ciąg znaków, który ma zostać odwrócony i zapisany.
 * @return Wskaźnik do pliku po zapisaniu danych, lub NULL w przypadku błędu zapisu.
 */
FILE * saveDataToFileWithRevert(FILE * file, char * word);

/**
 * Funkcja zamyka otwarty plik.
 * 
 * @param file Wskaźnik do otwartego pliku, który ma zostać zamknięty.
 */
void closeFile(FILE * file);

int main(int argc, char *argv[]) {

	char * files[] = {"./tmp/underscore.txt", "./tmp/reverse.txt" }; 

	if(argc != 3) {
		printf("Nipoprawne parametry. Wpisz: a.exe / a.out [string][1|2] \n");
		return 1;
	}

	FILE * file = NULL;
	
	switch(argv[2][0]) {
		case '1': {
			file = openFileToSave(files[0]);
			file = saveDataToFileWithUnderscore(file, argv[1]);
			break;
		}
		case '2': {
			file = openFileToSave(files[1]);
			file = saveDataToFileWithRevert(file, argv[1]);
			break;
		}
		default: {
			printf("Nipoprawne parametry. Wpisz: a.exe / a.out [string][1|2] \n");
		}
	}

	closeFile(file);
	
	return 0;
}

FILE * openFileToSave(char filename[]) {

	char type[] = "w";
	FILE * file = NULL;

	if((file = fopen(filename, type)) == NULL) {
		printf("Nie moge otworzyc %s ! \n", filename);
		exit(1);
	}

	return file;

}

void closeFile(FILE * file) {

	fclose(file);
}

FILE * saveDataToFileWithUnderscore(FILE * file, char * word) {

	int i = 0;

	while(word[i]) {
		if(i != 0) {
			putc('_', file);
		}
		
		putc(word[i++], file);
	}

	return file;
}

FILE * saveDataToFileWithRevert(FILE * file, char * word) {

	int size = strlen(word);
	
	while(size-- > 0) {
		putc(word[size], file);
	}

	return file;
}
