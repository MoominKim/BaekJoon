#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

vector<pair<int, int> > l;
int arr[51];

int next(int N)
{
	for (int i = N + 1; i < l.size(); i++)
	{
		if (l[i].second != 0)
		{
			return i;
		}
	}
	return -1;
}

int nnext(int N) {return next(next(N));}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	sort(arr,arr + N);
	l.push_back(make_pair(arr[0], 1));
	for (int i = 1; i < N; i++)
	{
		if (l[l.size() - 1].first == arr[i]) l[l.size() - 1].second += 1;
		else l.push_back(make_pair(arr[i],1));
	}
	for (int i = 0; i != -1; i = next(i))
	{
		if (next(i) != -1 && l[i].first + 1 == l[next(i)].first)
		{
			if (nnext(i) != -1)
			{
				for (int j = 0; j < l[i].second; j++) printf("%d ", l[i].first);
				printf("%d ", l[nnext(i)].first);
				l[nnext(i)].second -= 1;
			}
			else
			{
				for (int j = 0; j < l[next(i)].second; j++) printf("%d ", l[next(i)].first);
				l[next(i)].second = 0;
				for (int j = 0; j < l[i].second; j++) printf("%d ", l[i].first); 
			}
		}
		else
		{
			for (int j = 0; j < l[i].second; j++) printf("%d ", l[i].first);
		}
	}
}