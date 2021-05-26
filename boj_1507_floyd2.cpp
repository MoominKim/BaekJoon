#include <bits/stdc++.h>

using namespace std;

int test[21][21];
int Map[21][21];
int chk[21][21];
int N;
int sum=0;

void f(int i,int j)
{

    if(chk[i][j]) return;

    chk[i][j]=1;

    for(int k=0;k<N;k++)
    {
        if(i==k||j==k)continue;

        if(Map[i][j]>Map[i][k]+Map[k][j])
        {
            cout<<-1<<'\n';
            exit(0);
        }

        if(Map[i][j]==Map[i][k]+Map[k][j])
        {
            test[i][j]-=Map[i][j];
            sum-=Map[i][j];
            f(i,k);
            f(k,j);
            return;
        }

    }

}

int main()
{

    cin>>N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>Map[i][j];
            sum+=Map[i][j];
            test[i][j]=Map[i][j];
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(chk[i][j]==0)
            {
                f(i,j);
            }
        }
    }

//    for(int i=0;i<N;i++)
//    {
//        for(int j=0;j<N;j++)
//        {
//            cout<<test[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
    cout<<sum/2<<'\n';

}
