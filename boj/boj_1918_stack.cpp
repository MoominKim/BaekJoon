#include <bits/stdc++.h>

using namespace std;

stack<char> S;
int pri[310];

int main()
{
    string inp;
    cin >> inp;
    pri['(']=0;
    pri['+']=pri['-']=1;
    pri['*']=pri['/']=2;
    for(int i = 0;i < inp.length();i++)
    {
        if('A' <= inp[i] && inp[i] <= 'Z') cout << inp[i];
		else
		{
			if(inp[i]=='(')S.push(inp[i]);
			else if(inp[i] == ')')
	        {
                while(S.top()!='(')
                {
                    cout << S.top();
                    S.pop();
                }
                S.pop();
            }    
			else 
            {
                while(!S.empty()&&pri[S.top()] >= pri[inp[i]])
                {
                    cout << S.top();
                    S.pop();
                }
                S.push(inp[i]);
            }
		}
	}
	while(!S.empty())
	{
	    cout << S.top();
        S.pop();
    }    
}
