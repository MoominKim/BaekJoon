#include <bits/stdc++.h>

using namespace std;

vector<int> arr[100100];
int parent[100100];
queue<int> q;

int main()
{
    int N;
    cin >> N;
    for(int i=0;i<N-1;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    q.push(1);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        for(int next:arr[now])
        {
            if(parent[next]==0)
            {
                parent[next]=now;
                q.push(next);
            }
        }
    }
    for(int i=2;i<=N;i++)
    {
        cout<<parent[i]<<'\n';
    }
}
