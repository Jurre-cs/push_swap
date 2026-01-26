/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   double_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/15 13:42:23 by jstomps       #+#    #+#                 */
/*   Updated: 2026/01/26 15:25:16 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_rotate(t_stack **ahead, t_stack **bhead)
{
	t_stack	*atop;
	t_stack	*abottom;
	t_stack	*btop;
	t_stack	*bbottom;

	atop = *ahead;
	abottom = ft_lstlast(*ahead);
	*ahead = (*ahead)->next;
	abottom->next = atop;
	atop->next = NULL;
	
	btop = *bhead;
	bbottom = ft_lstlast(*bhead);
	*bhead = (*bhead)->next;
	bbottom->next = btop;
	btop->next = NULL;
	write(1, "rr\n", 3);
}

void	double_reverse_rotate(t_stack **ahead, t_stack **bhead)
{
	t_stack	*asecondtolast;
	t_stack *alast;
	t_stack	*bsecondtolast;
	t_stack *blast;
	
	asecondtolast = second_to_last(*ahead);
	alast = ft_lstlast(*ahead);
	alast->next = *ahead;
	*ahead = alast;
	asecondtolast->next = NULL;

	bsecondtolast = second_to_last(*bhead);
	blast = ft_lstlast(*bhead);
	blast->next = *bhead;
	*bhead = blast;
	bsecondtolast->next = NULL;
	write(1, "rrr\n", 4);
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
	while ((i != (*from)->cheapest->cost) && (i != (*to)->cheapest->cost))
	{
		if ((*from)->index > mediaan)
			double_reverse_rotate(from, to);
		else
			double_rotate(from, to);
		i++;
	}
	ops(from, to, i);
}
