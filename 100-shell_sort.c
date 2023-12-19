#include "sort.h"

/**
 * shell_sort - function sorting integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence.
 * @array: Pointer to the first element of the array of integers
 * @size: size of the integers in the array being sorted
 */
void shell_sort(int *array, size_t size)
{
	int inner_loop = 0;
	int outer_loop = 0;
	int gap = 1;
	int swapper = 0;

	if (!array || size < 2)
		return;
	while (gap < (int)size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		outer_loop = gap;
		while (outer_loop < (int)size)
		{
			swapper = array[outer_loop];
			inner_loop = outer_loop;
			while (inner_loop > gap - 1 && array[inner_loop - gap] >= swapper)
			{
				array[inner_loop] = array[inner_loop - gap];
				inner_loop = inner_loop - gap;
			}
			array[inner_loop] = swapper;
			outer_loop++;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
