#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
    int max = array[0];
    int i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *sorted_array;
    int max, i;

    if (array == NULL || size < 2)
        return;

    sorted_array = malloc(sizeof(int) * size);
    if (sorted_array == NULL)
        return;

    max = get_max(array, size);
    count_array = malloc(sizeof(int) * (max + 1));
    if (count_array == NULL)
    {
        free(sorted_array);
        return;
    }

    for (i = 0; i < max + 1; i++)
        count_array[i] = 0;

    for (i = 0; i < (int)size; i++)
        count_array[array[i]]++;

    for (i = 1; i < max + 1; i++)
        count_array[i] += count_array[i - 1];

    print_array(count_array, max + 1);

    for (i = size - 1; i >= 0; i--)
    {
        sorted_array[count_array[array[i]] - 1] = array[i];
        count_array[array[i]]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = sorted_array[i];

    free(sorted_array);
    free(count_array);
}
