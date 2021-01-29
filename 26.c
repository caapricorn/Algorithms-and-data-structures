/*Составьте программу prefixes.c, выполняющую поиск всех периодических префиксов заданной строки S*/

#include <stdio.h>
#include <stdlib.h>

unsigned int length (char *s) {
    int i,k;
    k =0;
    for (i=0;s[i]!='\0';i++) {
        if (s[i]!=' ')
            k+=1;
    }
    return k;
}

int* prefix(char* s)
{
    int n = length(s);
    int* pi = malloc(n * sizeof(int));
    pi[0] = 0;
    int t=0,i=1;
    while(i<n)
    {
        while(t>0 && s[t]!=s[i])
        {
            t=pi[t-1];
        }
        if (s[t] == s[i])
        {
            t++;
        }
        pi[i]=t;
        i++;
    }
    for (i=1;i<n;i++)
    {
        if(!((i+1)%(i+1-pi[i])) && ((i+1)/(i+1-pi[i])>1))
        {
            printf("%d %d\n",i+1,(i+1)/(i+1-pi[i]));
        }

    }
    free (pi);
    return 0;
}

int main(int num, char** arg) {
    prefix(arg[1]);
    return 0;
}
