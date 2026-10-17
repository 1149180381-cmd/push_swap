/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:57:03 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/15 12:15:49 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 12:57:03 by xinyu             #+#    #+#             */
/*   Updated: 2026/10/17 00:00:00 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size(int total)
{
	int	size;

	size = 1;
	while ((long)size * size < total)
		size++;
	return (size * 2);
}

static void	push_chunk(t_stack *a, t_stack *b, int start, int end)
{
	int	size;
	int	mid;

	size = a->total_nodes;
	mid = (start + end) / 2;
	while (size-- > 0 && a->top)
	{
		if (a->top->index >= start && a->top->index < end)
		{
			pb(a, b);
			if (b->top->index < mid)
				rb(b);
		}
		else
			ra(a);
	}
}

static void	push_all(t_stack *a, t_stack *b, int chunk)
{
	int	start;
	int	total;
	int	end;

	start = 0;
	total = a->total_nodes;
	while (a->top && start < total)
	{
		end = start + chunk;
		if (end > total)
			end = total;
		push_chunk(a, b, start, end);
		start = end;
	}
}

static void	pull_max(t_stack *a, t_stack *b, int *max)
{
	int	pos;

	while (b->top && b->top->index == *max)
	{
		pa(a, b);
		(*max)--;
	}
	if (!b->top)
		return ;
	pos = find_index_position(b, *max);
	if (pos <= b->total_nodes / 2)
	{
		while (b->top->index != *max)
			rb(b);
	}
	else
	{
		while (b->top->index != *max)
			rrb(b);
	}
	pa(a, b);
	(*max)--;
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	chunk;
	int	max;
	int	total;

	if (!a || !a->top || !b || is_sorted(a))
		return ;
	total = a->total_nodes;
	chunk = chunk_size(total);
	push_all(a, b, chunk);
	max = total - 1;
	while (b->top)
		pull_max(a, b, &max);
}
