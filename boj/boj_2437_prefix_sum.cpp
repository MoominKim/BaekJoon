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
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    if(v[0]!=1)cout<<1;
    else
    {
        int sum=1;
        for(int i=1;i<N;i++)
        {
            if(sum+1<v[i])
            {
                cout<<sum+1<<'\n';
                exit(0);
            }
            sum+=v[i];
        }
        cout<<sum+1<<'\n';
    }
}
