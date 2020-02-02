#include "sort.h"
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
	char *str_selection, *filename;

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

	filename = "2-O";
	str_selection = "O(n^2)\nO(n^2)\nO(n^2)";
	create_file(filename, str_selection);
}
