#include <string.h>
#include <iostream>

using namespace std;

int K;
int rem[16];
int len[16];
char arr[16][51];

void mod(int a)
{
	int res = 0;
	for (int i = 0; i < len[a]; i++) res = (res * 10 + arr[a][i] - '0') % K;
	rem[a] = res;
}

int MOD(int a,int pow)
{
	int res = rem[a];
	for (int i = 0; i < pow; i++) res = (res * 10) % K;
	return res;
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		len[i] = strlen(arr[i]);
	}
	cin >> K;
	for (int i = 0; i < N; i++) mod(i);

}