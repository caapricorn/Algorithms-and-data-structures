/* Составьте функцию maxarray, возвращающую индекс максимального элемента произвольного массива */

int maxarray(void  *base, unsigned long nel, unsigned long width,
             int (*compare)(void *a, void *b))
{

    int max = 0;
    int t;
            for (unsigned long j = 1; j < nel; j++) {
                t = compare((char *)base+width*max,(char *)base+width*j);
                if (t < 0)
                {
                    max = j;
                }
            }
            return max;

}

