#include <iostream>

using namespace std;

int chk[1 << 20];
int arr[20];
int N, S;
int cnt;

void f(int now,int sum,int bit)
{
	if (chk[bit] == 0 && sum == S) cnt++;
	if (now == N) return;
	chk[bit] = 1;
	f(now + 1, sum + arr[now], bit | 1 << now);
	f(now + 1, sum, bit);
}
int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];
	chk[0] = 1;
	f(0, 0, 0);
	cout << cnt;
}