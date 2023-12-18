#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge_sort - A function that sorts an array using merge algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */

void merge_sort(int *array, size_t size)
{
	size_t idx = 0;
	int *base = NULL;

	if (array == NULL || size < 2)
		return;
	base = malloc(sizeof(int) * size);
	if (base == NULL)
		return;
	for(; idx < size; idx++)
		base[idx] = array[idx];
	merge_partition(0, size, array, base);
	free(base);
}

/**
 * merge - A function that sorts the subarrays.
 * @low: Lower index.
 * @midd: Middle index.
 * @high: Higher index.
 * @dest: Destination for data.
 * @src: source of data
 * Return: Nothing
 */
void merge(size_t low, size_t midd, size_t high, int *dest, int *src)
{
	size_t a = 0, b = 0, c = 0;

	printf("Merging....\n");
	printf("[left]: ");
	print_array(src + low, midd - low);
	printf("[right]: ");
	print_array(src + midd, high - midd);
	a = low;
	b = midd;
	c = low;

	for(; c < high; c++)
	{
		if (a < midd && (b >= high || src[a] <= src[b]))
		{
			dest[c] = src[a];
			a++;
		}
		else
		{
			dest[c] = src[b];
			b++;
		}
	}
	printf("[Done]: ");
	print_array(dest + low, high - low);
}

/**
 * merge_partition - A funtion that splits the array recursively.
 * @low: Lower index.
 * @high: Higher index.
 * @array: The array to sort.
 * @base: The copy of the array.
 * Return: Nothing.
 */

void merge_partition(size_t low, size_t high, int *array, int *base)
{
	size_t midd = 0;

	if (high - low < 2)
		return;
	midd = (low + high) / 2;
	merge_partition(low, midd, array, base);
	merge_partition(midd, high, array, base);
	merge(low, midd, high, array, base);
	for (midd = low; midd < high; midd++)
		base[midd] = array[midd];
}
