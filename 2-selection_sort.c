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
 * selection_sort - selection sort algorithm
 *
 * @array: input array
 * @size: size of array
 * Description: sort and array using the selection sort algorithm
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, less;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		less = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[less])
				less = j;
		}

		if (less != i)
		{
			swap_int(&array[i], &array[less]);
			print_array(array, size);
		}
	}
}
