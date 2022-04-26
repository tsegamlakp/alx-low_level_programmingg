#include "lists.h"
/**
 * insert_nodeint_at_index - insert new node at index n
 * @head: pointer to head Node
 * @idx: index to be iserted at
 * @n: default data
 *
 * Return: new List head
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *Node, *ptr, *pre;
	unsigned int i  = 0;

	Node = malloc(sizeof(listint_t));
	if (Node == NULL)
		return (NULL);
	Node->n = n;
	if (*head == NULL)
	{
		Node->next = NULL;
		*head = Node;
		return (Node);
	}
	else
	{
		pre = NULL;
		ptr = (*head);
		if (idx == 0)
		{
			Node->next = *head;
			*head = Node;
			return (Node);
		}
		while (ptr)
		{
			if (i == idx)
			{
				Node->next = ptr;
				pre->next = Node;
				return (Node);
			}
			i++;
			pre = ptr;
			ptr = pre->next;
		}
		free(Node);
		return (NULL);
	}
}

