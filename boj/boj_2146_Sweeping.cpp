#include <bits/stdc++.h>

using namespace std;

int arr[110][110];
int island[110][110];
int border[110][110];
int px[]={0,0,-1,1};
int py[]={-1,1,0,0};
int now=1;
int N;

void BFS(int x,int y)
{
    island[x][y]=now;
    for(int i=0;i<4;i++)
    {
        int gx=x+px[i];
        int gy=y+py[i];
        if(gx<0||gx>=N||gy<0||gy>=N)continue;
        if(arr[gx][gy]==0)
        {
            border[x][y]=1;
            continue;
        }
        if(island[gx][gy]!=0)continue;
        BFS(gx,gy);
    }
}

int main()
{

    cin>>N;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(arr[i][j]&&island[i][j]==0)
            {
                BFS(i,j);
                now++;
            }
        }
    }

//    cout<<'\n'<<'\n';
//    for(int i=0;i<N;i++)
//    {
//        for(int j=0;j<N;j++)
//        {
//            cout<<island[i][j]<<' ';
//        }
//        cout<<'\n';
//    }
    int Min=2e9;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(border[i][j]==1)
            {
                int t=2e9;
                for(int k=max(i-Min,0);k<min(i+Min,N);k++)
                {
                    for(int l=max(j-Min,0);l<min(j+Min,N);l++)
                    {
                        if(island[k][l]!=0&&island[k][l] != island[i][j])
                        {
                            t=min(t,abs(k-i)+abs(l-j));
//                            cout<<t<<'\n';
                        }
                    }
                }
                Min=min(t,Min);
//                cout<<Min<<'\n';
            }
        }
    }
    cout<<Min-1<<'\n';
}

