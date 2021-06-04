#include <algorithm>>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int> > height;
int map[30][30];//각 지점들의 높이를 저장함
int dis[630][630];

int abs(int N)
{
	if (N > 0) return N;
	return -N;
}
int main()
{
	int N, M, T, D;
	cin >> N >> M >> T >> D;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c;
			cin >> c;
			if (c >= 'a') map[i][j] = c - 'a' + 26;
			else map[i][j] = c - 'A';
			height.push(make_pair(map[i][j], i * M + j));
		}
	}
	for (int i = 0; i < N * M; i++)
	{
		for (int j = 0; j < N * M; j++)
		{
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = 12345678;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i + 1 < N && abs(map[i + 1][j] - map[i][j]) <= T)
			{
				if (map[i + 1][j] - map[i][j] > 0) dis[i * M + j][(i + 1) * M + j] = (map[i + 1][j] - map[i][j]) * (map[i + 1][j] - map[i][j]);
				else dis[i * M + j][(i + 1) * M + j] = 1;
			}
			if (i - 1 >= 0 && abs(map[i - 1][j] - map[i][j]) <= T)
			{
				if (map[i - 1][j] - map[i][j] > 0) dis[i * M + j][(i - 1) * M + j] = (map[i - 1][j] - map[i][j]) * (map[i - 1][j] - map[i][j]);
				else dis[i * M + j][(i - 1) * M + j] = 1;
			}
			if (j + 1 < M && abs(map[i][j + 1] - map[i][j]) <= T)
			{
				if (map[i][j + 1] - map[i][j] > 0) dis[i * M + j][i * M + j + 1] = (map[i][j + 1] - map[i][j]) * (map[i][j + 1] - map[i][j]);
				else dis[i * M + j][i * M + j + 1] = 1;
			}
			if (j - 1 >= 0 && abs(map[i][j - 1] - map[i][j]) <= T)
			{
				if (map[i][j - 1] - map[i][j] > 0) dis[i * M + j][i * M + j - 1] = (map[i][j - 1] - map[i][j]) * (map[i][j - 1] - map[i][j]);
				else dis[i * M + j][i * M + j - 1] = 1;
			}
		}
	}
	for (int i = 0; i < N * M; i++)
	{
		for (int j = 0; j < N * M; j++)
		{
			if (j == i) continue;
			for (int k = 0; k < N * M; k++)
			{
				if (k == i) continue;
				if (dis[j][k] > dis[j][i] + dis[i][k]) dis[j][k] = dis[j][i] + dis[i][k];
			}
		}
	}
	while (!height.empty())
	{
		if (dis[0][height.top().second] + dis[height.top().second][0] <= D)
		{
			cout << height.top().first;
			return 0;
		}
		height.pop();
	}
	//dis[0][a] + dis[a][0] < D
}