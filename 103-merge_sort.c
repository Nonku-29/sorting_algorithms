#include <stdlib.h>
#include "sort.h"

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted subarray.
 * @start: The starting index of the subarray.
 * @middle: The middle index of the subarray.
 * @end: The ending index of the subarray.
 */
void merge_subarr(int *subarr, int *buffer, size_t start, size_t middle,
                  size_t end)
{
    size_t i, j, k = 0;

    for (i = start, j = middle; i < middle && j < end; k++)
    {
        buffer[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
    }

    for (; i < middle; i++)
    {
        buffer[k++] = subarr[i];
    }

    for (; j < end; j++)
    {
        buffer[k++] = subarr[j];
    }

    for (i = start, k = 0; i < end; i++)
    {
        subarr[i] = buffer[k++];
    }
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buffer: A buffer to store the sorted result.
 * @start: The starting index of the subarray.
 * @end: The ending index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *buffer, size_t start, size_t end)
{
    size_t middle;

    if (end - start > 1)
    {
        middle = start + (end - start) / 2;
        merge_sort_recursive(subarr, buffer, start, middle);
        merge_sort_recursive(subarr, buffer, middle, end);
        merge_subarr(subarr, buffer, start, middle, end);
    }
}

/**
 * merge_sort - Sort an array of integers in ascending order
 *              using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
    int *buffer;

    if (array == NULL || size < 2)
        return;

    buffer = malloc(sizeof(int) * size);
    if (buffer == NULL)
        return;

    merge_sort_recursive(array, buffer, 0, size);

    free(buffer);
}
