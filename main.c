/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/02/09 21:20:08 by jstomps       #+#    #+#                 */
/*   Updated: 2026/02/09 23:55:04 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*astack;
	int		count;

	astack = NULL;
	count = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = copy_without_first(argv);
	if (!argv || !*argv)
		return (free(argv), -1);
	count = check(argv);
	if (count == -1)
		return (free_args(argv), -1);
	convert(argv, &astack);
	if (check_double(astack))
		return (free_stack(&astack), free_args(argv), -1);
	push_swap(&astack);
	free_stack(&astack);
	free_args(argv);
	return (0);
}

void	free_args(char **argv)
{
	int	i;

	if (!argv || !argv[0])
		return ;
	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

bool	check_double(t_stack *astack)
{
	t_stack	*buffer;

	while (astack)
	{
		buffer = astack;
		while (buffer)
		{
			if (astack->num == buffer->num && astack != buffer)
				return (true);
			buffer = buffer->next;
		}
		astack = astack->next;
	}
	return (false);
}

char	**copy_without_first(char **argv)
{
	char	**new;
	int		i;
	int		count;

	if (!argv || !argv[0])
		return (NULL);
	count = 0;
	while (argv[count])
		count++;
	new = malloc(sizeof(char *) * count);
	if (!new)
		return (NULL);
	i = 0;
	while (argv[i + 1])
	{
		new[i] = ft_strdup(argv[i + 1]);
		if (!new[i])
			return (free_args(new), NULL);
		i++;
	}
	new[i] = NULL;
	return (new);
}

// t_stack	convert(char **nums);

// int	main(int argc, char **argv)
// {
// 	char **nums = parse_args(&argv[1], argc - 1);
// 	if (!nums)
// 		return EXIT_FAILURE;
// 	t_stack *stack = convert(nums);
// 	if (!stack || !check_stack_validity(stack))
// 		return EXIT_FAILURE;
// 	free_nums(nums);
// 	int res = push_swap(stack);
// 	free_stack(stack);
// 	return EXIT_SUCCESS;
// }

// char **parse_args(char **arg, int arg_amount) {
// 	if (arg_amount == 1)
// 		return (ft_split(arg[0], ' '));
// 	return copy_arguments(arg, arg_amount);
// }

// int	main(int argc, char **argv)
// {
// 	t_stack	*astack;
// 	int		count;

// 	astack = NULL;
// 	count = 0;
// 	if (argc == 1 || (argc == 2 && !argv[1][0]))
// 		return (1);
// 	if (argc == 2)
// 		argv = ft_split(argv[1], ' ');
// 	if (!argv || !*argv)
// 		return (free(argv), -1);
// 	count = check(argv);
// 	if (count == -1)
// 		return (free_args(argv), -1);
// 	convert(argv, &astack);
// 	if (check_double(astack))
// 		return (free_stack(&astack), free_args(argv), -1);
// 	push_swap(&astack);
// 	free_stack(&astack);
// 	free_args(argv);
// 	return (0);
// }