#include <bits/stdc++.h>

using namespace std;

int arr[1010];
int dp[1010][1010];//카드의 길이가 s,e일때 취할 수 있는 최댓값

int f(int s,int e,int t)
{
    int &ret=dp[s][e];
    if(!t)
    {
        if(s==e) return arr[s];
        if(ret!=-1)return ret;
        ret=max(arr[s]+f(s+1,e,!t),arr[e]+f(s,e-1,!t));
    }
    else
    {
        if(s==e) return 0;
        if(ret!=-1)return min(dp[s+1][e],dp[s][e-1]);
        ret=min(f(s+1,e,!t),f(s,e-1,!t));
    }
    return ret;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(dp,-1,sizeof(dp));
        int N;
        cin>>N;
        for(int i=1;i<=N;i++)cin>>arr[i];
        for(int i=1;i<=N;i++)dp[i][i]=arr[i];
        cout<<f(1,N,0)<<'\n';
    }
}
