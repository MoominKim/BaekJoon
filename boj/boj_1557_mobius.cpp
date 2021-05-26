#include <iostream>
#define MAXN 1000000
#define ll long long
#define int ll
using namespace std;

int mu[MAXN];

void buildmu()
{
    mu[1] = 1;
    for(int i = 1; i <= MAXN; i++) 
    {
        for(int j = 2 * i; j <= MAXN; j += i) 
        {
            mu[j] -= mu[i];
        }
    }

}

ll sqn(ll N)
{
    int ans = 0;
    for (int i = 1; i*i<=N; i++) 
        ans += (mu[i]*(N/(i*i))); 
    return ans;

}

signed main()
{
    buildmu();
    int K;
    cin>>K;
    int l=0,r=K*2;
    while(l<=r)
    {
        int mid=(l+r)/2;
        int tmp=sqn(mid);
        if(tmp==K)
        {
            cout<<mid;
            return 0;
        }
        if(tmp<K)
        {
            l=mid+1;
        }
        else
        {
            r=mid;
        }
    }
}
