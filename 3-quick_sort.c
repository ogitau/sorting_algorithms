#include "sort.h"

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

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm (Lomuto partition scheme)
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    recursive_quick_sort(array, 0, size - 1);
}

/**
 * recursive_quick_sort - Recursively sorts a partition of an array using
 *                        the Quick sort algorithm (Lomuto partition scheme)
 * @array: Pointer to the first element of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void recursive_quick_sort(int *array, int low, int high)
{
    if (low < high)
    {
        int partition_index = lomuto_partition(array, low, high);
        print_array(array, high + 1);

        recursive_quick_sort(array, low, partition_index - 1);
        recursive_quick_sort(array, partition_index + 1, high);
    }
}

/**
 * lomuto_partition - Partitions an array using Lomuto partition scheme
 * @array: Pointer to the first element of the array
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: The final position of the pivot element
 */
int lomuto_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            if (i != j)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, high + 1);
            }
        }
    }

    if (array[i + 1] != array[high])
    {
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, high + 1);
    }

    return (i + 1);
}
