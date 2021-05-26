#include <string>
#include <iostream>

using namespace std;

string S;
string arr;

int main()
{
	cin >> S;
	cin >> arr;
	int l = 0;
	int r = arr.size() - 1;
	val = S.size();
	while(true)
	{
		int chk = 0;
		for(int i = l;i < arr.size();i++)
		{
			if(arr.substr(i,val) == S) 
			{
				arr.erase(i,val);
				(i - (2 * val)) <= 0 ? l = 0 : l = i - (2 * val);
				chk = 1;
				break;
			}
		}
		if(chk == 0) break;
		chk = 0;
		if(r >= arr.size()) r = arr.size() - 1;
		for(int i = r;i >= 0;i--)
		{
			if(arr.substr(i,val) == S) 
			{
				arr.erase(i, val);
				chk = 1;
				r = i;
				break;
			}
		}
		if(chk == 0) break;

	}
	cout << arr << '\n';
}
