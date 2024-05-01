#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Cocktail shaker sort algorithm
 *
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = *list, *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		while (start && start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(start, start->next);
				if (!start->prev)
					*list = start;
				swapped = 1;
				print_list(*list);
			}
			else
				start = start->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		end = start;
		while (start && start->prev != NULL)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(start->prev, start);
				if (!start->prev)
					*list = start;
				swapped = 1;
				print_list(*list);
			}
			else
				start = start->prev;
		}
	}
}

