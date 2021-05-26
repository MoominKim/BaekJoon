#include <bits/stdc++.h>

using namespace std;

vector<int> people[51];//people이 속해있는 party를 저장
vector<int> party[51];//party에 속해있는 people을 저장
queue<int> know;//구라를 알고있는 people을 저장
int knowpeople[51];//구라를 알고있는 people chk
int knowparty[51];//구라를 알고있는 party chk

int main()
{

    int N,M,K;
    cin>>N>>M>>K;

    for(int i=0;i<K;i++) 
    {
        int a;
        cin>>a;
        know.push(a);
    }

    for(int i=0;i<M;i++)
    {

        int num;
        cin>>num;

        for(int j=0;j<num;j++)
        {
            int val;
            cin>>val;
            party[i].push_back(val);
            people[val].push_back(i);
        }

    }
    
    while(!know.empty())
    {

        int start=know.front();
        know.pop();

        for(int next:people[start])
        {
            if(knowparty[next]==1) continue;
            knowparty[next]=1;

            for(int inp:party[next])
            {
                if(knowpeople[inp]==1) continue;
                knowpeople[inp]=1;
                know.push(inp);
            }
        }
    }
    int cnt=0;
    for(int i=0;i<M;i++)
    {
        if(knowparty[i]==0)
            cnt++;
    }
    cout<<cnt<<'\n';
}

