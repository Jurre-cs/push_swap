/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turkalg.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/09 16:35:50 by jstomps       #+#    #+#                 */
/*   Updated: 2026/02/09 22:12:54 by jstomps       ########   odam.nl         */
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

void	execute_moves(t_stack **from, t_stack **to, t_stack *cheapest)
{
	int	medians[2];

	if (!cheapest || !cheapest->tar)
		return ;
	medians[0] = nodecount(from) / 2;
	medians[1] = nodecount(to) / 2;
	rotate_both(from, to, cheapest, medians);
	rotate_single_a(from, cheapest, medians[0]);
	rotate_single_b(to, cheapest->tar, medians[1]);
}
