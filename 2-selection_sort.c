#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 *
 * @array: array to be sorted.
 *
 * @size: number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t smallest, i, j, tmp, smallest_ind;

	for (i = 0; i < size; i++)
	{
		smallest = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				smallest = array[j];
				smallest_ind = j;
			}
		}
		tmp = array[i];
		array[i] = smallest;
		array[smallest_ind] = tmp;
		print_array(array, size);
	}
}
