#include <bits/stdc++.h>

using namespace std;

stack<pair<int,int> > s;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string arr;
    cin>>arr;
    string boom;
    cin>>boom;

    string t="";
    int len=boom.size();
    string ans="";
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==boom[0])
        {
            t.push_back(arr[i]);
            s.push({t.size()-1,1});
            if(s.top().second==len)
            {
                int start=s.top().first;
                assert(start+len>=t.size());
                t.erase(start,len);
                s.pop();
            }
        }
        else if(!s.empty()&&arr[i]==boom[s.top().second])
        {
            t.push_back(arr[i]);
            s.top().second++;
            if(s.top().second==len)
            {
                int start=s.top().first;
                assert(start+len>=t.size());
                t.erase(start,len);
                s.pop();
            }
        }
        else
        {
            if(!t.empty())
            {
                ans+=t;
                t.clear();
                while(!s.empty()) s.pop();
            }
            ans.push_back(arr[i]);
        }
    }
	if(!t.empty())
    {
    	ans+=t;
        t.clear();
    }
    if(ans.empty())cout<<"FRULA\n";
    else cout<<ans<<'\n';
}
