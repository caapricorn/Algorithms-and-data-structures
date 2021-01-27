/* Составьте программу commonletters.c, вычисляющую общие буквы двух строк */

#include <stdio.h>

int main() {
    char c, start = 'A';
    unsigned long a = 0, b = 0, d;
    int i = 0;

    while((c=getchar())!=' ')
    {
        a |= 1UL << (c - start);
    }

    while((c=getchar())!='\n')
    {
        b |= 1UL << (c - start);
    }

    a &= b;
    b = 1;
    while (a!=0) {
        d = b & a;
        a = a >> 1;
        if (d == 1) {
            printf("%c", start + i);
        }
        i++;
    }
    return 0;
}
