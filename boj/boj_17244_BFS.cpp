#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
int n, m,answer;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
char arr[52][52];
int visited[52][52][1<<6];
map<pair<int,int>,int> itemList;
P S, E;
struct state {
	int x;
	int y;
	int item;
};
void func() {
	queue<state> q;
	visited[S.first][S.second][0] = 1;
	q.push({ S.first,S.second,0 });

	while (!q.empty()) {
		int curX = q.front().x;
		int curY = q.front().y;
		int curItem = q.front().item;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = curX + dx[i];
			int y = curY + dy[i];
			if (arr[x][y] == '#' || visited[x][y][curItem]) continue;

			if (arr[x][y] == 'X') {
				int item = itemList[make_pair(x, y)];
				if (curItem & (1 << item)) {
					visited[x][y][curItem] = visited[curX][curY][curItem]+1;
					q.push({ x,y,curItem });
				}
				else {
					visited[x][y][curItem | (1 << item)] = visited[curX][curY][curItem] + 1;
					q.push({ x,y,curItem | (1 << item) });
				}
			}
			else if (arr[x][y] == 'E') {
				if (curItem == (1 << itemList.size()) - 1) {
					answer = min(answer, visited[curX][curY][curItem]);
				}
			}
			else {
				visited[x][y][curItem] = visited[curX][curY][curItem] + 1;
				q.push({ x,y,curItem });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	
	int itemNum = 0;
	answer = n * m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') S = make_pair(i, j);
			else if (arr[i][j] == 'E') E = make_pair(i, j);
			else if (arr[i][j] == 'X') {
				itemList[make_pair(i, j)] = itemNum++;
			}
		}
	}
	func();
	cout << answer << '\n';

	return 0;
}