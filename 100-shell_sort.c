#include "sort.h"

/**
 * shell_sort - function sorting integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence.
 * @array: Pointer to the first element of the array of integers
 * @size: size of the integers in the array being sorted
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, k, m;
	int store;

	if (array == NULL || size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (k = gap; k < size; k++)
		{
			store = array[k];
			for (m = k; m >= gap && array[m  - gap] > store; /
					m -= gap)
				array[m] = array[m - gap];
			array[m] = store;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
