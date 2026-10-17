/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinyu <xinyu@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 15:01:40 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/16 15:01:41 by xinyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bring_to_top(t_stack *a, int index);

static void	sort_3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->index;
	y = a->top->next->index;
	z = a->top->next->next->index;
	if (x < y && y < z)
		return ;
	if (x < z && z < y)
	{
		rra(a);
		sa(a);
	}
	else if (y < x && x < z)
		sa(a);
	else if (y < z && z < x)
		ra(a);
	else if (z < x && x < y)
		rra(a);
	else if (z < y && y < x)
	{
		sa(a);
		rra(a);
	}
}

static void	sort_5(t_stack *a, t_stack *b)
{
	bring_to_top(a, 0);
	pb(a, b);
	bring_to_top(a, 1);
	pb(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
	return ;
}

static void	sort_4(t_stack *a, t_stack *b)
{
	bring_to_top(a, 0);
	pb(a, b);
	sort_3(a);
	pa(a, b);
	return ;
}

static void	bring_to_top(t_stack *a, int index)
{
	int	pos;
	int	half;

	pos = find_index_position(a, index);
	half = a->total_nodes / 2;
	if (pos <= half)
	{
		while (a->top->index != index)
			ra(a);
	}
	else
	{
		while (a->top->index != index)
			rra(a);
	}
}

void	small_sort(t_stack *a, t_stack *b)
{
	int	n;

	n = a->total_nodes;
	if (n == 2)
	{
		if (a->top->index > a->top->next->index)
			sa(a);
	}
	else if (n == 3)
		sort_3(a);
	else if (n == 4)
		sort_4(a, b);
	else if (n == 5)
		sort_5(a, b);
	else
		return ;
	return ;
}
