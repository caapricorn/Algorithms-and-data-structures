/*Составьте программу maxprod.c, выполняющую поиск отрезка последовательности простых дробей {vi}n-1
  0, на котором произведение дробей максимально*/
  
  #include <stdlib.h>
#include <stdio.h>


double log(double x)
{
    if (x < 0.00001)
    {
        //printf("%lf --> %d\n", x, -7);
        return -200000;
    }
    if (x>1.5) return -log(1/x);
    double s = 0, a = x-1;
    for (int j = 1; j < 300; ++j)
    {
        s += a / j;
        a *= -(x-1);
        if (a > -0.00001 && a < 0.00001)
            break;
    }
    //printf("%lf --> %lf\n", x, s);
    return s;
}


int main() {
    int n;
    // float a, c;
    // char b;
    scanf("%d", &n);
    double *x = (double*)malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++)
    {
        // scanf("%f%c%f", &a, &b, &c);
        int a, b, j = 0;
        char buf[1024];
        scanf("%s", buf);
        while (buf[j] != '/') ++j;
        buf[j] = 0;
        sscanf(buf, "%d", &a);
        sscanf(buf + (j+1), "%d", &b);
        x[i] = log(1.0*a/b);
        // x[j] = log(a / c);
    }

    int
            ans_l = 0,
            ans_r = 0,
            min_pos = -1
    ;
    double P = 0,
            ans = x[0],
            min_P = 0
    ;
    for (int r = 0; r < n; ++r)
    {
        P += x[r];

        double cur = P - min_P;
        if (cur > ans+0.00002)
        {
            ans = cur;
            ans_l = min_pos + 1;
            ans_r = r;
        }

        if (P < min_P-0.00002)
        {
            min_P = P;
            min_pos = r;
        }
    }
    printf("%d %d\n", ans_l, ans_r);
    free(x);
    return 0;}




