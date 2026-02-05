/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   single_operations.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/14 15:59:33 by jstomps       #+#    #+#                 */
/*   Updated: 2026/02/04 20:13:50 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ap(t_stack **ahead, t_stack **bhead)
{
	t_stack	*atop;

	atop = *ahead;
	*ahead = atop->next;
	atop->next = *bhead;
	*bhead = atop;
	write(1, "pa\n", 3);
}

void	bp(t_stack **ahead, t_stack **bhead)
{
	t_stack	*atop;

	atop = *ahead;
	*ahead = atop->next;
	atop->next = *bhead;
	*bhead = atop;
	write(1, "pb\n", 3);
}

void	rr(t_stack **head, char *op)
{
	t_stack	*secondtolast;
	t_stack *last;
	
	secondtolast = second_to_last(*head);
	last = ft_lstlast(*head);
	last->next = *head;
	*head = last;
	secondtolast->next = NULL;
	write(1, op, 4);
}

void	r(t_stack **head, char *op)
{
	t_stack	*top;
	t_stack	*bottom;

	top = *head;
	bottom = ft_lstlast(*head);
	*head = (*head)->next;
	bottom->next = top;
	top->next = NULL;
	write(1, op, 3);
}

void	s(t_stack **head, char *op)
{
	t_stack *firstnode;
	t_stack *secondnode;

	firstnode = *head;
	secondnode = (*head)->next;
	firstnode->next = secondnode->next;
	secondnode->next = firstnode;
	*head = secondnode;
	write(1, op, 3);
}

// #include <stdio.h>

// int main(void)
// {
// 	struct s_list *ahead;
// 	struct s_list *asecond;
// 	struct s_list *athird;
// 	struct s_list *aforth;
// 	struct s_list *acurrent;
// 	struct s_list *bhead;
// 	// struct s_list *bsecond;
// 	// struct s_list *bthird;
// 	// struct s_list *bforth;
// 	struct s_list *bcurrent;

// 	ahead = malloc(sizeof(struct s_list));
// 	asecond = malloc(sizeof(struct s_list));
// 	athird = malloc(sizeof(struct s_list));
// 	aforth = malloc(sizeof(struct s_list));
// 	bhead = NULL;
// 	// bhead = malloc(sizeof(struct s_list));
// 	// bsecond = malloc(sizeof(struct s_list));
// 	// bthird = malloc(sizeof(struct s_list));
// 	// bforth = malloc(sizeof(struct s_list));
// 	ahead->num = 1;
// 	ahead->next = asecond;
// 	asecond->num = 2;
// 	asecond->next = athird;
// 	athird->num = 3;
// 	athird->next = aforth;
// 	aforth->num = 4;
// 	aforth->next = NULL;
// 	// acurrent = ahead;
// 	// bhead->num = 10;
// 	// bhead->next = bsecond;
// 	// bsecond->num = 9;
// 	// bsecond->next = bthird;
// 	// bthird->num = 8;
// 	// bthird->next = bforth;
// 	// bforth->num = 7;
// 	// bforth->next = NULL;
// 	// bcurrent = bhead;
// 	Bpush(&ahead, &bhead);
// 	acurrent = ahead;
// 	bcurrent = bhead;
// 	while (acurrent != NULL)
// 	{
// 		printf("a: %d\n", acurrent->num);
// 		acurrent = acurrent->next;
// 	}
// 	while (bcurrent != NULL)
// 	{
// 		printf("b: %d\n", bcurrent->num);
// 		bcurrent = bcurrent->next;
// 	}
// }