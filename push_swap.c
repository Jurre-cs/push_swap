/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/10 17:10:31 by jstomps       #+#    #+#                 */
/*   Updated: 2026/01/23 21:40:16 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**push_swap(t_stack **astack)
{
	int count;

	count = 0;
	*astack = NULL;
	if (!sorted(astack))
	{
		if (nodecount(astack) == 3)
			sort_3(&astack);
		if (nodecount(astack) == 2)
			swap(&astack, "sa\n");
		else
			turkalg(astack);
	}
	else
		return (free_stack(astack), write(1, "pizza\n", 6), NULL);
	return (astack);
}

int	check(char **argv)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ' && (argv[i][j] < '0' || 
				argv[i][j] > '9') && argv[i][j] != '-')
				return(-1);
			j++;
		}
		i++;
	}
	return(i + 1);
}

int	convert(char **argv,t_stack **astack)
{
	t_stack *anode;
	int 	count;

	count = 1;
	while (argv[count])
	{
		anode = (struct s_stack*)malloc(sizeof(t_stack));
		if (!anode)
			return (-1);
		anode->num = ft_atoi(argv[count]);
		anode->next = NULL;
		ft_lstadd_back(astack, anode);
		count++;
	}
	if (*astack == NULL)
		return (-1);
	return (count - 1);
}

void	free_stack(t_stack **stack)
{
	t_stack *current;
	t_stack *next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
