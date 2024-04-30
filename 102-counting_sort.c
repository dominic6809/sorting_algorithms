#include "sort.h"

/**
 * get_max - Finds the maximum element in an array
 * @array: The array to search
 * @size: Number of elements in the array
 *
 * Return: The maximum element in the array
 */
int get_max(int *array, int size)
{
	int max = array[0];
	int i = 1;

	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}

	return (max);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using Counting Sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Description: This function implements the Counting Sort algorithm to
 * sort the elements of the array in ascending order.
 * It prints the counting array once it is set up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted;
	int max, i = 0;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;

	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	i = 0;
	while (i < (max + 1))
	{
		count[i] = 0;
		i++;
	}

	i = 0;
	while (i < (int)size)
	{
		count[array[i]] += 1;
		i++;
	}

	i = 1;
	while (i < (max + 1))
	{
		count[i] += count[i - 1];
		i++;
	}

	print_array(count, max + 1);

	i = size - 1;
	while (i >= 0)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
		i--;
	}

	i = 0;
	while (i < (int)size)
	{
		array[i] = sorted[i];
		i++;
	}

	free(sorted);
	free(count);
}
