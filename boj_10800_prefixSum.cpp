#include <bits/stdc++.h>

using namespace std;

vector<pair<int,pair<int,int> > > arr;
int color[200100];
int player[200100];

signed main()
{

    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int a,b;
        cin>>a>>b;
        arr.push_back({b,{a,i}});
    }

    sort(arr.begin(),arr.end());
    int sum=0;
    for(int i=0, j=0;i<arr.size();i++)
    {

        int c=arr[i].second.first;
        int val=arr[i].first;
        int idx=arr[i].second.second;
        for(;val>arr[j].first;j++)
        {
            sum+=arr[j].first;
            color[arr[j].second.first]+=arr[j].first;
        }
        player[idx]=sum-color[c];
    }

    for(int i=0;i<N;i++)
    {
        cout<<player[i]<<'\n';
    }
}

