#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>

#define ll long long
#define MAX_SIZE 15

using namespace std;

int dp[1 << MAX_SIZE][MAX_SIZE][10]; //state, artistNumber, cost
int cost[MAX_SIZE][MAX_SIZE];
int n;

int f(int state, int artist, int c, int d) {
    int& ret = dp[state][artist][c];
    if (ret != 0) return ret;
    ret = d;

    for (int i = 0; i < n; i++) {
        if (state & (1 << i) || cost[artist][i] < c) continue;//안되는거는 컨티뉴시킴
        ret = max(ret, f(state | (1 << i), i, cost[artist][i], d + 1));//i는 현재위치,c는 현재 비용,d는 스트레잌
    }
    return ret;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &cost[i][j]);
        }
    }

    printf("%d", f(1, 0, 0, 1));

    return 0;
}
