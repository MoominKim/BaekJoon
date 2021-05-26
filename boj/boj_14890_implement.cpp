#include <bits/stdc++.h>

using namespace std;

int Map[110][110];
int N,L;

int garo(int x)
{
    int as=0;
    for(int i=0;i<N-1;i++)
    {
        as++;
        if(Map[x][i]==Map[x][i+1]+1)
        {
            if(as<0)return 0;
            as=-L;
        }
        else if(Map[x][i]+1==Map[x][i+1])
        {
            if(as<L)return 0;
            as=0;
        }
        else if(Map[x][i]!=Map[x][i+1])return 0;
    }
	as++;
	if(as<0)return 0;
    return 1;
}

int sero(int y)
{ 
	int as=0;
    for(int i=0;i<N-1;i++)
    {
        as++;
        if(Map[i][y]==Map[i+1][y]+1)
        {
            if(as<0)return 0;
            as=-L;
        }
        else if(Map[i][y]+1==Map[i+1][y])
        {
            if(as<L)return 0;
            as=0;
        }
        else if(Map[i][y]!=Map[i+1][y])return 0;
    }
    as++;
    if(as<0)return 0;
    return 1;
}


int main()
{
    cin>>N>>L;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>Map[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<N;i++) cnt+=garo(i)+sero(i);
    cout<<cnt<<'\n';
}
