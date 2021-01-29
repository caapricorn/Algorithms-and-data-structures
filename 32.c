/*Составьте программу rangegcd.c, вычисляющую наибольший общий делитель на различных интервалах последовательности целых чисел*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE (1)
#define FALSE (0)

int gcd(int a, int b)
{
	if (a == 0 && b == 0)
		return 0;

	while (a > 0 && b > 0)
	{
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}
	return (a > 0)? a : b;
}

int main()
{
	int n, x;
	scanf("%d", &n);
	int *a = (int*)malloc(sizeof(int) * n);
	for (int j = 0; j < n; ++j)
	{
		scanf("%d", &x);
		if (x < 0)
			x = -x;
		a[j] = x;
	}

	int n2 = 1, H = 0;
	while (n2 < n)
		n2 *= 2, H++;

	int S0 = n2;

	int** G = (int**)malloc(sizeof(int*) * (H+1));

	for (int h = 0; h <= H; ++h, n2 /= 2)
	{
		G[h] = (int*)malloc(sizeof(int) * n2);
		if (h == 0)
		{
			for (int k = 0; k < n; ++k)
				G[0][k] = a[k];
			for (int k = n; k < n2; ++k)
				G[0][k] = 0;
			free(a);
		}
		else
		{
			// printf("level %d width %d \n", h, n2);

			for (int k = 0; k < n2; ++k)
				G[h][k] = gcd(G[h-1][2*k], G[h-1][2*k+1])/*, printf("%d ", G[h][k])*/;
			// printf("\n");
		}
	}

	int M, l, r;
	scanf("%d", &M);
	// printf("M = %d\n", M);
	for (int _i = 0; _i < M; ++_i)
	{
		// printf("query %d\n", _i);
		scanf("%d %d", &l, &r);
		if (l < 0)
			l = 0;
		if (r > n-1)
			r = n-1;
		if (l == 0 && r == n-1)
		{
			printf("%d\n", G[H][0]);
			continue;
		}

		int h = H-1, s = S0/2, kl = l / s, kr = r / s;
		while (kl == kr && h > 0)
		{
			h--, s /= 2, kl = l / s, kr = r / s;
		}

		int x0 = s * kr;
		// printf("x0 = %d    h = %d    \n", x0, h);

		int g = G[0][x0];
		// printf("g0 = %d\n", g);
		int z = h, s1 = s, x1 = x0;
		while (z >= 0)
		{
			// printf("z = %d    s1 = %d\n", z, s1);
			if (x1 + s1-1 <= r)
			{
				g = gcd(g, G[z][x1/s1]);
				// printf("[%d, %d] --> %d\n", x1, x1 + s1-1, G[z][x1/s1]); 
				x1 += s1;
			}
			z--, s1 /= 2;
		}

		z = h, s1 = s, x1 = x0;
		while (z >= 0)
		{
			// printf("z = %d    s1 = %d\n", z, s1);
			if (x1 - s1 >= l)
			{
				g = gcd(g, G[z][x1/s1 - 1]);
				// printf("[%d, %d] --> %d\n", x1 - s1, x1 - 1, G[z][x1/s1 - 1]); 
				x1 -= s1;
			}
			z--, s1 /= 2;
		}
		printf("%d\n", g);
	}

	for (int i = 0; i <= H; ++i) free(G[i]);
	free(G);
	return 0;
}
