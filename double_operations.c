/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   double_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/15 13:42:23 by jstomps       #+#    #+#                 */
/*   Updated: 2026/02/09 16:34:57 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dr(t_stack **ahead, t_stack **bhead)
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

void	drr(t_stack **ahead, t_stack **bhead)
{
	t_stack	*asecondtolast;
	t_stack	*alast;
	t_stack	*bsecondtolast;
	t_stack	*blast;

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
