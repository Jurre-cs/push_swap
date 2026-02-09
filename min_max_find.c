/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   min_max_find.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/09 16:29:12 by jstomps       #+#    #+#                 */
/*   Updated: 2026/02/09 22:13:22 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
