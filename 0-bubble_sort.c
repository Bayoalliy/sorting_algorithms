#include "sort.h"

/**
 * bubble_sort - sort an array in ascending order.
 *
 * @array: array to be sorted.
 *
 * @size: size of the array.
 *
 * Return: Always 0
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, tmp, swap;

	while (swap)
	{
		swap = 0;

		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				swap = 1;
				print_array(array, size);
			}
		}
	}
}
