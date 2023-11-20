#include "sort.h"

/**
 * remove_node - remove a node from linked list.
 *
 * @node: node to be removed.
 */
void remove_node(listint_t *node)
{
	node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
}


/**
 * insert_node - insert removed node into another position.
 *
 * @old_node:  node occupying the position of new node.
 *
 * @new_node: node to be inserted in new position.
 *
 * @head: pointer to the first node(header).
 */
void insert_node(listint_t *old_node, listint_t *new_node, listint_t **head)
{
	if (!old_node->prev)
	{
		new_node->next = old_node;
		new_node->prev = NULL;
		new_node->next->prev = new_node;
		*head = new_node;
	}
	else
	{
		new_node->next = old_node;
		new_node->prev = old_node->prev;
		old_node->prev = new_node;
		new_node->prev->next = new_node;
	}
}


/**
 * insertion_sort_list - sort linked list in ascending order.
 *
 * @list: pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *tmp, *p_node;

	current = current->next;

	while (current)
	{
		p_node = current->prev;
		if (current->n < p_node->n)
		{
			tmp = current->next;
			while (p_node && current->n < p_node->n)
			{
				remove_node(current);
				insert_node(p_node, current, list);
				print_list(*list);
				p_node = current->prev;
			}
			current = tmp;
		}
		else
			current = current->next;
	}
}

