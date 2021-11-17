#include <stdio.h>
#include <math.h>
#define A -5
#define B 5
#define H 0.1

int	main(void)
{
	double	x;
	double	f;
	double	sum;
	int		i;

	x = A;
	i = 0;
	sum = 0;
	while (x <= B)
	{
		f = x * exp(x) + 2 * sin(x) - sqrt(fabs(pow(x, 3) - pow(x, 2)));
		printf("X = %4.1f ; F = %8.4f\n", x, f);
		if (fmod(floor(f), 2) == 0 && f != 0) //0 не чётный
		{
			sum += f;
			i++;
		}
		x += H;
	}
	printf("-----------------------\nRESULT : %8.4f\n", sum / i);
	return(0);
}