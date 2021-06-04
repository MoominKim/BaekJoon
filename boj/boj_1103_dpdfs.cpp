#include <bits/stdc++.h>

using namespace std;

vector<int> v[2510];
char Map[51][51];
int px[4] = { 0,0,1,-1 };
int py[4] = { 1,-1,0,0 };
int dp[2510];
int chk[2510];

int dfs(int start)
{
    if (chk[start] == 1)
    {
        cout << -1 << '\n';
        exit(0);
    }
    int& ret = dp[start];
    if (ret != -1) return ret;
    ret = 0;
    chk[start] = 1;
    for (int i = 0; i < v[start].size(); i++)
    {
        ret = max(ret, 1 + dfs(v[start][i]));
    }
    chk[start] = 0;
    return ret;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Map[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int mv = Map[i][j] - '0';
            for (int k = 0; k < 4; k++)
            {
                int mx = mv * px[k] + i;
                int my = mv * py[k] + j;
                if (mx < 0 || mx >= N || my < 0 || my >= M || Map[mx][my] == 'H') continue;
                v[i * M + j].push_back(mx * M + my);
            }
        }
    }
    cout << dfs(0) + 1;
}