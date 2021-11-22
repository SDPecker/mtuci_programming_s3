#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

int	rearrange(int n)
{
	int	res;
	int	tmp;

	res = n % 10;
	tmp = n;
	while (tmp / 10 > 0)
	{
		tmp /= 10;
		res = res * 10 + tmp % 10;
	}
	return(res);
}

int	check_prime(int	n)
{
	int	i;
	i = 3;
	if (n <= 0 || n % 2)
		return (0);
	while (i <= sqrt(n))
	{
		if (!(n % i))
			return (0);
		i += 2;
	}
	return (1);
}

int	q_ind(int *arr)
{
	int	i;
	int	fl;
	int res;

	i = 0;
	fl = 0;
	res = -1;
	while (arr[i] && res < 0)
	{
		if (arr[i] % 2 == 1)
			res = i;
		i++;
	}
	if (res < 0)
		return (-1);
	while (arr[i])
	{
		if (arr[i] % 2 == 1 && arr[i] < arr[res])
			res = i;
		i++;
	}
	return (res);
}

void	arr_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	buf;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = 1;
		while (j < size)
		{
			if (arr[j] < arr[j - 1])
			{
				buf = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = buf;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int	*arr;
	int	q;
	int	i;
	i = 0;

	arr = arr_generator(ARR_SIZE, A, B);
	print_arr(arr, ARR_SIZE);
	q = q_ind(arr);
	printf("Q INDEX : %i ; Q VALUE : %i\n", q, arr[q]);
	while (i < ARR_SIZE)
	{
		if (!check_prime(arr[i]))
			arr[i] = rearrange(arr[i]);
		i++;
	}
	printf("-----APPLYING T ACTIONS-----\n");
	print_arr(arr, ARR_SIZE);
	printf("-----SORTING ARRAY-----\n");
	arr_sort(arr, ARR_SIZE);
	print_arr(arr, ARR_SIZE);
	return (0);
}