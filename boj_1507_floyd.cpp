/*

    -1을 출력해야하는 경우가 어떤 경우인지 신중하게 생각할 것

*/
#include <bits/stdc++.h>

using namespace std;

int Map[21][21];
int chk[21][21];
int sum=0;
int N;

void f(int i,int j)
{
    if(chk[i][j])return;
    int c=0;
    for(int k=0;k<N;k++)
    {
        if(i==k||j==k)continue;
        if(Map[i][k]+Map[k][j]==Map[i][j])
        {
            chk[i][j]=1;
            chk[j][i]=1;
            f(i,k);
            f(k,j);
            c=1;
        }
    }
    if(c) return;
    chk[i][j]=1;
    chk[j][i]=1;
    sum+=Map[i][j];
}

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>Map[i][j];
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            for(int k=0;k<N;k++)
            {
                if(Map[i][j] > Map[i][k] + Map[k][j])
                {
                    cout<<-1<<'\n';
                    exit(0);
                }
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==j)continue;
            if(chk[i][j]==0)f(i,j);
        }
    }
    cout<<sum<<'\n';
}
