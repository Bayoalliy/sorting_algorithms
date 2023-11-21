#include "sort.h"

/*
int recurse_split(int *left, int *right, int *pivot, size_t size)
{
	int tmp;

	int *first_elem, *last_elem;
	if (pivot < left)
		return(0);

	first_elem = left;
	last_elem = pivot;

	while (first_elem < pivot)
	{
		if (*left > *pivot)
		{
			tmp = *first_elem;
			*first_elem = *right;
			*right = *pivot;
			*pivot = tmp;
			pivot--;
			right = pivot - 1;
		}
		else
			first_elem++;
	}

	printf("first_elem: %p\n", (void *)left);
	recurse_split(first_elem, right-1, pivot-1, size);
	recurse_split(pivot+1, last_elem-1, last_elem, size);
	return (0);
}




void quick_sort(int *array, size_t size)
{
	int *left, *right, *pivot;

	left = array;
	pivot = array + (size - 1);
	right = pivot - 1;

	printf("array: %p\n", (void *)left);
	recurse_split(left, right, pivot, size);

}
*/


/**
 * _qsort - auxiliar function for the
 * quick_sort function
 * @a: input arrray
 * @low: index for the first element
 * @high: index for the last element
 * @size: size of the array
 * Return: no return
 */
void _qsort(int *a, int low, int high, int size)
{
	int p, w, i;
	int tmp;

	if (low < high)
	{
		p = high;
		w = low;
		for (i = low; i < high; i++)
		{
			if (a[i] < a[p])
			{
				if (i != w)
				{
					tmp = a[i];
					a[i] = a[w];
					a[w] = tmp;
					print_array(a, size);
				}
				w++;
			}
		}
		if (w != p && a[w] != a[p])
		{
			tmp = a[w];
			a[w] = a[p];
			a[p] = tmp;
			print_array(a, size);
		}
		_qsort(a, low, w - 1, size);
		_qsort(a, w + 1, high, size);
	}
}

/**
 * quick_sort - function that sorts an array
 * of integers in ascending order using the
 * quick sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1, size);
}
