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
    int *count, *output;
    int max_value = 0, i;

    if (array == NULL || size < 2)
        return;

    /* Find the maximum value in the array */
    for (i = 0; i < (int)size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    count = malloc((max_value + 1) * sizeof(int));
    if (count == NULL)
        return;

    output = malloc(size * sizeof(int));
    if (output == NULL)
    {
        free(count);
        return;
    }

    /* Initialize count array with zeros */
    for (i = 0; i <= max_value; i++)
        count[i] = 0;

    /* Count the frequency of each element in the array */
    for (i = 0; i < (int)size; i++)
        count[array[i]]++;

    /* Compute the prefix sum of the count array */
    for (i = 1; i <= max_value; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (i = (int)size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the sorted elements back to the original array */
    for (i = 0; i < (int)size; i++)
        array[i] = output[i];

    /* Print the count array */
    printf("%d", count[0]);
    for (i = 1; i <= max_value; i++)
        printf(", %d", count[i]);
    printf("\n");

    free(count);
    free(output);
}
