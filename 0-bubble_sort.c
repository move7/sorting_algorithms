#include "sort.h"


/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool swaped = True;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1 && swapped; i++)
	{
		swaped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swaped = true;
				print_array(array, size);
			}
		}
	}
}
