#include <stdio.h>
#include <stdlib.h>

/**
* Merge two subarrays of 'array[]'.
* First subarray is array[l..m]
* Second subarray is array[m+1..r]
*/
void merge(int *array, size_t l, size_t m, size_t r)
{
	size_t i, j, k;
	size_t n1 = m - l + 1;
	size_t n2 = r - m;

	int *left = malloc(sizeof(int) * n1);
	int *right = malloc(sizeof(int) * n2);

	for (i = 0; i < n1; i++)
		left[i] = array[l + i];
	for (j = 0; j < n2; j++)
		right[j] = array[m + 1 + j];

	i = 0;
	j = 0;
	k = 1;

	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		array[k] = right[j];
		j++;
		k++;
	}

	free(left);
	free(right);
}

/**
* Merge Sort function with step-by-step output using while loops
*/
void merge_sort(int *array, size_t size)
{
	size_t current_size = 1;
	size_t left_start;
	size_t mid;
	size_t right_end;
	size_t i;

	if (size < 2)
		return;

	while (current_size < size)
	{
		left_start = 0;

		while (left_start < size)
		{
			mid = (left_start + current_size - 1 < size - 1) ? (left_start + current_size - 1) : (size - 1);
			right_end = (left_start + 2 * current_size - 1 < size - 1) ? (left_start + 2 * current_size - 1) : (size - 1);

			merge(array, left_start, mid, right_end);

			printf("Merging...\n");
			printf("[left]: ");

			i = left_start;
			
			while (i <= mid)
			{
				printf("%d", array[i]);
				if (i < mid)
					printf(", ");
				i++;
			}
			printf("\n[right]: ");

			i = mid + 1;

			while (i <= right_end)
			{
				printf("%d", array[i]);
				if (i < right_end)
					printf(", ");
				i++;
			}
			printf("\n[Done]: ");

			i = left_start;

			while (i <= right_end)
			{
				printf("%d", array[i]);
				if (i < right_end)
					printf(", ");
				i++;
			}
			printf("\n");

			left_start += 2 * current_size;
		}
		current_size *= 2;
	}
}
