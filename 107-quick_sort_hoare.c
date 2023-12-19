#include "sort.h"

/**
 * hoare_partition - Hoare partition scheme using rightmost index as pivot
 * @array: array of integers to be sorted
 * @low: index in source array that begins partition
 * @high: index in source array that ends partition
 * @size: amount of elements in array
 * Return: new index at which to start new recursive partition
 */
int hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int a, b, pivot, tmp;

	pivot = array[high];
	a = low - 1;
	b = high + 1;
	while (1)
	{
		do {
			a++;
		} while (array[a] < pivot);
		do {
			b--;
		} while (array[b] > pivot);
		if (a == b)
			return (b - 1);
		else if (a > b)
			return (b);
		tmp = array[a];
		array[a] = array[b];
		array[b] = tmp;
		print_array(array, size);
	}
}

/**
 * hoare_quicksort - recursively sorts array of integers
 * @array: array of integers to be sorted
 * @low: index in source array that begins partition
 * @high: index in source array that ends partition
 * @size: amount of elements in array
 */
void hoare_quicksort(int *array, size_t low, size_t high, size_t size)
{
	size_t border;

	if (low < high)
	{
		border = hoare_partition(array, low, high, size);
		hoare_quicksort(array, low, border, size);
		hoare_quicksort(array, border + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts array of integers in ascending order 
 * @array: array of values to be printed
 * @size: number of elements in array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_quicksort(array, 0, size - 1, size);
}
