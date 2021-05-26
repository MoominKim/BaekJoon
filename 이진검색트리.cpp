#include <stdio.h>
#include <iostream>

using namespace std;

int tree[30010][3];//val,left,right

void append(int now,int val)
{
	if(tree[val][0] < tree[now][0])
	{
		if(tree[now][1] == 0)
		{
			tree[now][1] = val;
			return;
		}
		append(tree[now][1],val);
	}
	if(tree[val][0] > tree[now][0])
	{
		if(tree[now][2] == 0)
		{
			tree[now][2] = val;
			return;
		}
		append(tree[now][2],val);
	}
}

void post_fix(int now)
{

	if(tree[now][0] == 0) return;
	post_fix(tree[now][1]);
	post_fix(tree[now][2]);
	printf("%d\n",tree[now][0]);
	return;
}

int main()
{
	int now = 0;
	int idx = 1;
	int N;
	while(scanf("%d",&N) != EOF)
	{
		//puts("!");
		tree[idx][0] = N;
		if(idx != 1) append(1,idx);
		idx++;
	}
	//for(int i = 0;i < idx;i++)
	//{
	//	cout << tree[i][0] << ' ' << tree[i][1] << ' ' << tree[i][2] << '\n';
	//}
	post_fix(1);
}
