#include "sort.h"
/**
 * printsub - function that print a sub array
 * @array: array to be printed
 * @start: start
 * @end: end
 */
void printsub(int *array, size_t start, size_t end)
{
	size_t i;

	for (i = start; i < end; i++)
	{
		if (i != (end - 1))
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}

}
/**
 * TDmerge - Turn down algo
 * @array: array
 * @sorted: sorted sub array
 * @l: start
 * @r: end
 */
void TDmerge(int *array, int *sorted, size_t l, size_t r)
{
	size_t i, j, k;
	size_t m = (r + l) / 2;

	if (r - l <= 1)
		return;

	TDmerge(array, sorted, l, m);
	TDmerge(array, sorted, m, r);
	printf("Merging...\n");
	printf("[left]: ");
	printsub(array, l, m);
	printf("[right]: ");
	printsub(array, m, r);

	i = l;
	j = m;
	for (k = l; k < r; k++)
	{
		if ((i < m) && (j == r || array[i] < array[j]))
		{
			sorted[k] = array[i];
			i++;
		}
		else
		{
			sorted[k] = array[j];
			j++;
		}
	}
	printf("[Done]: ");
	printsub(sorted, l, r);

	for (i = l; i < r; i++)
		array[i] = sorted[i];
}
/**
 * merge_sort - merge sort algo
 * @array: array to be sorted
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *sorted;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);

	if (sorted == NULL)
		return;

	TDmerge(array, sorted, 0, size);
	free(sorted);
}
