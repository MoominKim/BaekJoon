#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char map[60][60];
int chk[60][60][64];
vector<pair<int, int> > t;
queue<pair<pair<int, int>, pair<int, int> > > p;
int	N, M;
int px[] = { 0,0,1,-1 };
int py[] = { 1,-1,0,0 };

int BFS()
{
	int Min = 2e9;
	while (!p.empty())
	{
		int x = p.front().first.first;
		int y = p.front().first.second;
		int keys = p.front().second.first;
		int now = p.front().second.second;
		p.pop();
		if (x < 0 || x >= N || y < 0 || y >= M || chk[x][y][keys] || map[x][y] == '#') continue;
		if (map[x][y] == '1' && Min > now)  Min = now;
		if ('a' <= map[x][y] && map[x][y] <= 'f') keys = keys | 1 << map[x][y] - 'a';
		if ('A' <= map[x][y] && map[x][y] <= 'F' && (keys & 1 << map[x][y] - 'A') == false) continue;
		chk[x][y][keys] = 1;
		
		int tmp = keys;
		for (int i = 0; i < 4; i++)
		{
			keys = tmp;
			p.push({ {x + px[i],y + py[i]} ,{keys,now + 1} });
		}
	}
	if (Min == 2e9) return -1;
	return Min;
}

int main()
{
	int x, y;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{

			cin >> map[i][j];
			if (map[i][j] == '0')
			{
				x = i;
				y = j;
			}
			if (map[i][j] == '1')
			{
				t.push_back({ i,j });
			}
		}
	}
	p.push({ {x,y},{0,0} });
	cout << BFS();
}