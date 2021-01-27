/* Составьте программу maxksum.c, определяющую, какие k подряд идущих элементов последовательности имеют максимальную сумму */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    long  sum = 0, sumMax;
    int n,*a, firstIndexI = 0, maxIndexI = 0, k, i, x;

    scanf("%d", &n);
    scanf("%d", &k);

    a = (int*)malloc(k * sizeof(int));
    for (i = 0; i<k ; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sumMax = sum;
    for ( i = 0 ; i < n-k; i++)
    {

        scanf("%d", &x);
        firstIndexI++;
        if ((sum + x - a[(firstIndexI-1) % k]) > sumMax)
        {
            sumMax = (sum + x - a[(firstIndexI -1)% k]);
            maxIndexI = firstIndexI;
        }
        sum = sum + x -  a[(firstIndexI-1) % k];
        a[(firstIndexI-1) % k] = x;
    }

    printf("%d", maxIndexI);
    free(a);
    return 0;
}
