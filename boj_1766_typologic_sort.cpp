#include <bits/stdc++.h>

using namespace std;

int bef[33000];
vector<int> v[33000];
priority_queue<int> q;

int main()
{
    int N,M;
    cin>>N>>M;
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        bef[b]++;
    }
    for(int i=1;i<=N;i++) if(!bef[i])q.push(-i);
    while(!q.empty())
    {
        int now=-q.top();
        q.pop();
        cout<<now<<' ';
        for(int next:v[now])
        {
            if(!--bef[next])q.push(-next);
        }
    }
}

