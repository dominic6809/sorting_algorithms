#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 * @list: The list to be printed
 *
 * Description: This function prints the elements of a linked list of integers,
 * separated by commas, followed by a newline character.
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}
