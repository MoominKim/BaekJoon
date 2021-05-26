#include <bits/stdc++.h>

using namespace std;

int dist[1010][1010];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dist,-1,sizeof(dist));
    int N,M,X;
    cin>>N>>M>>X;
    for(int i=1;i<=N;i++)dist[i][i]=0;
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b]=c;
    }
    for(int sai=1;sai<=N;sai++)
    {
        for(int sij=1;sij<=N;sij++)
        {
            if(dist[sij][sai]==-1)continue;
            for(int doc=1;doc<=N;doc++)
            {
                if(dist[sai][doc]==-1)continue;
                if(dist[sij][doc]==-1||dist[sij][doc]>dist[sij][sai]+dist[sai][doc])
                {
                    dist[sij][doc]=dist[sij][sai]+dist[sai][doc];
                }
            }
        }
    }
//    for(int i=1;i<=N;i++)
//    {
//        for(int j=1;j<=N;j++)
//        {
//            cout<<dist[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
    int Max=0;
    for(int i=1;i<=N;i++) Max=max(Max,dist[i][X]+dist[X][i]);
    cout<<Max<<'\n';
}
