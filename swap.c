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
