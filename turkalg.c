/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turkalg.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/05 by jstomps               #+#    #+#                 */
/*   Updated: 2026/02/05 by jstomps               ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turkalg(t_stack **a_stack)
{
	t_stack	*b_stack;

	if (!a_stack || !*a_stack || nodecount(a_stack) <= 3)
		return ;
	b_stack = NULL;
	while (nodecount(a_stack) > 3)
	{
		make_index(a_stack);
		make_index(&b_stack);
		push_cheapest(a_stack, &b_stack);
	}
	sort3(a_stack);
	push_back_all(a_stack, &b_stack);
	rotate_to_min(a_stack);
}

void	push_cheapest(t_stack **from, t_stack **to)
{
	t_stack	*cheapest;

	if (!from || !*from)
		return ;
	find_targets(*from, *to);
	calculate_costs(*from, *to);
	cheapest = get_cheapest(*from);
	if (!cheapest)
		return ;
	execute_moves(from, to, cheapest);
	bp(from, to);
}

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
		current->cost = calculate_move_cost(current, len_from);
		if (current->tar)
			current->tar->cost = calculate_move_cost(current->tar, len_to);
		current = current->next;
	}
}

int	calculate_move_cost(t_stack *node, int len)
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

void	execute_moves(t_stack **from, t_stack **to, t_stack *node)
{
	int	median_from;
	int	median_to;

	if (!node || !node->tar)
		return ;
	median_from = nodecount(from) / 2;
	median_to = nodecount(to) / 2;
	rotate_both(from, to, node, median_from, median_to);
	rotate_single(from, node, median_from, "ra\n", "rra\n");
	rotate_single(to, node->tar, median_to, "rb\n", "rrb\n");
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *node, int ma, int mb)
{
	while (node->index != 0 && node->tar->index != 0)
	{
		if (node->index <= ma && node->tar->index <= mb)
		{
			dr(a, b);
			make_index(a);
			make_index(b);
		}
		else if (node->index > ma && node->tar->index > mb)
		{
			drr(a, b);
			make_index(a);
			make_index(b);
		}
		else
			break ;
	}
}

void	rotate_single(t_stack **stack, t_stack *node, 
	int med, char *r_op, char *rr_op)
{
	if (!node)
		return ;
	while (node->index != 0)
	{
		if (node->index <= med)
			r(stack, r_op);
		else
			rr(stack, rr_op);
		make_index(stack);
	}
}

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

t_stack	*max_find(t_stack *to)
{
	t_stack	*buffer_to;
	t_stack	*max;
	ssize_t	tmp;

	if (!to)
		return (NULL);
	max = to;
	tmp = to->num;
	buffer_to = to->next;
	while (buffer_to)
	{
		if (buffer_to->num > tmp)
		{
			tmp = buffer_to->num;
			max = buffer_to;
		}
		buffer_to = buffer_to->next;
	}
	return (max);
}

t_stack	*min_find(t_stack *to)
{
	t_stack	*buffer_to;
	t_stack	*min;
	ssize_t	tmp;

	if (!to)
		return (NULL);
	min = to;
	tmp = to->num;
	buffer_to = to->next;
	while (buffer_to)
	{
		if (buffer_to->num < tmp)
		{
			tmp = buffer_to->num;
			min = buffer_to;
		}
		buffer_to = buffer_to->next;
	}
	return (min);
}
