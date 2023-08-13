/*
	Program, który weryfikuje, czy zostało wprowadzone słowo: 'daddy'.
	Jeżeli użytkownik wprowadzi takie słowo to program powinien zakonczyć swoje działanie.
*/

#include <stdio.h>
#include <string.h>

int main(void) {

	char word[] = "*****";

	printf("Wprowadzaj slowa, a ja sprwdze czy zawieraja wyraz 'daddy': \n");

	int index = 0;
	while(strcmp(word, "daddy") != 0) {

		for(int index = 0; index < strlen(word); ++index) {
			scanf("%c", &word[index]);

			if(word[index] == '\n') {
				break;
			}
		}
	}

	printf("End... \n");

	return 0;
}
