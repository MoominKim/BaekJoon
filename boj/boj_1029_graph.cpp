/*#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int> > > edge;
int chk[16];

int LIS(int start, int idx)
{
	int tmp = 0;
	int Max = 1;
	for (int i = idx; i < edge.size(); i++)
	{
		if (i == 0 || edge[i - 1].first != edge[i].first) tmp = i;
		if (edge[i].second.first == start && chk[edge[i].second.second] == 0 && edge[i].second.first != edge[i].second.second)
		{
			chk[edge[i].second.second] = 1;
			Max = max(Max, LIS(edge[i].second.second, tmp) + 1);
			chk[edge[i].second.second] = 0;
		}
	}
	return Max;
}

int main()
{
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char c[16];
		cin >> c;
		for (int j = 0; j < N; j++)
		{
			edge.push_back(make_pair(c[j] - '0', make_pair(i, j)));
		}
	}
	sort(edge.begin(), edge.end());
	chk[0] = 1;
	cout << LIS(0, 0);
}*/