#include "sort.h"
/**
 * determines_k - find the max value in aray
 * @array: input array
 * @size: size of array
 *
 * Description: find the max integer in array
 * Return: max
 */
int determines_k(int *array, size_t size)
{
	size_t i;
	int k = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	return (k);
}
/**
 * counting_sort - count sort algorithm
 * @array: input array
 * @size: size of array
 *
 * Description: use se Count Sort algorithm
 */
void counting_sort(int *array, size_t size)
{
	size_t i, key, key_o;
	int k = 0, j;
	int *count_array, *output;

	if (array == NULL || size < 2)
		return;

	/*determines k */
	k = determines_k(array, size);

	count_array = calloc((k + 1), sizeof(int));
	output = malloc(sizeof(int) * size);

	if (count_array == NULL || output == NULL)
		return;

	/* fills count array */
	for (i = 0; i < size; i++)
	{
		key = array[i];
		count_array[key]++;
	}
	for (j = 1; j < (k + 1); j++)
		count_array[j] += count_array[j - 1];

	print_array(count_array, k + 1);

	for (i = 0; i < size; i++)
	{
		key = array[i];
		key_o = count_array[key - 1];
		output[key_o] = array[i];
		count_array[key]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count_array);
	free(output);
}
