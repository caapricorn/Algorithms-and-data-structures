/*Составьте программу datesort.c, осуществляющую сортировку последовательности дат по возрастанию*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Date Date;

struct Date {
    int dd;
    int mm;
    int yyyy;
};

Date* ddsort(Date *src, char d, int n)
{
    int count[32] = {0};
    for (int i=0; i<n;i++)
    {
        count[src[i].dd%32]++;
        //printf("&d",count[src[i].dd%31]);
    }
    for (int i=1;i<32;i++)
    {
        count[i]+=count[i-1];
        //printf("%d", count[i]);
    }
    Date* D=(Date*)malloc((n+1)*sizeof(Date));
    for(int i=n-1;i>=0;i--)
    {
        D[--count[src[i].dd%32]]=src[i];
    }free(src);
    return(D);

}


Date* dmsort(Date *src, char d, int n)
{
    int count[13] = {0};
    for (int i=0; i<n;i++)
    {
        count[src[i].mm%13]++;
        //printf("&d",count[src[i].mm%12]);
    }
    for (int i=1;i<13;i++)
    {
        count[i]+=count[i-1];
        //printf("%d", count[i]);
    }
    Date* D=(Date*)malloc((n+1)*sizeof(Date));
    for(int i=n-1;i>=0;i--)
    {
        D[--count[src[i].mm%13]]=src[i];
    }free(src);
    return(D);
}


Date* dysort(Date *src, char d, int n)
{
    int count[61] = {0};
    for (int i=0; i<n;i++)
    {
        count[src[i].yyyy+61-2031]++;
    }
    for (int i=1;i<61;i++)
    {
        count[i]+=count[i-1];
    }
    Date* D=(Date*)malloc((n+1)*sizeof(Date));
    for(int i=n-1;i>=0;i--)
    {
        D[--count[src[i].yyyy+61-2031]]=src[i];
    }free(src);
    return(D);
}


int main(int argc, char** argv) {
    int i,n;
    scanf("%d", &n);
    Date* a=(Date*)malloc((n+1)*sizeof(Date));
    for (i=0;i<n;i++) {
        scanf("%d %d %d", &a[i].yyyy,&a[i].mm, &a[i].dd);
    }
    if (n>1) {
        a = ddsort(a, 'd', n);
        a = dmsort(a, 'm', n);
        a = dysort(a, 'y', n);
    }
    for (i=0;i<n;i++) {
        printf("%d %d %d", a[i].yyyy,a[i].mm, a[i].dd);
        printf("\n");
    }
    free(a);
    return 0;
}
