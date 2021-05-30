#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<vector<pair<int,int> > > v[110];
const int MOD = 1000000007;
int dp[110][21][21];//T,now,first

int f(int N,int K)
{
    if(K==0) return 1;
    int a=pow(N,K/2);
    int temp=(a*a)%MOD;
    if(K%2==0) return temp;
    else return (temp * a) % MOD;

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T,N,D;
    cin>>T>>N>>D;

    for(int i=0;i<T;i++)
    {
        int M;
        cin>>M;

        v[i].resize(N);
        for(int j=0;j<M;j++)
        {
            int a,b,c;
            v[i][a].push_back({b,c});
        }
    }
    
    for(int i=1;i<=N;i++) dp[0][i][i]=1;
    for(int t=0;t<T;t++)
    {
        for(int i=1;i<=N;i++)
        {
            for(auto next:v[t][i])
            {
                for(int j=1;j<=N;j++)
                {
                    dp[t+1][next.first][j] = (dp[t][i][j] * next.second) % MOD;
                }
            }
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            cout<<pow(dp[T][j][i],D/T)<<' ';
        }
        cout<<'\n';
    }

}