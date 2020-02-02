#include "sort.h"
/**
 * swap_sort - swap 2 nodes on double linked list
 *
 * @list: The list to be sorted
 * @ptr: node to change
 * @tmp: temporal node
 * Return: nothing
 */
void swap_sort(listint_t **list, listint_t *ptr, listint_t *tmp)
{
			ptr->prev->next = ptr->next;
			if (ptr->next != NULL)
				ptr->next->prev = ptr->prev;
			if (tmp == NULL)
			{
				tmp = *list;
				ptr->prev = NULL;
				ptr->next = tmp;
				ptr->next->prev = ptr;
				*list = ptr;
			}
			else
			{
				tmp = tmp->next;
				tmp->prev->next = ptr;
				ptr->prev = tmp->prev;
				tmp->prev = ptr;
				ptr->next = tmp;
			}
}
/**
 * insertion_sort_list - sorted a list using the Insertion sort algorithm
 *
 * @list: The list to be sorted
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur = NULL, *ptr = NULL, *tmp;
	int n;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	cur = *list;
	cur = cur->next;
	while (cur != NULL)
	{
		n = 0;
		ptr = cur;
		tmp = cur->prev;
		cur = cur->next;
		while (tmp != NULL && tmp->n > ptr->n)
		{
			n++;
			tmp = tmp->prev;
		}
		if (n)
		{
			swap_sort(list, ptr, tmp);
		}
		print_list(*list);
	}
}
