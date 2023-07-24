#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort.
 * @list: A pointer to the head of a doubly-linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		insert = current->prev;
		while (insert != NULL && current->n < insert->n)
		{
			if (current->next != NULL)
				current->next->prev = insert;
			if (insert->prev != NULL)
				insert->prev->next = current;
			else
				*list = current;
			current->prev = insert->prev;
			insert->next = current->next;
			current->next = insert;
			insert->prev = current;
			print_list((const listint_t *)*list);
			insert = current->prev;
		}
	}
}

