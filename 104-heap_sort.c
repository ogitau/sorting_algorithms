#include "sort.h"
/**
 * swap - function that swap two element
 * @x: first element
 * @y: second element
 */
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * heapify - heapify operation
 * @array: the array
 * @size: size of array
 * @index: the index
 * @heap: updated size of array
 */
void heapify(int *array, size_t size, size_t  index, size_t heap)
{
	size_t largest = index;
	size_t left = (index * 2) + 1;
	size_t  right = (index * 2) + 2;

	if (left < heap && array[left] > array[largest])
		largest = left;

	if (right < heap && array[right] > array[largest])
		largest = right;
	if (largest != index)
	{
		swap(&array[index], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest, heap);
	}

}
/**
 * heap_sort - sort array using heap algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1 ; i >= 0; i--)
	{
		heapify(array, size, i, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, 0, i);

	}
}
