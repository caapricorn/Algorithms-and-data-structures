/* Составьте функцию revarray, переставляющую элементы любого массива в обратном порядке */

void revarray(void *base, unsigned long nel, unsigned long width)
{unsigned long t;
    for(int i = 0, k =nel*width - width; i < k; i+=width, k-=width) {
        for (int j = 0; j < width; j++) {
            t = *((char *) base + i + j);
            *((char *) base + i + j) = *((char *) base + k + j);
            *((char *) base + k + j) = t;
        }
    }
}
