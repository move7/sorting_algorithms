#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort.
 *
 * @list: A pointer to the head of a doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		insertion_point = current->prev;

		while (insertion_point && insertion_point->n > current->n)
		{
			if (current->next)
				current->next->prev = insertion_point;
			insertion_point->next = current->next;
			current->next = insertion_point;
			current->prev = insertion_point->prev;
			insertion_point->prev = current;
			if (current->prev == NULL)
				*list = current;

			print_list(*list);

			insertion_point = current->prev;
		}

		current = current->next;
	}
}

