/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallsort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/14 16:02:55 by jstomps       #+#    #+#                 */
/*   Updated: 2026/01/26 16:31:13 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack **head)
{
	int tmp;
	t_stack *current;

	tmp = INT_MIN;
	current = *head;
	while (current)
	{
		if (tmp < current->num)
		{
			tmp = current->num;
			current = current->next;
		}
		else
			return (0);
	}
	return (1);
}

void	smallsort(t_stack **head)
{
	if (sorted(head))
		return ;
	else if ((*head)->num > (*head)->next->num)
		swap(head, "sa\n");
	else 
		sort3(head);
}

void	sort3(t_stack **head)
{
	int a;
	int b;
	int c;
	
	if (sorted(head))
		return ;
	a = (*head)->num;
	b = (*head)->next->num;
	c = (*head)->next->next->num;
	if (a > b && b < c && a < c)
		swap(head, "sa\n");
	else if (a > b && b > c)
	{
		rotate(head, "ra\n");
		swap(head, "sa\n");
	}
	else if (a > b && b < c && a > c)
		rotate(head, "ra\n");
	else if (a < b && b > c && a < c)
	{
		swap(head, "sa\n");
		rotate(head, "ra\n");
	}
	else if (a < b && b > c && a > c)
		reverse_rotate(head, "rra\n");
}

void	turk_move_small(t_stack **from, t_stack **to, char c)
{
	int expense;
	int nodes;

	nodes = nodecount(from);
	while (nodes != 0)
	{
		cost_search(from, to);
		if (*from == NULL || *to == NULL ||
			(*from)->cheapest == NULL || (*to)->cheapest == NULL)
			break;
		expense = (*from)->cheapest->cost + (*to)->cheapest->cost;
		if ((*from)->cheapest && (*to)->cheapest &&
		(*from)->cheapest == (*to)->cheapest)
			double_ops(from, to);
		else
			ops(from, to, 0);
		push(from, to, c);
		nodes--;
	}
}
