#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

typedef tuple<int, int, int> it;
int box[102][102][102];
bool visited[102][102][102];
int m, n, h;

int tomato() {
   queue<it> ripe;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         for (int k = 1; k <= h; k++) {
            if (box[i][j][k] == 1) {
               ripe.push({ i,j,k });
               visited[i][j][k] = true;
            }
         }
      }
   }

   int nx, ny, nz, maxlen = 0;

   while (!ripe.empty()) {
      nx = get<0>(ripe.front());
      ny = get<1>(ripe.front());
      nz = get<2>(ripe.front());
      if (box[nx][ny][nz] > maxlen)
         maxlen = box[nx][ny][nz];
      ripe.pop();

      if (!box[nx + 1][ny][nz] && !visited[nx + 1][ny][nz]) {
         box[nx + 1][ny][nz] = box[nx][ny][nz] + 1;
         ripe.push({ nx + 1,ny,nz });
         visited[nx + 1][ny][nz] = true;
      }
      if (!box[nx - 1][ny][nz] && !visited[nx - 1][ny][nz]) {
         box[nx - 1][ny][nz] = box[nx][ny][nz] + 1;
         ripe.push({ nx - 1,ny,nz });
         visited[nx - 1][ny][nz] = true;
      }
      if (!box[nx][ny + 1][nz] && !visited[nx][ny + 1][nz]) {
         box[nx][ny + 1][nz] = box[nx][ny][nz] + 1;
         ripe.push({ nx,ny + 1,nz });
         visited[nx][ny + 1][nz] = true;
      }
      if (!box[nx][ny - 1][nz] && !visited[nx][ny - 1][nz]) {
         box[nx][ny - 1][nz] = box[nx][ny][nz] + 1;
         ripe.push({ nx,ny - 1,nz });
         visited[nx][ny - 1][nz] = true;
      }
      if (!box[nx][ny][nz + 1] && !visited[nx][ny][nz + 1]) {
         box[nx][ny][nz + 1] = box[nx][ny][nz] + 1;
         ripe.push({ nx,ny,nz + 1 });
         visited[nx][ny][nz + 1] = true;
      }
      if (!box[nx][ny][nz - 1] && !visited[nx][ny][nz - 1]) {
         box[nx][ny][nz - 1] = box[nx][ny][nz] + 1;
         ripe.push({ nx,ny,nz - 1 });
         visited[nx][ny][nz - 1] = true;
      }
   }

   return maxlen;
}

int main() {
   scanf("%d %d %d", &m, &n, &h);
   for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
         for (int k = 1; k <= h; k++)
            scanf("%d", &box[i][j][k]);

   for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= m + 1; j++) {
         box[i][j][0] = 1;
         box[i][j][h + 1] = 1;
      }
   }
   for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= h + 1; j++) {
         box[i][0][j] = 1;
         box[i][m + 1][j] = 1;
      }
   }
   for (int i = 0; i <= m + 1; i++) {
      for (int j = 0; j <= h + 1; j++) {
         box[0][i][j] = 1;
         box[n + 1][i][j] = 1;
      }
   }

   int maxlen = tomato();

   bool complete = true;
   for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
         for (int k = 1; k <= h; k++)
            if (box[i][j][k] == 0)
               complete = false;

   if (complete)
      printf("%d", maxlen - 1);
   else
      printf("-1");
}
