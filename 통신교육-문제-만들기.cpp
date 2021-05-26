#include <vector>
#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

vector<int> arr;

signed main()
{
	int N,M;
	cin >> N >> M;
	for(int i =0;i < N;i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(),arr.end());
	if(M % 2 == 0) M -= 1;
	int a = M / 2;
	int b = M - a;
	int suma = 0;
	int sumb = 0;
	for(int i = 0;i < a;i++) suma += arr[i];
	for(int j = N - 1;j >= N - b;j--)
	{
		sumb += arr[j];
		//cout << arr[j] << ' ';
	}
	cout << sumb - suma;
}
