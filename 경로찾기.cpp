#include <iostream>
#include <cstring>

#define MOD 1000007

using namespace std;

int dp[51][51][51][51];
int arr[51][51];
int N,M,C;

int BFS(int x,int y,int cnt,int prev)
{
	if(x > N || y > M) return 0;
	if(x == N && y == M)
	{
		if(cnt == 0 && arr[x][y] == 0) return 1;
		if(cnt == 1 && arr[x][y] > prev) return 1;
		return 0;
	}
	int &ret = dp[x][y][cnt][prev];
	if(ret != -1) return ret;
	ret = 0;
	if(arr[x][y] == 0) ret = (BFS(x + 1,y,cnt,prev) + BFS(x,y + 1,cnt,prev)) % MOD;
	else if(arr[x][y] > prev) ret = (BFS(x + 1,y,cnt - 1,arr[x][y]) + BFS(x,y + 1,cnt - 1,arr[x][y])) % MOD;
	return ret;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	cin >> N >> M >> C;
	for(int i = 1;i <= C;i++)
	{
		int a,b;
		cin >> a >> b;
		arr[a][b] = i;
	}
	for(int i = 0;i <= C;i++) cout << BFS(1,1,i,0) << ' ';
}
