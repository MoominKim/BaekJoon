#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int tree[3000000];
int unit[500100];

void makeTree(int left,int right,int tidx)
{
	if (left > right) return;
	if (left == right) tree[tidx] = unit[left];
	else
	{
		int mid = (left + right) / 2;
		makeTree(left, mid, tidx * 2);
		makeTree(mid + 1, right, tidx * 2 + 1);
		tree[tidx] = tree[tidx * 2] + tree[tidx * 2 + 1];
	}
}

void changeTree(int left,int right,int target,int val,int tidx)
{
	if (left > right) return;
	if (left == right) tree[tidx] += val;
	else
	{
		int mid = (left + right) / 2;
		if (mid < target) changeTree(mid + 1, right, target, val, tidx * 2 + 1);
		else changeTree(left, mid, target, val, tidx * 2);
		tree[tidx] = tree[tidx * 2] + tree[tidx * 2 + 1];
	}
}

int chkTree(int left,int right,int target,int tidx)
{
	if (left > right) return -1;
	if (left == right) return left;
	int mid = (left + right) / 2;
	if (tree[tidx * 2] < target) return chkTree(mid + 1, right, target - tree[tidx * 2], tidx * 2 + 1);
	else return chkTree(left, mid, target, tidx * 2);
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &unit[i]);
	makeTree(1, N, 1);
	int M;
	scanf("%d", &M);
	for (int t = 1; t <= M; t++)
	{
		int is;
		scanf("%d", &is);
		if (is == 1)
		{
			int target, val;
			scanf("%d %d", &target, &val);
			changeTree(1, N, target, val, 1);
		}
		else
		{
			int target;
			scanf("%d", &target);
			printf("%d\n",chkTree(1, N, target, 1));
		}
	}
}
