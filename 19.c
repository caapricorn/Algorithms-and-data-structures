/*Составьте функцию shellsort, выполняющую сортировку произвольной последовательности методом Шелла*/

void shellsort(unsigned long nel,
               int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j))
{
    int a = 1 , b = 1, c = 0, t = -1, mid=0, i = 0, k=0, g=0,v=1;
    if(nel>1) {
        while (c < nel) {
            c = a + b;
            a = b;
            b = c;
        }
        if (a != 1) {
            mid = a;
            k = mid;

            while (k > 0 && c > 1) {


                for (i = 0; mid < nel; i++, mid++) {
                    v=1;
                    if (compare(i, mid) == 1) {
                        swap(i, mid);
                        t = i;
                        g = mid;
                        while (i - k >= 0 && v>0) {
                            v=-1;
                            i -= k;
                            mid -= k;
                            if (compare(i, mid) == 1) {
                                swap(i, mid);
                                v=1;
                            }
                        }
                        i = t;
                        mid = g;
                    }
                }
                k = c - a;
                mid = k;
                a = k;
                c -= a;
            }
        } else if (compare(i, i + 1) == 1) {
            swap(i, i + 1);
        }
    }


}
