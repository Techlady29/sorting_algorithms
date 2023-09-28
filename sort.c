#include "sort.h"

/**
 * swap_ints - this swaps two integers in an array
 * @c: the first integer to swap
 * @s: the second integer to swap
 */

void swap_ints(int *c, int *s)
{
        int tmp;

        tmp = *c;
        *c = *s;
        *s = tmp;
}

/**
 * selection_sort - this sorts an array of integers in ascending order
 * using the selection sort algorithm
 * @array: an array of integers
 * @size: the size of the array
 * Description: this prints the array after each swap
 */

void selection_sort(int *array, size_t size)
{
        int *min;
        size_t c, j, s;

        if (array == NULL || size < 2)
                return;

        for (c = 0; c < size - 1; c++)
        {
                min = array + c;
                for (s = c + 1; s < size; s++)
                        min = (array[j] < *min) ? (array + j) : min;

                if ((array + c) != min)
                {
                        swap_ints(array + c, min);
                        print_array(array, size);
                }
        }
}
