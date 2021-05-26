#include <bits/stdc++.h>

using namespace std;

int dist[30100];
vector<pair<int,int>> v[30100];
priority_queue<pair<int,int> > renew;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int V,E;
	cin >> V >> E;
	int st;
	cin >> st;
	for(int i=0;i<E;i++)
	{
		int here,there,w;
		cin >> here >> there >> w;
		v[here].push_back({there,w});
	}
	memset(dist,-1,sizeof(dist));
	renew.push({0,st});
	dist[st]=0;
	while(!renew.empty())
	{
		int now = renew.top().second;
		int	guri = -renew.top().first;
		renew.pop();
		for(auto next : v[now])
		{
			if(dist[next.first] == -1 || guri + next.second < dist[next.first])
			{
				dist[next.first] = guri + next.second;
				renew.push({-dist[next.first],next.first});
			}	
		}
	}
	for(int i = 1;i <= V;i++)
	{
		if(dist[i] == -1) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}
