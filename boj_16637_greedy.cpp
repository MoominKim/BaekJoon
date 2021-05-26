#include <bits/stdc++.h>
#define int long long

using namespace std;

string c;
int Max=-2e18;
int N;
int len;

int num(char a)
{
    return a-'0';
}

int op(int a,int b,char p)
{
    if(p=='+') return a+b;
    if(p=='-') return a-b;
    if(p=='*') return a*b;
    if(p=='/') return a/b;
    return 0;
}

void f(int now,int val)
{
    if(now==len)
    {
        if(Max<val)Max=val;
        return;
    }
    if(now==0)
    {
        int a=now*2;
        f(now+1,num(c[a]));
        f(now+2,op(num(c[a]),num(c[a+2]),c[a+1]));
    }
    else if(now==len-1)
    {
        int a=now*2;
        f(now+1,op(val,num(c[a]),c[a-1]));
    }
    else
    {
        int a=now*2;
        f(now+1,op(val,num(c[a]),c[a-1]));
        f(now+2,op(val,op(num(c[a]),num(c[a+2]),c[a+1]),c[a-1]));
    }
}

signed main()
{
    cin>>N;
    len=N/2+1;
    cin>>c;

    if(N==1)cout<<c[0]<<'\n';
    else
    {
        f(0,0);
        cout<<Max<<'\n';
    }
}
