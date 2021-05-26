#include <bits/stdc++.h>

using namespace std;

int arr[10100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        int a;
        cin>>a;
        arr[a]++;
    }
    for(int i=1;i<=10000;i++)
    {
        for(int j=0;j<arr[i];j++)cout<<i<<'\n';
    }
}
