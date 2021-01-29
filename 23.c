/*Составьте программу quicksort.c, осуществляющую сортировку массива целых чисел в порядке возрастания*/

#include <stdlib.h>
#include <stdio.h>


int *array;

int partition(int low, int high, int* P)
{
    int buffer;
    int i=low;
    int j=low;
    while (j<high)
    {
        if (P[j]<P[high])
        {
            buffer = P[j];
            P[j]=P[i];
            P[i]=buffer;
            i++;
        }
        j++;
    }
    buffer=P[i];
    P[i]=P[high];
    P[high]=buffer;
    return i;
}
int m;
int selectsort(int n, int* P)
{
    int j=n-1, k, i, buffer;
    while(j>0)
    {
        k=j;
        i=j-1;
        while (i>=0)
        {
            if (P[k]<P[i])
            {
                k=i;
            }
            i--;
        }
        buffer=P[j];
        P[j]=P[k];
        P[k]=buffer;
        j--;

    }
    return *P;
}
void quick(int low, int high, int* P)
{
    int q;
    while (low<high)
    {


        if (high - low + 1 < m)
        {
            selectsort(high-low+1,P);        }
        q=partition(low, high, P);
        if (q<(high+low)/2) {
            quick(low, q - 1, P);
            low++;
        }
        else {
            quick(q + 1, high, P);
            high--;
        }
    }
}





int main(int argc, char **argv)
{
    int i, n;
    scanf("%d", &n);
    scanf("%d", &m);
    array = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);

    quick(0, n-1, array);
    for (i=0;i<n;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}
