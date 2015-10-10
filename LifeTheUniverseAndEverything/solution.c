#include <stdio.h>

int main()
{
	int a;
	int flag = 1;
	while (flag)
	{
		scanf("%d",&a);
		if (a == 42)
		{
			flag = 0;
		}
		else
		{
			printf("%d\n",a);
		}
	}
	return 0;
}
