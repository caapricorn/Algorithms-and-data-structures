/*Составьте программу superstr.c, вычисляющую длину кратчайшей строки, содержащей все эти строки в качестве подстрок*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TRUE (1)
#define FALSE (0)

int bestOverlap(char *a, char *b, int aLen, int bLen)
{
	int i, j, start
		;
	start = aLen - bLen;
	if (start < 1) start = 1;
	//
	for (i = start; i <= aLen - 1; ++i)
	{
		int fOverlapping = TRUE;
		for (j = i; j < aLen; ++j)
		{
			if (a[j] != b[j-i])
			{
				fOverlapping = FALSE;
				break;
			}
		}
		if (fOverlapping)
		{
			return aLen - i;
		}
	}
	return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	int *t = (int*)malloc(sizeof(int) * n);
	char **a = (char **)malloc(sizeof(char*) * n);

	for (int i = 0; i < n; ++i)
	{
		a[i] = (char*)malloc(sizeof(char) * 30);
		scanf("%s", a[i]);
	}

	int *Len = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
	{
		Len[i] = strlen(a[i]);
	}

	short *O = (short*)malloc(sizeof(short) * n * n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int o = (i==j)? 0 : bestOverlap(a[i], a[j], Len[i], Len[j]);
			O[i*n+j] = o;
		}
	}

	short *J = (short*)malloc(sizeof(short) * n);
	for (int i = 0; i < n; ++i)
	{
		J[i] = i;
	}
	int minLen = 0;
	int lastStep = FALSE;
	while (1)
	{
		if (lastStep)
			break;
		//
		int L = Len[J[0]];
		for (int i = 1; i < n; i++)
		{
			L += -O[J[i-1]*n + J[i]] + Len[J[i]];
			if (minLen)
				if (L >= minLen)
					break;
		}
		if (minLen)
		{
			if (L < minLen)
			{
				minLen = L;
			}
		}
		else
		{
			minLen = L;
		}
		//
		// --------------------------------------------------------------
		// iterator
		int r = n - 2;
		while (J[r] > J[r+1] && r > 0)
			r--;		
		if (r == 0)
			if (J[0] == n-1)
			{
				lastStep = TRUE;
				continue;
			}
		int y = J[r] + 1;
		for (int j = 0; j < n; ++j) 
			t[j] = 0;
		for (int l = 0; l < r; ++l) 
			t[J[l]] = 1;
		while (t[y])
			y++;
		J[r] = y;
		t[y] = 1;
		//
		int s = n-1;
		while (t[s]) 
			s--;
		for (int l = n-1; l >= r+1; l--)
		{
			J[l] = s;
			s--;
			while (s>0 && t[s] ) 
				s--;
		}
		
	}
	printf("%d\n", minLen);
	free(J);
	free(O);
	free(Len);
	for (int i = 0; i < n; ++i) free(a[i]);
	free(a);free(t);
	return 0; 
}
