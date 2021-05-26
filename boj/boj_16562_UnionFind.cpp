#include <bits/stdc++.h>

using namespace std;

int parent[10100];
int val[10100];
int chk[10100];

int find(int p)
{
    if(parent[p]==p)return p;
    return parent[p]=find(parent[p]);
}

int main()
{
    int N,M,K;
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++)
    {
        parent[i]=i;
        cin>>val[i];
    }
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        a=find(a);
        b=find(b);
        if(a!=b)
        {
            if(val[a]>val[b]) parent[a]=parent[b];
            else parent[b]=parent[a];
        }
    }
    int sum=0;
    for(int i=1;i<=N;i++)
    {
        int t=find(i);
        if(chk[t]==0)
        {
            sum+=val[t];
            chk[t]=1;
        }
    }
    if(sum<=K)cout<<sum<<'\n';
    else cout<<"Oh no\n";
}
