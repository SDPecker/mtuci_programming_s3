#include <stdio.h>
#include <math.h>
#define A -5
#define B 5
#define H 0.1

int	main(void)
{
	double	x;
	double	y;
	double	sum;
	int		i;

	x = A;
	i = 0;
	sum = 0;
	while (x <= B)
	{
		y = x * exp(x) + 2 * sin(x) - sqrt(fabs(pow(x, 3) - pow(x, 2)));
		sum += y;
		printf("X = %4.1f ; Y = %8.4f\n", x, y);
		if (fabs(x) < 1)
		{
			if (y > 0 && x >= 0 && y <= (1 - x))
				i++;
			else if (y <= 0 && x <=0 && x >= -1 && y >= -1)
				i++;
		}
		x += H;
	}
	printf("-----------------------\nSUM/NUM: %8.4f\n", sum / ((B - A) / H + 1));
	printf("RESULT : %i\n", i);
	return (0);
}