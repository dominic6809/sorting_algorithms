#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge - Merges two subarrays into one sorted array
 * @array: The array to sort
 * @tmp: Temporary array to store merged elements
 * @l: Start index of left subarray
 * @m: Middle index
 * @r: End index of right subarray
 */
void merge(int *array, int *tmp, size_t l, size_t m, size_t r)
{
	size_t i = l, j = m, k = 0;

	printf("[Merging...]\n");
	printf("[left]: ");
	print_array(array + l, m - l);
	printf("[right]: ");
	print_array(array + m, r - m);

	while (i < m && j < r)
		tmp[k++] = (array[i] < array[j]) ? array[i++] : array[j++];

	while (i < m)
		tmp[k++] = array[i++];

	while (j < r)
		tmp[k++] = array[j++];

	for (i = l, k = 0; i < r; ++i, ++k)
		array[i] = tmp[k];

	printf("[Done]: ");
	print_array(array + l, r - l);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using Merge sort
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	size_t middle = size / 2;
	int *tmp = malloc(sizeof(int) * size);

	if (size < 2)
		return;

	if (!tmp)
		return;

	merge_sort(array, middle);
	merge_sort(array + middle, size - middle);
	merge(array, tmp, 0, middle, size);

	free(tmp);
}

