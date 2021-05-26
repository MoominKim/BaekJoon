#include <bits/stdc++.h>

using namespace std;

int sum[510];
int arr[510];
int dp[510][510];

int f(int s,int e)
{
    if(s==e)
    {
        return 0;
    }
    int& ret=dp[s][e];
    if(ret!=0)return ret;
    ret=2e9;
    for(int i=s;i<e;i++)
    {
        ret=min(ret,f(s,i)+f(i+1,e)+sum[e]-sum[s-1]);
    }
    return ret;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(arr,0,sizeof(arr));
        memset(dp,0,sizeof(dp));
        int N;
        cin>>N;
        for(int i=1;i<=N;i++) cin>>arr[i];
        for(int i=1;i<=N;i++)sum[i]=sum[i-1]+arr[i];
        cout<<f(1,N)<<'\n';
//        cout<<'\n';
//        for(int i=1;i<=N;i++)
//        {
//            for(int j=1;j<=N;j++)
//            {
//                cout<<dp[i][j]<<' ';
//            }
//            cout<<'\n';
//        }
    }
}
