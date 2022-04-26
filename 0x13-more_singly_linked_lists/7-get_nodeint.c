#include "lists.h"
/**
 * get_nodeint_at_index - get nth node index
 * @head: head Node
 * @index: index of nth Node
 *
 * Return: nth Node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	if (head == NULL)
		return (NULL);
	i = 0;
	while (head && (i < index))
	{
		if (head == NULL)
			return (NULL);
		i++;
		head = head->next;
	}

	return (head);
}



