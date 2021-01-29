/*Составьте функцию сsort, выполняющую сортировку слов в предложении методом подсчёта сравнений*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define INITIAL_SIZE 128

char *getstring()
{
    char *s;
    int flag, len = 0, size = INITIAL_SIZE;

    s = (char*)malloc(INITIAL_SIZE);
    if (s == NULL) return NULL;

    for (;;) {
        if (fgets(s+len, size-len, stdin) == NULL) {
            free(s);
            return NULL;
        }

        len += (int)strlen(s+len);
        if (s[len-1] == '\n') break;

        char *new_s = (char*)malloc(size *= 2);
        if (new_s == NULL) {
            free(s);
            return NULL;
        }

        memcpy(new_s, s, len);
        free(s);
        s = new_s;
    }

    s[len-1] = 0;
    return s;
}


void csort(char *src, char *dest)
{
    int kolslov = 0, i;
    if (src[0]!=' ') kolslov++;
    for (i = 1; src[i]!='\0'; ++i){
        if(src[i-1]==' ' && src[i]!=' ') kolslov++;
    }
    int* count = malloc(kolslov * sizeof(int));
    int* width = malloc(kolslov * sizeof(int));
    count[0] = 0;
    while (src[count[0]] == ' ') count[0]++;
    int k=count[0]+1, slovo=1;
    while (src[k] != '\0')
    {
        if (src[k-1] == ' ' && src[k] !=' ') {
            count[slovo] = k;
            slovo++;
        }
        if (src[k] == ' ' && src[k-1]!= ' ')
        {
            width[slovo-1]=k-count[slovo-1];
        } else if (src[k+1] == '\0' && src[k] != ' ')
        {
            width[slovo-1]=k-count[slovo-1]+1;
        }
        k++;
    }
    int* compare[100];
    for ( i=0;i<kolslov;++i)
        compare[width[i]]++;
    int   kolslov2=kolslov;
    k=1;
    while (kolslov>0)
    {
        for (i=0;i<kolslov2;i++) {
            if (k == width[i]) {
                while (src[count[i]] != ' ' && src[count[i]] != '\0') {
                    *dest=src[count[i]];
                    count[i]++;
                    dest++;
                }
                *(dest++)=' ';
                kolslov--;
            }
        }
        k++;
    }
    *dest = 0;
    free(count);
    free(width);
}


int main()
{
    char* s = getstring(), a[200];

    csort(s, a);

    printf("%s", a);

    free(s);
}
