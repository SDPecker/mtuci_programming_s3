#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double	sum1(int n)
{
	double	sign;
	int		i;
	double	sum;

	sign = 1;
	i = 2;
	sum = 0;
	while (i <= n)
	{
		sum += sign * (i - 1) / (i * i * i * i - i);
		i++;
		sign *= -1;
	}
	return (sum);
}

double	sum2(double eps)
{
	double	diff;
	int		i;

	diff = sum1(3) - sum1(2);
	i = 3;
	while (fabs(diff) > eps)
	{
		i++;
		diff = sum1(i) - sum1(i - 1);
	}
	return(sum1(i));
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("SUM OF N : %f\n", sum1(atoi(av[1])));
		printf("SUM TO PREC EPS : %f \n", sum2(atof(av[2])));
	}
	return (0);
}