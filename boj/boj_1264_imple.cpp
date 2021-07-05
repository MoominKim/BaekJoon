#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char a[300];

int main()
{
	while (1)
	{
		int cnt = 0;
		scanf("%[^\n]", a);
		if (a[0] == '#' && strlen(a) == 1)
		{
			return 0;
		}
		getchar();
		a[strlen(a)] = '\0';

		for (int i = 0; i < strlen(a); i++)
		{
			if (a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U' || a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
			{
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
}