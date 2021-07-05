#include <iostream>

using namespace std;

int main()
{
	int N, r, c;
	cin >> N >> r >> c;//r이 세로,c가 가로
	int res = 1;
	for (int i = 1; i < N; i++) res *= 2;
	int x = 0, y = 0;
	int ans = 0;
	while (res >= 1)
	{
		if (c < x + res && r < y + res)
		{
			res /= 2;
		}
		else if (c < x + res + res && r < y + res)
		{
			ans += res * res;
			x = x + res;
			res /= 2;
		}
		else if (c < x + res && r < y + res + res)
		{
			ans += res * res * 2;
			y = y + res;
			res /= 2;
		}
		else if (c < x + res + res && r < y + res + res)
		{
			ans += res * res * 3;
			x = x + res;
			y = y + res;
			res /= 2;
		}
	}
	cout << ans;
}