/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turkalg.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/26 13:08:57 by jstomps       #+#    #+#                 */
/*   Updated: 2026/01/30 21:55:39 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void turkalg(t_stack **astack)
{
	t_stack *bstack;
	t_stack *buffer_from;
	t_stack	*buffer_to;

	bstack = NULL;
	buffer_from = *astack;
	buffer_to = bstack;
	if (nodecount(astack) > 4)
		bpush(astack, &bstack);
	bpush(astack, &bstack);
	move_b(astack, &bstack, buffer_from, buffer_to);
	min_check(&bstack, buffer_from, buffer_to, INT_MAX);
	sort3(astack);
	move_a(&bstack, astack, buffer_from, buffer_to);
}

void	move_b(t_stack **from, t_stack **to, 
	t_stack *buffer_from, t_stack *buffer_to)
{
	int		len;
	int		cheap;

	len = nodecount(from);
	if (sorted(from))
		return ;
	make_index(from);
	make_index(to);
	while (len > 3)
	{
		buffer_from = *from;
		buffer_to = *to;
		max_check(to, buffer_from, buffer_to, INT_MIN);
		cheap = find_cheapestb(to, buffer_from, buffer_to);
		buffer_from = equal_to_cheap(from, cheap);
		buffer_to = buffer_from->tar;
		if ((buffer_from->index < len && buffer_to->index < nodecount(to) / 2) 
		|| (buffer_from->index >= len && buffer_to->index >= nodecount(to) / 2))
			double_ops(from, to, buffer_from, buffer_to);
		else
			ops(from, to, 0);
		bpush(from, to);
		len = nodecount(from);
	}
}

int	find_cheapestb(t_stack **to, t_stack *buffer_from, t_stack *buffer_to)
{
	int cheap;
	t_stack *original_to;
	
	cheap = INT_MAX;
	while (buffer_from != NULL)
	{
		original_to = buffer_to;
		while (buffer_to != NULL )
		{
			if (buffer_to->num < buffer_from->num)
			{
				cheap = find_2(buffer_from, buffer_to, cheap);
				break;
			}
			buffer_to = buffer_to->next;
		}
		buffer_to = original_to;
		cheap = min_check(to, buffer_from, buffer_to, cheap);
		buffer_from = buffer_from->next;
	}
	return (cheap);
}

int	cost_calc(t_stack *node)
{
	int	cost;
	int stacklen;
	t_stack *buffer;

	buffer = node;
	while (buffer->next)
		buffer = buffer->next;
	stacklen = buffer->index + 1;
	cost = 0;
	if (node && node->index > (stacklen / 2))
		cost = stacklen - node->index;
	else if (node)
		cost = node->index;
	else
		return (cost);
	node->cost = cost;
	return (cost);
}
