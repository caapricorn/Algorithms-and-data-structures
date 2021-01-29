/*Составьте программу rangehd.c, определяющую, является ли указанная подстрока строки гипердромом*/

#include <stdlib.h>
#include <stdio.h>

#define INF 1000000001 // предпологаем, что чисел больше такого не будет.

int TREE_REAL_DATA = 0;

int *tree_data = NULL;

    int __tree_sum(int p, int l, int r, int a, int b) {
        // printf("(%d, %d) ", a, b);
        if (b < l || r < a) return 0;
        if (a <= l && r <= b) return tree_data[p];
        int r1 = __tree_sum(p * 2, l, (l + r) / 2, a, b); // опрос левого предка
        int r2 = __tree_sum(p * 2 + 1, (l + r) / 2 + 1, r, a, b); // опрос правого предка
        return r1 ^ r2; // нахождение большего из левого и правого поддеревьев
    }

// более юзабильная оболочка для функции выше.
    int tree_check(int a, int b) {
        int s = __tree_sum(1, 0, TREE_REAL_DATA - 1, a, b);
        // printf("[%d, %d] --> %d\n", a, b, s);
        if ((b-a+1 & 1) == 0) // even
        {
            return (s == 0);
        }
        else // odd
        {
            while ((s & 1) == 0)
                s /= 2;
            return (s == 1);
        }
    }

    int letter2code(char sym)
    {
        int p = sym - 'a', code = 1;
        while (p > 0)
        {
            code = code * 2, p--;
        }
        return code;
    }
// обновление элемента № р.
    void tree_update(int p, char sym) 
    {
        p += TREE_REAL_DATA; 

        int v = letter2code(sym), w = tree_data[p], delta = v ^ w;

        tree_data[p] = v;
        for (p /= 2; p > 0; p /= 2) 
        {
            tree_data[p] ^= delta;
        }
    }

    // простейшая инициализация - установка всех значений в -INF

    void tree_init() {
        for (int i = 0; i < TREE_REAL_DATA * 2; i++)
            tree_data[i] = 0;
    }





int main()
{
    int n, m, x, j, L, K, start;
    char* s = (char*)malloc(sizeof(char) * 1000001 );

    scanf("%s", s);
    n = 0;
    while (s[n])
        n++;

    TREE_REAL_DATA = 2, L = 1;
    while (TREE_REAL_DATA < n)
        TREE_REAL_DATA *= 2, L++;
    
    tree_data = (int*)malloc((4*n) * sizeof(int));

    tree_init();

    for (int i = 0; i < n; i++)
    {
        // tree_update(i, s[i]);
        tree_data[TREE_REAL_DATA + i] = letter2code(s[i]);
    }
    start = TREE_REAL_DATA;
    for (m = 1, K = TREE_REAL_DATA / 2; m <= L; m++, K /= 2)
    {
        start -= K;
        for (int i = 0; i < K; i++)
        {
            tree_data[start + i] = tree_data[start + K + 2*i] ^ tree_data[start + K + 2*i+1];
        }
    }
    free(s);

    // for (int i = 0; i < 4*n; i++)
    // {
    //     printf("%d ", tree_data[i]);
    // }
    // printf("\n");

    // printf("----\nCommands:\n");
    scanf("%d", &m);
    char cmd[10], u[1000001];
    for (int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%s", cmd);
        scanf("%d", &l);
        scanf("%s", u);

        if (cmd[0] == 'H')
        {
            sscanf(u, "%d", &r);
            if (tree_check(l, r))
                printf("%s\n", "YES");
            else
                printf("%s\n", "NO" );
        }
        else
        {
            int len = 0, p, m = 0;
            while (u[len])
                len++;

            // tree_update(l+j, u[j]), j++;

            // printf("len = %d\n", len);
            for (int i = l; i < l+len; i++)
            {
                tree_data[TREE_REAL_DATA + i] = letter2code(u[i-l]);
            }
            start = TREE_REAL_DATA;
            for (int m = 1, K = TREE_REAL_DATA / 2, p = 2; m <= L; m++, K /= 2, p *= 2)
            {
                // printf("[%d, %d]\n", l/p, (l+len)/p );
                start -= K;
                for (int i = l/p; i <= (l+len)/p + 1 && i < K; i++)
                {
                    // printf("i = %d\n", i);
                    tree_data[start + i] = tree_data[start + K + 2*i] ^ tree_data[start + K + 2*i+1];
                }
            }
            // for (int i = 0; i < 4*n; i++)
            // {
            //     printf("%d ", tree_data[i]);
            // }
            // printf("\n");
        }
    }
    free(tree_data);
    return 0;
}
