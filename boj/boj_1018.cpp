#include <iostream>
#include <algorithm>

using namespace std;

int arr[50][50]; 
char map[50][50];

int f(int x,int y)
{
	int res = 1;
	int A = 0;
	int B = 0;
	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			if (arr[i][j] != res) A++;
			else B++;
			res = !res;
		}
		res = !res;
	}
	return min(A, B);
}
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		char c[51];
		cin >> c;
		for (int j = 0; j < M; j++)
		{
			if (c[j] == 'W') arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}
	
	int Min = 2e9;
	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			Min = min(Min,f(i,j));
		}
	}
	cout << Min;
}