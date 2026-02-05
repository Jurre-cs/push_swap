/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/12/10 17:03:26 by jstomps       #+#    #+#                 */
/*   Updated: 2026/02/05 05:29:55 by jstomps       ########   odam.nl         */
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

//push_swap.c
void	push_swap(t_stack **astack);
int		check(char **argv);
int		convert(char **argv, t_stack **astack);
void	free_stack(t_stack **stack);
void	make_index(t_stack **stack);

//helper.c
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *node);
t_stack	*second_to_last(t_stack *lst);
ssize_t	ft_atoi(const char *nptr);
int		nodecount(t_stack **stack);

//single_operations.c
void	ap(t_stack **ahead, t_stack **bhead);
void	bp(t_stack **ahead, t_stack **bhead);
void	rr(t_stack **head, char *op);
void	r(t_stack **head, char *op);
void	s(t_stack **head, char *op);

//double_operations.c
void	dr(t_stack **ahead, t_stack **bhead);
void	drr(t_stack **ahead, t_stack **bhead);

//smallsort.c
int		sorted(t_stack **head);
void	smallsort(t_stack **head);
void	sort3(t_stack **head);

//turkalg.c
void	turkalg(t_stack **a_stack);

void	push_cheapest(t_stack **from, t_stack **to);
void	find_targets(t_stack *from, t_stack *to);
t_stack	*find_best_target(t_stack *node, t_stack *stack, t_stack *best);
void	calculate_costs(t_stack *from, t_stack *to);
int		calculate_move_cost(t_stack *node, int len);
t_stack	*get_cheapest(t_stack *stack);
void	execute_moves(t_stack **from, t_stack **to, t_stack *node);
void	rotate_both(t_stack **a, t_stack **b, t_stack *node, int ma, int mb);
void	rotate_single(t_stack **stack, t_stack *node,
	 int med, char *r_op, char *rr_op);
void	push_back_all(t_stack **a, t_stack **b);
t_stack	*find_target_for_b(t_stack *node, t_stack *stack, t_stack *best);
void	position_for_push(t_stack **stack, t_stack *target);
void	rotate_to_min(t_stack **stack);
t_stack	*max_find(t_stack *to);
t_stack	*min_find(t_stack *to);
// void	move_back(t_stack **from, t_stack **to);
// void	cheapest_a(t_stack *from, t_stack *to, t_stack *origin);

#endif
