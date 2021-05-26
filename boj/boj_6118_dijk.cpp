#include <bits/stdc++.h>

using namespace std;

vector<int> v[20100];
int dp[20100];
priority_queue<pair<int,int> > q;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));

    int N,M;
    cin>>N>>M;

    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dp[1]=0;
    q.push({0,1});
    while(!q.empty())
    {
        int dist=-q.top().first;
        int now=q.top().second;
        q.pop();
        if(dp[now]<dist)continue;
        for(auto next:v[now])
        {
            if(dp[next]==-1||dp[next]>dist+1)
            {
                dp[next]=dist+1;
                q.push({-dp[next],next});
            }
        }
    }
    int Max=0;
    int Maxidx=0;
    int Maxcnt=0;
    for(int i=1;i<=N;i++)
    {
        if(Max==dp[i]) Maxcnt++;
        if(Max<dp[i])
        {
            Max=dp[i];
            Maxidx=i;
            Maxcnt=1;
        }
    }
    cout<<Maxidx<<' '<<Max<<' '<<Maxcnt<<'\n';
}
