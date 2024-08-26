/* 13L01.c: Inicjowanie lancuchow znakowych */

#include <stdio.h>

int main(void) {

    char str1[] = {
        'A',' ',
        's', 't', 'r', 'i', 'n', 'g',' ',
        'c', 'o', 'n', 's', 't', 'a', 'n', 't', '\0'
    };

    char str2[] = "Another string constant";

    char *ptr_str;
    int i;

    /* drukuje str1 */
    for(i = 0; str1[i]; i++)
        printf("%c", str1[i]);
    printf("\n");

    /* drukuje str2 */
    for(i = 0; str2[i]; i++)
        printf("%c", str2[i]);
    printf("\n");

    /* przypisanie lancuch do wskaznika */
    ptr_str = "Assign a string to pointer";
    for(i = 0; *ptr_str; i++)
        printf("%c",*ptr_str++);
    printf("\n");

	return 0;
}
