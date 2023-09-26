#include "sort.h"

/**
* swap_nodes - Swaps two nodes in a doubly linked list
* @list: Double pointer to the head of the doubly linked list
* @node1: First node to swap
* @node2: Second node to swap
*/
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
	if (node2->prev != NULL)
	{
		node2->prev->next = node2;
	}
}
/**
* cocktail_sort_list - Sorts a doubly linked list of integers in ascending
* order using the Cocktail shaker sort algorithm
* @list: listint_t list
*/
void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *node;

	node = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (node->next != NULL)
		{
			if (node->n > node->next->n)
			{
				swap_nodes(list, node, node->next);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
			else
			{
				node = node->next;
			}
		}
		if (swapped == 0)
		{
			break;
		}
		swapped = 0;
		while (node->prev != NULL)
		{
			if (node->prev->n > node->n)
			{
				swap_nodes(list, node->prev, node);
				swapped = 1;
				print_list((const listint_t *)*list);
			}
		}
	}
}
