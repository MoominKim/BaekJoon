#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<utility>
using namespace std;

typedef pair<int, int> ip;
vector<ip> linked[100001];

int longest(int fromn, int ton) {
   int max = 0, tmp;
   for (int i = 0; i < linked[ton].size(); i++) {
      if (linked[ton][i].first == fromn)
         continue;
      else {
         tmp = linked[ton][i].second + longest(ton, linked[ton][i].first);
         max = max > tmp ? max : tmp;
      }
   }
   return max;
}

int main() {
   int v;
   scanf("%d", &v);

   int n;
   int a, b;
   for (int i = 0; i < v; i++) {
      scanf("%d", &n);
      scanf("%d", &a);
      while (a != -1) {
         scanf("%d", &b);
         linked[n].push_back(make_pair(a, b));
         scanf("%d", &a);
      }
   }
   int max = 0, tmp;
   for (int i = 1; i <= v; i++) {
      if (linked[i].size() == 1) {
         tmp = longest(0, i);
         max = max > tmp ? max : tmp;
      }
   }

   printf("%d", max);
}
