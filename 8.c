/* Составьте программу mergeseq.c, выполняющую слияние двух последовательностей */

#include <stdio.h>
#include <stdlib.h>
int main() {
    long *x, n1, n2, i, k = 0;
    scanf("%ld ", &n1);
    x = (long*)malloc(n1 * sizeof(long));
    for (i = 0; i<n1 ; i++)
    {
        scanf("%ld", &x[i]);
    }

    scanf("%ld ", &n2);
    unsigned long k2 = n2;
    if (n2 == 0)
    {
        for (i=0; i<n1; i++)
        {
            printf("%ld ", x[i]);
        }
    }
    else if (n1 == 0)
    { long y;
        for (i=0; i<n2; i++)
        {
            scanf("%ld", &y);
            printf("%ld ", y);
        }
    }
    else { long y;
        for (i = 0; i < (n2 + n1); i++) {

            if (i > 0) {
                    if (k < n1 && x[k] <= y) {
                        printf("%ld ", x[k]);
                        k++;
                    } else if (i < (n2 + n1 -1)){
                        printf("%ld ", y);
                        --k2;
                        if (k2 > 0) {
                            scanf("%ld", &y);
                        }
                    }

            } else {
                    scanf("%ld ", &y);
                    }

        }
        while (k != n1)
            {
                printf("%ld ", x[k]);
                k++;
            }
        while (k2 != 0)
        {
            if (k2 == 1) {
            printf("%ld ", y);
            k2--;
        } else
            {
                printf("%ld ", y);
                k2--;
                scanf("%ld", &y);
            }
        }

    }
    free(x);
    return 0;
}
