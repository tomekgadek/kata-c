/*
    bmi.c: FR_02_06 - BMI

    Zadanie: https://pl.spoj.com/problems/FR_02_06/

    Kompilacja oraz uruchomienie programu: gcc bmi.c && ./a.out < ./tests/bmi-tests.txt
*/
#include <stdio.h>
#include <stdlib.h>

#define BMI_OK 0
#define BMI_UP 1
#define BMI_DW -1

#define BMI_OK_TXT "wartosc prawidlowa"
#define BMI_UP_TXT "nadwaga"
#define BMI_DW_TXT "niedowaga"

#define TXT_SIZE 20

struct person {
    char name[TXT_SIZE+1];
    int height;
    int weight;

    int status;
};

float get_bmi(short int, short int);
int get_bmi_result(float);

int main(void) {
    struct person *people = NULL;
    int number_of_people = 0;

    scanf("%d", &number_of_people);
    people = (struct person *)malloc(number_of_people * sizeof(struct person));

    if(people == NULL) { 
        return 1; 
    }

    for(int i = 0; i < number_of_people; i++) {
        scanf("%s %d %d", people[i].name, &people[i].weight, &people[i].height);
        people[i].status = get_bmi_result(get_bmi(people[i].height, people[i].weight));
    }

    int bmi_status = BMI_DW;

    while(bmi_status < 2) {
        switch(bmi_status) {
            case BMI_DW: { printf("%s\n", BMI_DW_TXT); break; }
            case BMI_OK: { printf("%s\n", BMI_OK_TXT); break; }
            case BMI_UP: { printf("%s\n", BMI_UP_TXT); break; }
        }

        for(int i = 0; i < number_of_people; i++) {
            if(people[i].status == bmi_status) {
                printf("%s\n", people[i].name);
            }
        }
        bmi_status++;

        putchar('\n');
    }

    free(people);

    return 0;
}

float get_bmi(short int height, short int weight) {
    return (float)weight / (((float)height / 100.0) * ((float)height / 100.0));
}

int get_bmi_result(float bmi) {
    if(bmi < 18.5) {
        return BMI_DW;
    } else if(bmi >= 18.5 && bmi < 25.0) {
        return BMI_OK;
    }
    
    return BMI_UP;
}
