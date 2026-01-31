/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/10 17:03:26 by jstomps       #+#    #+#                 */
/*   Updated: 2026/01/31 01:51:53 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "libft/libft.h"
#include <stdbool.h>

typedef struct s_stack
{
	ssize_t			num;
	int				index;
	struct s_stack	*next;
	struct s_stack	*tar;
	int				cost;
	struct s_stack	*min;
	struct s_stack	*max;
}					t_stack;

/* push_swap.c */
t_stack	**push_swap(t_stack **astack);
int		check(char **argv);
int		convert(char **argv, t_stack **astack);
void	free_stack(t_stack **stack);
void	make_index(t_stack **stack);

/* helper.c */
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *node);
t_stack	*second_to_last(t_stack *lst);
ssize_t	ft_atoi(const char *nptr);
int		nodecount(t_stack **stack);

/* single_operations.c */
void	ap(t_stack **ahead, t_stack **bhead);
void	bp(t_stack **ahead, t_stack **bhead);
void	rr(t_stack **head, char *op);
void	r(t_stack **head, char *op);
void	s(t_stack **head, char *op);

/* double_operations.c */
void	dr(t_stack **ahead, t_stack **bhead);
void	drr(t_stack **ahead, t_stack **bhead);

/* smallsort.c */
int		sorted(t_stack **head);
void	smallsort(t_stack **head);
void	sort3(t_stack **head);

/* turkalg.c */
t_stack	**turkalg(t_stack **a_stack);
void	move(t_stack **from, t_stack **to);
t_stack	*find_cheapest(t_stack **from, t_stack **to, char c);
void	cheapest_b(t_stack **from, t_stack **to, 
    t_stack *buffer_from, t_stack *buffer_to, int price);
int		cost(t_stack *stack);
bool	min_check(t_stack *buffer_from, t_stack **to);
t_stack	*max_check(t_stack **to);
t_stack	*tar_costs(t_stack **stack);
void	d_ops(t_stack **from, t_stack **to, t_stack *cheapest);
void	ops(t_stack **to, t_stack *cheapest, int i, double mediaan);
void	move_back(t_stack **from, t_stack **to);
void	cheapest_a(t_stack **from, t_stack **to, 
    t_stack *buffer_from, t_stack *buffer_to, int price);

#endif
