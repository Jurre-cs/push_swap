/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turkalg.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/26 13:08:57 by jstomps       #+#    #+#                 */
/*   Updated: 2026/01/26 17:09:28 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	min_check(t_stack **stack, t_stack *buffer_to);

void turkalg(t_stack **astack)
{
	t_stack *bstack;

	bstack = NULL;
	if (nodecount(astack) > 4)
		bpush(astack, &bstack);
	bpush(astack, &bstack);
	move(astack, &bstack, 'b', 3);
	min_check(astack, bstack);
	sort3(astack);
	move(&bstack, astack, 'a', 0);
}

void	move(t_stack **from, t_stack **to, char c, int leftover)
{
	t_stack *buffer_from;
	t_stack	*buffer_to;
	int		len;

	len = nodecount(from);
	if (sorted(from))
		return ;
	make_index(from);
	make_index(to);
	while (len > leftover)
	{
		buffer_from = *from;
		buffer_to = *to;
		len = nodecount(from);
		find_cheapest(from, to, buffer_from, buffer_to);
		buffer_from = (*from)->cheapest;
		buffer_to = (*to)->cheapest;
		if ((buffer_from->index < len && buffer_to->index < nodecount(to) / 2) 
		|| (buffer_from->index >= len && buffer_to->index >= nodecount(to) / 2))
			double_ops(from, to);
		else
			ops(from, to, 0);
		push(from, to, c);
		len = nodecount(from);
	}
}

void	find_cheapest(t_stack **from, t_stack **to, 
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
			if (buffer_to->num < buffer_from->num)
			{
				if (cost_calc(buffer_from) + cost_calc(buffer_to) < cheap)
				{
					cheap = cost_calc(buffer_from) + cost_calc(buffer_to);
					(*from)->cheapest = buffer_from;
					(*to)->cheapest = buffer_to;
				}
				break;
			}
			buffer_to = buffer_to->next;
		}
		min_check(to, buffer_to);
		buffer_from = buffer_from->next;
		buffer_to = original_to;
	}
}

int	cost_calc(t_stack *stack)
{
	int	cost;
	int stacklen;
	
	stacklen = nodecount(&stack);
	cost = 0;
	if (stack->index > (stacklen / 2))
		cost = stacklen - stack->index;
	else
		cost = stack->index;
	stack->cost = cost;
	return (cost);
}

void	min_check(t_stack **stack, t_stack *buffer_to)
{
	t_stack	*buffer;
	int		min;

	min = INT_MAX;
	buffer = *stack;
	if (buffer_to == NULL)
	{
		while (buffer != NULL)
		{
			if (buffer->num < min)
			{
				min = buffer->num;
				(*stack)->min = buffer;
			}
			buffer = buffer->next;
		}
	}
	else
		return ;
}
