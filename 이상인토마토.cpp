#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int, int> ip;
int box[1002][1002];
bool visited[1002][1002];
int m, n;

int tomato() {
   queue<ip> ripe;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         if (box[i][j] == 1) {
            ripe.push(make_pair(i, j));
            visited[i][j] = true;
         }
      }
   }

   int nowx, nowy, maxlen = 0;

   while (!ripe.empty()) {
      nowx = ripe.front().first;
      nowy = ripe.front().second;
      if (box[nowx][nowy] > maxlen)
         maxlen = box[nowx][nowy];
      ripe.pop();

      if (!box[nowx + 1][nowy] && !visited[nowx + 1][nowy]) {
         box[nowx + 1][nowy] = box[nowx][nowy] + 1;
         ripe.push(make_pair(nowx + 1, nowy));
         visited[nowx + 1][nowy] = true;
      }
      if (!box[nowx - 1][nowy] && !visited[nowx - 1][nowy]) {
         box[nowx - 1][nowy] = box[nowx][nowy] + 1;
         ripe.push(make_pair(nowx - 1, nowy));
         visited[nowx - 1][nowy] = true;
      }
      if (!box[nowx][nowy + 1] && !visited[nowx][nowy + 1]) {
         box[nowx][nowy + 1] = box[nowx][nowy] + 1;
         ripe.push(make_pair(nowx, nowy + 1));
         visited[nowx][nowy + 1] = true;
      }
      if (!box[nowx][nowy - 1] && !visited[nowx][nowy - 1]) {
         box[nowx][nowy - 1] = box[nowx][nowy] + 1;
         ripe.push(make_pair(nowx, nowy - 1));
         visited[nowx][nowy - 1] = true;
      }
   }

   return maxlen;
}

int main() {
   scanf("%d %d", &m, &n);

   for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
         scanf("%d", &box[i][j]);

   for (int i = 0; i <= n + 1; i++) {
      box[i][0] = 1;
      box[i][m + 1] = 1;
   }
   for (int i = 0; i <= m + 1; i++) {
      box[0][i] = 1;
      box[n + 1][i] = 1;
   }

   int maxlen = tomato();

   bool complete = true;
   for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
         if (box[i][j] == 0)
            complete = false;

   if (complete)
      printf("%d", maxlen - 1);
   else
      printf("-1");
}
