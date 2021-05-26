#include <bits/stdc++.h>

using namespace std;

int Map[1200][1200];
int xsum[1200];
int pre[1200][1200];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cin>>Map[i][j];
        }
    }  
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            xsum[j]=xsum[j-1]+Map[i][j];
            pre[i][j]=pre[i-1][j]+xsum[j];
        }
    } 
    while(M--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1]<<'\n';
    }
     
}

