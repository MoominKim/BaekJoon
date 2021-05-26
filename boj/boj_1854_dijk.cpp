#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<pair<ll, ll>> G[1005];
ll n, m, k;
ll dist[1005][1005];
int visited[1005];
struct cmp
{
	bool operator()(pair <ll, ll > a, pair<ll, ll> b)
	{
		return a.second > b.second;
	}
};
void dijkstra(ll s)
{
	for (int i = 1; i <= k; i++) for(int j = 1; j <= n; j++)dist[i][j] = LLONG_MAX;
	dist[1][s] = 0;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
	pq.push({ s, 0 });
	int C = 0;
	while (!pq.empty())
	{
		ll x = pq.top().first, d = pq.top().second;
		pq.pop();
		if(visited[x] >= k) continue;
		int cnt = ++visited[x];
		if(cnt == k) C++;
		dist[cnt][x] = d;
		if(C == n) break;
		for(auto i : G[x])
        {
            pq.push({i.first, d + i.second});
        }
	}
	for (int i = 1; i <= n; i++)
	{
		if (dist[k][i] == LLONG_MAX) cout << "-1\n";
		else cout << dist[k][i] << '\n';
	}
}
int main()
{
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (ll i = 1; i <= m; i++)
	{
		ll s, e, x; cin >> s >> e >> x;
		G[s].push_back({ e, x });
	}
	dijkstra(1);
}
