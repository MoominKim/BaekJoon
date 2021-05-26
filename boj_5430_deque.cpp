#include <bits/stdc++.h>

using namespace std;

string T;
int N;
string C;
deque<int> d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin>>z;
    while(z--)
    {
        T.clear();
        C.clear();
        cin>>T;
        cin>>N;
        cin>>C;
        if(N!=0)
        {
            int res=0;
            for(int i=1;i<C.size();i++)
            {
                if(C[i]==','||C[i]==']')
                {
                    d.push_back(res);
                    res=0;
                }
                else
                {
                    res*=10;
                    res+=C[i]-'0';
                }

            }
        }
        int t=0;
        int c=0;
        for(int i=0;i<T.size();i++)
        {
            if(T[i]=='R')t=!t;
            else
            {
                if(d.size()==0)
                {
                    cout<<"error\n";
                    c=1;
                    break;
                }
                if(t==0) d.pop_front();
                else d.pop_back();
            }
        }
        if(c)continue;
        cout<<'[';
        if(t==0)
        {
            while(!d.empty())
            {
                cout<<d.front();
                d.pop_front();
                if(!d.empty())cout<<",";
            }
        }
        if(t==1)
        {
            while(!d.empty())
            {
                cout<<d.back();
                d.pop_back();
                if(!d.empty())cout<<",";
            }
        }
        cout<<"]\n";
    }
}
