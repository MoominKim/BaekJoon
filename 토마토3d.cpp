#include <iostream>
#include <queue>

using namespace std;

int N,M,H;
int map[101][101][101];
queue<pair<int,pair<int,int> > > ripe;
int px[] = {-1,1,0,0,0,0};
int py[] = {0,0,-1,1,0,0};
int pz[] = {0,0,0,0,-1,1};


int main()
{
	int riped = 0;
	int none = 0;
	cin >> N >> M >> H;
	for(int i = 0;i < H;i++)
	{
		for(int j = 0;j < M;j++)
		{
			for(int k = 0;k < N;k++)
			{
				cin >> map[i][j][k];
				if(map[i][j][k] == 1)
				{
					ripe.push({i,{j,k}});
					riped++;
				}
				if(map[i][j][k] == -1) none++;
			}
		}
	}
	int max = 1;
	int cnt = 0;
	while(!ripe.empty())
	{
		pair<int,pair<int,int> > tmp = ripe.front();
		ripe.pop();
		for(int i = 0;i < 6;i++)
		{
			int gx = tmp.first + px[i];
		 	int gy = tmp.second.first + py[i];
			int gz = tmp.second.second + pz[i];
			if(gx >= H || gy >= M || gz >= N ||gz < 0 || gx < 0 || gy < 0) continue;
			else if(map[gx][gy][gz] != 0) continue;
			else 
			{
				map[gx][gy][gz] = map[tmp.first][tmp.second.first][tmp.second.second] + 1;
				if(max < map[gx][gy][gz]) 
					max = map[gx][gy][gz];
				riped++;
				ripe.push({gx,{gy,gz}});
			}
		}
	}
	//cout << riped << ' '<< none << '\n';
	if(riped + none == M * N * H) cout << max - 1;
	else cout << -1;
}

