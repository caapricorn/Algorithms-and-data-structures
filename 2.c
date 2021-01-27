/* Составьте программу fibinc.c, прибавляющую единицу к натуральному числу, записанному в фибоначчиевой системе счисления. */


#include <stdio.h>
int main() {
    int d1, d2, d3;
    long i, n;
    scanf("%ld", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &d1);

        if (i > 1) {
            if (d1 == 0 && d2 == 1 && d3 == 1) {
                d1 = 1;
                d2 = 0;
                d3 = 0;
            }
            printf("%d ", d3);
        } else if (i == 0) {
            if (d1 == 0) {
                d1 = 1;
            } else {
                d1 = 0;
            }
        } else if (i == 1) {
            if (d2 == 0 && d1 == 0) {
                d1 = 1;
            }
        }
        d3 = d2;
        d2 = d1;
    }
    if (n > 2) {
        if (d2 == 1 && d3 == 1) {
            printf("%d %d %d", 0, 0, 1);
        } else {
            printf("%d %d", d3, d2);
        }
    } else {
        if (n == 1) {
            printf("%d ", d2);
            if (d2 == 0) {
                printf("%d", 1);
            }
        } else {
            if (n == 2 && d1 == d2) {
                printf("%d %d %d", 0, 0, 1);
            }
        }

    }
    return 0;
}






