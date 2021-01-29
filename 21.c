/*Составьте функцию hsort, выполняющую пирамидальную сортировку произвольного массива*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmpsba(char *a, char *b)
{
    /* compare two strings by number of letter "a" in them */
    char *ptoa;  //pointer to 'a' in string
    int naa = 0; //number of letter "a" in string, pointed by a
    int nab = 0; //number of letter "a" in string, pointed by b
    ptoa = strchr(a,'a');
    while(ptoa) {
        ++naa;
        ptoa = strchr(++ptoa,'a');
    }
    ptoa = strchr(b,'a');
    while(ptoa) {
        ++nab;
        ptoa = strchr(++ptoa,'a');
    }
    if(naa == nab) return 0;
    return naa < nab ? -1 : 1 ;
}
void swap(char **a, char **b)
{
    //Exchange two strings pointed by a and b
    char *t;
    t = *a;
    *a = *b;
    *b = t;
}
void mkheap(char **arr, int n, int i, int (*cmp)( char *, char * ))
{
// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи
    int l,r;
    int largest = i;
// Инициализируем наибольший элемент как корень
    l = 2*i + 1; // левый = 2*i + 1
    r = 2*i + 2; // правый = 2*i + 2
// Если левый дочерний элемент больше корня
    if( l < n ) if((*cmp)(arr[l],arr[largest]) > 0) largest = l;
    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if( r < n ) if((*cmp)(arr[r],arr[largest]) > 0) largest = r;
    // Если  наибольший элемент не корень
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        mkheap(arr, n, largest, (*cmp));
    }
}

void hsort(char **base, size_t nel, size_t width, int (*cmp)( char *, char * ))
// Пирамидальная сортировка массива из строк по количеству букв "а" в них
{
    // make max-heap first
    for(int i = nel/2 - 1; i >= 0; i--) mkheap(base,nel,i,(*cmp));
    // Один за другим извлекаем элементы из кучи
    for (int i=nel-1; i>0; i--)
    {
        // Перемещаем текущий корень в конец
        swap(&base[0], &base[i]);

        // вызываем процедуру переделывания уменьшенной кучи
        mkheap(base, i, 0, (*cmp));
    }
}

int main()
{
    int ns; //number of strings, read it from stdin
    int lstr, mlstr; // length of string, maximum length of strings in array
    scanf("%d", &ns);
    //allocate memory for pointers to pointers to strings
    char** base = malloc(ns * sizeof(char*));
    if( base == NULL ) {printf("Can't allocate memory!\n"); exit(EXIT_FAILURE);}
    mlstr = 0;
    for (int i = 0; i < ns; i++)
    {
        base[i] = malloc(100 * sizeof(char)); //allocate memory for string, not more whan 100 letters!
        if( base[i] == NULL ) {printf("Can't allocate memory for strings!\n"); exit(EXIT_FAILURE);}
        scanf(" %s", base[i]);
        lstr = strlen(base[i]);
        if(lstr > 100) {printf("String too long!\n"); exit(EXIT_FAILURE);}
        if(lstr > mlstr) mlstr = lstr;
    }
    //Let's try sort strings according to number of letter "a" in it
    hsort(base, ns, mlstr*sizeof(char*), cmpsba);
    for (int i = 0; i < ns; i++)
    {
        printf("%s\n", base[i]);
        free(base[i]);
    }
    free(base);
}
