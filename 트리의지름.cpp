#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

#define ll long long

using namespace std;

vector<pair<int,ll> > tree[100100];//연결된점,거리
int chk[100100];
int Max;
int Maxidx;

void DFS(int start,int val)
{
	chk[start] = 1;
	if(val > Max)
	{
		Max = val;
		Maxidx = start;
	}
	for(int i = 0;i < tree[start].size();i++)
	{
		if(chk[tree[start][i].first] == 0)
		{
			DFS(tree[start][i].first,val + tree[start][i].second);
		}
	}
	return;
}
int main()
{
	int V;
	cin >> V;
	for(int i = 0; i < V;i++)
	{
		int a;
		cin >> a;
		int b,c;
		while(1)
		{
			cin >> b;
			if(b == -1) break;
			cin >> c;
			tree[a].push_back({b,c});
		}
	}
	DFS(1,0);
	int tmp = Max;
	Max = 0;
	memset(chk,0,sizeof(chk));
	DFS(Maxidx,0);
	int ans = Max;
	if(Max < tmp) ans = tmp;
	cout << ans;
}
