#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> v;

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        v.push_back({a,i});
    }
    sort(v.begin(),v.end());
    int Max=0;
    for(int i=0;i<N;i++)
    {
        if(v[i].second-i>Max)Max=v[i].second-i;
    }
    cout<<Max+1;
}
