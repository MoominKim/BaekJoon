#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        if(v.empty())v.push_back(a);
        else
        {
            auto p=lower_bound(v.begin(),v.end(),a);
            if(p==v.end())v.push_back(a);
            else *p=a;
        }
    }
    cout<<v.size()<<'\n';
}
