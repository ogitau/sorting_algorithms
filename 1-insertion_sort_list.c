#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 *                        using insertion mode
 * @list: pointer to the doubly linked list head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *store;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curr = (*list)->next;
	while (curr != NULL)
	{
		store = curr->next;
		while (curr->prev != NULL && curr->n < curr->prev->n)
		{
			curr->prev->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = curr->prev;
			curr->next = curr->prev;
			curr->prev = curr->prev->prev;
			curr->next->prev = curr;
			if (curr->prev == NULL)
				*list = curr;
			else
				curr->prev->next = curr;
			print_list(*list);
		}
		curr = store;
	}
}
