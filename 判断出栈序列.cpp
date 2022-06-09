#include<cstdio>
#include<cstring>
#include<stack>
#include<cstdlib>
using namespace std;
int a[100000] = { 0 }, b[100000] = { 0 };
int main()
{
	int n = 0, m = 0;
	int flag = 0;
	while (~scanf("%d%d", &n, &m) && n+m)
	{
		if (flag)
			printf("\n");
		for (int i = 1; i <= n; i++)
		{
			a[i] = i;
		}
		while (m--)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &b[j]);
			}
			stack<int>s;
			int x = 1, y = 1;
			while (y <= n)
			{
				if (a[x] == b[y])
				{
					x++;
					y++;
				}
				else if (!s.empty() && s.top() == b[y])
				{
					y++;
					s.pop();
				}
				else if (x <= n)
				{
					s.push(a[x]);
					x++;
				}
				else
					break;
			}
			if (s.empty())
				printf("Yes\n");
			else
				printf("No\n");
		}
		flag = 1;
	}
	return 0;
}
