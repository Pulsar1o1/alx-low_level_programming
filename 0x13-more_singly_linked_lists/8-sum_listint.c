#include "lists.h"

/**
 * sum_listint
 * a linked list.
 * @head: head of a list.
 *
 * return: sum of all the data (n)
 */

int sum_listint(listint_t *head)
{
	int sum;

	sum = 0;
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
