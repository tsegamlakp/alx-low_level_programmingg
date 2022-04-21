#include "lists.h"
/**
 * print_list -print list nodes give head node
 * @h: list args
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t i;
	char *s;
	list_t *Node = NULL;

	i = 0;
	if (h == NULL)
		return (0);
	if (!(h->str))
		printf("[%u] %s\n", 0, "(nil)");
	else
		printf("[%u] %s\n", h->len, h->str);
	i++;
	Node = h->next;
	while (Node)
	{
		s = Node->str;
		if (s == NULL)
			printf("[%u] %s\n", 0, "(nil)");
		else
			printf("[%u] %s\n", Node->len, Node->str);

		Node = Node->next;
		i++;
	}

	return (i);
}

