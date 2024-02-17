#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 * @array: The array to sort
 * @size: Number of elements in the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursively sorts an array of integer
 * @array: The array to be sorted
 * @lo: The starting index of the partition to be sorted
 * @hi: The ending index of the partition to be sorted
 * @size: Number of elements in @array
 */

void quick_sort_recursive(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quick_sort_recursive(array, lo, p - 1, size);
		quick_sort_recursive(array, p + 1, hi, size);
	}
}

/**
 * partition - Partitions an array of integers
 * @array: The array to be partitioned
 * @lo: The starting index of the partition to be partitioned
 * @hi: The ending index of the partition to be partitioned
 * @size: Number of elements in
 * Return: the pivot element position
 */

int partition(int *array, int lo, int hi, size_t size)
{
	int i, j, pivot, tmp;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[hi])
	{
		tmp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}
