#include "sort.h"

/**
 * bubble_sort - function that sorts integers in an accessending order
 * @array: the array containing the integers being sorted
 * @size: the size of the elements in a given array of integers
 */

void bubble_sort(int *array, size_t size)
{
	size_t n, p;
	int temp_array;
	int already_sorted;

	if (!array || size < 2)
		return;

	for (n = 0; n < size - 1; n++)
	{
		already_sorted = 0;
		for (p = 0; p < size - p - 1; p++)
		{
			if (array[p] > array[p + 1])
			{
				temp_array = array[p];
				array[p] = array[p + 1];
				array[p + 1] = temp_array;
				already_sorted = 1;
				print_array(array, size);
			}
		}
		if (already_sorted == 0)
			break;
	}
}
