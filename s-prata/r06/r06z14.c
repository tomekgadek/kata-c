/*
    r06z14.c: Jim Szczęściarz

    14. Jim Szczęsciarz wygrał milion dolarów, które ulokował na rachunku 
    bankowym o oprocentowaniu 8% rocznie. Ostatniego dnia każdego roku Jim 
    wypłaca 100 000 dolarów. Napisz program, który oblicza, ile lat 
    upłynie, zanim Jim całkowicie opróżni swoje konto.  
*/

#include <stdio.h>

int main(void) {

    double jim_account_balance = 1000000.0; // 1mln $
    double jim_account_rate = 0.08;         // 8%
    double withdraw = 100000.0;

    int years = 0;

    while(jim_account_balance - withdraw >= 0) {

        years++;

        /*
            Jim wypłaca środki zaraz przed końcem umowy, ponieważ mamy 
            oprocentowanie w skali roku. Kapitalizacja będzie wyliczana
            na podstawie pomniejszonego salda.
        */
        jim_account_balance -= withdraw;

        jim_account_balance += (jim_account_balance * jim_account_rate);
        
    }

    printf("Jim calkowicie oprozni swoje konto po %d latach. \n", years);
    printf("Stan konta: %.2lf \n", jim_account_balance);

    return 0;
}
