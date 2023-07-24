#include "sort.h"

/**
 * selection_sort - Sort an array of integers in ascending order
 *
 * @array: An array.
 * @size: The size.
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		size_t min_idx = i;
		
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (min_idx != i)
		{
			int temp = array[i];
			
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
