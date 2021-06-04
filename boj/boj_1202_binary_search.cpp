#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

vector<pair<int, int> > jewel;
vector<int> bag;
priority_queue<int> q;

signed main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int M, V;
		cin >> M >> V;
		jewel.push_back({M,V});
	}
	for (int i = 0; i < K; i++)
	{
		int b;
		cin >> b;
		bag.push_back(b);
	}
	sort(jewel.begin(),jewel.end());
	sort(bag.begin(),bag.end());
	int sum = 0;
	int idx = 0;
	for (int i = 0; i < K; i++)
	{
		while (idx < N && jewel[idx].first <= bag[i])
		{
			q.push(jewel[idx++].second);
		}
		if (!q.empty())
		{
			sum += q.top();
			q.pop();
		}
	}

	cout << sum;
}