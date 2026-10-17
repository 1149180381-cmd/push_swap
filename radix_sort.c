/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaniagu <apaniagu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 11:38:58 by apaniagu          #+#    #+#             */
/*   Updated: 2026/10/17 00:00:00 by apaniagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_bits(t_stack *a, t_stack *b, int bit)
{
	int	size;
	int	mask;

	mask = 1 << bit;
	size = a->total_nodes;
	while (size-- > 0 && a->top)
	{
		if ((a->top->index & mask) == 0)
			pb(a, b);
		else
			ra(a);
	}
	while (b->top)
		pa(a, b);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	max_bits;
	int	bit;

	if (!a || !a->top || !b || is_sorted(a))
		return ;
	size = a->total_nodes;
	max_bits = 1;
	while ((size - 1) >> max_bits)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		process_bits(a, b, bit);
		if (is_sorted(a))
			return ;
		bit++;
	}
}
