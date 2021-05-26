#include <bits/stdc++.h>

using namespace std;

int dist[110][110];

int main()
{
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        dist[a][b]=1;
        dist[b][a]=-1;
    }
    for(int sai=1;sai<=N;sai++)
    {
        for(int sij=1;sij<=N;sij++)
        {
            for(int doc=1;doc<=N;doc++)
            {
                if(dist[sij][doc]==0)
                {
                    if(dist[sij][sai]==1&&dist[sai][doc]==1) dist[sij][doc]=1;
                    if(dist[sij][sai]==-1&&dist[sai][doc]==-1) dist[sij][doc]=-1;
                }
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        int cnt=0;
        for(int j=1;j<=N;j++)
        {
            if(i==j)continue;
            if(dist[i][j]==0)cnt++;
        }
        cout<<cnt<<'\n';
    }
}
