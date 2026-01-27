/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/10 17:03:26 by jstomps       #+#    #+#                 */
/*   Updated: 2026/01/27 23:01:04 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "libft/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
	int				cost;
	struct s_stack	*cheapest;
	struct s_stack	*min;
	struct s_stack	*max;
}					t_stack;

int		convert(char **argv, t_stack **astack);
int		check(char **argv);
t_stack	**push_swap(t_stack **astack);
void	turkalg(t_stack **astack);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*second_to_last(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *node);
void	bpush(t_stack **ahead, t_stack **bhead);
void	apush(t_stack **ahead, t_stack **bhead);
void	reverse_rotate(t_stack **head, char *op);
void	rotate(t_stack **head, char *op);
void	swap(t_stack **head, char *op);
int		ft_atoi(const char *nptr);
void	sort3(t_stack **head);
void	double_reverse_rotate(t_stack **ahead, t_stack **bhead);
void	double_rotate(t_stack **ahead, t_stack **bhead);
void	make_index(t_stack **stack);
int		nodecount(t_stack **stack);
void	ops(t_stack **from, t_stack **to, int i);
void	double_ops(t_stack **from, t_stack **to);
int		sorted(t_stack **head);
void	push(t_stack **ahead, t_stack **bhead, char c);
void	smallsort(t_stack **head);
void	free_stack(t_stack **stack);
int		cost_calc(t_stack *stack);
void	find_cheapestb(t_stack **from, t_stack **to, 
	t_stack *buffer_from, t_stack *buffer_to);
void	find_cheapesta(t_stack **from, t_stack **to, 
	t_stack *buffer_from, t_stack *buffer_to);
int		find_2(t_stack **from, t_stack **to, 
	t_stack *buffer_from, t_stack *buffer_to, int cheap);
void	moveb(t_stack **from, t_stack **to, 
	t_stack *buffer_from, t_stack *buffer_to);
void	movea(t_stack **from, t_stack **to, 
	t_stack *buffer_from, t_stack *buffer_to);
void	min_check(t_stack **stack, t_stack *buffer_to);
void	max_check(t_stack **to, t_stack *buffer_to);

#endif