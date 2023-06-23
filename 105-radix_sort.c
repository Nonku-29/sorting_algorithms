#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int significant_digit, int *buffer);
void radix_sort(int *array, size_t size);

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

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return max;
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @significant_digit: The significant digit to sort on.
 * @buffer: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int significant_digit, int *buffer)
{
    int count[10] = {0};

    for (size_t i = 0; i < size; i++)
        count[(array[i] / significant_digit) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        buffer[count[(array[i] / significant_digit) % 10] - 1] = array[i];
        count[(array[i] / significant_digit) % 10]--;
    }

    for (size_t i = 0; i < size; i++)
        array[i] = buffer[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm.
 * Prints the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int max = get_max(array, size);
    int *buffer = malloc(sizeof(int) * size);
    if (buffer == NULL)
        return;

    for (int significant_digit = 1; max / significant_digit > 0; significant_digit *= 10)
    {
        radix_counting_sort(array, size, significant_digit, buffer);
        // print_array(array, size);  // Uncomment for debugging
    }

    free(buffer);
}
