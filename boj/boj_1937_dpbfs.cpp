#include <bits/stdc++.h>

using namespace std;

int arr[510][510];
int dp[510][510];
int px[]={0,0,-1,1};
int py[]={-1,1,0,0};
int N;
int f(int x,int y)
{
    int &ret=dp[x][y];
    if(ret!=-1)return ret;
    ret=1;
    for(int i=0;i<4;i++)
    {
        int gx=x+px[i];
        int gy=y+py[i];
        if(gx<0||gx>=N||gy<0||gy>=N)continue;
        if(arr[gx][gy]<=arr[x][y])continue;
        ret=max(ret,1+f(gx,gy));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>arr[i][j];
        }
    }
    int Max=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            int tmp=f(i,j);
            if(tmp>Max)Max=tmp;
        }
    }
    cout<<Max<<'\n';
}
