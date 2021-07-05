#include <iostream>

using namespace std;
               
int arr[11];//11은 0부터 9까지

int main()
{
	int sum = 0;
	int res = 1;
	int N;
	cin >> N;
	while (N)
	{
		int tmp = N % 10;
		N /= 10;
		for (int i = 0; i < tmp; i++)
		{
			if (i == 0) arr[i] += res * N;
			else arr[i] += res * (N + 1);
		}
		if (tmp == 0) arr[tmp] += (res * (N - 1)) + sum + 1;
		else arr[tmp] += (res * N) + sum + 1;
		for (int i = tmp + 1; i < 10; i++) arr[i] += res * N;
		sum += tmp * res;
		res *= 10;
	}
	for (int i = 0; i < 10; i++) cout << arr[i] << ' ';
}