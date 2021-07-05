#include <bits/stdc++.h>

using namespace std;

int d[11][500100];
int p[11][51];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int C,D,M;
    cin>>C>>D>>M;

    for(int i=1;i<=C;i++)
    {
        for(int j=1;j<=D;j++)
        {
            cin>>p[j][i];
        }
    }

    int Max=M;
    for(int i=1;i<=D;i++)
    {
        d[i][0]=0;
        for(int j=1;j<=500000;j++)
        {
            for(int k=1;k<=C;k++)
            {
                if(j<p[i][k]) continue;
                d[i][j] = max(d[i][j],d[i][j-p[i][k]]+(p[i+1][k]-p[i][k]));
            }
        }
        Max=Max+d[i][Max];
    }
    cout<<Max<<'\n';
}