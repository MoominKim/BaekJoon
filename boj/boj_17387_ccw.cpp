#include <bits/stdc++.h>
#define int long long
#define xy pair<int,int>
#define x first
#define y second

using namespace std;


int ccw(xy a,xy b,xy c)
{
    int temp = a.x*b.y+b.x*c.y+c.x*a.y;
    temp-=a.y*b.x+b.y*c.x+c.y*a.x;
    if(temp>0)return 1;
    if(temp<0)return -1;
    return 0;
}

int solve(xy a,xy b,xy c,xy d)
{
    int abc=ccw(a,b,c);
    int abd=ccw(a,b,d);
    int cda=ccw(c,d,a);
    int cdb=ccw(c,d,b);
    if(abc*abd==0&&cda*cdb==0)
    {
        if(a>b)swap(a,b);
        if(c>d)swap(c,d);
        return a<=d&&c<=b;
    }
    return abc*abd<=0&&cda*cdb<=0;
}

signed main()
{
    xy a,b,c,d;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
    cout<<solve(a,b,c,d);
}
