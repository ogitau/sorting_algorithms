#include "sort.h"
#include <stdio.h>

/**
 * bitonic_compare_ascending - helper to bitonic_merge
 * @x: subarray in current frame of recursion
 * @size: number of elements in `x`
 */
void bitonic_compare_ascending(int *x, size_t size)
{
	size_t dist, idx;
	int temp;

	dist = size / 2;
	for (idx = 0; idx < dist; idx++)
	{
		if (x[idx] > x[idx + dist])
		{
		temp = x[idx];
		x[idx] = x[idx + dist];
		x[idx + dist] = temp;
		}
	}
}

/**
 * bitonic_compare_descending - helper to bitonic_merge
 * @x: subarray in current frame of recursion
 * @size: number of elements in `x`
 */
void bitonic_compare_descending(int *x, size_t size)
{
	size_t dist, idx;
	int temp;

	dist = size / 2;
	for (idx = 0; idx < dist; idx++)
	{
		if (x[idx] < x[idx + dist])
		{
		temp = x[idx];
		x[idx] = x[idx + dist];
		x[idx + dist] = temp;
		}
	}
}
/**
 * bitonic_merge - second recursive function of bitonic_sort
 * @x: subarray in previous frame of recursion
 * @size: number of elements in `x`
 * @orig_size: number of elements in source array being sorted
 */
void bitonic_merge(int *x, size_t size, size_t orig_size)
{
	int *first, *second;

	if (size > 1)
	{
		first = x;
		second = x + (size / 2);
		bitonic_compare_ascending(x, size);
		bitonic_merge(first, size / 2, orig_size);
		bitonic_merge(second, size / 2, orig_size);
	}
}

/**
 * bitonic_sort_r - first recursive engine of bitonic_sort
 * @x: subarray in previous frame of recursion
 * @size: number of elements in `x`
 * @orig_size: number of elements in source array being sorted
 */
void bitonic_sort_r(int *x, size_t size, size_t orig_size)
{
	int *first, *second;

	if (size <= 1)
		return;

	first = x;
	second = x + (size / 2);
	printf("Merging [%lu/%lu] (UP):\n", size, orig_size);
	print_array(x, size);
	bitonic_sort_r(first, size / 2, orig_size);
	bitonic_sort_r(second, size / 2, orig_size);
	bitonic_merge(x, size, orig_size);
	printf("Result [%lu/%lu] (UP):\n", size, orig_size);
	print_array(x, size);
}

/**
 * bitonic_sort - sorts array of integers in ascending order using a bitonic
 * sort algorithm
 * @array: array of values to be printed
 * @size: number of elements in array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;
	bitonic_sort_r(array, size, size);
}

