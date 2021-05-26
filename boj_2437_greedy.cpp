#include <bits/stdc++.h>

using namespace std;

vector<int> v;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}//입력

	sort(v.begin(),v.end());//정렬

	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (sum < v[i] - 1)//sum+1값이 v[i]가 아니라면, sum+1의 값을 정의할 수 없음.
		{
			cout << sum + 1 << '\n';
			exit(0);
		}
		sum += v[i];
	}
	cout << sum + 1<< '\n';//더 이상 값이 없으면, sum+1의 값을 정의할 수 없음.
}
