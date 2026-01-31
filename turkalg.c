/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   turkalg.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2026/01/30 22:35:40 by jstomps       #+#    #+#                 */
/*   Updated: 2026/01/31 02:20:51 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**turkalg(t_stack **a_stack)
{
	t_stack	*b_stack;
	
	b_stack = NULL;
	bp(a_stack, &b_stack);
	if (nodecount(a_stack) >= 4)
		bp(a_stack, &b_stack);
	move(a_stack, &b_stack);
	sort3(a_stack);
	move_back(&b_stack, a_stack);
	return (a_stack);
}

void	move(t_stack **from, t_stack **to)
{
	int len;
	t_stack *cheapest;

	len = nodecount(from);
	while (len > 3)
	{
		make_index(from);
		make_index(to);
		cheapest = find_cheapest(from, to, 'b');
		d_ops(from, to, cheapest);
		bp(from, to);
		if (*to == (*to)->min)
			r(to, "rb\n");
	}
}

t_stack	*find_cheapest(t_stack **from, t_stack **to, char c)
{
	t_stack *buffer_from;
	t_stack *buffer_to;
	t_stack *cheapest;
	int		price;

	price = INT_MAX;
	buffer_from = *from;
	buffer_to = *to;
	while (buffer_from)
	{
		if (c == 'b')
			cheapest_b(from, to, buffer_from, buffer_to, price);
		else if (c == 'a')
			cheapest_a(from, to, buffer_from, buffer_to, price);
		cheapest = tar_costs(from);
		buffer_from = buffer_from->next;
	}
	return (cheapest);
}

void	cheapest_b(t_stack **from, t_stack **to, 
	t_stack *buffer_from, t_stack *buffer_to, int price)
{
	buffer_from = *from;
	while (buffer_to)
	{
		if (buffer_to->num < buffer_from->num)
		{
			buffer_from->tar = buffer_to;
			buffer_to->cost = cost(buffer_to);
			buffer_from->cost = cost(buffer_from);
			if (price > (buffer_to->cost + buffer_from->cost))
				price = (buffer_to->cost + buffer_from->cost);
			break;
		}
		else if (min_check(buffer_from, to))
		{
			buffer_from->tar = *to;
			break;
		}
		buffer_to = buffer_to->next;
	}
}

int	cost(t_stack *stack)
{
	double	mediaan;
	int		halfprice;
	int		len;

	len = nodecount(&stack);
	halfprice = 0;
	mediaan = (len / 2);
	if (stack->index > mediaan)
		halfprice = (len - stack->index + 1);
	else if (stack->index < mediaan)
		halfprice = stack->index;
	else
		return (-1);
	return (halfprice);
}

bool	min_check(t_stack *buffer_from, t_stack **to)
{
	t_stack *buffer_to;
	t_stack	*max;

	buffer_to = *to;
	while (buffer_to != NULL && buffer_to->num > buffer_from->num)
		buffer_to = buffer_to->next;
	if (!buffer_from)
	{
		max = max_check(to);
		max->min = buffer_from;
		return (true);
	}
	else
		return (false);
}

t_stack	*max_check(t_stack **to)
{
	t_stack *buffer_to;
	t_stack *max;
	ssize_t	tmp;

	max = NULL;
	tmp = LLONG_MIN;
	buffer_to = *to;
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

t_stack *tar_costs(t_stack **stack)
{
	t_stack *buffer_stack;
	t_stack *cheapest;
	int 	price;

	price = INT_MAX;
	buffer_stack = *stack;
	while (buffer_stack)
	{
		if ((buffer_stack->cost + buffer_stack->tar->cost) < price)
		{
			price = (buffer_stack->cost + buffer_stack->tar->cost);
			cheapest = buffer_stack;
		}
		buffer_stack = buffer_stack->next;
	}
	cheapest->cost = price;
	return (cheapest);
}

void	d_ops(t_stack **from, t_stack **to, t_stack *cheapest)
{
	double mediaan;
	int i;
	
	i = 0;
	mediaan = 0.0;
	if (min_check(cheapest, to))
		ops(to, cheapest, i, mediaan);
	mediaan = nodecount(from) / 2;
	while (cheapest->cost > i && cheapest->tar->cost > i)
		{
			if (cheapest->cost > mediaan && cheapest->tar->cost > mediaan)
				drr(from, to);
			else if (cheapest->cost < mediaan && cheapest->tar->cost < mediaan)
				dr(from, to);
			i++;
		}
	ops(to, cheapest, i, mediaan);
}

void ops(t_stack **to, t_stack *cheapest, int i, double mediaan)
{
	while (cheapest->cost < mediaan && cheapest->cost < i)
	{
		r(&cheapest, "ra\n");
		i++;
	}
	while (cheapest->cost > mediaan && cheapest->cost < i)
	{
		rr(&cheapest, "rra\n");
		i++;
	}
	if (min_check(cheapest, to))
		return ;
	while (cheapest->tar->cost < mediaan && cheapest->cost < i)
	{
		r(&cheapest, "rb\n");
		i++;
	}
	while (cheapest->tar->cost > mediaan && cheapest->cost < i)
	{
		rr(&cheapest, "rrb\n");
		i++;
	}
}

void	move_back(t_stack **from, t_stack **to)
{
	int len;
	t_stack *cheapest;

	len = nodecount(from);
	while (len > 0)
	{
		make_index(from);
		make_index(to);
		cheapest = find_cheapest(from, to, 'a');
		d_ops(from, to, cheapest);
		ap(from, to);
		if (*to == (*to)->min)
			r(to, "ra\n");
	}
}

void	cheapest_a(t_stack **from, t_stack **to, 
	t_stack *buffer_from, t_stack *buffer_to, int price)
{
	while (buffer_to)
	{
		if (buffer_to->num > buffer_from->num)
		{
			(*from)->tar = buffer_to;
			buffer_to->cost = cost(buffer_to);
			buffer_from->cost = cost(buffer_from);
			if (price > (buffer_to->cost + buffer_from->cost))
				price = (buffer_to->cost + buffer_from->cost);
			break;
		}
		else if (min_check(buffer_from, to))
		{
			(*from)->tar = *to;
			break;
		}
		buffer_to = buffer_to->next;
	}
}
