#include <bits/stdc++.h>

using namespace std;

int Map[110][110];

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin>>N>>M;
    
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        Map[a][b]=1;
        Map[b][a]=-1;
    }

    for(int k=1;k<=N;k++)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                if(Map[i][j]!=0)continue;
                if(Map[i][k]==1&&Map[k][j]==1) Map[i][j]=1;
                if(Map[i][k]==-1&&Map[k][j]==-1) Map[i][j]=-1;
            }
        }
    }

    for(int i=1;i<=N;i++)
    {

        int cnt=0;

        for(int j=1;j<=N;j++)
        {
            if(i==j) continue;
            if(!Map[i][j])cnt++;
        }

        cout<<cnt<<'\n';
    }

}
