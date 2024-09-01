/* 18L05.c: Pobranie parametrow z wiersza polecen SysOp */

#include <stdio.h>

int main(int argc, char *argv[]) {
    int i;

    printf("Argument argc ma wartosc: %d\n", argc);
    printf("%d parametrow przekazano do funkcji main(): \n", argc);

    printf("Pierwszy parametr z wiersza polecen to: %s\n", argv[0]);
    printf("Pozostale parametry z wiersza polecen: \n");
    
    for(i = 1; i < argc; i++)
        printf("%s\n", argv[i]);
    printf("\n");

    return 0;
}
