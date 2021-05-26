#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<pair<int,int> > v[10100];
int dist[10100][21];
priority_queue<pair<int,pair<int,int> > > q;

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //입력 빠르게 받기

    int N,M,K;
    cin >> N >> M >> K;
    for(int i=0;i<M;i++)
    {
        int st,en,di;
        cin>>st>>en>>di;
        v[st].push_back({en,di});
        v[en].push_back({st,di});
    }

    memset(dist,-1,sizeof(dist));

    int Min=2e18;
    q.push({0,{1,0}});
    while(!q.empty())
    {

        int now=q.top().second.first;
        int br=q.top().second.second;
        int dis=-q.top().first;
//        cout<<now<<' '<<br<<' '<<dis<<'\n';
        q.pop();
        if(now==N)
        {
            if(dis<Min)Min=dis;
            continue;
        }
        if(dist[now][br]!=-1&&dist[now][br] < dis)continue;
        for(pair<int,int> i:v[now])
        {

            int next=i.first;
            int d=i.second;

            if(dist[next][br]==-1||dist[next][br] > dis+d)
            {
                dist[next][br]=dis+d;
                q.push({-dist[next][br],{next,br}});
            }

            if(br<K&&(dist[next][br+1]>dis||dist[next][br+1]==-1))
            {
                dist[next][br+1]=dis;
                q.push({-dist[next][br+1],{next,br+1}});
            }

        }

    }

    cout<<Min<<'\n';
}
