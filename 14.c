/*Составьте функцию split, выполняющую разбиение строки на слова*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int split(char *s, char ***words){
    int kolslov = 0, i;
    if (s[0]!=' ') kolslov++;
    for (i = 1; s[i]!='\0'; ++i){
        if(s[i-1]==' ' && s[i]!=' ') kolslov++;
    }
    (*words) = (char**)malloc((kolslov+2)*sizeof(char*));
    int j=0, k=0, g=0,sum=0, v=0, t=0;
    for (i=0; i<kolslov; i++)
    {
        while (s[j] == ' ')
        {
            j++;
            t++;
        }
        k+=j;
        while (s[k]!=' ' && s[k] != '\0')
        {
            k++;
            g++;
        }
        sum+=t+g;
        (*words)[i]=(char*)malloc(sizeof(char)*(g+1));
        while(g>0)
        {
            (*words)[i][v]=s[sum-g];
            v++;
            g--;
        }
        (*words)[i][v]='\0';
        v=0;
        g=0;
        j=sum;
        k=0;
        t=0;

    }



    return kolslov;
}
