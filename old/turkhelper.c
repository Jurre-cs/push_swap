/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turkhelper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/15 15:21:28 by jstomps       #+#    #+#                 */
/*   Updated: 2026/01/30 21:28:42 by jstomps       ########   odam.nl         */
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

int	min_check(t_stack **to, 
	t_stack *buffer_from, t_stack *buffer_to, int cheap)
{
	t_stack	*buffer;
	int		min;

	min = INT_MAX;
	buffer = buffer_to;
	if (buffer_to != NULL)
	{
		while (buffer_to != NULL)
		{
			cheap = find_2(buffer_from, buffer_to, cheap);
			if (buffer->num < min)
			{
				min = buffer->num;
				(*to)->min = buffer_to;
			}
			buffer_to = buffer_to->next;
		}
		buffer_to = buffer;
		return (cheap);
	}
	else
		return (cheap);
}

int	max_check(t_stack **to, 
	t_stack *buffer_from, t_stack *buffer_to, int cheap)
{
	t_stack	*buffer;
	int 	max;
	
	buffer = buffer_to;
	max = INT_MIN;
	if (buffer_to != NULL)
	{
		while (buffer_to != NULL)
		{
			if (buffer_to->num > max)
			{
				cheap = find_2(buffer_from, buffer_to, cheap);
				max = buffer_to->num;
				(*to)->max = buffer_to;
			}
			buffer_to = buffer_to->next;
		}
		buffer_to = buffer;
		return (cheap);
	}
	else
		return (-1);
}

t_stack	*find_min(t_stack **stack)
{
	t_stack	*buffer;
	
	if (!stack || !*stack)
		return (NULL);
	buffer = *stack;
	while (buffer->min == NULL)
		buffer = buffer->next;
	return (buffer);
}

t_stack	*find_max(t_stack **stack)
{
	t_stack	*buffer;
	
	if (!stack || !*stack)
		return (NULL);
	buffer = *stack;
	while (buffer->max == NULL)
		buffer = buffer->next;
	return (buffer);
}