#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main()
{
    int n;
    cin>>n;
    vector<pair<int,int> > v(n);
    for(auto &i:v) cin>>i.first>>i.second;
    vector<vector<int> > len(n,vector<int>(n));
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int dx=v[i].first-v[j].first;
            int dy=v[i].second-v[j].second;
            len[i][j]=dx*dx+dy*dy;
        }
    }
    int cnt=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int a=len[i][j];
                int b=len[j][k];
                int c=len[i][k];
                int Max=max(max(a,b),c);
                int sum=a+b+c;
                if(2*Max==sum)cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
}
