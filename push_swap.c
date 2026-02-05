/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/10 17:10:31 by jstomps       #+#    #+#                 */
/*   Updated: 2026/02/02 19:54:47 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **astack)
{
	if (sorted(astack))
		return ;
	if (nodecount(astack) == 3)
		sort3(astack);
	else if (nodecount(astack) == 2)
		s(astack, "sa\n");
	else if (nodecount(astack) > 3)
		turkalg(astack);
	else
	{
		write(1, "Error\n", 6);
		free_stack(astack);
	}
}

int	check(char **argv)
{
	int i;
	int j;
	
	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != ' ' && (argv[i][j] < '0' || argv[i][j] > '9')
			&& argv[i][j] != '-' && argv[i][j + 1] != '-')
				return (-1);
			if (argv[i][j + 1] == '-' && argv[i][j] == '-')
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
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
		anode->index = 0;
		anode->cost = 0;
		anode->tar = NULL;
		anode->min = NULL;
		anode->max = NULL;
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

	if (!stack || !*stack)
		return;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	make_index(t_stack **stack)
{
	int		i;
	t_stack *head;
	
	i = 0;
	head = *stack;
	while (head)
	{
		head->index = i;
		head = head->next;
		i++;
	}
}
