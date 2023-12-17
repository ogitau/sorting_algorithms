#include "sort.h"

/**
 * selection_sort - function that sorts integers in ascending order
 *                  using the Selection sort algorithm
 * @array: Pointer to the first element of the array of integers
 * @size: size of integers in an array being sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest_value;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		smallest_value = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest_value])
				smallest_value = j;
		}
		if (min_idx != i)
		{
			swap(&array[i], &array[smallest_value]);
			print_array(array, size);
		}
	}
}

/**
 * swap - a function that swaps the selected values of two integers
 * @first: Pointer to the selected first integer
 * @second: Pointer to the selected second integer
 */
void swap(int *first, int *second)
{
	int store = *first;
	*first = *second;
	*second = store;
}
