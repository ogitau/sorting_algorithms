#include "sort.h"

/**
 * selection_sort - function that sorts integers in ascending order
 *                  using the Selection sort algorithm
 * @array: Pointer to the first element of the array of integers
 * @size: size of integers in an array being sorted
 */
void selection_sort(int *array, size_t size)
{
	size_t m = 0;
	size_t n = 1;
	size_t swapper = 0;
	size_t smallest_value = 0;
	size_t length = size - 1;

	if (size < 2)
		return;
	while (m < length)
	{
		if (n == size)
		{
			if (m != smallest_value)
			{
				swapper = array[m];
				array[m] = array[smallest_value];
				array[smallest_value] = swapper;
				print_array(array, size);
			}
			++m;
			smallest_value = m;
			n = m + 1;
			continue;
		}
		if (array[smallest_value] > array[n])
			smallest_value = n;
		++n;
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
