#include <bits/stdc++.h>

using namespace std;

int main()
{
    string T;
    cin>>T;
    sort(T.begin(),T.end());
    for(int i=0;i<T.size();i++)
    {
        cout<<T[T.size()-i-1];
    }

}
