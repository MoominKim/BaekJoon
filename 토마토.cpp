#include <iostream>
#include <queue>

using namespace std;

int N,M;
int map[1010][1010];
queue<pair<int,int> > ripe;
int px[] = {-1,1,0,0};
int py[] = {0,0,-1,1};

int main()
{
	int riped = 0;
	int none = 0;
	cin >> N >> M;
	for(int i = 0;i < M;i++)
	{
		for(int j = 0;j < N;j++)
		{
			cin >> map[i][j];
			if(map[i][j] == 1)
			{
				ripe.push({i,j});
				riped++;
			}
			if(map[i][j] == -1) none++;
		}
	}
	int max = 1;
	int cnt = 0;
	while(!ripe.empty())
	{
		pair<int,int> tmp = ripe.front();
		ripe.pop();
		for(int i = 0;i < 4;i++)
		{
			int gx = tmp.first + px[i];
		 	int gy = tmp.second + py[i];
			if(gx >= M || gy >= N || gx < 0 || gy < 0) continue;
			else if(map[gx][gy] != 0) continue;
			else 
			{
				map[gx][gy] = map[tmp.first][tmp.second] + 1;
				if(max < map[gx][gy]) 
					max = map[gx][gy];
				riped++;
				ripe.push({gx,gy});
			}
		}
	}
	if(riped + none == M * N) cout << max - 1;
	else cout << -1;
}
