#include <bits/stdc++.h>

using namespace std;

int A[21];
int B[21];
vector<int> a;
vector<int> b;
int N,S;
int alen;
int blen;

void asum(int l,int now,int c)
{
    if(c)a.push_back(l);
    if(now==alen) return;
    asum(l+A[now],now+1,1);
    asum(l,now+1,0);
}

void bsum(int l,int now,int c)
{
    if(c) b.push_back(l);
    if(now==blen) return;
    bsum(l+B[now],now+1,1);
    bsum(l,now+1,0);
}

int main()
{
    cin>>N>>S;
    alen=N/2;
    blen=N-N/2;
    for(int i=0;i<N/2;i++) cin>>A[i];
    for(int i=N/2;i<N;i++) cin>>B[i-N/2];
//    for(int i=0;i<alen;i++) cout<<A[i]<<' ';
//    cout<<'\n';
//    for(int i=0;i<blen;i++) cout<<B[i]<<' ';
//    cout<<'\n';
    asum(0,0,0);
    bsum(0,0,0);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

//    for(int i=0;i<a.size();i++)cout<<a[i]<<' ';
//    cout<<'\n';
//    for(int i=0;i<b.size();i++)cout<<b[i]<<' ';
//    cout<<'\n';
    int sum=0;
    for(int i=0;i<a.size();i++)
        if(a[i]==S)sum++;
    for(int i=0;i<b.size();i++)
        if(b[i]==S)sum++;
    for(int i=0;i<a.size();i++)
    {
        int p=lower_bound(b.begin(),b.end(),S-a[i])-b.begin();
//      if(a[i]==-3)cout<<b[p]<<'\n';
        if(p==b.size()||a[i]!=-b[p]) continue;
//      if(a[i]==-3)cout<<"!\n";
        int j;
        for(j=p;j<b.size()&&b[j]==b[p];j++);
        sum+=j-p;
//        cout<<a[i]<<' '<<b[p]<<'\n';
//        cout<<sum<<'\n';
//        cout<<p<<' '<<j<<'\n'<<'\n';
    }
    cout<<sum;
}
