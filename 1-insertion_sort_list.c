#include "sort.h"
/**
 * insertion_sort_list - sorted a list using the Insertion sort algorithm
 *
 * @list: The list to be sorted
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *guia;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	current = *list;
	/* guia point in the array */
	guia = *list;
	while (guia != NULL)
	{
		guia = guia->next;
		/* checks compare from the guia to the start */
		while (current->prev && (current->n < current->prev->n))
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->next->prev;
			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;
			current->next->prev = current;
			print_list(*list);
		}
		current = guia;
	}
}
