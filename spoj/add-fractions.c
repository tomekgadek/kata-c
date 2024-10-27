/*
    add-fractions.c: FR_02_06 - BMI

    Zadanie: https://pl.spoj.com/problems/FR_01_02/

    Kompilacja oraz uruchomienie programu: gcc add-fractions.c && ./a.out < ./tests/add-fractions-tests.txt
*/
#include <stdio.h>

typedef unsigned long long int fraction_type;

fraction_type GCD(fraction_type, fraction_type); // NWD
fraction_type LCM(fraction_type, fraction_type); // NWW

int main(void) {
    fraction_type numerator1, numerator2, denominator1, denominator2;

    scanf("%llu%*c%llu", &numerator1, &denominator1);
    scanf("%llu%*c%llu", &numerator2, &denominator2);

    fraction_type denominator_without_gcd = LCM(denominator1, denominator2);
    fraction_type numerator_without_gcd = 
        denominator_without_gcd / denominator1*numerator1 + denominator_without_gcd / denominator2 * numerator2;

    fraction_type common_gcd = GCD(numerator_without_gcd, denominator_without_gcd);

    fraction_type numerator_with_gcd = numerator_without_gcd / common_gcd;
    fraction_type denominator_with_gcd = denominator_without_gcd / common_gcd;

    printf("%llu/%llu + %llu/%llu = %llu/%llu\n", 
        numerator1, denominator1, numerator2, denominator2, numerator_with_gcd, denominator_with_gcd);

    return 0;
}

fraction_type GCD(fraction_type digit_a, fraction_type digit_b) {
    fraction_type swap_buffer;

    while(digit_b != 0) {
        swap_buffer = digit_b;
        digit_b = digit_a % digit_b;
        digit_a = swap_buffer;
    }

    return digit_a;
}
 
fraction_type LCM(fraction_type digit_a, fraction_type digit_b) {
    return digit_a / GCD(digit_a, digit_b) * digit_b;
}
