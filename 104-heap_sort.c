#include "sort.h"

/**
 * swap_root - A function that swap the root nodes.
 * @array: The heap to sort.
 * @root: The root of the heap.
 * @hi: The higher index.
 * @size: The size of the array.
 * Return: Nothing
 */
void swap_root(int *array, size_t root, size_t high, size_t size)
{
	size_t low = 0, midd = 0, tmp = 0;
	int ax = 0;

	while ((low = (2 * root + 1)) <= high)
	{
		tmp = root;
		midd = low + 1;
		if (array[tmp] < array[low])
			tmp = low;
		if (midd <= high && array[tmp] < array[midd])
			tmp = midd;
		if (tmp == root)
			return;
		ax = array[root];
		array[root] = array[tmp];
		array[tmp] = ax;
		print_array(array, size);
		root = tmp;
	}
}

/**
 * heap_sort - A function that sorts an array using heap algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void heap_sort(int *array, size_t size)
{
	size_t high = 0, gp = 0;
	int tmp = 0;

		if (array == NULL || size < 2)
			return;

		for (gp = (size - 2) / 2; 1; gp--)
		{
			swap_root(array, gp, size - 1, size);
			if (gp == 0)
				break;
		}

		high = size - 1;
		while (high > 0)
	{
		tmp = array[high];
		array[high] = array[0];
		array[0] = tmp;
		print_array(array, size);
		high--;
		swap_root(array, 0, high, size);
	}
}
