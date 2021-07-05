#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
int arr[100][100];
int chk[100];
int idx = 0;
int ca[100];
int tmp[100];

void find()
{
	int min = 12345678;
	int minidx;
	for (int i = 1; i <= N; i++)
	{
		if (min > tmp[i] && tmp[i] != 0)
		{
			min = tmp[i];
			minidx = i;
		}
	}
	ca[idx] = minidx;
}

void dfs(int start)
{
	int max = 1;
	if (chk[start]) return;
	chk[start] = 1;
	for (int i = 1; i <= N; i++)
	{
		if (arr[start][i] != 12345678)
		{
			if (max < arr[start][i])
			{
				max = arr[start][i];
			}
			dfs(i);
		}
	}
	tmp[start] = max;
}

void reset()
{
	for (int i = 1; i <= N; i++)
	{
		tmp[i] = ca[i] = 0;
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = 12345678;
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	reset();
	for (int i = 0; i < M; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 1; k <= N; k++)
			{
				if (i == j)
				{
					arr[j][i] = 0;
					arr[i][j] = 0;
				}
				if (arr[i][j] > arr[i][k] + arr[k][j])
				{
					arr[i][j] = arr[i][k] + arr[k][j];
					arr[j][i] = arr[i][k] + arr[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (chk[i] == 1) continue;
		dfs(i);
		find();
		idx++;
		for (int j = 1; j <= N; j++)
		{
			tmp[j] = 0;
		}
	}

	printf("%d\n", idx);
	for (int i = 0; i < idx; i++)
	{
		printf("%d\n", ca[i]);
	}
}