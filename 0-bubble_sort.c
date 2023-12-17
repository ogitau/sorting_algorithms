#include "sort.h"

/**
*bubble_sort - function that sorts integers in an ascending order
*@array: an array containing integers being sorted
*@size: size of the array of integers
*/

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	short int already_sorted = 0;
	int temp_array = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp_array = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp_array;
				already_sorted = 1;
				print_array(array, size);
			}
		}
		if (already_sorted == 0)
			break;
	}
}
