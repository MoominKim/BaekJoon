#include <bits/stdc++.h>
#define int long long
using namespace std;

int vt[110][110];

signed main()
{
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            vt[i][j]=2e18;
            if(i==j)vt[i][j]=0;
        }
    }
    for(int i=0;i<M;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        vt[a][b]=min(vt[a][b],c);
    }
    
    for(int sai=1;sai<=N;sai++)
    {
        for(int here=1;here<=N;here++)
        {
            for(int there=1;there<=N;there++)
            {
                vt[here][there]=min(vt[here][there],vt[here][sai]+vt[sai][there]);
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            if(vt[i][j]==2e18)cout<<"0 ";
            else cout<<vt[i][j]<<' ';
        }
        cout<<'\n';
    }
}
