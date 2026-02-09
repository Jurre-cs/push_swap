/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   smallsort.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/14 16:02:55 by jstomps       #+#    #+#                 */
/*   Updated: 2026/02/09 16:34:46 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack **head)
{
	int		tmp;
	t_stack	*current;

	tmp = INT_MIN;
	current = *head;
	while (current)
	{
		if (tmp < current->num)
		{
			tmp = current->num;
			current = current->next;
		}
		else
			return (0);
	}
	return (1);
}

void	smallsort(t_stack **head)
{
	if (sorted(head))
		return ;
	else if ((*head)->num > (*head)->next->num)
		s(head, "sa\n");
	else
		sort3(head);
}

void	sort3(t_stack **head)
{
	int	a;
	int	b;
	int	c;

	if (sorted(head))
		return ;
	a = (*head)->num;
	b = (*head)->next->num;
	c = (*head)->next->next->num;
	if (a > b && b < c && a < c)
		s(head, "sa\n");
	else if (a > b && b > c)
	{
		r(head, "ra\n");
		s(head, "sa\n");
	}
	else if (a > b && b < c && a > c)
		r(head, "ra\n");
	else if (a < b && b > c && a < c)
	{
		s(head, "sa\n");
		r(head, "ra\n");
	}
	else if (a < b && b > c && a > c)
		rr(head, "rra\n");
}
