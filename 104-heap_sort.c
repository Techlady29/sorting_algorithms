#include <stdio.h>
#include "sort.h"

/**
* swap - Swaps two integers in an array
* @array: The array containing the elements
* @a: Index of the first element
* @b: Index of the second element
*/
void swap(int *array, int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}

/**
* heapify - Builds a max heap from an array
* @array: The array to be turned into a heap
* @size: The size of the array
* @index: The index to start heapify from
*/
void heapify(int *array, size_t size, int index)
{
	int largest = index;
	int left_child, right_child;

	while (1)
	{
		left_child = 2 * index + 1;
		right_child = 2 * index + 2;

		if (left_child < (int)size && array[left_child] > array[largest])
			largest = left_child;

		if (right_child < (int)size && array[right_child] > array[largest])
			largest = right_child;

		if (largest != index)
		{
			swap(array, index, largest);
			print_array(array, size);
			index = largest;
		}
		else
		{
			break;
		}
	}
}

/**
* heap_sort - Sorts an array of integers in ascending order using Heap Sort
* @array: The array to be sorted
* @size: The size of the array
*/
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size <= 1)
		return;

	i = size / 2 - 1;
	while (i >= 0)
	{
		heapify(array, size, i);
		i--;
	}

	i = size - 1;
	while (i > 0)
	{
		swap(array, 0, i);
		print_array(array, size);
		heapify(array, i, 0);
		i--;
	}
}
