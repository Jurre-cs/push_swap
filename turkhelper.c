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
