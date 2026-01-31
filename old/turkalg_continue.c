/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turkalg_continue.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/27 20:10:21 by jstomps       #+#    #+#                 */
/*   Updated: 2026/01/30 22:28:52 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_a(t_stack **from, t_stack **to, 
	t_stack *buffer_from, t_stack *buffer_to)
{
	int	len;
	int cheap;

	len = nodecount(from);
	if (sorted(from))
		return ;
	make_index(from);
	make_index(to);
	while (len > 0)
	{
		buffer_from = *from;
		buffer_to = *to;
		max_check(to, buffer_from, buffer_to, INT_MIN);
		cheap = find_cheapesta(to, buffer_from, buffer_to);
		buffer_from = equal_to_cheap(from, cheap);
		buffer_to = buffer_from->tar;
		if ((buffer_from->index < len && buffer_to->index < nodecount(to) / 2) 
		|| (buffer_from->index >= len && buffer_to->index >= nodecount(to) / 2))
		double_ops(from, to, buffer_from, buffer_to);
		else
			ops(from, to, 0);
		apush(from, to);
		len = nodecount(from);
	}
}

int	find_2(t_stack *buffer_from, t_stack *buffer_to, int cheap)
{
	int from_cost;
	int to_cost;
	
	from_cost = cost_calc(buffer_from);
	to_cost = cost_calc(buffer_to);
	if (from_cost + to_cost < cheap)
		cheap = from_cost + to_cost;
	buffer_from->tar = buffer_to;
	return (cheap);
}

int	find_cheapesta(t_stack **to, t_stack *buffer_from, t_stack *buffer_to)
{
	int cheap;
	t_stack *original_to;
	
	cheap = INT_MAX;
	while (buffer_from != NULL)
	{
		original_to = buffer_to;
		while (buffer_to != NULL)
		{
			if (buffer_to->num > buffer_from->num)
			{
				cheap = find_2(buffer_from, buffer_to, cheap);
				break;
			}
			buffer_to = buffer_to->next;
		}
		cheap = min_check(to, buffer_from, buffer_to, cheap);
		buffer_from = buffer_from->next;
		buffer_to = original_to;
	}
	return (cheap);
}

t_stack	*equal_to_cheap(t_stack **from, int cheap)
{
	t_stack *buffer;
	t_stack *cheapest;
	
	cheap = 1;
	if (!from)
		return (NULL);
	buffer = *from;
	cheapest = *from;
	while (buffer)
	{
		if (cheapest->cost > buffer->cost)
			cheapest = buffer;
		buffer = buffer->next;
	}
	return (cheapest);
}