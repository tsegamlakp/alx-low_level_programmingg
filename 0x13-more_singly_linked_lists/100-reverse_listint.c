#include "lists.h"
/**
 * reverse_listint - reverse List Node
 * @head: pointer to head
 *
 * Return: reversed List
 */

listint_t *reverse_listint(listint_t **head)
{

	listint_t *prev, *post;

	prev = NULL;
	while (*head)
	{
		post = (*head)->next;
		(*head)->next = prev;
		prev = (*head);
		(*head) = post;
	}

	return (prev);
}
