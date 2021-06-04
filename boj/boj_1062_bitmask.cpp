#include <iostream>
#include <string>

using namespace std;

int Max = 0;
string arr[51];
int N, K;

void f(int bit, int left, int now)
{
	if (left == 0)
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			int chk = 1;
			for (int j = 0; j < arr[i].size(); j++)
			{
				if (!(bit & 1 << arr[i][j] - 'a'))
				{
					chk = 0;
					break;
				}
			}
			if (chk)cnt++;
		}
		if (cnt > Max) Max = cnt;
		return;
	}
	for (int i = now; i < 26; i++)
	{
		if (bit & 1 << i) continue;
		f(bit | 1 << i, left - 1, i + 1);
	}
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	if (K < 5) {
		cout << 0;
		return 0;
	}
	if (K == 26)
	{
		cout << N;
		return 0;
	}
	int tmp = 0;
	tmp = tmp | 1 << 'a' - 'a';
	tmp = tmp | 1 << 'n' - 'a';
	tmp = tmp | 1 << 't' - 'a';
	tmp = tmp | 1 << 'i' - 'a';
	tmp = tmp | 1 << 'c' - 'a';
	f(tmp, K - 5, 0);
	cout << Max;
}