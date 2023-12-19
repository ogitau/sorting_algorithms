#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - Recursive function for Quick sort algorithm
 * @array: The array of integers to be sorted
 * @lower: The lower index of the current partition
 * @higher: The higher index of the current partition
 * @size: The size of the array
 */
void quick_sort_rec(int *array, int lower, int higher, size_t size)
{
	int l_p = 0;

	if (lower < higher)
	{
		l_p = lomuto_partition(array, lower, higher, size);
		quick_sort_rec(array, lower, l_p - 1, size);
		quick_sort_rec(array, l_p + 1, higher, size);
	}
}

/**
 * lomuto_partition - Performs the Lomuto partition scheme for Quick sort
 * @array: The array of integers to be sorted
 * @lower: The lower index of the current partition
 * @higher: The higher index of the current partition
 * @size: The size of the array
 * Return: Index of the pivot after partitioning
 */
int lomuto_partition(int *array, int lower, int higher, size_t size)
{
	int i = 0, j = 0, pivot = 0, aux = 0;

	pivot = array[higher];
	i = lower;

	for (j = lower; j < higher; ++j)
	{
		if (array[j] < pivot)
		{
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			if (aux != array[i])
				print_array(array, size);
			++i;
		}
	}
	aux = array[i];
	array[i] = array[higher];
	array[higher] = aux;
	if (aux != array[i])
		print_array(array, size);
	return (i);
}
