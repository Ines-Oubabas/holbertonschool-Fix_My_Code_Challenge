#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int p;

    if (*head == NULL)
        return (-1);

    current = *head;
    p = 0;

    /* Traverse the list to find the node at the index */
    while (current != NULL && p < index)
    {
        current = current->next;
        p++;
    }

    if (current == NULL) /* If index is out of bounds */
        return (-1);

    /* Case 1: Deleting the head node */
    if (current == *head)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    else
    {
        /* Case 2: Deleting any other node */
        if (current->prev != NULL)
            current->prev->next = current->next;

        if (current->next != NULL)
            current->next->prev = current->prev;
    }

    free(current);
    return (1);
}
