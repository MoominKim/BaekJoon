#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

vector<vector<pair<int,int>>> v;
vector<int> dist;
int chk=0;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		chk=0;
		dist.clear();
		v.clear();
		int N,M,W;
		cin>>N>>M>>W;
		dist.resize(N+1);
		v.resize(N + 1);
		for(int i = 0;i < M;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			v[a].push_back({b,c});
			v[b].push_back({a,c});
		}
		for(int i = 0;i < W;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			v[a].push_back({b,-c});
		}
		for(int i=1;i<=N;i++)dist[i]=INF;
		dist[1]=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=1;j<=N;j++)
			{		
				for(auto k : v[j])
				{	
					int next=k.first;
					int ds=k.second;
					if(dist[j] + ds < dist[next])
					{
						dist[next]=dist[j]+ds;
						if(i==N) chk=true;
					}
				}
			}
		}
		if(chk) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
