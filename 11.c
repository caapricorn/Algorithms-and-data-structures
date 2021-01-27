/*Составьте функцию binsearch, выполняющую поиск заданного числа в последовательности чисел, отсортированном по возрастанию, методом деления пополам*/

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    unsigned long bin, left = -1, right=nel;
    while (left+1<right)
    {
        bin=(left+right)/2;
        if (compare(bin) == -1)
        {
            left = bin;
        }
        else if (compare(bin) == 1)
        {
            right = bin;
        }
        else
        {
            return bin;
        }

    }
    return nel;
}
