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
    dlistint_t *tmp = *head;
    unsigned int p = 0;

    if (*head == NULL)
        return (-1);

    /* Si le nœud à supprimer est le premier */
    if (index == 0)
    {
        *head = tmp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(tmp);
        return (1);
    }

    /* Parcourir la liste pour trouver le nœud à supprimer */
    while (tmp != NULL && p < index)
    {
        tmp = tmp->next;
        p++;
    }

    /* Si le nœud à supprimer n'existe pas */
    if (tmp == NULL)
        return (-1);

    /* Mise à jour des pointeurs */
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;

    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;

    free(tmp);

    return (1);
}
