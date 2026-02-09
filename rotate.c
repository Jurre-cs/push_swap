/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/09 20:57:27 by jstomps       #+#    #+#                 */
/*   Updated: 2026/02/09 22:13:14 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *node, int *medians)
{
	while (node->index != 0 && node->tar->index != 0)
	{
		if (node->index <= medians[0] && node->tar->index <= medians[1])
		{
			dr(a, b);
			make_index(a);
			make_index(b);
		}
		else if (node->index > medians[0] && node->tar->index > medians[1])
		{
			drr(a, b);
			make_index(a);
			make_index(b);
		}
		else
			break ;
	}
}

void	rotate_single_a(t_stack **stack, t_stack *cheapest, int med)
{
	if (!cheapest)
		return ;
	while (cheapest->index != 0)
	{
		if (cheapest->index <= med)
			r(stack, "ra\n");
		else
			rr(stack, "rra\n");
		make_index(stack);
	}
}

void	rotate_single_b(t_stack **stack, t_stack *cheapest, int med)
{
	if (!cheapest)
		return ;
	while (cheapest->index != 0)
	{
		if (cheapest->index <= med)
			r(stack, "rb\n");
		else
			rr(stack, "rrb\n");
		make_index(stack);
	}
}

void	rotate_to_min(t_stack **stack)
{
	t_stack	*min;
	int		median;

	min = min_find(*stack);
	if (!min)
		return ;
	make_index(stack);
	median = nodecount(stack) / 2;
	while (*stack != min)
	{
		if (min->index <= median)
			r(stack, "ra\n");
		else
			rr(stack, "rra\n");
		make_index(stack);
	}
}
