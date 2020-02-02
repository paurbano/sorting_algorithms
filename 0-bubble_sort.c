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
 * bubble_sort - sort by bubble algorithm
 *
 * @array: input array
 * @size: lenght of array
 * Description: sort an array by bubbe algorithm
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	bool ordered = false;

	if (array == NULL || size == 0)
		return;

	while (!ordered)
	{
		ordered = true;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap_int(&array[i - 1], &array[i]);
				print_array(array, size);
				ordered = false;
			}
		}
	}

}
