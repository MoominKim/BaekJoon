#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v[1010];
priority_queue<pair<int,int> > q;
int dist[1010];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++)dist[i]=2e9;
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    int A,B;
    cin>>A>>B;
    dist[A]=0;
    q.push({-0,A});
    while(!q.empty())
    {
        int now=q.top().second;
        q.pop();
        for(auto next:v[now])
        {
            if(dist[next.first] > dist[now]+next.second)
            {
                dist[next.first]=dist[now]+next.second;
                q.push({-dist[next.first],next.first});
            }
        }
    }
    cout<<dist[B]<<'\n';
}
