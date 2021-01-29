/*Составьте программу power2.c, вычисляющую, сколько существует непустых сочетаний чисел из последовательности таких, что сумма чисел в сочетании равна степени числа 2*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE (1)
#define FALSE (0)

int isPowerOfTwo(int a)
{
	if (a == 0)
		return FALSE;
	
	if (a < 0)
		//a = -a;
		return FALSE;

	if (a == 1)
		return TRUE; // ????????

	while (!(a & 1))
		a = a >> 1;

	return (a == 1);
}

int main()
{
	int n, x, s, M, K;
	scanf("%d", &n);
	int *a = (int*)malloc(sizeof(int) * n);
	int *S = (int*)malloc(sizeof(int) * n);
	s = 0;
	for (int j = 0; j < n; ++j)
	{
		scanf("%d", &x);
		a[j] = x;
		s += x;
		S[j] = s;
	}

	M = 1;
	for (int j = 0; j < n; ++j)
		M *= 2;

	int x0 = a[0];
	s = x0;
	K = isPowerOfTwo(s)? 1 : 0;
	for (int i = 2; i < M; ++i)
	{
		if ((i-1) & 1)
		{
			int u = i ^ (i-1), r = 0;
			while (u & 1)
				r++, u = u >> 1;
			// printf("s = %d    -->    s - %d + %d = %d   (r = %d, i = %d)\n", s, S[r-2], a[r-1], s - S[r-2] + a[r-1], r, i);
			s = s - S[r-2] + a[r-1];
		}
		else // i is even
		{
			s += x0;
		}
		//if (isPowerOfTwo(s))
			// printf("i = %d%d%d%d%d    s = %d\n", ((i&16)>>4), ((i&8)>>3), ((i&4)>>2), ((i&2)>>1), (i&1), s );
		K += isPowerOfTwo(s)? 1 : 0;
	}
	printf("%d\n", K);
	free(a), free(S);
	return 0;
}
