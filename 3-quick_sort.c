#include "sort.h"

/**
* quick_sort - sorts an array of integers in ascending order
*              using the Quick sort algorithm
* @array: array of integers
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	lomuto_sort(array, 0, size - 1, size);
}
/**
* lomuto_sort - sorts a partition of an array of integers
* @array: array of integers
* @low: low index of the partition to sort
* @high: high index of the partition to sort
* @size: size of the array
*/
void lomuto_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		lomuto_sort(array, low, pivot - 1, size);
		lomuto_sort(array, pivot + 1, high, size);
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
	int i = low - 1;
	int j;

	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (pivot < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
* swap - swaps the values of two integers
* @a: first integer
* @b: second integer
*/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
