#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main()
{
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());

    vector<int> tmp;
    for(int i=0;i<M;i++) tmp.push_back(0);
    do{
        int c=0;
        for(int i=0;i<M;i++)
        {
            if(tmp[i]!=v[i])c=1;
            tmp[i]=v[i];
        }        
        if(c)
        {
            for(int i=0;i<M;i++) cout<<tmp[i]<<' ';
            cout<<'\n';
        }
    }while(next_permutation(v.begin(),v.end()));
}
