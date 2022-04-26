#include "lists.h"
/**
 * delete_nodeint_at_index - delete node at index
 * @head: pointer to head of node
 * @index: index of node to be deleted
 *
 * Return: 1 if succed else -1
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *ptri, *post;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);
	ptri = *head;
	post = ptri->next;
	if (index == 0)
	{
		post = (*head)->next;
		free(*head);
		*head = post;
		return (1);
	}
	else
	{
		i++;
		while (post)
		{
			if (i == index)
			{
				ptri->next = post->next;
				free(post);
				return (1);
			}
			i++;
			ptri = post;
			post = post->next;
		}
		return (-1);
	}
}
