#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v[1010];
int dist[1010];
int parent[1010];
priority_queue<pair<int,int> > q;

int main()
{

    int N,M;
    cin>>N>>M;

    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }

    int st,en;
    cin>>st>>en;
    for(int i=1;i<=N;i++) dist[i]=2e9;
    dist[st]=0;
    q.push({0,st});
    while(!q.empty())
    {
        int loc=q.top().second;
        q.pop();
        for(auto next:v[loc])
        {
            if(dist[next.first]>dist[loc]+next.second)
            {
                parent[next.first]=loc;
                dist[next.first]=dist[loc]+next.second;
                q.push({-dist[next.first],next.first});
            }
        }
    }
    cout<<dist[en]<<'\n';
    stack<int> s;
    for(int i=en;i!=st;i=parent[i])
    {
        s.push(i);
    }
    s.push(st);
    cout<<s.size()<<'\n';
    while(!s.empty())
    {
        cout<<s.top()<<' ';
        s.pop();
    }
    cout<<'\n';
}
