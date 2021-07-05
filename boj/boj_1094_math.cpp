#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int N;
	int ans = 0;
	scanf("%d", &N);
	for (int i = 64; i > 0; i /= 2)
	{
		if (i == 0) break;
		while (N - i >= 0)
		{
			N -= i;
			ans++;
		}
	}
	printf("%d", ans);
}