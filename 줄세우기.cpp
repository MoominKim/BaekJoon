/*
 
   
   20201231 줄세우기.cpp
   copyright 김무진


   이 문제는 스킬트리와 같은 문제이다.
   선행되는 조건을 모두 만족시켜야 하는데,
   그 선행되는 조건을 만족시켰을 시 나머지 순서는 전혀 상관이 없음을 알 수 있다.
   따라서, chk로 a가 몇번 언급되는지(선행되는 조건이 몇 개 인지)를 세고
   pos(입력을 할 수 있게 된 것들)을 순회하면서 조건을 clear해나가다 보면,
   모든 가지를 전부 순회할 수있게 된다.
 
 
 
 
 
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

vector<int> arr[32010];
int chk[32010];
queue<int> pos;
stack<int> ans;

int main()
{
	int N,M;
	cin >> N >> M;
	for(int i = 0;i < M;i++)
	{
		int a,b;
		cin >> a >> b;
		arr[b].push_back(a);
		chk[a]++;
	}
	for(int i = 1;i <= N;i++)
	{
		if(chk[i] == 0) pos.push(i);
	}
	while(!pos.empty())
	{
		int tmp = pos.front();
		pos.pop();
		ans.push(tmp);
		for(int i = 0;i < arr[tmp].size();i++)
		{
			int& ret = arr[tmp][i];
			chk[ret]--;
			if(chk[ret] == 0) pos.push(ret);
		}
	}
	while(!ans.empty())
	{
		int tmp = ans.top();
		ans.pop();
		cout << tmp << ' ';
	}
}

