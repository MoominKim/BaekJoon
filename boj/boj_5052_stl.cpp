#include <bits/stdc++.h>

using namespace std;

vector<string> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin>>T;
    while(T--)
    {
        v.clear();
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            string a;
            cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        int c=1;
        for(int i=0;i<N-1;i++)
        {
            string here=v[i];
            string there=v[i+1];
            if(here==there.substr(0,here.size()))
            {
                cout<<"NO\n";
                c=0;
                break;
            }
        }
        if(c) cout<<"YES\n";
    }
}
