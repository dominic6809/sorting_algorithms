#include "sort.h"

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
	size_t root = start;

	while ((root * 2) + 1 <= end)
	{
		size_t child = (root * 2) + 1;
		size_t swap = root;

		/* Find the largest child to swap with */
		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		/* If the root holds the largest element, return */
		if (swap == root)
			return;

		/* Swap the root with the largest child */
		int temp = array[root];

		array[root] = array[swap];

		array[swap] = temp;

		/* Print array after each swap */
		for (size_t i = 0; i < size; ++i)
			print_array(array, size);

		/* Move to the next level of the heap */
		root = swap;
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
	if (array == NULL || size <= 1)
		return;

	/* Build the heap */
	for (size_t start = (size / 2) - 1; start < size; --start)
		sift_down(array, size, start, size - 1);

	/* Perform heap sort */
	for (size_t end = size - 1; end > 0; --end)
	{
		/* Swap the root (largest element) with the last element */
		int temp = array[end];

		array[end] = array[0];
		array[0] = temp;

		/* Print array after each swap */
		for (size_t i = 0; i < size; ++i)
			print_array(array, size);

		/* Restore the heap property */
		sift_down(array, size, 0, end - 1);
	}
}
