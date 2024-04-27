#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using Counting Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Description: This function implements the Counting Sort algorithm to
 * sort the elements of the array in ascending order. It prints the counting
 * array once it is set up.
 */
void counting_sort(int *array, size_t size)
{
	int *count;
	int *sorted;
	int x;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	int max = array[0];

	for (x = 1; x < (int)size; x++)
	{
	if (array[x] > max)
	max = array[x];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
	free(count);
	return;
	}

	for (x = 0; x <= max; x++)
	count[x] = 0;

	for (x = 0; x < (int)size; x++)
	count[array[x]] += 1;

	print_array(count, max + 1);

	for (x = 0; x < (int)size; x++)
	{
	sorted[count[array[x]] - 1] = array[x];
	count[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
	array[x] = sorted[x];

	free(sorted);
	free(count);
}
