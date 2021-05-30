#include <bits/stdc++.h>

using namespace std;

int N,M,K;
int n,m;

void init()
{
    cin>>N>>M>>K;
    n=(N-1)/2;
    m=(M-1)/2;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();

    int C,R;
    int t=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if((i+1)*(j+1)==K)
            {
                C=i;
                R=j;
                t=1;
                break;
            }
        }
        if(t) break;
    }
    if(!t)
    {
        cout<<"Impossible";
        return 0;
    }
    //cout <<C <<' '<<R<<'\n';
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(i%2&&i/2<C)
            {
                cout<<'#';
            }
            else if(j%2&&j/2<R)
            {
                cout<<'#';
            }
            else
            {
                cout<<'.';
            }
        }
        cout<<'\n';
    }
    return 0;
}