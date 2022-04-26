#include "lists.h"
/**
 * free_listint2 - free list using double ptr to head
 * @head: pointer of pointer to head node
 */
void free_listint2(listint_t **head)
{
	listint_t *ptr;

	if (head == NULL)
		return;
	while (*head)
	{
		ptr = (*head)->next;
		free(*head);
		*head = ptr;
	}
	head = NULL;

}
