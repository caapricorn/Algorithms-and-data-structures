/* Составьте программу rangeset.c, вычисляющую оптимальное представление множества чисел в виде набора отрезков. */

#include <stdio.h>

int main() {
    long a[2], b[2];
    long i, n;
    scanf("%ld", &n);
    scanf("%ld %ld ", &a[0], &a[1]);
    for (i = 0; i < (n - 1); i++) {
        scanf("%ld %ld", &b[0], &b[1]);
        if (b[0] < a[1] && b[1] > a[1]) {
            a[1] = b[1];
        } else {
            if (b[1]> a[1] && a[1]+1 == b[0])
            {
                a[1] = b[1];
            } else {
                 if (a[0] < b[0] && a[1] < b[1]) {
                    printf("%ld %ld ", a[0], a[1]);
                    a[0] = b[0];
                    a[1] = b[1];
                }

            }
        }
    }
    printf("%ld %ld", a[0], a[1]);
    return 0;
}
