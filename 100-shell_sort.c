#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Description: This function implements the Shell Sort algorithm using
 * the Knuth sequence of intervals to sort the elements of the array in
 * ascending order. It prints the array each time the interval decreases.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int temp;

	if (array == NULL || size <= 1)
		return;

	/* Calculate initial gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		/* Perform insertion sort for the current gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}
		print_array(array, size);
		gap /= 3; /* Reduce gap using Knuth sequence */
	}
}
