#include <stdio.h>
#include "sort.h"

/**
  * quick_sort - the function name
  * @array: parameter of type int *.
  * @size: parameter of type size_t .
  * Return: void .
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	_quick_sort(array, 0, size - 1, size);
}
/**
* _quick_sort - Recursive function to perform quick sort
*
* @array: Pointer to the array to be sorted
* @low: Lower index of the partition to be sorted
* @high: Upper index of the partition to be sorted
* @size: Size of the array
*/
void _quick_sort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);

		_quick_sort(array, low, pi - 1, size);
		_quick_sort(array, pi + 1, high, size);
	}
}

/**
  * lomuto_partition - the function name
  * @array: parameter of type int *.
  * @low: parameter of type int .
  * @high: parameter of type int .
  * @size: parameter of type size_t .
  * Return: int .
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
  * swap - the function name
  * @a: parameter of type int *.
  * @b: parameter of type int *.
  * Return: void .
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
