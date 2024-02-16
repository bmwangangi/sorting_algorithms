#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * using insertion algorithm
 * @list: doubly linked list of integers
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		if (current->prev != NULL && current->prev->n > current->n)
		{
			listint_t *prev = current->prev;

			while (prev != NULL && prev->n > current->n)
			{
				listint_t *tmp = prev->prev;

				prev->prev = current;
				prev->next = current->next;
				if (current->next != NULL)
					current->next->prev = prev;
				current->next = prev;
				current->prev = tmp;
				if (tmp == NULL)
					*list = current;
				else
					tmp->next = current;
				prev = current->prev;
				print_list(*list);
			}
			current = current->next;
		}
		else
		{
			current = current->next;
		}
	}
}
