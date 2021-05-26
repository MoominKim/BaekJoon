/*
 *
 * 2021 1 1
 * copyright 김무진
 * 할 수 있는 행동이 4가지
 * 4 ^ 10 ~~ 1000000이므로, 모든 가짓수를 해도 시간복잡도에 큰 부담이 되지않는다
 * - > 맵의 사이즈가 Max = 10이므로, 따라서, 모든 경우를 다 해보는 simulation문제로 판단함.
 *
 *
 */
#include <iostream>
#include <algorithm> // pair를 받기 위함
#include <queue>

using namespace std;

queue<pair<pair<pair<int, int>, pair<int, int> >, int> > q;

char arr[110][110];

int up(pair<int, int> R, pair<int, int> B, int cnt)
{
	int chk = 0;
	arr[B.first][B.second] = 'B';
	while (1)
	{
		if (arr[R.first - 1][R.second] == 'O') chk = 1;
		if (arr[R.first - 1][R.second] == '.') R.first--;
		else break;
	}
	arr[B.first][B.second] = '.';
	if (chk == 0) arr[R.first][R.second] = 'R';
	while (1)
	{
		if (arr[B.first - 1][B.second] == 'O')
		{
			arr[R.first][R.second] = '.';
			return 0;
		}
		if (arr[B.first - 1][B.second] == '.') B.first--;
		else break;
	}
	arr[R.first][R.second] = '.';
	arr[B.first][B.second] = 'B';
	while (1)
	{
		if (arr[R.first - 1][R.second] == '.') R.first--;
		else break;
	}
	arr[B.first][B.second] = '.';
	if (chk == 1)
	{
		cout << cnt + 1;
		return 1;
	}
	q.push({ {R,B},cnt + 1 });
	return 0;
}

int down(pair<int, int> R, pair<int, int> B, int cnt)
{
	int chk = 0;
	arr[B.first][B.second] = 'B';
	while (1)
	{
		if (arr[R.first + 1][R.second] == 'O') chk = 1;
		if (arr[R.first + 1][R.second] == '.') R.first++;
		else break;
	}
	arr[B.first][B.second] = '.';
	if(chk == 0) arr[R.first][R.second] = 'R';
	while (1)
	{
		if (arr[B.first + 1][B.second] == 'O') 
		{
			arr[R.first][R.second] = '.';
			return 0;
		}
		if (arr[B.first + 1][B.second] == '.') B.first++;
		else break;
	}
	arr[R.first][R.second] = '.';
	arr[B.first][B.second] = 'B';
	while (1)
	{
		if (arr[R.first + 1][R.second] == '.') R.first++;
		else break;
	}
	arr[B.first][B.second] = '.';
	if (chk == 1)
	{
		cout << cnt + 1;
		return 1;
	}
	q.push({ {R,B},cnt + 1 });
	return 0;
}

int left(pair<int, int> R, pair<int, int> B, int cnt)
{
	int chk = 0;
	arr[B.first][B.second] = 'B';
	while (1)
	{
		if (arr[R.first][R.second - 1] == 'O') chk = 1;
		if (arr[R.first][R.second - 1] == '.') R.second--;
		else break;
	}
	arr[B.first][B.second] = '.';
	if (chk == 0) arr[R.first][R.second] = 'R';
	while (1)
	{
		if (arr[B.first][B.second - 1] == 'O')
		{
			arr[R.first][R.second] = '.';
			return 0;
		}
		if (arr[B.first][B.second - 1] == '.') B.second--;
		else break;
	}
	arr[R.first][R.second] = '.';
	arr[B.first][B.second] = 'B';
	while (1)
	{
		if (arr[R.first][R.second - 1] == '.') R.second--;
		else break;
	}
	arr[B.first][B.second] = '.';
	if (chk == 1)
	{
		cout << cnt + 1;
		return 1;
	}
	q.push({ {R,B},cnt + 1 });
	return 0;
}

int right(pair<int, int> R, pair<int, int> B, int cnt)
{
	int chk = 0;
	arr[B.first][B.second] = 'B';
	while (1)
	{
		if (arr[R.first][R.second + 1] == 'O') chk = 1;
		if (arr[R.first][R.second + 1] == '.') R.second++;
		else break;
	}
	arr[B.first][B.second] = '.';
	if (chk == 0) arr[R.first][R.second] = 'R';
	while (1)
	{
		if (arr[B.first][B.second + 1] == 'O')
		{
			arr[R.first][R.second] = '.';
			return 0;
		}
		if (arr[B.first][B.second + 1] == '.') B.second++;
		else break;
	}
	arr[R.first][R.second] = '.';
	arr[B.first][B.second] = 'B';
	while (1)
	{
		if (arr[R.first][R.second + 1] == '.') R.second++;
		else break;
	}
	arr[B.first][B.second] = '.';
	if (chk == 1)
	{
		cout << cnt + 1;
		return 1;
	}
	q.push({ {R,B},cnt + 1 });
	return 0;
}

int main()
{
	pair<int, int> R;
	pair<int, int> B;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'R')
			{
				R = { i,j };
				arr[i][j] = '.';
			}
			if (arr[i][j] == 'B')
			{
				B = { i,j };
				arr[i][j] = '.';
			}
		}
	}
	q.push({ {R,B},0 });
	while (!q.empty())
	{
		R = q.front().first.first;
		B = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (cnt == 10) continue;
		if (up(R, B, cnt)) return 0;
		if (down(R, B, cnt)) return 0;
		if (left(R, B, cnt)) return 0;
		if (right(R, B, cnt)) return 0;
	}
	cout << -1;
	return 0;
}


