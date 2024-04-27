#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using Selection Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Description: This function implements the Selection Sort algorithm to
 * sort the elements of the array in ascending order. It prints the array
 * after each swap operation.
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, k = 0, min_index = 0;
	int temp;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (k = i + 1; k < size; k++)
		{
			if (array[k] < array[min_index])
				min_index = k;
		}

		if (min_index != i)
		{
			/* Swap array[i] and array[min_index] */
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
