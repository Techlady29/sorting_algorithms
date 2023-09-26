#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting Sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
    size_t i,j;
    int max = 0;

    if (size <= 1 || !array)
        return;

    max = array[0];
    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    int *count = malloc((max + 1) * sizeof(int));
    if (!count)
        return;

    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (i = 0; i < size; i++) {
        count[array[i]]++;
    }

    printf("Count array:\n");
    print_array(count, max + 1); // Print the counting array

    size_t j = 0;
    for (i = 0; i <= max; i++) {
        while (count[i] > 0) {
            array[j] = i;
            j++;
            count[i]--;
        }
    }

    free(count);
}
