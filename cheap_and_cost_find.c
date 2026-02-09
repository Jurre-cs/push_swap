/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cheap_and_cost_find.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/09 21:06:30 by jstomps       #+#    #+#                 */
/*   Updated: 2026/02/09 22:13:28 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_targets(t_stack *from, t_stack *to)
{
	t_stack	*current;
	t_stack	*best;

	best = NULL;
	current = from;
	while (current)
	{
		current->tar = find_best_target(current, to, best);
		current = current->next;
	}
}

t_stack	*find_best_target(t_stack *node, t_stack *stack, t_stack *best)
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
		if (current->num < node->num)
		{
			diff = node->num - current->num;
			if (diff < best_diff)
			{
				best_diff = diff;
				best = current;
			}
		}
		current = current->next;
	}
	if (!best)
		best = max_find(stack);
	return (best);
}

void	calculate_costs(t_stack *from, t_stack *to)
{
	t_stack	*current;
	int		len_from;
	int		len_to;

	current = from;
	len_from = nodecount(&from);
	len_to = nodecount(&to);
	while (current)
	{
		current->cost = calculate_moves(current, len_from);
		if (current->tar)
			current->tar->cost = calculate_moves(current->tar, len_to);
		current = current->next;
	}
}

int	calculate_moves(t_stack *node, int len)
{
	int	median;

	if (!node || len == 0)
		return (0);
	median = len / 2;
	if (node->index <= median)
		return (node->index);
	else
		return (len - node->index);
}

t_stack	*get_cheapest(t_stack *stack)
{
	t_stack	*cheapest;
	t_stack	*current;
	int		min_cost;
	int		total_cost;

	if (!stack)
		return (NULL);
	cheapest = stack;
	min_cost = INT_MAX;
	current = stack;
	while (current)
	{
		total_cost = current->cost;
		if (current->tar)
			total_cost += current->tar->cost;
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
