#include "sort.h"

void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * max_heapify - Maintain the max heap property.
 * @array: The array to be heapified.
 * @size: The size of the array.
 * @base: The base index.
 * @root: The root index.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, largest;

	left = 2 * root + 1;
	right = 2 * root + 2;
	largest = root;

	if (left < base && array[left] > array[largest])
	largest = left;

	if (right < base && array[right] > array[largest])
	largest = right;

	if (largest != root)
	{
	int tmp = array[root];

	array[root] = array[largest];
	array[largest] = tmp;

	print_array(array, size);
	max_heapify(array, size, base, largest);
	}
}

/**
 * heap_sort - Sort an array of integers using heap sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
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
	int tmp = array[0];

	array[0] = array[i];
	array[i] = tmp;

	print_array(array, size);
	max_heapify(array, size, i, 0);
	}
}
