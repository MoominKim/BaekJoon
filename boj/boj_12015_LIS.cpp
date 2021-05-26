#include <bits/stdc++.h>

using namespace std;
int arr[1001000];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
    for(int i=0;i<N;i++)
    {
        if(v.empty())v.push_back(arr[i]);
        else
        {
            int p=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
            if(p==v.size())v.push_back(arr[i]);
            else v[p]=arr[i];
        }
    }
    cout<<v.size();
}
