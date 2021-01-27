/* Составьте программу kprimes.c, вычисляющую все k-простые числа, не превышающие некоторого числа n */

#include <stdio.h>
#include <math.h>
char x[7000001] = { 0 };


int main()
{
    int k, n, t,i;
    scanf("%d %d", &k, &n);
    x[2]=1;
    if (x[2] == k) printf("%d ", 2);
    for (i=3; i<(n+1);i++)
    {
        x[i] = 1;
    }

    for (i = 2; i < (sqrt(n)+1); i++)
        {
           if (x[i] == 1)
           {
               for (t = 2; i*t <= n; t++)
               {
                   x[i*t]=x[t]+1;
               }
           }
        }
    for (i=3; i<(n+1);i++) {
        if (x[i] == k)
        {
            printf("%d ", i);
        }

    }
    return 0;

}
