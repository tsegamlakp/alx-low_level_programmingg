#include "lists.h"
/**
 * print_listint - print all elements of list
 * @h: header pointer
 *
 * Return: number of elements
 */
size_t print_listint(const listint_t *h)
{
	listint_t *ptr;
	size_t count;

	count = 0;
	if (h == NULL)
		return (0);
	count++;
	printf("%d\n", h->n);
	ptr = h->next;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
		count++;
	}

	return (count);
}
