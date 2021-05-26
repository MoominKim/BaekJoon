#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define int long long

using namespace std;

set<pair<pair<int,int>,pair<int,int> > > S;
priority_queue<pair<int,pair<pair<int,int>,pair<int,int> > > > Q;
vector<int> arr[4];
int MAX = 2e18;

signed main()
{
	int A,B,C,D,K;
	cin >> A >> B >> C >> D >> K;
	for(int i = 0;i < A;i++)
	{
		int a;
		cin >> a;
		arr[0].push_back(MAX - a);
	}
	for(int i = 0;i < B;i++)
	{
		int a;
		cin >> a;
		arr[1].push_back(MAX - a);
	}
	for(int i = 0;i < C;i++)
	{
		int a;
		cin >> a;
		arr[2].push_back(MAX - a);
	}
	for(int i = 0;i < D;i++)
	{
		int a;
		cin >> a;
		arr[3].push_back(MAX - a);
	}
	for(int i = 0;i < 4;i++) 
	{
		sort(arr[i].begin(),arr[i].end());
		for(int j = 0;j < arr[i].size();j++) arr[i][j] = MAX - arr[i][j];
	}
	Q.push({arr[0][0] + arr[1][0] + arr[2][0] + arr[3][0],{{0,0},{0,0}}});
	while(K--)
	{
		int val = Q.top().first;
		int a = Q.top().second.first.first;
		int b = Q.top().second.first.second;
		int c = Q.top().second.second.first;
		int d = Q.top().second.second.second;
		Q.pop();
		//cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
		if(S.find({{a,b},{c,d}}) == S.end())
		{
			S.insert({{a,b},{c,d}});
			cout << val << '\n';
			if(a + 1 < A) Q.push({arr[0][a + 1] + arr[1][b] + arr[2][c] + arr[3][d],{{a + 1,b},{c,d}}});
			if(b + 1 < B) Q.push({arr[0][a] + arr[1][b + 1] + arr[2][c] + arr[3][d],{{a,b + 1},{c,d}}});
			if(c + 1 < C) Q.push({arr[0][a] + arr[1][b] + arr[2][c + 1] + arr[3][d],{{a,b},{c + 1,d}}});
			if(d + 1 < D) Q.push({arr[0][a] + arr[1][b] + arr[2][c] + arr[3][d + 1],{{a,b},{c,d + 1}}});
		}
		else K++;
	}
}
