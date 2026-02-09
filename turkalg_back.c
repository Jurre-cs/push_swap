/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turkalg_back.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/09 21:10:25 by jstomps       #+#    #+#                 */
/*   Updated: 2026/02/09 22:13:05 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_all(t_stack **a, t_stack **b)
{
	t_stack	*target;
	t_stack	*best;

	best = NULL;
	while (*b)
	{
		make_index(a);
		make_index(b);
		target = find_target_for_b(*b, *a, best);
		position_for_push(a, target);
		ap(b, a);
	}
}

t_stack	*find_target_for_b(t_stack *node, t_stack *stack, t_stack *best)
{
	t_stack	*current;
	ssize_t	best_diff;
	ssize_t	diff;

	if (!stack)
		return (NULL);
	best_diff = LLONG_MAX;
	current = stack;
	while (current)
	{
		if (current->num > node->num)
		{
			diff = current->num - node->num;
			if (diff < best_diff)
			{
				best_diff = diff;
				best = current;
			}
		}
		current = current->next;
	}
	if (!best)
		best = min_find(stack);
	return (best);
}

void	position_for_push(t_stack **stack, t_stack *target)
{
	int	median;

	if (!target)
		return ;
	median = nodecount(stack) / 2;
	while (*stack != target)
	{
		if (target->index <= median)
			r(stack, "ra\n");
		else
			rr(stack, "rra\n");
		make_index(stack);
	}
}
