/* Составьте программу saddle.c, выполняющую поиск седлового элемента матрицы */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, i = 0, j = 0, k = 0, ij, ii;
    long a;
    scanf("%d%d", &m, &n);
    long *max = (long*)malloc(m * sizeof(long));
    long *min = (long*)malloc(n * sizeof(long));
    for (i = 0; i < m; i++){
        max[i] = -9999999999;
    }
    for (i = 0; i < n; i++){
        min[i] = 9999999999;
    }

    for (i = 0; i < m * n; i++){
        scanf("%ld", &a);
        if (a < min[i % n]) {
            min[i % n] = a;
        }
        if (a > max[i / n]) {
            max[i / n] = a;
        }
    }
    char f = 'a';
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (min[i] == max[j]) {
                if (k == 0)
                {
                    ij = j;
                    ii = i;
                    f = 'b';
                    k++;
                } else {
                    printf("%s", "none");
                    free(max);
                    free(min);
                    return 0;
                }
            }
        }
    }
    if (f == 'a') {printf("%s", "none");}
    else printf("%d %d", ij, ii);
    free(max);
    free(min);
    return 0;
}
