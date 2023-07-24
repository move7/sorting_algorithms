#include "sort.h"


/**
 * insertion_sort_list - Sorts a doubly linked list.
 *
 * @list: A pointer to the head of a doubly-linked list.
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t  *current = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (current)
	{
		listint_t *next_node = current->next;
		listint_t *prev_node = current->prev;

		while (prev_node && prev_node->n > current->n)
		{
			prev_node->next = current->next;
			current->next = prev_node;
			current->prev = prev_node->prev;
			prev_node = prev_node->prev;
			print_list((const listint_t *)*list);
		}
		current = next_node;
	}
}
