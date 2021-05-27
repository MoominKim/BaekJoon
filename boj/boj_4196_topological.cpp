#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#define MAX_V 100100
using namespace std;
int v, e, visited[MAX_V + 1], x, y, r;
int scc[MAX_V];
vector<vector<int>> vt;
vector<vector<int>> rvt;
stack<int> st;
int in[MAX_V];

void dfs(int v) {
    visited[v] = true;
    for (int next : vt[v]) {
        if (visited[next])
            continue;
        dfs(next);
    }
    st.push(v);
}
void func(int v, int c) {
    visited[v] = true;
    scc[v]=c;
    for (int next : rvt[v]) {
        if (visited[next])
            continue;
            
        func(next, c);
    }
}
int main() {
    int _T;
    scanf("%d",&_T);
    while(_T--)
    { 
        vt.clear();
        rvt.clear();
        memset(in,0,sizeof(in));
        memset(visited,0,sizeof(visited));
        memset(scc,0,sizeof(scc));
        v=e=x=y=r=0;
        scanf("%d%d", &v, &e);
        vt.resize(v + 1);
        rvt.resize(v + 1);
        for (int i = 0; i < e; i++) {
            scanf("%d%d", &x, &y);
            vt[x].push_back(y);
            rvt[y].push_back(x);
        }
        for (int i = 1; i <= v; i++) {
            if (visited[i])
                continue;
            dfs(i);
        }
        memset(visited, 0, sizeof(visited));
        while (st.size()) {
            int here = st.top();
            st.pop();
            if (visited[here])
                continue;
            func(here, ++r);
        }
        for(int i=1;i<=v;i++)
        {
            for(int next:vt[i])
            {
                if(scc[next]==scc[i])continue;
                in[scc[next]]++;
            }
        }
        int ans=0;
        for(int i=1;i<=r;i++)
        {
            if(!in[i])ans++;
        }
        printf("%d\n",ans);
    }
}

