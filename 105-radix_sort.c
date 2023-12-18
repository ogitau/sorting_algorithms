#include "sort.h"
#include <stdlib.h>

/**
 * init_bucket_count - resets bucket_count values to 0
 * @bucket_count: array containing amounts of members for arrays in `buckets`
 */
void init_bucket_count(int *bucket_count)
{
	int i;

	for (i = 0; i < 10; i++)
		bucket_count[i] = 0;
}

/**
 * build_buckets - allocates space for arrays to be held in `buckets`
 * @buckets: array of arrays each containing sorted members of `array`
 * @bucket_count: array containing amounts of members for arrays in `buckets`
 */
void build_buckets(int *bucket_count, int **buckets)
{
	int *bucket;
	int i;

	for (i = 0; i < 10; i++)
	{
		bucket = malloc(sizeof(int) * bucket_count[i]);
		if (!bucket)
		{
			for (; i > -1; i--)
				free(buckets[i]);
			free(buckets);
			exit(EXIT_FAILURE);
		}
		buckets[i] = bucket;
	}
	init_bucket_count(bucket_count);
}

/**
 * find_max - searches array of integers for highest value
 * @array: array of values to be searched
 * @size: number of elements in array
 * Return: largest integer stored in array
 */
int find_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * into_array - flattens buckets into array sorted by current digit place,
 * @array: array of values to be printed
 * @size: number of elements in array
 * @buckets: array of arrays each containing sorted members of `array`
 * @bucket_count: array containing amounts of members for arrays in `buckets`
 */
void into_array(int *array, size_t size, int **buckets, int *bucket_count)
{
	int i, j, k;


	for (k = 0, i = 0; k < 10; k++)
	{
		for (j = 0; j < bucket_count[k]; j++, i++)
			array[i] = buckets[k][j];
	}

	print_array(array, size);

	for (i = 0; i < 10; i++)
		free(buckets[i]);
}

/**
 * radix_sort - Sorts array of integers in ascending order using a Radix sort
 * @array: array of values to be sorted
 * @size: number of elements in array
 */
void radix_sort(int *array, size_t size)
{
	int **buckets;
	int bucket_count[10];
	int max, max_digits, pass, divisor, digit;
	size_t i;

	if (!array || size < 2)
		return;
	buckets = malloc(sizeof(int *) * 10);
	if (!buckets)
		exit(1);

	max = find_max(array, size);
	for (max_digits = 0; max > 0; max_digits++)
		max /= 10;

	for (pass = 0, divisor = 1; pass < max_digits; pass++, divisor *= 10)
	{
		init_bucket_count(bucket_count);

		for (i = 0; i < size; i++)
		{
			digit = (array[i] / divisor) % 10;
			bucket_count[digit]++;
		}
		build_buckets(bucket_count, buckets);

		for (i = 0; i < size; i++)
		{
			digit = (array[i] / divisor) % 10;
			buckets[digit][bucket_count[digit]] = array[i];
			bucket_count[digit]++;
		}
		into_array(array, size, buckets, bucket_count);
	}
	free(buckets);
}
