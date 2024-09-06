/* lnk_list.c: Funkcje manipulujace lista */

#include <stdio.h>
#include <stdlib.h>
#include "lnk_list.h"           /* Plik naglowkowy */

static NODE *head_ptr = NULL;   /* inicjujemy jako pusty wskaznik */

/* interfejs dla funkcji main() */
void main_interface(int ch) {

    switch(ch) {
        case 'a':
            list_node_add();
            break;
        case 'd':
            if(!list_node_delete())
                list_node_print();
            break;
        case 'p':
            list_node_print();
            break;
        default:
            break;
    }
}

NODE *list_node_create(void) {
    NODE *ptr;
    
    if((ptr = (NODE *)malloc(sizeof(NODE))) == NULL)
        ErrorExit("malloc() failed \n");
    
    ptr->next_ptr = NULL;
    ptr->id = 0;

    return ptr;
}

void list_node_add(void) {

    NODE *new_ptr, *ptr;
    
    new_ptr = list_node_create();
    printf("Wpisz imie i numer ID studenta:\n");
    scanf("%s%ld", new_ptr->name, &new_ptr->id);
    
    if(head_ptr == NULL) {

        head_ptr = new_ptr;
    } else {

        for(ptr = head_ptr; ptr->next_ptr != NULL; ptr = ptr->next_ptr);
        
        ptr->next_ptr = new_ptr;
    }
}

int list_node_delete(void) {

    NODE *ptr, *ptr_saved;
    unsigned long id;
    int deleted = 0;
    int reval = 0;

    if(head_ptr == NULL) {

        printf("Sorry, nie mam czego usuwac. \n");
        reval = 1;
    } else {

        printf("Podaj numer ID studenta: ");
        scanf("%ld", &id);
            
        if(head_ptr->id == id) {
            ptr_saved = head_ptr->next_ptr;
            free(head_ptr);
            head_ptr = ptr_saved;
            if(head_ptr == NULL) {

                printf("Wszystkie elementy z listy zostaly usuniete. \n");
                reval = 1;
            }
        } else {

            for(ptr = head_ptr; ptr->next_ptr != NULL; ptr = ptr->next_ptr) {
                
                if(ptr->next_ptr->id == id) {

                    ptr_saved=ptr->next_ptr->next_ptr;
                    free(ptr->next_ptr);
                    ptr->next_ptr=ptr_saved;
                    deleted = 1;
                    break;
                }
            } 
            
            if(!deleted) {

                printf("Nie moge odszukac takiego numeru ID studenta. \n");
            }
        }
    }
    
    return reval;
}

void list_node_print(void) {

    NODE *ptr;

    if(head_ptr==NULL) {
    
        printf("Nie ma nic do wyswietlenia, niestety. \n");
    } else {

        printf("Zawartosc listy: \n");
        for(ptr = head_ptr; ptr->next_ptr != NULL; ptr = ptr->next_ptr) {

            printf("%s:%ld->", ptr->name, ptr->id);
        } 
        
        printf("%s:%ld->|", ptr->name, ptr->id);
        printf("\n");
    }
}

void list_node_free(void) {

    NODE *ptr, *ptr_saved;

    for(ptr = head_ptr; ptr != NULL; ) {

        ptr_saved = ptr->next_ptr;
        free(ptr);
        ptr = ptr_saved;
    }

    free(ptr);
}

void ErrorExit(char *str) {

    printf("%s \n", str);
    exit(1);
}
