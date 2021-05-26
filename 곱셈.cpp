#include <bits/stdc++.h>
#define int long long

using namespace std;

int f(int A,int B,int C)
{
	if(B==1) return A%C;
	if(B==2) return (A*A)%C;
	if(B%2==0)
	{
		int p=f(A,B/2,C);
		p=(p*p)%C;
		return p;
	}
	else
	{
		int p=f(A,(B-1)/2,C);
		p=(p*p)%C;
		p=(p*A)%C;
		return p;
	}
}

signed main()
{
	int A,B,C;
	cin>>A>>B>>C;
	cout<<f(A,B,C)<<'\n';
}
