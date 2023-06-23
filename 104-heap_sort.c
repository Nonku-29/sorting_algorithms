#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @heap_size: The size of the heap.
 * @parent: The parent node of the binary tree.
 */
void max_heapify(int *array, size_t size, size_t heap_size, size_t parent)
{
    size_t left_child, right_child, largest;

    left_child = 2 * parent + 1;
    right_child = 2 * parent + 2;
    largest = parent;

    if (left_child < heap_size && array[left_child] > array[largest])
        largest = left_child;

    if (right_child < heap_size && array[right_child] > array[largest])
        largest = right_child;

    if (largest != parent)
    {
        swap_ints(&array[parent], &array[largest]);
        max_heapify(array, size, heap_size, largest);
    }
}

/**
 * heap_sort - Sort an array of integers in ascending order
 *             using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort algorithm.
 * Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    for (int i = size / 2 - 1; i >= 0; i--)
    {
        max_heapify(array, size, size, i);
    }

    for (int i = size - 1; i > 0; i--)
    {
        swap_ints(&array[0], &array[i]);
        max_heapify(array, size, i, 0);
    }
}
