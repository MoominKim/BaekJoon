#include <bits/stdc++.h>

using namespace std;

int arr[9][9];
int sero[9][10];
int garo[9][10];
int nemo[9][10];
const int N=9;

int whnem(int x,int y)
{
	return (x/3)*3+y/3;
}

void f(int now)
{
	if(now==81)
	{
		for(int i = 0;i < N;i++)
		{
			for(int j = 0;j < N;j++)
			{
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
	int x = now / 9;
	int y = now % 9;
	if(arr[x][y]!=0)f(now+1);
	else
	{
		for(int i = 1;i <= 9;i++)
		{
			if(sero[x][i] == 0 && garo[y][i] == 0 && nemo[whnem(x,y)][i] == 0)
			{
			/*	if(x==1&&y==4) 
				{
					cout<<sero[x][i]<<'\n'<<garo[y][i]<<'\n'<<nemo[whnem(x,y)][i]<<'\n'<<i<<'\n';
				}*/
				arr[x][y] = i;
				sero[x][i] = 1;
				garo[y][i] = 1;
				nemo[whnem(x,y)][i] = 1;
				f(now+1);
				arr[x][y] = 0;
				sero[x][i] = 0;
				garo[y][i] = 0;
				nemo[whnem(x,y)][i] = 0;
			}
		}
	}
}

int main()
{
	for(int i = 0;i < N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin >> arr[i][j];
			//if(i==1&&j==3)cout<<arr[i][j]<<' '<<arr[i][j-1]<<'\n';
			if(arr[i][j])
			{
				sero[i][arr[i][j]]=1;
				garo[j][arr[i][j]]=1;
				nemo[whnem(i,j)][arr[i][j]]=1;
				//if(i==1&&j==3)cout<<arr[i][j];
					
			}
		}
	}
//	cout << sero[1][1] << '\n';
	f(0);
}
