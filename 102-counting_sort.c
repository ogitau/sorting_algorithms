#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                the Counting sort algorithm
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max_value = 0;
	int index_looper = 1;
	int *array_counter = NULL;
	int *array_store = NULL;

	if (!array || size < 2)
		return;
	max_value = array[0];
	while (index_looper < (int)size)
	{
		if (array[index_looper] > max_value)
			max_value = array[index_looper];
		index_looper++;
	}
	array_store = malloc(sizeof(int) * size);
	if (!array_store)
		return;
	array_counter = malloc(sizeof(int) * (max_value + 1));
	if (!array_counter)
	{
		free(array_store);
		return;
	}
	for (index_looper = 0; index_looper <= max_value; ++index_looper)
		array_counter[index_looper] = 0;
	for (index_looper = 0; index_looper < (int)size; ++index_looper)
		array_counter[array[index_looper]]++;
	for (index_looper = 1; index_looper <= max_value; ++index_looper)
		array_counter[index_looper] = array_counter[index_looper - 1] + array_counter[index_looper];
	print_array(array_counter, max_value + 1);
	for (index_looper = 0; index_looper < (int)size; ++index_looper)
	{
		array_store[array_counter[array[index_looper]] - 1] = array[index_looper];
		array_counter[array[index_looper]]--;
	}
	for (index_looper = 0; index_looper < (int)size; ++index_looper)
		array[index_looper] = array_store[index_looper];
	free(array_counter);
	free(array_store);
	array_counter = array_store = NULL;
}
