#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

int dp[1010][1010];
int a[1010];
int b[1010];
int N;

int Max(int a, int b) { return a > b ? a : b; }
int f(int x,int y)
{
	if (dp[x][y] != -1) return dp[x][y];
	if (x == N + 1 || y == N + 1) return dp[x][y] = 0;
	dp[x][y] = 1;
	for (int i = x + 1; i <= N; i++)
	{
		if (a[x] >= a[i]) continue;
		for (int j = y + 1; j <= N; j++)
		{
			if (a[i] == b[j])
			{
				dp[x][y] = Max(dp[x][y], f(i,j) + 1);
			}
		}
	}
	return dp[x][y];
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= N; i++) scanf("%d", &b[i]);
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dp[i][j] = -1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (a[i] == b[j])
			{
				ans = Max(ans, f(i,j));
			}
		}
	}
	printf("%d", ans);
}