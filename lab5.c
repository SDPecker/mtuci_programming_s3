#include <stdio.h>
#include <stdlib.h>
#define A 0
#define B 100
#define ARR_SIZE 30

int	*arr_generator(unsigned int size, unsigned int min, unsigned int max)
{
	unsigned int	i;
	int				*res;

	res = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		res[i] = min + rand() % (max - min);
	}
	return (res);
}

int	main(void)
{
	int	*arr;
	int	*mins;
	int	i;
	int	j;
	int	sum;

	arr = arr_generator(ARR_SIZE, A, B);
	mins = (int *)malloc(sizeof(int) * 3);
	i = 1;
	j = 0;
	sum = 0;
	while (j < 3)
	{
		mins[j] = 0;
		while (i < ARR_SIZE)
		{
			if (arr[i] < arr[mins[j]] && (j != 0 &&))
				mins[j] = i;
			i++;
		}
		i = 0;
		j++;
	}
	
}