#include "sort.h"

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
	char *str_bubble, *filename;

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

	filename = "0-O";
	str_bubble = "O(n)\nO(n^2)\nO(n^2)";
	create_file(filename, str_bubble);
}
