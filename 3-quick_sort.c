#include "sort.h"

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int above = left;
	int below;

	for (below = left; below < right; below++)
	{
		if (array[below] < pivot)
		{
			if (above != below)
			{
				int temp = array[below];

				array[below] = array[above];
				array[above] = temp;
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > pivot)
	{
		int temp = array[above];

		array[above] = array[right];
		array[right] = temp;
		print_array(array, size);
	}

	return (above);
}

/**
 * quick_sort - Sort an array of integers in ascending.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

/**
 * lomuto_sort - Implement the quicksort algorithm.
 *
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index.
 * @right: The ending index.
 *
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	if (left < right)
	{
		int part = lomuto_partition(array, size, left, right);

		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

