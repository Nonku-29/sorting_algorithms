#include "sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void cocktail_sort_list(listint_t **list);

/**
 * swap_nodes - Swap two nodes in a doubly-linked list.
 * @list: A pointer to the head of the list.
 * @node1: The first node to be swapped.
 * @node2: The second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->prev != NULL)
        node1->prev->next = node2;
    else
        *list = node2;

    if (node2->next != NULL)
        node2->next->prev = node1;
    
    node1->next = node2->next;
    node2->prev = node1->prev;
    node1->prev = node2;
    node2->next = node1;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of the doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *tail, *shaker;
    bool swapped = true;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = false;

        for (shaker = *list; shaker->next != NULL; shaker = shaker->next)
        {
            if (shaker->n > shaker->next->n)
            {
                swap_nodes(list, shaker, shaker->next);
                print_list((const listint_t *)*list);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        tail = shaker;

        for (shaker = shaker->prev; shaker != NULL; shaker = shaker->prev)
        {
            if (shaker->n > shaker->next->n)
            {
                swap_nodes(list, shaker, shaker->next);
                print_list((const listint_t *)*list);
                swapped = true;
            }
        }
    }
}
