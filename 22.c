/*Составьте программу mergesort.c, осуществляющую сортировку массива целых чисел в порядке возрастания модуля числа*/

#include <stdlib.h>
#include <stdio.h>


int *array, *T;

//int 
void Merge(int k,int l,int m, int* P)
{
    T = (int*)malloc((m-k+1) * sizeof(int));
    int i=k;
    int j=l+1;
    int h=0;
    while (h<m-k+1)
    {
        if (j<=m && (i == l+1 || abs(P[j]) < abs(P[i]) ))
        {
            T[h-k]=P[j];
            j++;
        } else
        {
            T[h-k]=P[i];
            i++;
        }
        h++;

    }
    int q=0;
    for (int d=k;d<=m;d++)
    {
        if (q<h)
        {
        P[d]=T[q-k];
        q++;}
    }
    free(T);
    // return *P;
}

void IS(int, int*);

//int 
void MSR(int low, int high,int* P)
{
    if (low< high)
    {
        int med = (low+high)/2;

        if (med-low+1 <= 4)
            IS(med-low+1, P + low);
        else
            MSR(low, med, P);

        if (high-(med+1)+1 <= 4)
            IS(high-(med+1)+1, P + (med+1));
        else
            MSR(med+1, high, P);

        Merge(low, med, high, P);
    }

    // return *P;
}

// int 
void IS (int n, int* a)
{
    int i=1, elem, loc;
    while (i<n)
    {
        elem=a[i];
        loc=i-1;
        while (loc>=0 && abs(a[loc]) > abs(elem) )
        {
            a[loc+1]=a[loc];
            loc--;
        }
        a[loc+1]=elem;
        i++;
    }
    // return *a;
}

int main(int argc, char **argv)
{
    int i, n;
    scanf("%d", &n);

    array = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) 
        scanf("%d", &array[i]);

    MSR(0, n-1, array);
    // if (n>4) MSR(0, n-1, array);
    // else IS(n,array);

    for (i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}
