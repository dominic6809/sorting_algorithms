#include "sort.h"

void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
void swap_ints(int *x, int *y);

/**
  * swap_ints - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 * Description: This function performs the swap_ints operation
 * on the heap to maintain the heap property.
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @end: The root node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t end)
{
	size_t left, right, large;

	left = 2 * end + 1;
	right = 2 * end + 2;
	large = end;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != end)
	{
		swap_ints(array + end, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using Heap Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Description: This function implements the Heap Sort algorithm to
 * sort the elements of the array in ascending order. It prints the array
 * after each time two elements are swapped.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
	return;

	for (i = size / 2 - 1; i >= 0; i--)
	max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
