#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list of integers
* in ascending order using the Insertion sort algorithm
* @list: The list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		prev = current->prev;
		while (prev != NULL && prev->n > temp->n)
		{
			prev->next = temp->next;
			if (temp->next != NULL)
			{
				temp->next->prev = prev;
			}
			temp->next = prev;
			temp->prev = prev->prev;
			prev->prev = temp;
			prev = temp->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
