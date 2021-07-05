#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int chk[5010];
int N, K;

int next(int i)
{
	if (i > N) return next(0);
	if (chk[i + 1]) return next(i + 1);
	return i + 1;
}

int main()
{
	scanf("%d %d", &N, &K);
	chk[N + 1] = 1;
	int idx = 0;
	printf("<");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			idx = next(idx);
		}
		chk[idx] = 1;
		if (i == N - 1) printf("%d>", idx);
		else printf("%d, ",idx);
	}
}