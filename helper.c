/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/14 16:09:51 by jstomps       #+#    #+#                 */
/*   Updated: 2026/02/04 23:21:40 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *node)
{
	if (*lst == NULL)
		*lst = node;
	else
		ft_lstadd_back(&(*lst)->next, node);
}

t_stack	*second_to_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next && lst->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

ssize_t	ft_atoi(const char *nptr)
{
	int	i;
	ssize_t	out;

	i = 1;
	out = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			i *= -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		out *= 10;
		out += (*nptr - 48);
		nptr++;
	}
	return (out * i);
}

int	nodecount(t_stack **stack)
{
	int count;
	t_stack *current;
	
	count = 0;
	if (stack == NULL)
		return (count);
	current = *stack;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
