/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turkalg_continue.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/27 20:10:21 by jstomps       #+#    #+#                 */
/*   Updated: 2026/01/27 23:01:56 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	movea(t_stack **from, t_stack **to, 
	t_stack *buffer_from, t_stack *buffer_to)
{
	int		len;

	len = nodecount(from);
	if (sorted(from))
		return ;
	make_index(from);
	make_index(to);
	while (len > 3)
	{
		buffer_from = *from;
		buffer_to = *to;
		max_check(to, buffer_to);
		find_cheapesta(from, to, buffer_from, (*to)->max);
		buffer_from = (*from)->cheapest;
		buffer_to = (*to)->cheapest;
		if ((buffer_from->index < len && buffer_to->index < nodecount(to) / 2) 
		|| (buffer_from->index >= len && buffer_to->index >= nodecount(to) / 2))
			double_ops(from, to);
		else
			ops(from, to, 0);
		apush(from, to);
		len = nodecount(from);
	}
}

int	find_2(t_stack **from, t_stack **to, 
	t_stack *buffer_from, t_stack *buffer_to, int cheap)
{
	int from_cost;
	int to_cost;
	
	from_cost = cost_calc(buffer_from);
	to_cost = cost_calc(buffer_to);
	if (from_cost + to_cost < cheap)
	{
		cheap = from_cost + to_cost;
		(*from)->cheapest = buffer_from;
		(*to)->cheapest = buffer_to;
	}
	return (cheap);
}

void	find_cheapesta(t_stack **from, t_stack **to, 
	t_stack *buffer_from, t_stack *buffer_to)
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
				cheap = find_2(from, to, buffer_from, buffer_to, cheap);
				break;
			}
			buffer_to = buffer_to->next;
		}
		min_check(to, buffer_to);
		buffer_from = buffer_from->next;
		buffer_to = original_to;
	}
}