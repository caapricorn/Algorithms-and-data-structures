/*Составьте функцию peak, возвращающую индекс любого пика в последовательности*/

unsigned long peak(unsigned long nel,
                   int (*less)(unsigned long i, unsigned long j))
{
     unsigned long bin1 = 0, bin2= nel-1,bin12, t;

     while (bin1<bin2){
         bin12= bin1/2+bin2/2;
             if (less(bin12 - 1, bin12)==0) {
                 bin2 = bin12-1;

             } else if (less(bin12 + 1, bin12)==0) {
                 bin1 = bin12+1;
             } else {
                 return bin12;
             }

     }

}
