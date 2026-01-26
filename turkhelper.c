/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turkhelper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/15 15:21:28 by jstomps       #+#    #+#                 */
/*   Updated: 2026/01/23 17:39:27 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_index(t_stack **stack)
{
	int		i;
	t_stack *head;
	
	i = 0;
	head = *stack;
	while (*stack)
	{
		(*stack)->index = i;
		*stack = (*stack)->next;
		i++;
	}
	*stack = head;
}

void	push(t_stack **ahead, t_stack **bhead, char c)
{
	if (c == 'a')
		apush(ahead, bhead);
	else if (c == 'b')
		bpush(ahead, bhead);
}

void	ops(t_stack **from, t_stack **to, int i)
{
	int j;
	int mediaan;

	j = i;
	mediaan = nodecount(from);
	while(i != (*from)->cheapest->cost)
	{
		if ((*from)->index < mediaan)
			rotate(from, "ra\n");
		else
			reverse_rotate(from, "rra\n");
		i++;
	}
	if ((*to)->cheapest == (*to)->min)
		return;
	mediaan = nodecount(to);
	while (j != (*to)->cheapest->cost)
	{
		if ((*to)->index < mediaan)
			rotate(to, "rb\n");
		else
			reverse_rotate(to, "rrb\n");
		j++;
	}
}

void	double_ops(t_stack **from, t_stack **to)
{
	int i;
	int mediaan;

	i = 0;
	mediaan = nodecount(from);
	if ((*to)->cheapest == (*to)->min)
		return(ops(from, to, i));
	else
	{
		while ((i != (*from)->cheapest->cost) && (i != (*to)->cheapest->cost))
		{
			if ((*from)->index > mediaan)
				double_reverse_rotate(from, to);
			else
				double_rotate(from, to);
			i++;
		}
	}
	ops(from, to, i);
}
