#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 1000000

using namespace std;

vector<pair<int, int> > a;
int chk[51];

int main()
{
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		a.push_back(make_pair(MAX - t,i));
	}
	sort(a.begin(),a.end());
	int S;
	cin >> S;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (chk[j] == 0 && abs(a[j].second - i) <= S)
			{
				S -= abs(a[j].second - i);
				chk[j] = 1;
				cout << MAX - a[j].first << ' ';
				int l = i;
				int r = a[j].second;
				for (int k = 0; k < N; k++)
				{
					if (l <= a[k].second && a[k].second < r)
					{
						a[k].second += 1;
					}
				}
				a[j].second = l;
				break;
			}
		}
	}

}