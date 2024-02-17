#include "sort.h"

/**
 * shell_sort - Sorts an array of integers
 * @array: Pointer to the array of integers to be sorted
 * @size: Number of elements in the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Determine the starting gap value */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];

			array[j] = temp;
		}
		gap = (gap - 1) / 3;
	}
}
