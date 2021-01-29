/*Составьте программу kmpall.c, осуществляющую поиск всех вхождений подстроки S в строку T*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* kmpall(char* S,char* T)
{
    int ns= strlen(S), nt = strlen(T);

    int* pi = malloc(ns * sizeof(int));
    pi[0] = 0;
    int t=0,i=1;
    while(i<ns)
    {
        while(t>0 && S[t]!=S[i])
        {
            t=pi[t-1];
        }
        if (S[t] == S[i])
        {
            t++;
        }
        pi[i]=t;
        i++;
    }

    int q=0,k=0;
    while(k<nt)
    {
        while(q>0 && S[q]!=T[k])
        {
            q=pi[q-1];
        }
        if (S[q] == T[k])
        {
            q++;
        }
        if (q == ns)
        {
            k=k-ns+1;
            printf("%d ",k);
            k=k+ns-1;
        }
        k++;
    }


    free (pi);
    return 0 ;
}


int main(int num, char** arg) {
    kmpall(arg[1],arg[2]);
    return 0;
}
