#include <bits/stdc++.h>

using namespace std;

int in[100100];
int pre[100100];
int idx[100100];

void f(int ix,int iy,int px,int py)
{
    if(ix>iy||px>py)return;
    int root=pre[py];
    cout<<root<<' ';
    f(ix,idx[root]-1,px,px+(idx[root]-ix)-1);
    f(idx[root]+1,iy,px+(idx[root]-ix),py-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++)cin>>in[i];
    for(int i=0;i<N;i++)cin>>pre[i];
    for(int i=0;i<N;i++)idx[in[i]]=i;
    f(0,N-1,0,N-1);
}
