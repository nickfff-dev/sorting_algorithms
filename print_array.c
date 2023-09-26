#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
  * print_array - the function name
  * @array: parameter of type const int *.
  * @size: parameter of type size_t .
  * Return: void .
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
		{
			printf(", ");
		}
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
