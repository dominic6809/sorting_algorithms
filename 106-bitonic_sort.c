#include "sort.h"

/**
 * bitonic_merge - Merge the array in ascending order
 * @array: The array to be sorted
 * @size: Size of the array
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 *
 * Description: This function recursively merges the array in ascending
 * order if dir is 1, and in descending order if dir is 0.
 */
void bitonic_merge(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t k = size / 2;
        for (size_t i = 0; i < k; ++i)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                // Swap the elements
                int temp = array[i];
                array[i] = array[i + k];
                array[i + k] = temp;
                printf("Merging: ");
                for (size_t j = 0; j < size; ++j)
                    printf("%d ", array[j]);
                printf("\n");
            }
        }
        bitonic_merge(array, k, dir);
        bitonic_merge(array + k, k, dir);
    }
}

/**
 * bitonic_sort_recursive - Sorts the bitonic sequence recursively
 * @array: The array to be sorted
 * @size: Size of the array
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 *
 * Description: This function recursively sorts the array in bitonic
 * sequence defined by the given direction (ascending or descending).
 */
void bitonic_sort_recursive(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t k = size / 2;
        bitonic_sort_recursive(array, k, 1);
        bitonic_sort_recursive(array + k, k, 0);
        bitonic_merge(array, size, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using Bitonic Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array (must be a power of 2)
 *
 * Description: This function sorts the elements of the array in ascending order
 * using the Bitonic Sort algorithm.
 * It prints the array each time two elements are swapped.
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    bitonic_sort_recursive(array, size, 1);
}
