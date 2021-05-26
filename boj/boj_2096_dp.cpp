#include <bits/stdc++.h>

using namespace std;

int Maxdp[2][3];
int Mindp[2][3];
int arr[100100][3];

int main()
{
    memset(Maxdp,-1,sizeof(Maxdp));
    memset(Mindp,-1,sizeof(Mindp));
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    int t=0;
    Maxdp[0][0]=Mindp[0][0]=arr[0][0];
    Maxdp[0][1]=Mindp[0][1]=arr[0][1];
    Maxdp[0][2]=Mindp[0][2]=arr[0][2];
    for(int i=1;i<N;i++)
    {
        Maxdp[!t][0]=max(Maxdp[t][0],Maxdp[t][1])+arr[i][0];
        Maxdp[!t][1]=max(Maxdp[t][0],max(Maxdp[t][1],Maxdp[t][2]))+arr[i][1];
        Maxdp[!t][2]=max(Maxdp[t][2],Maxdp[t][1])+arr[i][2];
        Mindp[!t][0]=min(Mindp[t][0],Mindp[t][1])+arr[i][0];
        Mindp[!t][1]=min(Mindp[t][0],min(Mindp[t][1],Mindp[t][2]))+arr[i][1];
        Mindp[!t][2]=min(Mindp[t][1],Mindp[t][2])+arr[i][2];
        t=!t;
    }
    int Min=2e9;
    int Max=0;
    for(int i=0;i<3;i++)
    {
        Max=max(Maxdp[t][i],Max);
        Min=min(Mindp[t][i],Min);
    }
    cout<<Max<<' '<<Min<<'\n';
}
