#include <bits/stdc++.h>

using namespace std;

string input[510];
int dp[510][510];
int N,M;
int pi[100];
int pj[100];

int f(int i,int j)
{
    if(i<0||i>=N||j<0||j>=M) return 1;
    int& ret=dp[i][j];
    if(ret!=-1) return ret;
    //cout<<px[input[x][y]]<<py[input[x][y]]<<'\n';
    ret=0;
    return ret = f(i+pi[input[i][j]],j+pj[input[i][j]]);
}

int main()
{

    memset(dp,-1,sizeof(dp));
    pi['U']=-1;
    pj['R']=1;
    pi['D']=1;
    pj['L']=-1;

    cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>input[i];

    int sum=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
                sum+=f(i,j);                 
    
    cout<<sum<<'\n';
    return 0;
}