/* lnk_list.h: Plik naglowkowy dla listy */

#ifndef LNK_LIST_H
#define LNK_LIST_H

#define MAX_LEN 16

struct lnk_list_struct {                /*struktura - ELEMENTY LISTY*/

    char name[MAX_LEN];                 /* imie studenta */
    unsigned long id;                   /* nr id studenta */
    struct lnk_list_struct *next_ptr;   /* wskaznik do nastepnego elementu listy */
};

typedef struct lnk_list_struct NODE;    /* struktura - ELEMENT LISTY */

NODE *list_node_create(void);
void list_node_add(void);
int list_node_delete(void);
void list_node_print(void);
void list_node_free(void);

void ErrorExit(char *);

void main_interface(int);

#endif                                  /* dla LNK_LIST_H */
