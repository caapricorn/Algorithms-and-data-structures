/* Составьте программу pderive.c, вычисляющую значение k-той
 производной полинома в заданной точке x0 */


#include <stdio.h>
#include <math.h>
int main (int argc, char **argv)
{
        long k, i, j, c, a, l, x0, n;
        long f, b;
        scanf("%ld%ld%ld", &n, &k, &x0);
        b=0;
        a=n;
        c=n;
        f=1;
        l=powl(x0,n-k+1);
        for (i = 0; i <= (a-k); i++)
        {
                scanf("%ld", &f);
                for (j=0; j<k; j++)
                {
                        f*=c;
                        c--;
                }
                b += f*(l/x0);
                l/=x0;
                n--;
                c=n;
        }

        printf("%ld ", b);

        return 0;
}
