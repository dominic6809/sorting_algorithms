#include "sort.h"

void sift_down(int *array, size_t size, size_t start, size_t end);
void heap_sort(int *array, size_t size);

/**
 * sift_down - Perform the sift-down operation on the heap
 * @array: The array representing the heap
 * @size: Size of the heap
 * @start: Index of the root node of the heap
 * @end: Index of the last node of the heap
 *
 * Description: This function performs the sift-down operation
 * on the heap to maintain the heap property.
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t left, right, largest;

	left = 2 * start + 1;
	right = 2 * start + 2;
	largest = start;

	if (left < end && array[left] > array[largest])
	largest = left;

	if (right < end && array[right] > array[largest])
	largest = right;

	if (largest != start)
	{
	/* Swap elements directly without a separate swap function*/
	int tmp = array[start];

	array[start] = array[largest];
	array[largest] = tmp;

	print_array(array, size);
	sift_down(array, size, start, largest);
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
	sift_down(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
	/* Swap elements directly without a separate swap function*/
	int tmp = array[0];

	array[0] = array[i];
	array[i] = tmp;

	print_array(array, size);
	sift_down(array, size, i, 0);
	}
}
