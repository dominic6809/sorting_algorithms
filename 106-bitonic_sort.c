#include "sort.h"

/**
 * bitonic_merge - Merges two bitonic sequences in ascending order.
 * @array: The array to be sorted.
 * @low: Starting index of the first sequence.
 * @count: The number of elements in the sequence.
 * @dir: 1 for ascending order, 0 for descending order.
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
	size_t j = count / 2;
	size_t i;

	printf("Merging [%lu/%lu] (%s):\n", count, count, dir ? "UP" : "DOWN");
	print_array(array + low, count);

	for (i = low; i < low + j; i++)
	{
	if ((array[i] > array[i + j]) == dir)
	{
	int temp = array[i];

	array[i] = array[i + j];
	array[i + j] = temp;
	}
	}

	bitonic_merge(array, low, j, dir);
	bitonic_merge(array, low + j, j, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence.
 * @array: The array to be sorted.
 * @low: Starting index of the sequence.
 * @count: The number of elements in the sequence.
 * @dir: 1 for ascending order, 0 for descending order.
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	if (count > 1)
	{
	size_t k = count / 2;

	bitonic_sort_recursive(array, low, k, 1);
	bitonic_sort_recursive(array, low + k, k, 0);

	bitonic_merge(array, low, count, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	printf("%d", array[0]);
	bitonic_sort_recursive(array, 0, size, 1);
}
