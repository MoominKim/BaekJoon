#include <iostream>
#include <stack>
#define int long long

using namespace std;

stack<int > S;//arr[.first]를 최솟값으로 갖는 스택
int arr[100100];
int Ps[100100];

signed main()
{
	int N;
	cin >> N;
	for(int i = 1;i <= N;i++)
	{
		cin >> arr[i];
		Ps[i] += arr[i] + Ps[i - 1];
	}
	arr[N + 1] = 0;
	S.push(0);
	S.push(1);
	int Max = 0;
	for(int i = 2;i <= N + 1;i++)
	{
		while(!S.empty() && arr[S.top()] > arr[i])
		{
			int tmp = S.top();
			S.pop();
			int sum = arr[tmp] * (Ps[i - 1] - Ps[S.top()]);
			if(sum > Max)
			{
				Max = sum;
			}
			//cout << tmp << ' ' << sum << '\n';

		}
		S.push(i);
	}
	cout << Max << '\n';
}
