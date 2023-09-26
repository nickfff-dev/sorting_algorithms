#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* insertion_sort_list - sorts a doubly linked list of integers
* in ascending order using the Insertion sort algorithm
* @list: The list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current)
	{
		temp = current;
		current = current->next;
		while (temp && temp->prev && temp->prev->n > temp->n)
		{
			temp->prev->next = temp->next;
			if (temp->next)
			{
				temp->next->prev = temp->prev;
			}
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (!temp->prev)
			{
				*list = temp;
			}
			print_list((const listint_t *)*list);
		}
	}
}
