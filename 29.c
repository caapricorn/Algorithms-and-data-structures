/*Составьте программу rangemax.c, выполняющую поиск максимального элемента на различных интервалах последовательности целых чисел, которая время от времени изменяется*/

#include <stdlib.h>
#include <stdio.h>

#define INF 1000000001 // предпологаем, что чисел больше такого не будет.

int TREE_REAL_DATA = 0;

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })



int *tree_data = NULL;


int __tree_find_max(int p, int l, int r, int a, int b) {
    if (b < l || r < a) return -INF;
    if (a <= l && r <= b) return tree_data[p];
    int r1 = __tree_find_max(p * 2, l, (l + r) / 2, a, b); // опрос левого предка
    int r2 = __tree_find_max(p * 2 + 1, (l + r) / 2 + 1, r, a, b); // опрос правого предка
    return max(r1, r2); // нахождение большего из левого и правого поддеревьев
}

// более юзабильная оболочка для функции выше.
int tree_find_max(int a, int b) {
    return __tree_find_max(1, 0, TREE_REAL_DATA - 1, a, b);
}

// обновление элемента № р.
void tree_update(int p, int x) {
    p += TREE_REAL_DATA; // преобразование позиции p к позиции в самом нижнем массве,
// в котором реально находится массив со значениями.
    tree_data[p] = x;
    for (p /= 2; p; p /= 2) {
        if (tree_data[p * 2] > tree_data[p * 2 + 1])
            tree_data[p] = tree_data[p * 2];
        else tree_data[p] = tree_data[p * 2 + 1];
    }
}

// простейшая инициализация - установка всех значений в -INF
void tree_init() {
    for (int i = 0; i < TREE_REAL_DATA * 2; i++)
        tree_data[i] = -INF;
}





int main()
{
    int n, m, x;
    scanf("%d", &n);

    TREE_REAL_DATA = 2;
    while (TREE_REAL_DATA < n)
        TREE_REAL_DATA *= 2;
    tree_data = (int*)malloc((4*n) * sizeof(int));
    tree_init();
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        tree_update(i, x);
    }
    for (int i = 0; i < 4*n; i++)
    {
        //printf("%d ", tree_data[i]);
    }
    //printf("\n");

    scanf("%d", &m);
    char s[10];
    for (int i=0;i<m;i++)
    {
        int l, r;
        scanf("%s%d%d", s, &l, &r);

        if (s[0] == 'M')
            printf("%d\n", tree_find_max(l, r));
        else
            tree_update(l, r);

    }
    free(tree_data);
    return 0;
}
