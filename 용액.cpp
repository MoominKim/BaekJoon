#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> arr;

int main()
{
	int Min = INT_MAX;
	int N;
	cin >> N;
	for(int i = 0;i < N;i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
	int l = 0;
	int r = arr.size() - 1;
	int ansa;
	int ansb;
	while(l < r)
	{
		if(abs(arr[r] + arr[l]) < Min) 
		{
			Min = abs(arr[r] + arr[l]);
			ansa = arr[l];
			ansb = arr[r];
		}
		if(arr[r] + arr[l] < 0) l++;
		else r--;
	}
	cout << ansa << ' ' << ansb; 
}
