#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

char inp[51][51];
int island[51][51];
int chk[51][51];
pair<int, int> is[10100];
pair<int, int> parent[10100];
int ans[10100];
int N, M;

int Min(int a, int b) { return a < b ? a : b; }

void find(int p,int val)
{
	if (p == parent[p].first)
	{
		if (val > parent[p].second) parent[p].second = val;
		return;
	}
	if (val > parent[p].second) parent[p].second = val;
	find(parent[p].first, parent[p].second + 1);
}

void BFS(int y, int x,int val)
{
	if (y < 0 || y >= N || x < 0 || x >= M || inp[y][x] == '.' || island[y][x] == val) return;
	island[y][x] = val;
	int px[] = { 0,0,1,-1,1,-1,1,-1 };
	int py[] = { 1,-1,0,0,1,-1,-1,1 };
	for (int i = 0; i < 8; i++) BFS(y + py[i], x + px[i], val);
}

int f(int y,int x,int val)
{
	if (y < 0 || x < 0 || y >= N || x >= M) return 0;
	if (island[y][x] != val && island[y][x] != 0) return island[y][x];
	if (chk[y][x] == val) return 12345678;
	int d = 12345678;
	chk[y][x] = val;
	d = Min(d,f(y + 1, x,val));
	d = Min(d,f(y - 1, x,val));
	d = Min(d,f(y, x + 1,val));
	d = Min(d,f(y, x - 1,val));
	return d;
}

int main()
{
	int idx = 1;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%s", inp[i]);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (inp[i][j] == 'x' && island[i][j] == 0)
			{
				BFS(i, j, idx);
				is[idx++] = make_pair(i,j);
			}
		}
	}
	if (idx == 1)
	{
		printf("-1");
		return 0;
	}
	else
	{
		int Max = 0;
		for (int i = 1; i < idx; i++) parent[i] = make_pair(i,0);
		for (int i = 1; i < idx; i++)
		{
			int tmp = f(is[i].first,is[i].second,i);
			if (tmp != 0)
			{
				parent[i].first = tmp;
				find(tmp, parent[i].second + 1);
			}
		}
		for (int i = 1; i < idx; i++)
		{
			ans[parent[i].second]++;
			if (Max < parent[i].second) Max = parent[i].second;
		}
		for (int i = 0; i <= Max; i++) printf("%d ", ans[i]);
	}
}