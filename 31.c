/*Составьте программу rangepeak.c, выполняющую вычисление количества пиков на различных интервалах последовательности целых чисел, которая время от времени изменяется*/

#include <stdlib.h>
#include <stdio.h>

#define INF 1000000001 // предпологаем, что чисел больше такого не будет.

int TREE_REAL_DATA = 0;

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })



int *tree_data = NULL;


    int __tree_find_max(int p, int l, int r, int a, int b) 
    {
        // printf("[max] p = %d   l = %d   r = %d   a = %d   b = %d\n", p,l,r,a,b);
        int n = tree_data[3 * TREE_REAL_DATA], p0 = p;
        int* A = tree_data + (2 * TREE_REAL_DATA);

        if (b < l || r < a) 
        {
            // printf("\t\t(0) p = %d   l = %d   r = %d   a = %d   b = %d   --> %d\n", p0,l,r,a,b, tree_data[p]);
            return 0;
        }
        if ((a < l && r < b) || (l == r)) 
        {
            // printf("\t\t(1) p = %d   l = %d   r = %d   a = %d   b = %d   --> %d\n", p0,l,r,a,b, tree_data[p]);
            return tree_data[p];
        }
        int r1 = __tree_find_max(p * 2, l, (l + r) / 2, a, b); // опрос левого предка
        int r2 = __tree_find_max(p * 2 + 1, (l + r) / 2 + 1, r, a, b); // опрос правого предка
        //
        // printf("\ttest? %d,%d in [%d,%d]   n = %d   p = %d < %d ?\n", (l + r)/2, (l + r)/2 + 1, l, r, n, p, TREE_REAL_DATA - TREE_REAL_DATA/2);
        int U = 0;
        if (p < TREE_REAL_DATA - TREE_REAL_DATA/2)
        for (int j1 = (l + r)/2; j1 <= (l + r)/2 + 1; ++j1)
        {
            if (j1 >= 0 && j1 < n && j1 >= a && j1 <= b)
            {
                // printf("\ttesting: %d in [%d,%d]\n", j1, l, r);
                if (A[j1] >= A[j1-1] && A[j1] >= A[j1+1])
                    U++;
            }
        }
        //
        // printf("\t\tp = %d   l = %d   r = %d   a = %d   b = %d   --> %d\n", p0,l,r,a,b, r1+r2+U);
        return r1 + r2 + U; 
    }

// более юзабильная оболочка для функции выше.
    int tree_find_max(int a, int b) 
    {
        return __tree_find_max(1, 0, TREE_REAL_DATA - 1, a, b);
    }

// обновление элемента № р.
    void tree_update(int p, int x) 
    {
        int n = tree_data[3 * TREE_REAL_DATA];
        int* A = tree_data + (2 * TREE_REAL_DATA);
        A[p] = x;

        int start = TREE_REAL_DATA, K = TREE_REAL_DATA / 2, q = 2;

        p += TREE_REAL_DATA; 

        for (p /= 2; p; p /= 2, K /= 2, q *= 2) 
        {
            start -= K;
            int s = (p - start) * q;
            //
            int U = tree_data[2*p] + tree_data[2*p + 1];
            //
            for (int j1 = s + q/2 - 1; j1 <= s + q/2 && j1 < n-1 && j1 > s && j1 < s + q - 1; ++j1)
            {
                if (A[j1] >= A[j1-1] && A[j1] >= A[j1+1])
                    U++;
            }
            tree_data[p] = U;
        }

        // for (int i = 0; i < 4*TREE_REAL_DATA; i++)
        // {
        //     if (!(i % TREE_REAL_DATA)) printf("\n");
        //     printf("%d ", tree_data[i]);
        // }
        // printf("\n");
    }

// простейшая инициализация - установка всех значений в -INF
    void tree_init() 
    {
        for (int i = 0; i < TREE_REAL_DATA * 4; i++)
            tree_data[i] = 0;
    }





int main()
{
    int n, m, x, q, start, K, L, _min;
    scanf("%d", &n);
    n += 2;

    TREE_REAL_DATA = 2, L = 1;
    while (TREE_REAL_DATA < n)
        TREE_REAL_DATA *= 2, L++;
    
    tree_data = (int*)malloc((4*TREE_REAL_DATA) * sizeof(int));

    tree_init();

    int* A = tree_data + (2 * TREE_REAL_DATA);

    for (int i = 0; i < n-2; i++)
    {
        scanf("%d", &x);
        A[i+1] = x;
        if (i == 0)
            _min = x;
        else
            if (x < _min)
                _min = x;
    }
    A[0] = A[n-1] = _min - 1;

    tree_data[3 * TREE_REAL_DATA] = n;
    // for (int i = 0; i < n; i++)
    // {
    //     tree_data[TREE_REAL_DATA + i] = 0;
    // }
    start = TREE_REAL_DATA;
    for (m = 1, q = 2, K = TREE_REAL_DATA / 2; m <= L; m++, K /= 2, q *= 2)
    {
        start -= K;
        for (int i = 0, s = 0; i < K; i++, s += q)
        {
            int U = tree_data[start + K + 2*i] + tree_data[start + K + 2*i+1];
            //
            for (int j1 = s + q/2 - 1; j1 <= s + q/2 && j1 < n-1 && j1 > s && j1 < s + q - 1; ++j1)
            {
                if (A[j1] >= A[j1-1] && A[j1] >= A[j1+1])
                    U++;
            }
            tree_data[start + i] = U;
        }
    }


    // for (int i = 0; i < 4*TREE_REAL_DATA; i++)
    // {
    //     if (!(i % TREE_REAL_DATA)) printf("\n");
    //     printf("%d ", tree_data[i]);
    // }
    // printf("\n");
    // return 0;

    scanf("%d", &m);
    char s[10];
    for (int i=0;i<m;i++)
    {
        int l, r;
        scanf("%s%d%d", s, &l, &r);

        if (s[0] == 'P')
        {
            printf("%d\n", tree_find_max(l+1, r+1));
        }
        else
            tree_update(l+1, r);

    }
    free(tree_data);
    return 0;
}
