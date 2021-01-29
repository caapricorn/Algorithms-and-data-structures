/*Составьте функцию bubblesort, осуществляющую двунаправленную пузырьковую сортировку произвольной последовательности*/

void bubblesort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j)) {
    int left = 0, right = nel-1, i=0, k = -1;


    while (left < right) {

        for (i = left; i < right; i++) {
            if (i!= k && compare(i, i + 1) == 1) {
                swap(i, i + 1);
                k = i;

            }
        }
            right = k;
            for (i = right; i >= left; i--) {
                if (i != k && compare(i, i + 1) == 1) {
                    swap(i, i + 1);
                    k = i;
                }

            }
            left = k+1;

        }
    }
