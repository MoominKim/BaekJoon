#include <bits/stdc++.h>

using namespace std;

pair<int,int> tree[40];
const int out='.'-'A';

void pre(int now)
{
    if(now==out)return;
    cout<<(char)(now+'A');
    pre(tree[now].first);
    pre(tree[now].second);
}

void in(int now)
{
    if(now==out)return;
    in(tree[now].first);
    cout<<(char)(now+'A');
    in(tree[now].second);
}

void post(int now)
{
    if(now==out)return;
    post(tree[now].first);
    post(tree[now].second);
    cout<<(char)(now+'A');
}

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        char a,b,c;
        cin>>a>>b>>c;
        tree[a-'A']={b-'A',c-'A'};
    }
    pre(0);
    cout<<'\n';
    in(0);
    cout<<'\n';
    post(0);
}
