#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int preorder[10001];

void postorder(int prestart, int Tlen) {
   if (Tlen <= 0)
      return;

   int parent = preorder[prestart];

   int Llen;
   for (Llen = 1; Llen < Tlen; Llen++)
      if (preorder[prestart + Llen] > parent)
         break;
   Llen--;

   postorder(prestart + 1, Llen);
   postorder(prestart + Llen + 1, Tlen - Llen - 1);
   if (parent != 0)
      printf("%d ", parent);
}

int main() {
   int i = 0;
   while (scanf("%d", preorder + i++) != EOF);

   postorder(0, i);
}

