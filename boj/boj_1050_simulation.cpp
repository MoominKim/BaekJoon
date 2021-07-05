#include <iostream>
#include <assert.h>
#include <vector>
#include <string>

#define ll long long

using namespace std;

//모든 문자열, 값의 순서는 문자열이 앞, 값이 뒤이다

typedef struct {
	string name;
	vector<pair<string, ll> > comp;
}pot;

pot potion[52];
vector<pair<string, ll> > Min_po;//potion의 값의 Min값을 넣음
ll N, M;
ll LL1 = 1;

int strlen(char a[])
{
	int i = 0;
	for (; a[i]; i++);
	return i;
}

void upload_Min(string name, ll val)
{
	for (int i = 0; i < Min_po.size(); i++)
	{
		if (Min_po[i].first == name)
		{
			Min_po[i].second = val;
			return;
		}
	}
	Min_po.push_back(make_pair(name, val));
}

int download_Min(string name)
{
	for (int i = 0; i < Min_po.size(); i++) if (Min_po[i].first == name) return Min_po[i].second;
	return -1;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string a;
		int b;
		cin >> a;
		cin >> b;
		Min_po.push_back(make_pair(a, b));
	}
	for (int t = 0; t < M; t++)
	{
		char arr[52];
		cin >> arr;
		int Len = strlen(arr);
		int i = 0;
		string tmp = "";
		for (; arr[i] != '='; i++) tmp.push_back(arr[i]);
		potion[t].name = tmp;
		tmp.clear();
		for (; i < Len;)
		{
			pair<string, ll> gred;
			i++;
			gred.second = arr[i] - '0';
			i++;//계수부분을 자름

			for (; i < Len && arr[i] != '+'; i++) tmp.push_back(arr[i]);
			gred.first = tmp;
			tmp.clear();//재료부분을 자름

			potion[t].comp.push_back(gred);
		}
	}

	//문제 없음

	bool is_change = true;
	while (is_change)
	{
		is_change = false;
		for (int t = 0; t < M; t++)
		{
			bool ERROR = false;
			ll sum = 0;
			for (int i = 0; i < potion[t].comp.size(); i++)
			{
				int tmp = download_Min(potion[t].comp[i].first);
				if (tmp == -1)
				{
					ERROR = true;
					break;
				}
				sum += tmp * potion[t].comp[i].second * LL1;
				if (sum > 1000000000) sum = 1000000001;
			}
			if (ERROR == true) continue;	
			int tmp = download_Min(potion[t].name);
			if (tmp > sum || tmp == -1)
			{
				assert(sum != -1);
				is_change = true;
				upload_Min(potion[t].name, sum);
			}

		}
	}
	//assert(download_Min("LOVE") != -1);
	cout << download_Min("LOVE");
}