#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	check(int a, int n)
{
	return (n < a && fmod(sqrt(n), 1) == 0);
}

int	main(void)
{
	int	a;
	int	n;
	int	c;

	printf("A = ");
	scanf("%d", &a);
	c = 0;
	n = 1;
	printf("ENTER NUMBERS\n");
	while (n)
	{
		scanf("%d", &n);
		if (n && check(a, n))
			c++;
	}
	printf("COUNT : %d\n", c);
	return (0);
}