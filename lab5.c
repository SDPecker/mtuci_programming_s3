#include <stdio.h>
#include <stdlib.h>
#define A 0
#define B 100
#define ARR_SIZE 30

int	*arr_generator(unsigned int size, int min, int max)
{
	unsigned int	i;
	int				*res;

	res = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		res[i] = min + rand() % (max - min);
		i++;
	}
	return (res);
}

void	print_arr(int *arr, unsigned int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i % 10 == 9 && i != 0)
			printf("%10i\n", arr[i]);
		else
			printf("%10i", arr[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	int	*arr;
	int	*mins;
	int	i;

	arr = arr_generator(ARR_SIZE, A, B);
	print_arr(arr, ARR_SIZE);
	mins = (int *)malloc(sizeof(int) * 3);
	i = 3;
	mins[0] = 0; mins[1] = 1; mins[2] = 2;
	while (i < ARR_SIZE)
	{
		if (arr[i] < arr[mins[0]])
		{
			mins[2] = mins[1];
			mins[1] = mins[0];
			mins[0] = i;
		}
		else if (arr[i] < arr[mins[1]])
		{
			mins[2] = mins[1];
			mins[1] = i;
		}
		else if (arr[i] < arr[mins[2]])
			mins[2] = i;
		i++;
	}
	printf("INDS = %3i %3i %3i\n", mins[0], mins[1], mins[2]);
	printf("SUM = %i\n", arr[mins[0]] + arr[mins[1]] + arr[mins[2]]);
	return(0);
}