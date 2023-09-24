#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
#include <stdbool.h>

/**
* swap - Swaps two integers in an array.
* @a: Pointer to the first integer to swap.
* @b: Pointer to the second integer to swap.
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
* bubble_sort - Sorts an array of integers using Bubble Sort algorithm.
*
* @array: The array to be sorted.
* @size: Number of elements in the array.
*/
void bubble_sort(int *array, size_t size)
{
	bool swapped;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = true;
				print_array(array, size);
			}
		}

		if (!swapped)
			break;
	}
}
