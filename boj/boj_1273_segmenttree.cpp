#include <iostream>

using namespace std;

int arr[300100];
int tree[12001000];
int propa[12001000];

void makeTree(int left,int right,int tleft,int tright,int target,int tidx)
{
	if (propa[tidx] != 0)
	{
		tree[tidx] += propa[tidx] * (right - left + 1);
		propa[tidx * 2] = propa[tidx];
		propa[tidx * 2 + 1] = propa[tidx];
		propa[tidx] = 0;
	}
	if (left == tleft && right == tright)
	{
		if (left == right) tree[tidx] = target;
		else propa[tidx] = target;
		return;
	}
	int mid = (left + right) / 2;
	if (mid >= tright) makeTree(left,mid,tleft,tright,target,tidx * 2);
	else if (mid < tleft) makeTree(mid + 1,right,tleft,tright,target,tidx * 2 + 1);
	else
	{
		makeTree(left,mid,tleft,mid,target,tidx * 2);
		makeTree(mid + 1,right,mid + 1,tright,target,tidx * 2 + 1);
	}
	tree[tidx] = tree[tidx * 2] + tree[tidx * 2 + 1];
}

int main()
{
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int t = 0; t < 3; t++)
	{
		for (int i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			if (t == 0) makeTree(1, 3000000, 1 + arr[i], arr[i] + a, 5, 1);
			if (t == 0) makeTree(1, 3000000, 1 + arr[i], arr[i] + a, 2, 1);
			if (t == 0) makeTree(1, 3000000, 1 + arr[i], arr[i] + a, 1, 1);
		}
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;

	}
}