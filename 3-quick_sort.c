#include "sort.h"
/**
 * swap_int - swap two numbers
 * @a: firts number
 * @b: second number
 *
 * Description: Write a function that swaps the values of two integers
 */
void swap_int(int *a, int *b)
{
	int x;

	x = *a;
	*a = *b;
	*b = x;
}

/**
 * lomuto_part - implements lomuto partition
 * @array: input array
 * @low: low index in array
 * @high: high index array
 * @size: size of array
 *
 * Return: position for next iteration
 */
int lomuto_part(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j, i = low;

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap_int(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * apply_quicksort - quick sort algorithm
 * @array: input array
 * @low: low index in array
 * @high: high index array
 * @size: size of array
 *
 * Description: implements quick sort algorithm
 */
void apply_quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_part(array, low, high, size);

		apply_quicksort(array, low, pivot - 1, size);
		apply_quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - initializes quick sort
 * @array: input array
 * @size: size of array
 *
 * Description: call function quick sort
 */

void quick_sort(int *array, size_t size)
{
	/*int low, high;*/

	if (array == NULL || size < 2)
		return;

	/*low = 0;*/
	/*high = size - 1;*/
	apply_quicksort(array, 0, size - 1, size);
}
